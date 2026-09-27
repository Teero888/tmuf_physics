/* CSceneVehicleCar: lifecycle, wheels, contacts and impulses. */

#include <stdlib.h>
#include <string.h>

#include "reference/car_util.h"

/* ---- tuning curves (CFuncKeysReal::GetValue, CSceneVehicleCarTuning) ---- */

static float key_lower(float k) { return (float)((double)k - (double)1.0e-5f); }
static float key_upper(float k) { return (float)((double)k + (double)1.0e-5f); }

static int within(float x, float lo, float hi) {
  float l = key_lower(lo), h = key_upper(hi);
  return !isnan(x) && !isnan(l) && !isnan(h) && x >= l && x <= h;
}

float tmuf_curve_eval(const tmuf_curve *cv, float x) {
  uint32_t n = cv->present ? cv->count : 0;
  if (n == 0)
    return 0.0f;
  uint32_t k0, k1;
  if (n == 1 || x < key_lower(cv->x[0])) {
    k0 = k1 = 0;
  } else if (x > key_upper(cv->x[n - 1])) {
    k0 = k1 = n - 1;
  } else {
    uint32_t cur = 0;
    int found = 0;
    for (uint32_t scanned = 0; scanned <= n; scanned++) {
      uint32_t next = cur + 1 < n ? cur + 1 : 0;
      if (within(x, cv->x[cur], cv->x[next])) {
        found = 1;
        break;
      }
      cur = next;
    }
    k0 = cur;
    k1 = found ? (cur + 1 < n ? cur + 1 : 0) : (cur + 1u < n ? cur + 1u : 0u);
  }
  float blend = 0.0f;
  if (k0 != k1) {
    float x0 = cv->x[k0];
    float span = cv->x[k1] - x0;
    blend = fabsf(span) >= 1.0e-5f ? (x - x0) / span : 0.0f;
  }
  if (cv->constant)
    return cv->y[k0];
  return (1.0f - blend) * cv->y[k0] + blend * cv->y[k1];
}

float car_eval_speed_curve(const tmuf_curve *curve, float speed) {
  return tmuf_curve_eval(curve, tmuf_mul_fd(speed, (double)3.6f));
}

static float linear_speed_curve(tmuf_curve *curve, float speed) {
  curve->constant = 1; /* SetInterpolation(Constant) */
  return car_eval_speed_curve(curve, speed);
}

#define CV(c) (&(c)->t->curves)
float tn_max_side_friction(car *c, float s) { return car_eval_speed_curve(&CV(c)->max_side_friction_from_speed, s); }
float tn_accel(car *c, float s) { return linear_speed_curve(&CV(c)->slip_response_accel_from_speed, s); }
float tn_rollover_lateral(car *c, float s) { return car_eval_speed_curve(&CV(c)->rollover_lateral_from_speed, s); }
float tn_steer_drive_torque(car *c, float s) {
  return car_eval_speed_curve(&CV(c)->steering_drive_torque_from_speed, s);
}
float tn_lateral_contact_slowdown(car *c, float s) {
  return linear_speed_curve(&CV(c)->lateral_contact_slow_down_from_speed, s);
}
float tn_steer_slowdown(car *c, float s) { return linear_speed_curve(&CV(c)->steer_slow_down_from_speed, s); }
float tn_rollover_lateral_coef(car *c, float a) {
  return tmuf_curve_eval(&CV(c)->rollover_lateral_coefficient_from_angle, a);
}
float tn_m4_steer_radius(car *c, float s) { return car_eval_speed_curve(&CV(c)->radius_steering_radius_from_speed, s); }
float tn_m4_max_friction(car *c, float s) {
  return car_eval_speed_curve(&CV(c)->radius_steering_max_friction_from_speed, s);
}
float tn_m5_accel(car *c, float s) { return car_eval_speed_curve(&CV(c)->slip_response_accel_from_speed, s); }
float tn_m5_slipping_accel(car *c, float s) {
  float v = car_eval_speed_curve(&CV(c)->slip_response_slipping_accel_from_speed, s);
  return c->t->slip_response.slipping_accel_scale * v;
}
float tn_m5_steer_slowdown(car *c, float s) { return car_eval_speed_curve(&CV(c)->steer_slow_down_from_speed, s); }
float tn_water_friction(car *c, float s) { return car_eval_speed_curve(&CV(c)->water_friction_from_speed, s); }
float tn_m5_lateral_contact_slowdown(car *c, float s) {
  return car_eval_speed_curve(&CV(c)->lateral_contact_slow_down_from_speed, s);
}
float tn_m6_damper_modulation(car *c, float absorb) {
  const tmuf_vt_suspension *su = &c->t->suspension;
  float n = 0.0f;
  if (su->damper_modulation_min_absorb != su->damper_modulation_max_absorb)
    n = (absorb - su->damper_modulation_min_absorb) /
        (su->damper_modulation_max_absorb - su->damper_modulation_min_absorb);
  return tmuf_curve_eval(&CV(c)->suspension_damper_absorb_modulation, n);
}
float tn_m6_rear_gear_accel(car *c, float s) { return car_eval_speed_curve(&CV(c)->reverse_gear_accel_from_speed, s); }
float tn_m6_burnout_radius(car *c, float s) { return car_eval_speed_curve(&CV(c)->burnout_radius_from_speed, s); }
float tn_m6_lateral_speed_from_radius(car *c, float r) {
  float v = tmuf_curve_eval(&CV(c)->burnout_lateral_speed_from_radius, r);
  return (float)((double)v / (double)3.6f);
}
float tn_m6_burnout_rollover(car *c, float s) { return car_eval_speed_curve(&CV(c)->burnout_rollover_from_speed, s); }
float tn_m6_donut_rollover(car *c, float s) { return car_eval_speed_curve(&CV(c)->donut_rollover_from_speed, s); }
float tn_m6_rollover_lateral_ratio(car *c, float r) {
  return car_eval_speed_curve(&CV(c)->burnout_rollover_lateral_from_speed_ratio, r);
}

