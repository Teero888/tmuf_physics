// Class implementation: CMwStack

// =================================================
// Function: CMwStack::CMwStack
// =================================================
void __thiscall CMwStack::CMwStack(CMwStack *this,CMwStack *param_1,ulong param_2)
{
{
  ulong unaff_ESI;
  
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0xc) = 1;
  SetSize(this,(CMwStatsValue *)param_1,unaff_ESI);
  return;
}
}

// =================================================
// Function: CMwStack::ChangeBaseVal
// =================================================
ulong __thiscall CMwStack::ChangeBaseVal(CMwStack *this,CMwStack *param_1,ulong param_2)
{
{
  if (*(int *)(this + 4) != 0) {
    **(undefined4 **)(this + 0x10) = param_1;
    return 0;
  }
  return 5;
}
}

// =================================================
// Function: CMwStack::CopyFrom
// =================================================
void __thiscall CMwStack::CopyFrom(CMwStack *this,SParam_Set *param_1,SParam *param_2)
{
{
  void *pvVar1;
  SParam *pSVar2;
  
  if (*(void **)(this + 0x10) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x10));
    operator_delete__(*(void **)(this + 0x14));
  }
  pSVar2 = param_2 + *(int *)(param_1 + 8);
  *(SParam **)(this + 8) = pSVar2;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  if (pSVar2 == (SParam *)0x0) {
    *(undefined4 *)(this + 0x10) = 0;
    *(undefined4 *)(this + 0x14) = 0;
  }
  else {
    pvVar1 = operator_new__(-(uint)((int)(ZEXT48(pSVar2) * 4 >> 0x20) != 0) |
                            (uint)(ZEXT48(pSVar2) * 4));
    *(void **)(this + 0x10) = pvVar1;
    pvVar1 = operator_new__(-(uint)((int)(ZEXT48(pSVar2) * 4 >> 0x20) != 0) |
                            (uint)(ZEXT48(pSVar2) * 4));
    *(void **)(this + 0x14) = pvVar1;
    if (*(int *)(param_1 + 4) != 0) {
      _memcpy(*(void **)(this + 0x10),*(void **)(param_1 + 0x10),*(int *)(param_1 + 4) * 4);
      _memcpy(*(void **)(this + 0x14),*(void **)(param_1 + 0x14),*(int *)(param_1 + 4) * 4);
      return;
    }
  }
  return;
}
}

// =================================================
// Function: CMwStack::FillIndexFromText
// =================================================
ulong __thiscall
CMwStack::FillIndexFromText
          (CMwStack *this,CMwStack *param_1,ulong param_2,CMwNod *param_3,CFastString *param_4)
{
{
  int iVar1;
  CMwNod *pCVar2;
  ulong uVar3;
  undefined1 *puVar4;
  TiXmlAttribute *unaff_EBX;
  TiXmlAttributeSet *unaff_ESI;
  SFastTokenInt *unaff_EDI;
  CFastString *in_stack_00000014;
  ulong in_stack_ffffffc4;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_ffffffc8;
  undefined4 local_34;
  undefined *local_30;
  undefined1 auStack_2c [4];
  CFastBuffer<class_CCrystalFace*> *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined *local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ae4db0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (&local_34,
             (CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffb8));
  local_1c = 0;
  local_18 = PTR_DAT_00bbf7d8;
  local_24 = 2;
  local_20 = 0xffffffff;
  local_14 = 0;
  local_10 = 0;
  local_c = &DAT_00bc9c54;
  iVar1 = CFastString::GetNextToken(param_4,(CFastStringInt *)&local_24,unaff_EDI);
  while (iVar1 != 0) {
    if (local_18 != (undefined *)0x0) {
      in_stack_00000014 = operator_new(8);
      if (in_stack_00000014 == (CFastString *)0x0) {
        in_stack_00000014 = (CFastString *)0x0;
      }
      else {
        *(undefined4 *)in_stack_00000014 = 0;
        *(undefined **)(in_stack_00000014 + 4) = PTR_DAT_00bbf7d8;
      }
      local_34 = local_14;
      local_30 = local_18;
      CFastString::SetString
                (in_stack_00000014,(CFastStringInt *)&local_34,(SStringParam *)unaff_ESI);
      unaff_ESI = (TiXmlAttributeSet *)&stack0x00000018;
      unaff_EDI = (SFastTokenInt *)0x938401;
      CFastBuffer<class_CDx9TextureKeeper*>::Add(&local_28,unaff_ESI,unaff_EBX);
    }
    iVar1 = CFastString::GetNextToken(param_4,(CFastStringInt *)&local_24,unaff_EDI);
  }
  pCVar2 = (CMwNod *)CFastBuffer<class_CCrystalFace*>::GetCount(auStack_2c,local_28);
  uVar3 = FillIndexFromText(this,(CMwStack *)param_4,(ulong)in_stack_00000014,pCVar2,
                            (CFastString *)unaff_ESI);
  CFastBuffer<class_CFastString*>::DeleteAll(&local_28,(CFastArray<class_CCrystalEdge*> *)unaff_EBX)
  ;
  if (uVar3 != 0) {
    SetSize(this,(CMwStatsValue *)0x0,in_stack_ffffffc4);
  }
  if (puStack_8 != PTR_DAT_00bbf7d8) {
    puVar4 = puStack_8 + -1;
    if ((puStack_8[-1] & 0x80) != 0) {
      puVar4 = puStack_8 + -4;
    }
    operator_delete__(puVar4);
    local_c = (undefined *)0x0;
    puStack_8 = PTR_DAT_00bbf7d8;
  }
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(&local_20,in_stack_ffffffc8)
  ;
  ExceptionList = param_3;
  return uVar3;
}
}

