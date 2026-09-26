#include "common/vehicle_tuning.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

#define TMUF_PI 3.1415927f
#define TMUF_QUARTER_PI (TMUF_PI * 0.25f)

void tmuf_vehicle_tuning_defaults(tmuf_vehicle_tuning *t) {
  memset(t, 0, sizeof *t);
  t->contact_response.body_impact_feedback_high_threshold = 20.0f;
  t->engine_speed_norm = 200.0f / 3.6f;
  t->geared_drive.transmission.reverse_speed_norm = 50.0f / 3.6f;
  t->geared_drive.forward_accel_base = 20.0f;
  t->geared_drive.forward_accel_cap_when_slipping = 500.0f;
  t->geared_drive.forward_accel_cap = 500.0f;
  t->low_speed_friction_magnitude = 1.0f;
  t->geared_drive.speed_limit_force = 10.0f;
  t->visual.wheel_speed_base = 1.0f;
  t->visual.wheel_speed_scale = 0.5f;
  t->steering.assist_full_speed = 20.0f;
  t->steering.slew_rate = 20.0f;
  t->geared_drive.side_force_to_drive_torque_scale = 0.01f;
  t->geared_drive.lateral_force_scale = -1.0f;
  t->geared_drive.slipping_side_friction_scale = 0.6f;
  t->geared_drive.drive_side_friction_slip_blend = 1.0f;
  t->contact_response.point_impulse_angular_y_scale = 1.0f;
  t->contact_response.point_impulse_angular_scale = 1.0f;
  t->turbo.impulse_scale_a = 3.0f;
  t->turbo.impulse_scale_b = 3.0f;
  t->turbo.duration_a = 1000u;
  t->turbo.duration_b = 1000u;
  t->contact_response.special_contact_impulse_magnitude = 10.0f;
  t->contact_response.special_solid_feedback_value = 0.1f;
  t->suspension.wheel_static_spring_scale = 0.2f;
  t->body_air_response.solid_physical_mass = 800.0f;
  t->body_air_response.solid_inertia_mass = 1.0f;
  t->body_air_response.solid_inertia_box_size[0] = 0.5f;
  t->body_air_response.solid_inertia_box_size[1] = 0.5f;
  t->body_air_response.solid_inertia_box_size[2] = 0.5f;
  t->contact_response.point_impulse_angular_speed_max = 100.0f;
  t->contact_response.point_impulse_linear_speed_growth_limit_sq = 10000.0f;
  t->body_air_response.airborne_solid_feedback0 = 0.1f;
  t->body_air_response.air_torque_linear_coef = 0.5f;
  t->body_air_response.air_torque_quadratic_coef = 1.0f;
  t->body_air_response.grounded_solid_feedback1 = 1.0f;
  t->body_air_response.airborne_solid_feedback1 = 1.0f;
  t->body_air_response.solid_physical_response_coef_b = 0.3f;
  t->contact_response.single_material = TMUF_MATERIAL_RUBBER;
  t->contact_response.body_contact_tangent_limit_other = 0.8f;
  t->contact_response.body_contact_tangent_limit_metal = 0.4f;
  t->suspension.wheel_absorb_follow_coef = 5.0f;
  t->radius_steering.steer_torque_speed_scale = 1.0f;
  t->radius_steering.angular_damping_linear = 1.0f;
  t->radius_steering.lateral_friction_linear = 1.0f;
  t->radius_steering.capture_exit_side_speed_max = 1.0f;
  t->radius_steering.input_steer_radius_scale = 1.0f;
  t->radius_steering.slipping_friction_scale = 1.0f;
  t->radius_steering.captured_angle_rate = 0.005f;
  t->radius_steering.captured_angle_radius_scale = 0.3f;
  t->radius_steering.steer_angle_limit = TMUF_QUARTER_PI;
  t->radius_steering.steer_angle_from_input_scale = TMUF_QUARTER_PI;
  t->slip_response.slipping_accel_scale = 1.0f;
  t->slip_response.lateral_slow_down_tick_window = 500u;
  t->slip_response.rollover_torque_cap = 20.0f;
  t->slip_response.steering_memory_ticks = 1u;
  t->geared_drive.slip_ratio_scale = 1.0f;
  t->water.buoyancy_force = 1.0f;
  t->water.splash_horizontal_speed_threshold = 200.0f / 3.6f;
  t->water.splash_total_speed_threshold = 50.0f;
  t->water.angular_linear_damping = 0.1f;
  t->water.angular_speed_damping = 0.2f;
  t->feedback.force_divisor = 5.0f;
  t->geared_drive.burnout.reverse_force_threshold = 200.0f;
  t->geared_drive.current_force_torque_min = 0.01f;
  t->geared_drive.current_torque_x_scale = 0.1f;
  t->geared_drive.current_torque_z_scale = 0.1f;
  t->geared_drive.per_slipping_wheel_accel_scale = 0.5f;
  t->geared_drive.low_speed_b_slipping_grip_scale = 0.2f;
  t->geared_drive.forward_accel_cap_when_slipping_reverse = 100.0f;
  t->geared_drive.forward_accel_cap_reverse = 50.0f;
  t->geared_drive.burnout.donut_speed_high = 10.0f;
  t->geared_drive.burnout.donut_speed_low = 3.0f;
  t->geared_drive.burnout.lateral_correction_scale = 1.0f;
  t->geared_drive.burnout.angle_torque_scale = 6.0f;
  t->geared_drive.burnout.angular_damping_linear = 2.0f;
  t->geared_drive.burnout.angle_return_quadratic = 0.5f;
  t->geared_drive.burnout.tangent_angular_damping = 0.5f;
  t->geared_drive.burnout.radius_correction_scale = 1.0f;
  t->geared_drive.burnout.radius_correction_speed_scale = 0.2f;
  t->geared_drive.burnout.radius_min = 20.0f;
  t->geared_drive.burnout.tangent_speed_max = 10.0f;
  t->geared_drive.burnout.angle_limit = 0.35f;
  t->geared_drive.burnout.angle_limit_positive = 1.7453f;
  t->geared_drive.burnout.angle_limit_negative = 0.785f;
  t->geared_drive.burnout.duration_ticks = 1000u;
  t->geared_drive.burnout.drive_fade_scale = 0.5f;
  t->geared_drive.burnout.side_force_fade_scale = 0.01f;
  t->geared_drive.burnout.exit_duration_ticks = 500u;
  t->geared_drive.burnout.exit_accel_fade_scale = 4.0f;
  t->geared_drive.burnout.exit_min_speed = 5.0f;
  t->geared_drive.burnout.exit_steer_grip_scale = 1.0f;
  t->geared_drive.burnout.exit_bonus_accel_scale = 10.0f;
  t->geared_drive.burnout.wheel_angular_speed_override = 150.0f;
  t->geared_drive.burnout.exit_side_friction_scale = 1.0f;
  t->geared_drive.input.engine_input_maximum = 0.8f;
  t->geared_drive.input.burnout_hold_input_rise = 5000.0f;
  t->geared_drive.input.airborne_input_rise = 5000.0f;
  t->geared_drive.input.airborne_input_fall = 2500.0f;
  t->geared_drive.input.ground_input_brake = 5000.0f;
  t->geared_drive.input.ground_input_rise = 10000.0f;
  t->geared_drive.input.transition_input_rise = 10000.0f;
  t->geared_drive.input.ground_input_fall = 4000.0f;
  t->geared_drive.input.forward_transition_speed_high = 3.0f;
  t->geared_drive.input.forward_transition_speed_low = -2.0f;
  t->geared_drive.input.reverse_transition_speed_high = 2.0f;
  t->geared_drive.input.reverse_transition_speed_low = -3.0f;
  t->geared_drive.dirt_slide_side_force_scale = 0.05f;
  t->geared_drive.dirt_slide_gate_scale = 20.0f;
  t->geared_drive.dirt_slide_forward_force_scale = 15.0f;
  t->geared_drive.dirt_slide_forward_gate_scale = 1.0f;
  t->body_air_response.air_control_y_switch_threshold = TMUF_PI;
  t->feedback.surface_base_rate = -0.3f;
  t->contact_response.wheel_impact_feedback_high_threshold = 20.0f;
  t->contact_response.wheel_impact_feedback_low_threshold = 5.0f;
  t->contact_response.body_impact_feedback_low_threshold = 5.0f;
}

