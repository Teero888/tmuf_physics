#include "common/gbx.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "common/class_id_table.h"
#include "common/chunk_info_table.h"
#include "common/class_tree.h"
#include "common/compress.h"

#define MAX_STRING (16u * 1024u * 1024u)
#define MAX_NODES (1u << 24)

/* ---- sources ---- */

static int mem_read(tmuf_source *s, void *out, size_t n) {
  tmuf_mem_source *m = (tmuf_mem_source *)s;
  if (n > m->size - m->pos)
    return 0;
  memcpy(out, m->data + m->pos, n);
  m->pos += n;
  return 1;
}

void tmuf_mem_source_init(tmuf_mem_source *s, const uint8_t *data, size_t size) {
  s->base.read = mem_read;
  s->base.mix = NULL;
  s->data = data;
  s->size = size;
  s->pos = 0;
}

/* ---- class ids ---- */

static uint32_t table_lookup(const uint32_t (*table)[2], size_t n, uint32_t key) {
  size_t lo = 0, hi = n;
  while (lo < hi) {
    size_t mid = (lo + hi) / 2;
    if (table[mid][0] < key)
      lo = mid + 1;
    else
      hi = mid;
  }
  return lo < n && table[lo][0] == key ? table[lo][1] : key;
}

uint32_t tmuf_wrap_class_id(uint32_t id) {
  return table_lookup(TMUF_WRAP_CLASS_ID, sizeof TMUF_WRAP_CLASS_ID / sizeof TMUF_WRAP_CLASS_ID[0], id);
}

uint32_t tmuf_unwrap_class_id(uint32_t id) {
  return table_lookup(TMUF_UNWRAP_CLASS_ID, sizeof TMUF_UNWRAP_CLASS_ID / sizeof TMUF_UNWRAP_CLASS_ID[0], id);
}

static const tmuf_class_info *class_info(uint32_t id) {
  size_t lo = 0, hi = sizeof TMUF_CLASSES / sizeof TMUF_CLASSES[0];
  while (lo < hi) {
    size_t mid = (lo + hi) / 2;
    if (TMUF_CLASSES[mid].id < id)
      lo = mid + 1;
    else
      hi = mid;
  }
  return lo < sizeof TMUF_CLASSES / sizeof TMUF_CLASSES[0] && TMUF_CLASSES[lo].id == id ? &TMUF_CLASSES[lo] : NULL;
}

uint32_t tmuf_class_parent(uint32_t id) {
  const tmuf_class_info *c = class_info(id);
  return c ? c->parent : 0xffffffffu;
}

const char *tmuf_class_name(uint32_t id) {
  const tmuf_class_info *c = class_info(id);
  return c ? c->name : "?";
}

/* ---- reader ---- */

void tmuf_gbx_init(tmuf_gbx *g, tmuf_source *src, tmuf_arena *arena, const tmuf_gbx_class *const *classes,
                   size_t class_count) {
  memset(g, 0, sizeof *g);
  g->src = src;
  g->arena = arena;
  g->classes = classes;
  g->class_count = class_count;
  g->chunk_size = 0xffffffffu;
}

void **tmuf_gbx_internal_ref(tmuf_gbx *g, uint32_t index) {
  if (index >= 0x100000u) {
    tmuf_gbx_fail(g, "internal reference %u", index);
    return NULL;
  }
  if (index >= g->internal_ref_cap) {
    uint32_t cap = g->internal_ref_cap ? g->internal_ref_cap : 16;
    while (cap <= index)
      cap *= 2;
    void **refs = TMUF_ARENA_ARRAY(g->arena, void *, cap);
    if (!refs) {
      tmuf_gbx_fail(g, "out of memory");
      return NULL;
    }
    memset(refs, 0, sizeof *refs * cap);
    if (g->internal_ref_cap)
      memcpy(refs, g->internal_refs, sizeof *refs * g->internal_ref_cap);
    g->internal_refs = refs;
    g->internal_ref_cap = cap;
  }
  return &g->internal_refs[index];
}

void tmuf_gbx_fail(tmuf_gbx *g, const char *fmt, ...) {
  if (g->error)
    return;
  g->error = 1;
  va_list ap;
  va_start(ap, fmt);
  int n = snprintf(g->message, sizeof g->message, "@%llu: ", (unsigned long long)g->pos);
  if (n > 0 && (size_t)n < sizeof g->message)
    vsnprintf(g->message + n, sizeof g->message - (size_t)n, fmt, ap);
  va_end(ap);
}

