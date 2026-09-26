#include "reference/sim.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common/replay.h"
#include "reference/car_util.h"

#define TREE_COLLISION 0x80u

/* ---- car collision trees ---- */

typedef struct tree_build {
  ref_sim *s;
  tmuf_assets *assets;
  const tmuf_vehicle *v;
  uint32_t trees, children;
  int count_only;
} tree_build;

static const tmuf_plug_tree *plug_tree(tmuf_assets *a, tmuf_asset *owner, tmuf_gbx_node *n, tmuf_asset **out) {
  tmuf_gbx_node *tn = tmuf_assets_follow(a, owner, n, out);
  if (!tn || !tn->data || !tn->cls)
    return NULL;
  uint32_t cls = tn->cls->id;
  if (cls != 0x0904f000u && cls != 0x09015000u && cls != 0x09062000u)
    return NULL;
  return tn->data;
}

static int str_ieq(const char *a, const char *b) {
  if (!a || !b)
    return 0;
  for (; *a && *b; a++, b++) {
    char x = *a >= 'A' && *a <= 'Z' ? (char)(*a + 32) : *a;
    char y = *b >= 'A' && *b <= 'Z' ? (char)(*b + 32) : *b;
    if (x != y)
      return 0;
  }
  return *a == *b;
}

static ref_mtree *build_tree(tree_build *b, tmuf_asset *owner, tmuf_gbx_node *node, const gm_iso4 *parent_root,
                             int depth) {
  tmuf_asset *ta;
  const tmuf_plug_tree *t = plug_tree(b->assets, owner, node, &ta);
  if (!t || !(t->flags & TREE_COLLISION) || depth > 32)
    return NULL;
  gm_iso4 local;
  iso4_identity(&local);
  if (t->has_iso) {
    for (int r = 0; r < 3; r++)
      for (int c = 0; c < 3; c++)
        local.r.m[r][c] = t->iso[r * 3 + c];
    local.t = v3(t->iso[9], t->iso[10], t->iso[11]);
  }
  gm_iso4 root = (t->flags & 4u) ? iso4_mult(&local, parent_root) : *parent_root;
  ref_mtree *m = NULL;
  uint32_t first_child = b->children;
  if (!b->count_only) {
    m = &b->s->trees[b->trees];
    memset(m, 0, sizeof *m);
    m->flags = t->flags;
    m->local = local;
    m->children = b->s->child_ptrs + first_child;
    if (t->surface)
      m->surf = ref_world_surface(&b->s->world, b->assets, ta, t->surface);
    for (uint32_t w = 0; w < b->v->wheel_count; w++)
      if (str_ieq(t->name, b->v->wheels[w].surface)) {
        b->s->def.wheels[w].tree = m;
        b->s->def.wheels[w].force_point = root.t;
      }
  }
  b->trees++;
  uint32_t n = 0;
  for (uint32_t i = 0; i < t->child_count; i++) {
    tmuf_asset *ca;
    const tmuf_plug_tree *ct = plug_tree(b->assets, ta, t->children[i], &ca);
    if (ct && (ct->flags & TREE_COLLISION))
      n++;
  }
  b->children += n;
  uint32_t k = 0;
  for (uint32_t i = 0; i < t->child_count; i++) {
    ref_mtree *c = build_tree(b, ta, t->children[i], &root, depth + 1);
    if (c && m)
      m->children[k++] = c;
  }
  if (m)
    m->child_count = k;
  return m;
}

static int build_car_trees(ref_sim *s, tmuf_assets *assets, const tmuf_vehicle *v) {
  gm_iso4 id;
  iso4_identity(&id);
  tree_build b = {s, assets, v, 0, 0, 1};
  build_tree(&b, v->solid_owner, v->solid_tree, &id, 0);
  s->tree_count = b.trees;
  s->trees = calloc(b.trees ? b.trees : 1, sizeof *s->trees);
  s->child_ptrs = calloc(b.children ? b.children : 1, sizeof *s->child_ptrs);
  if (!s->trees || !s->child_ptrs)
    return 0;
  tree_build f = {s, assets, v, 0, 0, 0};
  s->def.root = build_tree(&f, v->solid_owner, v->solid_tree, &id, 0);
  return s->def.root != NULL;
}

