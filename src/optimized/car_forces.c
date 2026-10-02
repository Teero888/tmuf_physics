/* CSceneVehicleCar: the per-substep force pipeline (ComputeForces), engine
   and wheel integration, friction, air control and feedback. */

#include "optimized/car_util.h"

#define FEEDBACK_RAMP_CONTACT 6u
#define TURBO_A_CONTACT 7u
#define TURBO_B_CONTACT 0x1au
#define TURBO_ROULETTE_CONTACT 0x1eu
#define FREE_WHEELING_CONTACT 0x1du

/* ---- engine (scene_vehicle_car_powertrain) ---- */

static int all_wheels_airborne(const car *c) { return !car_is_ground_contact(c); }

static void clamp_engine_input(car *c) {
  float mem = c->engine.input_memory, mx = c->engine.input_max, r = 0.0f;
  if (!(mem <= 0.0f)) {
    r = mem;
    if (!(mx > mem))
      r = mx;
  }
  c->engine.input_memory = r;
}

static float gear_ratio(const car *c, int g) { return c->t->geared_drive.transmission.gear_speed_ratio[(uint32_t)g]; }
static float upshift(const car *c, int g) { return c->t->geared_drive.transmission.upshift_threshold[(uint32_t)g]; }
static float downshift(const car *c, int g) { return c->t->geared_drive.transmission.downshift_threshold[(uint32_t)g]; }
static float target_bias(const car *c, int g) { return c->t->geared_drive.transmission.target_input_bias[(uint32_t)g]; }

static float transmission_weighted_speed(const car *c) {
  gm_vec3 s = c->geared.local_speed;
  float sq = (s.z * s.z + 0.3f * s.x * s.x) + 0.1f * s.y * s.y;
  return tmuf_sqrtf(sq);
}

static void integrate_legacy_engine(car *c, float input, float dt, int blocked) {
  input = fabsf(input);
  int ready = !blocked && !(0.0f < c->engine.shift_cooldown);
  int stored = c->engine.gear;
  int ri = stored < 2 ? 0 : stored - 1;
  float speed = transmission_weighted_speed(c);
  float target = (speed / (c->t->engine_speed_norm * 0.2f)) * gear_ratio(c, ri);
  if (ready) {
    input = target;
    if (!c->engine.use_gate_b) {
      if (stored == 0) {
        c->engine.gear = 1;
        c->engine.shift_cooldown = 0.04f;
      } else if (upshift(c, ri) < target && stored < 5) {
        c->engine.gear = stored + 1;
        c->engine.shift_cooldown = 0.04f;
      } else if (target < downshift(c, ri) && stored > 1) {
        c->engine.gear = stored - 1;
        c->engine.shift_cooldown = 0.04f;
      }
    } else if (stored != 0) {
      c->engine.gear = 0;
      c->engine.shift_cooldown = 0.04f;
    }
  } else if (!(c->engine.shift_cooldown < 0.0f) && !(dt + dt < c->engine.shift_cooldown)) {
    c->engine.input_memory -= c->engine.input_max * dt * 1.9f;
  }
  float rate = ready ? 12.0f : 3.5f;
  c->engine.input_memory += (c->engine.input_max * input - c->engine.input_memory) * dt * rate;
}

static void directional_transition_input(car *c, float dt, int active, int state) {
  const tmuf_vt_engine_input *in = &c->t->geared_drive.input;
  int index = state == ENGINE_FORWARD ? 1 : 0;
  float sz = c->geared.local_speed.z;
  int outside;
  if (state == ENGINE_FORWARD)
    outside = in->forward_transition_speed_high < sz || sz < in->forward_transition_speed_low;
  else
    outside = sz < in->reverse_transition_speed_low || in->reverse_transition_speed_high < sz;
  c->geared.input_window_exceeded = outside != 0;
  c->engine.slip_rpm_scale = 1.0f;
  float asz = fabsf(sz);
  c->engine.target_input = asz * gear_ratio(c, index) + target_bias(c, index) * 0.0f;
  if (outside || !active) {
    float next = c->engine.input_memory - in->ground_input_fall * dt;
    c->engine.input_memory = next;
    if (next <= c->engine.target_input) {
      c->engine.input_memory = c->engine.target_input;
      c->geared.engine_state = ENGINE_STEADY;
      c->geared.input_window_exceeded = 0;
    }
  } else {
    c->engine.input_memory = in->transition_input_rise * dt + c->engine.input_memory;
  }
}