int tmuf_gbx_read(tmuf_gbx *g, void *out, size_t n) {
  if (g->error) {
    memset(out, 0, n);
    return 0;
  }
  uint8_t *o = out;
  while (g->peeked && n > 0) {
    *o++ = g->peek_buf[4 - g->peeked];
    g->peeked--;
    n--;
    g->pos++;
  }
  if (n == 0)
    return 1;
  if (!g->src->read(g->src, o, n)) {
    memset(o, 0, n);
    tmuf_gbx_fail(g, "read past end (%zu bytes)", n);
    return 0;
  }
  g->pos += n;
  return 1;
}

int tmuf_gbx_skip(tmuf_gbx *g, size_t n) {
  uint8_t buf[256];
  while (n > 0 && !g->error) {
    size_t k = n < sizeof buf ? n : sizeof buf;
    tmuf_gbx_read(g, buf, k);
    n -= k;
  }
  return !g->error;
}

uint32_t tmuf_gbx_peek_u32(tmuf_gbx *g) {
  if (g->error)
    return 0;
  uint8_t b[4];
  int have = g->peeked;
  for (int i = 0; i < have; i++)
    b[i] = g->peek_buf[4 - have + i];
  if (have < 4 && !g->src->read(g->src, b + have, (size_t)(4 - have))) {
    tmuf_gbx_fail(g, "peek past end");
    return 0;
  }
  memcpy(g->peek_buf, b, 4);
  g->peeked = 4;
  return (uint32_t)b[0] | (uint32_t)b[1] << 8 | (uint32_t)b[2] << 16 | (uint32_t)b[3] << 24;
}

uint8_t tmuf_gbx_u8(tmuf_gbx *g) {
  uint8_t v;
  tmuf_gbx_read(g, &v, 1);
  return v;
}

uint16_t tmuf_gbx_u16(tmuf_gbx *g) {
  uint8_t b[2];
  tmuf_gbx_read(g, b, 2);
  return (uint16_t)(b[0] | b[1] << 8);
}

uint32_t tmuf_gbx_u32(tmuf_gbx *g) {
  uint8_t b[4];
  tmuf_gbx_read(g, b, 4);
  return (uint32_t)b[0] | (uint32_t)b[1] << 8 | (uint32_t)b[2] << 16 | (uint32_t)b[3] << 24;
}

uint64_t tmuf_gbx_u64(tmuf_gbx *g) {
  uint64_t lo = tmuf_gbx_u32(g);
  return lo | (uint64_t)tmuf_gbx_u32(g) << 32;
}

float tmuf_gbx_f32(tmuf_gbx *g) {
  uint32_t v = tmuf_gbx_u32(g);
  float f;
  memcpy(&f, &v, 4);
  return f;
}

int tmuf_gbx_bool(tmuf_gbx *g) { return tmuf_gbx_u32(g) != 0; }

const char *tmuf_gbx_string(tmuf_gbx *g) {
  uint32_t n = tmuf_gbx_u32(g);
  if (g->error)
    return "";
  if (n > (uint32_t)MAX_STRING) {
    tmuf_gbx_fail(g, "string length %u", n);
    return "";
  }
  char *s = tmuf_arena_alloc(g->arena, (size_t)n + 1);
  if (!s) {
    tmuf_gbx_fail(g, "out of memory");
    return "";
  }
  tmuf_gbx_read(g, s, n);
  return g->error ? "" : s;
}

const char *tmuf_gbx_id(tmuf_gbx *g, uint32_t *number) {
  if (number)
    *number = 0;
  if (!g->id_version_read) {
    uint32_t version = tmuf_gbx_u32(g);
    if (version != 3) {
      tmuf_gbx_fail(g, "lookback version %u", version);
      return "";
    }
    g->id_version_read = 1;
  }
  uint32_t v = tmuf_gbx_u32(g);
  if (g->error)
    return "";
  if (v == 0xffffffffu)
    return "";
  if ((v & 0xc0000000u) == 0) {
    /* Numeric id (collection / engine ids), no string. */
    if (number)
      *number = v;
    return NULL;
  }
  uint32_t index = v & 0x3fffffffu;
  if (index == 0) {
    const char *s = tmuf_gbx_string(g);
    if (g->error)
      return "";
    if (g->id_count == g->id_cap) {
      uint32_t cap = g->id_cap ? g->id_cap * 2 : 64;
      const char **ids = TMUF_ARENA_ARRAY(g->arena, const char *, cap);
      if (!ids) {
        tmuf_gbx_fail(g, "out of memory");
        return "";
      }
      if (g->id_count)
        memcpy(ids, g->ids, sizeof *ids * g->id_count);
      g->ids = ids;
      g->id_cap = cap;
    }
    g->ids[g->id_count++] = s;
    return s;
  }
  if (index > g->id_count) {
    tmuf_gbx_fail(g, "lookback index %u of %u", index, g->id_count);
    return "";
  }
  return g->ids[index - 1];
}

