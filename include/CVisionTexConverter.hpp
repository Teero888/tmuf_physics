#ifndef CVISIONTEXCONVERTER_HPP
#define CVISIONTEXCONVERTER_HPP

#include "typedefs.h"

struct CVisionTexConverter {
    void** vftable; // accesses: 11

    // Member Functions
    CPlugFileImg * __thiscall GetImage(CVisionTexConverter *this,CVisionTexConverter *param_1);
    uchar * __thiscall GetPixels (CVisionTexConverter *this,CVisionTexConverter *param_1,ulong param_2,ulong param_3, ulong *param_4,GmNat3 *param_5);
    void __thiscall HeightToBumpNormal (CVisionTexConverter *this,CVisionTexConverter *param_1,ENormalFormat param_2, GxRGBAColor *param_3);
    void __thiscall HeightToDispH01(CVisionTexConverter *this,CVisionTexConverter *param_1);
    void __thiscall InvertYCubeMapFace (CVisionTexConverter *this,CVisionTexConverter *param_1,ulong param_2);
    void __thiscall RxGyBz_To_R0GyBzAx(CVisionTexConverter *this,CVisionTexConverter *param_1);
    void __thiscall ~CVisionTexConverter(CVisionTexConverter *this,CVisionTexConverter *param_1);
};

#endif // CVISIONTEXCONVERTER_HPP
