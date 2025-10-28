
/* protected: void __thiscall CSceneVehicleCar::WheelIntegrate(struct
   CSceneVehicleCar::SSimulationWheel &,float) */

void __thiscall CSceneVehicleCar::WheelIntegrate(CSceneVehicleCar *this,
                                                 SSimulationWheel *param_1,
                                                 float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  float local_4;

  iVar9 = *(int *)(this + 100);
  piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar9 + 0x14),
                                            *(ulong *)(iVar9 + 0x24));
  iVar5 = *(int *)(*piVar6 + 0x350);
  if (iVar5 == 0) {
    *(float *)(param_1 + 0xb4) =
        *(float *)(param_1 + 0xb4) - *(float *)(param_1 + 0xbc);
    *(undefined4 *)(param_1 + 0xbc) = 0;
    iVar9 = *(int *)(this + 100);
    piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar9 + 0x14),
                                              *(ulong *)(iVar9 + 0x24));
    piVar7 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar9 + 0x14),
                                              *(ulong *)(iVar9 + 0x24));
    piVar8 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar9 + 0x14),
                                              *(ulong *)(iVar9 + 0x24));
    fVar1 = *(float *)(*piVar6 + 0x124);
    fVar2 = *(float *)(param_1 + 0xb4);
    fVar3 = *(float *)(*piVar7 + 0x114);
    fVar4 = *(float *)(*piVar8 + 0x118);
    puVar10 = (undefined4 *)(param_1 + 0x10);
    puVar11 = (undefined4 *)(param_1 + 0x40);
    for (iVar9 = 0xc; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar11 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar11 = puVar11 + 1;
    }
    fVar1 = *(float *)(param_1 + 0xb8) +
            param_2 *
                ((fVar1 - fVar2) * fVar3 - fVar4 * *(float *)(param_1 + 0xb8));
    *(float *)(param_1 + 0xb8) = fVar1;
    fVar1 = fVar1 * param_2 + *(float *)(param_1 + 0xb4);
    *(float *)(param_1 + 0xb4) = fVar1;
    fVar1 = -fVar1;
    local_4 = fVar1 * 0.0;
    *(float *)(param_1 + 100) = *(float *)(param_1 + 100) + local_4;
    fVar1 = fVar1 + *(float *)(param_1 + 0x68);
  } else {
    if (iVar5 != 1) {
      if (iVar5 == 2) {
        fVar1 = *(float *)(param_1 + 0xb4);
        fVar2 = *(float *)(param_1 + 0xbc);
        piVar6 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar9 + 0x14), *(ulong *)(iVar9 + 0x24));
        piVar7 = (int *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(iVar9 + 0x14), *(ulong *)(iVar9 + 0x24));
        fVar3 = *(float *)(*piVar6 + 0x124);
        fVar4 = *(float *)(*piVar7 + 0x194);
        puVar10 = (undefined4 *)(param_1 + 0x10);
        puVar11 = (undefined4 *)(param_1 + 0x40);
        for (iVar9 = 0xc; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar11 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar11 = puVar11 + 1;
        }
        fVar1 = fVar4 * param_2 * (fVar3 - (fVar1 - fVar2)) + (fVar1 - fVar2);
        *(float *)(param_1 + 0xb8) =
            param_2 / (fVar1 - *(float *)(param_1 + 0xb4));
        *(float *)(param_1 + 0xb4) = fVar1;
        *(undefined4 *)(param_1 + 0xbc) = 0;
        fVar2 = -fVar1 * 0.0;
        *(float *)(param_1 + 100) = fVar2 + *(float *)(param_1 + 100);
        *(float *)(param_1 + 0x68) = *(float *)(param_1 + 0x68) + -fVar1;
        *(float *)(param_1 + 0x6c) = fVar2 + *(float *)(param_1 + 0x6c);
        CSceneVehicle::SSurfaceHandler::UpdateSurface(
            (SSurfaceHandler *)(param_1 + 0xc));
        return;
      }
      goto LAB_007bd6c6;
    }
    fVar1 = *(float *)(param_1 + 0xb4);
    fVar2 = *(float *)(param_1 + 0xbc);
    piVar6 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar9 + 0x14),
                                              *(ulong *)(iVar9 + 0x24));
    piVar7 = (int *)CFastBuffer<>::operator[]((CFastBuffer<> *)(iVar9 + 0x14),
                                              *(ulong *)(iVar9 + 0x24));
    fVar3 = *(float *)(*piVar6 + 0x124);
    fVar4 = *(float *)(*piVar7 + 0x194);
    puVar10 = (undefined4 *)(param_1 + 0x10);
    puVar11 = (undefined4 *)(param_1 + 0x40);
    for (iVar9 = 0xc; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar11 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar11 = puVar11 + 1;
    }
    fVar1 = fVar4 * param_2 * (fVar3 - (fVar1 - fVar2)) + (fVar1 - fVar2);
    *(float *)(param_1 + 0xb8) = param_2 / (fVar1 - *(float *)(param_1 + 0xb4));
    *(float *)(param_1 + 0xb4) = fVar1;
    *(undefined4 *)(param_1 + 0xbc) = 0;
    local_4 = -fVar1 * 0.0;
    *(float *)(param_1 + 100) = local_4 + *(float *)(param_1 + 100);
    fVar1 = *(float *)(param_1 + 0x68) + -fVar1;
  }
  *(float *)(param_1 + 0x68) = fVar1;
  *(float *)(param_1 + 0x6c) = *(float *)(param_1 + 0x6c) + local_4;
LAB_007bd6c6:
  CSceneVehicle::SSurfaceHandler::UpdateSurface(
      (SSurfaceHandler *)(param_1 + 0xc));
  return;
}
