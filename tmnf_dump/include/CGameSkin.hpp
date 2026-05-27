#ifndef CGAMESKIN_HPP
#define CGAMESKIN_HPP

#include "typedefs.h"

struct CGameSkin {
    void** vftable;
    byte _final_padding[0xa0]; // Total size: 0xa4

    // Member Functions
    ulong __thiscall GetIconIndex(CGameSkin *this,CGameSkin *param_1);
    void __thiscall GetIcon(CGameSkin *this,CMwParamFastBuffer<class_CMwParamVec4> *param_1, EMwIconList *param_2,EMwIconList *param_3);
    void __thiscall GetSkinDisplayName (CGameSkin *this,CGameSkin *param_1,CSystemPackDesc *param_2,CFastStringInt *param_3);
};

#endif // CGAMESKIN_HPP
