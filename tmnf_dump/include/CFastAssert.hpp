#ifndef CFASTASSERT_HPP
#define CFASTASSERT_HPP

#include "typedefs.h"

struct CFastAssert {
    void** vftable;

    // Member Functions
    void __cdecl StaticInit(void);
};

#endif // CFASTASSERT_HPP
