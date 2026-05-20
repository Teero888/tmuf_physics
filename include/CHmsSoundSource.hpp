#ifndef CHMSSOUNDSOURCE_HPP
#define CHMSSOUNDSOURCE_HPP

#include "typedefs.h"

struct CHmsSoundSource {
    byte _padding_0x0[84];
    int field_0x54; // accesses: 1
    byte _padding_0x58[24];
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1
    undefined4 field_0x78; // accesses: 1
    undefined4 field_0x7c; // accesses: 1
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
    undefined4 field_0x88; // accesses: 1
    undefined4 field_0x8c; // accesses: 1
    undefined4 field_0x90; // accesses: 1
    int field_0x94; // accesses: 1
    byte _padding_0x98[8];
    int field_0xa0; // accesses: 1

    // Member Functions
    int __thiscall GetIsPlaying(CHmsSoundSource *this,CSceneSoundSource *param_1);
    void __thiscall ResetSoundParams(CHmsSoundSource *this,CHmsSoundSource *param_1);
};

#endif // CHMSSOUNDSOURCE_HPP
