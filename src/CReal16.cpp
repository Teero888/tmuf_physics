// Class implementation: CReal16

// =================================================
// Function: CReal16::CReal16
// =================================================
void __thiscall CReal16::CReal16(void *this,CReal16 *param_1,float param_2)
{
{
  short sVar1;
  
  if ((float)param_1 == 0.0) {
    *(undefined2 *)this = 0;
    return;
  }
  if (*(short *)(&DAT_00c410c8 + ((uint)param_1 >> 0x17) * 2) != 0) {
    *(short *)this =
         (short)(((uint)param_1 & 0x7fffff) + 0x1000 >> 0xd) +
         *(short *)(&DAT_00c410c8 + ((uint)param_1 >> 0x17) * 2);
    return;
  }
  sVar1 = Convert((int)param_1);
  *(short *)this = sVar1;
  return;
}
}

