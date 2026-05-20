#ifndef CMWCMDBLOCKMAIN_HPP
#define CMWCMDBLOCKMAIN_HPP

#include "typedefs.h"

struct CMwCmd;
struct CPlugAudio;

struct CMwCmdBlockMain {
    byte _padding_0x0[20];
    CPlugAudio * field_0x14; // accesses: 1
    byte _padding_0x18[48];
    uint field_0x48; // accesses: 4
    byte _padding_0x4c[32];
    int field_0x6c; // accesses: 3
    int field_0x70; // accesses: 3

    // Member Functions
    void __thiscall Run(CMwCmdBlockMain *this,CMwCmdExpStringConcat *param_1);
    void __thiscall Sleep(CMwCmdBlockMain *this,CMwCmdBlock *param_1,ulong param_2);
};

#endif // CMWCMDBLOCKMAIN_HPP
