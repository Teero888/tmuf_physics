#ifndef CSCENEMOBILABSORBCONTACT_HPP
#define CSCENEMOBILABSORBCONTACT_HPP

#include "typedefs.h"

struct CSceneMobilAbsorbContact {
    byte _padding_0x0[64];
    int * field_0x40; // accesses: 1

    // Member Functions
    void __thiscall AbsorbContact (CSceneMobilAbsorbContact *this,CSceneMobilAbsorbContact *param_1,CHmsItem *param_2, CHmsPhysicalContact *param_3);
};

#endif // CSCENEMOBILABSORBCONTACT_HPP
