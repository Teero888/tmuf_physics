#ifndef CHMSVIEWPORT_HPP
#define CHMSVIEWPORT_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CHmsViewport : public CMwNod {
public:
    CHmsViewport() : CMwNod() {}
    virtual ~CHmsViewport() {}

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
};

#endif // CHMSVIEWPORT_HPP
