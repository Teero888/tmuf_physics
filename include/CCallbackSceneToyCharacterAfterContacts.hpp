#ifndef CCALLBACKSCENETOYCHARACTERAFTERCONTACTS_HPP
#define CCALLBACKSCENETOYCHARACTERAFTERCONTACTS_HPP

#include "typedefs.h"

struct CCallbackSceneToyCharacterAfterContacts {
    byte _padding_0x0[64];
    int * field_0x40; // accesses: 1

    // Member Functions
    void __thiscall AfterContacts (CCallbackSceneToyCharacterAfterContacts *this, CCallbackSceneVehicleBallAfterContacts *param_1,CHmsItem *param_2);
};

#endif // CCALLBACKSCENETOYCHARACTERAFTERCONTACTS_HPP
