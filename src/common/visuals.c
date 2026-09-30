/* What a track draws (tmuf_track_visuals): the scene's visible visuals as
   plain data. Meshes and materials are shared between the instances that
   place them; a material names the texture files its shader samples. */

#include "common/visuals.h"

#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { CLS_VISUAL = 0x09006000u, CLS_SHADER = 0x09002000u, CLS_MATERIAL = 0x09079000u, CLS_SAMPLER = 0x0907e000u,
       CLS_BITMAP = 0x09011000u };

static uint32_t node_class(const tmuf_gbx_node *n) { return n && n->cls ? n->cls->id : 0; }

/* pointer -> index, open addressing */
typedef struct ptr_map {
  uint32_t cap;
  const void **keys;
  uint32_t *values;
} ptr_map;

static int map_init(ptr_map *m, uint32_t n) {
  m->cap = 64;
  while (m->cap < n * 2u)
    m->cap *= 2;
  m->keys = calloc(m->cap, sizeof *m->keys);
  m->values = calloc(m->cap, sizeof *m->values);
  return m->keys && m->values;
}

static void map_free(ptr_map *m) {
  free(m->keys);
  free(m->values);
}

static uint32_t *map_slot(ptr_map *m, const void *key, int *found) {
  uint32_t h = (uint32_t)(((uintptr_t)key >> 4) * 2654435761u) & (m->cap - 1u);
  while (m->keys[h] && m->keys[h] != key)
    h = (h + 1u) & (m->cap - 1u);
  *found = m->keys[h] != NULL;
  m->keys[h] = key;
  return &m->values[h];
}

static const char *dup(tmuf_arena *a, const char *s) { return s ? tmuf_arena_strndup(a, s, strlen(s)) : NULL; }

typedef struct builder {
  tmuf_scene *scene;
  tmuf_arena *arena;
  tmuf_visual_mesh *meshes;
  tmuf_visual_material *materials;
  uint32_t mesh_count, material_count;
  ptr_map mesh_map, material_map;
  int oom;
  int sprites; /* also take sprite visuals (vertices without indices) */
} builder;

/* the image file a bitmap loads: on disk, else inside the packs */
static void bitmap_file(builder *b, tmuf_asset *owner, tmuf_gbx_node *bitmap, tmuf_visual_texture *t,
                        int use_tc_scale) {
  t->file = t->pack_file = NULL;
  tmuf_asset *ba;
  tmuf_gbx_node *bn = tmuf_assets_follow(&b->scene->assets, owner, bitmap, &ba);
  if (node_class(bn) != CLS_BITMAP || !bn->data) {
    if (getenv("TMUF_VISUALS_DEBUG"))
      fprintf(stderr, "bitmap %s from %s: node %p class %08x\n", bitmap->file ? bitmap->file : "(inline)",
              owner ? owner->path : "-", (void *)bn, node_class(bn));
    return;
  }
  const tmuf_plug_bitmap *bm = bn->data;
  /* CPlugBitmapAddress::ApplyBitmapTcScale: addresses flagged 0x1000 take the
     bitmap's texcoord transform, and a bitmap flagged 0x8000 its generation */
  if (use_tc_scale && bm->has_tc_transform) {
    const float r = bm->tc_rotation * 3.14159265358979f / 180.0f, c = cosf(r), s = sinf(r);
    t->transform[0] = c * bm->tc_scale[0];
    t->transform[1] = s * bm->tc_scale[0];
    t->transform[2] = -s * bm->tc_scale[1];
    t->transform[3] = c * bm->tc_scale[1];
    t->transform[4] = bm->tc_offset[0];
    t->transform[5] = bm->tc_offset[1];
    t->has_transform = 1;
  }
  if (bm->has_flags && (bm->flags & 0x8000u) && t->texcoord == TMUF_TEXCOORD_GENERATED)
    t->generate = (bm->flags >> 16) & 0xffu;
  char path[1200];
  if (bm->image && bm->image->external &&
      tmuf_packset_resolve(b->scene->assets.set, &ba->gbx, bm->image, ba->path, path, sizeof path).pack >= 0) {
    t->pack_file = dup(b->arena, path);
    return;
  }
  if (!bm->image || !tmuf_packset_resolve_file(b->scene->assets.set, &ba->gbx, bm->image, ba->path, path, sizeof path)) {
    if (getenv("TMUF_VISUALS_DEBUG")) {
      char stored[600] = "";
      if (bm->image && bm->image->external)
        tmuf_gbx_external_path(&ba->gbx, bm->image, "", stored, sizeof stored);
      char inpack[600] = "";
      if (bm->image && bm->image->external)
        tmuf_packset_resolve(b->scene->assets.set, &ba->gbx, bm->image, ba->path, inpack, sizeof inpack);
      fprintf(stderr, "bitmap [pack: %s] %s: image %s %s class %08x file %s ancestor %u\n", inpack, ba->path,
              bm->image ? (bm->image->external ? "external" : "inline") : "none", stored,
              bm->image ? bm->image->class_id : 0, bm->image && bm->image->file ? bm->image->file : "-",
              ba->gbx.ancestor_level);
    }
    return;
  }
  t->file = dup(b->arena, path);
}

