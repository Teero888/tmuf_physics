#ifndef CDX9DEVICECAPS_HPP
#define CDX9DEVICECAPS_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CDx9DeviceCaps : public CMwNod {
public:
    CDx9DeviceCaps() : CMwNod() {}
    virtual ~CDx9DeviceCaps() {}

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
};

#endif // CDX9DEVICECAPS_HPP