static void transmission_transitions(car *c, int active, int burnout) {
  const tmuf_vt_engine_input *in = &c->t->geared_drive.input;
  float sz = c->geared.local_speed.z;
  if (in->forward_transition_speed_low < sz && sz < in->forward_transition_speed_high && active &&
      !c->engine.use_gate_b && c->geared.engine_state == ENGINE_STEADY) {
    c->geared.engine_state = ENGINE_FORWARD;
    c->geared.input_window_exceeded = 0;
    if (c->engine.gear == 0) {
      c->engine.shift_cooldown = 0.025f;
      c->engine.gear = 1;
    }
  } else if (in->reverse_transition_speed_low < sz && sz < in->reverse_transition_speed_high && active &&
             c->engine.use_gate_b && c->geared.engine_state == ENGINE_STEADY) {
    c->geared.engine_state = ENGINE_REVERSE;
    c->geared.input_window_exceeded = 0;
    if (c->engine.gear != 0) {
      c->engine.gear = 0;
      c->engine.shift_cooldown = 0.025f;
    }
  }
  if (c->geared.engine_state != ENGINE_STEADY && c->geared.engine_state != ENGINE_GEAR_SHIFT)
    return;
  if (!c->engine.use_gate_b) {
    if (c->engine.gear == 0) {
      c->geared.engine_state = ENGINE_GEAR_SHIFT;
      c->geared.shift_down = 0;
      if (c->engine.input_memory < 1000.0f) {
        c->engine.shift_cooldown = 0.025f;
        c->engine.gear = 1;
      }
    }
    int g = c->engine.gear;
    if (g > 0) {
      float up = upshift(c, g) * c->engine.input_max;
      if (up < c->engine.target_input && g < 5) {
        c->engine.shift_cooldown = 0.025f;
        c->engine.gear = g + 1;
        c->geared.engine_state = ENGINE_GEAR_SHIFT;
        c->geared.shift_down = 0;
        return;
      }
      float down = downshift(c, g) * c->engine.input_max;
      if (c->engine.target_input < down && g > 1) {
        c->engine.shift_cooldown = 0.025f;
        c->engine.gear = g - 1;
        c->geared.engine_state = ENGINE_GEAR_SHIFT;
        c->geared.shift_down = 1;
      }
    }
  } else if (c->engine.gear != 0) {
    c->geared.engine_state = ENGINE_GEAR_SHIFT;
    c->geared.shift_down = 1;
    if (c->engine.input_memory < 1000.0f) {
      c->engine.gear = 0;
      c->engine.shift_cooldown = burnout ? 0.002f : 0.025f;
    }
  }
}

static void integrate_geared_engine(car *c, float dt, int active, int blocked) {
  const tmuf_vt_engine_input *in = &c->t->geared_drive.input;
  if (blocked) {
    if (active)
      c->engine.input_memory = in->airborne_input_rise * dt + c->engine.input_memory;
    else
      c->engine.input_memory = c->engine.input_memory - in->airborne_input_fall * dt;
    return;
  }
  int burnout = c->geared.burnout_phase == BURNOUT_SPIN || c->geared.burnout_phase == BURNOUT_CIRCLE;
  if (burnout && c->engine.gear != 0)
    c->geared.engine_state = ENGINE_BURNOUT;
  else if (c->geared.engine_state == ENGINE_BURNOUT)
    c->geared.engine_state = ENGINE_STEADY;

  switch (c->geared.engine_state) {
  case ENGINE_FORWARD:
  case ENGINE_REVERSE:
    directional_transition_input(c, dt, active, c->geared.engine_state);
    break;
  case ENGINE_BURNOUT:
    c->engine.target_input = c->engine.input_max;
    c->engine.slip_rpm_scale = 1.15f;
    if (c->engine.input_memory < c->engine.input_max)
      c->engine.input_memory = in->burnout_hold_input_rise * dt + c->engine.input_memory;
    else if (c->engine.input_max < c->engine.input_memory)
      c->engine.input_memory = in->airborne_input_fall * dt + c->engine.input_memory;
    break;
  default: {
    if (c->slip.active && active) {
      if (c->engine.slip_rpm_scale < 1.15f)
        c->engine.slip_rpm_scale = (1.15f - c->engine.slip_rpm_scale) * 0.3f * dt + c->engine.slip_rpm_scale;
      else
        c->engine.slip_rpm_scale = 1.15f;
    } else {
      c->engine.slip_rpm_scale = 1.0f;
    }
    int g = c->engine.gear;
    float slip_speed = c->geared.local_speed.z * c->engine.slip_rpm_scale;
    c->engine.target_input = fabsf(slip_speed) * gear_ratio(c, g);
    if ((!c->engine.use_gate_b && g == 0) || (c->engine.use_gate_b && g != 0))
      c->engine.target_input = 0.0f;
    if (!(c->engine.input_memory < c->engine.target_input)) {
      float fall;
      if (active)
        fall = (!c->slip.active || burnout) ? in->ground_input_brake : in->airborne_input_fall;
      else
        fall = in->ground_input_fall;
      float next = c->engine.input_memory - fall * dt;
      c->engine.input_memory = next;
      if (next < c->engine.target_input)
        c->geared.engine_state = ENGINE_STEADY;
    } else {
      float next = in->ground_input_rise * dt + c->engine.input_memory;
      c->engine.input_memory = next;
      if (c->engine.target_input < next)
        c->geared.engine_state = ENGINE_STEADY;
    }
    break;
  }
  }
  transmission_transitions(c, active, burnout);
}

static void engine_integrate(car *c, float input, float dt) {
  int active = input > 0.1f;
  int airborne = all_wheels_airborne(c);
  if (0.0f < c->engine.shift_cooldown)
    c->engine.shift_cooldown = c->engine.shift_cooldown - dt;
  int blocked = airborne || (0.0f < c->engine.shift_cooldown);
  if (c->t->handling_model != HANDLING_GEARED)
    integrate_legacy_engine(c, input, dt, blocked);
  else
    integrate_geared_engine(c, dt, active, blocked);
  clamp_engine_input(c);
}

