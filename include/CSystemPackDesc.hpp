#ifndef CSYSTEMPACKDESC_HPP
#define CSYSTEMPACKDESC_HPP

#include "typedefs.h"

struct CSystemFid;

struct CSystemPackDesc {
    void** vftable; // accesses: 4
    int field_0x4; // accesses: 3
    byte _padding_0x8[64];
    undefined4 field_0x48; // accesses: 6
    int field_0x4c; // accesses: 1
    int field_0x50; // accesses: 1
    byte _padding_0x54[36];
    int * field_0x78; // accesses: 3

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
