#ifndef CSYSTEMFIDSFOLDER_HPP
#define CSYSTEMFIDSFOLDER_HPP

#include "typedefs.h"

struct CSystemFidsFolder {
    void** vftable; // accesses: 3
    byte _padding_0x4[16];
    int * field_0x14; // accesses: 1
    byte _padding_0x18[28];
    uint field_0x34; // accesses: 2
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 2
    undefined * field_0x44; // accesses: 3

    // Member Functions
    EMakeDir __cdecl MakeDir(CFastStringInt *param_1);
    void __thiscall CSystemFidsFolder(CSystemFidsFolder *this,CSystemFidsFolder *param_1);
    void __thiscall GetFullName(CSystemFidsFolder *this,CPlugFile *param_1,CFastStringInt *param_2);
    void __thiscall SetDirName (CSystemFidsFolder *this,CSystemFidsFolder *param_1,CFastStringInt *param_2);
    void __thiscall ~CSystemFidsFolder(CSystemFidsFolder *this,CSystemFidsFolder *param_1);
};

#endif // CSYSTEMFIDSFOLDER_HPP