/* ---- init ---- */

static void iso_from_scene(gm_iso4 *iso, const tmuf_iso *t) {
  for (int r = 0; r < 3; r++)
    for (int c = 0; c < 3; c++)
      iso->r.m[r][c] = t->m[r][c];
  iso->t = v3(t->t[0], t->t[1], t->t[2]);
}

/* BuildReplayValidationSpawnLocation */
static gm_iso4 validation_spawn(const gm_iso4 *loc, uint32_t seed) {
  if (seed == 0)
    return *loc;
  double normalized = (double)(seed % 100000u) / 100000.0;
  float yaw_deg = (float)((normalized - 0.5) * 0.1000000014901161);
  float yaw = (float)((double)(yaw_deg * 3.1415927410125732f) / 180.0);
  /* GmMat3::RotateY on identity, then LeftMult */
  float cs = tmuf_cosf(yaw), sn = tmuf_sinf(yaw);
  gm_mat3 r;
  mat3_identity(&r);
  r.m[0][0] = cs;
  r.m[0][2] = sn;
  r.m[2][0] = -sn;
  r.m[2][2] = cs;
  gm_iso4 out = *loc;
  out.r = mat3_compose(&r, &loc->r); /* LeftMult: the seed rotation first */
  return out;
}

int ref_sim_init(ref_sim *s, tmuf_scene *scene, const tmuf_vehicle *v, const gm_iso4 *spawn, uint32_t seed,
                 const ref_tick *first, char *err, size_t err_size) {
  memset(s, 0, sizeof *s);
  if (!ref_world_build(&s->world, scene)) {
    snprintf(err, err_size, "static world");
    return 0;
  }
  s->corpus_count = scene->corpus_count;
  s->corpus_iso = calloc(s->corpus_count ? s->corpus_count : 1, sizeof *s->corpus_iso);
  if (!s->corpus_iso)
    return 0;
  for (uint32_t i = 0; i < s->corpus_count; i++)
    iso_from_scene(&s->corpus_iso[i], &scene->corpora[i].iso);

  car_def *d = &s->def;
  d->tuning = v->tuning;
  d->wheel_count = v->wheel_count;
  for (uint32_t i = 0; i < v->wheel_count; i++) {
    d->wheels[i].kills_lateral_speed = v->wheels[i].kills_lateral_speed;
    d->wheels[i].front = v->wheels[i].front;
  }
  if (!build_car_trees(s, &scene->assets, v)) {
    snprintf(err, err_size, "vehicle collision tree");
    return 0;
  }
  for (uint32_t i = 0; i < v->wheel_count; i++) {
    ref_mtree *t = d->wheels[i].tree;
    if (!t) {
      snprintf(err, err_size, "wheel %s has no collision tree", v->wheels[i].surface ? v->wheels[i].surface : "?");
      return 0;
    }
    /* ApplySingleMaterialRefFromTuning */
    if (t->surf && t->surf->material_count == 1u && d->tuning.contact_response.single_material < MAT_COUNT)
      ((uint8_t *)t->surf->material_ids)[0] = (uint8_t)d->tuning.contact_response.single_material;
  }
  ref_mtree_update_box(d->root);
  if (getenv("TMUF_SIM_DEBUG")) {
    for (uint32_t i = 0; i < s->tree_count; i++) {
      const ref_mtree *t = &s->trees[i];
      fprintf(stderr, "tree %u %p flags %x children %u surf type %d t=(%g %g %g) box c=(%g %g %g) h=(%g %g %g)\n", i,
              (const void *)t, t->flags, t->child_count, t->surf ? (int)t->surf->type : -1, (double)t->local.t.x,
              (double)t->local.t.y, (double)t->local.t.z, (double)t->box.center.x, (double)t->box.center.y,
              (double)t->box.center.z, (double)t->box.half.x, (double)t->box.half.y, (double)t->box.half.z);
    }
    for (uint32_t i = 0; i < v->wheel_count; i++)
      fprintf(stderr, "wheel %u %s front %d kill %d tree %p\n", i, v->wheels[i].surface, v->wheels[i].front,
              v->wheels[i].kills_lateral_speed, (void *)d->wheels[i].tree);
    fprintf(stderr, "fake texture %ux%u bpp %u\n", v->fake_width, v->fake_height, v->fake_bpp);
    for (uint32_t i = 0; i < v->material_count; i++)
      fprintf(stderr, "material %u id %u blend %g %g %g %g fake %d period %g %g scale %g depth %g\n", i,
              v->materials[i].natural_id, (double)v->materials[i].blend[0], (double)v->materials[i].blend[1],
              (double)v->materials[i].blend[2], (double)v->materials[i].blend[3], v->materials[i].fake_bitmap != NULL,
              (double)v->materials[i].fake_period_x, (double)v->materials[i].fake_period_z,
              (double)v->materials[i].fake_speed_scale, (double)v->materials[i].fake_depth_max);
  }
  d->linear_speed_cap = v->has_params ? v->speed_cap : 277.77777f;
  d->reverse_gear_speed_threshold = v->has_params ? v->reverse_speed_threshold : 10.0f;
  d->water_box.center = v3(v->water_box[0], v->water_box[1], v->water_box[2]);
  d->water_box.half = v3(v->water_box[3], v->water_box[4], v->water_box[5]);
  d->fake_texture.width = v->fake_width;
  d->fake_texture.height = v->fake_height;
  d->fake_texture.bpp = v->fake_bpp;
  d->fake_texture.stride = v->fake_width * v->fake_bpp;
  d->fake_texture.pixels = v->fake_pixels;
  d->material_count = v->material_count;
  for (uint32_t i = 0; i < v->material_count; i++) {
    const tmuf_vehicle_material *m = &v->materials[i];
    car_material *cm = &d->materials[i];
    cm->x = m->blend[0];
    cm->y = m->blend[1];
    cm->z = m->blend[2];
    cm->w = m->blend[3];
    cm->fake_contact = m->fake_bitmap != NULL;
    cm->fake_period_x = m->fake_period_x;
    cm->fake_period_z = m->fake_period_z;
    cm->fake_speed_scale = m->fake_speed_scale;
    cm->fake_depth_max = m->fake_depth_max;
    cm->feedback_speed_divisor = m->feedback_speed_divisor;
    cm->feedback_scale = m->feedback_scale;
    cm->natural_id = m->natural_id;
    if (m->natural_id < MAT_COUNT)
      d->material_remap[m->natural_id] = i;
  }

  /* ReplayVehicleBody::InitializeAtSpawn */
  s->body.type = DYNA_FULL;
  s->body.active = 1;
  s->body.has_max_ang = 1;
  s->body.max_ang = 100.0f;
  s->gravity_y = -10.0f;
  s->linear_damping = 1.0f;
  s->angular_damping = 1.0f;

  car *c = &s->car;
  car_init(c, d, &s->body);
  c->linear_speed_cap = d->linear_speed_cap;
  c->reverse_gear_speed_threshold = d->reverse_gear_speed_threshold;
  /* BuildVehicleDynaDefinition, then OnEnterScene (UpdateParamsFromTuning) */
  car_update_params(c);
  float amax = d->tuning.contact_response.point_impulse_angular_speed_max;
  s->body.has_max_ang = amax > SCALAR_EPS;
  s->body.max_ang = amax;
  dyna_set_location(&s->body, spawn);
  car_set_controls(c, first->gate_a, first->gate_b, first->steering);
  if (first->establish_spawn) {
    gm_iso4 cur = {s->body.state.rot, s->body.state.pos};
    car_establish_spawn(c, &cur);
  }
  if (first->enable_race)
    car_begin_race(c);
  gm_iso4 seeded = validation_spawn(spawn, seed);
  dyna_set_location(&s->body, &seeded);
  s->det.world = &s->world;
  s->det.out = &s->buf;
  s->det.group_pair = 0;
  s->first_step = 1;
  return 1;
}

