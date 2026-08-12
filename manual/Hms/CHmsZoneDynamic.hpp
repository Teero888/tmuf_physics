#ifndef CHMSZONEDYNAMIC_HPP
#define CHMSZONEDYNAMIC_HPP

#include "CMwNod.hpp"
#include "SHmsPhysicalCollision.hpp"
#include "CHmsPhysicalContact.hpp"
#include "CFastBuffer.hpp"
#include <cstdint>

class CHmsZone;
class CHmsCorpus;
class CHmsForceField;
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
    CFastBuffer<CHmsCorpus*> m_dynamicCorpuses; // native +0x140
    uint8_t m_padding_14c[12];
    void* m_manager158; // 0x158
    CFastBuffer<SHmsPhysicalCollision> m_collisions; // 0x15C
    void* m_ptr168;
    uint8_t m_final_padding[12];

    // Host-side storage for the CHmsZone +0x7C buffer represented by the
    // native-layout padding above.
    CFastBuffer<CHmsForceField*> m_forceFields;
    bool m_forcesPrepared;

    CHmsZoneDynamic();
    virtual ~CHmsZoneDynamic();

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }

    static CMwNod* MwNewCHmsZoneDynamic();
    uint32_t GetMwClassId();

    void AddForceField(CHmsForceField* field);
    void RemoveForceField(CHmsForceField* field);
    void ComputeCorpusForces(CHmsCorpus* corpus, float dt);
    void PrepareForPhysicsStep(float dt = 0.01f);
    void PhysicsStep2(float dt = 0.01f);
    void ComputeCollisionResponse();
    void SolveImpulse(
        SHmsPhysicalCollision* collision,
        CHmsPhysicalContact* body1Contact,
        CHmsPhysicalContact* body2Contact);
    void SolveImpulse(SHmsPhysicalCollision* collision, SHmsPhysicalCollision* col2, CHmsCorpus* param_3);
};

#endif // CHMSZONEDYNAMIC_HPP
