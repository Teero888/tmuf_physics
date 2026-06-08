#ifndef CGAMECTNZONE_HPP
#define CGAMECTNZONE_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CGameCtnZone : public CMwNod {
public:
    CGameCtnZone() : CMwNod() {}
    virtual ~CGameCtnZone() {}

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
};

#endif // CGAMECTNZONE_HPP
