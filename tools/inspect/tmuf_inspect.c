/* Development CLI for the parsing layer.
 *
 *   tmuf_inspect packs PACKS_DIR [PACK]      open packs, test-extract every file
 *   tmuf_inspect ls PACKS_DIR PACK           list files of one pack
 *   tmuf_inspect cat PACKS_DIR PACK PATH OUT extract one file
 *   tmuf_inspect replays FILE...            parse replays, summarise
 *   tmuf_inspect body GBX OUT               write the (decompressed) body
 *   tmuf_inspect map REPLAY OUT             write the embedded challenge GBX
 *   tmuf_inspect gbx PACKS_DIR PACK PATH    parse a pack file with feedback,
 *                                           print header info and mixed values
 *   tmuf_inspect vehicle PACKS_DIR NAME     print a vehicle's solid tree
 *   tmuf_inspect refs PACKS_DIR LIST        resolve the external references of
 *                                           every file in LIST (verify format)
 *   tmuf_inspect verify PACKS_DIR LIST      LIST lines: "pack<TAB>path<TAB>hex..."
 *                                           (expected mixes from an oracle
 *                                           trace); parse and compare each
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common/challenge.h"
#include "common/scene.h"
#include "common/assets.h"
#include "common/vehicle.h"
#include "common/vehicle_tuning.h"
#include "common/gbx.h"
#include "common/pack.h"
#include "common/pack_classes.h"
#include "common/packset.h"
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
      tmuf_challenge c;
      if (!tmuf_challenge_parse(r.challenge, r.challenge_size, &arena, &c, err, sizeof err)) {
        printf("FAIL %s: challenge: %s\n", argv[i], err);
        failed++;
        tmuf_arena_free(&arena);
        free(data);
        continue;
      }
      ok++;
      if (verbose) {
        printf("map \"%s\" %s/%s/%s, decoration %s/%s/%s, size %ux%ux%u, %u blocks (v%u), vehicle %s, laps %u%s\n",
               c.name, c.map[0], c.map[1], c.map[2], c.decoration[0], c.decoration[1], c.decoration[2], c.size[0],
               c.size[1], c.size[2], c.block_count, c.block_version, c.vehicle[0], c.laps, c.lap_race ? " (lap race)" : "");
        for (uint32_t b = 0; b < c.block_count && b < 6; b++)
          printf("  %-28s dir %u at %u,%u,%u flags %08x\n", c.blocks[b].name, c.blocks[b].dir, c.blocks[b].x,
                 c.blocks[b].y, c.blocks[b].z, c.blocks[b].flags);
      }
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

static int cmd_map(const char *in, const char *out) {
  size_t size;
  uint8_t *data = read_file(in, &size);
  if (!data)
    return 1;
  tmuf_arena arena;
  tmuf_arena_init(&arena);
  tmuf_replay_file r;
  char err[256];
  int ok = tmuf_replay_parse(data, size, &arena, &r, err, sizeof err);
  if (ok) {
    FILE *f = fopen(out, "wb");
    fwrite(r.challenge, 1, r.challenge_size, f);
    fclose(f);
  } else {
    printf("%s\n", err);
  }
  tmuf_arena_free(&arena);
  free(data);
  return !ok;
}

/* Records every value mixed into the stream, then forwards it. */
typedef struct logging_source {
  tmuf_source base;
  tmuf_source *inner;
  uint8_t seen[1 << 20]; /* first MiB of plain bytes read, for dumps */
  size_t seen_size;
  uint32_t mixes[65536];
  size_t mix_count;
  uint64_t *pos;
  uint64_t mix_pos[65536];
} logging_source;

static int log_read(tmuf_source *s, void *out, size_t n) {
  logging_source *l = (logging_source *)s;
  int ok = l->inner->read(l->inner, out, n);
  if (ok) {
    size_t k = n < sizeof l->seen - l->seen_size ? n : sizeof l->seen - l->seen_size;
    memcpy(l->seen + l->seen_size, out, k);
    l->seen_size += k;
  }
  return ok;
}

