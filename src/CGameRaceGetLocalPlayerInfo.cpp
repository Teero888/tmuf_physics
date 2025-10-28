
/* public: class CGamePlayerInfo * __thiscall
 * CGameRace::GetLocalPlayerInfo(void)const  */

CGamePlayerInfo *__thiscall CGameRace::GetLocalPlayerInfo(CGameRace *this)

{
  int iVar1;
  CGamePlayerInfo **ppCVar2;

  if (*(int **)(this + 0x18) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(this + 0x18) + 0x118))();
    if (iVar1 != 0) {
      iVar1 = (**(code **)(**(int **)(this + 0x18) + 0x118))();
      ppCVar2 = (CGamePlayerInfo **)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(iVar1 + 0x2fc), 0);
      return *ppCVar2;
    }
  }
  return (CGamePlayerInfo *)0x0;
}
