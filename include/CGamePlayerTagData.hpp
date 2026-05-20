#ifndef CGAMEPLAYERTAGDATA_HPP
#define CGAMEPLAYERTAGDATA_HPP

#include "typedefs.h"

struct CGamePlayerTagData {
    void** vftable;
    byte _padding_0x4[16];
    CPlugBitmap * field_0x14; // accesses: 2

    // Member Functions
    CPlugBitmap * __thiscall GetBitmap(CGamePlayerTagData *this,CGamePlayerTagData *param_1);
};

#endif // CGAMEPLAYERTAGDATA_HPP
