#ifndef TMUF_COMMON_VEHICLE_TUNING_H
#define TMUF_COMMON_VEHICLE_TUNING_H

/* Vehicle tuning values (CSceneVehicleCarTuning) decoded from the parsed
   tuning chunks: defaults, then each archived chunk in file order. Field
   names follow what the physics code uses them for. */

#include <stddef.h>
#include <stdint.h>

#include "common/assets.h"
#include "common/pack_classes.h"

#define TMUF_MAX_GEARS 16
#define TMUF_MAX_CURVE_KEYS 64
#define TMUF_MATERIAL_RUBBER 5u

typedef struct tmuf_curve {
  int present;
  int constant; /* step interpolation (CFuncKeys mode 1), else linear */
  uint32_t count;
  float x[TMUF_MAX_CURVE_KEYS], y[TMUF_MAX_CURVE_KEYS];
} tmuf_curve;

typedef struct tmuf_vt_curves {
  tmuf_curve lateral_contact_slow_down_from_speed;
  tmuf_curve max_side_friction_from_speed;
  tmuf_curve rollover_lateral_from_speed;
  tmuf_curve rollover_lateral_coefficient_from_angle;
  tmuf_curve wheel_visual_steer_angle_from_speed;
  tmuf_curve steering_drive_torque_from_speed;
  tmuf_curve steer_slow_down_from_speed;
  tmuf_curve suspension_damper_absorb_modulation;
  tmuf_curve air_control_z_scale;
  tmuf_curve radius_steering_radius_from_speed;
  tmuf_curve radius_steering_max_friction_from_speed;
  tmuf_curve slip_response_accel_from_speed;
  tmuf_curve slip_response_slipping_accel_from_speed;
  tmuf_curve reverse_gear_accel_from_speed;
  tmuf_curve burnout_rollover_lateral_from_speed_ratio;
  tmuf_curve burnout_radius_from_speed;
  tmuf_curve burnout_lateral_speed_from_radius;
  tmuf_curve donut_rollover_from_speed;
  tmuf_curve burnout_rollover_from_speed;
  tmuf_curve splash_vertical_impulse;
  tmuf_curve splash_horizontal_impulse;
  tmuf_curve water_friction_from_speed;
  tmuf_curve surface_feedback;
  tmuf_curve vehicle_feedback_ramp1;
  tmuf_curve vehicle_feedback_ramp0;
  tmuf_curve vehicle_default30_to100;
} tmuf_vt_curves;

typedef struct tmuf_vt_visual_settings {
  float wheel_speed_base;
  float wheel_speed_scale;
} tmuf_vt_visual_settings;

typedef struct tmuf_vt_steering {
  float slew_rate;
  float assist_full_speed;
  float slow_down_scale;
} tmuf_vt_steering;

typedef struct tmuf_vt_suspension {
  float wheel_spring_coef;
  float wheel_damper_coef;
  float damper_modulation_max_absorb;
  float damper_modulation_min_absorb;
  float wheel_rest_damper_absorb;
  float wheel_static_spring_scale;
  float wheel_absorb_follow_coef;
} tmuf_vt_suspension;

typedef struct tmuf_vt_contact_response {
  float body_impact_feedback_high_threshold;
  float body_impact_feedback_low_threshold;
  float wheel_impact_feedback_high_threshold;
  float wheel_impact_feedback_low_threshold;
  float body_contact_tangent_limit_other;
  float body_contact_tangent_limit_metal;
  float body_contact_impulse_metal;
  float body_contact_impulse_other;
  float wheel_contact_impulse_other;
  float wheel_contact_impulse_metal;
  float point_impulse_angular_y_scale;
  float point_impulse_angular_scale;
  float point_impulse_angular_speed_max;
  float point_impulse_linear_speed_growth_limit_sq;
  float special_contact_impulse_magnitude;
  float special_solid_feedback_value;
  uint32_t single_material;
} tmuf_vt_contact_response;

typedef struct tmuf_vt_body_air_response {
  float solid_physical_mass;
  float solid_inertia_mass;
  float solid_inertia_box_size[3];
  float solid_center_z_half_extent_scale;
  float solid_center_y_offset;
  float solid_physical_response_coef_b;
  float airborne_solid_feedback0;
  float air_torque_linear_coef;
  float air_torque_quadratic_coef;
  float grounded_solid_feedback1;
  float airborne_solid_feedback1;
  float slope_adherence1_min;
  float slope_adherence1_max;
  float slope_adherence2_min;
  float slope_adherence2_max;
  uint32_t air_control_memory_tick_window;
  float air_control_y_switch_threshold;
} tmuf_vt_body_air_response;

typedef struct tmuf_vt_radius_steering {
  float steer_torque_speed_scale;
  float angular_damping_linear;
  float angular_damping_quadratic;
  float lateral_friction_linear;
  float lateral_friction_quadratic;
  float capture_exit_side_speed_max;
  float input_steer_radius_scale;
  float slipping_friction_scale;
  float captured_angle_rate;
  float captured_angle_radius_scale;
  float steer_angle_limit;
  float steer_angle_from_input_scale;
} tmuf_vt_radius_steering;

typedef struct tmuf_vt_slip_response {
  float slipping_accel_scale;
  uint32_t lateral_slow_down_tick_window;
  float rollover_torque_cap;
  uint32_t steering_memory_ticks;
  int slip_slowdown_enabled;
  uint32_t slip_slowdown_ticks;
  float longitudinal_torque_scale;
} tmuf_vt_slip_response;

