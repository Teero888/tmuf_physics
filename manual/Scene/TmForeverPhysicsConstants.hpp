#pragma once

// Scalar data read directly from TmForeverFixed.exe. These values deliberately
// preserve the float-to-double widening performed by the original executable;
// rounded decimal approximations can change curve lookups and branch thresholds.
namespace TmForeverPhysicsConstants {

// .rdata 0x00b3d2a8: double initialized from the single-precision value 3.6f.
inline constexpr double kSpeedCurveScale = 3.599999904632568359375;

// .rdata 0x00b2c060.
inline constexpr float kNegativeOne = -1.0f;

// .rdata 0x00b313b8: double initialized from 0.5f.
inline constexpr double kHalf = 0.5;

// .rdata 0x00b36110: double initialized from the game's single-precision pi.
inline constexpr double kPi = 3.1415927410125732421875;

// .rdata 0x00b362c0: double initialized from 0.1f.
inline constexpr double kInputThreshold = 0.100000001490116119140625;

// .data 0x00d0ac60: squared-length threshold used before normalizing a
// wheel/contact vector.
inline constexpr float kNormalizeSquaredEpsilon = 9.99999943962492920972e-11f;

// .data 0x00d1a938. Sphere/mesh contact generation uses the same 1e-10f
// squared-length guard before normalizing triangle edges and vertex deltas.
inline constexpr float kCollisionNormalizeSquaredEpsilon =
    9.99999943962492920972e-11f; // 0x2EDBE6FE

// .data 0x00d1fb48. TransformByNOMat uses this before normalizing a
// reflection-recomputed triangle plane.
inline constexpr float kMeshTransformNormalSquaredEpsilon =
    9.99999943962492920972e-11f; // 0x2EDBE6FE

// .data 0x00d1fc38. GmSurfPolygon::ComputeNormalFromVertices falls back to
// +X when the generated normal is shorter than this squared-length threshold.
inline constexpr float kPolygonNormalSquaredEpsilon =
    9.99999943962492920972e-11f; // 0x2EDBE6FE

// .rdata 0x00bbdc5c. The native sphere/mesh edge-interior branch has a wider
// guard than its vertex branch and rejects squared distances at or below
// 1e-5f before producing a normal.
inline constexpr float kCollisionEdgeSquaredDistanceEpsilon =
    9.99999974737875163555e-6f; // 0x3727C5AC

// .rdata 0x00b55d98. Collision-group preparation uses this threshold when
// comparing two corpuses' squared linear speeds.
inline constexpr float kCollisionSpeedSquaredDifferenceEpsilon =
    9.99999974737875163555e-6f; // 0x3727C5AC

// .rdata pointer slot 0x00b2c178 resolves to the zero scalar used in the
// front-wheel rotation expression.
inline constexpr float kZero = 0.0f;

// Geometry tolerances recovered from the native routines that consume them.
// Several addresses contain the same value, but keeping the constants named by
// their use makes it possible to audit each native comparison independently.

// .rdata 0x00b785dc and 0x00bbe3f8.
inline constexpr float kLineIntersectionEpsilon =
    9.99999974737875163555e-6f; // 0x3727C5AC
inline constexpr float kCoincidentSurfaceEpsilon =
    9.99999974737875163555e-6f; // 0x3727C5AC

// .data 0x00d1a8ac and 0x00d07588. These are 1e-10f, not the 1e-6f
// approximation that was previously used by GmVec4 plane construction.
inline constexpr float kPlaneNormalSquaredEpsilon =
    9.99999943962492920972e-11f; // 0x2EDBE6FE

// .rdata 0x00b31460. PlaneEqInterPlane uses this to choose a stable pair of
// coordinates for its 2x2 solve.
inline constexpr float kPlaneSolveAxisThreshold = 0.5f; // 0x3F000000

// .rdata 0x00b44a20 and 0x00b362c0. The executable stores these as doubles
// widened from 0.99f and 0.1f respectively.
inline constexpr double kPlaneNormalDotThreshold =
    0.9900000095367431640625;
inline constexpr double kPlaneDistanceThreshold = kInputThreshold;

// .rdata 0x00b59790: Y component installed by the
// CHmsForceFieldUniform constructor. CHmsZoneDynamic multiplies this by the
// physical object's gravity coefficient and mass before accumulating it.
inline constexpr float kDefaultUniformGravity =
    -9.81000041961669921875f; // 0xC11CF5C3

// .rdata 0x00B36144. CSceneVehicleCarTuning's constructor stores this at
// +0x168, and UpdateParamsFromTuning copies it to the physical object's
// maximum collision-substep distance at +0x30.
inline constexpr float kDefaultVehicleMaxDistancePerStep =
    0.300000011920928955078125f; // 0x3E99999A

// CSceneVehicleCar::WheelUpdateSpeedFromVehicleSpeed at 0x007C0EC0 uses
// these values to drive or brake an airborne wheel and to decay a wheel that
// is neither driven nor braked. The scale and decay are native doubles, so
// their full values must survive the float-to-double x87 operations.
// .rdata 0x00B9EF4C.
inline constexpr float kWheelInputEpsilon =
    9.99999974737875163555e-6f; // 0x3727C5AC
// The same +1e-5f value guards SDynaMath impulse-direction normalization;
// .rdata 0x00B574FC holds its negative counterpart for AbsorbingValMin.
inline constexpr float kImpulseDirectionEpsilon = kWheelInputEpsilon;
inline constexpr float kNegativeAbsorbingValueEpsilon =
    -9.99999974737875163555e-6f; // 0xB727C5AC

// ApplyWaterForces at 0x007C2910 accepts a body only after more than 0.5f of
// depth and restricts its rebound branch to less than the widened 0.9f value.
// The partially-submerged and downward-speed tests use exact zero/-1e-5f.
inline constexpr float kWaterMinimumDepth = kPlaneSolveAxisThreshold;
inline constexpr double kWaterReboundMaximumDepth =
    0.89999997615814208984375; // .rdata 0x00B41EA8
inline constexpr float kWaterSurfaceDeltaThreshold = 0.0f; // 0x00C418E0
inline constexpr float kWaterDownwardSpeedThreshold =
    kNegativeAbsorbingValueEpsilon;
inline constexpr float kDefaultWaterAngularFrictionSq =
    0.20000000298023223876953125f; // .rdata 0x00B33A54
inline constexpr float kDefaultWaterCollisionHeight =
    -3.4028234663852885981170418348451692544e38f; // .rdata 0x00B55DA4
// .rdata 0x00B2F718.
inline constexpr double kWheelGasAngularSpeedScale = 200.0; // 0x4069000000000000
// .rdata 0x00B9F1C0.
inline constexpr double kWheelAirborneAngularDecay =
    0.99500000476837158203125; // 0x3FEFD70A40000000
// .rdata 0x00B36ADC and 0x00B36184 respectively.
inline constexpr float kWheelAngularAcceleration = 100.0f; // 0x42C80000
inline constexpr float kWheelAngularDeceleration = -100.0f; // 0xC2C80000

// SSimulationWheel::SRealTimeState::Integrate at 0x007C1060 wraps its visual
// wheel angle over 256 full turns and rebuilds its orientation only for a
// direction vector above the native squared-length guard.
// .rdata 0x00B9EF64: 256 * the game's single-precision 2*pi value.
inline constexpr float kWheelRotationAnglePeriod =
    1608.4954833984375f; // 0x44C90FDB
// .data 0x00D06A80.
inline constexpr float kWheelDirectionSquaredEpsilon =
    9.99999943962492920972e-11f; // 0x2EDBE6FE

// IntegrateVehicle 0x7C3A50..0x7C3A76 drives the visual steering target of a
// steerable wheel with -smoothedSteer times a constant maximum angle. The
// executable spells that constant as a float 30 degrees scaled by kPi over
// 180, and stores the product back through a four-byte slot before the
// multiply, so the recorded value is the float the game actually uses:
//   .rdata 0x00B36198 float  30.0f  (0x41F00000)
//   .rdata 0x00B36110 double kPi
//   .rdata 0x00B36AB8 double 180.0  (0x4066800000000000)
inline constexpr float kWheelVisualSteeringAngleMax =
    0.523598790168762207031250f; // 0x3F060A92
inline constexpr float kWheelVisualSteeringAngleDegrees = 30.0f; // 0x41F00000
inline constexpr double kDegreesPerHalfTurn = 180.0;

// ComputeForcesModel6's reverse selector at 0x7C5A18..0x7C5B14 gates on
// lateral and forward speed with a single float from .rdata 0x00B313AC. Its
// gas and brake comparisons reuse kInputThreshold, the same .rdata 0x00B362C0
// double this file already carries, and IntegrateVehicle's steer-radius guard
// reuses kWheelInputEpsilon at .rdata 0x00B9EF4C.
inline constexpr float kReverseSpeedThreshold = 2.0f; // 0x40000000

// The forward-speed ceiling the reverse selector compares against lives at car
// +0x5CC, which is SEngine +0x30. The car constructor seeds it from
// .rdata 0x00B36194; a separate setter overwrites it with a km/h value scaled
// by kSpeedCurveScale. Leaving it at zero makes reverse unreachable from a
// standstill, because the selector needs a strictly negative forward speed.
inline constexpr float kDefaultReverseSpeedCeiling = 10.0f; // 0x41200000

// .data 0x00D1A840. GmMat3::SetUpVandDOV independently uses this guard while
// normalizing the two basis vectors it constructs.
inline constexpr float kMatrixBasisSquaredEpsilon =
    9.99999943962492920972e-11f; // 0x2EDBE6FE

// CSceneVehicleCarTuning's constructor initializes the extra ShockModel 0
// force multiplier from .rdata 0x00B33A54.
inline constexpr float kDefaultShockModel0ForceFactor =
    0.20000000298023223876953125f; // 0x3E4CCCCD

// CSceneVehicleCar::SEngine and EngineIntegrate constants. The M6 shift
// duration and the older engine's shift duration are distinct in the fixed
// executable.
// .rdata 0x00B9EFB0.
inline constexpr float kDefaultEngineMaxRpm = 11000.0f; // 0x462BE000
// .rdata 0x00B9EFC0 and 0x00B989DC.
inline constexpr float kM6ShiftDuration = 0.02500000037252902984619140625f; // 0x3CCCCCCD
inline constexpr float kM6ReverseTakeoffShiftDuration = 0.00200000009499490261077880859375f; // 0x3B03126F
// .rdata 0x00B9EFD0 and the widened copy at 0x00B9EFC8.
inline constexpr float kM6ClutchRatioTarget =
    1.14999997615814208984375f; // 0x3F933333
inline constexpr double kM6ClutchRatioTargetWide =
    1.14999997615814208984375;
// .rdata 0x00B5B8E0 and 0x00C418D8.
inline constexpr double kM6ClutchRatioResponse =
    0.300000011920928955078125;
inline constexpr double kEngineIdleRpm = 1000.0;

// Pre-Model-6 engine path at 0x007BE00B..0x007BE253.
// .rdata 0x00B80D18, 0x00B43310, 0x00B9EFB8, 0x00B36AE8,
// and 0x00B3D274.
inline constexpr float kOldEngineShiftDuration =
    0.039999999105930328369140625f; // 0x3D23D70A
inline constexpr double kOldEngineSpeedScale =
    0.20000000298023223876953125;
inline constexpr double kOldEngineShiftRpmLoss =
    1.89999997615814208984375;
inline constexpr float kOldEngineAirResponse = 3.5f; // 0x40600000
inline constexpr float kOldEngineGroundResponse = 12.0f; // 0x41400000
// .rdata 0x00BA3814: constructor default of tuning +0x2C, used as
// the legacy engine speed divisor base.
inline constexpr float kDefaultOldEngineSpeedDivisorBase =
    55.5555572509765625f; // 0x425E38E4
inline constexpr double kOldEngineLateralSpeedWeight =
    kM6ClutchRatioResponse;

// Vehicles/Media/Solid/StadiumCar.Solid.Gbx stores the four simulation-wheel
// nodes at these exact longitudinal coordinates (FLSurf/FRSurf and
// RLSurf/RRSurf). UpdateParamsFromTuning at 0x7BFFA0 builds their bounding box
// and writes twice its Z half-extent to CSceneVehicleCar +0x840.
inline constexpr float kStadiumWheelFrontZ =
    1.7820889949798583984375f; // 0x3FE41B7E
inline constexpr float kStadiumWheelRearZ =
    -1.205502033233642578125f; // 0xBF9A4DE4
inline constexpr float kStadiumWheelbase =
    2.9875910282135009765625f; // 0x403F34B1

// The same solid stores each wheel collision ellipsoid as
// (half-width, radius, radius) = (0.182f, 0.364f, 0.364f).
inline constexpr float kStadiumWheelRadius =
    0.3639999926090240478515625f; // 0x3EBA5E35

// Exact FLSurf, FRSurf, RRSurf, and RLSurf translations from the same solid.
// This order matches VehicleInitFromSolid's four-wheel buffer and the native
// force loops: the front pair first, followed by rear-right and rear-left.
inline constexpr int kStadiumWheelCount = 4;
inline constexpr float kStadiumWheelLocalX[kStadiumWheelCount] = {
    0.863012015819549560546875f,  // FLSurf, 0x3F5CEE5B
    -0.86299002170562744140625f,  // FRSurf, 0xBF5CECEA
    -0.8849999904632568359375f,   // RRSurf, 0xBF628F5C
    0.88500201702117919921875f,   // RLSurf, 0x3F628F7E
};
inline constexpr float kStadiumWheelLocalY[kStadiumWheelCount] = {
    0.352499991655349731445312f,  // FLSurf, 0x3EB47AE1
    0.352499991655349731445312f,  // FRSurf, 0x3EB47AE1
    0.352503985166549682617188f,  // RRSurf, 0x3EB47B67
    0.352503985166549682617188f,  // RLSurf, 0x3EB47B67
};
inline constexpr float kStadiumWheelLocalZ[kStadiumWheelCount] = {
    kStadiumWheelFrontZ,
    kStadiumWheelFrontZ,
    kStadiumWheelRearZ,
    kStadiumWheelRearZ,
};

// ComputeAirControl scales its angular drag direction by the double at
// .rdata 0x00B3D2C0 whenever the steering opposes the retained yaw hard
// enough. The multiply at 0x7BF405 is a QWORD fmul, so the scale is
// double-typed.
inline constexpr double kAirControlDampingScale = 3.0;

// ComputeForcesModel6 halves its assembled axial drive term whenever the car
// is in water. The gate at 0x7C6288 tests the dword ApplyWaterForces returned
// into the frame slot at function entry (0x7C3ED4, also stored to car +0x5E4),
// and 0x7C62E2 multiplies the term by the double at .rdata 0x00B313B8 with a
// QWORD fmul. That address is the same 0.5 this file already carries as
// kHalf, so the axial halving reuses it rather than introducing a duplicate.

} // namespace TmForeverPhysicsConstants
