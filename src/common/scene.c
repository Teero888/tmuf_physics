#include "common/scene.h"
#include "common/scene_ctn.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "common/pack_classes.h"

/* ---- GmIso4 math, in the game's operation order ---- */

static float dot3(const float a[3], const float b[3]) {
  float xy = a[0] * b[0] + a[1] * b[1];
  return xy + a[2] * b[2];
}

void tmuf_iso_identity(tmuf_iso *iso) {
  memset(iso, 0, sizeof *iso);
  iso->m[0][0] = iso->m[1][1] = iso->m[2][2] = 1.0f;
}

void tmuf_iso_from_archive(tmuf_iso *iso, const float v[12]) {
  for (int r = 0; r < 3; r++)
    for (int c = 0; c < 3; c++)
      iso->m[r][c] = v[r * 3 + c];
  iso->t[0] = v[9];
  iso->t[1] = v[10];
  iso->t[2] = v[11];
}

void tmuf_iso_point(const tmuf_iso *iso, const float p[3], float out[3]) {
  float r[3];
  for (int i = 0; i < 3; i++)
    r[i] = dot3(iso->m[i], p) + iso->t[i];
  memcpy(out, r, sizeof r);
}

/* GmMath::Compose(a.rotation, b.rotation): each basis (column) of a mapped
   by b; translation = b applied to a's translation. */
void tmuf_iso_mult(tmuf_iso *out, const tmuf_iso *a, const tmuf_iso *b) {
  tmuf_iso r;
  for (int c = 0; c < 3; c++) {
    float col[3] = {a->m[0][c], a->m[1][c], a->m[2][c]};
    for (int i = 0; i < 3; i++)
      r.m[i][c] = dot3(b->m[i], col);
  }
  tmuf_iso_point(b, a->t, r.t);
  *out = r;
}

/* GmMat3::SetRotateQuarterY. */
static void rotate_quarter_y(tmuf_iso *iso, unsigned quarter) {
  static const float COS[4] = {1.0f, 0.0f, -1.0f, 0.0f};
  float c = COS[quarter & 3], s = COS[(quarter + 3) & 3];
  memset(iso->m, 0, sizeof iso->m);
  /* rows: X = (c, 0, -s), Y = (0, 1, 0), Z = (s, 0, c) */
  iso->m[0][0] = c;
  iso->m[0][2] = -s;
  iso->m[1][1] = 1.0f;
  iso->m[2][0] = s;
  iso->m[2][2] = c;
}

static int debug_enabled(void) {
  static int v = -1;
  if (v < 0)
    v = getenv("TMUF_SCENE_DEBUG") != NULL;
  return v;
}

/* ---- output ---- */

static void add_triangle(tmuf_scene *s, const float a[3], const float b[3], const float c[3], uint16_t material) {
  if (!s->collect_triangles)
    return;
  if (s->triangle_count == s->triangle_cap) {
    uint32_t cap = s->triangle_cap ? s->triangle_cap * 2 : 4096;
    tmuf_static_triangle *t = realloc(s->triangles, sizeof *t * cap);
    if (!t)
      return;
    s->triangles = t;
    s->triangle_cap = cap;
  }
  tmuf_static_triangle *t = &s->triangles[s->triangle_count++];
  memcpy(t->v[0], a, 12);
  memcpy(t->v[1], b, 12);
  memcpy(t->v[2], c, 12);
  t->material = material;
  t->block = s->current_block;
}

/* ---- solids and trees ---- */

static void emit_surface(tmuf_scene *s, tmuf_asset *owner, tmuf_gbx_node *surface_node, const tmuf_iso *world) {
  tmuf_asset *sa;
  tmuf_gbx_node *sn = tmuf_assets_follow(&s->assets, owner, surface_node, &sa);
  if (debug_enabled() && (!sn || !sn->data || sn->class_id != 0x0900c000u))
    fprintf(stderr, "      surface %p class %08x data %p skipped\n", (void *)sn, sn ? sn->class_id : 0, sn ? sn->data : NULL);
  if (!sn || !sn->data || sn->class_id != 0x0900c000u)
    return;
  const tmuf_plug_surface *surf = sn->data;
  tmuf_asset *ga;
  tmuf_gbx_node *gn = tmuf_assets_follow(&s->assets, sa, surf->geom, &ga);
  if (debug_enabled())
    fprintf(stderr, "      geom %p class %08x type %u tris %u\n", (void *)gn, gn ? gn->class_id : 0,
            gn && gn->data ? ((tmuf_plug_surface_geom *)gn->data)->type : 99,
            gn && gn->data ? ((tmuf_plug_surface_geom *)gn->data)->triangle_count : 0);
  if (!gn || !gn->data || gn->class_id != 0x0900f000u)
    return;
  const tmuf_plug_surface_geom *geom = gn->data;
  if (geom->type != TMUF_SURF_MESH)
    return;
  float *raised = NULL;
  uint8_t *raised_tris = NULL;
  if (s->pylon_raise && !tmuf_scene_raise_mesh(geom, s->pylon_raise, s->square_height, &raised, &raised_tris))
    return;
  const float *vertices = raised ? raised : geom->vertices;
  for (uint32_t i = 0; i < geom->triangle_count; i++) {
    const uint8_t *rec = geom->triangles + (size_t)i * 32;
    uint32_t idx[3];
    uint16_t mat;
    memcpy(idx, rec + 16, 12);
    memcpy(&mat, rec + 28, 2);
    float w[3][3];
    int ok = 1;
    for (int k = 0; k < 3; k++) {
      if (idx[k] >= geom->vertex_count) {
        ok = 0;
        break;
      }
      tmuf_iso_point(world, vertices + (size_t)idx[k] * 3, w[k]);
    }
    if (ok)
      add_triangle(s, w[0], w[1], w[2], mat);
  }
  free(raised);
  free(raised_tris);
}

