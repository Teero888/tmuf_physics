
/* public: __thiscall CSceneVehicle::SSurfaceHandler::SSurfaceHandler(void) */

SSurfaceHandler *__thiscall CSceneVehicle::SSurfaceHandler::SSurfaceHandler(
    SSurfaceHandler *this)

{
  *(undefined4 *)this = 0;
  GmIso4::SetIdentity((GmIso4 *)(this + 4));
  GmIso4::SetIdentity((GmIso4 *)(this + 0x34));
  return this;
}
