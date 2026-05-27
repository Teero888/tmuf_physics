#ifndef CNETSOURCE_HPP
#define CNETSOURCE_HPP

#include "typedefs.h"

struct CNetFileTransferDownload;

struct CNetSource {
    void** vftable;
    byte _padding_0x4[16];
    CNetFileTransferDownload * field_0x14; // accesses: 1
    byte _padding_0x18[8];
    int * field_0x20; // accesses: 4
    byte _final_padding[0x48]; // Total size: 0x6c

    // Member Functions
    void __thiscall WriteData(CNetSource *this,CClassicArchive *param_1,void *param_2,ulong param_3);
};

#endif // CNETSOURCE_HPP
