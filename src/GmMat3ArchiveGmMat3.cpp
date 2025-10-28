
/* public: void __thiscall GmMat3::ArchiveGmMat3(class CClassicArchive &) */

void __thiscall GmMat3::ArchiveGmMat3(GmMat3 *this, CClassicArchive *param_1)

{
  CClassicArchive::DoReal(param_1, (float *)this, 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 4), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 8), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0xc), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x10), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x14), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x18), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x1c), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x20), 1);
  return;
}
