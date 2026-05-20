#ifndef CCONTROLENTRY_HPP
#define CCONTROLENTRY_HPP

#include "typedefs.h"

struct CControlKeyboardInterface;

struct CControlEntry {
    byte _padding_0x0[252];
    uint field_0xfc; // accesses: 2
    byte _padding_0x100[48];
    undefined4 field_0x130; // accesses: 1
    byte _padding_0x134[4];
    undefined4 field_0x138; // accesses: 1
    byte _padding_0x13c[4];
    undefined4 field_0x140; // accesses: 1
    undefined4 field_0x144; // accesses: 1
    undefined4 field_0x148; // accesses: 1
    undefined * field_0x14c; // accesses: 1
    byte _padding_0x150[4];
    undefined4 field_0x154; // accesses: 1
    byte _padding_0x158[4];
    undefined4 field_0x15c; // accesses: 4

    // Member Functions
    void __thiscall CControlEntry(CControlEntry *this,CControlEntry *param_1);
    void __thiscall SetEditedStringAndGiveFocus (CControlEntry *this,CControlEntry *param_1,CFastStringInt *param_2,ulong param_3);
};

#endif // CCONTROLENTRY_HPP
