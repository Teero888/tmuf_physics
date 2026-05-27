// Class implementation: private_void_thiscall_CTrackManiaRaceInterface

// =================================================
// Function: SDownloadProgress::GetCurProgress
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
`private:_void___thiscall_CTrackManiaRaceInterface::UpdateDownloadProgress(void)'::__l2::
SDownloadProgress::GetCurProgress(void *this,SDownloadProgress *param_1)
{
{
  int iVar1;
  float fVar2;
  float fVar3;
  
  iVar1 = *(int *)((int)this + 0xc);
  if (iVar1 == 0) {
    return 1.0;
  }
  fVar2 = (float)*(int *)((int)this + 8);
  if (*(int *)((int)this + 8) < 0) {
    fVar2 = fVar2 + _DAT_00c418d0;
  }
  fVar3 = (float)iVar1;
  if (iVar1 < 0) {
    fVar3 = fVar3 + _DAT_00c418d0;
  }
  return fVar2 / fVar3;
}
}

// =================================================
// Function: SDownloadProgress::GetTotalProgress
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
`private:_void___thiscall_CTrackManiaRaceInterface::UpdateDownloadProgress(void)'::__l2::
SDownloadProgress::GetTotalProgress(void *this,SDownloadProgress *param_1)
{
{
  int iVar1;
  float fVar2;
  float fVar3;
  
  iVar1 = *(int *)this;
  if (iVar1 == 0) {
    return 1.0;
  }
  fVar2 = (float)*(int *)((int)this + 4);
  if (*(int *)((int)this + 4) < 0) {
    fVar2 = fVar2 + _DAT_00c418d0;
  }
  fVar3 = (float)iVar1;
  if (iVar1 < 0) {
    fVar3 = fVar3 + _DAT_00c418d0;
  }
  return fVar2 / fVar3;
}
}

// =================================================
// Function: SDownloadProgress::SDownloadProgress
// =================================================
void __thiscall
`private:_void___thiscall_CTrackManiaRaceInterface::UpdateDownloadProgress(void)'::__l2::
SDownloadProgress::SDownloadProgress(void *this,SDownloadProgress *param_1)
{
{
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  return;
}
}

