// Class implementation: SStreamDeclComp

// =================================================
// Function: SStreamDeclComp::GetPlugRegType
// =================================================
EPlugVDclType __thiscall
SStreamDeclComp::GetPlugRegType(void *this,SStreamDeclComp *param_1,EPlugVDcl param_2)
{
{
  uint uVar1;
  
  uVar1 = *(uint *)this;
  if (param_1 == (SStreamDeclComp *)0x3) {
    return (uVar1 >> 3 & 3) - 1;
  }
  if ((-1 < (int)uVar1) ||
     ((((param_1 != (SStreamDeclComp *)&DAT_00000005 &&
        (param_1 != (SStreamDeclComp *)&DAT_00000006)) &&
       (param_1 != (SStreamDeclComp *)&DAT_00000012)) &&
      (((param_1 != (SStreamDeclComp *)&DAT_00000014 &&
        (param_1 != (SStreamDeclComp *)&DAT_00000013)) && (param_1 != (SStreamDeclComp *)0x15))))))
  {
    if (param_1 + -10 < (SStreamDeclComp *)&DAT_00000008) {
      return (uVar1 >> ((char)param_1 * '\x02' - 0x14U & 0x1f)) >> 0xb & 3;
    }
    return *(EPlugVDclType *)(&DAT_00d142c8 + (int)param_1 * 4);
  }
  if (DAT_00d77b08 != 0) {
    if (DAT_00d77b08 == 1) {
      return 10;
    }
    if (DAT_00d77b08 == 2) {
      return 0xe;
    }
  }
  return 2;
}
}

