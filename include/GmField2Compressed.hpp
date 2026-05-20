#ifndef GMFIELD2COMPRESSED_HPP
#define GMFIELD2COMPRESSED_HPP

#include "typedefs.h"

struct GmField2Compressed {
    byte _padding_0x0[36];
    float field_0x24; // accesses: 2
    float field_0x28; // accesses: 1
    float field_0x2c; // accesses: 2
    float field_0x30; // accesses: 2

    // Member Functions
    void __thiscall GetAxeXAt(void *this,GmField2Compressed *param_1,GmNat2 *param_2,float *param_3);
    void __thiscall GetScaleAndRotationAt (void *this,GmField2Compressed *param_1,GmVec2 *param_2,float *param_3,float *param_4);
    void __thiscall GetScaleAt (void *this,GmField2Compressed *param_1,GmVec2 *param_2,float *param_3);
    void __thiscall GetVec2At (void *this,GmField2Compressed *param_1,GmNat2 *param_2,GmVec2 *param_3);
};

#endif // GMFIELD2COMPRESSED_HPP
