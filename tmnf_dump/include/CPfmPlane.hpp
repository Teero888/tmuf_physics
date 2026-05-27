#ifndef CPFMPLANE_HPP
#define CPFMPLANE_HPP

#include "typedefs.h"

struct CPfmPlane {
    void** vftable;
    float field_0x4; // accesses: 6
    float field_0x8; // accesses: 6
    float field_0xc; // accesses: 6
    undefined4 field_0x10; // accesses: 2
    undefined4 field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 2
    float field_0x1c; // accesses: 1

    // Member Functions
    void __thiscall Set(CPfmPlane *this,CMwCmdScriptVarBool *param_1,int param_2);
};

#endif // CPFMPLANE_HPP
