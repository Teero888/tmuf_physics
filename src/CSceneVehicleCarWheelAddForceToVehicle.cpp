
/* protected: void __thiscall CSceneVehicleCar::WheelAddForceToVehicle(struct
   CSceneVehicleCar::SSimulationWheel &,class GmVec3 const &) */

void __thiscall CSceneVehicleCar::WheelAddForceToVehicle(
    CSceneVehicleCar *this, SSimulationWheel *param_1, GmVec3 *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  undefined4 local_4;

  iVar1 = *(int *)(this + 100);
  piVar3 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                            *(ulong *)(iVar1 + 0x24));
  iVar2 = *(int *)(*piVar3 + 0x350);
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x124) != 0) {
      local_24 = 0.0;
      local_20 = 1.0;
      local_1c = 0.0;
      piVar3 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                                *(ulong *)(iVar1 + 0x24));
      piVar4 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                                *(ulong *)(iVar1 + 0x24));
      piVar5 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                                *(ulong *)(iVar1 + 0x24));
      local_20 = *(float *)(*piVar4 + 0x114) * *(float *)(*piVar3 + 0x128) *
                 (*(float *)(*piVar5 + 0x124) - *(float *)(param_1 + 0xb4));
      local_24 = local_20 * 0.0;
      local_1c = local_24;
      AddVehicleForce(this, (GmVec3 *)&local_24, (GmVec3 *)(param_1 + 0xa8));
    }
  } else if (iVar2 == 1) {
    if (*(int *)(param_1 + 0x124) != 0) {
      piVar3 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                                *(ulong *)(iVar1 + 0x24));
      piVar4 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                                *(ulong *)(iVar1 + 0x24));
      piVar5 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                                *(ulong *)(iVar1 + 0x24));
      local_8 = (*(float *)(*piVar3 + 0x124) - *(float *)(param_1 + 0xb4)) *
                    *(float *)(*piVar4 + 0x114) -
                *(float *)(*piVar5 + 0x118) * *(float *)(param_1 + 0xb8);
      local_c = 0;
      local_4 = 0;
      AddVehicleForce(this, (GmVec3 *)&local_c, (GmVec3 *)(param_1 + 0xa8));
      return;
    }
  } else if ((iVar2 == 2) && (*(int *)(param_1 + 0x124) != iVar2 + -2)) {
    piVar3 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                              *(ulong *)(iVar1 + 0x24));
    piVar4 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                              *(ulong *)(iVar1 + 0x24));
    piVar5 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar1 + 0x14),
                                              *(ulong *)(iVar1 + 0x24));
    local_14 = (*(float *)(*piVar3 + 0x124) - *(float *)(param_1 + 0xb4)) *
                   *(float *)(*piVar4 + 0x114) -
               *(float *)(*piVar5 + 0x118) * *(float *)(param_1 + 0xb8);
    local_18 = 0;
    local_10 = 0;
    AddVehicleForce(this, (GmVec3 *)&local_18, (GmVec3 *)(param_1 + 0xa8));
    return;
  }
  return;
}