/* Scalar fields: (chunk, kind, index among the chunk's fields of that kind,
   destination). Naturals marked bool store (value != 0). */
typedef struct scalar_binding {
  uint32_t chunk;
  char kind;
  uint32_t index;
  size_t offset;
  int is_bool;
} scalar_binding;

static const scalar_binding SCALARS[] = {
    {0x0a029000u, 'R', 1, offsetof(tmuf_vehicle_tuning, visual.wheel_speed_base), 0}, /* Root */
    {0x0a029000u, 'R', 2, offsetof(tmuf_vehicle_tuning, visual.wheel_speed_scale), 0}, /* Root */
    {0x0a029000u, 'R', 3, offsetof(tmuf_vehicle_tuning, engine_speed_norm), 0}, /* Root */
    {0x0a029000u, 'R', 4, offsetof(tmuf_vehicle_tuning, suspension.wheel_spring_coef), 0}, /* Root */
    {0x0a029000u, 'R', 5, offsetof(tmuf_vehicle_tuning, suspension.wheel_damper_coef), 0}, /* Root */
    {0x0a029000u, 'R', 6, offsetof(tmuf_vehicle_tuning, suspension.damper_modulation_max_absorb), 0}, /* Root */
    {0x0a029000u, 'R', 7, offsetof(tmuf_vehicle_tuning, suspension.damper_modulation_min_absorb), 0}, /* Root */
    {0x0a029000u, 'R', 8, offsetof(tmuf_vehicle_tuning, suspension.wheel_rest_damper_absorb), 0}, /* Root */
    {0x0a029000u, 'R', 11, offsetof(tmuf_vehicle_tuning, suspension.wheel_static_spring_scale), 0}, /* Root */
    {0x0a029002u, 'R', 0, offsetof(tmuf_vehicle_tuning, body_air_response.solid_physical_mass), 0}, /* SolidBody */
    {0x0a029002u, 'R', 1, offsetof(tmuf_vehicle_tuning, body_air_response.solid_center_z_half_extent_scale), 0}, /* SolidBody */
    {0x0a029002u, 'R', 2, offsetof(tmuf_vehicle_tuning, body_air_response.solid_center_y_offset), 0}, /* SolidBody */
    {0x0a029005u, 'R', 0, offsetof(tmuf_vehicle_tuning, body_air_response.grounded_solid_feedback1), 0}, /* GroundedSolidFeedback */
    {0x0a02900au, 'R', 0, offsetof(tmuf_vehicle_tuning, body_air_response.airborne_solid_feedback0), 0}, /* AirborneTorque */
    {0x0a02900au, 'R', 1, offsetof(tmuf_vehicle_tuning, body_air_response.air_torque_linear_coef), 0}, /* AirborneTorque */
    {0x0a02900bu, 'R', 0, offsetof(tmuf_vehicle_tuning, body_air_response.solid_inertia_mass), 0}, /* SolidInertia */
    {0x0a02900bu, 'R', 1, offsetof(tmuf_vehicle_tuning, body_air_response.solid_inertia_box_size[0]), 0}, /* SolidInertia */
    {0x0a02900bu, 'R', 2, offsetof(tmuf_vehicle_tuning, body_air_response.solid_inertia_box_size[1]), 0}, /* SolidInertia */
    {0x0a02900bu, 'R', 3, offsetof(tmuf_vehicle_tuning, body_air_response.solid_inertia_box_size[2]), 0}, /* SolidInertia */
    {0x0a029018u, 'R', 0, offsetof(tmuf_vehicle_tuning, body_air_response.airborne_solid_feedback0), 0}, /* AirTorqueResponse */
    {0x0a029018u, 'R', 1, offsetof(tmuf_vehicle_tuning, body_air_response.air_torque_linear_coef), 0}, /* AirTorqueResponse */
    {0x0a029018u, 'R', 2, offsetof(tmuf_vehicle_tuning, body_air_response.air_torque_quadratic_coef), 0}, /* AirTorqueResponse */
    {0x0a029026u, 'R', 0, offsetof(tmuf_vehicle_tuning, body_air_response.slope_adherence1_min), 0}, /* SlopeAdherence */
    {0x0a029026u, 'R', 1, offsetof(tmuf_vehicle_tuning, body_air_response.slope_adherence1_max), 0}, /* SlopeAdherence */
    {0x0a029026u, 'R', 2, offsetof(tmuf_vehicle_tuning, body_air_response.slope_adherence2_min), 0}, /* SlopeAdherence */
    {0x0a029026u, 'R', 3, offsetof(tmuf_vehicle_tuning, body_air_response.slope_adherence2_max), 0}, /* SlopeAdherence */
    {0x0a029046u, 'R', 0, offsetof(tmuf_vehicle_tuning, water.buoyancy_force), 0}, /* WaterAndSplashResponse */
    {0x0a029046u, 'R', 1, offsetof(tmuf_vehicle_tuning, water.splash_horizontal_speed_threshold), 0}, /* WaterAndSplashResponse */
    {0x0a029046u, 'R', 2, offsetof(tmuf_vehicle_tuning, water.splash_total_speed_threshold), 0}, /* WaterAndSplashResponse */
    {0x0a029047u, 'R', 0, offsetof(tmuf_vehicle_tuning, water.angular_linear_damping), 0}, /* WaterAngularLinearDamping */
    {0x0a02905fu, 'R', 0, offsetof(tmuf_vehicle_tuning, water.angular_speed_damping), 0}, /* WaterAngularSpeedDamping */
    {0x0a029007u, 'R', 0, offsetof(tmuf_vehicle_tuning, steering.slew_rate), 0}, /* SteeringSlewRate */
    {0x0a029019u, 'R', 0, offsetof(tmuf_vehicle_tuning, contact_response.body_contact_tangent_limit_other), 0}, /* ContactImpulseResponse */
    {0x0a029019u, 'R', 1, offsetof(tmuf_vehicle_tuning, contact_response.body_contact_tangent_limit_metal), 0}, /* ContactImpulseResponse */
    {0x0a029019u, 'R', 2, offsetof(tmuf_vehicle_tuning, contact_response.body_contact_impulse_metal), 0}, /* ContactImpulseResponse */
    {0x0a029019u, 'R', 3, offsetof(tmuf_vehicle_tuning, contact_response.body_contact_impulse_other), 0}, /* ContactImpulseResponse */
    {0x0a029019u, 'R', 5, offsetof(tmuf_vehicle_tuning, contact_response.wheel_contact_impulse_other), 0}, /* ContactImpulseResponse */
    {0x0a029019u, 'R', 7, offsetof(tmuf_vehicle_tuning, contact_response.wheel_contact_impulse_metal), 0}, /* ContactImpulseResponse */
    {0x0a029023u, 'R', 0, offsetof(tmuf_vehicle_tuning, contact_response.point_impulse_angular_scale), 0}, /* PointImpulseAndM6SteerAssist */
    {0x0a029023u, 'R', 1, offsetof(tmuf_vehicle_tuning, steering.assist_full_speed), 0}, /* PointImpulseAndM6SteerAssist */
    {0x0a029032u, 'R', 4, offsetof(tmuf_vehicle_tuning, contact_response.wheel_impact_feedback_high_threshold), 0}, /* ImpactFeedbackThresholds */
    {0x0a029032u, 'R', 5, offsetof(tmuf_vehicle_tuning, contact_response.wheel_impact_feedback_low_threshold), 0}, /* ImpactFeedbackThresholds */
    {0x0a029032u, 'R', 6, offsetof(tmuf_vehicle_tuning, contact_response.body_impact_feedback_high_threshold), 0}, /* ImpactFeedbackThresholds */
    {0x0a029032u, 'R', 7, offsetof(tmuf_vehicle_tuning, contact_response.body_impact_feedback_low_threshold), 0}, /* ImpactFeedbackThresholds */
    {0x0a029033u, 'R', 0, offsetof(tmuf_vehicle_tuning, contact_response.point_impulse_angular_speed_max), 0}, /* PointImpulseAngularSpeedMax */
    {0x0a02904au, 'R', 1, offsetof(tmuf_vehicle_tuning, feedback.force_divisor), 0}, /* ForceFeedbackDivisorLegacy */
    {0x0a02905bu, 'R', 0, offsetof(tmuf_vehicle_tuning, feedback.surface_base_rate), 0}, /* SurfaceFeedback */
    {0x0a029010u, 'R', 0, offsetof(tmuf_vehicle_tuning, geared_drive.side_force_to_drive_torque_scale), 0}, /* ForceModelAndM6SideForceTorque */
    {0x0a02901du, 'R', 0, offsetof(tmuf_vehicle_tuning, body_air_response.airborne_solid_feedback1), 0}, /* AirborneFeedbackAndModel5Torque */
    {0x0a02901du, 'R', 1, offsetof(tmuf_vehicle_tuning, slip_response.longitudinal_torque_scale), 0}, /* AirborneFeedbackAndModel5Torque */
    {0x0a029028u, 'R', 1, offsetof(tmuf_vehicle_tuning, geared_drive.slipping_side_friction_scale), 0}, /* MaxSideFrictionAndWheelAbsorb */
    {0x0a029028u, 'R', 3, offsetof(tmuf_vehicle_tuning, low_speed_friction_magnitude), 0}, /* MaxSideFrictionAndWheelAbsorb */
    {0x0a029028u, 'R', 4, offsetof(tmuf_vehicle_tuning, suspension.wheel_absorb_follow_coef), 0}, /* MaxSideFrictionAndWheelAbsorb */
    {0x0a029029u, 'R', 0, offsetof(tmuf_vehicle_tuning, geared_drive.lateral_force_scale), 0}, /* RolloverLateralAndM6LateralForce */
    {0x0a02902cu, 'R', 0, offsetof(tmuf_vehicle_tuning, body_air_response.air_control_y_switch_threshold), 0}, /* AirControlAndRolloverCoef */
    {0x0a02902cu, 'R', 1, offsetof(tmuf_vehicle_tuning, geared_drive.forward_accel_speed_coef), 0}, /* AirControlAndRolloverCoef */
    {0x0a02902cu, 'R', 2, offsetof(tmuf_vehicle_tuning, geared_drive.forward_accel_cap_when_slipping), 0}, /* AirControlAndRolloverCoef */
    {0x0a02902cu, 'R', 3, offsetof(tmuf_vehicle_tuning, geared_drive.forward_accel_cap), 0}, /* AirControlAndRolloverCoef */
    {0x0a02902cu, 'R', 4, offsetof(tmuf_vehicle_tuning, low_speed_linear_damping), 0}, /* AirControlAndRolloverCoef */
    {0x0a029036u, 'R', 0, offsetof(tmuf_vehicle_tuning, radius_steering.steer_torque_speed_scale), 0}, /* Model4SteerRadiusAndFriction */
    {0x0a029036u, 'R', 1, offsetof(tmuf_vehicle_tuning, radius_steering.angular_damping_linear), 0}, /* Model4SteerRadiusAndFriction */
    {0x0a029036u, 'R', 2, offsetof(tmuf_vehicle_tuning, radius_steering.lateral_friction_linear), 0}, /* Model4SteerRadiusAndFriction */
    {0x0a029038u, 'R', 1, offsetof(tmuf_vehicle_tuning, radius_steering.slipping_friction_scale), 0}, /* Model4MaxFrictionAndSlipping */
    {0x0a029038u, 'R', 2, offsetof(tmuf_vehicle_tuning, radius_steering.input_steer_radius_scale), 0}, /* Model4MaxFrictionAndSlipping */
    {0x0a029039u, 'R', 0, offsetof(tmuf_vehicle_tuning, radius_steering.angular_damping_quadratic), 0}, /* Model4QuadraticDampingFriction */
    {0x0a029039u, 'R', 1, offsetof(tmuf_vehicle_tuning, radius_steering.lateral_friction_quadratic), 0}, /* Model4QuadraticDampingFriction */
    {0x0a02903au, 'R', 0, offsetof(tmuf_vehicle_tuning, radius_steering.captured_angle_rate), 0}, /* Model4SteerAngleAndStateRadius */
    {0x0a02903au, 'R', 1, offsetof(tmuf_vehicle_tuning, radius_steering.captured_angle_radius_scale), 0}, /* Model4SteerAngleAndStateRadius */
    {0x0a02903bu, 'R', 0, offsetof(tmuf_vehicle_tuning, radius_steering.capture_exit_side_speed_max), 0}, /* Model4StateExitSideSpeedMax */
    {0x0a02903cu, 'R', 0, offsetof(tmuf_vehicle_tuning, radius_steering.steer_angle_from_input_scale), 0}, /* Model4SteerAngleInputScale */
    {0x0a029041u, 'R', 0, offsetof(tmuf_vehicle_tuning, slip_response.rollover_torque_cap), 0}, /* Model5RolloverTorqueCap */
    {0x0a029008u, 'R', 0, offsetof(tmuf_vehicle_tuning, geared_drive.transmission.reverse_speed_norm), 0}, /* M6ReverseAndTurboImpulse */
    {0x0a029008u, 'R', 1, offsetof(tmuf_vehicle_tuning, turbo.impulse_scale_a), 0}, /* M6ReverseAndTurboImpulse */
    {0x0a029009u, 'R', 0, offsetof(tmuf_vehicle_tuning, geared_drive.forward_accel_base), 0}, /* M6ForwardAccelBase */
    {0x0a029027u, 'R', 0, offsetof(tmuf_vehicle_tuning, geared_drive.slipping_steer_torque_scale), 0}, /* M6SlippingSteerAndFrictionBlend */
    {0x0a029027u, 'R', 1, offsetof(tmuf_vehicle_tuning, geared_drive.side_friction_slip_blend), 0}, /* M6SlippingSteerAndFrictionBlend */
    {0x0a02902eu, 'R', 0, offsetof(tmuf_vehicle_tuning, steering.slow_down_scale), 0}, /* M6SteerSlowDown */
    {0x0a029031u, 'R', 0, offsetof(tmuf_vehicle_tuning, geared_drive.speed_limit_force), 0}, /* M6SpeedLimitForce */
    {0x0a029031u, 'R', 1, offsetof(tmuf_vehicle_tuning, geared_drive.force_z_scale), 0}, /* M6SpeedLimitForce */
    {0x0a029044u, 'R', 0, offsetof(tmuf_vehicle_tuning, geared_drive.slip_ratio_scale), 0}, /* M6SlipRatioScale */
    {0x0a02904du, 'R', 0, offsetof(tmuf_vehicle_tuning, geared_drive.current_force_torque_min), 0}, /* M6CurrentForceTorqueMin */
    {0x0a02904eu, 'R', 0, offsetof(tmuf_vehicle_tuning, geared_drive.current_torque_x_scale), 0}, /* M6CurrentTorqueScale */
    {0x0a02904eu, 'R', 1, offsetof(tmuf_vehicle_tuning, geared_drive.current_torque_z_scale), 0}, /* M6CurrentTorqueScale */
    {0x0a02905cu, 'R', 0, offsetof(tmuf_vehicle_tuning, geared_drive.forward_accel_cap_when_slipping_reverse), 0}, /* M6ReverseForwardAccelCaps */
    {0x0a02905cu, 'R', 1, offsetof(tmuf_vehicle_tuning, geared_drive.forward_accel_cap_reverse), 0}, /* M6ReverseForwardAccelCaps */
    {0x0a029060u, 'R', 0, offsetof(tmuf_vehicle_tuning, geared_drive.transmission.reverse_speed_norm), 0}, /* M6ReverseTurboFull */
    {0x0a029060u, 'R', 1, offsetof(tmuf_vehicle_tuning, turbo.impulse_scale_a), 0}, /* M6ReverseTurboFull */
    {0x0a029060u, 'R', 2, offsetof(tmuf_vehicle_tuning, turbo.impulse_scale_b), 0}, /* M6ReverseTurboFull */
    {0x0a029060u, 'N', 0, offsetof(tmuf_vehicle_tuning, turbo.duration_a), 0}, /* M6ReverseTurboFull */
    {0x0a029060u, 'N', 1, offsetof(tmuf_vehicle_tuning, turbo.duration_b), 0}, /* M6ReverseTurboFull */
    {0x0a029062u, 'R', 0, offsetof(tmuf_vehicle_tuning, geared_drive.dirt_slide_side_force_scale), 0}, /* M6Mat6SlideSideForceScale */
    {0x0a029063u, 'R', 0, offsetof(tmuf_vehicle_tuning, geared_drive.dirt_slide_gate_scale), 0}, /* M6Mat6SlideGateScale */
    {0x0a029064u, 'R', 0, offsetof(tmuf_vehicle_tuning, geared_drive.dirt_slide_forward_force_scale), 0}, /* M6Mat6SlideForwardScale */
    {0x0a029065u, 'R', 0, offsetof(tmuf_vehicle_tuning, geared_drive.dirt_slide_forward_gate_scale), 0}, /* M6Mat6SlideForwardGateScale */
    {0x0a02904bu, 'R', 1, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.reverse_force_threshold), 0}, /* M6ReverseBurnoutForceThresholdLegacy */
    {0x0a02904fu, 'R', 0, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.donut_speed_high), 0}, /* M6DonutAndBurnoutRadius */
    {0x0a029051u, 'R', 0, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.side_force_fade_scale), 0}, /* M6BurnoutSideForceFadeScale */
    {0x0a029053u, 'R', 0, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.radius_correction_speed_scale), 0}, /* M6BurnoutRadiusCorrectionSpeedScale */
    {0x0a02905du, 'R', 0, offsetof(tmuf_vehicle_tuning, feedback.force_divisor), 0}, /* M6Full */
    {0x0a02905du, 'R', 1, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.reverse_force_threshold), 0}, /* M6Full */
    {0x0a02905du, 'R', 2, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.lateral_correction_scale), 0}, /* M6Full */
    {0x0a02905du, 'R', 3, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.donut_speed_low), 0}, /* M6Full */
    {0x0a02905du, 'R', 4, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.angle_torque_scale), 0}, /* M6Full */
    {0x0a02905du, 'R', 5, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.radius_correction_scale), 0}, /* M6Full */
    {0x0a02905du, 'R', 6, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.radius_min), 0}, /* M6Full */
    {0x0a02905du, 'R', 7, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.tangent_speed_max), 0}, /* M6Full */
    {0x0a02905du, 'R', 8, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.angular_damping_linear), 0}, /* M6Full */
    {0x0a02905du, 'R', 9, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.angle_return_quadratic), 0}, /* M6Full */
    {0x0a02905du, 'R', 10, offsetof(tmuf_vehicle_tuning, geared_drive.per_slipping_wheel_accel_scale), 0}, /* M6Full */
    {0x0a02905du, 'R', 11, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.drive_fade_scale), 0}, /* M6Full */
    {0x0a02905du, 'R', 12, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.exit_accel_fade_scale), 0}, /* M6Full */
    {0x0a02905du, 'R', 13, offsetof(tmuf_vehicle_tuning, geared_drive.low_speed_b_slipping_grip_scale), 0}, /* M6Full */
    {0x0a02905du, 'R', 14, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.exit_side_friction_scale), 0}, /* M6Full */
    {0x0a02905du, 'R', 15, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.exit_steer_grip_scale), 0}, /* M6Full */
    {0x0a02905du, 'R', 16, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.exit_min_speed), 0}, /* M6Full */
    {0x0a02905du, 'R', 17, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.angle_limit), 0}, /* M6Full */
    {0x0a02905du, 'R', 18, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.wheel_angular_speed_override), 0}, /* M6Full */
    {0x0a02905du, 'R', 19, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.angle_limit_positive), 0}, /* M6Full */
    {0x0a02905du, 'R', 20, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.angle_limit_negative), 0}, /* M6Full */
    {0x0a02905du, 'R', 21, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.exit_bonus_accel_scale), 0}, /* M6Full */
    {0x0a02905du, 'R', 22, offsetof(tmuf_vehicle_tuning, geared_drive.input.engine_input_maximum), 0}, /* M6Full */
    {0x0a02905du, 'N', 0, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.duration_ticks), 0}, /* M6Full */
    {0x0a02905du, 'N', 1, offsetof(tmuf_vehicle_tuning, geared_drive.burnout.exit_duration_ticks), 0}, /* M6Full */
    {0x0a029056u, 'R', 0, offsetof(tmuf_vehicle_tuning, geared_drive.input.burnout_hold_input_rise), 0}, /* M6InputRiseFall */
    {0x0a029056u, 'R', 1, offsetof(tmuf_vehicle_tuning, geared_drive.input.airborne_input_rise), 0}, /* M6InputRiseFall */
    {0x0a029056u, 'R', 2, offsetof(tmuf_vehicle_tuning, geared_drive.input.airborne_input_fall), 0}, /* M6InputRiseFall */
    {0x0a029058u, 'R', 0, offsetof(tmuf_vehicle_tuning, geared_drive.input.ground_input_brake), 0}, /* M6GroundInputBrake */
    {0x0a029059u, 'R', 0, offsetof(tmuf_vehicle_tuning, geared_drive.input.ground_input_rise), 0}, /* M6GroundModeInputHighWindow */
    {0x0a029059u, 'R', 1, offsetof(tmuf_vehicle_tuning, geared_drive.input.forward_transition_speed_high), 0}, /* M6GroundModeInputHighWindow */
    {0x0a029059u, 'R', 2, offsetof(tmuf_vehicle_tuning, geared_drive.input.transition_input_rise), 0}, /* M6GroundModeInputHighWindow */
    {0x0a029059u, 'R', 3, offsetof(tmuf_vehicle_tuning, geared_drive.input.ground_input_fall), 0}, /* M6GroundModeInputHighWindow */
    {0x0a02905au, 'R', 0, offsetof(tmuf_vehicle_tuning, geared_drive.input.reverse_transition_speed_high), 0}, /* M6ModeInputLowWindow */
    {0x0a02905au, 'R', 1, offsetof(tmuf_vehicle_tuning, geared_drive.input.forward_transition_speed_low), 0}, /* M6ModeInputLowWindow */
    {0x0a02905au, 'R', 2, offsetof(tmuf_vehicle_tuning, geared_drive.input.reverse_transition_speed_low), 0}, /* M6ModeInputLowWindow */
    {0x0a029010u, 'N', 0, offsetof(tmuf_vehicle_tuning, handling_model), 0}, /* ForceModelAndM6SideForceTorque */
    {0x0a02900du, 'N', 0, offsetof(tmuf_vehicle_tuning, contact_response.single_material), 0}, /* SingleMaterialRef */
    {0x0a02900eu, 'N', 0, offsetof(tmuf_vehicle_tuning, wheel_force_mode), 0}, /* WheelForceMode */
    {0x0a029035u, 'N', 0, offsetof(tmuf_vehicle_tuning, slip_response.slip_slowdown_enabled), 1}, /* Model5SlipSlowdownEnabled */
    {0x0a02901eu, 'N', 0, offsetof(tmuf_vehicle_tuning, body_air_response.air_control_memory_tick_window), 0}, /* AirControlMemoryTickWindow */
    {0x0a02902fu, 'N', 0, offsetof(tmuf_vehicle_tuning, turbo.duration_a), 0}, /* TurboDuration */
    {0x0a02903eu, 'N', 0, offsetof(tmuf_vehicle_tuning, slip_response.lateral_slow_down_tick_window), 0}, /* Model45LateralSlowDownTicks */
    {0x0a029042u, 'N', 0, offsetof(tmuf_vehicle_tuning, slip_response.steering_memory_ticks), 0}, /* Model5SteeringMemoryTicks */
    {0x0a029043u, 'N', 0, offsetof(tmuf_vehicle_tuning, slip_response.slip_slowdown_ticks), 0}, /* Model5SlipSlowdownTicks */
};

