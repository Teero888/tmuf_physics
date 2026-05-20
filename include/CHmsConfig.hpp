#ifndef CHMSCONFIG_HPP
#define CHMSCONFIG_HPP

#include "typedefs.h"

struct CHmsConfig {
    byte _padding_0x0[8];
    int field_0x8; // accesses: 2
    byte _padding_0xc[8];
    undefined4 field_0x14; // accesses: 3
    undefined4 field_0x18; // accesses: 3
    undefined4 field_0x1c; // accesses: 1

    // Member Functions
    CMwClassInfo * __thiscall MwGetClassInfo(CHmsConfig *this,CFuncSegment *param_1);
    CMwNod * __cdecl MwNewCHmsConfig(void);
    int __thiscall MwIsKindOf(CHmsConfig *this,CMwCmdAffectParam *param_1,ulong param_2);
    ulong __thiscall GetChunkInfo(CHmsConfig *this,CFuncSegment *param_1,ulong param_2);
    ulong __thiscall GetMwClassId(CHmsConfig *this,CControlStyle *param_1);
    ulong __thiscall GetUidChunkFromIndex(CHmsConfig *this,CMwCmdExpIso4Ident *param_1,ulong param_2);
    void * __thiscall _vector_deleting_destructor_(CHmsConfig *this,CRpcCallInternal *param_1,uint param_2);
    void __thiscall CHmsConfig(CHmsConfig *this,CHmsConfig *param_1);
    void __thiscall Chunk(CHmsConfig *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3);
    void __thiscall CopyFromConfig(CHmsConfig *this,CHmsConfig *param_1,CHmsConfig *param_2);
    void __thiscall CopyFromShadowGroups (CHmsConfig *this,CHmsConfig *param_1,CFastArray<class_CHmsShadowGroup*> *param_2);
    void __thiscall CreateDefaultData(CHmsConfig *this,CCrystal *param_1);
    void __thiscall ShadowGroupsSetCount(CHmsConfig *this,CHmsConfig *param_1,ulong param_2);
    void __thiscall ~CHmsConfig(CHmsConfig *this,CHmsConfig *param_1);
};

#endif // CHMSCONFIG_HPP
