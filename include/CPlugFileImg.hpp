#ifndef CPLUGFILEIMG_HPP
#define CPLUGFILEIMG_HPP

#include "typedefs.h"

struct CPlugFileImg {
    byte _padding_0x0[2];
    undefined2 field_0x2; // accesses: 2
    undefined2 field_0x4; // accesses: 6
    byte _padding_0x6[2];
    ulong field_0x8; // accesses: 2
    undefined4 field_0xc; // accesses: 8
    byte _padding_0x10[4];
    undefined4 field_0x14; // accesses: 1
    ulong field_0x18; // accesses: 9
    ulong field_0x1c; // accesses: 11
    ulong field_0x20; // accesses: 6
    undefined4 field_0x24; // accesses: 33
    uchar * field_0x28; // accesses: 19
    ulong field_0x2c; // accesses: 4
    undefined4 field_0x30; // accesses: 1

    // Member Functions
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ void __thiscall Force1stPixelAlpha0(CPlugFileImg *this,CPlugFileImg *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall FilterWrappedPixel (CPlugFileImg *this,CPlugFileImg *param_1,GxBGRAColor_conflict *param_2, GxTexCoord *param_3,EGxTexFilter param_4,ulong param_5,ulong param_6,ECubeFace param_7, EGxTexAddress param_8);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetPixelFromNormal (CPlugFileImg *this,CPlugFileImg *param_1,ushort *param_2,GmVec3 *param_3);
    int __thiscall IsInSystemMemory(CPlugFileImg *this,CPlugFileImg *param_1);
    int __thiscall ReGenerateForceTexelLoading(CPlugFileImg *this,CPlugFileImg *param_1);
    uchar * __thiscall GetFaceLevel (CPlugFileImg *this,CPlugFileImg *param_1,ulong param_2,ulong param_3,ulong *param_4, GmNat3 *param_5);
    uchar * __thiscall GetPixel(CPlugFileImg *this,CPlugFileImg *param_1,ulong param_2,ulong param_3);
    uchar * __thiscall GetWrappedPixel (CPlugFileImg *this,CPlugFileImg *param_1,GxTexCoord *param_2,ECubeFace param_3);
    ulong __cdecl GetMipMapTotalNbBlock4x4 (ulong param_1,ulong param_2,ulong param_3,ulong param_4,ulong param_5);
    ulong __cdecl GetMipMapTotalNbPixel (ulong param_1,ulong param_2,ulong param_3,ulong param_4,ulong param_5);
    ulong __thiscall ComputeByteSize(CPlugFileImg *this,CPlugFileImg *param_1,int param_2);
    ulong __thiscall GetByteSizePerComp(CPlugFileImg *this,CPlugFileImg *param_1);
    void * __thiscall AllocatePixels(CPlugFileImg *this,CPlugFileImg *param_1);
    void __thiscall AddAlpha_BGRA(CPlugFileImg *this,CPlugFileImg *param_1,uchar param_2);
    void __thiscall CPlugFileImg(CPlugFileImg *this,CPlugFileImg *param_1);
    void __thiscall DeletePixels(CPlugFileImg *this,CPlugFileImg *param_1);
    void __thiscall ForceBorders_BGRA (CPlugFileImg *this,CPlugFileImg *param_1,GxBGRAColor_conflict *param_2,int param_3, int param_4,ulong param_5);
    void __thiscall GetPixelMip (CPlugFileImg *this,CPlugFileImg *param_1,GxBGRAColor_conflict *param_2,ulong param_3, ulong param_4,ulong param_5,ECubeFace param_6);
    void __thiscall SetPixels (CPlugFileImg *this,CPlugFileImg *param_1,SDesc *param_2,uchar *param_3,ulong param_4);
};

#endif // CPLUGFILEIMG_HPP