/* Reader for a class, or for its nearest ancestor that has one (e.g.
   CTrackManiaReplayRecord is read as CGameCtnReplayRecord). */
static const tmuf_gbx_class *find_class(const tmuf_gbx *g, uint32_t id) {
  for (int depth = 0; depth < 32 && id != 0 && id != 0xffffffffu; depth++) {
    for (size_t i = 0; i < g->class_count; i++)
      if (g->classes[i]->id == id)
        return g->classes[i];
    id = tmuf_class_parent(id);
  }
  return NULL;
}

static const tmuf_gbx_chunk *find_chunk(const tmuf_gbx_class *cls, uint32_t id, tmuf_gbx_chunk *scratch) {
  for (; cls; cls = cls->base) {
    for (size_t i = 0; i < cls->chunk_count; i++)
      if (cls->chunks[i].id == id)
        return &cls->chunks[i];
    if (cls->accepts && cls->accepts(id)) {
      scratch->id = id;
      scratch->skippable = TMUF_GBX_MAYBE_SKIP;
      scratch->read = cls->generic;
      return scratch;
    }
  }
  return NULL;
}

/* CMwNod::Archive: at the start of every node the game mixes the unwrapped
   id of the node's parent class into the stream feedback. */
static void node_feedback(tmuf_gbx *g, uint32_t class_id) {
  if (!g->feedback || !g->src->mix || g->error)
    return;
  uint32_t parent = tmuf_class_parent(class_id);
  if (parent == 0xffffffffu) {
    tmuf_gbx_fail(g, "class %08x not in class tree", class_id);
    return;
  }
  if (parent == 0)
    return;
  uint32_t v = tmuf_unwrap_class_id(parent);
  if (v == 0x07031000u)
    v = 0x07001000u;
  uint8_t b[4] = {(uint8_t)v, (uint8_t)(v >> 8), (uint8_t)(v >> 16), (uint8_t)(v >> 24)};
  g->src->mix(g->src, b, 4);
}

void tmuf_gbx_mix_u32(tmuf_gbx *g, uint32_t v) {
  if (!g->feedback || !g->src->mix || g->error)
    return;
  uint8_t b[4] = {(uint8_t)v, (uint8_t)(v >> 8), (uint8_t)(v >> 16), (uint8_t)(v >> 24)};
  g->src->mix(g->src, b, 4);
}

void tmuf_gbx_node_body(tmuf_gbx *g, const tmuf_gbx_class *cls, void *node) {
  tmuf_gbx_node_body_as(g, cls, cls->id, node);
}

#define CHUNK_UNKNOWN 0xfacade01u

/* GetChunkInfo of the node's actual class (generated from the game). */
uint32_t tmuf_chunk_info(uint32_t class_id, uint32_t chunk_id) {
  for (size_t i = 0; i < sizeof TMUF_CHUNK_INFO_OVERRIDE / sizeof TMUF_CHUNK_INFO_OVERRIDE[0]; i++)
    if (TMUF_CHUNK_INFO_OVERRIDE[i][1] == chunk_id) {
      for (uint32_t c = class_id, depth = 0; c && c != 0xffffffffu && depth < 32; c = tmuf_class_parent(c), depth++)
        if (TMUF_CHUNK_INFO_OVERRIDE[i][0] == c)
          return TMUF_CHUNK_INFO_OVERRIDE[i][2];
    }
  size_t lo = 0, hi = sizeof TMUF_CHUNK_INFO / sizeof TMUF_CHUNK_INFO[0];
  while (lo < hi) {
    size_t mid = (lo + hi) / 2;
    if (TMUF_CHUNK_INFO[mid][0] < chunk_id)
      lo = mid + 1;
    else
      hi = mid;
  }
  if (lo < sizeof TMUF_CHUNK_INFO / sizeof TMUF_CHUNK_INFO[0] && TMUF_CHUNK_INFO[lo][0] == chunk_id)
    return TMUF_CHUNK_INFO[lo][1];
  return CHUNK_UNKNOWN;
}

