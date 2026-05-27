// Class implementation: GxDXT1_Block

// =================================================
// Function: GxDXT1_Block::GetTexel
// =================================================
GxDXT1_Block * __thiscall
GxDXT1_Block::GetTexel(void *this,GxDXT1_Block *param_1,ulong param_2,ulong param_3)
{
{
  uint uVar1;
  
  uVar1 = *(byte *)(param_3 + 4 + (int)this) >> ((char)param_2 * '\x02' & 0x1fU) & 3;
  if (uVar1 < 2) {
    GxBGRColor565::Get32b((void *)((int)this + uVar1 * 2),(GxBGRColor565 *)param_1);
    return param_1;
  }
  if (*(ushort *)this < *(ushort *)((int)this + 2)) {
    if (uVar1 == 3) {
      *(undefined4 *)param_1 = 0;
      return param_1;
    }
    GxBGRColor565::Get32b(this,(GxBGRColor565 *)&param_2);
    GxBGRColor565::Get32b((void *)((int)this + 2),(GxBGRColor565 *)&param_3);
    *(ulong *)param_1 =
         (param_3 & 0xff) + (param_2 & 0xff) >> 1 |
         (param_2 >> 1 & 0x7f8000) + (param_3 >> 1 & 0x7f8000) & 0xffff0000 |
         (param_2 >> 1 & 0x7f80) + (param_3 >> 1 & 0x7f80) & 0xff00 | 0xff000000;
    return param_1;
  }
  GxBGRColor565::Get32b((void *)((int)this + uVar1 * 2 + -4),(GxBGRColor565 *)&param_3);
  GxBGRColor565::Get32b((void *)((int)this + (uVar1 - 1 & 1) * 2),(GxBGRColor565 *)&param_2);
  *(uint *)param_1 =
       ((((param_2 >> 0x10 & 0xff) + (param_3 >> 0x10 & 0xff) * 2) / 3 | 0xffffff00) << 8 |
       ((param_2 >> 8 & 0xff) + (param_3 >> 8 & 0xff) * 2) / 3 & 0xff) << 8 |
       ((param_2 & 0xff) + (param_3 & 0xff) * 2) / 3 & 0xff;
  return param_1;
}
}

