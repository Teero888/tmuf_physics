#ifndef CFUNCKEYS_HPP
#define CFUNCKEYS_HPP

#include "typedefs.h"

struct CFuncKeys {
    void** vftable; // accesses: 1

    // Member Functions
    int __thiscall ComputeBlendCoef (CFuncKeys *this,CFastBufferKey<struct_CGameCtnMediaBlockTime::SKeyVal> *param_1, float param_2,ulong *param_3,ulong *param_4,float *param_5,int param_6);
    ulong __thiscall InsertKeyX(CFuncKeys *this,CFuncKeys *param_1,float param_2);
    void __thiscall CFuncKeys(CFuncKeys *this,CFuncKeys *param_1);
    void __thiscall GetBoundingIndices (CFuncKeys *this,CFastBufferKey<struct_SOldKeyVal> *param_1,float param_2,ulong *param_3, ulong *param_4,int param_5);
};

#endif // CFUNCKEYS_HPP
