#ifndef CGAMECONTROLCARDMANAGER_HPP
#define CGAMECONTROLCARDMANAGER_HPP

#include "typedefs.h"

struct CMwNod;

struct CGameControlCardManager {
    byte _padding_0x0[20];
    CGameControlCardManager * field_0x14; // accesses: 1
    CMwNod * field_0x18; // accesses: 1

    // Member Functions
    void __thiscall SetGetDataTypeInfosFromNodCallBack (CGameControlCardManager *this,CGameControlCardManager *param_1,CMwNod *param_2, _func___cdecl_void_CMwNod_ptr_CFastString_ptr *param_3);
};

#endif // CGAMECONTROLCARDMANAGER_HPP
