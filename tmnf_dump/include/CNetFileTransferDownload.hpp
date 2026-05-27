#ifndef CNETFILETRANSFERDOWNLOAD_HPP
#define CNETFILETRANSFERDOWNLOAD_HPP

#include "typedefs.h"

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

    void** vftable;
    byte _final_padding[0x15]; // Total size: 0x19

    // Member Functions
    void __thiscall AddDataToWrite (CNetFileTransferDownload *this,CNetFileTransferDownload *param_1,CFastString *param_2);
    void __thiscall GetSizeDone (CNetFileTransferDownload *this,CNetFileTransferDownload *param_1,ulong *param_2, ulong *param_3);
};

#endif // CNETFILETRANSFERDOWNLOAD_HPP
