#ifndef CMWVALUESTD_HPP
#define CMWVALUESTD_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CMwValueStd : public CMwNod {
public:
    CMwValueStd() : CMwNod() {}
    virtual ~CMwValueStd() {}

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
};

#endif // CMWVALUESTD_HPP
