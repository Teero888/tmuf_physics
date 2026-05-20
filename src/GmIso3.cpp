// Class implementation: GmIso3

// =================================================
// Function: GmIso3::ArchiveGmIso3
// =================================================
void __thiscall GmIso3::ArchiveGmIso3(void *this,GmIso3 *param_1,CClassicArchive *param_2)
{
{
  ulong unaff_EBX;
  ulong unaff_ESI;
  ulong unaff_EDI;
  ulong unaff_retaddr;
  
  CClassicArchive::DoReal((CClassicArchive *)param_1,this,(float *)0x1,unaff_EDI);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 4),(float *)0x1,unaff_ESI);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 8),(float *)0x1,unaff_EBX);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 0xc),(float *)0x1,
             unaff_retaddr);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 0x10),(float *)0x1,
             (ulong)param_1);
  CClassicArchive::DoReal
            ((CClassicArchive *)param_1,(CClassicArchive *)((int)this + 0x14),(float *)0x1,
             (ulong)param_2);
  return;
}
}

// =================================================
// Function: GmIso3::Mult
// =================================================
void __thiscall GmIso3::Mult(void *this,GmIso3 *param_1,GmIso3 *param_2)
{
{
  float fVar1;
  GmIso3 *unaff_EDI;
  
  GmMat2::Mult(this,param_1,unaff_EDI);
  fVar1 = *(float *)((int)this + 0x10);
  *(float *)((int)this + 0x10) =
       *(float *)((int)this + 0x14) * *(float *)(param_1 + 4) + fVar1 * *(float *)param_1;
  *(float *)((int)this + 0x14) =
       *(float *)((int)this + 0x14) * *(float *)(param_1 + 0xc) + *(float *)(param_1 + 8) * fVar1;
  *(float *)((int)this + 0x10) = *(float *)((int)this + 0x10) + *(float *)(param_1 + 0x10);
  *(float *)((int)this + 0x14) = *(float *)(param_1 + 0x14) + *(float *)((int)this + 0x14);
  return;
}
}

// =================================================
// Function: GmIso3::MultInverse
// =================================================
void __thiscall GmIso3::MultInverse(void *this,GmIso3 *param_1,GmIso3 *param_2)
{
{
  GmScaleTrans2 *unaff_ESI;
  GmIso3 *in_stack_ffffffe8;
  GmIso3 local_14 [20];
  
  SetInverse(&stack0xffffffe8,(GmScaleTrans2 *)param_1,unaff_ESI);
  Mult(this,local_14,in_stack_ffffffe8);
  return;
}
}

// =================================================
// Function: GmIso3::Set
// =================================================
void __thiscall GmIso3::Set(void *this,CMwCmdScriptVarBool *param_1,int param_2)
{
{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  return;
}
}

// =================================================
// Function: GmIso3::SetIdentity
// =================================================
void __thiscall GmIso3::SetIdentity(void *this,GmMat43 *param_1)
{
{
  GmMat43 *unaff_ESI;
  
  GmMat2::SetIdentity(this,unaff_ESI);
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  return;
}
}

// =================================================
// Function: GmIso3::SetInverse
// =================================================
void __thiscall GmIso3::SetInverse(void *this,GmScaleTrans2 *param_1,GmScaleTrans2 *param_2)
{
{
  float fVar1;
  GmMat2 *unaff_EDI;
  
  GmMat2::SetTranspose(this,(GmMat2 *)param_1,unaff_EDI);
  *(float *)((int)this + 0x10) = -*(float *)(param_1 + 0x10);
  *(float *)((int)this + 0x14) = -*(float *)(param_1 + 0x14);
  fVar1 = *(float *)((int)this + 0x10);
  *(float *)((int)this + 0x10) =
       *(float *)((int)this + 0x10) * *(float *)this +
       *(float *)((int)this + 4) * *(float *)((int)this + 0x14);
  *(float *)((int)this + 0x14) =
       *(float *)((int)this + 0xc) * *(float *)((int)this + 0x14) +
       *(float *)((int)this + 8) * fVar1;
  return;
}
}

// =================================================
// Function: GmIso3::SetMult
// =================================================
void __thiscall
GmIso3::SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3)
{
{
  GmIso4 *unaff_EDI;
  
  GmMat2::SetMult(this,param_1,param_2,unaff_EDI);
  *(float *)((int)this + 0x10) =
       *(float *)(param_1 + 0x10) * *(float *)param_2 +
       *(float *)(param_2 + 4) * *(float *)(param_1 + 0x14);
  *(float *)((int)this + 0x14) =
       *(float *)(param_2 + 0xc) * *(float *)(param_1 + 0x14) +
       *(float *)(param_2 + 8) * *(float *)(param_1 + 0x10);
  *(float *)((int)this + 0x10) = *(float *)((int)this + 0x10) + *(float *)(param_2 + 0x10);
  *(float *)((int)this + 0x14) = *(float *)(param_2 + 0x14) + *(float *)((int)this + 0x14);
  return;
}
}

