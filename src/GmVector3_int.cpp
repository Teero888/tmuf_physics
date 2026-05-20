// Class implementation: GmVector3_int

// =================================================
// Function: GmVector3<int>::Clamp
// =================================================
void __thiscall
GmVector3<int>::Clamp
          (void *this,GmVector3<int> *param_1,GmVector3<int> *param_2,GmVector3<int> *param_3)
{
{
  int iVar1;
  
  iVar1 = *(int *)param_1;
  if ((*(int *)this < iVar1) || (iVar1 = *(int *)param_2, iVar1 < *(int *)this)) {
    *(int *)this = iVar1;
  }
  iVar1 = *(int *)(param_1 + 4);
  if ((*(int *)((int)this + 4) < iVar1) ||
     (iVar1 = *(int *)(param_2 + 4), iVar1 < *(int *)((int)this + 4))) {
    *(int *)((int)this + 4) = iVar1;
  }
  iVar1 = *(int *)(param_1 + 8);
  if ((*(int *)((int)this + 8) < iVar1) ||
     (iVar1 = *(int *)(param_2 + 8), iVar1 < *(int *)((int)this + 8))) {
    *(int *)((int)this + 8) = iVar1;
  }
  return;
}
}

