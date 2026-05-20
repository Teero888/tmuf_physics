#ifndef CMWCMDBLOCK_HPP
#define CMWCMDBLOCK_HPP

#include "typedefs.h"

struct CMwCmdBlock {
    byte _padding_0x0[68];
    int field_0x44; // accesses: 8
    uint field_0x48; // accesses: 7
    byte _padding_0x4c[72];
    code * field_0x94; // accesses: 1

    // Member Functions
    void __thiscall CleanContext(CMwCmdBlock *this,CMwCmdBlock *param_1);
    void __thiscall Run(CMwCmdBlock *this,CMwCmdExpStringConcat *param_1);
    void __thiscall SaveContext(CMwCmdBlock *this,CMwCmdBlock *param_1);
};

#endif // CMWCMDBLOCK_HPP
