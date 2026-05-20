// Class implementation: CPlugFileSnd

// =================================================
// Function: CPlugFileSnd::GetLength
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall CPlugFileSnd::GetLength(CPlugFileSnd *this,CPlugFileSnd *param_1)
{
{
  int iVar1;
  float fVar2;
  float fVar3;
  ulong uVar4;
  CPlugFileSnd *unaff_ESI;
  
  iVar1 = *(int *)(this + 0x18);
  if (iVar1 == 0) {
    return 0.0;
  }
  uVar4 = GetNbBlocks(this,unaff_ESI);
  fVar2 = (float)(int)uVar4;
  if ((int)uVar4 < 0) {
    fVar2 = fVar2 + _DAT_00c418d0;
  }
  fVar3 = (float)iVar1;
  if (iVar1 < 0) {
    fVar3 = fVar3 + _DAT_00c418d0;
  }
  return fVar2 / fVar3;
}
}

// =================================================
// Function: CPlugFileSnd::GetNbBlocks
// =================================================
ulong __thiscall CPlugFileSnd::GetNbBlocks(CPlugFileSnd *this,CPlugFileSnd *param_1)
{
{
  if (((*(uint *)(this + 0x24) != 0xffffffff) && (*(ushort *)(this + 0x20) != 0)) &&
     (*(short *)(this + 0x14) != 0)) {
    return *(uint *)(this + 0x24) / (uint)*(ushort *)(this + 0x20);
  }
  return 0;
}
}