/* ---- wheels ---- */

static void wheel_update_speed(car *c, car_wheel *w, float fwd, float dt) {
  if (w->contact) {
    if (c->geared.wheel_speed_override && !c->geared.drive_speed_inhibited) {
      w->angular_speed = c->t->geared_drive.burnout.wheel_angular_speed_override;
      return;
    }
    w->angular_speed = fwd / w->rolling_radius;
    return;
  }
  float target = 0.0f, accel = 0.0f;
  if (c->controls.gate_b > SCALAR_EPS) {
    target = 1.0f - c->controls.gate_b;
    if (target <= 0.0f)
      target = 0.0f;
    else if (target >= 1.0f)
      target = 1.0f;
    accel = -100.0f;
  } else if (c->controls.gate_a > SCALAR_EPS && !c->geared.drive_speed_inhibited &&
             !c->controls.forced_low_speed_friction) {
    target = tmuf_mul_fd(c->controls.gate_a, 200.0);
    accel = 100.0f;
  } else {
    w->angular_speed = tmuf_mul_fd(w->angular_speed, (double)0.995f);
  }
  if (!(fabsf(accel) < SCALAR_EPS)) {
    float next = accel * dt + w->angular_speed;
    w->angular_speed = next;
    if (accel > 0.0f && next > target)
      w->angular_speed = target;
    else if (accel < 0.0f && next < target)
      w->angular_speed = target;
  }
}

/* GmFunc::Mod(value, min, max) */
static float gm_mod(float v, float lo, float hi) {
  if (lo < v && v < hi)
    return v;
  float period = hi - lo;
  float w = fmodf(v - lo, period);
  if (w < 0.0f)
    w += period;
  return w + lo;
}

static void wheel_state_integrate(car_wheel *w, float dt) {
  float spin = w->angular_speed * dt + w->spin_angle;
  w->spin_angle = gm_mod(spin, 0.0f, WHEEL_SPIN_PERIOD);
  float l2 = len2_yxz(w->normal_sum);
  if (l2 > VEC_EPS2) {
    float inv = 1.0f / tmuf_sqrtf(l2);
    w->normal_sum.x = w->normal_sum.x * inv;
    w->normal_sum.y = w->normal_sum.y * inv;
    w->normal_sum.z = inv * w->normal_sum.z;
  }
  float cur = w->steer_angle, target = w->steer_target;
  if (target > cur) {
    float next = cur + dt;
    w->steer_angle = next > target ? target : next;
  } else {
    float next = cur - dt;
    w->steer_angle = target > next ? target : next;
  }
}

static void wheel_visual_state(car *c, car_wheel *w, float fwd, float dt) {
  float steer = 0.0f;
  if (w->front) {
    float max_deg = 30.0f;
    if (c->t->curves.wheel_visual_steer_angle_from_speed.present)
      max_deg = tmuf_curve_eval(&c->t->curves.wheel_visual_steer_angle_from_speed, fabsf(fwd) * KMH);
    float max_rad = (max_deg * PI_F) / 180.0f;
    steer = -c->controls.current_steering * max_rad;
  }
  w->steer_target = steer;
  wheel_update_speed(c, w, fwd, dt);
  wheel_state_integrate(w, dt);
}

static void wheel_integrate(car *c, car_wheel *w, float dt) {
  const tmuf_vt_suspension *su = &c->t->suspension;
  switch (c->t->wheel_force_mode) {
  case WHEEL_FORCE_SPRING: {
    w->damper_absorb = w->damper_absorb - w->max_replacement_y;
    w->max_replacement_y = 0.0f;
    w->cur_iso = w->rest_iso;
    float a = (su->wheel_rest_damper_absorb - w->damper_absorb) * su->wheel_spring_coef -
              su->wheel_damper_coef * w->damper_velocity;
    w->damper_velocity = a * dt + w->damper_velocity;
    w->damper_absorb = dt * w->damper_velocity + w->damper_absorb;
    w->cur_iso.t.y += -w->damper_absorb;
    break;
  }
  case WHEEL_FORCE_FOLLOW:
  case WHEEL_FORCE_FOLLOW_IMPULSE: {
    float base = w->damper_absorb - w->max_replacement_y;
    w->cur_iso = w->rest_iso;
    float disp = su->wheel_rest_damper_absorb - base;
    float target = disp * dt * su->wheel_absorb_follow_coef + base;
    w->damper_velocity = (target - w->damper_absorb) / dt;
    w->damper_absorb = target;
    w->max_replacement_y = 0.0f;
    w->cur_iso.t.y += -target;
    break;
  }
  default:
    break;
  }
  if (w->tree)
    w->tree->local = w->cur_iso;
}

static void update_current_steering(car *c, float dt) {
  float rate = c->t->steering.slew_rate;
  if (rate <= 0.0f) {
    c->controls.current_steering = c->controls.steering;
    return;
  }
  float dir = -1.0f;
  if (c->controls.current_steering - c->controls.steering < 0.0f)
    dir = 1.0f;
  float cand = rate * dir * dt + c->controls.current_steering;
  float next = cand;
  if (c->controls.steering <= c->controls.current_steering) {
    if (c->controls.steering > cand)
      next = c->controls.steering;
  } else if (c->controls.steering < cand) {
    next = c->controls.steering;
  }
  c->controls.current_steering = next;
}

