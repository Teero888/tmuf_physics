#ifndef CCONTROLBASE_HPP
#define CCONTROLBASE_HPP

#include "typedefs.h"

struct CControlEffectMaster;
struct CMwCmdFastCall;
struct CMwNod;
struct CMwParam;

struct CControlBase {
    struct CStyleSheetElem<class_CControlStyle> {
        byte _padding_0x0[16];
        code * field_0x10; // accesses: 1
        byte _padding_0x14[364];
        int field_0x180; // accesses: 1

        // Member Functions
        CMwNod * __thiscall Get (void *this,CSystemData *param_1,CSystemFid *param_2,CSystemFid *param_3,ulong *param_4);
        void __thiscall Set (void *this,CMwCmdScriptVarBool *param_1,int param_2);
    };

    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 8
    CMwParam * field_0x8; // accesses: 1
    float field_0xc; // accesses: 2
    undefined4 field_0x10; // accesses: 4
    int * field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    byte _padding_0x20[4];
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    byte _padding_0x2c[64];
    undefined4 field_0x6c; // accesses: 2
    CMwCmdFastCall * field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1
    undefined4 field_0x78; // accesses: 1
    undefined4 field_0x7c; // accesses: 1
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
    undefined4 field_0x88; // accesses: 1
    undefined4 field_0x8c; // accesses: 1
    undefined4 field_0x90; // accesses: 1
    undefined4 field_0x94; // accesses: 2
    undefined4 field_0x98; // accesses: 2
    undefined4 field_0x9c; // accesses: 2
    undefined4 field_0xa0; // accesses: 3
    undefined4 field_0xa4; // accesses: 2
    undefined4 field_0xa8; // accesses: 2
    undefined4 field_0xac; // accesses: 2
    undefined4 field_0xb0; // accesses: 2
    undefined4 field_0xb4; // accesses: 4
    undefined4 field_0xb8; // accesses: 2
    undefined4 field_0xbc; // accesses: 2
    undefined4 field_0xc0; // accesses: 2
    undefined4 field_0xc4; // accesses: 2
    undefined4 field_0xc8; // accesses: 2
    undefined4 field_0xcc; // accesses: 2
    undefined4 field_0xd0; // accesses: 5
    byte _padding_0xd4[8];
    int field_0xdc; // accesses: 1
    byte _padding_0xe0[4];
    int field_0xe4; // accesses: 1
    byte _padding_0xe8[8];
    undefined4 field_0xf0; // accesses: 3
    undefined * field_0xf4; // accesses: 1
    CMwCmdFastCall * field_0xf8; // accesses: 1
    undefined4 field_0xfc; // accesses: 14
    undefined4 field_0x100; // accesses: 1
    undefined * field_0x104; // accesses: 1
    undefined4 field_0x108; // accesses: 1
    undefined4 field_0x10c; // accesses: 1
    undefined4 field_0x110; // accesses: 1
    byte _padding_0x114[4];
    undefined4 field_0x118; // accesses: 1
    undefined4 field_0x11c; // accesses: 9
    byte _padding_0x120[92];
    int field_0x17c; // accesses: 3

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
