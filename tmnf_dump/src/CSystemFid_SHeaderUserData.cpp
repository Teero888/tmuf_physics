// Class implementation: CSystemFid_SHeaderUserData

// =================================================
// Function: CSystemFid::SHeaderUserData::ComputeByteSizeTotalInFile
// =================================================
ulong __thiscall
CSystemFid::SHeaderUserData::ComputeByteSizeTotalInFile(void *this,SHeaderUserData *param_1)
{
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = *(int *)this;
  for (iVar2 = iVar1; iVar2 != 0; iVar2 = iVar2 + -1) {
    this = (void *)((int)this + 8);
    iVar3 = iVar3 + (*(uint *)this & 0x7fffffff);
  }
  return iVar3 + 4 + iVar1 * 8;
}
}

