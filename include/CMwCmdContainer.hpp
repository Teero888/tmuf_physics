#ifndef CMWCMDCONTAINER_HPP
#define CMWCMDCONTAINER_HPP

#include "typedefs.h"

struct CMwCmdContainer {
    void** vftable; // accesses: 1
    byte _padding_0x4[28];
    undefined4 field_0x20; // accesses: 2

    // Member Functions
    CMwCmdFastCall * __thiscall AddFastCall (CMwCmdContainer *this,CMwCmdContainer *param_1,CMwNod *param_2, _func___cdecl_void *param_3,ulong param_4);
    void __thiscall AddCmd(CMwCmdContainer *this,CMwCmdBuffer *param_1,CMwCmd *param_2);
    void __thiscall CMwCmdContainer(CMwCmdContainer *this,CMwCmdContainer *param_1);
};

#endif // CMWCMDCONTAINER_HPP
