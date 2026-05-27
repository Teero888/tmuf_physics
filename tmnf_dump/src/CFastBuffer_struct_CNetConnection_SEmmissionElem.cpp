// Class implementation: CFastBuffer_struct_CNetConnection_SEmmissionElem

// =================================================
// Function: CFastBuffer<struct_CNetConnection::SEmmissionElem>::RemoveAt
// =================================================
void __thiscall
CFastBuffer<struct_CNetConnection::SEmmissionElem>::RemoveAt
          (void *this,CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *param_1,
          ulong param_2,ulong param_3)
{
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = (*(int *)this - (int)param_1) - param_2;
  if (iVar4 != 0) {
    iVar6 = (int)param_1 * 0xc;
    iVar5 = (int)(param_1 + param_2) * 0xc;
    do {
      iVar2 = *(int *)((int)this + 4);
      iVar1 = iVar5 + iVar2;
      puVar3 = (undefined4 *)(iVar2 + iVar6);
      *puVar3 = *(undefined4 *)(iVar5 + iVar2);
      puVar3[1] = *(undefined4 *)(iVar1 + 4);
      iVar5 = iVar5 + 0xc;
      iVar6 = iVar6 + 0xc;
      iVar4 = iVar4 + -1;
      puVar3[2] = *(undefined4 *)(iVar1 + 8);
    } while (iVar4 != 0);
  }
  *(ulong *)this = *(int *)this - param_2;
  return;
}
}

