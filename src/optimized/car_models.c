/* CSceneVehicleCar handling models: 3 (standard / lateral), 4 (radius
   steering), 5 (slip response) and 6 (geared drive, burnouts). */

#include "optimized/car_util.h"

typedef struct force_request {
  float dt;
  gm_vec3 current_force;
  float slope_a, slope_b;
  gm_vec3 lin, ang;
  float steer_yaw;
  int has_ground_material;
  float mat[4]; /* x y z w */
  int *slip_flag;
  float *surface_feedback;
} force_request;

static void mark_all_wheels_slipping(car *c) {
  for (uint32_t i = 0; i < c->wheel_count; i++)
    c->wheels[i].slipping = 1;
}

static gm_vec3 steered_lateral(const car_wheel *w, float steer_yaw) {
  gm_vec3 lat = v3(w->normal_sum.y, -w->normal_sum.x, 0.0f);
  lat = normalize_or(lat, v3(1.0f, 0.0f, 0.0f), VEC_EPS2);
  if (w->front) {
    float cs = tmuf_cosf(steer_yaw);
    float ns = -tmuf_sinf(steer_yaw);
    lat = v3(cs * lat.x, cs * lat.y, ns + cs * lat.z);
  }
  return lat;
}

static void update_gate_b_from_speed(car *c, float speed) {
  if (c->controls.forced_low_speed_friction)
    return;
  if (!(speed < c->reverse_gear_speed_threshold)) {
    if (c->controls.gate_a > GATE)
      c->engine.use_gate_b = 0;
  } else if (!(GATE < c->controls.gate_b)) {
    c->engine.use_gate_b = 0;
  } else {
    c->engine.use_gate_b = 1;
  }
}

/* ---- model 3 ---- */

static void model3_contact_forces(car *c, force_request *r) {
  const tmuf_vehicle_tuning *t = c->t;
  for (uint32_t i = 0; i < c->wheel_count; i++) {
    car_wheel *w = &c->wheels[i];
    car_wheel_add_force(c, w);
    const car_material *m = car_wheel_material(c, w);
    if (!w->contact || !(t->geared_drive.lateral_force_scale > 0.0f) || t->handling_model != HANDLING_LATERAL)
      continue;
    float grip = w->slipping ? t->geared_drive.slipping_side_friction_scale : 1.0f;
    float max_side = m->w * r->slope_a * tn_max_side_friction(c, r->lin.z) * grip;
    gm_vec3 lat = steered_lateral(w, r->steer_yaw);
    float side = -t->geared_drive.lateral_force_scale * 0.5f * v3_dot(r->lin, lat);
    if (!(max_side < fabsf(side))) {
      w->slipping = 0;
    } else {
      float capped = sign_nn(side) * max_side;
      side = (1.0f - t->geared_drive.side_friction_slip_blend) * capped + t->geared_drive.side_friction_slip_blend * side;
      w->slipping = 1;
    }
    if (w->slipping)
      *r->slip_flag = 1;
    gm_vec3 lf = v3_scale(lat, side);
    car_add_force(c, lf);
    float roll = -tn_rollover_lateral(c, r->lin.z) * r->slope_a * tn_rollover_lateral_coef(c, fabsf(lat.y));
    car_add_torque(c, v3(lf.z * roll, 0.0f, -roll * lf.x));
  }
}

static void model3_steering_torques(car *c, force_request *r, float speed) {
  const tmuf_vehicle_tuning *t = c->t;
  for (uint32_t i = 0; i < c->wheel_count; i++) {
    car_wheel *w = &c->wheels[i];
    float half = (w->front ? c->geared.wheel_span : -c->geared.wheel_span) * 0.5f;
    float ramp = 1.0f;
    if (!(t->steering.assist_full_speed < speed))
      ramp = tmuf_sinf((speed / t->steering.assist_full_speed) * HALF_PI_F);
    float max_side = tn_max_side_friction(c, r->lin.z) * r->mat[3];
    float wss = r->lin.x + r->ang.y * half;
    float side = -t->geared_drive.lateral_force_scale * 0.5f * wss;
    if (max_side < fabsf(side)) {
      float b = (1.0f - t->geared_drive.drive_side_friction_slip_blend) * max_side +
                t->geared_drive.drive_side_friction_slip_blend * fabsf(side);
      side = sign_nn(side) * b;
    }
    float torque = t->geared_drive.side_force_to_drive_torque_scale * side;
    if (w->front) {
      float rev = !c->engine.use_gate_b ? 1.0f : -1.0f;
      float slip = w->slipping ? t->geared_drive.slipping_steer_torque_scale : 1.0f;
      float st = tn_steer_drive_torque(c, r->lin.z);
      float assist = rev * ramp * c->controls.current_steering * st * slip;
      torque = torque - assist;
    }
    car_add_torque(c, v3(0.0f, torque * half, 0.0f));
  }
}

static void model3_drive_forces(car *c, force_request *r) {
  const tmuf_vehicle_tuning *t = c->t;
  const tmuf_vt_geared_drive *gd = &t->geared_drive;
  float accel = tn_accel(c, r->lin.z);
  float side_limit = tn_max_side_friction(c, r->lin.z) * r->mat[3];
  float slow_in = fabsf(gd->lateral_force_scale * 0.5f * r->lin.x);
  if (side_limit < slow_in)
    slow_in = side_limit;
  float drive_scale = r->mat[1] * c->controls.gate_a + (c->engine.use_gate_b ? -1.0f : 0.0f) * r->mat[1] * c->controls.gate_b +
                      (c->turbo.type != TURBO_NONE ? c->turbo.impulse_scale : 0.0f);
  float drive = (accel - t->steering.slow_down_scale * slow_in * fabsf(c->controls.current_steering) *
                             tn_steer_slowdown(c, r->lin.z)) *
                drive_scale;
  if (c->controls.forced_low_speed_friction)
    drive = c->turbo.type == TURBO_NONE ? 0.0f : accel * c->turbo.impulse_scale;
  float opp = 0.0f;
  if (r->lin.z > 0.0f) {
    opp = (gd->forward_accel_base + gd->forward_accel_speed_coef * r->lin.z) * c->controls.gate_b;
    float cap = r->mat[2] * (*r->slip_flag == 0 ? gd->forward_accel_cap : gd->forward_accel_cap_when_slipping);
    if (cap < opp) {
      opp = cap;
      mark_all_wheels_slipping(c);
    }
  }
  if (r->lin.z < 0.0f && c->controls.forced_low_speed_friction) {
    opp = (gd->forward_accel_base - gd->forward_accel_speed_coef * r->lin.z) * c->controls.gate_a;
    float cap = r->mat[2] * (*r->slip_flag == 0 ? gd->forward_accel_cap : gd->forward_accel_cap_when_slipping);
    if (cap < opp) {
      opp = cap;
      mark_all_wheels_slipping(c);
    }
    opp = -opp;
  }
  if (c->controls.forced_low_speed_friction && fabsf(r->lin.z) < 1.0f)
    opp *= fabsf(r->lin.z);
  *r->surface_feedback = opp;
  float net = drive - opp;
  if (t->engine_speed_norm * r->mat[0] < r->lin.z)
    net = -gd->speed_limit_force;
  if (r->lin.z < -(gd->transmission.reverse_speed_norm * r->mat[0]))
    net = gd->speed_limit_force;
  float fz = net * r->slope_b;
  car_add_force(c, v3(0.0f, 0.0f, fz));
  car_add_torque(c, v3(-fz * t->slip_response.longitudinal_torque_scale, 0.0f, 0.0f));
  car_add_force(c, v3(0.0f, 0.0f, (-gd->force_z_scale * r->current_force.z) / t->body_air_response.grounded_solid_feedback1));
}

