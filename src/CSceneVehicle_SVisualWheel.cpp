// Class implementation: CSceneVehicle_SVisualWheel

// =================================================
// Function: CSceneVehicle::SVisualWheel::Reset
// =================================================
void __thiscall CSceneVehicle::SVisualWheel::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  int extraout_EAX;
  int extraout_EAX_00;
  GmFrustumIso4 *unaff_retaddr;
  GmFrustumIso4 *in_stack_0000000c;
  
  SVisualHandler::Reset((void *)((int)this + 8),unaff_retaddr);
  SVisualHandler::Reset((void *)(extraout_EAX + 0x74),param_1);
  SVisualHandler::Reset((void *)(extraout_EAX_00 + 0xe0),in_stack_0000000c);
  return;
}
}

// =================================================
// Function: CSceneVehicle::SVisualWheel::SVisualWheel
// =================================================
void __thiscall CSceneVehicle::SVisualWheel::SVisualWheel(void *this,SVisualWheel *param_1)
{
{
  SVisualHandler *unaff_ESI;
  SVisualHandler *unaff_retaddr;
  SVisualHandler *in_stack_00000008;
  GmFrustumIso4 *in_stack_0000000c;
  
  SVisualHandler::SVisualHandler((void *)((int)this + 8),unaff_ESI);
  SVisualHandler::SVisualHandler((void *)((int)this + 0x74),unaff_retaddr);
  SVisualHandler::SVisualHandler((void *)((int)this + 0xe0),(SVisualHandler *)param_1);
  SVisualHandler::SVisualHandler((void *)((int)this + 0x14c),in_stack_00000008);
  *(undefined4 *)this = 0xffffffff;
  Reset(this,in_stack_0000000c);
  return;
}
}