/* Curves: (chunk, index among the chunk's node references, destination). */
typedef struct curve_binding {
  uint32_t chunk;
  uint32_t node_index;
  size_t offset;
  int optional;
} curve_binding;

#define CURVE(chunk, index, member, opt) {chunk, index, offsetof(tmuf_vehicle_tuning, curves.member), opt}
static const curve_binding CURVES[] = {
    CURVE(0x0a029024u, 0, slip_response_accel_from_speed, 0),
    CURVE(0x0a02902au, 0, lateral_contact_slow_down_from_speed, 0),
    CURVE(0x0a02902bu, 0, steer_slow_down_from_speed, 0),
    CURVE(0x0a029030u, 0, steering_drive_torque_from_speed, 0),
    CURVE(0x0a029028u, 0, max_side_friction_from_speed, 0),
    CURVE(0x0a029029u, 0, rollover_lateral_from_speed, 0),
    CURVE(0x0a02902cu, 0, rollover_lateral_coefficient_from_angle, 0),
    CURVE(0x0a029036u, 0, radius_steering_radius_from_speed, 0),
    CURVE(0x0a029038u, 0, radius_steering_max_friction_from_speed, 0),
    CURVE(0x0a02903du, 0, slip_response_slipping_accel_from_speed, 0),
    CURVE(0x0a029046u, 2, splash_vertical_impulse, 0),
    CURVE(0x0a029046u, 0, splash_horizontal_impulse, 0),
    CURVE(0x0a029046u, 1, water_friction_from_speed, 0),
    CURVE(0x0a029049u, 0, suspension_damper_absorb_modulation, 0),
    CURVE(0x0a02905du, 0, reverse_gear_accel_from_speed, 0),
    CURVE(0x0a029052u, 0, burnout_rollover_lateral_from_speed_ratio, 0),
    CURVE(0x0a02904fu, 0, burnout_radius_from_speed, 0),
    CURVE(0x0a02905du, 1, burnout_lateral_speed_from_radius, 0),
    CURVE(0x0a02905du, 3, donut_rollover_from_speed, 0),
    CURVE(0x0a02905du, 2, burnout_rollover_from_speed, 0),
    CURVE(0x0a02905eu, 0, air_control_z_scale, 0),
    CURVE(0x0a029061u, 0, wheel_visual_steer_angle_from_speed, 1),
    CURVE(0x0a02905bu, 0, surface_feedback, 0),
};

