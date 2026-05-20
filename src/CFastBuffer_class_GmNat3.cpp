// Class implementation: CFastBuffer_class_GmNat3

// =================================================
// Function: CFastBuffer<class_GmNat3>::Find
// =================================================
int __thiscall
CFastBuffer<class_GmNat3>::Find
          (void *this,CFastArray<class_GxTexCoordSet> *param_1,GxTexCoordSet *param_2)
{
{
  uint uVar1;
  int *piVar2;
  
  uVar1 = 0;
  if (*(uint *)this != 0) {
    piVar2 = *(int **)((int)this + 4);
    do {
      if (((*piVar2 == *(int *)param_1) && (piVar2[1] == *(int *)(param_1 + 4))) &&
         (piVar2[2] == *(int *)(param_1 + 8))) {
        return uVar1;
      }
      uVar1 = uVar1 + 1;
      piVar2 = piVar2 + 3;
    } while (uVar1 < *(uint *)this);
  }
  return -1;
}
}

