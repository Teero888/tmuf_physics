#ifndef CAUDIOSOUNDMULTI_HPP
#define CAUDIOSOUNDMULTI_HPP

#include "typedefs.h"

struct CAudioSoundMulti {
    void** vftable; // accesses: 1
    byte _padding_0x4[116];
    undefined4 field_0x78; // accesses: 1

    // Member Functions
    void __thiscall CAudioSoundMulti (CAudioSoundMulti *this,CAudioSoundMulti *param_1,CPlugSoundMulti *param_2, CAudioPort *param_3);
};

#endif // CAUDIOSOUNDMULTI_HPP
