#ifndef CGAMEGHOST_HPP
#define CGAMEGHOST_HPP

#include "typedefs.h"

struct CGameGhost {
    void** vftable;
    byte _padding_0x4[64];
    int field_0x44; // accesses: 1
    byte _padding_0x48[32];
    int field_0x68; // accesses: 2
    byte _final_padding[0x1c]; // Total size: 0x88

    // Member Functions
    int __thiscall IsFixedTimeStep(CGameGhost *this,CGameGhost *param_1);
    ulong __thiscall GetDuration(CGameGhost *this,CPlugFileAvi *param_1);
    void __thiscall ClearNotSimulatedData(CGameGhost *this,CGameGhost *param_1);
};

#endif // CGAMEGHOST_HPP
