#ifndef CSCENEPATH_HPP
#define CSCENEPATH_HPP

#include "typedefs.h"

struct CScenePath {
    void** vftable;
    byte _final_padding[0x34]; // Total size: 0x38

    // Member Functions
    float __thiscall GetLength(CScenePath *this,CPlugFileSnd *param_1);
};

#endif // CSCENEPATH_HPP
