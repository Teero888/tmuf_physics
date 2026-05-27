#ifndef CAUDIOSOUNDENGINE_HPP
#define CAUDIOSOUNDENGINE_HPP

#include "typedefs.h"

struct CAudioSoundEngine {
    void** vftable; // accesses: 1
    byte _final_padding[0x2]; // Total size: 0x6

    // Member Functions
    void __thiscall CAudioSoundEngine (CAudioSoundEngine *this,CAudioSoundEngine *param_1,CPlugSoundEngine *param_2, CAudioPort *param_3);
};

#endif // CAUDIOSOUNDENGINE_HPP
