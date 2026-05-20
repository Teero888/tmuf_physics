#ifndef GMRECTALIGNED_HPP
#define GMRECTALIGNED_HPP

#include "typedefs.h"

struct GmRectAligned {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 7
    float field_0x8; // accesses: 6
    float field_0xc; // accesses: 6

    // Member Functions
    int __thiscall TestInter (void *this,CPlugVolumeProjector *param_1,GmBoxAligned *param_2,GmIso4 *param_3);
    void __thiscall Mult(void *this,GmIso3 *param_1,GmIso3 *param_2);
    void __thiscall SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3);
};

#endif // GMRECTALIGNED_HPP
