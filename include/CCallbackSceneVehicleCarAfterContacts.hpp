#ifndef CCALLBACKSCENEVEHICLECARAFTERCONTACTS_HPP
#define CCALLBACKSCENEVEHICLECARAFTERCONTACTS_HPP

#include "typedefs.h"

struct CSceneVehicleCar;

struct CCallbackSceneVehicleCarAfterContacts {
    byte _padding_0x0[64];
    CSceneVehicleCar * field_0x40; // accesses: 1

    // Member Functions
    void __thiscall AfterContacts (CCallbackSceneVehicleCarAfterContacts *this, CCallbackSceneVehicleBallAfterContacts *param_1,CHmsItem *param_2);
};

#endif // CCALLBACKSCENEVEHICLECARAFTERCONTACTS_HPP
