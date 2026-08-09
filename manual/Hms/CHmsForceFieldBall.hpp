#ifndef CHMSFORCEFIELDBALL_HPP
#define CHMSFORCEFIELDBALL_HPP

#include "CHmsForceField.hpp"
#include "GmBoxAligned.hpp"
#include <cstdint>

class CPlugVisualStrip;
class CMwCmdExpIso4Ident;
class CSystemData;
class CMwStack;
class CClassicArchive;
class CFuncSegment;
struct CPfmHeap;

class CHmsForceFieldBall : public CHmsForceField {
public:
    float m_pos[3]; // 0x3C, 0x40, 0x44
    uint8_t m_padding2[20];
    uint32_t m_field_0x5c;
    uint32_t m_field_0x60;
    uint32_t m_field_0x64;
    uint32_t m_field_0x68;
    uint32_t m_field_0x6c;
    uint32_t m_field_0x70;
    uint32_t m_field_0x74;
    uint32_t m_field_0x78;

    CHmsForceFieldBall();
    virtual ~CHmsForceFieldBall();

    bool GetValue(
        const GmVec3& position, GmVec3& value) const override;

    CMwClassInfo* MwGetClassInfo(CFuncSegment* param_1);
    static CMwNod* MwNewCHmsForceFieldBall();
    int MwIsKindOf(uint32_t classId);
    int TestBoxOverlap(GmBoxAligned* param_2);
    
    uint32_t GetChunkInfo(CFuncSegment* param_1, uint32_t param_2);
    uint32_t GetMwClassId();
    uint32_t GetUidChunkFromIndex(CMwCmdExpIso4Ident* param_1, uint32_t param_2);
    uint32_t VirtualParam_Set(CSystemData* param_1, CMwStack* param_2, void* param_3);
    
    void* _scalar_deleting_destructor_(CPfmHeap* param_1, uint32_t param_2);
    void Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3);
    void ComputeBoundingBox(CPlugVisualStrip* param_1, uint32_t param_2, uint32_t param_3);
};

#endif // CHMSFORCEFIELDBALL_HPP
