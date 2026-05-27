#ifndef CPLUGAUDIO_HPP
#define CPLUGAUDIO_HPP

#include "typedefs.h"

struct CPlugAudio {
    void** vftable; // accesses: 1

    // Member Functions
    CMwId * __thiscall MwGetId(CPlugAudio *this,CPlugAudio *param_1);
    void __thiscall CPlugAudio(CPlugAudio *this,CPlugAudio *param_1);
};

#endif // CPLUGAUDIO_HPP
