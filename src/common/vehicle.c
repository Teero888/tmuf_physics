#include "common/vehicle.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common/pack.h"

#define CLASS_COLLECTOR_VEHICLE 0x0301c000u
#define CLASS_VEHICLE_CAR 0x0a02b000u

static int ieq(const char *a, const char *b) {
  for (; *a && *b; a++, b++) {
    char x = *a >= 'A' && *a <= 'Z' ? (char)(*a + 32) : *a;
    char y = *b >= 'A' && *b <= 'Z' ? (char)(*b + 32) : *b;
    if (x != y)
      return 0;
  }
  return *a == *b;
}

/* Collector identifier (header chunk 0x0301a003) of a pack file. */
static int collector_is(tmuf_assets *assets, tmuf_pack_ref ref, const char *name) {
  const tmuf_pack *pack = &assets->set->packs[ref.pack];
  tmuf_pack_stream ps;
  if (!tmuf_pack_stream_open(&ps, pack, ref.file))
    return 0;
  tmuf_gbx g;
  tmuf_gbx_init(&g, &ps.base, &assets->arena, NULL, 0);
  int match = 0;
  if (tmuf_gbx_read_header(&g)) {
    for (uint32_t i = 0; i < g.header_chunk_count; i++) {
      if (g.header_chunks[i].id != 0x0301a003u)
        continue;
      tmuf_mem_source ms;
      tmuf_mem_source_init(&ms, g.header_chunks[i].data, g.header_chunks[i].size);
      tmuf_gbx h;
      tmuf_gbx_init(&h, &ms.base, &assets->arena, NULL, 0);
      const char *id = tmuf_gbx_id(&h, NULL);
      match = !h.error && id && ieq(id, name);
      break;
    }
  }
  tmuf_pack_stream_close(&ps);
  return match;
}

/* The mobil the collector references: its external CSceneVehicleCar. */
static tmuf_pack_ref collector_mobil(tmuf_assets *assets, tmuf_pack_ref ref) {
  tmuf_pack_ref none = {-1, 0};
  const tmuf_packset *set = assets->set;
  char from[512];
  if (!tmuf_pack_file_path(&set->packs[ref.pack], ref.file, from, sizeof from))
    return none;
  tmuf_pack_stream ps;
  if (!tmuf_pack_stream_open(&ps, &set->packs[ref.pack], ref.file))
    return none;
  tmuf_gbx g;
  tmuf_gbx_init(&g, &ps.base, &assets->arena, NULL, 0);
  tmuf_pack_ref out = none;
  if (tmuf_gbx_read_header(&g)) {
    for (uint32_t i = 1; i <= g.node_count && out.pack < 0; i++) {
      if (!g.nodes[i].external)
        continue;
      char plain[512];
      tmuf_pack_ref r = tmuf_packset_resolve(set, &g, &g.nodes[i], from, plain, sizeof plain);
      if (r.pack >= 0 && set->packs[r.pack].files[r.file].class_id == CLASS_VEHICLE_CAR)
        out = r;
    }
  }
  tmuf_pack_stream_close(&ps);
  return out;
}

/* First external node of a file (by its header) whose pack class is cls. */
static tmuf_pack_ref file_ext_class(tmuf_assets *assets, tmuf_pack_ref ref, uint32_t cls) {
  tmuf_pack_ref none = {-1, 0};
  const tmuf_packset *set = assets->set;
  char from[512];
  if (!tmuf_pack_file_path(&set->packs[ref.pack], ref.file, from, sizeof from))
    return none;
  tmuf_pack_stream ps;
  if (!tmuf_pack_stream_open(&ps, &set->packs[ref.pack], ref.file))
    return none;
  tmuf_gbx g;
  tmuf_gbx_init(&g, &ps.base, &assets->arena, NULL, 0);
  tmuf_pack_ref out = none;
  if (tmuf_gbx_read_header(&g))
    for (uint32_t i = 1; i <= g.node_count && out.pack < 0; i++) {
      if (!g.nodes[i].external)
        continue;
      char plain[512];
      tmuf_pack_ref r = tmuf_packset_resolve(set, &g, &g.nodes[i], from, plain, sizeof plain);
      if (r.pack >= 0 && set->packs[r.pack].files[r.file].class_id == cls)
        out = r;
    }
  tmuf_pack_stream_close(&ps);
  return out;
}

/* The materials' fake contact bitmap image: an uncompressed true color TGA */
static void load_fake_texture(tmuf_vehicle *v, tmuf_assets *assets, tmuf_asset *materials) {
  tmuf_pack_ref bitmap = file_ext_class(assets, materials->ref, 0x09011000u);
  if (bitmap.pack < 0)
    return;
  tmuf_pack_ref tga = file_ext_class(assets, bitmap, 0x09023000u);
  if (tga.pack < 0)
    return;
  uint8_t *data;
  size_t size;
  if (!tmuf_pack_extract(&assets->set->packs[tga.pack], tga.file, &data, &size))
    return;
  if (size >= 18 && data[1] == 0 && data[2] == 2 && data[16] != 0 && data[16] % 8 == 0) {
    uint32_t w = (uint32_t)data[12] | (uint32_t)data[13] << 8, h = (uint32_t)data[14] | (uint32_t)data[15] << 8;
    uint32_t bpp = data[16] / 8u;
    size_t off = 18u + data[0], n = (size_t)w * h * bpp;
    if (w && h && off <= size && n <= size - off) {
      uint8_t *px = tmuf_arena_alloc(&assets->arena, n);
      if (px) {
        memcpy(px, data + off, n);
        v->fake_width = w;
        v->fake_height = h;
        v->fake_bpp = bpp;
        v->fake_pixels = px;
      }
    }
  }
  free(data);
}

