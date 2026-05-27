// Class implementation: GxFogGlobal

// =================================================
// Function: GxFogGlobal::ArchiveFog
// =================================================
void __thiscall GxFogGlobal::ArchiveFog(void *this,GxFogGlobal *param_1,CClassicArchive *param_2)
{
{
  ulong unaff_ESI;
  
  *(uint *)((int)this + 0x18) = *(uint *)((int)this + 0x18) & 0xf;
  CClassicArchive::DoData((CClassicArchive *)param_1,this,(void *)0x1c,unaff_ESI);
  *(uint *)((int)this + 0x18) = *(uint *)((int)this + 0x18) & 0xf;
  return;
}
}

