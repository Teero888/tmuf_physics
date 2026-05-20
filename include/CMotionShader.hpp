#ifndef CMOTIONSHADER_HPP
#define CMOTIONSHADER_HPP

#include "typedefs.h"

struct CMwNod;
struct CPlugMaterial;
struct CPlugShader;

struct CMotionShader {
    byte _padding_0x0[44];
    CPlugMaterial * field_0x2c; // accesses: 5
    CPlugShader * field_0x30; // accesses: 3
    byte _padding_0x34[4];
    undefined4 * field_0x38; // accesses: 6

    // Member Functions
    void __thiscall SetMaterial(CMotionShader *this,CPlugMaterialCustom *param_1,CPlugMaterial *param_2);
    void __thiscall SetShader(CMotionShader *this,CPlugBitmapShader *param_1,CPlugShader *param_2);
};

#endif // CMOTIONSHADER_HPP