int tmuf_vehicle_load(tmuf_vehicle *v, tmuf_assets *assets, const char *name, char *err, size_t err_size) {
  memset(v, 0, sizeof *v);
  const tmuf_packset *set = assets->set;
  tmuf_pack_ref collector = {-1, 0};
  for (int p = 0; p < set->pack_count && collector.pack < 0; p++)
    for (uint32_t f = 0; f < set->packs[p].file_count; f++) {
      if (set->packs[p].files[f].class_id != CLASS_COLLECTOR_VEHICLE)
        continue;
      tmuf_pack_ref r = {p, f};
      if (collector_is(assets, r, name)) {
        collector = r;
        break;
      }
    }
  if (collector.pack < 0) {
    snprintf(err, err_size, "no vehicle collector %s", name);
    return 0;
  }
  tmuf_pack_ref mref = collector_mobil(assets, collector);
  tmuf_asset *ma = mref.pack >= 0 ? tmuf_assets_load(assets, mref) : NULL;
  if (!ma || !ma->root) {
    snprintf(err, err_size, "vehicle %s: mobil not loaded%s%s", name, ma ? ": " : "", ma ? ma->error : "");
    return 0;
  }
  const tmuf_scene_object *mobil = ma->root;

  /* solid */
  if (!mobil->has_item) {
    snprintf(err, err_size, "vehicle %s: mobil without item", name);
    return 0;
  }
  tmuf_asset *sa;
  tmuf_gbx_node *sn = tmuf_assets_follow(assets, ma, mobil->item.solid, &sa);
  for (int depth = 0; sn && sn->data && sn->class_id == 0x09005000u && ((tmuf_plug_solid *)sn->data)->use_model &&
                      depth < 8;
       depth++)
    sn = tmuf_assets_follow(assets, sa, ((tmuf_plug_solid *)sn->data)->model, &sa);
  if (!sn || !sn->data || sn->class_id != 0x09005000u || !((tmuf_plug_solid *)sn->data)->tree) {
    snprintf(err, err_size, "vehicle %s: no solid", name);
    return 0;
  }
  v->solid_owner = sa;
  v->solid_tree = ((tmuf_plug_solid *)sn->data)->tree;

  /* tuning */
  tmuf_asset *ta;
  tmuf_gbx_node *tn = tmuf_assets_follow(assets, ma, mobil->vehicle_tunings, &ta);
  if (!tn || !tn->data || !tn->cls || tn->cls->id != 0x0a030000u) {
    snprintf(err, err_size, "vehicle %s: no tunings", name);
    return 0;
  }
  const tmuf_vehicle_tunings *ts = tn->data;
  if (ts->selected >= ts->tunings.count) {
    snprintf(err, err_size, "vehicle %s: bad selected tuning", name);
    return 0;
  }
  tmuf_asset *xa;
  tmuf_gbx_node *xn = tmuf_assets_follow(assets, ta, ts->tunings.nodes[ts->selected], &xa);
  if (!xn || !xn->data ||
      tmuf_vehicle_tuning_decode(&v->tuning, assets, xa, xn->data, err, err_size) != 0) {
    if (!err[0])
      snprintf(err, err_size, "vehicle %s: tuning", name);
    return 0;
  }

  /* struct */
  tmuf_asset *va;
  tmuf_gbx_node *vn = tmuf_assets_follow(assets, ma, mobil->vehicle_struct, &va);
  if (!vn || !vn->data || vn->class_id != 0x0a039000u) {
    snprintf(err, err_size, "vehicle %s: no vehicle struct", name);
    return 0;
  }
  const tmuf_vehicle_struct *vs = vn->data;
  v->visual_struct = vs;
  if (vs->wheel_count > TMUF_VEHICLE_MAX_WHEELS) {
    snprintf(err, err_size, "vehicle %s: %u wheels", name, vs->wheel_count);
    return 0;
  }
  v->wheel_count = vs->wheel_count;
  for (uint32_t i = 0; i < vs->wheel_count; i++) {
    v->wheels[i].kills_lateral_speed = vs->wheels[i].flags[0] != 0;
    v->wheels[i].front = vs->wheels[i].flags[1] != 0;
    v->wheels[i].surface = vs->wheels[i].name;
  }

  /* physical parameters */
  v->has_params = mobil->has_physical_params;
  v->speed_cap = mobil->physical_params[0];
  v->reverse_speed_threshold = mobil->physical_params[1];
  for (int i = 0; i < 6; i++)
    v->water_box[i] = mobil->physical_params[2 + i];

  /* materials */
  tmuf_asset *ra;
  tmuf_gbx_node *rn = tmuf_assets_follow(assets, ma, mobil->vehicle_materials, &ra);
  if (rn && rn->data && rn->class_id == 0x01026000u) {
    const tmuf_node_list *list = rn->data;
    for (uint32_t i = 0; i < list->count && v->material_count < TMUF_VEHICLE_MAX_MATERIALS; i++) {
      tmuf_asset *mma;
      tmuf_gbx_node *mn = tmuf_assets_follow(assets, ra, list->nodes[i], &mma);
      if (mn && mn->data && mn->class_id == 0x0a031000u)
        v->materials[v->material_count++] = *(const tmuf_vehicle_material *)mn->data;
    }
  }
  if (rn && ra && ra != ma)
    load_fake_texture(v, assets, ra);
  if (v->material_count == 0) {
    snprintf(err, err_size, "vehicle %s: no materials", name);
    return 0;
  }
  return 1;
}
