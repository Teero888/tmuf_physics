#ifndef CGAMEPLAYERTAGDATA_HPP
#define CGAMEPLAYERTAGDATA_HPP

#include "typedefs.h"

struct CPlugBitmap;

struct CGamePlayerTagData {
    byte _padding_0x0[20];
    CPlugBitmap * field_0x14; // accesses: 2

    // Member Functions
    CPlugBitmap * __thiscall GetBitmap(CGamePlayerTagData *this,CGamePlayerTagData *param_1);
};

#endif // CGAMEPLAYERTAGDATA_HPP