static void log_mix(tmuf_source *s, const uint8_t *b, size_t n) {
  logging_source *l = (logging_source *)s;
  if (n == 4 && l->mix_count < 65536) {
    l->mix_pos[l->mix_count] = *l->pos;
    l->mixes[l->mix_count++] = (uint32_t)b[0] | (uint32_t)b[1] << 8 | (uint32_t)b[2] << 16 | (uint32_t)b[3] << 24;
  }
  l->inner->mix(l->inner, b, n);
}

static int cmd_gbx(const char *dir, const char *pack_name, const char *path) {
  tmuf_packlist list;
  tmuf_pack pack;
  if (!load_packlist(dir, &list) || !open_pack(dir, &list, pack_name, &pack)) {
    fprintf(stderr, "cannot open pack\n");
    return 1;
  }
  long idx = tmuf_pack_find(&pack, path);
  tmuf_pack_stream ps;
  if (idx < 0 || !tmuf_pack_stream_open(&ps, &pack, (uint32_t)idx)) {
    fprintf(stderr, "cannot open %s\n", path);
    return 1;
  }
  static logging_source ls;
  memset(&ls, 0, sizeof ls);
  ls.base.read = log_read;
  ls.base.mix = log_mix;
  ls.inner = &ps.base;
  tmuf_arena arena;
  tmuf_arena_init(&arena);
  tmuf_gbx g;
  tmuf_gbx_init(&g, &ls.base, &arena, tmuf_pack_classes, tmuf_pack_class_count);
  g.feedback = 1;
  ls.pos = &g.pos;
  int ok = tmuf_gbx_read_header(&g);
  printf("class %08x (%s), format %.4s, %u nodes, %u header chunks\n", g.class_id, tmuf_class_name(g.class_id),
         (const char *)g.format, g.node_count, g.header_chunk_count);
  char file_dir[512];
  snprintf(file_dir, sizeof file_dir, "%s", path);
  char *slash = strrchr(file_dir, '\\');
  if (slash)
    slash[1] = 0;
  else
    file_dir[0] = 0;
  for (uint32_t i = 1; i <= g.node_count; i++)
    if (g.nodes[i].external) {
      char ext[512];
      if (!tmuf_gbx_external_path(&g, &g.nodes[i], file_dir, ext, sizeof ext))
        snprintf(ext, sizeof ext, "(unresolved)");
      printf("  ext node %u: %s -> %s\n", i, g.nodes[i].file ? g.nodes[i].file : "(resource)", ext);
    }
  if (ok)
    tmuf_gbx_read_root(&g);
  printf("%s after %llu bytes\n", g.error ? g.message : "parsed", (unsigned long long)g.pos);
  if (g.error) {
    size_t end = ls.seen_size, start = end > 96 ? end - 96 : 0;
    start &= ~(size_t)15;
    for (size_t i = start; i < end; i += 16) {
      printf("  %06zx:", i);
      for (size_t j = i; j < i + 16 && j < end; j++)
        printf(" %02x", ls.seen[j]);
      printf("\n");
    }
  }
  printf("mixes:");
  for (size_t i = 0; i < ls.mix_count; i++)
    printf(" %02x%02x%02x%02x@%llu", ls.mixes[i] & 0xff, (ls.mixes[i] >> 8) & 0xff, (ls.mixes[i] >> 16) & 0xff,
           ls.mixes[i] >> 24, (unsigned long long)ls.mix_pos[i]);
  printf("\n");
  tmuf_arena_free(&arena);
  tmuf_pack_stream_close(&ps);
  tmuf_pack_close(&pack);
  return g.error;
}

