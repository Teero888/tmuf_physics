#ifndef CGAMENETFORM_HPP
#define CGAMENETFORM_HPP

#include "typedefs.h"

struct CGameNetForm {
    void** vftable; // accesses: 2

    // Member Functions
    void __thiscall CGameNetForm(CGameNetForm *this,CGameNetForm *param_1);
    void __thiscall ~CGameNetForm(CGameNetForm *this,CGameNetForm *param_1);
};

#endif // CGAMENETFORM_HPP
