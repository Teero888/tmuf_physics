#ifndef CGAMEPLAYERTAGDATA_HPP
#define CGAMEPLAYERTAGDATA_HPP

#include "typedefs.h"

struct CGamePlayerTagData {
    byte _padding_0x0[20];
    int field_0x14; // accesses: 2

    // Member Functions
    CPlugBitmap * __thiscall GetBitmap(CGamePlayerTagData *this,CGamePlayerTagData *param_1);
};

#endif // CGAMEPLAYERTAGDATA_HPP
