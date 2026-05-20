// Class implementation: CGameCtnBench

// =================================================
// Function: CGameCtnBench::Start
// =================================================
void __thiscall CGameCtnBench::Start(CGameCtnBench *this,CGameCtnBench *param_1)
{
{
  GmFrustumIso4 *unaff_ESI;
  
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this + 0x28,unaff_ESI);
  (**(code **)(**(int **)(this + 0x24) + 0x7c))();
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  return;
}
}

// =================================================
// Function: CGameCtnBench::UpdateAsync
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CGameCtnBench::UpdateAsync(CGameCtnBench *this,CInputPortDx8 *param_1)
{
{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  TiXmlAttribute *unaff_ESI;
  undefined4 unaff_retaddr;
  float local_c;
  uint local_8;
  int local_4;
  
  CMwProfiler::GetTimeStamp((int64 *)&local_8);
  iVar2 = *(int *)(this + 0x3c);
  uVar1 = *(uint *)(this + 0x38);
  if ((iVar2 < 1) && ((iVar2 < 0 || (uVar1 < 3)))) {
    iVar2 = iVar2 + (uint)(0xfffffffe < uVar1);
    *(uint *)(this + 0x38) = uVar1 + 1;
    *(int *)(this + 0x3c) = iVar2;
    if ((-1 < iVar2) && ((0 < iVar2 || (2 < uVar1 + 1)))) {
      *(uint *)(this + 0x40) = local_8;
      *(int *)(this + 0x44) = local_4;
      *(int *)(this + 0x3c) = local_4;
      *(uint *)(this + 0x38) = local_8;
      return;
    }
  }
  else {
    uVar3 = CMwProfiler::GetTimeFromDeltaTimeStamp
                      (CONCAT44((local_4 - iVar2) - (uint)(local_8 < uVar1),local_8 - uVar1));
    local_c = 1.0 / ((float)(int)uVar3 * (float)_DAT_00b30a18);
    CFastBuffer<float>::Add(this + 0x28,(TiXmlAttributeSet *)&local_c,unaff_ESI);
    *(undefined4 *)(this + 0x3c) = unaff_retaddr;
    *(int *)(this + 0x38) = local_4;
  }
  return;
}
}

