// Class implementation: CPlugFileText

// =================================================
// Function: CPlugFileText::CPlugFileText
// =================================================
void __thiscall CPlugFileText::CPlugFileText(CPlugFileText *this,CPlugFileText *param_1)
{
{
  SStringParam *unaff_ESI;
  undefined1 *local_10;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00ad9483;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CPlugFile::CPlugFile((CPlugFile *)this,(CPlugFile *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined **)(this + 0x18) = PTR_DAT_00bbf7d8;
  local_c = (void *)0x0;
  local_10 = &DAT_00b2c878;
  CFastString::SetString((CFastString *)(this + 0x14),(CFastStringInt *)&local_10,unaff_ESI);
  ExceptionList = local_4;
  return;
}
}

