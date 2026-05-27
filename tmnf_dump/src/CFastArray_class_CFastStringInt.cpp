// Class implementation: CFastArray_class_CFastStringInt

// =================================================
// Function: CFastArray<class_CFastStringInt>::InitValue
// =================================================
void __thiscall
CFastArray<class_CFastStringInt>::InitValue
          (void *this,CFastArray<class_CSystemFidFile*> *param_1,CSystemFidFile **param_2)
{
{
  SStringParam *unaff_EBX;
  uint uVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar1 = 0;
  if (*(int *)this != 0) {
    do {
      local_c = *(undefined4 *)(param_1 + 4);
      local_8 = *(undefined4 *)param_1;
      local_4 = 0;
      CFastStringInt::SetString
                ((void *)(*(int *)((int)this + 4) + uVar1 * 8),(CFastStringInt *)&local_c,unaff_EBX)
      ;
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)this);
  }
  return;
}
}

