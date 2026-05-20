#ifndef CGAMEAVATAR_HPP
#define CGAMEAVATAR_HPP

#include "typedefs.h"

struct CSystemPackManager;

struct CGameAvatar {
    byte _padding_0x0[32];
    CSystemPackManager * field_0x20; // accesses: 3
    byte _padding_0x24[44];
    CSystemPackManager * field_0x50; // accesses: 1

    // Member Functions
    CPlugBitmap * __thiscall BitmapGet(CGameAvatar *this,CGameAvatar *param_1,EAvatarVariant param_2);
    EAvatarVariant __cdecl ComputeVariantFromText(CFastStringInt *param_1);
};

#endif // CGAMEAVATAR_HPP
