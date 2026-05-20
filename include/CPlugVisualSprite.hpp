#ifndef CPLUGVISUALSPRITE_HPP
#define CPLUGVISUALSPRITE_HPP

#include "typedefs.h"

struct CPlugVisualSprite {
    void** vftable; // accesses: 1
    byte _padding_0x4[24];
    uint field_0x1c; // accesses: 8
    byte _padding_0x20[20];
    float field_0x34; // accesses: 1
    float field_0x38; // accesses: 1
    float field_0x3c; // accesses: 1
    float field_0x40; // accesses: 1
    float field_0x44; // accesses: 1
    float field_0x48; // accesses: 1
    byte _padding_0x4c[76];
    undefined4 field_0x98; // accesses: 1
    undefined4 field_0x9c; // accesses: 1
    undefined4 field_0xa0; // accesses: 1
    undefined4 field_0xa4; // accesses: 1
    undefined4 field_0xa8; // accesses: 1
    undefined4 field_0xac; // accesses: 1
    uint field_0xb0; // accesses: 9
    ushort field_0xb4; // accesses: 5
    ushort field_0xb6; // accesses: 4
    byte _final_padding[0x8]; // Total size: 0xc0

    // Member Functions
    ulong __thiscall AddTexCoordSet (CPlugVisualSprite *this,CPlugVisualSprite *param_1,float param_2,float param_3, ulong param_4,float param_5,float param_6);
    void __thiscall AddSprite (CPlugVisualSprite *this,CPlugVisualSprite *param_1,GmVec3 *param_2,float param_3, GxColor *param_4,float param_5,float param_6,ulong param_7);
    void __thiscall CPlugVisualSprite(CPlugVisualSprite *this,CPlugVisualSprite *param_1);
    void __thiscall ComputeBoundingBox (CPlugVisualSprite *this,CPlugVisualStrip *param_1,ulong param_2,ulong param_3);
    void __thiscall SetRenderMode (CPlugVisualSprite *this,CPlugVisualIndexedLines *param_1,ERenderMode param_2);
    void __thiscall SetSpriteFlags (CPlugVisualSprite *this,CPlugVisualSprite *param_1,SSpriteF *param_2);
    void __thiscall UpdateAtlasTexCoords(CPlugVisualSprite *this,CPlugVisualSprite *param_1);
};

#endif // CPLUGVISUALSPRITE_HPP
