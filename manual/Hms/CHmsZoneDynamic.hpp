#ifndef CHMSZONEDYNAMIC_HPP
#define CHMSZONEDYNAMIC_HPP

#include "CMwNod.hpp"
#include "SHmsPhysicalCollision.hpp"
#include "CHmsPhysicalContact.hpp"
#include "CFastBuffer.hpp"
#include <cstdint>

class CHmsZone;
class CHmsCorpus;
class CClassicBufferMemory;

class CHmsZoneDynamic : public CMwNod {
public:
    uint8_t m_padding_zone[0x11C - 0x14]; // padding for base CHmsZone if it were inherited
    float m_field_0x11c;
    float m_field_0x120;
    uint8_t m_padding_124[16];
    int* m_ptr134;
    int* m_ptr138;
    uint8_t m_padding_13c[4];
    CFastBuffer<class CHmsItem*> m_dynamicItems; // 0x140
    uint8_t m_padding_14c[12];
    void* m_manager158; // 0x158
    CFastBuffer<SHmsPhysicalCollision> m_collisions; // 0x15C
    void* m_ptr168;
    uint8_t m_final_padding[12];

    CHmsZoneDynamic();
    virtual ~CHmsZoneDynamic();

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }

    static CMwNod* MwNewCHmsZoneDynamic();
    uint32_t GetMwClassId();

    void PhysicsStep2();
    void ComputeCollisionResponse();
    void SolveImpulse(SHmsPhysicalCollision* collision, CHmsPhysicalContact* contact1, CHmsPhysicalContact* contact2);
    void SolveImpulse(SHmsPhysicalCollision* collision, SHmsPhysicalCollision* col2, CHmsCorpus* param_3);
};

#endif // CHMSZONEDYNAMIC_HPP