typedef struct tmuf_vt_transmission {
  float reverse_speed_norm;
  float gear_speed_ratio[TMUF_MAX_GEARS];
  float upshift_threshold[TMUF_MAX_GEARS];
  float downshift_threshold[TMUF_MAX_GEARS];
  float rpm_wanted[TMUF_MAX_GEARS];
  float target_input_bias[TMUF_MAX_GEARS];
  float rpm_delta[TMUF_MAX_GEARS];
  uint32_t gear_count;
} tmuf_vt_transmission;

typedef struct tmuf_vt_burnout {
  float reverse_force_threshold;
  float donut_speed_high;
  float donut_speed_low;
  float lateral_correction_scale;
  float angle_torque_scale;
  float angular_damping_linear;
  float angle_return_quadratic;
  float tangent_angular_damping;
  float radius_correction_scale;
  float radius_correction_speed_scale;
  float radius_min;
  float tangent_speed_max;
  float angle_limit;
  float angle_limit_positive;
  float angle_limit_negative;
  uint32_t duration_ticks;
  float drive_fade_scale;
  float side_force_fade_scale;
  uint32_t exit_duration_ticks;
  float exit_accel_fade_scale;
  float exit_min_speed;
  float exit_steer_grip_scale;
  float exit_bonus_accel_scale;
  float wheel_angular_speed_override;
  float exit_side_friction_scale;
} tmuf_vt_burnout;

typedef struct tmuf_vt_engine_input {
  float engine_input_maximum;
  float burnout_hold_input_rise;
  float airborne_input_rise;
  float airborne_input_fall;
  float ground_input_brake;
  float ground_input_rise;
  float transition_input_rise;
  float ground_input_fall;
  float forward_transition_speed_high;
  float forward_transition_speed_low;
  float reverse_transition_speed_high;
  float reverse_transition_speed_low;
} tmuf_vt_engine_input;

typedef struct tmuf_vt_geared_drive {
  float forward_accel_base;
  float forward_accel_speed_coef;
  float forward_accel_cap_when_slipping;
  float forward_accel_cap;
  float speed_limit_force;
  float force_z_scale;
  float side_force_to_drive_torque_scale;
  float slipping_steer_torque_scale;
  float lateral_force_scale;
  float slipping_side_friction_scale;
  float side_friction_slip_blend;
  float drive_side_friction_slip_blend;
  float slip_ratio_scale;
  float current_force_torque_min;
  float current_torque_x_scale;
  float current_torque_z_scale;
  float per_slipping_wheel_accel_scale;
  float low_speed_b_slipping_grip_scale;
  float forward_accel_cap_when_slipping_reverse;
  float forward_accel_cap_reverse;
  float dirt_slide_side_force_scale;
  float dirt_slide_gate_scale;
  float dirt_slide_forward_force_scale;
  float dirt_slide_forward_gate_scale;
  tmuf_vt_transmission transmission;
  tmuf_vt_burnout burnout;
  tmuf_vt_engine_input input;
} tmuf_vt_geared_drive;

typedef struct tmuf_vt_water {
  float buoyancy_force;
  float splash_horizontal_speed_threshold;
  float splash_total_speed_threshold;
  float angular_linear_damping;
  float angular_speed_damping;
} tmuf_vt_water;

typedef struct tmuf_vt_turbo {
  float impulse_scale_a;
  float impulse_scale_b;
  uint32_t duration_a;
  uint32_t duration_b;
} tmuf_vt_turbo;

typedef struct tmuf_vt_feedback {
  float surface_base_rate;
  float force_divisor;
} tmuf_vt_feedback;

typedef struct tmuf_vehicle_tuning {
  float engine_speed_norm;
  float low_speed_friction_magnitude;
  float low_speed_linear_damping;
  uint32_t wheel_force_mode;
  uint32_t handling_model;
  tmuf_vt_visual_settings visual;
  tmuf_vt_steering steering;
  tmuf_vt_suspension suspension;
  tmuf_vt_contact_response contact_response;
  tmuf_vt_body_air_response body_air_response;
  tmuf_vt_radius_steering radius_steering;
  tmuf_vt_slip_response slip_response;
  tmuf_vt_geared_drive geared_drive;
  tmuf_vt_water water;
  tmuf_vt_turbo turbo;
  tmuf_vt_feedback feedback;
  tmuf_vt_curves curves;
} tmuf_vehicle_tuning;

enum { TMUF_WHEEL_FORCE_DIRECT_SPRING = 0, TMUF_WHEEL_FORCE_FOLLOW_ABSORB = 1, TMUF_WHEEL_FORCE_FOLLOW_ABSORB_IMPULSE = 2 };
enum {
  TMUF_HANDLING_STANDARD = 0,
  TMUF_HANDLING_LATERAL = 1,
  TMUF_HANDLING_RADIUS_STEERING = 3,
  TMUF_HANDLING_SLIP_RESPONSE = 4,
  TMUF_HANDLING_GEARED_DRIVE = 5
};

void tmuf_vehicle_tuning_defaults(tmuf_vehicle_tuning *t);
/* Applies the chunks of a parsed CSceneVehicleCarTuning (asset owns it, for
   resolving curve references). Returns 0 on success. */
int tmuf_vehicle_tuning_decode(tmuf_vehicle_tuning *t, tmuf_assets *assets, tmuf_asset *owner,
                               const tmuf_car_tuning *raw, char *err, size_t err_size);

#endif