void ref_sim_free(ref_sim *s) {
  ref_cbuf_free(&s->buf);
  for (uint32_t i = 0; i < s->tree_count; i++)
    ref_cbuf_free(&s->trees[i].sphere);
  free(s->trees);
  free(s->child_ptrs);
  free(s->corpus_iso);
  ref_world_free(&s->world);
  memset(s, 0, sizeof *s);
}

/* ---- zone ---- */

/* CHmsZoneDynamic::ComputeCorpusForces */
static void corpus_forces(ref_sim *s, float dt) {
  dyna *d = &s->body;
  d->write = d->state; /* ValidateDynamicState */
  const dyna_params *p = &d->params;
  gm_vec3 f = v3(0.0f, 0.0f, 0.0f);
  {
    float k = p->force_scale * p->mass;
    gm_vec3 g = v3(0.0f * k, s->gravity_y * k, k * 0.0f);
    f = v3(g.x + f.x, g.y + f.y, g.z + f.z);
  }
  {
    float k = -s->linear_damping * p->linear_damping_scale;
    gm_vec3 l = d->state.lin;
    l = v3(l.x * k, l.y * k, k * l.z);
    f = v3(l.x + f.x, l.y + f.y, l.z + f.z);
  }
  d->state.force = f;
  {
    gm_vec3 a = d->state.ang;
    float k = -s->angular_damping * p->angular_damping_scale;
    d->state.torque = v3(a.x * k, a.y * k, k * a.z);
  }
  s->car.tick = s->tick_ms;
  car_compute_forces(&s->car, dt);
}

