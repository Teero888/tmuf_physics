#ifndef CMOTIONTRACKMOBILMOVE_HPP
#define CMOTIONTRACKMOBILMOVE_HPP

#include "typedefs.h"

struct CMotionTrackMobilMove {
    byte _padding_0x0[44];
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    byte _padding_0x34[48];
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CMotionTrackMobilMove (CMotionTrackMobilMove *this,CMotionTrackMobilMove *param_1);
};

#endif // CMOTIONTRACKMOBILMOVE_HPP
