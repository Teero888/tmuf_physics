#include "optimized/sim.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common/replay.h"
#include "optimized/car_util.h"

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
  /* every operation in binary32 (the game's x87 runs at 24-bit precision;
     double intermediates differ, e.g. seed 3335649494) */
  float normalized = (float)(seed % 100000u) / 100000.0f;
  float yaw_deg = (normalized - 0.5f) * 0.1f;
  float yaw = (yaw_deg * 3.1415927410125732f) / 180.0f;
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

/* ---- race (CTrackManiaRace) ---- */

enum { GP_STATIC = 0, GP_TRIGGER = 1 };

static int race_init(ref_race *r, const tmuf_scene *scene) {
  uint32_t n = scene->corpus_count ? scene->corpus_count : 1;
  r->laps = 1;
  r->slot = malloc(sizeof *r->slot * n);
  r->role = calloc(n, 1);
  r->respawn_current = calloc(n, 1);
  r->spawn = calloc(n, sizeof *r->spawn);
  if (!r->slot || !r->role || !r->respawn_current || !r->spawn)
    return 0;
  /* ReplayStaticCorpusCollection: checkpoint slots in installation order */
  for (uint32_t i = 0; i < scene->corpus_count; i++) {
    const tmuf_scene_corpus *c = &scene->corpora[i];
    r->slot[i] = -1;
    if (!c->trigger || c->collision_group != 1)
      continue;
    r->role[i] = c->race_role;
    r->respawn_current[i] = c->respawn_current;
    iso_from_scene(&r->spawn[i], &c->spawn);
    if (c->race_role == TMUF_RACE_CHECKPOINT)
      r->slot[i] = (int32_t)r->checkpoint_count++;
  }
  r->passed = calloc(r->checkpoint_count + 1, 1);
  return r->passed != NULL;
}

/* CTrackManiaRace::SetInitialSpawnLocation */
static void race_set_initial_spawn(ref_race *r, const gm_iso4 *spawn) {
  r->current = r->previous = *spawn;
  r->has_spawn = 1;
}

/* CTrackManiaRace::ClearVehicleFreewheelState */
static void race_clear_freewheel(ref_sim *s) { s->car.controls.forced_low_speed_friction = 0; }

/* room for n checkpoint times */
static int race_times_reserve(ref_race *r, uint32_t n) {
  if (n <= r->checkpoint_time_cap)
    return 1;
  uint32_t cap = r->checkpoint_time_cap ? r->checkpoint_time_cap : r->checkpoint_count + 1;
  while (cap < n)
    cap *= 2;
  uint32_t *t = realloc(r->checkpoint_times, sizeof *t * cap);
  if (!t)
    return 0;
  r->checkpoint_times = t;
  r->checkpoint_time_cap = cap;
  return 1;
}

/* CTrackManiaRace::InternalOnCheckpoint */
static int race_internal_checkpoint(ref_sim *s, uint32_t index, uint32_t slot, const gm_iso4 *spawn) {
  ref_race *r = &s->race;
  if (index > r->checkpoint_count || slot > r->checkpoint_count || r->passed[slot])
    return 0;
  r->passed[slot] = 1;
  if (race_times_reserve(r, r->checkpoint_time_count + 1))
    r->checkpoint_times[r->checkpoint_time_count++] = s->tick_ms - TMUF_CONTROL_RACE_START_MS;
  if (index != r->checkpoint_count) {
    r->lap_checkpoints++;
    r->checkpoints_passed++;
  }
  if (spawn) {
    gm_iso4 at = *spawn;
    r->current = at; /* StoreSpawnLocation: SetSpawnLoc(spawn, 0) */
    r->has_spawn = 1;
  } else {
    r->current = r->previous;
  }
  race_clear_freewheel(s);
  return 1;
}

