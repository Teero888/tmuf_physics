#ifndef SHMAC_MD5_DATA_HPP
#define SHMAC_MD5_DATA_HPP

#include "typedefs.h"

struct SHMAC_MD5_Data {
    byte _padding_0x0[24];
    undefined4 field_0x18; // accesses: 2
    undefined4 field_0x1c; // accesses: 2
    undefined4 field_0x20; // accesses: 2
    undefined4 field_0x24; // accesses: 2
};

#endif // SHMAC_MD5_DATA_HPP
