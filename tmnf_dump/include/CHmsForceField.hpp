#ifndef CHMSFORCEFIELD_HPP
#define CHMSFORCEFIELD_HPP

#include "typedefs.h"

struct CHmsZone;

struct CHmsForceField {
    void** vftable; // accesses: 2
    byte _padding_0x4[16];
    CHmsZone * field_0x14; // accesses: 5
    byte _padding_0x18[64];
    undefined4 field_0x58; // accesses: 1

    // Member Functions
    CMwClassInfo * __thiscall MwGetClassInfo(CHmsForceField *this,CFuncSegment *param_1);
    CMwNod * __cdecl MwNewCHmsForceField(void);
    int __thiscall MwIsKindOf(CHmsForceField *this,CMwCmdAffectParam *param_1,ulong param_2);
    ulong __thiscall GetMwClassId(CHmsForceField *this,CControlStyle *param_1);
    void * __thiscall _vector_deleting_destructor_ (CHmsForceField *this,CRpcCallInternal *param_1,uint param_2);
    void __thiscall CHmsForceField(CHmsForceField *this,CHmsForceField *param_1);
    void __thiscall SetZone(CHmsForceField *this,CSceneSector *param_1,CHmsZone *param_2);
    void __thiscall ~CHmsForceField(CHmsForceField *this,CHmsForceField *param_1);
};

#endif // CHMSFORCEFIELD_HPP
