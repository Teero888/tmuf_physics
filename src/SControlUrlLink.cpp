// Class implementation: SControlUrlLink

// =================================================
// Function: SControlUrlLink::SControlUrlLink
// =================================================
void __thiscall SControlUrlLink::SControlUrlLink(void *this,SControlUrlLink *param_1)
{
{
  TiXmlNode *pTVar1;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_8 = &LAB_00a9c258;
  local_c = ExceptionList;
  pTVar1 = (TiXmlNode *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  *(undefined4 *)this = 0;
  *(undefined **)((int)this + 4) = PTR_DAT_00bbf7dc;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined **)((int)this + 0x14) = PTR_DAT_00bbf7dc;
  local_4 = 0;
  SPlugUrlLink::Clear(this,pTVar1);
  *(undefined4 *)((int)this + 0x20) = 0;
  ExceptionList = local_8;
  return;
}
}

