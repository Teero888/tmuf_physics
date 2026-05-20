#ifndef CGAMEPLAYERSCORE_HPP
#define CGAMEPLAYERSCORE_HPP

#include "typedefs.h"

struct CGamePlayerScore {
    void** vftable;
    byte _final_padding[0x19c]; // Total size: 0x1a0

    // Member Functions
    void __thiscall ForceNeedAllCampaignRecordsUpdate (CGamePlayerScore *this,CGamePlayerScore *param_1);
};

#endif // CGAMEPLAYERSCORE_HPP
