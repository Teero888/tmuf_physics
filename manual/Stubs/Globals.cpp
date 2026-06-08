#include <cmath>
#include <cstdint>
#include "Stubs/CSystemCrashDump.hpp"
#include "Fast/CFastAlgo.hpp"

// Floating point constants
float DAT_00b2c060 = 0.0f;
float CONST_00b2c060 = 0.0f;
float DAT_00c418d0 = 4294967296.0f;
float DAT_00b56ec0 = 1.0f;
float DAT_00b37b60 = 0.0001f;
float CONST_00b36110 = 3.14159265f;
float CONST_00b52a58 = 1.57079633f;
float CONST_00b2c178 = 0.00001f;
float CONST_00b530f8 = 32768.0f;
float CONST_00bbdbe4 = 1.0f / 3.14159265f;
float CONST_00b55d40 = 0.0f; 
float CONST_00bbdc00 = 0.0f; 
float CONST_00c418d8 = 0.0f; 
float CONST_00b9cfa4 = 0.0f; 
float CONST_00b9cfa8 = 0.0f; 
float DAT_00b56ec0_val = 1.0f;
void* DAT_00b56ec0_ptr = &DAT_00b56ec0_val;
float DAT_00b56ec0_v = 1.0f;
float DAT_00b56ec0_x = 1.0f;
float DAT_00b56ec0_y = 1.0f;
float DAT_00b56ec0_z = 1.0f;
float DAT_00b56ec0_w = 1.0f;
float DAT_00b56ec0_scalar = 1.0f;

// Global Objects/Pointers
CSystemCrashDump DAT_00d5546c; 
void* DAT_00d731e0 = nullptr; 
void* DAT_00d67560 = nullptr;
void* DAT_00d67564 = nullptr;
void* DAT_00d6764c = nullptr;
void* DAT_00d6770c = nullptr;
void* DAT_00d739e0 = nullptr;
void* DAT_00d739e4 = nullptr;
void* DAT_00d739e8 = nullptr;
void* DAT_00d7333c = nullptr;
void* DAT_00d73344 = nullptr;
void* DAT_00d73ba8 = nullptr;
void* DAT_00d73388 = nullptr;
void* DAT_00d7338c = nullptr;
void* DAT_00d73380 = nullptr;
void* DAT_00d7337C = nullptr;
void* DAT_00d73390 = nullptr;
void* DAT_00d73378 = nullptr;
void* DAT_00d733d0 = nullptr;
void* DAT_00d71c9c = nullptr;
void* PTR_DAT_00bc6508 = nullptr;
void* PTR_DAT_00bc651c = nullptr;
void* PTR_DAT_00bc6598 = nullptr;
void* DAT_00d357f0 = nullptr;
void* PTR_DAT_00bbf7d8 = nullptr;
void* DAT_00d35d04 = nullptr;
void* g_FirstClassInfo = nullptr;
int g_LastFlushTime = 0;
int g_FlushTimeout = 0;
int g_LogDisabled = 0;
void* g_OutStream1 = nullptr;
void* g_OutStream2 = nullptr;
void* g_OutStream3 = nullptr;
const char* g_LogCStr = "";
void* g_GlobalLog = nullptr;

// Functions
float MathUtility_9c1b40() { return 0.0f; }
void OnAccessViolation_ConcatToCrashFileName(void* p) {}
void Zone_UpdateWaterHeights(void* p) {}
struct STri_PosTexTgt;
void ComputeTriangleTangentUV_Rotated(STri_PosTexTgt* p, unsigned int i) {}
class CFastString;
void CSystemFileName_ConvertToSystemName_AndCreate(CFastString* p1, CFastString* p2) {}

extern "C" {
    uint32_t classic_crc32(uint32_t crc, const uint8_t* buf, uint32_t len) { return 0; }
    void classic_md5_init(classic_md5_ctx* ctx) {}
    void classic_md5_append(classic_md5_ctx* ctx, const uint8_t* data, uint32_t length) {}
    void classic_md5_finish(classic_md5_ctx* ctx, SNat128* digest) {}
}
