#ifndef CPFMPLANE_HPP
#define CPFMPLANE_HPP

#include "typedefs.h"

struct CPfmPlane {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 6
    float field_0x8; // accesses: 6
    float field_0xc; // accesses: 6
    float field_0x10; // accesses: 2
    float field_0x14; // accesses: 2
    float field_0x18; // accesses: 2
    float field_0x1c; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Set(CPfmPlane *this,CMwCmdScriptVarBool *param_1,int param_2);
};

#endif // CPFMPLANE_HPP
