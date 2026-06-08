#ifndef CFUNCCOLORGRADIENT_HPP
#define CFUNCCOLORGRADIENT_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CFuncColorGradient : public CMwNod {
public:
    CFuncColorGradient() : CMwNod() {}
    virtual ~CFuncColorGradient() {}

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
};

#endif // CFUNCCOLORGRADIENT_HPP