/* ---- collision response ---- */

static int compare_collisions(const ref_collision *a, const ref_collision *b) {
  const float av[9] = {a->point.x, a->point.y, a->point.z, a->normal.x, a->normal.y,
                       a->normal.z, a->separation.x, a->separation.y, a->separation.z};
  const float bv[9] = {b->point.x, b->point.y, b->point.z, b->normal.x, b->normal.y,
                       b->normal.z, b->separation.x, b->separation.y, b->separation.z};
  for (int i = 0; i < 9; i++) {
    if (!(bv[i] <= av[i]))
      return 1;
    if (bv[i] < av[i])
      return -1;
  }
  if (!a->sphere_merge_primary && b->sphere_merge_primary)
    return -1;
  return 1;
}

static void swap_c(ref_collision *v, size_t a, size_t b) {
  if (a != b) {
    ref_collision t = v[a];
    v[a] = v[b];
    v[b] = t;
  }
}

/* CHmsCollisionBuffer::SortForCollisionResponse (MSVC qsort) */
static void sort_collisions(ref_collision *v, size_t n) {
  if (n < 2)
    return;
  size_t lo_stack[30], hi_stack[30], depth = 0, lo = 0, hi = n - 1;
  for (;;) {
    size_t count = hi - lo + 1;
    if (count <= 8) {
      size_t h = hi;
      while (h > lo) {
        size_t sel = lo;
        for (size_t c = lo + 1; c <= h; c++)
          if (compare_collisions(&v[c], &v[sel]) > 0)
            sel = c;
        swap_c(v, sel, h);
        h--;
      }
    } else {
      size_t mid = lo + count / 2;
      if (compare_collisions(&v[lo], &v[mid]) > 0)
        swap_c(v, lo, mid);
      if (compare_collisions(&v[lo], &v[hi]) > 0)
        swap_c(v, lo, hi);
      if (compare_collisions(&v[mid], &v[hi]) > 0)
        swap_c(v, mid, hi);
      size_t lc = lo, hc = hi;
      for (;;) {
        if (mid > lc) {
          do
            lc++;
          while (lc < mid && compare_collisions(&v[lc], &v[mid]) <= 0);
        }
        if (mid <= lc) {
          do
            lc++;
          while (lc <= hi && compare_collisions(&v[lc], &v[mid]) <= 0);
        }
        do
          hc--;
        while (hc > mid && compare_collisions(&v[hc], &v[mid]) > 0);
        if (hc < lc)
          break;
        swap_c(v, lc, hc);
        if (mid == hc)
          mid = lc;
        else if (mid == lc)
          mid = hc;
      }
      hc++;
      if (mid < hc) {
        do
          hc--;
        while (hc > mid && compare_collisions(&v[hc], &v[mid]) == 0);
      }
      if (mid >= hc) {
        do
          hc--;
        while (hc > lo && compare_collisions(&v[hc], &v[mid]) == 0);
      }
      size_t left = hc - lo, right = hi - lc;
      if (left >= right) {
        if (lo < hc) {
          lo_stack[depth] = lo;
          hi_stack[depth] = hc;
          depth++;
        }
        if (lc < hi) {
          lo = lc;
          continue;
        }
      } else {
        if (lc < hi) {
          lo_stack[depth] = lc;
          hi_stack[depth] = hi;
          depth++;
        }
        if (lo < hc) {
          hi = hc;
          continue;
        }
      }
    }
    if (depth == 0)
      return;
    depth--;
    lo = lo_stack[depth];
    hi = hi_stack[depth];
  }
}

