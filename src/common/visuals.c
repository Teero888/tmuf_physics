/* What a track draws (tmuf_track_visuals): the scene's visible visuals as
   plain data. Meshes and materials are shared between the instances that
   place them; a material names the texture files its shader samples. */

#include "common/visuals.h"

#include "common/lightmap.h"

#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { CLS_VISUAL = 0x09006000u, CLS_SHADER = 0x09002000u, CLS_MATERIAL = 0x09079000u, CLS_SAMPLER = 0x0907e000u,
       CLS_BITMAP = 0x09011000u, CLS_SHADER_PASS = 0x09067000u, CLS_FUNC_LAYER_UV = 0x05015000u,
       CLS_FUNC_SHADERS = 0x05014000u };

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
  tmuf_vehicle_lighting *lighting; /* the car's: filled from the renders its bitmaps name */
  int is_night;                    /* the fid parameter IsNight: materials' night shaders */
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
  if (b->lighting && bm->render && bm->render->data && bm->render->cls) {
    const tmuf_plug_bitmap_render *r = bm->render->data;
    tmuf_vehicle_lighting *l = b->lighting;
    if (bm->render->cls->id == 0x09058000u && r->has_hemisphere) {
      l->has_hemisphere = 1;
      l->hemi_exp_l = r->exp_l;
      l->hemi_exp_a = r->exp_a;
      l->hemi_layout = r->hemi_layout;
    } else if (bm->render->cls->id == 0x09021000u && r->has_light_from_map) {
      l->has_light_from_map = 1;
      l->lfm_grid = r->lfm_grid;
      l->lfm_grid_max = r->lfm_grid_max;
      l->lfm_top = r->lfm[0];
      l->lfm_depth = r->lfm[1];
      memcpy(l->lfm_values, r->lfm + 2, sizeof l->lfm_values);
    }
  }
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

/* a shader function (CFuncShaderLayerUV) on the texture its layer names */
static void layer_uv_on(builder *b, tmuf_visual_texture *t, uint32_t n, const tmuf_func_layer_uv *f, tmuf_asset *fa) {
  if (!f->layer)
    return;
  for (uint32_t i = 0; i < n; i++) {
    if (!t[i].sampler || strcmp(t[i].sampler, f->layer) != 0)
      continue;
    t[i].has_anim = 1;
    t[i].anim_auto = f->auto_motion;
    t[i].anim_type = f->signal;
    t[i].anim_period = f->has_period ? f->period : 1.f;
    t[i].anim_phase = f->phase;
    memcpy(t[i].anim_start, f->vec28, sizeof t[i].anim_start);
    memcpy(t[i].anim_delta, f->vec30, sizeof t[i].anim_delta);
    memcpy(t[i].anim_scale, f->vec38, sizeof t[i].anim_scale);
    memcpy(t[i].anim_cells, f->cells, sizeof t[i].anim_cells);
    t[i].anim_flip_v = f->flip_v;
    t[i].anim_file = dup(b->arena, fa ? fa->path : "");
  }
}

/* the shader's function (+0x34): one CFuncShaderLayerUV, or a CFuncShaders
   list of them */
static void shader_funcs(builder *b, tmuf_visual_texture *t, uint32_t n, tmuf_asset *sa, const tmuf_plug_shader *sh) {
  tmuf_asset *fa = NULL;
  tmuf_gbx_node *fn = sh->func ? tmuf_assets_follow(&b->scene->assets, sa, sh->func, &fa) : NULL;
  if (node_class(fn) == CLS_FUNC_LAYER_UV && fn->data) {
    layer_uv_on(b, t, n, fn->data, fa);
  } else if (node_class(fn) == CLS_FUNC_SHADERS && fn->data) {
    const tmuf_func_shaders *list = fn->data;
    for (uint32_t i = 0; i < list->funcs.count; i++) {
      tmuf_asset *la = NULL;
      tmuf_gbx_node *ln = tmuf_assets_follow(&b->scene->assets, fa, list->funcs.nodes[i], &la);
      if (node_class(ln) == CLS_FUNC_LAYER_UV && ln->data)
        layer_uv_on(b, t, n, ln->data, la);
    }
  }
}

