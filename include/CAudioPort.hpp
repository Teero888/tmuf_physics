#ifndef CAUDIOPORT_HPP
#define CAUDIOPORT_HPP

#include "typedefs.h"

struct CMwRefBuffer;

struct CAudioPort {
    struct SFadingSound {

        // Member Functions
        /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
    };

    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 2
    undefined4 field_0xc; // accesses: 2
    int field_0x10; // accesses: 1
    int field_0x14; // accesses: 1
    byte _padding_0x18[4];
    float field_0x1c; // accesses: 5
    ulong field_0x20; // accesses: 1
    byte _padding_0x24[24];
    int field_0x3c; // accesses: 1
    byte _padding_0x40[8];
    undefined4 field_0x48; // accesses: 1
    byte _padding_0x4c[4];
    int field_0x50; // accesses: 2
    byte _padding_0x54[8];
    undefined4 field_0x5c; // accesses: 1
    byte _padding_0x60[8];
    EBalanceGroup field_0x68; // accesses: 1
    byte _padding_0x6c[4];
    undefined4 field_0x70; // accesses: 2
    CMwRefBuffer * field_0x74; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Fade(CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2,float param_3, float param_4,float param_5,int param_6);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall FadePlay(CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2,float param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetSecondaryVolume (CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2,ulong param_3,float param_4);
    CAudioSound * __thiscall AddSound (CAudioPort *this,CAudioPort *param_1,CPlugSound *param_2,EBalanceGroup param_3, int param_4);
    ulong __thiscall GetNbMaxSounds(CAudioPort *this,COalAudioPort *param_1);
    void __thiscall AutoBalance_Add(CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2,ulong param_3);
    void __thiscall AutoBalance_Sub(CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2);
    void __thiscall CleanPlayablePlugSounds (CAudioPort *this,CAudioPort *param_1,int param_2,CPlugSound *param_3);
    void __thiscall CreateSound(CAudioPort *this,CSceneSoundSource *param_1,CPlugSound *param_2);
    void __thiscall FadeStop (CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2,float param_3,int param_4);
    void __thiscall InternalFade (CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2,float param_3,float param_4, float param_5,int param_6);
    void __thiscall RemoveSound(CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2);
};

#endif // CAUDIOPORT_HPP