/* ---- lifecycle ---- */

static void wheel_update_surface(car *c, car_wheel *w) {
  (void)c;
  if (w->tree)
    w->tree->local = w->cur_iso;
}

void car_update_wheel_trees(car *c) {
  for (uint32_t i = 0; i < c->wheel_count; i++)
    wheel_update_surface(c, &c->wheels[i]);
}

static void wheel_reset(car *c, car_wheel *w) {
  w->max_replacement_y = 0.0f;
  w->damper_velocity = 0.0f;
  w->damper_absorb = c->t->suspension.wheel_rest_damper_absorb;
  float neg = -w->damper_absorb;
  w->cur_iso = w->rest_iso;
  w->cur_iso.t.y += neg;
  wheel_update_surface(c, w);
  w->angular_speed = 0.0f;
  w->spin_angle = 0.0f;
  w->contact = 0;
  w->normal_sum = v3(0.0f, 0.0f, 0.0f);
  w->steer_angle = 0.0f;
  w->steer_target = 0.0f;
  w->slipping = 0;
  w->normal_samples = 0;
  w->rejected = 0;
  w->rejected_point = v3(0.0f, 0.0f, 0.0f);
}

void car_init(car *c, car_def *def, dyna *body) {
  memset(c, 0, sizeof *c);
  c->def = def;
  c->t = &def->tuning;
  c->body = body;
  c->linear_speed_cap = 277.77777f;
  c->reverse_gear_speed_threshold = 10.0f;
  c->controls.special_mode = 1; /* ImpulseFromForce */
  c->feedback.forward.stiffness = 150.0f;
  c->feedback.forward.damping = 8.0f;
  c->feedback.side.stiffness = 150.0f;
  c->feedback.side.damping = 8.0f;
  c->feedback.drive_limit = 10.0f;
  c->feedback.velocity_limit = 15.0f;
  c->feedback.value_limit = 1.0f;
  c->geared.burnout_base_radius = 1.0f;
  c->geared.burnout_target_radius = 2.0f;
  c->geared.active_steer_slowdown = 1.0f;
  c->geared.wheel_span = 1.0f;
  c->engine.input_max = 11000.0f;
  c->engine.low_feedback_gate_scale = 1.0f;
  c->engine.slip_rpm_scale = 1.0f;
  c->engine.gear = 1;
  c->integration.update_wheel_visuals = 1;
  c->integration.integrate_wheels = 1;
  c->integration.integrate_engine = 1;
  c->integration.speed_blocked = 1;
  c->integration.speed_blocked2 = 1;

  /* VehicleInitFromSolid */
  c->wheel_count = def->wheel_count;
  for (uint32_t i = 0; i < c->wheel_count; i++) {
    car_wheel *w = &c->wheels[i];
    w->kills_lateral_speed = def->wheels[i].kills_lateral_speed;
    w->front = def->wheels[i].front;
    w->tree = def->wheels[i].tree;
    w->rolling_radius = 1.0f;
    mat3_identity(&w->rest_iso.r);
    w->rest_iso.t = v3(0.0f, 0.0f, 0.0f);
    if (w->tree) {
      w->rest_iso = w->tree->local;
      if (w->tree->surf && (w->tree->surf->type == SURF_SPHERE || w->tree->surf->type == SURF_ELLIPSOID))
        w->rolling_radius = w->tree->surf->geom_box.half.y; /* GmSurf::GetRollingRadius */
      w->force_point = def->wheels[i].force_point; /* GetThisToRootTransfo */
    }
    w->cur_iso = w->rest_iso;
  }
  car_reset(c);
}

