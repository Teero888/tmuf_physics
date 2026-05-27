#ifndef CGAMENETFORMGAMESYNC_HPP
#define CGAMENETFORMGAMESYNC_HPP

#include "typedefs.h"

struct CGameNetFormGameSync {
    void** vftable;
    byte _final_padding[0x40]; // Total size: 0x44

    // Member Functions
    void __cdecl SetPlayerDataSize(ulong param_1);
};

#endif // CGAMENETFORMGAMESYNC_HPP