int tmuf_scene_raise_mesh(const tmuf_plug_surface_geom *geom, uint32_t raise, float square_height, float **vertices,
                          uint8_t **triangles) {
  size_t vn = (size_t)geom->vertex_count * 3, tn = (size_t)geom->triangle_count * 32;
  float *v = malloc(sizeof *v * (vn ? vn : 1));
  uint8_t *t = malloc(tn ? tn : 1);
  if (!v || !t) {
    free(v);
    free(t);
    return 0;
  }
  if (vn)
    memcpy(v, geom->vertices, sizeof *v * vn);
  if (tn)
    memcpy(t, geom->triangles, tn);
  /* vertex y above square_height * 0.5 += square_height * raise */
  const float threshold = square_height * 0.5f;
  const float delta = square_height * (float)raise;
  for (uint32_t i = 0; i < geom->vertex_count; i++)
    if (v[i * 3 + 1] > threshold)
      v[i * 3 + 1] = v[i * 3 + 1] + delta;
  /* GmSurfMesh::ComputePlane: n = (v1 - v0) x (v2 - v0), normalized when
     its square is above 1e-10, plane distance ((-nx v0x) - ny v0y) - nz v0z */
  for (uint32_t i = 0; i < geom->triangle_count; i++) {
    uint8_t *rec = t + (size_t)i * 32;
    uint32_t idx[3];
    memcpy(idx, rec + 16, 12);
    if (idx[0] >= geom->vertex_count || idx[1] >= geom->vertex_count || idx[2] >= geom->vertex_count)
      continue;
    const float *a = v + (size_t)idx[0] * 3, *b = v + (size_t)idx[1] * 3, *c = v + (size_t)idx[2] * 3;
    const float e1x = b[0] - a[0], e1y = b[1] - a[1], e1z = b[2] - a[2];
    const float e2x = c[0] - a[0], e2y = c[1] - a[1], e2z = c[2] - a[2];
    float n[3] = {e2z * e1y - e2y * e1z, e1z * e2x - e2z * e1x, e1x * e2y - e2x * e1y};
    const float n2 = (n[1] * n[1] + n[0] * n[0]) + n[2] * n[2];
    if (n2 > 1.0e-5f * 1.0e-5f) {
      const float len = (float)sqrt((double)n2);
      const float inv = 1.0f / len;
      n[0] = n[0] * inv;
      n[1] = n[1] * inv;
      n[2] = inv * n[2];
    }
    const float d = ((-n[0] * a[0]) - n[1] * a[1]) - n[2] * a[2];
    memcpy(rec, n, 12);
    memcpy(rec + 12, &d, 4);
  }
  *vertices = v;
  *triangles = t;
  return 1;
}

static void emit_tree(tmuf_scene *s, tmuf_asset *owner, tmuf_gbx_node *tree_node, const tmuf_iso *parent, int depth) {
  if (depth > 64)
    return;
  tmuf_asset *ta;
  tmuf_gbx_node *tn = tmuf_assets_follow(&s->assets, owner, tree_node, &ta);
  if (debug_enabled())
    fprintf(stderr, "    %*stree -> %p class %08x cls %s data %p\n", depth * 2, "", (void *)tn, tn ? tn->class_id : 0,
            tn && tn->cls ? tn->cls->name : "-", tn ? tn->data : NULL);
  if (!tn || !tn->data)
    return;
  uint32_t cls = tn->cls ? tn->cls->id : 0;
  if (cls != 0x0904f000u && cls != 0x09015000u && cls != 0x09062000u)
    return; /* not a CPlugTree (generators, ...) */
  const tmuf_plug_tree *t = tn->data;
  if (debug_enabled() && getenv("TMUF_SCENE_TAG") && strtoul(getenv("TMUF_SCENE_TAG"), NULL, 16) == s->current_block) {
    tmuf_gbx_node *refs[3] = {t->visual, t->shader, t->material};
    static const char *names[3] = {"visual", "shader", "material"};
    for (int k = 0; k < 3; k++) {
      if (!refs[k])
        continue;
      tmuf_asset *ra;
      tmuf_gbx_node *rn = tmuf_assets_follow(&s->assets, ta, refs[k], &ra);
      fprintf(stderr, "    %*s  %s class %08x file %s asset %s\n", depth * 2, "", names[k], rn ? rn->class_id : 0,
              refs[k]->file ? refs[k]->file : "-", ra ? ra->path : "-");
    }
  }
  tmuf_iso world = *parent;
  if (t->has_iso) {
    tmuf_iso local;
    tmuf_iso_from_archive(&local, t->iso);
    tmuf_iso_mult(&world, &local, parent);
  }
  if (t->surface)
    emit_surface(s, ta, t->surface, &world);
  for (uint32_t i = 0; i < t->child_count; i++)
    emit_tree(s, ta, t->children[i], &world, depth + 1);
}

static void add_corpus(tmuf_scene *s, tmuf_asset *owner, tmuf_gbx_node *tree, const tmuf_iso *iso) {
  if (s->corpus_count == s->corpus_cap) {
    uint32_t cap = s->corpus_cap ? s->corpus_cap * 2 : 1024;
    tmuf_scene_corpus *c = realloc(s->corpora, sizeof *c * cap);
    if (!c)
      return;
    s->corpora = c;
    s->corpus_cap = cap;
  }
  tmuf_scene_corpus *c = &s->corpora[s->corpus_count++];
  c->owner = owner;
  c->tree = tree;
  c->iso = *iso;
  c->tag = s->current_block;
  c->pylon_raise = s->pylon_raise;
  c->trigger = s->current_trigger;
  c->item_flags = s->current_item_flags;
  /* Helper trees hang below a new CHALLENGEHELPERTREE tree without the
     collision flag: never collided. Other mobils keep their item group. */
  c->materials = s->current_materials;
  c->collision_group = s->helper_depth ? 0
                        : (s->force_static || !c->item_flags) ? 4
                                                               : (uint8_t)((c->item_flags >> 13) & 15u);
  c->is_static = s->helper_depth || s->force_static || !c->item_flags || (c->item_flags & 0x80000u) != 0;
  c->race_role = TMUF_RACE_NONE;
  c->respawn_current = c->has_spawn = 0;
  if (c->trigger && !s->helper_depth) {
    /* checkpoint triggers keep their archived item properties */
    c->collision_group = (uint8_t)((c->item_flags >> 13) & 15u);
    c->race_role = s->current_race_role;
    c->respawn_current = s->current_respawn_current;
    c->has_spawn = s->current_has_spawn;
    c->spawn = s->current_spawn;
  }
}

