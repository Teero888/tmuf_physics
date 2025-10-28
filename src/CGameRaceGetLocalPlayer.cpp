
/* public: class CGamePlayer * __thiscall CGameRace::GetLocalPlayer(void)const
 */

CGamePlayer *__thiscall CGameRace::GetLocalPlayer(CGameRace *this)

{
  CGamePlayerInfo *pCVar1;

  pCVar1 = GetLocalPlayerInfo(this);
  return *(CGamePlayer **)(pCVar1 + 0x238);
}
