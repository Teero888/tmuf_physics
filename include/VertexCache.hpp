#ifndef VERTEXCACHE_HPP
#define VERTEXCACHE_HPP

#include "typedefs.h"

struct VertexCache {
    void** vftable; // accesses: 1

    // Member Functions
    void __thiscall ~VertexCache(void *this,VertexCache *param_1);
};

#endif // VERTEXCACHE_HPP