static void material_data(uint8_t m, float *friction, float *restitution) {
  switch (m) {
  case MAT_ICE:
  case MAT_RUBBER:
  case MAT_TEST:
    *friction = 0.0f, *restitution = 0.0f;
    return;
  case MAT_SLIDING_RUBBER:
    *friction = 0.0f, *restitution = -0.5f;
    return;
  case MAT_GOLF_BALL:
    *friction = 1.0f, *restitution = 0.95f;
    return;
  case MAT_GOLF_WALL:
  case MAT_GOLF_GROUND:
    *friction = 1.0f, *restitution = 0.8f;
    return;
  default:
    *friction = 1.0f, *restitution = 0.5f;
  }
}

static float restitution_with(float self, float other) {
  if (self > 0.0f)
    return other > 0.0f ? other * self : other;
  if (other > 0.0f)
    return self;
  return other + self;
}

static gm_vec3 clamp_tangent(gm_vec3 s, gm_vec3 n, float fp) {
  float ns = (n.z * s.z + n.x * s.x) + n.y * s.y;
  gm_vec3 nc = v3(n.x * ns, n.y * ns, ns * n.z);
  gm_vec3 t = v3(s.x - nc.x, s.y - nc.y, s.z - nc.z);
  float nl = tmuf_sqrtf(len2_yxz(nc));
  float tl = tmuf_sqrtf(len2_yxz(t));
  float limit = nl * fp;
  if (tl > limit) {
    float k = limit / tl;
    t.x = k * t.x;
    t.y = t.y * k;
    t.z = k * t.z;
  }
  return v3(t.x + nc.x, t.y + nc.y, t.z + nc.z);
}

static void apply_impulse_side_a(dyna *d, const ref_collision *col, gm_vec3 speed, float restitution, float fp) {
  gm_vec3 adj = clamp_tangent(speed, col->normal, fp);
  gm_vec3 neg = v3(-adj.x, -adj.y, -adj.z);
  float sp = tmuf_sqrtf(len2_yxz(neg));
  if (!(sp > 1.0e-5f))
    return;
  float inv = 1.0f / sp;
  gm_vec3 dir = v3(inv * neg.x, neg.y * inv, inv * neg.z);
  /* AngularEffectiveMassTermForSolveImpulse (side A: YXZ dot) */
  gm_iso4 iso = {d->state.rot, d->state.pos};
  gm_vec3 center = iso4_mul_point(&iso, d->params.com);
  gm_vec3 lever = v3_sub(col->point, center);
  gm_vec3 ang = mat3_mul_vec(&d->state.inv_inertia_world, v3_cross(lever, dir));
  gm_vec3 at = v3_cross(ang, lever);
  float denom = dot_yxz(at, dir) + 1.0f / d->params.mass;
  float rs = sp * (restitution + 1.0f);
  float mag = rs / denom;
  dyna_add_impulse_at(d, v3(dir.x * mag, dir.y * mag, mag * dir.z), col->point);
}