void car_integrate_vehicle(car *c, float dt) {
  gm_vec3 lin = body_lin_local(c);
  float fwd = lin.z;
  if (c->integration.update_wheel_visuals)
    for (uint32_t i = 0; i < c->wheel_count; i++)
      wheel_visual_state(c, &c->wheels[i], fwd, dt);
  if (c->integration.integrate_wheels)
    for (uint32_t i = 0; i < c->wheel_count; i++)
      wheel_integrate(c, &c->wheels[i], dt);
  if (c->integration.integrate_engine) {
    if (!c->controls.forced_low_speed_friction) {
      float input = !c->engine.use_gate_b ? c->controls.gate_a : c->controls.gate_b;
      engine_integrate(c, input, dt);
    } else {
      c->engine.input_memory = 0.0f;
    }
  }
  update_current_steering(c, dt);
  if (c->def->root)
    ref_mtree_update_box(c->def->root); /* RefreshCollisionTree */
}

/* ---- ComputeForces helpers (scene_vehicle_car_feedback) ---- */

static void compute_ground_material_vals(const car *c, float out[4], int *has) {
  *has = 0;
  out[0] = out[1] = out[2] = out[3] = 0.0f;
  uint32_t n = 0;
  for (uint32_t i = 0; i < c->wheel_count; i++) {
    if (!c->wheels[i].contact)
      continue;
    const car_material *m = car_wheel_material(c, &c->wheels[0]); /* the game reads wheel 0 */
    n++;
    out[0] += m->x;
    out[1] += m->y;
    out[2] += m->z;
    out[3] += m->w;
    *has = 1;
  }
  if (n) {
    float inv = 1.0f / (float)n;
    out[0] *= inv;
    out[1] *= inv;
    out[2] *= inv;
    out[3] *= inv;
  }
}

static float slope_blend(float slope, float mn, float mx) {
  if (!(mn <= slope))
    return 0.0f;
  if (!(mx >= slope))
    return 1.0f;
  float angle = tmuf_mul_fd(tmuf_mul_fd((slope - mn) / (mx - mn), (double)PI_F), 0.5);
  return 1.0f - tmuf_cosf(angle);
}

static void get_slope_adherence(const car *c, gm_vec3 n, float *a, float *b) {
  float l2 = (n.y * n.y + n.x * n.x) + n.z * n.z;
  if (!(1.0e-10f < l2))
    return;
  float len = tmuf_sqrtf(l2);
  float slope = fabsf(n.y / len);
  const tmuf_vt_body_air_response *br = &c->t->body_air_response;
  *a = slope_blend(slope, br->slope_adherence1_min, br->slope_adherence1_max);
  *b = slope_blend(slope, br->slope_adherence2_min, br->slope_adherence2_max);
}

static void apply_friction_forces(car *c, gm_vec3 speed) {
  const tmuf_vehicle_tuning *t = c->t;
  if ((t->handling_model == HANDLING_SLIP || t->handling_model == HANDLING_GEARED) &&
      c->controls.no_ground_friction_guard && !car_is_ground_contact(c))
    return;
  float gate = !c->engine.use_gate_b ? c->controls.gate_a : c->controls.gate_b;
  if (gate < 1.0e-5f || c->controls.forced_low_speed_friction) {
    gm_vec3 f = speed;
    float l2 = len2_yxz(f);
    if (1.0e-10f < l2) {
      float inv = 1.0f / tmuf_sqrtf(l2);
      f.x = inv * f.x;
      f.y = f.y * inv;
      f.z = inv * f.z;
      float k = -t->low_speed_friction_magnitude;
      f.x = k * f.x;
      f.y = f.y * k;
      f.z = k * f.z;
      if (!c->controls.forced_low_speed_friction) {
        float d = -t->low_speed_linear_damping;
        gm_vec3 dmp = v3(speed.x * d, speed.y * d, d * speed.z);
        f.x = dmp.x + f.x;
        f.y = dmp.y + f.y;
        f.z = dmp.z + f.z;
      }
      car_add_force(c, f);
    }
  }
  if ((int32_t)t->handling_model < HANDLING_SLIP) {
    if (c->contacts.lateral_slowdown_contact) {
      float k = -tn_lateral_contact_slowdown(c, speed.z);
      car_add_force(c, v3(speed.x * k, speed.y * k, k * speed.z));
    }
    return;
  }
  uint32_t tick = c->tick;
  if (c->contacts.lateral_slowdown_contact)
    c->contacts.lateral_slowdown_tick = tick;
  if (c->contacts.lateral_slowdown_tick <= tick) {
    uint32_t elapsed = tick - c->contacts.lateral_slowdown_tick;
    if (elapsed < t->slip_response.lateral_slow_down_tick_window) {
      float len = tmuf_sqrtf(len2_yxz(speed));
      if (1.0e-5f < len) {
        float inv = 1.0f / len;
        gm_vec3 u = v3(speed.x * inv, speed.y * inv, inv * speed.z);
        float k = -tn_m5_lateral_contact_slowdown(c, len);
        car_add_force(c, v3(k * u.x, u.y * k, k * u.z));
      }
    }
  }
}

