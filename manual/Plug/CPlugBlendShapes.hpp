#ifndef CPLUGBLENDSHAPES_HPP
#define CPLUGBLENDSHAPES_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CPlugBlendShapes : public CMwNod {
public:
    CPlugBlendShapes() : CMwNod() {}
    virtual ~CPlugBlendShapes() {}

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
};

#endif // CPLUGBLENDSHAPES_HPP
