#ifndef CGAMECTNCOLLECTION_HPP
#define CGAMECTNCOLLECTION_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CGameCtnCollection : public CMwNod {
public:
    CGameCtnCollection() : CMwNod() {}
    virtual ~CGameCtnCollection() {}

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
};

#endif // CGAMECTNCOLLECTION_HPP
