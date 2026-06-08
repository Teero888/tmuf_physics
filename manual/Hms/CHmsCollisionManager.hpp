#ifndef CHMSCOLLISIONMANAGER_HPP
#define CHMSCOLLISIONMANAGER_HPP

#include "CMwNod.hpp"
#include "CFastBuffer.hpp"
#include "GmVec3.hpp"
#include "GmIso4.hpp"
#include <cstdint>

// Forward declarations
class CHmsCorpus;
class CHmsZone;
class CHmsCollisionBuffer;
class CPlugTree;
class CHmsZoneOverlay;
class CFuncSegment;
class CMwCmdAffectParam;
class CControlStyle;
class CPlugBlendShapes;
class CMwStack;
class CMwValueStd;
class CSystemData;
class CRpcCallInternal;
class CVisionViewportDx9;
struct GmBoxAligned;
struct SPlugTreeLocatedPair;
struct LocatedGmSurf;
struct CGmCollisionBuffer;

class CHmsCollisionManager : public CMwNod {
public:
    struct SGroup {
        struct SAgainstGroup {
            SGroup* m_against; // 0x00
            void* m_data;      // 0x04
            virtual ~SAgainstGroup();
        };

        virtual ~SGroup();
        uint8_t m_padding[0x20 - 0x04];
        CFastBuffer<SAgainstGroup> m_againstGroups; // 0x20
        uint8_t m_padding2[0x44 - 0x2C]; // Total size 0x44

        void AddCorpus(CHmsZone* param_1, CHmsCorpus* param_2);
        void AddNonStaticCorpus(CHmsCorpus* param_2);
        void AddStaticSurfacesFromTree(CHmsCorpus* param_2, CPlugTree* param_3, GmIso4* param_4, void* param_5);
        void ClearAllStatic();
        void ComputeIsToPerformCollisions();
        void ComputeNonStaticCorpusInfos();
        void RemoveCorpus(CHmsZoneOverlay* param_1, CHmsCorpus* param_2);
        void RemoveNonStaticCorpus(CHmsCorpus* param_2);
        void UpdateStaticCollisionTrees(CHmsCollisionManager* param_1);
    };

    struct SZone {
        virtual ~SZone();
        SGroup m_groups[5]; // 0x04 to 0x153
        
        // 0x154: GmMap2
        uint8_t m_padding[0x15c - 0x154];
        uint32_t m_field_0x15c;
        // ...
        CHmsCorpus* m_corpus18c;
        LocatedGmSurf* m_surf190;

        int ComputeCollision(LocatedGmSurf* param_1, LocatedGmSurf* param_2, CGmCollisionBuffer* param_3);
        int ComputeCollisionTree1RootOnly(SPlugTreeLocatedPair* param_2, GmBoxAligned* param_3);
        int ComputeCollisionTree2RootOnly(SPlugTreeLocatedPair* param_2, GmBoxAligned* param_3);
        int IntersectSegment(int param_2, GmVec3* param_3, GmVec3* param_4, float* param_5, CPlugTree** param_6);
        int IntersectSegment2(int param_2, GmVec3* param_3, GmVec3* param_4, int param_5, float* param_6, GmVec3* param_7);
        int IntersectSegment3(int param_2, GmVec3* param_3, GmVec3* param_4, float* param_5, uint16_t* param_6);
        int IntersectSegmentTree(GmVec3* param_2, GmVec3* param_3, CPlugTree* param_4, GmIso4* param_5, float* param_6);
        int IntersectSegmentTree2(GmVec3* param_2, GmVec3* param_3, int param_4, CPlugTree* param_5, GmIso4* param_6, float* param_7, GmVec3* param_8);
        int IntersectSegmentTree3(GmVec3* param_2, GmVec3* param_3, CPlugTree* param_4, GmIso4* param_5, float* param_6, uint16_t* param_7);
        void AddCorpus(CHmsCorpus* param_2);
        void DetectCollisionBetween(CHmsCorpus* param_2, CHmsCorpus* param_3);
        void DetectCollisionBetweenTreeAndStaticCollisionTree(GmIso4* param_2, CPlugTree* param_3);
        void DetectCollisionsCorpus(CHmsCollisionBuffer* param_2, CHmsCorpus* param_3);
        void PrepareCollisions();
        void RemoveCorpus(CHmsZoneOverlay* param_1, CHmsCorpus* param_2);
        void UpdateStaticCollisionTrees(CHmsCollisionManager* param_1);
    };

    uint8_t m_padding_0x14[16];
    uint32_t m_field_0x14;

    CHmsCollisionManager();
    virtual ~CHmsCollisionManager();

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }

    CMwClassInfo* MwGetClassInfo(CFuncSegment* param_1);
    static CMwNod* MwNewCHmsCollisionManager();
    SZone* AddZone(uint32_t param_2);
    int MwIsKindOf(uint32_t classId);
    uint32_t GetMwClassId();
    
    uint32_t VirtualParam_Get(CPlugBlendShapes* param_1, CMwStack* param_2, CMwValueStd* param_3);
    uint32_t VirtualParam_Set(CSystemData* param_1, CMwStack* param_2, void* param_3);
    
    void* _vector_deleting_destructor_(CRpcCallInternal* param_1, uint32_t param_2);
    static void StaticAddRef();
    static void StaticRelease();
    void DisableStaticCollision();
    void MwIsKilled(CMwNod* param_2);
    void RemoveZone(uint32_t param_2);
    void UpdateStaticCollisionTrees();
};

#endif // CHMSCOLLISIONMANAGER_HPP
