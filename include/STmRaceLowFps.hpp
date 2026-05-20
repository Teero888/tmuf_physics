#ifndef STMRACELOWFPS_HPP
#define STMRACELOWFPS_HPP

#include "typedefs.h"

struct CPlugAudio;

struct STmRaceLowFps {
    byte _padding_0x0[20];
    CPlugAudio * field_0x14; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateAsync(void *this,CInputPortDx8 *param_1);
    void __thiscall ResetFrames(void *this,STmRaceLowFps *param_1);
    void __thiscall Start(void *this,CGameCtnBench *param_1);
    void __thiscall Stop(void *this,STmRaceLowFps *param_1);
    void __thiscall StopAndReset(void *this,STmRaceLowFps *param_1);
};

#endif // STMRACELOWFPS_HPP
