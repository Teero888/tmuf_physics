#ifndef CINPUTDEVICE_HPP
#define CINPUTDEVICE_HPP

#include "typedefs.h"

struct CInputDevice {
    void** vftable;
    byte _final_padding[0x5]; // Total size: 0x9

    // Member Functions
    void __thiscall RumbleAdd (CInputDevice *this,CInputDevice *param_1,ulong param_2,float param_3,float param_4);
    void __thiscall RumbleCompute (CInputDevice *this,CInputDevice *param_1,ulong param_2,float *param_3,float *param_4);
};

#endif // CINPUTDEVICE_HPP
