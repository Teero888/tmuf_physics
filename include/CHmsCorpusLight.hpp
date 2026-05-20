#ifndef CHMSCORPUSLIGHT_HPP
#define CHMSCORPUSLIGHT_HPP

#include "typedefs.h"

struct CMotionLight;

struct CHmsCorpusLight {
    void** vftable; // accesses: 2
    byte _padding_0x4[16];
    undefined4 field_0x14; // accesses: 1
    byte _padding_0x18[36];
    undefined4 field_0x3c; // accesses: 3
    undefined4 field_0x40; // accesses: 3
    undefined4 field_0x44; // accesses: 3
    CMotionLight * field_0x48; // accesses: 6
    int * field_0x4c; // accesses: 8
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall ComputeBBoxInWorld (CHmsCorpusLight *this,CHmsCorpusLight *param_1,GmBoxAligned *param_2,ERadius param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CHmsCorpusLight(CHmsCorpusLight *this,CHmsCorpusLight *param_1);
    GmVec3 __thiscall GetPosition(CHmsCorpusLight *this,CGameControlCameraTarget *param_1);
    void __thiscall ComputeReflectGroundLocation (CHmsCorpusLight *this,CHmsCorpusLight *param_1,GmIso4 *param_2);
    void __thiscall LightReflectGroundClean(CHmsCorpusLight *this,CHmsCorpusLight *param_1);
    void __thiscall SetLight(CHmsCorpusLight *this,CMotionLight *param_1,GxLight *param_2);
    void __thiscall SetLocation(CHmsCorpusLight *this,CPlugTree *param_1,GmIso4 *param_2);
};

#endif // CHMSCORPUSLIGHT_HPP
