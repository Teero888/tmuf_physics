#ifndef CFASTSTRING_HPP
#define CFASTSTRING_HPP

#include "typedefs.h"

struct SStringParam;

struct CFastString {
    byte _padding_0x0[4];
    CFastString * field_0x4; // accesses: 59
    int field_0x8; // accesses: 4
    undefined1 * field_0xc; // accesses: 2
    int field_0x10; // accesses: 5
    int field_0x14; // accesses: 6
    char * field_0x18; // accesses: 3

    // Member Functions
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ void __thiscall RemoveAllWhiteSpaces(CFastString *this,CFastString *param_1,char *param_2);
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ void __thiscall SetNat64 (CFastString *this,CFastString *param_1,uint64 param_2,int param_3,ulong param_4, int param_5,int param_6,int param_7);
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ void __thiscall SetNatural (CFastString *this,CFastString *param_1,ulong param_2,int param_3,ulong param_4, int param_5,int param_6,int param_7);
    /* WARNING: Removing unreachable block (ram,0x00900159) */ int __cdecl CFastString::FilterStringForPrintableChars(CFastString *param_1);
    CFastString * __thiscall Format(CFastString *this,CFastString *param_1,char *param_2);
    CPlugFileGpuBuilder * __thiscall operator<<(CFastString *this,CPlugFileGpuBuilder *param_1,char *param_2);
    int __thiscall CompareNoCase (CFastString *this,CFastStringInt *param_1,SStringParam *param_2,ulong param_3);
    int __thiscall GetInteger(CFastString *this,CFastString *param_1,int *param_2,ulong param_3);
    int __thiscall GetLineAt(CFastString *this,CFastString *param_1,ulong param_2,CFastString *param_3);
    int __thiscall GetNatural (CFastString *this,CFastString *param_1,ulong *param_2,int param_3,ulong param_4);
    int __thiscall GetNextToken(CFastString *this,CFastStringInt *param_1,SFastTokenInt *param_2);
    int __thiscall GetReal(CFastString *this,CFastString *param_1,float *param_2);
    int __thiscall ReplaceFirst (CFastString *this,CFastString *param_1,SStringParam *param_2,SStringParam *param_3, ulong param_4,ulong param_5);
    int __thiscall TruncAfterChar(CFastString *this,CFastString *param_1,char param_2,int param_3);
    ulong __thiscall FindFirst(CFastString *this,CFastStringInt *param_1,ulong param_2,ulong param_3);
    ulong __thiscall FindFirstCharInSet (CFastString *this,CFastString *param_1,SStringParam *param_2,ulong param_3);
    void __thiscall CFastString(CFastString *this,CFastString *param_1,char *param_2);
    void __thiscall Compare (CFastString *this,SParam_Fids *param_1,SParam *param_2,int *param_3,int *param_4);
    void __thiscall Concat(CFastString *this,CFastStringInt *param_1,SStringParam *param_2);
    void __thiscall ConcatAndNewLine (CFastString *this,CFastString *param_1,SStringParam *param_2,char *param_3);
    void __thiscall ConcatBefore(CFastString *this,CFastStringInt *param_1,SStringParamInt *param_2);
    void __thiscall ConcatFormat(CFastString *this,CFastStringInt *param_1,char *param_2);
    void __thiscall InternalVFormat(CFastString *this,CFastString *param_1,char *param_2,char *param_3);
    void __thiscall SetLength (CFastString *this,CFastString *param_1,ulong param_2,int param_3,char param_4);
    void __thiscall SetReal(CFastString *this,CFastString *param_1,float param_2,ulong param_3);
    void __thiscall SetRealWithoutExponent (CFastString *this,CFastString *param_1,float param_2,ulong param_3);
    void __thiscall SetString(CFastString *this,CFastStringInt *param_1,SStringParam *param_2);
    void __thiscall TrimLeft(CFastString *this,CFastString *param_1,char *param_2);
    void __thiscall TrimRight(CFastString *this,CFastString *param_1,char *param_2);
    void __thiscall TruncAfter(CFastString *this,CFastString *param_1,ulong param_2);
    void __thiscall TruncBefore(CFastString *this,CFastString *param_1,ulong param_2);
    void __thiscall UpCase(CFastString *this,CFastString *param_1,ulong param_2,ulong param_3);
};

#endif // CFASTSTRING_HPP
