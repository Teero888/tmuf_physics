#ifndef CPLUGFONT_HPP
#define CPLUGFONT_HPP

#include "typedefs.h"

struct CPlugFont {
    struct CUrlLinks {

        // Member Functions
        /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall AddLineFeed(CUrlLinks *this,CUrlLinks *param_1);
    };

    struct SCharStyle {
        void** vftable; // accesses: 2
        undefined4 field_0x4; // accesses: 2
        undefined4 field_0x8; // accesses: 2
        undefined4 field_0xc; // accesses: 2
        undefined4 field_0x10; // accesses: 3
        uint field_0x14; // accesses: 2
        undefined4 field_0x18; // accesses: 1

        // Member Functions
        void __thiscall Init (void *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2, CVisionViewportDx9 *param_3,ESpriteColor0 *param_4);
        void __thiscall Pop(void *this,SCharStyle *param_1);
        void __thiscall Push(void *this,CFastBufferWheel<float> *param_1,float *param_2);
        void __thiscall SCharStyle(void *this,SCharStyle *param_1);
        void __thiscall ~SCharStyle(void *this,SCharStyle *param_1);
    };


    // Member Functions
    float __thiscall GetLength(CPlugFont *this,CPlugFileSnd *param_1);
    ulong __cdecl ReadNextChar(CFastStringInt *param_1,SCharStyle *param_2);
    void __cdecl GetPureString(CFastStringInt *param_1,CFastStringInt *param_2);
};

#endif // CPLUGFONT_HPP