static void model3(car *c, force_request *r) {
  model3_contact_forces(c, r);
  if (!r->has_ground_material || c->t->handling_model != HANDLING_LATERAL)
    return;
  float speed = tmuf_sqrtf(v3_dot(r->lin, r->lin));
  update_gate_b_from_speed(c, speed);
  model3_steering_torques(c, r, speed);
  model3_drive_forces(c, r);
}

/* ---- model 4 ---- */

typedef struct m4_state {
  float speed, steer_angle, steer_sin, steer_cos;
  gm_vec3 steered_side;
  float forward_speed, side_speed_exit;
  int was_active, slip_seen;
  float drive, opposing;
} m4_state;

static void lateral_friction(car *c, gm_vec3 lin, gm_vec3 dir, const float mat[4], float slope_a, int slipping,
                             float *out_force, int *out_slip) {
  const tmuf_vt_radius_steering *rs = &c->t->radius_steering;
  float side = (lin.y * dir.y + dir.x * lin.x) + lin.z * dir.z;
  float abs_side = fabsf(side);
  float req = rs->lateral_friction_linear * -side - side * abs_side * rs->lateral_friction_quadratic;
  float slip = slipping ? rs->slipping_friction_scale : 1.0f;
  float mx = tn_m4_max_friction(c, abs_side) * (mat[3] * slope_a) * slip;
  if (mx >= fabsf(req)) {
    *out_slip = 0;
    *out_force = req;
  } else {
    *out_slip = 1;
    *out_force = mx * (req < 0.0f ? -1.0f : 1.0f);
  }
}

static void model4_prepare(car *c, force_request *r, m4_state *s) {
  const tmuf_vt_radius_steering *rs = &c->t->radius_steering;
  s->speed = tmuf_sqrtf(v3_dot(r->lin, r->lin));
  update_gate_b_from_speed(c, s->speed);
  if (c->radius.phase == RADIUS_DIRECT && fabsf(c->controls.current_steering) < SCALAR_EPS) {
    c->radius.phase = RADIUS_CAPTURED;
    c->radius.steer_angle = tmuf_atan2f(r->lin.x, r->lin.z);
  }
  if (c->radius.phase == RADIUS_DIRECT)
    s->steer_angle = -c->controls.current_steering * rs->steer_angle_from_input_scale;
  else if (c->radius.phase == RADIUS_CAPTURED)
    s->steer_angle = c->radius.steer_angle;
  s->steer_sin = tmuf_sinf(s->steer_angle);
  s->steer_cos = tmuf_cosf(s->steer_angle);
  s->steered_side = v3(s->steer_cos, 0.0f, -s->steer_sin);
  s->forward_speed = r->lin.x * s->steer_sin + r->lin.z * s->steer_cos;
  s->side_speed_exit = r->lin.x;
  float sf = 0.0f, xf = 0.0f;
  int ss = 0, xs = 0;
  lateral_friction(c, r->lin, s->steered_side, r->mat, r->slope_a, s->was_active, &sf, &ss);
  lateral_friction(c, r->lin, v3(1.0f, 0.0f, 0.0f), r->mat, r->slope_a, s->was_active, &xf, &xs);
  car_add_force(c, v3_scale(s->steered_side, sf * 0.5f));
  car_add_force(c, v3(xf * 0.5f, 0.0f, 0.0f));
  float ay = r->ang.y;
  car_add_torque(c, v3(0.0f, -ay * rs->angular_damping_linear - fabsf(ay) * ay * rs->angular_damping_quadratic, 0.0f));
}

static void model4_steering_torque(car *c, m4_state *s) {
  const tmuf_vt_radius_steering *rs = &c->t->radius_steering;
  float ty = 0.0f;
  if (c->radius.phase == RADIUS_CAPTURED && fabsf(c->radius.steer_angle) > SCALAR_EPS &&
      fabsf(rs->captured_angle_radius_scale) > SCALAR_EPS) {
    float rev = !c->engine.use_gate_b ? 1.0f : -1.0f;
    float sign = c->radius.steer_angle > 0.0f ? 1.0f : -1.0f;
    float radius = tn_m4_steer_radius(c, fabsf(s->speed)) / (rs->captured_angle_radius_scale * fabsf(c->radius.steer_angle));
    if (radius > SCALAR_EPS)
      ty = (-(sign * rev) * s->speed * rs->steer_torque_speed_scale * rs->angular_damping_linear) / radius;
  } else if (fabsf(c->controls.current_steering) > SCALAR_EPS) {
    float rev = !c->engine.use_gate_b ? 1.0f : -1.0f;
    float sign = c->controls.current_steering > 0.0f ? 1.0f : -1.0f;
    float scale = s->was_active ? rs->input_steer_radius_scale : 1.0f;
    float radius = tn_m4_steer_radius(c, fabsf(s->speed)) * scale;
    if (radius > SCALAR_EPS)
      ty = (-(sign * rev) * s->speed * rs->steer_torque_speed_scale * rs->angular_damping_linear *
            fabsf(c->controls.current_steering)) /
           radius;
  }
  if (ty != 0.0f)
    car_add_torque(c, v3(0.0f, ty, 0.0f));
}