// =================================================
// Function: CMwStack::GetArgument
// =================================================
ulong __thiscall
CMwStack::GetArgument
          (CMwStack *this,CMwStack *param_1,ulong param_2,EStackType param_3,ulong *param_4)
{
{
  int iVar1;
  CMwStack *pCVar2;
  CMwStack *pCVar3;
  
  iVar1 = *(int *)(this + 4);
  pCVar3 = (CMwStack *)(iVar1 - 1);
  if ((*(int *)param_3 == -1) && (*(undefined4 *)param_3 = 0, iVar1 != 1)) {
    do {
      if (0xfffffff < *(int *)(*(int *)(this + 0x14) + *(int *)param_3 * 4)) break;
      pCVar2 = (CMwStack *)(*(int *)param_3 + 1);
      *(CMwStack **)param_3 = pCVar2;
    } while (pCVar2 < pCVar3);
  }
  pCVar2 = param_1 + *(int *)param_3;
  if ((pCVar2 < pCVar3) && (*(ulong *)(*(int *)(this + 0x14) + (int)pCVar2 * 4) == param_2)) {
    return *(ulong *)(*(int *)(this + 0x10) + (int)pCVar2 * 4);
  }
  return 0;
}
}

// =================================================
// Function: CMwStack::InsertBaseIndex
// =================================================
ulong __thiscall CMwStack::InsertBaseIndex(CMwStack *this,CMwStack *param_1,ulong param_2)
{
{
  ulong unaff_ESI;
  
  InsertBaseVal(this,param_1,unaff_ESI);
  **(undefined4 **)(this + 0x14) = 1;
  return 0;
}
}

// =================================================
// Function: CMwStack::InsertBaseNameIndex
// =================================================
ulong __thiscall CMwStack::InsertBaseNameIndex(CMwStack *this,CMwStack *param_1,ulong param_2)
{
{
  ulong unaff_ESI;
  
  InsertBaseVal(this,param_1,unaff_ESI);
  **(undefined4 **)(this + 0x14) = 2;
  return 0;
}
}

// =================================================
// Function: CMwStack::InsertBaseVal
// =================================================
ulong __thiscall CMwStack::InsertBaseVal(CMwStack *this,CMwStack *param_1,ulong param_2)
{
{
  uint uVar1;
  
  uVar1 = *(uint *)(this + 8);
  if (uVar1 <= *(uint *)(this + 4)) {
    return 4;
  }
  while (uVar1 = uVar1 - 1, 0 < (int)uVar1) {
    *(undefined4 *)(*(int *)(this + 0x10) + uVar1 * 4) =
         *(undefined4 *)(*(int *)(this + 0x10) + -4 + uVar1 * 4);
    *(undefined4 *)(*(int *)(this + 0x14) + uVar1 * 4) =
         *(undefined4 *)(*(int *)(this + 0x14) + -4 + uVar1 * 4);
  }
  *(int *)(this + 4) = *(int *)(this + 4) + 1;
  **(undefined4 **)(this + 0x10) = param_1;
  return 0;
}
}

