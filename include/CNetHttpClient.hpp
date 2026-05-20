#ifndef CNETHTTPCLIENT_HPP
#define CNETHTTPCLIENT_HPP

#include "typedefs.h"

struct CClassicBufferMemory;
struct CNetTransferInfoQueue;
struct CPlugFileGpuBuilder;
struct TiXmlAttributeSet;

struct CNetHttpClient {
    byte _padding_0x0[24];
    int field_0x18; // accesses: 5
    uint field_0x1c; // accesses: 3
    byte _padding_0x20[48];
    undefined4 field_0x50; // accesses: 4
    undefined4 field_0x54; // accesses: 1
    undefined4 field_0x58; // accesses: 4
    byte _padding_0x5c[12];
    DWORD field_0x68; // accesses: 1
    int field_0x6c; // accesses: 3
    byte _padding_0x70[24];
    code * field_0x88; // accesses: 1
    int field_0x8c; // accesses: 1

    // Member Functions
    EReadFileRes __thiscall InternalReadFile (CNetHttpClient *this,CNetHttpClient *param_1,CNetHttpResult *param_2,char *param_3, ulong param_4);
    int __thiscall ReadFile(CNetHttpClient *this,CNetHttpClient *param_1,CNetHttpResult *param_2);
    void __thiscall InternalTerminateReq (CNetHttpClient *this,CNetHttpClient *param_1,CNetHttpResult *param_2);
    void __thiscall TerminateReq(CNetHttpClient *this,CNetHttpClient *param_1,CNetHttpResult *param_2);
};

#endif // CNETHTTPCLIENT_HPP
