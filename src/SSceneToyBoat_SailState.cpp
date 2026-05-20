// Class implementation: SSceneToyBoat_SailState

// =================================================
// Function: SSceneToyBoat_SailState::SetFromSail
// =================================================
void __thiscall
SSceneToyBoat_SailState::SetFromSail
          (void *this,SSceneToyBoat_SailState *param_1,ESailType param_2,CBoatSailState *param_3)
{
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = 0;
  *(SSceneToyBoat_SailState **)this = param_1;
  if (param_2 == 0) {
    param_1 = (SSceneToyBoat_SailState *)0x0;
  }
  else {
    param_1 = *(SSceneToyBoat_SailState **)(param_2 + 0x84);
  }
  *(SSceneToyBoat_SailState **)((int)this + 0x10) = param_1;
  if (param_2 == 0) {
    param_1 = (SSceneToyBoat_SailState *)0x0;
  }
  else {
    param_1 = *(SSceneToyBoat_SailState **)(param_2 + 0x88);
  }
  *(SSceneToyBoat_SailState **)((int)this + 0x14) = param_1;
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(param_2 + 0x98);
  }
  *(undefined4 *)((int)this + 8) = uVar2;
  if (param_2 == 0) {
    uVar2 = 5;
  }
  else {
    uVar2 = *(undefined4 *)(param_2 + 0x8c);
  }
  *(undefined4 *)((int)this + 4) = uVar2;
  if (param_2 != 0) {
    uVar1 = *(undefined4 *)(param_2 + 0x90);
  }
  *(undefined4 *)((int)this + 0xc) = uVar1;
  return;
}
}

