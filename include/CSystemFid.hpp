#ifndef CSYSTEMFID_HPP
#define CSYSTEMFID_HPP

#include "typedefs.h"

struct CClassicArchive;
struct CMwNod;
struct CPlugMaterial;
struct CSystemFids;

struct CSystemFid {
    struct LoadHeaderUserDataFromChunkId<struct_CSystemArchiveNod {

        // Member Functions
        SHeaderFolderDep> (CSystemFid *this,CSystemFid *param_1,SHeaderFolderDep *param_2,ulong param_3,int param_4);
    };

    struct SCallStackFidContext {

        // Member Functions
        /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ~SCallStackFidContext(void *this,SCallStackFidContext *param_1);
        void __thiscall SCallStackFidContext (void *this,SCallStackFidContext *param_1,CSystemFid *param_2);
    };

    struct SHeaderUserData {

        // Member Functions
        ulong __thiscall ComputeByteSizeTotalInFile(void *this,SHeaderUserData *param_1);
    };

    byte _padding_0x0[4];
    undefined * field_0x4; // accesses: 13
    int field_0x8; // accesses: 5
    undefined4 field_0xc; // accesses: 2
    int field_0x10; // accesses: 1
    int * field_0x14; // accesses: 10
    int field_0x18; // accesses: 3
    undefined4 field_0x1c; // accesses: 3
    CPlugMaterial * field_0x20; // accesses: 14
    byte _padding_0x24[8];
    int field_0x2c; // accesses: 2
    int field_0x30; // accesses: 8
    byte _padding_0x34[48];
    ulong field_0x64; // accesses: 6
    uint * field_0x68; // accesses: 44
    undefined4 * field_0x6c; // accesses: 9
    CLoader * field_0x70; // accesses: 2
    byte _padding_0x74[12];
    uint field_0x80; // accesses: 3
    int field_0x84; // accesses: 3

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ CClassicArchive * __thiscall LoadHeaderUserDataFromChunkId_Begin (CSystemFid *this,CSystemFid *param_1,ulong param_2,int param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall LoadHeaderUserDataFromChunkId_End (CSystemFid *this,CSystemFid *param_1,CClassicArchive **param_2);
    CMwNod * __thiscall ParametrizedGetAnyLoadedNodLooselyFittingTheParams (CSystemFid *this,CSystemFid *param_1,CSystemFidParameters *param_2);
    CPlugMaterial * __thiscall GetNod(CSystemFid *this,CSysFidNodRef<class_CPlugMaterial> *param_1);
    CSystemFid * __thiscall ParametrizedGetFid(CSystemFid *this,CSystemFid *param_1,CSystemFidParameters *param_2);
    CSystemFid * __thiscall ParametrizedGetLoadableFid(CSystemFid *this,CSystemFid *param_1);
    int __thiscall ArchiveHeaderUserData(CSystemFid *this,CSystemFid *param_1,CClassicArchive *param_2);
    int __thiscall HeaderUserDataCreateFromArchive (CSystemFid *this,CSystemFid *param_1,CClassicArchive *param_2,ulong param_3);
    int __thiscall IsLoaded(CSystemFid *this,CSystemFid *param_1);
    ulong __thiscall GetClassId(CSystemFid *this,CSystemFid *param_1);
    ulong __thiscall VirtualParam_Get (CSystemFid *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3);
    void __thiscall BufferClose(CSystemFid *this,CSystemFid *param_1,CClassicBuffer *param_2);
    void __thiscall BuildHeaderUserData(CSystemFid *this,CSystemFid *param_1,CSystemArchiveNod *param_2);
    void __thiscall CSystemFid(CSystemFid *this,CSystemFid *param_1);
    void __thiscall ConcatLocation(CSystemFid *this,CSystemFid *param_1,int param_2);
    void __thiscall DetachNod(CSystemFid *this,CSystemFid *param_1,CMwNod *param_2);
    void __thiscall LoadHeaderUserData(CSystemFid *this,CSystemFid *param_1,CClassicBuffer *param_2);
    void __thiscall MergeLocation(CSystemFid *this,CSystemFid *param_1,int param_2);
    void __thiscall ParametrizedAddFid(CSystemFid *this,CSystemFid *param_1,CSystemFid *param_2);
    void __thiscall ResetHeaderUserDatas(CSystemFid *this,CSystemFid *param_1);
    void __thiscall SetNoHeaderUserDatas(CSystemFid *this,CSystemFid *param_1);
    void __thiscall SetNod(CSystemFid *this,CSysFidNodRef<class_CScene3d> *param_1,CScene3d *param_2);
    void __thiscall SetVirtualLoader(CSystemFid *this,CSystemFid *param_1,CLoader *param_2,ulong param_3);
    void __thiscall UpdateFidProps(CSystemFid *this,CLoaderFidContainer *param_1,CSystemFid *param_2);
    void __thiscall ~CSystemFid(CSystemFid *this,CSystemFid *param_1);
};

#endif // CSYSTEMFID_HPP
