#ifndef CNETMASTERSERVERDOWNLOAD_HPP
#define CNETMASTERSERVERDOWNLOAD_HPP

#include "typedefs.h"

struct CNetMasterServerDownload {
    void** vftable;
    byte _padding_0x4[52];
    undefined4 field_0x38; // accesses: 1
    byte _padding_0x3c[4];
    ulong field_0x40; // accesses: 1
    byte _padding_0x44[56];
    int field_0x7c; // accesses: 2

    // Member Functions
    void __thiscall GetDownloadSizeInfos (CNetMasterServerDownload *this,CNetMasterServerDownload *param_1,ulong *param_2, ulong *param_3);
};

#endif // CNETMASTERSERVERDOWNLOAD_HPP