static void emit_solid(tmuf_scene *s, tmuf_asset *owner, tmuf_gbx_node *solid_node, const tmuf_iso *world, int depth) {
  tmuf_asset *sa;
  tmuf_gbx_node *sn = tmuf_assets_follow(&s->assets, owner, solid_node, &sa);
  if (debug_enabled())
    fprintf(stderr, "    solid %s ext %d -> %p class %08x data %p (%s)\n", solid_node->file ? solid_node->file : "", solid_node->external, (void *)sn,
            sn ? sn->class_id : 0, sn ? sn->data : NULL, sa ? sa->path : "");
  if (!sn || !sn->data || sn->class_id != 0x09005000u)
    return;
  const tmuf_plug_solid *solid = sn->data;
  if (solid->use_model) {
    if (depth < 8)
      emit_solid(s, sa, solid->model, world, depth + 1);
    return;
  }
  if (solid->tree) {
    add_corpus(s, sa, solid->tree, world);
    emit_tree(s, sa, solid->tree, world, 0);
  }
}

static void emit_mobil(tmuf_scene *s, tmuf_asset *owner, tmuf_gbx_node *mobil_node, const tmuf_iso *world, int depth) {
  if (depth > 16)
    return;
  tmuf_asset *ma;
  tmuf_gbx_node *mn = tmuf_assets_follow(&s->assets, owner, mobil_node, &ma);
  if (debug_enabled())
    fprintf(stderr, "  %*smobil %p class %08x cls %s data %p item %d flags %08x\n", depth * 2, "", (void *)mn,
            mn ? mn->class_id : 0, mn && mn->cls ? mn->cls->name : "-", mn ? mn->data : NULL,
            mn && mn->data && mn->cls && mn->cls->id == 0x0a005000u ? ((tmuf_scene_object *)mn->data)->has_item : -1,
            mn && mn->data && mn->cls && mn->cls->id == 0x0a005000u ? ((tmuf_scene_object *)mn->data)->item.physics_flags : 0);
  if (!mn || !mn->data)
    return;
  if (!mn->cls || mn->cls->id != 0x0a005000u)
    return;
  const tmuf_scene_object *m = mn->data;
  /* CGameCtnBlock::SetMobilAndHelper: the linked trigger mobils */
  uint8_t saved_trigger = s->current_trigger;
  uint32_t saved_flags = s->current_item_flags;
  if (m->name && (strcmp(m->name, "TriggerCheckpoint") == 0 || strcmp(m->name, "TriggerFinishLine") == 0))
    s->current_trigger = 1;
  s->current_item_flags = m->has_item ? m->item.physics_flags : 0;
  if (m->has_item && m->item.solid)
    emit_solid(s, ma, m->item.solid, world, 0);
  for (uint32_t i = 0; i < m->children.count; i++) {
    tmuf_asset *la;
    tmuf_gbx_node *ln = tmuf_assets_follow(&s->assets, ma, m->children.nodes[i], &la);
    if (!ln || !ln->data || !ln->cls || ln->cls->id != 0x0a014000u)
      continue;
    const tmuf_object_link *link = ln->data;
    tmuf_iso local, linked;
    tmuf_iso_from_archive(&local, link->iso);
    tmuf_iso_mult(&linked, &local, world);
    emit_mobil(s, la, link->object, &linked, depth + 1);
  }
  s->current_trigger = saved_trigger;
  s->current_item_flags = saved_flags;
}

/* ---- blocks ---- */

/* Identifier of a collector file (header chunk 0x0301a003: version, then the
   ident: name, collection, author). The game indexes block infos by it. */
static const char *collector_name(tmuf_scene *s, tmuf_pack_ref ref) {
  const tmuf_pack *pack = &s->assets.set->packs[ref.pack];
  tmuf_pack_stream ps;
  if (!tmuf_pack_stream_open(&ps, pack, ref.file))
    return NULL;
  tmuf_gbx g;
  tmuf_gbx_init(&g, &ps.base, &s->assets.arena, NULL, 0);
  const char *name = NULL;
  if (tmuf_gbx_read_header(&g)) {
    for (uint32_t i = 0; i < g.header_chunk_count; i++) {
      if (g.header_chunks[i].id != 0x0301a003u)
        continue;
      tmuf_mem_source ms;
      tmuf_mem_source_init(&ms, g.header_chunks[i].data, g.header_chunks[i].size);
      tmuf_gbx h;
      tmuf_gbx_init(&h, &ms.base, &s->assets.arena, NULL, 0);
      const char *id = tmuf_gbx_id(&h, NULL);
      if (!h.error && id && *id)
        name = id;
      break;
    }
  }
  tmuf_pack_stream_close(&ps);
  return name;
}

static int ieq(const char *a, const char *b) {
  for (; *a && *b; a++, b++) {
    char x = *a >= 'A' && *a <= 'Z' ? (char)(*a + 32) : *a;
    char y = *b >= 'A' && *b <= 'Z' ? (char)(*b + 32) : *b;
    if (x != y)
      return 0;
  }
  return *a == *b;
}

/* Appends every collector under folder whose file name contains kind (e.g.
   ".TMED", ".TMDecoration.") to the catalog. */
/* CGameCtnBlockInfoFlat .. CGameCtnBlockInfoRectAsym (Rally stores the
   latter as .EDRectAsym, the others as .TMED*) */
static int is_block_info_class(uint32_t id) { return id >= 0x0304f000u && id <= 0x03056000u && !(id & 0xfffu); }

static void build_catalog(tmuf_scene *s, const char *folder, const char *kind, uint8_t tag) {
  const tmuf_packset *set = s->assets.set;
  char path[512];
  size_t flen = strlen(folder);
  for (int p = 0; p < set->pack_count; p++)
    for (uint32_t f = 0; f < set->packs[p].file_count; f++) {
      if (!tmuf_pack_file_path(&set->packs[p], f, path, sizeof path) || strncmp(path, folder, flen) != 0)
        continue;
      if (kind ? !strstr(path, kind) : !is_block_info_class(set->packs[p].files[f].class_id))
        continue;
      const char *name = collector_name(s, (tmuf_pack_ref){p, f});
      if (!name)
        continue;
      if (s->catalog_count == s->catalog_cap) {
        uint32_t cap = s->catalog_cap ? s->catalog_cap * 2 : 256;
        tmuf_scene_catalog_entry *c = realloc(s->catalog, sizeof *c * cap);
        if (!c)
          return;
        s->catalog = c;
        s->catalog_cap = cap;
      }
      s->catalog[s->catalog_count++] = (tmuf_scene_catalog_entry){name, {p, f}, tag};
    }
}

