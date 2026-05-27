#ifndef CAUDIOPORT_HPP
#define CAUDIOPORT_HPP

#include "typedefs.h"

struct CAudioPort {
    struct SFadingSound {
        void** vftable; // accesses: 1
        undefined4 field_0x4; // accesses: 1
        undefined4 field_0x8; // accesses: 1
        undefined4 field_0xc; // accesses: 1
        undefined4 field_0x10; // accesses: 1
        undefined4 field_0x14; // accesses: 1
        undefined4 field_0x18; // accesses: 1
        undefined4 field_0x1c; // accesses: 1
        undefined4 field_0x20; // accesses: 1
        undefined4 field_0x24; // accesses: 1
        undefined4 field_0x28; // accesses: 1

        // Member Functions
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
    };

    void** vftable; // accesses: 2
    byte _padding_0x4[16];
    int field_0x14; // accesses: 1
    byte _final_padding[0x3]; // Total size: 0x1b

    // Member Functions
    CAudioSound * __thiscall AddSound (CAudioPort *this,CAudioPort *param_1,CPlugSound *param_2,EBalanceGroup param_3, int param_4);
    ulong __thiscall GetNbMaxSounds(CAudioPort *this,COalAudioPort *param_1);
    void __thiscall AutoBalance_Add(CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2,ulong param_3);
    void __thiscall AutoBalance_Sub(CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2);
    void __thiscall CleanPlayablePlugSounds (CAudioPort *this,CAudioPort *param_1,int param_2,CPlugSound *param_3);
    void __thiscall CreateSound(CAudioPort *this,CSceneSoundSource *param_1,CPlugSound *param_2);
    void __thiscall Fade(CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2,float param_3, float param_4,float param_5,int param_6);
    void __thiscall FadePlay(CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2,float param_3);
    void __thiscall FadeStop (CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2,float param_3,int param_4);
    void __thiscall InternalFade (CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2,float param_3,float param_4, float param_5,int param_6);
    void __thiscall RemoveSound(CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2);
    void __thiscall SetSecondaryVolume (CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2,ulong param_3,float param_4);
};

#endif // CAUDIOPORT_HPP