static void model4_drive(car *c, force_request *r, m4_state *s) {
  const tmuf_vt_geared_drive *gd = &c->t->geared_drive;
  float accel = tn_accel(c, s->forward_speed);
  float rev = c->engine.use_gate_b ? -1.0f : 0.0f;
  float turbo = c->turbo.type != TURBO_NONE ? c->turbo.impulse_scale : 0.0f;
  s->drive = accel * (r->mat[1] * c->controls.gate_a + r->mat[1] * rev * c->controls.gate_b + turbo);
  if (c->controls.forced_low_speed_friction)
    s->drive = c->turbo.type == TURBO_NONE ? 0.0f : accel * c->turbo.impulse_scale;
  if (s->forward_speed > 0.0f) {
    s->opposing = (gd->forward_accel_base + gd->forward_accel_speed_coef * s->forward_speed) * c->controls.gate_b;
    float cap = r->mat[2] * (*r->slip_flag == 0 ? gd->forward_accel_cap : gd->forward_accel_cap_when_slipping);
    if (cap < s->opposing) {
      s->opposing = cap;
      s->slip_seen = 1;
    }
  }
  if (s->forward_speed < 0.0f && c->controls.forced_low_speed_friction) {
    s->opposing = (gd->forward_accel_base - gd->forward_accel_speed_coef * s->forward_speed) * c->controls.gate_a;
    float cap = r->mat[2] * (*r->slip_flag == 0 ? gd->forward_accel_cap : gd->forward_accel_cap_when_slipping);
    if (cap < s->opposing) {
      s->opposing = cap;
      s->slip_seen = 1;
    }
    s->opposing = -s->opposing;
  }
  if (c->controls.forced_low_speed_friction && fabsf(s->forward_speed) < 1.0f)
    s->opposing *= fabsf(s->forward_speed);
}

static void model4_radius_state(car *c, force_request *r, m4_state *s) {
  const tmuf_vt_radius_steering *rs = &c->t->radius_steering;
  if (!s->was_active) {
    if (s->slip_seen) {
      c->radius.steer_angle = 0.0f;
      c->radius.phase = RADIUS_DIRECT;
      c->radius.previous_sign = c->controls.current_steering > 0.0f ? 1.0f : -1.0f;
    }
    return;
  }
  c->radius.steer_angle += rs->captured_angle_rate * c->controls.current_steering * r->dt;
  if (fabsf(c->radius.steer_angle) > rs->steer_angle_limit)
    c->radius.steer_angle = sign_nn(c->radius.steer_angle) * rs->steer_angle_limit;
  int crossed = (c->radius.previous_sign > 0.0f && c->radius.steer_angle < 0.0f) ||
                (c->radius.previous_sign < 0.0f && c->radius.steer_angle > 0.0f);
  if ((fabsf(s->side_speed_exit) < rs->capture_exit_side_speed_max && fabsf(c->controls.current_steering) < SCALAR_EPS) ||
      crossed) {
    s->slip_seen = 0;
    c->radius.steer_angle = 0.0f;
    c->radius.phase = RADIUS_IDLE;
  } else {
    s->slip_seen = 1;
  }
}

static void model4_longitudinal(car *c, force_request *r, m4_state *s) {
  const tmuf_vehicle_tuning *t = c->t;
  *r->surface_feedback = s->opposing;
  float net = s->drive - s->opposing;
  if (t->engine_speed_norm * r->mat[0] < s->forward_speed)
    net = -t->geared_drive.speed_limit_force;
  if (s->forward_speed < -(t->geared_drive.transmission.reverse_speed_norm * r->mat[0]))
    net = t->geared_drive.speed_limit_force;
  float l = net * r->slope_b;
  car_add_force(c, v3(l * s->steer_sin, 0.0f, l * s->steer_cos));
  car_add_torque(c, v3(-l * t->slip_response.longitudinal_torque_scale, 0.0f, 0.0f));
}

static void model4(car *c, force_request *r) {
  for (uint32_t i = 0; i < c->wheel_count; i++)
    car_wheel_add_force(c, &c->wheels[i]);
  m4_state s = {0};
  s.steer_cos = 1.0f;
  s.steered_side = v3(1.0f, 0.0f, 0.0f);
  s.was_active = c->radius.phase != RADIUS_IDLE;
  if (r->has_ground_material) {
    model4_prepare(c, r, &s);
    model4_steering_torque(c, &s);
    model4_drive(c, r, &s);
    model4_radius_state(c, r, &s);
    model4_longitudinal(c, r, &s);
  }
  for (uint32_t i = 0; i < c->wheel_count; i++)
    c->wheels[i].slipping = s.slip_seen != 0;
  c->slip.active = s.slip_seen != 0;
}

/* ---- model 5 ---- */

typedef struct m5_state {
  int water, was_slipping, slip_seen;
  float side_limit_total, side_requested_total;
  uint32_t tick;
  float accel_base, drive;
} m5_state;

static float slip_acceleration_blend(car *c, uint32_t tick, float limit, float requested) {
  if (tick != c->slip.last_tick || !(limit > SCALAR_EPS))
    return 1.0f;
  float slip = (requested - limit) / limit / c->t->geared_drive.slip_ratio_scale;
  return 1.0f - clamp01(slip);
}

static void model5_contact_forces(car *c, force_request *r) {
  const tmuf_vehicle_tuning *t = c->t;
  for (uint32_t i = 0; i < c->wheel_count; i++) {
    car_wheel *w = &c->wheels[i];
    car_wheel_add_force(c, w);
    const car_material *m = car_wheel_material(c, w);
    if (!w->contact || !(t->geared_drive.lateral_force_scale > 0.0f))
      continue;
    float grip = w->slipping ? t->geared_drive.slipping_side_friction_scale : 1.0f;
    float max_side = m->w * r->slope_a * tn_max_side_friction(c, r->lin.z) * grip;
    gm_vec3 lat = steered_lateral(w, r->steer_yaw);
    float side = -t->geared_drive.lateral_force_scale * 0.5f * v3_dot(r->lin, lat);
    if (!(max_side < fabsf(side))) {
      w->slipping = 0;
    } else {
      float capped = sign_nn(side) * max_side;
      side = (1.0f - t->geared_drive.side_friction_slip_blend) * capped + t->geared_drive.side_friction_slip_blend * side;
      w->slipping = 1;
    }
    if (w->slipping)
      *r->slip_flag = 1;
    gm_vec3 lf = v3_scale(lat, side);
    car_add_force(c, lf);
    float roll = -tn_rollover_lateral(c, r->lin.z) * r->slope_a * tn_rollover_lateral_coef(c, fabsf(lat.y));
    car_add_torque(c, v3(lf.z * roll, 0.0f, -roll * lf.x));
  }
}

static void model5_side_torques(car *c, force_request *r, m5_state *s) {
  const tmuf_vehicle_tuning *t = c->t;
  float speed = tmuf_sqrtf(v3_dot(r->lin, r->lin));
  update_gate_b_from_speed(c, speed);
  for (uint32_t i = 0; i < 4 && i < c->wheel_count; i++) {
    car_wheel *w = &c->wheels[i];
    float half = (w->front ? c->geared.wheel_span : -c->geared.wheel_span) * 0.5f;
    float ramp = 1.0f;
    if (!(t->steering.assist_full_speed < speed))
      ramp = tmuf_sinf((speed / t->steering.assist_full_speed) * HALF_PI_F);
    float max_side = tn_max_side_friction(c, r->lin.z) * r->mat[3];
    float wss = r->lin.x + r->ang.y * half;
    float side = -t->geared_drive.lateral_force_scale * 0.5f * wss;
    if (fabsf(side) > max_side) {
      s->side_limit_total += max_side;
      s->side_requested_total += fabsf(side);
      float b = (1.0f - t->geared_drive.drive_side_friction_slip_blend) * max_side +
                t->geared_drive.drive_side_friction_slip_blend * fabsf(side);
      side = sign_nn(side) * b;
      s->slip_seen = 1;
    }
    float torque = t->geared_drive.side_force_to_drive_torque_scale * side;
    if (w->front) {
      float rev = !c->engine.use_gate_b ? 1.0f : -1.0f;
      float slip = w->slipping ? t->geared_drive.slipping_steer_torque_scale : 1.0f;
      float st = tn_steer_drive_torque(c, r->lin.z);
      torque = torque - rev * ramp * c->controls.current_steering * st * slip;
    }
    car_add_torque(c, v3(0.0f, torque * half, 0.0f));
  }
}

