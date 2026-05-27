#include "CMwParam.hpp"

// =================================================
// Function: CMwParam::IsIndexed
// Checks if this parameter is a container type (Array, Buffer, etc.)
// by querying specific RTTI virtual functions.
// =================================================
int CMwParam::IsIndexed()
{
    // Retrieve the vtable pointer
    void** vtable = *(void***)this;
    
    // Define the __thiscall function pointer signature for the virtuals
    typedef int (*ContainerCheckFunc)(void*);

    // Offset 0x78 (Index 30) - e.g., IsFastArray()
    ContainerCheckFunc check1 = (ContainerCheckFunc)vtable[30];
    if (check1(this) != 0) return 1;

    // Offset 0x7C (Index 31) - e.g., IsFastBuffer()
    ContainerCheckFunc check2 = (ContainerCheckFunc)vtable[31];
    if (check2(this) != 0) return 1;

    // Offset 0x80 (Index 32) - e.g., IsList()
    ContainerCheckFunc check3 = (ContainerCheckFunc)vtable[32];
    if (check3(this) != 0) return 1;

    // Offset 0x84 (Index 33) - e.g., IsMap/Dict()
    ContainerCheckFunc check4 = (ContainerCheckFunc)vtable[33];
    if (check4(this) != 0) return 1;

    // Not an indexed container
    return 0;
}