// =================================================
// Function: CMwStack::MakeInfoFromStack
// =================================================
ulong __thiscall
CMwStack::MakeInfoFromStack(CMwStack *this,CMwStack *param_1,SMwParamInfo *param_2,CMwNod *param_3)
{
{
  undefined4 uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined *puVar5;
  SMwParamInfo *pSVar6;
  undefined4 *puVar7;
  CMwParam *unaff_EDI;
  int iVar8;
  
  piVar3 = *(int **)(this + 0x14);
  iVar8 = 0;
  if (*piVar3 != 0) {
    do {
      piVar3 = piVar3 + 1;
      iVar8 = iVar8 + 1;
    } while (*piVar3 != 0);
    if (iVar8 != 0) {
      puVar7 = *(undefined4 **)(*(int *)(this + 0x10) + iVar8 * 4);
      iVar4 = CMwParam::IsIndexed((CMwParam *)puVar7[2],unaff_EDI);
      if (iVar4 == 0) {
        iVar4 = (**(code **)(*(int *)this + 0x10))(0x1008000);
        if (iVar4 != 0) goto LAB_00937781;
        if (iVar8 == 1) {
          iVar8 = **(int **)(this + 0x10);
          uVar2 = *(uint *)(puVar7[9] + iVar8 * 4);
          if (uVar2 < 0x1001000) {
            *(uint *)param_2 = uVar2;
            puVar5 = (&PTR_DAT_00bc6508)[uVar2];
          }
          else {
            *(undefined4 *)param_2 = 5;
            puVar5 = PTR_DAT_00bc651c;
          }
          *(undefined4 *)(param_2 + 4) = 0xffffffff;
          *(undefined4 *)(param_2 + 0xc) = 0xffffffff;
          *(undefined **)(param_2 + 8) = puVar5;
          *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(puVar7[10] + iVar8 * 4);
          *(undefined4 *)(param_2 + 0x14) = 0;
          *(undefined4 *)(param_2 + 0x18) = puVar7[6];
          return 0;
        }
        *(undefined4 *)param_2 = 0x24;
        *(undefined **)(param_2 + 8) = PTR_DAT_00bc6598;
        *(undefined4 *)(param_2 + 4) = 0xffffffff;
        *(undefined4 *)(param_2 + 0xc) = 0xffffffff;
        *(undefined4 *)(param_2 + 0x10) = 0;
        *(undefined4 *)(param_2 + 0x14) = 0;
        *(undefined4 *)(param_2 + 0x18) = puVar7[6];
      }
      else {
        iVar4 = puVar7[9];
        *(int *)param_2 = iVar4;
        *(undefined4 *)(param_2 + 4) = 0xffffffff;
        *(undefined **)(param_2 + 8) = (&PTR_DAT_00bc6508)[iVar4];
        *(undefined4 *)(param_2 + 0xc) = 0xffffffff;
        *(undefined4 *)(param_2 + 0x10) = puVar7[4];
        *(undefined4 *)(param_2 + 0x14) = puVar7[7];
        *(undefined4 *)(param_2 + 0x18) = puVar7[6];
        uVar1 = puVar7[10];
        *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfffffffb;
        *(undefined4 *)(param_2 + 0x1c) = uVar1;
        if (iVar8 == 2) {
          pSVar6 = param_2;
          puVar7 = &DAT_00d357f0;
          for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
            *puVar7 = *(undefined4 *)pSVar6;
            pSVar6 = pSVar6 + 4;
            puVar7 = puVar7 + 1;
          }
          puVar7 = &DAT_00d357f0;
LAB_00937781:
          *(undefined4 *)param_2 = 0x24;
          *(undefined4 *)(param_2 + 4) = 0xffffffff;
          *(undefined **)(param_2 + 8) = PTR_DAT_00bc6598;
          *(undefined4 *)(param_2 + 0xc) = 0xffffffff;
          *(undefined4 *)(param_2 + 0x10) = puVar7[4];
          *(undefined4 *)(param_2 + 0x14) = puVar7[5];
          *(undefined4 *)(param_2 + 0x18) = puVar7[6];
          switch(*puVar7) {
          case 9:
          case 0x13:
          case 0x17:
          case 0x31:
          case 0x35:
          case 0x39:
          case 0x3d:
            break;
          default:
            return 1;
          }
        }
      }
      return 0;
    }
  }
  puVar7 = (undefined4 *)**(undefined4 **)(this + 0x10);
  for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
    *(undefined4 *)param_1 = *puVar7;
    puVar7 = puVar7 + 1;
    param_1 = param_1 + 4;
  }
  return 0;
}
}