void car_reset(car *c) {
  /* ResetPlayerControls */
  c->controls.gate_a = c->controls.gate_b = c->controls.steering = 0.0f;
  c->controls.current_steering = 0.0f;
  c->controls.special_gate = 0.0f;
  c->contacts.special_cooldown_until = 0;
  c->controls.forced_low_speed_friction = 0;
  /* ResetTurbo */
  c->turbo.progress = 0.0f;
  c->turbo.type = TURBO_NONE;
  c->turbo.impulse_scale = 0.0f;
  /* ResetAirControl */
  c->air.refresh_memory = 0;
  c->air.memory_tick = 0;
  c->air.memory_angular = v3(0.0f, 0.0f, 0.0f);
  /* ResetRadiusSteering */
  c->radius.steer_angle = 0.0f;
  c->radius.phase = RADIUS_IDLE;
  c->radius.previous_sign = 0.0f;
  c->slip.steering_tick = UINT32_MAX;
  /* ResetGearedDrive */
  c->slip.active = 0;
  c->slip.last_tick = UINT32_MAX;
  c->slip.start_tick = UINT32_MAX;
  c->geared.wheel_speed_override = 0;
  c->geared.burnout_start = UINT32_MAX;
  c->geared.burnout_exit_start = UINT32_MAX;
  iso4_identity(&c->geared.frame_iso);
  c->geared.burnout_normal = v3(0.0f, 0.0f, 0.0f);
  c->geared.local_speed = v3(0.0f, 0.0f, 0.0f);
  c->geared.burnout_phase = BURNOUT_NONE;
  c->geared.engine_state = ENGINE_STEADY;
  c->geared.input_window_exceeded = 0;
  c->geared.drive_speed_inhibited = 0;
  /* ResetImpacts */
  c->contacts.body_contact = 0;
  c->contacts.lateral_slowdown_contact = 0;
  c->contacts.lateral_slowdown_tick = UINT32_MAX;
  c->controls.no_ground_friction_guard = 0;
  c->contacts.front_impact = c->contacts.rear_impact = c->contacts.body_impact = IMPACT_NONE;
  c->contacts.last_wheel_material = c->contacts.last_body_material = MAT_CONCRETE;
  c->contacts.peak_rear = c->contacts.peak_front = c->contacts.peak_body = IMPACT_NONE;
  c->contacts.front_bucket = 0.0f;
  c->contacts.peak_wheel_material = MAT_CONCRETE;
  c->contacts.rear_bucket = 0.0f;
  c->contacts.peak_body_material = MAT_CONCRETE;
  c->contacts.body_bucket = 0.0f;
  c->last_forces_tick = 0;
  /* ResetForceAccumulators */
  c->acc.force = c->acc.impulse = v3(0.0f, 0.0f, 0.0f);
  c->contacts.body_point_sum = c->contacts.body_normal_sum = v3(0.0f, 0.0f, 0.0f);
  c->contacts.body_contact_count = 0;
  c->contacts.wheel_contact_count = 0;
  c->feedback.surface = 0.0f;
  for (uint32_t i = 0; i < c->wheel_count; i++)
    wheel_reset(c, &c->wheels[i]);
  /* SEngine::Reset */
  c->engine.use_gate_b = 0;
  c->engine.input_memory = 0.0f;
  c->engine.gear = 1;
  c->engine.target_input = 0.0f;
  c->engine.low_feedback_force = 0.0f;
  c->engine.shift_cooldown = 0.0f;
  c->engine.slip_rpm_scale = 1.0f;
  /* ResetSolidFeedback */
  c->contact_feedback_scale = c->t->body_air_response.grounded_solid_feedback1;
  c->linear_fluid_friction = 0.0f;
  c->frame.forward_speed = c->frame.side_speed = 0.0f;
  c->frame.has_wheel_contact = c->frame.has_body_contact = 0;
}

void car_refresh_dyna_params(car *c) {
  dyna_params *p = &c->body->params;
  p->mass = c->solid_mass;
  p->com = c->solid_com;
  p->linear_damping_scale = c->linear_fluid_friction;
  p->angular_damping_scale = 0.0f;
  p->max_step_distance = c->t->body_air_response.solid_physical_response_coef_b;
  p->force_scale = c->contact_feedback_scale;
}

