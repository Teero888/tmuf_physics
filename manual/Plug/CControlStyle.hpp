#ifndef CCONTROLSTYLE_HPP
#define CCONTROLSTYLE_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CControlStyle : public CMwNod {
public:
    CControlStyle() : CMwNod() {}
    virtual ~CControlStyle() {}

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
};

#endif // CCONTROLSTYLE_HPP
