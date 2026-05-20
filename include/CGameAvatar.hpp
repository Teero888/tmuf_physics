#ifndef CGAMEAVATAR_HPP
#define CGAMEAVATAR_HPP

#include "typedefs.h"

struct CSystemPackManager;

struct CGameAvatar {
    void** vftable;

    // Member Functions
    CPlugBitmap * __thiscall BitmapGet(CGameAvatar *this,CGameAvatar *param_1,EAvatarVariant param_2);
    EAvatarVariant __cdecl ComputeVariantFromText(CFastStringInt *param_1);
};

#endif // CGAMEAVATAR_HPP
