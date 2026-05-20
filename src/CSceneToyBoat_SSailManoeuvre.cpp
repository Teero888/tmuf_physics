// Class implementation: CSceneToyBoat_SSailManoeuvre

// =================================================
// Function: CSceneToyBoat::SSailManoeuvre::ManoeuvreGet
// =================================================
CManoeuvre * __thiscall
CSceneToyBoat::SSailManoeuvre::ManoeuvreGet(void *this,SSailManoeuvre *param_1)
{
{
  if (*(int *)this == 0) {
    return (CManoeuvre *)0x0;
  }
  return *(CManoeuvre **)(*(int *)(*(int *)this + 0x14) + 0xb4 + *(int *)((int)this + 4) * 4);
}
}

