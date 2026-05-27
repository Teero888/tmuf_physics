#ifndef CSYSTEMFILENAME_HPP
#define CSYSTEMFILENAME_HPP

#include "typedefs.h"

struct CSystemFileName {
    void** vftable; // accesses: 5
    short * field_0x4; // accesses: 5

    // Member Functions
    int __cdecl GetRelativeName (CFastStringInt *param_1,CFastStringInt *param_2,CFastStringInt *param_3);
    int __cdecl IsDirectoryName(CFastStringInt *param_1);
    int __cdecl IsExtension(CFastStringInt *param_1,char *param_2);
    int __cdecl IsExtensionGbx(CFastStringInt *param_1);
    int __cdecl IsNormalized(CFastStringInt *param_1);
    int __cdecl IsValidShortFileName(CFastStringInt *param_1);
    int __cdecl SplitFirstDirectory(CFastStringInt *param_1,CFastStringInt *param_2,ulong *param_3);
    void __cdecl ConcatDirectory(CFastStringInt *param_1,CFastStringInt *param_2);
    void __cdecl ConvertToSystemName (CFastStringInt *param_1,CFastString *param_2,int param_3,EMode param_4);
    void __cdecl ExtractFullPathName(CFastStringInt *param_1,CFastStringInt *param_2);
    void __cdecl ExtractShortBaseName(CFastStringInt *param_1,CFastStringInt *param_2);
    void __cdecl ExtractShortName(CFastStringInt *param_1,CFastStringInt *param_2);
    void __cdecl FixFileName(CFastStringInt *param_1,ulong param_2);
    void __cdecl SplitLastDirectory(CFastStringInt *param_1,CFastStringInt *param_2);
    void __cdecl SplitPath (CFastStringInt *param_1,CFastStringInt *param_2,CFastStringInt *param_3, CFastStringInt *param_4,CFastStringInt *param_5,CFastStringInt *param_6);
    void __cdecl StripExtension(CFastStringInt *param_1,CFastStringInt *param_2);
    void __cdecl StripTrailingSlash(CFastStringInt *param_1);
    void __thiscall Normalize(void *this,GmQuat *param_1);
};

#endif // CSYSTEMFILENAME_HPP