static void authored_curve(tmuf_curve *c, const float (*keys)[2], uint32_t n) {
  memset(c, 0, sizeof *c);
  c->present = 1;
  c->count = n;
  for (uint32_t i = 0; i < n; i++) {
    c->x[i] = keys[i][0];
    c->y[i] = keys[i][1];
  }
}

static float field_real(const tmuf_tuning_field *f) {
  float v;
  memcpy(&v, &f->raw, 4);
  return v;
}

/* Field of the given kind with the given ordinal in the chunk. */
static const tmuf_tuning_field *nth_field(const tmuf_tuning_chunk *c, char kind, uint32_t index) {
  for (uint32_t i = 0; i < c->field_count; i++) {
    char k = c->fields[i].kind;
    if (kind == 'N' && k == 'B')
      k = 'N'; /* booleans are archived naturals */
    if (k == kind && index-- == 0)
      return &c->fields[i];
  }
  return NULL;
}

static int load_curve(tmuf_curve *out, tmuf_assets *assets, tmuf_asset *owner, tmuf_gbx_node *node) {
  tmuf_asset *ka;
  tmuf_gbx_node *kn = tmuf_assets_follow(assets, owner, node, &ka);
  if (!kn || !kn->data || !kn->cls || kn->cls->id != 0x05002000u)
    return 0;
  const tmuf_func_keys *k = kn->data;
  uint32_t n = k->x_count < k->y_count ? k->x_count : k->y_count;
  if (n > TMUF_MAX_CURVE_KEYS)
    return 0;
  memset(out, 0, sizeof *out);
  out->present = 1;
  out->constant = k->mode == 1u;
  out->count = n;
  for (uint32_t i = 0; i < n; i++) {
    out->x[i] = k->xs[i];
    out->y[i] = k->ys[i];
  }
  return 1;
}

