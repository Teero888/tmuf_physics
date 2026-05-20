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
    int field_0x70; // accesses: 3
    byte _final_padding[0x14]; // Total size: 0x88

    // Member Functions
    void __thiscall Run(CMwCmdBlockMain *this,CMwCmdExpStringConcat *param_1);
    void __thiscall Sleep(CMwCmdBlockMain *this,CMwCmdBlock *param_1,ulong param_2);
};

#endif // CMWCMDBLOCKMAIN_HPP