/* Parse one pack file; returns 1 if it parsed and the mixes match. */
static int verify_file(const tmuf_pack *pack, const char *path, const char *expected, char *why, size_t why_size) {
  long idx = tmuf_pack_find(pack, path);
  tmuf_pack_stream ps;
  if (idx < 0 || !tmuf_pack_stream_open(&ps, pack, (uint32_t)idx)) {
    snprintf(why, why_size, "cannot open");
    return 0;
  }
  static logging_source ls;
  memset(&ls, 0, sizeof ls);
  ls.base.read = log_read;
  ls.base.mix = log_mix;
  ls.inner = &ps.base;
  tmuf_arena arena;
  tmuf_arena_init(&arena);
  tmuf_gbx g;
  tmuf_gbx_init(&g, &ls.base, &arena, tmuf_pack_classes, tmuf_pack_class_count);
  g.feedback = 1;
  ls.pos = &g.pos;
  if (tmuf_gbx_read_header(&g))
    tmuf_gbx_read_root(&g);
  /* A correct parse consumes the file exactly. */
  uint32_t file_size = pack->files[idx].uncompressed_size;
  if (!g.error && g.pos != file_size)
    tmuf_gbx_fail(&g, "parse ended at %llu of %u bytes", (unsigned long long)g.pos, file_size);
  /* Compare the mixes made so far, even if parsing failed. */
  size_t i = 0;
  const char *e = expected;
  int mismatch = -1;
  while (*e) {
    while (*e == ' ')
      e++;
    if (!*e)
      break;
    unsigned v = (unsigned)strtoul(e, NULL, 16);
    uint32_t want = (v >> 24) | ((v >> 8) & 0xff00u) | ((v << 8) & 0xff0000u) | (v << 24);
    if (i >= ls.mix_count) {
      if (!g.error && mismatch < 0)
        mismatch = (int)i;
      break;
    }
    if (ls.mixes[i] != want && mismatch < 0)
      mismatch = (int)i;
    i++;
    while (*e && *e != ' ')
      e++;
  }
  if (!g.error && i < ls.mix_count && mismatch < 0)
    mismatch = (int)i;
  int ok = !g.error && mismatch < 0;
  if (g.error)
    snprintf(why, why_size, "%s (mixes ok up to %zu)", g.message, mismatch < 0 ? i : (size_t)mismatch);
  else if (mismatch >= 0)
    snprintf(why, why_size, "mix %d differs (have %zu, pos %llu)", mismatch, ls.mix_count,
             mismatch < (int)ls.mix_count ? (unsigned long long)ls.mix_pos[mismatch] : 0ull);
  tmuf_arena_free(&arena);
  tmuf_pack_stream_close(&ps);
  return ok;
}

static int cmd_verify(const char *dir, const char *list_path) {
  tmuf_packlist list;
  if (!load_packlist(dir, &list))
    return 1;
  FILE *f = fopen(list_path, "r");
  if (!f)
    return 1;
  static char line[1 << 20];
  tmuf_pack pack;
  char current[64] = "";
  int have_pack = 0, ok = 0, failed = 0;
  while (fgets(line, sizeof line, f)) {
    line[strcspn(line, "\n")] = 0;
    char *pack_name = line, *path = strchr(line, '\t');
    if (!path)
      continue;
    *path++ = 0;
    char *mixes = strchr(path, '\t');
    if (!mixes)
      mixes = path + strlen(path);
    else
      *mixes++ = 0;
    if (strcmp(pack_name, current) != 0) {
      if (have_pack)
        tmuf_pack_close(&pack);
      have_pack = open_pack(dir, &list, pack_name, &pack);
      snprintf(current, sizeof current, "%s", pack_name);
    }
    char why[256] = "";
    if (have_pack && verify_file(&pack, path, mixes, why, sizeof why)) {
      ok++;
    } else {
      failed++;
      printf("FAIL %s %s: %s\n", pack_name, path, have_pack ? why : "no pack");
    }
  }
  if (have_pack)
    tmuf_pack_close(&pack);
  fclose(f);
  printf("verify: %d ok, %d failed\n", ok, failed);
  return failed != 0;
}