static void model5_drive(car *c, force_request *r, m5_state *s) {
  const tmuf_vehicle_tuning *t = c->t;
  s->tick = c->tick;
  if (s->slip_seen) {
    c->slip.last_tick = s->tick;
    if (!s->was_slipping)
      c->slip.start_tick = s->tick;
    c->slip.elapsed = s->tick - c->slip.start_tick;
  }
  float mix = slip_acceleration_blend(c, s->tick, s->side_limit_total, s->side_requested_total);
  float accel_slip = tn_m5_slipping_accel(c, r->lin.z);
  s->accel_base = tn_m5_accel(c, r->lin.z);
  float accel = (1.0f - mix) * accel_slip + s->accel_base * mix;
  if (fabsf(c->controls.steering) > SCALAR_EPS) {
    c->slip.steering_tick = s->tick;
    c->slip.steering_slip = s->slip_seen != 0;
  }
  float gate = 0.0f;
  if (c->slip.steering_tick <= s->tick && s->tick - c->slip.steering_tick < t->slip_response.steering_memory_ticks)
    gate = (!c->slip.steering_slip || !t->slip_response.slip_slowdown_enabled) ? 1.0f : 0.0f;
  uint32_t window = c->slip.elapsed;
  if (t->slip_response.slip_slowdown_ticks < window)
    window = t->slip_response.slip_slowdown_ticks;
  if (t->slip_response.slip_slowdown_enabled && c->slip.last_tick <= s->tick && s->tick - c->slip.last_tick <= window)
    gate = 0.0f;
  float rev = c->engine.use_gate_b ? -1.0f : 0.0f;
  float turbo = c->turbo.type != TURBO_NONE ? c->turbo.impulse_scale : 0.0f;
  s->drive = (r->mat[1] * c->controls.gate_a + r->mat[1] * rev * c->controls.gate_b) * accel + s->accel_base * turbo -
             t->steering.slow_down_scale * gate * tn_m5_steer_slowdown(c, r->lin.z);
  if (c->controls.forced_low_speed_friction)
    s->drive = c->turbo.type == TURBO_NONE ? 0.0f : s->accel_base * c->turbo.impulse_scale;
}

static void model5_longitudinal(car *c, force_request *r, m5_state *s) {
  const tmuf_vehicle_tuning *t = c->t;
  const tmuf_vt_geared_drive *gd = &t->geared_drive;
  float opp = 0.0f;
  if (r->lin.z > 0.0f) {
    opp = (gd->forward_accel_base + gd->forward_accel_speed_coef * r->lin.z) * c->controls.gate_b;
    float cap = r->mat[2] * (*r->slip_flag == 0 ? gd->forward_accel_cap : gd->forward_accel_cap_when_slipping);
    if (cap < opp) {
      opp = cap;
      mark_all_wheels_slipping(c);
      s->slip_seen = 1;
    }
  }
  if (r->lin.z < 0.0f && c->controls.forced_low_speed_friction) {
    opp = (gd->forward_accel_base - gd->forward_accel_speed_coef * r->lin.z) * c->controls.gate_a;
    float cap = r->mat[2] * (*r->slip_flag == 0 ? gd->forward_accel_cap : gd->forward_accel_cap_when_slipping);
    if (cap < opp) {
      opp = cap;
      mark_all_wheels_slipping(c);
      s->slip_seen = 1;
    }
    opp = -opp;
  }
  if (c->controls.forced_low_speed_friction && fabsf(r->lin.z) < 1.0f)
    opp *= fabsf(r->lin.z);
  *r->surface_feedback = opp;
  float net = s->drive - opp;
  if (t->engine_speed_norm * r->mat[0] < r->lin.z)
    net = -gd->speed_limit_force;
  if (r->lin.z < -(gd->transmission.reverse_speed_norm * r->mat[0]))
    net = gd->speed_limit_force;
  float fz = net * r->slope_b;
  car_add_force(c, v3(0.0f, 0.0f, fz));
  if (!s->water) {
    float lim = fz;
    if (t->slip_response.rollover_torque_cap < fabsf(lim))
      lim = sign_nn(lim) * t->slip_response.rollover_torque_cap;
    car_add_torque(c, v3(-lim * t->slip_response.longitudinal_torque_scale, 0.0f, 0.0f));
  }
  car_add_force(c, v3(0.0f, 0.0f, (-gd->force_z_scale * r->current_force.z) / t->body_air_response.grounded_solid_feedback1));
}

static void model5(car *c, force_request *r) {
  m5_state s = {0};
  s.water = car_apply_water_forces(c, r->current_force);
  c->frame.in_water = s.water;
  s.was_slipping = c->slip.active;
  c->controls.no_ground_friction_guard = s.water != 0;
  model5_contact_forces(c, r);
  if (!r->has_ground_material) {
    c->slip.active = 0;
    return;
  }
  model5_side_torques(c, r, &s);
  model5_drive(c, r, &s);
  model5_longitudinal(c, r, &s);
  c->slip.active = s.slip_seen != 0;
}

/* ---- model 6 (scene_vehicle_car_handling + legacy_models) ---- */

typedef struct m6_state {
  float frame_y;
  int water, dirt_slide;
  uint32_t tick;
  int slip_seen;
  float side_limit_total, side_requested_total;
  uint32_t wheel_count;
} m6_state;

static int all_wheels_material(const car *c, uint8_t m) {
  for (uint32_t i = 0; i < c->wheel_count; i++)
    if (!c->wheels[i].contact || c->wheels[i].contact_material != m)
      return 0;
  return 1;
}

static int advance_burnout_phases(car *c, uint32_t tick) {
  const tmuf_vt_burnout *b = &c->t->geared_drive.burnout;
  int slip_seen = 0;
  if (c->geared.burnout_phase == BURNOUT_SPIN) {
    if (tick < c->geared.burnout_start || tick - c->geared.burnout_start >= b->duration_ticks) {
      c->geared.burnout_exit_start = tick;
      c->geared.burnout_phase = BURNOUT_EXIT;
    } else {
      slip_seen = 1;
    }
  }
  if (c->geared.burnout_phase == BURNOUT_EXIT) {
    if (tick < c->geared.burnout_exit_start || tick - c->geared.burnout_exit_start >= b->exit_duration_ticks) {
      c->geared.burnout_phase = BURNOUT_NONE;
      c->geared.wheel_speed_override = 0;
      return slip_seen;
    }
    mark_all_wheels_slipping(c);
  }
  return slip_seen;
}

