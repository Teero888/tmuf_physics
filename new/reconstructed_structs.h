// Automatically reconstructed structs from field accesses

#include "typedefs.h"

struct CAudioEngine {
    byte _padding_0x0[44];
    undefined4 field_0x2c; // accesses: 1
};

struct CAudioMusic {
    byte _padding_0x0[116];
    CMwRefBuffer * field_0x74; // accesses: 1
};

struct CAudioPort {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    float field_0x8; // accesses: 2
    int field_0xc; // accesses: 2
    int field_0x10; // accesses: 1
    int field_0x14; // accesses: 1
    byte _padding_0x18[4];
    float field_0x1c; // accesses: 5
    ulong field_0x20; // accesses: 1
    byte _padding_0x24[24];
    int field_0x3c; // accesses: 1
    byte _padding_0x40[8];
    undefined4 field_0x48; // accesses: 1
    byte _padding_0x4c[4];
    int field_0x50; // accesses: 2
    byte _padding_0x54[8];
    undefined4 field_0x5c; // accesses: 1
    byte _padding_0x60[8];
    EBalanceGroup field_0x68; // accesses: 1
    byte _padding_0x6c[4];
    undefined4 field_0x70; // accesses: 2
    CMwRefBuffer * field_0x74; // accesses: 1
};

struct CAudioSound {
    byte _padding_0x0[20];
    int field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    CAudioPort * field_0x44; // accesses: 4
    uint field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    ulong field_0x50; // accesses: 6
    EPlugVideoTimer field_0x54; // accesses: 3
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
    undefined4 field_0x70; // accesses: 1
    int * field_0x74; // accesses: 5
};

struct CAudioSoundEngine {
    byte _padding_0x0[120];
    undefined4 field_0x78; // accesses: 1
    undefined4 field_0x7c; // accesses: 1
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
    undefined4 field_0x88; // accesses: 1
    byte _padding_0x8c[224];
    undefined4 field_0x16c; // accesses: 1
    CPlugSoundEngine * field_0x170; // accesses: 1
};

struct CAudioSoundMulti {
    byte _padding_0x0[120];
    undefined4 field_0x78; // accesses: 1
};

struct CAudioSoundSurface {
    byte _padding_0x0[120];
    undefined4 field_0x78; // accesses: 1
    undefined4 field_0x7c; // accesses: 1
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
};

struct CBoatParam {
    byte _padding_0x0[24];
    int field_0x18; // accesses: 1
    byte _padding_0x1c[28];
    CFuncCurvesReal * field_0x38; // accesses: 1
    CFuncCurvesReal * field_0x3c; // accesses: 2
    byte _padding_0x40[56];
    float field_0x78; // accesses: 3
    byte _padding_0x7c[4];
    float field_0x80; // accesses: 3
    byte _padding_0x84[4];
    CFuncKeysReal * field_0x88; // accesses: 2
    CFuncKeysReal * field_0x8c; // accesses: 1
    byte _padding_0x90[44];
    int field_0xbc; // accesses: 1
    CFuncKeysReal * field_0xc0; // accesses: 2
    byte _padding_0xc4[12];
    float field_0xd0; // accesses: 1
};

struct CBoatSail {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 2
    byte _padding_0x8[12];
    int field_0x14; // accesses: 5
    int field_0x18; // accesses: 1
    int field_0x1c; // accesses: 3
    byte _padding_0x20[24];
    CFuncCurvesReal * field_0x38; // accesses: 1
    CFuncCurvesReal * field_0x3c; // accesses: 1
    CFuncCurvesReal * field_0x40; // accesses: 1
    CFuncCurvesReal * field_0x44; // accesses: 1
    CFuncKeysReal * field_0x48; // accesses: 2
    CFuncCurvesReal * field_0x4c; // accesses: 2
    byte _padding_0x50[4];
    CFuncCurves2Real * field_0x54; // accesses: 2
    CFuncKeysReal * field_0x58; // accesses: 2
    float field_0x5c; // accesses: 1
    float field_0x60; // accesses: 2
    byte _padding_0x64[32];
    float field_0x84; // accesses: 2
    byte _padding_0x88[28];
    float field_0xa4; // accesses: 1
    byte _padding_0xa8[4];
    float field_0xac; // accesses: 2
    byte _padding_0xb0[12];
    int field_0xbc; // accesses: 1
};

struct CBoatSailState {
    byte _padding_0x0[8];
    float field_0x8; // accesses: 1
    float field_0xc; // accesses: 2
    float field_0x10; // accesses: 2
    CBoatParam * field_0x14; // accesses: 48
    int * field_0x18; // accesses: 13
    CPlugTree * field_0x1c; // accesses: 4
    CPlugTree * field_0x20; // accesses: 4
    int * field_0x24; // accesses: 22
    int * field_0x28; // accesses: 13
    int * field_0x2c; // accesses: 2
    int field_0x30; // accesses: 1
    int field_0x34; // accesses: 1
    float field_0x38; // accesses: 1
    byte _padding_0x3c[4];
    float field_0x40; // accesses: 1
    float field_0x44; // accesses: 4
    float field_0x48; // accesses: 1
    byte _padding_0x4c[24];
    float field_0x64; // accesses: 1
    float field_0x68; // accesses: 1
    float field_0x6c; // accesses: 3
    float field_0x70; // accesses: 3
    float field_0x74; // accesses: 2
    int field_0x78; // accesses: 1
    int field_0x7c; // accesses: 2
    float field_0x80; // accesses: 8
    float field_0x84; // accesses: 10
    float field_0x88; // accesses: 3
    int field_0x8c; // accesses: 3
    float field_0x90; // accesses: 4
    byte _padding_0x94[4];
    float field_0x98; // accesses: 5
    float field_0x9c; // accesses: 10
    float field_0xa0; // accesses: 2
    float field_0xa4; // accesses: 8
    float field_0xa8; // accesses: 8
    float field_0xac; // accesses: 11
};

struct CCallbackComputeForces {
    byte _padding_0x0[64];
    CSceneVehicleGlider * field_0x40; // accesses: 1
};

struct CCallbackComputeForcesSpeedBoat {
    byte _padding_0x0[64];
    CSceneVehicleSpeedBoat * field_0x40; // accesses: 1
};

struct CCallbackSceneToyBoatComputeForces {
    byte _padding_0x0[64];
    CSceneToyBoat * field_0x40; // accesses: 1
};

struct CCallbackSceneToyBroomStickComputeForces {
    byte _padding_0x0[64];
    CSceneToyBroomstick * field_0x40; // accesses: 1
};

struct CCallbackSceneToyCharacterAfterContacts {
    byte _padding_0x0[64];
    int * field_0x40; // accesses: 1
};

struct CCallbackSceneToyCharacterComputeForces {
    byte _padding_0x0[64];
    CSceneToyCharacter * field_0x40; // accesses: 1
};

struct CCallbackSceneVehicleBallAfterContacts {
    byte _padding_0x0[64];
    CSceneVehicleBall * field_0x40; // accesses: 1
};

struct CCallbackSceneVehicleCarAfterContacts {
    byte _padding_0x0[64];
    CSceneVehicleCar * field_0x40; // accesses: 1
};

struct CCallbackSceneVehicleCarComputeForces {
    byte _padding_0x0[64];
    CSceneVehicleCar * field_0x40; // accesses: 1
};

struct CClassicArchive {
    byte _padding_0x0[4];
    int * field_0x4; // accesses: 27
    int field_0x8; // accesses: 9
    int field_0xc; // accesses: 14
    byte _padding_0x10[4];
    int field_0x14; // accesses: 3
};

struct CClassicBuffer {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    CClassicBuffer * field_0xc; // accesses: 1
    SLadderResult * field_0x10; // accesses: 3
};

struct CClassicBufferMemory {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    int field_0x8; // accesses: 1
    void * field_0xc; // accesses: 8
    void * field_0x10; // accesses: 8
    CClassicBufferMemory * field_0x14; // accesses: 12
    void * field_0x18; // accesses: 7
    int field_0x1c; // accesses: 9
};

struct CClassicCrypto_BlowFish {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 25
    byte _padding_0x8[4160];
    int field_0x1048; // accesses: 1
};

struct CClassicI18n {
    byte _padding_0x0[2];
    ushort field_0x2; // accesses: 1
    ulong field_0x4; // accesses: 23
    void * field_0x8; // accesses: 7
    void * field_0xc; // accesses: 8
    byte _padding_0x10[8];
    int field_0x18; // accesses: 5
    void * field_0x1c; // accesses: 10
    ulong field_0x20; // accesses: 8
    void * field_0x24; // accesses: 3
};

struct CClassicLog {
    byte _padding_0x0[4];
    void * field_0x4; // accesses: 6
    int field_0x8; // accesses: 1
    code * field_0xc; // accesses: 1
    code * field_0x10; // accesses: 1
    int * field_0x14; // accesses: 2
    byte _padding_0x18[148];
    int field_0xac; // accesses: 1
    byte _padding_0xb0[60];
    int * field_0xec; // accesses: 4
};

struct CControlBase {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 8
    CMwParam * field_0x8; // accesses: 1
    float field_0xc; // accesses: 2
    undefined4 * field_0x10; // accesses: 4
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
    float field_0xa0; // accesses: 3
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
    ulong field_0xd0; // accesses: 5
    byte _padding_0xd4[8];
    int field_0xdc; // accesses: 1
    byte _padding_0xe0[4];
    int field_0xe4; // accesses: 1
    byte _padding_0xe8[8];
    int field_0xf0; // accesses: 3
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
    int field_0x11c; // accesses: 9
    byte _padding_0x120[92];
    int field_0x17c; // accesses: 3
};

struct CControlBase_CStyleSheetElem_class_CControlStyle {
    byte _padding_0x0[16];
    code * field_0x10; // accesses: 1
    byte _padding_0x14[364];
    int field_0x180; // accesses: 1
};

struct CControlButton {
    byte _padding_0x0[4];
    SStringParam * field_0x4; // accesses: 2
    byte _padding_0x8[296];
    undefined4 field_0x130; // accesses: 1
    undefined4 field_0x134; // accesses: 1
    undefined4 field_0x138; // accesses: 1
    undefined4 field_0x13c; // accesses: 1
    undefined4 field_0x140; // accesses: 1
    undefined4 field_0x144; // accesses: 1
    undefined4 field_0x148; // accesses: 1
    undefined4 field_0x14c; // accesses: 1
    undefined4 field_0x150; // accesses: 1
    undefined4 field_0x154; // accesses: 1
    undefined4 field_0x158; // accesses: 1
    byte _padding_0x15c[4];
    int field_0x160; // accesses: 2
    undefined * field_0x164; // accesses: 1
    undefined4 field_0x168; // accesses: 1
    undefined4 field_0x16c; // accesses: 1
    undefined4 field_0x170; // accesses: 1
};

struct CControlColorChooser {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 4
    undefined4 field_0x8; // accesses: 4
    byte _padding_0xc[16];
    CPlugBitmap * field_0x1c; // accesses: 4
    byte _padding_0x20[40];
    CPlugFileGen * field_0x48; // accesses: 4
    byte _padding_0x4c[276];
    int field_0x160; // accesses: 2
    undefined4 * field_0x164; // accesses: 1
    undefined4 * field_0x168; // accesses: 1
    byte _padding_0x16c[8];
    CPlugTree * field_0x174; // accesses: 2
    CPlugVisualQuads2D * field_0x178; // accesses: 2
    float field_0x17c; // accesses: 3
    float field_0x180; // accesses: 3
    GmVec3 * field_0x184; // accesses: 1
    float field_0x188; // accesses: 1
    undefined4 field_0x18c; // accesses: 8
    undefined4 field_0x190; // accesses: 8
    undefined4 field_0x194; // accesses: 8
    float field_0x198; // accesses: 4
    byte _padding_0x19c[4];
    int * field_0x1a0; // accesses: 4
    CPlugFileGen * field_0x1a4; // accesses: 4
    undefined4 field_0x1a8; // accesses: 4
};

struct CControlContainer {
    byte _padding_0x0[24];
    int field_0x18; // accesses: 1
    byte _padding_0x1c[80];
    int field_0x6c; // accesses: 3
    CMwCmd * field_0x70; // accesses: 1
    byte _padding_0x74[28];
    undefined4 field_0x90; // accesses: 1
    byte _padding_0x94[100];
    CMwCmd * field_0xf8; // accesses: 1
    CControlBase field_0xfc; // accesses: 4
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
    int field_0x14c; // accesses: 3
    undefined4 field_0x150; // accesses: 1
    undefined4 field_0x154; // accesses: 1
    byte _padding_0x158[164];
    code * field_0x1fc; // accesses: 1
};

struct CControlDisplayGraph {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    int field_0xc; // accesses: 1
    byte _padding_0x10[272];
    undefined4 field_0x120; // accesses: 1
    uint field_0x124; // accesses: 1
    byte _padding_0x128[24];
    int field_0x140; // accesses: 1
    int field_0x144; // accesses: 3
    float field_0x148; // accesses: 4
    int field_0x14c; // accesses: 3
    byte _padding_0x150[4];
    int field_0x154; // accesses: 6
};

struct CControlEffectMaster {
    byte _padding_0x0[4];
    CControlEffectMaster * field_0x4; // accesses: 4
    byte _padding_0x8[24];
    CControlEffect * field_0x20; // accesses: 1
    CControlEffect * field_0x24; // accesses: 1
    ulong field_0x28; // accesses: 8
    undefined4 field_0x2c; // accesses: 3
    int * field_0x30; // accesses: 4
    CControlEffect * field_0x34; // accesses: 1
    CControlEffect * field_0x38; // accesses: 1
    CControlEffect * field_0x3c; // accesses: 1
    CControlEffect * field_0x40; // accesses: 1
    CControlEffect * field_0x44; // accesses: 1
    CMwRefBuffer * field_0x48; // accesses: 5
    byte _padding_0x4c[4];
    int field_0x50; // accesses: 1
    byte _padding_0x54[72];
    uint field_0x9c; // accesses: 2
    byte _padding_0xa0[124];
    int * field_0x11c; // accesses: 7
};

struct CControlEntry {
    byte _padding_0x0[252];
    uint field_0xfc; // accesses: 2
    byte _padding_0x100[48];
    undefined4 field_0x130; // accesses: 1
    byte _padding_0x134[4];
    undefined4 field_0x138; // accesses: 1
    byte _padding_0x13c[4];
    undefined4 field_0x140; // accesses: 1
    undefined4 field_0x144; // accesses: 1
    undefined4 field_0x148; // accesses: 1
    undefined * field_0x14c; // accesses: 1
    byte _padding_0x150[4];
    undefined4 field_0x154; // accesses: 1
    byte _padding_0x158[4];
    CControlKeyboardInterface * field_0x15c; // accesses: 4
};

struct CControlFrame {
    byte _padding_0x0[144];
    undefined4 field_0x90; // accesses: 1
    byte _padding_0x94[116];
    undefined4 field_0x108; // accesses: 1
    undefined4 field_0x10c; // accesses: 1
};

struct CControlGrid {
    byte _padding_0x0[4];
    ulong field_0x4; // accesses: 1
    byte _padding_0x8[376];
    undefined4 field_0x180; // accesses: 1
    undefined4 field_0x184; // accesses: 1
    undefined4 field_0x188; // accesses: 1
    undefined4 field_0x18c; // accesses: 1
    undefined4 field_0x190; // accesses: 1
    undefined4 field_0x194; // accesses: 1
    undefined4 field_0x198; // accesses: 1
    undefined4 field_0x19c; // accesses: 1
};

struct CControlKeyboardInterface {
    byte _padding_0x0[4];
    undefined2 * field_0x4; // accesses: 1
    byte _padding_0x6[10];
    undefined4 field_0x10; // accesses: 1
};

struct CControlLabel {
    byte _padding_0x0[4];
    SStringParam * field_0x4; // accesses: 2
    byte _padding_0x8[244];
    uint field_0xfc; // accesses: 2
    byte _padding_0x100[48];
    int field_0x130; // accesses: 2
    undefined * field_0x134; // accesses: 1
    undefined4 field_0x138; // accesses: 1
    undefined4 field_0x13c; // accesses: 1
    undefined4 field_0x140; // accesses: 1
    undefined4 field_0x144; // accesses: 1
    undefined4 field_0x148; // accesses: 1
};

struct CControlLayout {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
};

struct CControlMediaPlayer {
    byte _padding_0x0[24];
    CMwNod * field_0x18; // accesses: 4
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 2
    undefined4 field_0x24; // accesses: 2
    undefined4 field_0x28; // accesses: 2
    byte _padding_0x2c[16];
    undefined4 field_0x3c; // accesses: 1
    byte _padding_0x40[4];
    CMwCmdAffectParamBool * field_0x44; // accesses: 1
    byte _padding_0x48[40];
    CControlMediaPlayer * field_0x70; // accesses: 4
    byte _padding_0x74[32];
    undefined4 field_0x94; // accesses: 2
    undefined4 field_0x98; // accesses: 2
    undefined4 field_0x9c; // accesses: 2
    float field_0xa0; // accesses: 2
    float field_0xa4; // accesses: 2
    undefined4 field_0xa8; // accesses: 2
    byte _padding_0xac[96];
    undefined4 field_0x10c; // accesses: 1
    byte _padding_0x110[8];
    int field_0x118; // accesses: 2
    byte _padding_0x11c[68];
    undefined4 field_0x160; // accesses: 1
    undefined4 field_0x164; // accesses: 1
    undefined4 field_0x168; // accesses: 1
    undefined4 field_0x16c; // accesses: 1
    undefined4 field_0x170; // accesses: 1
    int field_0x174; // accesses: 3
    float field_0x178; // accesses: 1
    float field_0x17c; // accesses: 1
    undefined4 field_0x180; // accesses: 2
    undefined4 field_0x184; // accesses: 2
    int field_0x188; // accesses: 7
    int * field_0x18c; // accesses: 12
    undefined4 field_0x190; // accesses: 5
    CAudioSound * field_0x194; // accesses: 8
    int field_0x198; // accesses: 2
    undefined4 field_0x19c; // accesses: 5
    int field_0x1a0; // accesses: 5
    int * field_0x1a4; // accesses: 36
    int * field_0x1a8; // accesses: 27
};

struct CControlQuad {
    byte _padding_0x0[60];
    float field_0x3c; // accesses: 1
    byte _padding_0x40[12];
    int field_0x4c; // accesses: 2
    byte _padding_0x50[172];
    uint field_0xfc; // accesses: 2
    byte _padding_0x100[32];
    undefined4 field_0x120; // accesses: 1
    undefined4 field_0x124; // accesses: 1
    undefined4 field_0x128; // accesses: 1
    undefined4 field_0x12c; // accesses: 1
    undefined4 field_0x130; // accesses: 1
    undefined4 field_0x134; // accesses: 1
    undefined4 field_0x138; // accesses: 1
    undefined4 field_0x13c; // accesses: 1
    int field_0x140; // accesses: 1
};

struct CControlSimi2 {
    byte _padding_0x0[12];
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    undefined4 * field_0x14; // accesses: 9
    int field_0x18; // accesses: 1
    float field_0x1c; // accesses: 1
    float field_0x20; // accesses: 1
    int field_0x24; // accesses: 2
    undefined4 field_0x28; // accesses: 1
    float field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
};

struct CControlStyle {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 4
    float field_0x8; // accesses: 4
    undefined4 field_0xc; // accesses: 2
    undefined4 field_0x10; // accesses: 2
    int field_0x14; // accesses: 9
    undefined4 field_0x18; // accesses: 8
    CControlStyle * field_0x1c; // accesses: 5
    CControlStyle * field_0x20; // accesses: 5
    undefined4 field_0x24; // accesses: 3
    undefined4 field_0x28; // accesses: 6
    undefined4 field_0x2c; // accesses: 6
    undefined4 field_0x30; // accesses: 6
    undefined4 field_0x34; // accesses: 6
    undefined4 field_0x38; // accesses: 3
    undefined4 field_0x3c; // accesses: 3
    undefined4 field_0x40; // accesses: 3
    undefined4 field_0x44; // accesses: 3
    undefined4 field_0x48; // accesses: 3
    undefined4 field_0x4c; // accesses: 6
    int field_0x50; // accesses: 13
    undefined4 field_0x54; // accesses: 5
    undefined4 field_0x58; // accesses: 5
    byte _padding_0x5c[4];
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
    byte _padding_0x70[12];
    undefined4 field_0x7c; // accesses: 1
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
    undefined4 field_0x88; // accesses: 1
    byte _padding_0x8c[12];
    undefined4 field_0x98; // accesses: 1
    undefined4 field_0x9c; // accesses: 1
    undefined4 field_0xa0; // accesses: 1
    undefined4 field_0xa4; // accesses: 1
    byte _padding_0xa8[8];
    undefined4 field_0xb0; // accesses: 3
    undefined4 field_0xb4; // accesses: 3
    undefined4 field_0xb8; // accesses: 6
    undefined4 field_0xbc; // accesses: 6
    undefined4 field_0xc0; // accesses: 6
    undefined4 field_0xc4; // accesses: 2
    undefined4 field_0xc8; // accesses: 3
    undefined4 field_0xcc; // accesses: 3
    undefined4 field_0xd0; // accesses: 6
    undefined4 field_0xd4; // accesses: 6
    undefined4 field_0xd8; // accesses: 6
    undefined4 field_0xdc; // accesses: 3
    undefined4 field_0xe0; // accesses: 3
    undefined4 field_0xe4; // accesses: 3
    undefined4 field_0xe8; // accesses: 3
    undefined4 field_0xec; // accesses: 6
    undefined4 field_0xf0; // accesses: 3
    undefined4 field_0xf4; // accesses: 3
    undefined4 field_0xf8; // accesses: 3
    undefined4 field_0xfc; // accesses: 3
    undefined4 field_0x100; // accesses: 6
    undefined4 field_0x104; // accesses: 6
    undefined4 field_0x108; // accesses: 6
    undefined4 field_0x10c; // accesses: 3
    undefined4 field_0x110; // accesses: 3
    undefined4 field_0x114; // accesses: 3
    undefined4 field_0x118; // accesses: 3
    undefined4 field_0x11c; // accesses: 3
    undefined4 field_0x120; // accesses: 3
    undefined4 field_0x124; // accesses: 3
    undefined4 field_0x128; // accesses: 3
    undefined4 field_0x12c; // accesses: 3
    undefined4 field_0x130; // accesses: 3
    undefined4 field_0x134; // accesses: 3
    undefined4 field_0x138; // accesses: 3
    undefined4 field_0x13c; // accesses: 3
    undefined4 field_0x140; // accesses: 3
    undefined4 field_0x144; // accesses: 3
    undefined4 field_0x148; // accesses: 3
    undefined4 field_0x14c; // accesses: 3
    undefined4 field_0x150; // accesses: 3
    undefined4 field_0x154; // accesses: 3
    undefined4 field_0x158; // accesses: 3
    undefined4 field_0x15c; // accesses: 3
    undefined4 field_0x160; // accesses: 3
    undefined4 field_0x164; // accesses: 3
    undefined4 field_0x168; // accesses: 3
    undefined4 field_0x16c; // accesses: 3
    undefined4 field_0x170; // accesses: 3
    undefined4 field_0x174; // accesses: 3
    undefined4 field_0x178; // accesses: 3
    undefined4 field_0x17c; // accesses: 6
    CControlStyle * field_0x180; // accesses: 6
};

struct CControlStyleSheet {
    byte _padding_0x0[40];
    CMwRefBuffer * field_0x28; // accesses: 2
    byte _padding_0x2c[340];
    CControlStyleSheet * field_0x180; // accesses: 1
};

struct CControlText {
    byte _padding_0x0[288];
    undefined4 field_0x120; // accesses: 1
    undefined4 field_0x124; // accesses: 1
    undefined4 field_0x128; // accesses: 1
    int field_0x12c; // accesses: 4
};

struct CControlTimeLine2 {
    byte _padding_0x0[312];
    CControlTimeLine2 * field_0x138; // accesses: 2
    float field_0x13c; // accesses: 2
    float field_0x140; // accesses: 1
    byte _padding_0x144[16];
    float field_0x154; // accesses: 1
    float field_0x158; // accesses: 1
    byte _padding_0x15c[292];
    CPlugTree * field_0x280; // accesses: 4
};

struct CControlTools {
    byte _padding_0x0[4];
    short * field_0x4; // accesses: 2
    byte _padding_0x6[246];
    uint field_0xfc; // accesses: 2
    byte _padding_0x100[120];
    int field_0x178; // accesses: 1
    byte _padding_0x17c[44];
    CControlBase * field_0x1a8; // accesses: 1
    byte _padding_0x1ac[32];
    int field_0x1cc; // accesses: 1
};

struct CControlUrlLinks {
    byte _padding_0x0[328];
    undefined4 field_0x148; // accesses: 1
};

struct CCrystalLink {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 3
    undefined4 field_0x8; // accesses: 1
    int field_0xc; // accesses: 2
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    byte _padding_0x1c[40];
    int field_0x44; // accesses: 1
    void * field_0x48; // accesses: 4
    int field_0x4c; // accesses: 2
};

struct CCrystalVertex {
    byte _padding_0x0[56];
    int field_0x38; // accesses: 1
};

struct CDx9DeviceCaps {
    byte _padding_0x0[1076];
    undefined4 field_0x434; // accesses: 2
    SStringParam * field_0x438; // accesses: 3
    ulong field_0x43c; // accesses: 2
    undefined4 field_0x440; // accesses: 1
    byte _padding_0x444[28];
    int field_0x460; // accesses: 3
};

struct CDx9GpuBuilder {
    byte _padding_0x0[51];
    undefined4 field_0x33; // accesses: 1
};

struct CDx9PixelShader {
    byte _padding_0x0[200];
    int field_0xc8; // accesses: 2
};

struct CDx9ShaderKeeper {
    byte _padding_0x0[4];
    CPlugShader * field_0x4; // accesses: 2
    byte _padding_0x8[4];
    CPlugShader * field_0xc; // accesses: 3
    byte _padding_0x10[4];
    int field_0x14; // accesses: 3
    byte _padding_0x18[4];
    CPlugShader * field_0x1c; // accesses: 6
    uint field_0x20; // accesses: 3
    byte _padding_0x24[4];
    float field_0x28; // accesses: 1
    byte _padding_0x2c[32];
    uint field_0x4c; // accesses: 3
    byte _padding_0x50[36];
    int field_0x74; // accesses: 1
    byte _padding_0x78[8];
    uint field_0x80; // accesses: 5
    byte _padding_0x84[1028];
    uint field_0x488; // accesses: 1
};

struct CDx9StateBlock {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 71
    undefined4 field_0x8; // accesses: 39
    byte _padding_0xc[20];
    int field_0x20; // accesses: 1
    byte _padding_0x24[88];
    short field_0x7c; // accesses: 1
    byte _padding_0x7e[70];
    code * field_0xc4; // accesses: 1
    byte _padding_0xc8[920];
    int field_0x460; // accesses: 2
};

struct CDx9TextureKeeper {
    byte _padding_0x0[2];
    ushort field_0x2; // accesses: 18
    ushort field_0x4; // accesses: 25
    ushort field_0x6; // accesses: 1
    int * field_0x8; // accesses: 8
    float field_0xc; // accesses: 3
    int field_0x10; // accesses: 1
    int field_0x14; // accesses: 3
    byte _padding_0x18[12];
    uint field_0x24; // accesses: 6
    byte _padding_0x28[32];
    CPlugFileImg * field_0x48; // accesses: 5
    uint field_0x4c; // accesses: 9
    CVisionViewportDx9 field_0x4d; // accesses: 1
    uint field_0x50; // accesses: 2
    byte _padding_0x54[32];
    int field_0x74; // accesses: 1
    byte _padding_0x78[388];
    int field_0x1fc; // accesses: 4
    undefined4 field_0x200; // accesses: 1
    undefined4 field_0x204; // accesses: 1
    byte _padding_0x208[8];
    int field_0x210; // accesses: 4
    byte _padding_0x214[44];
    int field_0x240; // accesses: 1
    byte _padding_0x244[788];
    uint field_0x558; // accesses: 1
    byte _padding_0x55c[372];
    int field_0x6d0; // accesses: 2
};

struct CDx9VertexBuffer {
    byte _padding_0x0[540];
    int field_0x21c; // accesses: 4
};

struct CDx9VertexDeclaration {
    byte _padding_0x0[2];
    short field_0x2; // accesses: 1
    int field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 1
    byte _padding_0xc[1348];
    byte field_0x550; // accesses: 1
};

struct CDx9VertexShader {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    byte _padding_0x10[204];
    code * field_0xdc; // accesses: 1
};

struct CDx9VisualKeeper {
    byte _padding_0x0[1];
    uint3 field_0x1; // accesses: 5
    undefined2 field_0x2; // accesses: 2
    undefined2 field_0x4; // accesses: 48
    undefined2 field_0x6; // accesses: 2
    int field_0x8; // accesses: 19
    undefined4 field_0xc; // accesses: 4
    float field_0x10; // accesses: 1
    float field_0x14; // accesses: 3
    float field_0x18; // accesses: 1
    byte _padding_0x1c[52];
    int field_0x50; // accesses: 4
    byte _padding_0x54[40];
    uchar ** field_0x7c; // accesses: 1
    byte _padding_0x7d[27];
    int field_0x98; // accesses: 4
    int field_0x9c; // accesses: 1
    int field_0xa0; // accesses: 1
    byte _padding_0xa4[644];
    int field_0x328; // accesses: 1
};

struct CFastAlgo {
    byte _padding_0x0[24];
    undefined4 field_0x18; // accesses: 2
    undefined4 field_0x1c; // accesses: 2
    undefined4 field_0x20; // accesses: 2
    undefined4 field_0x24; // accesses: 2
};

struct CFastArray_char {
    byte _padding_0x0[4];
    void * field_0x4; // accesses: 4
};

struct CFastArray_class_CControlBase {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 1
};

struct CFastArray_class_CFastStringInt {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
};

struct CFastArray_class_CPlugSoundEngineComponent {
    byte _padding_0x0[8];
    int field_0x8; // accesses: 1
};

struct CFastArray_class_GmVec3 {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 2
};

struct CFastArray_class_GmVec4 {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 3
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
};

struct CFastArray_class_GxColor {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
};

struct CFastArray_class_GxTexCoordSet {
    byte _padding_0x0[4];
    void * field_0x4; // accesses: 6
};

struct CFastArray_struct_CDx9StateBlock_SPackedDesc {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 3
    undefined4 field_0x8; // accesses: 1
};

struct CFastArray_struct_CPlugVisual_SSubVisual {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    int field_0x8; // accesses: 2
};

struct CFastArray_struct_CSceneMobilSnow_SSnowFlakes {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
};

struct CFastArray_struct_GmSurfMesh_STriangle {
    byte _padding_0x0[8];
    int field_0x8; // accesses: 1
};

struct CFastArray_struct_SGameCtnIdentifier {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 2
};

struct CFastArray_struct_SPlugGpuLoadFx {
    byte _padding_0x0[4];
    int * field_0x4; // accesses: 2
};

struct CFastBufferCat_class_CHmsCorpusLight_struct_SFastCat {
    byte _padding_0x0[4];
    ulong field_0x4; // accesses: 2
};

struct CFastBufferCat_class_CHmsCorpus_struct_SFastCat {
    byte _padding_0x0[4];
    ulong field_0x4; // accesses: 2
};

struct CFastBufferCat_class_CMwCmd_struct_SFastCat {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 4
};

struct CFastBufferCat_class_CNetHttpResult_struct_SFastCat {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 1
};

struct CFastBufferCat_class_CPlugTree_struct_SFastCat {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
};

struct CFastBufferCat_class_CSceneMobil_struct_SFastCat {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
};

struct CFastBufferCat_class_GmVec4_struct_CPlugShaderLoadIds_SFxCat {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 1
};

struct CFastBufferCat_struct_CDx9StateBlock_STexStageState_struct_CDx9StateBlock_STexStageCat {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 18
};

struct CFastBufferCat_struct_CHmsViewport_SVisibleCamera_struct_CHmsViewport_SVisibleZoneCat {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
};

struct CFastBufferCat_struct_CInputPort_SMappedAction_struct_SFastCat {
    byte _padding_0x0[4];
    ulong field_0x4; // accesses: 4
};

struct CFastBufferCat_struct_CPlugBitmap_SSpecularHighlight_struct_CPlugBitmap_SSpecularSubMapCat {
    byte _padding_0x0[4];
    ulong field_0x4; // accesses: 4
};

struct CFastBufferCat_unsigned_long_struct_SFastCat {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
};

struct CFastBufferKey_struct_CGameCtnMediaBlockFxBlurDepth_SKeyVal {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 2
    undefined4 field_0xc; // accesses: 1
};

struct CFastBufferKey_struct_CGameCtnMediaBlockMusicEffect_SKeyVal {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 1
};

struct CFastBufferKey_struct_CGameCtnMediaBlockSound_SKeyVal {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 2
    undefined4 field_0xc; // accesses: 2
    undefined4 field_0x10; // accesses: 2
    undefined4 field_0x14; // accesses: 1
};

struct CFastBufferPool_struct_CGameNetPlayerInfo_SNetStateBuffer {
    byte _padding_0x0[16];
    undefined4 field_0x10; // accesses: 1
    byte _padding_0x14[24];
    undefined4 field_0x2c; // accesses: 1
};

struct CFastBufferPool_struct_CGameNetPlayerInfo_SNetStateBuffer_CFastBufferPool_struct_CGameNetPlayerInfo {
    byte _padding_0x0[16];
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 1
};

struct CFastBufferWheel_class_GmVec2 {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 1
};

struct CFastBufferWheel_class_GmVec3 {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 5
    float field_0x8; // accesses: 3
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
};

struct CFastBufferWheel_float {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 1
    byte _padding_0x8[4];
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
};

struct CFastBufferWheel_struct_CGamePlaygroundInterface_SAvatarMessage {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    byte _padding_0x8[4];
    int field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 1
};

struct CFastBufferWheel_struct_SMwTimedValueInstant_struct_SInputEventsStoreElem {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 3
    byte _padding_0x8[4];
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
};

struct CFastBufferWheel_unsigned_long {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 1
    byte _padding_0x8[4];
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
};

struct CFastBuffer_class_CGameNetPlayerInfo {
    byte _padding_0x0[4];
    code * field_0x4; // accesses: 1
};

struct CFastBuffer_class_CMwNodRef_class_CGameCtnCampaign {
    byte _padding_0x0[8];
    int field_0x8; // accesses: 1
};

struct CFastBuffer_class_CMwNodRef_class_CPlugMaterial {
    byte _padding_0x0[8];
    int field_0x8; // accesses: 1
};

struct CFastBuffer_class_CSceneMobil {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 1
};

struct CFastBuffer_class_GmInt4 {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
};

struct CFastBuffer_class_GmNat2 {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 4
};

struct CFastBuffer_class_GmNat3 {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 1
    int field_0x8; // accesses: 1
};

struct CFastBuffer_class_GmQuat {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 2
    undefined4 field_0xc; // accesses: 2
};

struct CFastBuffer_class_GmVec3 {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
};

struct CFastBuffer_class_GmVec4 {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
};

struct CFastBuffer_class_GxColor {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
};

struct CFastBuffer_float {
    byte _padding_0x0[8];
    int field_0x8; // accesses: 1
};

struct CFastBuffer_struct_CAudioPort_SAutoBalancedSound {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 2
    undefined4 field_0xc; // accesses: 2
};

struct CFastBuffer_struct_CFastBufferKey_struct_CGameCtnMediaBlockMusicEffect_SKeyVal_SKey {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 1
};

struct CFastBuffer_struct_CFastBufferKey_struct_CGameCtnMediaBlockSound_SKeyVal_SKey {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 1
};

struct CFastBuffer_struct_CFastBufferPool_struct_CGameNetPlayerInfo_SNetStateBuffer_SElem {
    byte _padding_0x0[44];
    undefined4 field_0x2c; // accesses: 2
};

struct CFastBuffer_struct_CGameCtnMediaBlockTriangles_STri {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
};

struct CFastBuffer_struct_CGameCtnMenus_SMenuLeaguePathStepInfos {
    byte _padding_0x0[8];
    undefined4 field_0x8; // accesses: 1
    undefined4 * field_0xc; // accesses: 1
};

struct CFastBuffer_struct_CHmsCameraFx_SBitmapOutput {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
};

struct CFastBuffer_struct_CHmsVPackerCell_SLightBallLoc {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
};

struct CFastBuffer_struct_CInputDevice_SRumble {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 2
};

struct CFastBuffer_struct_CInputEventsStore_SCachedValue {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
};

struct CFastBuffer_struct_CNetClient_SQueuedNetConnectionLessNod {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
};

struct CFastBuffer_struct_CNetConnection_SEmmissionElem {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
};

struct CFastBuffer_struct_CPlugFont_SCharStyle_SStyle {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
};

struct CFastBuffer_struct_CPlugModelMesh_SLineColor {
    byte _padding_0x0[8];
    int field_0x8; // accesses: 1
};

struct CFastBuffer_struct_CPlugVisual_SSkinIndex {
    byte _padding_0x0[8];
    int field_0x8; // accesses: 1
};

struct CFastBuffer_struct_CSceneToyBoat_SSailManoeuvre {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
};

struct CFastBuffer_struct_CSceneVehicleStruct_SSimulationWheel {
    byte _padding_0x0[8];
    int field_0x8; // accesses: 1
};

struct CFastBuffer_struct_CSceneVehicleStruct_SVisualWheel {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 2
    int field_0x8; // accesses: 3
};

struct CFastBuffer_struct_CSystemArchiveNod_SExternalRef {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
};

struct CFastBuffer_struct_CTrackManiaNetwork_SPlayListElem {
    byte _padding_0x0[8];
    undefined4 field_0x8; // accesses: 1
};

struct CFastBuffer_struct_CVisionHmsZone_SCasterCat {
    byte _padding_0x0[49];
    uint field_0x31; // accesses: 2
    byte _padding_0x35[1664921863];
    undefined1 * field_0x633cb13c; // accesses: 1
    byte _padding_0x633cb13d[1207298293];
    byte field_0xab329a32; // accesses: 1
    byte _padding_0xab329a33[889206015];
    byte field_0xe032cf32; // accesses: 1
};

struct CFastBuffer_struct_SCtnForcedMods_SEnvMod {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 2
    int field_0x8; // accesses: 1
};

struct CFastBuffer_struct_SMeshOctreeCell {
    byte _padding_0x0[8];
    int field_0x8; // accesses: 2
};

struct CFastBuffer_struct_SPlugTreeOptimTransf {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
};

struct CFastBuffer_struct_SQuadTreeMeshUv {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 1
};

struct CFastMapTable_struct_CGameAdvertisingElement_CImpressionCollector_SImpressionRecord {
    byte _padding_0x0[4];
    void * field_0x4; // accesses: 5
    undefined4 field_0x8; // accesses: 1
    ulong field_0xc; // accesses: 4
};

struct CFastMapTable_struct_CGameAdvertising_SInstanceId_SScanner {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 1
    byte _padding_0x8[4];
    uint field_0xc; // accesses: 2
};

struct CFastMapTable_struct_CPlugTreeMapShaderFill_SFillValue {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 3
    int field_0x8; // accesses: 4
    uint field_0xc; // accesses: 3
};

struct CFastMapTable_unsigned_char {
    byte _padding_0x0[4];
    void * field_0x4; // accesses: 3
    undefined4 field_0x8; // accesses: 1
    ulong field_0xc; // accesses: 4
};

struct CFastMapTable_unsigned_long {
    byte _padding_0x0[4];
    void * field_0x4; // accesses: 11
    int field_0x8; // accesses: 9
    ulong field_0xc; // accesses: 9
};

struct CFastMapTable_unsigned_long_SScanner {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 2
    byte _padding_0x8[4];
    uint field_0xc; // accesses: 2
};

struct CFastMap_class_CMwId_float {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
};

struct CFastString {
    byte _padding_0x0[4];
    SStringParam * field_0x4; // accesses: 59
    int field_0x8; // accesses: 4
    undefined1 * field_0xc; // accesses: 2
    byte _padding_0xd[3];
    int field_0x10; // accesses: 5
    int field_0x14; // accesses: 6
    char * field_0x18; // accesses: 3
};

struct CFastStringBase_char {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 10
};

struct CFastStringBase_wchar_t {
    byte _padding_0x0[4];
    undefined2 * field_0x4; // accesses: 4
};

struct CFastStringInt {
    byte _padding_0x0[4];
    char * field_0x4; // accesses: 19
    byte _padding_0x5[3];
    undefined2 * field_0x8; // accesses: 2
    byte _padding_0xa[2];
    int field_0xc; // accesses: 3
    int field_0x10; // accesses: 5
    int field_0x14; // accesses: 5
    byte _padding_0x18[4];
    wchar_t * field_0x1c; // accesses: 3
};

struct CFuncColorGradient {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 3
    float field_0x8; // accesses: 3
    byte _padding_0xc[8];
    float field_0x14; // accesses: 2
    float field_0x18; // accesses: 2
    float field_0x1c; // accesses: 2
    float field_0x20; // accesses: 3
    float field_0x24; // accesses: 3
    float field_0x28; // accesses: 3
    float field_0x2c; // accesses: 3
    float field_0x30; // accesses: 3
    float field_0x34; // accesses: 3
    float field_0x38; // accesses: 1
    float field_0x3c; // accesses: 1
    float field_0x40; // accesses: 1
    float field_0x44; // accesses: 4
    float field_0x48; // accesses: 4
};

struct CFuncCurves2Real {
    byte _padding_0x0[4];
    CFuncCurvesReal * field_0x4; // accesses: 2
    byte _padding_0x8[16];
    int field_0x18; // accesses: 1
};

struct CFuncCurvesReal {
    byte _padding_0x0[4];
    CFuncKeysReal * field_0x4; // accesses: 2
    byte _padding_0x8[16];
    int field_0x18; // accesses: 1
};

struct CFuncEnum {
    byte _padding_0x0[32];
    int field_0x20; // accesses: 3
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    byte _padding_0x44[8];
    undefined4 field_0x4c; // accesses: 1
};

struct CFuncEnvelope {
    byte _padding_0x0[48];
    float field_0x30; // accesses: 1
    int field_0x34; // accesses: 1
};

struct CFuncKeysReal {
    byte _padding_0x0[40];
    float * field_0x28; // accesses: 2
};

struct CFuncPathMesh {
    byte _padding_0x0[40];
    int * field_0x28; // accesses: 7
    CPfmMeshInterface * field_0x2c; // accesses: 3
};

struct CFuncPuffLull {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 6
    float field_0x8; // accesses: 5
    undefined4 field_0xc; // accesses: 2
    float field_0x10; // accesses: 2
    uint field_0x14; // accesses: 2
    byte _padding_0x18[16];
    float field_0x28; // accesses: 2
    byte _padding_0x2c[28];
    float field_0x48; // accesses: 2
    byte _padding_0x4c[8];
    float field_0x54; // accesses: 2
    byte _padding_0x58[4];
    float field_0x5c; // accesses: 2
};

struct CGameAdvertising {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 2
    float field_0x8; // accesses: 1
    byte field_0xc; // accesses: 2
    byte _padding_0xd[7];
    int field_0x14; // accesses: 2
    int field_0x18; // accesses: 3
    uint field_0x1c; // accesses: 6
    byte _padding_0x20[8];
    int field_0x28; // accesses: 3
    byte _padding_0x2c[4];
    ulong field_0x30; // accesses: 1
    CPlugVisualIndexedLines * field_0x34; // accesses: 1
    CPlugVisualIndexedLines * field_0x38; // accesses: 1
    float field_0x3c; // accesses: 2
    byte _padding_0x40[8];
    float field_0x48; // accesses: 1
    float field_0x4c; // accesses: 1
    float field_0x50; // accesses: 1
    byte _padding_0x54[4];
    CGameAdvertisingRadial * field_0x58; // accesses: 1
    byte _padding_0x5c[28];
    CPlugTree * field_0x78; // accesses: 1
    float field_0x7c; // accesses: 1
    float field_0x80; // accesses: 1
    int field_0x84; // accesses: 1
    byte _padding_0x88[8];
    float field_0x90; // accesses: 2
    CPlugShaderGeneric * field_0x94; // accesses: 1
    int field_0x98; // accesses: 1
    uint field_0x9c; // accesses: 6
    byte _padding_0xa0[40];
    int field_0xc8; // accesses: 3
    int field_0xcc; // accesses: 17
    GmIso3 * field_0xd0; // accesses: 6
};

struct CGameAdvertisingElement_CImpressionCollector {
    byte _padding_0x0[32];
    __time64_t field_0x20; // accesses: 1
    byte _padding_0x24[88];
    int field_0x7c; // accesses: 1
};

struct CGameApp {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 1
    byte _padding_0x8[12];
    undefined4 field_0x14; // accesses: 5
    int * field_0x18; // accesses: 13
    undefined4 field_0x1c; // accesses: 5
    undefined4 field_0x20; // accesses: 5
    CGameCtnCatalog * field_0x24; // accesses: 6
    int field_0x28; // accesses: 9
    undefined4 field_0x2c; // accesses: 5
    undefined4 field_0x30; // accesses: 5
    CGameApp * field_0x34; // accesses: 2
    undefined4 field_0x38; // accesses: 2
    undefined4 field_0x3c; // accesses: 2
    byte _padding_0x40[4];
    int field_0x44; // accesses: 1
    int field_0x48; // accesses: 1
    byte _padding_0x4c[4];
    int field_0x50; // accesses: 1
    byte _padding_0x54[16];
    CHmsViewport * field_0x64; // accesses: 2
    CAudioPort * field_0x68; // accesses: 7
    CMwNod * field_0x6c; // accesses: 1
    byte _padding_0x70[8];
    int field_0x78; // accesses: 10
    int field_0x7c; // accesses: 1
    byte _padding_0x80[16];
    int field_0x90; // accesses: 2
    byte _padding_0x94[120];
    CGameManialinkBrowser * field_0x10c; // accesses: 1
    CGameDialogs * field_0x110; // accesses: 1
    int field_0x114; // accesses: 4
    byte _padding_0x118[20];
    int field_0x12c; // accesses: 2
    int * field_0x130; // accesses: 2
    int field_0x134; // accesses: 4
    byte _padding_0x138[48];
    int field_0x168; // accesses: 6
    byte _padding_0x16c[4];
    CMwNod * field_0x170; // accesses: 1
    CMwNod * field_0x174; // accesses: 1
    CMwNod * field_0x178; // accesses: 1
    CAudioPort * field_0x17c; // accesses: 13
    CGameApp * field_0x180; // accesses: 6
    byte _padding_0x184[12];
    int field_0x190; // accesses: 3
    byte _padding_0x194[700];
    float field_0x450; // accesses: 1
    float field_0x454; // accesses: 1
};

struct CGameAvatar {
    byte _padding_0x0[32];
    CSystemPackManager * field_0x20; // accesses: 3
    byte _padding_0x24[44];
    CSystemPackManager * field_0x50; // accesses: 1
};

struct CGameCamera {
    byte _padding_0x0[68];
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    undefined4 field_0x58; // accesses: 2
    undefined4 field_0x5c; // accesses: 2
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
    undefined4 field_0x70; // accesses: 1
    CSceneCamera * field_0x74; // accesses: 1
};

struct CGameControlCamera {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    int field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 2
    byte _padding_0x20[48];
    undefined4 field_0x50; // accesses: 2
    undefined4 field_0x54; // accesses: 2
    undefined4 field_0x58; // accesses: 2
    undefined4 field_0x5c; // accesses: 1
    byte _padding_0x60[84];
    CGameControlCamera * field_0xb4; // accesses: 4
};

struct CGameControlCameraEffect {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
};

struct CGameControlCameraFree {
    byte _padding_0x0[456];
    CGameControlCameraFree * field_0x1c8; // accesses: 1
    SInputActionDesc * field_0x1cc; // accesses: 1
    SInputActionDesc * field_0x1d0; // accesses: 1
    SInputActionDesc * field_0x1d4; // accesses: 1
    SInputActionDesc * field_0x1d8; // accesses: 1
    SInputActionDesc * field_0x1dc; // accesses: 1
    SInputActionDesc * field_0x1e0; // accesses: 1
};

struct CGameControlCameraMaster {
    byte _padding_0x0[20];
    void * field_0x14; // accesses: 4
    byte _padding_0x18[80];
    int * field_0x68; // accesses: 13
    ulong field_0x6c; // accesses: 5
    int field_0x70; // accesses: 4
    undefined4 field_0x74; // accesses: 1
    byte _padding_0x78[4];
    int * field_0x7c; // accesses: 2
    byte _padding_0x80[4];
    int field_0x84; // accesses: 1
};

struct CGameControlCard {
    byte _padding_0x0[252];
    uint field_0xfc; // accesses: 3
    byte _padding_0x100[124];
    undefined4 field_0x17c; // accesses: 1
    byte _padding_0x180[60];
    int * field_0x1bc; // accesses: 3
    byte _padding_0x1c0[8];
    CGameControlCard * field_0x1c8; // accesses: 1
};

struct CGameControlCardManager {
    byte _padding_0x0[20];
    CGameControlCardManager * field_0x14; // accesses: 1
    CMwNod * field_0x18; // accesses: 1
};

struct CGameControlEdit {
    byte _padding_0x0[20];
    CMwNod * field_0x14; // accesses: 10
    byte _padding_0x18[4];
    int field_0x1c; // accesses: 5
    int field_0x20; // accesses: 5
    CMwNod * field_0x24; // accesses: 4
};

struct CGameControlGrid {
    byte _padding_0x0[464];
    undefined4 field_0x1d0; // accesses: 3
    byte _padding_0x1d4[48];
    CGameControlGrid * field_0x204; // accesses: 3
    byte _padding_0x208[16];
    ulong field_0x218; // accesses: 5
    CGameRemoteBuffer * field_0x21c; // accesses: 1
};

struct CGameControlMove {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    byte _padding_0x1c[36];
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    byte _padding_0x4c[36];
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1
    undefined4 field_0x78; // accesses: 1
    int field_0x7c; // accesses: 3
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
    undefined4 field_0x88; // accesses: 1
    undefined4 field_0x8c; // accesses: 1
    undefined4 field_0x90; // accesses: 1
    undefined4 field_0x94; // accesses: 1
    undefined4 field_0x98; // accesses: 1
    undefined4 field_0x9c; // accesses: 1
    undefined4 field_0xa0; // accesses: 1
    undefined4 field_0xa4; // accesses: 1
};

struct CGameControlPlayerAvatar {
    byte _padding_0x0[48];
    CGameAvatar * field_0x30; // accesses: 2
};

struct CGameControlRotate {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
};

struct CGameControlSelection {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    byte _padding_0x18[12];
    undefined4 field_0x24; // accesses: 1
    byte _padding_0x28[12];
    undefined4 field_0x34; // accesses: 1
};

struct CGameCtnApp {
    byte _padding_0x0[36];
    int field_0x24; // accesses: 1
    byte _padding_0x28[68];
    CInputPort * field_0x6c; // accesses: 6
    byte _padding_0x70[4];
    int field_0x74; // accesses: 2
    byte _padding_0x78[56];
    int field_0xb0; // accesses: 2
    byte _padding_0xb4[120];
    int field_0x12c; // accesses: 2
    byte _padding_0x130[20];
    CInputBindingsConfig * field_0x144; // accesses: 1
    CInputBindingsConfig * field_0x148; // accesses: 1
    byte _padding_0x14c[28];
    int field_0x168; // accesses: 3
    byte _padding_0x16c[8];
    int field_0x174; // accesses: 1
    byte _padding_0x178[28];
    int * field_0x194; // accesses: 5
    byte _padding_0x198[16];
    int field_0x1a8; // accesses: 3
    byte _padding_0x1ac[36];
    int field_0x1d0; // accesses: 1
    undefined4 field_0x1d4; // accesses: 1
    byte _padding_0x1d8[4];
    undefined4 field_0x1dc; // accesses: 1
    byte _padding_0x1e0[48];
    int field_0x210; // accesses: 4
    byte _padding_0x214[40];
    int * field_0x23c; // accesses: 3
    byte _padding_0x240[52];
    int field_0x274; // accesses: 1
    byte _padding_0x278[16];
    int field_0x288; // accesses: 2
    void * field_0x28c; // accesses: 1
    byte _padding_0x290[52];
    CInputBindingsConfig * field_0x2c4; // accesses: 1
    CInputBindingsConfig * field_0x2c8; // accesses: 1
    CInputBindingsConfig * field_0x2cc; // accesses: 1
    CInputBindingsConfig * field_0x2d0; // accesses: 1
    byte _padding_0x2d4[104];
    int field_0x33c; // accesses: 2
    int field_0x340; // accesses: 3
    float field_0x344; // accesses: 2
    undefined4 field_0x348; // accesses: 3
};

struct CGameCtnArticle {
    byte _padding_0x0[36];
    CPlugBitmap * field_0x24; // accesses: 2
    byte _padding_0x28[16];
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    byte _padding_0x48[16];
    CGameSkin * field_0x58; // accesses: 4
    undefined4 field_0x5c; // accesses: 3
};

struct CGameCtnBench {
    byte _padding_0x0[36];
    int * field_0x24; // accesses: 1
    byte _padding_0x28[16];
    int field_0x38; // accesses: 5
    int field_0x3c; // accesses: 5
    uint field_0x40; // accesses: 1
    int field_0x44; // accesses: 1
};

struct CGameCtnBlock {
    byte _padding_0x0[36];
    int field_0x24; // accesses: 4
    byte _padding_0x28[56];
    uint field_0x60; // accesses: 1
};

struct CGameCtnBlockInfo {
    byte _padding_0x0[48];
    undefined4 field_0x30; // accesses: 1
    byte _padding_0x34[36];
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1
    undefined4 field_0x78; // accesses: 1
    undefined4 field_0x7c; // accesses: 1
    byte _padding_0x80[36];
    float field_0xa4; // accesses: 1
    undefined4 field_0xa8; // accesses: 1
    float field_0xac; // accesses: 1
    byte _padding_0xb0[36];
    float field_0xd4; // accesses: 1
    undefined4 field_0xd8; // accesses: 1
    float field_0xdc; // accesses: 1
    undefined4 field_0xe0; // accesses: 1
    undefined4 field_0xe4; // accesses: 1
    undefined4 field_0xe8; // accesses: 1
    byte _padding_0xec[32];
    undefined4 field_0x10c; // accesses: 1
    undefined4 field_0x110; // accesses: 1
    undefined4 field_0x114; // accesses: 1
    undefined4 field_0x118; // accesses: 1
    undefined4 field_0x11c; // accesses: 1
    undefined4 field_0x120; // accesses: 1
    undefined4 field_0x124; // accesses: 1
    byte _padding_0x128[4];
    undefined4 field_0x12c; // accesses: 1
};

struct CGameCtnBlockUnitInfo {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    byte _padding_0x20[8];
    CGameCtnBlockInfoClip * field_0x28; // accesses: 1
    CGameCtnBlockInfoClip * field_0x2c; // accesses: 1
    CGameCtnBlockInfo * field_0x30; // accesses: 1
    byte _padding_0x34[4];
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    byte _padding_0x44[12];
    undefined4 field_0x50; // accesses: 1
};

struct CGameCtnChallenge {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 5
    float field_0x8; // accesses: 2
    byte _padding_0xc[12];
    CGameCtnBlockUnitInfo * field_0x18; // accesses: 1
    byte _padding_0x1c[8];
    CGameCtnCollection * field_0x24; // accesses: 5
    byte _padding_0x28[56];
    uint field_0x60; // accesses: 1
    byte _padding_0x64[24];
    float field_0x7c; // accesses: 1
    float field_0x80; // accesses: 1
    byte _padding_0x84[12];
    CGameCtnCollection * field_0x90; // accesses: 4
    byte _padding_0x94[8];
    uint field_0x9c; // accesses: 6
    byte _padding_0xa0[8];
    CGameCtnChallenge * field_0xa8; // accesses: 1
    uint field_0xac; // accesses: 1
    int field_0xb0; // accesses: 4
    byte _padding_0xb4[32];
    CGameCtnChallenge * field_0xd4; // accesses: 3
    int field_0xd8; // accesses: 3
    byte _padding_0xdc[204];
    int field_0x1a8; // accesses: 2
};

struct CGameCtnChapter {
    byte _padding_0x0[12];
    int field_0xc; // accesses: 4
    byte _padding_0x10[8];
    EDecorationMusic field_0x18; // accesses: 4
    byte _padding_0x1c[8];
    int field_0x24; // accesses: 1
};

struct CGameCtnCollection {
    byte _padding_0x0[28];
    int field_0x1c; // accesses: 4
    byte _padding_0x20[16];
    int field_0x30; // accesses: 4
    byte _padding_0x34[8];
    CGameCtnZone * field_0x3c; // accesses: 1
};

struct CGameCtnCollector {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    undefined * field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    byte _padding_0x24[12];
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    byte _padding_0x48[4];
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
};

struct CGameCtnCursor {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 3
    undefined4 field_0x8; // accesses: 3
    undefined4 field_0xc; // accesses: 1
    byte _padding_0x10[4];
    CPlugTree * field_0x14; // accesses: 3
    CPlugTree * field_0x18; // accesses: 3
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 4
    undefined4 field_0x24; // accesses: 4
    int field_0x28; // accesses: 10
    CGameCtnBlockInfo * field_0x2c; // accesses: 10
    int field_0x30; // accesses: 12
    float field_0x34; // accesses: 6
    float field_0x38; // accesses: 5
    undefined4 field_0x3c; // accesses: 2
    int * field_0x40; // accesses: 12
    int * field_0x44; // accesses: 18
    int * field_0x48; // accesses: 11
    CPlugTree * field_0x4c; // accesses: 16
    int field_0x50; // accesses: 22
    int field_0x54; // accesses: 3
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1
    float field_0x78; // accesses: 2
    float field_0x7c; // accesses: 2
    float field_0x80; // accesses: 2
    ESpriteColor0 * field_0x84; // accesses: 2
    undefined4 field_0x88; // accesses: 1
    undefined4 field_0x8c; // accesses: 1
    undefined4 field_0x90; // accesses: 1
    undefined4 field_0x94; // accesses: 1
    undefined4 field_0x98; // accesses: 1
    undefined4 field_0x9c; // accesses: 3
    undefined4 field_0xa0; // accesses: 1
    undefined4 field_0xa4; // accesses: 1
    undefined4 field_0xa8; // accesses: 1
    undefined4 field_0xac; // accesses: 1
    undefined4 field_0xb0; // accesses: 1
    undefined4 field_0xb4; // accesses: 1
    undefined4 field_0xb8; // accesses: 2
    undefined4 field_0xbc; // accesses: 2
    undefined4 field_0xc0; // accesses: 2
    undefined4 field_0xc4; // accesses: 2
    undefined4 field_0xc8; // accesses: 1
    undefined4 field_0xcc; // accesses: 1
    undefined4 field_0xd0; // accesses: 1
    undefined4 field_0xd4; // accesses: 1
    undefined4 field_0xd8; // accesses: 3
    undefined4 field_0xdc; // accesses: 1
    undefined4 field_0xe0; // accesses: 1
    undefined4 field_0xe4; // accesses: 1
    undefined4 field_0xe8; // accesses: 1
    undefined4 field_0xec; // accesses: 1
    undefined4 field_0xf0; // accesses: 1
    SVolatileTreePointer * field_0xf4; // accesses: 2
    byte _padding_0xf8[20];
    CGameCtnBlockInfo * field_0x10c; // accesses: 1
};

struct CGameCtnEditorScenePocLink {
    byte _padding_0x0[100];
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    byte _padding_0x6c[4];
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1
    float field_0x78; // accesses: 1
    float field_0x7c; // accesses: 12
    float field_0x80; // accesses: 2
    float field_0x84; // accesses: 1
    byte _padding_0x88[48];
    undefined4 field_0xb8; // accesses: 5
    undefined4 field_0xbc; // accesses: 1
};

struct CGameCtnGhost {
    byte _padding_0x0[4];
    SStringParam * field_0x4; // accesses: 1
    byte _padding_0x8[224];
    CGameCtnGhost * field_0xe8; // accesses: 1
    ulong field_0xec; // accesses: 1
    ulong field_0xf0; // accesses: 1
    byte _padding_0xf4[12];
    EReplayGhostVersion field_0x100; // accesses: 2
};

struct CGameCtnMasterServer {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 4
    byte _padding_0x8[4];
    CFastString * field_0xc; // accesses: 1
    CSystemFid * field_0x10; // accesses: 2
    undefined4 field_0x14; // accesses: 2
    byte _padding_0x18[24];
    ulong field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 2
    byte _padding_0x38[36];
    TiXmlText * field_0x5c; // accesses: 1
    byte _padding_0x60[168];
    int field_0x108; // accesses: 5
    byte _padding_0x10c[56];
    undefined4 field_0x144; // accesses: 2
    byte _padding_0x148[60];
    int field_0x184; // accesses: 1
    byte _padding_0x188[1320];
    int field_0x6b0; // accesses: 3
};

struct CGameCtnMediaBlock3dStereo {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 2
    float field_0x8; // accesses: 2
    byte _padding_0xc[24];
    int field_0x24; // accesses: 1
    byte _padding_0x28[12];
    float * field_0x34; // accesses: 1
};

struct CGameCtnMediaBlockFxBloom {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 3
    float field_0x8; // accesses: 3
    byte _padding_0xc[40];
    int field_0x34; // accesses: 1
};

struct CGameCtnMediaBlockFxBlurDepth {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 2
    int field_0x8; // accesses: 2
    float field_0xc; // accesses: 2
    byte _padding_0x10[36];
    int field_0x34; // accesses: 1
};

struct CGameCtnMediaBlockFxColors {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 3
    byte _padding_0x8[44];
    int field_0x34; // accesses: 1
    byte _padding_0x38[48];
    float field_0x68; // accesses: 3
    float field_0x6c; // accesses: 3
    float field_0x70; // accesses: 2
};

struct CGameCtnMediaBlockMusicEffect {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 3
    float field_0x8; // accesses: 3
    byte _padding_0xc[24];
    int field_0x24; // accesses: 1
};

struct CGameCtnMediaBlockSound {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 3
    float field_0x8; // accesses: 3
    float field_0xc; // accesses: 3
    float field_0x10; // accesses: 3
    float field_0x14; // accesses: 3
    byte _padding_0x18[12];
    int field_0x24; // accesses: 1
};

struct CGameCtnMediaBlockTime {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 2
    byte _padding_0x8[28];
    int field_0x24; // accesses: 1
    byte _padding_0x28[44];
    undefined4 * field_0x54; // accesses: 1
};

struct CGameCtnMediaBlockTransitionFade {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 3
    byte _padding_0x8[28];
    int field_0x24; // accesses: 1
    byte _padding_0x28[36];
    float field_0x4c; // accesses: 1
};

struct CGameCtnMediaClip {
    byte _padding_0x0[60];
    float field_0x3c; // accesses: 1
    float field_0x40; // accesses: 2
};

struct CGameCtnMediaClipPlayer {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    byte _padding_0x10[4];
    CGameCtnMediaClipPlayer * field_0x14; // accesses: 18
    ulong field_0x18; // accesses: 20
    CGameControlCameraMaster * field_0x1c; // accesses: 12
    CGameCtnMediaClipPlayer * field_0x20; // accesses: 5
    undefined4 field_0x24; // accesses: 4
    undefined4 field_0x28; // accesses: 4
    undefined4 field_0x2c; // accesses: 4
    CMwCmd * field_0x30; // accesses: 11
    int field_0x34; // accesses: 4
    CGameCtnMediaClipPlayer * field_0x38; // accesses: 2
    undefined4 field_0x3c; // accesses: 2
    float field_0x40; // accesses: 4
    CPlugFileVideo * field_0x44; // accesses: 3
    int * field_0x48; // accesses: 10
    float field_0x4c; // accesses: 3
    int field_0x50; // accesses: 2
    int field_0x54; // accesses: 19
    undefined4 field_0x58; // accesses: 1
    ulong field_0x5c; // accesses: 8
    int field_0x60; // accesses: 12
    byte _padding_0x64[4];
    CAudioPort * field_0x68; // accesses: 2
    byte _padding_0x6c[4];
    undefined4 field_0x70; // accesses: 2
    CGameCtnMediaClipViewer * field_0x74; // accesses: 2
    undefined4 field_0x78; // accesses: 1
    CGameCtnMediaClipPlayer * field_0x7c; // accesses: 2
    byte _padding_0x80[60];
    undefined4 field_0xbc; // accesses: 2
    byte _padding_0xc0[96];
    int field_0x120; // accesses: 2
    float field_0x124; // accesses: 1
    float field_0x128; // accesses: 1
    undefined4 field_0x12c; // accesses: 3
    byte _padding_0x130[12];
    undefined4 field_0x13c; // accesses: 2
    undefined4 field_0x140; // accesses: 2
    undefined4 field_0x144; // accesses: 2
    undefined4 field_0x148; // accesses: 2
    byte _padding_0x14c[48];
    CAudioPort * field_0x17c; // accesses: 2
};

struct CGameCtnMediaClipViewer {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 6
    int field_0x1c; // accesses: 3
    undefined4 field_0x20; // accesses: 1
    int field_0x24; // accesses: 2
    CGameCtnMediaClipViewer * field_0x28; // accesses: 1
    int field_0x2c; // accesses: 13
    int field_0x30; // accesses: 23
    int * field_0x34; // accesses: 6
    int * field_0x38; // accesses: 7
    undefined4 field_0x3c; // accesses: 2
    byte _padding_0x40[4];
    CGameCtnMediaClipGroup * field_0x44; // accesses: 11
    undefined4 field_0x48; // accesses: 1
    CGameCtnMediaClipPlayer * field_0x4c; // accesses: 12
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 2
    undefined4 field_0x68; // accesses: 2
    undefined4 field_0x6c; // accesses: 2
    undefined4 field_0x70; // accesses: 2
    int * field_0x74; // accesses: 6
    CGameCtnMediaClipViewer * field_0x78; // accesses: 3
};

struct CGameCtnMediaTracker {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 15
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 2
    byte _padding_0x10[4];
    int * field_0x14; // accesses: 8
    float field_0x18; // accesses: 5
    int field_0x1c; // accesses: 4
    CGameCtnChallenge * field_0x20; // accesses: 2
    byte _padding_0x24[4];
    CControlEffectSimi * field_0x28; // accesses: 2
    int field_0x2c; // accesses: 2
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    CControlEffectSimi * field_0x38; // accesses: 4
    byte _padding_0x3c[8];
    CGameCtnChallenge * field_0x44; // accesses: 1
    STransformDesc * field_0x48; // accesses: 1
    float field_0x4c; // accesses: 1
    float field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    int field_0x58; // accesses: 1
    byte _padding_0x5c[36];
    CGameCtnChallenge * field_0x80; // accesses: 1
    byte _padding_0x84[28];
    CGameSafeFrame * field_0xa0; // accesses: 4
    byte _padding_0xa4[4];
    int field_0xa8; // accesses: 1
    int field_0xac; // accesses: 2
    int field_0xb0; // accesses: 1
    int field_0xb4; // accesses: 16
    byte _padding_0xb8[4];
    int field_0xbc; // accesses: 1
    byte _padding_0xc0[12];
    int * field_0xcc; // accesses: 9
    byte _padding_0xd0[12];
    int field_0xdc; // accesses: 1
    byte _padding_0xe0[28];
    int field_0xfc; // accesses: 2
    byte _padding_0x100[24];
    int field_0x118; // accesses: 2
    int field_0x11c; // accesses: 7
    int * field_0x120; // accesses: 2
    byte _padding_0x124[108];
    int field_0x190; // accesses: 10
    int field_0x194; // accesses: 1
    CGameCtnCursor * field_0x198; // accesses: 5
    byte _padding_0x19c[116];
    int field_0x210; // accesses: 2
    byte _padding_0x214[20];
    int field_0x228; // accesses: 3
    byte _padding_0x22c[92];
    CGameControlCamera * field_0x288; // accesses: 7
    int * field_0x28c; // accesses: 3
    byte _padding_0x290[52];
    int field_0x2c4; // accesses: 1
    byte _padding_0x2c8[4];
    int field_0x2cc; // accesses: 2
    byte _padding_0x2d0[32];
    int * field_0x2f0; // accesses: 3
    byte _padding_0x2f4[212];
    int field_0x3c8; // accesses: 1
    byte _padding_0x3cc[32];
    undefined4 field_0x3ec; // accesses: 1
    byte _padding_0x3f0[92];
    int field_0x44c; // accesses: 4
    int * field_0x450; // accesses: 4
};

struct CGameCtnMenuProfileScene {
    byte _padding_0x0[28];
    int * field_0x1c; // accesses: 2
    int * field_0x20; // accesses: 2
    float field_0x24; // accesses: 1
    byte _padding_0x28[4];
    float field_0x2c; // accesses: 1
    float field_0x30; // accesses: 3
    float field_0x34; // accesses: 4
    float field_0x38; // accesses: 3
};

struct CGameCtnMenus {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    byte _padding_0xc[148];
    CHmsZone * field_0xa0; // accesses: 1
    byte _padding_0xa4[152];
    undefined4 field_0x13c; // accesses: 1
    byte _padding_0x140[36];
    undefined4 * field_0x164; // accesses: 2
    byte _padding_0x168[140];
    int field_0x1f4; // accesses: 1
    int field_0x1f8; // accesses: 1
    byte _padding_0x1fc[32];
    undefined4 field_0x21c; // accesses: 3
    undefined4 field_0x220; // accesses: 1
    byte _padding_0x224[24];
    undefined4 field_0x23c; // accesses: 1
    undefined4 field_0x240; // accesses: 1
    undefined4 field_0x244; // accesses: 1
    byte _padding_0x248[860];
    int field_0x5a4; // accesses: 6
    undefined4 field_0x5a8; // accesses: 3
    byte _padding_0x5ac[112];
    undefined4 field_0x61c; // accesses: 3
    int field_0x620; // accesses: 2
    byte _padding_0x624[128];
    CControlContainer * field_0x6a4; // accesses: 1
    byte _padding_0x6a8[88];
    undefined4 field_0x700; // accesses: 1
    byte _padding_0x704[128];
    CGameCtnApp * field_0x784; // accesses: 9
    int field_0x788; // accesses: 3
    int field_0x78c; // accesses: 4
};

struct CGameCtnNetForm {
    byte _padding_0x0[1];
    uint field_0x1; // accesses: 1
    uint field_0x4; // accesses: 1
    uint field_0x5; // accesses: 1
    byte _padding_0x9[23];
    undefined4 field_0x20; // accesses: 1
};

struct CGameCtnNetwork {
    byte _padding_0x0[36];
    undefined1 field_0x24; // accesses: 5
    byte _padding_0x25[3];
    CNetMasterServer * field_0x28; // accesses: 2
    byte _padding_0x2c[8];
    uint field_0x34; // accesses: 2
    byte _padding_0x38[8];
    int field_0x40; // accesses: 2
    int field_0x44; // accesses: 1
    byte _padding_0x48[36];
    int field_0x6c; // accesses: 1
    int field_0x70; // accesses: 1
    int field_0x74; // accesses: 1
    char field_0x78; // accesses: 3
    byte _padding_0x79[3];
    int field_0x7c; // accesses: 4
    undefined4 field_0x80; // accesses: 6
    byte _padding_0x84[4];
    int field_0x88; // accesses: 1
    byte _padding_0x8c[292];
    CNetMasterServer * field_0x1b0; // accesses: 2
    byte _padding_0x1b4[1092];
    int * field_0x5f8; // accesses: 9
};

struct CGameCtnPainter {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 2
    byte _padding_0x18[660];
    int field_0x2ac; // accesses: 4
    byte _padding_0x2b0[24];
    int * field_0x2c8; // accesses: 11
    byte _padding_0x2cc[4];
    int field_0x2d0; // accesses: 6
    byte _padding_0x2d4[44];
    int field_0x300; // accesses: 6
    byte _padding_0x304[56];
    int field_0x33c; // accesses: 2
    int field_0x340; // accesses: 2
    byte _padding_0x344[8];
    ulong field_0x34c; // accesses: 2
    ulong field_0x350; // accesses: 2
};

struct CGameCtnReplayRecord {
    byte _padding_0x0[4];
    CGameCtnReplayRecord * field_0x4; // accesses: 1
    byte _padding_0x8[12];
    undefined4 field_0x14; // accesses: 1
    byte _padding_0x18[12];
    CFastString * field_0x24; // accesses: 3
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    byte _padding_0x30[12];
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    byte _padding_0x4c[132];
    CFastStringInt * field_0xd0; // accesses: 1
    CGameCtnReplayRecord * field_0xd4; // accesses: 1
    byte _padding_0xd8[16];
    undefined4 field_0xe8; // accesses: 1
    ulong field_0xec; // accesses: 1
    ulong field_0xf0; // accesses: 1
    byte _padding_0xf4[4];
    int field_0xf8; // accesses: 1
    byte _padding_0xfc[16];
    ulong field_0x10c; // accesses: 2
};

struct CGameDialogs {
    byte _padding_0x0[20];
    int field_0x14; // accesses: 4
    byte _padding_0x18[12];
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    byte _padding_0x2c[16];
    int field_0x3c; // accesses: 1
    CMwNod * field_0x40; // accesses: 1
    _func___cdecl_void * field_0x44; // accesses: 1
    byte _padding_0x48[40];
    int field_0x70; // accesses: 3
    int * field_0x74; // accesses: 2
    byte _padding_0x78[56];
    int field_0xb0; // accesses: 1
    byte _padding_0xb4[88];
    undefined4 field_0x10c; // accesses: 2
};

struct CGameGhost {
    byte _padding_0x0[68];
    int field_0x44; // accesses: 1
    byte _padding_0x48[32];
    int field_0x68; // accesses: 2
};

struct CGameLeague {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 4
    byte _padding_0x8[16];
    SStringParam * field_0x18; // accesses: 1
    byte _padding_0x1c[4];
    undefined4 field_0x20; // accesses: 1
};

struct CGameManialink {
    byte _padding_0x0[4];
    SManialinkFormat * field_0x4; // accesses: 1
    TiXmlNode * field_0x8; // accesses: 4
    TiXmlNode * field_0xc; // accesses: 9
    int field_0x10; // accesses: 2
    byte _padding_0x14[8];
    TiXmlElement * field_0x1c; // accesses: 1
    int field_0x20; // accesses: 5
    int field_0x24; // accesses: 1
    byte _padding_0x28[4];
    CControlContainer * field_0x2c; // accesses: 9
    CControlLabel * field_0x30; // accesses: 1
    float field_0x34; // accesses: 2
    float field_0x38; // accesses: 2
    undefined4 field_0x3c; // accesses: 1
    undefined * field_0x40; // accesses: 1
    byte _padding_0x44[316];
    int field_0x180; // accesses: 2
    undefined4 field_0x184; // accesses: 1
    byte _padding_0x188[12];
    int field_0x194; // accesses: 1
};

struct CGameManialinkBrowser {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 1
    byte _padding_0x8[12];
    CGameApp_MenuContext * field_0x14; // accesses: 4
    int field_0x18; // accesses: 3
    int field_0x1c; // accesses: 1
    byte _padding_0x20[4];
    int * field_0x24; // accesses: 4
    byte _padding_0x28[4];
    undefined4 field_0x2c; // accesses: 3
    int field_0x30; // accesses: 4
    int field_0x34; // accesses: 2
    undefined1 * field_0x38; // accesses: 1
    byte _padding_0x39[3];
    undefined4 field_0x3c; // accesses: 3
    undefined4 field_0x40; // accesses: 3
    CAudioPort * field_0x44; // accesses: 4
    byte _padding_0x48[52];
    undefined4 field_0x7c; // accesses: 1
    byte _padding_0x80[28];
    int field_0x9c; // accesses: 1
    CGameApp * field_0xa0; // accesses: 5
};

struct CGameManialinkEntry {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    undefined * field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined * field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
};

struct CGameManialinkFileEntry {
    byte _padding_0x0[36];
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 9
    undefined4 field_0x2c; // accesses: 9
    ulong field_0x30; // accesses: 2
    undefined4 field_0x34; // accesses: 1
    undefined * field_0x38; // accesses: 1
};

struct CGameMasterServer {
    byte _padding_0x0[4];
    CClassicBuffer * field_0x4; // accesses: 3
    byte _padding_0x8[4];
    int field_0xc; // accesses: 1
    byte _padding_0x10[4];
    int field_0x14; // accesses: 1
    byte _padding_0x18[8];
    CFastStringInt * field_0x20; // accesses: 1
    TiXmlNode * field_0x24; // accesses: 2
    char * field_0x28; // accesses: 1
    byte _padding_0x29[11];
    undefined4 field_0x34; // accesses: 3
    TiXmlNode * field_0x38; // accesses: 2
    TiXmlElement * field_0x3c; // accesses: 2
    byte _padding_0x40[8];
    CSystemFid * field_0x48; // accesses: 3
    byte _padding_0x4c[300];
    undefined4 field_0x178; // accesses: 2
    byte _padding_0x17c[8];
    int field_0x184; // accesses: 3
    byte _padding_0x188[56];
    int field_0x1c0; // accesses: 1
    byte _padding_0x1c4[12];
    void * field_0x1d0; // accesses: 1
    byte _padding_0x1d4[12];
    ulong field_0x1e0; // accesses: 1
    byte _padding_0x1e4[252];
    undefined2 * field_0x2e0; // accesses: 1
};

struct CGameMasterServerRequest {
    byte _padding_0x0[88];
    CGameMasterServerRequest * field_0x58; // accesses: 1
    CMwNod * field_0x5c; // accesses: 1
    CGameMasterServerRequest * field_0x60; // accesses: 1
    CMwNod * field_0x64; // accesses: 1
};

struct CGameMasterServerRequestParams {
    byte _padding_0x0[12];
    SStringParam * field_0xc; // accesses: 1
};

struct CGameMenu {
    byte _padding_0x0[124];
    CGameMenu * field_0x7c; // accesses: 1
    byte _padding_0x80[48];
    uint field_0xb0; // accesses: 1
};

struct CGameMenuFrame {
    byte _padding_0x0[360];
    CGameMenuFrame * field_0x168; // accesses: 1
};

struct CGameMobil {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 3
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 2
    undefined * field_0x28; // accesses: 3
    undefined4 field_0x2c; // accesses: 3
    undefined4 field_0x30; // accesses: 1
};

struct CGameNetClient {
    byte _padding_0x0[348];
    CNetConnection * field_0x15c; // accesses: 2
};

struct CGameNetFormAdmin {
    byte _padding_0x0[28];
    undefined4 field_0x1c; // accesses: 1
};

struct CGameNetPlayerInfo {
    byte _padding_0x0[36];
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined * field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined * field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    undefined * field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 2
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
    int field_0x70; // accesses: 2
    int field_0x74; // accesses: 2
    byte _padding_0x78[4];
    undefined4 field_0x7c; // accesses: 1
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
    undefined4 field_0x88; // accesses: 1
    undefined4 field_0x8c; // accesses: 1
    undefined4 field_0x90; // accesses: 1
    undefined4 field_0x94; // accesses: 1
    byte _padding_0x98[32];
    undefined4 field_0xb8; // accesses: 1
    undefined4 field_0xbc; // accesses: 1
    byte _padding_0xc0[4];
    undefined4 field_0xc4; // accesses: 1
    byte _padding_0xc8[12];
    undefined4 field_0xd4; // accesses: 1
    undefined4 field_0xd8; // accesses: 1
    undefined4 field_0xdc; // accesses: 1
    undefined4 field_0xe0; // accesses: 1
    byte _padding_0xe4[36];
    ulong field_0x108; // accesses: 1
    undefined4 field_0x10c; // accesses: 1
    undefined4 field_0x110; // accesses: 1
    undefined4 field_0x114; // accesses: 1
    undefined4 field_0x118; // accesses: 1
    undefined4 field_0x11c; // accesses: 1
    undefined4 field_0x120; // accesses: 1
    undefined4 field_0x124; // accesses: 1
    undefined4 field_0x128; // accesses: 1
    undefined4 field_0x12c; // accesses: 1
    undefined2 field_0x130; // accesses: 1
    undefined2 field_0x132; // accesses: 1
    undefined4 field_0x134; // accesses: 1
    byte _padding_0x138[8];
    undefined2 field_0x140; // accesses: 1
    byte _padding_0x142[2];
    undefined4 field_0x144; // accesses: 1
    undefined4 field_0x148; // accesses: 1
    undefined4 field_0x14c; // accesses: 1
    undefined4 field_0x150; // accesses: 2
    undefined4 field_0x154; // accesses: 1
    undefined4 field_0x158; // accesses: 1
    undefined4 field_0x15c; // accesses: 1
    undefined4 field_0x160; // accesses: 1
    undefined4 field_0x164; // accesses: 1
    byte _padding_0x168[12];
    undefined4 field_0x174; // accesses: 1
};

struct CGameNetServerInfo {
    byte _padding_0x0[180];
    CGameNetServerInfo * field_0xb4; // accesses: 2
};

struct CGameNetwork {
    byte _padding_0x0[4];
    int * field_0x4; // accesses: 12
    byte _padding_0x8[8];
    SStringParam * field_0x10; // accesses: 5
    undefined4 field_0x14; // accesses: 2
    int field_0x18; // accesses: 1
    int field_0x1c; // accesses: 4
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    byte _padding_0x30[24];
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    byte _padding_0x58[4];
    undefined4 field_0x5c; // accesses: 1
    byte _padding_0x60[48];
    ulong field_0x90; // accesses: 1
    byte _padding_0x94[24];
    undefined4 field_0xac; // accesses: 1
    ushort field_0xb0; // accesses: 1
    byte _padding_0xb2[2];
    int field_0xb4; // accesses: 3
    byte _padding_0xb8[4];
    CGameNetwork * field_0xbc; // accesses: 1
    undefined1 * field_0xc0; // accesses: 1
    byte _padding_0xc1[3];
    undefined4 field_0xc4; // accesses: 1
    byte _padding_0xc8[92];
    int field_0x124; // accesses: 1
    undefined4 field_0x128; // accesses: 1
    byte _padding_0x12c[28];
    EPlayerType field_0x148; // accesses: 1
    byte _padding_0x14c[24];
    ulong field_0x164; // accesses: 1
    byte _padding_0x168[12];
    int field_0x174; // accesses: 1
    byte _padding_0x178[4];
    int field_0x17c; // accesses: 1
    byte _padding_0x180[4];
    int field_0x184; // accesses: 1
    byte _padding_0x188[32];
    int * field_0x1a8; // accesses: 8
    CGameNetServer * field_0x1ac; // accesses: 10
    int field_0x1b0; // accesses: 3
    byte _padding_0x1b4[4];
    int field_0x1b8; // accesses: 8
    byte _padding_0x1bc[20];
    int field_0x1d0; // accesses: 11
    int field_0x1d4; // accesses: 5
    byte _padding_0x1d8[100];
    int * field_0x23c; // accesses: 15
    byte _padding_0x240[896];
    int field_0x5c0; // accesses: 2
};

struct CGameNod {
    byte _padding_0x0[24];
    undefined4 field_0x18; // accesses: 1
};

struct CGameOutlineBox {
    byte _padding_0x0[4];
    ulong field_0x4; // accesses: 7
    int field_0x8; // accesses: 9
    byte _padding_0xc[4];
    CGameOutlineBox * field_0x10; // accesses: 1
    float field_0x14; // accesses: 9
    CPlugTree * field_0x18; // accesses: 9
    float field_0x1c; // accesses: 5
    float field_0x20; // accesses: 5
    float field_0x24; // accesses: 4
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    float field_0x30; // accesses: 3
    float field_0x34; // accesses: 3
    float field_0x38; // accesses: 3
    float field_0x3c; // accesses: 3
    byte _padding_0x40[92];
    uint field_0x9c; // accesses: 1
};

struct CGamePlayer {
    byte _padding_0x0[4];
    SStringParam * field_0x4; // accesses: 1
    byte _padding_0x8[20];
    int field_0x1c; // accesses: 4
    undefined4 field_0x20; // accesses: 3
    int * field_0x24; // accesses: 11
    CGamePlayer * field_0x28; // accesses: 4
    byte _padding_0x2c[4];
    undefined4 field_0x30; // accesses: 2
    undefined * field_0x34; // accesses: 3
    byte _padding_0x38[12];
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    byte _padding_0x4c[492];
    int field_0x238; // accesses: 3
};

struct CGamePlayerCameraSet {
    byte _padding_0x0[20];
    CGameControlCamera * field_0x14; // accesses: 4
    CGameControlCameraMaster * field_0x18; // accesses: 10
    CGameControlCamera * field_0x1c; // accesses: 7
    byte _padding_0x20[96];
    undefined4 field_0x80; // accesses: 1
};

struct CGamePlayerInfo {
    byte _padding_0x0[388];
    undefined4 field_0x184; // accesses: 1
    undefined * field_0x188; // accesses: 1
    byte _padding_0x18c[20];
    undefined4 field_0x1a0; // accesses: 1
    undefined4 field_0x1a4; // accesses: 1
    undefined4 field_0x1a8; // accesses: 1
    undefined4 field_0x1ac; // accesses: 1
    undefined4 field_0x1b0; // accesses: 1
    undefined4 field_0x1b4; // accesses: 1
    undefined4 field_0x1b8; // accesses: 1
    byte _padding_0x1bc[8];
    undefined4 field_0x1c4; // accesses: 1
    undefined4 field_0x1c8; // accesses: 1
    undefined4 field_0x1cc; // accesses: 1
    CGamePlayerInfo * field_0x1d0; // accesses: 1
    byte _padding_0x1d4[8];
    undefined4 field_0x1dc; // accesses: 1
    undefined4 field_0x1e0; // accesses: 1
    undefined4 field_0x1e4; // accesses: 1
    undefined4 field_0x1e8; // accesses: 1
    undefined4 field_0x1ec; // accesses: 1
    undefined4 field_0x1f0; // accesses: 1
    undefined4 field_0x1f4; // accesses: 1
    undefined * field_0x1f8; // accesses: 1
    byte _padding_0x1fc[8];
    undefined4 field_0x204; // accesses: 1
    byte _padding_0x208[36];
    undefined4 field_0x22c; // accesses: 1
    undefined * field_0x230; // accesses: 1
    undefined4 field_0x234; // accesses: 1
    undefined4 field_0x238; // accesses: 1
};

struct CGamePlayerProfile {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 3
    undefined4 field_0x8; // accesses: 1
    byte _padding_0xc[28];
    float field_0x28; // accesses: 2
    float field_0x2c; // accesses: 1
};

struct CGamePlayerScore {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
};

struct CGamePlayerTagData {
    byte _padding_0x0[20];
    int field_0x14; // accesses: 2
};

struct CGamePlayground {
    byte _padding_0x0[4];
    TiXmlDeclaration * field_0x4; // accesses: 3
    byte _padding_0x8[8];
    int field_0x10; // accesses: 2
    byte _padding_0x14[4];
    int field_0x18; // accesses: 9
    byte _padding_0x1c[4];
    int field_0x20; // accesses: 3
    byte _padding_0x24[12];
    undefined4 field_0x30; // accesses: 6
    undefined4 field_0x34; // accesses: 6
    byte _padding_0x38[12];
    int * field_0x44; // accesses: 8
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
};

struct CGamePlaygroundInterface {
    byte _padding_0x0[20];
    CGameManialinkPage * field_0x14; // accesses: 8
    CGameApp * field_0x18; // accesses: 2
    byte _padding_0x1c[12];
    int field_0x28; // accesses: 3
    undefined4 field_0x2c; // accesses: 4
    byte _padding_0x30[16];
    int field_0x40; // accesses: 3
    int * field_0x44; // accesses: 6
    int field_0x48; // accesses: 2
    byte _padding_0x4c[28];
    CControlLabel * field_0x68; // accesses: 5
    byte _padding_0x6c[20];
    byte field_0x80; // accesses: 1
    byte _padding_0x81[3];
    CFastStringInt * field_0x84; // accesses: 1
    byte _padding_0x88[8];
    uint field_0x90; // accesses: 1
    uint field_0x94; // accesses: 1
    ulong field_0x98; // accesses: 4
};

struct CGameRace {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 1
    byte _padding_0xc[4];
    int field_0x10; // accesses: 2
    int * field_0x14; // accesses: 2
    CGameCtnApp * field_0x18; // accesses: 17
    int field_0x1c; // accesses: 2
    int * field_0x20; // accesses: 13
    int field_0x24; // accesses: 3
    int field_0x28; // accesses: 11
    CGameNetPlayerInfo * field_0x2c; // accesses: 1
    CGameScene * field_0x30; // accesses: 5
    CMwNod * field_0x34; // accesses: 4
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    byte _padding_0x40[4];
    undefined4 field_0x44; // accesses: 3
    undefined4 field_0x48; // accesses: 1
    byte _padding_0x4c[4];
    CGameRace * field_0x50; // accesses: 2
    undefined4 field_0x54; // accesses: 3
    int field_0x58; // accesses: 8
    undefined4 field_0x5c; // accesses: 3
    CGameCtnMediaClipPlayer * field_0x60; // accesses: 15
    byte _padding_0x64[8];
    int field_0x6c; // accesses: 6
    int field_0x70; // accesses: 7
    int field_0x74; // accesses: 7
    undefined4 field_0x78; // accesses: 1
    undefined4 field_0x7c; // accesses: 2
    CGamePlayerCameraSet * field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
    undefined4 field_0x88; // accesses: 1
    byte _padding_0x8c[4];
    int field_0x90; // accesses: 1
    byte _padding_0x94[4];
    int field_0x98; // accesses: 6
    undefined4 field_0x9c; // accesses: 2
    CGameCtnMediaClipPlayer * field_0xa0; // accesses: 25
    CGameCtnMediaClipPlayer * field_0xa4; // accesses: 26
    int field_0xa8; // accesses: 4
    int field_0xac; // accesses: 2
    int * field_0xb0; // accesses: 10
    undefined4 field_0xb4; // accesses: 6
    byte _padding_0xb8[184];
    CMwNod * field_0x170; // accesses: 1
    CMwNod * field_0x174; // accesses: 1
    byte _padding_0x178[8];
    CGameCtnMediaClipPlayer * field_0x180; // accesses: 5
    byte _padding_0x184[180];
    CGamePlayer * field_0x238; // accesses: 1
};

struct CGameRemoteBufferPool {
    byte _padding_0x0[20];
    int * field_0x14; // accesses: 4
};

struct CGameSafeFrame {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    byte _padding_0x14[4];
    int field_0x18; // accesses: 2
    float field_0x1c; // accesses: 4
    float field_0x20; // accesses: 2
    float field_0x24; // accesses: 2
    int field_0x28; // accesses: 2
    float field_0x2c; // accesses: 1
    float field_0x30; // accesses: 1
    float field_0x34; // accesses: 1
    float field_0x38; // accesses: 1
    int field_0x3c; // accesses: 1
    CScene2d * field_0x40; // accesses: 1
    int field_0x44; // accesses: 2
    CScene2d * field_0x48; // accesses: 2
    byte _padding_0x4c[204];
    int field_0x118; // accesses: 1
    byte _padding_0x11c[8];
    float field_0x124; // accesses: 2
    byte _padding_0x128[8];
    float field_0x130; // accesses: 1
    byte _padding_0x134[368];
    int field_0x2a4; // accesses: 2
    int field_0x2a8; // accesses: 2
};

struct CGameScene {
    byte _padding_0x0[20];
    int * field_0x14; // accesses: 2
    byte _padding_0x18[4];
    undefined4 field_0x1c; // accesses: 2
    byte _padding_0x20[4];
    int * field_0x24; // accesses: 1
    byte _padding_0x28[8];
    int field_0x30; // accesses: 2
};

struct CGameSkin {
    byte _padding_0x0[28];
    undefined * field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
};

struct CGameSystemOverlay {
    byte _padding_0x0[56];
    uint field_0x38; // accesses: 4
};

struct CGbxApp {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 13
    byte _padding_0x18[4];
    int field_0x1c; // accesses: 1
    int field_0x20; // accesses: 1
    int field_0x24; // accesses: 2
    int field_0x28; // accesses: 1
    CSystemFids * field_0x2c; // accesses: 2
    CVisionViewportDx9 * field_0x30; // accesses: 2
    byte _padding_0x34[68];
    int field_0x78; // accesses: 2
    byte _padding_0x7c[56];
    int field_0xb4; // accesses: 1
    byte _padding_0xb8[52];
    undefined4 field_0xec; // accesses: 1
};

struct CGbxGame {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    byte _padding_0x18[20];
    HINSTANCE field_0x2c; // accesses: 1
    int field_0x30; // accesses: 8
    byte _padding_0x34[8];
    int field_0x3c; // accesses: 1
    byte _padding_0x40[16];
    HWND field_0x50; // accesses: 1
    byte _padding_0x54[40];
    undefined4 field_0x7c; // accesses: 1
    CMwEngine * field_0x80; // accesses: 3
    byte _padding_0x84[124];
    int field_0x100; // accesses: 2
    int field_0x104; // accesses: 1
    byte _padding_0x108[4];
    int field_0x10c; // accesses: 1
    byte _padding_0x110[12];
    int field_0x11c; // accesses: 1
};

struct CHmsAmbientOcc {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
};

struct CHmsCamera {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 4
    float field_0x8; // accesses: 4
    undefined4 field_0xc; // accesses: 2
    float field_0x10; // accesses: 2
    float field_0x14; // accesses: 2
    byte _padding_0x18[8];
    int field_0x20; // accesses: 1
    int field_0x24; // accesses: 1
    int field_0x28; // accesses: 1
    byte _padding_0x2c[4];
    float field_0x30; // accesses: 2
    undefined4 field_0x34; // accesses: 2
    undefined4 field_0x38; // accesses: 2
    float field_0x3c; // accesses: 5
    float field_0x40; // accesses: 4
    byte _padding_0x44[104];
    int field_0xac; // accesses: 1
    byte _padding_0xb0[16];
    int field_0xc0; // accesses: 2
    byte _padding_0xc4[84];
    int field_0x118; // accesses: 7
    float field_0x11c; // accesses: 5
    float field_0x120; // accesses: 5
    float field_0x124; // accesses: 12
    float field_0x128; // accesses: 4
    float field_0x12c; // accesses: 5
    float field_0x130; // accesses: 15
    int field_0x134; // accesses: 3
    undefined4 field_0x138; // accesses: 1
    undefined4 field_0x13c; // accesses: 1
    undefined4 field_0x140; // accesses: 1
    undefined4 field_0x144; // accesses: 1
    undefined4 field_0x148; // accesses: 1
    undefined4 field_0x14c; // accesses: 1
    undefined4 field_0x150; // accesses: 1
    undefined4 field_0x154; // accesses: 1
    undefined4 field_0x158; // accesses: 1
    undefined4 field_0x15c; // accesses: 1
    undefined4 field_0x160; // accesses: 1
    undefined4 field_0x164; // accesses: 3
    int field_0x168; // accesses: 2
    float field_0x16c; // accesses: 2
    float field_0x170; // accesses: 5
    int field_0x174; // accesses: 3
    float field_0x178; // accesses: 8
    undefined4 field_0x17c; // accesses: 1
    int field_0x180; // accesses: 2
    int field_0x184; // accesses: 3
    int field_0x188; // accesses: 3
    int field_0x18c; // accesses: 2
    int field_0x190; // accesses: 2
    int field_0x194; // accesses: 2
    float field_0x198; // accesses: 2
    float field_0x19c; // accesses: 3
    int * field_0x1a0; // accesses: 3
    byte _padding_0x1a4[12];
    undefined4 field_0x1b0; // accesses: 1
    undefined4 field_0x1b4; // accesses: 1
    undefined4 field_0x1b8; // accesses: 1
    undefined4 field_0x1bc; // accesses: 1
    undefined4 field_0x1c0; // accesses: 1
    float field_0x1c4; // accesses: 3
    float field_0x1c8; // accesses: 3
    float field_0x1cc; // accesses: 3
    float field_0x1d0; // accesses: 3
    undefined4 field_0x1d4; // accesses: 1
    float field_0x1d8; // accesses: 4
    float field_0x1dc; // accesses: 4
    float field_0x1e0; // accesses: 4
    undefined4 field_0x1e4; // accesses: 1
    undefined4 field_0x1e8; // accesses: 1
    undefined4 field_0x1ec; // accesses: 1
    undefined4 field_0x1f0; // accesses: 1
    int field_0x1f4; // accesses: 3
    int field_0x1f8; // accesses: 4
    CHmsCamera * field_0x1fc; // accesses: 3
    int field_0x200; // accesses: 2
    undefined4 field_0x204; // accesses: 2
    undefined4 field_0x208; // accesses: 1
    int * field_0x20c; // accesses: 8
    int field_0x210; // accesses: 2
    byte _padding_0x214[144];
    int field_0x2a4; // accesses: 2
    int field_0x2a8; // accesses: 2
};

struct CHmsCollisionManager {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 2
    byte _padding_0x8[8];
    int field_0x10; // accesses: 2
    undefined4 field_0x14; // accesses: 1
    int field_0x18; // accesses: 6
    byte _padding_0x1c[52];
    void * field_0x50; // accesses: 2
};

struct CHmsCollisionManager_SGroup {
    byte _padding_0x0[8];
    CSystemFidFile * field_0x8; // accesses: 2
    SCasterCat * field_0xc; // accesses: 1
    CSystemFid * field_0x10; // accesses: 2
    int field_0x14; // accesses: 2
    byte _padding_0x18[36];
    uint field_0x3c; // accesses: 3
    byte _padding_0x40[8];
    int field_0x48; // accesses: 4
    int field_0x4c; // accesses: 1
    CHmsCorpus * field_0x50; // accesses: 1
    ulong field_0x54; // accesses: 5
    byte _padding_0x58[52];
    int field_0x8c; // accesses: 1
    byte _padding_0x90[12];
    uint field_0x9c; // accesses: 2
};

struct CHmsCollisionManager_SZone {
    byte _padding_0x0[4];
    GmIso3 * field_0x4; // accesses: 28
    char field_0x6; // accesses: 4
    byte _padding_0x7[1];
    GmVec3 * field_0x8; // accesses: 20
    GmIso3 * field_0xc; // accesses: 12
    CHmsCorpus * field_0x10; // accesses: 10
    int field_0x14; // accesses: 4
    byte _padding_0x18[15];
    byte field_0x27; // accesses: 3
    byte _padding_0x28[12];
    int field_0x34; // accesses: 12
    byte _padding_0x38[16];
    int field_0x48; // accesses: 14
    byte _padding_0x4c[4];
    CHmsCollisionBuffer * field_0x50; // accesses: 12
    CSystemData * field_0x54; // accesses: 1
    int field_0x58; // accesses: 12
    byte _padding_0x5c[48];
    int field_0x8c; // accesses: 14
    byte _padding_0x90[12];
    byte field_0x9c; // accesses: 5
    byte _padding_0x9d[243];
    LocatedGmSurf * field_0x190; // accesses: 1
    int field_0x194; // accesses: 1
    byte _padding_0x198[52];
    CMwNod * field_0x1cc; // accesses: 1
};

struct CHmsConfig {
    byte _padding_0x0[8];
    int field_0x8; // accesses: 2
    byte _padding_0xc[8];
    undefined4 field_0x14; // accesses: 3
    undefined4 field_0x18; // accesses: 3
    undefined4 field_0x1c; // accesses: 1
};

struct CHmsCorpus {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    byte _padding_0xc[8];
    code * field_0x14; // accesses: 1
    code * field_0x18; // accesses: 3
    code * field_0x1c; // accesses: 1
    uint field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    byte _padding_0x2c[16];
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    CHmsCorpus * field_0x48; // accesses: 6
    void * field_0x4c; // accesses: 2
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    void * field_0x58; // accesses: 20
    byte _padding_0x5c[716];
    int field_0x328; // accesses: 1
    int field_0x32c; // accesses: 1
};

struct CHmsCorpusLight {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 2
    float field_0xc; // accesses: 1
    float field_0x10; // accesses: 1
    float field_0x14; // accesses: 3
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
};

struct CHmsDyna {
    byte _padding_0x0[4];
    SPredictionTypeVector * field_0x4; // accesses: 78
    SPredictionTypeVector * field_0x8; // accesses: 79
    float field_0xc; // accesses: 10
    float field_0x10; // accesses: 12
    float field_0x14; // accesses: 13
    float field_0x18; // accesses: 11
    float field_0x1c; // accesses: 7
    float field_0x20; // accesses: 7
    float field_0x24; // accesses: 6
    float field_0x28; // accesses: 5
    float field_0x2c; // accesses: 5
    float field_0x30; // accesses: 3
    float field_0x34; // accesses: 11
    float field_0x38; // accesses: 11
    float field_0x3c; // accesses: 11
    float field_0x40; // accesses: 8
    float field_0x44; // accesses: 8
    float field_0x48; // accesses: 10
    float field_0x4c; // accesses: 4
    float field_0x50; // accesses: 4
    float field_0x54; // accesses: 3
    float field_0x58; // accesses: 19
    float field_0x5c; // accesses: 19
    float field_0x60; // accesses: 20
    float field_0x64; // accesses: 8
    float field_0x68; // accesses: 8
    float field_0x6c; // accesses: 8
    float field_0x70; // accesses: 8
    float field_0x74; // accesses: 8
    float field_0x78; // accesses: 6
    byte _padding_0x7c[4];
    float field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 2
    undefined4 field_0x88; // accesses: 2
    undefined4 field_0x8c; // accesses: 2
    byte _padding_0x90[16];
    int field_0xa0; // accesses: 1
    byte _padding_0xa4[4];
    ulong field_0xa8; // accesses: 34
    int field_0xac; // accesses: 3
    int field_0xb0; // accesses: 4
    SHistoryPoint * field_0xb4; // accesses: 1
    SHistoryPoint * field_0xb8; // accesses: 1
    SHistoryPoint * field_0xbc; // accesses: 1
    SHistoryPoint * field_0xc0; // accesses: 1
    SHistoryPoint * field_0xc4; // accesses: 1
    byte _padding_0xc8[12];
    SHistoryPoint * field_0xd4; // accesses: 1
    SHistoryPoint * field_0xd8; // accesses: 1
    SHistoryPoint * field_0xdc; // accesses: 1
};

struct CHmsDyna_CHmsStateDyna {
    byte _padding_0x0[1];
    ushort field_0x1; // accesses: 1
    byte _padding_0x3[9];
    int field_0xc; // accesses: 1
    byte _padding_0x10[4];
    int field_0x14; // accesses: 1
};

struct CHmsEngine {
    byte _padding_0x0[32];
    undefined4 field_0x20; // accesses: 1
};

struct CHmsForceField {
    byte _padding_0x0[20];
    CHmsZone * field_0x14; // accesses: 5
    byte _padding_0x18[64];
    undefined4 field_0x58; // accesses: 1
};

struct CHmsForceFieldBall {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 2
    float field_0x8; // accesses: 1
    byte _padding_0xc[4];
    int field_0x10; // accesses: 1
    byte _padding_0x14[4];
    int field_0x18; // accesses: 3
    byte _padding_0x1c[32];
    float field_0x3c; // accesses: 1
    float field_0x40; // accesses: 1
    float field_0x44; // accesses: 1
    byte _padding_0x48[20];
    float field_0x5c; // accesses: 7
    float field_0x60; // accesses: 2
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1
    undefined4 field_0x78; // accesses: 1
};

struct CHmsForceFieldUniform {
    byte _padding_0x0[84];
    int field_0x54; // accesses: 1
    byte _padding_0x58[4];
    undefined4 field_0x5c; // accesses: 2
    undefined4 field_0x60; // accesses: 2
    undefined4 field_0x64; // accesses: 2
};

struct CHmsItem {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 56
    int field_0x8; // accesses: 11
    undefined4 field_0xc; // accesses: 6
    int * field_0x10; // accesses: 7
    CSceneToyMotorbike * field_0x14; // accesses: 21
    ulong field_0x18; // accesses: 116
    ushort field_0x1c; // accesses: 69
    byte _padding_0x1e[2];
    ushort field_0x20; // accesses: 28
    byte _padding_0x22[2];
    void * field_0x24; // accesses: 10
    byte _padding_0x28[4];
    int field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    SCasterCat * field_0x34; // accesses: 2
    byte _padding_0x38[8];
    undefined4 field_0x40; // accesses: 2
    undefined4 field_0x44; // accesses: 3
    int field_0x48; // accesses: 4
    int field_0x4c; // accesses: 4
    undefined4 field_0x50; // accesses: 1
    void * field_0x54; // accesses: 3
    int field_0x58; // accesses: 4
    byte _padding_0x5c[64];
    uint field_0x9c; // accesses: 12
};

struct CHmsLight {
    byte _padding_0x0[20];
    int field_0x14; // accesses: 1
    byte _padding_0x18[80];
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
    undefined4 field_0x70; // accesses: 5
    undefined4 field_0x74; // accesses: 1
    undefined4 field_0x78; // accesses: 1
    undefined4 field_0x7c; // accesses: 1
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
    undefined4 field_0x88; // accesses: 5
    undefined4 field_0x8c; // accesses: 9
};

struct CHmsPackLightMap {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    ulong field_0x8; // accesses: 2
    CHmsCorpus * field_0xc; // accesses: 2
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 2
    byte _padding_0x1c[4];
    int field_0x20; // accesses: 7
    int field_0x24; // accesses: 1
    int field_0x28; // accesses: 2
    undefined4 field_0x2c; // accesses: 4
    int field_0x30; // accesses: 1
    byte _padding_0x34[20];
    int field_0x48; // accesses: 7
    byte _padding_0x4c[12];
    int field_0x58; // accesses: 1
    byte _padding_0x5c[20];
    uint field_0x70; // accesses: 2
    byte _padding_0x74[328];
    int field_0x1bc; // accesses: 3
    byte _padding_0x1c0[4];
    int field_0x1c4; // accesses: 6
};

struct CHmsPicker {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 3
    undefined4 field_0x18; // accesses: 3
    void * field_0x1c; // accesses: 3
    void * field_0x20; // accesses: 3
    void * field_0x24; // accesses: 3
    void * field_0x28; // accesses: 3
    undefined4 field_0x2c; // accesses: 3
    undefined4 field_0x30; // accesses: 3
    undefined4 field_0x34; // accesses: 3
    undefined4 field_0x38; // accesses: 3
    undefined4 field_0x3c; // accesses: 3
    undefined4 field_0x40; // accesses: 3
    undefined4 field_0x44; // accesses: 3
    undefined4 field_0x48; // accesses: 3
    undefined4 field_0x4c; // accesses: 3
    undefined4 field_0x50; // accesses: 3
    undefined4 field_0x54; // accesses: 3
    undefined4 field_0x58; // accesses: 3
    undefined4 field_0x5c; // accesses: 3
    undefined4 field_0x60; // accesses: 3
    undefined4 field_0x64; // accesses: 3
    undefined4 field_0x68; // accesses: 3
    undefined4 field_0x6c; // accesses: 3
    undefined4 field_0x70; // accesses: 3
    undefined4 field_0x74; // accesses: 3
    undefined4 field_0x78; // accesses: 3
    undefined4 field_0x7c; // accesses: 3
    undefined4 field_0x80; // accesses: 3
    undefined4 field_0x84; // accesses: 3
    undefined4 field_0x88; // accesses: 3
    undefined4 field_0x8c; // accesses: 1
    undefined4 field_0x90; // accesses: 1
    undefined4 field_0x94; // accesses: 1
    byte _padding_0x98[48];
    undefined4 field_0xc8; // accesses: 3
    undefined4 field_0xcc; // accesses: 3
    void * field_0xd0; // accesses: 3
    undefined4 field_0xd4; // accesses: 3
    undefined4 field_0xd8; // accesses: 3
    undefined4 field_0xdc; // accesses: 3
    undefined4 field_0xe0; // accesses: 1
    undefined4 field_0xe4; // accesses: 1
};

struct CHmsPoc {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 1
    byte _padding_0x8[8];
    int field_0x10; // accesses: 1
    byte _padding_0x14[4];
    int field_0x18; // accesses: 3
    byte _padding_0x1c[44];
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    int field_0x54; // accesses: 3
};

struct CHmsPortal {
    byte _padding_0x0[12];
    float field_0xc; // accesses: 2
    byte _padding_0x10[4];
    undefined4 field_0x14; // accesses: 1
    float field_0x18; // accesses: 2
    undefined4 field_0x1c; // accesses: 3
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    byte _padding_0x6c[12];
    int * field_0x78; // accesses: 5
    SPlugFaceCull * field_0x7c; // accesses: 6
    undefined4 field_0x80; // accesses: 3
    CPlugTree * field_0x84; // accesses: 12
    CPlugVisual * field_0x88; // accesses: 24
    byte _padding_0x8c[4];
    float field_0x90; // accesses: 1
    float field_0x94; // accesses: 1
    float field_0x98; // accesses: 1
    float field_0x9c; // accesses: 1
    float field_0xa0; // accesses: 5
    float field_0xa4; // accesses: 1
    float field_0xa8; // accesses: 1
    float field_0xac; // accesses: 1
    float field_0xb0; // accesses: 4
    float field_0xb4; // accesses: 4
    float field_0xb8; // accesses: 4
    float field_0xbc; // accesses: 2
    float field_0xc0; // accesses: 2
    float field_0xc4; // accesses: 2
    float field_0xc8; // accesses: 2
    byte _padding_0xcc[48];
    undefined4 field_0xfc; // accesses: 6
    float field_0x100; // accesses: 7
    float field_0x104; // accesses: 7
};

struct CHmsShadowGroup {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1
    undefined4 field_0x78; // accesses: 1
    undefined4 field_0x7c; // accesses: 1
    undefined4 field_0x80; // accesses: 1
};

struct CHmsSoundSource {
    byte _padding_0x0[84];
    int field_0x54; // accesses: 1
    byte _padding_0x58[24];
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1
    undefined4 field_0x78; // accesses: 1
    undefined4 field_0x7c; // accesses: 1
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
    undefined4 field_0x88; // accesses: 1
    undefined4 field_0x8c; // accesses: 1
    undefined4 field_0x90; // accesses: 1
    int field_0x94; // accesses: 1
    byte _padding_0x98[8];
    int field_0xa0; // accesses: 1
};

struct CHmsVPackerCell {
    byte _padding_0x0[4];
    CPlugTreeVisualMip * field_0x4; // accesses: 4
    CPlugTree * field_0x8; // accesses: 4
    byte _padding_0xc[8];
    int field_0x14; // accesses: 2
    byte _padding_0x18[52];
    undefined4 field_0x4c; // accesses: 1
    byte _padding_0x50[8];
    CHmsZoneVPacker * field_0x58; // accesses: 6
    GmBoxAligned * field_0x5c; // accesses: 1
    CHmsVPackerCell * field_0x60; // accesses: 1
    ulong * field_0x64; // accesses: 1
    byte _padding_0x68[44];
    int field_0x94; // accesses: 1
};

struct CHmsViewport {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 15
    float field_0x8; // accesses: 9
    float field_0xc; // accesses: 6
    float field_0x10; // accesses: 9
    float field_0x14; // accesses: 11
    int field_0x18; // accesses: 6
    int field_0x1c; // accesses: 11
    float field_0x20; // accesses: 6
    float field_0x24; // accesses: 9
    float field_0x28; // accesses: 4
    float field_0x2c; // accesses: 5
    float field_0x30; // accesses: 3
    undefined4 field_0x34; // accesses: 1
    float field_0x38; // accesses: 5
    float field_0x3c; // accesses: 5
    float field_0x40; // accesses: 13
    float field_0x44; // accesses: 14
    float field_0x48; // accesses: 18
    int field_0x4c; // accesses: 2
    undefined4 field_0x50; // accesses: 1
    float field_0x54; // accesses: 4
    float field_0x58; // accesses: 2
    float field_0x5c; // accesses: 3
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1
    undefined4 field_0x78; // accesses: 1
    undefined4 field_0x7c; // accesses: 2
    undefined4 field_0x80; // accesses: 1
    CPlugTree * field_0x84; // accesses: 5
    undefined4 field_0x88; // accesses: 1
    int field_0x8c; // accesses: 1
    int field_0x90; // accesses: 2
    float field_0x94; // accesses: 4
    byte _padding_0x98[4];
    undefined4 field_0x9c; // accesses: 11
    undefined4 field_0xa0; // accesses: 19
    undefined4 field_0xa4; // accesses: 1
    undefined4 field_0xa8; // accesses: 1
    undefined4 field_0xac; // accesses: 1
    undefined4 field_0xb0; // accesses: 1
    byte _padding_0xb4[12];
    float field_0xc0; // accesses: 2
    float field_0xc4; // accesses: 2
    float field_0xc8; // accesses: 2
    uint field_0xcc; // accesses: 4
    byte _padding_0xd0[4];
    code * field_0xd4; // accesses: 1
    byte _padding_0xd8[56];
    undefined4 field_0x110; // accesses: 1
    undefined4 field_0x114; // accesses: 1
    undefined4 field_0x118; // accesses: 1
    byte _padding_0x11c[4];
    undefined4 field_0x120; // accesses: 1
    undefined4 field_0x124; // accesses: 1
    undefined * field_0x128; // accesses: 1
    undefined4 field_0x12c; // accesses: 1
    undefined4 field_0x130; // accesses: 1
    undefined4 field_0x134; // accesses: 1
    undefined4 field_0x138; // accesses: 1
    undefined4 field_0x13c; // accesses: 1
    undefined4 field_0x140; // accesses: 1
    undefined4 field_0x144; // accesses: 1
    undefined4 field_0x148; // accesses: 1
    undefined4 field_0x14c; // accesses: 1
    undefined4 field_0x150; // accesses: 1
    undefined4 field_0x154; // accesses: 1
    undefined4 field_0x158; // accesses: 1
    undefined * field_0x15c; // accesses: 1
    undefined4 field_0x160; // accesses: 1
    byte _padding_0x164[168];
    undefined4 field_0x20c; // accesses: 1
    byte _padding_0x210[4];
    undefined4 field_0x214; // accesses: 1
    undefined4 field_0x218; // accesses: 1
    byte _padding_0x21c[16];
    undefined4 field_0x22c; // accesses: 1
    int field_0x230; // accesses: 1
    undefined4 field_0x234; // accesses: 5
    void * field_0x238; // accesses: 6
    undefined4 field_0x23c; // accesses: 1
    int field_0x240; // accesses: 2
    CHmsConfig * field_0x244; // accesses: 2
    undefined4 field_0x248; // accesses: 1
    undefined4 field_0x24c; // accesses: 1
    undefined4 field_0x250; // accesses: 1
    undefined4 field_0x254; // accesses: 1
    undefined4 field_0x258; // accesses: 1
    CMwCmd * field_0x25c; // accesses: 2
    undefined4 field_0x260; // accesses: 1
    byte _padding_0x264[36];
    undefined4 field_0x288; // accesses: 1
    undefined4 field_0x28c; // accesses: 1
    undefined4 field_0x290; // accesses: 1
    byte _padding_0x294[8];
    int field_0x29c; // accesses: 1
    byte _padding_0x2a0[4];
    int field_0x2a4; // accesses: 8
    int field_0x2a8; // accesses: 8
    byte _padding_0x2ac[72];
    int field_0x2f4; // accesses: 1
    byte _padding_0x2f8[36];
    undefined4 * field_0x31c; // accesses: 9
    undefined4 field_0x320; // accesses: 1
    undefined4 field_0x324; // accesses: 1
    undefined4 field_0x328; // accesses: 1
    undefined4 field_0x32c; // accesses: 1
    undefined4 field_0x330; // accesses: 1
    undefined4 field_0x334; // accesses: 1
    undefined4 field_0x338; // accesses: 1
    ulong field_0x33c; // accesses: 3
    byte _padding_0x340[8];
    undefined4 field_0x348; // accesses: 1
    int field_0x34c; // accesses: 3
    int field_0x350; // accesses: 1
    undefined4 field_0x354; // accesses: 1
    undefined4 field_0x358; // accesses: 8
    undefined4 field_0x35c; // accesses: 12
    byte _padding_0x360[36];
    undefined2 field_0x384; // accesses: 3
    undefined2 field_0x386; // accesses: 2
    undefined2 field_0x388; // accesses: 1
    undefined2 field_0x38a; // accesses: 1
    CHmsCorpus * field_0x38c; // accesses: 20
    byte _padding_0x390[36];
    ulong field_0x3b4; // accesses: 4
    undefined4 field_0x3b8; // accesses: 1
    undefined4 field_0x3bc; // accesses: 1
    int field_0x3c0; // accesses: 5
    byte _padding_0x3c4[80];
    undefined4 field_0x414; // accesses: 4
    int field_0x418; // accesses: 3
    int field_0x41c; // accesses: 2
    undefined4 field_0x420; // accesses: 1
    undefined4 field_0x424; // accesses: 1
    undefined4 field_0x428; // accesses: 1
    undefined4 field_0x42c; // accesses: 1
    undefined4 field_0x430; // accesses: 12
    undefined4 field_0x434; // accesses: 1
    undefined4 field_0x438; // accesses: 1
    byte _padding_0x43c[12];
    int field_0x448; // accesses: 4
    undefined4 field_0x44c; // accesses: 1
    undefined4 field_0x450; // accesses: 1
    byte _padding_0x454[224];
    undefined4 field_0x534; // accesses: 1
    byte _padding_0x538[12];
    undefined4 field_0x544; // accesses: 1
    undefined4 field_0x548; // accesses: 1
    undefined4 field_0x54c; // accesses: 1
    undefined4 field_0x550; // accesses: 1
    undefined4 field_0x554; // accesses: 1
    undefined4 field_0x558; // accesses: 1
};

struct CHmsZone {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 77
    ulong field_0x8; // accesses: 2
    byte _padding_0xc[4];
    int field_0x10; // accesses: 4
    CHmsZone * field_0x14; // accesses: 10
    int field_0x18; // accesses: 16
    byte _padding_0x1c[4];
    int field_0x20; // accesses: 2
    byte _padding_0x24[8];
    int field_0x2c; // accesses: 2
    int field_0x30; // accesses: 2
    byte _padding_0x34[20];
    int field_0x48; // accesses: 4
    int field_0x4c; // accesses: 5
    int field_0x50; // accesses: 3
    ulong field_0x54; // accesses: 3
    byte _padding_0x58[20];
    int field_0x6c; // accesses: 6
    int field_0x70; // accesses: 3
    byte _padding_0x74[20];
    int * field_0x88; // accesses: 3
    byte field_0x8c; // accesses: 2
    byte _padding_0x8d[7];
    undefined4 field_0x94; // accesses: 1
    undefined4 field_0x98; // accesses: 1
    undefined4 field_0x9c; // accesses: 1
    undefined4 field_0xa0; // accesses: 2
    undefined4 field_0xa4; // accesses: 2
    undefined4 field_0xa8; // accesses: 2
    undefined4 field_0xac; // accesses: 13
    int field_0xb0; // accesses: 8
    undefined4 field_0xb4; // accesses: 2
    int field_0xb8; // accesses: 3
    int field_0xbc; // accesses: 2
    undefined4 field_0xc0; // accesses: 1
    int field_0xc4; // accesses: 6
    int field_0xc8; // accesses: 3
    undefined4 field_0xcc; // accesses: 1
    undefined4 field_0xd0; // accesses: 1
    float field_0xd4; // accesses: 6
    float field_0xd8; // accesses: 6
    byte _padding_0xdc[12];
    undefined4 field_0xe8; // accesses: 3
    ushort field_0xec; // accesses: 43
    ushort field_0xee; // accesses: 43
    ushort field_0xf0; // accesses: 43
    ushort field_0xf2; // accesses: 43
    byte _padding_0xf4[12];
    int field_0x100; // accesses: 6
    undefined4 * field_0x104; // accesses: 42
    float field_0x108; // accesses: 6
    byte _padding_0x10c[12];
    undefined4 * field_0x118; // accesses: 3
};

struct CHmsZoneDynamic {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 3
    float field_0x8; // accesses: 9
    float field_0xc; // accesses: 5
    float field_0x10; // accesses: 2
    void * field_0x14; // accesses: 9
    float field_0x18; // accesses: 6
    float field_0x1c; // accesses: 8
    float field_0x20; // accesses: 8
    float field_0x24; // accesses: 13
    float field_0x28; // accesses: 9
    float field_0x2c; // accesses: 11
    float field_0x30; // accesses: 4
    float field_0x34; // accesses: 12
    ushort field_0x36; // accesses: 4
    float field_0x38; // accesses: 8
    int field_0x3c; // accesses: 4
    byte _padding_0x40[8];
    ulong field_0x48; // accesses: 22
    byte _padding_0x4c[12];
    void * field_0x58; // accesses: 11
    byte _padding_0x5c[172];
    float * field_0x108; // accesses: 2
    byte _padding_0x10c[16];
    float field_0x11c; // accesses: 1
    float field_0x120; // accesses: 1
    byte _padding_0x124[16];
    int * field_0x134; // accesses: 4
    int * field_0x138; // accesses: 3
    byte _padding_0x13c[28];
    int field_0x158; // accesses: 1
    byte _padding_0x15c[12];
    void * field_0x168; // accesses: 10
    byte _padding_0x16c[448];
    int field_0x32c; // accesses: 3
    byte _padding_0x330[16];
    int field_0x340; // accesses: 1
};

struct CHmsZoneElem {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
};

struct CHmsZoneOverlay {
    byte _padding_0x0[24];
    undefined4 field_0x18; // accesses: 1
    byte _padding_0x1c[284];
    undefined4 field_0x138; // accesses: 1
    undefined4 field_0x13c; // accesses: 1
    undefined4 field_0x140; // accesses: 1
    undefined4 field_0x144; // accesses: 1
    undefined4 field_0x148; // accesses: 1
    undefined4 field_0x14c; // accesses: 1
    undefined4 field_0x150; // accesses: 1
    undefined4 field_0x154; // accesses: 1
    undefined4 field_0x158; // accesses: 1
    undefined4 field_0x15c; // accesses: 1
    undefined4 field_0x160; // accesses: 1
    undefined4 field_0x164; // accesses: 1
    undefined4 field_0x168; // accesses: 1
    undefined4 field_0x16c; // accesses: 1
    undefined4 field_0x170; // accesses: 1
};

struct CHmsZoneVPacker {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 13
    undefined4 field_0x8; // accesses: 5
    int field_0xc; // accesses: 7
    int field_0x10; // accesses: 12
    float field_0x14; // accesses: 11
    float field_0x18; // accesses: 8
    float field_0x1c; // accesses: 10
    ushort field_0x20; // accesses: 2
    byte _padding_0x22[2];
    int * field_0x24; // accesses: 5
    undefined4 field_0x28; // accesses: 2
    undefined4 field_0x2c; // accesses: 2
    undefined4 field_0x30; // accesses: 1
    byte _padding_0x34[20];
    int field_0x48; // accesses: 5
    int field_0x4c; // accesses: 2
    byte _padding_0x50[8];
    int field_0x58; // accesses: 4
    byte _padding_0x5c[4];
    void * field_0x60; // accesses: 6
    byte _padding_0x64[8];
    int field_0x6c; // accesses: 2
    byte _padding_0x70[4];
    undefined4 field_0x74; // accesses: 2
    undefined4 field_0x78; // accesses: 2
    undefined4 field_0x7c; // accesses: 2
    float field_0x80; // accesses: 6
    undefined1 * field_0x84; // accesses: 1
    byte _padding_0x85[3];
    undefined4 field_0x88; // accesses: 1
    byte _padding_0x8c[16];
    ushort field_0x9c; // accesses: 1
    ushort field_0x9e; // accesses: 1
    byte _padding_0xa0[36];
    undefined4 field_0xc4; // accesses: 1
    undefined4 field_0xc8; // accesses: 1
    undefined4 field_0xcc; // accesses: 1
    undefined4 field_0xd0; // accesses: 1
    undefined4 field_0xd4; // accesses: 1
    undefined4 field_0xd8; // accesses: 1
    undefined4 field_0xdc; // accesses: 1
    undefined4 field_0xe0; // accesses: 1
    CSceneSector * field_0xe4; // accesses: 3
    CHmsCorpus * field_0xe8; // accesses: 2
    int * field_0xec; // accesses: 8
    CHmsZoneVPacker * field_0xf0; // accesses: 13
    undefined4 field_0xf4; // accesses: 4
    undefined4 field_0xf8; // accesses: 27
    byte _padding_0xfc[40];
    float field_0x124; // accesses: 4
    byte _padding_0x128[96];
    void * field_0x188; // accesses: 3
    void * field_0x18c; // accesses: 3
    void * field_0x190; // accesses: 2
    void * field_0x194; // accesses: 3
    void * field_0x198; // accesses: 3
    byte _padding_0x19c[4];
    uint * field_0x1a0; // accesses: 5
    int field_0x1a4; // accesses: 2
};

struct CHmsZone_CVisionData {
    byte _padding_0x0[47];
    byte field_0x2f; // accesses: 2
    byte _padding_0x30[3];
    uint field_0x33; // accesses: 1
};

struct CInputBindingsConfig {
    byte _padding_0x0[4];
    ulong field_0x4; // accesses: 5
    undefined4 field_0x8; // accesses: 2
    byte _padding_0xc[56];
    undefined4 field_0x44; // accesses: 1
    undefined * field_0x48; // accesses: 1
    ulong field_0x4c; // accesses: 2
};

struct CInputDevice {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 3
    float field_0x8; // accesses: 3
};

struct CInputEngine {
    byte _padding_0x0[32];
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
};

struct CInputEventsStore {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 8
    undefined4 field_0x8; // accesses: 1
};

struct CInputPort {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 9
    byte _padding_0x8[12];
    void * field_0x14; // accesses: 2
    byte _padding_0x18[8];
    int field_0x20; // accesses: 6
    byte _padding_0x24[4];
    float field_0x28; // accesses: 1
    byte _padding_0x2c[8];
    int field_0x34; // accesses: 1
    ulong field_0x38; // accesses: 3
    byte _padding_0x3c[80];
    int field_0x8c; // accesses: 4
    int field_0x90; // accesses: 5
    int field_0x94; // accesses: 1
    int field_0x98; // accesses: 3
    byte _padding_0x9c[44];
    ulong field_0xc8; // accesses: 1
};

struct CInputPortDx8 {
    byte _padding_0x0[12];
    uint field_0xc; // accesses: 1
    byte _padding_0x10[4];
    void * field_0x14; // accesses: 2
    int field_0x18; // accesses: 1
    int field_0x1c; // accesses: 1
    int field_0x20; // accesses: 3
    byte _padding_0x24[16];
    int field_0x34; // accesses: 2
    SInputEvent * field_0x38; // accesses: 1
    byte _padding_0x3c[84];
    int field_0x90; // accesses: 1
    int field_0x94; // accesses: 1
    byte _padding_0x98[4];
    int field_0x9c; // accesses: 1
    byte _padding_0xa0[48];
    int field_0xd0; // accesses: 1
    byte _padding_0xd4[20];
    int field_0xe8; // accesses: 1
    byte _padding_0xec[8];
    uint field_0xf4; // accesses: 3
};

struct CLoadGeomVertexGen_2113 {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 2
};

struct CLoadGeomVertexGen_671098945 {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 4
    undefined4 field_0x8; // accesses: 2
};

struct CMotionCmdBase {
    byte _padding_0x0[20];
    void * field_0x14; // accesses: 2
    byte _padding_0x18[4];
    int field_0x1c; // accesses: 2
    undefined4 field_0x20; // accesses: 3
    CMotionCmdBase * field_0x24; // accesses: 1
    void * field_0x28; // accesses: 5
    float field_0x2c; // accesses: 7
    undefined4 field_0x30; // accesses: 1
    float field_0x34; // accesses: 2
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 2
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    int field_0x48; // accesses: 2
    undefined4 field_0x4c; // accesses: 1
};

struct CMotionDayTime {
    byte _padding_0x0[20];
    uint field_0x14; // accesses: 2
    byte _padding_0x18[12];
    int field_0x24; // accesses: 3
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    byte _padding_0x30[104];
    CPlugMaterial * field_0x98; // accesses: 1
    uint field_0x9c; // accesses: 4
};

struct CMotionEmitterLeaves {
    byte _padding_0x0[8];
    short field_0x8; // accesses: 1
    byte _padding_0xa[26];
    undefined4 field_0x24; // accesses: 1
};

struct CMotionEmitterParticles {
    byte _padding_0x0[124];
    undefined4 field_0x7c; // accesses: 1
    undefined4 field_0x80; // accesses: 2
    undefined4 field_0x84; // accesses: 1
    undefined4 field_0x88; // accesses: 5
    CSceneObjectLink * field_0x8c; // accesses: 2
};

struct CMotionEngine {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    byte _padding_0x18[4];
    undefined4 field_0x1c; // accesses: 1
    byte _padding_0x20[16];
    CMotionCmdBase * field_0x30; // accesses: 4
};

struct CMotionLight {
    byte _padding_0x0[44];
    GxLight * field_0x2c; // accesses: 4
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
};

struct CMotionManaged {
    byte _padding_0x0[20];
    int field_0x14; // accesses: 1
    CMotionManager * field_0x18; // accesses: 10
    undefined4 field_0x1c; // accesses: 1
    CMotionManager * field_0x20; // accesses: 9
    byte _padding_0x24[96];
    code * field_0x84; // accesses: 1
};

struct CMotionManagerMeteo {
    byte _padding_0x0[28];
    CSystemFileMemMapped * field_0x1c; // accesses: 2
    int field_0x20; // accesses: 2
    byte _padding_0x24[8];
    int field_0x2c; // accesses: 1
    byte _padding_0x30[132];
    float field_0xb4; // accesses: 1
    byte _padding_0xb8[56];
    float field_0xf0; // accesses: 1
    byte _padding_0xf4[56];
    CMotionManagerMeteoPuffLull * field_0x12c; // accesses: 2
};

struct CMotionManagerMeteoPuffLull {
    byte _padding_0x0[24];
    CFuncPuffLull * field_0x18; // accesses: 1
};

struct CMotionManagerParticles {
    byte _padding_0x0[4];
    float * field_0x4; // accesses: 53
    undefined4 field_0x8; // accesses: 42
    SPart * field_0xc; // accesses: 24
    int field_0x10; // accesses: 2
    ulong field_0x14; // accesses: 17
    ulong field_0x18; // accesses: 16
    ulong field_0x1c; // accesses: 15
    ulong * field_0x20; // accesses: 15
    float field_0x24; // accesses: 18
    float field_0x28; // accesses: 6
    float field_0x2c; // accesses: 7
    float field_0x30; // accesses: 5
    int field_0x34; // accesses: 10
    float field_0x38; // accesses: 13
    float field_0x3c; // accesses: 17
    float field_0x40; // accesses: 10
    undefined4 field_0x44; // accesses: 2
    undefined4 field_0x48; // accesses: 2
    byte _padding_0x4c[4];
    float field_0x50; // accesses: 3
    byte _padding_0x54[4];
    float field_0x58; // accesses: 2
    float field_0x5c; // accesses: 3
    float field_0x60; // accesses: 3
    float field_0x64; // accesses: 1
    byte _padding_0x68[4];
    float field_0x6c; // accesses: 1
    float field_0x70; // accesses: 2
    float field_0x74; // accesses: 1
    byte _padding_0x78[4];
    ulong field_0x7c; // accesses: 5
    SPartGroup * field_0x80; // accesses: 10
    float field_0x84; // accesses: 5
    int field_0x88; // accesses: 5
    undefined4 field_0x8c; // accesses: 4
    float field_0x90; // accesses: 4
    byte _padding_0x94[4];
    int field_0x98; // accesses: 5
    uint field_0x9c; // accesses: 7
    byte _padding_0xa0[4];
    undefined4 field_0xa4; // accesses: 2
    undefined4 field_0xa8; // accesses: 2
    byte _padding_0xac[16];
    float field_0xbc; // accesses: 1
    float field_0xc0; // accesses: 1
    byte _padding_0xc4[136];
    int field_0x14c; // accesses: 1
};

struct CMotionManagerWeathers {
    byte _padding_0x0[2];
    ushort field_0x2; // accesses: 1
    byte _padding_0x4[12];
    undefined4 field_0x10; // accesses: 2
    int * field_0x14; // accesses: 3
    byte _padding_0x18[4];
    CMotionTimerLoop * field_0x1c; // accesses: 2
    CMwCmdScriptVarBool * field_0x20; // accesses: 1
    float field_0x24; // accesses: 5
    float field_0x28; // accesses: 6
    float field_0x2c; // accesses: 7
    float field_0x30; // accesses: 2
    float field_0x34; // accesses: 3
    float field_0x38; // accesses: 5
    float field_0x3c; // accesses: 3
    float field_0x40; // accesses: 3
    float field_0x44; // accesses: 2
    undefined4 field_0x48; // accesses: 4
    float field_0x4c; // accesses: 2
    float field_0x50; // accesses: 2
    float field_0x54; // accesses: 1
    float field_0x58; // accesses: 1
    float field_0x5c; // accesses: 1
    float field_0x60; // accesses: 3
    byte _padding_0x64[4];
    GxFogBlender * field_0x68; // accesses: 2
    byte _padding_0x6c[4];
    CMotionManagerWeathers * field_0x70; // accesses: 6
    byte _padding_0x74[12];
    float field_0x80; // accesses: 1
    float field_0x84; // accesses: 1
    float field_0x88; // accesses: 1
    int field_0x8c; // accesses: 1
    int field_0x90; // accesses: 1
    undefined4 field_0x94; // accesses: 2
    CPlugMaterial * field_0x98; // accesses: 2
    undefined4 field_0x9c; // accesses: 4
    int field_0xa0; // accesses: 2
    byte _padding_0xa4[4];
    int field_0xa8; // accesses: 2
    uint field_0xac; // accesses: 7
    float field_0xb0; // accesses: 7
    CFuncWeather * field_0xb4; // accesses: 13
    CPlugFileImg * field_0xb8; // accesses: 15
    CSystemFid * field_0xbc; // accesses: 6
    CSystemFid * field_0xc0; // accesses: 4
    GxLight * field_0xc4; // accesses: 32
    CSceneLight * field_0xc8; // accesses: 7
    byte _padding_0xcc[4];
    undefined4 field_0xd0; // accesses: 1
    float field_0xd4; // accesses: 1
    float field_0xd8; // accesses: 1
    float field_0xdc; // accesses: 1
    float field_0xe0; // accesses: 1
    int field_0xe4; // accesses: 8
    byte _padding_0xe8[4];
    float * field_0xec; // accesses: 3
    void * field_0xf0; // accesses: 12
    int field_0xf4; // accesses: 2
    uint field_0xf8; // accesses: 3
    CPlugShader * field_0xfc; // accesses: 14
    int field_0x100; // accesses: 4
    CHmsZoneVPacker * field_0x104; // accesses: 6
    int field_0x108; // accesses: 3
    int field_0x10c; // accesses: 2
    int field_0x110; // accesses: 1
    int field_0x114; // accesses: 2
    undefined4 field_0x118; // accesses: 2
    undefined4 field_0x11c; // accesses: 2
    undefined4 field_0x120; // accesses: 2
    undefined4 field_0x124; // accesses: 1
    byte _padding_0x128[32];
    undefined4 field_0x148; // accesses: 1
    undefined4 field_0x14c; // accesses: 2
    undefined4 field_0x150; // accesses: 2
    undefined4 field_0x154; // accesses: 1
    CSceneFxNod * field_0x158; // accesses: 1
    byte _padding_0x15c[20];
    int field_0x170; // accesses: 1
};

struct CMotionParticleType {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 4
    float field_0x8; // accesses: 4
    byte _padding_0xc[24];
    int field_0x24; // accesses: 1
    byte _padding_0x28[288];
    ulong field_0x148; // accesses: 1
    byte _padding_0x14c[4];
    float field_0x150; // accesses: 1
    float field_0x154; // accesses: 1
    byte _padding_0x158[16];
    float field_0x168; // accesses: 1
    float field_0x16c; // accesses: 1
};

struct CMotionPath {
    byte _padding_0x0[44];
    undefined4 field_0x2c; // accesses: 1
    int field_0x30; // accesses: 2
    int field_0x34; // accesses: 2
    CMotionPath * field_0x38; // accesses: 5
    undefined4 field_0x3c; // accesses: 3
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
};

struct CMotionPlayer {
    byte _padding_0x0[24];
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    int * field_0x20; // accesses: 5
    undefined4 field_0x24; // accesses: 1
    ulong field_0x28; // accesses: 6
    undefined4 field_0x2c; // accesses: 1
    CTrackManiaEditorIcon * field_0x30; // accesses: 8
    CMwCmd * field_0x34; // accesses: 2
    undefined4 field_0x38; // accesses: 1
    byte _padding_0x3c[12];
    int field_0x48; // accesses: 2
    undefined4 field_0x4c; // accesses: 1
};

struct CMotionShader {
    byte _padding_0x0[44];
    CPlugMaterial * field_0x2c; // accesses: 5
    CPlugShader * field_0x30; // accesses: 3
    byte _padding_0x34[4];
    undefined4 * field_0x38; // accesses: 6
};

struct CMotionSkel {
    byte _padding_0x0[64];
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
};

struct CMotionSkelBlender {
    byte _padding_0x0[20];
    CMwCmd * field_0x14; // accesses: 2
};

struct CMotionSkelSimple {
    byte _padding_0x0[44];
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
};

struct CMotionTimerLoop {
    byte _padding_0x0[24];
    int field_0x18; // accesses: 2
    byte _padding_0x1c[4];
    int field_0x20; // accesses: 2
};

struct CMotionTrack {
    byte _padding_0x0[36];
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
};

struct CMotionTrackMobilMove {
    byte _padding_0x0[44];
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    byte _padding_0x34[48];
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1
};

struct CMotionTrackMobilPitchin {
    byte _padding_0x0[8];
    float field_0x8; // accesses: 1
    float field_0xc; // accesses: 1
    byte _padding_0x10[4];
    CPlugAudio * field_0x14; // accesses: 1
    byte _padding_0x18[12];
    undefined4 field_0x24; // accesses: 1
    float field_0x28; // accesses: 2
    undefined4 field_0x2c; // accesses: 1
    byte _padding_0x30[36];
    float field_0x54; // accesses: 2
    byte _padding_0x58[12];
    float field_0x64; // accesses: 4
    float field_0x68; // accesses: 4
    float field_0x6c; // accesses: 3
    undefined4 field_0x70; // accesses: 2
    float field_0x74; // accesses: 2
    undefined4 field_0x78; // accesses: 2
    undefined4 field_0x7c; // accesses: 2
    float field_0x80; // accesses: 2
    undefined4 field_0x84; // accesses: 2
    GmMat2 * field_0x88; // accesses: 1
    float field_0x8c; // accesses: 2
    byte _padding_0x90[20];
    float field_0xa4; // accesses: 4
    float field_0xa8; // accesses: 1
    float field_0xac; // accesses: 3
    float field_0xb0; // accesses: 3
    uint field_0xb4; // accesses: 2
};

struct CMotionTrackTree {
    byte _padding_0x0[44];
    undefined4 field_0x2c; // accesses: 1
    CPlugTree * field_0x30; // accesses: 4
    undefined4 field_0x34; // accesses: 1
    CMwCmd * field_0x38; // accesses: 3
};

struct CMotionTrackVisual {
    byte _padding_0x0[44];
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
};

struct CMotionWeather {
    byte _padding_0x0[24];
    CSceneToySea * field_0x18; // accesses: 2
    byte _padding_0x1c[20];
    int field_0x30; // accesses: 3
    int field_0x34; // accesses: 10
    byte _padding_0x38[28];
    CSceneMobilClouds * field_0x54; // accesses: 4
    byte _padding_0x58[24];
    undefined4 field_0x70; // accesses: 1
    byte _padding_0x74[32];
    CSceneToySea * field_0x94; // accesses: 1
    byte _padding_0x98[4];
    int field_0x9c; // accesses: 1
    int field_0xa0; // accesses: 1
    byte _padding_0xa4[64];
    int field_0xe4; // accesses: 2
};

struct CMotions {
    byte _padding_0x0[32];
    CMotionTrack * field_0x20; // accesses: 3
    byte _padding_0x24[12];
    CMotionCmdBase * field_0x30; // accesses: 1
};

struct CMultiArray_class_GmVec3 {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
};

struct CMwClassInfo {
    byte _padding_0x0[1];
    byte field_0x1; // accesses: 1
    byte _padding_0x2[2];
    int field_0x4; // accesses: 2
    CMwClassInfo * field_0x8; // accesses: 3
    byte _padding_0xc[8];
    char * field_0x14; // accesses: 1
    byte _padding_0x15[3];
    CMwClassInfo * field_0x18; // accesses: 2
    byte _padding_0x1c[4];
    int field_0x20; // accesses: 1
    uint field_0x24; // accesses: 1
};

struct CMwClassInfoCSceneVehicleCar {
    byte _padding_0x0[8];
    int field_0x8; // accesses: 7
    byte _padding_0xc[12];
    code * field_0x18; // accesses: 1
};

struct CMwCmd {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 3
    uint field_0x18; // accesses: 2
};

struct CMwCmdBlock {
    byte _padding_0x0[68];
    int field_0x44; // accesses: 8
    uint field_0x48; // accesses: 7
    byte _padding_0x4c[72];
    code * field_0x94; // accesses: 1
};

struct CMwCmdBlockMain {
    byte _padding_0x0[20];
    CPlugAudio * field_0x14; // accesses: 1
    byte _padding_0x18[48];
    uint field_0x48; // accesses: 4
    byte _padding_0x4c[32];
    CMwCmd * field_0x6c; // accesses: 3
    undefined4 * field_0x70; // accesses: 3
};

struct CMwCmdBuffer {
    byte _padding_0x0[4];
    ulong field_0x4; // accesses: 6
    byte _padding_0x8[8];
    int field_0x10; // accesses: 1
    int field_0x14; // accesses: 7
    CMwCmd * field_0x18; // accesses: 12
    int field_0x1c; // accesses: 9
    byte _padding_0x20[36];
    int field_0x44; // accesses: 4
};

struct CMwCmdBufferCore {
    byte _padding_0x0[4];
    ulong field_0x4; // accesses: 5
    byte field_0x6; // accesses: 1
    byte _padding_0x7[9];
    int field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 2
    int field_0x18; // accesses: 7
    _func___cdecl_void * field_0x1c; // accesses: 2
    _func___cdecl_void * field_0x20; // accesses: 2
    byte _padding_0x24[8];
    CMwCmdBuffer * field_0x2c; // accesses: 10
    int field_0x30; // accesses: 7
    int field_0x34; // accesses: 5
    int field_0x38; // accesses: 5
    ulong field_0x3c; // accesses: 6
    int field_0x40; // accesses: 6
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    byte _padding_0x54[4];
    undefined4 field_0x58; // accesses: 5
    int field_0x5c; // accesses: 4
    int field_0x60; // accesses: 6
    CMwCmdBufferCore * field_0x64; // accesses: 5
    int field_0x68; // accesses: 4
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
};

struct CMwCmdContainer {
    byte _padding_0x0[32];
    int field_0x20; // accesses: 2
};

struct CMwCmdFastCall {
    byte _padding_0x0[28];
    _func___cdecl_void * field_0x1c; // accesses: 1
    CMwNod * field_0x20; // accesses: 1
};

struct CMwCmdFastCallUser {
    byte _padding_0x0[28];
    _func___cdecl_void_ulong * field_0x1c; // accesses: 1
    CMwNod * field_0x20; // accesses: 1
    ulong field_0x24; // accesses: 1
};

struct CMwEngine {
    byte _padding_0x0[24];
    uint * field_0x18; // accesses: 2
    undefined4 field_0x1c; // accesses: 2
};

struct CMwEngineInfo {
    byte _padding_0x0[4];
    uint field_0x4; // accesses: 1
};

struct CMwEngineManager {
    byte _padding_0x0[4];
    uint field_0x4; // accesses: 2
};

struct CMwNod {
    byte _padding_0x0[4];
    ulong field_0x4; // accesses: 18
    int * field_0x8; // accesses: 12
    void * field_0xc; // accesses: 19
    void * field_0x10; // accesses: 18
    byte field_0x14; // accesses: 5
    byte _padding_0x15[3];
    CMwEngineInfo * field_0x18; // accesses: 21
    code * field_0x1c; // accesses: 1
};

struct CMwNodRef_class_CPlugFileGPUP {
    byte _padding_0x0[24];
    int field_0x18; // accesses: 1
};

struct CMwParamClass {
    byte _padding_0x0[24];
    int field_0x18; // accesses: 1
};

struct CMwParamFastArray_class_CMwParamClass {
    byte _padding_0x0[24];
    int field_0x18; // accesses: 2
};

struct CMwParamFastArray_class_CMwParamIso4 {
    byte _padding_0x0[4];
    ulong * field_0x4; // accesses: 1
    byte _padding_0x8[8];
    int field_0x10; // accesses: 1
    int field_0x14; // accesses: 1
    int field_0x18; // accesses: 2
};

struct CMwParamFastBuffer_class_CMwParamClass {
    byte _padding_0x0[24];
    int field_0x18; // accesses: 2
};

struct CMwParamFastBuffer_class_CMwParamIso4 {
    byte _padding_0x0[16];
    int field_0x10; // accesses: 1
    byte _padding_0x14[4];
    int field_0x18; // accesses: 3
};

struct CMwParamFastBuffer_class_CMwParamMwId {
    byte _padding_0x0[4];
    ulong * field_0x4; // accesses: 1
    byte _padding_0x8[8];
    int field_0x10; // accesses: 1
    int field_0x14; // accesses: 1
    int field_0x18; // accesses: 2
};

struct CMwParamFastBuffer_class_CMwParamReal {
    byte _padding_0x0[24];
    int field_0x18; // accesses: 1
};

struct CMwParamVec3 {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    byte _padding_0xc[4];
    int field_0x10; // accesses: 1
    byte _padding_0x14[4];
    int field_0x18; // accesses: 2
};

struct CMwRefBuffer {
    byte _padding_0x0[32];
    int field_0x20; // accesses: 2
    int field_0x24; // accesses: 3
};

struct CMwStack {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 21
    SParam * field_0x8; // accesses: 11
    int field_0xc; // accesses: 6
    undefined4 * field_0x10; // accesses: 26
    undefined4 * field_0x14; // accesses: 23
    int field_0x18; // accesses: 12
    undefined4 field_0x1c; // accesses: 1
};

struct CMwTimerAdapter {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 2
    float field_0x8; // accesses: 1
    ulong field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
};

struct CNetArchive {
    byte _padding_0x0[8];
    undefined4 field_0x8; // accesses: 2
    undefined4 field_0xc; // accesses: 1
};

struct CNetConnectedClient {
    byte _padding_0x0[28];
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 2
    ulong field_0x24; // accesses: 2
    float field_0x28; // accesses: 1
    byte _padding_0x2c[100];
    int field_0x90; // accesses: 1
};

struct CNetConnection {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 5
    EProtocol field_0x8; // accesses: 1
    int * field_0xc; // accesses: 1
    byte _padding_0x10[12];
    int field_0x1c; // accesses: 5
    undefined4 field_0x20; // accesses: 2
    undefined4 field_0x24; // accesses: 2
    ulong field_0x28; // accesses: 1
    byte _padding_0x2c[4];
    ulong field_0x30; // accesses: 2
    byte _padding_0x34[60];
    CNetConnection * field_0x70; // accesses: 3
    byte _padding_0x74[20];
    int field_0x88; // accesses: 1
    byte _padding_0x8c[4];
    int field_0x90; // accesses: 3
    byte _padding_0x94[8];
    int field_0x9c; // accesses: 4
    int * field_0xa0; // accesses: 4
    int * field_0xa4; // accesses: 4
    byte _padding_0xa8[12];
    int field_0xb4; // accesses: 2
    int field_0xb8; // accesses: 2
    int field_0xbc; // accesses: 2
    byte _padding_0xc0[12];
    int field_0xcc; // accesses: 2
    int field_0xd0; // accesses: 2
    int field_0xd4; // accesses: 2
};

struct CNetFileTransferDownload {
    byte _padding_0x0[4];
    CNetFileTransferDownload * field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    int field_0x10; // accesses: 1
    byte _padding_0x14[12];
    int * field_0x20; // accesses: 2
    byte _padding_0x24[28];
    int field_0x40; // accesses: 4
    ulong field_0x44; // accesses: 1
    byte _padding_0x48[20];
    int field_0x5c; // accesses: 2
    byte _padding_0x60[12];
    int field_0x6c; // accesses: 1
};

struct CNetFileTransferForm {
    byte _padding_0x0[28];
    undefined4 field_0x1c; // accesses: 1
    byte _padding_0x20[104];
    int * field_0x88; // accesses: 2
};

struct CNetHttpClient {
    byte _padding_0x0[24];
    int field_0x18; // accesses: 5
    CClassicBufferMemory * field_0x1c; // accesses: 3
    byte _padding_0x20[48];
    undefined4 field_0x50; // accesses: 4
    undefined4 field_0x54; // accesses: 1
    int field_0x58; // accesses: 4
    byte _padding_0x5c[12];
    DWORD field_0x68; // accesses: 1
    TiXmlAttributeSet * field_0x6c; // accesses: 3
    byte _padding_0x70[24];
    code * field_0x88; // accesses: 1
    int field_0x8c; // accesses: 1
};

struct CNetHttpResult {
    byte _padding_0x0[80];
    undefined4 field_0x50; // accesses: 2
    CNetHttpClient * field_0x54; // accesses: 4
};

struct CNetIPSource {
    byte _padding_0x0[152];
    int field_0x98; // accesses: 1
    int field_0x9c; // accesses: 1
    byte _padding_0xa0[4];
    int field_0xa4; // accesses: 2
    int field_0xa8; // accesses: 2
};

struct CNetMasterServer {
    byte _padding_0x0[44];
    undefined4 field_0x2c; // accesses: 1
    int field_0x30; // accesses: 3
    byte _padding_0x34[20];
    undefined4 field_0x48; // accesses: 1
    byte _padding_0x4c[4];
    int field_0x50; // accesses: 1
    code * field_0x54; // accesses: 2
    int field_0x58; // accesses: 2
    int field_0x5c; // accesses: 2
    int field_0x60; // accesses: 2
    byte _padding_0x64[12];
    int field_0x70; // accesses: 1
    code * field_0x74; // accesses: 2
    byte _padding_0x78[4];
    int field_0x7c; // accesses: 2
    uint field_0x80; // accesses: 1
    int field_0x84; // accesses: 2
};

struct CNetMasterServerDownload {
    byte _padding_0x0[20];
    int field_0x14; // accesses: 1
    byte _padding_0x18[4];
    int field_0x1c; // accesses: 1
    byte _padding_0x20[24];
    undefined4 field_0x38; // accesses: 1
    byte _padding_0x3c[4];
    ulong field_0x40; // accesses: 1
    byte _padding_0x44[56];
    int field_0x7c; // accesses: 2
};

struct CNetMasterServerRequest {
    byte _padding_0x0[80];
    CNetHttpResult * field_0x50; // accesses: 2
};

struct CNetNod {
    byte _padding_0x0[12];
    int field_0xc; // accesses: 3
    byte _padding_0x10[4];
    undefined4 * field_0x14; // accesses: 4
    undefined4 field_0x18; // accesses: 1
    byte _padding_0x1c[32];
    int field_0x3c; // accesses: 2
    int * field_0x40; // accesses: 1
};

struct CNetServer {
    byte _padding_0x0[28];
    CNetMasterServerRequest * field_0x1c; // accesses: 1
    byte _padding_0x20[112];
    undefined4 field_0x90; // accesses: 2
    byte _padding_0x94[8];
    int field_0x9c; // accesses: 1
};

struct CNetSource {
    byte _padding_0x0[20];
    CNetFileTransferDownload * field_0x14; // accesses: 1
    byte _padding_0x18[8];
    int * field_0x20; // accesses: 4
};

struct CNetSystem_CNetSystemError {
    byte _padding_0x0[12];
    undefined4 field_0xc; // accesses: 1
};

struct CNetTransferInfoQueue {
    byte _padding_0x0[4];
    void * field_0x4; // accesses: 6
    int field_0x8; // accesses: 5
    int field_0xc; // accesses: 2
    int field_0x10; // accesses: 6
    int field_0x14; // accesses: 6
    TiXmlAttribute * field_0x18; // accesses: 2
    TiXmlAttribute * field_0x1c; // accesses: 2
    TiXmlAttribute * field_0x20; // accesses: 2
};

struct CNetUDP {
    byte _padding_0x0[12];
    undefined4 field_0xc; // accesses: 1
};

struct CNetUPnP {
    byte _padding_0x0[20];
    int * field_0x14; // accesses: 3
    int * field_0x18; // accesses: 5
};

struct COalDevice {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    undefined * field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined * field_0x20; // accesses: 1
    byte _padding_0x24[8];
    undefined4 field_0x2c; // accesses: 1
    undefined * field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined * field_0x38; // accesses: 1
};

struct CPfmCell {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 3
    undefined4 field_0x8; // accesses: 5
};

struct CPfmMesh {
    byte _padding_0x0[212];
    int field_0xd4; // accesses: 2
    int field_0xd8; // accesses: 2
    int field_0xdc; // accesses: 2
};

struct CPfmMeshInterface {
    byte _padding_0x0[4];
    CPfmMesh * field_0x4; // accesses: 3
};

struct CPfmPlane {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 10
    float field_0x8; // accesses: 10
    float field_0xc; // accesses: 6
    float field_0x10; // accesses: 2
    float field_0x14; // accesses: 2
    float field_0x18; // accesses: 2
    float field_0x1c; // accesses: 1
};

struct CPlugEngine {
    byte _padding_0x0[32];
    undefined4 field_0x20; // accesses: 1
};

struct CPlugFile {
    byte _padding_0x0[8];
    CSystemFidFile * field_0x8; // accesses: 2
};

struct CPlugFileGPU {
    byte _padding_0x0[4];
    CPlugFileGpuBuilder * field_0x4; // accesses: 5
    undefined4 field_0x8; // accesses: 1
    byte _padding_0xc[12];
    int field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    uint field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 2
    byte _padding_0x30[24];
    ulong field_0x48; // accesses: 3
    byte _padding_0x4c[84];
    undefined4 field_0xa0; // accesses: 1
    byte _padding_0xa4[8];
    undefined4 field_0xac; // accesses: 1
    byte _padding_0xb0[4];
    ID3DXConstantTable * field_0xb4; // accesses: 1
    undefined4 field_0xb8; // accesses: 3
    undefined4 field_0xbc; // accesses: 5
    int field_0xc0; // accesses: 4
};

struct CPlugFileGPUP {
    byte _padding_0x0[188];
    undefined4 field_0xbc; // accesses: 1
    undefined4 field_0xc0; // accesses: 1
    undefined4 field_0xc4; // accesses: 1
};

struct CPlugFileGPUV {
    byte _padding_0x0[188];
    undefined4 field_0xbc; // accesses: 1
    undefined4 field_0xc0; // accesses: 1
    undefined4 field_0xc4; // accesses: 1
    undefined4 field_0xc8; // accesses: 1
    undefined4 field_0xcc; // accesses: 1
    undefined4 field_0xd0; // accesses: 1
};

struct CPlugFileGPU_SLoadDesc {
    byte _padding_0x0[4];
    uint field_0x4; // accesses: 2
};

struct CPlugFileGen {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 6
    float field_0x8; // accesses: 7
    float field_0xc; // accesses: 4
    byte _padding_0x10[8];
    CPlugFileImg * field_0x18; // accesses: 19
    int field_0x1c; // accesses: 19
    int field_0x20; // accesses: 1
    uint field_0x24; // accesses: 32
    undefined4 * field_0x28; // accesses: 9
    byte _padding_0x2c[8];
    undefined4 field_0x34; // accesses: 7
};

struct CPlugFileGpuBuilder {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 10
    int * field_0x8; // accesses: 7
    int field_0xc; // accesses: 4
    undefined * field_0x10; // accesses: 4
    int field_0x14; // accesses: 5
    char * field_0x18; // accesses: 3
    byte _padding_0x19[3];
    int field_0x1c; // accesses: 3
    undefined1 * field_0x20; // accesses: 1
    byte _padding_0x21[3];
    int field_0x24; // accesses: 3
    undefined1 * field_0x28; // accesses: 1
    byte _padding_0x29[3];
    int field_0x2c; // accesses: 3
    undefined1 * field_0x30; // accesses: 1
    byte _padding_0x31[3];
    int field_0x34; // accesses: 3
    undefined1 * field_0x38; // accesses: 1
    byte _padding_0x39[3];
    int field_0x3c; // accesses: 3
    undefined1 * field_0x40; // accesses: 1
};

struct CPlugFileImg {
    byte _padding_0x0[2];
    float field_0x2; // accesses: 2
    float field_0x4; // accesses: 6
    ulong field_0x8; // accesses: 2
    undefined4 field_0xc; // accesses: 8
    byte _padding_0x10[4];
    undefined4 field_0x14; // accesses: 1
    ulong field_0x18; // accesses: 9
    ulong field_0x1c; // accesses: 11
    ulong field_0x20; // accesses: 6
    undefined4 field_0x24; // accesses: 33
    void * field_0x28; // accesses: 19
    ulong field_0x2c; // accesses: 4
    undefined4 field_0x30; // accesses: 1
};

struct CPlugFilePHlsl {
    byte _padding_0x0[16];
    int field_0x10; // accesses: 1
    uint field_0x14; // accesses: 3
    byte _padding_0x18[8];
    undefined4 field_0x20; // accesses: 1
    byte _padding_0x24[164];
    int field_0xc8; // accesses: 2
};

struct CPlugFilePack {
    byte _padding_0x0[1];
    undefined4 field_0x1; // accesses: 1
    undefined4 field_0x5; // accesses: 1
    undefined4 field_0x9; // accesses: 1
    undefined4 field_0xd; // accesses: 1
    undefined4 field_0x11; // accesses: 1
    undefined4 field_0x15; // accesses: 1
    undefined4 field_0x19; // accesses: 1
    undefined4 field_0x1d; // accesses: 1
    byte _padding_0x21[75];
    undefined4 * field_0x6c; // accesses: 2
};

struct CPlugFilePsh {
    byte _padding_0x0[32];
    undefined4 field_0x20; // accesses: 1
    byte _padding_0x24[164];
    undefined4 field_0xc8; // accesses: 1
};

struct CPlugFileSnd {
    byte _padding_0x0[20];
    short field_0x14; // accesses: 1
    byte _padding_0x16[2];
    int field_0x18; // accesses: 1
    byte _padding_0x1c[4];
    ushort field_0x20; // accesses: 2
    byte _padding_0x22[2];
    uint field_0x24; // accesses: 2
};

struct CPlugFileText {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    undefined * field_0x18; // accesses: 1
};

struct CPlugFileVHlsl {
    byte _padding_0x0[4];
    CPlugFileGpuBuilder * field_0x4; // accesses: 15
    int field_0x8; // accesses: 3
    char * field_0xc; // accesses: 1
    byte _padding_0xd[3];
    int field_0x10; // accesses: 2
    NvStripInfo * field_0x14; // accesses: 4
    CPlugFileGpuBuilder * field_0x18; // accesses: 1
    int field_0x1c; // accesses: 3
    undefined4 field_0x20; // accesses: 3
    int field_0x24; // accesses: 7
    byte _padding_0x28[8];
    uint field_0x30; // accesses: 3
    int field_0x34; // accesses: 2
    int field_0x38; // accesses: 2
    byte _padding_0x3c[8];
    float field_0x44; // accesses: 2
    float field_0x48; // accesses: 3
    float field_0x4c; // accesses: 3
    byte _padding_0x50[60];
    uint field_0x8c; // accesses: 8
    byte _padding_0x90[28];
    CPlugGpuCompileCache * field_0xac; // accesses: 1
    byte _padding_0xb0[4];
    void * field_0xb4; // accesses: 1
    int * field_0xb8; // accesses: 2
    byte _padding_0xbc[32];
    int field_0xdc; // accesses: 2
};

struct CPlugFileVsh {
    byte _padding_0x0[32];
    undefined4 field_0x20; // accesses: 1
    byte _padding_0x24[184];
    undefined4 field_0xdc; // accesses: 1
    byte _padding_0xe0[4];
    undefined4 field_0xe4; // accesses: 1
    undefined4 field_0xe8; // accesses: 1
    undefined * field_0xec; // accesses: 1
};

struct CPlugFont {
    byte _padding_0x0[4];
    undefined2 * field_0x4; // accesses: 5
    byte _padding_0x6[2];
    undefined4 field_0x8; // accesses: 4
    undefined4 field_0xc; // accesses: 4
    undefined4 field_0x10; // accesses: 29
    uint field_0x14; // accesses: 2
    int field_0x18; // accesses: 1
};

struct CPlugFont_CUrlLinks {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 1
    byte _padding_0x18[8];
    int field_0x20; // accesses: 1
    byte _padding_0x24[4];
    undefined4 field_0x28; // accesses: 1
};

struct CPlugFont_SCharStyle {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 2
    undefined4 field_0xc; // accesses: 2
    undefined4 field_0x10; // accesses: 1
};

struct CPlugGpuFxLocator {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    byte _padding_0x18[4];
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
};

struct CPlugIndexBuffer {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 3
};

struct CPlugMaterial {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 2
    CPlugShader * field_0x18; // accesses: 6
    int * field_0x1c; // accesses: 4
    byte _padding_0x20[8];
    int field_0x28; // accesses: 2
    undefined4 field_0x2c; // accesses: 2
};

struct CPlugModelTree_ItTree {
    byte _padding_0x0[44];
    int field_0x2c; // accesses: 2
};

struct CPlugMusic {
    byte _padding_0x0[116];
    undefined4 field_0x74; // accesses: 1
};

struct CPlugMusicType {
    byte _padding_0x0[28];
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    byte _padding_0x28[24];
    undefined4 field_0x40; // accesses: 1
    byte _padding_0x44[44];
    undefined4 field_0x70; // accesses: 1
};

struct CPlugPhysicalObject {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    byte _padding_0xc[28];
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 2
    undefined4 field_0x38; // accesses: 2
    undefined4 field_0x3c; // accesses: 2
    undefined4 field_0x40; // accesses: 1
    byte _padding_0x44[72];
    int field_0x8c; // accesses: 4
};

struct CPlugShader {
    byte _padding_0x0[4];
    SCasterCat * field_0x4; // accesses: 4
    byte _padding_0x8[12];
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    int field_0x1c; // accesses: 19
    undefined4 field_0x20; // accesses: 6
    undefined4 field_0x24; // accesses: 2
    undefined2 field_0x28; // accesses: 2
    byte _padding_0x2a[10];
    undefined4 field_0x34; // accesses: 1
    byte _padding_0x38[21];
    char field_0x4d; // accesses: 1
    byte _padding_0x4e[38];
    CPlugBitmapRender * field_0x74; // accesses: 1
};

struct CPlugShaderApply {
    byte _padding_0x0[32];
    EGxTexOp field_0x20; // accesses: 2
    byte _padding_0x24[108];
    undefined4 field_0x90; // accesses: 1
    byte _padding_0x94[8];
    undefined4 field_0x9c; // accesses: 10
    undefined4 field_0xa0; // accesses: 3
};

struct CPlugShaderGeneric {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 6
    float field_0x8; // accesses: 6
    float field_0xc; // accesses: 4
    byte _padding_0x10[40];
    undefined4 field_0x38; // accesses: 2
    undefined4 field_0x3c; // accesses: 2
    undefined4 field_0x40; // accesses: 2
    float field_0x44; // accesses: 5
    float field_0x48; // accesses: 5
    float field_0x4c; // accesses: 4
    float field_0x50; // accesses: 5
    undefined4 field_0x54; // accesses: 1
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 3
    undefined4 field_0x68; // accesses: 3
    undefined4 field_0x6c; // accesses: 3
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1
    undefined4 field_0x78; // accesses: 1
    undefined4 field_0x7c; // accesses: 1
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
    undefined4 field_0x88; // accesses: 1
    uint field_0x8c; // accesses: 32
};

struct CPlugShaderLoadIds {
    byte _padding_0x0[8];
    ELoadId field_0x8; // accesses: 2
};

struct CPlugShaderPass {
    byte _padding_0x0[44];
    int field_0x2c; // accesses: 1
    byte _padding_0x30[4];
    CPlugShader * field_0x34; // accesses: 7
    undefined4 field_0x38; // accesses: 8
    byte _padding_0x3c[8];
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    byte _padding_0x4c[8];
    undefined4 field_0x54; // accesses: 1
};

struct CPlugSolid {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 5
    float field_0x8; // accesses: 15
    float field_0xc; // accesses: 3
    int field_0x10; // accesses: 2
    code * field_0x14; // accesses: 2
    GmVec3 * field_0x18; // accesses: 11
    byte _padding_0x1c[4];
    int field_0x20; // accesses: 1
    int field_0x24; // accesses: 1
    int field_0x28; // accesses: 1
    byte _padding_0x2c[8];
    float field_0x34; // accesses: 1
    float field_0x38; // accesses: 1
    float field_0x3c; // accesses: 1
    float field_0x40; // accesses: 3
    float field_0x44; // accesses: 2
    float field_0x48; // accesses: 2
    byte _padding_0x4c[8];
    CClassicArchive * field_0x54; // accesses: 1
    CClassicArchive * field_0x58; // accesses: 2
    CPlugSolid * field_0x5c; // accesses: 6
    int field_0x60; // accesses: 5
    int * field_0x64; // accesses: 43
    char * field_0x68; // accesses: 27
    byte _padding_0x69[3];
    float field_0x6c; // accesses: 6
    ulong field_0x70; // accesses: 10
};

struct CPlugSound {
    byte _padding_0x0[24];
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
};

struct CPlugSoundVideo {
    byte _padding_0x0[112];
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1
};

struct CPlugSurface {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    int field_0x8; // accesses: 5
    undefined4 field_0xc; // accesses: 1
    byte _padding_0x10[4];
    CClassicArchive * field_0x14; // accesses: 8
    byte _padding_0x18[12];
    ushort field_0x24; // accesses: 2
    ushort field_0x26; // accesses: 2
};

struct CPlugSurfaceGeom {
    byte _padding_0x0[4];
    undefined2 field_0x4; // accesses: 9
    char field_0x6; // accesses: 5
    byte _padding_0x7[1];
    float field_0x8; // accesses: 31
    float field_0xc; // accesses: 3
    float field_0x10; // accesses: 5
    float field_0x14; // accesses: 2
    float field_0x18; // accesses: 10
    float field_0x1c; // accesses: 4
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    float field_0x28; // accesses: 2
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    GmSurfMesh * field_0x34; // accesses: 50
    undefined4 field_0x38; // accesses: 1
};

struct CPlugSurfaceMaterialData {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 5
};

struct CPlugTree {
    byte _padding_0x0[4];
    byte field_0x4; // accesses: 45
    byte _padding_0x5[1];
    char field_0x6; // accesses: 1
    byte _padding_0x7[1];
    EVolatileTreeType field_0x8; // accesses: 30
    CSystemArchiveNod * field_0xc; // accesses: 16
    int * field_0x10; // accesses: 21
    byte field_0x14; // accesses: 39
    byte _padding_0x15[3];
    CMwParamClass * field_0x18; // accesses: 26
    float field_0x1c; // accesses: 42
    int field_0x20; // accesses: 9
    CPlugTree * field_0x24; // accesses: 17
    byte field_0x27; // accesses: 1
    float field_0x28; // accesses: 5
    float field_0x2c; // accesses: 3
    int field_0x30; // accesses: 5
    int field_0x34; // accesses: 11
    CPlugTree * field_0x38; // accesses: 15
    int field_0x3c; // accesses: 7
    int field_0x40; // accesses: 7
    int field_0x44; // accesses: 7
    int field_0x48; // accesses: 7
    undefined4 field_0x4c; // accesses: 1
    int field_0x50; // accesses: 3
    ulong field_0x54; // accesses: 17
    undefined2 field_0x56; // accesses: 4
    void * field_0x58; // accesses: 3
    byte _padding_0x5c[36];
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
    code * field_0x88; // accesses: 2
    CPlugTree * field_0x8c; // accesses: 26
    CPlugVisual * field_0x90; // accesses: 64
    CPlugShader * field_0x94; // accesses: 65
    CPlugMaterialCustom * field_0x98; // accesses: 35
    byte field_0x9c; // accesses: 184
    byte _padding_0x9d[3];
    CPlugTree * field_0xa0; // accesses: 27
    void * field_0xa4; // accesses: 8
    CPlugTree * field_0xa8; // accesses: 10
    byte _padding_0xac[4];
    code * field_0xb0; // accesses: 1
};

struct CPlugTreeGenText {
    byte _padding_0x0[60];
    int field_0x3c; // accesses: 1
    float field_0x40; // accesses: 2
    float field_0x44; // accesses: 3
    int field_0x48; // accesses: 1
    uint field_0x4c; // accesses: 2
    uint field_0x50; // accesses: 1
    int * field_0x54; // accesses: 4
};

struct CPlugTreeVisualMip {
    byte _padding_0x0[20];
    int field_0x14; // accesses: 1
    byte _padding_0x18[120];
    int field_0x90; // accesses: 1
    byte _padding_0x94[8];
    uint field_0x9c; // accesses: 2
    byte _padding_0xa0[28];
    int field_0xbc; // accesses: 3
    byte _padding_0xc0[12];
    float field_0xcc; // accesses: 4
    float field_0xd0; // accesses: 4
};

struct CPlugTree_CIteratorMaterial {
    byte _padding_0x0[152];
    CPlugMaterial * field_0x98; // accesses: 3
};

struct CPlugTree_CIteratorShader {
    byte _padding_0x0[148];
    CPlugShader * field_0x94; // accesses: 3
};

struct CPlugTree_CIteratorSurface {
    byte _padding_0x0[140];
    int field_0x8c; // accesses: 3
};

struct CPlugTree_CIteratorTree {
    byte _padding_0x0[36];
    int * field_0x24; // accesses: 1
};

struct CPlugTree_CIteratorVisual {
    byte _padding_0x0[144];
    int field_0x90; // accesses: 3
};

struct CPlugTree_SVolatileTreePointer {
    byte _padding_0x0[8];
    int field_0x8; // accesses: 1
};

struct CPlugViewDepLocator {
    byte _padding_0x0[8];
    float field_0x8; // accesses: 4
    float field_0xc; // accesses: 2
    float field_0x10; // accesses: 1
    float field_0x14; // accesses: 7
    float field_0x18; // accesses: 2
    GmIso4 * field_0x1c; // accesses: 1
    byte _padding_0x20[4];
    float field_0x24; // accesses: 2
    float field_0x28; // accesses: 4
    float field_0x2c; // accesses: 2
    float field_0x30; // accesses: 2
    float field_0x34; // accesses: 2
    float field_0x38; // accesses: 2
    float field_0x3c; // accesses: 2
    byte _padding_0x40[16];
    float field_0x50; // accesses: 2
    float field_0x54; // accesses: 2
    float field_0x58; // accesses: 2
    float field_0x5c; // accesses: 2
};

struct CPlugVisual {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 2
    byte _padding_0x18[4];
    uint field_0x1c; // accesses: 15
    byte _padding_0x20[20];
    undefined4 field_0x34; // accesses: 2
    undefined4 field_0x38; // accesses: 2
    undefined4 field_0x3c; // accesses: 2
    undefined4 field_0x40; // accesses: 2
    undefined4 field_0x44; // accesses: 2
    undefined4 field_0x48; // accesses: 2
    undefined4 field_0x4c; // accesses: 1
    byte _padding_0x50[28];
    undefined4 field_0x6c; // accesses: 1
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1
};

struct CPlugVisual2D {
    byte _padding_0x0[28];
    uint field_0x1c; // accesses: 2
};

struct CPlugVisualIndexed {
    byte _padding_0x0[152];
    int field_0x98; // accesses: 8
};

struct CPlugVisualIndexedLines {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    byte _padding_0x28[112];
    int field_0x98; // accesses: 2
    undefined4 field_0x9c; // accesses: 1
};

struct CPlugVisualLines {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 6
    undefined4 field_0x8; // accesses: 6
    undefined4 field_0xc; // accesses: 4
    undefined4 field_0x10; // accesses: 2
    undefined4 field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 2
    undefined4 field_0x1c; // accesses: 2
    undefined4 field_0x20; // accesses: 2
    undefined4 field_0x24; // accesses: 2
};

struct CPlugVisualQuads {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 4
    float field_0x8; // accesses: 4
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
};

struct CPlugVisualQuads2D {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 12
    float field_0x8; // accesses: 7
    float field_0xc; // accesses: 7
    undefined4 field_0x10; // accesses: 5
    undefined4 field_0x14; // accesses: 5
    undefined4 field_0x18; // accesses: 5
    undefined4 field_0x1c; // accesses: 5
};

struct CPlugVisualSprite {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 8
    float field_0x8; // accesses: 8
    float field_0xc; // accesses: 4
    byte _padding_0x10[4];
    float field_0x14; // accesses: 1
    byte _padding_0x18[4];
    uint field_0x1c; // accesses: 8
    byte _padding_0x20[20];
    float field_0x34; // accesses: 1
    float field_0x38; // accesses: 1
    float field_0x3c; // accesses: 1
    float field_0x40; // accesses: 1
    float field_0x44; // accesses: 1
    float field_0x48; // accesses: 1
    byte _padding_0x4c[76];
    undefined4 field_0x98; // accesses: 1
    undefined4 field_0x9c; // accesses: 1
    undefined4 field_0xa0; // accesses: 1
    undefined4 field_0xa4; // accesses: 1
    undefined4 field_0xa8; // accesses: 1
    undefined4 field_0xac; // accesses: 1
    undefined4 field_0xb0; // accesses: 9
    ushort field_0xb4; // accesses: 5
    ushort field_0xb6; // accesses: 4
};

struct CScene {
    byte _padding_0x0[24];
    int field_0x18; // accesses: 5
    byte _padding_0x1c[52];
    undefined4 field_0x50; // accesses: 1
    CSceneToySea * field_0x54; // accesses: 2
    byte _padding_0x58[68];
    undefined4 field_0x9c; // accesses: 2
};

struct CScene2d {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 2
    undefined4 field_0xc; // accesses: 2
    byte _padding_0x10[144];
    int field_0xa0; // accesses: 2
    int field_0xa4; // accesses: 7
    undefined4 field_0xa8; // accesses: 2
    undefined4 field_0xac; // accesses: 2
    undefined4 field_0xb0; // accesses: 2
    undefined4 field_0xb4; // accesses: 2
    byte _padding_0xb8[132];
    undefined4 field_0x13c; // accesses: 1
    undefined4 field_0x140; // accesses: 1
    undefined4 field_0x144; // accesses: 1
    undefined4 field_0x148; // accesses: 1
};

struct CScene3d {
    byte _padding_0x0[48];
    CSceneFx * field_0x30; // accesses: 1
    byte _padding_0x34[292];
    CSceneFxNod * field_0x158; // accesses: 4
    CScene3d * field_0x15c; // accesses: 2
};

struct CSceneCamera {
    byte _padding_0x0[20];
    int field_0x14; // accesses: 1
    byte _padding_0x18[24];
    CHmsCamera * field_0x30; // accesses: 3
    byte _padding_0x34[4];
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    byte _padding_0x44[260];
    CHmsCamera * field_0x148; // accesses: 1
    undefined4 field_0x14c; // accesses: 1
    undefined4 field_0x150; // accesses: 1
    undefined4 field_0x154; // accesses: 1
    byte _padding_0x158[184];
    int field_0x210; // accesses: 1
};

struct CSceneEngine {
    byte _padding_0x0[32];
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
};

struct CSceneFxColors_SParam {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 1
    float field_0x8; // accesses: 1
    float field_0xc; // accesses: 1
    float field_0x10; // accesses: 1
    float field_0x14; // accesses: 1
    float field_0x18; // accesses: 1
    float field_0x1c; // accesses: 1
    float field_0x20; // accesses: 1
    float field_0x24; // accesses: 1
    float field_0x28; // accesses: 1
    float field_0x2c; // accesses: 1
};

struct CSceneFxNod {
    byte _padding_0x0[20];
    int field_0x14; // accesses: 5
    int field_0x18; // accesses: 3
    int field_0x1c; // accesses: 8
    byte _padding_0x20[16];
    int * field_0x30; // accesses: 13
    byte _padding_0x34[16];
    CSceneFxNod * field_0x44; // accesses: 4
    byte _padding_0x48[364];
    CSceneFxNod * field_0x1b4; // accesses: 3
    code * field_0x1b8; // accesses: 2
};

struct CSceneFxVisionK {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 16
    float field_0x8; // accesses: 16
    float field_0xc; // accesses: 23
    float field_0x10; // accesses: 25
    float field_0x14; // accesses: 25
    float field_0x18; // accesses: 7
    float field_0x1c; // accesses: 7
    float field_0x20; // accesses: 7
    float field_0x24; // accesses: 9
    byte _padding_0x28[132];
    float field_0xac; // accesses: 2
    byte _padding_0xb0[4];
    float field_0xb4; // accesses: 1
    float field_0xb8; // accesses: 1
    float field_0xbc; // accesses: 1
    int field_0xc0; // accesses: 1
    byte _padding_0xc4[4];
    float field_0xc8; // accesses: 2
    byte _padding_0xcc[76];
    int field_0x118; // accesses: 3
    byte _padding_0x11c[8];
    int field_0x124; // accesses: 4
    byte _padding_0x128[4];
    int field_0x12c; // accesses: 7
    ulong field_0x130; // accesses: 1
};

struct CSceneLight {
    byte _padding_0x0[48];
    int field_0x30; // accesses: 4
    byte _padding_0x34[48];
    CSceneLight * field_0x64; // accesses: 1
};

struct CSceneMessageHandler {
    byte _padding_0x0[12];
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    void * field_0x14; // accesses: 3
    undefined4 field_0x18; // accesses: 2
    undefined4 field_0x1c; // accesses: 3
    CSceneMessageHandler * field_0x20; // accesses: 6
    byte _padding_0x24[4];
    CSceneMobilAbsorbContact * field_0x28; // accesses: 4
    ulong field_0x2c; // accesses: 2
    int field_0x30; // accesses: 2
    undefined4 field_0x34; // accesses: 2
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    int field_0x40; // accesses: 2
    undefined4 field_0x44; // accesses: 1
    int field_0x48; // accesses: 2
    undefined4 field_0x4c; // accesses: 1
};

struct CSceneMobil {
    byte _padding_0x0[4];
    CPlugTree * field_0x4; // accesses: 15
    CSceneMobil * field_0x8; // accesses: 13
    undefined4 field_0xc; // accesses: 1
    int field_0x10; // accesses: 5
    int * field_0x14; // accesses: 27
    int field_0x18; // accesses: 18
    CHmsLight * field_0x1c; // accesses: 1
    float field_0x20; // accesses: 18
    undefined4 field_0x24; // accesses: 8
    int * field_0x28; // accesses: 63
    CPlugSolid * field_0x2c; // accesses: 9
    CHmsLight * field_0x30; // accesses: 39
    CHmsCorpus * field_0x34; // accesses: 15
    GmLocFreeVal * field_0x38; // accesses: 8
    float field_0x3c; // accesses: 2
    CHmsCorpus * field_0x40; // accesses: 3
    CSceneMessageHandler * field_0x44; // accesses: 15
    float field_0x48; // accesses: 2
    byte _padding_0x4c[28];
    undefined4 field_0x68; // accesses: 1
    byte _padding_0x6c[12];
    code * field_0x78; // accesses: 2
    byte _padding_0x7c[8];
    float field_0x84; // accesses: 2
    code * field_0x88; // accesses: 1
    byte _padding_0x8c[4];
    int field_0x90; // accesses: 5
    byte _padding_0x94[4];
    CPlugMaterial * field_0x98; // accesses: 1
    uint field_0x9c; // accesses: 7
    byte _padding_0xa0[8];
    int field_0xa8; // accesses: 3
    int field_0xac; // accesses: 3
    CMotionLight * field_0xb0; // accesses: 6
};

struct CSceneMobilAbsorbContact {
    byte _padding_0x0[64];
    int * field_0x40; // accesses: 1
};

struct CSceneMobilClouds {
    byte _padding_0x0[28];
    uint field_0x1c; // accesses: 3
    byte _padding_0x20[8];
    CHmsItem * field_0x28; // accesses: 5
    byte _padding_0x2c[12];
    float field_0x38; // accesses: 1
    float field_0x3c; // accesses: 1
    float field_0x40; // accesses: 1
    float field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    byte _padding_0x4c[8];
    CLoadGeomDynaSprite * field_0x54; // accesses: 5
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    int field_0x68; // accesses: 2
    undefined4 field_0x6c; // accesses: 1
    int field_0x70; // accesses: 3
    undefined4 field_0x74; // accesses: 2
    CPlugTree * field_0x78; // accesses: 3
    undefined4 field_0x7c; // accesses: 1
    float field_0x80; // accesses: 1
    int field_0x84; // accesses: 6
    int field_0x88; // accesses: 6
    float field_0x8c; // accesses: 2
    float field_0x90; // accesses: 3
    CPlugShader * field_0x94; // accesses: 7
    int field_0x98; // accesses: 7
    byte field_0x9c; // accesses: 7
    byte _padding_0x9d[19];
    uint field_0xb0; // accesses: 1
};

struct CSceneMobilSnow {
    byte _padding_0x0[4];
    CPlugVisualSprite * field_0x4; // accesses: 1
    GmVec3 * field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    byte _padding_0x10[4];
    CPlugAudio * field_0x14; // accesses: 1
    byte _padding_0x18[4];
    uint field_0x1c; // accesses: 6
    byte _padding_0x20[8];
    int field_0x28; // accesses: 2
    byte _padding_0x2c[28];
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    byte _padding_0x54[8];
    CLoadGeomDynaSprite * field_0x5c; // accesses: 2
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
};

struct CSceneObject {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 4
    int field_0x8; // accesses: 2
    byte _padding_0xc[4];
    int field_0x10; // accesses: 4
    int * field_0x14; // accesses: 5
    int field_0x18; // accesses: 12
    undefined4 field_0x1c; // accesses: 1
    CFuncSegment * field_0x20; // accesses: 28
    undefined4 field_0x24; // accesses: 5
};

struct CSceneObjectLink {
    byte _padding_0x0[20];
    uint field_0x14; // accesses: 7
    CSceneObjectLink * field_0x18; // accesses: 5
    int field_0x1c; // accesses: 4
    CPlugTree * field_0x20; // accesses: 5
    undefined4 field_0x24; // accesses: 1
    byte _padding_0x28[52];
    int field_0x5c; // accesses: 5
    int * field_0x60; // accesses: 8
};

struct CScenePickedItem {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    byte _padding_0x18[212];
    undefined4 field_0xec; // accesses: 3
    undefined4 field_0xf0; // accesses: 3
    byte _padding_0xf4[48];
    undefined4 field_0x124; // accesses: 1
    byte _padding_0x128[48];
    undefined4 field_0x158; // accesses: 2
    undefined4 field_0x15c; // accesses: 2
};

struct CScenePickerManager {
    byte _padding_0x0[16];
    undefined4 field_0x10; // accesses: 1
    int * field_0x14; // accesses: 3
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    byte _padding_0x24[200];
    undefined4 field_0xec; // accesses: 1
    int field_0xf0; // accesses: 1
    byte _padding_0xf4[48];
    undefined4 field_0x124; // accesses: 1
    byte _padding_0x128[448];
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
    CMwCmd * field_0x65c; // accesses: 3
};

struct CScenePoc {
    byte _padding_0x0[40];
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    int * field_0x30; // accesses: 2
    undefined4 field_0x34; // accesses: 1
};

struct CSceneSector {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    byte _padding_0x18[4];
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1
};

struct CSceneSoundManager {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
};

struct CSceneSoundSource {
    byte _padding_0x0[48];
    int field_0x30; // accesses: 9
};

struct CSceneToyBoat {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 8
    float field_0x8; // accesses: 5
    byte _padding_0xc[8];
    void * field_0x14; // accesses: 22
    float field_0x18; // accesses: 28
    float field_0x1c; // accesses: 4
    float field_0x20; // accesses: 3
    float field_0x24; // accesses: 1
    int field_0x28; // accesses: 3
    float field_0x2c; // accesses: 1
    int field_0x30; // accesses: 2
    byte _padding_0x34[8];
    undefined4 field_0x3c; // accesses: 1
    int * field_0x40; // accesses: 2
    byte _padding_0x44[4];
    ulong field_0x48; // accesses: 2
    byte _padding_0x4c[16];
    float field_0x5c; // accesses: 7
    float field_0x60; // accesses: 5
    byte _padding_0x64[8];
    float field_0x6c; // accesses: 26
    float field_0x70; // accesses: 2
    float field_0x74; // accesses: 1
    float field_0x78; // accesses: 1
    float field_0x7c; // accesses: 1
    float field_0x80; // accesses: 3
    CBoatParam * field_0x84; // accesses: 20
    undefined4 field_0x88; // accesses: 1
    float field_0x8c; // accesses: 2
    float field_0x90; // accesses: 5
    CBoatSail * field_0x94; // accesses: 17
    CBoatSail * field_0x98; // accesses: 13
    undefined4 field_0x9c; // accesses: 1
    float field_0xa0; // accesses: 2
    float field_0xa4; // accesses: 5
    float field_0xa8; // accesses: 2
    float field_0xac; // accesses: 2
    float field_0xb0; // accesses: 11
    float field_0xb4; // accesses: 3
    float field_0xb8; // accesses: 3
    float field_0xbc; // accesses: 2
    byte _padding_0xc0[12];
    float field_0xcc; // accesses: 4
    float field_0xd0; // accesses: 4
    float field_0xd4; // accesses: 4
    float field_0xd8; // accesses: 9
    float field_0xdc; // accesses: 22
    undefined4 field_0xe0; // accesses: 2
    byte _padding_0xe4[4];
    int field_0xe8; // accesses: 3
    uint field_0xec; // accesses: 3
    int field_0xf0; // accesses: 2
    byte _padding_0xf4[4];
    float field_0xf8; // accesses: 5
    float field_0xfc; // accesses: 1
    float field_0x100; // accesses: 1
    float field_0x104; // accesses: 1
    undefined4 field_0x108; // accesses: 1
    float field_0x10c; // accesses: 5
    float field_0x110; // accesses: 2
    float field_0x114; // accesses: 2
    float field_0x118; // accesses: 7
    float field_0x11c; // accesses: 2
    float field_0x120; // accesses: 1
    byte _padding_0x124[12];
    ESailType field_0x130; // accesses: 20
    CBoatSailState * field_0x134; // accesses: 8
    int field_0x138; // accesses: 3
    float field_0x13c; // accesses: 3
    byte _padding_0x140[36];
    int field_0x164; // accesses: 2
    int field_0x168; // accesses: 4
    byte _padding_0x16c[28];
    float field_0x188; // accesses: 1
    byte _padding_0x18c[12];
    float field_0x198; // accesses: 4
    byte _padding_0x19c[16];
    float field_0x1ac; // accesses: 8
    uint field_0x1b0; // accesses: 1
    byte _padding_0x1b4[20];
    int field_0x1c8; // accesses: 10
    float field_0x1cc; // accesses: 10
    byte _padding_0x1d0[48];
    int field_0x200; // accesses: 2
    byte _padding_0x204[336];
    int field_0x354; // accesses: 1
    int field_0x358; // accesses: 1
    int field_0x35c; // accesses: 2
    byte _padding_0x360[44];
    CSceneSoundSource * field_0x38c; // accesses: 9
    undefined4 field_0x390; // accesses: 8
    undefined4 field_0x394; // accesses: 8
    undefined4 field_0x398; // accesses: 8
    undefined4 field_0x39c; // accesses: 8
    undefined4 field_0x3a0; // accesses: 7
    int field_0x3a4; // accesses: 12
    CSceneSoundSource * field_0x3a8; // accesses: 10
    undefined4 field_0x3ac; // accesses: 7
    int field_0x3b0; // accesses: 10
    int field_0x3b4; // accesses: 10
    CSceneSoundSource * field_0x3b8; // accesses: 9
    CSceneSoundSource * field_0x3bc; // accesses: 8
    CSceneSoundSource * field_0x3c0; // accesses: 8
    CSceneSoundSource * field_0x3c4; // accesses: 9
    int field_0x3c8; // accesses: 11
    byte _padding_0x3cc[12];
    float field_0x3d8; // accesses: 10
    float field_0x3dc; // accesses: 10
    float field_0x3e0; // accesses: 10
    float field_0x3e4; // accesses: 22
    float field_0x3e8; // accesses: 22
    float field_0x3ec; // accesses: 22
    byte _padding_0x3f0[4];
    undefined4 field_0x3f4; // accesses: 1
    CSceneMobil * field_0x3f8; // accesses: 4
    float field_0x3fc; // accesses: 4
    int field_0x400; // accesses: 5
};

struct CSceneToyBroomstick {
    byte _padding_0x0[12];
    float field_0xc; // accesses: 1
    float field_0x10; // accesses: 1
    void * field_0x14; // accesses: 3
    byte _padding_0x18[12];
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 5
    undefined4 field_0x2c; // accesses: 1
    byte _padding_0x30[164];
    CMwCmdBlockMain * field_0xd4; // accesses: 2
    byte _padding_0xd8[68];
    undefined4 field_0x11c; // accesses: 1
    byte _padding_0x120[24];
    undefined4 field_0x138; // accesses: 1
    undefined4 field_0x13c; // accesses: 1
    undefined4 field_0x140; // accesses: 1
    byte _padding_0x144[36];
    undefined4 field_0x168; // accesses: 1
    undefined4 field_0x16c; // accesses: 1
    undefined4 field_0x170; // accesses: 1
    ulong field_0x174; // accesses: 2
    float field_0x178; // accesses: 3
    float field_0x17c; // accesses: 3
    float field_0x180; // accesses: 3
};

struct CSceneToyCharacter {
    byte _padding_0x0[12];
    float field_0xc; // accesses: 1
    byte _padding_0x10[4];
    void * field_0x14; // accesses: 3
    byte _padding_0x18[4];
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    byte _padding_0x24[4];
    int field_0x28; // accesses: 7
    byte _padding_0x2c[36];
    int field_0x50; // accesses: 2
    byte _padding_0x54[36];
    float field_0x78; // accesses: 1
    byte _padding_0x7c[4];
    CSceneToyCharacter * field_0x80; // accesses: 4
    byte _padding_0x84[8];
    int field_0x8c; // accesses: 1
    code * field_0x90; // accesses: 2
    float field_0x94; // accesses: 1
    float field_0x98; // accesses: 1
    float field_0x9c; // accesses: 3
    undefined4 field_0xa0; // accesses: 1
    float field_0xa4; // accesses: 2
    undefined4 field_0xa8; // accesses: 1
    float field_0xac; // accesses: 4
    float field_0xb0; // accesses: 4
    float field_0xb4; // accesses: 3
    int field_0xb8; // accesses: 4
    CSceneToyCharacter * field_0xbc; // accesses: 4
    undefined4 field_0xc0; // accesses: 3
    ulong field_0xc4; // accesses: 5
    int field_0xc8; // accesses: 3
    int field_0xcc; // accesses: 2
    byte _padding_0xd0[156];
    char field_0x16c; // accesses: 1
    byte _padding_0x16d[11];
    float field_0x178; // accesses: 2
    float field_0x17c; // accesses: 1
};

struct CSceneToyFxDynaBump {
    byte _padding_0x0[28];
    int field_0x1c; // accesses: 1
    byte _padding_0x20[4];
    float field_0x24; // accesses: 1
    float field_0x28; // accesses: 2
    float field_0x2c; // accesses: 1
    byte _padding_0x30[12];
    float field_0x3c; // accesses: 1
    int field_0x40; // accesses: 2
    float field_0x44; // accesses: 1
    byte _padding_0x48[5];
    char field_0x4d; // accesses: 1
    byte _padding_0x4e[30];
    int field_0x6c; // accesses: 5
    float field_0x70; // accesses: 7
    float field_0x74; // accesses: 8
    float field_0x78; // accesses: 10
    float field_0x7c; // accesses: 10
    float field_0x80; // accesses: 10
    float field_0x84; // accesses: 4
    float field_0x88; // accesses: 4
    float field_0x8c; // accesses: 4
    int field_0x90; // accesses: 3
    CPlugMaterialFx * field_0x94; // accesses: 7
    CPlugMaterial * field_0x98; // accesses: 1
    GmVec4 * field_0x9c; // accesses: 4
    byte _padding_0xa0[4];
    float * field_0xa4; // accesses: 2
    byte _padding_0xa8[4];
    float * field_0xac; // accesses: 3
    byte _padding_0xb0[4];
    float * field_0xb4; // accesses: 3
    byte _padding_0xb8[4];
    undefined4 * field_0xbc; // accesses: 3
};

struct CSceneToyRock {
    byte _padding_0x0[20];
    void * field_0x14; // accesses: 3
    byte _padding_0x18[12];
    float field_0x24; // accesses: 2
    float field_0x28; // accesses: 3
    float field_0x2c; // accesses: 2
    byte _padding_0x30[8];
    float field_0x38; // accesses: 2
    byte _padding_0x3c[8];
    float field_0x44; // accesses: 2
    byte _padding_0x48[24];
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    int field_0x6c; // accesses: 1
    int field_0x70; // accesses: 5
    byte _padding_0x74[4];
    CSceneToySea * field_0x78; // accesses: 4
    float field_0x7c; // accesses: 2
    float field_0x80; // accesses: 5
    float field_0x84; // accesses: 2
    float field_0x88; // accesses: 3
    float field_0x8c; // accesses: 2
    float field_0x90; // accesses: 1
    float field_0x94; // accesses: 2
};

struct CSceneToySea {
    byte _padding_0x0[4];
    ulong field_0x4; // accesses: 1
    byte _padding_0x8[12];
    CPlugAudio * field_0x14; // accesses: 1
    byte _padding_0x18[4];
    SPlugGpuLoadFx * field_0x1c; // accesses: 2
    SPlugGpuLoadFx * field_0x20; // accesses: 1
    byte _padding_0x24[28];
    CPlugVolumeProjector * field_0x40; // accesses: 1
    CPlugVolumeProjector * field_0x44; // accesses: 1
    byte _padding_0x48[120];
    ulong * field_0xc0; // accesses: 7
    byte _padding_0xc4[16];
    GmVec4 * field_0xd4; // accesses: 1
    byte _padding_0xd8[8];
    GmVec4 * field_0xe0; // accesses: 1
    GmVec4 * field_0xe4; // accesses: 1
    GmVec4 * field_0xe8; // accesses: 1
    GmVec4 * field_0xec; // accesses: 1
    GmVec4 * field_0xf0; // accesses: 1
    byte _padding_0xf4[56];
    CSystemFileMemMapped * field_0x12c; // accesses: 2
};

struct CSceneToySeaHouleTable {
    byte _padding_0x0[112];
    void * field_0x70; // accesses: 6
    byte _padding_0x74[4];
    GmField2 * field_0x78; // accesses: 2
    int field_0x7c; // accesses: 4
    float field_0x80; // accesses: 3
};

struct CSceneVehicle {
    byte _padding_0x0[4];
    int * field_0x4; // accesses: 11
    CSystemFid * field_0x8; // accesses: 21
    float field_0xc; // accesses: 3
    int field_0x10; // accesses: 4
    float field_0x14; // accesses: 7
    short field_0x16; // accesses: 1
    CPlugFileSnd * field_0x18; // accesses: 14
    byte _padding_0x1c[4];
    undefined4 field_0x20; // accesses: 1
    int field_0x24; // accesses: 5
    int field_0x28; // accesses: 12
    int field_0x2c; // accesses: 1
    SPlugFaceCull * field_0x30; // accesses: 26
    byte _padding_0x34[4];
    undefined4 field_0x38; // accesses: 3
    float field_0x3c; // accesses: 3
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    float field_0x48; // accesses: 20
    int field_0x4c; // accesses: 16
    float field_0x50; // accesses: 15
    float field_0x54; // accesses: 4
    float field_0x58; // accesses: 16
    float field_0x5c; // accesses: 10
    int field_0x60; // accesses: 25
    CSceneToyCharacter * field_0x64; // accesses: 24
    CMwStack * field_0x68; // accesses: 23
    GxLight * field_0x6c; // accesses: 8
    float field_0x70; // accesses: 8
    float field_0x74; // accesses: 5
    float field_0x78; // accesses: 6
    int field_0x7c; // accesses: 7
    float field_0x80; // accesses: 3
    float field_0x84; // accesses: 3
    int field_0x88; // accesses: 3
    int field_0x8c; // accesses: 3
    float field_0x90; // accesses: 6
    int field_0x94; // accesses: 6
    undefined4 field_0x98; // accesses: 5
    byte _padding_0x9c[4];
    code * field_0xa0; // accesses: 4
    CPlugTreeVisualMip * field_0xa4; // accesses: 5
    int field_0xa8; // accesses: 5
    undefined4 field_0xac; // accesses: 2
    int field_0xb0; // accesses: 3
    undefined4 field_0xb4; // accesses: 2
    int field_0xb8; // accesses: 4
    undefined4 field_0xbc; // accesses: 2
    undefined4 field_0xc0; // accesses: 2
    undefined4 field_0xc4; // accesses: 2
    undefined4 field_0xc8; // accesses: 2
    undefined4 field_0xcc; // accesses: 2
    float field_0xd0; // accesses: 2
    byte _padding_0xd4[132];
    float field_0x158; // accesses: 3
    float field_0x15c; // accesses: 2
    byte _padding_0x160[4];
    float field_0x164; // accesses: 2
    float field_0x168; // accesses: 1
    SVisualHandler * field_0x16c; // accesses: 1
    byte _padding_0x170[8];
    float field_0x178; // accesses: 1
    byte _padding_0x17c[120];
    float field_0x1f4; // accesses: 2
    int field_0x1f8; // accesses: 4
    uint field_0x1fc; // accesses: 2
    byte _padding_0x200[4];
    undefined4 field_0x204; // accesses: 2
    undefined4 field_0x208; // accesses: 2
    undefined4 field_0x20c; // accesses: 2
    int field_0x210; // accesses: 3
    byte _padding_0x214[40];
    undefined4 field_0x23c; // accesses: 1
    undefined4 field_0x240; // accesses: 1
    byte _padding_0x244[4];
    undefined4 field_0x248; // accesses: 3
    byte _padding_0x24c[20];
    int field_0x260; // accesses: 16
    int field_0x264; // accesses: 15
    int field_0x268; // accesses: 20
    int field_0x26c; // accesses: 16
    int field_0x270; // accesses: 18
    int field_0x274; // accesses: 16
    int field_0x278; // accesses: 18
    int field_0x27c; // accesses: 16
    int field_0x280; // accesses: 16
    int field_0x284; // accesses: 16
    int field_0x288; // accesses: 17
    int field_0x28c; // accesses: 7
    byte _padding_0x290[8];
    int field_0x298; // accesses: 7
    byte _padding_0x29c[8];
    int field_0x2a4; // accesses: 2
    int field_0x2a8; // accesses: 3
    byte _padding_0x2ac[36];
    undefined4 field_0x2d0; // accesses: 8
    undefined4 field_0x2d4; // accesses: 3
    int field_0x2d8; // accesses: 12
    int field_0x2dc; // accesses: 4
};

struct CSceneVehicleBall {
    byte _padding_0x0[40];
    int field_0x28; // accesses: 2
    byte _padding_0x2c[36];
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    undefined4 field_0x58; // accesses: 1
    byte _padding_0x5c[448];
    undefined4 field_0x21c; // accesses: 1
    byte _padding_0x220[16];
    undefined4 field_0x230; // accesses: 1
    byte _padding_0x234[248];
    int field_0x32c; // accesses: 1
    byte _padding_0x330[8];
    undefined4 field_0x338; // accesses: 1
    undefined4 field_0x33c; // accesses: 1
    undefined4 field_0x340; // accesses: 1
    byte _padding_0x344[284];
    float field_0x460; // accesses: 1
    byte _padding_0x464[4];
    undefined4 field_0x468; // accesses: 1
    undefined4 field_0x46c; // accesses: 1
    undefined4 field_0x470; // accesses: 1
    byte _padding_0x474[16];
    undefined4 field_0x484; // accesses: 1
    undefined4 field_0x488; // accesses: 1
    byte _padding_0x48c[8];
    float field_0x494; // accesses: 1
    float field_0x498; // accesses: 1
    float field_0x49c; // accesses: 1
    float field_0x4a0; // accesses: 1
    float field_0x4a4; // accesses: 1
    float field_0x4a8; // accesses: 1
    float field_0x4ac; // accesses: 1
    float field_0x4b0; // accesses: 1
    float field_0x4b4; // accesses: 1
    byte _padding_0x4b8[20];
    float field_0x4cc; // accesses: 1
    float field_0x4d0; // accesses: 1
    float field_0x4d4; // accesses: 1
};

struct CSceneVehicleBall_SVehicleBallState {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    byte _padding_0x34[48];
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1
    undefined4 field_0x78; // accesses: 1
    undefined4 field_0x7c; // accesses: 1
};

struct CSceneVehicleCar {
    byte _padding_0x0[4];
    ulong field_0x4; // accesses: 72
    char field_0x6; // accesses: 2
    byte _padding_0x7[1];
    CSceneVehicleCarTuning * field_0x8; // accesses: 74
    ushort field_0xc; // accesses: 25
    byte _padding_0xe[2];
    float field_0x10; // accesses: 17
    CPlugAudio * field_0x14; // accesses: 26
    int field_0x18; // accesses: 15
    float field_0x1c; // accesses: 8
    float field_0x20; // accesses: 11
    CPlugBitmap * field_0x24; // accesses: 11
    int field_0x28; // accesses: 78
    float field_0x2c; // accesses: 10
    float field_0x30; // accesses: 9
    float field_0x34; // accesses: 15
    float field_0x38; // accesses: 13
    float field_0x3c; // accesses: 9
    float field_0x40; // accesses: 13
    float field_0x44; // accesses: 7
    CPlugFileImg * field_0x48; // accesses: 18
    CSceneVehicleCar * field_0x4c; // accesses: 4
    float field_0x50; // accesses: 29
    float field_0x54; // accesses: 35
    float field_0x58; // accesses: 16
    float field_0x5c; // accesses: 3
    float field_0x60; // accesses: 24
    int field_0x64; // accesses: 201
    int field_0x68; // accesses: 27
    float field_0x6c; // accesses: 16
    float field_0x70; // accesses: 4
    float field_0x74; // accesses: 4
    float field_0x78; // accesses: 22
    float field_0x7c; // accesses: 14
    float field_0x80; // accesses: 4
    float field_0x84; // accesses: 2
    float field_0x88; // accesses: 3
    int field_0x8c; // accesses: 8
    byte _padding_0x90[24];
    undefined4 field_0xa8; // accesses: 2
    undefined4 field_0xac; // accesses: 2
    undefined4 field_0xb0; // accesses: 5
    float field_0xb4; // accesses: 16
    float field_0xb8; // accesses: 12
    float field_0xbc; // accesses: 10
    float field_0xc0; // accesses: 4
    float field_0xc4; // accesses: 4
    byte _padding_0xc8[12];
    float field_0xd4; // accesses: 2
    code * field_0xd8; // accesses: 1
    int field_0xdc; // accesses: 1
    byte _padding_0xe0[8];
    int field_0xe8; // accesses: 1
    byte _padding_0xec[28];
    float field_0x108; // accesses: 3
    float field_0x10c; // accesses: 3
    float field_0x110; // accesses: 3
    undefined4 field_0x114; // accesses: 1
    undefined4 field_0x118; // accesses: 1
    undefined4 field_0x11c; // accesses: 1
    float field_0x120; // accesses: 9
    int field_0x124; // accesses: 22
    ushort field_0x128; // accesses: 13
    byte _padding_0x12a[2];
    float field_0x12c; // accesses: 28
    float field_0x130; // accesses: 2
    float field_0x134; // accesses: 2
    ulong field_0x138; // accesses: 2
    undefined4 field_0x13c; // accesses: 2
    int field_0x140; // accesses: 4
    float field_0x144; // accesses: 12
    float field_0x148; // accesses: 12
    float field_0x14c; // accesses: 12
    undefined4 field_0x150; // accesses: 2
    float field_0x154; // accesses: 5
    float field_0x158; // accesses: 5
    float field_0x15c; // accesses: 7
    float field_0x160; // accesses: 6
    float field_0x164; // accesses: 6
    float field_0x168; // accesses: 6
    char field_0x16c; // accesses: 2
    byte _padding_0x16d[11];
    float field_0x178; // accesses: 4
    float field_0x17c; // accesses: 1
    byte _padding_0x180[20];
    float field_0x194; // accesses: 3
    undefined4 field_0x198; // accesses: 1
    byte _padding_0x19c[16];
    float field_0x1ac; // accesses: 2
    byte _padding_0x1b0[32];
    float field_0x1d0; // accesses: 2
    undefined4 field_0x1d4; // accesses: 1
    undefined4 field_0x1d8; // accesses: 1
    float field_0x1dc; // accesses: 3
    float field_0x1e0; // accesses: 3
    float field_0x1e4; // accesses: 3
    float field_0x1e8; // accesses: 4
    float field_0x1ec; // accesses: 3
    float field_0x1f0; // accesses: 3
    float field_0x1f4; // accesses: 6
    float field_0x1f8; // accesses: 6
    float field_0x1fc; // accesses: 16
    byte _padding_0x200[16];
    undefined4 field_0x210; // accesses: 1
    undefined4 field_0x214; // accesses: 1
    undefined4 field_0x218; // accesses: 1
    float field_0x21c; // accesses: 3
    byte _padding_0x220[4];
    float field_0x224; // accesses: 3
    undefined4 field_0x228; // accesses: 2
    undefined4 field_0x22c; // accesses: 2
    float field_0x230; // accesses: 4
    byte _padding_0x234[4];
    float field_0x238; // accesses: 2
    float field_0x23c; // accesses: 3
    float field_0x240; // accesses: 3
    float field_0x244; // accesses: 7
    byte _padding_0x248[4];
    float field_0x24c; // accesses: 7
    float field_0x250; // accesses: 5
    byte _padding_0x254[16];
    int field_0x264; // accesses: 8
    int field_0x268; // accesses: 2
    CSceneSoundSource * field_0x26c; // accesses: 2
    int field_0x270; // accesses: 7
    int * field_0x274; // accesses: 4
    int field_0x278; // accesses: 4
    int field_0x27c; // accesses: 3
    CSceneSoundSource * field_0x280; // accesses: 2
    CSceneSoundSource * field_0x284; // accesses: 2
    int field_0x288; // accesses: 3
    byte _padding_0x28c[12];
    float field_0x298; // accesses: 1
    float field_0x29c; // accesses: 5
    GmIso4 * field_0x2a0; // accesses: 1
    ushort field_0x2a4; // accesses: 1
    byte _padding_0x2a6[2];
    int field_0x2a8; // accesses: 2
    int field_0x2ac; // accesses: 1
    float field_0x2b0; // accesses: 1
    float field_0x2b4; // accesses: 1
    float field_0x2b8; // accesses: 1
    float field_0x2bc; // accesses: 4
    float field_0x2c0; // accesses: 6
    float field_0x2c4; // accesses: 4
    byte _padding_0x2c8[12];
    CPlugShaderGeneric * field_0x2d4; // accesses: 2
    byte _padding_0x2d8[8];
    float field_0x2e0; // accesses: 4
    int field_0x2e4; // accesses: 22
    byte _padding_0x2e8[12];
    uint field_0x2f4; // accesses: 8
    byte _padding_0x2f8[48];
    int field_0x328; // accesses: 2
    int field_0x32c; // accesses: 2
    byte _padding_0x330[44];
    undefined4 field_0x35c; // accesses: 5
    undefined4 field_0x360; // accesses: 7
    undefined4 field_0x364; // accesses: 3
    undefined4 field_0x368; // accesses: 3
    undefined4 field_0x36c; // accesses: 3
    byte _padding_0x370[8];
    float field_0x378; // accesses: 4
    byte _padding_0x37c[36];
    CCallbackSceneVehicleBallAfterContacts * field_0x3a0; // accesses: 3
    float field_0x3a4; // accesses: 1
    undefined4 field_0x3a8; // accesses: 1
    undefined4 field_0x3ac; // accesses: 1
    undefined4 field_0x3b0; // accesses: 1
    uint field_0x3b4; // accesses: 1
    undefined4 field_0x3b8; // accesses: 1
    undefined4 field_0x3bc; // accesses: 1
    undefined4 field_0x3c0; // accesses: 1
    undefined4 field_0x3c4; // accesses: 1
    undefined4 field_0x3c8; // accesses: 1
    undefined4 field_0x3cc; // accesses: 1
    undefined4 field_0x3d0; // accesses: 1
    byte _padding_0x3d4[4];
    float field_0x3d8; // accesses: 2
    float field_0x3dc; // accesses: 2
    float field_0x3e0; // accesses: 2
    float field_0x3e4; // accesses: 2
    float field_0x3e8; // accesses: 2
    float field_0x3ec; // accesses: 2
    float field_0x3f0; // accesses: 2
    float field_0x3f4; // accesses: 2
    float field_0x3f8; // accesses: 1
    float field_0x3fc; // accesses: 1
    float field_0x400; // accesses: 1
    undefined4 field_0x404; // accesses: 2
    undefined4 field_0x408; // accesses: 2
    float field_0x40c; // accesses: 2
    float field_0x410; // accesses: 2
    float field_0x414; // accesses: 2
    float field_0x418; // accesses: 1
    byte _padding_0x41c[4];
    undefined4 field_0x420; // accesses: 1
    undefined4 field_0x424; // accesses: 1
    undefined4 field_0x428; // accesses: 1
    undefined4 field_0x42c; // accesses: 1
    uint field_0x430; // accesses: 1
    undefined4 field_0x434; // accesses: 2
    float field_0x438; // accesses: 2
    uint field_0x43c; // accesses: 1
    float field_0x440; // accesses: 2
    undefined4 field_0x444; // accesses: 1
    float field_0x448; // accesses: 1
    byte _padding_0x44c[16];
    int field_0x45c; // accesses: 1
    GmIso4 * field_0x460; // accesses: 1
    byte _padding_0x464[80];
    undefined4 field_0x4b4; // accesses: 1
    undefined4 field_0x4b8; // accesses: 1
    undefined4 field_0x4bc; // accesses: 1
    byte _padding_0x4c0[220];
    float field_0x59c; // accesses: 12
    undefined4 field_0x5a0; // accesses: 1
    undefined4 field_0x5a4; // accesses: 1
    float field_0x5a8; // accesses: 2
    float field_0x5ac; // accesses: 2
    float field_0x5b0; // accesses: 2
    float field_0x5b4; // accesses: 34
    float field_0x5b8; // accesses: 14
    float field_0x5bc; // accesses: 8
    float field_0x5c0; // accesses: 16
    int field_0x5c4; // accesses: 29
    int field_0x5c8; // accesses: 15
    float field_0x5cc; // accesses: 7
    int field_0x5d0; // accesses: 1
    int field_0x5d4; // accesses: 7
    int field_0x5d8; // accesses: 4
    int field_0x5dc; // accesses: 6
    int field_0x5e0; // accesses: 4
    int field_0x5e4; // accesses: 14
    float field_0x5e8; // accesses: 18
    byte _padding_0x5ec[4];
    float field_0x5f0; // accesses: 4
    float field_0x5f4; // accesses: 10
    CSceneVehicleCar * field_0x5f8; // accesses: 3
    CSceneVehicleCar * field_0x5fc; // accesses: 3
    float field_0x600; // accesses: 17
    int field_0x604; // accesses: 3
    float field_0x608; // accesses: 2
    CSceneVehicleCar * field_0x60c; // accesses: 29
    CSceneVehicleCar * field_0x610; // accesses: 3
    int field_0x614; // accesses: 3
    float field_0x618; // accesses: 6
    float field_0x61c; // accesses: 9
    undefined4 field_0x620; // accesses: 3
    float field_0x624; // accesses: 5
    float field_0x628; // accesses: 9
    undefined4 field_0x62c; // accesses: 3
    int field_0x630; // accesses: 4
    int field_0x634; // accesses: 2
    float field_0x638; // accesses: 10
    float field_0x63c; // accesses: 3
    int field_0x640; // accesses: 8
    undefined4 field_0x644; // accesses: 1
    undefined4 field_0x648; // accesses: 3
    float field_0x64c; // accesses: 2
    CSceneVehicleCar * field_0x650; // accesses: 6
    undefined4 field_0x654; // accesses: 12
    int field_0x658; // accesses: 12
    int field_0x65c; // accesses: 3
    int field_0x660; // accesses: 5
    int field_0x664; // accesses: 5
    int field_0x668; // accesses: 5
    byte _padding_0x66c[4];
    float field_0x670; // accesses: 6
    float field_0x674; // accesses: 6
    float field_0x678; // accesses: 6
    int field_0x67c; // accesses: 5
    int field_0x680; // accesses: 7
    float field_0x684; // accesses: 6
    float field_0x688; // accesses: 6
    float field_0x68c; // accesses: 6
    float field_0x690; // accesses: 12
    float field_0x694; // accesses: 12
    float field_0x698; // accesses: 11
    int field_0x69c; // accesses: 30
    int field_0x6a0; // accesses: 8
    byte _padding_0x6a4[16];
    float field_0x6b4; // accesses: 1
    byte _padding_0x6b8[28];
    float field_0x6d4; // accesses: 2
    float field_0x6d8; // accesses: 4
    float field_0x6dc; // accesses: 4
    float field_0x6e0; // accesses: 3
    float field_0x6e4; // accesses: 3
    float field_0x6e8; // accesses: 3
    float field_0x6ec; // accesses: 4
    float field_0x6f0; // accesses: 2
    ulong field_0x6f4; // accesses: 5
    float field_0x6f8; // accesses: 5
    undefined4 field_0x6fc; // accesses: 1
    float field_0x700; // accesses: 13
    float field_0x704; // accesses: 11
    float field_0x708; // accesses: 1
    int field_0x70c; // accesses: 3
    ulong field_0x710; // accesses: 3
    ulong * field_0x714; // accesses: 14
    undefined4 field_0x718; // accesses: 2
    undefined4 field_0x71c; // accesses: 2
    undefined4 field_0x720; // accesses: 2
    undefined4 field_0x724; // accesses: 2
    undefined4 field_0x728; // accesses: 2
    undefined4 field_0x72c; // accesses: 1
    undefined4 field_0x730; // accesses: 2
    undefined4 field_0x734; // accesses: 2
    undefined4 field_0x738; // accesses: 2
    int field_0x73c; // accesses: 3
    undefined4 field_0x740; // accesses: 1
    int field_0x744; // accesses: 12
    undefined4 field_0x748; // accesses: 5
    int field_0x74c; // accesses: 2
    byte _padding_0x750[192];
    undefined4 field_0x810; // accesses: 2
    undefined4 field_0x814; // accesses: 1
    float field_0x818; // accesses: 6
    float field_0x81c; // accesses: 7
    float field_0x820; // accesses: 7
    float field_0x824; // accesses: 5
    float field_0x828; // accesses: 5
    float field_0x82c; // accesses: 5
    byte _padding_0x830[4];
    int field_0x834; // accesses: 4
    int field_0x838; // accesses: 5
    int field_0x83c; // accesses: 5
    float field_0x840; // accesses: 8
    int field_0x844; // accesses: 2
    undefined4 field_0x848; // accesses: 1
    undefined4 field_0x84c; // accesses: 1
    undefined4 field_0x850; // accesses: 1
    undefined4 field_0x854; // accesses: 1
    undefined4 field_0x858; // accesses: 1
    undefined4 field_0x85c; // accesses: 1
    undefined4 field_0x860; // accesses: 1
    undefined4 field_0x864; // accesses: 1
    undefined4 field_0x868; // accesses: 1
    undefined4 field_0x86c; // accesses: 2
    undefined4 field_0x870; // accesses: 2
    undefined4 field_0x874; // accesses: 2
};

struct CSceneVehicleCarTuning {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 18
    int field_0x8; // accesses: 3
    byte _padding_0xc[4];
    int field_0x10; // accesses: 2
    byte _padding_0x14[4];
    int field_0x18; // accesses: 6
    byte _padding_0x1c[12];
    CFuncKeysReal * field_0x28; // accesses: 1
    float field_0x2c; // accesses: 3
    float field_0x30; // accesses: 3
    int field_0x34; // accesses: 16
    undefined4 field_0x38; // accesses: 1
    CFuncKeysReal * field_0x3c; // accesses: 1
    CFuncKeysReal * field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    CFuncKeysReal * field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    int field_0x68; // accesses: 11
    undefined4 field_0x6c; // accesses: 1
    CFuncKeysReal * field_0x70; // accesses: 1
    float field_0x74; // accesses: 3
    int field_0x78; // accesses: 12
    undefined4 field_0x7c; // accesses: 1
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
    undefined4 field_0x88; // accesses: 1
    undefined4 field_0x8c; // accesses: 1
    undefined4 field_0x90; // accesses: 1
    CFuncKeysReal * field_0x94; // accesses: 1
    undefined4 field_0x98; // accesses: 1
    undefined4 field_0x9c; // accesses: 1
    undefined4 field_0xa0; // accesses: 10
    undefined4 field_0xa4; // accesses: 1
    undefined4 field_0xa8; // accesses: 1
    undefined4 field_0xac; // accesses: 10
    undefined4 field_0xb0; // accesses: 1
    undefined4 field_0xb4; // accesses: 1
    undefined4 field_0xb8; // accesses: 10
    undefined4 field_0xbc; // accesses: 9
    undefined4 field_0xc0; // accesses: 1
    float field_0xc4; // accesses: 3
    float field_0xc8; // accesses: 3
    CFuncKeysReal * field_0xcc; // accesses: 1
    undefined4 field_0xd0; // accesses: 1
    undefined4 field_0xd4; // accesses: 1
    undefined4 field_0xd8; // accesses: 1
    undefined4 field_0xdc; // accesses: 1
    undefined4 field_0xe0; // accesses: 1
    undefined4 field_0xe4; // accesses: 1
    undefined4 field_0xe8; // accesses: 1
    undefined4 field_0xec; // accesses: 1
    float field_0xf0; // accesses: 2
    float field_0xf4; // accesses: 2
    undefined4 field_0xf8; // accesses: 2
    undefined4 field_0xfc; // accesses: 2
    undefined4 field_0x100; // accesses: 1
    CFuncKeysReal * field_0x104; // accesses: 1
    undefined4 field_0x108; // accesses: 1
    undefined4 field_0x10c; // accesses: 1
    undefined4 field_0x110; // accesses: 1
    undefined4 field_0x114; // accesses: 1
    undefined4 field_0x118; // accesses: 1
    float field_0x11c; // accesses: 3
    float field_0x120; // accesses: 4
    undefined4 field_0x124; // accesses: 1
    float field_0x128; // accesses: 1
    undefined4 field_0x12c; // accesses: 1
    undefined4 field_0x130; // accesses: 1
    undefined4 field_0x134; // accesses: 1
    CFuncKeysReal * field_0x138; // accesses: 1
    CFuncKeysReal * field_0x13c; // accesses: 1
    CFuncKeysReal * field_0x140; // accesses: 1
    undefined4 field_0x144; // accesses: 1
    undefined4 field_0x148; // accesses: 1
    CFuncKeysReal * field_0x14c; // accesses: 1
    undefined4 field_0x150; // accesses: 1
    undefined4 field_0x154; // accesses: 1
    CFuncKeysReal * field_0x158; // accesses: 1
    undefined4 field_0x15c; // accesses: 2
    undefined4 field_0x160; // accesses: 2
    undefined4 field_0x164; // accesses: 2
    undefined4 field_0x168; // accesses: 1
    undefined4 field_0x16c; // accesses: 1
    float field_0x170; // accesses: 1
    undefined4 field_0x174; // accesses: 1
    undefined4 field_0x178; // accesses: 1
    undefined4 field_0x17c; // accesses: 1
    float field_0x180; // accesses: 1
    undefined4 field_0x184; // accesses: 1
    undefined4 field_0x188; // accesses: 1
    undefined4 field_0x18c; // accesses: 1
    undefined4 field_0x190; // accesses: 1
    CFuncKeysReal * field_0x194; // accesses: 1
    undefined4 field_0x198; // accesses: 1
    undefined4 field_0x19c; // accesses: 1
    undefined4 field_0x1a0; // accesses: 1
    undefined4 field_0x1a4; // accesses: 1
    undefined4 field_0x1a8; // accesses: 1
    undefined4 field_0x1ac; // accesses: 1
    undefined4 field_0x1b0; // accesses: 1
    undefined4 field_0x1b4; // accesses: 10
    undefined4 field_0x1b8; // accesses: 1
    undefined4 field_0x1bc; // accesses: 9
    undefined4 field_0x1c0; // accesses: 1
    undefined4 field_0x1c4; // accesses: 8
    undefined4 field_0x1c8; // accesses: 1
    undefined4 field_0x1cc; // accesses: 1
    undefined4 field_0x1d0; // accesses: 1
    undefined4 field_0x1d4; // accesses: 1
    undefined4 field_0x1d8; // accesses: 1
    undefined4 field_0x1dc; // accesses: 1
    undefined4 field_0x1e0; // accesses: 11
    float field_0x1e4; // accesses: 2
    undefined4 field_0x1e8; // accesses: 1
    undefined4 field_0x1ec; // accesses: 8
    undefined4 field_0x1f0; // accesses: 8
    CFuncKeysReal * field_0x1f4; // accesses: 1
    undefined4 field_0x1f8; // accesses: 1
    undefined4 field_0x1fc; // accesses: 1
    undefined4 field_0x200; // accesses: 1
    undefined4 field_0x204; // accesses: 1
    float field_0x208; // accesses: 3
    float field_0x20c; // accesses: 3
    undefined4 field_0x210; // accesses: 8
    undefined4 field_0x214; // accesses: 8
    undefined4 field_0x218; // accesses: 10
    undefined4 field_0x21c; // accesses: 1
    float field_0x220; // accesses: 1
    undefined4 field_0x224; // accesses: 11
    CFuncKeysReal * field_0x228; // accesses: 1
    CFuncKeysReal * field_0x22c; // accesses: 1
    undefined4 field_0x230; // accesses: 11
    undefined4 field_0x234; // accesses: 1
    undefined4 field_0x238; // accesses: 1
    undefined4 field_0x23c; // accesses: 1
    CFuncKeysReal * field_0x240; // accesses: 1
    float field_0x244; // accesses: 1
    CFuncKeysReal * field_0x248; // accesses: 1
    CFuncKeysReal * field_0x24c; // accesses: 1
    undefined4 field_0x250; // accesses: 13
    float field_0x254; // accesses: 3
    float field_0x258; // accesses: 3
    undefined4 field_0x25c; // accesses: 11
    undefined4 field_0x260; // accesses: 11
    undefined4 field_0x264; // accesses: 1
    float field_0x268; // accesses: 1
    float field_0x26c; // accesses: 1
    CFuncKeysReal * field_0x270; // accesses: 1
    CFuncKeysReal * field_0x274; // accesses: 1
    undefined4 field_0x278; // accesses: 1
    float field_0x27c; // accesses: 1
    CFuncKeysReal * field_0x280; // accesses: 1
    float field_0x284; // accesses: 3
    undefined4 field_0x288; // accesses: 11
    undefined4 field_0x28c; // accesses: 1
    float field_0x290; // accesses: 3
    float field_0x294; // accesses: 3
    undefined4 field_0x298; // accesses: 1
    CFuncKeysReal * field_0x29c; // accesses: 1
    undefined4 field_0x2a0; // accesses: 1
    undefined4 field_0x2a4; // accesses: 11
    undefined4 field_0x2a8; // accesses: 1
    undefined4 field_0x2ac; // accesses: 1
    CFuncKeysReal * field_0x2b0; // accesses: 1
    undefined4 field_0x2b4; // accesses: 1
    CFuncKeysReal * field_0x2b8; // accesses: 1
    undefined4 field_0x2bc; // accesses: 1
    undefined4 field_0x2c0; // accesses: 1
    byte _padding_0x2c4[12];
    float field_0x2d0; // accesses: 5
    byte _padding_0x2d4[24];
    undefined4 field_0x2ec; // accesses: 1
    undefined4 field_0x2f0; // accesses: 1
    undefined4 field_0x2f4; // accesses: 1
    byte _padding_0x2f8[36];
    undefined4 field_0x31c; // accesses: 1
    undefined4 field_0x320; // accesses: 1
    undefined4 field_0x324; // accesses: 1
    undefined4 field_0x328; // accesses: 1
    float field_0x32c; // accesses: 3
    float field_0x330; // accesses: 3
    float field_0x334; // accesses: 3
    float field_0x338; // accesses: 3
    undefined4 field_0x33c; // accesses: 1
    CFuncKeysReal * field_0x340; // accesses: 1
    undefined4 field_0x344; // accesses: 1
    undefined4 field_0x348; // accesses: 1
    float field_0x34c; // accesses: 1
    undefined4 field_0x350; // accesses: 2
    undefined4 field_0x354; // accesses: 1
    undefined4 field_0x358; // accesses: 1
    undefined4 field_0x35c; // accesses: 1
    undefined4 field_0x360; // accesses: 1
    undefined4 field_0x364; // accesses: 1
    undefined4 field_0x368; // accesses: 1
    undefined4 field_0x36c; // accesses: 8
    byte _padding_0x370[8];
    undefined4 field_0x378; // accesses: 3
    undefined4 field_0x37c; // accesses: 1
    undefined4 field_0x380; // accesses: 9
    undefined4 field_0x384; // accesses: 1
    undefined4 field_0x388; // accesses: 1
    undefined4 field_0x38c; // accesses: 1
    undefined4 field_0x390; // accesses: 1
    undefined4 field_0x394; // accesses: 1
    undefined4 field_0x398; // accesses: 2
    float field_0x39c; // accesses: 2
    float field_0x3a0; // accesses: 2
    undefined4 field_0x3a4; // accesses: 1
    float field_0x3a8; // accesses: 1
};

struct CSceneVehicleCar_SSimulationWheel_SState {
    byte _padding_0x0[4];
    SParam * field_0x4; // accesses: 2
    float field_0x8; // accesses: 2
    undefined2 field_0xc; // accesses: 1
    byte _padding_0xe[2];
    int field_0x10; // accesses: 2
    int field_0x14; // accesses: 2
};

struct CSceneVehicleCar_SVehicleCarState {
    byte _padding_0x0[128];
    float field_0x80; // accesses: 3
    undefined4 field_0x84; // accesses: 2
    undefined4 field_0x88; // accesses: 2
    undefined4 field_0x8c; // accesses: 2
    undefined4 field_0x90; // accesses: 2
    undefined4 field_0x94; // accesses: 2
    undefined4 field_0x98; // accesses: 2
    undefined4 field_0x9c; // accesses: 2
    undefined4 field_0xa0; // accesses: 2
    undefined4 field_0xa4; // accesses: 2
};

struct CSceneVehicleGlider {
    byte _padding_0x0[40];
    int field_0x28; // accesses: 8
    byte _padding_0x2c[692];
    float field_0x2e0; // accesses: 1
    float field_0x2e4; // accesses: 1
    float field_0x2e8; // accesses: 2
    byte _padding_0x2ec[264];
    float field_0x3f4; // accesses: 1
    float field_0x3f8; // accesses: 1
    float field_0x3fc; // accesses: 1
    float field_0x400; // accesses: 1
    float field_0x404; // accesses: 1
    float field_0x408; // accesses: 1
    float field_0x40c; // accesses: 1
    float field_0x410; // accesses: 2
    float field_0x414; // accesses: 1
    float field_0x418; // accesses: 1
    float field_0x41c; // accesses: 1
    float field_0x420; // accesses: 2
    float field_0x424; // accesses: 1
};

struct CSceneVehicleMaterial {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 2
    undefined4 field_0x1c; // accesses: 2
    undefined4 field_0x20; // accesses: 2
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    byte _padding_0x38[4];
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
};

struct CSceneVehicleSpeedBoat {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 12
    float field_0x8; // accesses: 12
    float field_0xc; // accesses: 1
    float field_0x10; // accesses: 9
    float field_0x14; // accesses: 11
    float field_0x18; // accesses: 1
    float field_0x1c; // accesses: 1
    float field_0x20; // accesses: 1
    GmVec3 * field_0x24; // accesses: 1
    float field_0x28; // accesses: 32
    float field_0x2c; // accesses: 3
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    float field_0x38; // accesses: 2
    float field_0x3c; // accesses: 4
    int field_0x40; // accesses: 1
    float field_0x44; // accesses: 2
    short field_0x48; // accesses: 1
    byte _padding_0x4a[2];
    float field_0x4c; // accesses: 1
    float field_0x50; // accesses: 5
    float field_0x54; // accesses: 5
    float field_0x58; // accesses: 8
    byte _padding_0x5c[8];
    int field_0x64; // accesses: 4
    float field_0x68; // accesses: 3
    float field_0x6c; // accesses: 3
    float field_0x70; // accesses: 3
    CSceneVehicleSpeedBoat * field_0x74; // accesses: 1
    float field_0x78; // accesses: 3
    byte _padding_0x7c[16];
    GmMat3 * field_0x8c; // accesses: 1
    byte _padding_0x90[8];
    GmMat3 * field_0x98; // accesses: 1
    byte _padding_0x9c[8];
    float field_0xa4; // accesses: 1
    byte _padding_0xa8[4];
    float field_0xac; // accesses: 1
    byte _padding_0xb0[12];
    float field_0xbc; // accesses: 1
    float field_0xc0; // accesses: 2
    float field_0xc4; // accesses: 1
    float field_0xc8; // accesses: 1
    undefined4 field_0xcc; // accesses: 1
    float field_0xd0; // accesses: 1
    float field_0xd4; // accesses: 1
    float field_0xd8; // accesses: 17
    float field_0xdc; // accesses: 2
    GmMat3 * field_0xe0; // accesses: 1
    CSceneSector * field_0xe4; // accesses: 1
    float field_0xe8; // accesses: 3
    byte _padding_0xec[4];
    float field_0xf0; // accesses: 3
    float field_0xf4; // accesses: 1
    float field_0xf8; // accesses: 1
    byte _padding_0xfc[4];
    undefined4 field_0x100; // accesses: 1
    float field_0x104; // accesses: 1
    float field_0x108; // accesses: 1
    float field_0x10c; // accesses: 2
    float field_0x110; // accesses: 1
    byte _padding_0x114[4];
    float field_0x118; // accesses: 2
    byte _padding_0x11c[4];
    GmVec3 * field_0x120; // accesses: 1
    GmMat3 * field_0x124; // accesses: 1
    CSceneVehicleSpeedBoat * field_0x128; // accesses: 1
    float field_0x12c; // accesses: 2
    float field_0x130; // accesses: 1
    byte _padding_0x134[16];
    float field_0x144; // accesses: 2
    float field_0x148; // accesses: 1
    float field_0x14c; // accesses: 1
    float field_0x150; // accesses: 2
    float field_0x154; // accesses: 1
    byte _padding_0x158[32];
    GmMat3 * field_0x178; // accesses: 1
    byte _padding_0x17c[356];
    int field_0x2e0; // accesses: 3
    undefined4 field_0x2e4; // accesses: 2
    float field_0x2e8; // accesses: 5
};

struct CSceneVehicleStruct {
    byte _padding_0x0[68];
    undefined4 field_0x44; // accesses: 8
    undefined4 field_0x48; // accesses: 8
    undefined4 field_0x4c; // accesses: 8
};

struct CSceneVehicleStruct_SSimulationWheel {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
};

struct CSceneVehicleStruct_SVisualArm {
    byte _padding_0x0[8];
    undefined4 field_0x8; // accesses: 1
};

struct CSceneVehicleStruct_SVisualWheel {
    byte _padding_0x0[32];
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
};

struct CSceneVehicleTuning {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 2
    byte _padding_0x8[16];
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    CFuncSegment * field_0x24; // accesses: 15
};

struct CSceneVehicleTunings {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 4
    byte _padding_0x8[8];
    int field_0x10; // accesses: 4
    byte _padding_0x14[4];
    int field_0x18; // accesses: 13
    byte _padding_0x1c[4];
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 3
};

struct CSceneVehicle_SVehicleState {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 3
    float field_0x8; // accesses: 3
    float field_0xc; // accesses: 3
    float field_0x10; // accesses: 3
    undefined4 field_0x14; // accesses: 2
    float field_0x18; // accesses: 3
    undefined4 field_0x1c; // accesses: 2
    float field_0x20; // accesses: 3
    float field_0x24; // accesses: 3
    float field_0x28; // accesses: 3
    float field_0x2c; // accesses: 3
    float field_0x30; // accesses: 3
    byte _padding_0x34[48];
    undefined4 field_0x64; // accesses: 2
    undefined4 field_0x68; // accesses: 2
    float field_0x6c; // accesses: 4
    float field_0x70; // accesses: 4
    float field_0x74; // accesses: 4
    float field_0x78; // accesses: 3
    float field_0x7c; // accesses: 3
};

struct CSceneVehicle_SVisualHandler {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    byte _padding_0x8[148];
    byte field_0x9c; // accesses: 3
    byte _padding_0x9d[7];
    void * field_0xa4; // accesses: 1
};

struct CSystemArchiveNod {
    byte _padding_0x0[4];
    CSystemFid * field_0x4; // accesses: 46
    CSystemFid * field_0x8; // accesses: 21
    ulong field_0xc; // accesses: 11
    CSystemFid * field_0x10; // accesses: 9
    CSystemFids * field_0x14; // accesses: 8
    ulong field_0x18; // accesses: 17
    int field_0x1c; // accesses: 48
    byte _padding_0x20[8];
    int field_0x28; // accesses: 2
    byte _padding_0x2c[4];
    int field_0x30; // accesses: 2
    byte _padding_0x34[24];
    ulong field_0x4c; // accesses: 6
    CSystemFid * field_0x50; // accesses: 90
    byte _padding_0x54[4];
    CSystemFids * field_0x58; // accesses: 2
    ulong field_0x5c; // accesses: 16
    int field_0x60; // accesses: 1
    ulong field_0x64; // accesses: 4
    byte _padding_0x68[4];
    undefined4 * field_0x6c; // accesses: 10
    byte _padding_0x70[4];
    CClassicBufferMemory * field_0x74; // accesses: 3
    CSystemArchiveNod * field_0x78; // accesses: 12
    int field_0x7c; // accesses: 5
    undefined4 field_0x80; // accesses: 2
    int field_0x84; // accesses: 5
    ulong field_0x88; // accesses: 5
    int field_0x8c; // accesses: 9
    CSystemArchiveNod * field_0x90; // accesses: 7
    undefined4 field_0x94; // accesses: 2
    undefined4 * field_0x98; // accesses: 5
    void * field_0x9c; // accesses: 6
    int field_0xa0; // accesses: 2
    CClassicBufferMemory * field_0xa4; // accesses: 12
};

struct CSystemArchiveNod_SHeaderFolderDep {
    byte _padding_0x0[8];
    int field_0x8; // accesses: 2
};

struct CSystemConfig {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    undefined * field_0x1c; // accesses: 1
    int field_0x20; // accesses: 4
    undefined4 field_0x24; // accesses: 6
    CSystemConfigDisplay * field_0x28; // accesses: 3
    undefined4 field_0x2c; // accesses: 2
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1
    int field_0x3c; // accesses: 5
    int field_0x40; // accesses: 5
    undefined4 field_0x44; // accesses: 3
    undefined * field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined * field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 2
    undefined4 field_0x70; // accesses: 1
    undefined * field_0x74; // accesses: 1
    undefined4 field_0x78; // accesses: 1
    undefined * field_0x7c; // accesses: 1
    byte _padding_0x80[20];
    undefined4 field_0x94; // accesses: 1
    undefined4 field_0x98; // accesses: 1
    undefined * field_0x9c; // accesses: 1
    undefined4 field_0xa0; // accesses: 1
    undefined4 field_0xa4; // accesses: 1
    undefined4 field_0xa8; // accesses: 1
    undefined * field_0xac; // accesses: 1
    undefined4 field_0xb0; // accesses: 1
    undefined4 field_0xb4; // accesses: 1
    undefined4 field_0xb8; // accesses: 1
    byte _padding_0xbc[12];
    undefined4 field_0xc8; // accesses: 1
    undefined4 field_0xcc; // accesses: 1
    undefined4 field_0xd0; // accesses: 1
    undefined4 field_0xd4; // accesses: 1
    undefined4 field_0xd8; // accesses: 1
    undefined4 field_0xdc; // accesses: 1
    undefined4 field_0xe0; // accesses: 1
    undefined4 field_0xe4; // accesses: 1
    undefined * field_0xe8; // accesses: 1
    undefined4 field_0xec; // accesses: 1
    undefined * field_0xf0; // accesses: 1
    undefined4 field_0xf4; // accesses: 1
    undefined4 field_0xf8; // accesses: 1
    undefined4 field_0xfc; // accesses: 1
    undefined4 field_0x100; // accesses: 1
    undefined4 field_0x104; // accesses: 1
    undefined4 field_0x108; // accesses: 1
    undefined4 field_0x10c; // accesses: 1
    undefined4 field_0x110; // accesses: 1
    undefined * field_0x114; // accesses: 1
    undefined4 field_0x118; // accesses: 1
    undefined4 field_0x11c; // accesses: 1
    undefined4 field_0x120; // accesses: 1
    undefined4 field_0x124; // accesses: 1
    undefined4 field_0x128; // accesses: 1
    undefined4 field_0x12c; // accesses: 1
    undefined * field_0x130; // accesses: 1
    undefined4 field_0x134; // accesses: 1
    undefined4 field_0x138; // accesses: 1
    undefined4 field_0x13c; // accesses: 1
    undefined4 field_0x140; // accesses: 1
    undefined4 field_0x144; // accesses: 1
    undefined4 field_0x148; // accesses: 6
    undefined4 field_0x14c; // accesses: 5
    undefined4 field_0x150; // accesses: 5
    undefined4 field_0x154; // accesses: 5
    undefined4 field_0x158; // accesses: 8
    undefined4 field_0x15c; // accesses: 8
    undefined4 field_0x160; // accesses: 7
    undefined4 field_0x164; // accesses: 6
    undefined4 field_0x168; // accesses: 1
    undefined4 field_0x16c; // accesses: 11
    undefined4 field_0x170; // accesses: 10
    undefined4 field_0x174; // accesses: 1
    undefined4 field_0x178; // accesses: 1
    undefined4 field_0x17c; // accesses: 1
    undefined4 field_0x180; // accesses: 1
    undefined4 field_0x184; // accesses: 1
    undefined4 field_0x188; // accesses: 1
    undefined4 field_0x18c; // accesses: 1
    undefined4 field_0x190; // accesses: 1
    undefined * field_0x194; // accesses: 1
    undefined4 field_0x198; // accesses: 1
    undefined * field_0x19c; // accesses: 1
    undefined4 field_0x1a0; // accesses: 1
    byte _padding_0x1a4[20];
    int field_0x1b8; // accesses: 2
    int field_0x1bc; // accesses: 2
    int field_0x1c0; // accesses: 2
    int field_0x1c4; // accesses: 2
    int field_0x1c8; // accesses: 2
};

struct CSystemConfigDisplay {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 2
    byte _padding_0x8[12];
    int field_0x14; // accesses: 2
    int field_0x18; // accesses: 2
    undefined4 field_0x1c; // accesses: 2
    undefined4 field_0x20; // accesses: 2
    undefined4 field_0x24; // accesses: 2
    undefined4 field_0x28; // accesses: 2
    undefined4 field_0x2c; // accesses: 2
    undefined4 field_0x30; // accesses: 2
    undefined4 field_0x34; // accesses: 3
    undefined4 field_0x38; // accesses: 3
    int field_0x3c; // accesses: 3
    int field_0x40; // accesses: 7
    int field_0x44; // accesses: 6
    undefined4 field_0x48; // accesses: 10
    undefined4 field_0x4c; // accesses: 16
    undefined4 field_0x50; // accesses: 4
    undefined4 field_0x54; // accesses: 16
    undefined4 field_0x58; // accesses: 3
    undefined4 field_0x5c; // accesses: 12
    int field_0x60; // accesses: 9
    int field_0x64; // accesses: 8
    int field_0x68; // accesses: 13
    undefined4 field_0x6c; // accesses: 7
    undefined4 field_0x70; // accesses: 7
    undefined4 field_0x74; // accesses: 7
    undefined4 field_0x78; // accesses: 14
    undefined4 field_0x7c; // accesses: 10
    undefined4 field_0x80; // accesses: 2
    float field_0x84; // accesses: 11
    undefined4 field_0x88; // accesses: 2
    undefined4 field_0x8c; // accesses: 3
    undefined4 field_0x90; // accesses: 3
    undefined4 field_0x94; // accesses: 3
    int field_0x98; // accesses: 3
    undefined4 field_0x9c; // accesses: 2
    undefined4 field_0xa0; // accesses: 2
    undefined4 field_0xa4; // accesses: 3
    undefined4 field_0xa8; // accesses: 3
    undefined4 field_0xac; // accesses: 4
    undefined4 field_0xb0; // accesses: 3
    undefined4 field_0xb4; // accesses: 3
    undefined4 field_0xb8; // accesses: 3
    undefined4 field_0xbc; // accesses: 3
    undefined4 field_0xc0; // accesses: 3
    undefined4 field_0xc4; // accesses: 3
    int field_0xc8; // accesses: 4
    undefined4 field_0xcc; // accesses: 5
    undefined4 field_0xd0; // accesses: 1
    undefined4 field_0xd4; // accesses: 22
};

struct CSystemCrashDump {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 2
    CSystemFidFile * field_0x8; // accesses: 2
    byte _padding_0xc[28];
    undefined4 field_0x28; // accesses: 2
};

struct CSystemData {
    byte _padding_0x0[4];
    CSystemFidsFolder * field_0x4; // accesses: 2
    byte _padding_0x8[12];
    int field_0x14; // accesses: 3
    undefined * field_0x18; // accesses: 1
    CSystemFid * field_0x1c; // accesses: 15
    int field_0x20; // accesses: 9
    undefined4 field_0x24; // accesses: 3
    byte _padding_0x28[32];
    int field_0x48; // accesses: 2
    byte _padding_0x4c[24];
    CSystemData * field_0x64; // accesses: 3
    int field_0x68; // accesses: 1
};

struct CSystemDataFolders {
    byte _padding_0x0[20];
    int field_0x14; // accesses: 2
    int field_0x18; // accesses: 3
};

struct CSystemEngine {
    byte _padding_0x0[4];
    SStringParam * field_0x4; // accesses: 10
    uint field_0x8; // accesses: 5
    byte _padding_0xc[8];
    CSystemFids * field_0x14; // accesses: 10
    uint field_0x18; // accesses: 2
    CSystemEngine * field_0x1c; // accesses: 3
    CSystemEngine * field_0x20; // accesses: 6
    int * field_0x24; // accesses: 6
    CSystemFids * field_0x28; // accesses: 6
    CSystemFids * field_0x2c; // accesses: 5
    CSystemFids * field_0x30; // accesses: 5
    undefined4 field_0x34; // accesses: 1
    byte _padding_0x38[20];
    CSystemFids * field_0x4c; // accesses: 3
    CSystemFids * field_0x50; // accesses: 5
    CSystemEngine * field_0x54; // accesses: 1
    byte _padding_0x58[4];
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined * field_0x68; // accesses: 1
    undefined4 * field_0x6c; // accesses: 3
    byte _padding_0x70[4];
    CClassicBuffer * field_0x74; // accesses: 1
    byte _padding_0x78[280];
    uint field_0x190; // accesses: 1
};

struct CSystemFid {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 13
    CSystemFid * field_0x8; // accesses: 5
    undefined4 field_0xc; // accesses: 2
    int field_0x10; // accesses: 1
    CSystemFids * field_0x14; // accesses: 10
    int field_0x18; // accesses: 3
    undefined4 field_0x1c; // accesses: 3
    CSystemFid * field_0x20; // accesses: 14
    byte _padding_0x24[8];
    int field_0x2c; // accesses: 2
    CSystemFid * field_0x30; // accesses: 8
    byte _padding_0x34[48];
    ulong field_0x64; // accesses: 6
    int field_0x68; // accesses: 44
    undefined4 * field_0x6c; // accesses: 9
    CLoader * field_0x70; // accesses: 2
    byte _padding_0x74[12];
    uint field_0x80; // accesses: 3
    int field_0x84; // accesses: 3
};

struct CSystemFidFile {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    byte _padding_0x8[12];
    int * field_0x14; // accesses: 4
    undefined4 field_0x18; // accesses: 1
    uint field_0x1c; // accesses: 2
    byte _padding_0x20[76];
    undefined ** field_0x6c; // accesses: 2
    byte _padding_0x70[4];
    undefined4 field_0x74; // accesses: 3
    undefined * field_0x78; // accesses: 4
    byte _padding_0x7c[4];
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
};

struct CSystemFidMemory {
    byte _padding_0x0[24];
    undefined4 field_0x18; // accesses: 1
    byte _padding_0x1c[80];
    undefined4 field_0x6c; // accesses: 1
    byte _padding_0x70[4];
    undefined4 * field_0x74; // accesses: 3
    int field_0x78; // accesses: 2
};

struct CSystemFidParameters {
    byte _padding_0x0[4];
    CHmsCorpus ** field_0x4; // accesses: 4
    ulong * field_0x8; // accesses: 2
    byte _padding_0xc[8];
    ulong field_0x14; // accesses: 4
    undefined * field_0x18; // accesses: 2
    undefined4 field_0x1c; // accesses: 2
    undefined4 field_0x20; // accesses: 2
    CFastStringInt * field_0x24; // accesses: 2
    ulong field_0x28; // accesses: 8
    int field_0x2c; // accesses: 13
};

struct CSystemFidParameters_SParam {
    byte _padding_0x0[4];
    SParam * field_0x4; // accesses: 1
    EParamType field_0x8; // accesses: 1
    ulong * field_0xc; // accesses: 1
};

struct CSystemFidParameters_SParam_Fid {
    byte _padding_0x0[36];
    CSystemFid * field_0x24; // accesses: 1
};

struct CSystemFidParameters_SParam_Fid_Common {
    byte _padding_0x0[4];
    char * field_0x4; // accesses: 1
    byte _padding_0x5[11];
    ulong field_0x10; // accesses: 1
    CSystemPackDesc * field_0x14; // accesses: 1
    byte _padding_0x18[8];
    undefined4 field_0x20; // accesses: 1
};

struct CSystemFidParameters_SParam_Fids {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 2
    byte _padding_0x8[8];
    int field_0x10; // accesses: 2
    int field_0x14; // accesses: 2
    int * field_0x18; // accesses: 4
    int * field_0x1c; // accesses: 3
    byte _padding_0x20[4];
    CSystemFids * field_0x24; // accesses: 3
};

struct CSystemFidParameters_SParam_Id {
    byte _padding_0x0[20];
    EParamType field_0x14; // accesses: 1
};

struct CSystemFids {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 8
    byte _padding_0x8[12];
    CSystemFids * field_0x14; // accesses: 15
    undefined4 field_0x18; // accesses: 3
    uint field_0x1c; // accesses: 2
    byte _padding_0x20[20];
    undefined4 field_0x34; // accesses: 3
    byte _padding_0x38[8];
    SStringParam * field_0x40; // accesses: 2
    byte _padding_0x44[40];
    undefined ** field_0x6c; // accesses: 1
    byte _padding_0x70[4];
    int field_0x74; // accesses: 2
};

struct CSystemFidsDrive {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    byte _padding_0x8[16];
    CSystemFidsDrive * field_0x18; // accesses: 1
};

struct CSystemFidsFolder {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    byte _padding_0x8[12];
    int * field_0x14; // accesses: 1
    byte _padding_0x18[28];
    uint field_0x34; // accesses: 2
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 2
    undefined * field_0x44; // accesses: 3
};

struct CSystemFile {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 4
    byte _padding_0x8[4];
    int field_0xc; // accesses: 14
    undefined4 * field_0x10; // accesses: 7
    undefined4 field_0x14; // accesses: 2
    SStringParamInt * field_0x18; // accesses: 4
    ulong field_0x1c; // accesses: 6
    void * field_0x20; // accesses: 13
    int field_0x24; // accesses: 13
};

struct CSystemFileMemMapped {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    ulong field_0x18; // accesses: 2
    HANDLE field_0x1c; // accesses: 3
    HANDLE field_0x20; // accesses: 3
    LPCVOID field_0x24; // accesses: 3
};

struct CSystemFileName {
    byte _padding_0x0[2];
    short field_0x2; // accesses: 2
    ulong field_0x4; // accesses: 22
    short field_0x6; // accesses: 2
};

struct CSystemManagerFile {
    byte _padding_0x0[4];
    LPCWSTR field_0x4; // accesses: 14
    byte _padding_0x8[16];
    undefined4 field_0x18; // accesses: 4
};

struct CSystemPackDesc {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 4
    int field_0x8; // accesses: 3
    int field_0xc; // accesses: 2
    byte _padding_0x10[8];
    int field_0x18; // accesses: 1
    byte _padding_0x1c[12];
    int field_0x28; // accesses: 1
    int field_0x2c; // accesses: 1
    int field_0x30; // accesses: 1
    byte _padding_0x34[20];
    CSystemFid * field_0x48; // accesses: 6
    int field_0x4c; // accesses: 1
    int field_0x50; // accesses: 2
    byte _padding_0x54[20];
    undefined4 field_0x68; // accesses: 1
    byte _padding_0x6c[12];
    int * field_0x78; // accesses: 3
};

struct CSystemPackManager {
    byte _padding_0x0[4];
    char * field_0x4; // accesses: 9
    byte _padding_0x5[3];
    int field_0x8; // accesses: 2
    void * field_0xc; // accesses: 2
    undefined4 field_0x10; // accesses: 1
    int field_0x14; // accesses: 2
    uint field_0x18; // accesses: 1
    int field_0x1c; // accesses: 2
    int field_0x20; // accesses: 2
    void * field_0x24; // accesses: 4
    undefined * field_0x28; // accesses: 2
    code * field_0x2c; // accesses: 1
    byte _padding_0x30[8];
    code * field_0x38; // accesses: 4
    code * field_0x3c; // accesses: 4
    int field_0x40; // accesses: 3
    int field_0x44; // accesses: 1
    int field_0x48; // accesses: 6
    CSystemFids * field_0x4c; // accesses: 3
    CSystemFids * field_0x50; // accesses: 3
    byte _padding_0x54[4];
    int field_0x58; // accesses: 1
    byte _padding_0x5c[4];
    int field_0x60; // accesses: 1
    int field_0x64; // accesses: 1
    byte _padding_0x68[4];
    int field_0x6c; // accesses: 2
};

struct CSystemXmlTools {
    byte _padding_0x0[4];
    ulong field_0x4; // accesses: 9
    int * field_0x8; // accesses: 6
    byte _padding_0xc[4];
    SStringParam * field_0x10; // accesses: 4
    TiXmlElement * field_0x14; // accesses: 3
    int * field_0x18; // accesses: 13
    code * field_0x1c; // accesses: 1
    int field_0x20; // accesses: 15
    void * field_0x24; // accesses: 3
    byte _padding_0x28[68];
    undefined4 * field_0x6c; // accesses: 6
};

struct CTrackMania {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 1
    float field_0x8; // accesses: 1
    float field_0xc; // accesses: 1
    byte _padding_0x10[28];
    int field_0x2c; // accesses: 1
    int * field_0x30; // accesses: 1
    byte _padding_0x34[4];
    CHmsItem * field_0x38; // accesses: 1
    byte _padding_0x3c[28];
    int field_0x58; // accesses: 1
    byte _padding_0x5c[36];
    float field_0x80; // accesses: 1
    byte _padding_0x84[16];
    float field_0x94; // accesses: 1
    float field_0x98; // accesses: 1
    int field_0x9c; // accesses: 1
    float field_0xa0; // accesses: 1
    undefined4 field_0xa4; // accesses: 1
    byte _padding_0xa8[132];
    int field_0x12c; // accesses: 2
    byte _padding_0x130[56];
    CTrackManiaPlayerProfile * field_0x168; // accesses: 1
    byte _padding_0x16c[4];
    int field_0x170; // accesses: 1
    byte _padding_0x174[4];
    float field_0x178; // accesses: 1
    float field_0x17c; // accesses: 1
    undefined4 field_0x180; // accesses: 1
    byte _padding_0x184[20];
    int field_0x198; // accesses: 2
    byte _padding_0x19c[68];
    code * field_0x1e0; // accesses: 1
    byte _padding_0x1e4[132];
    undefined4 field_0x268; // accesses: 1
    byte _padding_0x26c[4];
    int field_0x270; // accesses: 1
    byte _padding_0x274[416];
    int * field_0x414; // accesses: 3
    int field_0x418; // accesses: 5
    byte _padding_0x41c[232];
    ulong field_0x504; // accesses: 1
    CTrackMania * field_0x508; // accesses: 1
    byte _padding_0x50c[52];
    int field_0x540; // accesses: 2
    undefined2 * field_0x544; // accesses: 1
    byte _padding_0x546[2];
    int field_0x548; // accesses: 2
    undefined2 * field_0x54c; // accesses: 1
};

struct CTrackManiaControlScores {
    byte _padding_0x0[20];
    int field_0x14; // accesses: 1
    int field_0x18; // accesses: 1
    byte _padding_0x1c[56];
    int field_0x54; // accesses: 2
    byte _padding_0x58[20];
    int field_0x6c; // accesses: 2
    int field_0x70; // accesses: 2
    byte _padding_0x74[236];
    int field_0x160; // accesses: 2
    int field_0x164; // accesses: 2
    int field_0x168; // accesses: 1
    CTrackManiaControlScores * field_0x16c; // accesses: 2
    void * field_0x170; // accesses: 1
    int field_0x174; // accesses: 3
    int field_0x178; // accesses: 2
    byte _padding_0x17c[16];
    CTrackManiaControlScores * field_0x18c; // accesses: 5
    int * field_0x190; // accesses: 3
    CTrackManiaRaceScore * field_0x194; // accesses: 1
    ulong field_0x198; // accesses: 2
    byte _padding_0x19c[24];
    CGameCtnEditor * field_0x1b4; // accesses: 1
    CGameCtnEditor * field_0x1b8; // accesses: 1
    CTrackManiaControlScores * field_0x1bc; // accesses: 7
    CTrackManiaControlScores * field_0x1c0; // accesses: 7
    byte _padding_0x1c4[12];
    CGameControlGridCard * field_0x1d0; // accesses: 1
    CGameControlGridCard * field_0x1d4; // accesses: 2
    CGameControlGridCard * field_0x1d8; // accesses: 2
    byte _padding_0x1dc[100];
    uint field_0x240; // accesses: 1
    byte _padding_0x244[100];
    int field_0x2a8; // accesses: 2
    byte _padding_0x2ac[104];
    int field_0x314; // accesses: 2
};

struct CTrackManiaControlScores2 {
    byte _padding_0x0[4];
    int * field_0x4; // accesses: 14
    byte _padding_0x8[4];
    int * field_0xc; // accesses: 4
    CControlLabel * field_0x10; // accesses: 2
    undefined4 field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 2
    undefined4 field_0x1c; // accesses: 1
    byte _padding_0x20[4];
    CFastString * field_0x24; // accesses: 1
    int field_0x28; // accesses: 6
    undefined4 field_0x2c; // accesses: 2
    int field_0x30; // accesses: 2
    CFastStringInt * field_0x34; // accesses: 4
    int field_0x38; // accesses: 2
    CControlBase * field_0x3c; // accesses: 1
    int * field_0x40; // accesses: 5
    CControlBase * field_0x44; // accesses: 1
    CFastStringInt * field_0x48; // accesses: 1
    CControlBase * field_0x4c; // accesses: 1
    CControlBase * field_0x50; // accesses: 1
    int field_0x54; // accesses: 3
    int * field_0x58; // accesses: 4
    CControlBase * field_0x5c; // accesses: 1
    CFastStringInt * field_0x60; // accesses: 2
    int * field_0x64; // accesses: 3
    byte _padding_0x68[216];
    undefined * field_0x140; // accesses: 2
    byte _padding_0x144[36];
    int field_0x168; // accesses: 1
    int field_0x16c; // accesses: 1
    int field_0x170; // accesses: 1
    int field_0x174; // accesses: 1
    int field_0x178; // accesses: 1
    int field_0x17c; // accesses: 1
    int field_0x180; // accesses: 1
    CMwId * field_0x184; // accesses: 2
    int field_0x188; // accesses: 2
    int field_0x18c; // accesses: 1
    int field_0x190; // accesses: 1
    byte _padding_0x194[8];
    CFastString * field_0x19c; // accesses: 1
    undefined * field_0x1a0; // accesses: 1
    byte _padding_0x1a4[12];
    ulong field_0x1b0; // accesses: 1
    byte _padding_0x1b4[12];
    int field_0x1c0; // accesses: 5
    int field_0x1c4; // accesses: 1
    int field_0x1c8; // accesses: 1
    byte _padding_0x1cc[16];
    int field_0x1dc; // accesses: 2
    undefined * field_0x1e0; // accesses: 1
    int field_0x1e4; // accesses: 4
    CControlBase * field_0x1e8; // accesses: 2
    CControlBase * field_0x1ec; // accesses: 2
    byte _padding_0x1f0[4];
    CControlBase * field_0x1f4; // accesses: 1
    byte _padding_0x1f8[4];
    CControlBase * field_0x1fc; // accesses: 1
    int field_0x200; // accesses: 10
    byte _padding_0x204[16];
    int field_0x214; // accesses: 7
    int field_0x218; // accesses: 7
    int field_0x21c; // accesses: 8
    int field_0x220; // accesses: 3
    int field_0x224; // accesses: 3
    byte _padding_0x228[12];
    undefined4 field_0x234; // accesses: 1
    byte _padding_0x238[8];
    CFastStringInt * field_0x240; // accesses: 3
};

struct CTrackManiaEditor {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 3
    undefined4 field_0x8; // accesses: 3
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    CGameCtnChallenge * field_0x14; // accesses: 4
    int field_0x18; // accesses: 4
    CMwId * field_0x1c; // accesses: 2
    CGameCtnChallenge * field_0x20; // accesses: 4
    byte _padding_0x24[4];
    undefined4 field_0x28; // accesses: 2
    undefined4 field_0x2c; // accesses: 2
    undefined4 field_0x30; // accesses: 1
    ECardinalDir field_0x34; // accesses: 1
    int field_0x38; // accesses: 5
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    byte _padding_0x44[56];
    undefined4 field_0x7c; // accesses: 1
    undefined4 field_0x80; // accesses: 1
    byte _padding_0x84[8];
    undefined4 field_0x8c; // accesses: 1
    byte _padding_0x90[40];
    CTrackManiaEditorInterface * field_0xb8; // accesses: 1
    int field_0xbc; // accesses: 4
    byte _padding_0xc0[4];
    int * field_0xc4; // accesses: 11
    byte _padding_0xc8[12];
    CGameCtnChallenge * field_0xd4; // accesses: 2
    byte _padding_0xd8[764];
    int * field_0x3d4; // accesses: 5
    undefined4 field_0x3d8; // accesses: 1
    undefined4 field_0x3dc; // accesses: 1
    undefined4 field_0x3e0; // accesses: 1
    byte _padding_0x3e4[120];
    undefined4 field_0x45c; // accesses: 1
    undefined4 field_0x460; // accesses: 1
    byte _padding_0x464[24];
    int field_0x47c; // accesses: 1
    byte _padding_0x480[100];
    undefined4 field_0x4e4; // accesses: 1
    byte _padding_0x4e8[32];
    undefined4 field_0x508; // accesses: 1
    undefined4 field_0x50c; // accesses: 1
    undefined4 field_0x510; // accesses: 1
    undefined4 field_0x514; // accesses: 1
};

struct CTrackManiaEditorFree {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    uint field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 3
    undefined4 field_0x18; // accesses: 3
    float field_0x1c; // accesses: 3
    float field_0x20; // accesses: 4
    float field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    float field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    byte _padding_0x44[100];
    uint field_0xa8; // accesses: 1
    byte _padding_0xac[4];
    uint field_0xb0; // accesses: 1
    byte _padding_0xb4[8];
    int field_0xbc; // accesses: 2
    byte _padding_0xc0[84];
    int field_0x114; // accesses: 1
    byte _padding_0x118[1020];
    int field_0x514; // accesses: 2
};

struct CTrackManiaEditorIcon {
    byte _padding_0x0[28];
    CTrackManiaEditorIcon * field_0x1c; // accesses: 1
};

struct CTrackManiaEditorIconPage {
    byte _padding_0x0[24];
    EMwIconList field_0x18; // accesses: 1
    EMwIconList field_0x1c; // accesses: 1
    byte _padding_0x20[8];
    int field_0x28; // accesses: 1
};

struct CTrackManiaEditorInterface {
    byte _padding_0x0[20];
    undefined4 * field_0x14; // accesses: 7
    int field_0x18; // accesses: 7
    byte _padding_0x1c[12];
    CScene2d * field_0x28; // accesses: 2
    byte _padding_0x2c[8];
    int field_0x34; // accesses: 5
    int field_0x38; // accesses: 10
    byte _padding_0x3c[12];
    CTrackManiaEditorInterface * field_0x48; // accesses: 2
    byte _padding_0x4c[12];
    int field_0x58; // accesses: 1
    byte _padding_0x5c[4];
    int field_0x60; // accesses: 2
    int field_0x64; // accesses: 3
    byte _padding_0x68[8];
    int field_0x70; // accesses: 11
    ulong field_0x74; // accesses: 2
    ulong field_0x78; // accesses: 1
    uint field_0x7c; // accesses: 2
    uint field_0x80; // accesses: 2
    CFastString * field_0x84; // accesses: 4
};

struct CTrackManiaEditorPuzzle {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 3
    undefined4 field_0x8; // accesses: 2
    undefined4 field_0xc; // accesses: 1
    byte _padding_0x10[8];
    undefined4 field_0x18; // accesses: 1
    float field_0x1c; // accesses: 1
    float field_0x20; // accesses: 6
    float field_0x24; // accesses: 1
    byte _padding_0x28[4];
    undefined4 field_0x2c; // accesses: 1
    byte _padding_0x30[24];
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 2
    byte _padding_0x58[96];
    CTrackManiaEditorInterface * field_0xb8; // accesses: 1
};

struct CTrackManiaEditorSimple {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    uint field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    byte _padding_0x10[12];
    float field_0x1c; // accesses: 1
    float field_0x20; // accesses: 5
    float field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    float field_0x30; // accesses: 1
    byte _padding_0x34[116];
    uint field_0xa8; // accesses: 1
    byte _padding_0xac[4];
    uint field_0xb0; // accesses: 1
    byte _padding_0xb4[8];
    int field_0xbc; // accesses: 1
    byte _padding_0xc0[84];
    int field_0x114; // accesses: 1
};

struct CTrackManiaEditorTerrain {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 8
    int field_0x8; // accesses: 2
    byte _padding_0xc[20];
    CGameCtnChallenge * field_0x20; // accesses: 4
};

struct CTrackManiaMenus {
    byte _padding_0x0[124];
    undefined4 field_0x7c; // accesses: 1
    byte _padding_0x80[352];
    int field_0x1e0; // accesses: 3
    byte _padding_0x1e4[1308];
    undefined4 field_0x700; // accesses: 1
    undefined4 field_0x704; // accesses: 1
    byte _padding_0x708[124];
    CGameApp * field_0x784; // accesses: 10
    int field_0x788; // accesses: 1
    byte _padding_0x78c[180];
    void * field_0x840; // accesses: 3
};

struct CTrackManiaNetForm {
    byte _padding_0x0[140];
    undefined4 field_0x8c; // accesses: 2
    undefined * field_0x90; // accesses: 3
    byte _padding_0x94[4];
    undefined4 field_0x98; // accesses: 2
    undefined * field_0x9c; // accesses: 3
    byte _padding_0xa0[12];
    undefined4 field_0xac; // accesses: 2
    undefined * field_0xb0; // accesses: 3
};

struct CTrackManiaNetwork {
    byte _padding_0x0[4];
    CFastStringInt * field_0x4; // accesses: 13
    byte _padding_0x8[4];
    int field_0xc; // accesses: 3
    CFastString * field_0x10; // accesses: 6
    CPlugAudio * field_0x14; // accesses: 8
    undefined4 field_0x18; // accesses: 1
    byte _padding_0x1c[4];
    undefined4 field_0x20; // accesses: 4
    byte field_0x24; // accesses: 8
    byte _padding_0x25[3];
    undefined4 field_0x28; // accesses: 4
    undefined4 field_0x2c; // accesses: 4
    ulong field_0x30; // accesses: 4
    byte _padding_0x34[4];
    CFastStringInt * field_0x38; // accesses: 1
    int field_0x3c; // accesses: 2
    byte _padding_0x40[4];
    int field_0x44; // accesses: 2
    byte _padding_0x48[8];
    undefined4 field_0x50; // accesses: 1
    undefined * field_0x54; // accesses: 1
    byte _padding_0x58[24];
    int field_0x70; // accesses: 1
    int field_0x74; // accesses: 1
    byte _padding_0x78[100];
    int field_0xdc; // accesses: 2
    byte _padding_0xe0[48];
    code * field_0x110; // accesses: 1
    byte _padding_0x114[4];
    int field_0x118; // accesses: 4
    byte _padding_0x11c[148];
    int field_0x1b0; // accesses: 8
    byte _padding_0x1b4[28];
    int field_0x1d0; // accesses: 3
    byte _padding_0x1d4[44];
    int field_0x200; // accesses: 3
    byte _padding_0x204[4];
    ulong field_0x208; // accesses: 1
    byte _padding_0x20c[48];
    CTrackManiaNetworkServerInfo * field_0x23c; // accesses: 1
    byte _padding_0x240[20];
    int field_0x254; // accesses: 1
    byte _padding_0x258[8];
    ulong field_0x260; // accesses: 3
    byte _padding_0x264[72];
    int field_0x2ac; // accesses: 3
    byte _padding_0x2b0[840];
    CGameCtnApp * field_0x5f8; // accesses: 16
    byte _padding_0x5fc[96];
    int field_0x65c; // accesses: 2
    int field_0x660; // accesses: 8
    byte _padding_0x664[156];
    int field_0x700; // accesses: 1
    byte _padding_0x704[212];
    int field_0x7d8; // accesses: 4
    byte _padding_0x7dc[68];
    undefined4 field_0x820; // accesses: 4
    byte _padding_0x824[8];
    undefined4 field_0x82c; // accesses: 1
    byte _padding_0x830[32];
    CClassicArchive * field_0x850; // accesses: 2
};

struct CTrackManiaPlayerInfo {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 2
    byte _padding_0x8[100];
    int field_0x6c; // accesses: 1
    int field_0x70; // accesses: 1
    byte _padding_0x74[20];
    int field_0x88; // accesses: 1
    byte _padding_0x8c[4];
    int field_0x90; // accesses: 1
    byte _padding_0x94[420];
    undefined4 field_0x238; // accesses: 1
    byte _padding_0x23c[4];
    undefined4 field_0x240; // accesses: 1
    byte _padding_0x244[96];
    undefined4 field_0x2a4; // accesses: 1
    undefined4 field_0x2a8; // accesses: 1
    undefined4 field_0x2ac; // accesses: 1
    byte _padding_0x2b0[4];
    int field_0x2b4; // accesses: 2
    undefined4 field_0x2b8; // accesses: 1
    byte _padding_0x2bc[4];
    undefined4 field_0x2c0; // accesses: 1
    undefined4 field_0x2c4; // accesses: 1
    undefined4 field_0x2c8; // accesses: 1
    undefined4 field_0x2cc; // accesses: 1
    undefined4 field_0x2d0; // accesses: 1
    undefined4 field_0x2d4; // accesses: 1
    byte _padding_0x2d8[8];
    int field_0x2e0; // accesses: 2
    undefined4 field_0x2e4; // accesses: 1
    undefined4 field_0x2e8; // accesses: 1
    undefined4 field_0x2ec; // accesses: 1
    undefined4 field_0x2f0; // accesses: 1
    undefined4 field_0x2f4; // accesses: 1
    byte _padding_0x2f8[16];
    undefined4 field_0x308; // accesses: 1
    undefined4 field_0x30c; // accesses: 1
    undefined * field_0x310; // accesses: 1
    ulong field_0x314; // accesses: 2
    undefined4 field_0x318; // accesses: 1
    undefined4 field_0x31c; // accesses: 1
    undefined4 field_0x320; // accesses: 1
    byte _padding_0x324[12];
    undefined4 field_0x330; // accesses: 1
    undefined4 field_0x334; // accesses: 1
    undefined4 field_0x338; // accesses: 1
    undefined4 field_0x33c; // accesses: 1
    undefined4 field_0x340; // accesses: 1
    undefined4 field_0x344; // accesses: 1
    undefined4 field_0x348; // accesses: 1
    undefined4 field_0x34c; // accesses: 1
    byte _padding_0x350[80];
    undefined4 field_0x3a0; // accesses: 1
    undefined * field_0x3a4; // accesses: 1
    undefined4 field_0x3a8; // accesses: 1
    undefined * field_0x3ac; // accesses: 1
};

struct CTrackManiaRace {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 8
    int field_0x8; // accesses: 4
    byte _padding_0xc[8];
    CPlugAudio * field_0x14; // accesses: 7
    int * field_0x18; // accesses: 41
    int field_0x1c; // accesses: 3
    int * field_0x20; // accesses: 20
    float field_0x24; // accesses: 11
    float field_0x28; // accesses: 20
    float field_0x2c; // accesses: 6
    int field_0x30; // accesses: 3
    CGameCamera * field_0x34; // accesses: 8
    byte _padding_0x38[8];
    int field_0x40; // accesses: 3
    CTrackManiaRace * field_0x44; // accesses: 1
    int field_0x48; // accesses: 3
    int field_0x4c; // accesses: 1
    int field_0x50; // accesses: 2
    GmMat3 * field_0x54; // accesses: 1
    byte _padding_0x58[8];
    uint field_0x60; // accesses: 4
    byte _padding_0x64[12];
    int field_0x70; // accesses: 6
    int field_0x74; // accesses: 6
    int field_0x78; // accesses: 3
    float field_0x7c; // accesses: 2
    int field_0x80; // accesses: 2
    byte _padding_0x84[4];
    int field_0x88; // accesses: 1
    code * field_0x8c; // accesses: 1
    byte _padding_0x90[8];
    int field_0x98; // accesses: 1
    uint field_0x9c; // accesses: 2
    int field_0xa0; // accesses: 5
    int field_0xa4; // accesses: 2
    int field_0xa8; // accesses: 2
    byte _padding_0xac[4];
    int field_0xb0; // accesses: 2
    CMwNod * field_0xb4; // accesses: 4
    byte _padding_0xb8[12];
    CGameCtnChallenge * field_0xc4; // accesses: 28
    byte _padding_0xc8[4];
    undefined4 field_0xcc; // accesses: 1
    int field_0xd0; // accesses: 4
    byte _padding_0xd4[24];
    float field_0xec; // accesses: 11
    int field_0xf0; // accesses: 1
    int field_0xf4; // accesses: 4
    byte _padding_0xf8[4];
    int field_0xfc; // accesses: 4
    undefined4 field_0x100; // accesses: 1
    float field_0x104; // accesses: 4
    int field_0x108; // accesses: 4
    int field_0x10c; // accesses: 5
    int field_0x110; // accesses: 4
    byte _padding_0x114[12];
    int field_0x120; // accesses: 1
    byte _padding_0x124[36];
    int field_0x148; // accesses: 1
    byte _padding_0x14c[28];
    int field_0x168; // accesses: 1
    CGameRace * field_0x16c; // accesses: 1
    byte _padding_0x170[4];
    undefined4 field_0x174; // accesses: 2
    float field_0x178; // accesses: 1
    byte _padding_0x17c[116];
    undefined4 field_0x1f0; // accesses: 1
    byte _padding_0x1f4[20];
    int field_0x208; // accesses: 2
    byte _padding_0x20c[32];
    undefined4 field_0x22c; // accesses: 1
    byte _padding_0x230[8];
    int field_0x238; // accesses: 4
    byte _padding_0x23c[24];
    CGameRace * field_0x254; // accesses: 1
    byte _padding_0x258[12];
    float field_0x264; // accesses: 1
    CTrackManiaRace * field_0x268; // accesses: 1
    undefined4 field_0x26c; // accesses: 1
    int field_0x270; // accesses: 2
    ulong field_0x274; // accesses: 3
    float field_0x278; // accesses: 2
    byte _padding_0x27c[12];
    int field_0x288; // accesses: 3
    byte _padding_0x28c[24];
    CGameRace * field_0x2a4; // accesses: 1
    byte _padding_0x2a8[4];
    int field_0x2ac; // accesses: 8
    ulong field_0x2b0; // accesses: 4
    byte _padding_0x2b4[4];
    int field_0x2b8; // accesses: 1
    ulong field_0x2bc; // accesses: 1
    int field_0x2c0; // accesses: 2
    ulong field_0x2c4; // accesses: 6
    byte _padding_0x2c8[12];
    ulong field_0x2d4; // accesses: 3
    byte _padding_0x2d8[4];
    int field_0x2dc; // accesses: 3
    byte _padding_0x2e0[28];
    int field_0x2fc; // accesses: 9
    void * field_0x300; // accesses: 1
    undefined4 field_0x304; // accesses: 2
    void * field_0x308; // accesses: 8
    int field_0x30c; // accesses: 3
    byte _padding_0x310[4];
    void * field_0x314; // accesses: 4
    int field_0x318; // accesses: 2
    float field_0x31c; // accesses: 3
    int field_0x320; // accesses: 5
    undefined4 field_0x324; // accesses: 2
    float field_0x328; // accesses: 2
    int field_0x32c; // accesses: 4
    CTrackManiaPlayerInfo * field_0x330; // accesses: 11
    undefined4 field_0x334; // accesses: 1
    undefined4 field_0x338; // accesses: 1
    int field_0x33c; // accesses: 5
    undefined4 field_0x340; // accesses: 4
    byte _padding_0x344[104];
    undefined4 field_0x3ac; // accesses: 1
    byte _padding_0x3b0[124];
    undefined4 field_0x42c; // accesses: 1
    byte _padding_0x430[40];
    undefined4 field_0x458; // accesses: 1
    undefined4 field_0x45c; // accesses: 1
    undefined4 field_0x460; // accesses: 1
    byte _padding_0x464[72];
    undefined4 field_0x4ac; // accesses: 1
    byte _padding_0x4b0[20];
    undefined4 field_0x4c4; // accesses: 1
    undefined4 field_0x4c8; // accesses: 1
    undefined4 field_0x4cc; // accesses: 1
    undefined4 field_0x4d0; // accesses: 1
    undefined4 field_0x4d4; // accesses: 1
    undefined4 field_0x4d8; // accesses: 1
    undefined4 field_0x4dc; // accesses: 1
    undefined4 field_0x4e0; // accesses: 1
    byte _padding_0x4e4[4];
    int field_0x4e8; // accesses: 2
    int field_0x4ec; // accesses: 4
    undefined4 field_0x4f0; // accesses: 2
    undefined4 field_0x4f4; // accesses: 2
    undefined4 field_0x4f8; // accesses: 2
    undefined4 field_0x4fc; // accesses: 2
    CGameCtnChallenge * field_0x500; // accesses: 2
    byte _padding_0x504[12];
    int * field_0x510; // accesses: 11
    int field_0x514; // accesses: 5
    int * field_0x518; // accesses: 4
    ECallback field_0x51c; // accesses: 1
    byte _padding_0x520[24];
    int field_0x538; // accesses: 6
    int field_0x53c; // accesses: 1
    int field_0x540; // accesses: 3
    int field_0x544; // accesses: 2
};

struct CTrackManiaRaceInterface {
    byte _padding_0x0[4];
    CFastString * field_0x4; // accesses: 4
    SStringParam * field_0x8; // accesses: 3
    byte _padding_0xc[4];
    int field_0x10; // accesses: 1
    int field_0x14; // accesses: 7
    CGameApp * field_0x18; // accesses: 2
    CFastString * field_0x1c; // accesses: 4
    int field_0x20; // accesses: 3
    byte _padding_0x24[4];
    int field_0x28; // accesses: 3
    byte _padding_0x2c[32];
    ulong field_0x4c; // accesses: 1
    ulong field_0x50; // accesses: 1
    byte _padding_0x54[24];
    int field_0x6c; // accesses: 4
    int field_0x70; // accesses: 10
    int field_0x74; // accesses: 9
    byte _padding_0x78[4];
    int field_0x7c; // accesses: 1
    byte field_0x80; // accesses: 4
    byte _padding_0x81[7];
    int field_0x88; // accesses: 1
    byte _padding_0x8c[4];
    int field_0x90; // accesses: 1
    byte _padding_0x94[8];
    int field_0x9c; // accesses: 2
    CTrackManiaRaceNet * field_0xa0; // accesses: 59
    byte _padding_0xa4[4];
    CGameNetwork * field_0xa8; // accesses: 37
    int field_0xac; // accesses: 1
    CControlLabel * field_0xb0; // accesses: 8
    int field_0xb4; // accesses: 4
    uint field_0xb8; // accesses: 1
    uint field_0xbc; // accesses: 2
    int field_0xc0; // accesses: 5
    int field_0xc4; // accesses: 2
    undefined4 field_0xc8; // accesses: 2
    CControlBase * field_0xcc; // accesses: 1
    byte _padding_0xd0[8];
    int field_0xd8; // accesses: 2
    CControlBase * field_0xdc; // accesses: 9
    CControlBase * field_0xe0; // accesses: 1
    CControlBase * field_0xe4; // accesses: 1
    CControlBase * field_0xe8; // accesses: 1
    CControlBase * field_0xec; // accesses: 1
    CControlBase * field_0xf0; // accesses: 1
    CControlBase * field_0xf4; // accesses: 1
    CControlBase * field_0xf8; // accesses: 1
    int * field_0xfc; // accesses: 3
    CControlBase * field_0x100; // accesses: 1
    CControlBase * field_0x104; // accesses: 1
    int * field_0x108; // accesses: 14
    int * field_0x10c; // accesses: 6
    int field_0x110; // accesses: 5
    int * field_0x114; // accesses: 3
    CControlBase * field_0x118; // accesses: 1
    byte _padding_0x11c[12];
    CControlBase * field_0x128; // accesses: 2
    CControlBase * field_0x12c; // accesses: 2
    CControlBase * field_0x130; // accesses: 2
    byte _padding_0x134[4];
    CControlBase * field_0x138; // accesses: 1
    int field_0x13c; // accesses: 3
    int * field_0x140; // accesses: 6
    uint field_0x144; // accesses: 3
    CControlBase * field_0x148; // accesses: 5
    CControlBase * field_0x14c; // accesses: 5
    CControlBase * field_0x150; // accesses: 2
    ulong field_0x154; // accesses: 3
    int field_0x158; // accesses: 3
    CMwCmdScriptVarBool * field_0x15c; // accesses: 2
    CControlBase * field_0x160; // accesses: 1
    byte _padding_0x164[4];
    int field_0x168; // accesses: 1
    int field_0x16c; // accesses: 2
    int field_0x170; // accesses: 1
    byte _padding_0x174[4];
    CControlBase * field_0x178; // accesses: 1
    CControlBase * field_0x17c; // accesses: 1
    CControlBase * field_0x180; // accesses: 1
    CControlBase * field_0x184; // accesses: 1
    int field_0x188; // accesses: 3
    byte _padding_0x18c[12];
    int field_0x198; // accesses: 2
    CControlBase * field_0x19c; // accesses: 1
    int field_0x1a0; // accesses: 6
    CControlBase * field_0x1a4; // accesses: 1
    byte _padding_0x1a8[4];
    CControlBase * field_0x1ac; // accesses: 1
    CControlBase * field_0x1b0; // accesses: 1
    CControlBase * field_0x1b4; // accesses: 1
    CControlBase * field_0x1b8; // accesses: 1
    CControlBase * field_0x1bc; // accesses: 1
    CControlBase * field_0x1c0; // accesses: 1
    CControlBase * field_0x1c4; // accesses: 1
    CControlBase * field_0x1c8; // accesses: 1
    CControlBase * field_0x1cc; // accesses: 1
    float field_0x1d0; // accesses: 1
    float field_0x1d4; // accesses: 1
    float field_0x1d8; // accesses: 1
    float field_0x1dc; // accesses: 1
    float field_0x1e0; // accesses: 1
    float field_0x1e4; // accesses: 1
    byte _padding_0x1e8[4];
    CControlBase * field_0x1ec; // accesses: 2
    byte _padding_0x1f0[4];
    CControlBase * field_0x1f4; // accesses: 2
    CControlBase * field_0x1f8; // accesses: 2
    byte _padding_0x1fc[4];
    int field_0x200; // accesses: 8
    CControlBase * field_0x204; // accesses: 1
    byte _padding_0x208[8];
    int * field_0x210; // accesses: 6
    int * field_0x214; // accesses: 11
    int * field_0x218; // accesses: 3
    ulong field_0x21c; // accesses: 5
    byte _padding_0x220[56];
    CControlBase * field_0x258; // accesses: 1
    int * field_0x25c; // accesses: 7
    int * field_0x260; // accesses: 3
    CControlBase * field_0x264; // accesses: 1
    int field_0x268; // accesses: 2
    byte _padding_0x26c[4];
    uint field_0x270; // accesses: 1
    byte _padding_0x274[20];
    int field_0x288; // accesses: 2
    byte _padding_0x28c[12];
    int field_0x298; // accesses: 2
    int field_0x29c; // accesses: 2
    int field_0x2a0; // accesses: 1
    ulong field_0x2a4; // accesses: 4
    byte _padding_0x2a8[4];
    int field_0x2ac; // accesses: 4
    int * field_0x2b0; // accesses: 4
    int field_0x2b4; // accesses: 1
    byte _padding_0x2b8[28];
    CFastString * field_0x2d4; // accesses: 1
    byte _padding_0x2d8[8];
    int field_0x2e0; // accesses: 1
    byte _padding_0x2e4[12];
    ulong field_0x2f0; // accesses: 3
    float field_0x2f4; // accesses: 2
    float field_0x2f8; // accesses: 2
    float field_0x2fc; // accesses: 3
    ulong field_0x300; // accesses: 5
    float field_0x304; // accesses: 1
    float field_0x308; // accesses: 1
    float field_0x30c; // accesses: 2
    undefined4 field_0x310; // accesses: 1
    int field_0x314; // accesses: 1
    byte _padding_0x318[744];
    int field_0x600; // accesses: 1
    byte _padding_0x604[8];
    int field_0x60c; // accesses: 1
};

struct CTrackManiaRaceNet {
    byte _padding_0x0[20];
    CPlugAudio * field_0x14; // accesses: 3
    int * field_0x18; // accesses: 8
    byte _padding_0x1c[4];
    CGamePlayerCameraSet * field_0x20; // accesses: 8
    CTrackManiaRaceNet * field_0x24; // accesses: 4
    byte _padding_0x28[4];
    ulong field_0x2c; // accesses: 2
    byte _padding_0x30[8];
    ulong field_0x38; // accesses: 3
    ulong field_0x3c; // accesses: 2
    byte _padding_0x40[16];
    int field_0x50; // accesses: 1
    byte _padding_0x54[24];
    int field_0x6c; // accesses: 12
    int field_0x70; // accesses: 12
    int field_0x74; // accesses: 11
    int field_0x78; // accesses: 4
    int field_0x7c; // accesses: 10
    byte _padding_0x80[4];
    int field_0x84; // accesses: 8
    int field_0x88; // accesses: 2
    byte _padding_0x8c[12];
    int field_0x98; // accesses: 16
    undefined4 field_0x9c; // accesses: 2
    byte _padding_0xa0[8];
    int field_0xa8; // accesses: 2
    byte _padding_0xac[428];
    int field_0x258; // accesses: 1
    byte _padding_0x25c[96];
    CGameRace * field_0x2bc; // accesses: 1
    byte _padding_0x2c0[84];
    int field_0x314; // accesses: 1
    byte _padding_0x318[24];
    int field_0x330; // accesses: 2
    byte _padding_0x334[32];
    int field_0x354; // accesses: 2
    uint field_0x358; // accesses: 2
    int field_0x35c; // accesses: 1
    byte _padding_0x360[52];
    undefined4 field_0x394; // accesses: 1
    undefined4 field_0x398; // accesses: 1
    byte _padding_0x39c[380];
    CTrackManiaRaceInterface * field_0x518; // accesses: 2
    byte _padding_0x51c[60];
    undefined4 field_0x558; // accesses: 1
    byte _padding_0x55c[88];
    int field_0x5b4; // accesses: 10
    int field_0x5b8; // accesses: 5
    int field_0x5bc; // accesses: 6
    undefined4 field_0x5c0; // accesses: 2
    int field_0x5c4; // accesses: 3
    byte _padding_0x5c8[184];
    int field_0x680; // accesses: 2
};

struct CTrackManiaRaceNetLaps {
    byte _padding_0x0[20];
    CPlugAudio * field_0x14; // accesses: 1
    int * field_0x18; // accesses: 4
    byte _padding_0x1c[8];
    CTrackManiaRaceNetLaps field_0x24; // accesses: 1
    byte _padding_0x28[40];
    int field_0x50; // accesses: 1
    byte _padding_0x54[28];
    int field_0x70; // accesses: 4
    int field_0x74; // accesses: 5
    undefined4 field_0x78; // accesses: 1
    byte _padding_0x7c[28];
    int field_0x98; // accesses: 3
    byte _padding_0x9c[632];
    int field_0x314; // accesses: 1
    byte _padding_0x318[684];
    int field_0x5c4; // accesses: 2
    byte _padding_0x5c8[184];
    int field_0x680; // accesses: 2
};

struct CTrackManiaRaceNetRounds {
    byte _padding_0x0[20];
    CPlugAudio * field_0x14; // accesses: 1
    byte _padding_0x18[1648];
    undefined4 field_0x688; // accesses: 1
};

struct CTrackManiaRaceNetTimeAttack {
    byte _padding_0x0[20];
    CPlugAudio * field_0x14; // accesses: 1
    byte _padding_0x18[472];
    undefined4 field_0x1f0; // accesses: 3
    byte _padding_0x1f4[804];
    CTrackManiaRaceInterface * field_0x518; // accesses: 2
};

struct CTrackManiaRaceScore {
    byte _padding_0x0[20];
    int field_0x14; // accesses: 1
    int field_0x18; // accesses: 1
    int field_0x1c; // accesses: 1
    byte _padding_0x20[44];
    int field_0x4c; // accesses: 3
    undefined4 field_0x50; // accesses: 2
    CTrackManiaPlayerInfo * field_0x54; // accesses: 9
    undefined4 field_0x58; // accesses: 1
    byte _padding_0x5c[384];
    int field_0x1dc; // accesses: 1
};

struct CTrackManiaRaceTriggerAbsorbContact {
    byte _padding_0x0[4];
    CTrackManiaRaceTriggerAbsorbContact * field_0x4; // accesses: 8
    byte _padding_0x8[56];
    int field_0x40; // accesses: 2
};

struct CTrackManiaSwitcher {
    byte _padding_0x0[20];
    CControlUiDockable * field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 1
    CGameApp * field_0x1c; // accesses: 18
    byte _padding_0x20[88];
    CGameCtnMediaContext * field_0x78; // accesses: 4
    byte _padding_0x7c[52];
    int field_0xb0; // accesses: 2
    byte _padding_0xb4[16];
    CSceneObjectLink * field_0xc4; // accesses: 1
    byte _padding_0xc8[168];
    int field_0x170; // accesses: 2
    byte _padding_0x174[16];
    CGameCtnMediaClipViewer * field_0x184; // accesses: 1
    CGameCtnMediaClipViewer * field_0x188; // accesses: 1
    byte _padding_0x18c[648];
    int * field_0x414; // accesses: 2
};

struct CVisionEngine {
    byte _padding_0x0[144];
    int field_0x90; // accesses: 1
};

struct CVisionShaderKeeper {
    byte _padding_0x0[8];
    undefined4 * field_0x8; // accesses: 4
    CDx9IndexBuffer * field_0xc; // accesses: 2
    uint field_0x10; // accesses: 16
    byte _padding_0x14[12];
    uint field_0x20; // accesses: 1
};

struct CVisionTexConverter {
    byte _padding_0x0[1];
    int field_0x1; // accesses: 7
    byte _padding_0x5[43];
    byte field_0x30; // accesses: 4
    byte _padding_0x31[2];
    undefined1 field_0x33; // accesses: 2
    byte _padding_0x34[1];
    byte field_0x35; // accesses: 2
    byte _padding_0x36[4];
    uint field_0x3a; // accesses: 3
    CVisionTexConverter * field_0x3b; // accesses: 3
    byte _padding_0x3f[859056627];
    uint field_0x33342a32; // accesses: 2
};

struct CVisionViewport {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 1
    CClassicBufferMemory * field_0x8; // accesses: 3
    byte _padding_0xc[4];
    uint field_0x10; // accesses: 3
    CVisionShaderKeeper * field_0x14; // accesses: 7
    byte _padding_0x18[4];
    uint field_0x1c; // accesses: 1
    byte _padding_0x20[20];
    int field_0x34; // accesses: 1
    byte _padding_0x38[424];
    undefined4 field_0x1e0; // accesses: 1
    undefined4 field_0x1e4; // accesses: 1
    undefined4 field_0x1e8; // accesses: 1
    undefined4 field_0x1ec; // accesses: 1
    byte _padding_0x1f0[8];
    undefined4 field_0x1f8; // accesses: 1
    undefined4 field_0x1fc; // accesses: 1
    undefined4 field_0x200; // accesses: 1
    undefined4 field_0x204; // accesses: 1
    undefined4 field_0x208; // accesses: 1
    byte _padding_0x20c[4];
    undefined4 field_0x210; // accesses: 1
    byte _padding_0x214[8];
    undefined4 field_0x21c; // accesses: 1
    undefined4 field_0x220; // accesses: 1
    undefined4 field_0x224; // accesses: 1
    undefined4 field_0x228; // accesses: 1
    byte _padding_0x22c[204];
    int field_0x2f8; // accesses: 1
    byte _padding_0x2fc[632];
    undefined4 field_0x574; // accesses: 1
    byte _padding_0x578[160];
    undefined4 field_0x618; // accesses: 1
    byte _padding_0x61c[28];
    undefined4 field_0x638; // accesses: 1
    byte _padding_0x63c[12];
    undefined4 field_0x648; // accesses: 1
    byte _padding_0x64c[180];
    undefined4 field_0x700; // accesses: 1
    undefined4 field_0x704; // accesses: 1
    undefined4 field_0x708; // accesses: 1
    byte _padding_0x70c[212];
    undefined4 field_0x7e0; // accesses: 1
    undefined4 field_0x7e4; // accesses: 1
    undefined4 field_0x7e8; // accesses: 1
    undefined4 field_0x7ec; // accesses: 1
    undefined4 field_0x7f0; // accesses: 1
    undefined4 field_0x7f4; // accesses: 1
};

struct CVisionViewportDx9 {
    byte _padding_0x0[1];
    undefined2 field_0x1; // accesses: 1
    undefined2 field_0x2; // accesses: 1
    ulong field_0x4; // accesses: 56
    byte field_0x8; // accesses: 43
    byte _padding_0x9[3];
    CPlugBitmap * field_0xc; // accesses: 46
    float field_0x10; // accesses: 18
    byte field_0x14; // accesses: 134
    byte _padding_0x15[3];
    CSystemFid * field_0x18; // accesses: 26
    ulong field_0x1c; // accesses: 44
    undefined2 field_0x20; // accesses: 46
    ushort field_0x22; // accesses: 10
    undefined2 field_0x24; // accesses: 53
    ushort field_0x26; // accesses: 8
    CVisionShaderKeeper * field_0x28; // accesses: 37
    byte field_0x2c; // accesses: 22
    byte _padding_0x2d[3];
    float field_0x30; // accesses: 14
    byte field_0x31; // accesses: 26
    byte field_0x32; // accesses: 3
    uint field_0x33; // accesses: 5
    float field_0x34; // accesses: 15
    float field_0x38; // accesses: 15
    undefined1 * field_0x39; // accesses: 6
    byte field_0x3a; // accesses: 4
    int field_0x3b; // accesses: 1
    ulong field_0x3c; // accesses: 25
    float field_0x40; // accesses: 11
    int * field_0x44; // accesses: 8
    ulong field_0x48; // accesses: 22
    CSystemArchiveNod * field_0x4c; // accesses: 10
    char field_0x4d; // accesses: 5
    byte _padding_0x4e[2];
    int field_0x50; // accesses: 15
    undefined2 field_0x54; // accesses: 14
    short field_0x56; // accesses: 1
    float field_0x58; // accesses: 14
    ulong field_0x5c; // accesses: 23
    ulong field_0x60; // accesses: 14
    ulong field_0x64; // accesses: 6
    CPlugShader * field_0x68; // accesses: 8
    float field_0x6c; // accesses: 11
    float field_0x70; // accesses: 5
    CPlugBitmap * field_0x74; // accesses: 22
    float field_0x78; // accesses: 4
    CPlugBitmap * field_0x7c; // accesses: 7
    CPlugBitmap * field_0x80; // accesses: 8
    float field_0x84; // accesses: 7
    undefined4 field_0x88; // accesses: 1
    undefined4 field_0x8c; // accesses: 1
    float field_0x90; // accesses: 3
    float field_0x94; // accesses: 6
    float field_0x98; // accesses: 3
    float field_0x9c; // accesses: 4
    float field_0xa0; // accesses: 40
    int field_0xa4; // accesses: 7
    float field_0xa8; // accesses: 2
    float field_0xac; // accesses: 20
    int field_0xb0; // accesses: 17
    float field_0xb4; // accesses: 3
    float field_0xb8; // accesses: 1
    float field_0xbc; // accesses: 4
    float field_0xc0; // accesses: 1
    int field_0xc4; // accesses: 22
    float field_0xc8; // accesses: 4
    float field_0xcc; // accesses: 17
    CHmsCorpusLight * field_0xd0; // accesses: 4
    undefined4 field_0xd4; // accesses: 1
    byte _padding_0xd8[4];
    code * field_0xdc; // accesses: 2
    byte _padding_0xe0[8];
    ulong field_0xe8; // accesses: 2
    CVisionViewportDx9 * field_0xec; // accesses: 2
    int field_0xf0; // accesses: 3
    float field_0xf4; // accesses: 1
    IDirect3DSurface9 * field_0xf8; // accesses: 1
    CHmsCamera * field_0xfc; // accesses: 2
    int field_0x100; // accesses: 2
    float field_0x104; // accesses: 7
    byte _padding_0x108[20];
    float field_0x11c; // accesses: 1
    undefined4 field_0x120; // accesses: 3
    undefined4 field_0x124; // accesses: 6
    byte _padding_0x128[12];
    int field_0x134; // accesses: 1
    byte _padding_0x138[40];
    undefined4 field_0x160; // accesses: 1
    byte _padding_0x164[16];
    undefined4 field_0x174; // accesses: 2
    byte _padding_0x178[100];
    uint field_0x1dc; // accesses: 4
    byte _padding_0x1e0[28];
    CHmsCamera * field_0x1fc; // accesses: 1
    byte _padding_0x200[16];
    int field_0x210; // accesses: 2
    byte _padding_0x214[36];
    int field_0x238; // accesses: 2
    byte _padding_0x23c[12];
    int field_0x248; // accesses: 5
    int field_0x24c; // accesses: 4
    byte _padding_0x250[84];
    int field_0x2a4; // accesses: 5
    int field_0x2a8; // accesses: 5
    byte _padding_0x2ac[12];
    int field_0x2b8; // accesses: 9
    byte _padding_0x2bc[60];
    int field_0x2f8; // accesses: 1
    byte _padding_0x2fc[24];
    int field_0x314; // accesses: 2
    undefined4 field_0x318; // accesses: 1
    byte _padding_0x31c[16];
    int field_0x32c; // accesses: 3
    byte _padding_0x330[32];
    CHmsCamera * field_0x350; // accesses: 2
    byte _padding_0x354[48];
    undefined4 * field_0x384; // accesses: 14
    ushort field_0x386; // accesses: 12
    ushort field_0x388; // accesses: 26
    ushort field_0x38a; // accesses: 19
    undefined4 field_0x38c; // accesses: 2
    byte _padding_0x390[48];
    SRenderShaderParam * field_0x3c0; // accesses: 5
    byte _padding_0x3c4[80];
    uint field_0x414; // accesses: 41
    undefined4 field_0x418; // accesses: 2
    CVisionViewportDx9 * field_0x41c; // accesses: 6
    CPlugBitmapRenderWater * field_0x420; // accesses: 4
    undefined4 field_0x424; // accesses: 5
    undefined4 field_0x428; // accesses: 4
    undefined4 field_0x42c; // accesses: 6
    undefined4 field_0x430; // accesses: 2
    int field_0x434; // accesses: 3
    uint field_0x438; // accesses: 1
    byte _padding_0x43c[12];
    CMwId * field_0x448; // accesses: 3
    int field_0x44c; // accesses: 6
    CVisionViewportDx9 * field_0x450; // accesses: 5
    byte _padding_0x454[24];
    int field_0x46c; // accesses: 4
    byte _padding_0x470[664];
    int * field_0x708; // accesses: 7
    byte _padding_0x70c[268];
    undefined4 field_0x818; // accesses: 1
    byte _padding_0x81c[4];
    undefined4 field_0x820; // accesses: 1
    undefined4 field_0x824; // accesses: 1
    byte _padding_0x828[12];
    undefined4 field_0x834; // accesses: 1
    undefined4 field_0x838; // accesses: 1
    undefined4 field_0x83c; // accesses: 1
    undefined4 field_0x840; // accesses: 1
    undefined4 field_0x844; // accesses: 1
    undefined4 field_0x848; // accesses: 1
    undefined4 field_0x84c; // accesses: 1
    undefined4 field_0x850; // accesses: 6
    undefined4 field_0x854; // accesses: 4
    undefined4 field_0x858; // accesses: 3
    SCasterCat * field_0x85c; // accesses: 3
    undefined4 field_0x860; // accesses: 3
    undefined4 field_0x864; // accesses: 2
    CPlugTree * field_0x868; // accesses: 11
    byte _padding_0x86c[36];
    undefined4 field_0x890; // accesses: 1
    undefined4 field_0x894; // accesses: 1
    undefined4 field_0x898; // accesses: 1
    undefined4 field_0x89c; // accesses: 1
    undefined4 field_0x8a0; // accesses: 1
    undefined4 field_0x8a4; // accesses: 1
    undefined4 field_0x8a8; // accesses: 1
    undefined4 field_0x8ac; // accesses: 1
    undefined4 field_0x8b0; // accesses: 1
    undefined4 field_0x8b4; // accesses: 1
    byte _padding_0x8b8[16];
    undefined4 field_0x8c8; // accesses: 1
    byte _padding_0x8cc[24];
    CPlugVisual * field_0x8e4; // accesses: 12
    CMwId * field_0x8e8; // accesses: 9
    CVisionViewportDx9 * field_0x8ec; // accesses: 4
    byte _padding_0x8f0[20];
    undefined4 field_0x904; // accesses: 8
    undefined4 field_0x908; // accesses: 1
    undefined4 field_0x90c; // accesses: 1
    undefined4 field_0x910; // accesses: 1
    int field_0x914; // accesses: 3
    undefined4 field_0x918; // accesses: 3
    ulong field_0x91c; // accesses: 12
    undefined4 field_0x920; // accesses: 7
    undefined4 field_0x924; // accesses: 1
    undefined4 field_0x928; // accesses: 1
    undefined4 * field_0x92c; // accesses: 2
    byte _padding_0x930[12];
    undefined4 field_0x93c; // accesses: 1
    undefined4 field_0x940; // accesses: 1
    undefined4 field_0x944; // accesses: 1
    undefined4 field_0x948; // accesses: 1
    byte _padding_0x94c[72];
    int field_0x994; // accesses: 1
    byte _padding_0x998[12];
    undefined4 field_0x9a4; // accesses: 1
    undefined4 field_0x9a8; // accesses: 1
    byte _padding_0x9ac[76];
    float * field_0x9f8; // accesses: 63
    byte _padding_0x9fc[60];
    undefined4 field_0xa38; // accesses: 1
    undefined4 field_0xa3c; // accesses: 1
    undefined4 field_0xa40; // accesses: 1
    undefined4 field_0xa44; // accesses: 1
    undefined4 field_0xa48; // accesses: 1
    int * field_0xa4c; // accesses: 5
    undefined4 field_0xa50; // accesses: 2
    undefined4 field_0xa54; // accesses: 5
    undefined4 field_0xa58; // accesses: 3
    int field_0xa5c; // accesses: 4
    SRasterizeVertex * field_0xa60; // accesses: 8
    float field_0xa64; // accesses: 2
    float field_0xa68; // accesses: 5
    float field_0xa6c; // accesses: 5
    float field_0xa70; // accesses: 5
    byte _padding_0xa74[2084];
    CVisionViewportDx9 * field_0x1298; // accesses: 2
    byte _padding_0x129c[28];
    int field_0x12b8; // accesses: 2
    float field_0x12bc; // accesses: 2
    byte _padding_0x12c0[100];
    CVisionViewport * field_0x1324; // accesses: 2
    byte _padding_0x1328[4];
    CPlugShader * field_0x132c; // accesses: 2
    byte _padding_0x1330[324];
    CPlugFileGPUP * field_0x1474; // accesses: 1
    CPlugFileGPUP * field_0x1478; // accesses: 1
    CPlugFileGPUP * field_0x147c; // accesses: 1
    byte _padding_0x1480[32];
    CPlugFileGPUP * field_0x14a0; // accesses: 2
    CPlugFileGPUP * field_0x14a4; // accesses: 1
    CPlugFileGPUP * field_0x14a8; // accesses: 1
    byte _padding_0x14ac[64];
    CPlugFileGPUP * field_0x14ec; // accesses: 1
    byte _padding_0x14f0[16];
    CPlugFileGPUP * field_0x1500; // accesses: 1
    CPlugFileGPUP * field_0x1504; // accesses: 1
    CPlugFileGPUP * field_0x1508; // accesses: 1
    byte _padding_0x150c[8];
    int field_0x1514; // accesses: 1
    byte _padding_0x1518[4];
    CPlugBitmap * field_0x151c; // accesses: 26
    byte _padding_0x1520[20];
    CPlugShaderApply * field_0x1534; // accesses: 3
    CPlugFileGPUV * field_0x1538; // accesses: 2
    byte _padding_0x153c[100];
    undefined4 field_0x15a0; // accesses: 1
    int field_0x15a4; // accesses: 4
    undefined4 field_0x15a8; // accesses: 3
    undefined4 field_0x15ac; // accesses: 1
    byte _padding_0x15b0[36];
    CPlugTree * field_0x15d4; // accesses: 8
    byte _padding_0x15d8[12];
    undefined4 field_0x15e4; // accesses: 1
    byte _padding_0x15e8[8];
    undefined4 field_0x15f0; // accesses: 1
    undefined4 field_0x15f4; // accesses: 1
    undefined4 field_0x15f8; // accesses: 1
    undefined4 field_0x15fc; // accesses: 1
    undefined4 field_0x1600; // accesses: 1
    undefined4 field_0x1604; // accesses: 1
    undefined4 field_0x1608; // accesses: 1
    undefined4 field_0x160c; // accesses: 1
    undefined4 field_0x1610; // accesses: 1
    byte _padding_0x1614[3401247];
    uint field_0x33fc33; // accesses: 1
    byte _padding_0x33fc37[590793];
    byte field_0x3d0000; // accesses: 1
    byte _padding_0x3d0001[474951883];
    byte field_0x1c8c30cc; // accesses: 2
    byte _padding_0x1c8c30cd[128220514];
    byte field_0x2430ae2f; // accesses: 2
    byte _padding_0x2430ae30[302085377];
    uint field_0x36322331; // accesses: 2
    byte _padding_0x36322335[27005207];
    uint field_0x37ce344c; // accesses: 2
    byte _padding_0x37ce3450[191206371];
    uint field_0x4333c833; // accesses: 1
    byte _padding_0x4333c837[117312762];
    uint field_0x4a31d531; // accesses: 2
    byte _padding_0x4a31d535[1761603836];
    uint field_0xb331c631; // accesses: 4
    byte _padding_0xb331c635[1073945855];
    uint field_0xf334e334; // accesses: 1
};

struct CVisionViewportDx9_CCameraFxDx9 {
    byte _padding_0x0[20];
    CVisionViewportDx9 * field_0x14; // accesses: 1
    byte _padding_0x18[12];
    int field_0x24; // accesses: 2
    byte _padding_0x28[536];
    int field_0x240; // accesses: 1
    byte _padding_0x244[1696];
    undefined4 field_0x8e4; // accesses: 2
    byte _padding_0x8e8[28];
    undefined4 field_0x904; // accesses: 2
};

struct CVisionViewportNull {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
};

struct CVisionVisualKeeper {
    byte _padding_0x0[4];
    CVisionVisualKeeper * field_0x4; // accesses: 1
};

struct GmArchive {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 9
    float field_0x8; // accesses: 7
    float field_0xc; // accesses: 2
};

struct GmBoxAligned {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 29
    float field_0x8; // accesses: 31
    float field_0xc; // accesses: 13
    float field_0x10; // accesses: 10
    float field_0x14; // accesses: 12
    float field_0x18; // accesses: 3
    float field_0x1c; // accesses: 2
    float field_0x20; // accesses: 2
    float field_0x24; // accesses: 1
    float field_0x28; // accesses: 1
    float field_0x2c; // accesses: 1
};

struct GmBoxOriented {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 3
    float field_0x8; // accesses: 3
    float field_0xc; // accesses: 3
    float field_0x10; // accesses: 3
    float field_0x14; // accesses: 3
    float field_0x18; // accesses: 3
    float field_0x1c; // accesses: 3
    float field_0x20; // accesses: 3
};

struct GmCamFreeVal {
    byte _padding_0x0[48];
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
};

struct GmField2 {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 3
    byte _padding_0x8[20];
    int field_0x1c; // accesses: 1
    byte _padding_0x20[4];
    float field_0x24; // accesses: 1
};

struct GmField2Base {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 9
    float field_0x8; // accesses: 1
    byte _padding_0xc[8];
    float field_0x14; // accesses: 1
    float field_0x18; // accesses: 1
    int field_0x1c; // accesses: 6
    int field_0x20; // accesses: 6
};

struct GmFrustum {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 9
    float field_0x8; // accesses: 10
    float field_0xc; // accesses: 9
    float field_0x10; // accesses: 8
    float field_0x14; // accesses: 9
    float field_0x18; // accesses: 3
    float field_0x1c; // accesses: 3
    float field_0x20; // accesses: 3
    float field_0x24; // accesses: 3
    float field_0x28; // accesses: 3
    float field_0x2c; // accesses: 3
    float field_0x30; // accesses: 2
    float field_0x34; // accesses: 2
    float field_0x38; // accesses: 2
    float field_0x3c; // accesses: 2
    float field_0x40; // accesses: 2
    float field_0x44; // accesses: 2
    float field_0x48; // accesses: 2
    float field_0x4c; // accesses: 2
    undefined4 field_0x50; // accesses: 2
    undefined4 field_0x54; // accesses: 2
    undefined4 field_0x58; // accesses: 2
    float field_0x5c; // accesses: 1
};

struct GmFunc {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 1
};

struct GmIso3 {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 3
    float field_0x8; // accesses: 3
    float field_0xc; // accesses: 3
    float field_0x10; // accesses: 6
    float field_0x14; // accesses: 6
};

struct GmIso4 {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 33
    float field_0x8; // accesses: 32
    float field_0xc; // accesses: 17
    float field_0x10; // accesses: 15
    float field_0x14; // accesses: 15
    float field_0x18; // accesses: 14
    float field_0x1c; // accesses: 13
    float field_0x20; // accesses: 13
    float field_0x24; // accesses: 11
    float field_0x28; // accesses: 11
    float field_0x2c; // accesses: 11
};

struct GmLensVal {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 2
    float field_0x8; // accesses: 2
    float field_0xc; // accesses: 10
    float field_0x10; // accesses: 10
};

struct GmLocFreeVal {
    byte _padding_0x0[36];
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
};

struct GmLooseOctree_struct_SHmsVPackerObject_class_CHmsVPackerCell_class_CHmsVPackerLevel {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 11
    float field_0x8; // accesses: 6
    float field_0xc; // accesses: 6
    float field_0x10; // accesses: 10
    float field_0x14; // accesses: 8
    float field_0x18; // accesses: 5
    undefined4 field_0x1c; // accesses: 1
    float field_0x20; // accesses: 1
    float field_0x24; // accesses: 1
    float field_0x28; // accesses: 1
    byte _padding_0x2c[20];
    float field_0x40; // accesses: 1
    float field_0x44; // accesses: 1
    float field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    int field_0x58; // accesses: 2
    byte _padding_0x5c[4];
    undefined4 field_0x60; // accesses: 3
    byte _padding_0x64[8];
    int field_0x6c; // accesses: 5
    int field_0x70; // accesses: 5
};

struct GmMap2_unsigned_char {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 6
};

struct GmMat3 {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 34
    float field_0x8; // accesses: 35
    float field_0xc; // accesses: 9
    float field_0x10; // accesses: 9
    float field_0x14; // accesses: 9
    float field_0x18; // accesses: 9
    float field_0x1c; // accesses: 9
    float field_0x20; // accesses: 9
};

struct GmMat4 {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 17
    float field_0x8; // accesses: 17
    float field_0xc; // accesses: 17
    float field_0x10; // accesses: 11
    float field_0x14; // accesses: 11
    float field_0x18; // accesses: 9
    float field_0x1c; // accesses: 6
    float field_0x20; // accesses: 6
    float field_0x24; // accesses: 6
    float field_0x28; // accesses: 6
    float field_0x2c; // accesses: 6
};

struct GmMat43 {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
};

struct GmOctree_struct_CHmsCollisionManager_SColOctreeCell {
    byte _padding_0x0[4];
    TiXmlAttribute * field_0x4; // accesses: 18
    float field_0x8; // accesses: 4
    float field_0xc; // accesses: 5
    float field_0x10; // accesses: 3
    float field_0x14; // accesses: 4
    float field_0x18; // accesses: 3
    byte _padding_0x1c[48];
    undefined4 field_0x4c; // accesses: 12
};

struct GmOctree_struct_SMeshOctreeCell {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 20
    undefined4 field_0x8; // accesses: 10
    undefined4 field_0xc; // accesses: 11
    undefined4 field_0x10; // accesses: 10
    void * field_0x14; // accesses: 11
    undefined4 field_0x18; // accesses: 11
    undefined4 field_0x1c; // accesses: 9
};

struct GmQuadTree_struct_SQuadTreeMeshUv {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 13
    float * field_0x8; // accesses: 8
    float field_0xc; // accesses: 8
    TiXmlAttributeSet * field_0x10; // accesses: 8
    undefined4 field_0x14; // accesses: 10
};

struct GmQuat {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 15
    float field_0x8; // accesses: 14
    float field_0xc; // accesses: 13
    float field_0x10; // accesses: 2
    float field_0x14; // accesses: 1
    float field_0x18; // accesses: 1
    float field_0x1c; // accesses: 1
    float field_0x20; // accesses: 2
};

struct GmRectAligned {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 7
    float field_0x8; // accesses: 6
    float field_0xc; // accesses: 6
};

struct GmScaleTrans2 {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 8
    float field_0x8; // accesses: 8
    float field_0xc; // accesses: 8
};

struct GmSurf {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 7
    float field_0x8; // accesses: 9
    undefined2 field_0x9; // accesses: 2
    byte _padding_0xb[1];
    float field_0xc; // accesses: 4
    float field_0x10; // accesses: 4
    undefined4 field_0x14; // accesses: 3
    float field_0x18; // accesses: 3
    float field_0x1c; // accesses: 3
    byte _padding_0x20[4];
    float field_0x24; // accesses: 2
    float field_0x28; // accesses: 1
    float field_0x2c; // accesses: 2
};

struct GmSurfEllipsoid {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 3
    undefined4 field_0xc; // accesses: 3
    undefined4 field_0x10; // accesses: 3
    undefined4 field_0x14; // accesses: 1
};

struct GmSurfMesh {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 38
    float field_0x8; // accesses: 40
    float field_0xc; // accesses: 7
    float field_0x10; // accesses: 5
    float field_0x14; // accesses: 6
    float field_0x18; // accesses: 5
    undefined2 field_0x1c; // accesses: 1
    byte _padding_0x1e[6];
    int field_0x24; // accesses: 3
};

struct GmSurfPolygon {
    byte _padding_0x0[72];
    undefined4 field_0x48; // accesses: 1
};

struct GmSurfSphere {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 6
    float field_0x8; // accesses: 11
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 1
};

struct GmUnit {
    byte _padding_0x0[4];
    char * field_0x4; // accesses: 2
};

struct GmVec2 {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 16
    float field_0x8; // accesses: 2
    float field_0xc; // accesses: 2
    float field_0x10; // accesses: 1
    float field_0x14; // accesses: 1
};

struct GmVec3 {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 31
    float field_0x8; // accesses: 31
    float field_0xc; // accesses: 3
    float field_0x10; // accesses: 3
    float field_0x14; // accesses: 3
    float field_0x18; // accesses: 3
    float field_0x1c; // accesses: 3
    float field_0x20; // accesses: 3
    float field_0x24; // accesses: 4
    float field_0x28; // accesses: 4
    float field_0x2c; // accesses: 4
};

struct GmVec4 {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 37
    float field_0x8; // accesses: 41
    float field_0xc; // accesses: 25
    float field_0x10; // accesses: 11
    float field_0x14; // accesses: 5
    float field_0x18; // accesses: 9
    float field_0x1c; // accesses: 2
    float field_0x20; // accesses: 2
    float field_0x24; // accesses: 2
    float field_0x28; // accesses: 2
    float field_0x2c; // accesses: 2
};

struct GmVector3_int {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 2
    int field_0x8; // accesses: 2
};

struct GxBGRAColor {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 1
    float field_0x8; // accesses: 1
};

struct GxClipper {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 1
};

struct GxColor {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 16
    float field_0x8; // accesses: 19
    GmVec3 * field_0xc; // accesses: 1
};

struct GxFog {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
};

struct GxFogBlender {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 2
    byte _padding_0x8[12];
    undefined4 field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 2
    undefined4 * field_0x1c; // accesses: 4
    float field_0x20; // accesses: 3
    float field_0x24; // accesses: 3
    float field_0x28; // accesses: 3
    float field_0x2c; // accesses: 3
    float field_0x30; // accesses: 3
    float field_0x34; // accesses: 3
    float field_0x38; // accesses: 3
    float field_0x3c; // accesses: 3
};

struct GxLight {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 2
    float field_0x8; // accesses: 2
    byte _padding_0xc[12];
    float field_0x18; // accesses: 4
    float field_0x1c; // accesses: 4
    float field_0x20; // accesses: 4
    float field_0x24; // accesses: 3
    float field_0x28; // accesses: 2
    float field_0x2c; // accesses: 2
    float field_0x30; // accesses: 2
    float field_0x34; // accesses: 2
};

struct SDx9Static {
    byte _padding_0x0[4];
    ulong field_0x4; // accesses: 2
    byte _padding_0x8[8];
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 1
};

struct SDynaMath {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 12
    float field_0x8; // accesses: 12
};

struct SGridAddChildContext {
    byte _padding_0x0[504];
    code * field_0x1f8; // accesses: 1
};

struct SHmsRenderRect {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
};

struct SHmsSphereBufferContact {
    byte _padding_0x0[16];
    undefined4 field_0x10; // accesses: 1
    byte _padding_0x14[8];
    float field_0x1c; // accesses: 2
    float field_0x20; // accesses: 2
    float field_0x24; // accesses: 2
    byte _padding_0x28[16];
    int field_0x38; // accesses: 2
};

struct SManialinkFormat {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    CMwNod * field_0x34; // accesses: 1
};

struct SNodFid {
    byte _padding_0x0[8];
    int field_0x8; // accesses: 1
};

struct SPlugFaceCull {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 5
    float field_0x8; // accesses: 3
    float field_0xc; // accesses: 2
    float field_0x10; // accesses: 2
    float field_0x14; // accesses: 2
    float field_0x18; // accesses: 2
    float field_0x1c; // accesses: 2
    float field_0x20; // accesses: 2
    float field_0x24; // accesses: 1
    float field_0x28; // accesses: 1
    float field_0x2c; // accesses: 1
};

struct SPlugUrlLink {
    byte _padding_0x0[4];
    SStringParam * field_0x4; // accesses: 1
};

struct SSceneToyBoat_NetState {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 1
    byte _padding_0x8[8];
    float field_0x10; // accesses: 1
    CPlugAudio * field_0x14; // accesses: 1
    byte _padding_0x18[4];
    CSceneToyBoat * field_0x1c; // accesses: 1
    byte _padding_0x20[8];
    int field_0x28; // accesses: 1
    byte _padding_0x2c[140];
    GmVec3 * field_0xb8; // accesses: 1
    GmVec3 * field_0xbc; // accesses: 1
    byte _padding_0xc0[28];
    undefined4 field_0xdc; // accesses: 1
    byte _padding_0xe0[44];
    undefined4 field_0x10c; // accesses: 1
    byte _padding_0x110[8];
    undefined4 field_0x118; // accesses: 1
    undefined4 field_0x11c; // accesses: 1
    byte _padding_0x120[224];
    undefined4 field_0x200; // accesses: 1
};

struct SSceneToyBoat_ReplayState {
    byte _padding_0x0[40];
    int field_0x28; // accesses: 1
    byte _padding_0x2c[92];
    undefined4 field_0x88; // accesses: 1
    undefined4 field_0x8c; // accesses: 1
    byte _padding_0x90[40];
    undefined4 field_0xb8; // accesses: 1
    undefined4 field_0xbc; // accesses: 1
    byte _padding_0xc0[28];
    undefined4 field_0xdc; // accesses: 1
};

struct SSceneToyBoat_SailState {
    byte _padding_0x0[132];
    SSceneToyBoat_SailState * field_0x84; // accesses: 1
    SSceneToyBoat_SailState * field_0x88; // accesses: 1
    undefined4 field_0x8c; // accesses: 1
    undefined4 field_0x90; // accesses: 1
    byte _padding_0x94[4];
    undefined4 field_0x98; // accesses: 1
};

struct SStringParamInt {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
};

struct SSysGraphicAdapter {
    byte _padding_0x0[4];
    WCHAR * field_0x4; // accesses: 1
};

struct SSystemTime {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 7
};

struct STmRaceLowFps {
    byte _padding_0x0[20];
    CPlugAudio * field_0x14; // accesses: 2
};

struct STmValidateParam {
    byte _padding_0x0[232];
    uint field_0xe8; // accesses: 2
    byte _padding_0xec[4];
    uint field_0xf0; // accesses: 2
    byte _padding_0xf4[24];
    undefined4 field_0x10c; // accesses: 1
    byte _padding_0x110[96];
    undefined4 field_0x170; // accesses: 1
};

struct SVehicleSimpleNetState {
    byte _padding_0x0[12];
    short field_0xc; // accesses: 8
    byte _padding_0xe[2];
    int field_0x10; // accesses: 12
    int field_0x14; // accesses: 12
    byte _padding_0x18[4];
    int field_0x1c; // accesses: 4
    byte _padding_0x20[68];
    uint field_0x64; // accesses: 1
    byte _padding_0x68[24];
    float field_0x80; // accesses: 1
};

struct SVehicleSimpleState_ReplayAfter040104 {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 5
    float field_0x8; // accesses: 5
    float field_0xc; // accesses: 5
    float field_0x10; // accesses: 5
    uint field_0x14; // accesses: 5
    float field_0x18; // accesses: 1
    uint field_0x1c; // accesses: 1
    byte _padding_0x20[68];
    uint field_0x64; // accesses: 1
    uint field_0x68; // accesses: 1
    byte _padding_0x6c[20];
    float field_0x80; // accesses: 1
    byte _padding_0x84[4];
    uint field_0x88; // accesses: 1
    uint field_0x8c; // accesses: 1
};

struct SVehicleSimpleState_ReplayAfter081205 {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 9
    float field_0x8; // accesses: 7
    float field_0xc; // accesses: 8
    float field_0x10; // accesses: 9
    int field_0x14; // accesses: 9
    float field_0x18; // accesses: 2
    uint field_0x1c; // accesses: 1
    byte _padding_0x20[4];
    float field_0x24; // accesses: 2
    float field_0x28; // accesses: 2
    byte _padding_0x2c[56];
    int field_0x64; // accesses: 2
    int field_0x68; // accesses: 2
    byte _padding_0x6c[20];
    float field_0x80; // accesses: 2
    byte _padding_0x84[4];
    int field_0x88; // accesses: 2
    int field_0x8c; // accesses: 2
};

struct SVehicleSimpleState_ReplayAfter170806 {
    byte _padding_0x0[44];
    float field_0x2c; // accesses: 2
};

struct SVehicleSimpleState_ReplayAfter211003 {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 5
    float field_0x8; // accesses: 4
    ushort field_0xc; // accesses: 4
    byte _padding_0xe[2];
    uint field_0x10; // accesses: 4
    uint field_0x14; // accesses: 5
    float field_0x18; // accesses: 1
    byte _padding_0x1c[72];
    uint field_0x64; // accesses: 1
    uint field_0x68; // accesses: 1
    byte _padding_0x6c[20];
    float field_0x80; // accesses: 1
};

struct TiXmlAttribute {
    byte _padding_0x0[24];
    int field_0x18; // accesses: 2
};

struct TiXmlAttributeSet {
    byte _padding_0x0[28];
    int field_0x1c; // accesses: 3
    int field_0x20; // accesses: 3
};

struct TiXmlDeclaration {
    byte _padding_0x0[44];
    undefined4 * field_0x2c; // accesses: 1
    undefined4 * field_0x30; // accesses: 1
    undefined4 * field_0x34; // accesses: 1
};

struct TiXmlDocument {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 7
    undefined4 field_0x8; // accesses: 6
    byte _padding_0xc[12];
    int field_0x18; // accesses: 1
    byte _padding_0x1c[20];
    int field_0x30; // accesses: 4
    undefined4 * field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 5
    undefined4 field_0x40; // accesses: 5
};

struct TiXmlElement {
    byte _padding_0x0[24];
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    byte _padding_0x20[44];
    TiXmlElement * field_0x4c; // accesses: 1
};

struct TiXmlNode {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    void * field_0x10; // accesses: 4
    int field_0x14; // accesses: 3
    undefined4 * field_0x18; // accesses: 6
    int field_0x1c; // accesses: 7
    undefined4 * field_0x20; // accesses: 5
    undefined4 field_0x24; // accesses: 2
    TiXmlNode * field_0x28; // accesses: 5
};

struct TiXmlPrinter {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    byte _padding_0x8[4];
    undefined4 * field_0xc; // accesses: 3
    undefined4 * field_0x10; // accesses: 2
    undefined4 * field_0x14; // accesses: 2
};

struct public_void_thiscall_CGameOutlineBox {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 4
    int field_0x8; // accesses: 4
};