static int cmd_refs(const char *dir, const char *list_path) {
  static tmuf_packset set;
  char err[256];
  if (!tmuf_packset_open(&set, dir, err, sizeof err)) {
    fprintf(stderr, "%s\n", err);
    return 1;
  }
  FILE *f = fopen(list_path, "r");
  if (!f)
    return 1;
  static char line[1 << 20];
  int files = 0, refs = 0, unresolved = 0, shown = 0;
  while (fgets(line, sizeof line, f)) {
    line[strcspn(line, "\n")] = 0;
    char *path = strchr(line, '\t');
    if (!path)
      continue;
    *path++ = 0;
    char *tab = strchr(path, '\t');
    if (tab)
      *tab = 0;
    tmuf_pack_ref r = tmuf_packset_find_stored(&set, path);
    if (r.pack < 0)
      continue;
    tmuf_pack_stream ps;
    if (!tmuf_pack_stream_open(&ps, &set.packs[r.pack], r.file))
      continue;
    tmuf_arena arena;
    tmuf_arena_init(&arena);
    tmuf_gbx g;
    tmuf_gbx_init(&g, &ps.base, &arena, NULL, 0);
    if (tmuf_gbx_read_header(&g)) {
      files++;
      for (uint32_t i = 1; i <= g.node_count; i++) {
        if (!g.nodes[i].external || !g.nodes[i].file)
          continue;
        refs++;
        char plain[600];
        if (tmuf_packset_resolve(&set, &g, &g.nodes[i], path, plain, sizeof plain).pack < 0) {
          unresolved++;
          if (shown++ < 100000)
            printf("UNRESOLVED %s: %s (folder %u, up %u)\n", path, g.nodes[i].file, g.nodes[i].folder,
                   g.ancestor_level);
        }
      }
    }
    tmuf_arena_free(&arena);
    tmuf_pack_stream_close(&ps);
  }
  fclose(f);
  printf("refs: %d files, %d external refs, %d unresolved\n", files, refs, unresolved);
  tmuf_packset_close(&set);
  return unresolved != 0;
}

/* Static collision triangles of a map (challenge or replay file), written as
   u32 count then 9 floats per triangle. */
static int cmd_scene(const char *packs, const char *in, const char *out) {
  size_t size;
  uint8_t *data = read_file(in, &size);
  if (!data)
    return 1;
  tmuf_arena arena;
  tmuf_arena_init(&arena);
  char err[256];
  const uint8_t *map_data = data;
  size_t map_size = size;
  tmuf_replay_file r;
  if (tmuf_replay_parse(data, size, &arena, &r, err, sizeof err) && r.challenge) {
    map_data = r.challenge;
    map_size = r.challenge_size;
  }
  tmuf_challenge map;
  if (!tmuf_challenge_parse(map_data, map_size, &arena, &map, err, sizeof err)) {
    printf("map: %s\n", err);
    return 1;
  }
  tmuf_packset set;
  if (!tmuf_packset_open(&set, packs, err, sizeof err)) {
    printf("packs: %s\n", err);
    return 1;
  }
  tmuf_scene scene;
  int ok = tmuf_scene_build(&scene, &set, &map, TMUF_SCENE_TRIANGLES);
  if (scene.has_start)
    printf("start: rot %g %g %g / %g %g %g / %g %g %g pos %.9g %.9g %.9g\n", scene.start.m[0][0], scene.start.m[0][1],
           scene.start.m[0][2], scene.start.m[1][0], scene.start.m[1][1], scene.start.m[1][2], scene.start.m[2][0],
           scene.start.m[2][1], scene.start.m[2][2], scene.start.t[0], scene.start.t[1], scene.start.t[2]);
  printf("scene %s: %u blocks placed, %u missing, %u triangles %s\n", map.name ? map.name : "?", scene.blocks_placed,
         scene.blocks_missing, scene.triangle_count, ok ? "" : scene.error);
  FILE *f = fopen(out, "wb");
  if (f) {
    fwrite(&scene.triangle_count, 4, 1, f);
    for (uint32_t i = 0; i < scene.triangle_count; i++)
      fwrite(scene.triangles[i].v, 4, 9, f);
    fclose(f);
  }
  if (getenv("TMUF_SCENE_BLOCKS")) {
    f = fopen(getenv("TMUF_SCENE_BLOCKS"), "w");
    for (uint32_t i = 0; f && i < map.block_count; i++)
      fprintf(f, "B %u %s %u %u %u %u %08x\n", i, map.blocks[i].name, map.blocks[i].dir, map.blocks[i].x, map.blocks[i].y,
              map.blocks[i].z, map.blocks[i].flags);
    for (uint32_t i = 0; f && i < scene.triangle_count; i++)
      fprintf(f, "T %u\n", scene.triangles[i].block);
    if (f)
      fclose(f);
  }
  tmuf_scene_free(&scene);
  tmuf_packset_close(&set);
  tmuf_arena_free(&arena);
  free(data);
  return !ok;
}

