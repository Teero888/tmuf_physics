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
    static unsigned long WrapClassId(unsigned long classId);
    void Chunk(CFuncSegment* segment, CClassicArchive* archive, unsigned long chunkId);
};

#endif // CMWDEPRECATED_HPP