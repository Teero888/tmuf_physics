#ifndef CCONTROLBUTTON_HPP
#define CCONTROLBUTTON_HPP

#include "typedefs.h"

struct SStringParam;

struct CControlButton {
    void** vftable; // accesses: 3
    SStringParam * field_0x4; // accesses: 4
    byte _padding_0x8[296];
    undefined4 field_0x130; // accesses: 1
    undefined4 field_0x134; // accesses: 1
    undefined4 field_0x138; // accesses: 1
    undefined4 field_0x13c; // accesses: 1
    undefined4 field_0x140; // accesses: 1
    undefined4 field_0x144; // accesses: 1
    undefined4 field_0x148; // accesses: 1
    undefined4 field_0x14c; // accesses: 1
    undefined4 field_0x150; // accesses: 1
    undefined4 field_0x154; // accesses: 1
    undefined4 field_0x158; // accesses: 1
    byte _padding_0x15c[4];
    undefined4 field_0x160; // accesses: 2
    undefined * field_0x164; // accesses: 1
    undefined4 field_0x168; // accesses: 1
    undefined4 field_0x16c; // accesses: 1
    undefined4 field_0x170; // accesses: 1

    // Member Functions
    void __cdecl InitFuncEnum(CFuncEnum *param_1);
    void __thiscall CControlButton(CControlButton *this,CControlButton *param_1);
    void __thiscall SetIcons(CControlButton *this,CControlButton *param_1,CFuncEnum *param_2);
    void __thiscall SetLabel(CControlButton *this,CControlButton *param_1,CFastStringInt *param_2);
};

#endif // CCONTROLBUTTON_HPP