/* Decodes the selected tuning of a CSceneVehicleTunings pack file. */
static int cmd_tuning(const char *packs, const char *path) {
  tmuf_packset set;
  char err[256];
  if (!tmuf_packset_open(&set, packs, err, sizeof err)) {
    printf("packs: %s\n", err);
    return 1;
  }
  tmuf_assets assets;
  tmuf_assets_init(&assets, &set);
  int rc = 1;
  tmuf_asset *a = tmuf_assets_load_path(&assets, path);
  if (!a) {
    a = tmuf_assets_load(&assets, tmuf_packset_find_stored(&set, path));
  }
  if (a && a->class_id == 0x0a030000u) {
    const tmuf_vehicle_tunings *ts = a->root;
    printf("%u tunings, selected %u\n", ts->tunings.count, ts->selected);
    for (uint32_t i = 0; getenv("TMUF_ALL_TUNINGS") && i < ts->tunings.count; i++) {
      tmuf_asset *xa;
      tmuf_gbx_node *xn = tmuf_assets_follow(&assets, a, ts->tunings.nodes[i], &xa);
      static tmuf_vehicle_tuning x;
      if (xn && xn->data && tmuf_vehicle_tuning_decode(&x, &assets, xa, xn->data, err, sizeof err) == 0)
        printf("  [%u] %s mass %g imass %g box %g %g %g handling %u\n", i, ((tmuf_car_tuning *)xn->data)->name,
               x.body_air_response.solid_physical_mass, x.body_air_response.solid_inertia_mass,
               x.body_air_response.solid_inertia_box_size[0], x.body_air_response.solid_inertia_box_size[1],
               x.body_air_response.solid_inertia_box_size[2], x.handling_model);
      else
        printf("  [%u] %s\n", i, err);
    }
    tmuf_asset *ta;
    tmuf_gbx_node *tn = ts->selected < ts->tunings.count
                            ? tmuf_assets_follow(&assets, a, ts->tunings.nodes[ts->selected], &ta)
                            : NULL;
    if (tn && tn->data) {
      static tmuf_vehicle_tuning t;
      if (tmuf_vehicle_tuning_decode(&t, &assets, ta, tn->data, err, sizeof err) == 0) {
        printf("tuning %s: mass %g inertia mass %g box %g %g %g handling %u wheel force %u engine speed norm %g\n",
               ((tmuf_car_tuning *)tn->data)->name, t.body_air_response.solid_physical_mass,
               t.body_air_response.solid_inertia_mass, t.body_air_response.solid_inertia_box_size[0],
               t.body_air_response.solid_inertia_box_size[1], t.body_air_response.solid_inertia_box_size[2],
               t.handling_model, t.wheel_force_mode, t.engine_speed_norm);
        printf("gears %u:", t.geared_drive.transmission.gear_count);
        for (uint32_t i = 0; i < t.geared_drive.transmission.gear_count; i++)
          printf(" %g", t.geared_drive.transmission.gear_speed_ratio[i]);
        printf("\naccel curve keys %u, max side friction keys %u\n", t.curves.slip_response_accel_from_speed.count,
               t.curves.max_side_friction_from_speed.count);
        rc = 0;
      } else {
        printf("decode: %s\n", err);
      }
    } else {
      printf("no selected tuning\n");
    }
  } else {
    printf("cannot load %s\n", path);
  }
  tmuf_assets_free(&assets);
  tmuf_packset_close(&set);
  return rc;
}

