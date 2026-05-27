#ifndef CPLUGSOUNDVIDEO_HPP
#define CPLUGSOUNDVIDEO_HPP

#include "typedefs.h"

struct CPlugSoundVideo {
    void** vftable; // accesses: 1
    byte _padding_0x4[108];
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1

    // Member Functions
    void __thiscall CPlugSoundVideo(CPlugSoundVideo *this,CPlugSoundVideo *param_1);
};

#endif // CPLUGSOUNDVIDEO_HPP
