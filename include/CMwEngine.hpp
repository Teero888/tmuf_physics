#ifndef CMWENGINE_HPP
#define CMWENGINE_HPP

#include "typedefs.h"

struct CMwEngine {
    void** vftable; // accesses: 2
    byte _padding_0x4[20];
    uint * field_0x18; // accesses: 2
    undefined4 field_0x1c; // accesses: 2

    // Member Functions
    void __thiscall AllocateGroups(CMwEngine *this,CMwEngine *param_1);
    void __thiscall CMwEngine(CMwEngine *this,CMwEngine *param_1);
};

#endif // CMWENGINE_HPP
