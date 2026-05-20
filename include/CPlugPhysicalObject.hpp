#ifndef CPLUGPHYSICALOBJECT_HPP
#define CPLUGPHYSICALOBJECT_HPP

#include "typedefs.h"

struct CPlugPhysicalObject {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    byte _padding_0xc[28];
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 2
    undefined4 field_0x38; // accesses: 2
    undefined4 field_0x3c; // accesses: 2
    undefined4 field_0x40; // accesses: 1
    byte _padding_0x44[72];
    int field_0x8c; // accesses: 4

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CPlugPhysicalObject(void *this,CPlugPhysicalObject *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeInertiaMatrix (void *this,CPlugPhysicalObject *param_1,float param_2,int param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetInertiaMatrixBox (void *this,CPlugPhysicalObject *param_1,float param_2,GmVec3 *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetInertiaMatrixSphere(void *this,CPlugPhysicalObject *param_1,float param_2);
    /* WARNING: Removing unreachable block (ram,0x008a160f) */ /* WARNING: Removing unreachable block (ram,0x008a1627) */ /* WARNING: Removing unreachable block (ram,0x008a1613) */ /* WARNING: Removing unreachable block (ram,0x008a1635) */ /* WARNING: Removing unreachable block (ram,0x008a163b) */ /* WARNING: Removing unreachable block (ram,0x008a1651) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CPlugPhysicalObject::ComputeComPos(void *this,CPlugPhysicalObject *param_1,int param_2);
    void __thiscall ComputeComPosAndInertiaMatrix (void *this,CPlugPhysicalObject *param_1,float param_2,int param_3);
    void __thiscall CopyFrom(void *this,SParam_Set *param_1,SParam *param_2);
    void __thiscall SetComPos(void *this,CPlugPhysicalObject *param_1,GmVec3 *param_2);
    void __thiscall SetComPosAndInertiaMatrixFromTreeBoundingBox (void *this,CPlugPhysicalObject *param_1);
};

#endif // CPLUGPHYSICALOBJECT_HPP
