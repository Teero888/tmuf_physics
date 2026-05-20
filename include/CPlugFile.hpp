#ifndef CPLUGFILE_HPP
#define CPLUGFILE_HPP

#include "typedefs.h"

struct CSystemFidFile;

struct CPlugFile {
    byte _padding_0x0[8];
    char * field_0x8; // accesses: 2

    // Member Functions
    CPlugFile * __cdecl CreateFromFid(CSystemFidFile *param_1);
    ulong __cdecl GetClassIdFromFid(CSystemFidFile *param_1);
    ulong __cdecl GetClassIdFromFileName(CFastStringInt *param_1);
    void __thiscall CPlugFile(CPlugFile *this,CPlugFile *param_1);
    void __thiscall GetFullName(CPlugFile *this,CPlugFile *param_1,CFastStringInt *param_2);
};

#endif // CPLUGFILE_HPP
