// Class implementation: CControlKeyboardInterface

// =================================================
// Function: CControlKeyboardInterface::GetString
// =================================================
/* WARNING: Variable defined which should be unmapped: param_1 */

void __thiscall
CControlKeyboardInterface::GetString
          (CControlKeyboardInterface *this,CMwStatsValue *param_1,CFastString *param_2)
{
{
  CFastStringInt *pCVar1;
  CMwStatsValue *this_00;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  SCasterCat *pSVar5;
  SShaderCustom *unaff_EBX;
  CControlKeyboardInterface *this_01;
  SOldChars *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CClassicBufferMemory *pCVar6;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  CMwStatsValue *unaff_EDI;
  uint uVar8;
  ulong unaff_retaddr;
  SStringParam *in_stack_0000000c;
  SStringParam *in_stack_00000010;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack00000014;
  uint in_stack_00000018;
  int in_stack_00000024;
  uint in_stack_0000002c;
  CControlKeyboardInterface *pCVar9;
  
  this_00 = param_1;
  pCVar9 = this;
  if (*(int *)param_1 != 0) {
    CFastStringBase<wchar_t>::AllocAtLeast(param_1,(CFastStringBase<wchar_t> *)0x0,1,0,unaff_EBP);
    **(undefined2 **)(param_1 + 4) = 0;
    *(undefined4 *)param_1 = 0;
  }
  this_01 = this + 0x18;
  iVar2 = CFastBuffer<class_CAudioSound*>::IsEmpty(this_01,unaff_EBX);
  if (iVar2 == 0) {
    uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(this_01,unaff_ESI);
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (this_01,(CFastBuffer<class_CCrystalFace*> *)pCVar9);
    pCVar6 = (CClassicBufferMemory *)(uVar3 / 10 + uVar4);
    if (pCVar6 < (CClassicBufferMemory *)0x3e9) {
      pCVar6 = (CClassicBufferMemory *)0x3e8;
    }
    CFastStringBase<wchar_t>::PreAlloc(param_1,pCVar6,unaff_retaddr);
    pCStack00000014 =
         (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
         CFastBuffer<class_CCrystalFace*>::GetCount
                   (this_01,(CFastBuffer<class_CCrystalFace*> *)param_1);
    pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCStack00000014 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      uVar8 = 1;
      param_1 = unaff_EDI;
      do {
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_01,pCVar7,(ulong)param_1);
        pCVar1 = *(CFastStringInt **)pSVar5;
        if (pCVar1 == (CFastStringInt *)0x24) {
          if (in_stack_00000024 == 0) {
            if (uVar8 < in_stack_00000018) {
              pCVar7 = pCVar7 + 1;
              pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 (this_01,pCVar7,(ulong)param_2);
              pCVar1 = *(CFastStringInt **)pSVar5;
              uVar8 = in_stack_0000002c;
              param_1 = (CMwStatsValue *)pCVar7;
              if ((pCVar1 != (CFastStringInt *)&DAT_0000003c) &&
                 (pCVar1 != (CFastStringInt *)&DAT_0000003e)) {
                param_1 = (CMwStatsValue *)0x791b9c;
                CFastStringInt::Concat(this_00,(CFastStringInt *)0x24,in_stack_0000000c);
                param_2 = (CFastString *)0x791ba4;
                CFastStringInt::Concat(this_00,pCVar1,in_stack_00000010);
                in_stack_0000000c = (SStringParam *)pCVar1;
              }
            }
          }
          else {
            CFastStringInt::Concat(this_00,(CFastStringInt *)0x24,(SStringParam *)param_2);
            param_2 = (CFastString *)0x24;
            param_1 = (CMwStatsValue *)0x791b6d;
            CFastStringInt::Concat(this_00,(CFastStringInt *)0x24,in_stack_0000000c);
          }
        }
        else {
          CFastStringInt::Concat(this_00,pCVar1,(SStringParam *)param_2);
          param_1 = (CMwStatsValue *)pCVar1;
        }
        pCVar7 = pCVar7 + 1;
        uVar8 = uVar8 + 1;
      } while (pCVar7 < pCStack00000014);
    }
  }
  return;
}
}

// =================================================
// Function: CControlKeyboardInterface::SetString
// =================================================
void __thiscall
CControlKeyboardInterface::SetString
          (CControlKeyboardInterface *this,CFastStringInt *param_1,SStringParam *param_2)
{
{
  CControlKeyboardInterface *this_00;
  ulong uVar1;
  CFastStringInt *unaff_EBX;
  ulong unaff_ESI;
  GmFrustumIso4 *unaff_EDI;
  CFastStringInt *unaff_retaddr;
  ulong uStack0000000c;
  ulong uStack00000010;
  ulong in_stack_00000014;
  CControlKeyboardInterface *pCVar2;
  
  this_00 = this + 0x18;
  pCVar2 = this;
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this_00,unaff_EDI);
  CFastBuffer<int>::SetSizeAtLeast
            (this_00,*(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)param_2,unaff_ESI);
  uStack00000010 = CFastStringInt::ReadCharsStart(param_2,unaff_EBX);
  uStack0000000c =
       CFastStringInt::ReadCharsNext(param_2,(CFastStringInt *)&stack0x00000010,(ulong *)pCVar2);
  uVar1 = uStack0000000c;
  while (uVar1 != 0) {
    CFastBuffer<class_CDx9TextureKeeper*>::Add
              (this_00,(TiXmlAttributeSet *)&stack0x0000000c,(TiXmlAttribute *)unaff_retaddr);
    unaff_retaddr = (CFastStringInt *)&stack0x00000018;
    in_stack_00000014 = CFastStringInt::ReadCharsNext(param_2,unaff_retaddr,(ulong *)param_1);
    uVar1 = in_stack_00000014;
  }
  *(undefined4 *)(this + 0x10) = 1;
  return;
}
}

