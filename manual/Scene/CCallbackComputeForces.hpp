#ifndef CCALLBACKCOMPUTEFORCES_HPP
#define CCALLBACKCOMPUTEFORCES_HPP

#include <cstdint>

class CCallbackSceneToyBroomStickComputeForces;
class CHmsItem;

class CCallbackComputeForces {
public:
    virtual ~CCallbackComputeForces();
    virtual void ComputeForces(CCallbackSceneToyBroomStickComputeForces* param_1, CHmsItem* param_2, float param_3) = 0;
};

#endif // CCALLBACKCOMPUTEFORCES_HPP