/* the textures of a shader: its sampler addresses, the material's custom
   bitmaps replacing those of the same sampler name; then the custom bitmaps
   no address names (the game's programs sample them by name, e.g. a block's
   "Lighting") */
static void shader_textures(builder *b, tmuf_visual_material *m, tmuf_asset *sa, const tmuf_plug_shader *sh,
                            const tmuf_plug_material_custom *custom, tmuf_asset *ca, const tmuf_plug_bitmap **first) {
  *first = NULL;
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
    memset(&t[n], 0, sizeof t[n]);
    t[n].sampler = dup(b->arena, ad->sampler ? ad->sampler : "");
    t[n].texcoord = ad->has_address ? (ad->address_flags >> 15) & 31u : 0u;
    t[n].generate = ad->has_address ? ad->address_flags & 0xffu : 0u;
    t[n].has_transform = ad->has_transform;
    memcpy(t[n].transform, ad->transform, sizeof t[n].transform);
    t[n].has_matrix = ad->has_matrix;
    memcpy(t[n].matrix, ad->matrix, sizeof t[n].matrix);
    if (bitmap)
      bitmap_file(b, bowner, bitmap, &t[n], ad->has_address && (ad->address_flags & 0x1000u));
    if (i == 0 && bitmap) {
      tmuf_gbx_node *bn = tmuf_assets_follow(&b->scene->assets, bowner, bitmap, NULL);
      if (node_class(bn) == CLS_BITMAP && bn->data)
        *first = bn->data;
    }
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
  shader_funcs(b, t, n, sa, sh);
  m->textures = t;
  m->texture_count = n;
}

/* CPlugBitmap::UsageIsBumpNormal */
static int usage_is_bump(uint32_t usage) {
  switch (usage) {
  case 5:
  case 6:
  case 10:
  case 11:
  case 19:
  case 20:
  case 24:
  case 25:
  case 26:
  case 27:
  case 28:
    return 1;
  default:
    return 0;
  }
}

/* How the game draws a material's shader (see tmuf_visual_material):
   CPlugShaderApply::OnNodLoaded and ComputeRequireAlphaBlending at load,
   the delayed render lists, CDx9ShaderKeeper::Undirty's render states.
   alpha_bitmap: the bitmap of the shader's first texture (its output alpha
   texture), NULL for none. */
