// Class implementation: CFastArray_class_GmVec4

// =================================================
// Function: CFastArray<class_GmVec4>::CopyFromFastArray
// =================================================
void __thiscall
CFastArray<class_GmVec4>::CopyFromFastArray
          (void *this,CFastArray<class_GmVec4> *param_1,CFastArray<class_GmVec4> *param_2)
{
{
  CFastBuffer<class_CSystemFidsFolder*> *pCVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<class_CSystemFidsFolder*> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(param_1,unaff_EDI);
  CFastArray<struct_CMotionTrackMobilPitchin::SurfacePoint>::SetCount(this,pCVar1,unaff_ESI);
  if (pCVar1 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
    iVar4 = 0;
    do {
      iVar2 = *(int *)(param_1 + 4) + iVar4;
      puVar3 = (undefined4 *)(*(int *)((int)this + 4) + iVar4);
      *puVar3 = *(undefined4 *)(*(int *)(param_1 + 4) + iVar4);
      puVar3[1] = *(undefined4 *)(iVar2 + 4);
      puVar3[2] = *(undefined4 *)(iVar2 + 8);
      iVar4 = iVar4 + 0x10;
      pCVar1 = pCVar1 + -1;
      puVar3[3] = *(undefined4 *)(iVar2 + 0xc);
    } while (pCVar1 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0);
  }
  return;
}
}

