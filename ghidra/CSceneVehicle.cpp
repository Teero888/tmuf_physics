
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

/* public: void __thiscall CSceneVehicle::SSurfaceHandler::Reset(void) */

void __thiscall CSceneVehicle::SSurfaceHandler::Reset(SSurfaceHandler *this)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;

  puVar2 = (undefined4 *)(this + 4);
  puVar3 = (undefined4 *)(this + 0x34);
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}

/* public: __thiscall CSceneVehicle::SSurfaceHandler::SSurfaceHandler(void) */

SSurfaceHandler *__thiscall CSceneVehicle::SSurfaceHandler::SSurfaceHandler(
    SSurfaceHandler *this)

{
  *(undefined4 *)this = 0;
  GmIso4::SetIdentity((GmIso4 *)(this + 4));
  GmIso4::SetIdentity((GmIso4 *)(this + 0x34));
  return this;
}

/* public: void __thiscall CSceneVehicle::SSurfaceHandler::UpdateSurface(void)
 */

void __thiscall CSceneVehicle::SSurfaceHandler::UpdateSurface(
    SSurfaceHandler *this)

{
  if (*(CPlugTree **)this != (CPlugTree *)0x0) {
    CPlugTree::SetLocation(*(CPlugTree **)this, (GmIso4 *)(this + 0x34));
  }
  return;
}