/* ReplayVehicleSimulation::BuildDynaParameters */
void car_default_dyna_params(const car *c, dyna_params *p) {
  if (c->wheel_count == 0)
    return;
  const tmuf_vehicle_tuning *t = c->t;
  gm_vec3 mn = v3(0, 0, 0), mx = v3(0, 0, 0);
  float bottom_sum = 0.0f;
  for (uint32_t i = 0; i < c->wheel_count; i++) {
    const car_wheel *w = &c->wheels[i];
    gm_vec3 q = w->rest_iso.t;
    float bottom = q.y - w->rolling_radius;
    if (i == 0) {
      mn = mx = q;
      bottom_sum = bottom;
    } else {
      if (q.x < mn.x)
        mn.x = q.x;
      if (q.y < mn.y)
        mn.y = q.y;
      if (q.z < mn.z)
        mn.z = q.z;
      if (mx.x < q.x)
        mx.x = q.x;
      if (mx.y < q.y)
        mx.y = q.y;
      if (mx.z < q.z)
        mx.z = q.z;
      bottom_sum = bottom_sum + bottom;
    }
  }
  gm_box b = box_from_min_max(mn, mx);
  p->mass = t->body_air_response.solid_physical_mass;
  p->linear_damping_scale = 0.0f;
  p->angular_damping_scale = 0.0f;
  p->max_step_distance = t->body_air_response.solid_physical_response_coef_b;
  p->force_scale = t->body_air_response.grounded_solid_feedback1;
  p->com = b.center;
  p->com.y = (1.0f / (float)c->wheel_count) * bottom_sum + t->body_air_response.solid_center_y_offset;
  p->com.z = b.center.z + t->body_air_response.solid_center_z_half_extent_scale * b.half.z;
  const float *box = t->body_air_response.solid_inertia_box_size;
  float width = box[0] * 2.0f, height = box[1] * 2.0f, length = 2.0f * box[2];
  float scale = (1.0f / t->body_air_response.solid_inertia_mass) * 12.0f;
  for (int r = 0; r < 3; r++)
    for (int k = 0; k < 3; k++)
      p->inv_inertia_local.m[r][k] = 0.0f;
  p->inv_inertia_local.m[0][0] = scale / (height * height + length * length);
  p->inv_inertia_local.m[1][1] = scale / (length * length + width * width);
  p->inv_inertia_local.m[2][2] = scale / (width * width + height * height);
}

void car_update_params(car *c) {
  if (c->wheel_count == 0)
    return;
  const tmuf_vehicle_tuning *t = c->t;
  gm_vec3 mn = v3(0, 0, 0), mx = v3(0, 0, 0);
  float bottom_sum = 0.0f;
  for (uint32_t i = 0; i < c->wheel_count; i++) {
    car_wheel *w = &c->wheels[i];
    /* ApplySingleMaterialRefFromTuning: done when the definition is built */
    gm_vec3 p = w->rest_iso.t;
    float bottom = p.y - w->rolling_radius;
    if (i == 0) {
      mn = mx = p;
      bottom_sum = bottom;
    } else {
      if (p.x < mn.x)
        mn.x = p.x;
      if (p.y < mn.y)
        mn.y = p.y;
      if (p.z < mn.z)
        mn.z = p.z;
      if (mx.x < p.x)
        mx.x = p.x;
      if (mx.y < p.y)
        mx.y = p.y;
      if (mx.z < p.z)
        mx.z = p.z;
      bottom_sum = bottom_sum + bottom;
    }
  }
  gm_box b = box_from_min_max(mn, mx);
  c->geared.wheel_span = b.half.z + b.half.z;
  gm_vec3 com = b.center;
  float zoff = t->body_air_response.solid_center_z_half_extent_scale * b.half.z;
  com.z = b.center.z + zoff;
  float inv_count = 1.0f / (float)c->wheel_count;
  float avg_bottom = inv_count * bottom_sum;
  com.y = avg_bottom + t->body_air_response.solid_center_y_offset;
  c->solid_mass = t->body_air_response.solid_physical_mass;
  c->contact_feedback_scale = t->body_air_response.grounded_solid_feedback1;
  c->linear_fluid_friction = 0.0f;
  c->solid_com = com;
  /* CPlugPhysicalObject::SetInertiaMatrixBox */
  const float *box = t->body_air_response.solid_inertia_box_size;
  float width = box[0] * 2.0f, height = box[1] * 2.0f, length = 2.0f * box[2];
  float scale = (1.0f / t->body_air_response.solid_inertia_mass) * 12.0f;
  gm_mat3 inv;
  for (int r = 0; r < 3; r++)
    for (int k = 0; k < 3; k++)
      inv.m[r][k] = 0.0f;
  inv.m[0][0] = scale / (height * height + length * length);
  inv.m[1][1] = scale / (length * length + width * width);
  inv.m[2][2] = scale / (width * width + height * height);
  c->body->params.inv_inertia_local = inv;
  c->geared.active_steer_slowdown = t->steering.slow_down_scale;
  c->engine.input_max = t->geared_drive.input.engine_input_maximum;
  car_refresh_dyna_params(c);
}

