#ifndef CNETFILETRANSFERFORM_HPP
#define CNETFILETRANSFERFORM_HPP

#include "typedefs.h"

struct CNetFileTransferForm {
    void** vftable;
    byte _padding_0x4[24];
    undefined4 field_0x1c; // accesses: 1
    byte _padding_0x20[104];
    int * field_0x88; // accesses: 2
    byte _final_padding[0x14]; // Total size: 0xa0

    // Member Functions
    void __thiscall GetSize (CNetFileTransferForm *this,CControlGrid *param_1,ulong *param_2,ulong *param_3);
};

#endif // CNETFILETRANSFERFORM_HPP
