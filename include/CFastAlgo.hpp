#ifndef CFASTALGO_HPP
#define CFASTALGO_HPP

#include "typedefs.h"

struct CFastAlgo {
    byte _padding_0x0[24];
    undefined4 field_0x18; // accesses: 2
    undefined4 field_0x1c; // accesses: 2
    undefined4 field_0x20; // accesses: 2
    undefined4 field_0x24; // accesses: 2

    // Member Functions
    /* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */ /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ ulong __cdecl ComputeCrc32(CClassicBuffer *param_1,ulong param_2);
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ void __cdecl ComputeHMAC_MD5_Digest(SHMAC_MD5_Data *param_1);
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ void __cdecl ComputeMD5_Digest(uchar *param_1,ulong param_2,SNat128 *param_3);
    ulong __cdecl ComputeHashSize(ulong param_1);
    ulong __cdecl ComputeHashVal(char *param_1,ulong *param_2);
    ulong __cdecl GetRandomNat32(void);
};

#endif // CFASTALGO_HPP
