#ifndef CGAMECTNCOLLECTION_HPP
#define CGAMECTNCOLLECTION_HPP

#include "typedefs.h"

struct CGameCtnCollection {
    byte _padding_0x0[60];
    CGameCtnZone * field_0x3c; // accesses: 1

    // Member Functions
    CGameCtnZone * __thiscall GetZone(CGameCtnCollection *this,CGameCtnCollection *param_1,CMwId *param_2);
    CGameCtnZone * __thiscall GetZoneFromLandBlockInfo (CGameCtnCollection *this,CGameCtnCollection *param_1,CGameCtnBlockInfo *param_2);
    void __thiscall SetCurrentZone (CGameCtnCollection *this,CGameCtnCollection *param_1,CMwId *param_2);
};

#endif // CGAMECTNCOLLECTION_HPP
