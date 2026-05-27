#ifndef CGAMENETPLAYERINFO_HPP
#define CGAMENETPLAYERINFO_HPP

#include "typedefs.h"

struct CGameNetPlayerInfo {
    void** vftable; // accesses: 1
    byte _final_padding[0xd]; // Total size: 0x11

    // Member Functions
    int __thiscall IsSpectator(CGameNetPlayerInfo *this,CGameNetPlayerInfo *param_1);
    void __thiscall CGameNetPlayerInfo(CGameNetPlayerInfo *this,CGameNetPlayerInfo *param_1);
    void __thiscall RemoveNetStateSending (CGameNetPlayerInfo *this,CGameNetPlayerInfo *param_1,uchar param_2);
    void __thiscall SetDirty(CGameNetPlayerInfo *this,CPlugVertexStream *param_1,int param_2);
    void __thiscall SetGeneratedPlayerUId (CGameNetPlayerInfo *this,CGameNetPlayerInfo *param_1,uchar param_2);
};

#endif // CGAMENETPLAYERINFO_HPP
