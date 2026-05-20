#ifndef CFUNCENUM_HPP
#define CFUNCENUM_HPP

#include "typedefs.h"

struct CFuncEnum {
    void** vftable; // accesses: 1
    byte _padding_0x4[28];
    CFuncEnum * field_0x20; // accesses: 3
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    byte _padding_0x44[8];
    undefined4 field_0x4c; // accesses: 1

    // Member Functions
    void __thiscall CFuncEnum(CFuncEnum *this,CFuncEnum *param_1);
    void __thiscall SetValue(CFuncEnum *this,CMwCmdAffectParamBool *param_1);
    void __thiscall SetWantedCount(CFuncEnum *this,CFuncEnum *param_1,ulong param_2);
};

#endif // CFUNCENUM_HPP
