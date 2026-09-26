/* Development CLI for the parsing layer.
 *
 *   tmuf_inspect packs PACKS_DIR [PACK]      open packs, test-extract every file
 *   tmuf_inspect ls PACKS_DIR PACK           list files of one pack
 *   tmuf_inspect cat PACKS_DIR PACK PATH OUT extract one file
 *   tmuf_inspect replays FILE...            parse replays, summarise
 *   tmuf_inspect body GBX OUT               write the (decompressed) body
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common/gbx.h"
#include "common/pack.h"
#include "common/replay.h"

static uint8_t *read_file(const char *path, size_t *size) {
  FILE *f = fopen(path, "rb");
  if (!f)
    return NULL;
  fseek(f, 0, SEEK_END);
  long n = ftell(f);
  fseek(f, 0, SEEK_SET);
  uint8_t *data = malloc(n > 0 ? (size_t)n : 1);
  if (data && fread(data, 1, (size_t)n, f) != (size_t)n) {
    free(data);
    data = NULL;
  }
  fclose(f);
  *size = (size_t)n;
  return data;
}

static int load_packlist(const char *dir, tmuf_packlist *list) {
  char path[1024];
  size_t size;
  snprintf(path, sizeof path, "%s/packlist.dat", dir);
  uint8_t *data = read_file(path, &size);
  if (!data) {
    fprintf(stderr, "cannot read %s\n", path);
    return 0;
  }
  int ok = tmuf_packlist_parse(data, size, "", list);
  free(data);
  if (!ok)
    fprintf(stderr, "packlist.dat did not verify\n");
  return ok;
}

static int open_pack(const char *dir, const tmuf_packlist *list, const char *name, tmuf_pack *pack) {
  char path[1024];
  size_t size;
  snprintf(path, sizeof path, "%s/%s.pak", dir, name);
  uint8_t *data = read_file(path, &size);
  if (!data) {
    /* Pack names in packlist.dat are lower case; files may not be. */
    snprintf(path, sizeof path, "%s/%c%s.pak", dir, name[0] - 'a' + 'A', name + 1);
    data = read_file(path, &size);
  }
  if (!data)
    return 0;
  return tmuf_pack_open(pack, data, size, list, name);
}

static void test_pack(const char *dir, const tmuf_packlist *list, const char *name) {
  tmuf_pack pack;
  if (!open_pack(dir, list, name, &pack)) {
    printf("%-12s open FAILED\n", name);
    return;
  }
  uint32_t ok = 0, fail = 0, enc = 0, comp = 0;
  uint32_t fail_classes[64], fail_class_counts[64];
  unsigned nclasses = 0;
  for (uint32_t i = 0; i < pack.file_count; i++) {
    const tmuf_pack_file *f = &pack.files[i];
    enc += tmuf_pack_file_encrypted(f);
    comp += tmuf_pack_file_compressed(f);
    uint8_t *data;
    size_t size;
    int good = tmuf_pack_extract(&pack, i, &data, &size);
    /* Uncompressed files have no checksum; require a GBX magic instead. */
    if (good && !tmuf_pack_file_compressed(f) && (size < 3 || memcmp(data, "GBX", 3) != 0))
      good = 0;
    free(data);
    if (good) {
      ok++;
      continue;
    }
    fail++;
    unsigned c = 0;
    while (c < nclasses && fail_classes[c] != f->class_id)
      c++;
    if (c == nclasses && nclasses < 64) {
      fail_classes[nclasses] = f->class_id;
      fail_class_counts[nclasses++] = 0;
    }
    if (c < 64)
      fail_class_counts[c]++;
  }
  printf("%-12s files %6u  encrypted %6u  compressed %6u  extract ok %6u  failed %6u\n", name, pack.file_count, enc,
         comp, ok, fail);
  for (unsigned c = 0; c < nclasses; c++)
    printf("    failed class 0x%08x: %u\n", fail_classes[c], fail_class_counts[c]);
  tmuf_pack_close(&pack);
}

