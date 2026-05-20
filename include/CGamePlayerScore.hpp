#ifndef CGAMEPLAYERSCORE_HPP
#define CGAMEPLAYERSCORE_HPP

#include "typedefs.h"

struct CGamePlayerScore {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1

    // Member Functions
    void __thiscall ForceNeedAllCampaignRecordsUpdate (CGamePlayerScore *this,CGamePlayerScore *param_1);
};

#endif // CGAMEPLAYERSCORE_HPP
