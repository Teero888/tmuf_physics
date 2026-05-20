#ifndef CSYSTEMFIDSDRIVE_HPP
#define CSYSTEMFIDSDRIVE_HPP

#include "typedefs.h"

struct CSystemFidsDrive {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    byte _padding_0x8[16];
    CSystemFidsDrive * field_0x18; // accesses: 1

    // Member Functions
    void __thiscall CSystemFidsDrive(CSystemFidsDrive *this,CSystemFidsDrive *param_1);
    void __thiscall SetDriveName (CSystemFidsDrive *this,CSystemFidsDrive *param_1,CFastStringInt *param_2);
    void __thiscall ~CSystemFidsDrive(CSystemFidsDrive *this,CSystemFidsDrive *param_1);
};

#endif // CSYSTEMFIDSDRIVE_HPP
