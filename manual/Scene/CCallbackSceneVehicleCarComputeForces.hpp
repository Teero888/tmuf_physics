#ifndef CCALLBACKSCENEVEHICLECARCOMPUTEFORCES_HPP
#define CCALLBACKSCENEVEHICLECARCOMPUTEFORCES_HPP

#include "CCallbackComputeForces.hpp"
#include <cstdint>

class CHmsItem;
class CCallbackSceneToyBroomStickComputeForces;

class CCallbackSceneVehicleCarComputeForces : public CCallbackComputeForces {
public:
    virtual ~CCallbackSceneVehicleCarComputeForces();

    // Member Functions
    void ComputeForces(CHmsItem* item, float dt) override;

    static CCallbackSceneVehicleCarComputeForces* Instance();
};

#endif // CCALLBACKSCENEVEHICLECARCOMPUTEFORCES_HPP
