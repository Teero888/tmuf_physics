#ifndef CMWCMDBUFFERCORE_HPP
#define CMWCMDBUFFERCORE_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CMwCmdBufferCore : public CMwNod {
public:
    CMwCmdBufferCore() : CMwNod() {}
    virtual ~CMwCmdBufferCore() {}

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
};

#endif // CMWCMDBUFFERCORE_HPP
