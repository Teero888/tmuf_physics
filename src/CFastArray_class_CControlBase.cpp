// Class implementation: CFastArray_class_CControlBase

// =================================================
// Function: >::AddTailWithUniqueId
// =================================================
void __thiscall
CFastArray<class_CControlBase*>::AddTailWithUniqueId
          (void *this,CFastArray<class_CMotion*> *param_1,CMotion **param_2,char *param_3)
{
{
  bool bVar1;
  CFastArray<class_CMotion*> *pCVar2;
  SFormat *pSVar3;
  int iVar4;
  int *piVar5;
  void *this_00;
  int *piVar6;
  undefined *puVar7;
  CTrackManiaEditorIconPage *pCVar8;
  undefined4 uStack_1c;
  undefined *puStack_18;
  undefined4 uStack_14;
  undefined *puStack_10;
  void *local_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  pCVar2 = param_1;
  iStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ac68f0;
  local_c = ExceptionList;
  pSVar3 = (SFormat *)(DAT_00cca150 ^ (uint)&stack0xffffffd0);
  ExceptionList = &local_c;
  iVar4 = (**(code **)(**(int **)param_1 + 0x14))();
  if (iVar4 != 0) {
    piVar5 = (int *)(**(code **)(**(int **)param_1 + 0x14))();
    if (*piVar5 == -1) {
      (**(code **)(**(int **)param_1 + 0x18))(param_2);
    }
    uStack_14 = 0;
    puStack_10 = PTR_DAT_00bbf7d8;
    pCVar8 = (CTrackManiaEditorIconPage *)&uStack_14;
    iStack_4 = 0;
    this_00 = (void *)(**(code **)(**(int **)param_1 + 0x14))();
    CMwId::GetName(this_00,pCVar8);
    do {
      bVar1 = false;
      param_1 = (CFastArray<class_CMotion*> *)0x0;
      if (*(int *)this == 0) break;
      do {
        piVar5 = (int *)(**(code **)(**(int **)(*(int *)((int)this + 4) + (int)param_1 * 4) + 0x14))
                                  ();
        if (piVar5 != (int *)0x0) {
          piVar6 = (int *)(**(code **)(**(int **)pCVar2 + 0x14))();
          if (*piVar5 == *piVar6) {
            bVar1 = true;
            uStack_1c = 0;
            puStack_18 = PTR_DAT_00bbf7d8;
            iStack_4._0_1_ = 1;
            CFastString::Format((CFastString *)PTR_DAT_00bbf7d8,(CFastString *)&uStack_1c,"%s_%2d");
            pSVar3 = (SFormat *)0x76770d;
            (**(code **)(**(int **)pCVar2 + 0x18))();
            iStack_4 = (uint)iStack_4._1_3_ << 8;
            if (puStack_18 != PTR_DAT_00bbf7d8) {
              puVar7 = puStack_18 + -1;
              if ((puStack_18[-1] & 0x80) != 0) {
                puVar7 = puStack_18 + -4;
              }
              operator_delete__(puVar7);
              uStack_1c = 0;
              puStack_18 = PTR_DAT_00bbf7d8;
            }
          }
        }
        param_1 = param_1 + 1;
      } while (param_1 < *(CFastArray<class_CMotion*> **)this);
    } while (bVar1);
    iStack_4 = 0xffffffff;
    if (puStack_10 != PTR_DAT_00bbf7d8) {
      puVar7 = puStack_10 + -1;
      if ((puStack_10[-1] & 0x80) != 0) {
        puVar7 = puStack_10 + -4;
      }
      operator_delete__(puVar7);
      uStack_14 = 0;
      puStack_10 = PTR_DAT_00bbf7d8;
    }
  }
  CFastArray<class_CFastBuffer<class_CSceneMobil*>*>::AddTail
            (this,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)pCVar2,pSVar3);
  ExceptionList = puStack_8;
  return;
}
}

// =================================================
// Function: >::CopyFromFastArray
// =================================================
void __thiscall
CFastArray<class_CControlBase*>::CopyFromFastArray
          (void *this,CFastArray<class_GmVec4> *param_1,CFastArray<class_GmVec4> *param_2)
{
{
  CFastBuffer<class_CSystemFidsFolder*> *pCVar1;
  CFastBuffer<class_CSystemFidsFolder*> *pCVar2;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<class_CSystemFidsFolder*> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(param_1,unaff_EDI);
  CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount(this,pCVar1,unaff_ESI);
  pCVar2 = (CFastBuffer<class_CSystemFidsFolder*> *)0x0;
  if (pCVar1 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
    do {
      *(undefined4 *)(*(int *)((int)this + 4) + (int)pCVar2 * 4) =
           *(undefined4 *)(*(int *)(param_1 + 4) + (int)pCVar2 * 4);
      pCVar2 = pCVar2 + 1;
    } while (pCVar2 < pCVar1);
  }
  return;
}
}

