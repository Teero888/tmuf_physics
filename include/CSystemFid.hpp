#ifndef CSYSTEMFID_HPP
#define CSYSTEMFID_HPP

#include "typedefs.h"

struct CClassicArchive;
struct CMwNod;
struct CSystemFids;

struct CSystemFid {
    struct LoadHeaderUserDataFromChunkId<struct_CSystemArchiveNod {
        void** vftable;

        // Member Functions
        SHeaderFolderDep> (CSystemFid *this,CSystemFid *param_1,SHeaderFolderDep *param_2,ulong param_3,int param_4);
    };

    struct SCallStackFidContext {
        void** vftable; // accesses: 3
        SCallStackFidContext * field_0x4; // accesses: 3

        // Member Functions
        /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ~SCallStackFidContext(void *this,SCallStackFidContext *param_1);
        void __thiscall SCallStackFidContext (void *this,SCallStackFidContext *param_1,CSystemFid *param_2);
    };

    struct SHeaderUserData {
        void** vftable; // accesses: 2

        // Member Functions
        ulong __thiscall ComputeByteSizeTotalInFile(void *this,SHeaderUserData *param_1);
    };

    void** vftable; // accesses: 4
    byte _padding_0x4[16];
    CSystemFids * field_0x14; // accesses: 10
    byte _padding_0x18[4];
    uint field_0x1c; // accesses: 3
    int * field_0x20; // accesses: 11
    byte _padding_0x24[12];
    CSystemFid * field_0x30; // accesses: 7
    byte _padding_0x34[48];
    ulong field_0x64; // accesses: 6
    uint * field_0x68; // accesses: 44
    int * field_0x6c; // accesses: 9
    CLoader * field_0x70; // accesses: 2

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