static void compute_air_control(car *c, gm_vec3 ang, uint32_t tick, int ground, int reset) {
  const tmuf_vehicle_tuning *t = c->t;
  const tmuf_vt_body_air_response *br = &t->body_air_response;
  if ((t->handling_model == HANDLING_SLIP || t->handling_model == HANDLING_GEARED) &&
      c->controls.no_ground_friction_guard)
    return;
  gm_vec3 torque = v3(-ang.x, -ang.y, -ang.z);
  if (reset)
    c->air.memory_tick = tick;
  if (reset || c->air.refresh_memory) {
    c->air.memory_angular = ang;
  } else if ((uint32_t)(tick - c->air.memory_tick) < br->air_control_memory_tick_window) {
    gm_vec3 target = ang;
    int strong = 0;
    float steer = c->controls.steering;
    if ((1.0e-5f < steer && c->air.memory_angular.y < 0.0f) || (steer < -1.0e-5f && 0.0f < c->air.memory_angular.y)) {
      if (br->air_control_y_switch_threshold < fabsf(ang.y)) {
        strong = 1;
        c->air.memory_angular.y = ang.y;
      }
    } else {
      if (!(1.0e-5f < steer) || !(0.0f < c->air.memory_angular.y)) {
        if (steer < -1.0e-5f && c->air.memory_angular.y < 0.0f)
          strong = 1;
      } else {
        strong = 1;
      }
      c->air.memory_angular.y = ang.y;
    }
    target.y = c->air.memory_angular.y;
    if (t->handling_model == HANDLING_SLIP || t->handling_model == HANDLING_GEARED) {
      float tx = (1.0e-5f < c->controls.gate_b && 0.0f < c->air.memory_angular.x) ? 0.0f : ang.x;
      c->air.memory_angular.x = tx;
      target.x = c->air.memory_angular.x;
    }
    if (strong) {
      torque.x = torque.x * 3.0f;
      torque.y = torque.y * 3.0f;
      torque.z = 3.0f * torque.z;
    }
    if (!ground) {
      float zs = tmuf_curve_eval(&t->curves.air_control_z_scale, fabsf(ang.z));
      torque.z = torque.z * zs;
    }
    body_set_ang_local(c, target);
  }
  if (!ground) {
    float xy = torque.x * torque.x + torque.y * torque.y;
    float l2 = torque.z * torque.z + xy;
    float len = tmuf_sqrtf(l2);
    if (len >= 1.0e-5f) {
      float inv = 1.0f / len;
      gm_vec3 u = v3(inv * torque.x, inv * torque.y, inv * torque.z);
      float quad = br->air_torque_quadratic_coef * len;
      quad *= len;
      float lin = len * br->air_torque_linear_coef;
      float mag = quad + lin;
      car_add_torque(c, v3(mag * u.x, u.y * mag, mag * u.z));
    }
  }
}

/* CSceneVehicleCar::ApplyWaterSplashImpulse (speed: the world speed the
   caller calls local) */
static void water_splash_impulse(car *c, gm_vec3 speed, float input) {
  float v = tmuf_curve_eval(&c->t->curves.splash_vertical_impulse, input);
  float h = tmuf_curve_eval(&c->t->curves.splash_horizontal_impulse, input);
  gm_vec3 imp = v3(-h * speed.x, -v * speed.y, -h * speed.z);
  imp = mat3_tmul_vec(&c->body->state.rot, imp);
  /* CSceneVehicle::WaterSplash */
  c->water_splash_events++;
  c->water_splash_speed = speed;
  car_add_impulse(c, imp);
}

/* CSceneVehicleCar::ApplyWaterForces */
int car_apply_water_forces(car *c, gm_vec3 force_to_subtract) {
  const tmuf_scene_water *wz = c->water;
  if (!wz || !wz->enabled)
    return 0;
  const dyna_state *st = &c->body->state;
  gm_iso4 iso = {st->rot, st->pos};
  gm_box wb = box_transform(&c->def->water_box, &iso);
  float half_y = fabsf(wb.half.y);
  float lower = wb.center.y - half_y, upper = wb.center.y + half_y;
  if (!tmuf_water_accepts(wz, wb.center.x, wb.center.z, lower, upper))
    return 0;
  float depth = wz->surface_height - lower;
  if (!(depth > 0.5f))
    return 0;
  const tmuf_vt_water *tw = &c->t->water;
  gm_vec3 lin = body_lin_local(c);          /* GetLinearSpeed: local */
  gm_vec3 speed = mat3_mul_vec(&st->rot, lin); /* back to world */
  float h2 = speed.x * speed.x + speed.z * speed.z;
  if (!c->air.refresh_memory && depth < 0.9f && (wz->surface_height - upper) < 0.0f && speed.y < -1.0e-5f) {
    float ht = tw->splash_horizontal_speed_threshold;
    if (h2 > ht * ht) {
      float hs = tmuf_sqrtf(h2);
      float input = -hs / speed.y;
      if (input != input)
        return 0;
      if (!(input < 0.0f)) {
        water_splash_impulse(c, speed, input);
        return 0;
      }
    } else {
      float tt = tw->splash_total_speed_threshold;
      if (v3_len2(lin) > tt * tt) {
        water_splash_impulse(c, speed, 0.0f);
        return 0;
      }
    }
  }
  gm_vec3 drag = v3(0.0f, 0.0f, 0.0f);
  float slen = tmuf_sqrtf(v3_len2(lin));
  if (1.0e-5f < slen)
    drag = v3_scale(lin, -tn_water_friction(c, slen));
  gm_vec3 ang = body_ang_local(c);
  gm_vec3 torque = v3_scale(ang, -tw->angular_linear_damping);
  float alen = tmuf_sqrtf(v3_len2(ang));
  torque = v3_add(torque, v3_scale(ang, -alen * tw->angular_speed_damping));
  gm_vec3 buoyancy = mat3_tmul_vec(&st->rot, v3(0.0f, -tw->buoyancy_force, 0.0f));
  gm_vec3 central = v3_sub(v3_add(buoyancy, drag), force_to_subtract);
  car_add_force(c, central);
  car_add_torque(c, torque);
  return 1;
}

