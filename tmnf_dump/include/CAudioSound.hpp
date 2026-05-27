#ifndef CAUDIOSOUND_HPP
#define CAUDIOSOUND_HPP

#include "typedefs.h"

struct CAudioPort;
struct CMwNod;

struct CAudioSound {
    void** vftable; // accesses: 1
    byte _final_padding[0xd]; // Total size: 0x11

    // Member Functions
    void __thiscall CAudioSound (CAudioSound *this,CAudioSound *param_1,CPlugSound *param_2,CAudioPort *param_3);
    void __thiscall Play(CAudioSound *this,CPlugFileVideo *param_1,EPlugVideoTimer param_2,int param_3, ulong param_4);
    void __thiscall Stop(CAudioSound *this,STmRaceLowFps *param_1);
};

#endif // CAUDIOSOUND_HPP
