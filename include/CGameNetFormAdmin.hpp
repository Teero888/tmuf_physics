#ifndef CGAMENETFORMADMIN_HPP
#define CGAMENETFORMADMIN_HPP

#include "typedefs.h"

struct CGameNetFormAdmin {
    void** vftable; // accesses: 2
    byte _padding_0x4[24];
    undefined4 field_0x1c; // accesses: 1

    // Member Functions
    void __thiscall CGameNetFormAdmin (CGameNetFormAdmin *this,CGameNetFormAdmin *param_1,EMessageType param_2);
    void __thiscall ~CGameNetFormAdmin(CGameNetFormAdmin *this,CGameNetFormAdmin *param_1);
};

#endif // CGAMENETFORMADMIN_HPP
