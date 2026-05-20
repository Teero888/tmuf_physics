#ifndef CGAMENOD_HPP
#define CGAMENOD_HPP

#include "typedefs.h"

struct CGameNod {
    byte _padding_0x0[24];
    undefined4 field_0x18; // accesses: 1

    // Member Functions
    ulong __thiscall GetChunkInfo(CGameNod *this,CFuncSegment *param_1,ulong param_2);
    void __thiscall CGameNod(CGameNod *this,CGameNod *param_1);
    void __thiscall Chunk(CGameNod *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3);
    void __thiscall ~CGameNod(CGameNod *this,CGameNod *param_1);
};

#endif // CGAMENOD_HPP
