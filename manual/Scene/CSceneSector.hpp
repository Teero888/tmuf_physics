#ifndef CSCENESECTOR_HPP
#define CSCENESECTOR_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CSceneSector : public CMwNod {
public:
    CSceneSector() : CMwNod() {}
    virtual ~CSceneSector() {}

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
};

#endif // CSCENESECTOR_HPP
