// Class implementation: CFastBuffer_class_CSystemPackDesc

// =================================================
// Function: >::ReleaseAll
// =================================================
void __thiscall
CFastBuffer<class_CSystemPackDesc*>::ReleaseAll
          (void *this,CFastBuffer<class_CSystemPackDesc*> *param_1)
{
{
  int iVar1;
  CMwNod *unaff_EDI;
  
  for (iVar1 = *(int *)this; iVar1 != 0; iVar1 = iVar1 + -1) {
    if (*(int *)(*(int *)((int)this + 4) + -4 + iVar1 * 4) != 0) {
      CMwNod::MwRelease(*(CMwNod **)(*(int *)((int)this + 4) + -4 + iVar1 * 4),unaff_EDI);
      *(undefined4 *)(*(int *)((int)this + 4) + -4 + iVar1 * 4) = 0;
    }
  }
  *(undefined4 *)this = 0;
  return;
}
}

