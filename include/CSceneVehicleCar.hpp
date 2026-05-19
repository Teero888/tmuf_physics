// Derived from: gbx-tools-3d/GbxTools3D/GbxTools3D.Client/Components/Modules/GhostControls.razor.cs

#ifndef CSCENEVEHICLECAR_HPP
#define CSCENEVEHICLECAR_HPP

#include "typedefs.h"
#include "GmVec3.hpp"
#include "GmQuat.hpp"

class CSceneVehicleCar {
public:
  struct Sample {
    TimeInt32 Time;
    GmVec3 Position;
    GmQuat Rotation;
    float VelocitySpeed;
    float RPM;
    float FLWheelRotation;
    float FRWheelRotation;
    float RLWheelRotation;
    float RRWheelRotation;
    float SteerFront;
    float FLDampenLen;
    float FRDampenLen;
    float RLDampenLen;
    float RRDampenLen;
    bool FLIsSliding;
    bool FRIsSliding;
    bool RLIsSliding;
    bool RRIsSliding;
    bool FLOnGround;
    bool FROnGround;
    bool RLOnGround;
    bool RROnGround;
  };
};

#endif // CSCENEVEHICLECAR_HPP