void car_begin_race(car *c) {
  c->integration.update_wheel_visuals = 1;
  c->integration.integrate_wheels = 1;
  c->integration.integrate_engine = 1;
  c->integration.zero_horizontal_speed = 0;
  c->integration.speed_blocked = 0;
  c->integration.speed_blocked2 = 0;
}

void car_set_controls(car *c, float a, float b, float s) {
  c->controls.gate_a = a;
  c->controls.gate_b = b;
  c->controls.steering = s;
}

void car_establish_spawn(car *c, const gm_iso4 *spawn) {
  c->geared.frame_iso = *spawn;
  c->slip.active = 0;
  c->slip.last_tick = UINT32_MAX;
  c->slip.start_tick = UINT32_MAX;
}

/* ---- impulses ---- */

/* SDynaMath::ComputeImpulse */
static gm_vec3 compute_impulse(float mass, const gm_mat3 *inertia, float restitution, gm_vec3 speed, gm_vec3 n,
                               gm_vec3 lever) {
  gm_vec3 au = v3(n.z * lever.y - n.y * lever.z, n.x * lever.z - lever.x * n.z, n.y * lever.x - n.x * lever.y);
  au = mat3_mul_vec(inertia, au);
  gm_vec3 ap = v3(lever.z * au.y - au.z * lever.y, lever.x * au.z - lever.z * au.x, au.x * lever.y - lever.x * au.y);
  float sn = dot_yxz(speed, n);
  float num = (restitution - 1.0f) * sn;
  float am = v3_dot(n, ap);
  float denom = 1.0f / mass + am;
  float scale = num / denom;
  return v3(n.x * scale, n.y * scale, scale * n.z);
}

static void compute_and_apply_contact_impulse(car *c, float restitution, gm_vec3 speed, gm_vec3 normal,
                                              gm_vec3 point) {
  gm_vec3 lever = v3_sub(point, c->solid_com);
  gm_vec3 imp = compute_impulse(c->solid_mass, &c->body->params.inv_inertia_local, restitution, speed, normal, lever);
  car_add_impulse_at(c, imp, point);
}

void car_add_impulse(car *c, gm_vec3 imp) {
  dyna_add_impulse(c->body, dyna_local_dir_to_world(c->body, imp));
  c->acc.impulse.x = c->acc.impulse.x + imp.x;
  c->acc.impulse.y = imp.y + c->acc.impulse.y;
  c->acc.impulse.z = imp.z + c->acc.impulse.z;
}

/* CSceneVehicleCar::AddVehicleImpulse(impulse, point) */
void car_add_impulse_at(car *c, gm_vec3 imp, gm_vec3 point) {
  dyna_state *s = &c->body->state;
  const dyna_params *p = &c->body->params;
  const tmuf_vt_contact_response *cr = &c->t->contact_response;
  gm_vec3 wimp = mat3_mul_vec(&s->rot, imp);
  gm_iso4 iso = {s->rot, s->pos};
  gm_vec3 wpoint = iso4_mul_point(&iso, point);
  gm_vec3 wcom = iso4_mul_point(&iso, p->com);
  float inv_mass = 1.0f / p->mass;
  gm_vec3 cand = v3(s->lin.x + wimp.x * inv_mass, s->lin.y + wimp.y * inv_mass, s->lin.z + wimp.z * inv_mass);
  float pre = (s->lin.y * s->lin.y + s->lin.x * s->lin.x) + s->lin.z * s->lin.z;
  float post = (cand.y * cand.y + cand.x * cand.x) + cand.z * cand.z;
  float growth = post - pre;
  if (pre < post && cr->point_impulse_linear_speed_growth_limit_sq < growth)
    cand = v3(0.0f, 0.0f, 0.0f);
  s->lin = cand;
  gm_vec3 r = v3(wpoint.x - wcom.x, wpoint.y - wcom.y, wpoint.z - wcom.z);
  gm_vec3 d = v3(r.y * wimp.z - r.z * wimp.y, r.z * wimp.x - wimp.z * r.x, wimp.y * r.x - r.y * wimp.x);
  d = mat3_mul_vec(&s->inv_inertia_world, d);
  float as = cr->point_impulse_angular_scale;
  d.x = as * d.x;
  d.y = as * d.y;
  d.z = as * d.z;
  d.y = cr->point_impulse_angular_y_scale * d.y;
  s->ang.x = s->ang.x + d.x;
  s->ang.y = s->ang.y + d.y;
  s->ang.z = s->ang.z + d.z;
  float mx = cr->point_impulse_angular_speed_max;
  float cur = (s->ang.y * s->ang.y + s->ang.x * s->ang.x) + s->ang.z * s->ang.z;
  if (cur > mx * mx) {
    float len = tmuf_sqrtf(cur);
    float k = mx / len;
    s->ang.x = s->ang.x * k;
    s->ang.y = s->ang.y * k;
    s->ang.z = s->ang.z * k;
  }
  c->acc.impulse.x = imp.x + c->acc.impulse.x;
  c->acc.impulse.y = imp.y + c->acc.impulse.y;
  c->acc.impulse.z = imp.z + c->acc.impulse.z;
}

