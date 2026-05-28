#include "SMwIdInternal.hpp"

// =================================================
// Function: SMwIdInternal::SMwIdInternal
// =================================================
SMwIdInternal::SMwIdInternal() 
{
    // In standard C++, when this constructor is called, the compiler 
    // automatically injects the default constructors for all member variables.
    
    // 1. m_stringArena (CFastBuffer) is constructed at offset 0x00.
    
    // 2. m_buckets[32] (CFastArray) triggers the MSVC _eh_vector_constructor_iterator_
    //    which loops 32 (0x20) times, initializing an 8-byte CFastArray at offset 0x0C.
    //    This is entirely implicit in C++, so no code needs to be written here for it.

    // 3. Initialize the primitive flags to 0 to ensure clean memory
    m_isInitialized = 0;
}