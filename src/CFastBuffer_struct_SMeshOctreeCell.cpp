// Class implementation: CFastBuffer_struct_SMeshOctreeCell

// =================================================
// Function: CFastBuffer<struct_SMeshOctreeCell>::ArchiveCount
// =================================================
void __thiscall
CFastBuffer<struct_SMeshOctreeCell>::ArchiveCount
          (void *this,CFastArray<class_CPlugFileSnd*> *param_1,CClassicArchive *param_2)
{
{
  CFastBuffer<struct_SMeshOctreeCell> *pCVar1;
  ulong unaff_ESI;
  int unaff_EDI;
  
  CClassicArchive::DoNatural((CClassicArchive *)param_1,this,(ulong *)0x1,0,unaff_EDI);
  if (*(uint *)this != 0) {
    if ((0x10000000 < *(uint *)this) && (DAT_00d72e8c != (code *)0x0)) {
      (*DAT_00d72e8c)();
    }
    if (*(int *)(param_1 + 8) == 0) {
      pCVar1 = *(CFastBuffer<struct_SMeshOctreeCell> **)this;
      operator_delete__(*(void **)((int)this + 4));
      *(undefined4 *)((int)this + 4) = 0;
      *(undefined4 *)((int)this + 8) = 0;
      *(undefined4 *)this = 0;
      InitSize(this,pCVar1,unaff_ESI);
      *(CFastBuffer<struct_SMeshOctreeCell> **)this = pCVar1;
    }
  }
  return;
}
}

// =================================================
// Function: CFastBuffer<struct_SMeshOctreeCell>::ArchiveFastBuffer
// =================================================
void __thiscall
CFastBuffer<struct_SMeshOctreeCell>::ArchiveFastBuffer
          (void *this,CFastBuffer<class_CGameCtnChallengeGroup*> *param_1,CClassicArchive *param_2)
{
{
  CFastBuffer<struct_SMeshOctreeCell> *pCVar1;
  int unaff_ESI;
  int unaff_EDI;
  ulong uVar2;
  
  uVar2 = 10;
  CClassicArchive::DoNatural
            ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xfffffffc,(ulong *)0x1,0,unaff_EDI
            );
  CClassicArchive::DoNatural((CClassicArchive *)param_1,this,(ulong *)0x1,0,unaff_ESI);
  if (*(uint *)this != 0) {
    if ((0x10000000 < *(uint *)this) && (DAT_00d72e8c != (code *)0x0)) {
      (*DAT_00d72e8c)();
    }
    if (*(int *)(param_1 + 8) == 0) {
      pCVar1 = *(CFastBuffer<struct_SMeshOctreeCell> **)this;
      operator_delete__(*(void **)((int)this + 4));
      *(undefined4 *)((int)this + 4) = 0;
      *(undefined4 *)((int)this + 8) = 0;
      *(undefined4 *)this = 0;
      InitSize(this,pCVar1,uVar2);
      *(CFastBuffer<struct_SMeshOctreeCell> **)this = pCVar1;
    }
  }
  return;
}
}

