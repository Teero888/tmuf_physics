#ifndef CSCENE_HPP
#define CSCENE_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CScene : public CMwNod {
public:
    CScene() : CMwNod() {}
    virtual ~CScene() {}

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
};

#endif // CSCENE_HPP
