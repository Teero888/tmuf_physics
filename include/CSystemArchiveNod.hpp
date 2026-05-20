#ifndef CSYSTEMARCHIVENOD_HPP
#define CSYSTEMARCHIVENOD_HPP

#include "typedefs.h"

struct CClassicArchive;
struct CClassicBuffer;
struct CClassicBufferMemory;
struct CMwNod;
struct CSystemEngine;
struct CSystemFid;
struct CSystemFidFile;
struct CSystemFidMemory;
struct CSystemFidParameters;
struct CSystemFids;
struct CSystemManagerFile;

struct CSystemArchiveNod {
    struct SHeaderFolderDep {
        byte _padding_0x0[8];
        int field_0x8; // accesses: 2

        // Member Functions
        int __thiscall FillHeaderUserData (void *this,SHeader *param_1,ulong param_2,CGameSkin *param_3,int *param_4);
        void __thiscall Archive (void *this,CFastCrypt<unsigned_long> *param_1,CClassicArchive *param_2);
    };

    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 46
    undefined4 field_0x8; // accesses: 21
    undefined4 field_0xc; // accesses: 11
    undefined4 field_0x10; // accesses: 9
    undefined4 field_0x14; // accesses: 8
    undefined4 field_0x18; // accesses: 17
    undefined4 field_0x1c; // accesses: 48
    byte _padding_0x20[8];
    int field_0x28; // accesses: 2
    byte _padding_0x2c[4];
    int field_0x30; // accesses: 2
    byte _padding_0x34[24];
    undefined4 field_0x4c; // accesses: 6
    undefined4 field_0x50; // accesses: 90
    byte _padding_0x54[4];
    undefined4 field_0x58; // accesses: 2
    undefined4 field_0x5c; // accesses: 16
    int field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 4
    byte _padding_0x68[4];
    undefined4 * field_0x6c; // accesses: 10
    byte _padding_0x70[4];
    undefined4 field_0x74; // accesses: 3
    undefined4 field_0x78; // accesses: 12
    undefined4 field_0x7c; // accesses: 5
    undefined4 field_0x80; // accesses: 2
    undefined4 field_0x84; // accesses: 5
    undefined4 field_0x88; // accesses: 5
    undefined4 field_0x8c; // accesses: 9
    undefined4 field_0x90; // accesses: 7
    undefined4 field_0x94; // accesses: 2
    undefined4 field_0x98; // accesses: 5
    undefined4 field_0x9c; // accesses: 6
    undefined4 field_0xa0; // accesses: 2
    undefined4 field_0xa4; // accesses: 12