/*
 * CMwNod::Archive, reading (TMUF 0x92430c). For each chunk id the class's
 * GetChunkInfo decides: unknown, or skippable but not parsed -> the next
 * word must be "PIKS" + size (skipped) or the node ends with that word
 * consumed; skippable and parsed -> "PIKS" + size, then Chunk(); else
 * Chunk(). No peeking: reading ahead would decrypt a pack page before the
 * game has mixed node feedback into it.
 */
void tmuf_gbx_node_body_as(tmuf_gbx *g, const tmuf_gbx_class *cls, uint32_t class_id, void *node) {
  uint32_t saved_class = g->node_class;
  g->node_class = class_id;
  node_feedback(g, class_id);
  for (int guard = 0; guard < 100000 && !g->error && !g->stop; guard++) {
    uint32_t raw = tmuf_gbx_u32(g);
    if (g->error || raw == TMUF_GBX_FACADE)
      break;
    uint32_t id = tmuf_wrap_chunk_id(raw);
    uint32_t info = tmuf_chunk_info(class_id, id);
    if (info == CHUNK_UNKNOWN || (!(info & 1) && (info & 0x10))) {
      if (tmuf_gbx_u32(g) != TMUF_GBX_SKIP)
        break;
      tmuf_gbx_skip(g, tmuf_gbx_u32(g));
      continue;
    }
    tmuf_gbx_chunk scratch;
    const tmuf_gbx_chunk *c = find_chunk(cls, id, &scratch);
    if (!c && (info & 0x10)) {
      /* Skippable chunk nothing here needs: skip it by its size. */
      if (tmuf_gbx_u32(g) != TMUF_GBX_SKIP) {
        tmuf_gbx_fail(g, "%s: chunk %08x missing PIKS", cls->name, id);
        break;
      }
      tmuf_gbx_skip(g, tmuf_gbx_u32(g));
      continue;
    }
    if (!c) {
      tmuf_gbx_fail(g, "%s (%08x): no reader for chunk %08x (info %x)", cls->name, class_id, id, info);
      break;
    }
    uint32_t size = 0xffffffffu;
    if (info & 0x10) {
      if (tmuf_gbx_u32(g) != TMUF_GBX_SKIP) {
        tmuf_gbx_fail(g, "%s: chunk %08x missing PIKS", cls->name, id);
        break;
      }
      size = tmuf_gbx_u32(g);
    }
    uint64_t start = g->pos;
    g->chunk_size = size;
    if (c->read)
      c->read(g, node, id);
    g->chunk_size = 0xffffffffu;
    if (!g->error && size != 0xffffffffu && g->pos - start != size)
      tmuf_gbx_fail(g, "%s: chunk %08x read %llu of %u bytes", cls->name, id, (unsigned long long)(g->pos - start),
                    size);
  }
  g->node_class = saved_class;
}

static tmuf_gbx_node *new_inline_node(tmuf_gbx *g, uint32_t index, uint32_t class_id) {
  const tmuf_gbx_class *cls = find_class(g, class_id);
  if (!cls) {
    tmuf_gbx_fail(g, "no reader for class %08x (%s)", class_id, tmuf_class_name(class_id));
    return NULL;
  }
  tmuf_gbx_node *n = &g->nodes[index];
  n->class_id = class_id;
  n->cls = cls;
  n->data = tmuf_arena_alloc(g->arena, cls->size ? cls->size : 1);
  if (!n->data) {
    tmuf_gbx_fail(g, "out of memory");
    return NULL;
  }
  if (cls->archive)
    cls->archive(g, n->data);
  else
    tmuf_gbx_node_body_as(g, cls, class_id, n->data);
  return n;
}

tmuf_gbx_node *tmuf_gbx_fidref(tmuf_gbx *g) {
  uint32_t index = tmuf_gbx_u32(g);
  if (g->error || index == TMUF_GBX_NULL_NODE)
    return NULL;
  if (index == 0 || index > g->node_count || !g->nodes[index].external) {
    tmuf_gbx_fail(g, "fid reference %u is not external", index);
    return NULL;
  }
  return &g->nodes[index];
}