static void clamp_linear_speed(car *c, gm_vec3 *lin) {
  float cap = c->linear_speed_cap;
  float cap2 = cap * cap;
  float xy = lin->y * lin->y + lin->x * lin->x;
  float s2 = lin->z * lin->z + xy;
  if (cap2 < s2 && cap2 > VEC_EPS2) {
    float len = tmuf_sqrtf(s2);
    float k = cap / len;
    lin->x = k * lin->x;
    lin->y = lin->y * k;
    lin->z = k * lin->z;
    body_set_lin_local(c, *lin);
  }
}

static float visual_steer_yaw(const car *c, gm_vec3 lin) {
  float denom = fabsf(lin.z) * c->t->visual.wheel_speed_scale + c->t->visual.wheel_speed_base;
  float a = 0.0f;
  if (!(denom < SCALAR_EPS))
    a = asin_safe(1.0f / denom);
  return (-c->controls.current_steering) * a;
}

static int impact_severity(float bucket, float lo, float hi, int cur) {
  if (!(lo < bucket))
    return cur;
  if (hi < bucket)
    return cur < IMPACT_HIGH ? IMPACT_HIGH : cur;
  return cur == IMPACT_NONE ? IMPACT_LOW : cur;
}

static void update_impact_states(car *c) {
  const tmuf_vt_contact_response *cr = &c->t->contact_response;
  c->contacts.front_impact = impact_severity(c->contacts.front_bucket, cr->wheel_impact_feedback_low_threshold,
                                             cr->wheel_impact_feedback_high_threshold, c->contacts.front_impact);
  c->contacts.rear_impact = impact_severity(c->contacts.rear_bucket, cr->wheel_impact_feedback_low_threshold,
                                            cr->wheel_impact_feedback_high_threshold, c->contacts.rear_impact);
  c->contacts.body_impact = impact_severity(c->contacts.body_bucket, cr->body_impact_feedback_low_threshold,
                                            cr->body_impact_feedback_high_threshold, c->contacts.body_impact);
  if (c->contacts.peak_rear < c->contacts.rear_impact) {
    c->contacts.peak_rear = c->contacts.rear_impact;
    c->contacts.peak_wheel_material = c->contacts.last_wheel_material;
  }
  if (c->contacts.peak_front < c->contacts.front_impact) {
    c->contacts.peak_front = c->contacts.front_impact;
    c->contacts.peak_wheel_material = c->contacts.last_wheel_material;
  }
  if (c->contacts.peak_body < c->contacts.body_impact) {
    c->contacts.peak_body = c->contacts.body_impact;
    c->contacts.peak_body_material = c->contacts.last_body_material;
  }
  if (c->sound.enabled) {
    c->sound.front_impact = impact_severity(c->contacts.front_bucket, cr->wheel_impact_feedback_low_threshold,
                                            cr->wheel_impact_feedback_high_threshold, c->sound.front_impact);
    c->sound.rear_impact = impact_severity(c->contacts.rear_bucket, cr->wheel_impact_feedback_low_threshold,
                                           cr->wheel_impact_feedback_high_threshold, c->sound.rear_impact);
    c->sound.body_impact = impact_severity(c->contacts.body_bucket, cr->body_impact_feedback_low_threshold,
                                           cr->body_impact_feedback_high_threshold, c->sound.body_impact);
  }
}

static void apply_special_contact_response(car *c, gm_vec3 force, uint32_t tick, int ground) {
  if (!(c->controls.special_gate > SCALAR_EPS))
    return;
  switch (c->controls.special_mode) {
  case 1:
    if (ground && c->contacts.special_cooldown_until < tick) {
      gm_vec3 imp = v3(-force.x, -force.y, -force.z);
      float l2 = v3_dot(imp, imp);
      if (l2 > VEC_EPS2)
        imp = v3_scale(imp, 1.0f / tmuf_sqrtf(l2));
      imp = v3_scale(imp, c->t->contact_response.special_contact_impulse_magnitude);
      car_add_impulse(c, imp);
      c->contacts.special_cooldown_until = tick + 100;
    }
    break;
  case 2:
    c->contact_feedback_scale = c->t->contact_response.special_solid_feedback_value;
    car_refresh_dyna_params(c);
    break;
  case 3:
    c->turbo.type = TURBO_DIRECT;
    c->turbo.impulse_scale = c->t->turbo.impulse_scale_a;
    break;
  default:
    break;
  }
}

