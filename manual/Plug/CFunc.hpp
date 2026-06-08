#ifndef CFUNC_HPP
#define CFUNC_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CFunc : public CMwNod {
public:
    CFunc() : CMwNod() {}
    virtual ~CFunc() {}

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
};

#endif // CFUNC_HPP
