#ifndef CCLASSICARCHIVE_HPP
#define CCLASSICARCHIVE_HPP

#include "typedefs.h"

struct CClassicBuffer;

struct CClassicArchive {
    byte _padding_0x0[4];
    int * field_0x4; // accesses: 27
    int field_0x8; // accesses: 9
    int field_0xc; // accesses: 14
    byte _padding_0x10[4];
    int field_0x14; // accesses: 3

    // Member Functions
    CClassicBuffer * __thiscall DetachBuffer(CClassicArchive *this,CClassicArchive *param_1,int param_2);
    int __thiscall DoData (CClassicArchive *this,CNetNod_CheckedArchive *param_1,void *param_2,ulong param_3);
    int __thiscall ReadLine(CClassicArchive *this,CClassicArchive *param_1);
    void __thiscall CClassicArchive(CClassicArchive *this,CClassicArchive *param_1);
    void __thiscall DoBool(CClassicArchive *this,CClassicArchive *param_1,int *param_2,ulong param_3);
    void __thiscall DoInteger (CClassicArchive *this,CClassicArchive *param_1,int *param_2,ulong param_3,int param_4);
    void __thiscall DoNat16 (CClassicArchive *this,CClassicArchive *param_1,ushort *param_2,ulong param_3,int param_4);
    void __thiscall DoNat8 (CClassicArchive *this,CClassicArchive *param_1,uchar *param_2,ulong param_3,int param_4);
    void __thiscall DoNatural (CClassicArchive *this,CClassicArchive *param_1,ulong *param_2,ulong param_3,int param_4);
    void __thiscall DoReal(CClassicArchive *this,CClassicArchive *param_1,float *param_2,ulong param_3);
    void __thiscall DoString (CClassicArchive *this,CClassicCrypto_BlowFish *param_1,CFastString *param_2, CFastString *param_3,ECipherOpMode param_4,uint64 *param_5,int param_6);
    void __thiscall MwDoNodRef<class_CMwRefBuffer> (CClassicArchive *this,CClassicArchive *param_1,CMwNodRef<class_CMwRefBuffer> *param_2);
    void __thiscall ReadBool(CClassicArchive *this,CClassicArchive *param_1,int *param_2,ulong param_3);
    void __thiscall ReadData (CClassicArchive *this,CClassicArchive *param_1,void *param_2,ulong param_3);
    void __thiscall ReadInteger (CClassicArchive *this,CClassicArchive *param_1,int *param_2,ulong param_3,int param_4);
    void __thiscall ReadMask (CClassicArchive *this,CClassicArchive *param_1,ulong *param_2,ulong param_3);
    void __thiscall ReadNat16 (CClassicArchive *this,CClassicArchive *param_1,ushort *param_2,ulong param_3,int param_4);
    void __thiscall ReadNat8 (CClassicArchive *this,CClassicArchive *param_1,uchar *param_2,ulong param_3,int param_4);
    void __thiscall ReadNatural (CClassicArchive *this,CClassicArchive *param_1,ulong *param_2,ulong param_3,int param_4);
    void __thiscall ReadReal (CClassicArchive *this,CClassicArchive *param_1,float *param_2,ulong param_3);
    void __thiscall ReadString (CClassicArchive *this,CClassicArchive *param_1,CFastStringInt *param_2,ulong param_3);
    void __thiscall SkipData(CClassicArchive *this,CClassicArchive *param_1,ulong param_2);
    void __thiscall WriteBool (CClassicArchive *this,CClassicArchive *param_1,int *param_2,ulong param_3);
    void __thiscall WriteData (CClassicArchive *this,CClassicArchive *param_1,void *param_2,ulong param_3);
    void __thiscall WriteInteger (CClassicArchive *this,CClassicArchive *param_1,int *param_2,ulong param_3,int param_4);
    void __thiscall WriteLine(CClassicArchive *this,CClassicArchive *param_1);
    void __thiscall WriteMask (CClassicArchive *this,CClassicArchive *param_1,ulong *param_2,ulong param_3);
    void __thiscall WriteNat16 (CClassicArchive *this,CClassicArchive *param_1,ushort *param_2,ulong param_3,int param_4);
    void __thiscall WriteNat8 (CClassicArchive *this,CClassicArchive *param_1,uchar *param_2,ulong param_3,int param_4);
    void __thiscall WriteNatural (CClassicArchive *this,CClassicArchive *param_1,ulong *param_2,ulong param_3,int param_4);
    void __thiscall WriteReal (CClassicArchive *this,CClassicArchive *param_1,float *param_2,ulong param_3);
    void __thiscall WriteString (CClassicArchive *this,CClassicArchive *param_1,CFastStringInt *param_2,ulong param_3);
    void __thiscall ~CClassicArchive(CClassicArchive *this,CClassicArchive *param_1);
};

#endif // CCLASSICARCHIVE_HPP
