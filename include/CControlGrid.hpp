#ifndef CCONTROLGRID_HPP
#define CCONTROLGRID_HPP

#include "typedefs.h"

struct CControlGrid {
    void** vftable; // accesses: 1
    byte _padding_0x4[380];
    undefined4 field_0x180; // accesses: 1
    undefined4 field_0x184; // accesses: 1
    undefined4 field_0x188; // accesses: 1
    undefined4 field_0x18c; // accesses: 1
    undefined4 field_0x190; // accesses: 1
    undefined4 field_0x194; // accesses: 1
    undefined4 field_0x198; // accesses: 1
    undefined4 field_0x19c; // accesses: 1
    byte _final_padding[0x20]; // Total size: 0x1c0

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CControlGrid(CControlGrid *this,CControlGrid *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetChildSquare (CControlGrid *this,CControlGrid *param_1,ulong param_2,ulong param_3,ulong param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateForceColumnsWidths(CControlGrid *this,CControlGrid *param_1);
};

#endif // CCONTROLGRID_HPP
