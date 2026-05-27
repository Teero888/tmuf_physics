#ifndef CSYSTEMFIDPARAMETERS_HPP
#define CSYSTEMFIDPARAMETERS_HPP

#include "typedefs.h"

struct CSystemFidParameters {
    struct SParam {
        void** vftable; // accesses: 2
        SParam * field_0x4; // accesses: 1
        EParamType field_0x8; // accesses: 1
        ulong * field_0xc; // accesses: 1

        // Member Functions
        void __thiscall SParam (SParam *this,SParam *param_1,EParamType param_2,ulong *param_3,int param_4);
        void __thiscall ~SParam(SParam *this,SParam *param_1);
    };

    struct CSystemFid;

    struct SParam_Fid {
        void** vftable; // accesses: 1
        byte _padding_0x4[32];
        CSystemFid * field_0x24; // accesses: 1

        // Member Functions
        void __thiscall SParam_Fid (SParam_Fid *this,SParam_Fid *param_1,CSystemFid *param_2);
    };

    struct CSystemPackDesc;

    struct SParam_Fid_Common {
        void** vftable; // accesses: 1
        byte _padding_0x4[12];
        ulong field_0x10; // accesses: 1
        CSystemPackDesc * field_0x14; // accesses: 1
        byte _padding_0x18[8];
        undefined4 field_0x20; // accesses: 1

        // Member Functions
        void __thiscall SParam_Fid_Common (SParam_Fid_Common *this,SParam_Fid_Common *param_1,EParamType param_2, CSystemPackDesc *param_3,CFastString *param_4,ulong param_5);
    };

    struct CSystemFids;

    struct SParam_Fids {
        void** vftable; // accesses: 1
        int field_0x4; // accesses: 1
        byte _padding_0x8[8];
        int field_0x10; // accesses: 1
        int field_0x14; // accesses: 1
        int * field_0x18; // accesses: 2
        undefined * field_0x1c; // accesses: 2
        byte _padding_0x20[4];
        CSystemFids * field_0x24; // accesses: 2

        // Member Functions
        void __thiscall Compare (SParam_Fids *this,SParam_Fids *param_1,SParam *param_2,int *param_3,int *param_4);
        void __thiscall SParam_Fids (SParam_Fids *this,SParam_Fids *param_1,CSystemFids *param_2);
        void __thiscall ~SParam_Fids(SParam_Fids *this,SParam_Fids *param_1);
    };

    struct SParam_Id {
        void** vftable; // accesses: 1
        byte _padding_0x4[16];
        EParamType field_0x14; // accesses: 1

        // Member Functions
        void __thiscall SParam_Id(SParam_Id *this,SParam_Id *param_1);
        void __thiscall ~SParam_Id(SParam_Id *this,SParam_Id *param_1);
    };

    void** vftable; // accesses: 2
    byte _padding_0x4[36];
    undefined4 field_0x28; // accesses: 2
    int field_0x2c; // accesses: 6

    // Member Functions
    CMwId * __thiscall Remap(CSystemFidParameters *this,SIdRemapTable *param_1,CMwId *param_2);
    CSystemFidParameters * __cdecl GetCurrentParameters(void);
    int __cdecl DoesMatch(ulong *param_1,CFastBuffer<unsigned_long> *param_2);
    int __cdecl RemappedLoadFromFid(CMwNod **param_1,CSystemFid *param_2,CMwNod *param_3);
    int __cdecl RemappedLoadFromFid<class_CMwNod> (CMwNodRef<class_CMwNod> *param_1,CSystemFid *param_2,CMwNod *param_3);
    int __thiscall AddParam (CSystemFidParameters *this,CSystemFidParameters *param_1,SParam *param_2);
    int __thiscall GetParamValue (CSystemFidParameters *this,CSystemFidParameters *param_1,SParam *param_2);
    int __thiscall Includes (CSystemFidParameters *this,CSystemFidParameters *param_1,CSystemFidParameters *param_2, ulong param_3,int param_4);
    int __thiscall MergeForChildFid (CSystemFidParameters *this,CSystemFidParameters *param_1,CSystemFidParameters *param_2, CSystemFid *param_3,ulong param_4);
    int __thiscall MergeForClassIds (CSystemFidParameters *this,CSystemFidParameters *param_1,CSystemFidParameters *param_2, CFastBuffer<class_CSystemFid*> *param_3);
    void __cdecl PopForFid(CSystemFid *param_1,ulong param_2);
    void __cdecl PushForFid(CSystemFid *param_1,ulong param_2);
    void __thiscall CSystemFidParameters (CSystemFidParameters *this,CSystemFidParameters *param_1,CSystemFidParameters *param_2);
    void __thiscall DoOneRemap (CSystemFidParameters *this,CSystemFidParameters *param_1,CSystemFid *param_2, CSystemPackDesc **param_3,CFastString *param_4,ulong *param_5, CSystemFidParameters *param_6);
    void __thiscall Pop(CSystemFidParameters *this,SCharStyle *param_1);
    void __thiscall Push (CSystemFidParameters *this,CFastBufferWheel<float> *param_1,float *param_2);
    void __thiscall Simplify (CSystemFidParameters *this,CSystemFidParameters *param_1,ulong param_2);
    void __thiscall ~CSystemFidParameters (CSystemFidParameters *this,CSystemFidParameters *param_1);
};

#endif // CSYSTEMFIDPARAMETERS_HPP
