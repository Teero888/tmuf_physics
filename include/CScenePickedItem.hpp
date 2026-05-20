#ifndef CSCENEPICKEDITEM_HPP
#define CSCENEPICKEDITEM_HPP

#include "typedefs.h"

struct CMwNod;

struct CScenePickedItem {
    void** vftable; // accesses: 1
    byte _padding_0x4[16];
    int * field_0x14; // accesses: 3
    byte _padding_0x18[212];
    CMwNod * field_0xec; // accesses: 4
    CMwNod * field_0xf0; // accesses: 4
    byte _padding_0xf4[48];
    undefined4 field_0x124; // accesses: 2
    byte _padding_0x128[48];
    undefined4 field_0x158; // accesses: 2
    CMwNod * field_0x15c; // accesses: 2

    // Member Functions
    void __thiscall CScenePickedItem(CScenePickedItem *this,CScenePickedItem *param_1);
    void __thiscall Reset(CScenePickedItem *this,GmFrustumIso4 *param_1);
    void __thiscall SetKilledCallBack (CScenePickedItem *this,CScenePickedItem *param_1,CMwNod *param_2, _func___cdecl_void_CScenePickedItem_ptr *param_3);
    void __thiscall SubDependences(CScenePickedItem *this,CScenePickedItem *param_1);
};

#endif // CSCENEPICKEDITEM_HPP
