#ifndef CAUDIOSOUNDENGINE_HPP
#define CAUDIOSOUNDENGINE_HPP

#include "typedefs.h"

struct CAudioSoundEngine {
    void** vftable; // accesses: 1
    byte _padding_0x4[116];
    undefined4 field_0x78; // accesses: 1
    undefined4 field_0x7c; // accesses: 1
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
    undefined4 field_0x88; // accesses: 1
    byte _padding_0x8c[224];
    undefined4 field_0x16c; // accesses: 1
    CPlugSoundEngine * field_0x170; // accesses: 1

    // Member Functions
    void __thiscall CAudioSoundEngine (CAudioSoundEngine *this,CAudioSoundEngine *param_1,CPlugSoundEngine *param_2, CAudioPort *param_3);
};

#endif // CAUDIOSOUNDENGINE_HPP
