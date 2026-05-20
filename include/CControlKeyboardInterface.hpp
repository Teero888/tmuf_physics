#ifndef CCONTROLKEYBOARDINTERFACE_HPP
#define CCONTROLKEYBOARDINTERFACE_HPP

#include "typedefs.h"

struct CControlKeyboardInterface {
    byte _padding_0x0[4];
    undefined2 * field_0x4; // accesses: 1
    byte _padding_0x8[8];
    undefined4 field_0x10; // accesses: 1

    // Member Functions
    /* WARNING: Variable defined which should be unmapped: param_1 */ void __thiscall GetString (CControlKeyboardInterface *this,CMwStatsValue *param_1,CFastString *param_2);
    void __thiscall SetString (CControlKeyboardInterface *this,CFastStringInt *param_1,SStringParam *param_2);
};

#endif // CCONTROLKEYBOARDINTERFACE_HPP
