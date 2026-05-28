#ifndef CFASTALGO_HPP
#define CFASTALGO_HPP

#include <cstdint>

// Forward Declarations
class CClassicBuffer;

// Standard 128-bit structure used for MD5 hashes
struct SNat128 {
    uint32_t data[4];
};

// Reconstructed HMAC-MD5 Data structure based on memory offsets
struct SHMAC_MD5_Data {
    const uint8_t* m_data;       // 0x00 - Payload to hash
    uint32_t m_dataLength;       // 0x04 - Payload length
    // ... padding/other fields ...
    uint8_t m_key[16];           // 0x18 - 16-byte HMAC Key
    SNat128 m_digest;            // 0x28 - Output hash
};

// =================================================
// CFastAlgo
// Global static utility class for hashing, cryptography, 
// and math algorithms.
// =================================================
class CFastAlgo {
public:
    // Hashing & Integrity
    static uint32_t ComputeCrc32(CClassicBuffer* buffer, uint32_t initialCrc);
    static uint32_t ComputeHashSize(uint32_t elementCount);
    static uint32_t ComputeHashVal(const char* str, uint32_t* outLength);
    
    // Cryptography
    static void ComputeHMAC_MD5_Digest(SHMAC_MD5_Data* hmacData);
    static void ComputeMD5_Digest(const uint8_t* data, uint32_t dataLength, SNat128* outDigest);
    
    // RNG
    static uint32_t GetRandomNat32();

private:
    // Internal Helpers
    static bool IsPrime(uint32_t number);
};

// External cryptographic functions linked by the engine
struct classic_md5_ctx {
    uint32_t state[4];
    uint32_t count[2];
    uint8_t buffer[64];
};

extern "C" {
    void classic_md5_init(classic_md5_ctx* ctx);
    void classic_md5_append(classic_md5_ctx* ctx, const uint8_t* data, uint32_t length);
    void classic_md5_finish(classic_md5_ctx* ctx, SNat128* digest);
    uint32_t classic_crc32(uint32_t crc, const uint8_t* buf, uint32_t len);
}

#endif // CFASTALGO_HPP