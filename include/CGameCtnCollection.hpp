#ifndef CGAMECTNCOLLECTION_HPP
#define CGAMECTNCOLLECTION_HPP

#include "typedefs.h"

struct CGameCtnCollection {
    void** vftable;
    byte _padding_0x4[56];
    CGameCtnZone * field_0x3c; // accesses: 1
    byte _final_padding[0x128]; // Total size: 0x168

    // Member Functions
    CGameCtnZone * __thiscall GetZone(CGameCtnCollection *this,CGameCtnCollection *param_1,CMwId *param_2);
    CGameCtnZone * __thiscall GetZoneFromLandBlockInfo (CGameCtnCollection *this,CGameCtnCollection *param_1,CGameCtnBlockInfo *param_2);
    void __thiscall SetCurrentZone (CGameCtnCollection *this,CGameCtnCollection *param_1,CMwId *param_2);
};

#endif // CGAMECTNCOLLECTION_HPP
