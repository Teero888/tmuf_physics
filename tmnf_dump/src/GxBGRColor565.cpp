// Class implementation: GxBGRColor565

// =================================================
// Function: GxBGRColor565::Get32b
// =================================================
GxBGRColor565 * __thiscall GxBGRColor565::Get32b(void *this,GxBGRColor565 *param_1)
{
{
  ushort uVar1;
  
  uVar1 = *(ushort *)this;
  *param_1 = SUB41(((uVar1 & 0x1f) * 0xff) / 0x1f,0);
  param_1[1] = SUB41(((uVar1 >> 5 & 0x3f) * 0xff) / 0x3f,0);
  param_1[2] = SUB41(((uint)(uVar1 >> 0xb) * 0xff) / 0x1f,0);
  return param_1;
}
}

// =================================================
// Function: GxBGRColor565::SetRGB8
// =================================================
void __thiscall
GxBGRColor565::SetRGB8(void *this,GxBGRColor565 *param_1,uchar param_2,uchar param_3,uchar param_4)
{
{
  *(ushort *)this =
       (ushort)((((uint)param_2 * 0x3f) / 0xff & 0x3f |
                ((((uint)param_1 & 0xff) * 0x1f) / 0xff) * 0x40) << 5) |
       (ushort)(((uint)param_3 * 0x1f) / 0xff) & 0x1f;
  return;
}
}

