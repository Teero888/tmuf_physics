#ifndef CMWNODREF_CLASS_CMWNOD__HPP
#define CMWNODREF_CLASS_CMWNOD__HPP

#include "typedefs.h"

struct CMwNod;

struct CMwNodRef<class_CMwNod> {
    void** vftable; // accesses: 8
};

#endif // CMWNODREF_CLASS_CMWNOD__HPP
