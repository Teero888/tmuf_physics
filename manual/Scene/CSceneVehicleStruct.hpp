#ifndef CSCENEVEHICLESTRUCT_HPP
#define CSCENEVEHICLESTRUCT_HPP

#include "CMwNod.hpp"
#include <cstdint>

struct GmFrustumIso4;

class CSceneVehicleStruct : public CMwNod {
public:
    struct SSimulationWheel {
        virtual ~SSimulationWheel();
    };

    struct SVisualArm {
        virtual ~SVisualArm();
        uint32_t field_0x4;
    };

    struct SVisualWheel {
        virtual ~SVisualWheel();
    };

    uint8_t m_padding[64];
    CMwNod* m_nod44;
    CMwNod* m_nod48;
    CMwNod* m_nod4c;

    CSceneVehicleStruct();
    virtual ~CSceneVehicleStruct();

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }

    static CMwNod* MwNewCSceneVehicleStruct();
    
    uint32_t GetMwClassId();
};

#endif // CSCENEVEHICLESTRUCT_HPP
