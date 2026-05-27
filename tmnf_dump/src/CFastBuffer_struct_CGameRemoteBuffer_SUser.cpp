// Class implementation: CFastBuffer_struct_CGameRemoteBuffer_SUser

// =================================================
// Function: >::ReplaceByLastIfFound
// =================================================
void __thiscall
CFastBuffer<struct_CGameRemoteBuffer::SUser*>::ReplaceByLastIfFound
          (void *this,CFastBuffer<struct_CGameRemoteBuffer::SUser*> *param_1,SUser **param_2)
{
{
  int iVar1;
  GxTexCoordSet *unaff_ESI;
  
  iVar1 = CFastArray<class_CGameMenuFrame*>::Find
                    (this,(CFastArray<class_GxTexCoordSet> *)param_1,unaff_ESI);
  if (iVar1 != -1) {
    *(int *)this = *(int *)this + -1;
    *(undefined4 *)(*(int *)((int)this + 4) + iVar1 * 4) =
         *(undefined4 *)(*(int *)((int)this + 4) + *(int *)this * 4);
  }
  return;
}
}

