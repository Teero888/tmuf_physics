#ifndef CHMSZONEVPACKER_HPP
#define CHMSZONEVPACKER_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CHmsZoneVPacker : public CMwNod {
public:
    CHmsZoneVPacker() : CMwNod() {}
    virtual ~CHmsZoneVPacker() {}

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
};

#endif // CHMSZONEVPACKER_HPP
