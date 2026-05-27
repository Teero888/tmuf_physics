#ifndef CGAMEDIALOGS_HPP
#define CGAMEDIALOGS_HPP

#include "typedefs.h"

struct CMwNod;

struct CGameDialogs {
    void** vftable;
    byte _final_padding[0x9]; // Total size: 0xd

    // Member Functions
    void __cdecl AdjustQuadBgSize(CControlFrame *param_1,int param_2);
    void __thiscall DoMessage (CGameDialogs *this,CGameDialogs *param_1,CFastStringInt *param_2,CFastStringInt *param_3, CMwNod *param_4,_func___cdecl_void *param_5);
    void __thiscall HideDialogs(CGameDialogs *this,CGameCtnMenus *param_1);
};

#endif // CGAMEDIALOGS_HPP