    // Member Functions
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ int __thiscall DoFidSaveFile(CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod *param_2);
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ int __thiscall DoFidSaveFileSafe (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod *param_2,ulong param_3);
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ int __thiscall DoLoadHeader(CSystemArchiveNod *this,CSystemArchiveNod *param_1);
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ int __thiscall DoLoadRef(CSystemArchiveNod *this,CSystemArchiveNod *param_1);
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ int __thiscall ExtractExternalLocations (CSystemArchiveNod *this,CSystemArchiveNod *param_1, CFastBuffer<class_CSystemFids*> **param_2,CSystemFidsDrive *param_3);
    CPlugVisual * __thiscall Duplicate(CSystemArchiveNod *this,CPlugVisualVertexs *param_1);
    int __cdecl LoadFileFrom (CFastStringInt *param_1,CMwNod **param_2,CSystemFids *param_3,EArchive param_4);
    int __cdecl LoadFromFid(CMwNod **param_1,CSystemFid *param_2,EArchive param_3);
    int __cdecl LoadFromFid<class_CMwNod> (CMwNodRef<class_CMwNod> *param_1,CSystemFid *param_2,EArchive param_3);
    int __cdecl LoadFromFid<class_CPlugSolid> (CMwNodRef<class_CPlugSolid> *param_1,CSystemFid *param_2,EArchive param_3);
    int __cdecl LoadFromFid<class_CPlugSound> (CMwNodRef<class_CPlugSound> *param_1,CSystemFid *param_2,EArchive param_3);
    int __cdecl LoadFromFid<class_CVisionResourceFile> (CMwNodRef<class_CVisionResourceFile> *param_1,CSystemFid *param_2,EArchive param_3);
    int __cdecl LoadMemoryTemp(CClassicBufferMemory *param_1,CMwNod **param_2);
    int __cdecl LoadResource(ulong param_1,CMwNod **param_2);
    int __cdecl Save(CMwNod *param_1,ulong param_2,int param_3);
    int __cdecl SaveFile (CFastStringInt *param_1,CMwNod *param_2,CSystemFids *param_3,ulong param_4, EArchive param_5,int param_6);
    int __cdecl SaveMemoryTemp (CClassicBufferMemory *param_1,CMwNod *param_2,ulong param_3,int param_4);
    int __cdecl SaveMemoryToFile(CSystemFid *param_1,CClassicBufferMemory *param_2);
    int __thiscall AddInternalRef (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod *param_2,ulong *param_3, char *param_4);
    int __thiscall DoFidLoadFile (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod **param_2);
    int __thiscall DoFidLoadMemory (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod **param_2);
    int __thiscall DoFidLoadRefs (CSystemArchiveNod *this,CSystemArchiveNod *param_1,EArchive param_2, CClassicBuffer *param_3);
    int __thiscall DoFidSaveMemory (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod *param_2);
    int __thiscall DoFindNod (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod **param_2,CSystemFid *param_3);
    int __thiscall DoIsFileSame (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CSystemFid *param_2, CClassicBufferMemory *param_3);
    int __thiscall DoLoadAll(CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod **param_2);
    int __thiscall DoLoadAllRef(CSystemArchiveNod *this,CSystemArchiveNod *param_1);
    int __thiscall DoLoadBody(CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod **param_2);
    int __thiscall DoLoadFile (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CFastStringInt *param_2, CMwNod **param_3,CSystemFids *param_4,EArchive param_5);
    int __thiscall DoLoadFromFid (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod **param_2);
    int __thiscall DoLoadMemory (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CClassicBufferMemory *param_2, CMwNod **param_3);
    int __thiscall DoLoadMemoryTemp (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CClassicBufferMemory *param_2, CMwNod **param_3);
    int __thiscall DoLoadResource (CSystemArchiveNod *this,CSystemArchiveNod *param_1,ulong param_2,CMwNod **param_3);
    int __thiscall DoSave (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod *param_2,ulong param_3, EArchive param_4,int param_5);
    int __thiscall DoSaveAll(CSystemArchiveNod *this,CSystemArchiveNod *param_1);
    int __thiscall DoSaveBody(CSystemArchiveNod *this,CSystemArchiveNod *param_1);
    int __thiscall DoSaveBodyMemory (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod *param_2);
    int __thiscall DoSaveFile (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CFastStringInt *param_2, CMwNod *param_3,CSystemFids *param_4,ulong param_5,EArchive param_6,int param_7);
    int __thiscall DoSaveHeader(CSystemArchiveNod *this,CSystemArchiveNod *param_1);
    int __thiscall DoSaveMemory (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CClassicBufferMemory *param_2, CMwNod *param_3,ulong param_4);
    int __thiscall DoSaveMemoryTemp (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CClassicBufferMemory *param_2, CMwNod *param_3,ulong param_4,int param_5);
    int __thiscall DoSaveRef(CSystemArchiveNod *this,CSystemArchiveNod *param_1);
    int __thiscall InsertExternalLocations (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CSystemFids *param_2, CFastBuffer<class_CSystemFids*> *param_3);
    int __thiscall LoadCurrentHeader (CSystemArchiveNod *this,CSystemArchiveNod *param_1,EVersion param_2);
    void __cdecl ComputeCrcNat32(CMwNod *param_1,ulong *param_2);
    void __cdecl ComputeCrcString(CMwNod *param_1,CFastString *param_2);
    void __thiscall CSystemArchiveNod(CSystemArchiveNod *this,CSystemArchiveNod *param_1);
    void __thiscall Compare (CSystemArchiveNod *this,SParam_Fids *param_1,SParam *param_2,int *param_3,int *param_4);
    void __thiscall DoDecode(CSystemArchiveNod *this,CSystemArchiveNod *param_1,ulong param_2);
    void __thiscall DoFormatFromFid(CSystemArchiveNod *this,CSystemArchiveNod *param_1);
    void __thiscall ParametrizedFinalization (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod *param_2);
    void __thiscall ParametrizedFindOrAddFid (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CSystemFid *param_2,CMwNod *param_3);
    void __thiscall ~CSystemArchiveNod(CSystemArchiveNod *this,CSystemArchiveNod *param_1);
};

#endif // CSYSTEMARCHIVENOD_HPP