/* CTrackManiaRace::OnCheckpointContact for a trigger corpus the car touched */
static void race_trigger(ref_sim *s, uint32_t corpus) {
  ref_race *r = &s->race;
  if (corpus >= s->corpus_count)
    return;
  switch (r->role[corpus]) {
  case TMUF_RACE_CHECKPOINT: {
    /* OnCheckpoint */
    if (r->respawn_current[corpus])
      race_clear_freewheel(s);
    if (r->slot[corpus] < 0)
      return;
    gm_iso4 current = r->current;
    const gm_iso4 *spawn = r->respawn_current[corpus] ? &current : &r->spawn[corpus];
    race_internal_checkpoint(s, r->lap_checkpoints, (uint32_t)r->slot[corpus], spawn);
    return;
  }
  case TMUF_RACE_FINISH:
  case TMUF_RACE_START_FINISH:
    /* OnFinishLine */
    if (r->completed || r->lap_checkpoints < r->checkpoint_count)
      return;
    if (!race_internal_checkpoint(s, r->checkpoint_count, r->checkpoint_count, NULL))
      return;
    r->completed_laps++;
    if (r->laps != 0 && r->completed_laps >= r->laps) {
      r->completed = 1;
      r->finish_time = s->tick_ms - TMUF_CONTROL_RACE_START_MS;
      return;
    }
    memset(r->passed, 0, r->checkpoint_count + 1);
    r->lap_checkpoints = 0;
    return;
  default:
    return;
  }
}

/* ReplayVehicleSimulation::Respawn */
static void respawn(ref_sim *s) {
  if (!s->race.has_spawn)
    return;
  s->race.respawns++;
  car *c = &s->car;
  float a = c->controls.gate_a, b = c->controls.gate_b, st = c->controls.steering;
  car_reset(c);
  dyna *d = &s->body;
  dyna_state *states[3] = {&d->temp, &d->write, &d->state};
  for (int i = 0; i < 3; i++) {
    dyna_state *x = states[i];
    x->lin = x->lin_corr = x->ang = x->force = x->torque = v3(0.0f, 0.0f, 0.0f);
    x->tweaked_valid = 0;
    x->tweaked_lin = v3(0.0f, 0.0f, 0.0f);
  }
  d->replacement_count = 0;
  c->integration.speed_blocked2 = 0;
  car_default_dyna_params(c, &d->params);
  gm_iso4 at = s->race.current;
  dyna_set_location(d, &at);
  car_set_controls(c, a, b, st);
}

