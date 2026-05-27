#ifndef CAUDIOSOUNDSURFACE_HPP
#define CAUDIOSOUNDSURFACE_HPP

#include "typedefs.h"

struct CAudioSoundSurface {
    void** vftable; // accesses: 1
    byte _final_padding[0x1]; // Total size: 0x5

    // Member Functions
    void __thiscall CAudioSoundSurface (CAudioSoundSurface *this,CAudioSoundSurface *param_1,CPlugSoundSurface *param_2, CAudioPort *param_3);
};

#endif // CAUDIOSOUNDSURFACE_HPP
