#ifndef CGAMESKIN_HPP
#define CGAMESKIN_HPP

#include "typedefs.h"

struct CGameSkin {
    byte _padding_0x0[28];
    undefined * field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1

    // Member Functions
    ulong __thiscall GetIconIndex(CGameSkin *this,CGameSkin *param_1);
    void __thiscall GetIcon(CGameSkin *this,CMwParamFastBuffer<class_CMwParamVec4> *param_1, EMwIconList *param_2,EMwIconList *param_3);
    void __thiscall GetSkinDisplayName (CGameSkin *this,CGameSkin *param_1,CSystemPackDesc *param_2,CFastStringInt *param_3);
};

#endif // CGAMESKIN_HPP
