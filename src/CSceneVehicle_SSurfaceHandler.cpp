// Class implementation: CSceneVehicle_SSurfaceHandler

// =================================================
// Function: CSceneVehicle::SSurfaceHandler::Init
// =================================================
void __thiscall
CSceneVehicle::SSurfaceHandler::Init
          (void *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2,
          CVisionViewportDx9 *param_3,ESpriteColor0 *param_4)
{
{
  CPlugTree *pCVar1;
  int iVar2;
  GmMat43 *unaff_ESI;
  undefined4 *this_00;
  CMwId *unaff_EDI;
  undefined4 *puVar3;
  
  pCVar1 = CPlugSolid::GetPlugFromId((CPlugSolid *)param_1,(CPlugSolid *)param_2,unaff_EDI);
  *(CPlugTree **)this = pCVar1;
  this_00 = (undefined4 *)((int)this + 4);
  if (pCVar1 != (CPlugTree *)0x0) {
    pCVar1 = pCVar1 + 0x5c;
    puVar3 = this_00;
    for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *(undefined4 *)pCVar1;
      pCVar1 = pCVar1 + 4;
      puVar3 = puVar3 + 1;
    }
    puVar3 = (undefined4 *)((int)this + 0x34);
    for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *this_00;
      this_00 = this_00 + 1;
      puVar3 = puVar3 + 1;
    }
    return;
  }
  GmIso4::SetIdentity(this_00,unaff_ESI);
  puVar3 = (undefined4 *)((int)this + 0x34);
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *this_00;
    this_00 = this_00 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}
}

// =================================================
// Function: CSceneVehicle::SSurfaceHandler::Reset
// =================================================
void __thiscall CSceneVehicle::SSurfaceHandler::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)((int)this + 0x34);
  for (iVar1 = 0xc; this = (void *)((int)this + 4), iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *(undefined4 *)this;
    puVar2 = puVar2 + 1;
  }
  return;
}
}

// =================================================
// Function: CSceneVehicle::SSurfaceHandler::SSurfaceHandler
// =================================================
void __thiscall CSceneVehicle::SSurfaceHandler::SSurfaceHandler(void *this,SSurfaceHandler *param_1)
{
{
  GmMat43 *unaff_ESI;
  GmMat43 *unaff_retaddr;
  
  *(undefined4 *)this = 0;
  GmIso4::SetIdentity((void *)((int)this + 4),unaff_ESI);
  GmIso4::SetIdentity((void *)((int)this + 0x34),unaff_retaddr);
  return;
}
}

// =================================================
// Function: CSceneVehicle::SSurfaceHandler::UpdateSurface
// =================================================
void __thiscall CSceneVehicle::SSurfaceHandler::UpdateSurface(void *this,SSurfaceHandler *param_1)
{
{
  GmIso4 *unaff_retaddr;
  
  if (*(CPlugTree **)this != (CPlugTree *)0x0) {
    CPlugTree::SetLocation(*(CPlugTree **)this,(CPlugTree *)((int)this + 0x34),unaff_retaddr);
  }
  return;
}
}

