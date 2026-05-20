#ifndef CAUDIOSOUNDMULTI_HPP
#define CAUDIOSOUNDMULTI_HPP

#include "typedefs.h"

struct CAudioSoundMulti {
    byte _padding_0x0[120];
    undefined4 field_0x78; // accesses: 1

    // Member Functions
    void __thiscall CAudioSoundMulti (CAudioSoundMulti *this,CAudioSoundMulti *param_1,CPlugSoundMulti *param_2, CAudioPort *param_3);
};

#endif // CAUDIOSOUNDMULTI_HPP
