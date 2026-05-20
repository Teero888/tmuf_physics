#ifndef CCLASSICI18N_HPP
#define CCLASSICI18N_HPP

#include "typedefs.h"

struct SStringParam;

struct CClassicI18n {
    byte _padding_0x0[2];
    ushort field_0x2; // accesses: 1
    undefined4 field_0x4; // accesses: 23
    undefined4 field_0x8; // accesses: 7
    undefined4 field_0xc; // accesses: 8
    byte _padding_0x10[8];
    undefined4 field_0x18; // accesses: 5
    undefined4 field_0x1c; // accesses: 10
    undefined4 field_0x20; // accesses: 8
    undefined4 field_0x24; // accesses: 3

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall IsLatinCharsInCurCatalog(CClassicI18n *this,CClassicI18n *param_1,ulong param_2);
    char * __cdecl StripContext(char *param_1);
    int __cdecl GetPrimaryLanguage(char *param_1,char *param_2);
    int __thiscall LoadMessageCatalog (CClassicI18n *this,CClassicI18n *param_1,char *param_2,CClassicBuffer *param_3, CFastString *param_4);
    ulong __cdecl IsLanguageKindOf(char *param_1,char *param_2);
    ulong __thiscall FindMsg(CClassicI18n *this,CClassicI18n *param_1,wchar_t *param_2);
    void __thiscall ComputeHashTable(CClassicI18n *this,CClassicI18n *param_1);
    void __thiscall InsertMsg(CClassicI18n *this,CClassicI18n *param_1,wchar_t *param_2,ulong param_3);
    void __thiscall Reset(CClassicI18n *this,GmFrustumIso4 *param_1);
    wchar_t * __cdecl ConvertStringForWin32(CFastStringInt *param_1);
    wchar_t * __cdecl GetTranslatedString(CFastStringInt *param_1);
    wchar_t * __thiscall GetTranslatedStringInternal(CClassicI18n *this,CClassicI18n *param_1,wchar_t *param_2);
};

#endif // CCLASSICI18N_HPP
