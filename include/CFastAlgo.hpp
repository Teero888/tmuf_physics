#ifndef CFASTALGO_HPP
#define CFASTALGO_HPP

#include "typedefs.h"

struct CFastAlgo {
    void** vftable;

    // Member Functions
    ulong __cdecl ComputeCrc32(CClassicBuffer *param_1,ulong param_2);
    ulong __cdecl ComputeHashSize(ulong param_1);
    ulong __cdecl ComputeHashVal(char *param_1,ulong *param_2);
    ulong __cdecl GetRandomNat32(void);
    void __cdecl ComputeHMAC_MD5_Digest(SHMAC_MD5_Data *param_1);
    void __cdecl ComputeMD5_Digest(uchar *param_1,ulong param_2,SNat128 *param_3);
};

#endif // CFASTALGO_HPP
