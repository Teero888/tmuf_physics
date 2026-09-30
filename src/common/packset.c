#include "common/packset.h"

#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <dirent.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common/crypto.h"

static char lower_char(char c) { return c >= 'A' && c <= 'Z' ? (char)(c - 'A' + 'a') : c; }

static uint64_t path_hash(const char *s) {
  uint64_t h = 1469598103934665603ull; /* FNV-1a */
  for (; *s; s++) {
    h ^= (uint8_t)lower_char(*s);
    h *= 1099511628211ull;
  }
  return h ? h : 1;
}

static int path_equal(const char *a, const char *b) {
  for (; *a && *b; a++, b++)
    if (lower_char(*a) != lower_char(*b))
      return 0;
  return *a == *b;
}

static uint8_t *read_whole(const char *path, size_t *size) {
  FILE *f = fopen(path, "rb");
  if (!f)
    return NULL;
  fseek(f, 0, SEEK_END);
  long n = ftell(f);
  fseek(f, 0, SEEK_SET);
  uint8_t *data = n > 0 ? malloc((size_t)n) : NULL;
  if (data && fread(data, 1, (size_t)n, f) != (size_t)n) {
    free(data);
    data = NULL;
  }
  fclose(f);
  *size = (size_t)n;
  return data;
}

static void table_insert(tmuf_packset *set, uint64_t h, int pack, uint32_t file) {
  uint32_t mask = set->table_cap - 1;
  for (uint32_t i = (uint32_t)h & mask;; i = (i + 1) & mask)
    if (!set->table[i].hash) {
      set->table[i] = (tmuf_packset_entry){h, (uint16_t)pack, file};
      return;
    }
}

int tmuf_packset_open(tmuf_packset *set, const char *dir, char *err, size_t err_size) {
  memset(set, 0, sizeof *set);
  snprintf(set->dir, sizeof set->dir, "%s", dir);
  char path[1024];
  size_t size;
  snprintf(path, sizeof path, "%s/packlist.dat", dir);
  uint8_t *data = read_whole(path, &size);
  if (!data || !tmuf_packlist_parse(data, size, "", &set->list)) {
    free(data);
    snprintf(err, err_size, "cannot read %s", path);
    return 0;
  }
  free(data);
  uint32_t total = 0;
  for (int i = 0; i < set->list.count; i++) {
    const char *name = set->list.entries[i].name;
    snprintf(path, sizeof path, "%s/%s.pak", dir, name);
    data = read_whole(path, &size);
    if (!data) {
      /* Pack file names are capitalised on disk. */
      snprintf(path, sizeof path, "%s/%c%s.pak", dir, name[0] >= 'a' && name[0] <= 'z' ? name[0] - 'a' + 'A' : name[0],
               name + 1);
      data = read_whole(path, &size);
    }
    if (!data)
      continue; /* listed but not installed (e.g. patch packs) */
    if (!tmuf_pack_open(&set->packs[set->pack_count], data, size, &set->list, name)) {
      snprintf(err, err_size, "cannot open pack %s", name);
      tmuf_packset_close(set);
      return 0;
    }
    total += set->packs[set->pack_count].file_count;
    set->pack_count++;
  }
  set->table_cap = 1;
  while (set->table_cap < total * 2 + 16)
    set->table_cap <<= 1;
  set->table = calloc(set->table_cap, sizeof *set->table);
  if (!set->table) {
    snprintf(err, err_size, "out of memory");
    tmuf_packset_close(set);
    return 0;
  }
  for (int p = 0; p < set->pack_count; p++)
    for (uint32_t f = 0; f < set->packs[p].file_count; f++)
      if (tmuf_pack_file_path(&set->packs[p], f, path, sizeof path))
        table_insert(set, path_hash(path), p, f);
  return 1;
}

void tmuf_packset_close(tmuf_packset *set) {
  for (int i = 0; i < set->pack_count; i++)
    tmuf_pack_close(&set->packs[i]);
  free(set->table);
  memset(set, 0, sizeof *set);
}

tmuf_pack_ref tmuf_packset_find_stored(const tmuf_packset *set, const char *path) {
  tmuf_pack_ref r = {-1, 0};
  if (!set->table)
    return r;
  uint64_t h = path_hash(path);
  uint32_t mask = set->table_cap - 1;
  char buf[512];
  for (uint32_t i = (uint32_t)h & mask; set->table[i].hash; i = (i + 1) & mask) {
    const tmuf_packset_entry *e = &set->table[i];
    if (e->hash == h && tmuf_pack_file_path(&set->packs[e->pack], e->file, buf, sizeof buf) && path_equal(buf, path)) {
      r.pack = e->pack;
      r.file = e->file;
      return r;
    }
  }
  return r;
}

