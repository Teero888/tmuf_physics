#ifndef CCONTROLBASE_HPP
#define CCONTROLBASE_HPP

#include "typedefs.h"

struct CMwCmdFastCall;
struct CMwNod;

struct CControlBase {
    struct CMwNod;

    struct CStyleSheetElem<class_CControlStyle> {
        void** vftable; // accesses: 11
        int field_0x4; // accesses: 2

        // Member Functions
        CMwNod * __thiscall Get (void *this,CSystemData *param_1,CSystemFid *param_2,CSystemFid *param_3,ulong *param_4);
        void __thiscall Set (void *this,CMwCmdScriptVarBool *param_1,int param_2);
    };

    void** vftable; // accesses: 14
    byte _final_padding[0x1a]; // Total size: 0x1e

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ SMwParamInfo * __thiscall GetParamInfo(CControlBase *this,CControlBase *param_1,CMwStack *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl GetOffsetFromAlign (GmVec2 *param_1,GmVec2 param_2,EAlignHorizontal param_3,EAlignVertical param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CControlBase(CControlBase *this,CControlBase *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Clean(CControlBase *this,CHmsOcclusion *param_1);
    CControlBase * __cdecl CreateFromStack(CMwNod *param_1,char *param_2,CControlStyle *param_3,int param_4);
    CControlBase * __cdecl GetControl(CControlContainer *param_1,char *param_2);
    CControlStyle * __thiscall GetStyle(CControlBase *this,CControlBase *param_1);
    CMwCmd * __thiscall BindEvent (CControlBase *this,CControlBase *param_1,EEvent param_2,CMwNod *param_3, _func___cdecl_void_ulong *param_4,ulong param_5);
    CMwNod * __thiscall GetStyleSheetElem (CControlBase *this,CControlStyleSheet *param_1,CMwId *param_2,CControlBase *param_3);
    CPlugTree * __thiscall GetControlDrawTree(CControlBase *this,CControlBase *param_1,int param_2);
    GmVec2 __thiscall GetControlSize(CControlBase *this,CControlBase *param_1);
    int __cdecl GiveFocus(CControlBase *param_1,int param_2);
    int __thiscall CreateStack(CControlBase *this,CControlBase *param_1,CMwNod *param_2,char *param_3);
    void __cdecl RecursiveSetVisualFocusForcedAndDraw(CControlBase *param_1,int param_2);
    void __cdecl SetReadOnly(CControlContainer *param_1,char *param_2,int param_3);
    void __thiscall CleanTree(CControlBase *this,CPlugCrystal *param_1,CPlugTree *param_2);
    void __thiscall RefreshSizeAndAlignment(CControlBase *this,CControlBase *param_1);
    void __thiscall RefreshSizeAndAlignmentNoDraw(CControlBase *this,CControlBase *param_1);
    void __thiscall SetControlSizeFromBox(CControlBase *this,CControlBase *param_1,GmBoxAligned *param_2);
    void __thiscall SetSolid(CControlBase *this,CSceneToyMotorbike *param_1,CPlugSolid *param_2);
};

#endif // CCONTROLBASE_HPP