// =================================================
// Function: CMwStack::SetSize
// =================================================
void __thiscall CMwStack::SetSize(CMwStack *this,CMwStatsValue *param_1,ulong param_2)
{
{
  void *pvVar1;
  void *pvVar2;
  
  if (param_1 == (CMwStatsValue *)0x0) {
    if (*(void **)(this + 0x10) != (void *)0x0) {
      operator_delete__(*(void **)(this + 0x10));
      operator_delete__(*(void **)(this + 0x14));
      *(undefined4 *)(this + 4) = 0;
      *(undefined4 *)(this + 0x10) = 0;
      *(undefined4 *)(this + 8) = 0;
      *(undefined4 *)(this + 0x14) = 0;
      return;
    }
  }
  else {
    pvVar1 = operator_new__(-(uint)((int)(ZEXT48(param_1) * 4 >> 0x20) != 0) |
                            (uint)(ZEXT48(param_1) * 4));
    pvVar2 = operator_new__(-(uint)((int)(ZEXT48(param_1) * 4 >> 0x20) != 0) |
                            (uint)(ZEXT48(param_1) * 4));
    if (*(int *)(this + 8) == 0) {
      *(undefined4 *)(this + 4) = 0;
    }
    else {
      _memcpy(pvVar1,*(void **)(this + 0x10),*(int *)(this + 4) * 4);
      _memcpy(pvVar2,*(void **)(this + 0x14),*(int *)(this + 4) * 4);
      operator_delete__(*(void **)(this + 0x10));
      operator_delete__(*(void **)(this + 0x14));
    }
    *(void **)(this + 0x10) = pvVar1;
    *(int *)(this + 0x18) = *(int *)(this + 4) + -1;
    *(CMwStatsValue **)(this + 8) = param_1;
    *(void **)(this + 0x14) = pvVar2;
  }
  return;
}
}

// =================================================
// Function: CMwStack::WatchNextNameIndex
// =================================================
ulong __thiscall
CMwStack::WatchNextNameIndex
          (CMwStack *this,CMwStack *param_1,ulong *param_2,CMwNod **param_3,ulong param_4)
{
{
  CFastStringInt *pCVar1;
  int *piVar2;
  CMwNod **ppCVar3;
  CMwStack *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ae4d38;
  local_c = ExceptionList;
  pCVar1 = (CFastStringInt *)(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  ExceptionList = &local_c;
  *(int *)(this + 0x18) = *(int *)(this + 0x18) + -1;
  local_10 = this;
  CMwId::CreateFromLocalIndex((ulong)&local_10);
  ppCVar3 = (CMwNod **)0x0;
  local_4 = 0;
  if (param_3 != (CMwNod **)0x0) {
    do {
      piVar2 = (int *)(**(code **)(*(int *)param_2[(int)ppCVar3] + 0x14))();
      if ((piVar2 != (int *)0x0) && ((CMwStack *)*piVar2 == local_10)) {
        *(CMwNod ***)param_1 = ppCVar3;
        local_4 = 0xffffffff;
        OnAccessViolation_ConcatToCrashFileName(pCVar1);
        ExceptionList = local_c;
        return 0;
      }
      ppCVar3 = (CMwNod **)((int)ppCVar3 + 1);
    } while (ppCVar3 < param_3);
  }
  local_4 = 0xffffffff;
  OnAccessViolation_ConcatToCrashFileName(pCVar1);
  ExceptionList = local_c;
  return 2;
}
}

// =================================================
// Function: CMwStack::~CMwStack
// =================================================
void __thiscall CMwStack::~CMwStack(CMwStack *this,CMwStack *param_1)
{
{
  *(undefined ***)this = vftable;
  if (*(int *)(this + 0xc) != 0) {
    operator_delete__(*(void **)(this + 0x10));
    operator_delete__(*(void **)(this + 0x14));
  }
  return;
}
}

