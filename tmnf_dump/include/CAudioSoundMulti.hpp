#ifndef CAUDIOSOUNDMULTI_HPP
#define CAUDIOSOUNDMULTI_HPP

#include "typedefs.h"

struct CAudioSoundMulti {
    void** vftable; // accesses: 1

    // Member Functions
    void __thiscall CAudioSoundMulti (CAudioSoundMulti *this,CAudioSoundMulti *param_1,CPlugSoundMulti *param_2, CAudioPort *param_3);
};

#endif // CAUDIOSOUNDMULTI_HPP
