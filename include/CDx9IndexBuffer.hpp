#ifndef CDX9INDEXBUFFER_HPP
#define CDX9INDEXBUFFER_HPP

#include "typedefs.h"

struct CDx9IndexBuffer {
    void** vftable; // accesses: 2
    byte _padding_0x4[28];
    uint field_0x20; // accesses: 1
};

#endif // CDX9INDEXBUFFER_HPP
