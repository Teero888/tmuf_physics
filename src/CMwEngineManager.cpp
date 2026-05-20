// Class implementation: CMwEngineManager

// =================================================
// Function: CMwEngineManager::AddClass
// =================================================
void __thiscall
CMwEngineManager::AddClass(CMwEngineManager *this,CMwEngineInfo *param_1,CMwClassInfo *param_2)
{
{
  CMwEngineManager *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CMwEngineInfo *this_01;
  undefined4 extraout_EAX;
  ulong unaff_EBX;
  CMwEngineInfo *unaff_EBP;
  void *pvVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  ulong unaff_ESI;
  ulong unaff_EDI;
  undefined4 uVar6;
  uint uVar7;
  void *in_stack_00000018;
  CMwEngineInfo *in_stack_00000024;
  void *pvVar8;
  ulong in_stack_fffffff0;
  void *pvVar9;
  CMwClassInfo *pCVar10;
  
  pCVar10 = (CMwClassInfo *)&LAB_00ae5a3b;
  this_00 = this + 4;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(*(uint *)(param_1 + 4) >> 0x18);
  pvVar4 = (void *)(*(uint *)(param_1 + 4) & 0xff000000);
  pvVar9 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pvVar8 = pvVar4;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (this_00,(CFastBuffer<class_CCrystalFace*> *)
                              (DAT_00cca150 ^ (uint)&stack0xffffffdc));
  if (pCVar2 <= pCVar1) {
    pCVar5 = pCVar1 + 1;
    if (pCVar5 < (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000030) {
      pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000030;
    }
    CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
              (this_00,(CFastBuffer<class_CSystemFidsFolder*> *)pCVar5,unaff_EDI);
    pvVar4 = pvVar9;
    for (; pvVar9 = pvVar4, pCVar2 < pCVar5; pCVar2 = pCVar2 + 1) {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar2,unaff_ESI);
      *(undefined4 *)pSVar3 = 0;
    }
  }
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar1,unaff_ESI);
  uVar6 = 0;
  if (*(int *)pSVar3 == 0) {
    this_01 = operator_new(0x14);
    if (this_01 != (CMwEngineInfo *)0x0) {
      CMwEngineInfo::CMwEngineInfo(this_01,unaff_EBP);
      uVar6 = extraout_EAX;
    }
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar1,unaff_EBX);
    *(undefined4 *)pSVar3 = uVar6;
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar1,(ulong)pvVar8)
    ;
    *(void **)(*(int *)pSVar3 + 4) = pvVar4;
    uVar7 = 0;
    do {
      if ((CMwEngineInfo *)(&DAT_00d35d04)[uVar7 * 2] == param_1) {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar1,in_stack_fffffff0);
        *(undefined4 *)(*(int *)pSVar3 + 8) = *(undefined4 *)(uVar7 * 8 + 0xd35d00);
        break;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < 0x2e);
  }
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar1,(ulong)pvVar9);
  CMwEngineInfo::AddClass(*(CMwEngineInfo **)pSVar3,in_stack_00000024,pCVar10);
  ExceptionList = in_stack_00000018;
  return;
}
}

// =================================================
// Function: CMwEngineManager::GetClassInfo
// =================================================
CMwClassInfo * __thiscall
CMwEngineManager::GetClassInfo(CMwEngineManager *this,CMwEngineManager *param_1,ulong param_2)
{
{
  void *this_00;
  CFastBuffer<class_CCrystalFace*> *pCVar1;
  ulong uVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  CPlugFileGpuBuilder *this_01;
  undefined *puVar5;
  ulong unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  undefined4 uStack0000000c;
  undefined *in_stack_00000010;
  CPlugFileGpuBuilder *in_stack_fffffff0;
  char *pcVar7;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pCVar1 = (CFastBuffer<class_CCrystalFace*> *)(DAT_00cca150 ^ (uint)&stack0xffffffdc);
  pcVar7 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  uVar2 = CMwDeprecated::WrapClassId((ulong)param_1);
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar2 >> 0xc & 0xfff);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 4,pCVar1);
  if ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar2 >> 0x18) < pCVar3) {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 4,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar2 >> 0x18),
                        unaff_EDI);
    if (*(int *)pSVar4 != 0) {
      this_00 = (void *)(*(int *)pSVar4 + 0xc);
      pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
      if (pCVar6 < pCVar3) {
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar6,unaff_EBP)
        ;
        if (*(CMwClassInfo **)pSVar4 != (CMwClassInfo *)0x0) {
          ExceptionList = param_1;
          return *(CMwClassInfo **)pSVar4;
        }
      }
    }
  }
  local_4 = 0;
  uStack0000000c = 0;
  CFastString::Format((CFastString *)PTR_DAT_00bbf7d8,(CFastString *)&local_4,
                      "Trying to use a class (0x%08x) from engine \"%s\", which is not available in this exe."
                     );
  if (DAT_00d71e54 != 0) {
    DAT_00d71e54 = 0;
    *DAT_00d71e58 = 0;
  }
  this_01 = CFastString::operator<<
                      ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)&param_1,
                       (char *)&lpOutputString_00b2bcc4);
  CFastString::operator<<((CFastString *)this_01,in_stack_fffffff0,pcVar7);
  CClassicLog::AddLogStringInFile();
  if (in_stack_00000010 != PTR_DAT_00bbf7d8) {
    puVar5 = in_stack_00000010 + -1;
    if ((in_stack_00000010[-1] & 0x80) != 0) {
      puVar5 = in_stack_00000010 + -4;
    }
    operator_delete__(puVar5);
  }
  ExceptionList = param_1;
  return (CMwClassInfo *)0x0;
}
}

