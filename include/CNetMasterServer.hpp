#ifndef CNETMASTERSERVER_HPP
#define CNETMASTERSERVER_HPP

#include "typedefs.h"

struct CNetHttpResult;

struct CNetMasterServer {
    byte _padding_0x0[72];
    undefined4 field_0x48; // accesses: 1
    byte _padding_0x4c[4];
    int field_0x50; // accesses: 1
    int field_0x54; // accesses: 2
    int field_0x58; // accesses: 2
    undefined4 field_0x5c; // accesses: 2
    int field_0x60; // accesses: 1
    byte _padding_0x64[12];
    int field_0x70; // accesses: 1
    int field_0x74; // accesses: 2
    byte _padding_0x78[4];
    int field_0x7c; // accesses: 2
    uint field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 2

    // Member Functions
    CNetMasterServerRequest * __thiscall SendMasterServerRequest (CNetMasterServer *this,CNetMasterServer *param_1,CFastString *param_2, SRequestElement *param_3, CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*> *param_4);
    SRequestInfos * __thiscall FindRequestInfo (CNetMasterServer *this,CNetMasterServer *param_1,CFastString *param_2);
    void __thiscall CancelUpToDateCheck (CNetMasterServer *this,CNetMasterServer *param_1,CNetMasterServerUptoDateCheck *param_2);
    void __thiscall FindValidationData (CNetMasterServer *this,CNetMasterServer *param_1,CFastString *param_2, CFastString *param_3);
    void __thiscall PauseDownload (CNetMasterServer *this,CNetMasterServer *param_1,CNetMasterServerDownload *param_2);
};

#endif // CNETMASTERSERVER_HPP
