#ifndef CGAMECTNCOLLECTION_HPP
#define CGAMECTNCOLLECTION_HPP

#include "typedefs.h"

struct CGameCtnCollection {
    byte _padding_0x0[28];
    int field_0x1c; // accesses: 4
    byte _padding_0x20[16];
    int field_0x30; // accesses: 4
    byte _padding_0x34[8];
    CGameCtnZone * field_0x3c; // accesses: 1

    // Member Functions
    CGameCtnZone * __thiscall GetZone(CGameCtnCollection *this,CGameCtnCollection *param_1,CMwId *param_2);
    CGameCtnZone * __thiscall GetZoneFromLandBlockInfo (CGameCtnCollection *this,CGameCtnCollection *param_1,CGameCtnBlockInfo *param_2);
    void __thiscall SetCurrentZone (CGameCtnCollection *this,CGameCtnCollection *param_1,CMwId *param_2);
};

#endif // CGAMECTNCOLLECTION_HPP
