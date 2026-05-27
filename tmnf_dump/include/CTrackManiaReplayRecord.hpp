#ifndef CTRACKMANIAREPLAYRECORD_HPP
#define CTRACKMANIAREPLAYRECORD_HPP

#include "typedefs.h"

struct CTrackManiaReplayRecord {
    void** vftable; // accesses: 1
    byte _final_padding[0x48]; // Total size: 0x4c

    // Member Functions
    void __thiscall CTrackManiaReplayRecord (CTrackManiaReplayRecord *this,CTrackManiaReplayRecord *param_1);
};

#endif // CTRACKMANIAREPLAYRECORD_HPP
