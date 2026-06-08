#ifndef CPLUGBITMAPRENDER_HPP
#define CPLUGBITMAPRENDER_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CPlugBitmapRender : public CMwNod {
public:
    CPlugBitmapRender() : CMwNod() {}
    virtual ~CPlugBitmapRender() {}

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
};

#endif // CPLUGBITMAPRENDER_HPP
