#ifndef CGAMEMANIALINKBROWSER_HPP
#define CGAMEMANIALINKBROWSER_HPP

#include "typedefs.h"

struct CAudioPort;
struct CAudioSound;
struct CGameApp;
struct CMwNod;

struct CGameManialinkBrowser {
    void** vftable;
    byte _final_padding[0x5]; // Total size: 0x9

    // Member Functions
    int __thiscall IsActive(CGameManialinkBrowser *this,CGameManialinkBrowser *param_1);
    void __thiscall ApplyActiveAndEnabled (CGameManialinkBrowser *this,CGameManialinkBrowser *param_1);
    void __thiscall ManialinkBrowser_CleanPage (CGameManialinkBrowser *this,CGameManialinkBrowser *param_1);
    void __thiscall SetIsEnabled(CGameManialinkBrowser *this,COalAudioPort *param_1,int param_2);
};

#endif // CGAMEMANIALINKBROWSER_HPP
