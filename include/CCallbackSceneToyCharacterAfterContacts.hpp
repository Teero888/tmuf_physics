#ifndef CCALLBACKSCENETOYCHARACTERAFTERCONTACTS_HPP
#define CCALLBACKSCENETOYCHARACTERAFTERCONTACTS_HPP

#include "typedefs.h"

struct CCallbackSceneToyCharacterAfterContacts {
    void** vftable;

    // Member Functions
    void __thiscall AfterContacts (CCallbackSceneToyCharacterAfterContacts *this, CCallbackSceneVehicleBallAfterContacts *param_1,CHmsItem *param_2);
};

#endif // CCALLBACKSCENETOYCHARACTERAFTERCONTACTS_HPP
