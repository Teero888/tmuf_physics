#ifndef CPLUGPHYSICALOBJECT_HPP
#define CPLUGPHYSICALOBJECT_HPP

#include "typedefs.h"

struct CPlugTree;

struct CPlugPhysicalObject {
    void** vftable; // accesses: 5
    float field_0x4; // accesses: 1
    byte _padding_0x8[12];
    float field_0x14; // accesses: 1
    byte _padding_0x18[12];
    float field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 2
    undefined4 field_0x2c; // accesses: 2
    undefined4 field_0x30; // accesses: 2
    undefined4 field_0x34; // accesses: 2
    undefined4 field_0x38; // accesses: 5
    undefined4 field_0x3c; // accesses: 5
    undefined4 field_0x40; // accesses: 5
    CPlugTree * field_0x44; // accesses: 6

    // Member Functions
    void __thiscall CPlugPhysicalObject(void *this,CPlugPhysicalObject *param_1);
    void __thiscall ComputeComPos(void *this,CPlugPhysicalObject *param_1,int param_2);
    void __thiscall ComputeComPosAndInertiaMatrix (void *this,CPlugPhysicalObject *param_1,float param_2,int param_3);
    void __thiscall ComputeInertiaMatrix (void *this,CPlugPhysicalObject *param_1,float param_2,int param_3);
    void __thiscall CopyFrom(void *this,SParam_Set *param_1,SParam *param_2);
    void __thiscall SetComPos(void *this,CPlugPhysicalObject *param_1,GmVec3 *param_2);
    void __thiscall SetComPosAndInertiaMatrixFromTreeBoundingBox (void *this,CPlugPhysicalObject *param_1);
    void __thiscall SetInertiaMatrixBox (void *this,CPlugPhysicalObject *param_1,float param_2,GmVec3 *param_3);
    void __thiscall SetInertiaMatrixSphere(void *this,CPlugPhysicalObject *param_1,float param_2);
};

#endif // CPLUGPHYSICALOBJECT_HPP
