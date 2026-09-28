#ifndef TMUF_REFERENCE_CAR_UTIL_H
#define TMUF_REFERENCE_CAR_UTIL_H

/* Shared helpers of the car translation units (SceneVehicleCarDynamics,
   SceneVehicleMath). Each states its operation order. */

#include <math.h>

#include "optimized/car.h"

#define VEC_EPS2 1.0e-10f
#define SCALAR_EPS 1.0e-5f
#define GATE 0.1f
#define PI_F 3.1415927f
#define HALF_PI_F (PI_F * 0.5f)
#define KMH 3.6f
#define WHEEL_SPIN_PERIOD (512.0f * PI_F)

/* (a.y b.y + a.x b.x) + a.z b.z */
static inline float dot_yxz(gm_vec3 a, gm_vec3 b) { return (a.y * b.y + a.x * b.x) + a.z * b.z; }
static inline float len2_yxz(gm_vec3 a) { return dot_yxz(a, a); }

/* GmMath::NormalizeOr */
static inline gm_vec3 normalize_or(gm_vec3 v, gm_vec3 fallback, float min_len2) {
  float l2 = v3_dot(v, v);
  if (l2 > min_len2)
    return v3_scale(v, 1.0f / tmuf_sqrtf(l2));
  return fallback;
}

static inline float clamp01(float v) {
  float r = 0.0f;
  if (!(v < 0.0f) && v != 0.0f) {
    r = v;
    if (v == v && 1.0f < v)
      r = 1.0f;
  }
  return r;
}

static inline float clamp_sym(float v, float m) {
  if (v != v)
    return v;
  if (!(-m < v))
    return -m;
  if (!(v < m))
    return m;
  return v;
}

static inline float sign_nn(float v) { return v < 0.0f ? -1.0f : 1.0f; }

static inline float u2f_nat(uint32_t v) { return (float)v; }

/* GmFunc::AsinSafe */
static inline float asin_safe(float v) {
  const float lim = 1.0f - 1e-6f;
  if (v < -lim)
    return -HALF_PI_F;
  if (lim < v)
    return HALF_PI_F;
  return tmuf_asinf(v);
}

/* GmVec3::GetAngle */
static inline float vec_angle(gm_vec3 a, gm_vec3 b) {
  float d = tmuf_mul_fd(v3_dot(a, b), 1.0 - (double)1.0e-5f);
  float angle = tmuf_acosf(d);
  if (angle <= 1.0e-5f)
    return angle;
  gm_vec3 na = normalize_or(a, a, 1.0e-10f);
  gm_vec3 nb = normalize_or(b, b, 1.0e-10f);
  if (v3_cross(na, nb).y < 0.0f)
    angle = -angle;
  return angle;
}

/* Local-space body wrappers (CHmsItem / CHmsDyna Local*) */
static inline gm_vec3 body_lin_local(const car *c) { return mat3_tmul_vec(&c->body->state.rot, c->body->state.lin); }
static inline gm_vec3 body_ang_local(const car *c) { return mat3_tmul_vec(&c->body->state.rot, c->body->state.ang); }
static inline gm_vec3 body_force_local(const car *c) {
  return mat3_tmul_vec(&c->body->state.rot, c->body->state.force);
}
static inline void body_set_lin_local(car *c, gm_vec3 v) { c->body->state.lin = dyna_local_dir_to_world(c->body, v); }
static inline void body_set_ang_local(car *c, gm_vec3 v) { c->body->state.ang = dyna_local_dir_to_world(c->body, v); }
static inline void body_set_force_local(car *c, gm_vec3 v) {
  c->body->state.force = dyna_local_dir_to_world(c->body, v);
}
static inline void body_set_torque_local(car *c, gm_vec3 v) {
  c->body->state.torque = dyna_local_dir_to_world(c->body, v);
}

/* CSceneVehicleCar::Add* (feed the feedback accumulators) */
static inline void car_add_force_at(car *c, gm_vec3 f, gm_vec3 p) {
  dyna_add_force_at(c->body, dyna_local_dir_to_world(c->body, f), dyna_local_point_to_world(c->body, p));
  c->acc.force.x = c->acc.force.x + f.x;
  c->acc.force.y = f.y + c->acc.force.y;
  c->acc.force.z = f.z + c->acc.force.z;
}
static inline void car_add_force(car *c, gm_vec3 f) {
  dyna_add_force(c->body, dyna_local_dir_to_world(c->body, f));
  c->acc.force.x = c->acc.force.x + f.x;
  c->acc.force.y = f.y + c->acc.force.y;
  c->acc.force.z = f.z + c->acc.force.z;
}
static inline void car_add_torque(car *c, gm_vec3 t) { dyna_add_torque(c->body, dyna_local_dir_to_world(c->body, t)); }

float car_eval_speed_curve(const tmuf_curve *curve, float speed);

/* Tuning curve accessors (CSceneVehicleCarTuning) */
float tn_max_side_friction(car *c, float speed);
float tn_accel(car *c, float speed);
float tn_rollover_lateral(car *c, float speed);
float tn_rollover_lateral_coef(car *c, float angle);
float tn_steer_drive_torque(car *c, float speed);
float tn_lateral_contact_slowdown(car *c, float speed);
float tn_steer_slowdown(car *c, float speed);
float tn_water_friction(car *c, float speed);
float tn_m4_steer_radius(car *c, float speed);
float tn_m4_max_friction(car *c, float speed);
float tn_m5_accel(car *c, float speed);
float tn_m5_slipping_accel(car *c, float speed);
float tn_m5_steer_slowdown(car *c, float speed);
float tn_m5_lateral_contact_slowdown(car *c, float speed);
float tn_m6_damper_modulation(car *c, float absorb);
float tn_m6_rear_gear_accel(car *c, float speed);
float tn_m6_burnout_radius(car *c, float speed);
float tn_m6_lateral_speed_from_radius(car *c, float radius);
float tn_m6_burnout_rollover(car *c, float speed);
float tn_m6_donut_rollover(car *c, float speed);
float tn_m6_rollover_lateral_ratio(car *c, float ratio);

/* car.c internals shared with the force units */
void car_add_impulse(car *c, gm_vec3 impulse);
void car_add_impulse_at(car *c, gm_vec3 impulse, gm_vec3 point);
void car_wheel_add_force(car *c, car_wheel *w);
int car_is_ground_contact(const car *c);
const car_material *car_wheel_material(const car *c, const car_wheel *w);
void car_integrate_vehicle(car *c, float dt);
void car_create_fake_contacts(car *c);
void car_compute_selected_handling(car *c, float dt, gm_vec3 current_force, float slope_a, float slope_b,
                                   gm_vec3 lin, gm_vec3 ang, float steer_yaw, int has_ground_material,
                                   const float mat_vals[4], int *slip_flag, float *surface_feedback);
int car_apply_water_forces(car *c, gm_vec3 force_to_subtract);

#endif
