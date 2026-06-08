#ifndef CHMSZONEOVERLAY_HPP
#define CHMSZONEOVERLAY_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CHmsZoneOverlay : public CMwNod {
public:
    CHmsZoneOverlay() : CMwNod() {}
    virtual ~CHmsZoneOverlay() {}

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
};

#endif // CHMSZONEOVERLAY_HPP