static float burnout_phase(uint32_t elapsed, uint32_t duration) {
  float scaled = (float)elapsed * PI_F;
  return scaled / (float)duration;
}

static float burnout_drive_fade(car *c, uint32_t tick) {
  const tmuf_vt_burnout *b = &c->t->geared_drive.burnout;
  if (c->geared.burnout_phase == BURNOUT_SPIN) {
    float fade = tmuf_sinf(burnout_phase(tick - c->geared.burnout_start, b->duration_ticks));
    return (b->drive_fade_scale - 1.0f) * fade + 1.0f;
  }
  if (c->geared.burnout_phase == BURNOUT_EXIT) {
    float fade = tmuf_sinf(burnout_phase(tick - c->geared.burnout_exit_start, b->exit_duration_ticks));
    return (b->exit_accel_fade_scale - 1.0f) * fade + 1.0f;
  }
  return 1.0f;
}

static float burnout_side_force_fade(car *c, uint32_t tick) {
  const tmuf_vt_burnout *b = &c->t->geared_drive.burnout;
  if (c->geared.burnout_phase != BURNOUT_SPIN)
    return 1.0f;
  float fade = tmuf_cosf(burnout_phase(tick - c->geared.burnout_start, b->duration_ticks * 2));
  return (b->side_force_fade_scale - 1.0f) * fade + 1.0f;
}

static float burnout_exit_acceleration(car *c, uint32_t tick) {
  const tmuf_vt_burnout *b = &c->t->geared_drive.burnout;
  if (c->geared.burnout_phase != BURNOUT_EXIT)
    return 0.0f;
  uint32_t q = (tick - c->geared.burnout_exit_start) / b->exit_duration_ticks;
  float d = (float)q - 1.0f;
  return d * d * b->exit_bonus_accel_scale;
}

static void update_gear_direction(car *c, gm_vec3 lin) {
  if (c->geared.burnout_phase != BURNOUT_NONE) {
    c->engine.use_gate_b = 0;
    return;
  }
  if (c->controls.gate_b > GATE && lin.z < c->reverse_gear_speed_threshold && fabsf(lin.x) < 2.0f)
    c->engine.use_gate_b = 1;
  if (c->controls.gate_a > GATE && (lin.z > 0.0f || fabsf(lin.x) > 2.0f))
    c->engine.use_gate_b = 0;
  if (c->controls.gate_a < GATE && c->controls.gate_b < GATE) {
    if (lin.z > 0.0f || fabsf(lin.z) < 2.0f)
      c->engine.use_gate_b = 0;
    else
      c->engine.use_gate_b = 1;
  }
  if (lin.z > 0.0f && c->turbo.type != TURBO_NONE)
    c->engine.use_gate_b = 0;
}

static gm_vec3 transform_dir(const gm_iso4 *iso, gm_vec3 v) { return mat3_mul_vec(&iso->r, v); }

static void enter_circular_burnout(car *c, gm_vec3 lin, float steer_yaw) {
  const tmuf_vt_burnout *b = &c->t->geared_drive.burnout;
  c->geared.burnout_phase = BURNOUT_CIRCLE;
  c->geared.burnout_direction = sign_nn(steer_yaw);
  gm_vec3 sum = v3(0.0f, 0.0f, 0.0f);
  for (uint32_t i = 0; i < c->wheel_count; i++)
    if (c->wheels[i].contact)
      sum = v3_add(sum, c->wheels[i].normal_sum);
  float l2 = v3_dot(sum, sum);
  if (VEC_EPS2 < l2) {
    c->geared.burnout_normal = v3_scale(sum, 1.0f / tmuf_sqrtf(l2));
  } else {
    c->geared.burnout_normal = v3(0.0f, 1.0f, 0.0f);
    c->geared.burnout_phase = BURNOUT_NONE;
  }
  gm_vec3 com = c->solid_com;
  /* BuildBurnoutRadiusSeed */
  const gm_box *wb = &c->def->water_box;
  float zero = 0.0f;
  float zextra = (wb->half.y * zero) + (wb->half.x * zero);
  zextra += wb->half.z;
  gm_vec3 seed = v3(wb->center.x - com.x, wb->center.y - com.y, wb->center.z - com.z + zextra);
  c->geared.burnout_base_radius = tmuf_sqrtf(v3_dot(seed, seed));
  gm_vec3 tangent = v3_scale(v3_cross(c->geared.burnout_normal, lin), c->geared.burnout_direction);
  tangent = normalize_or(tangent, tangent, VEC_EPS2);
  c->geared.burnout_normal = transform_dir(&c->geared.frame_iso, c->geared.burnout_normal);
  if (c->geared.burnout_normal.y < 0.75f) {
    c->geared.burnout_phase = BURNOUT_NONE;
    c->geared.burnout_normal = v3(0.0f, 1.0f, 0.0f);
  }
  float signed_angle = vec_angle(v3(0.0f, 0.0f, 1.0f), tangent) * sign_nn(steer_yaw);
  if (signed_angle > b->angle_limit_positive || signed_angle < -b->angle_limit_negative) {
    c->geared.burnout_phase = BURNOUT_NONE;
  } else {
    gm_vec3 tw = transform_dir(&c->geared.frame_iso, tangent);
    gm_vec3 cw = iso4_mul_point(&c->geared.frame_iso, com);
    float target = tn_m6_burnout_radius(c, lin.z) + c->geared.burnout_base_radius;
    c->geared.burnout_target_radius = target;
    c->geared.burnout_center = v3_add(cw, v3_scale(tw, target));
  }
  c->geared.wheel_speed_override = c->geared.burnout_phase == BURNOUT_CIRCLE ? 1 : 0;
}

static void try_enter_forward_burnout(car *c, gm_vec3 lin, float steer_yaw, float frame_y, uint32_t tick,
                                      int has_ground_material) {
  const tmuf_vt_burnout *b = &c->t->geared_drive.burnout;
  if (c->controls.forced_low_speed_friction || !has_ground_material)
    return;
  if (!(c->controls.gate_a > GATE && c->controls.gate_b > GATE))
    return;
  if (lin.z < b->donut_speed_low && frame_y > 0.75f) {
    c->geared.burnout_phase = BURNOUT_SPIN;
    c->geared.wheel_speed_override = 1;
    c->geared.burnout_start = tick;
  }
  if (lin.z < b->donut_speed_high && lin.z > b->donut_speed_low && !(fabsf(steer_yaw) < SCALAR_EPS))
    enter_circular_burnout(c, lin, steer_yaw);
}

