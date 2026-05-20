#ifndef CLASS_CHMSVPACKERLEVEL__HPP
#define CLASS_CHMSVPACKERLEVEL__HPP

#include "typedefs.h"

struct class_CHmsVPackerLevel> {
    void** vftable; // accesses: 9
    float field_0x4; // accesses: 3
    float field_0x8; // accesses: 3
    float field_0xc; // accesses: 3
    float field_0x10; // accesses: 3
    float field_0x14; // accesses: 3
    float field_0x18; // accesses: 2
    byte _padding_0x1c[36];
    float field_0x40; // accesses: 1
    float field_0x44; // accesses: 1
    float field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    byte _padding_0x58[8];
    undefined4 field_0x60; // accesses: 3
    byte _padding_0x64[8];
    undefined4 field_0x6c; // accesses: 5
    undefined4 field_0x70; // accesses: 5

    // Member Functions
    CHmsVPackerCell ** __thiscall SubObject (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *this,CHmsZoneVPacker *param_1,SHmsVPackerObject *param_2);
    float __thiscall Update (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *this,SGmSmoothReal2 *param_1,int param_2,ulong param_3);
    void __thiscall AddObject (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *this,CSceneMobil *param_1,CSceneObject *param_2,CSceneObjectLink **param_3);
    void __thiscall CellDelete (GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *this,GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> *param_1,SUserData *param_2);
};

#endif // CLASS_CHMSVPACKERLEVEL__HPP
