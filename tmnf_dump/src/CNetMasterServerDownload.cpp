// Class implementation: CNetMasterServerDownload

// =================================================
// Function: CNetMasterServerDownload::GetDownloadSizeInfos
// =================================================
void __thiscall
CNetMasterServerDownload::GetDownloadSizeInfos
          (CNetMasterServerDownload *this,CNetMasterServerDownload *param_1,ulong *param_2,
          ulong *param_3)
{
{
  int iVar1;
  
  *(undefined4 *)param_1 = *(undefined4 *)(this + 0x38);
  *param_2 = *(ulong *)(this + 0x40);
  iVar1 = *(int *)(this + 0x7c);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x1c) != 0)) &&
     (*(int *)param_1 = *(int *)param_1 + *(int *)(iVar1 + 0x14), *param_2 == 0)) {
    *param_2 = *(ulong *)(*(int *)(this + 0x7c) + 0x1c);
  }
  return;
}
}

