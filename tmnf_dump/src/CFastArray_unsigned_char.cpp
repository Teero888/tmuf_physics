// Class implementation: CFastArray_unsigned_char

// =================================================
// Function: CFastArray<unsigned_char>::InitValue
// =================================================
void __thiscall
CFastArray<unsigned_char>::InitValue
          (void *this,CFastArray<class_CSystemFidFile*> *param_1,CSystemFidFile **param_2)
{
{
  uint uVar1;
  
  uVar1 = 0;
  if (*(int *)this != 0) {
    do {
      *(CFastArray<class_CSystemFidFile*> *)(uVar1 + *(int *)((int)this + 4)) = *param_1;
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)this);
  }
  return;
}
}

