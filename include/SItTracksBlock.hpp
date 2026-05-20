#ifndef SITTRACKSBLOCK_HPP
#define SITTRACKSBLOCK_HPP

#include "typedefs.h"

struct SItTracksBlock {
    SItTracksBlock * field_0x0; // accesses: 2
    int field_0x4; // accesses: 5
    byte _padding_0x8[4];
    int field_0xc; // accesses: 6
    ulong field_0x10; // accesses: 4

    // Member Functions
    int __thiscall NextBlock(void *this,SItTracksBlock *param_1);
    void __thiscall SItTracksBlock (void *this,SItTracksBlock *param_1,CFastBufferRef<class_CGameCtnMediaTrack> *param_2);
};

#endif // SITTRACKSBLOCK_HPP
