#ifndef CHMSFORCEFIELD_HPP
#define CHMSFORCEFIELD_HPP

#include "CMwNod.hpp"
#include "GmVec3.hpp"
#include <cstdint>

class CHmsZone;
class CSceneSector;
class CFuncSegment;
class CMwCmdAffectParam;
class CControlStyle;
class CRpcCallInternal;
class CFuncColorGradient;

class CHmsForceField : public CMwNod {
public:
    CHmsZone* m_zone;    // 0x14
    uint8_t m_padding[64];
    uint32_t m_field_0x58;

    CHmsForceField();
    virtual ~CHmsForceField();

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
    virtual GmVec3 GetValue(CFuncColorGradient* param_1, float param_2) { return GmVec3(0,0,0); }

    CMwClassInfo* MwGetClassInfo(CFuncSegment* param_1);
    static CMwNod* MwNewCHmsForceField();
    int MwIsKindOf(uint32_t classId);
    uint32_t GetMwClassId();
    
    void* _vector_deleting_destructor_(CRpcCallInternal* param_1, uint32_t param_2);
    void SetZone(CSceneSector* param_1, CHmsZone* param_2);
};

#endif // CHMSFORCEFIELD_HPP
