
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