static void try_enter_reverse_burnout(car *c, gm_vec3 lin, float drive, float frame_y, uint32_t tick) {
  if (c->controls.forced_low_speed_friction || !(lin.z < 0.0f) || !(c->controls.gate_a > GATE))
    return;
  if (c->t->geared_drive.burnout.reverse_force_threshold < -drive * c->t->feedback.force_divisor * lin.z &&
      frame_y > 0.75f) {
    c->geared.burnout_start = tick;
    c->geared.burnout_phase = BURNOUT_SPIN;
    c->geared.wheel_speed_override = 1;
  }
}

static void circular_burnout_forces(car *c, force_request *r, int water) {
  const tmuf_vt_burnout *b = &c->t->geared_drive.burnout;
  if (c->geared.burnout_phase != BURNOUT_CIRCLE)
    return;
  float steer_yaw = r->steer_yaw;
  gm_vec3 lin = r->lin;
  if (c->controls.gate_a < GATE || c->controls.gate_b < GATE || fabsf(steer_yaw) < SCALAR_EPS ||
      c->geared.burnout_direction != sign_nn(steer_yaw) || c->contacts.lateral_slowdown_contact ||
      c->contacts.body_contact || !r->has_ground_material || water || c->controls.forced_low_speed_friction) {
    c->geared.burnout_phase = BURNOUT_NONE;
    return;
  }
  gm_vec3 sum = v3(0.0f, 0.0f, 0.0f);
  for (uint32_t i = 0; i < c->wheel_count; i++)
    sum = v3_add(sum, c->wheels[i].normal_sum);
  gm_vec3 avg = normalize_or(sum, v3(0.0f, 1.0f, 0.0f), VEC_EPS2);
  gm_vec3 wn = transform_dir(&c->geared.frame_iso, avg);
  float drift = fabsf(vec_angle(wn, c->geared.burnout_normal));
  if (drift > b->angle_limit) {
    c->geared.burnout_phase = BURNOUT_NONE;
    return;
  }
  gm_vec3 com = c->solid_com;
  gm_iso4 inv = iso4_inverse(&c->geared.frame_iso);
  gm_vec3 local_center = iso4_mul_point(&inv, c->geared.burnout_center);
  gm_vec3 radial = v3_sub(local_center, com);
  float r2 = (radial.y * radial.y + radial.x * radial.x) + radial.z * radial.z;
  float radius = tmuf_sqrtf(r2);
  gm_vec3 rdir = radial;
  if (r2 > VEC_EPS2) {
    float inv_r = 1.0f / radius;
    rdir = v3(radial.x * inv_r, radial.y * inv_r, radial.z * inv_r);
  }
  gm_vec3 tangent = v3_cross(avg, rdir);
  float tspeed = v3_dot(lin, tangent);
  float rspeed = v3_dot(lin, rdir);
  if (fabsf(tspeed) > b->tangent_speed_max)
    c->geared.burnout_phase = BURNOUT_NONE;
  int needs = radius > c->geared.burnout_base_radius || radius < b->radius_min;
  if (!needs) {
    c->geared.burnout_phase = BURNOUT_NONE;
  } else {
    float ex = (radius - c->geared.burnout_target_radius) * b->radius_correction_scale -
               rspeed * b->radius_correction_speed_scale;
    float e = tmuf_expf(ex);
    float t2 = tspeed * tspeed;
    float mag = (t2 / radius) * e;
    car_add_force(c, v3_scale(rdir, mag));
  }
  for (uint32_t i = 0; i < c->wheel_count; i++) {
    car_wheel_add_force(c, &c->wheels[i]);
    c->wheels[i].slipping = 0;
  }
  float lat_speed = tn_m6_lateral_speed_from_radius(c, radius);
  float lat_scale = b->lateral_correction_scale * (-sign_nn(steer_yaw) * lat_speed - tspeed);
  car_add_force(c, v3_scale(tangent, lat_scale));
  float angle = vec_angle(v3(0.0f, 0.0f, 1.0f), rdir);
  float norm = (float)((double)angle / (double)PI_F);
  double signed_angle = (double)c->geared.burnout_direction * (double)norm * (double)PI_F;
  if (!isfinite(norm) || signed_angle < -(double)b->angle_limit_negative ||
      signed_angle > (double)b->angle_limit_positive) {
    c->geared.burnout_phase = BURNOUT_NONE;
  } else {
    float ret = 0.0f, ay = r->ang.y;
    if (norm <= 0.0f) {
      if (!(ay > 0.0f)) {
        float d = norm + 1.0f;
        ret = -b->angle_return_quadratic * ay * (d * d);
      } else {
        ret = -b->angular_damping_linear * ay;
      }
    } else if (!(ay < 0.0f)) {
      float d = norm - 1.0f;
      ret = -b->angle_return_quadratic * ay * (d * d);
    } else {
      ret = -b->angular_damping_linear * ay;
    }
    float tang = tspeed / radius;
    float damp = 0.0f;
    if ((norm <= 0.0f && tang > 0.0f) || (norm > 0.0f && tang < 0.0f))
      damp = -b->tangent_angular_damping * tang;
    float ty = b->angle_torque_scale * norm + ret + damp;
    car_add_torque(c, v3(0.0f, ty, 0.0f));
  }
  car_add_torque(c, v3(0.0f, 0.0f, tn_m6_donut_rollover(c, fabsf(lin.x)) * -sign_nn(lin.x)));
  car_add_torque(c, v3(tn_m6_burnout_rollover(c, lin.z), 0.0f, 0.0f));
}

static int can_apply_dirt_slide(const car *c) { return c->controls.gate_b < GATE || c->controls.gate_b == GATE; }

static void model6_dirt_slide(car *c, force_request *r, m6_state *s) {
  const tmuf_vt_geared_drive *gd = &c->t->geared_drive;
  if (!s->dirt_slide || r->lin.z <= 6.0f)
    return;
  if (c->controls.gate_b > GATE)
    car_add_force(c, v3(-0.1f * r->lin.x, -0.1f * r->lin.y, -0.1f * r->lin.z));
  if (c->controls.forced_low_speed_friction || c->controls.gate_a <= GATE || !can_apply_dirt_slide(c))
    return;
  gm_vec3 u = normalize_or(r->lin, v3(0.0f, 0.0f, 1.0f), VEC_EPS2);
  float aux = fabsf(u.x), az = fabsf(r->lin.z);
  float gate = aux * 20.0f + 1.0f;
  float db = az + 1.0f;
  float denom = db * db;
  float side_denom = gd->dirt_slide_gate_scale * c->controls.gate_a + 1.0f;
  gm_vec3 front, rear;
  front.x = (gd->dirt_slide_side_force_scale * u.x) / side_denom;
  front.y = 0.0f;
  front.z = gd->dirt_slide_forward_gate_scale * c->controls.gate_a * 1.5f * aux * gate *
            gd->dirt_slide_forward_force_scale / denom;
  rear.x = -front.x;
  rear.y = 0.0f;
  rear.z = gd->dirt_slide_forward_gate_scale * c->controls.gate_a * aux * gate * gd->dirt_slide_forward_force_scale /
           denom;
  for (uint32_t i = 0; i < c->wheel_count; i++) {
    car_wheel *w = &c->wheels[i];
    if (!w->slipping)
      continue;
    if (i <= 1)
      car_add_force_at(c, front, w->force_point);
    if (i == 2 || i == 3)
      car_add_force_at(c, rear, w->force_point);
  }
}