static gm_vec3 local_to_world_side_a(const gm_mat3 *r, gm_vec3 v) {
  return v3((r->m[0][1] * v.y + r->m[0][0] * v.x) + r->m[0][2] * v.z,
            (r->m[1][1] * v.y + r->m[1][0] * v.x) + r->m[1][2] * v.z,
            (r->m[2][1] * v.y + r->m[2][0] * v.x) + r->m[2][2] * v.z);
}

static void collision_response(ref_sim *s) {
  sort_collisions(s->buf.items, s->buf.count);
  if (getenv("TMUF_SIM_DEBUG"))
    for (uint32_t i = 0; i < s->buf.count; i++) {
      const ref_collision *c = &s->buf.items[i];
      fprintf(stderr, "  t=%u col %u tree %p corpus %d mat %u/%u p %.9g %.9g %.9g n %.9g %.9g %.9g sep %.9g %.9g %.9g\n",
              s->tick_ms, i, c->tree_a, c->corpus_b, c->mat_a, c->mat_b, (double)c->point.x, (double)c->point.y, (double)c->point.z, (double)c->normal.x,
              (double)c->normal.y, (double)c->normal.z, (double)c->separation.x, (double)c->separation.y,
              (double)c->separation.z);
    }
  dyna *d = &s->body;
  for (uint32_t i = 0; i < s->buf.count; i++) {
    ref_collision *col = &s->buf.items[i];
    const gm_mat3 *rot = &d->state.rot;
    /* InitForCollisionAResponse (the car asks for local contacts) */
    car_contact ct;
    memset(&ct, 0, sizeof ct);
    ct.tree = col->tree_a;
    ct.own_material = col->mat_a;
    ct.peer_material = col->mat_b;
    ct.normal = mat3_tmul_vec(rot, col->normal);
    ct.point = mat3_tmul_vec(rot, v3_sub(col->point, d->state.pos));
    if (col->corpus_b >= 0 && (uint32_t)col->corpus_b < s->corpus_count) {
      ct.has_peer = 1;
      ct.peer_corpus = (uint32_t)col->corpus_b;
      ct.peer_z = mat3_col(&s->corpus_iso[col->corpus_b].r, 2);
    }
    /* SolveImpulse: car (dynamic type Normal) against static */
    float fa, ra, fb, rb;
    material_data(col->mat_a, &fa, &ra);
    material_data(col->mat_b, &fb, &rb);
    float restitution = restitution_with(ra, rb);
    gm_vec3 repl = v3_neg(col->separation);
    gm_vec3 speed_a = dyna_speed_at(d, col->point);
    gm_vec3 rel = v3_sub(v3(0.0f, 0.0f, 0.0f), speed_a);
    ct.accepted = 1;
    ct.replacement = mat3_tmul_vec(rot, repl);
    ct.speed = mat3_tmul_vec(rot, v3_neg(rel));
    car_absorb_contact(&s->car, &ct);
    repl = local_to_world_side_a(rot, ct.replacement);
    dyna_add_replacement(d, repl);
    if (!ct.accepted)
      continue;
    apply_impulse_side_a(d, col, speed_a, restitution, fa * fb);
  }
}

static void detect(ref_sim *s) {
  s->buf.count = 0;
  gm_iso4 iso = {s->body.state.rot, s->body.state.pos};
  ref_detect_static(&s->det, s->def.root, &iso);
  ref_detect_merge(&s->det);
}

static void substep(ref_sim *s, float dt) {
  corpus_forces(s, dt);
  dyna_pre_collision(&s->body, dt);
  detect(s);
  collision_response(s);
  dyna_post_collision(&s->body);
}

