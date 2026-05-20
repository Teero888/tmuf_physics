#ifndef SITTRACKSBLOCK_HPP
#define SITTRACKSBLOCK_HPP

#include "typedefs.h"

struct SItTracksBlock {

    // Member Functions
    int __thiscall NextBlock(void *this,SItTracksBlock *param_1);
    void __thiscall SItTracksBlock (void *this,SItTracksBlock *param_1,CFastBufferRef<class_CGameCtnMediaTrack> *param_2);
};

#endif // SITTRACKSBLOCK_HPP
