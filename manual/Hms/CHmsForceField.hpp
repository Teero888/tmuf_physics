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
    CHmsZone* m_zone;             // native +0x14
    uint8_t m_padding[60];        // native +0x18 .. +0x53
    int32_t m_isActive;           // native +0x54 (inherited CHmsPoc state)
    uint32_t m_field_0x58;        // native +0x58

    CHmsForceField();
    virtual ~CHmsForceField();

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
    // Vtable +0x8C in the 32-bit executable. The field writes a world-space
    // acceleration for the queried point and returns whether it applies.
    virtual bool GetValue(
        const GmVec3& position, GmVec3& value) const;

    CMwClassInfo* MwGetClassInfo(CFuncSegment* param_1);
    static CMwNod* MwNewCHmsForceField();
    int MwIsKindOf(uint32_t classId);
    uint32_t GetMwClassId();
    
    void* _vector_deleting_destructor_(CRpcCallInternal* param_1, uint32_t param_2);
    void SetZone(CSceneSector* param_1, CHmsZone* param_2);
};

#endif // CHMSFORCEFIELD_HPP