static int load_array(float *dst, uint32_t *count, const tmuf_tuning_field *f) {
  if (!f || f->kind != 'F' || f->float_count > TMUF_MAX_GEARS)
    return 0;
  memcpy(dst, f->floats, sizeof(float) * f->float_count);
  *count = f->float_count;
  return 1;
}

int tmuf_vehicle_tuning_decode(tmuf_vehicle_tuning *t, tmuf_assets *assets, tmuf_asset *owner,
                               const tmuf_car_tuning *raw, char *err, size_t err_size) {
  tmuf_vehicle_tuning_defaults(t);
  float gear[TMUF_MAX_GEARS], up[TMUF_MAX_GEARS], down[TMUF_MAX_GEARS], rpm[TMUF_MAX_GEARS];
  uint32_t n_gear = 0, n_up = 0, n_down = 0, n_rpm = 0;
  int have_curve[sizeof CURVES / sizeof CURVES[0]];
  memset(have_curve, 0, sizeof have_curve);

  for (uint32_t ci = 0; ci < raw->chunk_count; ci++) {
    const tmuf_tuning_chunk *c = &raw->chunks[ci];
    for (size_t b = 0; b < sizeof SCALARS / sizeof SCALARS[0]; b++) {
      const scalar_binding *sb = &SCALARS[b];
      if (sb->chunk != c->chunk_id)
        continue;
      const tmuf_tuning_field *f = nth_field(c, sb->kind, sb->index);
      if (!f) {
        snprintf(err, err_size, "tuning chunk %08x lacks %c[%u]", c->chunk_id, sb->kind, sb->index);
        return 1;
      }
      uint8_t *dst = (uint8_t *)t + sb->offset;
      if (sb->kind == 'R') {
        float v = field_real(f);
        if (!isfinite(v)) {
          snprintf(err, err_size, "tuning chunk %08x: non-finite value", c->chunk_id);
          return 1;
        }
        memcpy(dst, &v, 4);
      } else {
        uint32_t v = sb->is_bool ? (f->raw != 0u) : f->raw;
        memcpy(dst, &v, 4);
      }
    }
    /* derived invariants (the game's chunk handlers copy these) */
    switch (c->chunk_id) {
    case 0x0a029005u:
      t->body_air_response.airborne_solid_feedback1 = t->body_air_response.grounded_solid_feedback1;
      break;
    case 0x0a029008u:
      t->turbo.impulse_scale_b = t->turbo.impulse_scale_a;
      break;
    case 0x0a02900au:
      t->body_air_response.air_torque_quadratic_coef = 0.0f;
      break;
    case 0x0a02902fu:
      t->turbo.duration_b = t->turbo.duration_a;
      break;
    case 0x0a02905du:
      if (!load_array(gear, &n_gear, nth_field(c, 'F', 0)) || !load_array(up, &n_up, nth_field(c, 'F', 1)) ||
          !load_array(down, &n_down, nth_field(c, 'F', 2))) {
        snprintf(err, err_size, "tuning: bad transmission arrays");
        return 1;
      }
      break;
    case 0x0a029057u:
      if (!load_array(rpm, &n_rpm, nth_field(c, 'F', 0))) {
        snprintf(err, err_size, "tuning: bad rpm array");
        return 1;
      }
      break;
    }
    for (size_t b = 0; b < sizeof CURVES / sizeof CURVES[0]; b++) {
      if (CURVES[b].chunk != c->chunk_id || have_curve[b])
        continue;
      const tmuf_tuning_field *f = nth_field(c, 'O', CURVES[b].node_index);
      if (f && f->node && load_curve((tmuf_curve *)((uint8_t *)t + CURVES[b].offset), assets, owner, f->node))
        have_curve[b] = 1;
    }
  }
  for (size_t b = 0; b < sizeof CURVES / sizeof CURVES[0]; b++)
    if (!have_curve[b] && !CURVES[b].optional) {
      snprintf(err, err_size, "tuning: missing curve %zu", b);
      return 1;
    }
  static const float RAMP1[3][2] = {{0.0f, 0.0f}, {30.0f, 0.1f}, {100.0f, 0.3f}};
  static const float RAMP0[3][2] = {{0.0f, 0.0f}, {30.0f, 0.01f}, {100.0f, 0.05f}};
  static const float D30[3][2] = {{0.0f, 0.0f}, {30.0f, 0.0f}, {100.0f, 1.0f}};
  authored_curve(&t->curves.vehicle_feedback_ramp1, RAMP1, 3);
  authored_curve(&t->curves.vehicle_feedback_ramp0, RAMP0, 3);
  authored_curve(&t->curves.vehicle_default30_to100, D30, 3);

  /* transmission: derived target input bias and rpm deltas */
  tmuf_vt_transmission *tr = &t->geared_drive.transmission;
  if (n_gear) {
    if (n_up != n_gear || n_down != n_gear || n_rpm != n_gear) {
      snprintf(err, err_size, "tuning: transmission array sizes differ");
      return 1;
    }
    float emax = t->geared_drive.input.engine_input_maximum;
    tr->gear_count = n_gear;
    memcpy(tr->gear_speed_ratio, gear, sizeof(float) * n_gear);
    memcpy(tr->upshift_threshold, up, sizeof(float) * n_gear);
    memcpy(tr->downshift_threshold, down, sizeof(float) * n_gear);
    memcpy(tr->rpm_wanted, rpm, sizeof(float) * n_gear);
    for (uint32_t i = 0; i < n_gear; i++)
      tr->target_input_bias[i] = tr->rpm_delta[i] = 0.0f;
    for (uint32_t i = 2; i < n_gear; i++) {
      float ratio = gear[i] / gear[i - 1];
      float offset = (rpm[i] - up[i - 1] * ratio) * emax;
      tr->target_input_bias[i] = ratio * tr->target_input_bias[i - 1] + offset;
    }
    for (uint32_t i = 1; n_gear >= 2 && i < n_gear - 1; i++) {
      if (emax == 0.0f)
        tr->rpm_delta[i] = 0.0f;
      else
        tr->rpm_delta[i] = (down[i + 1] - tr->target_input_bias[i + 1] / emax) * gear[i] / gear[i + 1] +
                           tr->target_input_bias[i] / emax;
    }
  }
  return 0;
}
