#ifndef CNETMASTERSERVER_HPP
#define CNETMASTERSERVER_HPP

#include "typedefs.h"

struct CNetMasterServer {
    void** vftable;
    byte _final_padding[0x6]; // Total size: 0xa

    // Member Functions
    CNetMasterServerRequest * __thiscall SendMasterServerRequest (CNetMasterServer *this,CNetMasterServer *param_1,CFastString *param_2, SRequestElement *param_3, CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*> *param_4);
    SRequestInfos * __thiscall FindRequestInfo (CNetMasterServer *this,CNetMasterServer *param_1,CFastString *param_2);
    void __thiscall CancelUpToDateCheck (CNetMasterServer *this,CNetMasterServer *param_1,CNetMasterServerUptoDateCheck *param_2);
    void __thiscall FindValidationData (CNetMasterServer *this,CNetMasterServer *param_1,CFastString *param_2, CFastString *param_3);
    void __thiscall PauseDownload (CNetMasterServer *this,CNetMasterServer *param_1,CNetMasterServerDownload *param_2);
};

#endif // CNETMASTERSERVER_HPP
