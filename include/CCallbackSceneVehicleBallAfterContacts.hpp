#ifndef CCALLBACKSCENEVEHICLEBALLAFTERCONTACTS_HPP
#define CCALLBACKSCENEVEHICLEBALLAFTERCONTACTS_HPP

#include "typedefs.h"

struct CSceneVehicleBall;

struct CCallbackSceneVehicleBallAfterContacts {
    byte _padding_0x0[64];
    CSceneVehicleBall * field_0x40; // accesses: 1

    // Member Functions
    void __thiscall AfterContacts (CCallbackSceneVehicleBallAfterContacts *this, CCallbackSceneVehicleBallAfterContacts *param_1,CHmsItem *param_2);
};

#endif // CCALLBACKSCENEVEHICLEBALLAFTERCONTACTS_HPP