static void dump_tree(tmuf_assets *assets, tmuf_asset *owner, tmuf_gbx_node *node, int depth) {
  tmuf_asset *ta;
  tmuf_gbx_node *tn = tmuf_assets_follow(assets, owner, node, &ta);
  if (!tn || !tn->data || depth > 20)
    return;
  uint32_t cls = tn->cls ? tn->cls->id : 0;
  if (cls != 0x0904f000u && cls != 0x09015000u && cls != 0x09062000u) {
    printf("%*s[%08x]\n", depth * 2, "", tn->class_id);
    return;
  }
  const tmuf_plug_tree *t = tn->data;
  printf("%*stree [%08x] '%s' flags %08x", depth * 2, "", cls, t->name ? t->name : "", t->flags);
  if (t->has_iso)
    printf(" iso t=(%g %g %g)", t->iso[9], t->iso[10], t->iso[11]);
  if (t->surface) {
    tmuf_asset *sa;
    tmuf_gbx_node *sn = tmuf_assets_follow(assets, ta, t->surface, &sa);
    if (sn && sn->data && sn->class_id == 0x0900c000u) {
      const tmuf_plug_surface *surf = sn->data;
      tmuf_asset *ga;
      tmuf_gbx_node *gn = tmuf_assets_follow(assets, sa, surf->geom, &ga);
      if (gn && gn->data) {
        const tmuf_plug_surface_geom *geom = gn->data;
        printf(" surface type %u params %g %g %g %g %g %g tris %u mats %u", geom->type, geom->params[0],
               geom->params[1], geom->params[2], geom->params[3], geom->params[4], geom->params[5],
               geom->triangle_count, surf->material_count);
      }
    }
  }
  if (t->visual) {
    tmuf_asset *va;
    tmuf_gbx_node *vn = tmuf_assets_follow(assets, ta, t->visual, &va);
    if (vn && vn->data && vn->class_id == 0x09006000u) {
      const tmuf_plug_visual *v = vn->data;
      printf(" visual %08x verts %u stride %u tris %u uvs %u", vn->class_id, v->vertex_count, v->vertex_stride,
             v->index_count / 3u, v->texcoord_count);
    } else
      printf(" visual [%08x]", vn ? vn->class_id : 0);
  }
  tmuf_gbx_node *refs[2] = {t->material, t->shader};
  for (int k = 0; k < 2; k++)
    if (refs[k]) {
      tmuf_asset *ra;
      tmuf_gbx_node *rn = tmuf_assets_follow(assets, ta, refs[k], &ra);
      printf(" %s %s", k ? "shader" : "material", ra && refs[k]->external ? ra->path : "(inline)");
      (void)rn;
    }
  if (t->mip_count)
    printf(" mips %u from %u", t->mip_count, t->mip_first);
  if (t->has_iso)
    printf("\n%*s  rot %g %g %g / %g %g %g / %g %g %g", depth * 2, "", t->iso[0], t->iso[1], t->iso[2], t->iso[3],
           t->iso[4], t->iso[5], t->iso[6], t->iso[7], t->iso[8]);
  printf("\n");
  for (uint32_t i = 0; i < t->child_count; i++)
    dump_tree(assets, ta, t->children[i], depth + 1);
}

