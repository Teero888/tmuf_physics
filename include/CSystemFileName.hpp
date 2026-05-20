#ifndef CSYSTEMFILENAME_HPP
#define CSYSTEMFILENAME_HPP

#include "typedefs.h"

struct CSystemFileName {
    byte _padding_0x0[2];
    short field_0x2; // accesses: 2
    wchar_t * field_0x4; // accesses: 22
    short field_0x6; // accesses: 2

    // Member Functions
    /* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */ void __cdecl ConvertToSystemName (CFastStringInt *param_1,CFastString *param_2,int param_3,EMode param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl SplitPath (CFastStringInt *param_1,CFastStringInt *param_2,CFastStringInt *param_3, CFastStringInt *param_4,CFastStringInt *param_5,CFastStringInt *param_6);
    int __cdecl GetRelativeName (CFastStringInt *param_1,CFastStringInt *param_2,CFastStringInt *param_3);
    int __cdecl IsDirectoryName(CFastStringInt *param_1);
    int __cdecl IsExtension(CFastStringInt *param_1,char *param_2);
    int __cdecl IsExtensionGbx(CFastStringInt *param_1);
    int __cdecl IsNormalized(CFastStringInt *param_1);
    int __cdecl IsValidShortFileName(CFastStringInt *param_1);
    int __cdecl SplitFirstDirectory(CFastStringInt *param_1,CFastStringInt *param_2,ulong *param_3);
    void __cdecl ConcatDirectory(CFastStringInt *param_1,CFastStringInt *param_2);
    void __cdecl ExtractFullPathName(CFastStringInt *param_1,CFastStringInt *param_2);
    void __cdecl ExtractShortBaseName(CFastStringInt *param_1,CFastStringInt *param_2);
    void __cdecl ExtractShortName(CFastStringInt *param_1,CFastStringInt *param_2);
    void __cdecl FixFileName(CFastStringInt *param_1,ulong param_2);
    void __cdecl SplitLastDirectory(CFastStringInt *param_1,CFastStringInt *param_2);
    void __cdecl StripExtension(CFastStringInt *param_1,CFastStringInt *param_2);
    void __cdecl StripTrailingSlash(CFastStringInt *param_1);
    void __thiscall Normalize(void *this,GmQuat *param_1);
};

#endif // CSYSTEMFILENAME_HPP
