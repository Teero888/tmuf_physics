// Class implementation: CGameCtnBlockInfo

// =================================================
// Function: CGameCtnBlockInfo::AddBlock
// =================================================
void __thiscall
CGameCtnBlockInfo::AddBlock
          (CGameCtnBlockInfo *this,CGameCtnBlockInfo *param_1,GmNat3 param_2,int param_3,
          ulong param_4,int param_5)
{
{
  CGameCtnBlockUnitInfo *this_00;
  ulong extraout_EAX;
  CGameCtnBlockInfo *this_01;
  SFormat *pSVar1;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00aae5ab;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pSVar1 = (SFormat *)0x54;
  this_00 = operator_new(0x54);
  local_4 = 0;
  if (this_00 == (CGameCtnBlockUnitInfo *)0x0) {
    param_4 = 0;
  }
  else {
    pSVar1 = (SFormat *)0x0;
    CGameCtnBlockUnitInfo::CGameCtnBlockUnitInfo
              (this_00,(CGameCtnBlockUnitInfo *)param_1,param_2,param_3,param_4,
               (CGameCtnBlockInfoClip *)param_5,(CGameCtnBlockInfoClip *)0x0,
               (CGameCtnBlockInfoClip *)0x0,(CGameCtnBlockInfoClip *)0x0,(CGameCtnBlockInfo *)0x0);
    param_4 = extraout_EAX;
  }
  local_8 = (undefined1 *)0xffffffff;
  if (param_5 == 0) {
    this_01 = this + 0xf4;
  }
  else {
    this_01 = this + 0xec;
  }
  CFastArray<class_CFastBuffer<class_CSceneMobil*>*>::AddTail
            (this_01,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)&param_4,pSVar1);
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CGameCtnBlockInfo::CGameCtnBlockInfo
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CGameCtnBlockInfo::CGameCtnBlockInfo(CGameCtnBlockInfo *this,CGameCtnBlockInfo *param_1)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  CFastArray<class_CManoeuvre*> *unaff_EBX;
  CFastArray<class_CManoeuvre*> *unaff_EBP;
  CFastArray<class_CManoeuvre*> *unaff_ESI;
  undefined4 *puVar6;
  undefined4 *puVar7;
  CFastArray<class_CManoeuvre*> *unaff_EDI;
  CGameCtnBlockInfo *pCVar8;
  void *in_stack_0000000c;
  undefined1 uStack00000010;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00aae3d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar8 = this;
  CGameCtnCollector::CGameCtnCollector
            ((CGameCtnCollector *)this,(CGameCtnCollector *)(DAT_00cca150 ^ (uint)&stack0xffffffe0))
  ;
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0xec,unaff_EDI);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0xf4,unaff_ESI);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0xfc,unaff_EBP);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x104,unaff_EBX);
  *(undefined4 *)(this + 0x10c) = 0;
  *(undefined4 *)(this + 0x110) = 0;
  *(undefined4 *)(this + 0x114) = 0;
  *(undefined4 *)(this + 0x118) = 0;
  uStack00000010 = 8;
  CMwId::CMwId(this + 0x128,(CMwId *)pCVar8);
  puVar7 = (undefined4 *)PTR_DAT_00cf3550;
  *(undefined4 *)(this + 0xe0) = 0;
  *(undefined4 *)(this + 0x58) = 1;
  *(undefined4 *)(this + 0x5c) = 1;
  *(undefined4 *)(this + 0x60) = 1;
  *(undefined4 *)(this + 100) = 1;
  *(undefined4 *)(this + 0x68) = 1;
  *(undefined4 *)(this + 0x6c) = 1;
  *(undefined4 *)(this + 0x7c) = 2;
  *(undefined4 *)(this + 0xe8) = 0;
  *(undefined4 *)(this + 0x30) = 1;
  puVar6 = puVar7;
  pCVar8 = this + 0x80;
  for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined4 *)pCVar8 = *puVar6;
    puVar6 = puVar6 + 1;
    pCVar8 = pCVar8 + 4;
  }
  pCVar8 = this + 0xb0;
  for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined4 *)pCVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    pCVar8 = pCVar8 + 4;
  }
  fVar3 = (float)_DAT_00b5b908;
  fVar1 = _DAT_00ce9474 * fVar3;
  fVar2 = (float)_DAT_00b313b8;
  *(float *)(this + 0xa4) = _DAT_00ce9474 * fVar2;
  uVar4 = _DAT_00b69500;
  *(undefined4 *)(this + 0xa8) = _DAT_00b69500;
  *(float *)(this + 0xac) = fVar1;
  fVar3 = _DAT_00ce9474 * fVar3;
  *(float *)(this + 0xd4) = _DAT_00ce9474 * fVar2;
  *(undefined4 *)(this + 0xd8) = uVar4;
  *(float *)(this + 0xdc) = fVar3;
  *(undefined4 *)(this + 0x124) = 1;
  *(undefined4 *)(this + 0x11c) = 3;
  *(undefined4 *)(this + 0xe4) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x74) = 1;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 300) = 0;
  *(undefined4 *)(this + 0x120) = 0;
  ExceptionList = in_stack_0000000c;
  return;
}
}

