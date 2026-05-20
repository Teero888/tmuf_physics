#ifndef CVISIONTEXCONVERTER_HPP
#define CVISIONTEXCONVERTER_HPP

#include "typedefs.h"

struct CVisionTexConverter {
    void** vftable; // accesses: 11

    // Member Functions
    /* WARNING: Control flow encountered bad instruction data */ /* WARNING: Instruction at (ram,0x009b517d) overlaps instruction at (ram,0x009b517c) */ /* WARNING: Removing unreachable block (ram,0x009b5172) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ CPlugFileImg * __thiscall CVisionTexConverter::GetImage(CVisionTexConverter *this,CVisionTexConverter *param_1);
    /* WARNING: Control flow encountered bad instruction data */ /* WARNING: Instruction at (ram,0x009b517d) overlaps instruction at (ram,0x009b517c) */ /* WARNING: Removing unreachable block (ram,0x009b5172) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CVisionTexConverter::HeightToBumpNormal (CVisionTexConverter *this,CVisionTexConverter *param_1,ENormalFormat param_2, GxRGBAColor *param_3);
    /* WARNING: Control flow encountered bad instruction data */ /* WARNING: Instruction at (ram,0x009b517d) overlaps instruction at (ram,0x009b517c) */ /* WARNING: Removing unreachable block (ram,0x009b5172) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CVisionTexConverter::~CVisionTexConverter(CVisionTexConverter *this,CVisionTexConverter *param_1);
    /* WARNING: Control flow encountered bad instruction data */ /* WARNING: Instruction at (ram,0x009b5362) overlaps instruction at (ram,0x009b5361) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ uchar * __thiscall CVisionTexConverter::GetPixels (CVisionTexConverter *this,CVisionTexConverter *param_1,ulong param_2,ulong param_3, ulong *param_4,GmNat3 *param_5);
    /* WARNING: Control flow encountered bad instruction data */ /* WARNING: Instruction at (ram,0x009b5362) overlaps instruction at (ram,0x009b5361) */ /* WARNING: Unable to track spacebase fully for stack */ /* WARNING: Removing unreachable block (ram,0x009b527e) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CVisionTexConverter::RxGyBz_To_R0GyBzAx(CVisionTexConverter *this,CVisionTexConverter *param_1);
    /* WARNING: Control flow encountered bad instruction data */ /* WARNING: Instruction at (ram,0x009b55e3) overlaps instruction at (ram,0x009b55e0) */ /* WARNING: Unable to track spacebase fully for stack */ /* WARNING: Removing unreachable block (ram,0x009b54fe) */ void __thiscall CVisionTexConverter::InvertYCubeMapFace (CVisionTexConverter *this,CVisionTexConverter *param_1,ulong param_2);
    /* WARNING: Control flow encountered bad instruction data */ void __thiscall HeightToDispH01(CVisionTexConverter *this,CVisionTexConverter *param_1);
};

#endif // CVISIONTEXCONVERTER_HPP
