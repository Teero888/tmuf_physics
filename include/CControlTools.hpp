#ifndef CCONTROLTOOLS_HPP
#define CCONTROLTOOLS_HPP

#include "typedefs.h"

struct CControlBase;

struct CControlTools {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 2
    byte _padding_0x8[244];
    uint field_0xfc; // accesses: 2
    byte _padding_0x100[120];
    int field_0x178; // accesses: 1
    byte _padding_0x17c[44];
    CControlBase * field_0x1a8; // accesses: 1
    byte _padding_0x1ac[32];
    int field_0x1cc; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl CreateRankText(ulong param_1,CFastStringInt *param_2,int param_3);
    void __cdecl ControlBind(CControlBase *param_1,CMwNod *param_2,char *param_3);
    void __cdecl ControlBindEvent (CControlBase *param_1,EEvent param_2,CMwNod *param_3,_func___cdecl_void_ulong *param_4, ulong param_5);
    void __cdecl ControlDraw(CControlBase *param_1);
    void __cdecl ControlGiveFocus(CControlBase *param_1);
    void __cdecl ControlRetrieve<class_CControlBase> (CControlContainer *param_1,char *param_2,CControlBase **param_3,int param_4,int param_5, int param_6);
    void __cdecl ControlRetrieve<class_CControlGrid> (CControlContainer *param_1,char *param_2,CControlGrid **param_3,int param_4,int param_5, int param_6);
    void __cdecl ControlRetrieve<class_CControlLabel> (CControlContainer *param_1,char *param_2,CControlLabel **param_3,int param_4,int param_5, int param_6);
    void __cdecl ControlRetrieve<class_CControlQuad> (CControlContainer *param_1,char *param_2,CControlQuad **param_3,int param_4,int param_5, int param_6);
    void __cdecl ControlRetrieveAndSetLabel (CControlContainer *param_1,char *param_2,CFastStringInt *param_3,int param_4,int param_5);
    void __cdecl ControlRetrieveAndSetVisible (CControlContainer *param_1,char *param_2,int param_3,int param_4,int param_5);
    void __cdecl ControlSetLabel(CControlBase *param_1,CFastStringInt *param_2);
    void __cdecl ControlSetReadOnlyAndDraw(CControlBase *param_1,int param_2,int param_3);
    void __cdecl ControlSetVisible(CControlBase *param_1,int param_2);
    void __cdecl FixLocalUrl(CFastString *param_1,CFastStringInt *param_2);
    void __thiscall Connect(void *this,CCrystalEdge *param_1);
};

#endif // CCONTROLTOOLS_HPP
