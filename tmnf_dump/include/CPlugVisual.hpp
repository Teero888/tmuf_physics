#ifndef CPLUGVISUAL_HPP
#define CPLUGVISUAL_HPP

#include "typedefs.h"

struct CPlugVisual {
    void** vftable; // accesses: 6
    byte _final_padding[0x6]; // Total size: 0xa

    // Member Functions
    int __thiscall IsVisible(CPlugVisual *this,CPlugVisual *param_1,GmFrustum *param_2,GmIso4 *param_3);
    int __thiscall UpdateVisualFromShaderRequirement (CPlugVisual *this,CPlugVisual *param_1,CPlugShader **param_2,CPlugShader *param_3);
    ulong __thiscall AddTexCoordSet (CPlugVisual *this,CPlugVisualSprite *param_1,float param_2,float param_3,ulong param_4, float param_5,float param_6);
    void __thiscall CPlugVisual(CPlugVisual *this,CPlugVisual *param_1,CPlugVisual *param_2);
    void __thiscall EnableVertexColor(CPlugVisual *this,CPlugVisual *param_1,int param_2);
    void __thiscall EnableVertexNormal(CPlugVisual *this,CPlugVisual *param_1,int param_2);
    void __thiscall RemoveTexCoordSetAll(CPlugVisual *this,CPlugVisual *param_1);
    void __thiscall SetBoundingBox(CPlugVisual *this,CPlugVisual *param_1,GmBoxAligned *param_2);
    void __thiscall SetBoundingMinMax (CPlugVisual *this,CPlugVisual *param_1,GmVec3 *param_2,GmVec3 *param_3);
};

#endif // CPLUGVISUAL_HPP