/* the textures of a shader: its sampler addresses, the material's custom
   bitmaps replacing those of the same sampler name; then the custom bitmaps
   no address names (the game's programs sample them by name, e.g. a block's
   "Lighting") */
static void shader_textures(builder *b, tmuf_visual_material *m, tmuf_asset *sa, const tmuf_plug_shader *sh,
                            const tmuf_plug_material_custom *custom, tmuf_asset *ca) {
  const uint32_t cap = sh->address_count + (custom ? custom->bitmap_count : 0u);
  tmuf_visual_texture *t = TMUF_ARENA_ARRAY(b->arena, tmuf_visual_texture, cap ? cap : 1);
  if (!t) {
    b->oom = 1;
    return;
  }
  uint32_t n = 0;
  for (uint32_t i = 0; i < sh->address_count; i++) {
    tmuf_asset *aa;
    tmuf_gbx_node *an = tmuf_assets_follow(&b->scene->assets, sa, sh->addresses[i], &aa);
    if (node_class(an) != CLS_SAMPLER || !an->data)
      continue;
    const tmuf_plug_bitmap_address *ad = an->data;
    tmuf_gbx_node *bitmap = ad->bitmap;
    tmuf_asset *bowner = aa;
    for (uint32_t k = 0; custom && k < custom->bitmap_count; k++)
      if (custom->bitmap_names[k] && ad->sampler && strcmp(custom->bitmap_names[k], ad->sampler) == 0) {
        bitmap = custom->bitmaps[k];
        bowner = ca;
        break;
      }
    t[n].sampler = dup(b->arena, ad->sampler ? ad->sampler : "");
    t[n].file = t[n].pack_file = NULL;
    t[n].unbound = 0;
    t[n].texcoord = ad->has_address ? (ad->address_flags >> 15) & 31u : 0u;
    t[n].generate = ad->has_address ? ad->address_flags & 0xffu : 0u;
    t[n].has_transform = ad->has_transform;
    memcpy(t[n].transform, ad->transform, sizeof t[n].transform);
    if (bitmap)
      bitmap_file(b, bowner, bitmap, &t[n], ad->has_address && (ad->address_flags & 0x1000u));
    n++;
  }
  for (uint32_t k = 0; custom && k < custom->bitmap_count; k++) {
    const char *name = custom->bitmap_names[k];
    if (!name || !custom->bitmaps[k])
      continue;
    int named = 0;
    for (uint32_t i = 0; i < n && !named; i++)
      named = strcmp(t[i].sampler, name) == 0;
    if (named)
      continue;
    memset(&t[n], 0, sizeof t[n]);
    t[n].sampler = dup(b->arena, name);
    t[n].unbound = 1;
    bitmap_file(b, ca, custom->bitmaps[k], &t[n], 0);
    n++;
  }
  m->textures = t;
  m->texture_count = n;
}

/* the replacement the game loads for a material reference of a remapped
   block (tmuf_scene_visual_remap), NULL to keep it */
