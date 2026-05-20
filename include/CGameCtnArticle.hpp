#ifndef CGAMECTNARTICLE_HPP
#define CGAMECTNARTICLE_HPP

#include "typedefs.h"

struct CGameSkin;
struct CMwNod;
struct CPlugShaderApply;

struct CGameCtnArticle {
    byte _padding_0x0[36];
    CPlugShaderApply * field_0x24; // accesses: 2
    byte _padding_0x28[16];
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    byte _padding_0x48[16];
    CGameSkin * field_0x58; // accesses: 4
    undefined4 field_0x5c; // accesses: 3

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ CFuncEnum * __thiscall CreateIcon (CGameCtnArticle *this,CGameCtnArticle *param_1,ulong param_2,int param_3);
    CPlugBitmap * __thiscall GetSkinIconByChecksum (CGameCtnArticle *this,CGameCtnArticle *param_1,SNat128 *param_2);
    CPlugBitmap * __thiscall GetSkinIconByIndex(CGameCtnArticle *this,CGameCtnArticle *param_1,ulong param_2);
    int __thiscall HasDefaultSkin(CGameCtnArticle *this,CGameCtnArticle *param_1);
    ulong __thiscall GetDefaultSkinIndex(CGameCtnArticle *this,CGameCtnArticle *param_1);
    ulong __thiscall GetSkinIndexFromDisplayName (CGameCtnArticle *this,CGameCtnArticle *param_1,CFastStringInt *param_2);
    void __cdecl PurgeAllForce(void);
    void __thiscall GetDefaultSkinChecksum (CGameCtnArticle *this,CGameCtnArticle *param_1,SNat128 *param_2);
    void __thiscall GetSkinChecksum (CGameCtnArticle *this,CGameCtnArticle *param_1,ulong param_2,SNat128 *param_3);
    void __thiscall GetSkinDisplayName (CGameCtnArticle *this,CGameSkin *param_1,CSystemPackDesc *param_2,CFastStringInt *param_3 );
    void __thiscall Purge(CGameCtnArticle *this,CGameCtnArticle *param_1);
};

#endif // CGAMECTNARTICLE_HPP