static tmuf_pack_ref find_collector(const tmuf_scene *s, const char *name, uint8_t tag) {
  for (uint32_t i = 0; i < s->catalog_count; i++)
    if (s->catalog[i].tag == tag && ieq(s->catalog[i].name, name))
      return s->catalog[i].ref;
  return (tmuf_pack_ref){-1, 0};
}

enum { CATALOG_BLOCK_INFO, CATALOG_DECORATION };

/* Collections live under Collections\ (.TMCollection or .TMElementColl);
   matched by the name stored in their body. */
static tmuf_asset *find_collection(tmuf_scene *s, const char *name) {
  const tmuf_packset *set = s->assets.set;
  char path[512];
  for (int p = 0; p < set->pack_count; p++)
    for (uint32_t f = 0; f < set->packs[p].file_count; f++) {
      if (!tmuf_pack_file_path(&set->packs[p], f, path, sizeof path) || strncmp(path, "Collections\\", 12) != 0)
        continue;
      tmuf_asset *a = tmuf_assets_load(&s->assets, (tmuf_pack_ref){p, f});
      if (a && a->class_id == 0x03033000u && a->root && ((tmuf_collection *)a->root)->name &&
          ieq(((tmuf_collection *)a->root)->name, name))
        return a;
    }
  return NULL;
}

/* The game's rand() (MSVC LCG) as used by GmFunc::RandNat. */
uint32_t scene_rand_nat(tmuf_scene *s, uint32_t lo, uint32_t hi) {
  s->rand_state = s->rand_state * 214013u + 2531011u;
  uint32_t r = (s->rand_state >> 16) & 0x7fffu;
  float unit = (float)r / 32768.0f;
  float scaled = unit * (float)(hi - lo + 1u);
  return (uint32_t)(scaled + (float)lo);
}

tmuf_asset *scene_block_info(tmuf_scene *s, const char *name) {
  tmuf_pack_ref r = find_collector(s, name, CATALOG_BLOCK_INFO);
  if (r.pack < 0)
    return NULL;
  tmuf_asset *a = tmuf_assets_load(&s->assets, r);
  return a && a->root ? a : NULL;
}

int scene_debug(void) { return debug_enabled(); }

/* GmMat3::SetRotateQuarterY(quarter) (rotate_quarter_y counts the other way) */
void tmuf_iso_rotate_quarter_y(tmuf_iso *iso, unsigned quarter) { rotate_quarter_y(iso, (4u - quarter) & 3u); }

/* ClipSideTransform */
static void clip_side(unsigned side, float sq, tmuf_iso *out) {
  static const unsigned QUARTER[4] = {0, 3, 2, 1};
  tmuf_iso_identity(out);
  tmuf_iso_rotate_quarter_y(out, QUARTER[side & 3]);
  out->t[0] = (side == 1 || side == 2) ? sq : 0.0f;
  out->t[1] = 0.0f;
  out->t[2] = (side == 2 || side == 3) ? sq : 0.0f;
}

/* ---- geometry water planes ---- */

/* CPlugMaterial::GetSupportedShader: the model's (else the material's) device
   set that is the last one not newer than the supported device (PC3, VHigh) */
static tmuf_gbx_node *material_shader(tmuf_scene *s, tmuf_asset *owner, tmuf_gbx_node *node, tmuf_asset **shader_owner,
                                      const tmuf_plug_material_custom **custom, tmuf_asset **custom_owner) {
  tmuf_asset *ma;
  tmuf_gbx_node *mn = tmuf_assets_follow(&s->assets, owner, node, &ma);
  if (!mn || !mn->data || !mn->cls || mn->cls->id != 0x09079000u)
    return NULL;
  const tmuf_plug_material *m = mn->data;
  if (m->custom) {
    tmuf_gbx_node *cn = tmuf_assets_follow(&s->assets, ma, m->custom, custom_owner);
    if (cn && cn->data && cn->cls && cn->cls->id == 0x0903a000u)
      *custom = cn->data;
  }
  const tmuf_plug_material *sets = m;
  tmuf_asset *sets_owner = ma;
  if (m->model) {
    tmuf_gbx_node *mm = tmuf_assets_follow(&s->assets, ma, m->model, &sets_owner);
    if (!mm || !mm->data || !mm->cls || mm->cls->id != 0x09079000u)
      return NULL;
    sets = mm->data;
  }
  if (!sets->device_count)
    return NULL;
  uint32_t sel = sets->device_count - 1u;
  while (sets->device_words[sel] > 0x00030004u && sel != 0)
    sel--;
  if (!sets->device_shaders[sel])
    return NULL;
  return tmuf_assets_follow(&s->assets, sets_owner, sets->device_shaders[sel], shader_owner);
}

static int id_equal(const char *a, const char *b) { return a && b && strcmp(a, b) == 0; }

/* The tree's shader is a water shader (CHmsCorpus::WaterGetPlaneEqInZone):
   flags & 0xc00000 == 0x800000 and a bitmap updated by a
   CPlugBitmapRenderWater (the material's custom bitmaps replace the
   shader's by sampler name) */
static int water_shader(tmuf_scene *s, tmuf_asset *owner, tmuf_gbx_node *node) {
  tmuf_asset *sa = NULL, *ca = NULL;
  const tmuf_plug_material_custom *custom = NULL;
  tmuf_gbx_node *sn = material_shader(s, owner, node, &sa, &custom, &ca);
  if (!sn || !sn->data || !sn->cls || sn->cls->id != 0x09002000u)
    return 0;
  const tmuf_plug_shader *sh = sn->data;
  if (!sh->has_flags || (sh->flags[1] & 0x00c00000u) != 0x00800000u)
    return 0;
  for (uint32_t i = 0; i < sh->address_count; i++) {
    tmuf_asset *aa;
    tmuf_gbx_node *an = tmuf_assets_follow(&s->assets, sa, sh->addresses[i], &aa);
    if (!an || !an->data || !an->cls || an->cls->id != 0x0907e000u)
      continue;
    const tmuf_plug_bitmap_address *ad = an->data;
    tmuf_gbx_node *bitmap = ad->bitmap;
    tmuf_asset *bowner = aa;
    for (uint32_t k = 0; custom && k < custom->bitmap_count; k++)
      if (id_equal(custom->bitmap_names[k], ad->sampler)) {
        bitmap = custom->bitmaps[k];
        bowner = ca;
        break;
      }
    tmuf_asset *ba;
    tmuf_gbx_node *bn = bitmap ? tmuf_assets_follow(&s->assets, bowner, bitmap, &ba) : NULL;
    if (!bn || !bn->data || !bn->cls || bn->cls->id != 0x09011000u)
      continue;
    const tmuf_plug_bitmap *b = bn->data;
    if (b->render && b->render->class_id == 0x09087000u)
      return 1;
  }
  return 0;
}

