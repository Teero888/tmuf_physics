#ifndef CSCENESOUNDSOURCE_HPP
#define CSCENESOUNDSOURCE_HPP

#include "typedefs.h"

struct CHmsSoundSource;
struct CMwRefBuffer;

struct CSceneSoundSource {
    void** vftable; // accesses: 4
    byte _padding_0x4[44];
    int field_0x30; // accesses: 9
    byte _padding_0x34[64];
    CMwRefBuffer * field_0x74; // accesses: 1

    // Member Functions
    CPlugSound * __thiscall GetPlugSound(CSceneSoundSource *this,CSceneSoundSource *param_1);
    int __thiscall GetIsPlaying(CSceneSoundSource *this,CSceneSoundSource *param_1);
    void __thiscall Play (CSceneSoundSource *this,CPlugFileVideo *param_1,EPlugVideoTimer param_2,int param_3, ulong param_4);
    void __thiscall SetVolume(CSceneSoundSource *this,CSceneSoundSource *param_1,float param_2);
    void __thiscall Stop(CSceneSoundSource *this,STmRaceLowFps *param_1);
};

#endif // CSCENESOUNDSOURCE_HPP
