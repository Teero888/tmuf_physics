#ifndef CMWCMDBLOCK_HPP
#define CMWCMDBLOCK_HPP

#include "typedefs.h"

struct CMwCmdBlock {
    void** vftable; // accesses: 2
    byte _padding_0x4[64];
    undefined4 field_0x44; // accesses: 8
    uint field_0x48; // accesses: 7
    byte _final_padding[0x4]; // Total size: 0x50

    // Member Functions
    void __thiscall CleanContext(CMwCmdBlock *this,CMwCmdBlock *param_1);
    void __thiscall Run(CMwCmdBlock *this,CMwCmdExpStringConcat *param_1);
    void __thiscall SaveContext(CMwCmdBlock *this,CMwCmdBlock *param_1);
};

#endif // CMWCMDBLOCK_HPP
