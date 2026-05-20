// Class implementation: CNetArchive

// =================================================
// Function: CNetArchive::CNetArchive
// =================================================
void __thiscall CNetArchive::CNetArchive(CNetArchive *this,CNetArchive *param_1)
{
{
  CClassicArchive *unaff_ESI;
  
  CClassicArchive::CClassicArchive((CClassicArchive *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0xc) = 0;
  return;
}
}

// =================================================
// Function: CNetArchive::EndReading
// =================================================
void __thiscall
CNetArchive::EndReading(CNetArchive *this,CPlugFileOggVorbis *param_1,SStreamContext **param_2)
{
{
  int unaff_retaddr;
  
  CClassicArchive::DetachBuffer((CClassicArchive *)this,(CClassicArchive *)0x1,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CNetArchive::StartReading
// =================================================
SStreamContext * __thiscall CNetArchive::StartReading(CNetArchive *this,CPlugFileOggVorbis *param_1)
{
{
  SStreamContext *extraout_EAX;
  SStreamContext *extraout_EAX_00;
  SStreamContext *pSVar1;
  GmFrustumIso4 *unaff_ESI;
  CPlugVisual *unaff_EDI;
  int in_stack_0000000c;
  
  CVisionVisualKeeper::SetVisual
            ((CVisionVisualKeeper *)this,(CVisionVisualKeeper *)param_1,unaff_EDI);
  pSVar1 = extraout_EAX;
  if (in_stack_0000000c != 0) {
    CClassicBufferMemory::Reset((CClassicBufferMemory *)param_1,unaff_ESI);
    pSVar1 = extraout_EAX_00;
  }
  *(undefined4 *)(this + 8) = 0;
  return pSVar1;
}
}

// =================================================
// Function: CNetArchive::StartStoring
// =================================================
void __thiscall
CNetArchive::StartStoring
          (CNetArchive *this,CNetArchive *param_1,CClassicBufferMemory *param_2,int param_3)
{
{
  CClassicBufferMemory *unaff_ESI;
  CPlugVisual *unaff_EDI;
  
  CVisionVisualKeeper::SetVisual
            ((CVisionVisualKeeper *)this,(CVisionVisualKeeper *)param_1,unaff_EDI);
  if (param_3 != 0) {
    CClassicBufferMemory::Empty((CClassicBufferMemory *)param_1,unaff_ESI);
  }
  *(undefined4 *)(this + 8) = 1;
  return;
}
}

