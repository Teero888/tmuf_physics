// Class implementation: CNetFileTransferDownload

// =================================================
// Function: CNetFileTransferDownload::AddDataToWrite
// =================================================
void __thiscall
CNetFileTransferDownload::AddDataToWrite
          (CNetFileTransferDownload *this,CNetFileTransferDownload *param_1,CFastString *param_2)
{
{
  int iVar1;
  void *this_00;
  CFastString *extraout_EAX;
  TiXmlAttribute *unaff_ESI;
  CNetFileTransferDataToWrite *unaff_EDI;
  
  iVar1 = *(int *)param_1;
  this_00 = operator_new(0x1c);
  if (this_00 == (void *)0x0) {
    param_2 = (CFastString *)0x0;
  }
  else {
    CNetFileTransferDataToWrite::CNetFileTransferDataToWrite(this_00,unaff_EDI);
    param_2 = extraout_EAX;
  }
  *(CNetFileTransferDownload **)(param_2 + 4) = param_1;
  *(undefined4 *)(param_2 + 8) = 1;
  *(int *)(param_2 + 0x10) = iVar1;
  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(this + 0x40);
  *(int *)(this + 0x40) = *(int *)(this + 0x40) + iVar1;
  CFastBuffer<class_CDx9TextureKeeper*>::Add(this + 0x88,(TiXmlAttributeSet *)&param_2,unaff_ESI);
  return;
}
}

// =================================================
// Function: CNetFileTransferDownload::GetSizeDone
// =================================================
void __thiscall
CNetFileTransferDownload::GetSizeDone
          (CNetFileTransferDownload *this,CNetFileTransferDownload *param_1,ulong *param_2,
          ulong *param_3)
{
{
  CNetFileTransferDownload *pCVar1;
  ulong *puVar2;
  int iVar3;
  ulong *unaff_EDI;
  
  puVar2 = param_2;
  pCVar1 = param_1;
  *param_2 = *(ulong *)(this + 0x44);
  *(undefined4 *)param_1 = *(undefined4 *)(this + 0x40);
  if (*(int *)(this + 0x5c) == 0) {
    iVar3 = *(int *)(this + 0x6c);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 0x20) != 0)) {
      iVar3 = (**(code **)(**(int **)(iVar3 + 0x20) + 0x14))();
      *(int *)pCVar1 = *(int *)pCVar1 + iVar3;
    }
  }
  else {
    CNetMasterServerDownload::GetDownloadSizeInfos
              (*(CNetMasterServerDownload **)(*(int *)(this + 0x5c) + 0x18),
               (CNetMasterServerDownload *)&param_1,(ulong *)&param_2,unaff_EDI);
    if (*puVar2 == 0) {
      *puVar2 = (ulong)param_3;
    }
    *(int *)pCVar1 = *(int *)pCVar1 + (int)param_2;
  }
  if (*puVar2 < *(uint *)pCVar1) {
    *(ulong *)pCVar1 = *puVar2;
  }
  return;
}
}

