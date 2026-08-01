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

// .rdata pointer slot 0x00b2c178 resolves to the zero scalar used in the
// front-wheel rotation expression.
inline constexpr float kZero = 0.0f;

// .rdata 0x00b59790: Y component installed by the
// CHmsForceFieldUniform constructor. CHmsZoneDynamic multiplies this by the
// physical object's gravity coefficient and mass before accumulating it.
inline constexpr float kDefaultUniformGravity =
    -9.81000041961669921875f; // 0xC11CF5C3

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

} // namespace TmForeverPhysicsConstants
