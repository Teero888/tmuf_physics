#ifndef CGAMEPLAYGROUNDINTERFACE_HPP
#define CGAMEPLAYGROUNDINTERFACE_HPP

#include "typedefs.h"

struct CControlBase;
struct CControlFrame;
struct CControlLabel;
struct CFastStringInt;

struct CGamePlaygroundInterface {
    void** vftable; // accesses: 4

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
