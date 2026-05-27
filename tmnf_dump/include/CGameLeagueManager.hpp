#ifndef CGAMELEAGUEMANAGER_HPP
#define CGAMELEAGUEMANAGER_HPP

#include "typedefs.h"

struct CGameLeagueManager {
    void** vftable;

    // Member Functions
    CGameLeague * __cdecl InternalGetLeagueFromPathAndName (CFastBufferRef<class_CGameLeague> *param_1,CFastStringInt *param_2, CFastStringInt *param_3);
    CGameLeague * __thiscall GetLeagueFromFullPath (CGameLeagueManager *this,CGameLeagueManager *param_1,CFastStringInt *param_2);
    void __thiscall ForceUpdate(CGameLeagueManager *this,CGameLeagueManager *param_1);
    void __thiscall GetStepLeaguesFromFullPath (CGameLeagueManager *this,CGameLeagueManager *param_1,CFastStringInt *param_2, CFastBuffer<class_CGameLeague*> *param_3,int param_4);
};

#endif // CGAMELEAGUEMANAGER_HPP
