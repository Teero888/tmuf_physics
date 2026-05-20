#ifndef GMMAT2_HPP
#define GMMAT2_HPP

#include "typedefs.h"

struct GmIso4;

struct GmMat2 {
    GmIso4 * field_0x0; // accesses: 7
    float field_0x4; // accesses: 6
    float field_0x8; // accesses: 6
    float field_0xc; // accesses: 6

    // Member Functions
    void __thiscall Mult(void *this,GmIso3 *param_1,GmIso3 *param_2);
    void __thiscall Rotate(void *this,GmMat2 *param_1,float param_2);
    void __thiscall SetIdentity(void *this,GmMat43 *param_1);
    void __thiscall SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3);
    void __thiscall SetRotation(void *this,GmMat2 *param_1,float param_2);
    void __thiscall SetTranspose(void *this,GmMat2 *param_1,GmMat2 *param_2);
};

#endif // GMMAT2_HPP
