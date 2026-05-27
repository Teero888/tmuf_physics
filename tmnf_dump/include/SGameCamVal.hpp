#ifndef SGAMECAMVAL_HPP
#define SGAMECAMVAL_HPP

#include "typedefs.h"

struct SGameCamVal {
    byte _padding_0x0[68];
    undefined4 field_0x44; // accesses: 2
    undefined4 field_0x48; // accesses: 2
    undefined4 field_0x4c; // accesses: 2
    undefined4 field_0x50; // accesses: 2
    undefined4 field_0x54; // accesses: 2
    undefined4 field_0x58; // accesses: 2
    undefined4 field_0x5c; // accesses: 2

    // Member Functions
    void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
    void __thiscall SGameCamVal(void *this,SGameCamVal *param_1);
};

#endif // SGAMECAMVAL_HPP
