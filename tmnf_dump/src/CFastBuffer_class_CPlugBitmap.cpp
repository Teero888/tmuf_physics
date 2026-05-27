// Class implementation: CFastBuffer_class_CPlugBitmap

// =================================================
// Function: >::ReplaceByLast
// =================================================
void __thiscall
CFastBuffer<class_CPlugBitmap*>::ReplaceByLast
          (void *this,CFastBuffer<class_CPlugBitmap*> *param_1,CPlugBitmap **param_2)
{
{
  int iVar1;
  GxTexCoordSet *unaff_ESI;
  
  iVar1 = CFastArray<class_CGameMenuFrame*>::Find
                    (this,(CFastArray<class_GxTexCoordSet> *)param_1,unaff_ESI);
  *(int *)this = *(int *)this + -1;
  *(undefined4 *)(*(int *)((int)this + 4) + iVar1 * 4) =
       *(undefined4 *)(*(int *)((int)this + 4) + *(int *)this * 4);
  return;
}
}