static tmuf_asset *remapped_material(builder *b, uint8_t set, tmuf_asset *owner, tmuf_gbx_node *ref) {
  if (set == TMUF_REMAP_SET_NONE || !ref || !ref->external)
    return NULL;
  char path[600];
  if (tmuf_packset_resolve(b->scene->assets.set, &owner->gbx, ref, owner->path, path, sizeof path).pack < 0)
    return NULL;
  const char *repl = tmuf_scene_visual_remap(b->scene, set, path);
  tmuf_asset *ra = repl ? tmuf_assets_load_path(&b->scene->assets, repl) : NULL;
  return ra && ra->root && ra->class_id == CLS_MATERIAL ? ra : NULL;
}

/* the material of a visual: the tree's material, else its shader, else the
   visual's own material (a remapped block's materials replaced as the game
   loads them); UINT32_MAX for none */
static uint32_t material_of(builder *b, const tmuf_scene_visual *v, tmuf_asset *visual_owner,
                            const tmuf_plug_visual *visual, uint8_t remap_set) {
  struct {
    tmuf_asset *owner;
    tmuf_gbx_node *ref;
  } refs[3] = {{v->owner, v->material}, {v->owner, v->shader}, {visual_owner, visual->material}};
  for (int r = 0; r < 3; r++) {
    if (!refs[r].ref)
      continue;
    tmuf_asset *na;
    tmuf_gbx_node *n = tmuf_assets_follow(&b->scene->assets, refs[r].owner, refs[r].ref, &na);
    uint32_t cls = node_class(n);
    if (!n || !n->data || (cls != CLS_MATERIAL && cls != CLS_SHADER))
      continue;
    tmuf_asset *owner = refs[r].owner;
    tmuf_gbx_node *ref = refs[r].ref;
    tmuf_asset *ra = cls == CLS_MATERIAL ? remapped_material(b, remap_set, owner, ref) : NULL;
    if (ra) {
      owner = na = ra;
      ref = n = &ra->gbx.nodes[0];
      cls = node_class(n);
      if (!n->data || cls != CLS_MATERIAL)
        continue;
    }
    int found;
    uint32_t *slot = map_slot(&b->material_map, n, &found);
    if (found)
      return *slot;
    tmuf_visual_material *m = &b->materials[b->material_count];
    memset(m, 0, sizeof *m);
    m->name = dup(b->arena, ra || ref->external ? na->path : "");
    tmuf_asset *sa = na, *ca = NULL;
    const tmuf_plug_material_custom *custom = NULL;
    tmuf_gbx_node *sn = cls == CLS_SHADER ? n
                                          : tmuf_scene_material_shader(b->scene, owner, ref, &sa, &custom, &ca);
    if (node_class(sn) == CLS_SHADER && sn->data) {
      const tmuf_plug_shader *sh = sn->data;
      m->has_shader_flags = sh->has_flags;
      m->shader_flags[0] = sh->flags[0];
      m->shader_flags[1] = sh->flags[1];
      m->has_render_state = sh->has_apply_state;
      m->render_state[0] = sh->apply_state[0];
      m->render_state[1] = sh->apply_state[1];
      shader_textures(b, m, sa, sh, custom, ca);
    }
    m->lightmap_uv = UINT32_MAX;
    for (uint32_t t = 0; t < m->texture_count; t++)
      if (!m->textures[t].unbound && strcmp(m->textures[t].sampler, "PreLightGen") == 0)
        m->lightmap_uv = m->textures[t].texcoord;
    *slot = b->material_count++;
    return *slot;
  }
  return UINT32_MAX;
}

