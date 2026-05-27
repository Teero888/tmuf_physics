#ifndef CGAMEPLAYGROUND_HPP
#define CGAMEPLAYGROUND_HPP

#include "typedefs.h"

struct CMwNod;

struct CGamePlayground {
    void** vftable; // accesses: 6

    // Member Functions
    int __thiscall UpdateFromSettings (CGamePlayground *this,CGamePlayground *param_1,CFastString *param_2,int param_3);
    ulong __thiscall GetPlayerNumber(CGamePlayground *this,CGamePlayground *param_1,ulong param_2);
    ulong __thiscall VirtualParam_Get (CGamePlayground *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3);
    ulong __thiscall VirtualParam_Set (CGamePlayground *this,CSystemData *param_1,CMwStack *param_2,void *param_3);
    void __thiscall CGamePlayground(CGamePlayground *this,CGamePlayground *param_1);
    void __thiscall Clean(CGamePlayground *this,CHmsOcclusion *param_1);
    void __thiscall CommonSwitchFrom(CGamePlayground *this,CGamePlayground *param_1);
    void __thiscall ~CGamePlayground(CGamePlayground *this,CGamePlayground *param_1);
};

#endif // CGAMEPLAYGROUND_HPP