/* CHmsZoneDynamic::PhysicsStep2 for the car */
static void physics_step2(ref_sim *s) {
  float dt = (float)(int32_t)s->period_ms * 0.001f;
  dyna *d = &s->body;
  if (!d->active)
    return;
  d->temp = d->state;
  gm_vec3 l = d->state.lin, a = d->state.ang;
  float ll = tmuf_sqrtf((l.y * l.y + l.x * l.x) + l.z * l.z);
  float al = tmuf_sqrtf((a.x * a.x + a.y * a.y) + a.z * a.z);
  float scaled = ((ll + al) * dt) / d->params.max_step_distance;
  uint32_t n;
  if (!isfinite(scaled) || fabsf(scaled) >= 18446744073709551616.0f) {
    n = 1;
  } else {
    double tr = trunc((double)scaled);
    uint32_t mag = (uint32_t)fmod(fabs(tr), 4294967296.0);
    n = (signbit(scaled) ? 0u - mag : mag) + 1u;
  }
  if (n > 1000u)
    n = 1000u;
  s->substeps = n;
  float remaining = dt;
  if (n > 1) {
    float split = dt / (float)n;
    for (uint32_t k = n - 1; k != 0; k--) {
      substep(s, split);
      remaining = remaining - split;
    }
  }
  substep(s, remaining);
  d->write = d->temp; /* CopyTempToState */
  car_after_contacts(&s->car);
}

void ref_sim_step(ref_sim *s, const ref_tick *t) {
  car *c = &s->car;
  if (!s->first_step) {
    /* ReplayVehicleSimulation::PrepareStep */
    car_set_controls(c, t->gate_a, t->gate_b, t->steering);
    if (t->establish_spawn) {
      gm_iso4 cur = {s->body.state.rot, s->body.state.pos};
      car_establish_spawn(c, &cur);
    }
    if (t->enable_race)
      car_begin_race(c);
    if (t->reset_at_race_start) {
      c->turbo.roulette_origin = t->time_ms;
      c->integration.speed_blocked = 0;
      car_reset(c);
    }
    /* InstallPhysicalParameters(CaptureDynaParameters()): solid = dyna */
    c->solid_mass = s->body.params.mass;
    c->solid_com = s->body.params.com;
    c->contact_feedback_scale = s->body.params.force_scale;
    c->linear_fluid_friction = s->body.params.linear_damping_scale;
  }
  s->tick_ms = t->time_ms;
  s->period_ms = t->period_ms;
  /* respawns: not implemented yet */
  physics_step2(s);
  s->first_step = 0;
}

/* ---- control ticks (ReplayControlPlan, input-only validation) ---- */

enum { ACT_NONE, ACT_ACCEL, ACT_GAS, ACT_BRAKE, ACT_STEER, ACT_LEFT, ACT_RIGHT, ACT_RUNNING, ACT_FINISH, ACT_RESPAWN };

static int action_kind(const char *name) {
  static const struct {
    const char *n;
    int k;
  } T[] = {{"Accelerate", ACT_ACCEL}, {"Gas", ACT_GAS},         {"Brake", ACT_BRAKE},
           {"Steer", ACT_STEER},      {"SteerLeft", ACT_LEFT},  {"SteerRight", ACT_RIGHT},
           {"_FakeIsRaceRunning", ACT_RUNNING}, {"_FakeFinishLine", ACT_FINISH}, {"Respawn", ACT_RESPAWN}};
  for (size_t i = 0; i < sizeof T / sizeof T[0]; i++)
    if (name && strcmp(name, T[i].n) == 0)
      return T[i].k;
  return ACT_NONE;
}

static int32_t signed24(uint32_t e) {
  e &= 0x00ffffffu;
  return (e & 0x00800000u) ? (int32_t)(e | 0xff000000u) : (int32_t)e;
}

typedef struct ctl_state {
  int running, accel, brake, left, right;
  int32_t left_t, right_t, steer_t, accel_t, brake_t, gas_t;
  int32_t steer, gas;
} ctl_state;

