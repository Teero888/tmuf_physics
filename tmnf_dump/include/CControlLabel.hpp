#ifndef CCONTROLLABEL_HPP
#define CCONTROLLABEL_HPP

#include "typedefs.h"

struct CControlLabel {
    void** vftable; // accesses: 1
    byte _padding_0x4[248];
    uint field_0xfc; // accesses: 2
    byte _padding_0x100[48];
    undefined4 field_0x130; // accesses: 2
    undefined * field_0x134; // accesses: 1
    undefined4 field_0x138; // accesses: 1
    undefined4 field_0x13c; // accesses: 1
    undefined4 field_0x140; // accesses: 1
    undefined4 field_0x144; // accesses: 1
    undefined4 field_0x148; // accesses: 1

    // Member Functions
    void __thiscall CControlLabel(CControlLabel *this,CControlLabel *param_1);
    void __thiscall SetLabel(CControlLabel *this,CControlButton *param_1,CFastStringInt *param_2);
};

#endif // CCONTROLLABEL_HPP
