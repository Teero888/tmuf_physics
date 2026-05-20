// Class implementation: CFastBuffer_class_CGameNetPlayerInfo

// =================================================
// Function: >::FindKey<unsigned_char>
// =================================================
ulong __thiscall
CFastBuffer<class_CGameNetPlayerInfo*>::FindKey<unsigned_char>
          (void *this,CFastBuffer<class_CGameNetPlayerInfo*> *param_1,
          SFastKey<class_CGameNetPlayerInfo*,unsigned_char> *param_2)
{
{
  int iVar1;
  ulong uVar2;
  
  uVar2 = 0;
  if (*(int *)this != 0) {
    do {
      iVar1 = (**(code **)(param_1 + 4))(param_1,*(int *)((int)this + 4) + uVar2 * 4);
      if (iVar1 == 0) {
        return uVar2;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)this);
  }
  return 0xffffffff;
}
}

