#ifndef CAUDIOMUSIC_HPP
#define CAUDIOMUSIC_HPP

#include "typedefs.h"

struct CMwRefBuffer;

struct CAudioMusic {
    byte _padding_0x0[116];
    CMwRefBuffer * field_0x74; // accesses: 1

    // Member Functions
    void __thiscall CAudioMusic (CAudioMusic *this,CAudioMusic *param_1,CPlugMusic *param_2,CAudioPort *param_3);
};

#endif // CAUDIOMUSIC_HPP
