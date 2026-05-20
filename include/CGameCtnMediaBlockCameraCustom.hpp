#ifndef CGAMECTNMEDIABLOCKCAMERACUSTOM_HPP
#define CGAMECTNMEDIABLOCKCAMERACUSTOM_HPP

#include "typedefs.h"

struct CGameCtnMediaBlockCameraCustom {
    struct SKeyVal {
        void** vftable; // accesses: 1
        undefined4 field_0x4; // accesses: 1
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
        undefined4 field_0x40; // accesses: 1
        undefined4 field_0x44; // accesses: 1
        undefined4 field_0x48; // accesses: 1
        undefined4 field_0x4c; // accesses: 1
        undefined4 field_0x50; // accesses: 1
        undefined4 field_0x54; // accesses: 1
        undefined4 field_0x58; // accesses: 1
        undefined4 field_0x5c; // accesses: 1

        // Member Functions
        /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
    };

    void** vftable;
    byte _final_padding[0x34]; // Total size: 0x38

    // Member Functions
    GmVec3 __thiscall GetValue (CGameCtnMediaBlockCameraCustom *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CGAMECTNMEDIABLOCKCAMERACUSTOM_HPP