/* ---- wheel helpers ---- */

int car_is_ground_contact(const car *c) {
  for (uint32_t i = 0; i < c->wheel_count; i++)
    if (c->wheels[i].contact)
      return 1;
  return 0;
}

const car_material *car_wheel_material(const car *c, const car_wheel *w) {
  uint32_t m = w->contact_material < MAT_COUNT ? w->contact_material : 0;
  return &c->def->materials[c->def->material_remap[m]];
}

/* WheelAddForceToVehicle */
void car_wheel_add_force(car *c, car_wheel *w) {
  if (!w->contact)
    return;
  const tmuf_vt_suspension *su = &c->t->suspension;
  gm_vec3 f = v3(0.0f, 0.0f, 0.0f);
  if (c->t->wheel_force_mode == WHEEL_FORCE_SPRING) {
    f.y = (su->wheel_rest_damper_absorb - w->damper_absorb) * (su->wheel_spring_coef * su->wheel_static_spring_scale);
    car_add_force_at(c, f, w->force_point);
    return;
  }
  if (c->t->wheel_force_mode == WHEEL_FORCE_FOLLOW || c->t->wheel_force_mode == WHEEL_FORCE_FOLLOW_IMPULSE) {
    float spring = (su->wheel_rest_damper_absorb - w->damper_absorb) * su->wheel_spring_coef;
    f.y = spring - su->wheel_damper_coef * w->damper_velocity;
    car_add_force_at(c, f, w->force_point);
  }
}

/* ---- contacts ---- */

static float body_contact_impulse(const car *c, uint8_t m) {
  return m == MAT_METAL ? c->t->contact_response.body_contact_impulse_metal
                        : c->t->contact_response.body_contact_impulse_other;
}
static float body_contact_tangent_limit(const car *c, uint8_t m) {
  return m == MAT_METAL ? c->t->contact_response.body_contact_tangent_limit_metal
                        : c->t->contact_response.body_contact_tangent_limit_other;
}
static float wheel_contact_impulse(const car *c, uint8_t m) {
  return m == MAT_METAL ? c->t->contact_response.wheel_contact_impulse_metal
                        : c->t->contact_response.wheel_contact_impulse_other;
}

static void apply_follow_absorb_impulse(car *c, car_wheel *w, car_contact *ct, int blocked) {
  float restitution = -wheel_contact_impulse(c, ct->peer_material);
  gm_vec3 speed = ct->speed;
  float ns = dot_yxz(ct->normal, speed);
  if (!(ns < 0.0f))
    return;
  gm_vec3 nc = v3(ct->normal.x * ns, ct->normal.y * ns, ns * ct->normal.z);
  float ncy = nc.y;
  if (blocked || !(ncy < 0.0f)) {
    compute_and_apply_contact_impulse(c, restitution, speed, ct->normal, ct->point);
    return;
  }
  float nxz = 0.0f;
  gm_vec3 s2 = ct->speed;
  s2.x = s2.x - nxz;
  s2.y = s2.y - ncy;
  s2.z = s2.z - nxz;
  if (dot_yxz(ct->normal, s2) < 0.0f)
    compute_and_apply_contact_impulse(c, restitution, s2, ct->normal, w->cur_iso.t);
}

static int apply_follow_absorb_replacement(car *c, car_wheel *w, car_contact *ct) {
  float ry = ct->replacement.y;
  int blocked = 0;
  if (ry > 0.0f) {
    float cand = ry;
    float amax = c->t->suspension.damper_modulation_max_absorb;
    if (amax >= -SCALAR_EPS) {
      float clamped = w->damper_absorb - amax;
      if (clamped <= ry) {
        cand = clamped;
        blocked = 1;
      }
    }
    float prev = w->max_replacement_y;
    float mx = cand;
    if (!(cand > prev))
      mx = prev;
    w->max_replacement_y = mx;
    float xz = 0.0f;
    ct->replacement.x = ct->replacement.x - xz;
    ct->replacement.y = ct->replacement.y - cand;
    ct->replacement.z = ct->replacement.z - xz;
  } else {
    blocked = 1;
  }
  return blocked;
}

