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
    virtual void ComputeForces(CCallbackSceneToyBroomStickComputeForces* param_1, CHmsItem* param_2, float dt) override;
};

#endif // CCALLBACKSCENEVEHICLECARCOMPUTEFORCES_HPP
