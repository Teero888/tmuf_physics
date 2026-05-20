#ifndef SHMSRENDERRECT_HPP
#define SHMSRENDERRECT_HPP

#include "typedefs.h"

struct SHmsRenderRect {
    undefined4 field_0x0; // accesses: 1
    undefined4 field_0x4; // accesses: 1
    byte _padding_0x8[28];
    undefined4 field_0x24; // accesses: 2
    undefined4 field_0x28; // accesses: 2
    undefined4 field_0x2c; // accesses: 2
    undefined4 field_0x30; // accesses: 2
    undefined4 field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
    void __thiscall ComputeTransfosFromRect(void *this,SHmsRenderRect *param_1);
    void __thiscall CutScissorRect(void *this,SHmsRenderRect *param_1,GmRectAligned *param_2);
    void __thiscall SetRect (void *this,CDynaSpecular *param_1,ulong param_2,ulong param_3,ulong param_4,ulong param_5 ,ulong param_6);
};

#endif // SHMSRENDERRECT_HPP
