#ifndef CNETSOURCE_HPP
#define CNETSOURCE_HPP

#include "typedefs.h"

struct CNetFileTransferDownload;

struct CNetSource {
    byte _padding_0x0[20];
    CNetFileTransferDownload * field_0x14; // accesses: 1
    byte _padding_0x18[8];
    undefined4 field_0x20; // accesses: 4

    // Member Functions
    void __thiscall WriteData(CNetSource *this,CClassicArchive *param_1,void *param_2,ulong param_3);
};

#endif // CNETSOURCE_HPP