/* GmVec4::PlaneEqMult */
static void plane_mult(float p[4], const tmuf_iso *iso) {
  float x = p[0], y = p[1], z = p[2];
  float nx = (iso->m[0][1] * y + iso->m[0][0] * x) + iso->m[0][2] * z;
  float ny = (iso->m[1][0] * x + iso->m[1][1] * y) + iso->m[1][2] * z;
  float nz = (iso->m[2][0] * x + iso->m[2][1] * y) + iso->m[2][2] * z;
  p[0] = nx, p[1] = ny, p[2] = nz;
  p[3] = p[3] - ((nx * iso->t[0] + ny * iso->t[1]) + nz * iso->t[2]);
}

/* first tree (pre-order, root included) with a water shader and a visual:
   the plane y = its visual's bounding box center, in world space */
static int tree_water_plane(tmuf_scene *s, tmuf_asset *owner, tmuf_gbx_node *tree_node, const tmuf_iso *parent,
                            int depth, float plane[4]) {
  if (depth > 64)
    return 0;
  tmuf_asset *ta;
  tmuf_gbx_node *tn = tmuf_assets_follow(&s->assets, owner, tree_node, &ta);
  if (!tn || !tn->data || !tn->cls)
    return 0;
  uint32_t cls = tn->cls->id;
  if (cls != 0x0904f000u && cls != 0x09015000u && cls != 0x09062000u)
    return 0;
  const tmuf_plug_tree *t = tn->data;
  tmuf_iso world = *parent;
  if (t->has_iso) {
    tmuf_iso local;
    tmuf_iso_from_archive(&local, t->iso);
    tmuf_iso_mult(&world, &local, parent);
  }
  if (t->shader && t->visual && water_shader(s, ta, t->shader)) {
    tmuf_asset *va;
    tmuf_gbx_node *vn = tmuf_assets_follow(&s->assets, ta, t->visual, &va);
    if (vn && vn->data && vn->cls && vn->cls->id == 0x09006000u) {
      const tmuf_plug_visual *v = vn->data;
      plane[0] = 0.0f, plane[1] = 1.0f, plane[2] = 0.0f, plane[3] = -v->bbox[1];
      plane_mult(plane, &world);
      return 1;
    }
  }
  for (uint32_t i = 0; i < t->child_count; i++)
    if (tree_water_plane(s, ta, t->children[i], &world, depth + 1, plane))
      return 1;
  return 0;
}

/* GmVec4::PlaneEqIsNearlyEqual */
static int plane_near(const float a[4], const float b[4]) {
  float dot = (b[1] * a[1] + b[0] * a[0]) + b[2] * a[2];
  return dot >= 0.99000001f && fabsf(a[3] - b[3]) <= 0.1f;
}

/* Zone_UpdateWaterHeights over the scene's corpora, then each wet cell gets
   the index + 1 of its ground block's plane (only index 1 is water for the
   car: CSceneVehicleCar::ApplyWaterForces) */
static void finish_geometry_water(tmuf_scene *s) {
  uint32_t *tags = s->water_ground_tags;
  s->water_ground_tags = NULL;
  if (!tags || !s->water.cells) {
    free(tags);
    return;
  }
  float planes[255][4];
  uint32_t plane_count = 0;
  float *corpus_plane = malloc(sizeof(float) * 4 * (s->corpus_count ? s->corpus_count : 1));
  uint8_t *has_plane = calloc(s->corpus_count ? s->corpus_count : 1, 1);
  if (!corpus_plane || !has_plane) {
    free(corpus_plane), free(has_plane), free(tags);
    return;
  }
  for (uint32_t i = 0; i < s->corpus_count; i++) {
    const tmuf_scene_corpus *c = &s->corpora[i];
    float *p = corpus_plane + 4 * i;
    if (!tree_water_plane(s, c->owner, c->tree, &c->iso, 0, p))
      continue;
    has_plane[i] = 1;
    uint32_t k = 0;
    while (k < plane_count && !plane_near(planes[k], p))
      k++;
    if (k == plane_count && plane_count < 255) {
      memcpy(planes[plane_count], p, sizeof planes[0]);
      plane_count++;
    }
  }
  size_t n = (size_t)s->water.dims[0] * s->water.dims[1];
  for (size_t i = 0; i < n; i++) {
    if (tags[i] == UINT32_MAX)
      continue;
    /* the ground block's mobil: its first corpus */
    uint32_t ci = 0;
    while (ci < s->corpus_count && s->corpora[ci].tag != tags[i])
      ci++;
    if (ci == s->corpus_count || !has_plane[ci])
      continue;
    for (uint32_t k = 0; k < plane_count; k++)
      if (plane_near(planes[k], corpus_plane + 4 * ci)) {
        s->water.cells[i] = (uint8_t)(k + 1u);
        break;
      }
  }
  if (debug_enabled()) {
    fprintf(stderr, "geometry water: %u planes", plane_count);
    for (uint32_t k = 0; k < plane_count; k++)
      fprintf(stderr, " (%g %g %g %g)", (double)planes[k][0], (double)planes[k][1], (double)planes[k][2],
              (double)planes[k][3]);
    fputc('\n', stderr);
  }
  free(corpus_plane), free(has_plane), free(tags);
}

