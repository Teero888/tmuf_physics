#ifndef CSYSTEMFIDSDRIVE_HPP
#define CSYSTEMFIDSDRIVE_HPP

#include "typedefs.h"

struct CSystemFidsDrive {
    void** vftable; // accesses: 3
    byte _padding_0x4[20];
    CSystemFidsDrive * field_0x18; // accesses: 1
    byte _final_padding[0x2c]; // Total size: 0x48

    // Member Functions
    void __thiscall CSystemFidsDrive(CSystemFidsDrive *this,CSystemFidsDrive *param_1);
    void __thiscall SetDriveName (CSystemFidsDrive *this,CSystemFidsDrive *param_1,CFastStringInt *param_2);
    void __thiscall ~CSystemFidsDrive(CSystemFidsDrive *this,CSystemFidsDrive *param_1);
};

#endif // CSYSTEMFIDSDRIVE_HPP
