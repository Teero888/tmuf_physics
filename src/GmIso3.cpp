
/* public: void __thiscall GmIso3::ArchiveGmIso3(class CClassicArchive &) */

void __thiscall GmIso3::ArchiveGmIso3(GmIso3 *this, CClassicArchive *param_1)

{
  CClassicArchive::DoReal(param_1, (float *)this, 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 4), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 8), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0xc), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x10), 1);
  CClassicArchive::DoReal(param_1, (float *)(this + 0x14), 1);
  return;
}

/* public: void __thiscall GmIso3::Mult(class GmIso3 const &) */

void __thiscall GmIso3::Mult(GmIso3 *this, GmIso3 *param_1)

{
  float fVar1;

  GmMat2::Mult((GmMat2 *)this, (GmMat2 *)param_1);
  fVar1 = *(float *)(this + 0x10);
  *(float *)(this + 0x10) = *(float *)(this + 0x14) * *(float *)(param_1 + 4) +
                            fVar1 * *(float *)param_1;
  *(float *)(this + 0x14) =
      *(float *)(this + 0x14) * *(float *)(param_1 + 0xc) +
      *(float *)(param_1 + 8) * fVar1;
  *(float *)(this + 0x10) =
      *(float *)(this + 0x10) + *(float *)(param_1 + 0x10);
  *(float *)(this + 0x14) =
      *(float *)(param_1 + 0x14) + *(float *)(this + 0x14);
  return;
}

/* public: void __thiscall GmIso3::MultInverse(class GmIso3 const &) */

void __thiscall GmIso3::MultInverse(GmIso3 *this, GmIso3 *param_1)

{
  GmIso3 local_18[24];

  SetInverse(local_18, param_1);
  Mult(this, local_18);
  return;
}

/* public: void __thiscall GmIso3::Set(class GmIso3 const &) */

void __thiscall GmIso3::Set(GmIso3 *this, GmIso3 *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  return;
}

/* public: void __thiscall GmIso3::SetIdentity(void) */

void __thiscall GmIso3::SetIdentity(GmIso3 *this)

{
  GmMat2::SetIdentity((GmMat2 *)this);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  return;
}

/* public: void __thiscall GmIso3::SetInverse(class GmIso3 const &) */

void __thiscall GmIso3::SetInverse(GmIso3 *this, GmIso3 *param_1)

{
  float fVar1;

  GmMat2::SetTranspose((GmMat2 *)this, (GmMat2 *)param_1);
  *(float *)(this + 0x10) = -*(float *)(param_1 + 0x10);
  *(float *)(this + 0x14) = -*(float *)(param_1 + 0x14);
  fVar1 = *(float *)(this + 0x10);
  *(float *)(this + 0x10) = *(float *)(this + 0x10) * *(float *)this +
                            *(float *)(this + 4) * *(float *)(this + 0x14);
  *(float *)(this + 0x14) = *(float *)(this + 0xc) * *(float *)(this + 0x14) +
                            *(float *)(this + 8) * fVar1;
  return;
}

/* public: void __thiscall GmIso3::SetMult(class GmIso3 const &,class GmIso3
 * const &) */

void __thiscall GmIso3::SetMult(GmIso3 *this, GmIso3 *param_1, GmIso3 *param_2)

{
  GmMat2::SetMult((GmMat2 *)this, (GmMat2 *)param_1, (GmMat2 *)param_2);
  *(float *)(this + 0x10) =
      *(float *)(param_1 + 0x10) * *(float *)param_2 +
      *(float *)(param_2 + 4) * *(float *)(param_1 + 0x14);
  *(float *)(this + 0x14) =
      *(float *)(param_2 + 0xc) * *(float *)(param_1 + 0x14) +
      *(float *)(param_2 + 8) * *(float *)(param_1 + 0x10);
  *(float *)(this + 0x10) =
      *(float *)(this + 0x10) + *(float *)(param_2 + 0x10);
  *(float *)(this + 0x14) =
      *(float *)(param_2 + 0x14) + *(float *)(this + 0x14);
  return;
}
