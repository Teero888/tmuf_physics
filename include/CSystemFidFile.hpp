#ifndef CSYSTEMFIDFILE_HPP
#define CSYSTEMFIDFILE_HPP

#include "typedefs.h"

struct CSystemFidFile {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    byte _padding_0x8[12];
    int * field_0x14; // accesses: 4
    undefined4 field_0x18; // accesses: 1
    uint field_0x1c; // accesses: 2
    byte _padding_0x20[76];
    undefined ** field_0x6c; // accesses: 2
    byte _padding_0x70[4];
    undefined4 field_0x74; // accesses: 3
    undefined * field_0x78; // accesses: 4
    byte _padding_0x7c[4];
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1

    // Member Functions
    int __thiscall GetFullNameUpTo (CSystemFidFile *this,CSystemFidsDrive *param_1,CFastStringInt *param_2, CSystemFids *param_3);
    int __thiscall OSCheckIfExists(CSystemFidFile *this,CSystemFidFile *param_1);
    void __thiscall CSystemFidFile(CSystemFidFile *this,CSystemFidFile *param_1);
    void __thiscall ForceUpdateFidProps(CSystemFidFile *this,CSystemFidFile *param_1);
    void __thiscall GetFullName(CSystemFidFile *this,CPlugFile *param_1,CFastStringInt *param_2);
    void __thiscall SetFileName(CSystemFidFile *this,CSystemFidFile *param_1,CFastStringInt *param_2);
    void __thiscall ~CSystemFidFile(CSystemFidFile *this,CSystemFidFile *param_1);
};

#endif // CSYSTEMFIDFILE_HPP
