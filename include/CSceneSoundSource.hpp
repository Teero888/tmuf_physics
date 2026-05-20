#ifndef CSCENESOUNDSOURCE_HPP
#define CSCENESOUNDSOURCE_HPP

#include "typedefs.h"

struct CHmsSoundSource;

struct CSceneSoundSource {
    byte _padding_0x0[48];
    int field_0x30; // accesses: 9

    // Member Functions
    CPlugSound * __thiscall GetPlugSound(CSceneSoundSource *this,CSceneSoundSource *param_1);
    int __thiscall GetIsPlaying(CSceneSoundSource *this,CSceneSoundSource *param_1);
    void __thiscall Play (CSceneSoundSource *this,CPlugFileVideo *param_1,EPlugVideoTimer param_2,int param_3, ulong param_4);
    void __thiscall SetVolume(CSceneSoundSource *this,CSceneSoundSource *param_1,float param_2);
    void __thiscall Stop(CSceneSoundSource *this,STmRaceLowFps *param_1);
};

#endif // CSCENESOUNDSOURCE_HPP