/* Hex of the length byte and the MD5 digest, low nibble first. */
void tmuf_hash_file_name(const char *relative, char out[35]) {
  static const char HEX[] = "0123456789ABCDEF";
  char low[512];
  size_t n = strlen(relative);
  if (n >= sizeof low)
    n = sizeof low - 1;
  for (size_t i = 0; i < n; i++)
    low[i] = lower_char(relative[i]);
  uint8_t d[16];
  tmuf_md5_bytes(low, n, d);
  out[0] = HEX[n & 15];
  out[1] = HEX[(n >> 4) & 15];
  for (int i = 0; i < 16; i++) {
    out[2 + i * 2] = HEX[d[i] & 15];
    out[3 + i * 2] = HEX[d[i] >> 4];
  }
  out[34] = 0;
}

tmuf_pack_ref tmuf_packset_find(const tmuf_packset *set, const char *plain) {
  tmuf_pack_ref r = tmuf_packset_find_stored(set, plain);
  if (r.pack >= 0)
    return r;
  /* Try every parent folder as the base of the hidden name. */
  char buf[600];
  for (const char *s = plain; *s; s++) {
    if (*s != '\\')
      continue;
    size_t base = (size_t)(s - plain) + 1;
    if (base + 35 >= sizeof buf)
      break;
    memcpy(buf, plain, base);
    tmuf_hash_file_name(plain + base, buf + base);
    r = tmuf_packset_find_stored(set, buf);
    if (r.pack >= 0)
      return r;
  }
  return r;
}

tmuf_pack_ref tmuf_packset_resolve(const tmuf_packset *set, const tmuf_gbx *g, const tmuf_gbx_node *node,
                                   const char *from, char *plain_out, size_t plain_out_size) {
  tmuf_pack_ref none = {-1, 0};
  char dir[512];
  snprintf(dir, sizeof dir, "%s", from);
  char *slash = strrchr(dir, '\\');
  if (slash)
    slash[1] = 0;
  else
    dir[0] = 0;
  /* A hashed file's real directory may be deeper than its stored one by up
     to ancestor_level folders; try each depth, the shallowest assumption
     (real directory == stored directory) first. */
  tmuf_gbx g2 = *g;
  for (uint32_t hidden = 0; hidden <= g->ancestor_level; hidden++) {
    g2.ancestor_level = g->ancestor_level - hidden;
    char path[600];
    if (!tmuf_gbx_external_path(&g2, node, dir, path, sizeof path))
      continue;
    tmuf_pack_ref r = tmuf_packset_find(set, path);
    if (r.pack >= 0) {
      if (plain_out && plain_out_size)
        snprintf(plain_out, plain_out_size, "%s", path);
      return r;
    }
  }
  return none;
}

/* path (in out, '/' separated) made to exist on disk: each component after
   the base matched case-insensitively (Windows needs no help) */
static int find_on_disk(char *out, size_t out_size, size_t base_len) {
#ifdef _WIN32
  (void)base_len;
  (void)out_size;
  FILE *f = fopen(out, "rb");
  if (!f)
    return 0;
  fclose(f);
  return 1;
#else
  char built[1200];
  if (base_len >= sizeof built)
    return 0;
  memcpy(built, out, base_len);
  built[base_len] = 0;
  const char *p = out + base_len;
  while (*p) {
    while (*p == '/')
      p++;
    const char *end = strchr(p, '/');
    size_t n = end ? (size_t)(end - p) : strlen(p);
    if (!n)
      break;
    DIR *d = opendir(built[0] ? built : ".");
    if (!d)
      return 0;
    const struct dirent *e;
    int found = 0;
    while ((e = readdir(d)) != NULL) {
      if (strlen(e->d_name) != n)
        continue;
      size_t k = 0;
      while (k < n && tolower((unsigned char)e->d_name[k]) == tolower((unsigned char)p[k]))
        k++;
      if (k == n) {
        size_t len = strlen(built);
        if (len + 1 + n + 1 > sizeof built) {
          closedir(d);
          return 0;
        }
        built[len] = '/';
        memcpy(built + len + 1, e->d_name, n);
        built[len + 1 + n] = 0;
        found = 1;
        break;
      }
    }
    closedir(d);
    if (!found)
      return 0;
    p += n;
  }
  if (strlen(built) + 1 > out_size)
    return 0;
  memcpy(out, built, strlen(built) + 1);
  return 1;
#endif
}