tmuf_gbx_node *tmuf_gbx_noderef(tmuf_gbx *g) {
  uint32_t index = tmuf_gbx_u32(g);
  if (g->error || index == TMUF_GBX_NULL_NODE || index == 0xfffffffeu)
    return NULL;
  if (index == 0)
    return &g->nodes[0]; /* the root node */
  if (index > g->node_count) {
    tmuf_gbx_fail(g, "node index %u of %u", index, g->node_count);
    return NULL;
  }
  tmuf_gbx_node *n = &g->nodes[index];
  if (n->external || n->cls)
    return n;
  uint32_t class_id = tmuf_wrap_class_id(tmuf_gbx_u32(g));
  return g->error ? NULL : new_inline_node(g, index, class_id);
}

/* ---- header ---- */

/* Reference table folders, flattened depth first, 1-based. */
static int read_folders(tmuf_gbx *g, uint32_t parent, unsigned depth) {
  uint32_t count = tmuf_gbx_u32(g);
  if (count > 4096 || depth > 32) {
    tmuf_gbx_fail(g, "reference folders");
    return 0;
  }
  for (uint32_t i = 0; i < count && !g->error; i++) {
    const char *name = tmuf_gbx_string(g);
    if (g->folder_count % 64 == 0) {
      tmuf_gbx_folder *f = TMUF_ARENA_ARRAY(g->arena, tmuf_gbx_folder, (size_t)g->folder_count + 65);
      if (!f) {
        tmuf_gbx_fail(g, "out of memory");
        return 0;
      }
      if (g->folder_count)
        memcpy(f, g->folders, sizeof *f * ((size_t)g->folder_count + 1));
      g->folders = f;
    }
    uint32_t index = ++g->folder_count;
    g->folders[index].name = name;
    g->folders[index].parent = parent;
    read_folders(g, index, depth + 1);
  }
  return !g->error;
}

static int append(char *out, size_t out_size, const char *s) {
  size_t n = strlen(out), k = strlen(s);
  if (n + k >= out_size)
    return 0;
  memcpy(out + n, s, k + 1);
  return 1;
}

static int append_folder(const tmuf_gbx *g, uint32_t folder, char *out, size_t out_size, unsigned depth) {
  if (folder == 0)
    return 1;
  if (folder > g->folder_count || depth > 32)
    return 0;
  return append_folder(g, g->folders[folder].parent, out, out_size, depth + 1) &&
         append(out, out_size, g->folders[folder].name) && append(out, out_size, "\\");
}

int tmuf_gbx_external_path(const tmuf_gbx *g, const tmuf_gbx_node *n, const char *dir, char *out, size_t out_size) {
  if (!n || !n->external || !n->file || out_size == 0)
    return 0;
  out[0] = 0;
  /* Go up ancestor_level directories from dir. */
  size_t len = strlen(dir);
  if (len >= out_size)
    return 0;
  memcpy(out, dir, len + 1);
  for (uint32_t up = 0; up < g->ancestor_level; up++) {
    if (len == 0)
      return 0;
    len--; /* trailing backslash */
    while (len > 0 && out[len - 1] != '\\')
      len--;
    out[len] = 0;
  }
  return append_folder(g, n->folder, out, out_size, 0) && append(out, out_size, n->file);
}

