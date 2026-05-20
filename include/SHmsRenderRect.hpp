#ifndef SHMSRENDERRECT_HPP
#define SHMSRENDERRECT_HPP

#include "typedefs.h"

struct SHmsRenderRect {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
    void __thiscall ComputeTransfosFromRect(void *this,SHmsRenderRect *param_1);
    void __thiscall CutScissorRect(void *this,SHmsRenderRect *param_1,GmRectAligned *param_2);
    void __thiscall SetRect (void *this,CDynaSpecular *param_1,ulong param_2,ulong param_3,ulong param_4,ulong param_5 ,ulong param_6);
};

#endif // SHMSRENDERRECT_HPP
