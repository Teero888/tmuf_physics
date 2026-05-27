// Class implementation: CFastMapTable_struct_CGameAdvertisingElement_CImpressionCollector_SImpressionRecord

// =================================================
// Function: CFastMapTable<struct_CGameAdvertisingElement::CImpressionCollector::SImpressionRecord>::Clear
// =================================================
void __thiscall
CFastMapTable<struct_CGameAdvertisingElement::CImpressionCollector::SImpressionRecord>::Clear
          (CFastMapTable<struct_CGameAdvertisingElement::CImpressionCollector::SImpressionRecord>
           *this,TiXmlNode *param_1)
{
{
  ulong unaff_retaddr;
  
  ClearAndShrink(this,(CFastMapTable<unsigned_char> *)0xffffffff,unaff_retaddr);
  return;
}
}

// =================================================
// Function: ClearAndShrink
// =================================================
void __thiscall
CFastMapTable<struct_CGameAdvertisingElement::CImpressionCollector::SImpressionRecord>::
ClearAndShrink(CFastMapTable<struct_CGameAdvertisingElement::CImpressionCollector::SImpressionRecord>
               *this,CFastMapTable<unsigned_char> *param_1,ulong param_2)
{
{
  ulong uVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 != (CFastMapTable<unsigned_char> *)0xffffffff) {
    uVar1 = CFastAlgo::ComputeHashSize((ulong)param_1);
    if (uVar1 < *(uint *)(this + 0xc)) {
      operator_delete__(*(void **)(this + 4));
      *(ulong *)(this + 0xc) = uVar1;
      pvVar2 = operator_new__(-(uint)((int)((ulonglong)uVar1 * 0x30 >> 0x20) != 0) |
                              (uint)((ulonglong)uVar1 * 0x30));
      *(void **)(this + 4) = pvVar2;
    }
  }
  uVar3 = 0;
  if (*(int *)(this + 0xc) != 0) {
    iVar4 = 0;
    do {
      *(undefined4 *)(iVar4 + *(int *)(this + 4)) = 0xffffffff;
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 0x30;
    } while (uVar3 < *(uint *)(this + 0xc));
  }
  *(undefined4 *)(this + 8) = 0;
  return;
}
}

// =================================================
// Function: SetFastMapTable
// =================================================
void __thiscall
CFastMapTable<struct_CGameAdvertisingElement::CImpressionCollector::SImpressionRecord>::
SetFastMapTable(CFastMapTable<struct_CGameAdvertisingElement::CImpressionCollector::SImpressionRecord>
                *this,CFastMapTable<struct_CPlugTreeMapShaderFill::SFillValue> *param_1,
               CFastMapTable<struct_CPlugTreeMapShaderFill::SFillValue> *param_2,ulong param_3)
{
{
  ulong uVar1;
  void *pvVar2;
  int iVar3;
  TiXmlNode *unaff_ESI;
  CFastBuffer<struct_SCtnForcedMods::SEnvMod> *unaff_EDI;
  TiXmlAttribute *in_stack_00000014;
  SFillValue *in_stack_ffffffd0;
  SFillValue *in_stack_ffffffd4;
  CFastMapTable<struct_CPlugTreeMapShaderFill::SFillValue> *local_28;
  undefined4 local_24;
  ulong local_20;
  TiXmlAttributeSet local_1c [28];
  
  operator_delete__(*(void **)(this + 4));
  if (param_2 == (CFastMapTable<struct_CPlugTreeMapShaderFill::SFillValue> *)0xffffffff) {
    uVar1 = CFastBuffer<struct_SCtnForcedMods::SEnvMod>::GetAllocatedSize(param_1,unaff_EDI);
    param_2 = (CFastMapTable<struct_CPlugTreeMapShaderFill::SFillValue> *)
              CFastAlgo::ComputeHashSize(uVar1);
  }
  *(CFastMapTable<struct_CPlugTreeMapShaderFill::SFillValue> **)(this + 0xc) = param_2;
  pvVar2 = operator_new__(-(uint)((int)(ZEXT48(param_2) * 0x30 >> 0x20) != 0) |
                          (uint)(ZEXT48(param_2) * 0x30));
  *(void **)(this + 4) = pvVar2;
  Clear(this,unaff_ESI);
  local_28 = param_1;
  local_24 = 0;
  iVar3 = SScanner::GetNext(&local_28,(SScanner *)&stack0x00000010,&local_20,in_stack_ffffffd0);
  while (iVar3 != 0) {
    Add(this,local_1c,in_stack_00000014);
    iVar3 = SScanner::GetNext(&local_24,(SScanner *)&stack0x00000014,(ulong *)local_1c,
                              in_stack_ffffffd4);
  }
  return;
}
}

