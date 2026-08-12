#ifndef CHMSCOLLISIONMANAGER_HPP
#define CHMSCOLLISIONMANAGER_HPP

#include "CMwNod.hpp"
#include "CFastBuffer.hpp"
#include "GmVec3.hpp"
#include "GmIso4.hpp"
#include "GmBoxAligned.hpp"
#include <cstdint>
#include <vector>

// Forward declarations
class CHmsCorpus;
class CHmsZone;
class CHmsCollisionBuffer;
class CPlugTree;
class CPlugSurface;
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
struct LocatedGmSurf;
struct CGmCollisionBuffer;

// Recovered native four-pointer pair passed through the recursive tree
// collision helpers: tree 1, its parent/world transform, tree 2, and its
// parent/world transform.
struct SPlugTreeLocatedPair {
    CPlugTree* m_tree1 = nullptr;
    GmIso4* m_parentToWorld1 = nullptr;
    CPlugTree* m_tree2 = nullptr;
    GmIso4* m_parentToWorld2 = nullptr;
};

class CHmsCollisionManager : public CMwNod {
public:
    struct SGroup {
        struct SAgainstGroup {
            SGroup* m_against = nullptr;
            uint32_t m_config[5]{};
            uint32_t m_lineCount = 0;
            uint32_t m_columnCount = 0;
            std::vector<uint32_t> m_isToPerformCollision;

            uint32_t& Get(uint32_t line, uint32_t column) {
                return m_isToPerformCollision[
                    line * m_columnCount + column];
            }
        };

        // Native 32-bit offsets are 0x00, 0x0c, 0x18, 0x24, and 0x30.
        // These typed members preserve the same semantics without pretending
        // pointer-sized C++ objects retain the executable's byte offsets.
        CFastBuffer<CHmsCorpus*> m_corpuses;
        CFastBuffer<CHmsCorpus*> m_nonStaticCorpuses;
        CFastBuffer<float> m_squaredLinearSpeeds;
        std::vector<SAgainstGroup> m_againstGroups;
        // Native SColOctreeCell stores the box inline at +0x04, transform at
        // +0x1c, surface at +0x4c, corpus at +0x50, and tree at +0x54.
        // The standalone build currently keeps the same leaves in a flat
        // buffer; collision results are identical, with only broadphase
        // acceleration still pending.
        struct SStaticCollisionLeaf {
            GmBoxAligned m_worldBounds;
            GmIso4 m_location;
            CPlugSurface* m_surface = nullptr;
            CHmsCorpus* m_corpus = nullptr;
            CPlugTree* m_tree = nullptr;
        };
        CFastBuffer<SStaticCollisionLeaf> m_staticCollisionTreeData;
        uint32_t m_groupId = 0;
        uint32_t m_skipDynamicPairPreparation = 0;

        SGroup() = default;
        ~SGroup() = default;

        void AddCorpus(CHmsZone* param_1, CHmsCorpus* param_2);
        void AddNonStaticCorpus(CHmsCorpus* param_2);
        void AddStaticSurfacesFromTree(
            CHmsCorpus* corpus,
            CPlugTree* tree,
            const GmIso4* parentToWorld,
            void* unused);
        void ClearAllStatic();
        void ComputeIsToPerformCollisions();
        void ComputeNonStaticCorpusInfos();
        void RemoveCorpus(CHmsZoneOverlay* param_1, CHmsCorpus* param_2);
        void RemoveNonStaticCorpus(CHmsCorpus* param_2);
        void UpdateStaticCollisionTrees(CHmsCollisionManager* param_1);
    };

    struct SZone {
        SGroup m_groups[5];
        uint32_t m_zoneId = 0;
        CHmsCollisionManager* m_manager = nullptr;
        CHmsCorpus* m_corpus18c = nullptr;
        LocatedGmSurf* m_surf190 = nullptr;
        CHmsCollisionBuffer* m_activeCollisionBuffer = nullptr;
        uint32_t* m_activeConfig = nullptr;
        SGroup* m_activeStaticGroup = nullptr;

        SZone(uint32_t zoneId, CHmsCollisionManager* manager);
        ~SZone() = default;

        void RebuildPairTables();

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

    // Native fields +0x14 and +0x18. They are typed semantically for the
    // standalone 64-bit build rather than accessed through native offsets.
    uint32_t m_field_0x14;
    CFastBuffer<SZone*> m_zones;

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