// =================================================
// Function: CGameCtnBlockInfo::GetBlockUnitInfo
// =================================================
CGameCtnBlockUnitInfo * __thiscall
CGameCtnBlockInfo::GetBlockUnitInfo
          (CGameCtnBlockInfo *this,CGameCtnBlockInfo *param_1,ulong param_2,int param_3)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  
  if (param_2 != 0) {
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0xec,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                        unaff_retaddr);
    return *(CGameCtnBlockUnitInfo **)pSVar1;
  }
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0xf4,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                      unaff_retaddr);
  return *(CGameCtnBlockUnitInfo **)pSVar1;
}
}

// =================================================
// Function: CGameCtnBlockInfo::GetMobil
// =================================================
CSceneMobil * __thiscall
CGameCtnBlockInfo::GetMobil
          (CGameCtnBlockInfo *this,CGameCtnBlockInfo *param_1,int param_2,ulong param_3,
          ulong param_4)
{
{
  CFastBuffer<class_CSceneMobil*> *this_00;
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_ESI;
  SShaderCustom *unaff_retaddr;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000018;
  
  this_00 = GetMobilBuffer(this,param_1,param_2,unaff_ESI);
  if (this_00 != (CFastBuffer<class_CSceneMobil*> *)0x0) {
    iVar1 = CFastBuffer<class_CAudioSound*>::IsEmpty(this_00,unaff_retaddr);
    if (iVar1 == 0) {
      pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (this_00,(CFastBuffer<class_CCrystalFace*> *)param_1);
      if (pCVar2 <= in_stack_00000018) {
        in_stack_00000018 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      }
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,in_stack_00000018,param_2);
      return *(CSceneMobil **)pSVar3;
    }
  }
  return (CSceneMobil *)0x0;
}
}

// =================================================
// Function: CGameCtnBlockInfo::GetMobilBuffer
// =================================================
CFastBuffer<class_CSceneMobil*> * __thiscall
CGameCtnBlockInfo::GetMobilBuffer
          (CGameCtnBlockInfo *this,CGameCtnBlockInfo *param_1,int param_2,ulong param_3)
{
{
  ulong uVar1;
  SCasterCat *pSVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CGameCtnBlockInfo *this_00;
  ulong unaff_retaddr;
  
  this_00 = this + 0xfc;
  if (param_1 == (CGameCtnBlockInfo *)0x0) {
    this_00 = this + 0x104;
  }
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
  if (uVar1 <= param_3) {
    return (CFastBuffer<class_CSceneMobil*> *)0x0;
  }
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_3,
                      unaff_retaddr);
  return *(CFastBuffer<class_CSceneMobil*> **)pSVar2;
}
}

// =================================================
// Function: CGameCtnBlockInfo::GetNbBlockUnitInfos
// =================================================
ulong __thiscall
CGameCtnBlockInfo::GetNbBlockUnitInfos
          (CGameCtnBlockInfo *this,CGameCtnBlockInfo *param_1,int param_2)
{
{
  ulong uVar1;
  CFastBuffer<class_CCrystalFace*> *unaff_retaddr;
  
  if (param_1 != (CGameCtnBlockInfo *)0x0) {
    uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0xec,unaff_retaddr);
    return uVar1;
  }
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0xf4,unaff_retaddr);
  return uVar1;
}
}

