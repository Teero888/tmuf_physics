#ifndef CGAMENETFORMADMIN_HPP
#define CGAMENETFORMADMIN_HPP

#include "typedefs.h"

struct CGameNetFormAdmin {
    byte _padding_0x0[28];
    undefined4 field_0x1c; // accesses: 1

    // Member Functions
    void __thiscall CGameNetFormAdmin (CGameNetFormAdmin *this,CGameNetFormAdmin *param_1,EMessageType param_2);
    void __thiscall ~CGameNetFormAdmin(CGameNetFormAdmin *this,CGameNetFormAdmin *param_1);
};

#endif // CGAMENETFORMADMIN_HPP
