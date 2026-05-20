#ifndef CGAMECTNMEDIACLIP_HPP
#define CGAMECTNMEDIACLIP_HPP

#include "typedefs.h"

struct CGameCtnMediaClip {
    byte _padding_0x0[60];
    float field_0x3c; // accesses: 1
    float field_0x40; // accesses: 2

    // Member Functions
    CGameCtnMediaClip * __cdecl CreateFromGhosts(CFastBufferRef<class_CGameCtnGhost> *param_1,int param_2);
    float __thiscall GetMediaBlockEndMax(CGameCtnMediaClip *this,CGameCtnMediaClip *param_1);
    float __thiscall StartTimeGet(CGameCtnMediaClip *this,CGameCtnMediaClip *param_1);
    float __thiscall StopTimeGet(CGameCtnMediaClip *this,CGameCtnMediaClip *param_1);
    int __thiscall KeepPlayingGet(CGameCtnMediaClip *this,CGameCtnMediaClip *param_1);
};

#endif // CGAMECTNMEDIACLIP_HPP