static void material_draw_state(tmuf_visual_material *m, uint32_t cls, const tmuf_plug_shader *sh, const tmuf_plug_bitmap *alpha_bitmap) {
  const int apply = cls == 0x09026000u || cls == 0x09068000u || cls == 0x09069000u;
  const uint32_t st = sh->has_apply_state ? sh->apply_state[0] : 0u;
  const uint32_t src = st & 31u, dst = (st >> 5) & 31u, op = (st >> 10) & 7u, func = (st >> 24) & 7u;
  const uint32_t usage = alpha_bitmap && alpha_bitmap->has_usage ? alpha_bitmap->usage : 0u;
  uint32_t f = sh->has_flags ? sh->flags[0] : 0u;
  m->shader_class = cls;
  m->alpha_texture = alpha_bitmap && sh->address_count ? 0u : UINT32_MAX;
  m->alpha_texture_usage = usage;
  m->has_generic_flags = sh->has_generic;
  m->generic_flags = sh->generic_flags;
  if (apply && sh->has_apply_state) {
    /* CPlugShaderApply::ComputeRequireAlphaBlending */
    if (op == 0 && dst == 5) {
      f |= 0x180u;
      if (!(st & 0x10000000u) && alpha_bitmap && (usage & 0xffu) != 7u && !usage_is_bump(usage & 0xffu) && (usage & 0x200000u))
        f &= ~0x100u;
    } else if (op == 0 && src == 1 && dst == 0) {
      f &= ~0x100u;
      f = func != 6u ? f | 0x80u : f & ~0x80u;
    } else {
      f |= 0x180u;
    }
    /* OnNodLoaded: AlphaToCoverage */
    m->alpha_to_coverage =
        !(st & 0x400000u) && src == 4 && dst == 5 && op == 0 && alpha_bitmap && alpha_bitmap->has_flags && (alpha_bitmap->flags & 0x1000000u);
  }
  m->draw_flags = f;
  const uint32_t f1 = sh->has_flags ? sh->flags[1] : 0u;
  m->static_shadow = (f1 >> 21) & 1u;
  m->shadow_caster_disable = (f1 >> 18) & 1u;
  m->shadow_depth_bias_extra = (f1 >> 16) & 1u;
  m->double_sided = (f >> 10) & 1u;
  /* the delayed render list and the prepass (CVisionViewport) */
  if (f & 0x40000u) {
    m->draw_list = TMUF_DRAW_SORT_CUSTOM;
    m->sort_position = (f >> 26) & 3u;
    m->prepass = m->sort_position < 2;
  } else {
    m->draw_list = (f & 0x100u) ? TMUF_DRAW_BLENDED : (f & 0x80u) ? TMUF_DRAW_ALPHA_TEST : TMUF_DRAW_OPAQUE;
    m->prepass = m->draw_list != TMUF_DRAW_BLENDED && !m->static_shadow;
  }
  /* CDx9ShaderKeeper::Undirty */
  const int bit21 = (f & 0x80u) && alpha_bitmap && (usage & 0x200000u);
  uint32_t bsrc = src;
  m->alpha_test = 0;
  m->alpha_ref = 0;
  m->alpha_func = TMUF_CMP_ALWAYS;
  if (f & 0x100u) {
    if (bit21 && !(st & 0x10000000u)) {
      if (src == 4 && dst == 5) {
        m->alpha_test = 1;
        m->alpha_ref = 128;
        m->alpha_func = TMUF_CMP_GREATER;
        if (func == 6u)
          bsrc = 1;
      }
    } else if ((src == 0 || src == 4) && (dst == 1 || dst == 5)) {
      m->alpha_test = 1;
      m->alpha_ref = 0;
      m->alpha_func = TMUF_CMP_NOT_EQUAL;
    }
    m->alpha_blend = 1;
  } else {
    m->alpha_blend = 0;
    if (bit21 && src == 4) {
      m->alpha_test = 1;
      m->alpha_ref = 128; /* the viewport's reference */
      m->alpha_func = TMUF_CMP_GREATER;
    }
  }
  m->blend_src = bsrc;
  m->blend_dst = dst;
  m->blend_op = op;
  if (sh->has_apply_state && func != 6u) {
    m->alpha_test = 1;
    m->alpha_ref = (st >> 14) & 0xffu;
    m->alpha_func = func + 2u;
  }
}

