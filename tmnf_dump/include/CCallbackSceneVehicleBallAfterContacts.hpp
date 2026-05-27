#ifndef CCALLBACKSCENEVEHICLEBALLAFTERCONTACTS_HPP
#define CCALLBACKSCENEVEHICLEBALLAFTERCONTACTS_HPP

#include "typedefs.h"

struct CCallbackSceneVehicleBallAfterContacts {
    void** vftable;

    // Member Functions
    void __thiscall AfterContacts (CCallbackSceneVehicleBallAfterContacts *this, CCallbackSceneVehicleBallAfterContacts *param_1,CHmsItem *param_2);
};

#endif // CCALLBACKSCENEVEHICLEBALLAFTERCONTACTS_HPP
