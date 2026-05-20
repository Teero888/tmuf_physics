#ifndef CTRACKMANIAEDITORINTERFACE_HPP
#define CTRACKMANIAEDITORINTERFACE_HPP

#include "typedefs.h"

struct CControlContainer;
struct CScene2d;
struct CTrackManiaEditor;
struct ulong;

struct CTrackManiaEditorInterface {
    void** vftable; // accesses: 1
    byte _padding_0x4[36];
    CScene2d * field_0x28; // accesses: 2
    byte _padding_0x2c[8];
    int field_0x34; // accesses: 4
    undefined4 field_0x38; // accesses: 10
    byte _padding_0x3c[12];
    undefined4 field_0x48; // accesses: 2
    byte _padding_0x4c[12];
    int field_0x58; // accesses: 1
    byte _padding_0x5c[4];
    int field_0x60; // accesses: 2
    int field_0x64; // accesses: 3
    byte _padding_0x68[8];
    undefined4 field_0x70; // accesses: 11
    ulong field_0x74; // accesses: 2
    ulong field_0x78; // accesses: 1
    byte _padding_0x7c[8];
    int field_0x84; // accesses: 3

    // Member Functions
    CGameCtnArticle * __thiscall GetCurrentArticle (CTrackManiaEditorInterface *this,CTrackManiaEditorInterface *param_1);
    CTrackManiaEditorIcon * __thiscall GetCurrentIcon (CTrackManiaEditorInterface *this,CTrackManiaEditorInterface *param_1);
    int __thiscall BackStep (CTrackManiaEditorInterface *this,CTrackManiaEditorInterface *param_1);
    int __thiscall SelectIcon (CTrackManiaEditorInterface *this,CTrackManiaEditorInterface *param_1,ulong param_2);
    void __thiscall SetContextualHelpMessage (CTrackManiaEditorInterface *this,CTrackManiaEditorInterface *param_1, CFastStringInt *param_2);
    void __thiscall Show(CTrackManiaEditorInterface *this,CSceneToyMotorbike *param_1);
    void __thiscall UpdateAllocatedValue (CTrackManiaEditorInterface *this,CTrackManiaEditorInterface *param_1);
    void __thiscall UpdateAmount (CTrackManiaEditorInterface *this,CTrackManiaEditorInterface *param_1, CGameCtnArticle *param_2);
    void __thiscall UpdateCurrentLevel (CTrackManiaEditorInterface *this,CTrackManiaEditorInterface *param_1);
    void __thiscall UpdateIconsStyle (CTrackManiaEditorInterface *this,CTrackManiaEditorInterface *param_1);
    void __thiscall UpdateSubButtonsSize (CTrackManiaEditorInterface *this,CTrackManiaEditorInterface *param_1);
    void __thiscall UpdateToolTips (CTrackManiaEditorInterface *this,CGameCtnMediaTracker *param_1,int param_2);
};

#endif // CTRACKMANIAEDITORINTERFACE_HPP
