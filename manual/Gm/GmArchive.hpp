#ifndef GMARCHIVE_HPP
#define GMARCHIVE_HPP

#include "GmVec3.hpp"
#include "GmQuat.hpp"

class CClassicBuffer;

class GmArchive {
public:
    // Readers
    static void ReadQuat_6(CClassicBuffer* buf, GmQuat* outQuat);
    static void ReadReal_3(CClassicBuffer* buf, float* outVal);
    static void ReadVec3Pos_12(CClassicBuffer* buf, GmVec3* outVec);
    static void ReadVec3Pos_9(CClassicBuffer* buf, GmVec3* outVec);
    static void ReadVec3Unit_4(CClassicBuffer* buf, GmVec3* outVec);
    static void ReadVec3_4(CClassicBuffer* buf, GmVec3* outVec);

    // Writers
    static void WriteQuat_6(CClassicBuffer* buf, const GmQuat* quat);
    static void WriteReal_3(CClassicBuffer* buf, float val);
    static void WriteVec3Pos_12(CClassicBuffer* buf, const GmVec3* vec);
    static void WriteVec3Pos_9(CClassicBuffer* buf, const GmVec3* vec);
    static void WriteVec3Unit_2(CClassicBuffer* buf, const GmVec3* vec);
    static void WriteVec3Unit_4(CClassicBuffer* buf, const GmVec3* vec);
    static void WriteVec3_4(CClassicBuffer* buf, const GmVec3* vec);
};

#endif // GMARCHIVE_HPP