static int is_ground_contact_id(const car *c, uint8_t id, gm_vec3 *peer_axis, uint32_t *peer_corpus) {
  for (uint32_t i = 0; i < c->wheel_count; i++) {
    const car_wheel *w = &c->wheels[i];
    if (w->contact && w->contact_material == id) {
      *peer_axis = w->peer_z_local;
      *peer_corpus = w->peer_corpus;
      return 1;
    }
  }
  return 0;
}

static int all_wheel_contact_id(const car *c, uint8_t id) {
  uint32_t missing = 0;
  for (uint32_t i = 0; i < c->wheel_count; i++) {
    const car_wheel *w = &c->wheels[i];
    if (!w->contact) {
      missing++;
      continue;
    }
    if (w->contact_material != id)
      return 0;
  }
  return missing != c->wheel_count;
}

static float roulette_value01(uint32_t delta, uint32_t period) {
  uint32_t rem = delta % period;
  float phase = (float)rem / (float)period;
  if (phase < 4.0f / 7.0f)
    return 0.0f;
  if (phase < 6.0f / 7.0f)
    return 0.5f;
  return 1.0f;
}

static void enable_turbo(car *c, uint32_t tick, uint32_t duration, float scale, int type, uint32_t source) {
  if (c->turbo.type != type) {
    c->turbo.start_tick = tick;
    c->turbo.source_corpus = UINT32_MAX;
  }
  if (type == TURBO_DIRECT) {
    c->turbo.impulse_scale = scale;
  } else if (type == TURBO_ROULETTE && c->turbo.source_corpus != source) {
    float phase = roulette_value01(tick - c->turbo.roulette_origin, 1000u);
    c->turbo.type2_phase = phase;
    c->turbo.impulse_scale = (float)((double)phase + 1.0) * scale;
    c->turbo.source_corpus = source;
  }
  c->turbo.end_tick = tick + duration;
  c->turbo.type = type;
}

static void process_turbo_contacts(car *c, uint32_t tick) {
  const tmuf_vt_turbo *tb = &c->t->turbo;
  gm_vec3 axis;
  uint32_t corpus = 0;
  if (is_ground_contact_id(c, TURBO_A_CONTACT, &axis, &corpus))
    enable_turbo(c, tick, tb->duration_a, tb->impulse_scale_a * axis.z, TURBO_DIRECT, corpus);
  if (is_ground_contact_id(c, TURBO_B_CONTACT, &axis, &corpus))
    enable_turbo(c, tick, tb->duration_b, tb->impulse_scale_b * axis.z, TURBO_DIRECT, corpus);
  if (is_ground_contact_id(c, TURBO_ROULETTE_CONTACT, &axis, &corpus))
    enable_turbo(c, tick, tb->duration_a, tb->impulse_scale_a * axis.z, TURBO_ROULETTE, corpus);
  if (is_ground_contact_id(c, FREE_WHEELING_CONTACT, &axis, &corpus))
    c->controls.forced_low_speed_friction = 1;
}

static void update_turbo(car *c, uint32_t tick) {
  if (c->turbo.type != TURBO_NONE) {
    if (tick > c->turbo.end_tick)
      c->turbo.type = TURBO_NONE;
    if (c->turbo.type != TURBO_NONE) {
      float elapsed = (float)(tick - c->turbo.start_tick);
      float duration = (float)(c->turbo.end_tick - c->turbo.start_tick);
      c->turbo.progress = elapsed / duration;
      return;
    }
  }
  c->turbo.progress = 0.0f;
}

static void spring_integrate(car_spring *s, float dt) {
  float a = (0.0f - s->value) * s->stiffness - s->damping * s->velocity;
  float v = a * dt + s->velocity;
  s->velocity = v;
  s->value = dt * v + s->value;
}

static void feedback_spring_axis(car *c, car_spring *s, float dt, float f, float imp, int invert) {
  spring_integrate(s, dt);
  float drive = invert ? (-f * dt - imp) : (f * dt + imp);
  drive = clamp_sym(drive, c->feedback.drive_limit);
  float delta = (drive / c->feedback.drive_limit) * c->feedback.velocity_limit;
  s->value = clamp_sym(s->value, c->feedback.value_limit);
  s->velocity = clamp_sym(s->velocity + delta, c->feedback.velocity_limit);
}

static void update_feedback_tail(car *c, float dt, gm_vec3 lin, gm_vec3 saved_force, gm_vec3 saved_impulse,
                                 float surface) {
  const tmuf_vehicle_tuning *t = c->t;
  gm_vec3 f = body_force_local(c);
  float k = 1.0f / t->feedback.force_divisor;
  c->geared.scaled_force = v3(k * f.x, k * f.y, k * f.z);
  float cv = tmuf_curve_eval(&t->curves.surface_feedback, surface);
  float rate = cv + t->feedback.surface_base_rate;
  c->feedback.surface = clamp01(rate * dt + c->feedback.surface);
  feedback_spring_axis(c, &c->feedback.side, dt, saved_force.x, saved_impulse.x, 0);
  feedback_spring_axis(c, &c->feedback.forward, dt, saved_force.z, saved_impulse.z, 1);
  float dir = all_wheel_contact_id(c, FEEDBACK_RAMP_CONTACT) ? 1.0f : -1.0f;
  float in = fabsf(lin.z * KMH);
  float r0 = tmuf_curve_eval(&t->curves.vehicle_feedback_ramp0, in);
  c->feedback.ramp0 = clamp01(c->feedback.ramp0 + r0 * dt * dir);
  float r1 = tmuf_curve_eval(&t->curves.vehicle_feedback_ramp1, in);
  c->feedback.ramp1 = clamp01(c->feedback.ramp1 + r1 * dt * dir);
}

