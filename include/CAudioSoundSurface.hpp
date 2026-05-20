#ifndef CAUDIOSOUNDSURFACE_HPP
#define CAUDIOSOUNDSURFACE_HPP

#include "typedefs.h"

struct CAudioSoundSurface {
    void** vftable; // accesses: 1
    byte _padding_0x4[116];
    undefined4 field_0x78; // accesses: 1
    undefined4 field_0x7c; // accesses: 1
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1

    // Member Functions
    void __thiscall CAudioSoundSurface (CAudioSoundSurface *this,CAudioSoundSurface *param_1,CPlugSoundSurface *param_2, CAudioPort *param_3);
};

#endif // CAUDIOSOUNDSURFACE_HPP
