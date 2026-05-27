// Class implementation: CMotionDayTime

// =================================================
// Function: CMotionDayTime::CMotionDayTime
// =================================================
void __thiscall CMotionDayTime::CMotionDayTime(CMotionDayTime *this,CMotionDayTime *param_1)
{
{
  CMotionManaged *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_retaddr;
  
  CMotionManaged::CMotionManaged((CMotionManaged *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x30,unaff_retaddr);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x3c,(CFastBuffer<class_CPlugFileSndGen*> *)param_1);
  *(undefined4 *)(this + 0x24) = 1;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  return;
}
}

// =================================================
// Function: CMotionDayTime::OnDayTimeChange
// =================================================
void __thiscall
CMotionDayTime::OnDayTimeChange
          (CMotionDayTime *this,CMotionWeather *param_1,CFuncWeather *param_2,EDayTime4 param_3)
{
{
  CPlugTree *pCVar1;
  CPlugMaterial *this_00;
  int iVar2;
  ulong uVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  SCasterCat *pSVar5;
  CPlugMaterial *unaff_EBX;
  CMwNod *pCVar6;
  CMotionDayTime *pCVar7;
  CPlugMaterialCustom *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CMotionDayTime *unaff_retaddr;
  int in_stack_00000010;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack00000014;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000018;
  CPlugMaterial *in_stack_ffffffdc;
  EParam EVar9;
  CPlugShader *pCVar10;
  ulong in_stack_fffffff4;
  CMwNod *local_8;
  CPlugMaterialCustom *local_4;
  
  pCVar7 = this + 0x30;
  EVar9 = 0x571717;
  local_8 = (CMwNod *)this;
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(pCVar7,unaff_EDI);
  if (uVar3 != 0) {
    if (*(int *)(this + 0x24) == 1) {
      pCVar10 = (CPlugShader *)0x57172c;
      pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(pCVar7,unaff_ESI);
      pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        local_4 = (CPlugMaterialCustom *)(uint)(param_3 == 0);
        do {
          pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (pCVar7,pCVar8,(ulong)in_stack_ffffffdc);
          in_stack_ffffffdc = unaff_EBX;
          pCVar1 = *(CPlugTree **)pSVar5;
          this_00 = *(CPlugMaterial **)(pCVar1 + 0x98);
          unaff_EBX = in_stack_ffffffdc;
          CPlugMaterial::ForceParam(this_00,in_stack_ffffffdc,EVar9);
          pCVar10 = CPlugMaterial::GetSupportedShader(this_00,(CPlugMaterial *)pCVar10);
          EVar9 = 0x571772;
          CPlugTree::SetShader(pCVar1,(CPlugBitmapShader *)pCVar10,(CPlugShader *)unaff_ESI);
          pCVar8 = pCVar8 + 1;
          this = unaff_retaddr;
        } while (pCVar8 < pCVar4);
      }
    }
    else {
      if (*(CSystemFid **)(this + (int)param_2 * 4 + 0x28) == (CSystemFid *)0x0) {
        local_8 = (CMwNod *)0x0;
      }
      else {
        CSystemArchiveNod::LoadFromFid(&local_8,*(CSystemFid **)(this + (int)param_2 * 4 + 0x28),7);
      }
      pCVar6 = local_8;
      pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(pCVar7,unaff_ESI);
      pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      this = unaff_retaddr;
      if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (pCVar7,pCVar8,(ulong)unaff_EBP);
          pCVar1 = *(CPlugTree **)pSVar5;
          if (pCVar6 == (CMwNod *)0x0) {
            *(uint *)(pCVar1 + 0x9c) = *(uint *)(pCVar1 + 0x9c) & 0xfffffff7;
          }
          else {
            CPlugTree::SetMaterial(pCVar1,(CPlugMaterialCustom *)pCVar6,unaff_EBX);
            *(uint *)(pCVar1 + 0x9c) = *(uint *)(pCVar1 + 0x9c) | 8;
            unaff_EBP = (CPlugMaterialCustom *)pCVar6;
          }
          pCVar8 = pCVar8 + 1;
          pCVar6 = (CMwNod *)local_4;
        } while (pCVar8 < pCVar4);
      }
    }
  }
  pCVar7 = this + 0x3c;
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (pCVar7,(CFastBuffer<class_CCrystalFace*> *)unaff_EBP);
  if (uVar3 != 0) {
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (pCVar7,(CFastBuffer<class_CCrystalFace*> *)unaff_EBX);
    pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    pCStack00000014 = pCVar4;
    if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (pCVar7,pCVar8,in_stack_fffffff4);
        iVar2 = *(int *)(*(int *)pSVar5 + 0xb0);
        if (iVar2 != 0) {
          *(uint *)(iVar2 + 0x14) =
               (uint)(in_stack_00000010 == 0) << 4 | *(uint *)(iVar2 + 0x14) & 0xffffffe7 |
               (uint)(in_stack_00000010 == 0) * 8;
          pCVar4 = in_stack_00000018;
        }
        pCVar8 = pCVar8 + 1;
      } while (pCVar8 < pCVar4);
    }
  }
  return;
}
}

// =================================================
// Function: CMotionDayTime::SetMaterialMode
// =================================================
void __thiscall
CMotionDayTime::SetMaterialMode(CMotionDayTime *this,CMotionDayTime *param_1,EMaterialMode param_2)
{
{
  *(CMotionDayTime **)(this + 0x24) = param_1;
  return;
}
}

