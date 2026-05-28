#include "CFastAlgo.hpp"
#include "CClassicArchive.hpp"
#include <cstdlib>
#include <cstring>
#include <algorithm> // For std::min

// =================================================
// Function: CFastAlgo::ComputeCrc32
// Reads a buffer in 4096-byte chunks and calculates its CRC32.
// =================================================
uint32_t CFastAlgo::ComputeCrc32(CClassicBuffer* buffer, uint32_t initialCrc) 
{
    // Emulating the virtual calls: GetSize() and ResetPos()
    typedef uint32_t (*GetSizeFunc)(CClassicBuffer*);
    typedef void (*ResetPosFunc)(CClassicBuffer*);
    
    GetSizeFunc getSize = (GetSizeFunc)*((void**)((char*)buffer + 0x18));
    ResetPosFunc resetPos = (ResetPosFunc)*((void**)((char*)buffer + 0x14));
    
    uint32_t remaining = getSize(buffer);
    resetPos(buffer);
    
    uint32_t crc = 0;
    uint8_t stackBuffer[4096]; // 0x1000 bytes
    
    while (remaining != 0) {
        uint32_t toRead = std::min(remaining, (uint32_t)4096);
        
        int readSuccess = buffer->ReadAll(stackBuffer, toRead);
        if (readSuccess == 0) {
            break;
        }
        
        crc = classic_crc32(crc, stackBuffer, toRead);
        remaining -= toRead;
    }
    
    return crc;
}

// =================================================
// Function: CFastAlgo::ComputeHashSize
// Calculates the next optimal prime number for a hash map 
// given a target element count (multiplied by 4/3 to maintain 75% load factor).
// =================================================
uint32_t CFastAlgo::ComputeHashSize(uint32_t elementCount) 
{
    uint32_t targetCapacity = (elementCount * 4) / 3;
    
    if (targetCapacity > 10) {
        // Force the number to be odd before checking for primes
        uint32_t hashSize = targetCapacity | 1; 
        
        while (!IsPrime(hashSize)) {
            hashSize += 2;
        }
        return hashSize;
    }
    
    return 11; // Minimum hash bucket size
}

// =================================================
// Function: CFastAlgo::ComputeHashVal
// Textbook Peter J. Weinberger (PJW) string hash algorithm.
// =================================================
uint32_t CFastAlgo::ComputeHashVal(const char* str, uint32_t* outLength) 
{
    uint32_t hash = 0;
    uint32_t length = 0;
    char c = *str;
    
    while (c != '\0') {
        hash = (hash * 0x10) + static_cast<int>(c);
        length++;
        str++;
        
        uint32_t highBits = hash & 0xF0000000;
        if (highBits != 0) {
            hash ^= (highBits >> 24);
            hash ^= highBits;
        }
        c = *str;
    }
    
    if (outLength != nullptr) {
        *outLength = length;
    }
    
    return hash;
}

// =================================================
// Function: CFastAlgo::ComputeHMAC_MD5_Digest
// Standard HMAC-MD5 implementation.
// =================================================
void CFastAlgo::ComputeHMAC_MD5_Digest(SHMAC_MD5_Data* hmacData) 
{
    uint8_t ipad[64];
    uint8_t opad[64];
    
    std::memset(ipad, 0, 64);
    std::memset(opad, 0, 64);
    
    // Copy the 16-byte key into both pads
    std::memcpy(ipad, hmacData->m_key, 16);
    std::memcpy(opad, hmacData->m_key, 16);
    
    // XOR the pads with HMAC constants
    for (uint32_t i = 0; i < 64; ++i) {
        ipad[i] ^= 0x36;
        opad[i] ^= 0x5C;
    }
    
    classic_md5_ctx ctx;
    
    // Inner MD5 = MD5(ipad || message)
    classic_md5_init(&ctx);
    classic_md5_append(&ctx, ipad, 64);
    classic_md5_append(&ctx, hmacData->m_data, hmacData->m_dataLength);
    
    SNat128 innerDigest;
    classic_md5_finish(&ctx, &innerDigest);
    
    // Outer MD5 = MD5(opad || innerDigest)
    classic_md5_init(&ctx);
    classic_md5_append(&ctx, opad, 64);
    classic_md5_append(&ctx, reinterpret_cast<const uint8_t*>(&innerDigest), 16);
    classic_md5_finish(&ctx, &hmacData->m_digest);
}

// =================================================
// Function: CFastAlgo::ComputeMD5_Digest
// =================================================
void CFastAlgo::ComputeMD5_Digest(const uint8_t* data, uint32_t dataLength, SNat128* outDigest) 
{
    classic_md5_ctx ctx;
    
    classic_md5_init(&ctx);
    classic_md5_append(&ctx, data, dataLength);
    classic_md5_finish(&ctx, outDigest);
}

// =================================================
// Function: CFastAlgo::GetRandomNat32
// Rebuilds a 32-bit random integer from 4 calls to rand().
// =================================================
uint32_t CFastAlgo::GetRandomNat32() 
{
    uint32_t result = 0;
    int iterations = 4;
    
    do {
        int r = std::rand();
        
        // Exact MSVC bitwise extraction to grab a clean 8-bit chunk 
        // from a standard 15-bit (0x7FFF) rand() return value.
        uint32_t byteChunk = static_cast<uint32_t>((r + ((r >> 31) & 0x7F)) >> 7) & 0xFF;
        
        result = (result << 8) | byteChunk;
        iterations--;
        
    } while (iterations != 0);
    
    return result;
}

// =================================================
// Helper Function: CFastAlgo::IsPrime
// Reconstructed missing dependency.
// =================================================
bool CFastAlgo::IsPrime(uint32_t number) 
{
    if (number <= 1) return false;
    if (number <= 3) return true;
    if (number % 2 == 0 || number % 3 == 0) return false;

    for (uint32_t i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}