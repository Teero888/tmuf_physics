#ifndef CFUNCSEGMENT_HPP
#define CFUNCSEGMENT_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CFuncSegment : public CMwNod {
public:
    CFuncSegment() : CMwNod() {}
    virtual ~CFuncSegment() {}

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
};

#endif // CFUNCSEGMENT_HPP
