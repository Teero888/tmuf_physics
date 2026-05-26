#ifndef GMMAP2_UNSIGNED_CHAR__HPP
#define GMMAP2_UNSIGNED_CHAR__HPP

#include "typedefs.h"

struct GmMap2<unsigned_char> {
    float field_0x0; // accesses: 4
    float field_0x4; // accesses: 4
    float field_0x8; // accesses: 4
    float field_0xc; // accesses: 4
    float field_0x10; // accesses: 7
    float field_0x14; // accesses: 5
    float field_0x18; // accesses: 1

    // Member Functions
    GmVec3 __thiscall GetValue(void *this,CFuncColorGradient *param_1,float param_2);
    ulong __thiscall IsInside(void *this,GmRectAligned *param_1,GmVec2 *param_2);
    void __thiscall GmMap2<unsigned_char>(void *this,GmMap2<unsigned_char> *param_1);
    void __thiscall Init (void *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2, CVisionViewportDx9 *param_3,ESpriteColor0 *param_4);
    void __thiscall SetValue(void *this,CMwCmdAffectParamBool *param_1);
};

#endif // GMMAP2_UNSIGNED_CHAR__HPP
