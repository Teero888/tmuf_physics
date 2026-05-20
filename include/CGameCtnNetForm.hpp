#ifndef CGAMECTNNETFORM_HPP
#define CGAMECTNNETFORM_HPP

#include "typedefs.h"

struct CGameCtnNetForm {
    byte _padding_0x0[1];
    uint field_0x1; // accesses: 1
    uint field_0x4; // accesses: 1
    uint field_0x5; // accesses: 1
    byte _padding_0x9[23];
    undefined4 field_0x20; // accesses: 1

    // Member Functions
    int __cdecl ValidatePacketForcedMods (int param_1,int param_2,int param_3,uchar param_4,uchar *param_5,ulong param_6);
    int __cdecl ValidatePacketForcedMusic (int param_1,int param_2,int param_3,uchar param_4,uchar *param_5,ulong param_6);
    void __thiscall CGameCtnNetForm (CGameCtnNetForm *this,CGameCtnNetForm *param_1,EMessageType param_2);
    void __thiscall ~CGameCtnNetForm(CGameCtnNetForm *this,CGameCtnNetForm *param_1);
};

#endif // CGAMECTNNETFORM_HPP
