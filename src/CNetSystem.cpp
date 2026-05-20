// Class implementation: CNetSystem

// =================================================
// Function: CNetSystem::Init
// =================================================
void __thiscall
CNetSystem::Init(void *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2,
                CVisionViewportDx9 *param_3,ESpriteColor0 *param_4)
{
{
  int iVar1;
  
  if ((DAT_00d5690c == 0) && (DAT_00d56aa0 = DAT_00d56aa0 + 1, DAT_00d56910 == 0)) {
    iVar1 = Ordinal_115(0x202,&DAT_00d56910);
    if (iVar1 != 0) {
      DAT_00d56910 = 0;
      LogSocketError(0);
      return;
    }
    if (((char)DAT_00d56910 != '\x02') || (DAT_00d56910._1_1_ != '\x02')) {
      Ordinal_116();
      DAT_00d56910 = 0;
      return;
    }
  }
  DAT_00d5690c = DAT_00d5690c + 1;
  return;
}
}

