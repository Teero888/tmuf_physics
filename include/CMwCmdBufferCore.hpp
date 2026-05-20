#ifndef CMWCMDBUFFERCORE_HPP
#define CMWCMDBUFFERCORE_HPP

#include "typedefs.h"

struct CDx9DynamicVB;
struct CMwCmdBuffer;
struct CMwTimer;
struct CMwTimerAdapter;
struct CPlugAudio;

struct CMwCmdBufferCore {
    void** vftable; // accesses: 2
    byte _padding_0x4[16];
    CPlugAudio * field_0x14; // accesses: 2
    CMwTimer * field_0x18; // accesses: 4
    byte _padding_0x1c[16];
    CMwCmdBuffer * field_0x2c; // accesses: 10
    int field_0x30; // accesses: 7
    undefined4 field_0x34; // accesses: 5
    int field_0x38; // accesses: 5
    int field_0x3c; // accesses: 6
    undefined4 field_0x40; // accesses: 6
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    byte _padding_0x54[4];
    uint field_0x58; // accesses: 5
    undefined4 field_0x5c; // accesses: 4
    int field_0x60; // accesses: 6
    CMwCmdBufferCore * field_0x64; // accesses: 5
    undefined4 field_0x68; // accesses: 4
    byte _padding_0x6c[8];
    undefined4 field_0x74; // accesses: 1
    byte _padding_0x78[60];
    undefined4 field_0xb4; // accesses: 1
    undefined4 field_0xb8; // accesses: 1
    CMwTimerAdapter * field_0xbc; // accesses: 5
    int field_0xc0; // accesses: 5
    CMwCmdBufferCore * field_0xc4; // accesses: 3
    byte _padding_0xc8[56];
    CMwCmdBuffer * field_0x100; // accesses: 19
    byte _final_padding[0x4]; // Total size: 0x108

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl ForceFpuCwForSimulationX86(char *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CMwCmdBufferCore(CMwCmdBufferCore *this,CMwCmdBufferCore *param_1);
    CMwClassInfo * __thiscall MwGetClassInfo(CMwCmdBufferCore *this,CFuncSegment *param_1);
    CMwCmdFastCall * __thiscall AddNotifySetTime (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,CMwNod *param_2, _func___cdecl_void *param_3);
    CMwNod * __cdecl MwNewCMwCmdBufferCore(void);
    SMwSchemeTimedProperties * __thiscall GetSchemeProperies(CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,ulong param_2);
    int __thiscall MwIsKindOf(CMwCmdBufferCore *this,CMwCmdAffectParam *param_1,ulong param_2);
    ulong __thiscall GetMwClassId(CMwCmdBufferCore *this,CControlStyle *param_1);
    ulong __thiscall GetSchemePeriod(CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,ulong param_2);
    ulong __thiscall SnapTimeToPreviousSchemePeriod (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,EMwSchemeTimedPatterns param_2, ulong param_3);
    ulong __thiscall SnapTimeToSchemePeriod (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,EMwSchemeTimedPatterns param_2, ulong param_3);
    ulong __thiscall VirtualParam_Get (CMwCmdBufferCore *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3);
    void * __thiscall _scalar_deleting_destructor_ (CMwCmdBufferCore *this,CPfmHeap *param_1,uint param_2);
    void __cdecl CreateCoreCmdBuffer(void);
    void __cdecl DestroyCoreCmdBuffer(void);
    void __thiscall Disable(CMwCmdBufferCore *this,CCrystalLink *param_1);
    void __thiscall Enable(CMwCmdBufferCore *this,CMwCmdBufferCore *param_1);
    void __thiscall EnableFixedTickFrequency (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,int param_2,ulong param_3);
    void __thiscall EnableFixedTickTime (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,int param_2,ulong param_3,ulong param_4);
    void __thiscall HighFrequencyAddCmd (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,CMwNod *param_2, _func___cdecl_void *param_3);
    void __thiscall HighFrequencyEnterSafeSection (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,ulong param_2);
    void __thiscall HighFrequencyLeaveSafeSection(CMwCmdBufferCore *this,CMwCmdBufferCore *param_1);
    void __thiscall HighFrequencyRun(CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,ulong param_2);
    void __thiscall HighFrequencySubCmd (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,CMwNod *param_2, _func___cdecl_void *param_3);
    void __thiscall HighFrequencyYield(CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,ulong param_2);
    void __thiscall InitCmdBuffer(CMwCmdBufferCore *this,CMwCmdBufferCore *param_1);
    void __thiscall Run(CMwCmdBufferCore *this,CMwCmdExpStringConcat *param_1);
    void __thiscall SetIsSimulationOnly(CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,int param_2);
    void __thiscall SetSchemePatternsProperties (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,SMwSchemeTimedProperties *param_2);
    void __thiscall SetSimulationCurrentTime (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,ulong param_2);
    void __thiscall SetSimulationRelativeSpeed (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,float param_2);
    void __thiscall StartSimulation (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,int param_2,int param_3,float param_4);
    void __thiscall StopSimulation(CMwCmdBufferCore *this,CMwCmdBufferCore *param_1);
    void __thiscall SubNotifySetTime (CMwCmdBufferCore *this,CMwCmdBufferCore *param_1,CMwNod *param_2, _func___cdecl_void *param_3);
    void __thiscall ~CMwCmdBufferCore(CMwCmdBufferCore *this,CMwCmdBufferCore *param_1);
};

#endif // CMWCMDBUFFERCORE_HPP
