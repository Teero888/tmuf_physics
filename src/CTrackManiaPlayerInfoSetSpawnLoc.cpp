
/* public: void __thiscall CTrackManiaPlayerInfo::SetSpawnLoc(class GmIso4 const
 * &,int) */

void __thiscall CTrackManiaPlayerInfo::SetSpawnLoc(CTrackManiaPlayerInfo *this,
                                                   GmIso4 *param_1, int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;

  puVar2 = (undefined4 *)param_1;
  puVar3 = (undefined4 *)(this + 0x274);
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  if (param_2 != 0) {
    puVar2 = (undefined4 *)(this + 0x244);
    for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *(undefined4 *)param_1;
      param_1 = (GmIso4 *)((int)param_1 + 4);
      puVar2 = puVar2 + 1;
    }
  }
  return;
}