static void model6_contact_wheel(car *c, force_request *r, m6_state *s, car_wheel *w, gm_vec3 com) {
  const tmuf_vehicle_tuning *t = c->t;
  const tmuf_vt_geared_drive *gd = &t->geared_drive;
  if (!w->contact || !(gd->lateral_force_scale >= 0.0f))
    return;
  const car_material *m = car_wheel_material(c, w);
  gm_vec3 lever = v3_sub(w->latest_contact_point, com);
  gm_vec3 side_axis = steered_lateral(w, r->steer_yaw);
  gm_vec3 ftf = v3_scale(c->geared.scaled_force, -t->feedback.force_divisor);
  float ftl = tmuf_sqrtf(v3_dot(ftf, ftf));
  if (ftl < gd->current_force_torque_min)
    ftf = v3(0.0f, 0.0f, 0.0f);
  gm_vec3 ft = v3_cross(lever, ftf);
  ft = v3_scale(ft, -1.0f);
  ft.x *= gd->current_torque_x_scale;
  ft.y = 0.0f;
  ft.z *= gd->current_torque_z_scale;
  car_add_torque(c, ft);
  if (c->geared.burnout_phase == BURNOUT_SPIN)
    car_add_torque(c, v3(tn_m6_burnout_rollover(c, r->lin.z), 0.0f, 0.0f));
  float bside = burnout_side_force_fade(c, s->tick);
  float dmod = tn_m6_damper_modulation(c, w->damper_absorb);
  float slip_grip = w->slipping ? gd->slipping_side_friction_scale : 1.0f;
  float low_b_grip = (w->slipping && c->controls.gate_b > GATE) ? gd->low_speed_b_slipping_grip_scale : 1.0f;
  float curve = tn_max_side_friction(c, r->lin.z);
  float max_static = m->w * r->slope_a * curve * slip_grip * low_b_grip * dmod;
  float css = v3_dot(r->lin, side_axis);
  float req = -gd->lateral_force_scale * 0.5f * css * bside;
  if (!(max_static < fabsf(req))) {
    w->slipping = 0;
  } else {
    float cap = sign_nn(req) * max_static;
    req = (1.0f - gd->side_friction_slip_blend) * cap + gd->side_friction_slip_blend * req;
    w->slipping = 1;
    *r->slip_flag = 1;
  }
  gm_vec3 sf = v3_scale(side_axis, req);
  model6_dirt_slide(c, r, s);
  car_add_force(c, sf);
}

static float steer_assist_ramp(const car *c, gm_vec3 lin) {
  float speed = tmuf_sqrtf((lin.x * lin.x + lin.y * lin.y) + lin.z * lin.z);
  if (speed < 0.7f)
    return 0.0f;
  if (speed > c->t->steering.assist_full_speed)
    return 1.0f;
  return tmuf_sinf((speed / c->t->steering.assist_full_speed) * HALF_PI_F);
}

typedef struct side_result {
  float force, limit, requested;
  int slipped;
} side_result;

static side_result geared_wheel_side_force(car *c, car_wheel *w, force_request *r, float ramp) {
  const tmuf_vt_geared_drive *gd = &c->t->geared_drive;
  side_result res = {0};
  float half = (w->front ? c->geared.wheel_span : -c->geared.wheel_span) * 0.5f;
  float wss = r->lin.x + r->ang.y * half;
  float max_static = tn_max_side_friction(c, r->lin.z) * r->mat[3];
  float req = -gd->lateral_force_scale * 0.5f * wss;
  if (fabsf(req) > max_static) {
    float mag = (1.0f - gd->drive_side_friction_slip_blend) * max_static + gd->drive_side_friction_slip_blend * fabsf(req);
    res.limit = max_static;
    res.requested = fabsf(req);
    req = sign_nn(req) * mag;
    res.slipped = 1;
  }
  float torque = gd->side_force_to_drive_torque_scale * req;
  if (w->front) {
    float st = tn_steer_drive_torque(c, r->lin.z);
    float assist = ramp * c->controls.current_steering * st;
    if (c->engine.use_gate_b)
      assist = -assist;
    if (w->slipping)
      assist = assist * gd->slipping_steer_torque_scale;
    torque = torque - assist;
  }
  car_add_torque(c, v3(0.0f, torque * half, 0.0f));
  res.force = req;
  return res;
}

static void update_slip_memory(car *c, uint32_t tick, int seen) {
  if (!seen)
    return;
  c->slip.last_tick = tick;
  if (!c->slip.active)
    c->slip.start_tick = tick;
  c->slip.elapsed = tick - c->slip.start_tick;
}

static float slipping_wheel_drive_scale(const car *c) {
  float p = 1.0f;
  for (uint32_t i = 0; i < c->wheel_count; i++)
    if (c->wheels[i].slipping)
      p *= c->t->geared_drive.per_slipping_wheel_accel_scale;
  return p;
}

static float opposing_longitudinal(car *c, force_request *r, float drive, float frame_y, uint32_t tick, int slip_flag,
                                   int *slipped) {
  const tmuf_vt_geared_drive *gd = &c->t->geared_drive;
  float opp = 0.0f;
  if (r->lin.z > 0.0f) {
    float pen = slipping_wheel_drive_scale(c);
    opp = (gd->forward_accel_base + gd->forward_accel_speed_coef * r->lin.z) * c->controls.gate_b * pen;
    float cap = r->mat[2] * (slip_flag ? gd->forward_accel_cap_when_slipping : gd->forward_accel_cap);
    if (cap < opp) {
      opp = cap;
      mark_all_wheels_slipping(c);
      *slipped = 1;
    }
  } else if (r->lin.z < 0.0f && c->controls.gate_a > GATE) {
    try_enter_reverse_burnout(c, r->lin, drive, frame_y, tick);
    float pen = slipping_wheel_drive_scale(c);
    opp = (gd->forward_accel_base - gd->forward_accel_speed_coef * r->lin.z) * c->controls.gate_a * pen;
    float cap =
        r->mat[2] * (slip_flag ? gd->forward_accel_cap_when_slipping_reverse : gd->forward_accel_cap_reverse);
    if (cap < opp) {
      opp = cap;
      mark_all_wheels_slipping(c);
      *slipped = 1;
    }
  }
  return opp;
}

