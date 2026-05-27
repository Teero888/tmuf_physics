#ifndef CGAMENETSERVER_HPP
#define CGAMENETSERVER_HPP

#include "typedefs.h"

struct CGameNetServer {
    void** vftable;

    // Member Functions
    CNetConnectedClient * __thiscall FindConnection(CGameNetServer *this,CGameNetServer *param_1,ulong param_2);
    void __thiscall SendAll(CGameNetServer *this,CGameNetServer *param_1,CNetNod *param_2);
    void __thiscall SendAllExcept (CGameNetServer *this,CGameNetServer *param_1,CNetNod *param_2, CNetConnectedClient *param_3);
};

#endif // CGAMENETSERVER_HPP
