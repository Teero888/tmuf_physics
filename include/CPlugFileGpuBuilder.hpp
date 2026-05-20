#ifndef CPLUGFILEGPUBUILDER_HPP
#define CPLUGFILEGPUBUILDER_HPP

#include "typedefs.h"

struct CPlugFileGpuBuilder {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 10
    int field_0x8; // accesses: 7
    int field_0xc; // accesses: 4
    undefined * field_0x10; // accesses: 4
    int field_0x14; // accesses: 5
    undefined1 * field_0x18; // accesses: 3
    int field_0x1c; // accesses: 3
    undefined1 * field_0x20; // accesses: 1
    int field_0x24; // accesses: 3
    undefined1 * field_0x28; // accesses: 1
    int field_0x2c; // accesses: 3
    undefined1 * field_0x30; // accesses: 1
    int field_0x34; // accesses: 3
    undefined1 * field_0x38; // accesses: 1
    int field_0x3c; // accesses: 3
    undefined1 * field_0x40; // accesses: 1

    // Member Functions
    CPlugFileGpuBuilder * __thiscall operator<< (CPlugFileGpuBuilder *this,CPlugFileGpuBuilder *param_1,char *param_2);
    void __thiscall AddInOut (CPlugFileGpuBuilder *this,CPlugFileGpuBuilder *param_1,EInOut param_2,EPlugVDcl param_3, char *param_4);
    void __thiscall AddStr (CPlugFileGpuBuilder *this,CPlugFileGpuBuilder *param_1,CFastString *param_2);
    void __thiscall AddVersion (CPlugFileGpuBuilder *this,CPlugFileGpuBuilder *param_1,char *param_2);
    void __thiscall Build (CPlugFileGpuBuilder *this,NvStripInfo *param_1, vector<class_NvEdgeInfo*,class_std::allocator<class_NvEdgeInfo*>_> *param_2, vector<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_> *param_3);
    void __thiscall CPlugFileGpuBuilder(CPlugFileGpuBuilder *this,CPlugFileGpuBuilder *param_1);
    void __thiscall ConvertInOut (CPlugFileGpuBuilder *this,CPlugFileGpuBuilder *param_1,EInOut param_2,EPlugVDcl param_3);
    void __thiscall Reset(CPlugFileGpuBuilder *this,GmFrustumIso4 *param_1);
    void __thiscall ~CPlugFileGpuBuilder(CPlugFileGpuBuilder *this,CPlugFileGpuBuilder *param_1);
};

#endif // CPLUGFILEGPUBUILDER_HPP