/* the shader's passes: their GPU programs' files and constants */
static void shader_passes(builder *b, tmuf_visual_material *m, tmuf_asset *sa, const tmuf_plug_shader *sh) {
  if (!sh->pass_count)
    return;
  tmuf_visual_pass *p = TMUF_ARENA_ARRAY(b->arena, tmuf_visual_pass, sh->pass_count);
  if (!p) {
    b->oom = 1;
    return;
  }
  memset(p, 0, sizeof *p * sh->pass_count);
  uint32_t n = 0;
  for (uint32_t i = 0; i < sh->pass_count; i++) {
    tmuf_asset *pa;
    tmuf_gbx_node *pn = tmuf_assets_follow(&b->scene->assets, sa, sh->passes[i], &pa);
    if (node_class(pn) != CLS_SHADER_PASS || !pn->data)
      continue;
    const tmuf_plug_shader_pass *sp = pn->data;
    for (int k = 0; k < 2; k++) {
      const tmuf_plug_gpu_program *g = &sp->programs[k];
      tmuf_visual_program *v = k ? &p[n].pixel : &p[n].vertex;
      if (g->file) {
        char path[1200];
        if (g->file->external) {
          v->file = dup(b->arena, g->file->file);
          if (pa && tmuf_packset_resolve(b->scene->assets.set, &pa->gbx, g->file, pa->path, path, sizeof path).pack >= 0)
            v->pack_file = dup(b->arena, path);
        }
      }
      v->constant_count = g->constant_count;
      for (uint32_t c = 0; c < g->constant_count; c++) {
        v->constant_names[c] = dup(b->arena, g->constant_names[c]);
        memcpy(v->constants[c], g->constants[c], sizeof v->constants[c]);
      }
    }
    n++;
  }
  m->passes = p;
  m->pass_count = n;
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
                                          : tmuf_scene_material_shader(b->scene, owner, ref, b->is_night, &sa,
                                                                       &custom, &ca);
    if (node_class(sn) == CLS_SHADER && sn->data) {
      const tmuf_plug_shader *sh = sn->data;
      m->has_shader_flags = sh->has_flags;
      m->shader_flags[0] = sh->flags[0];
      m->shader_flags[1] = sh->flags[1];
      m->has_render_state = sh->has_apply_state;
      m->render_state[0] = sh->apply_state[0];
      m->render_state[1] = sh->apply_state[1];
      m->visible_id = sh->visible_id;
      m->hidden = (sh->visible_id & 0x100u) != 0;
      const tmuf_plug_bitmap *alpha_bitmap;
      shader_textures(b, m, sa, sh, custom, ca, &alpha_bitmap);
      material_draw_state(m, sn->class_id, sh, alpha_bitmap);
      shader_passes(b, m, sa, sh);
    } else {
      m->alpha_texture = UINT32_MAX;
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
  m->sub_visual_count = pv->sub_visual_count;
  m->sub_visuals = pv->sub_visuals;
  memcpy(m->bounds, pv->bbox, sizeof m->bounds);
  *slot = b->mesh_count++;
  return *slot;
}

/* a tree's CFuncTreeSubVisualSequence as the public sequence, NULL for none */
static const tmuf_visual_sequence *sequence_of(builder *b, const tmuf_scene_visual *v) {
  tmuf_asset *fa = NULL;
  tmuf_gbx_node *fn = v->func ? tmuf_assets_follow(&b->scene->assets, v->owner, v->func, &fa) : NULL;
  if (node_class(fn) != 0x05031000u || !fn->data)
    return NULL;
  const tmuf_func_tree_sequence *f = fn->data;
  const tmuf_func_keys *keys = f->has_inline_keys ? &f->inline_keys : NULL;
  if (!keys && f->keys) {
    tmuf_gbx_node *kn = tmuf_assets_follow(&b->scene->assets, fa, f->keys, NULL);
    keys = kn && kn->data ? kn->data : NULL;
  }
  if (!f->has_period || !keys || keys->x_count < 2 || keys->natural_count < keys->x_count)
    return NULL;
  tmuf_visual_sequence *s = TMUF_ARENA_ARRAY(b->arena, tmuf_visual_sequence, 1);
  if (!s)
    return NULL;
  s->period = f->period;
  s->phase = f->phase;
  s->key_count = keys->x_count;
  s->key_times = keys->xs;
  s->key_values = keys->naturals;
  return s;
}

static int build_list(tmuf_visuals_data *out, tmuf_scene *scene, const tmuf_scene_visual *list, uint32_t n,
                      const uint32_t *lightmap_of_corpus, tmuf_arena *arena, int sprites, int remap,
                      tmuf_vehicle_lighting *lighting, int is_night) {
  memset(out, 0, sizeof *out);
  builder b = {scene, arena, NULL, NULL, 0, 0, {0}, {0}, 0, sprites, lighting, is_night};
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
    /* only the scene's visuals have mips (tmuf_visuals_build) */
    in->mip = list == scene->visuals ? v->mip : UINT32_MAX;
    in->mip_level = list == scene->visuals ? v->mip_level : 0;
    in->sequence = b.meshes[mesh].sub_visual_count ? sequence_of(&b, v) : NULL;
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

/* CPlugTreeVisualMip::SetDistributionFromFarZs (the bin count, a static of
   the game, is 5) */
#define MIP_BINS 5u

static void mip_distribution(tmuf_visual_mip *m) {
  const uint32_t n = m->level_count;
  const float *far_z = m->far_z;
  m->table_count = 1;
  if (n <= 2) {
    m->table[0] = 0;
    m->z0 = n <= 1 ? (float)0x1.9999986666660p+124 : far_z[0];
    m->scale = 100000.0f;
    return;
  }
  m->z0 = far_z[0];
  if (n == 3) {
    m->table[0] = 1;
    m->scale = 1.0f / (far_z[1] - far_z[0]);
    return;
  }
  const float range = far_z[n - 2] - far_z[0];
  m->scale = 1.0f / range;
  m->table_count = MIP_BINS;
  uint32_t level = 1;
  for (uint32_t i = 0; i < MIP_BINS; i++) {
    const float z = (float)i * range / (float)MIP_BINS + m->z0;
    while (level + 1 < n && far_z[level] < z)
      level++;
    m->table[i] = level;
  }
}

uint32_t tmuf_visual_mip_level(const tmuf_visual_mip *mip, float z) {
  const uint32_t n = mip->level_count;
  const float t = (z - mip->z0) * mip->scale;
  if (!(t >= 1e-5f) && !isnan(t))
    return 0;
  if ((double)t > 0x1.fffebp-1 || isnan(t))
    return n ? n - 1 : 0;
  const float bin = (float)mip->table_count * t - 0.5f;
  const long i = lrintf(bin);
  uint32_t level = i >= 0 && (unsigned long)i < mip->table_count ? mip->table[i] : 0;
  if (level >= n)
    level = n ? n - 1 : 0;
  return level;
}

float tmuf_visual_mip_z(const tmuf_visual_mip *mip, const float view_z[4], float near_z, float f) {
  if (mip->rule == TMUF_VISUAL_MIP_PACKED) {
    /* the near clip plane in world: normal -forward, -(plane . c + w) */
    const float *c = mip->sphere;
    const float p0 = -view_z[0], p1 = -view_z[1], p2 = -view_z[2], w = near_z - view_z[3];
    const float d = -(((p1 * c[1] + p0 * c[0]) + p2 * c[2]) + w);
    return (d - mip->sphere[3]) * f;
  }
  /* GmBoxAligned::SetMult's z row, then the box's smallest z */
  const float *b = mip->box;
  const float cz = ((view_z[1] * b[1] + view_z[0] * b[0]) + view_z[2] * b[2]) + view_z[3];
  const float hz = (fabsf(view_z[1]) * b[4] + fabsf(view_z[0]) * b[3]) + fabsf(view_z[2]) * b[5];
  return (cz - hz) * f;
}

int tmuf_visuals_build(tmuf_visuals_data *out, tmuf_scene *scene, const uint32_t *lightmap_of_corpus, int is_night,
                       tmuf_arena *arena) {
  if (!build_list(out, scene, scene->visuals, scene->visual_count, lightmap_of_corpus, arena, 0, 1, NULL, is_night))
    return 0;
  if (!scene->mip_count)
    return 1;
  tmuf_visual_mip *mips = calloc(scene->mip_count, sizeof *mips);
  if (!mips) {
    tmuf_visuals_free(out);
    return 0;
  }
  for (uint32_t i = 0; i < scene->mip_count; i++) {
    const tmuf_scene_mip *sm = &scene->mips[i];
    tmuf_visual_mip *m = &mips[i];
    m->rule = sm->rule;
    m->parent = sm->parent;
    m->parent_level = sm->parent_level;
    memcpy(m->box, sm->box, sizeof m->box);
    memcpy(m->sphere, sm->sphere, sizeof m->sphere);
    m->level_count = sm->level_count;
    m->far_z = sm->far_z;
    m->block = sm->corpus < scene->corpus_count ? scene->corpora[sm->corpus].tag : 0;
    mip_distribution(m);
  }
  out->mips = mips;
  out->view.mip_count = scene->mip_count;
  out->view.mips = mips;
  return 1;
}

/* ---- the vehicle ---- */

/* ---- lights (CPlugTreeLight -> CPlugLight -> GxLight*) ---- */

enum { CLS_PLUG_LIGHT = 0x0901d000u };

static float cos_half_degrees(float a) { return cosf(a * 3.14159265358979f / 360.0f); }

/* One tree light: its CPlugLight (ref, in owner) placed at iso. is_night: the
   fid parameter IsNight (CPlugTreeLight::ApplyFidParameters). Returns 0
   when the reference doesn't lead to a GxLight, or when the game drops it. */
static int light_fill(builder *b, tmuf_asset *owner, tmuf_gbx_node *ref, const tmuf_iso *iso, int is_night,
                      const char *mood_folder, tmuf_light *out) {
  memset(out, 0, sizeof *out);
  tmuf_asset *pa = NULL, *ga;
  tmuf_gbx_node *pn = NULL;
  /* the fid parameters of the map's mood: a light file of the same name in
     the mood's folder replaces the one the solid names (e.g. Stadium's
     Moods\Sunset\StadiumspotBig.Light.Gbx) */
  if (mood_folder && mood_folder[0] && ref->external && ref->file) {
    const char *name = strrchr(ref->file, '\\');
    name = name ? name + 1 : ref->file;
    char path[1024];
    const size_t fl = strlen(mood_folder);
    snprintf(path, sizeof path, "%s%s%s", mood_folder, mood_folder[fl - 1] == '\\' ? "" : "\\", name);
    tmuf_asset *ma = tmuf_assets_load_path(&b->scene->assets, path);
    if (ma && !ma->failed && ma->class_id == CLS_PLUG_LIGHT && ma->gbx.nodes && ma->gbx.nodes[0].data) {
      pa = ma;
      pn = &ma->gbx.nodes[0];
    }
  }
  if (!pn)
    pn = tmuf_assets_follow(&b->scene->assets, owner, ref, &pa);
  if (node_class(pn) != CLS_PLUG_LIGHT || !pn->data)
    return 0;
  const tmuf_plug_light *pl = pn->data;
  tmuf_gbx_node *gn = pl->light ? tmuf_assets_follow(&b->scene->assets, pa, pl->light, &ga) : NULL;
  if (!gn || !gn->data || node_class(gn) != 0x04001000u)
    return 0;
  const tmuf_gx_light *g = gn->data;
  switch (gn->class_id) {
  case 0x04003000u:
    out->kind = TMUF_LIGHT_POINT;
    break;
  case 0x04002000u:
    out->kind = TMUF_LIGHT_BALL;
    break;
  case 0x0400b000u:
    out->kind = TMUF_LIGHT_SPOT;
    break;
  default:
    out->kind = TMUF_LIGHT_OTHER;
    break;
  }
  out->archived_flags = g->flags;
  out->plug_flags = pl->flags;
  out->night_only = (int)(pl->flags & 1u);
  /* CPlugTreeLight::ApplyFidParameters: its global @0xd16c08 is 1 (never
     written), so a night-only light on a day map loses its GxLight copy
     (released, +0xb0 = 0) and the flags are not forced: the copy keeps the
     archived ones (UpdateFromPlugLight) */
  if (out->night_only && !is_night)
    return 0;
  out->flags = g->flags;
  for (int r = 0; r < 3; r++)
    for (int c = 0; c < 3; c++)
      out->location.r.m[r][c] = iso->m[r][c];
  out->location.t = (tmuf_vec3){iso->t[0], iso->t[1], iso->t[2]};
  for (int k = 0; k < 3; k++) {
    out->position[k] = iso->t[k];
    out->direction[k] = iso->m[k][2];
  }
  memcpy(out->rgb, g->rgb, sizeof out->rgb);
  out->intensity = g->intensity;
  out->diffuse_intensity = g->diffuse;
  out->specular_intensity = g->specular;
  out->specular_power = g->specular_power;
  for (int k = 0; k < 3; k++) {
    out->diffuse_rgb[k] = g->intensity * g->diffuse * g->rgb[k];
    out->specular_rgb[k] = g->specular * g->intensity * g->rgb[k];
  }
  out->flare_intensity = g->flare_intensity;
  out->flare_size = g->point[0];
  out->flare_bias_z = g->point[1];
  memcpy(out->radius, g->radius, sizeof out->radius);
  if (out->kind == TMUF_LIGHT_BALL || out->kind == TMUF_LIGHT_SPOT) {
    /* ball[]: +0x80, +0x78, +0x7c, +0x84, +0x88, +0x8c */
    out->ball_flags = g->ball_flags;
    out->attenuation[0] = g->ball[1];
    out->attenuation[1] = g->ball[2];
    memcpy(out->ambient_rgb, g->ball + 3, sizeof out->ambient_rgb);
  }
  if (out->kind == TMUF_LIGHT_SPOT) {
    out->angle_inner = g->spot[0];
    out->angle_outer = g->spot[1];
    /* UpdateCosHalfAngles: the flare angle is the outer one unless set */
    out->angle_flare = (g->spot_flags & 1u) ? g->spot[2] : g->spot[1];
    out->falloff = g->spot[5];
    out->cos_inner = cos_half_degrees(out->angle_inner);
    out->cos_outer = cos_half_degrees(out->angle_outer);
    out->cos_flare = cos_half_degrees(out->angle_flare);
  }
  if (pl->flare) {
    tmuf_visual_texture t;
    memset(&t, 0, sizeof t);
    tmuf_vehicle_lighting *saved = b->lighting;
    b->lighting = NULL;
    bitmap_file(b, pa, pl->flare, &t, 0);
    b->lighting = saved;
    out->flare_file = t.file;
    out->flare_pack_file = t.pack_file;
  }
  out->file = dup(b->arena, (ref->external || pn != ref) && pa ? pa->path : "");
  return 1;
}

static int lights_build(tmuf_lights_data *out, tmuf_scene *scene, const tmuf_scene_light *list, uint32_t n,
                        int is_night, const char *mood_folder, tmuf_arena *arena) {
  memset(out, 0, sizeof *out);
  builder b = {scene, arena, NULL, NULL, 0, 0, {0}, {0}, 0, 0, NULL, is_night};
  out->lights = malloc(sizeof *out->lights * (n ? n : 1));
  if (!out->lights)
    return 0;
  for (uint32_t i = 0; i < n; i++) {
    tmuf_light *l = &out->lights[out->count];
    if (!light_fill(&b, list[i].owner, list[i].light, &list[i].iso, is_night, mood_folder, l))
      continue;
    l->block = list[i].tag;
    l->lod_near = list[i].lod_near;
    l->lod_far = list[i].lod_far;
    l->decorator_hidden = list[i].hidden;
    out->count++;
  }
  return 1;
}

int tmuf_track_lights_build(tmuf_lights_data *out, tmuf_scene *scene, int is_night, const char *mood_folder,
                            tmuf_arena *arena) {
  return lights_build(out, scene, scene->lights, scene->light_count, is_night, mood_folder, arena);
}

void tmuf_lights_free(tmuf_lights_data *l) {
  free(l->lights);
  memset(l, 0, sizeof *l);
}

void tmuf_light_box(const tmuf_light *l, uint32_t which, float box[6]) {
  float r = 0.0f;
  if (which < 4) {
    r = l->radius[which];
  } else {
    if ((l->flags & 1u) && l->radius[0] > 0.0f)
      r = l->radius[0];
    if ((l->flags & 8u) && r < l->radius[1])
      r = l->radius[1];
    if ((l->flags & 4u) && r < l->radius[2])
      r = l->radius[2];
  }
  if (l->kind != TMUF_LIGHT_SPOT) {
    for (int k = 0; k < 3; k++) {
      box[k] = l->position[k];
      box[3 + k] = r;
    }
    return;
  }
  /* GmBoxAligned::SetFromConeAndRadius(apex, axis, cos of the outer half
     angle, r) */
  const float c = l->cos_outer, sn = sqrtf(1.0f - c * c);
  float mn[3], mx[3];
  for (int k = 0; k < 3; k++) {
    const float d = l->direction[k], sd = sqrtf(1.0f - d * d);
    float hi = r;
    if (d <= c) {
      float f = d * c + sd * sn;
      hi = (f > 0.0f ? f : 0.0f) * r;
    }
    float lo = -r;
    if (-d <= c) {
      float f = sd * sn - d * c;
      lo = -r * (f > 0.0f ? f : 0.0f);
    }
    mn[k] = l->position[k] + lo;
    mx[k] = l->position[k] + hi;
  }
  for (int k = 0; k < 3; k++) {
    box[k] = (mn[k] + mx[k]) * 0.5f;
    box[3 + k] = (mx[k] - mn[k]) * 0.5f;
  }
}

typedef struct vehicle_builder {
  tmuf_scene *scene;
  tmuf_arena *arena;
  tmuf_vehicle_part *parts;
  uint32_t part_count, part_cap;
  tmuf_scene_visual *list;
  uint32_t count, cap;
  int oom;
  tmuf_scene_light *lights; /* its light trees (tag: the part) */
  uint32_t light_count, light_cap;
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
  if (cls == 0x09062000u && t->light) {
    if (b->light_count == b->light_cap) {
      uint32_t cap = b->light_cap ? b->light_cap * 2 : 8;
      tmuf_scene_light *l = realloc(b->lights, sizeof *l * cap);
      if (!l) {
        b->oom = 1;
        return;
      }
      b->lights = l;
      b->light_cap = cap;
    }
    tmuf_scene_light *l = &b->lights[b->light_count++];
    l->owner = ta;
    l->light = t->light;
    tmuf_iso_identity(&l->iso); /* the part's own frame */
    l->tag = index;
    l->lod_near = lod_near;
    l->lod_far = lod_far;
    l->hidden = 0;
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
                               int is_night, const char *mood_folder, tmuf_arena *arena) {
  memset(out, 0, sizeof *out);
  vehicle_builder b = {scene, arena, NULL, 0, 0, NULL, 0, 0, 0, NULL, 0, 0};
  vehicle_tree(&b, vehicle->solid_owner, vehicle->solid_tree, TMUF_VEHICLE_NO_PART, 0, 0.0f, FLT_MAX);
  tmuf_vehicle_lighting *lighting = &out->view.lighting;
  /* the game's defaults (CPlugBitmapRenderLightFromMap constructor) */
  lighting->lfm_footprint = 1.0f + 1.5f / 2.0f;
  lighting->lfm_white = 0.5f;
  lighting->lfm_up_min = 0.8f;
  lighting->lfm_grid = lighting->lfm_grid_max = 2;
  lighting->lfm_depth = 10.0f;
  lighting->lfm_top = 0.05f;
  if (b.oom || !build_list(&out->visuals, scene, b.list, b.count, NULL, arena, 0, 0, lighting, is_night) ||
      !lights_build(&out->lights, scene, b.lights, b.light_count, is_night, mood_folder, arena)) {
    free(b.parts);
    free(b.list);
    free(b.lights);
    return 0;
  }
  free(b.list);
  free(b.lights);
  if (!tmuf_tree_box(scene, vehicle->solid_owner, vehicle->solid_tree, lighting->box))
    memset(lighting->box, 0, sizeof lighting->box);
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
  out->view.light_count = out->lights.count;
  out->view.lights = out->lights.lights;
  out->view.part_count = b.part_count;
  out->view.parts = b.parts;
  out->view.level_count = level_count;
  out->view.levels = levels;
  return 1;
}

void tmuf_vehicle_visuals_free(tmuf_vehicle_visuals_data *v) {
  tmuf_visuals_free(&v->visuals);
  tmuf_lights_free(&v->lights);
  free(v->parts);
  memset(v, 0, sizeof *v);
}

int tmuf_visuals_build_list(tmuf_visuals_data *out, tmuf_scene *scene, const tmuf_scene_visual *list, uint32_t n,
                            int is_night, tmuf_arena *arena) {
  return build_list(out, scene, list, n, NULL, arena, 1, 0, NULL, is_night);
}

void tmuf_visuals_free(tmuf_visuals_data *v) {
  free(v->mips);
  free(v->meshes);
  free(v->materials);
  free(v->instances);
  memset(v, 0, sizeof *v);
}