static int cmd_replays(int argc, char **argv) {
  int ok = 0, failed = 0;
  int verbose = argc == 1;
  for (int i = 0; i < argc; i++) {
    size_t size;
    uint8_t *data = read_file(argv[i], &size);
    if (!data) {
      printf("FAIL %s: cannot read\n", argv[i]);
      failed++;
      continue;
    }
    tmuf_arena arena;
    tmuf_arena_init(&arena);
    tmuf_replay_file r;
    char err[256];
    if (!tmuf_replay_parse(data, size, &arena, &r, err, sizeof err)) {
      printf("FAIL %s: %s\n", argv[i], err);
      failed++;
    } else {
      ok++;
      const tmuf_ghost *gh = r.ghosts[0];
      if (verbose) {
        printf("challenge %u bytes, %u ghost(s)\n", r.challenge_size, r.ghost_count);
        printf("race time %u, respawns %u, stunts %u, vehicle %s/%s/%s\n", gh->race_time, gh->respawns,
               gh->stunt_score, gh->vehicle[0], gh->vehicle[1], gh->vehicle[2]);
        printf("inputs: duration %u, version %u, %u events, seed %u, actions:", gh->input_duration,
               gh->input_version, gh->event_count, gh->validation_seed);
        for (uint32_t a = 0; a < gh->action_count; a++)
          printf(" %s", gh->actions[a]);
        printf("\n");
        for (uint32_t e = 0; e < gh->event_count && e < 12; e++)
          printf("  %8u %-12s %08x\n", gh->events[e].time,
                 gh->events[e].action < gh->action_count ? gh->actions[gh->events[e].action] : "?",
                 gh->events[e].value);
      } else if (!gh->has_inputs) {
        printf("NOINPUT %s\n", argv[i]);
      }
    }
    tmuf_arena_free(&arena);
    free(data);
  }
  printf("replays: %d ok, %d failed\n", ok, failed);
  return failed != 0;
}

static int cmd_body(const char *in, const char *out) {
  size_t size;
  uint8_t *data = read_file(in, &size);
  if (!data)
    return 1;
  tmuf_arena arena;
  tmuf_arena_init(&arena);
  tmuf_mem_source src;
  tmuf_mem_source_init(&src, data, size);
  tmuf_gbx g;
  tmuf_gbx_init(&g, &src.base, &arena, NULL, 0);
  int ok = tmuf_gbx_read_header(&g);
  if (ok) {
    tmuf_mem_source *body = (tmuf_mem_source *)g.src;
    FILE *f = fopen(out, "wb");
    fwrite(body->data + body->pos, 1, body->size - body->pos, f);
    fclose(f);
    printf("class %08x (%s), %u nodes, body %zu bytes\n", g.class_id, tmuf_class_name(g.class_id), g.node_count,
           body->size - body->pos);
  } else {
    printf("%s\n", g.message);
  }
  tmuf_arena_free(&arena);
  free(data);
  return !ok;
}

int main(int argc, char **argv) {
  if (argc >= 4 && strcmp(argv[1], "body") == 0)
    return cmd_body(argv[2], argv[3]);
  if (argc >= 2 && strcmp(argv[1], "replays") == 0)
    return cmd_replays(argc - 2, argv + 2);
  if (argc < 3) {
    fprintf(stderr, "usage: see source\n");
    return 2;
  }
  tmuf_packlist list;
  if (!load_packlist(argv[2], &list))
    return 1;
  if (strcmp(argv[1], "packs") == 0) {
    for (int i = 0; i < list.count; i++)
      if (argc < 4 || strcmp(argv[3], list.entries[i].name) == 0)
        test_pack(argv[2], &list, list.entries[i].name);
    return 0;
  }
  tmuf_pack pack;
  if (argc < 4 || !open_pack(argv[2], &list, argv[3], &pack)) {
    fprintf(stderr, "cannot open pack\n");
    return 1;
  }
  if (strcmp(argv[1], "ls") == 0) {
    char path[512];
    for (uint32_t i = 0; i < pack.file_count; i++) {
      const tmuf_pack_file *f = &pack.files[i];
      tmuf_pack_file_path(&pack, i, path, sizeof path);
      printf("%08x %c%c %9u %s\n", f->class_id, tmuf_pack_file_encrypted(f) ? 'E' : '-',
             tmuf_pack_file_compressed(f) ? 'Z' : '-', f->uncompressed_size, path);
    }
  } else if (strcmp(argv[1], "cat") == 0 && argc >= 6) {
    long idx = tmuf_pack_find(&pack, argv[4]);
    uint8_t *data;
    size_t size;
    if (idx < 0 || !tmuf_pack_extract(&pack, (uint32_t)idx, &data, &size)) {
      fprintf(stderr, "extract failed\n");
      return 1;
    }
    FILE *f = fopen(argv[5], "wb");
    fwrite(data, 1, size, f);
    fclose(f);
    free(data);
  }
  tmuf_pack_close(&pack);
  return 0;
}
