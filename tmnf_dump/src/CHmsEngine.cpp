// Class implementation: CHmsEngine

// =================================================
// Function: CHmsEngine::CHmsEngine
// =================================================
void __thiscall CHmsEngine::CHmsEngine(CHmsEngine *this,CHmsEngine *param_1)
{
{
  CFastStringInt *unaff_ESI;
  CMwId *unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a96353;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CMwEngine::CMwEngine((CMwEngine *)this,(CMwEngine *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  *(undefined ***)this = vftable;
  CMwId::CMwId(this + 0x24,unaff_EDI);
  *(undefined4 *)(this + 0x20) = 0x6005000;
  CMwId::SetLocalName(this + 0x24,(CMwId *)"PackedVisual",unaff_ESI);
  ExceptionList = (void *)0x0;
  return;
}
}

