#ifndef CPLUGTREE_HPP
#define CPLUGTREE_HPP

#include "typedefs.h"

struct CClassicArchive;
struct CMwNod;
struct CPlugMaterial;
struct CPlugMaterialCustom;
struct CPlugShader;
struct CPlugShaderApply;
struct CPlugShaderGeneric;
struct CPlugSolid;
struct CPlugVisual;
struct CVisionVisualKeeper;

struct CPlugTree {
    struct CIteratorMaterial {
        void** vftable;
        void * field_0x4; // accesses: 1
        byte _padding_0x8[4];
        int field_0xc; // accesses: 5

        // Member Functions
        CPlugMaterial * __thiscall GetNextMaterial (void *this,CIteratorMaterial *param_1,CPlugTree **param_2);
        void __thiscall CIteratorMaterial (void *this,CIteratorMaterial *param_1,CPlugTree *param_2,EMode param_3);
        void __thiscall ResetItMaterial (void *this,CIteratorMaterial *param_1,CPlugTree *param_2,EMode param_3);
        void __thiscall ~CIteratorMaterial(void *this,CIteratorMaterial *param_1);
    };

    struct CIteratorShader {
        void** vftable;
        byte _padding_0x4[8];
        int field_0xc; // accesses: 5

        // Member Functions
        CPlugShader * __thiscall GetNextShader(void *this,CIteratorShader *param_1,CPlugTree **param_2);
        void __thiscall CIteratorShader (void *this,CIteratorShader *param_1,CPlugTree *param_2,EMode param_3);
        void __thiscall ResetItShader (void *this,CIteratorShader *param_1,CPlugTree *param_2,EMode param_3);
    };

    struct CIteratorSurface {
        void** vftable;
        byte _padding_0x4[8];
        int field_0xc; // accesses: 4

        // Member Functions
        CPlugSurface * __thiscall GetNextSurface (void *this,CIteratorSurface *param_1,CPlugTree **param_2);
        void __thiscall ResetItSurface (void *this,CIteratorSurface *param_1,CPlugTree *param_2,EMode param_3);
    };

    struct CPlugModelTree;

    struct CIteratorTree {
        void** vftable; // accesses: 2
        byte _padding_0x4[8];
        CPlugTree * field_0xc; // accesses: 7
        CPlugTree * field_0x10; // accesses: 3

        // Member Functions
        CPlugModelTree * __thiscall GetNextTree(void *this,CPlugModelTree_ItTree *param_1);
        void __thiscall CIteratorTree (void *this,CIteratorTree *param_1,CPlugTree *param_2,EMode param_3);
        void __thiscall ResetItTree (void *this,CIteratorTree *param_1,CPlugTree *param_2,EMode param_3);
    };

    struct CIteratorVisual {
        void** vftable;
        byte _padding_0x4[8];
        int field_0xc; // accesses: 5

        // Member Functions
        CPlugVisual * __thiscall GetNextVisual(void *this,CIteratorVisual *param_1,CPlugTree **param_2);
        void __thiscall CIteratorVisual (void *this,CIteratorVisual *param_1,CPlugTree *param_2,EMode param_3);
        void __thiscall ResetItVisual (void *this,CIteratorVisual *param_1,CPlugTree *param_2,EMode param_3);
    };

    struct CPlugSolid;

    struct SVolatileTreePointer {
        void** vftable; // accesses: 3

        // Member Functions
        CPlugTree * __thiscall GetTree(void *this,SVolatileTreePointer *param_1);
        void __thiscall Archive (void *this,CFastCrypt<unsigned_long> *param_1,CClassicArchive *param_2);
        void __thiscall SVolatileTreePointer(void *this,SVolatileTreePointer *param_1);
        void __thiscall ~SVolatileTreePointer(void *this,SVolatileTreePointer *param_1);
    };

