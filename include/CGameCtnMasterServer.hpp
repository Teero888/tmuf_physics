#ifndef CGAMECTNMASTERSERVER_HPP
#define CGAMECTNMASTERSERVER_HPP

#include "typedefs.h"

struct CGameCtnMasterServer {
    struct SMedalsInfo {
        void** vftable;

        // Member Functions
        void __thiscall SMedalsInfo(void *this,SMedalsInfo *param_1);
    };

    void** vftable;
    byte _final_padding[0x2]; // Total size: 0x6

    // Member Functions
    CGameMasterServerRequest * __thiscall StopOfficialRecord (CGameCtnMasterServer *this,CGameCtnMasterServer *param_1,SOfficialRecordState *param_2);
    int __thiscall ReadForcedManialinksParams (CGameCtnMasterServer *this,CGameCtnMasterServer *param_1,TiXmlElement *param_2);
    void __thiscall ReadData (CGameCtnMasterServer *this,CClassicArchive *param_1,void *param_2,ulong param_3);
};

#endif // CGAMECTNMASTERSERVER_HPP
