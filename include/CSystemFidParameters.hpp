#ifndef CSYSTEMFIDPARAMETERS_HPP
#define CSYSTEMFIDPARAMETERS_HPP

#include "typedefs.h"

struct ulong;

struct CSystemFidParameters {
    struct SParam {

        // Member Functions
        void __thiscall SParam (SParam *this,SParam *param_1,EParamType param_2,ulong *param_3,int param_4);
        void __thiscall ~SParam(SParam *this,SParam *param_1);
    };

    struct SParam_Fid {

        // Member Functions
        void __thiscall SParam_Fid (SParam_Fid *this,SParam_Fid *param_1,CSystemFid *param_2);
    };

    struct SParam_Fid_Common {

        // Member Functions
        void __thiscall SParam_Fid_Common (SParam_Fid_Common *this,SParam_Fid_Common *param_1,EParamType param_2, CSystemPackDesc *param_3,CFastString *param_4,ulong param_5);
    };

    struct SParam_Fids {

        // Member Functions
        void __thiscall Compare (SParam_Fids *this,SParam_Fids *param_1,SParam *param_2,int *param_3,int *param_4);
        void __thiscall SParam_Fids (SParam_Fids *this,SParam_Fids *param_1,CSystemFids *param_2);
        void __thiscall ~SParam_Fids(SParam_Fids *this,SParam_Fids *param_1);
    };

    struct SParam_Id {

        // Member Functions
        void __thiscall SParam_Id(SParam_Id *this,SParam_Id *param_1);
        void __thiscall ~SParam_Id(SParam_Id *this,SParam_Id *param_1);
    };

    void** vftable; // accesses: 5
    ulong field_0x4; // accesses: 1
    byte _padding_0x8[32];
    undefined4 field_0x28; // accesses: 2
    undefined4 field_0x2c; // accesses: 9

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall GetParamValue (CSystemFidParameters *this,CSystemFidParameters *param_1,SParam *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall Includes (CSystemFidParameters *this,CSystemFidParameters *param_1,CSystemFidParameters *param_2, ulong param_3,int param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall MergeForChildFid (CSystemFidParameters *this,CSystemFidParameters *param_1,CSystemFidParameters *param_2, CSystemFid *param_3,ulong param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CSystemFidParameters (CSystemFidParameters *this,CSystemFidParameters *param_1,CSystemFidParameters *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall DoOneRemap (CSystemFidParameters *this,CSystemFidParameters *param_1,CSystemFid *param_2, CSystemPackDesc **param_3,CFastString *param_4,ulong *param_5, CSystemFidParameters *param_6);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Simplify (CSystemFidParameters *this,CSystemFidParameters *param_1,ulong param_2);
    /* WARNING: Removing unreachable block (ram,0x00429720) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall CSystemFidParameters::AddParam (CSystemFidParameters *this,CSystemFidParameters *param_1,SParam *param_2);
    /* WARNING: Variable defined which should be unmapped: param_2 */ void __cdecl PushForFid(CSystemFid *param_1,ulong param_2);
    CMwId * __thiscall Remap(CSystemFidParameters *this,SIdRemapTable *param_1,CMwId *param_2);
    CSystemFidParameters * __cdecl GetCurrentParameters(void);
    int __cdecl DoesMatch(ulong *param_1,CFastBuffer<unsigned_long> *param_2);
    int __cdecl RemappedLoadFromFid(CMwNod **param_1,CSystemFid *param_2,CMwNod *param_3);
    int __cdecl RemappedLoadFromFid<class_CMwNod> (CMwNodRef<class_CMwNod> *param_1,CSystemFid *param_2,CMwNod *param_3);
    int __thiscall MergeForClassIds (CSystemFidParameters *this,CSystemFidParameters *param_1,CSystemFidParameters *param_2, CFastBuffer<class_CSystemFid*> *param_3);
    void __cdecl PopForFid(CSystemFid *param_1,ulong param_2);
    void __thiscall Pop(CSystemFidParameters *this,SCharStyle *param_1);
    void __thiscall Push (CSystemFidParameters *this,CFastBufferWheel<float> *param_1,float *param_2);
    void __thiscall ~CSystemFidParameters (CSystemFidParameters *this,CSystemFidParameters *param_1);
};

#endif // CSYSTEMFIDPARAMETERS_HPP
