#ifndef CHMSCOLLISIONMANAGER_HPP
#define CHMSCOLLISIONMANAGER_HPP

#include "typedefs.h"

struct CHmsCollisionManager {
    struct CHmsCorpus;
    struct CPlugTree;
    struct CSystemFid;
    struct CSystemFidFile;

    struct SGroup {
        struct SAgainstGroup {

            // Member Functions
            void __thiscall SAgainstGroup(void *this,SAgainstGroup *param_1);
            void __thiscall ~SAgainstGroup(void *this,SAgainstGroup *param_1);
        };

        byte _padding_0x0[8];
        CSystemFidFile * field_0x8; // accesses: 2
        SCasterCat * field_0xc; // accesses: 1
        SCasterCat * field_0x10; // accesses: 2
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

        // Member Functions
        /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeIsToPerformCollisions(void *this,SGroup *param_1);
        void __thiscall AddCorpus(void *this,SZone *param_1,CHmsCorpus *param_2);
        void __thiscall AddNonStaticCorpus(void *this,SGroup *param_1,CHmsCorpus *param_2);
        void __thiscall AddStaticSurfacesFromTree (void *this,SGroup *param_1,CHmsCorpus *param_2,CPlugTree *param_3,GmIso4 *param_4, CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell> *param_5);
        void __thiscall ClearAllStatic(void *this,SGroup *param_1);
        void __thiscall ComputeNonStaticCorpusInfos(void *this,SGroup *param_1);
        void __thiscall RemoveCorpus(void *this,CHmsZoneOverlay *param_1,CHmsCorpus *param_2);
        void __thiscall RemoveNonStaticCorpus(void *this,SGroup *param_1,CHmsCorpus *param_2);
        void __thiscall SGroup(void *this,SGroup *param_1);
        void __thiscall UpdateStaticCollisionTrees(void *this,CHmsCollisionManager *param_1);
        void __thiscall ~SGroup(void *this,SGroup *param_1);
    };

    struct CHmsCollisionBuffer;
    struct CHmsCorpus;
    struct CMwNod;
    struct CSystemData;
    struct GmIso3;
    struct GmIso4;
    struct GmVec3;
    struct SPlugFaceCull;

    struct SZone {
        byte _padding_0x0[4];
        undefined4 * field_0x4; // accesses: 28
        char field_0x6; // accesses: 4
        byte _padding_0x7[1];
        GmVec3 * field_0x8; // accesses: 20
        GmIso3 * field_0xc; // accesses: 12
        int field_0x10; // accesses: 10
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
        uint field_0x9c; // accesses: 5
        byte _padding_0xa0[240];
        LocatedGmSurf * field_0x190; // accesses: 1
        int field_0x194; // accesses: 1
        byte _padding_0x198[52];
        CMwNod * field_0x1cc; // accesses: 1

