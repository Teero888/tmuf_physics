#ifndef CMWDEPRECATED_HPP
#define CMWDEPRECATED_HPP

class CFuncSegment;
class CClassicArchive;

// =================================================
// CMwDeprecated
// Handles backwards compatibility for deprecated class IDs 
// and skips legacy data chunks in serialized files.
// =================================================
class CMwDeprecated {
public:
    virtual ~CMwDeprecated(); // 0x00 - vftable

    // Member Functions
    static uint32_t WrapClassId(uint32_t classId);
    void Chunk(CFuncSegment* segment, CClassicArchive* archive, uint32_t chunkId);
};

#endif // CMWDEPRECATED_HPP