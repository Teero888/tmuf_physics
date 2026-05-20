// Class implementation: CGameCtnApp_SNationConfig

// =================================================
// Function: CGameCtnApp::SNationConfig::~SNationConfig
// =================================================
void __thiscall CGameCtnApp::SNationConfig::~SNationConfig(void *this,SNationConfig *param_1)
{
{
  undefined *puVar1;
  
  puVar1 = *(undefined **)((int)this + 4);
  if (puVar1 != PTR_DAT_00bbf7dc) {
    if ((puVar1[-1] & 0x80) == 0) {
      puVar1 = puVar1 + -2;
    }
    else {
      puVar1 = puVar1 + -4;
    }
    operator_delete__(puVar1);
    *(undefined4 *)this = 0;
    *(undefined **)((int)this + 4) = PTR_DAT_00bbf7dc;
  }
  return;
}
}

