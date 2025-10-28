
/* public: void __thiscall CSceneVehicle::SSurfaceHandler::Init(class CPlugSolid
   const &,struct SSurfaceId const &) */

void __thiscall CSceneVehicle::SSurfaceHandler::Init(SSurfaceHandler *this,
                                                     CPlugSolid *param_1,
                                                     SSurfaceId *param_2)

{
  CPlugTree *pCVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *this_00;
  undefined4 *puVar4;

  pCVar1 = CPlugSolid::GetPlugFromId(param_1, (CMwId *)param_2);
  *(CPlugTree **)this = pCVar1;
  this_00 = (undefined4 *)(this + 4);
  if (pCVar1 != (CPlugTree *)0x0) {
    puVar3 = (undefined4 *)(pCVar1 + 0x5c);
    puVar4 = this_00;
    for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    puVar3 = (undefined4 *)(this + 0x34);
    for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *this_00;
      this_00 = this_00 + 1;
      puVar3 = puVar3 + 1;
    }
    return;
  }
  GmIso4::SetIdentity((GmIso4 *)this_00);
  puVar3 = (undefined4 *)(this + 0x34);
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *this_00;
    this_00 = this_00 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}
