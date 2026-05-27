#ifndef CPLUGFILE_HPP
#define CPLUGFILE_HPP

#include "typedefs.h"

struct CSystemFidFile;

struct CPlugFile {
    void** vftable; // accesses: 1

    // Member Functions
    CPlugFile * __cdecl CreateFromFid(CSystemFidFile *param_1);
    ulong __cdecl GetClassIdFromFid(CSystemFidFile *param_1);
    ulong __cdecl GetClassIdFromFileName(CFastStringInt *param_1);
    void __thiscall CPlugFile(CPlugFile *this,CPlugFile *param_1);
    void __thiscall GetFullName(CPlugFile *this,CPlugFile *param_1,CFastStringInt *param_2);
};

#endif // CPLUGFILE_HPP