        // Member Functions
        /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall IntersectSegment (void *this,SZone *param_1,ECollisionGroup param_2,GmVec3 *param_3,GmVec3 *param_4, float *param_5,CPlugTree **param_6);
        /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall IntersectSegment3 (void *this,SZone *param_1,ECollisionGroup param_2,GmVec3 *param_3,GmVec3 *param_4, float *param_5,ushort *param_6);
        /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SZone (void *this,SZone *param_1,ulong param_2,CHmsCollisionManager *param_3);
        int __cdecl ComputeCollision (LocatedGmSurf *param_1,LocatedGmSurf *param_2,CGmCollisionBuffer *param_3);
        int __thiscall ComputeCollisionTree1RootOnly (void *this,SZone *param_1,SPlugTreeLocatedPair *param_2,GmBoxAligned *param_3);
        int __thiscall ComputeCollisionTree2RootOnly (void *this,SZone *param_1,SPlugTreeLocatedPair *param_2,GmBoxAligned *param_3);
        int __thiscall IntersectSegment2 (void *this,SZone *param_1,ECollisionGroup param_2,GmVec3 *param_3,GmVec3 *param_4, int param_5,float *param_6,GmVec3 *param_7);
        int __thiscall IntersectSegmentTree (void *this,SZone *param_1,GmVec3 *param_2,GmVec3 *param_3,CPlugTree *param_4, GmIso4 *param_5,float *param_6);
        int __thiscall IntersectSegmentTree2 (void *this,SZone *param_1,GmVec3 *param_2,GmVec3 *param_3,int param_4,CPlugTree *param_5, GmIso4 *param_6,float *param_7,GmVec3 *param_8);
        int __thiscall IntersectSegmentTree3 (void *this,SZone *param_1,GmVec3 *param_2,GmVec3 *param_3,CPlugTree *param_4, GmIso4 *param_5,float *param_6,ushort *param_7);
        void __thiscall AddCorpus(void *this,SZone *param_1,CHmsCorpus *param_2);
        void __thiscall DetectCollisionBetween (void *this,SZone *param_1,CHmsCorpus *param_2,CHmsCorpus *param_3);
        void __thiscall DetectCollisionBetweenTreeAndStaticCollisionTree (void *this,SZone *param_1,GmIso4 *param_2,CPlugTree *param_3);
        void __thiscall DetectCollisionsCorpus (void *this,SZone *param_1,CHmsCollisionBuffer *param_2,CHmsCorpus *param_3);
        void __thiscall PrepareCollisions(void *this,SZone *param_1);
        void __thiscall RemoveCorpus(void *this,CHmsZoneOverlay *param_1,CHmsCorpus *param_2);
        void __thiscall UpdateStaticCollisionTrees(void *this,CHmsCollisionManager *param_1);
    };

    byte _padding_0x0[4];
    int field_0x4; // accesses: 2
    byte _padding_0x8[8];
    int field_0x10; // accesses: 2
    undefined4 field_0x14; // accesses: 1
    int field_0x18; // accesses: 6
    byte _padding_0x1c[52];
    undefined4 field_0x50; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall VirtualParam_Set (CHmsCollisionManager *this,CSystemData *param_1,CMwStack *param_2,void *param_3);
    CMwClassInfo * __thiscall MwGetClassInfo(CHmsCollisionManager *this,CFuncSegment *param_1);
    CMwNod * __cdecl MwNewCHmsCollisionManager(void);
    SZone * __thiscall AddZone (CHmsCollisionManager *this,CHmsCollisionManager *param_1,ulong param_2);
    int __thiscall MwIsKindOf (CHmsCollisionManager *this,CMwCmdAffectParam *param_1,ulong param_2);
    ulong __thiscall GetMwClassId(CHmsCollisionManager *this,CControlStyle *param_1);
    ulong __thiscall VirtualParam_Get (CHmsCollisionManager *this,CPlugBlendShapes *param_1,CMwStack *param_2, CMwValueStd *param_3);
    void * __thiscall _vector_deleting_destructor_ (CHmsCollisionManager *this,CRpcCallInternal *param_1,uint param_2);
    void __cdecl StaticAddRef(void);
    void __cdecl StaticRelease(void);
    void __thiscall CHmsCollisionManager(CHmsCollisionManager *this,CHmsCollisionManager *param_1);
    void __thiscall DisableStaticCollision (CHmsCollisionManager *this,CHmsCollisionManager *param_1);
    void __thiscall MwIsKilled (CHmsCollisionManager *this,CVisionViewportDx9 *param_1,CMwNod *param_2);
    void __thiscall RemoveZone (CHmsCollisionManager *this,CHmsCollisionManager *param_1,ulong param_2);
    void __thiscall UpdateStaticCollisionTrees (CHmsCollisionManager *this,CHmsCollisionManager *param_1);
    void __thiscall ~CHmsCollisionManager (CHmsCollisionManager *this,CHmsCollisionManager *param_1);
};

#endif // CHMSCOLLISIONMANAGER_HPP
