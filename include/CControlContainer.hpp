#ifndef CCONTROLCONTAINER_HPP
#define CCONTROLCONTAINER_HPP

#include "typedefs.h"

struct CControlBase;
struct CMwCmd;
struct ulong;

struct CControlContainer {
    void** vftable; // accesses: 4
    byte _padding_0x4[20];
    int field_0x18; // accesses: 1
    byte _padding_0x1c[80];
    CControlContainer * field_0x6c; // accesses: 1
    CMwCmd * field_0x70; // accesses: 1
    byte _padding_0x74[28];
    undefined4 field_0x90; // accesses: 1
    byte _padding_0x94[100];
    CMwCmd * field_0xf8; // accesses: 1
    uint field_0xfc; // accesses: 4
    byte _padding_0x100[32];
    undefined4 field_0x120; // accesses: 2
    undefined4 field_0x124; // accesses: 1
    ulong field_0x128; // accesses: 2
    undefined4 field_0x12c; // accesses: 1
    undefined4 field_0x130; // accesses: 1
    undefined4 field_0x134; // accesses: 1
    undefined4 field_0x138; // accesses: 1
    undefined * field_0x13c; // accesses: 1
    undefined4 field_0x140; // accesses: 1
    byte _padding_0x144[8];
    undefined4 field_0x14c; // accesses: 3
    undefined4 field_0x150; // accesses: 1
    undefined4 field_0x154; // accesses: 1

    // Member Functions
    CControlBase * __thiscall CreateControl (CControlContainer *this,CControlContainer *param_1,char *param_2,char *param_3, char *param_4,CMwNod *param_5,char *param_6,CControlStyle *param_7);
    CControlBase * __thiscall GetFocusedChild(CControlContainer *this,CControlContainer *param_1);
    CPlugTree * __thiscall GetChildFromId(CControlContainer *this,CPlugTree *param_1,CMwId *param_2);
    int __thiscall GetRelativeLocation (CControlContainer *this,CControlContainer *param_1,GmIso4 *param_2,CControlBase *param_3);
    ulong __thiscall GetFocusedChildIndex(CControlContainer *this,CControlContainer *param_1);
    void __thiscall CControlContainer(CControlContainer *this,CControlContainer *param_1);
    void __thiscall DisconnectFromModel(CControlContainer *this,CPlugSolid *param_1,int param_2);
    void __thiscall RemoveAllChilds(CControlContainer *this,CControlContainer *param_1);
    void __thiscall SetLayoutDirty(CControlContainer *this,CControlContainer *param_1);
};

#endif // CCONTROLCONTAINER_HPP
