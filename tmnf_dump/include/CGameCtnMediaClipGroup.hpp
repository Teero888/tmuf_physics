#ifndef CGAMECTNMEDIACLIPGROUP_HPP
#define CGAMECTNMEDIACLIPGROUP_HPP

#include "typedefs.h"

struct CGameCtnMediaClipGroup {
    void** vftable;
    byte _final_padding[0x28]; // Total size: 0x2c

    // Member Functions
    ulong __thiscall ClipFind (CGameCtnMediaClipGroup *this,CGameCtnMediaClipGroup *param_1,GmNat3 *param_2);
};

#endif // CGAMECTNMEDIACLIPGROUP_HPP