static void controls_from(const ctl_state *st, float *a, float *b, float *steer) {
  *steer = 0.0f;
  int32_t dt = st->left_t > st->right_t ? st->left_t : st->right_t;
  int analog = st->steer_t > dt || (st->steer_t == dt && !st->left && !st->right && abs(st->steer) > 655);
  if (analog)
    *steer = (float)st->steer / 65536.0f;
  else if (st->left)
    *steer = -1.0f;
  else if (st->right)
    *steer = 1.0f;
  *a = 0.0f;
  *b = 0.0f;
  int32_t gt = st->accel_t > st->brake_t ? st->accel_t : st->brake_t;
  int analog_gas = st->gas_t > gt || (st->gas_t == gt && !st->accel && !st->brake);
  if (analog_gas) {
    if (st->gas <= -19661)
      *a = 1.0f;
    else if (st->gas >= 19661)
      *b = 1.0f;
  } else {
    *a = st->accel ? 1.0f : 0.0f;
    *b = st->brake ? 1.0f : 0.0f;
  }
}

uint32_t ref_control_ticks(const tmuf_ghost *g, ref_tick **out) {
  const uint32_t tick_ms = 10, prestart = 2600, base = 100000;
  *out = NULL;
  int32_t final_target = (int32_t)prestart + (int32_t)g->input_duration;
  uint32_t cap = (uint32_t)(final_target / (int32_t)tick_ms) + 2;
  ref_tick *ticks = calloc(cap, sizeof *ticks);
  if (!ticks)
    return 0;
  int kinds[256] = {0};
  for (uint32_t i = 0; i < g->action_count && i < 256; i++)
    kinds[i] = action_kind(g->actions[i]);
  ctl_state st;
  memset(&st, 0, sizeof st);
  uint32_t cursor = 0, n = 0;
  int prev_running = 0, reset_done = 0, spawn_done = 0;
  for (int32_t t = (int32_t)tick_ms; t <= final_target; t += (int32_t)tick_ms) {
    uint32_t sample = base - prestart + (uint32_t)t;
    uint32_t respawns = 0;
    int finish = 0;
    while (cursor < g->event_count && g->events[cursor].time <= sample) {
      const tmuf_input_event *e = &g->events[cursor];
      int k = kinds[e->action];
      int active = e->value != 0;
      int32_t et = (int32_t)e->time;
      if (k == ACT_RESPAWN && st.running && active)
        respawns++;
      if (k == ACT_FINISH && e->value == 1)
        finish = 1;
      switch (k) {
      case ACT_ACCEL:
        st.accel = active, st.accel_t = et;
        break;
      case ACT_GAS:
        st.gas = -signed24(e->value), st.gas_t = et;
        break;
      case ACT_BRAKE:
        st.brake = active, st.brake_t = et;
        break;
      case ACT_STEER:
        st.steer = -signed24(e->value), st.steer_t = et;
        break;
      case ACT_LEFT:
        st.left = active, st.left_t = et;
        break;
      case ACT_RIGHT:
        st.right = active, st.right_t = et;
        break;
      case ACT_RUNNING:
        st.running = active;
        break;
      default:
        break;
      }
      cursor++;
    }
    ref_tick *tk = &ticks[n++];
    tk->period_ms = tick_ms;
    tk->time_ms = (uint32_t)t;
    tk->finish_race = finish;
    if (!spawn_done && t >= 0) {
      tk->establish_spawn = 1;
      spawn_done = 1;
    }
    if (t >= (int32_t)prestart) {
      tk->enable_race = 1;
      tk->respawns = respawns;
      if (!reset_done && !prev_running && st.running) {
        tk->reset_at_race_start = 1;
        reset_done = 1;
      }
    }
    prev_running = st.running;
    controls_from(&st, &tk->gate_a, &tk->gate_b, &tk->steering);
  }
  /* appendUnobservedTrailingTick (race mode) */
  if (n > 0) {
    ticks[n] = ticks[n - 1];
    ticks[n].time_ms += ticks[n].period_ms;
    ticks[n].establish_spawn = 0;
    ticks[n].reset_at_race_start = 0;
    ticks[n].finish_race = 0;
    ticks[n].respawns = 0;
    n++;
  }
  *out = ticks;
  return n;
}
