// Class implementation: CFastBuffer_class_CSceneMobil

// =================================================
// Function: >::Merge
// =================================================
void __thiscall
CFastBuffer<class_CSceneMobil*>::Merge
          (void *this,CFastBuffer<class_CSceneMobil*> *param_1,
          CFastBuffer<class_CSceneMobil*> *param_2)
{
{
  int iVar1;
  ulong uVar2;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar3;
  int iVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong unaff_EDI;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar5;
  
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(param_1,unaff_ESI);
  if (uVar2 != 0) {
    iVar1 = *(int *)(param_1 + 4);
    pCVar5 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(*(int *)this + uVar2);
    CFastBuffer<int>::SetSizeAtLeast(this,pCVar5,unaff_EDI);
    pCVar3 = *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)this;
    while (pCVar3 < pCVar5) {
      iVar4 = (int)pCVar3 - *(int *)this;
      pCVar3 = pCVar3 + 1;
      *(undefined4 *)(*(int *)((int)this + 4) + -4 + (int)pCVar3 * 4) =
           *(undefined4 *)(iVar1 + iVar4 * 4);
    }
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)this = pCVar5;
  }
  return;
}
}

