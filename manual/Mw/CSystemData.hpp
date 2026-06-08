#ifndef CSYSTEMDATA_HPP
#define CSYSTEMDATA_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CSystemData : public CMwNod {
public:
    CSystemData() : CMwNod() {}
    virtual ~CSystemData() {}

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
};

#endif // CSYSTEMDATA_HPP
