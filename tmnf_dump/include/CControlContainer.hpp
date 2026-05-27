#ifndef CCONTROLCONTAINER_HPP
#define CCONTROLCONTAINER_HPP

#include "typedefs.h"

struct CControlBase;
struct CMwCmd;

struct CControlContainer {
    void** vftable; // accesses: 4
    byte _final_padding[0x5]; // Total size: 0x9

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
