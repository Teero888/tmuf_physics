#ifndef CHMSCOLLISIONMANAGER_HPP
#define CHMSCOLLISIONMANAGER_HPP

#include "typedefs.h"

struct CHmsCollisionManager {
    struct SGroup {
        struct SAgainstGroup {
            void** vftable;

            // Member Functions
            void __thiscall SAgainstGroup(void *this,SAgainstGroup *param_1);
            void __thiscall ~SAgainstGroup(void *this,SAgainstGroup *param_1);
        };

        void** vftable;
        byte _padding_0x4[60];
        int field_0x40; // accesses: 2

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

    struct SZone {
        void** vftable; // accesses: 3
        byte _padding_0x4[56];
        undefined4 field_0x3c; // accesses: 1
        undefined4 field_0x40; // accesses: 1
        byte _padding_0x44[12];
        LocatedGmSurf * field_0x50; // accesses: 3
        byte _padding_0x54[44];
        undefined4 field_0x80; // accesses: 1
        undefined4 field_0x84; // accesses: 1
        byte _padding_0x88[4];
        CMwNod * field_0x8c; // accesses: 1
        byte _padding_0x90[52];
        undefined4 field_0xc4; // accesses: 1
        undefined4 field_0xc8; // accesses: 1
        byte _padding_0xcc[60];
        undefined4 field_0x108; // accesses: 1
        undefined4 field_0x10c; // accesses: 1
        byte _padding_0x110[60];
        undefined4 field_0x14c; // accesses: 1
        undefined4 field_0x150; // accesses: 1
        byte _padding_0x154[36];
        undefined4 field_0x178; // accesses: 1
        undefined4 field_0x17c; // accesses: 1
        undefined4 field_0x180; // accesses: 1
        undefined4 field_0x184; // accesses: 4
        SZone * field_0x188; // accesses: 5
        CHmsCorpus * field_0x18c; // accesses: 3
        LocatedGmSurf * field_0x190; // accesses: 3
        int field_0x194; // accesses: 1
        undefined1 * field_0x198; // accesses: 1
        CMwNod * field_0x19c; // accesses: 3

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

    void** vftable; // accesses: 2
    byte _padding_0x4[16];
    undefined4 field_0x14; // accesses: 1
    byte _final_padding[0xc]; // Total size: 0x24

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
