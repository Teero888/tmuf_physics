#ifndef CSYSTEMPACKDESC_HPP
#define CSYSTEMPACKDESC_HPP

#include "typedefs.h"

struct CFastString;
struct CSystemFid;

struct CSystemPackDesc {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 4
    undefined4 field_0x8; // accesses: 3
    undefined4 field_0xc; // accesses: 2
    byte _padding_0x10[8];
    int field_0x18; // accesses: 1
    byte _padding_0x1c[12];
    int field_0x28; // accesses: 1
    int field_0x2c; // accesses: 1
    int field_0x30; // accesses: 1
    byte _padding_0x34[20];
    undefined4 field_0x48; // accesses: 6
    int field_0x4c; // accesses: 1
    int field_0x50; // accesses: 2
    byte _padding_0x54[20];
    undefined4 field_0x68; // accesses: 1
    byte _padding_0x6c[12];
    int field_0x78; // accesses: 3

    // Member Functions
    SNat128 __cdecl ComputeChecksum (ulong param_1,ulong param_2,ulong param_3,ulong param_4,uchar *param_5);
    int __cdecl ConvertChecksumToString(SNat128 *param_1,CFastString *param_2,int param_3);
    int __thiscall CanSetURL(CSystemPackDesc *this,CSystemPackDesc *param_1);
    void __cdecl SetChecksumNull(SNat128 *param_1);
    void __thiscall GetContents (CSystemPackDesc *this,CSystemPackDesc *param_1,CSystemFids **param_2,CSystemFid **param_3 );
    void __thiscall SetURL(CSystemPackDesc *this,CSystemPackDesc *param_1,CFastString *param_2);
    void __thiscall TouchLastTimeOfUse(CSystemPackDesc *this,CSystemPackDesc *param_1);
};

#endif // CSYSTEMPACKDESC_HPP
