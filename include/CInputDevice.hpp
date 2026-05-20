#ifndef CINPUTDEVICE_HPP
#define CINPUTDEVICE_HPP

#include "typedefs.h"

struct CInputDevice {
    byte _padding_0x0[4];
    ulong field_0x4; // accesses: 3
    float field_0x8; // accesses: 3

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall RumbleCompute (CInputDevice *this,CInputDevice *param_1,ulong param_2,float *param_3,float *param_4);
    void __thiscall RumbleAdd (CInputDevice *this,CInputDevice *param_1,ulong param_2,float param_3,float param_4);
};

#endif // CINPUTDEVICE_HPP
