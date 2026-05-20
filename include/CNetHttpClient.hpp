#ifndef CNETHTTPCLIENT_HPP
#define CNETHTTPCLIENT_HPP

#include "typedefs.h"

struct CNetTransferInfoQueue;

struct CNetHttpClient {
    void** vftable;
    byte _final_padding[0x3]; // Total size: 0x7

    // Member Functions
    EReadFileRes __thiscall InternalReadFile (CNetHttpClient *this,CNetHttpClient *param_1,CNetHttpResult *param_2,char *param_3, ulong param_4);
    int __thiscall ReadFile(CNetHttpClient *this,CNetHttpClient *param_1,CNetHttpResult *param_2);
    void __thiscall InternalTerminateReq (CNetHttpClient *this,CNetHttpClient *param_1,CNetHttpResult *param_2);
    void __thiscall TerminateReq(CNetHttpClient *this,CNetHttpClient *param_1,CNetHttpResult *param_2);
};

#endif // CNETHTTPCLIENT_HPP