/* the mesh of a visual (shared), UINT32_MAX when it has no indexed triangles */
static uint32_t mesh_of(builder *b, tmuf_gbx_node *vn) {
  int found;
  uint32_t *slot = map_slot(&b->mesh_map, vn, &found);
  if (found)
    return *slot;
  const tmuf_plug_visual *pv = vn->data;
  const int sprite = vn->class_id == 0x09010000u; /* CPlugVisualSprite */
  if (!pv->vertices || (!(sprite && b->sprites) && (!pv->indices || pv->index_count < 3))) {
    *slot = UINT32_MAX;
    return UINT32_MAX;
  }
  tmuf_visual_mesh *m = &b->meshes[b->mesh_count];
  memset(m, 0, sizeof *m);
  m->vertex_count = pv->vertex_count;
  m->vertex_stride = pv->vertex_stride;
  m->vertices = pv->vertices;
  m->flags = sprite ? TMUF_VISUAL_SPRITES
                    : ((pv->flags & 0x20u) ? TMUF_VISUAL_NORMAL : 0u) | ((pv->flags & 0x40u) ? TMUF_VISUAL_COLOR : 0u);
  if (sprite) {
    m->sprite_flags = pv->sprite_flags;
    m->sprite_atlas[0] = pv->sprite_atlas[0];
    m->sprite_atlas[1] = pv->sprite_atlas[1];
    memcpy(m->sprite_axis, pv->sprite_axis, sizeof m->sprite_axis);
    memcpy(m->sprite_offset, pv->sprite_offset, sizeof m->sprite_offset);
  }
  m->uv_set_count = pv->texcoord_count;
  for (uint32_t i = 0; i < pv->texcoord_count && i < TMUF_VISUAL_MAX_UV_SETS; i++) {
    m->uv_sets[i] = pv->texcoords[i];
    m->uv_dims[i] = pv->texcoord_dim[i];
  }
  m->tangents = pv->tangents;
  m->binormals = pv->binormals;
  m->index_count = pv->index_count - pv->index_count % 3u;
  m->indices = pv->indices;
  memcpy(m->bounds, pv->bbox, sizeof m->bounds);
  *slot = b->mesh_count++;
  return *slot;
}

static int build_list(tmuf_visuals_data *out, tmuf_scene *scene, const tmuf_scene_visual *list, uint32_t n,
                      const uint32_t *lightmap_of_corpus, tmuf_arena *arena, int sprites, int remap) {
  memset(out, 0, sizeof *out);
  builder b = {scene, arena, NULL, NULL, 0, 0, {0}, {0}, 0, sprites};
  b.meshes = malloc(sizeof *b.meshes * (n ? n : 1));
  b.materials = malloc(sizeof *b.materials * (n ? 3u * n : 1));
  tmuf_visual_instance *instances = malloc(sizeof *instances * (n ? n : 1));
  if (!b.meshes || !b.materials || !instances || !map_init(&b.mesh_map, n) || !map_init(&b.material_map, 3u * n)) {
    free(b.meshes), free(b.materials), free(instances);
    map_free(&b.mesh_map), map_free(&b.material_map);
    return 0;
  }
  uint32_t count = 0;
  for (uint32_t i = 0; i < n && !b.oom; i++) {
    const tmuf_scene_visual *v = &list[i];
    tmuf_asset *va;
    tmuf_gbx_node *vn = tmuf_assets_follow(&scene->assets, v->owner, v->visual, &va);
    if (node_class(vn) != CLS_VISUAL || !vn->data)
      continue;
    const uint32_t mesh = mesh_of(&b, vn);
    if (mesh == UINT32_MAX)
      continue;
    tmuf_visual_instance *in = &instances[count++];
    in->mesh = mesh;
    const uint8_t set = remap && v->corpus < scene->corpus_count ? scene->corpora[v->corpus].remap_set
                                                                 : (uint8_t)TMUF_REMAP_SET_NONE;
    in->material = material_of(&b, v, va, vn->data, set);
    for (int r = 0; r < 3; r++)
      for (int c = 0; c < 3; c++)
        in->location.r.m[r][c] = v->iso.m[r][c];
    in->location.t = (tmuf_vec3){v->iso.t[0], v->iso.t[1], v->iso.t[2]};
    in->block = v->tag;
    in->lod_near = v->lod_near;
    in->lod_far = v->lod_far;
    in->lightmap = lightmap_of_corpus && v->corpus < scene->corpus_count ? lightmap_of_corpus[v->corpus] : UINT32_MAX;
  }
  map_free(&b.mesh_map);
  map_free(&b.material_map);
  if (b.oom) {
    free(b.meshes), free(b.materials), free(instances);
    return 0;
  }
  out->meshes = b.meshes;
  out->materials = b.materials;
  out->instances = instances;
  out->view.mesh_count = b.mesh_count;
  out->view.material_count = b.material_count;
  out->view.instance_count = count;
  out->view.meshes = b.meshes;
  out->view.materials = b.materials;
  out->view.instances = instances;
  return 1;
}