static void clear_wheel_contact_scratch(car *c) {
  for (uint32_t i = 0; i < c->wheel_count; i++) {
    car_wheel *w = &c->wheels[i];
    w->contact = 0;
    w->normal_samples = 0;
    w->latest_contact_point = v3(0.0f, 0.0f, 0.0f);
    w->normal_sum = v3(0.0f, 0.0f, 0.0f);
    w->contact_material = MAT_CONCRETE; /* ClearContactCarryStamp */
    w->rejected = 0;
  }
}

static void update_dyna_params_for_ground_contact(car *c, int ground) {
  const tmuf_vt_body_air_response *br = &c->t->body_air_response;
  c->contact_feedback_scale = ground ? br->grounded_solid_feedback1 : br->airborne_solid_feedback1;
  c->linear_fluid_friction = ground ? 0.0f : br->airborne_solid_feedback0;
  car_refresh_dyna_params(c);
}

/* CSceneVehicleCar::ComputeForces */
void car_compute_forces(car *c, float dt) {
  gm_vec3 saved_impulse = c->acc.impulse, saved_force = c->acc.force;
  c->acc.force = v3(0.0f, 0.0f, 0.0f);
  c->acc.impulse = v3(0.0f, 0.0f, 0.0f);

  if (c->integration.speed_blocked || c->integration.speed_blocked2 || c->def->water_box.half.x < 0.0f) {
    gm_vec3 zero = v3(0.0f, 0.0f, 0.0f);
    body_set_lin_local(c, zero);
    body_set_ang_local(c, zero);
    body_set_force_local(c, zero);
    body_set_torque_local(c, zero);
    return;
  }

  car_create_fake_contacts(c);
  car_integrate_vehicle(c, dt);

  uint32_t tick = c->tick;
  int ground = car_is_ground_contact(c);
  update_dyna_params_for_ground_contact(c, ground);
  if (!c->integration.integrate_wheels)
    return;

  float mat_vals[4] = {1.0f, 1.0f, 1.0f, 1.0f};
  int has_ground_material = 0;
  float slope_a = 1.0f, slope_b = 1.0f, steer_yaw = 0.0f;
  int slip_flag = 0, kill_side = 0;
  gm_vec3 lin = body_lin_local(c);
  float surface = 0.0f;
  if (c->integration.zero_horizontal_speed) {
    lin.x = 0.0f;
    lin.z = 0.0f;
    body_set_lin_local(c, lin);
  } else {
    gm_vec3 ang = body_ang_local(c);
    gm_vec3 force = body_force_local(c);
    c->engine.low_feedback_force = 0.0f;
    apply_friction_forces(c, lin);
    clamp_linear_speed(c, &lin);
    compute_ground_material_vals(c, mat_vals, &has_ground_material);
    get_slope_adherence(c, force, &slope_a, &slope_b);
    steer_yaw = visual_steer_yaw(c, lin);
    c->geared.local_speed = lin;
    car_compute_selected_handling(c, dt, force, slope_a, slope_b, lin, ang, steer_yaw, has_ground_material, mat_vals,
                                  &slip_flag, &surface);
    /* ScanWheelSideSpeedKillContacts */
    int any = 0;
    for (uint32_t i = 0; i < c->wheel_count; i++)
      if (c->wheels[i].contact) {
        any = 1;
        if (c->wheels[i].kills_lateral_speed)
          kill_side = 1;
      }
    /* UpdateLowSpeedFeedback */
    if (any) {
      float gate = -c->controls.gate_b * c->engine.low_feedback_gate_scale;
      float fr = c->t->low_speed_friction_magnitude * c->engine.low_feedback_friction_scale;
      c->engine.low_feedback_force = gate - fr;
    }
    /* KillSideSpeedForTaggedContact */
    float lfs = c->t->geared_drive.lateral_force_scale;
    if (kill_side && lfs == lfs && 0.0f > lfs) {
      lin.x = 0.0f;
      body_set_lin_local(c, lin);
    }
    compute_air_control(c, ang, tick, ground, kill_side);
    apply_special_contact_response(c, force, tick, ground);
    update_impact_states(c);
    c->last_forces_tick = tick;
    process_turbo_contacts(c, tick);
    update_turbo(c, tick);
  }
  update_feedback_tail(c, dt, lin, saved_force, saved_impulse, surface);
  clear_wheel_contact_scratch(c);
  /* ResetPerTickContactFeedback */
  c->contacts.front_bucket = 0.0f;
  c->contacts.body_contact = 0;
  c->contacts.rear_bucket = 0.0f;
  c->air.refresh_memory = 0;
  c->contacts.body_bucket = 0.0f;
  c->contacts.lateral_slowdown_contact = 0;
}
