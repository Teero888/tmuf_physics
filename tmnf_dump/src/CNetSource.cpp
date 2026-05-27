// Class implementation: CNetSource

// =================================================
// Function: CNetSource::WriteData
// =================================================
void __thiscall
CNetSource::WriteData(CNetSource *this,CClassicArchive *param_1,void *param_2,ulong param_3)
{
{
  int iVar1;
  CFastString *unaff_ESI;
  
  if (*(int **)(this + 0x20) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(this + 0x20) + 0x14))();
    if (iVar1 != 0) {
      CNetFileTransferDownload::AddDataToWrite
                (*(CNetFileTransferDownload **)(this + 0x14),
                 *(CNetFileTransferDownload **)(this + 0x20),unaff_ESI);
      *(undefined4 *)(this + 0x20) = 0;
    }
  }
  return;
}
}

