#ifndef CPLUGMUSIC_HPP
#define CPLUGMUSIC_HPP

#include "typedefs.h"

struct CPlugMusic {
    void** vftable; // accesses: 1
    byte _padding_0x4[112];
    undefined4 field_0x74; // accesses: 1

    // Member Functions
    void __thiscall CPlugMusic(CPlugMusic *this,CPlugMusic *param_1);
};

#endif // CPLUGMUSIC_HPP
