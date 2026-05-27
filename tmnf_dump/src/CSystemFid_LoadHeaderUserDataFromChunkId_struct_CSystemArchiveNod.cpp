// Class implementation: CSystemFid_LoadHeaderUserDataFromChunkId_struct_CSystemArchiveNod

// =================================================
// Function: CSystemFid::LoadHeaderUserDataFromChunkId<struct_CSystemArchiveNod::SHeaderFolderDep>
// =================================================
int __thiscall
CSystemFid::LoadHeaderUserDataFromChunkId<struct_CSystemArchiveNod::SHeaderFolderDep>
          (CSystemFid *this,CSystemFid *param_1,SHeaderFolderDep *param_2,ulong param_3,int param_4)
{
{
  CClassicArchive *pCVar1;
  int unaff_ESI;
  CClassicArchive *unaff_retaddr;
  
  pCVar1 = LoadHeaderUserDataFromChunkId_Begin(this,(CSystemFid *)param_2,param_3,unaff_ESI);
  if (pCVar1 == (CClassicArchive *)0x0) {
    return 0;
  }
  CSystemArchiveNod::SHeaderFolderDep::Archive
            (param_2,(CFastCrypt<unsigned_long> *)pCVar1,unaff_retaddr);
  LoadHeaderUserDataFromChunkId_End(this,(CSystemFid *)&stack0x00000014,(CClassicArchive **)param_1)
  ;
  return 1;
}
}

