#ifndef CHMSFORCEFIELDUNIFORM_HPP
#define CHMSFORCEFIELDUNIFORM_HPP

#include "typedefs.h"

struct CHmsForceFieldUniform {
    byte _padding_0x0[84];
    int field_0x54; // accesses: 1
    byte _padding_0x58[4];
    undefined4 field_0x5c; // accesses: 2
    undefined4 field_0x60; // accesses: 2
    undefined4 field_0x64; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CHmsForceFieldUniform (CHmsForceFieldUniform *this,CHmsForceFieldUniform *param_1);
    CMwClassInfo * __thiscall MwGetClassInfo(CHmsForceFieldUniform *this,CFuncSegment *param_1);
    CMwNod * __cdecl MwNewCHmsForceFieldUniform(void);
    GmVec3 __thiscall GetValue (CHmsForceFieldUniform *this,CFuncColorGradient *param_1,float param_2);
    int __thiscall MwIsKindOf (CHmsForceFieldUniform *this,CMwCmdAffectParam *param_1,ulong param_2);
    ulong __thiscall GetChunkInfo(CHmsForceFieldUniform *this,CFuncSegment *param_1,ulong param_2);
    ulong __thiscall GetMwClassId(CHmsForceFieldUniform *this,CControlStyle *param_1);
    ulong __thiscall GetUidChunkFromIndex (CHmsForceFieldUniform *this,CMwCmdExpIso4Ident *param_1,ulong param_2);
    void * __thiscall _scalar_deleting_destructor_ (CHmsForceFieldUniform *this,CPfmHeap *param_1,uint param_2);
    void __thiscall Chunk (CHmsForceFieldUniform *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3);
    void __thiscall ~CHmsForceFieldUniform (CHmsForceFieldUniform *this,CHmsForceFieldUniform *param_1);
};

#endif // CHMSFORCEFIELDUNIFORM_HPP
