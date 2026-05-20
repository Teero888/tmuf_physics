// Class implementation: SPlugVisibleFilterOptim

// =================================================
// Function: SPlugVisibleFilterOptim::IsIdRejected
// =================================================
int __thiscall
SPlugVisibleFilterOptim::IsIdRejected
          (void *this,SPlugVisibleFilterOptim *param_1,SPlugVisibleId *param_2)
{
{
  if ((*(ushort *)this != 0) &&
     (*(ushort *)((int)this + 2) != (*(ushort *)param_1 & *(ushort *)this))) {
    return 1;
  }
  return 0;
}
}

