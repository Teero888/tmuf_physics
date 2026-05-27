#ifndef CCONTROLKEYBOARDINTERFACE_HPP
#define CCONTROLKEYBOARDINTERFACE_HPP

#include "typedefs.h"

struct CControlKeyboardInterface {
    void** vftable;
    byte _padding_0x4[12];
    undefined4 field_0x10; // accesses: 1

    // Member Functions
    void __thiscall GetString (CControlKeyboardInterface *this,CMwStatsValue *param_1,CFastString *param_2);
    void __thiscall SetString (CControlKeyboardInterface *this,CFastStringInt *param_1,SStringParam *param_2);
};

#endif // CCONTROLKEYBOARDINTERFACE_HPP