int tmuf_visuals_build(tmuf_visuals_data *out, tmuf_scene *scene, const uint32_t *lightmap_of_corpus,
                       tmuf_arena *arena) {
  return build_list(out, scene, scene->visuals, scene->visual_count, lightmap_of_corpus, arena, 0, 1);
}

/* ---- the vehicle ---- */

typedef struct vehicle_builder {
  tmuf_scene *scene;
  tmuf_arena *arena;
  tmuf_vehicle_part *parts;
  uint32_t part_count, part_cap;
  tmuf_scene_visual *list;
  uint32_t count, cap;
  int oom;
} vehicle_builder;

static void vehicle_tree(vehicle_builder *b, tmuf_asset *owner, tmuf_gbx_node *tree_node, uint32_t parent, int depth,
                         float lod_near, float lod_far) {
  if (depth > 64 || b->oom)
    return;
  tmuf_asset *ta;
  tmuf_gbx_node *tn = tmuf_assets_follow(&b->scene->assets, owner, tree_node, &ta);
  const uint32_t cls = node_class(tn);
  if (!tn || !tn->data || (cls != 0x0904f000u && cls != 0x09015000u && cls != 0x09062000u))
    return;
  const tmuf_plug_tree *t = tn->data;
  if (b->part_count == b->part_cap) {
    uint32_t cap = b->part_cap ? b->part_cap * 2 : 64;
    tmuf_vehicle_part *p = realloc(b->parts, sizeof *p * cap);
    if (!p) {
      b->oom = 1;
      return;
    }
    b->parts = p;
    b->part_cap = cap;
  }
  const uint32_t index = b->part_count++;
  tmuf_vehicle_part *part = &b->parts[index];
  part->name = dup(b->arena, t->name ? t->name : "");
  part->parent = parent;
  tmuf_iso iso;
  tmuf_iso_identity(&iso);
  if (t->has_iso)
    tmuf_iso_from_archive(&iso, t->iso);
  for (int r = 0; r < 3; r++)
    for (int c = 0; c < 3; c++)
      part->location.r.m[r][c] = iso.m[r][c];
  part->location.t = (tmuf_vec3){iso.t[0], iso.t[1], iso.t[2]};
  if (t->visual && (t->flags & 8u)) {
    if (b->count == b->cap) {
      uint32_t cap = b->cap ? b->cap * 2 : 64;
      tmuf_scene_visual *l = realloc(b->list, sizeof *l * cap);
      if (!l) {
        b->oom = 1;
        return;
      }
      b->list = l;
      b->cap = cap;
    }
    tmuf_scene_visual *v = &b->list[b->count++];
    v->owner = ta;
    v->visual = t->visual;
    v->material = t->material;
    v->shader = t->shader;
    tmuf_iso_identity(&v->iso); /* the part's own frame */
    v->tag = index;
    v->lod_near = lod_near;
    v->lod_far = lod_far;
  }
  for (uint32_t i = 0; i < t->child_count; i++) {
    float n = lod_near, f = lod_far;
    if (t->mip_count && i >= t->mip_first) {
      const uint32_t k = i - t->mip_first;
      const float from = k ? t->mip_distances[k - 1] : 0.0f, to = t->mip_distances[k];
      n = from > n ? from : n;
      f = to < f ? to : f;
    }
    vehicle_tree(b, ta, t->children[i], index, depth + 1, n, f);
  }
}

/* SolidGetTargetFromId: the first tree of that name, depth first */
static uint32_t part_named(const vehicle_builder *b, const tmuf_visual_id *id) {
  if (!id->name || !id->name[0])
    return TMUF_VEHICLE_NO_PART;
  for (uint32_t i = 0; i < b->part_count; i++)
    if (strcmp(b->parts[i].name, id->name) == 0)
      return i;
  return TMUF_VEHICLE_NO_PART;
}