/* AppendBlockPlacementModels for one installation */
static void emit_install(tmuf_scene *s, const ctn_install *in) {
  if (debug_enabled())
    fprintf(stderr, "install tag %08x kind %d active %d suppressed %d main %p raise %u\n", in->tag, in->kind,
            in->active, in->suppressed, (void *)in->main.node, in->pylon_raise);
  if (!in->active || in->suppressed)
    return;
  s->current_block = in->tag;
  s->force_static = 1;
  /* ReplaySceneBlockPlacement::MaterialVariant; clips and helpers use the
     base materials unless remapped */
  s->current_materials = in->material == CTN_MATERIAL_REPLACEMENT ? TMUF_MATERIALS_REPLACEMENT
                         : in->material == CTN_MATERIAL_SKIN      ? TMUF_MATERIALS_SKIN
                                                                  : TMUF_MATERIALS_OWN;
  if (in->kind == CTN_INSTALL_PYLON)
    s->current_materials = TMUF_MATERIALS_OWN;
  /* CGameCtnBlock::SpawnLocation(0, 0) and the block's race role */
  s->current_race_role = TMUF_RACE_NONE;
  s->current_respawn_current = s->current_has_spawn = 0;
  if (in->kind == CTN_INSTALL_BLOCK && in->info) {
    static const uint8_t ROLE[5] = {TMUF_RACE_START, TMUF_RACE_FINISH, TMUF_RACE_CHECKPOINT, TMUF_RACE_NONE,
                                    TMUF_RACE_START_FINISH};
    if (in->info->has_way_type && in->info->way_type < 5)
      s->current_race_role = ROLE[in->info->way_type];
    s->current_respawn_current = (uint8_t)in->info->respawn_current;
    tmuf_iso local;
    tmuf_iso_identity(&local);
    if (in->info->has_spawn)
      tmuf_iso_from_archive(&local, in->info->spawn[in->ground ? 0 : 1]);
    tmuf_iso_mult(&s->current_spawn, &local, &in->iso);
    s->current_has_spawn = 1;
  }
  if (in->kind == CTN_INSTALL_CLIP) {
    /* CreateMobilForClip builds the side mobils in side order, takes the
       first as the block's mobil and removes it from the list with
       ReplaceByLastAt: the scene gets the first, the last, then the rest */
    unsigned present[4], n = 0;
    for (unsigned side = 0; side < 4; side++)
      if (in->clip[side].node)
        present[n++] = side;
    for (unsigned k = 0; k < n; k++) {
      unsigned side = k == 0 ? present[0] : k == 1 ? present[n - 1] : present[k - 1];
      tmuf_iso local, world;
      clip_side(side, s->square_size, &local);
      tmuf_iso_mult(&world, &local, &in->iso);
      emit_mobil(s, in->clip[side].asset, in->clip[side].node, &world, 0);
    }
  } else if (in->kind == CTN_INSTALL_PYLON) {
    s->pylon_raise = in->pylon_raise;
    emit_mobil(s, in->main.asset, in->main.node, &in->iso, 0);
    s->pylon_raise = 0;
  } else {
    if (in->main.node)
      emit_mobil(s, in->main.asset, in->main.node, &in->iso, 0);
    s->force_static = 0;
    s->helper_depth++;
    for (int k = 0; k < 2; k++)
      if (in->helper[k].node)
        emit_mobil(s, in->helper[k].asset, in->helper[k].node, &in->iso, 0);
    s->helper_depth--;
  }
  s->force_static = 0;
  s->current_materials = TMUF_MATERIALS_OWN;
  s->blocks_placed++;
}

static int ieq_prefix(const char *s, const char *prefix) {
  for (; *prefix; s++, prefix++)
    if (tolower((unsigned char)*s) != tolower((unsigned char)*prefix))
      return 0;
  return 1;
}

int tmuf_scene_remap_material(const tmuf_scene *s, uint8_t materials, const char *path, uint8_t *id) {
  if (materials == TMUF_MATERIALS_OWN || !path || !path[0])
    return 0;
  for (uint32_t i = 0; i < s->material_remap_count; i++) {
    const tmuf_material_remap *r = &s->material_remaps[i];
    size_t n = strlen(r->source);
    int hit = ieq(path, r->source) ||
              (r->folder && ieq_prefix(path, r->source) && (r->source[n - 1] == '\\' || path[n] == '\\'));
    if (!hit)
      continue;
    /* StaticSolidMaterialRemaps: the replacement's material, or the
       default (concrete) material for a decoration skin */
    *id = materials == TMUF_MATERIALS_REPLACEMENT ? r->replacement_id : 0;
    return 1;
  }
  return 0;
}

static void dir_of(char *out, size_t size, const char *path) {
  snprintf(out, size, "%s", path);
  char *slash = strrchr(out, '\\');
  if (slash)
    slash[1] = 0;
  else
    out[0] = 0;
}

/* SkinMaterialRemapCatalog::Load: the CPlugGameSkin material rules of the
   collection's terrain modifiers, in order. */
static void load_material_remaps(tmuf_scene *s, tmuf_asset *ca, const tmuf_collection *coll) {
  const tmuf_packset *set = s->assets.set;
  for (uint32_t i = 0; i < coll->terrain_modifier_count; i++) {
    char mpath[600], kpath[600], dir[600];
    tmuf_pack_ref mr = tmuf_packset_resolve(set, &ca->gbx, coll->terrain_modifiers[i], ca->path, mpath, sizeof mpath);
    tmuf_asset *ma = mr.pack >= 0 ? tmuf_assets_load(&s->assets, mr) : NULL;
    if (debug_enabled())
      fprintf(stderr, "terrain modifier %u: %s -> %s class %08x\n", i, mr.pack >= 0 ? mpath : "(unresolved)",
              ma ? ma->path : "-", ma ? ma->class_id : 0);
    if (!ma || !ma->root || ma->class_id != 0x0303c000u)
      continue;
    const tmuf_terrain_modifier *tm = ma->root;
    tmuf_pack_ref kr = tmuf_packset_resolve(set, &ma->gbx, tm->skin, mpath, kpath, sizeof kpath);
    tmuf_asset *ka = kr.pack >= 0 ? tmuf_assets_load(&s->assets, kr) : NULL;
    if (!ka || !ka->root || ka->class_id != 0x03031000u || !tm->folder || !tm->folder[0])
      continue;
    const tmuf_game_skin *skin = ka->root;
    if (debug_enabled())
      fprintf(stderr, "  skin %s folder %s rules %u\n", kpath, tm->folder, skin->rule_count);
    dir_of(dir, sizeof dir, kpath);
    for (uint32_t k = 0; k < skin->rule_count; k++) {
      const tmuf_skin_rule *rule = &skin->rules[k];
      if (!rule->has_target || rule->class_id != 0x09079000u || !rule->prefix || !rule->prefix[0])
        continue;
      char target[600], repl[600];
      tmuf_pack_ref tr = tmuf_packset_resolve(set, &ka->gbx, rule->target, kpath, target, sizeof target);
      int folder = tr.pack < 0;
      if (folder && !tmuf_gbx_external_path(&ka->gbx, rule->target, dir, target, sizeof target))
        continue;
      size_t fl = strlen(tm->folder);
      snprintf(repl, sizeof repl, "%s%s%s%s", tm->folder, tm->folder[fl - 1] == '\\' ? "" : "\\", rule->prefix,
               strstr(rule->prefix, ".Material.Gbx") ? "" : ".Material.Gbx");
      /* only rules whose replacement material loads are installed */
      tmuf_asset *ra = tmuf_assets_load_path(&s->assets, repl);
      if (!ra || !ra->root || ra->class_id != 0x09079000u || !((tmuf_plug_material *)ra->root)->has_surface)
        continue;
      if (debug_enabled())
        fprintf(stderr, "material remap %s%s -> %s (%u)\n", target, folder ? " (folder)" : "", repl,
                ((tmuf_plug_material *)ra->root)->surface_id);
      if (s->material_remap_count == TMUF_SCENE_MAX_MATERIAL_REMAPS)
        return;
      tmuf_material_remap *r = &s->material_remaps[s->material_remap_count++];
      snprintf(r->source, sizeof r->source, "%s", target);
      r->folder = folder;
      r->replacement_id = ((tmuf_plug_material *)ra->root)->surface_id;
    }
  }
}