static float geared_drive_force(car *c, force_request *r, uint32_t tick, int water, float mix) {
  const tmuf_vehicle_tuning *t = c->t;
  float slipping_curve = tn_m5_slipping_accel(c, r->lin.z);
  float gear_curve = c->engine.use_gate_b ? tn_m6_rear_gear_accel(c, r->lin.z) : tn_m5_accel(c, r->lin.z);
  float blended = c->geared.engine_state == ENGINE_GEAR_SHIFT ? 0.0f : (1.0f - mix) * slipping_curve + gear_curve * mix;
  float turbo = c->turbo.type != TURBO_NONE ? gear_curve * c->turbo.impulse_scale : 0.0f;
  float rev = c->engine.use_gate_b ? -1.0f : 0.0f;
  float slowdown = t->steering.slow_down_scale * fabsf(c->controls.current_steering) * tn_m5_steer_slowdown(c, r->lin.z) *
                   (c->engine.use_gate_b ? -1.0f : 1.0f);
  float drive = burnout_exit_acceleration(c, tick) +
                burnout_drive_fade(c, tick) *
                    (turbo + (c->controls.gate_a * r->mat[1] + rev * r->mat[1] * c->controls.gate_b) * blended) -
                slowdown;
  if (water)
    drive *= 0.5f;
  if (c->controls.forced_low_speed_friction)
    drive = c->turbo.type != TURBO_NONE ? gear_curve * c->turbo.impulse_scale : 0.0f;
  return drive;
}

static void model6_ground_forces(car *c, force_request *r, m6_state *s) {
  const tmuf_vehicle_tuning *t = c->t;
  const tmuf_vt_geared_drive *gd = &t->geared_drive;
  if (!c->controls.forced_low_speed_friction && c->controls.gate_b > GATE && c->controls.gate_a < GATE &&
      c->geared.burnout_phase == BURNOUT_SPIN) {
    c->geared.burnout_exit_start = s->tick;
    c->geared.burnout_phase = BURNOUT_EXIT;
  }
  try_enter_forward_burnout(c, r->lin, r->steer_yaw, s->frame_y, s->tick, r->has_ground_material);
  update_gear_direction(c, r->lin);
  float roll_in = (r->lin.x * r->lin.x) / (fabsf(r->lin.z) + 1.0f);
  car_add_torque(c, v3(0.0f, 0.0f, -sign_nn(r->lin.x) * tn_m6_rollover_lateral_ratio(c, roll_in)));
  float ramp = steer_assist_ramp(c, r->lin);
  for (uint32_t i = 0; i < s->wheel_count; i++) {
    side_result wf = geared_wheel_side_force(c, &c->wheels[i], r, ramp);
    s->side_limit_total += wf.limit;
    s->side_requested_total += wf.requested;
    s->slip_seen |= wf.slipped;
  }
  update_slip_memory(c, s->tick, s->slip_seen);
  float mix = slip_acceleration_blend(c, s->tick, s->side_limit_total, s->side_requested_total);
  float drive = geared_drive_force(c, r, s->tick, s->water, mix);
  int slipped = 0;
  float opp = opposing_longitudinal(c, r, drive, s->frame_y, s->tick, *r->slip_flag, &slipped);
  s->slip_seen |= slipped;
  *r->surface_feedback = opp;
  float net = drive - sign_nn(r->lin.z) * opp;
  if (r->lin.z > t->engine_speed_norm * r->mat[0])
    net = !(net < 0.0f) ? -gd->speed_limit_force : net - gd->speed_limit_force;
  if (r->lin.z < -gd->transmission.reverse_speed_norm * r->mat[0])
    net = !(net > 0.0f) ? gd->speed_limit_force : net + gd->speed_limit_force;
  car_add_force(c, v3(0.0f, 0.0f, net * r->slope_b));
  car_add_force(c, v3(0.0f, 0.0f, (-gd->force_z_scale * r->current_force.z) / t->body_air_response.grounded_solid_feedback1));
  c->slip.active = s->slip_seen != 0;
  c->geared.local_speed = r->lin;
}

static void model6(car *c, force_request *r) {
  /* CaptureBurnoutReferenceFrame: corpus GetLocation (write state) */
  c->geared.frame_iso.r = c->body->write.rot;
  c->geared.frame_iso.t = c->body->write.pos;
  m6_state s = {0};
  s.frame_y = c->geared.frame_iso.r.m[1][1];
  s.water = car_apply_water_forces(c, r->current_force);
  c->frame.in_water = s.water;
  c->controls.no_ground_friction_guard = s.water != 0;
  s.dirt_slide = all_wheels_material(c, MAT_DIRT);
  if (c->geared.burnout_phase == BURNOUT_CIRCLE) {
    circular_burnout_forces(c, r, s.water);
    if (c->geared.burnout_phase != BURNOUT_CIRCLE) {
      c->geared.burnout_phase = BURNOUT_SPIN;
      c->geared.burnout_start = c->tick;
    }
    c->geared.local_speed = r->lin;
    return;
  }
  s.tick = c->tick;
  s.slip_seen = advance_burnout_phases(c, s.tick);
  gm_vec3 com = c->solid_com;
  s.wheel_count = c->wheel_count;
  for (uint32_t i = 0; i < s.wheel_count; i++) {
    car_wheel_add_force(c, &c->wheels[i]);
    model6_contact_wheel(c, r, &s, &c->wheels[i], com);
  }
  if (!r->has_ground_material) {
    if (c->geared.burnout_phase == BURNOUT_SPIN) {
      c->geared.burnout_exit_start = s.tick;
      c->geared.burnout_phase = BURNOUT_EXIT;
    }
    c->slip.active = s.slip_seen != 0;
    c->geared.local_speed = r->lin;
    return;
  }
  model6_ground_forces(c, r, &s);
}

void car_compute_selected_handling(car *c, float dt, gm_vec3 current_force, float slope_a, float slope_b, gm_vec3 lin,
                                   gm_vec3 ang, float steer_yaw, int has_ground_material, const float mat_vals[4],
                                   int *slip_flag, float *surface_feedback) {
  force_request r;
  r.dt = dt;
  r.current_force = current_force;
  r.slope_a = slope_a;
  r.slope_b = slope_b;
  r.lin = lin;
  r.ang = ang;
  r.steer_yaw = steer_yaw;
  r.has_ground_material = has_ground_material != 0;
  for (int i = 0; i < 4; i++)
    r.mat[i] = mat_vals[i];
  r.slip_flag = slip_flag;
  r.surface_feedback = surface_feedback;
  switch (c->t->handling_model) {
  case HANDLING_RADIUS:
    model4(c, &r);
    break;
  case HANDLING_SLIP:
    model5(c, &r);
    break;
  case HANDLING_GEARED:
    model6(c, &r);
    break;
  default:
    model3(c, &r);
    break;
  }
}
