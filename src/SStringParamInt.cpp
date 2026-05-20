// Class implementation: SStringParamInt

// =================================================
// Function: SStringParamInt::SStringParamInt
// =================================================
void __thiscall
SStringParamInt::SStringParamInt(void *this,SStringParamInt *param_1,wchar_t *param_2)
{
{
  *(undefined4 *)this = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 4) = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 8) = 0;
  return;
}
}

