// Class implementation: SManialinkFormat

// =================================================
// Function: SManialinkFormat::SManialinkFormat
// =================================================
void __thiscall SManialinkFormat::SManialinkFormat(void *this,SManialinkFormat *param_1)
{
{
  CMwNod *this_00;
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)((int)this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)((int)this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)((int)this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)((int)this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)((int)this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)((int)this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)((int)this + 0x34) = 0;
  this_00 = *(CMwNod **)(param_1 + 0x34);
  if (this_00 != (CMwNod *)0x0) {
    CMwNod::MwAddRef(this_00,unaff_EDI);
    if (*(CMwNod **)((int)this + 0x34) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)((int)this + 0x34),unaff_ESI);
    }
    *(CMwNod **)((int)this + 0x34) = this_00;
  }
  return;
}
}

