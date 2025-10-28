
/* protected: void __thiscall CSceneVehicleCar::AddVehicleForce(class GmVec3
   const &,class GmVec3 const &) */

void __thiscall CSceneVehicleCar::AddVehicleForce(CSceneVehicleCar *this,
                                                  GmVec3 *param_1,
                                                  GmVec3 *param_2)

{
  CHmsItem::AddForce(*(CHmsItem **)(this + 0x28), param_1, param_2);
  *(float *)(this + 0x818) = *(float *)(this + 0x818) + *(float *)param_1;
  *(float *)(this + 0x81c) = *(float *)(param_1 + 4) + *(float *)(this + 0x81c);
  *(float *)(this + 0x820) = *(float *)(param_1 + 8) + *(float *)(this + 0x820);
  return;
}