int tmuf_gbx_read_header(tmuf_gbx *g) {
  uint8_t magic[3];
  tmuf_gbx_read(g, magic, 3);
  if (g->error || memcmp(magic, "GBX", 3) != 0) {
    tmuf_gbx_fail(g, "not a GBX file");
    return 0;
  }
  g->version = tmuf_gbx_u16(g);
  if (g->version < 3 || g->version > 6) {
    tmuf_gbx_fail(g, "GBX version %u", g->version);
    return 0;
  }
  tmuf_gbx_read(g, g->format, g->version >= 4 ? 4 : 3);
  if (g->version < 4)
    g->format[3] = 'R';
  if (g->format[0] != 'B') {
    tmuf_gbx_fail(g, "text GBX not supported");
    return 0;
  }
  g->class_id = tmuf_wrap_class_id(tmuf_gbx_u32(g));
  if (g->version >= 6) {
    uint32_t user_size = tmuf_gbx_u32(g);
    if (user_size) {
      uint64_t start = g->pos;
      uint32_t count = tmuf_gbx_u32(g);
      if (count > 256) {
        tmuf_gbx_fail(g, "header chunk count %u", count);
        return 0;
      }
      g->header_chunk_count = count;
      g->header_chunks = TMUF_ARENA_ARRAY(g->arena, tmuf_gbx_header_chunk, count ? count : 1);
      for (uint32_t i = 0; i < count; i++) {
        g->header_chunks[i].id = tmuf_wrap_chunk_id(tmuf_gbx_u32(g));
        uint32_t size = tmuf_gbx_u32(g);
        g->header_chunks[i].size = size & 0x7fffffffu;
        g->header_chunks[i].heavy = (size & 0x80000000u) != 0;
      }
      for (uint32_t i = 0; i < count && !g->error; i++) {
        uint8_t *d = tmuf_arena_alloc(g->arena, g->header_chunks[i].size ? g->header_chunks[i].size : 1);
        if (!d) {
          tmuf_gbx_fail(g, "out of memory");
          return 0;
        }
        tmuf_gbx_read(g, d, g->header_chunks[i].size);
        g->header_chunks[i].data = d;
      }
      if (!g->error && g->pos - start != user_size) {
        tmuf_gbx_fail(g, "user data size mismatch");
        return 0;
      }
    }
  }
  g->node_count = tmuf_gbx_u32(g);
  if (g->error || g->node_count > (uint32_t)MAX_NODES) {
    tmuf_gbx_fail(g, "node count %u", g->node_count);
    return 0;
  }
  g->nodes = TMUF_ARENA_ARRAY(g->arena, tmuf_gbx_node, (size_t)g->node_count + 1);
  if (!g->nodes) {
    tmuf_gbx_fail(g, "out of memory");
    return 0;
  }

  uint32_t external = tmuf_gbx_u32(g);
  if (external > g->node_count) {
    tmuf_gbx_fail(g, "external node count %u", external);
    return 0;
  }
  if (external) {
    g->ancestor_level = tmuf_gbx_u32(g);
    read_folders(g, 0, 0);
    for (uint32_t i = 0; i < external && !g->error; i++) {
      uint32_t flags = tmuf_gbx_u32(g);
      const char *file = NULL;
      uint32_t folder = 0;
      if (flags & 4)
        tmuf_gbx_u32(g); /* resource index */
      else
        file = tmuf_gbx_string(g);
      uint32_t index = tmuf_gbx_u32(g);
      if (g->version >= 5)
        tmuf_gbx_u32(g); /* use file */
      if (!(flags & 4))
        folder = tmuf_gbx_u32(g);
      if (index == 0 || index > g->node_count) {
        tmuf_gbx_fail(g, "external node index %u", index);
        return 0;
      }
      g->nodes[index].external = 1;
      g->nodes[index].file = file;
      g->nodes[index].folder = folder;
    }
  }
  if (g->error)
    return 0;

  if (g->format[2] == 'C') {
    uint32_t size = tmuf_gbx_u32(g), csize = tmuf_gbx_u32(g);
    if (g->error || size > (256u << 20) || csize > (256u << 20)) {
      tmuf_gbx_fail(g, "body sizes %u %u", size, csize);
      return 0;
    }
    uint8_t *packed = tmuf_arena_alloc(g->arena, csize ? csize : 1);
    g->body = tmuf_arena_alloc(g->arena, size ? size : 1);
    if (!packed || !g->body) {
      tmuf_gbx_fail(g, "out of memory");
      return 0;
    }
    tmuf_gbx_read(g, packed, csize);
    if (g->error)
      return 0;
    if (!tmuf_lzo1x_decompress(packed, csize, g->body, size)) {
      tmuf_gbx_fail(g, "LZO body does not decompress");
      return 0;
    }
    g->body_size = size;
    tmuf_mem_source_init(&g->body_src, g->body, size);
    g->src = &g->body_src.base;
    g->pos = 0;
  }
  return 1;
}

void *tmuf_gbx_read_root(tmuf_gbx *g) {
  const tmuf_gbx_class *cls = find_class(g, g->class_id);
  if (!cls) {
    tmuf_gbx_fail(g, "no reader for root class %08x (%s)", g->class_id, tmuf_class_name(g->class_id));
    return NULL;
  }
  void *node = tmuf_arena_alloc(g->arena, cls->size ? cls->size : 1);
  if (!node) {
    tmuf_gbx_fail(g, "out of memory");
    return NULL;
  }
  g->nodes[0].class_id = g->class_id;
  g->nodes[0].cls = cls;
  g->nodes[0].data = node;
  tmuf_gbx_node_body_as(g, cls, g->class_id, node);
  return g->error ? NULL : node;
}
