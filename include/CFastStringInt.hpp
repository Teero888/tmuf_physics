#ifndef CFASTSTRINGINT_HPP
#define CFASTSTRINGINT_HPP

#include "typedefs.h"

struct CFastString;

struct CFastStringInt {
    void** vftable; // accesses: 20
    int field_0x4; // accesses: 29

    // Member Functions
    CFastString __thiscall GetLatin1(void *this,CFastStringInt *param_1);
    int __cdecl FilterTo7bit(CFastString *param_1,SStringParam *param_2,char param_3);
    int __thiscall CompareNoCase (void *this,CFastStringInt *param_1,SStringParam *param_2,ulong param_3);
    int __thiscall GetNextToken(void *this,CFastStringInt *param_1,SFastTokenInt *param_2);
    ulong __thiscall FindFirst(void *this,CFastStringInt *param_1,ulong param_2,ulong param_3);
    ulong __thiscall FindLast(void *this,CFastStringInt *param_1,ulong param_2,ulong param_3);
    ulong __thiscall ReadCharsNext(void *this,CFastStringInt *param_1,ulong *param_2);
    ulong __thiscall ReadCharsStart(void *this,CFastStringInt *param_1);
    void * __thiscall _scalar_deleting_destructor_(void *this,CPfmHeap *param_1,uint param_2);
    void __thiscall CFastStringInt(void *this,CFastStringInt *param_1,SStringParam *param_2);
    void __thiscall Compare(void *this,SParam_Fids *param_1,SParam *param_2,int *param_3,int *param_4);
    void __thiscall Concat(void *this,CFastStringInt *param_1,SStringParam *param_2);
    void __thiscall ConcatBefore(void *this,CFastStringInt *param_1,SStringParamInt *param_2);
    void __thiscall ConcatFormat(void *this,CFastStringInt *param_1,char *param_2);
    void __thiscall GetAscii(void *this,CFastStringInt *param_1,CFastString *param_2);
    void __thiscall GetEscaped(void *this,CFastStringInt *param_1,CFastString *param_2);
    void __thiscall GetLimitedSizeUtf8OrAscii (void *this,CFastStringInt *param_1,CFastString *param_2,ulong param_3);
    void __thiscall GetUtf8(void *this,CFastStringInt *param_1,CFastString *param_2,int param_3);
    void __thiscall GetUtf8OrAscii(void *this,CFastStringInt *param_1,CFastString *param_2);
    void __thiscall InternalSetCompose (void *this,CFastStringInt *param_1,ulong param_2,wchar_t *param_3,char *param_4, CFastArray<struct_SStringParamInt_const*> *param_5);
    void __thiscall SetCompose (void *this,CFastStringInt *param_1,SStringParam *param_2,SStringParamInt *param_3);
    void __thiscall SetEscaped(void *this,CFastStringInt *param_1,CFastString *param_2);
    void __thiscall SetLatin1OrUtf8(void *this,CFastStringInt *param_1,SStringParam *param_2);
    void __thiscall SetLength(void *this,CFastString *param_1,ulong param_2,int param_3,char param_4);
    void __thiscall SetString(void *this,CFastStringInt *param_1,SStringParam *param_2);
    void __thiscall SetUtf8(void *this,CFastStringInt *param_1,SStringParam *param_2);
    void __thiscall TruncAfterIndex(void *this,CFastStringInt *param_1,ulong param_2);
    void __thiscall TruncBeforeIndex(void *this,CFastStringInt *param_1,ulong param_2);
};

#endif // CFASTSTRINGINT_HPP
