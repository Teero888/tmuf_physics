#ifndef CCALLBACKCOMPUTEFORCES_HPP
#define CCALLBACKCOMPUTEFORCES_HPP

#include "CHmsItem.hpp"

class CCallbackSceneToyBroomStickComputeForces;
class CHmsItem;

class CCallbackComputeForces : public CHmsItem::CCallback {
public:
    virtual ~CCallbackComputeForces();
    ECallback GetType() const override { return CB_PHYSICS; }
    virtual void ComputeForces(CHmsItem* item, float dt) override = 0;
};

#endif // CCALLBACKCOMPUTEFORCES_HPP