static void wheel_absorb_contact(car *c, car_wheel *w, car_contact *ct) {
  const float max_nx = 0.70710677f; /* CIsinQuarterPi, 0x3f3504f3 */
  w->contact = fabsf(ct->normal.x) < max_nx;
  if (!w->contact) {
    c->contacts.lateral_slowdown_contact = 1;
    w->rejected_point = ct->point;
    w->rejected = 1;
  }
  if (w->contact) {
    w->normal_samples++;
    w->normal_sum = v3_add(w->normal_sum, ct->normal);
    w->contact_material = ct->peer_material;
  }
  ct->accepted = 0;
  if (ct->has_peer) {
    w->peer_corpus = ct->peer_corpus;
    /* MultTranspose(self GetLocation rotation): the write state */
    w->peer_z_local = mat3_tmul_vec(&c->body->write.rot, ct->peer_z);
  }
  w->latest_contact_point = ct->point;
  if (c->t->wheel_force_mode != WHEEL_FORCE_FOLLOW_IMPULSE)
    return;
  int blocked = apply_follow_absorb_replacement(c, w, ct);
  if (w->contact) {
    apply_follow_absorb_impulse(c, w, ct, blocked);
    return;
  }
  float restitution = -body_contact_impulse(c, ct->peer_material);
  if (dot_yxz(ct->normal, ct->speed) < 0.0f) {
    gm_vec3 p = v3(ct->point.x, c->solid_com.y, ct->point.z);
    compute_and_apply_contact_impulse(c, restitution, ct->speed, ct->normal, p);
  }
}

static void absorb_body_contact_with_impulse(car *c, car_contact *ct) {
  float sn = (ct->normal.y * ct->speed.y + ct->normal.x * ct->speed.x) + ct->normal.z * ct->speed.z;
  if (sn < 0.0f) {
    float restitution = -body_contact_impulse(c, ct->peer_material);
    float limit = body_contact_tangent_limit(c, ct->peer_material);
    gm_vec3 ns = v3(ct->normal.x * sn, ct->normal.y * sn, sn * ct->normal.z);
    gm_vec3 ts = v3(ct->speed.x - ns.x, ct->speed.y - ns.y, ct->speed.z - ns.z);
    float nl = tmuf_sqrtf(len2_yxz(ns));
    float tl = tmuf_sqrtf(len2_yxz(ts));
    float tmax = nl * limit;
    if (tl > tmax) {
      float k = tmax / tl;
      ts.x = k * ts.x;
      ts.y = ts.y * k;
      ts.z = k * ts.z;
    }
    gm_vec3 in = v3(-(ts.x + ns.x), -(ts.y + ns.y), -(ts.z + ns.z));
    float il = tmuf_sqrtf(len2_yxz(in));
    if (SCALAR_EPS < il) {
      float inv = 1.0f / il;
      in.x = inv * in.x;
      in.y = in.y * inv;
      in.z = inv * in.z;
      compute_and_apply_contact_impulse(c, restitution, ct->speed, in, ct->point);
    }
  }
  ct->accepted = 0;
}

static uint32_t wheel_from_tree(const car *c, const void *tree) {
  for (uint32_t i = 0; i < c->wheel_count; i++)
    if (c->wheels[i].tree == tree)
      return i;
  return UINT32_MAX;
}

/* CSceneVehicleCar::AbsorbContact */
void car_absorb_contact(car *c, car_contact *ct) {
  if (ct->peer_material == MAT_WATER || ct->peer_material == MAT_GOLF_BALL) {
    ct->accepted = 0;
    ct->replacement = v3(0.0f, 0.0f, 0.0f);
    return;
  }
  c->air.refresh_memory = 1;
  uint32_t wi = wheel_from_tree(c, ct->tree);
  float impact = fabsf(dot_yxz(ct->normal, ct->speed));
  if (wi == UINT32_MAX || !(ct->normal.y > 0.2f)) {
    c->contacts.body_bucket = c->contacts.body_bucket + impact;
  } else if (!c->wheels[wi].front) {
    c->contacts.rear_bucket = c->contacts.rear_bucket + impact;
  } else {
    c->contacts.front_bucket = impact + c->contacts.front_bucket;
  }
  if (wi != UINT32_MAX) {
    c->contacts.last_wheel_material = ct->peer_material;
    wheel_absorb_contact(c, &c->wheels[wi], ct);
    c->contacts.wheel_contact_count++;
    return;
  }
  if (ct->normal.y < -0.75f && c->t->handling_model == HANDLING_GEARED) {
    float along = dot_yxz(ct->normal, ct->replacement);
    ct->replacement = v3_scale(ct->normal, along);
  }
  c->contacts.body_point_sum = v3_add(c->contacts.body_point_sum, ct->point);
  c->contacts.body_normal_sum = v3_add(c->contacts.body_normal_sum, ct->normal);
  c->contacts.body_contact_count++;
  c->contacts.body_contact = 1;
  c->contacts.last_body_material = ct->peer_material;
  if (c->t->wheel_force_mode == WHEEL_FORCE_FOLLOW_IMPULSE)
    absorb_body_contact_with_impulse(c, ct);
}

