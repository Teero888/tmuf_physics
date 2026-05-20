#ifndef STMRACELOWFPS_HPP
#define STMRACELOWFPS_HPP

#include "typedefs.h"

struct STmRaceLowFps {
    undefined4 field_0x0; // accesses: 3
    undefined4 field_0x4; // accesses: 4
    int field_0x8; // accesses: 3
    byte _padding_0xc[20];
    undefined4 field_0x20; // accesses: 2
    int field_0x24; // accesses: 6
    int field_0x28; // accesses: 6

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateAsync(void *this,CInputPortDx8 *param_1);
    void __thiscall ResetFrames(void *this,STmRaceLowFps *param_1);
    void __thiscall Start(void *this,CGameCtnBench *param_1);
    void __thiscall Stop(void *this,STmRaceLowFps *param_1);
    void __thiscall StopAndReset(void *this,STmRaceLowFps *param_1);
};

#endif // STMRACELOWFPS_HPP
