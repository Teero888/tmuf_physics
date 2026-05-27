// Class implementation: CNetMasterServer

// =================================================
// Function: CNetMasterServer::CancelUpToDateCheck
// =================================================
void __thiscall
CNetMasterServer::CancelUpToDateCheck
          (CNetMasterServer *this,CNetMasterServer *param_1,CNetMasterServerUptoDateCheck *param_2)
{
{
  CNetMasterServer *this_00;
  CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *pCVar1;
  ulong unaff_ESI;
  CNetHttpResult *unaff_EDI;
  CMwNod *unaff_retaddr;
  
  this_00 = param_1;
  if (*(int *)(param_1 + 0x5c) == 0) {
    if (*(int *)(param_1 + 0x58) == 0) {
      *(undefined4 *)(param_1 + 0x5c) = 1;
      *(undefined4 *)(param_1 + 0x48) = 0xfffffffb;
      if ((*(int *)(param_1 + 0x50) != 0) && (*(int *)(param_1 + 0x54) != 0)) {
        (**(code **)(param_1 + 0x54))(param_1);
      }
      pCVar1 = (CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)
               CFastArray<class_CGameMenuFrame*>::Find
                         (this + 0xe0,(CFastArray<class_GxTexCoordSet> *)&param_1,
                          (GxTexCoordSet *)unaff_EDI);
      if (pCVar1 != (CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)0xffffffff) {
        CFastBuffer<class_CTrackManiaEditorIcon*>::RemoveAt(this + 0xe0,pCVar1,1,unaff_ESI);
        CMwNod::MwRelease((CMwNod *)this_00,unaff_retaddr);
        return;
      }
    }
    else {
      CNetHttpResult::Cancel(*(CNetHttpResult **)(param_1 + 0x58),unaff_EDI);
    }
  }
  return;
}
}

// =================================================
// Function: CNetMasterServer::FindRequestInfo
// =================================================
SRequestInfos * __thiscall
CNetMasterServer::FindRequestInfo
          (CNetMasterServer *this,CNetMasterServer *param_1,CFastString *param_2)
{
{
  CNetMasterServer *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  int extraout_EAX;
  int *unaff_EBX;
  int *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  ulong in_stack_fffffff8;
  
  this_00 = this + 0xc0;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CPlugBitmapRenderSolid::SSolid>::operator[]
                         (this_00,pCVar3,unaff_ESI);
      if (*(int *)pSVar2 == *(int *)param_2) {
        unaff_ESI = 0;
        CFastString::Compare
                  (param_2,(SParam_Fids *)&stack0x00000000,(SParam *)0x0,unaff_EBP,unaff_EBX);
        if (extraout_EAX == 0) {
          pSVar2 = CFastBuffer<struct_CPlugBitmapRenderSolid::SSolid>::operator[]
                             (this_00,pCVar3,in_stack_fffffff8);
          return (SRequestInfos *)pSVar2;
        }
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return (SRequestInfos *)0x0;
}
}

// =================================================
// Function: CNetMasterServer::FindValidationData
// =================================================
void __thiscall
CNetMasterServer::FindValidationData
          (CNetMasterServer *this,CNetMasterServer *param_1,CFastString *param_2,
          CFastString *param_3)
{
{
  SRequestInfos *pSVar1;
  int iVar2;
  CFastString *unaff_ESI;
  SStringParam *unaff_EDI;
  SStringParam *in_stack_fffffff8;
  undefined4 local_4;
  
  pSVar1 = FindRequestInfo(this,param_1,unaff_ESI);
  if (pSVar1 != (SRequestInfos *)0x0) {
    local_4 = *(undefined4 *)(pSVar1 + 0x2c);
    CFastString::SetString(param_3,(CFastStringInt *)&local_4,unaff_EDI);
    if ((*(int *)(pSVar1 + 0x30) != 0) &&
       (iVar2 = *(int *)(pSVar1 + 0x30) + -1, *(int *)(pSVar1 + 0x30) = iVar2, iVar2 == 0)) {
      CFastString::SetString
                ((CFastString *)(pSVar1 + 0x28),(CFastStringInt *)&stack0x00000000,in_stack_fffffff8
                );
    }
    return;
  }
  local_4 = DAT_00d71ca0;
  CFastString::SetString(param_3,(CFastStringInt *)&local_4,in_stack_fffffff8);
  return;
}
}

// =================================================
// Function: CNetMasterServer::PauseDownload
// =================================================
void __thiscall
CNetMasterServer::PauseDownload
          (CNetMasterServer *this,CNetMasterServer *param_1,CNetMasterServerDownload *param_2)
{
{
  CNetMasterServer *this_00;
  CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *pCVar1;
  ulong unaff_ESI;
  CGameCtnMediaTracker *unaff_EDI;
  CMwNod *unaff_retaddr;
  
  this_00 = param_1;
  if (*(int *)(param_1 + 0x84) == 0) {
    if (*(int *)(param_1 + 0x7c) == 0) {
      *(uint *)(param_1 + 0x80) = (uint)(*(int *)(param_1 + 0x60) == 0);
      *(undefined4 *)(param_1 + 0x84) = 1;
      if ((*(int *)(param_1 + 0x70) != 0) && (*(int *)(param_1 + 0x74) != 0)) {
        (**(code **)(param_1 + 0x74))(param_1);
      }
      if (*(int *)(this_00 + 0x60) == 0) {
        pCVar1 = (CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)
                 CFastArray<class_CGameMenuFrame*>::Find
                           (this + 0xcc,(CFastArray<class_GxTexCoordSet> *)&param_1,
                            (GxTexCoordSet *)unaff_EDI);
        if (pCVar1 != (CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)0xffffffff) {
          CFastBuffer<class_CTrackManiaEditorIcon*>::RemoveAt(this + 0xcc,pCVar1,1,unaff_ESI);
          CMwNod::MwRelease((CMwNod *)this_00,unaff_retaddr);
          return;
        }
      }
    }
    else {
      CNetHttpResult::Pause(*(CNetHttpResult **)(param_1 + 0x7c),unaff_EDI);
    }
  }
  return;
}
}

// =================================================
// Function: CNetMasterServer::SendMasterServerRequest
// =================================================
CNetMasterServerRequest * __thiscall
CNetMasterServer::SendMasterServerRequest
          (CNetMasterServer *this,CNetMasterServer *param_1,CFastString *param_2,
          SRequestElement *param_3,
          CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>
          *param_4)
{
{
  CNetMasterServerRequest *pCVar1;
  TiXmlAttribute *unaff_ESI;
  SRequestElement *in_stack_00000014;
  CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>
  *in_stack_ffffffe8;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_ffffffec;
  CFastString local_10 [4];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a92898;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (&stack0xffffffe8,
             (CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
  CFastBuffer<class_CDx9TextureKeeper*>::Add
            (&stack0xffffffec,(TiXmlAttributeSet *)&param_3,unaff_ESI);
  pCVar1 = SendMasterServerRequest
                     (this,(CNetMasterServer *)param_3,local_10,in_stack_00000014,in_stack_ffffffe8)
  ;
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(&local_c,in_stack_ffffffec);
  ExceptionList = param_1;
  return pCVar1;
}
}

