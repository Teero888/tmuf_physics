#ifndef CSYSTEMENGINE_HPP
#define CSYSTEMENGINE_HPP

#include "typedefs.h"

struct CSystemFids;
struct CSystemFidsDrive;
struct CSystemManagerFile;

struct CSystemEngine {
    void** vftable; // accesses: 1
    byte _padding_0x4[28];
    CSystemManagerFile * field_0x20; // accesses: 3
    int * field_0x24; // accesses: 6
    CSystemFids * field_0x28; // accesses: 6
    int * field_0x2c; // accesses: 5
    int * field_0x30; // accesses: 5
    undefined4 field_0x34; // accesses: 1
    byte _padding_0x38[20];
    CSystemFids * field_0x4c; // accesses: 3
    CSystemFids * field_0x50; // accesses: 5
    CSystemEngine * field_0x54; // accesses: 1
    byte _padding_0x58[4];
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined * field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1

    // Member Functions
    /* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */ ulong __cdecl GetExeCheckSum(void);
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl CaptureInfoOsCpu(void);
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ /* WARNING: Removing unreachable block (ram,0x00431e44) */ /* WARNING: Removing unreachable block (ram,0x00431e26) */ ECpuExt __cdecl CSystemEngine::GetCpuExtHardware(void);
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ void __cdecl GetCurrentDir(CFastStringInt *param_1);
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ void __cdecl GetExeDir(CFastStringInt *param_1);
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ void __cdecl GetMyDocumentsDir(CFastStringInt *param_1);
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ void __cdecl GetSharedAppDir(CFastStringInt *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __cdecl LoadGraphicPerformance(void);
    /* WARNING: Removing unreachable block (ram,0x0041ec2f) */ void __cdecl CSystemEngine::GetLogRootPath (CFastString *param_1,CFastStringInt *param_2,CFastStringInt *param_3, CFastStringInt *param_4);
    CClassicBuffer * __thiscall DetachBuffer(CSystemEngine *this,CClassicArchive *param_1,int param_2);
    CMwNod * __thiscall GetResourceFromId(CSystemEngine *this,CSystemEngine *param_1,ulong param_2);
    CSystemFid * __thiscall FindFid (CSystemEngine *this,CSystemFids *param_1,CFastStringInt *param_2,int param_3, EFindWay param_4);
    CSystemFid * __thiscall FindFidFromBaseNameAndClassId (CSystemEngine *this,CSystemFids *param_1,CFastStringInt *param_2,ulong param_3);
    CSystemFid * __thiscall FindFidResource(CSystemEngine *this,CSystemEngine *param_1,CSystemFidFile *param_2);
    CSystemFidFile * __thiscall FindFidFile(CSystemEngine *this,CSystemEngine *param_1,CSystemFidFile *param_2);
    CSystemFidFile * __thiscall FindOrAddFidAt (CSystemEngine *this,CSystemEngine *param_1,CSystemFids *param_2,CFastStringInt *param_3, int *param_4);
    CSystemFidFile * __thiscall GetConfigFile (CSystemEngine *this,CSystemEngine *param_1,CFastStringInt *param_2,EMode param_3, int param_4);
    CSystemFidFile * __thiscall GetFidFromResource(CSystemEngine *this,CSystemEngine *param_1,ulong param_2);
    CSystemFids * __thiscall GetLocationBuffer(CSystemEngine *this,CSystemEngine *param_1);
    CSystemFids * __thiscall GetLocationData(CSystemEngine *this,CSystemEngine *param_1);
    CSystemFids * __thiscall GetLocationShared(CSystemEngine *this,CSystemEngine *param_1);
    CSystemFids * __thiscall GetLocationUser(CSystemEngine *this,CSystemEngine *param_1);
    char * __thiscall I18nGetSystemLanguage(CSystemEngine *this,CSystemEngine *param_1);
    int __cdecl FileIniSetFullName(CFastStringInt *param_1);
    int __thiscall FindDriveAndRelName (CSystemEngine *this,CSystemEngine *param_1,CFastStringInt *param_2, CSystemFidsDrive **param_3,CFastStringInt *param_4);
    int __thiscall I18nLoadMessageCatalog (CSystemEngine *this,CSystemEngine *param_1,CSystemFid *param_2,char *param_3);
    int __thiscall I18nSetLanguage(CSystemEngine *this,CSystemEngine *param_1,char *param_2);
    int __thiscall LoadSystemConfigAndBindToFid (CSystemEngine *this,CSystemEngine *param_1,CFastStringInt *param_2,int param_3, CMwNodRef<class_CSystemConfig> *param_4);
    void __cdecl FileIniRead(CFastString *param_1,CFastString *param_2,CFastString *param_3);
    void __cdecl FileIniSetSection(CFastString *param_1);
    void __cdecl GetRunDir(CFastStringInt *param_1);
    void __cdecl LogSystemInfos(void);
    void __cdecl RegistrySetApplicationPath(char *param_1);
    void __thiscall AddFidNod (CSystemEngine *this,CSystemEngine *param_1,CMwNod *param_2,CSystemFid *param_3, CSystemFidParameters *param_4);
    void __thiscall ApplySystemConfig (CSystemEngine *this,CVisionViewportDx9 *param_1,CSystemConfig *param_2,int param_3);
    void __thiscall BindFidNod (CSystemEngine *this,CSystemEngine *param_1,CMwNod *param_2,CSystemFid *param_3);
    void __thiscall CSystemEngine(CSystemEngine *this,CSystemEngine *param_1);
    void __thiscall InitForGbxGame (CSystemEngine *this,CSystemEngine *param_1,ulong param_2,CFastString *param_3, CFastString *param_4,CFastStringInt *param_5,CFastStringInt *param_6);
    void __thiscall LoadResourceTable(CSystemEngine *this,CSystemEngine *param_1);
    void __thiscall RemoveAndDeleteFid(CSystemEngine *this,CSystemEngine *param_1,CSystemFid *param_2);
    void __thiscall RemoveFid(CSystemEngine *this,CSystemEngine *param_1,CSystemFid *param_2);
    void __thiscall SetDrives (CSystemEngine *this,CSystemEngine *param_1,CFastStringInt *param_2, CFastStringInt *param_3,CFastStringInt *param_4,CFastStringInt *param_5);
    void __thiscall SetLocationDataShortName (CSystemEngine *this,CSystemEngine *param_1,CFastStringInt *param_2);
    void __thiscall Sleep(CSystemEngine *this,CMwCmdBlock *param_1,ulong param_2);
    void __thiscall UnbindFid(CSystemEngine *this,CSystemEngine *param_1,CMwNod *param_2);
    void __thiscall UnbindFidNod (CSystemEngine *this,CSystemEngine *param_1,CMwNod *param_2,CSystemFid *param_3);
};

#endif // CSYSTEMENGINE_HPP