    void** vftable; // accesses: 65
    byte _padding_0x4[8];
    int field_0xc; // accesses: 1
    byte _padding_0x10[4];
    CPlugSolid * field_0x14; // accesses: 10
    undefined4 field_0x18; // accesses: 9
    CMwNod * field_0x1c; // accesses: 20
    int field_0x20; // accesses: 1
    CPlugTree * field_0x24; // accesses: 6
    byte _padding_0x28[12];
    undefined4 field_0x34; // accesses: 6
    undefined4 field_0x38; // accesses: 6
    undefined4 field_0x3c; // accesses: 6
    undefined4 field_0x40; // accesses: 6
    undefined4 field_0x44; // accesses: 6
    undefined4 field_0x48; // accesses: 6
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    uint field_0x54; // accesses: 14
    short field_0x56; // accesses: 4
    void * field_0x58; // accesses: 3
    byte _padding_0x5c[36];
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
    undefined4 field_0x88; // accesses: 1
    CMwNod * field_0x8c; // accesses: 23
    int * field_0x90; // accesses: 54
    CMwNod * field_0x94; // accesses: 61
    CMwNod * field_0x98; // accesses: 31
    uint field_0x9c; // accesses: 122
    int * field_0xa0; // accesses: 27
    CMwCmdAffectParamBool * field_0xa4; // accesses: 7
    CMwNod * field_0xa8; // accesses: 10

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ CPlugTree * __cdecl MakeQuad2D (CPlug *param_1,float param_2,float param_3,CPlugVisual *param_4,float param_5, ulong param_6,ulong param_7,ulong param_8,GmVec2 *param_9,GmVec2 *param_10, GmVec2 *param_11);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ CPlugTree * __thiscall GetAllChildNext(CPlugTree *this,CPlugTree *param_1,ulong *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ CPlugVisual * __thiscall CreateGroupVisual(CPlugTree *this,CPlugTree *param_1,SPlugTreeOptimGroup *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ CPlugVisual * __thiscall GetAllVisualNext(CPlugTree *this,CPlugTree *param_1,ulong *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall IsEqual(CPlugTree *this,CPlugTree *param_1,SPlugTreeOptimGroup *param_2, SPlugTreeOptimCriteria *param_3,SPlugTreeOptimTravel *param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall UpdateBoundingBox(CPlugTree *this,CPlugTree *param_1,int param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall GetAllChildStart(CPlugTree *this,CPlugTree *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall GetAllVisualStart(CPlugTree *this,CPlugTree *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall VirtualParam_Get (CPlugTree *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall VirtualParam_Set(CPlugTree *this,CSystemData *param_1,CMwStack *param_2,void *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CPlugTree(CPlugTree *this,CPlugTree *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GetOptimizedGroups (CPlugTree *this,CPlugCrystal *param_1,CFastBuffer<struct_SPlugTreeOptimGroup*> *param_2, SPlugTreeOptimCriteria *param_3,SPlugTreeOptimTravel *param_4,CPlugTree *param_5);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GetThisAndVolatileChildsBoundingBox (CPlugTree *this,CPlugTree *param_1,GmBoxAligned *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GetVolatileTreePointer (CPlugTree *this,CPlugTree *param_1,EVolatileTreeType param_2, SVolatileTreePointer *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetSubVisualIndex (CPlugTree *this,CPlugTree *param_1,ulong param_2,ulong param_3,float param_4);
    CControlBase * __thiscall AddChild(CPlugTree *this,SGridAddChildContext *param_1,char *param_2,CMwNod *param_3, char *param_4,ulong param_5);
    CMwClassInfo * __thiscall MwGetClassInfo(CPlugTree *this,CFuncSegment *param_1);
    CMwNod * __cdecl MwNewCPlugTree(void);
    CPlugShader * __thiscall ChangeShaderClass(CPlugTree *this,CPlugTree *param_1,ulong param_2);
    CPlugSolid * __thiscall CreateModelInstance(CPlugTree *this,CPlugSolid *param_1);
    CPlugSurface * __thiscall CreateGroupSurface(CPlugTree *this,CPlugTree *param_1,SPlugTreeOptimGroup *param_2);
    CPlugTree * __thiscall CreateChildFromVisual(CPlugTree *this,CPlugTree *param_1,CPlugVisual *param_2);
    CPlugTree * __thiscall DetachChild(CPlugTree *this,CPlugTreeVisualMip *param_1,ulong param_2);
    CPlugTree * __thiscall DetachChildPtr(CPlugTree *this,CPlugTree *param_1,CPlugTree *param_2);
    CPlugTree * __thiscall DuplicateRecursive(CPlugTree *this,CPlugTree *param_1);
    CPlugTree * __thiscall DuplicateThis(CPlugTree *this,CPlugTree *param_1);
    CPlugTree * __thiscall GetAllTreeNext(CPlugTree *this,CPlugTree *param_1,ulong *param_2);
    CPlugTree * __thiscall GetChild(CPlugTree *this,CPlugTreeVisualMip *param_1,ulong param_2);
    CPlugTree * __thiscall GetChildFromId(CPlugTree *this,CPlugTree *param_1,CMwId *param_2);
    CPlugTree * __thiscall GetFirstParentOfClassId(CPlugTree *this,CPlugTree *param_1,ulong param_2);
    CPlugTree * __thiscall GetLastChild(CPlugTree *this,CPlugTree *param_1);
    CPlugTree * __thiscall GetModelTree(CPlugTree *this,CPlugTree *param_1);
    CPlugTree * __thiscall GetPlugFromId(CPlugTree *this,CPlugSolid *param_1,CMwId *param_2);
    CPlugTree * __thiscall GetPlugFromModelId(CPlugTree *this,CPlugTree *param_1,CMwId *param_2);
    CPlugTree * __thiscall InternalCreateSolidModelInstance(CPlugTree *this,CPlugTree *param_1);
    CPlugTree * __thiscall InternalCreateSolidModelInstanceThis(CPlugTree *this,CPlugTree *param_1);
    CPlugTree * __thiscall InternalGetChildFromPointer (CPlugTree *this,CPlugTree *param_1,SVolatileTreePointer *param_2);
    CPlugTree * __thiscall InternalRecursiveCreate (CPlugTree *this,CPlugTreeVisualMip *param_1,_func___cdecl_CPlugTree_ptr *param_2, int param_3,CPlugTree *param_4);
    CPlugTree * __thiscall MakeGroupTree (CPlugTree *this,CPlugTree *param_1,SPlugTreeOptimGroup *param_2, SPlugTreeOptimCriteria *param_3);
    int __thiscall FindTree(CPlugTree *this,CPlugTree *param_1,CPlugTree *param_2);
    int __thiscall GetDecorationBoundingBox (CPlugTree *this,CPlugTreeLight *param_1,int param_2,GmBoxAligned *param_3);
    int __thiscall GetIsRooted(CPlugTree *this,CPlugTree *param_1);
    int __thiscall HasPlugCrystal(CPlugTree *this,CPlugTree *param_1);
    int __thiscall HideInvalidTrees(CPlugTree *this,CPlugTree *param_1);
    int __thiscall IsOptimizable(CPlugTree *this,CPlugTree *param_1,SPlugTreeOptimCriteria *param_2);
    int __thiscall IsVisualValid(CPlugTree *this,CPlugTree *param_1);
    int __thiscall MergePrimitivesInTree (CPlugTree *this,CPlugTree *param_1,CPlugShader *param_2, CFastBuffer<class_CPlugVisual*> *param_3);
    int __thiscall MwIsKindOf(CPlugTree *this,CMwCmdAffectParam *param_1,ulong param_2);
    ulong __thiscall GetChildCount(CPlugTree *this,CPlugTreeVisualMip *param_1);
    ulong __thiscall GetChildIndex(CPlugTree *this,CPlugTreeVisualMip *param_1,CPlugTree *param_2);
    ulong __thiscall GetChunkCount(CPlugTree *this,CPlugSoundMood *param_1);
    ulong __thiscall GetChunkInfo(CPlugTree *this,CFuncSegment *param_1,ulong param_2);
    ulong __thiscall GetMwClassId(CPlugTree *this,CControlStyle *param_1);
    ulong __thiscall GetRecursiveTreeCount(CPlugTree *this,CPlugTree *param_1,int param_2,int param_3);
    ulong __thiscall GetRecursiveVertexCount (CPlugTree *this,CPlugTreeVisualMip *param_1,int param_2,int param_3);
    ulong __thiscall GetRootedChildCount(CPlugTree *this,CPlugTree *param_1);
    ulong __thiscall GetUidChunkFromIndex(CPlugTree *this,CMwCmdExpIso4Ident *param_1,ulong param_2);
    ulong __thiscall GetVolatileChildCount(CPlugTree *this,CPlugTree *param_1);
    ulong __thiscall VirtualParam_Sub (CPlugTree *this,CGameCtnDecorationMood *param_1,CMwStack *param_2,void *param_3);
    void * __thiscall _scalar_deleting_destructor_(CPlugTree *this,CPfmHeap *param_1,uint param_2);
    void __thiscall ApplyFidParameters (CPlugTree *this,CPlugFontBitmap *param_1,CSystemFidParameters *param_2, CSystemFidParameters *param_3,CFastBuffer<struct_CMwNod::SManuallyLoadedFid> *param_4);
    void __thiscall Chunk(CPlugTree *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3);
    void __thiscall ConnectAsChild(CPlugTree *this,CPlugTree *param_1,CPlugTree *param_2,int param_3);
    void __thiscall CopyFrom(CPlugTree *this,SParam_Set *param_1,SParam *param_2);
    void __thiscall CopyFromModel(CPlugTree *this,CPlugTreeLight *param_1,CPlugTree *param_2,int param_3);
    void __thiscall DeconnectAsChild(CPlugTree *this,CPlugTree *param_1,CPlugTree *param_2);
    void __thiscall DeleteAllChilds(CPlugTree *this,CPlugTreeVisualMip *param_1);
    void __thiscall DeleteAllVolatileChilds(CPlugTree *this,CPlugTree *param_1);
    void __thiscall DeleteChild(CPlugTree *this,CPlugTree *param_1,ulong param_2);
    void __thiscall DeleteChildPtr(CPlugTree *this,CPlugTree *param_1,CPlugTree *param_2);
    void __thiscall DisconnectFromModel(CPlugTree *this,CPlugSolid *param_1,int param_2);
    void __thiscall DisconnectThisFromModel (CPlugTree *this,CPlugTreeLight *param_1,int param_2,ulong param_3);
    void __thiscall Generate(CPlugTree *this,CPlugTree *param_1,int param_2);
    void __thiscall GenerateOptimizedTree (CPlugTree *this,CPlugTree *param_1,CPlugTree **param_2,SPlugTreeOptimCriteria *param_3);
    void __thiscall GetThisToRootTransfo (CPlugTree *this,CPlugTree *param_1,GmIso4 *param_2,int param_3,CPlugTree *param_4);
    void __thiscall InternalCopyVolatileChilds(CPlugTree *this,CPlugTree *param_1,CPlugTree *param_2);
    void __thiscall InternalLoadSetSurface(CPlugTree *this,CPlugTree *param_1,CMwNod *param_2);
    void __thiscall InternalSetMwId(CPlugTree *this,CPlugTree *param_1,CMwId *param_2);
    void __thiscall OnNodLoaded(CPlugTree *this,CDx9DeviceCaps *param_1);
    void __thiscall RefreshThisFromModel(CPlugTree *this,CPlugTree *param_1);
    void __thiscall RenderBefore (CPlugTree *this,CPlugTreeFrustum *param_1,GmFrustum *param_2,GmBoxAligned *param_3, GmIso4 *param_4,GmIso4 *param_5,int *param_6,SPlugTreeInRenderFlags param_7);
    void __thiscall SetChild(CPlugTree *this,CPlugTreeVisualMip *param_1,CPlugTree *param_2,ulong param_3);
    void __thiscall SetFuncTree(CPlugTree *this,CPlugTree *param_1,CFuncTree *param_2);
    void __thiscall SetGenerator(CPlugTree *this,CPlugTree *param_1,CPlugTreeGenerator *param_2,int param_3);
    void __thiscall SetIdName(CPlugTree *this,CMwNod *param_1,char *param_2);
    void __thiscall SetIsPickableVisual(CPlugTree *this,CPlugTree *param_1,int param_2);
    void __thiscall SetIsRooted(CPlugTree *this,CPlugTree *param_1,int param_2);
    void __thiscall SetIsVisible(CPlugTree *this,CPlugTree *param_1,int param_2);
    void __thiscall SetLocation(CPlugTree *this,CPlugTree *param_1,GmIso4 *param_2);
    void __thiscall SetMaterial(CPlugTree *this,CPlugMaterialCustom *param_1,CPlugMaterial *param_2);
    void __thiscall SetPlugId(CPlugTree *this,CPlugTree *param_1,CMwId *param_2);
    void __thiscall SetRotation(CPlugTree *this,GmMat2 *param_1,float param_2);
    void __thiscall SetShader(CPlugTree *this,CPlugBitmapShader *param_1,CPlugShader *param_2);
    void __thiscall SetSurface(CPlugTree *this,CPlugTree *param_1,CPlugSurface *param_2);
    void __thiscall SetTranslation(CPlugTree *this,GmIso4 *param_1,GmVec3 *param_2);
    void __thiscall SetUseLocation(CPlugTree *this,CPlugTree *param_1,int param_2);
    void __thiscall SetVisual(CPlugTree *this,CVisionVisualKeeper *param_1,CPlugVisual *param_2);
    void __thiscall TransformByNOMat(CPlugTree *this,GmSurfMesh *param_1,GmIso4 *param_2);
    void __thiscall ~CPlugTree(CPlugTree *this,CPlugTree *param_1);
};

#endif // CPLUGTREE_HPP
