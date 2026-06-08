#ifndef CSCENETOYBOAT_HPP
#define CSCENETOYBOAT_HPP

#include "CMwNod.hpp"
#include "GmVec3.hpp"
#include <cstdint>

class CScene;
class CBoatParam;
class CBoatSail;
class CBoatSailState;
class CSceneToyBoat;
class CSceneMobil;
class CSceneMobilAbsorbContact;
class CHmsItem;
class CHmsPhysicalContact;
class CCallbackSceneToyBroomStickComputeForces;
class CClassicBufferMemory;
struct GmIso4;
struct CPfmHeap;

enum ESailType {
    ST_NONE = 0
};

class CSceneToyBoat : public CMwNod {
public:
    struct SSailManoeuvre {
        virtual ~SSailManoeuvre();
        int field_0x4;
    };

    uint8_t m_padding_boat[16];
    CScene* m_scene14; // 0x14
    uint8_t m_padding2[16];
    int m_field_0x28;
    uint8_t m_padding3[0x41C-0x2C]; // Total size 0x41C

    CSceneToyBoat();
    virtual ~CSceneToyBoat();

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }

    static CMwNod* MwNewCSceneToyBoat();
    
    uint32_t GetMwClassId();
};

#endif // CSCENETOYBOAT_HPP
