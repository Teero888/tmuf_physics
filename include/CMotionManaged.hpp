#ifndef CMOTIONMANAGED_HPP
#define CMOTIONMANAGED_HPP

#include "typedefs.h"

struct CMotionManaged {
    byte _padding_0x0[20];
    int field_0x14; // accesses: 1
    int * field_0x18; // accesses: 10
    undefined4 field_0x1c; // accesses: 1
    int field_0x20; // accesses: 9
    byte _padding_0x24[96];
    code * field_0x84; // accesses: 1

    // Member Functions
    CMotionManager * __thiscall QueryManager(CMotionManaged *this,CScene *param_1,ulong param_2);
    void __thiscall CMotionManaged(CMotionManaged *this,CMotionManaged *param_1);
    void __thiscall ReleaseManager(CMotionManaged *this,CScene *param_1,ulong param_2);
};

#endif // CMOTIONMANAGED_HPP
