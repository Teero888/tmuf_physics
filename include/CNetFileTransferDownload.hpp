#ifndef CNETFILETRANSFERDOWNLOAD_HPP
#define CNETFILETRANSFERDOWNLOAD_HPP

#include "typedefs.h"

struct ulong;

struct CNetFileTransferDownload {
    struct CNetFileTransferDataToWrite {
        void** vftable; // accesses: 1
        undefined4 field_0x4; // accesses: 1
        undefined4 field_0x8; // accesses: 1
        undefined4 field_0xc; // accesses: 1
        undefined4 field_0x10; // accesses: 1
        undefined4 field_0x14; // accesses: 1
        undefined4 field_0x18; // accesses: 1

        // Member Functions
        void __thiscall CNetFileTransferDataToWrite (void *this,CNetFileTransferDataToWrite *param_1);
    };

    void** vftable; // accesses: 2
    byte _padding_0x4[60];
    undefined4 field_0x40; // accesses: 4
    ulong field_0x44; // accesses: 1
    byte _padding_0x48[20];
    int field_0x5c; // accesses: 2
    byte _padding_0x60[12];
    int field_0x6c; // accesses: 1

    // Member Functions
    void __thiscall AddDataToWrite (CNetFileTransferDownload *this,CNetFileTransferDownload *param_1,CFastString *param_2);
    void __thiscall GetSizeDone (CNetFileTransferDownload *this,CNetFileTransferDownload *param_1,ulong *param_2, ulong *param_3);
};

#endif // CNETFILETRANSFERDOWNLOAD_HPP
