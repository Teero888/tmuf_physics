#ifndef CAUDIOSOUNDSURFACE_HPP
#define CAUDIOSOUNDSURFACE_HPP

#include "typedefs.h"

struct CAudioSoundSurface {
    byte _padding_0x0[120];
    undefined4 field_0x78; // accesses: 1
    undefined4 field_0x7c; // accesses: 1
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1

    // Member Functions
    void __thiscall CAudioSoundSurface (CAudioSoundSurface *this,CAudioSoundSurface *param_1,CPlugSoundSurface *param_2, CAudioPort *param_3);
};

#endif // CAUDIOSOUNDSURFACE_HPP
