#ifndef CNETARCHIVE_HPP
#define CNETARCHIVE_HPP

#include "typedefs.h"

struct CNetArchive {
    byte _padding_0x0[8];
    undefined4 field_0x8; // accesses: 2
    undefined4 field_0xc; // accesses: 1

    // Member Functions
    SStreamContext * __thiscall StartReading(CNetArchive *this,CPlugFileOggVorbis *param_1);
    void __thiscall CNetArchive(CNetArchive *this,CNetArchive *param_1);
    void __thiscall EndReading(CNetArchive *this,CPlugFileOggVorbis *param_1,SStreamContext **param_2);
    void __thiscall StartStoring (CNetArchive *this,CNetArchive *param_1,CClassicBufferMemory *param_2,int param_3);
};

#endif // CNETARCHIVE_HPP
