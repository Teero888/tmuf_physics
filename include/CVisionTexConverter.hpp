#ifndef CVISIONTEXCONVERTER_HPP
#define CVISIONTEXCONVERTER_HPP

#include "typedefs.h"

struct CVisionTexConverter {
    byte _padding_0x0[1];
    int field_0x1; // accesses: 7
    byte _padding_0x5[43];
    byte field_0x30; // accesses: 4
    byte _padding_0x31[2];
    undefined1 field_0x33; // accesses: 2
    byte _padding_0x34[1];
    byte field_0x35; // accesses: 2
    byte _padding_0x36[4];
    uint field_0x3a; // accesses: 3
    uint * field_0x3b; // accesses: 3
    byte _padding_0x3f[859056627];
    uint field_0x33342a32; // accesses: 2

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
