#include "CHmsZoneDynamic.hpp"
#include "CHmsDyna.hpp"
#include "CHmsCorpus.hpp"
#include "CHmsItem.hpp"
#include "SHmsPhysicalCollision.hpp"
#include "CHmsPhysicalContact.hpp"
#include "CPlugSurfaceMaterialData.hpp"
#include "CPlugSolid.hpp"
#include <algorithm>
#include <algorithm>

CHmsZoneDynamic::CHmsZoneDynamic() : CMwNod() {
    // Exact constructor writes at 0x54A350..0x54A35F.
    m_field_0x11c = 1.0f;
    m_field_0x120 = 1.0f;
}
CHmsZoneDynamic::~CHmsZoneDynamic() {}

CMwNod* CHmsZoneDynamic::MwNewCHmsZoneDynamic() { return new CHmsZoneDynamic(); }
uint32_t CHmsZoneDynamic::GetMwClassId() { return 0x06004000; }

void CHmsZoneDynamic::PhysicsStep2() {
    float dt = 0.01f; // Stub timestep

    // 1. Loop over all dynamic items and apply forces and pre-collision integration
    uint32_t count = m_dynamicItems.GetCount();
    for (uint32_t i = 0; i < count; ++i) {
        CHmsItem* item = m_dynamicItems[i];
        if (!item) continue;
        
        // In reality, this calls ComputeCorpusForces, then CHmsDyna::DoPreCollisionDynamic
        // For our test harness, item has corpuses, and we integrate the first corpus's dyna.
        if (item->m_corpuses.GetCount() > 0) {
            CHmsCorpus* corpus = item->m_corpuses[0];
            if (corpus && corpus->m_dyna) {
                // One velocity integration per physics frame. Vehicle and
                // environment callbacks have accumulated their forces first.
                corpus->m_dyna->Integrate(dt); // Updates pos/vel based on forces
            }
        }
    }
    
    // 2. Collision detection (populates m_collisions)
    // CHmsCollisionManager::DetectCollisionsCorpus(...) is stubbed out.
    // The harness manually injects collisions into m_collisions via Raycast right now.
    
    // 3. Collision Response
    ComputeCollisionResponse();
    
    // 4. Post-collision integration
    for (uint32_t i = 0; i < count; ++i) {
        CHmsItem* item = m_dynamicItems[i];
        if (!item) continue;
        
        if (item->m_corpuses.GetCount() > 0) {
            CHmsCorpus* corpus = item->m_corpuses[0];
            if (corpus && corpus->m_dyna) {
                // Post-collision (Finalize velocity to position)
                corpus->m_dyna->Move(dt);
            }
        }
    }
}

void CHmsZoneDynamic::ComputeCollisionResponse() {
    uint32_t count = m_collisions.GetCount();
    for (uint32_t i = 0; i < count; ++i) {
        SHmsPhysicalCollision& col = m_collisions[i];
        
        // Check if collision is a physical response (not a trigger/callback only)
        // Ghidra: if (*(int *)(*(int *)(pSVar4 + 0x48) + 8) == 0) -> skips SolveImpulse
        // For the manual stub, just call it anyway!
        if (col.m_ptr48 != nullptr && col.m_ptr48[2] != 0) {
            SolveImpulse(&col, static_cast<CHmsPhysicalContact*>(nullptr), static_cast<CHmsPhysicalContact*>(nullptr));
        } else {
            SolveImpulse(&col, static_cast<CHmsPhysicalContact*>(nullptr), static_cast<CHmsPhysicalContact*>(nullptr)); // STUB: ALWAYS SOLVE
        }
    }
    
    m_collisions.m_count = 0; // Clear for next frame
}

void CHmsZoneDynamic::SolveImpulse(SHmsPhysicalCollision* collision, CHmsPhysicalContact* contact1, CHmsPhysicalContact* contact2) {
    if (!collision || !collision->m_body1) return;
    
    CHmsDyna* dyna1 = collision->m_body1->m_dyna;
    if (!dyna1) return;
    
    // Get current velocity
    GmVec3 vel;
    dyna1->GetLocalLinearSpeed(&vel);
    
    // Dot product with normal
    float velAlongNormal = vel.x * collision->m_normal.x + vel.y * collision->m_normal.y + vel.z * collision->m_normal.z;
    
extern GmVec3 g_stub_pos;

    // If we're falling into the ground, stop the velocity along the normal and apply a tiny bounce
    if (velAlongNormal < 0) {
        float restitution = 0.0f; // No bounce
        float j = -(1.0f + restitution) * velAlongNormal;
        
        // Apply impulse (velocity change)
        vel.x += j * collision->m_normal.x;
        vel.y += j * collision->m_normal.y;
        vel.z += j * collision->m_normal.z;
        
        dyna1->SetLocalLinearSpeed(&vel);
        
        // Resolve penetration (snap to surface)
        // m_pos is the hit point on the ground. The car center should be slightly above it.
        if (collision->m_normal.y > 0.5f) {
            float desiredY = collision->m_pos.y + 0.35f;
            if (g_stub_pos.y < desiredY) {
                g_stub_pos.y = desiredY;
            }
        }
    }
}
