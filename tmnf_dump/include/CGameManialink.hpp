#ifndef CGAMEMANIALINK_HPP
#define CGAMEMANIALINK_HPP

#include "typedefs.h"

struct CGameManialink {
    struct SBuildPageParams {
        void** vftable; // accesses: 2
        undefined * field_0x4; // accesses: 3
        undefined4 field_0x8; // accesses: 1
        undefined4 field_0xc; // accesses: 1
        undefined4 field_0x10; // accesses: 1
        undefined4 field_0x14; // accesses: 1
        undefined4 field_0x18; // accesses: 1
        undefined4 field_0x1c; // accesses: 1
        undefined4 field_0x20; // accesses: 1
        undefined4 field_0x24; // accesses: 1
        undefined4 field_0x28; // accesses: 1
        undefined4 field_0x2c; // accesses: 1
        undefined4 field_0x30; // accesses: 1
        undefined4 field_0x34; // accesses: 1
        undefined4 field_0x38; // accesses: 1
        undefined4 field_0x3c; // accesses: 1

        // Member Functions
        void __thiscall SBuildPageParams(void *this,SBuildPageParams *param_1);
        void __thiscall ~SBuildPageParams(void *this,SBuildPageParams *param_1);
    };

    void** vftable; // accesses: 1
    byte _padding_0x4[40];
    undefined4 field_0x2c; // accesses: 1
    byte _padding_0x30[12];
    undefined4 field_0x3c; // accesses: 1
    undefined * field_0x40; // accesses: 1

    // Member Functions
    CGameManialinkPage * __cdecl BuildPage(SBuildPageParams *param_1,EErrorCode *param_2);
    void __cdecl AddPageToContainer(CGameManialinkPage *param_1,CControlFrame *param_2,float param_3);
};

#endif // CGAMEMANIALINK_HPP
