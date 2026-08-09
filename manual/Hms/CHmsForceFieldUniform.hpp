#ifndef CHMSFORCEFIELDUNIFORM_HPP
#define CHMSFORCEFIELDUNIFORM_HPP

#include "CHmsForceField.hpp"
#include <cstdint>

class CClassicArchive;
class CMwCmdExpIso4Ident;
struct CPfmHeap;

class CHmsForceFieldUniform : public CHmsForceField {
public:
    float m_force[3]; // 0x5C, 0x60, 0x64

    CHmsForceFieldUniform();
    virtual ~CHmsForceFieldUniform();

    bool GetValue(
        const GmVec3& position, GmVec3& value) const override;

    CMwClassInfo* MwGetClassInfo(CFuncSegment* param_1);
    static CMwNod* MwNewCHmsForceFieldUniform();
    int MwIsKindOf(uint32_t classId);
    uint32_t GetChunkInfo(CFuncSegment* param_1, uint32_t param_2);
    uint32_t GetMwClassId();
    uint32_t GetUidChunkFromIndex(CMwCmdExpIso4Ident* param_1, uint32_t param_2);
    
    void* _scalar_deleting_destructor_(CPfmHeap* param_1, uint32_t param_2);
    void Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3);
};

#endif // CHMSFORCEFIELDUNIFORM_HPP
