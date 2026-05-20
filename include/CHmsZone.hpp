#ifndef CHMSZONE_HPP
#define CHMSZONE_HPP

#include "typedefs.h"

struct CHmsItem;
struct CHmsZoneVPacker;
struct CMwNod;

struct CHmsZone {
    struct CVisionData {
        byte _padding_0x0[47];
        byte field_0x2f; // accesses: 2
        byte _padding_0x30[3];
        uint field_0x33; // accesses: 1

        // Member Functions
        /* WARNING: Control flow encountered bad instruction data */ /* WARNING: Instruction at (ram,0x009c0f9a) overlaps instruction at (ram,0x009c0f99) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void * __thiscall CHmsZone::CVisionData::_vector_deleting_destructor_ (CVisionData *this,CRpcCallInternal *param_1,uint param_2);
        void __thiscall ~CVisionData(CVisionData *this,CVisionData *param_1);
    };

    byte _padding_0x0[4];
    int field_0x4; // accesses: 77
    ulong field_0x8; // accesses: 2
    byte _padding_0xc[4];
    int field_0x10; // accesses: 4
    undefined4 field_0x14; // accesses: 10
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

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall VirtualParam_Get (CHmsZone *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall VirtualParam_Set(CHmsZone *this,CSystemData *param_1,CMwStack *param_2,void *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall AddCorpus(CHmsZone *this,SZone *param_1,CHmsCorpus *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CHmsZone(CHmsZone *this,CHmsZone *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall WaterRenderTileHeightSet(CHmsZone *this,CHmsZone *param_1,float param_2);
    CAudioSound * __thiscall AddSound(CHmsZone *this,CAudioPort *param_1,CPlugSound *param_2,EBalanceGroup param_3, int param_4);
    CHmsCorpus * __thiscall CreateZoneCorpus(CHmsZone *this,CHmsZoneOverlay *param_1);
    CMwClassInfo * __thiscall MwGetClassInfo(CHmsZone *this,CFuncSegment *param_1);
    CMwNod * __cdecl MwNewCHmsZone(void);
    int __thiscall CheckPreloadVisionData (CHmsZone *this,CHmsZone *param_1,CHmsViewport *param_2,CHmsCamera *param_3);
    int __thiscall MwIsKindOf(CHmsZone *this,CMwCmdAffectParam *param_1,ulong param_2);
    ulong __thiscall GetChunkInfo(CHmsZone *this,CFuncSegment *param_1,ulong param_2);
    ulong __thiscall GetMwClassId(CHmsZone *this,CControlStyle *param_1);
    ulong __thiscall GetUidChunkFromIndex(CHmsZone *this,CMwCmdExpIso4Ident *param_1,ulong param_2);
    ulong __thiscall VirtualParam_Add (CHmsZone *this,CMwCmdScriptVarClass *param_1,CMwStack *param_2,void *param_3);
    ulong __thiscall VirtualParam_Sub (CHmsZone *this,CGameCtnDecorationMood *param_1,CMwStack *param_2,void *param_3);
    void * __thiscall _vector_deleting_destructor_(CHmsZone *this,CRpcCallInternal *param_1,uint param_2);
    void __thiscall AddField(CHmsZone *this,CHmsZone *param_1,CHmsForceField *param_2);
    void __thiscall AddItem(CHmsZone *this,CGamePopUp *param_1,CFastStringInt *param_2,ulong param_3, int param_4);
    void __thiscall AddLight(CHmsZone *this,CHmsZone *param_1,CHmsLight *param_2,GmIso4 *param_3);
    void __thiscall ApplyFidParameters (CHmsZone *this,CPlugFontBitmap *param_1,CSystemFidParameters *param_2, CSystemFidParameters *param_3,CFastBuffer<struct_CMwNod::SManuallyLoadedFid> *param_4);
    void __thiscall Chunk(CHmsZone *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3);
    void __thiscall CorpusChangeBuild(CHmsZone *this,CHmsZone *param_1,CHmsCorpus *param_2,int param_3);
    void __thiscall CorpusChangeCat (CHmsZone *this,CHmsZone *param_1,ulong param_2,EHmsCorpusCat param_3, EHmsCorpusCat param_4);
    void __thiscall CorpusChangeLightEmitter(CHmsZone *this,CHmsZone *param_1,CHmsCorpus *param_2,int param_3);
    void __thiscall RemoveCorpus(CHmsZone *this,CHmsZoneOverlay *param_1,CHmsCorpus *param_2);
    void __thiscall RemoveField(CHmsZone *this,CHmsZone *param_1,CHmsForceField *param_2);
    void __thiscall RemoveItem(CHmsZone *this,CHmsZone *param_1,CHmsItem *param_2);
    void __thiscall RemoveLight(CHmsZone *this,CHmsZoneVPacker *param_1,CHmsCorpusLight *param_2);
    void __thiscall RemoveSound(CHmsZone *this,CAudioPort *param_1,CAudioSound *param_2);
    void __thiscall VPackerCreate(CHmsZone *this,CHmsZone *param_1,SHmsVPackerCreate *param_2);
    void __thiscall VPackerRemove(CHmsZone *this,CHmsZone *param_1);
    void __thiscall ~CHmsZone(CHmsZone *this,CHmsZone *param_1);
};

#endif // CHMSZONE_HPP
