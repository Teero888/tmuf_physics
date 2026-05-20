#ifndef CFASTRADIXSORT_HPP
#define CFASTRADIXSORT_HPP

#include "typedefs.h"

struct CFastRadixSort {
    void** vftable; // accesses: 4
    float * field_0x4; // accesses: 3
    int * field_0x8; // accesses: 13
    void * field_0xc; // accesses: 10
    undefined4 field_0x10; // accesses: 3
    undefined4 field_0x14; // accesses: 3

    // Member Functions
    /* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */ CFastRadixSort * __thiscall Sort(void *this,CFastRadixSort *param_1,float *param_2,ulong param_3);
    void __thiscall CFastRadixSort(void *this,CFastRadixSort *param_1);
    void __thiscall ResetIndices(void *this,CFastRadixSort *param_1);
    void __thiscall ~CFastRadixSort(void *this,CFastRadixSort *param_1);
};

#endif // CFASTRADIXSORT_HPP
