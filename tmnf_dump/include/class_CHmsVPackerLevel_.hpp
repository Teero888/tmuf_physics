#ifndef CLASS_CHMSVPACKERLEVEL__HPP
#define CLASS_CHMSVPACKERLEVEL__HPP

#include "typedefs.h"

struct class_CHmsVPackerLevel> {
    int field_0x0; // accesses: 1
    byte _padding_0x4[104];
    int field_0x6c; // accesses: 4
    int field_0x70; // accesses: 4

    // Member Functions
    CHmsVPackerCell ** __thiscall SubObject (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *this,CHmsZoneVPacker *param_1,SHmsVPackerObject *param_2);
    float __thiscall Update (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *this,SGmSmoothReal2 *param_1,int param_2,ulong param_3);
    void __thiscall AddObject (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *this,CSceneMobil *param_1,CSceneObject *param_2,CSceneObjectLink **param_3);
    void __thiscall CellDelete (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *this,GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *param_1,SUserData *param_2);
};

#endif // CLASS_CHMSVPACKERLEVEL__HPP
