#ifndef CMWCMDAFFECTPARAM_HPP
#define CMWCMDAFFECTPARAM_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CMwCmdAffectParam : public CMwNod {
public:
    CMwCmdAffectParam() : CMwNod() {}
    virtual ~CMwCmdAffectParam() {}

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
};

#endif // CMWCMDAFFECTPARAM_HPP