/* ---- fake contacts ---- */

static int pow2_wrapped(float coord, float period, float *result) {
  uint32_t cb = tmuf_f2u(coord), pb = tmuf_f2u(period);
  uint32_t cm = cb & 0x7fffffffu, ce = cm >> 23, pe = pb >> 23;
  if ((pb & 0x807fffffu) != 0u || pe == 0u || pe == 0xffu || ce == 0xffu)
    return 0;
  float mag = tmuf_u2f(cm);
  if (cm < pb) {
    *result = mag;
    return 1;
  }
  if (pe < 127u && ce > pe + 127u)
    return 0;
  float q = mag / period;
  uint32_t qb = tmuf_f2u(q), qe = qb >> 23;
  if (qe < 150u)
    qb &= ~((1u << (150u - qe)) - 1u);
  *result = mag - tmuf_u2f(qb) * period;
  return 1;
}

static uint32_t fake_texture_index(float coord, float period, uint32_t dim) {
  float w;
  if (!pow2_wrapped(coord, period, &w))
    w = fabsf(fmodf(coord, period));
  return (uint32_t)((w / period) * (float)dim);
}

void car_create_fake_contacts(car *c) {
  if (getenv("TMUF_NO_FAKE"))
    return;
  gm_vec3 lin = body_lin_local(c);
  uint32_t cached = ~0u;
  const car_material *mat = NULL;
  const car_fake_texture *tex = &c->def->fake_texture;
  gm_iso4 iso = {c->body->write.rot, c->body->write.pos};
  for (uint32_t i = 0; i < c->wheel_count; i++) {
    car_wheel *w = &c->wheels[i];
    if (!w->contact)
      continue;
    uint32_t cm = w->contact_material;
    if (cm != cached) {
      mat = &c->def->materials[c->def->material_remap[cm < MAT_COUNT ? cm : 0]];
      if (!mat->fake_contact || !tex->pixels)
        return;
      cached = cm;
    }
    gm_vec3 wp = iso4_mul_point(&iso, w->rest_iso.t);
    uint32_t px = fake_texture_index(wp.x, mat->fake_period_x, tex->width);
    uint32_t py = fake_texture_index(wp.z, mat->fake_period_z, tex->height);
    static int flip = -1, ch = 0, swap = 0;
    if (flip < 0) {
      flip = getenv("TMUF_FAKE_FLIP") ? 1 : 0;
      ch = getenv("TMUF_FAKE_CH") ? atoi(getenv("TMUF_FAKE_CH")) : 0;
      swap = getenv("TMUF_FAKE_SWAP") ? 1 : 0;
    }
    if (swap) {
      uint32_t t2 = px;
      px = py;
      py = t2;
    }
    if (flip)
      py = tex->height - 1 - py;
    uint8_t pixel = tex->pixels[(size_t)py * tex->stride + (size_t)px * tex->bpp + (size_t)ch];
    if (pixel == 0)
      continue;
    float ratio = (float)pixel / 255.0f;
    float fs = ratio * lin.z * mat->fake_speed_scale;
    if (mat->fake_depth_max < fs)
      fs = mat->fake_depth_max;
    car_contact ct;
    memset(&ct, 0, sizeof ct);
    ct.own_material = MAT_CONCRETE;
    ct.normal = v3(0.0f, 1.0f, 0.0f);
    ct.point = w->rest_iso.t;
    ct.speed = v3(0.0f, -fs, 0.0f);
    ct.peer_material = w->contact_material;
    wheel_absorb_contact(c, w, &ct);
  }
}

/* ---- AfterContacts ---- */

void car_after_contacts(car *c) {
  gm_vec3 lin = body_lin_local(c);
  c->frame.forward_speed = lin.z;
  c->frame.side_speed = lin.x;
  c->frame.has_body_contact = c->contacts.body_contact_count != 0;
  c->frame.has_wheel_contact = c->contacts.wheel_contact_count != 0;
  /* ResetContactAccumulators */
  c->contacts.wheel_contact_count = 0;
  c->contacts.body_contact_count = 0;
  c->contacts.body_point_sum = v3(0.0f, 0.0f, 0.0f);
  c->contacts.body_normal_sum = v3(0.0f, 0.0f, 0.0f);
}