/* Prints the solid tree of a vehicle (collector id, e.g. StadiumCar). */
static int cmd_vehicle(const char *packs, const char *name) {
  tmuf_packset set;
  char err[256];
  if (!tmuf_packset_open(&set, packs, err, sizeof err)) {
    printf("packs: %s\n", err);
    return 1;
  }
  tmuf_assets assets;
  tmuf_assets_init(&assets, &set);
  tmuf_vehicle v;
  if (!tmuf_vehicle_load(&v, &assets, name, err, sizeof err))
    printf("vehicle: %s\n", err);
  else {
    printf("solid %s\n", v.solid_owner->path);
    const tmuf_vehicle_struct *st = v.visual_struct;
    for (uint32_t k = 0; st && k < st->visual_vehicle_count; k++) {
      const tmuf_visual_vehicle_def *vv = &st->visual_vehicles[k];
      printf("visual %u quality %u body %s/%d pilot head %s/%d shadow %s/%d extra %s/%d\n", k, vv->quality,
             vv->body.name, vv->body.flag, vv->pilot_head.name, vv->pilot_head.flag, vv->shadow.name, vv->shadow.flag,
             vv->extra.name, vv->extra.flag);
      for (uint32_t i = 0; i < vv->wheel_count; i++) {
        const tmuf_visual_wheel_def *w = &vv->wheels[i];
        printf("  wheel %u steers %d: rolling %s/%d fixed %s/%d bouncing %s/%d steering %s/%d\n", w->wheel, w->steers,
               w->rolling.name, w->rolling.flag, w->fixed.name, w->fixed.flag, w->bouncing.name, w->bouncing.flag,
               w->steering.name, w->steering.flag);
      }
      for (uint32_t i = 0; i < vv->arm_count; i++) {
        const tmuf_visual_arm_def *a = &vv->arms[i];
        printf("  arm %s/%d from %s/%d to %s/%d flag0 %d rolls %d wheel %u\n", a->arm.name, a->arm.flag, a->from.name,
               a->from.flag, a->to.name, a->to.flag, a->flag0, a->rolls, a->wheel);
      }
      for (uint32_t i = 0; i < vv->light_count; i++)
        printf("  light %s/%d kind %u\n", vv->lights[i].tree.name, vv->lights[i].tree.flag, vv->lights[i].kind);
    }
    dump_tree(&assets, v.solid_owner, v.solid_tree, 0);
  }
  tmuf_assets_free(&assets);
  tmuf_packset_close(&set);
  return 0;
}

/* Prints the tree of a solid (pack path). */
static int cmd_solid(const char *packs, const char *path) {
  tmuf_packset set;
  char err[256];
  if (!tmuf_packset_open(&set, packs, err, sizeof err)) {
    printf("packs: %s\n", err);
    return 1;
  }
  tmuf_assets assets;
  tmuf_assets_init(&assets, &set);
  tmuf_asset *a = tmuf_assets_load_path(&assets, path);
  if (!a)
    a = tmuf_assets_load(&assets, tmuf_packset_find_stored(&set, path));
  if (a && a->class_id == 0x09005000u) {
    const tmuf_plug_solid *s = a->root;
    printf("solid physics %d mass %g com %g %g %g\n", s->has_physics, s->mass, s->center_of_mass[0],
           s->center_of_mass[1], s->center_of_mass[2]);
    dump_tree(&assets, a, s->tree, 0);
  }
  tmuf_assets_free(&assets);
  tmuf_packset_close(&set);
  return 0;
}

int main(int argc, char **argv) {
  if (argc >= 4 && strcmp(argv[1], "solid") == 0)
    return cmd_solid(argv[2], argv[3]);
  if (argc >= 4 && strcmp(argv[1], "vehicle") == 0)
    return cmd_vehicle(argv[2], argv[3]);
  if (argc >= 4 && strcmp(argv[1], "tuning") == 0)
    return cmd_tuning(argv[2], argv[3]);
  if (argc >= 5 && strcmp(argv[1], "scene") == 0)
    return cmd_scene(argv[2], argv[3], argv[4]);
  if (argc >= 4 && strcmp(argv[1], "refs") == 0)
    return cmd_refs(argv[2], argv[3]);
  if (argc >= 4 && strcmp(argv[1], "verify") == 0)
    return cmd_verify(argv[2], argv[3]);
  if (argc >= 5 && strcmp(argv[1], "gbx") == 0)
    return cmd_gbx(argv[2], argv[3], argv[4]);
  if (argc >= 4 && strcmp(argv[1], "map") == 0)
    return cmd_map(argv[2], argv[3]);
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
      printf("%08x %c%c %9u %9u %9u %s\n", f->class_id, tmuf_pack_file_encrypted(f) ? 'E' : '-',
             tmuf_pack_file_compressed(f) ? 'Z' : '-', f->uncompressed_size, f->compressed_size,
             pack.data_start + f->offset, path);
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
