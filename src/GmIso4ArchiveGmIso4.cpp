
/* public: void __thiscall GmIso4::ArchiveGmIso4(class CClassicArchive &) */

void __thiscall GmIso4::ArchiveGmIso4(GmIso4 *this, CClassicArchive *param_1)

{
  GmMat3::ArchiveGmMat3((GmMat3 *)this, param_1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x24), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x28), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x2c), 1);
  return;
}
