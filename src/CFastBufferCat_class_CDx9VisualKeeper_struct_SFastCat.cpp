// Class implementation: CFastBufferCat_class_CDx9VisualKeeper_struct_SFastCat

// =================================================
// Function: struct_SFastCat>::SetParsingAll
// =================================================
ulong __thiscall
CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat>::SetParsingAll
          (void *this,CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat> *param_1)
{
{
  ulong uVar1;
  
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0xffffffff;
  *(undefined4 *)((int)this + 0x20) = *(undefined4 *)((int)this + 0x10);
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount
                    ((void *)((int)this + 0xc),(CFastBuffer<class_CCrystalFace*> *)param_1);
  return uVar1;
}
}

