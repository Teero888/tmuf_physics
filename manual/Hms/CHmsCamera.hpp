#ifndef CHMSCAMERA_HPP
#define CHMSCAMERA_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CHmsCamera : public CMwNod {
public:
    CHmsCamera() : CMwNod() {}
    virtual ~CHmsCamera() {}

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
};

#endif // CHMSCAMERA_HPP
