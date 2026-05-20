#ifndef CCONTROLDISPLAYGRAPH_HPP
#define CCONTROLDISPLAYGRAPH_HPP

#include "typedefs.h"

struct CControlDisplayGraph {
    void** vftable; // accesses: 1
    byte _padding_0x4[284];
    undefined4 field_0x120; // accesses: 1
    uint field_0x124; // accesses: 1
    byte _padding_0x128[24];
    int field_0x140; // accesses: 1
    int field_0x144; // accesses: 3
    float field_0x148; // accesses: 4
    int field_0x14c; // accesses: 3
    byte _padding_0x150[4];
    int field_0x154; // accesses: 6
    byte _final_padding[0x24]; // Total size: 0x17c

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall AdvanceOneStep (CControlDisplayGraph *this,CControlDisplayGraph *param_1,int param_2);
};

#endif // CCONTROLDISPLAYGRAPH_HPP
