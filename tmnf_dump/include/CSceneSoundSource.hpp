#ifndef CSCENESOUNDSOURCE_HPP
#define CSCENESOUNDSOURCE_HPP

#include "typedefs.h"

struct CHmsSoundSource;

struct CSceneSoundSource {
    void** vftable;
    byte _padding_0x4[44];
    CHmsSoundSource * field_0x30; // accesses: 9
    byte _final_padding[0x8]; // Total size: 0x3c

    // Member Functions
    CPlugSound * __thiscall GetPlugSound(CSceneSoundSource *this,CSceneSoundSource *param_1);
    int __thiscall GetIsPlaying(CSceneSoundSource *this,CSceneSoundSource *param_1);
    void __thiscall Play (CSceneSoundSource *this,CPlugFileVideo *param_1,EPlugVideoTimer param_2,int param_3, ulong param_4);
    void __thiscall SetVolume(CSceneSoundSource *this,CSceneSoundSource *param_1,float param_2);
    void __thiscall Stop(CSceneSoundSource *this,STmRaceLowFps *param_1);
};

#endif // CSCENESOUNDSOURCE_HPP