/* CPlugDecoratorTreeArchivePayload::IsConditionEnabled */
static int decorator_condition(uint32_t condition, uint32_t quality) {
  switch (condition) {
  case 1: return quality == 0;
  case 2: return quality <= 1;
  case 3: return quality == 1;
  case 4: return quality == 1 || quality == 2;
  case 5: return quality == 2;
  case 6: return 1;
  default: return 0;
  }
}

/* CPlugTree::GetPlugFromId: the tree itself, then its children in order */
static tmuf_plug_tree *find_tree(tmuf_scene *s, tmuf_asset *owner, tmuf_gbx_node *tree_node, const char *id,
                                 int root, int depth) {
  tmuf_asset *ta;
  tmuf_gbx_node *tn = tmuf_assets_follow(&s->assets, owner, tree_node, &ta);
  if (!tn || !tn->data || !tn->cls || depth > 64)
    return NULL;
  uint32_t cls = tn->cls->id;
  if (cls != 0x0904f000u && cls != 0x09015000u && cls != 0x09062000u)
    return NULL;
  tmuf_plug_tree *t = tn->data;
  if ((id && id[0] && t->name && strcmp(t->name, id) == 0) || ((!id || !id[0]) && root))
    return t;
  for (uint32_t i = 0; i < t->child_count; i++) {
    tmuf_plug_tree *f = find_tree(s, ta, t->children[i], id, 0, depth + 1);
    if (f)
      return f;
  }
  return NULL;
}

/* The decoration's CPlugDecoratorSolid (.DecoSolid.Gbx) sets which trees of
   its Warp mobil collide (StaticSolidDecoratorAssembler, highest quality).
   The decoration's chunk naming it is crypted; its reference table is not. */
static void apply_decorator(tmuf_scene *s, tmuf_asset *da, tmuf_asset *owner, tmuf_gbx_node *mobil_node) {
  const tmuf_decorator_solid *dec = NULL;
  tmuf_asset *deca = NULL;
  for (uint32_t i = 1; i <= da->gbx.node_count && !dec; i++) {
    const tmuf_gbx_node *n = &da->gbx.nodes[i];
    size_t len = n->external && n->file ? strlen(n->file) : 0;
    if (len < 14 || !ieq(n->file + len - 14, ".DecoSolid.Gbx"))
      continue;
    tmuf_gbx_node *dn = tmuf_assets_follow(&s->assets, da, &da->gbx.nodes[i], &deca);
    if (dn && dn->data && dn->class_id == 0x090a3000u)
      dec = dn->data;
  }
  if (!dec)
    return;
  /* the mobil's solid tree */
  tmuf_asset *ma, *sa;
  tmuf_gbx_node *mn = tmuf_assets_follow(&s->assets, owner, mobil_node, &ma);
  if (!mn || !mn->data || !mn->cls || mn->cls->id != 0x0a005000u)
    return;
  const tmuf_scene_object *m = mn->data;
  if (!m->name || strcmp(m->name, "Warp") != 0 || !m->has_item || !m->item.solid)
    return;
  tmuf_gbx_node *soln = tmuf_assets_follow(&s->assets, ma, m->item.solid, &sa);
  for (int k = 0; k < 8 && soln && soln->data && soln->class_id == 0x09005000u &&
                  ((const tmuf_plug_solid *)soln->data)->use_model;
       k++)
    soln = tmuf_assets_follow(&s->assets, sa, ((const tmuf_plug_solid *)soln->data)->model, &sa);
  if (!soln || !soln->data || soln->class_id != 0x09005000u)
    return;
  tmuf_gbx_node *root = ((const tmuf_plug_solid *)soln->data)->tree;
  for (uint32_t i = 0; i < dec->trees.count; i++) {
    tmuf_asset *xa;
    tmuf_gbx_node *xn = tmuf_assets_follow(&s->assets, deca, dec->trees.nodes[i], &xa);
    if (!xn || !xn->data || xn->class_id != 0x090a2000u)
      continue;
    const tmuf_decorator_tree *d = xn->data;
    tmuf_plug_tree *t = find_tree(s, sa, root, d->tree_id, 1, 0);
    if (!t)
      continue;
    int collide = decorator_condition(d->show, 2) && decorator_condition(d->collision, 2);
    t->flags = collide ? (t->flags | 0x80u) : (t->flags & ~0x80u);
    if (debug_enabled())
      fprintf(stderr, "decorator: tree %s collision %d\n", d->tree_id ? d->tree_id : "(root)", collide);
  }
}

