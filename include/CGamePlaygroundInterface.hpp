#ifndef CGAMEPLAYGROUNDINTERFACE_HPP
#define CGAMEPLAYGROUNDINTERFACE_HPP

#include "typedefs.h"

struct CControlBase;
struct CControlFrame;
struct CControlLabel;
struct CFastStringInt;
struct ulong;

struct CGamePlaygroundInterface {
    void** vftable; // accesses: 4
    byte _padding_0x4[40];
    CControlBase * field_0x2c; // accesses: 1
    byte _padding_0x30[16];
    undefined4 field_0x40; // accesses: 3
    CControlFrame * field_0x44; // accesses: 6
    undefined4 field_0x48; // accesses: 2
    byte _padding_0x4c[28];
    CControlBase * field_0x68; // accesses: 5
    byte _padding_0x6c[24];
    CFastStringInt * field_0x84; // accesses: 1
    byte _padding_0x88[8];
    uint field_0x90; // accesses: 1
    uint field_0x94; // accesses: 1
    ulong field_0x98; // accesses: 4

    // Member Functions
    int __thiscall ChatIsAllowed (CGamePlaygroundInterface *this,CGamePlaygroundInterface *param_1);
    void __thiscall HideMusicInfo (CGamePlaygroundInterface *this,CGamePlaygroundInterface *param_1);
    void __thiscall SetAvatarMessage (CGamePlaygroundInterface *this,CGamePlaygroundInterface *param_1,CGamePlayerInfo *param_2 ,CFastStringInt *param_3,EAvatarVariant param_4);
    void __thiscall UpdateAsync(CGamePlaygroundInterface *this,CInputPortDx8 *param_1);
    void __thiscall UpdateAvatarMessage (CGamePlaygroundInterface *this,CGamePlaygroundInterface *param_1);
    void __thiscall UpdateManiaLinkPage (CGamePlaygroundInterface *this,CGamePlaygroundInterface *param_1);
    void __thiscall UpdateMusicInfo (CGamePlaygroundInterface *this,CGamePlaygroundInterface *param_1);
};

#endif // CGAMEPLAYGROUNDINTERFACE_HPP
