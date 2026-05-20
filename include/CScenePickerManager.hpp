#ifndef CSCENEPICKERMANAGER_HPP
#define CSCENEPICKERMANAGER_HPP

#include "typedefs.h"

struct CHmsPicker;
struct CMwCmd;
struct CMwNod;

struct CScenePickerManager {
    void** vftable; // accesses: 1
    byte _padding_0x4[12];
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    byte _padding_0x24[708];
    int field_0x2e8; // accesses: 1
    byte _padding_0x2ec[216];
    int field_0x3c4; // accesses: 1
    byte _padding_0x3c8[128];
    undefined4 field_0x448; // accesses: 1
    byte _padding_0x44c[4];
    undefined4 field_0x450; // accesses: 1
    undefined4 field_0x454; // accesses: 1
    byte _padding_0x458[172];
    undefined4 field_0x504; // accesses: 1
    undefined4 field_0x508; // accesses: 2
    undefined4 field_0x50c; // accesses: 2
    byte _padding_0x510[260];
    undefined4 field_0x614; // accesses: 1
    undefined4 field_0x618; // accesses: 1
    byte _padding_0x61c[48];
    CHmsPicker * field_0x64c; // accesses: 1
    undefined4 field_0x650; // accesses: 2
    undefined4 field_0x654; // accesses: 2
    undefined4 field_0x658; // accesses: 2
    CMwNod * field_0x65c; // accesses: 3

    // Member Functions
    void __thiscall CScenePickerManager(CScenePickerManager *this,CScenePickerManager *param_1);
    void __thiscall EndFocus (CScenePickerManager *this,CScenePickerManager *param_1,CScenePickedItem *param_2);
    void __thiscall FillSceneInfoMouse (CScenePickerManager *this,CScenePickerManager *param_1,CSceneInfoMouse *param_2);
    void __thiscall Reset(CScenePickerManager *this,GmFrustumIso4 *param_1);
};

#endif // CSCENEPICKERMANAGER_HPP