int tmuf_scene_build(tmuf_scene *s, const tmuf_packset *set, const tmuf_challenge *map, unsigned flags) {
  memset(s, 0, sizeof *s);
  s->collect_triangles = (flags & TMUF_SCENE_TRIANGLES) != 0;
  s->rand_state = 1;
  tmuf_assets_init(&s->assets, set);
  /* the map's own collection holds its blocks and zones; the decoration
     may come from another one (e.g. a Stadium map on a Bay decoration) */
  tmuf_asset *ca = map->map[1] && map->map[1][0] ? find_collection(s, map->map[1]) : NULL;
  if (!ca)
    ca = find_collection(s, map->decoration[1]);
  tmuf_asset *dca = find_collection(s, map->decoration[1]);
  if (!dca)
    dca = ca;
  if (!ca) {
    snprintf(s->error, sizeof s->error, "no collection %s", map->decoration[1]);
    return 0;
  }
  const tmuf_collection *coll = ca->root;
  s->collection = coll->name;
  s->default_vehicle = coll->vehicle[0];
  s->square_size = coll->square_size;
  s->square_height = coll->square_height;
  load_material_remaps(s, ca, coll);
  build_catalog(s, coll->folders[0], NULL, CATALOG_BLOCK_INFO);
  build_catalog(s, ((const tmuf_collection *)dca->root)->folders[2], ".TMDecoration.", CATALOG_DECORATION);
  tmuf_asset *da = tmuf_assets_load(&s->assets, find_collector(s, map->decoration[0], CATALOG_DECORATION));
  if (!da || da->class_id != 0x03038000u) {
    snprintf(s->error, sizeof s->error, "no decoration %s", map->decoration[0]);
    return 0;
  }
  tmuf_asset *dsa;
  tmuf_gbx_node *dsn = tmuf_assets_follow(&s->assets, da, ((tmuf_decoration *)da->root)->refs[0], &dsa);
  if (!dsn || !dsn->data || dsn->class_id != 0x0303b000u) {
    snprintf(s->error, sizeof s->error, "no decoration size for %s", map->decoration[0]);
    return 0;
  }
  const tmuf_decoration_size *dsize = dsn->data;
  s->size[0] = dsize->size[0];
  s->size[1] = dsize->size[1];
  s->size[2] = dsize->size[2];
  s->base_height = dsize->base_height;
  if (debug_enabled())
    fprintf(stderr, "water: heights %d surface %g secondary %g cull %g default %d geometry %d/%d; size %u %u %u base %u sq %g %g\n",
            coll->has_water_heights, (double)coll->water_surface, (double)coll->water_secondary,
            (double)coll->water_render_cull, coll->default_water, coll->has_geometry_water, coll->geometry_water_planes,
            s->size[0], s->size[1], s->size[2], s->base_height, (double)s->square_size, (double)s->square_height);
  if (debug_enabled())
    fprintf(stderr, "collection %s folders %s | %s | %s | %s; decoration %s %s %s\n", coll->name, coll->folders[0],
            coll->folders[1], coll->folders[2], coll->folders[3], map->decoration[0], map->decoration[1],
            map->decoration[2]);

  /* decoration scene (added to the zone before the map) */
  tmuf_asset *sa;
  tmuf_gbx_node *sn = tmuf_assets_follow(&s->assets, dsa, dsize->scene, &sa);
  if (sn && sn->data && sn->class_id == 0x0a003000u) {
    const tmuf_scene3d *sc = sn->data;
    for (uint32_t i = 0; i < sc->mobil_count && i < sc->loc_count; i++) {
      if (!sc->mobils[i] || !sc->mobils[i]->model)
        continue;
      apply_decorator(s, da, sa, sc->mobils[i]->model);
      tmuf_iso loc;
      tmuf_iso_from_archive(&loc, sc->locs[i].iso);
      s->current_block = 0xc0000000u | i;
      emit_mobil(s, sa, sc->mobils[i]->model, &loc, 0);
    }
  } else if (debug_enabled()) {
    fprintf(stderr, "no decoration scene\n");
  }

  /* the map's blocks, clips and pylons, in the game's add order */
  ctn_result cr;
  if (!ctn_build(s, map, ca, &cr)) {
    snprintf(s->error, sizeof s->error, "challenge construction failed");
    return 0;
  }
  s->blocks_missing = cr.blocks_missing;
  /* ReplaySceneBlockPlacements::FirstSurvivingStartLineSpawn:
     CGameCtnBlock::SpawnLocation of the first start block */
  /* without a start block the car spawns at the origin */
  tmuf_iso_identity(&s->start);
  for (uint32_t i = 0; i < cr.count && !s->has_start; i++) {
    const ctn_install *in = &cr.items[i];
    if (in->kind != CTN_INSTALL_BLOCK || !in->start_line)
      continue;
    tmuf_iso local;
    tmuf_iso_identity(&local);
    if (in->info->has_spawn)
      tmuf_iso_from_archive(&local, in->info->spawn[in->ground ? 0 : 1]);
    tmuf_iso_mult(&s->start, &local, &in->iso);
    s->has_start = 1;
  }
  for (uint32_t i = 0; i < cr.count; i++)
    emit_install(s, &cr.items[i]);
  ctn_result_free(&cr);
  finish_geometry_water(s);
  return 1;
}

/* Binary32::TruncateToUint32Modulo */
static uint32_t trunc_u32_mod(float v) {
  if (!isfinite(v) || fabs((double)v) >= 18446744073709551616.0)
    return 0u;
  double t = trunc((double)v);
  uint32_t mag = (uint32_t)fmod(fabs(t), 4294967296.0);
  return signbit(v) ? 0u - mag : mag;
}

int tmuf_water_accepts(const tmuf_scene_water *w, float x, float z, float lower, float upper) {
  if (!w->enabled)
    return 0;
  /* GmMap2::CellAt */
  uint32_t cx = trunc_u32_mod((x - w->origin[0]) / w->cell_size[0]);
  uint32_t cz = trunc_u32_mod((z - w->origin[1]) / w->cell_size[1]);
  int inside = cx < w->dims[0] && cz < w->dims[1];
  if (!inside && w->outside == 1 && w->surface_height > lower)
    return 1;
  if (!(upper > w->secondary_cull_height) || !(w->surface_height > lower))
    return 0;
  uint8_t v = inside ? w->cells[cx + w->dims[0] * cz] : w->outside;
  return v == 1;
}

void tmuf_scene_free(tmuf_scene *s) {
  free(s->water_ground_tags);
  free(s->water.cells);
  free(s->triangles);
  free(s->catalog);
  free(s->corpora);
  tmuf_assets_free(&s->assets);
  memset(s, 0, sizeof *s);
}
