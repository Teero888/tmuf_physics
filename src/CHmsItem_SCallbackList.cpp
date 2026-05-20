// Class implementation: CHmsItem_SCallbackList

// =================================================
// Function: CHmsItem::SCallbackList::SCallbackList
// =================================================
void __thiscall CHmsItem::SCallbackList::SCallbackList(void *this,SCallbackList *param_1)
{
{
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  return;
}
}

// =================================================
// Function: CHmsItem::SCallbackList::~SCallbackList
// =================================================
void __thiscall CHmsItem::SCallbackList::~SCallbackList(void *this,SCallbackList *param_1)
{
{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    piVar1 = *(int **)((int)this + uVar2 * 4);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))();
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 6);
  return;
}
}