/* dir/<up to depth folders>/rel on disk (case-insensitive): the first found */
static int find_below(const char *dir, const char *rel, int depth, char *out, size_t out_size) {
  char full[2048];
  const int len = snprintf(full, sizeof full, "%s/%s", dir, rel);
  if (len < 0 || (size_t)len >= sizeof full)
    return 0;
  if (find_on_disk(full, sizeof full, strlen(dir))) {
    snprintf(out, out_size, "%s", full);
    return 1;
  }
  if (depth <= 0)
    return 0;
#ifdef _WIN32
  char pattern[1200];
  snprintf(pattern, sizeof pattern, "%s/*", dir);
  WIN32_FIND_DATAA fd;
  HANDLE h = FindFirstFileA(pattern, &fd);
  if (h == INVALID_HANDLE_VALUE)
    return 0;
  int found = 0;
  do {
    if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) || fd.cFileName[0] == '.')
      continue;
    char sub[1200];
    const int sn = snprintf(sub, sizeof sub, "%s/%s", dir, fd.cFileName);
    if (sn < 0 || (size_t)sn >= sizeof sub)
      continue;
    found = find_below(sub, rel, depth - 1, out, out_size);
  } while (!found && FindNextFileA(h, &fd));
  FindClose(h);
  return found;
#else
  DIR *d = opendir(dir);
  if (!d)
    return 0;
  int found = 0;
  const struct dirent *e;
  while (!found && (e = readdir(d)) != NULL) {
    if (e->d_name[0] == '.')
      continue;
    char sub[1200];
    const int sn = snprintf(sub, sizeof sub, "%s/%s", dir, e->d_name);
    if (sn < 0 || (size_t)sn >= sizeof sub)
      continue;
    DIR *probe = opendir(sub);
    if (!probe)
      continue;
    closedir(probe);
    found = find_below(sub, rel, depth - 1, out, out_size);
  }
  closedir(d);
  return found;
#endif
}

int tmuf_packset_find_file(const tmuf_packset *set, const char *plain, char *out, size_t out_size) {
  char base[1100];
  snprintf(base, sizeof base, "%s", set->dir);
  size_t bl = strlen(base);
  while (bl > 0 && (base[bl - 1] == '/' || base[bl - 1] == '\\'))
    base[--bl] = 0;
  while (bl > 0 && base[bl - 1] != '/' && base[bl - 1] != '\\')
    bl--;
  snprintf(base + bl, sizeof base - bl, "GameData");
  char full[1200];
  int n = snprintf(full, sizeof full, "%s/%s", base, plain);
  if (n < 0 || (size_t)n >= sizeof full)
    return 0;
  for (char *c = full + strlen(base); *c; c++)
    if (*c == '\\')
      *c = '/';
  if (!find_on_disk(full, sizeof full, strlen(base)))
    return 0;
  snprintf(out, out_size, "%s", full);
  return 1;
}

int tmuf_packset_resolve_file(const tmuf_packset *set, const tmuf_gbx *g, const tmuf_gbx_node *node, const char *from,
                              char *out, size_t out_size) {
  if (!node || !node->external)
    return 0;
  char dir[512];
  snprintf(dir, sizeof dir, "%s", from);
  char *slash = strrchr(dir, '\\');
  if (slash)
    slash[1] = 0;
  else
    dir[0] = 0;
  /* GameData beside the Packs directory */
  char base[1100];
  snprintf(base, sizeof base, "%s", set->dir);
  size_t bl = strlen(base);
  while (bl > 0 && (base[bl - 1] == '/' || base[bl - 1] == '\\'))
    base[--bl] = 0;
  while (bl > 0 && base[bl - 1] != '/' && base[bl - 1] != '\\')
    bl--;
  snprintf(base + bl, sizeof base - bl, "GameData");
  tmuf_gbx g2 = *g;
  for (uint32_t hidden = 0; hidden <= g->ancestor_level; hidden++) {
    g2.ancestor_level = g->ancestor_level - hidden;
    char path[600];
    if (!tmuf_gbx_external_path(&g2, node, dir, path, sizeof path))
      continue;
    char full[1200];
    int n = snprintf(full, sizeof full, "%s/%s", base, path);
    if (n < 0 || (size_t)n >= sizeof full)
      continue;
    for (char *c = full + strlen(base); *c; c++)
      if (*c == '\\')
        *c = '/';
    if (find_on_disk(full, sizeof full, strlen(base))) {
      snprintf(out, out_size, "%s", full);
      return 1;
    }
  }
  /* A hashed file's real folder is unknown: the reference may be relative to
     a folder below its stored one. Look for it up to three levels deeper. */
  char path[600];
  g2.ancestor_level = g->ancestor_level;
  if (!tmuf_gbx_external_path(&g2, node, "", path, sizeof path))
    return 0;
  for (char *c = path; *c; c++)
    if (*c == '\\')
      *c = '/';
  char start[1200];
  snprintf(start, sizeof start, "%s/%s", base, dir);
  for (char *c = start + strlen(base); *c; c++)
    if (*c == '\\')
      *c = '/';
  size_t sl = strlen(start);
  while (sl > 0 && start[sl - 1] == '/')
    start[--sl] = 0;
  if (!find_on_disk(start, sizeof start, strlen(base)))
    return 0;
  return find_below(start, path, 3, out, out_size);
}
