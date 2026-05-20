#ifndef CMWCMDBLOCKMAIN_HPP
#define CMWCMDBLOCKMAIN_HPP

#include "typedefs.h"

struct CMwCmd;

struct CMwCmdBlockMain {
    void** vftable; // accesses: 1
    byte _padding_0x4[68];
    uint field_0x48; // accesses: 4
    byte _padding_0x4c[32];
    CMwCmd * field_0x6c; // accesses: 3
    undefined4 * field_0x70; // accesses: 3

    // Member Functions
    void __thiscall Run(CMwCmdBlockMain *this,CMwCmdExpStringConcat *param_1);
    void __thiscall Sleep(CMwCmdBlockMain *this,CMwCmdBlock *param_1,ulong param_2);
};

#endif // CMWCMDBLOCKMAIN_HPP
