#ifndef CINPUTPORTDX8_HPP
#define CINPUTPORTDX8_HPP

#include "typedefs.h"

struct CInputPortDx8 {
    void** vftable;
    byte _padding_0x4[28];
    int field_0x20; // accesses: 3
    byte _padding_0x24[16];
    int field_0x34; // accesses: 2
    SInputEvent * field_0x38; // accesses: 1
    byte _padding_0x3c[84];
    int field_0x90; // accesses: 1
    int field_0x94; // accesses: 1
    byte _padding_0x98[4];
    int field_0x9c; // accesses: 1
    byte _padding_0xa0[48];
    int field_0xd0; // accesses: 1
    byte _padding_0xd4[20];
    int field_0xe8; // accesses: 1
    byte _padding_0xec[8];
    uint field_0xf4; // accesses: 3
    byte _final_padding[0x4]; // Total size: 0xfc

    // Member Functions
    void __thiscall ApplyMouseSettings(CInputPortDx8 *this,CInputPortDx8 *param_1);
    void __thiscall NotifyMouseWheel(CInputPortDx8 *this,CInputPortDx8 *param_1,float param_2);
    void __thiscall UpdateAsync(CInputPortDx8 *this,CInputPortDx8 *param_1);
};

#endif // CINPUTPORTDX8_HPP