int tmuf_vehicle_visuals_build(tmuf_vehicle_visuals_data *out, tmuf_scene *scene, const tmuf_vehicle *vehicle,
                               tmuf_arena *arena) {
  memset(out, 0, sizeof *out);
  vehicle_builder b = {scene, arena, NULL, 0, 0, NULL, 0, 0, 0};
  vehicle_tree(&b, vehicle->solid_owner, vehicle->solid_tree, TMUF_VEHICLE_NO_PART, 0, 0.0f, FLT_MAX);
  if (b.oom || !build_list(&out->visuals, scene, b.list, b.count, NULL, arena, 0, 0)) {
    free(b.parts);
    free(b.list);
    return 0;
  }
  free(b.list);
  out->parts = b.parts;
  const tmuf_vehicle_struct *st = vehicle->visual_struct;
  const uint32_t level_count = st ? st->visual_vehicle_count : 0;
  tmuf_vehicle_visual_level *levels = TMUF_ARENA_ARRAY(arena, tmuf_vehicle_visual_level, level_count ? level_count : 1);
  if (!levels) {
    tmuf_vehicle_visuals_free(out);
    return 0;
  }
  for (uint32_t k = 0; k < level_count; k++) {
    const tmuf_visual_vehicle_def *d = &st->visual_vehicles[k];
    tmuf_vehicle_visual_level *l = &levels[k];
    memset(l, 0, sizeof *l);
    l->quality = d->quality;
    l->body = part_named(&b, &d->body);
    l->pilot_head = part_named(&b, &d->pilot_head);
    l->shadow = part_named(&b, &d->shadow);
    tmuf_vehicle_visual_wheel *w = TMUF_ARENA_ARRAY(arena, tmuf_vehicle_visual_wheel, d->wheel_count ? d->wheel_count : 1);
    tmuf_vehicle_visual_arm *a = TMUF_ARENA_ARRAY(arena, tmuf_vehicle_visual_arm, d->arm_count ? d->arm_count : 1);
    tmuf_vehicle_visual_light *li = TMUF_ARENA_ARRAY(arena, tmuf_vehicle_visual_light, d->light_count ? d->light_count : 1);
    if (!w || !a || !li) {
      tmuf_vehicle_visuals_free(out);
      return 0;
    }
    for (uint32_t i = 0; i < d->wheel_count; i++) {
      w[i].rolling = part_named(&b, &d->wheels[i].rolling);
      w[i].fixed = part_named(&b, &d->wheels[i].fixed);
      w[i].bouncing = part_named(&b, &d->wheels[i].bouncing);
      w[i].steering = part_named(&b, &d->wheels[i].steering);
      w[i].wheel = d->wheels[i].wheel;
      w[i].steers = d->wheels[i].steers;
    }
    for (uint32_t i = 0; i < d->arm_count; i++) {
      a[i].arm = part_named(&b, &d->arms[i].arm);
      a[i].from = part_named(&b, &d->arms[i].from);
      a[i].to = part_named(&b, &d->arms[i].to);
      a[i].rolls = d->arms[i].rolls;
      a[i].wheel = d->arms[i].wheel;
    }
    for (uint32_t i = 0; i < d->light_count; i++) {
      li[i].part = part_named(&b, &d->lights[i].tree);
      li[i].kind = d->lights[i].kind;
    }
    l->wheel_count = d->wheel_count;
    l->wheels = w;
    l->arm_count = d->arm_count;
    l->arms = a;
    l->light_count = d->light_count;
    l->lights = li;
    /* the level's group: the tree its first wheel hangs from */
    l->root = TMUF_VEHICLE_NO_PART;
    for (uint32_t i = 0; i < d->wheel_count && l->root == TMUF_VEHICLE_NO_PART; i++)
      if (w[i].rolling != TMUF_VEHICLE_NO_PART)
        l->root = b.parts[w[i].rolling].parent;
  }
  out->view.visuals = out->visuals.view;
  out->view.part_count = b.part_count;
  out->view.parts = b.parts;
  out->view.level_count = level_count;
  out->view.levels = levels;
  return 1;
}

void tmuf_vehicle_visuals_free(tmuf_vehicle_visuals_data *v) {
  tmuf_visuals_free(&v->visuals);
  free(v->parts);
  memset(v, 0, sizeof *v);
}

int tmuf_visuals_build_list(tmuf_visuals_data *out, tmuf_scene *scene, const tmuf_scene_visual *list, uint32_t n,
                            tmuf_arena *arena) {
  return build_list(out, scene, list, n, NULL, arena, 1, 0);
}

void tmuf_visuals_free(tmuf_visuals_data *v) {
  free(v->meshes);
  free(v->materials);
  free(v->instances);
  memset(v, 0, sizeof *v);
}