int ref_sim_init(ref_sim *s, tmuf_scene *scene, const tmuf_vehicle *v, const gm_iso4 *spawn, uint32_t seed,
                 const ref_tick *first, char *err, size_t err_size) {
  memset(s, 0, sizeof *s);
  if (!ref_world_build(&s->world, scene, REF_WORLD_STATIC) ||
      !ref_world_build(&s->triggers, scene, REF_WORLD_TRIGGERS) ||
      !ref_world_build(&s->nonstatic, scene, REF_WORLD_NONSTATIC)) {
    snprintf(err, err_size, "static world");
    return 0;
  }
  if (!race_init(&s->race, scene)) {
    snprintf(err, err_size, "race");
    return 0;
  }
  s->water = scene->water;
  s->water.cells = NULL;
  if (scene->water.enabled) {
    size_t n = (size_t)scene->water.dims[0] * scene->water.dims[1];
    s->water.cells = malloc(n ? n : 1);
    if (!s->water.cells)
      return 0;
    memcpy(s->water.cells, scene->water.cells, n);
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
  c->water = s->water.enabled ? &s->water : NULL;
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
    race_set_initial_spawn(&s->race, &cur);
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
  dyna_free(&s->body);
  free(s->race.passed);
  free(s->race.checkpoint_times);
  ref_cbuf_free(&s->buf);
  for (uint32_t i = 0; i < s->tree_count; i++)
    ref_cbuf_free(&s->trees[i].sphere);
  free(s->trees);
  free(s->child_ptrs);
  if (!s->shared) {
    free(s->water.cells);
    free(s->race.slot);
    free(s->race.role);
    free(s->race.respawn_current);
    free(s->race.spawn);
    ref_world_free(&s->triggers);
    ref_world_free(&s->nonstatic);
    free(s->corpus_iso);
    ref_world_free(&s->world);
  }
  memset(s, 0, sizeof *s);
}

/* ---- clones and snapshots ---- */

static ref_mtree *rebase_tree(const ref_sim *from, ref_sim *to, const ref_mtree *t) {
  return t ? to->trees + (t - from->trees) : NULL;
}

int ref_sim_clone(ref_sim *dst, const ref_sim *tpl) {
  *dst = *tpl;
  dst->shared = 1;
  dst->trees = calloc(tpl->tree_count ? tpl->tree_count : 1, sizeof *dst->trees);
  uint32_t nchild = 0;
  for (uint32_t i = 0; i < tpl->tree_count; i++)
    nchild += tpl->trees[i].child_count;
  dst->child_ptrs = calloc(nchild ? nchild : 1, sizeof *dst->child_ptrs);
  dst->race.passed = calloc(tpl->race.checkpoint_count + 1, 1);
  dst->race.checkpoint_times = NULL;
  dst->race.checkpoint_time_count = dst->race.checkpoint_time_cap = 0;
  dst->body.replacements = NULL;
  dst->body.replacement_count = dst->body.replacement_cap = 0;
  memset(&dst->buf, 0, sizeof dst->buf);
  if (!dst->trees || !dst->child_ptrs || !dst->race.passed) {
    free(dst->trees);
    free(dst->child_ptrs);
    free(dst->race.passed);
    memset(dst, 0, sizeof *dst);
    return 0;
  }
  memcpy(dst->race.passed, tpl->race.passed, tpl->race.checkpoint_count + 1);
  if (!race_times_reserve(&dst->race, tpl->race.checkpoint_time_count)) {
    free(dst->trees);
    free(dst->child_ptrs);
    free(dst->race.passed);
    memset(dst, 0, sizeof *dst);
    return 0;
  }
  if (tpl->race.checkpoint_time_count)
    memcpy(dst->race.checkpoint_times, tpl->race.checkpoint_times,
           sizeof(uint32_t) * tpl->race.checkpoint_time_count);
  dst->race.checkpoint_time_count = tpl->race.checkpoint_time_count;
  for (uint32_t i = 0; i < tpl->tree_count; i++) {
    dst->trees[i] = tpl->trees[i];
    memset(&dst->trees[i].sphere, 0, sizeof dst->trees[i].sphere);
    dst->trees[i].queued = 0;
    if (tpl->trees[i].children)
      dst->trees[i].children = dst->child_ptrs + (tpl->trees[i].children - tpl->child_ptrs);
  }
  for (uint32_t i = 0; i < nchild; i++)
    dst->child_ptrs[i] = rebase_tree(tpl, dst, tpl->child_ptrs[i]);
  dst->def.root = rebase_tree(tpl, dst, tpl->def.root);
  for (uint32_t i = 0; i < CAR_MAX_WHEELS; i++) {
    dst->def.wheels[i].tree = rebase_tree(tpl, dst, tpl->def.wheels[i].tree);
    dst->car.wheels[i].tree = dst->def.wheels[i].tree;
  }
  dst->car.def = &dst->def;
  dst->car.t = &dst->def.tuning;
  dst->car.body = &dst->body;
  dst->car.water = dst->water.enabled ? &dst->water : NULL;
  dst->det.out = &dst->buf;
  dst->det.queued_count = 0;
  return 1;
}

/* dst takes src's state; both are clones of one template (or the template).
   Fails (dst unchanged) only when out of memory. */
int ref_sim_copy_state(ref_sim *dst, const ref_sim *src) {
  if (!race_times_reserve(&dst->race, src->race.checkpoint_time_count))
    return 0;
  car_def *def = dst->car.def;
  tmuf_vehicle_tuning *t = dst->car.t;
  dyna *body = dst->car.body;
  const tmuf_scene_water *water = dst->car.water;
  ref_mtree *wheel_trees[CAR_MAX_WHEELS];
  for (uint32_t i = 0; i < CAR_MAX_WHEELS; i++)
    wheel_trees[i] = dst->car.wheels[i].tree;
  dst->car = src->car;
  dst->car.def = def;
  dst->car.t = t;
  dst->car.body = body;
  dst->car.water = water;
  for (uint32_t i = 0; i < CAR_MAX_WHEELS; i++)
    dst->car.wheels[i].tree = wheel_trees[i];
  gm_vec3 *rep = dst->body.replacements;
  uint32_t rep_cap = dst->body.replacement_cap;
  dst->body = src->body;
  dst->body.replacements = rep;
  dst->body.replacement_cap = rep_cap;
  dst->body.replacement_count = 0;
  uint8_t *passed = dst->race.passed;
  uint32_t *times = dst->race.checkpoint_times, times_cap = dst->race.checkpoint_time_cap;
  dst->race = src->race;
  dst->race.passed = passed;
  dst->race.checkpoint_times = times;
  dst->race.checkpoint_time_cap = times_cap;
  memcpy(passed, src->race.passed, src->race.checkpoint_count + 1);
  if (src->race.checkpoint_time_count)
    memcpy(times, src->race.checkpoint_times, sizeof(uint32_t) * src->race.checkpoint_time_count);
  dst->tick_ms = src->tick_ms;
  dst->period_ms = src->period_ms;
  dst->substeps = src->substeps;
  dst->first_step = src->first_step;
  const tmuf_curve *from = (const tmuf_curve *)&src->def.tuning.curves;
  tmuf_curve *to = (tmuf_curve *)&dst->def.tuning.curves;
  for (size_t i = 0; i < sizeof(tmuf_vt_curves) / sizeof(tmuf_curve); i++)
    to[i].constant = from[i].constant;
  /* the collision trees as they are: a box is refreshed once per step and
     can lag its tree's location (the wheels follow the suspension after
     the refresh) */
  for (uint32_t i = 0; i < dst->tree_count && i < src->tree_count; i++) {
    dst->trees[i].local = src->trees[i].local;
    dst->trees[i].box = src->trees[i].box;
  }
  return 1;
}

/* the curves' interpolation mode changes the first time some are read */
#define CURVE_COUNT (sizeof(tmuf_vt_curves) / sizeof(tmuf_curve))

typedef struct snap_head {
  car car;
  dyna body;
  ref_race race;
  uint32_t tick_ms, period_ms, substeps;
  int first_step;
  uint8_t curve_constant[CURVE_COUNT];
} snap_head;

/* snapshot: snap_head, the race's checkpoint flags and checkpoint times,
   then each collision tree's location and box */
typedef struct snap_tree {
  gm_iso4 local;
  gm_box box;
} snap_tree;

size_t ref_sim_snapshot_size(const ref_sim *s) {
  return sizeof(snap_head) + s->race.checkpoint_count + 1 + sizeof(uint32_t) * s->race.checkpoint_time_count +
         sizeof(snap_tree) * s->tree_count;
}

void ref_sim_save(const ref_sim *s, void *buf) {
  snap_head h;
  memset(&h, 0, sizeof h);
  h.car = s->car;
  h.body = s->body;
  h.body.replacements = NULL;
  h.body.replacement_count = h.body.replacement_cap = 0;
  h.race = s->race;
  h.tick_ms = s->tick_ms;
  h.period_ms = s->period_ms;
  h.substeps = s->substeps;
  h.first_step = s->first_step;
  const tmuf_curve *cv = (const tmuf_curve *)&s->def.tuning.curves;
  for (size_t i = 0; i < CURVE_COUNT; i++)
    h.curve_constant[i] = (uint8_t)cv[i].constant;
  memcpy(buf, &h, sizeof h);
  uint8_t *p = (uint8_t *)buf + sizeof h;
  memcpy(p, s->race.passed, s->race.checkpoint_count + 1);
  p += s->race.checkpoint_count + 1;
  if (s->race.checkpoint_time_count)
    memcpy(p, s->race.checkpoint_times, sizeof(uint32_t) * s->race.checkpoint_time_count);
  uint8_t *tp = p + sizeof(uint32_t) * s->race.checkpoint_time_count;
  for (uint32_t i = 0; i < s->tree_count; i++) {
    snap_tree st;
    st.local = s->trees[i].local;
    st.box = s->trees[i].box;
    memcpy(tp + sizeof st * i, &st, sizeof st);
  }
}

void ref_sim_load(ref_sim *s, const void *buf) {
  snap_head h;
  memcpy(&h, buf, sizeof h);
  /* the car's links stay those of this simulation */
  car_def *def = s->car.def;
  tmuf_vehicle_tuning *t = s->car.t;
  dyna *body = s->car.body;
  const tmuf_scene_water *water = s->car.water;
  ref_mtree *wheel_trees[CAR_MAX_WHEELS];
  for (uint32_t i = 0; i < CAR_MAX_WHEELS; i++)
    wheel_trees[i] = s->car.wheels[i].tree;
  s->car = h.car;
  s->car.def = def;
  s->car.t = t;
  s->car.body = body;
  s->car.water = water;
  for (uint32_t i = 0; i < CAR_MAX_WHEELS; i++)
    s->car.wheels[i].tree = wheel_trees[i];
  gm_vec3 *rep = s->body.replacements;
  uint32_t rep_cap = s->body.replacement_cap;
  s->body = h.body;
  s->body.replacements = rep;
  s->body.replacement_cap = rep_cap;
  s->body.replacement_count = 0;
  uint8_t *passed = s->race.passed;
  uint32_t *times = s->race.checkpoint_times, times_cap = s->race.checkpoint_time_cap;
  int32_t *slot = s->race.slot;
  uint8_t *role = s->race.role, *respawn_current = s->race.respawn_current;
  gm_iso4 *spawn = s->race.spawn;
  s->race = h.race;
  s->race.passed = passed;
  s->race.checkpoint_times = times;
  s->race.checkpoint_time_cap = times_cap;
  s->race.slot = slot;
  s->race.role = role;
  s->race.respawn_current = respawn_current;
  s->race.spawn = spawn;
  const uint8_t *p = (const uint8_t *)buf + sizeof h;
  memcpy(s->race.passed, p, s->race.checkpoint_count + 1);
  p += s->race.checkpoint_count + 1;
  const uint32_t ntimes = s->race.checkpoint_time_count;
  if (!race_times_reserve(&s->race, ntimes))
    s->race.checkpoint_time_count = s->race.checkpoint_time_cap; /* out of memory: the first ones */
  if (s->race.checkpoint_time_count)
    memcpy(s->race.checkpoint_times, p, sizeof(uint32_t) * s->race.checkpoint_time_count);
  p += sizeof(uint32_t) * ntimes;
  s->tick_ms = h.tick_ms;
  s->period_ms = h.period_ms;
  s->substeps = h.substeps;
  s->first_step = h.first_step;
  tmuf_curve *cv = (tmuf_curve *)&s->def.tuning.curves;
  for (size_t i = 0; i < CURVE_COUNT; i++)
    cv[i].constant = h.curve_constant[i];
  const uint8_t *tp = p;
  for (uint32_t i = 0; i < s->tree_count; i++) {
    snap_tree st;
    memcpy(&st, tp + sizeof st * i, sizeof st);
    s->trees[i].local = st.local;
    s->trees[i].box = st.box;
  }
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
  dyna *d = &s->body;
  for (uint32_t i = 0; i < s->buf.count; i++) {
    ref_collision *col = &s->buf.items[i];
    if (col->group_pair == GP_TRIGGER) {
      /* pair (3, 1): no impulse, only the trigger absorbs the contact */
      if (col->corpus_b >= 0)
        race_trigger(s, (uint32_t)col->corpus_b);
      continue;
    }
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

/* SZone::DetectCollisionsCorpus: the car's group (3) against the triggers
   (group 1), then the static items (group 4) and the group's non-static
   corpora; one sphere contact merge */
static void detect(ref_sim *s) {
  s->buf.count = 0;
  gm_iso4 iso = {s->body.state.rot, s->body.state.pos};
  /* the triggers, the static items, then the group's non-static corpora
     (collided per corpus by the game; none of the verified runs touch one);
     a world without records collides with nothing */
  const ref_world *const worlds[3] = {&s->triggers, &s->world, &s->nonstatic};
  const uint32_t pairs[3] = {GP_TRIGGER, GP_STATIC, GP_STATIC};
  ref_detect_worlds(&s->det, s->def.root, &iso, worlds, pairs, 3);
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
      race_set_initial_spawn(&s->race, &cur);
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
  for (uint32_t k = 0; k < t->respawns; k++) {
    respawn(s);
  }
  physics_step2(s);
  s->first_step = 0;
}
