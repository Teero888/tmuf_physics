#ifndef CGAMEPLAYGROUND_HPP
#define CGAMEPLAYGROUND_HPP

#include "typedefs.h"

struct CMwNod;
struct TiXmlDeclaration;

struct CGamePlayground {
    byte _padding_0x0[4];
    TiXmlDeclaration * field_0x4; // accesses: 3
    byte _padding_0x8[8];
    int field_0x10; // accesses: 2
    byte _padding_0x14[4];
    int field_0x18; // accesses: 9
    byte _padding_0x1c[4];
    int field_0x20; // accesses: 3
    byte _padding_0x24[12];
    undefined4 field_0x30; // accesses: 6
    undefined4 field_0x34; // accesses: 6
    byte _padding_0x38[12];
    int * field_0x44; // accesses: 8
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1

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
