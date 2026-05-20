#ifndef GMFIELD2COMPRESSED_HPP
#define GMFIELD2COMPRESSED_HPP

#include "typedefs.h"

struct GmField2Compressed {

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GetAxeXAt(void *this,GmField2Compressed *param_1,GmNat2 *param_2,float *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GetVec2At (void *this,GmField2Compressed *param_1,GmNat2 *param_2,GmVec2 *param_3);
    void __thiscall GetScaleAndRotationAt (void *this,GmField2Compressed *param_1,GmVec2 *param_2,float *param_3,float *param_4);
    void __thiscall GetScaleAt (void *this,GmField2Compressed *param_1,GmVec2 *param_2,float *param_3);
};

#endif // GMFIELD2COMPRESSED_HPP
