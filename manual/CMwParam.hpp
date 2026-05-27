#ifndef CMWPARAM_HPP
#define CMWPARAM_HPP

// =================================================
// CMwParam
// Base class for reflection parameter metadata.
// Size: 20 bytes (0x14)
// =================================================
class CMwParam {
public:
    virtual ~CMwParam(); // 0x00 - vftable
    
    // Internal metadata fields (padded to match 0x14 size)
    unsigned long m_flags;   // 0x04
    unsigned long m_typeId;  // 0x08
    unsigned long m_offset;  // 0x0C
    unsigned long m_size;    // 0x10

    // Member Functions
    int IsIndexed(); // Stripped the hallucinated param_1
};

#endif // CMWPARAM_HPP