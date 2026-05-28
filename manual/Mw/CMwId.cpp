#include "CMwId.hpp"
#include "CFastBuffer.hpp"
#include "CFastAlgo.hpp"
#include "CFastArray.hpp"

// =================================================
// Global Engine Dictionary Structures
// =================================================

extern void* DAT_00d739e0; // Pointer to the global SMwIdInternal dictionary instance
extern CMwId DAT_00d739e4; // Global default/empty CMwId
extern void (*DAT_00d72e88)(void); // Archive deletion callback

// External initialization callbacks
extern uint32_t* DAT_00d739e8;

// Local static UTF8 conversion buffer
extern uint32_t DAT_00d739f4;
extern CFastString DAT_00d739ec;

// =================================================
// Initialization
// =================================================
void CMwId::StaticInit() {
    // 1. Allocate the global String Dictionary (0x110 = 272 bytes)
    DAT_00d739e0 = new char[0x110]; // Cast to SMwIdInternal internally
    
    // 2. Pre-allocate buffer sizes based on typical game requirements
    // 0x249F0 = ~150,000 potential string registrations
    // CFastBuffer<unsigned_char>::SetSizeAtLeast(...) equivalent:
    
    uint32_t hashSize = CFastAlgo::ComputeHashSize(0x1D4C); // 7500
    
    // 3. Initialize Array bounds
    void* arrayTarget = (char*)DAT_00d739e0 + 0x0C;
    // CFastArray initialization logic...
    
    *(uint32_t*)((char*)DAT_00d739e0 + 0x10C) = 1; // Set initialized flag
    
    // 4. Create the global empty ID
    DAT_00d739e4 = CMwId(0);
    
    // 5. Run registered initialization callbacks (Iterating through function pointers)
    for (uint32_t* cb = DAT_00d739e8; cb != nullptr; cb = (uint32_t*)cb[1]) {
        typedef void (*InitCallback)();
        InitCallback func = (InitCallback)*cb;
        func();
    }
}

// =================================================
// Factories
// =================================================
CMwId CMwId::CreateFromLocalIndex(uint32_t index) {
    return CMwId(index);
}

CMwId CMwId::CreateFromLocalName(const char* name) {
    CMwId newId(0xFFFFFFFF);
    newId.SetLocalName(name);
    return newId;
}

// =================================================
// Resolving and Fetching Strings
// =================================================
const char* CMwId::GetString() const {
    // Ensure the dictionary is initialized
    if (DAT_00d739e0 == nullptr) return nullptr;

    // The top 2 bits (0xC0000000) define the ID category.
    // 0x40000000 and 0x80000000 are the flags for indexed string pool entries.
    if ((m_id & 0xC0000000) != 0x40000000 && (m_id & 0xC0000000) != 0x80000000) {
        return nullptr;
    }

    // Unpack the ID:
    // Bits 16-29: Page/Bucket Index
    // Bits 0-15: Element Index inside the Bucket
    uint32_t bucketIndex = (m_id & 0x3FFFFFFF) >> 16;
    uint32_t elementIndex = m_id & 0xFFFF;

    // Reconstructing the dense pointer math from Ghidra:
    // This accesses the CFastBuffer pages inside the SMwIdInternal struct
    void** pageArray = *(void***)((char*)DAT_00d739e0 + 0x0C + (bucketIndex * 8));
    
    if (pageArray != nullptr) {
        // Retrieve the actual C-string pointer from the element index
        return (const char*)pageArray[elementIndex];
    }
    
    return nullptr;
}

CFastString CMwId::GetName() const {
    const char* rawString = GetString();
    CFastString result;
    
    if (rawString != nullptr) {
        // String was successfully retrieved from the dictionary
        result.SetString(rawString);
    } else {
        // Fallback or unassigned ID
        result.SetString("Unassigned");
    }
    
    return result;
}

// TODO:
void CMwId::SetLocalName(const char* name) {
    // In Nadeo's engine, this function hashes the string, checks the 
    // global SMwIdInternal dictionary (DAT_00d739e0), inserts it if it 
    // doesn't exist, and then assigns the packed bits back to `m_id`.
    
    // The decompilation showed UTF8 conversion wrappers before routing 
    // into the internal dictionary adder.
    
    // Abstracted:
    // m_id = Internal_HashAndInsert(name);
}