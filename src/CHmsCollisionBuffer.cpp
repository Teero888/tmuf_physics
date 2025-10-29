
/* public: virtual class GmCollision & __thiscall
 * CHmsCollisionBuffer::AddCollision(void) */

GmCollision *__thiscall CHmsCollisionBuffer::AddCollision(
    CHmsCollisionBuffer *this)

{
  SHmsPhysicalCollision *pSVar1;

  pSVar1 = CFastBuffer<>::AddNewElem((CFastBuffer<> *)(this + 4));
  return (GmCollision *)(pSVar1 + 0x10);
}

/* public: __thiscall CHmsCollisionBuffer::CHmsCollisionBuffer(void) */

CHmsCollisionBuffer *__thiscall CHmsCollisionBuffer::CHmsCollisionBuffer(
    CHmsCollisionBuffer *this)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00a954db;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(this + 4));
  local_4 = 0;
  CFastBuffer<>::SetSizeAtLeast((CFastBuffer<> *)(CFastBuffer<> *)(this + 4),
                                0x32);
  ExceptionList = local_c;
  return this;
}

/* public: virtual class GmCollision & __thiscall
 * CHmsCollisionBuffer::GetCollision(unsigned long)
 */

GmCollision *__thiscall CHmsCollisionBuffer::GetCollision(
    CHmsCollisionBuffer *this, ulong param_1)

{
  SHmsPhysicalCollision *pSVar1;

  pSVar1 = CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 4), param_1);
  return (GmCollision *)(pSVar1 + 0x10);
}
