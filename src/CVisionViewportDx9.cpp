// Class implementation: CVisionViewportDx9

// =================================================
// Function: CVisionViewportDx9::BitmapSpecularGetClose
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CPlugBitmap * __thiscall
CVisionViewportDx9::BitmapSpecularGetClose
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,float param_2,float param_3)
{
{
  CVisionViewportDx9 *pCVar1;
  code *pcVar2;
  byte bVar3;
  uint *puVar4;
  CPlugBitmap *pCVar5;
  byte *extraout_ECX;
  byte *pbVar6;
  byte bVar8;
  byte *in_EDX;
  int *piVar7;
  byte *unaff_EBX;
  uint unaff_EBP;
  int unaff_ESI;
  undefined4 *puVar9;
  undefined4 *puVar10;
  uint unaff_EDI;
  uint uVar11;
  char in_CF;
  byte in_AF;
  bool bVar12;
  undefined2 in_FPUControlWord;
  undefined2 in_FPUStatusWord;
  undefined2 in_FPUTagWord;
  undefined2 in_FPULastInstructionOpcode;
  undefined4 in_FPUDataPointer;
  undefined4 uVar13;
  undefined8 uVar14;
  
  bVar12 = false;
  bVar3 = (byte)((uint)unaff_EBX >> 8);
  *in_EDX = (*in_EDX - bVar3) - in_CF;
  *in_EDX = *in_EDX & bVar3;
  pcVar2 = (code *)swi(0x3a);
  uVar14 = (*pcVar2)();
  piVar7 = (int *)((ulonglong)uVar14 >> 0x20);
  *piVar7 = *piVar7 >> ((byte)extraout_ECX & 0x1f);
  *(undefined2 *)piVar7 = in_FPUControlWord;
  puVar4 = _DAT_3dd03d8c;
  uVar11 = unaff_EDI &
           *(uint *)CONCAT22((short)((uint)unaff_EBX >> 0x10),
                             CONCAT11(bVar3 | *unaff_EBX,(byte)unaff_EBX));
  in_AF = 9 < ((byte)uVar14 & 0xf) | in_AF;
  bVar3 = (byte)uVar14 + in_AF * -6;
  if ((int)unaff_EBP < *(int *)(unaff_ESI + 0x3b)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  LOCK();
  UNLOCK();
  uVar13 = 0x99c364;
  bVar8 = (byte)((ulonglong)uVar14 >> 0x28);
  if (SBORROW4(CONCAT31((int3)((ulonglong)uVar14 >> 8),
                        bVar3 + (0x9f < bVar3 | in_AF * (bVar3 < 6)) * -0x60),0x3d823d7a)) {
    LOCK();
    pCVar1 = *(CVisionViewportDx9 **)param_2;
    *(uint **)param_2 = _DAT_3dd03d8c;
    _DAT_3dd03d8c = (uint *)uVar11;
    UNLOCK();
    bVar12 = ((uint)param_3 & 0x400) != 0;
    uVar13 = 0x99c373;
    pbVar6 = extraout_ECX + -1;
    if (pbVar6 == (byte *)0x0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    puVar4 = (uint *)CONCAT31((int3)((uint)param_1 >> 8),*(undefined1 *)param_2);
    param_2 = (float)((int)param_2 + 1 + (uint)bVar12 * -2);
    param_1 = pCVar1;
  }
  else {
    _DAT_3dd03d8c = (uint *)uVar11;
    *param_1 = (CVisionViewportDx9)((char)*param_1 - bVar8);
    param_1[-0x53cf5ad0] = (CVisionViewportDx9)((byte)param_1[-0x53cf5ad0] ^ (byte)unaff_EBX);
    pbVar6 = extraout_ECX;
  }
  pbVar6[0x2430b630] = pbVar6[0x2430b630] ^ bVar8;
  *puVar4 = *puVar4 ^ unaff_EBP;
  *(uint *)(pbVar6 + (int)param_2) = *(uint *)(pbVar6 + (int)param_2) ^ unaff_EBP;
  *pbVar6 = *pbVar6 ^ bVar8;
  pCVar5 = (CPlugBitmap *)((uint)puVar4 ^ 0x31);
  puVar9 = (undefined4 *)((uint)param_2 ^ (uint)pbVar6);
  *(uint *)pCVar5 = *(uint *)pCVar5 ^ (uint)pCVar5;
  bVar3 = (byte)((uint)piVar7 ^ (uint)param_1) ^
          *(byte *)(((uint)piVar7 ^ (uint)param_1) + (int)puVar9);
  if (((char)bVar3 < '\0') && ('\0' < (char)bVar3)) {
    *(undefined4 *)param_1 = *puVar9;
    puVar9 = (undefined4 *)((uint)(puVar9 + (uint)bVar12 * -2 + 1) ^ puVar9[(uint)bVar12 * -2 + 1]);
    puVar10 = puVar9 + (uint)bVar12 * -2 + 1;
    pCVar5 = (CPlugBitmap *)*puVar9;
    *(undefined2 *)puVar10 = in_FPUControlWord;
    *(undefined2 *)(puVar10 + 1) = in_FPUStatusWord;
    *(undefined2 *)(puVar10 + 2) = in_FPUTagWord;
    puVar10[5] = in_FPUDataPointer;
    puVar10[3] = uVar13;
    *(undefined2 *)((int)puVar10 + 0x12) = in_FPULastInstructionOpcode;
  }
  return pCVar5;
}
}

// =================================================
// Function: CVisionViewportDx9::BitmapSpecularsLAGetClose
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CPlugBitmap * __thiscall
CVisionViewportDx9::BitmapSpecularsLAGetClose
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,float param_2,float param_3,
          float param_4)
{
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  undefined4 in_EAX;
  uint uVar5;
  byte bVar6;
  byte *unaff_EBX;
  bool bVar7;
  
  bVar6 = (byte)((uint)unaff_EBX >> 8);
  *unaff_EBX = *unaff_EBX | bVar6;
  bVar4 = (byte)in_EAX | 0x3b;
  bVar1 = *unaff_EBX;
  *unaff_EBX = *unaff_EBX + bVar6;
  bVar3 = bVar4 + 0x3b;
  bVar7 = 0xc4 < bVar4 || CARRY1(bVar3,CARRY1(bVar1,bVar6));
  bVar4 = *unaff_EBX;
  bVar2 = *unaff_EBX;
  *unaff_EBX = (bVar2 - bVar6) - bVar7;
  *unaff_EBX = *unaff_EBX & bVar6;
  uVar5 = CONCAT31((int3)((uint)in_EAX >> 8),
                   (bVar3 + CARRY1(bVar1,bVar6) + -0x3b) -
                   (bVar4 < bVar6 || (byte)(bVar2 - bVar6) < bVar7)) & 0xffffff3b;
  *unaff_EBX = *unaff_EBX - bVar6;
  *unaff_EBX = *unaff_EBX ^ bVar6;
  return (CPlugBitmap *)((CONCAT31((int3)(uVar5 >> 8),(char)uVar5 + -0x3b) ^ 0x3b) + 1);
}
}

// =================================================
// Function: CVisionViewportDx9::BitmapStdInitAll
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0099b6ac) overlaps instruction at (ram,0x0099b6a9)
    */

void __thiscall
CVisionViewportDx9::BitmapStdInitAll(CVisionViewportDx9 *this,CVisionViewportDx9 *param_1)
{
{
  uint *puVar1;
  int iVar2;
  byte bVar3;
  char cVar4;
  undefined4 in_EAX;
  uint *extraout_ECX;
  undefined4 in_EDX;
  uint *extraout_EDX;
  int *unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  byte in_AF;
  char in_ZF;
  undefined4 unaff_retaddr;
  uint uVar5;
  char *pcVar6;
  
  if (this != (CVisionViewportDx9 *)0x1 && in_ZF == '\0') {
    in_EAX = unaff_retaddr;
  }
  *unaff_EBX = *unaff_EBX + unaff_EDI;
  iVar2 = *unaff_EBX;
  bVar3 = 9 < ((byte)in_EAX & 0xf) | in_AF;
  uVar5 = CONCAT31((int3)((uint)in_EAX >> 8),(byte)in_EAX + bVar3 * -6) & 0xffffff0f;
  cVar4 = (char)uVar5;
  pcVar6 = (char *)CONCAT22((short)(uVar5 >> 0x10),CONCAT11((char)((uint)in_EAX >> 8) - bVar3,cVar4)
                           );
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6[0x1000000] = pcVar6[0x1000000] + (char)((uint)in_EDX >> 8);
  *pcVar6 = *pcVar6 + cVar4;
  func_0x1130cd30();
  *extraout_EDX = *extraout_EDX ^ (uint)&stack0x00000000;
  puVar1 = (uint *)((int)extraout_ECX + unaff_ESI + 0x58);
  *puVar1 = *puVar1 ^ (uint)extraout_ECX;
  *(uint *)(unaff_ESI + 0x31) = *(uint *)(unaff_ESI + 0x31) ^ (uint)unaff_EBX;
  *extraout_ECX = *extraout_ECX ^ 0x31a13188;
  puVar1 = (uint *)((int)extraout_EDX + unaff_ESI + 0x32c032ac);
  *puVar1 = *puVar1 ^ unaff_EDI - iVar2 ^ 0xd531c231U;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: CVisionViewportDx9::CVisionViewportDx9
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CVisionViewportDx9::CVisionViewportDx9(CVisionViewportDx9 *this,CVisionViewportDx9 *param_1)
{
{
  uint uVar1;
  SCasterCat *pSVar2;
  undefined4 extraout_EAX;
  CPlugTree *this_00;
  undefined4 extraout_EAX_00;
  undefined4 uVar3;
  CPlugVisualQuads2D *pCVar4;
  CPlugVisualQuads2D *extraout_EAX_01;
  int iVar5;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBX;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBP;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  undefined4 uStack00000008;
  undefined1 uStack0000000c;
  void *in_stack_00000010;
  undefined1 uStack00000018;
  undefined1 uStack00000024;
  undefined1 uStack0000002c;
  CVisionViewportDx9 *pCVar6;
  code *pcVar7;
  CVisionViewportDx9 *pCVar8;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar9;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar10;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar11;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar12;
  code *pcVar13;
  code *pcVar14;
  code *pcVar15;
  code *pcVar16;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar17;
  ulong uVar18;
  code *pcVar19;
  CDx9GpuBuilder *pCVar20;
  code *pcVar21;
  CVisionViewportDx9 *pCVar22;
  CPlugTree *pCVar23;
  CVisionViewportDx9 *pCVar24;
  code *pcVar25;
  CPlugVisualQuads2D *pCVar26;
  CVisionViewportDx9 *pCVar27;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_ffffffdc;
  code *this_01;
  CFastStringInt *pCVar28;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_ffffffe0;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_ffffffe4;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_ffffffe8;
  CDx9FlareOcc *in_stack_ffffffec;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_fffffff0;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00ae9a4c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar24 = this;
  CVisionViewport::CVisionViewport
            ((CVisionViewport *)this,(CVisionViewport *)(DAT_00cca150 ^ (uint)&stack0xffffffc8));
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x800,unaff_EDI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x80c,unaff_ESI);
  *(undefined4 *)(this + 0x818) = 0;
  *(undefined4 *)(this + 0x820) = 0;
  *(undefined4 *)(this + 0x824) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x828,unaff_EBP);
  *(undefined4 *)(this + 0x868) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x86c,unaff_EBX);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x878,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar24);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x884,in_stack_ffffffdc);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x8cc,in_stack_ffffffe0);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x8d8,in_stack_ffffffe4);
  *(undefined4 *)(this + 0x910) = 0;
  *(undefined4 *)(this + 0x90c) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x930,in_stack_ffffffe8);
  uStack00000024 = 0xc;
  CDx9FlareOcc::CDx9FlareOcc(this + 0x94c,in_stack_ffffffec);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x9fc,in_stack_fffffff0);
  uStack0000002c = 0xe;
  _eh_vector_constructor_iterator_
            (this + 0xa08,0xc,4,
             CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>,
             CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>);
  this_01 = CDx9StateBlock::~CDx9StateBlock;
  pcVar25 = CDx9StateBlock::CDx9StateBlock;
  pCVar23 = (CPlugTree *)0x10;
  pCVar22 = (CVisionViewportDx9 *)&DAT_00000080;
  pCVar24 = this + 0xa74;
  uStack00000018 = 0xf;
  _eh_vector_constructor_iterator_
            (pCVar24,0x80,0x10,CDx9StateBlock::CDx9StateBlock,CDx9StateBlock::~CDx9StateBlock);
  pcVar21 = CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>;
  pcVar19 = CMwNodRef<class_CGameManialinkEntry>::CMwNodRef<class_CGameManialinkEntry>;
  uVar18 = 8;
  pCVar27 = this + 0x1274;
  pCVar17 = (CFastBuffer<class_CPlugFileSndGen*> *)&DAT_00000004;
  _eh_vector_constructor_iterator_
            (pCVar27,4,8,CMwNodRef<class_CGameManialinkEntry>::CMwNodRef<class_CGameManialinkEntry>,
             CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>);
  pcVar16 = CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>;
  pcVar14 = CMwNodRef<class_CGameManialinkEntry>::CMwNodRef<class_CGameManialinkEntry>;
  pCVar8 = this + 0x1294;
  pCVar12 = (CFastBuffer<class_CPlugFileSndGen*> *)&DAT_00000032;
  pCVar10 = (CFastBuffer<class_CPlugFileSndGen*> *)&DAT_00000004;
  _eh_vector_constructor_iterator_
            (pCVar8,4,0x32,
             CMwNodRef<class_CGameManialinkEntry>::CMwNodRef<class_CGameManialinkEntry>,
             CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x135c,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar8);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x1368,pCVar10);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x1374,pCVar12);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x1380,(CFastBuffer<class_CPlugFileSndGen*> *)pcVar14);
  pcVar15 = CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>;
  pcVar13 = CMwNodRef<class_CGameManialinkEntry>::CMwNodRef<class_CGameManialinkEntry>;
  pCVar11 = (CFastBuffer<class_CPlugFileSndGen*> *)&DAT_0000001d;
  pCVar8 = this + 0x138c;
  pCVar9 = (CFastBuffer<class_CPlugFileSndGen*> *)&DAT_00000004;
  _eh_vector_constructor_iterator_
            (pCVar8,4,0x1d,
             CMwNodRef<class_CGameManialinkEntry>::CMwNodRef<class_CGameManialinkEntry>,
             CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>);
  pcVar7 = CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>;
  pcVar14 = CMwNodRef<class_CGameManialinkEntry>::CMwNodRef<class_CGameManialinkEntry>;
  pCVar12 = (CFastBuffer<class_CPlugFileSndGen*> *)&DAT_0000001d;
  pCVar6 = this + 0x1400;
  pCVar10 = (CFastBuffer<class_CPlugFileSndGen*> *)&DAT_00000004;
  pCVar26 = (CPlugVisualQuads2D *)CONCAT31((int3)((uint)pcVar25 >> 8),0x17);
  _eh_vector_constructor_iterator_
            (pCVar6,4,0x1d,
             CMwNodRef<class_CGameManialinkEntry>::CMwNodRef<class_CGameManialinkEntry>,
             CMwNodRef<class_CSceneObjectLink>::~CMwNodRef<class_CSceneObjectLink>);
  pCVar20 = (CDx9GpuBuilder *)CONCAT31((int3)((uint)pcVar19 >> 8),0x18);
  CMwId::CMwId(this + 0x1510,(CMwId *)pCVar6);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x1544,pCVar10);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x1550,pCVar12);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>
            (this + 0x155c,(CFastArray<class_CManoeuvre*> *)pcVar14);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x1564,(CFastBuffer<class_CPlugFileSndGen*> *)pcVar7);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x1570,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar8);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x157c,pCVar9);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x1588,pCVar11);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x1594,(CFastBuffer<class_CPlugFileSndGen*> *)pcVar13);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x15b0,(CFastBuffer<class_CPlugFileSndGen*> *)pcVar15);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x15bc,(CFastBuffer<class_CPlugFileSndGen*> *)pcVar16);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x15c8,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar27);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x15d8,pCVar17);
  *(undefined4 *)(this + 0x15f0) = 0;
  *(undefined4 *)(this + 0x15f4) = 0;
  *(undefined4 *)(this + 0x15f8) = 0;
  local_8 = (undefined1 *)CONCAT31(local_8._1_3_,0x25);
  *(undefined4 *)(this + 0x15fc) = 0;
  *(undefined4 *)(this + 0x1600) = 0;
  *(undefined4 *)(this + 0x1604) = 0;
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(DAT_00d73300 + 0x20),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000009,uVar18);
  iVar5 = *(int *)pSVar2;
  if (*(int *)(iVar5 + 0x20) == 0) {
    this_01 = operator_new(0x1b4);
    local_4 = CONCAT31(local_4._1_3_,0x26);
    if ((CDx9GpuBuilder *)this_01 == (CDx9GpuBuilder *)0x0) {
      uVar3 = 0;
    }
    else {
      CDx9GpuBuilder::CDx9GpuBuilder((CDx9GpuBuilder *)this_01,pCVar20);
      uVar3 = extraout_EAX;
    }
    *(undefined4 *)(iVar5 + 0x20) = uVar3;
  }
  _DAT_00d75668 = _DAT_00d75668 | 1;
  _DAT_00d75644 = _DAT_00bd10b4;
  _DAT_00d75648 = _DAT_00bd10b0;
  _DAT_00d75650 = _DAT_00b2f708;
  _DAT_00d7564c = _DAT_00b59064;
  _DAT_00d75654 = _DAT_00b58720;
  _DAT_00d75658 = _DAT_00bd10ac;
  _DAT_00d7565c = _DAT_00bd10a8;
  _DAT_00d75660 = _DAT_00b59064;
  _DAT_00d75664 = _DAT_00b3d388;
  Dx9StaticInit();
  *(undefined4 *)(this + 0x894) = 0;
  *(undefined4 *)(this + 0x89c) = 0;
  *(undefined4 *)(this + 0x8a0) = 0;
  *(undefined4 *)(this + 0x8a4) = 0;
  *(undefined4 *)(this + 0x898) = 0;
  *(undefined4 *)(this + 0x8c8) = 0;
  *(undefined4 *)(this + 0x8b4) = 0;
  *(undefined4 *)(this + 0x8b0) = 0;
  *(undefined4 *)(this + 0x908) = 0;
  *(undefined4 *)(this + 0x8e4) = 0xffffffff;
  *(undefined4 *)(this + 0x8e8) = 0;
  *(undefined4 *)(this + 0x914) = 0;
  *(undefined4 *)(this + 0x918) = 0;
  *(undefined4 *)(this + 0x8a8) = 0xffffffff;
  *(undefined4 *)(this + 0x8ac) = 0xffffffff;
  *(undefined4 *)(this + 0x91c) = 2;
  *(undefined4 *)(this + 0x920) = 3;
  CFastString::SetString
            ((CFastString *)(this + 0x294),(CFastStringInt *)&stack0xffffffe0,
             (SStringParam *)pcVar21);
  *(undefined4 *)(this + 0x904) = 0;
  *(undefined4 *)(this + 0x8ec) = 0xffffffff;
  SetShaderForced(this,(CVisionViewportDx9 *)0x0,(CPlugShader *)pCVar24);
  *(undefined4 *)(this + 0x9f8) = 0;
  *(undefined4 *)(this + 0xa38) = 0;
  *(undefined4 *)(this + 0xa3c) = 0;
  *(undefined4 *)(this + 0xa40) = 0;
  *(undefined4 *)(this + 0xa44) = 0;
  *(undefined4 *)(this + 0xa48) = 0;
  CDx9VisualKeeper::StaticInit();
  RasterizeConstruct(this,pCVar22);
  *(undefined4 *)(this + 0x15a4) = 0;
  this_00 = operator_new(0xac);
  uStack0000000c = 0x27;
  if (this_00 == (CPlugTree *)0x0) {
    uVar3 = 0;
  }
  else {
    CPlugTree::CPlugTree(this_00,pCVar23);
    uVar3 = extraout_EAX_00;
  }
  *(undefined4 *)(this + 0x15d4) = uVar3;
  pCVar4 = operator_new(0x84);
  if (pCVar4 == (CPlugVisualQuads2D *)0x0) {
    pCVar4 = (CPlugVisualQuads2D *)0x0;
  }
  else {
    CPlugVisualQuads2D::CPlugVisualQuads2D(pCVar4,pCVar26);
    pCVar4 = extraout_EAX_01;
  }
  in_stack_00000010 = (void *)CONCAT31(in_stack_00000010._1_3_,0x25);
  CFastBuffer<class_GxVertex2>::AllocSetCount
            (pCVar4 + 0x78,(CFastBuffer<class_GxVertex2> *)&DAT_00000004,(ulong)pCVar26);
  local_4 = 0x3f800000;
  uStack00000008 = 0x3f800000;
  local_c = (void *)0x0;
  local_8 = (undefined1 *)0x0;
  CPlugVisualQuads2D::CreateQuad
            (pCVar4,(CPlugVisualQuads2D *)0x0,(GmVec2)0x0,_DAT_00b313ac,_DAT_00b313ac,
             (GxColor *)&local_4,0,0.0);
  CPlugVisual::AddTexCoordSet
            ((CPlugVisual *)pCVar4,(CPlugVisualSprite *)0x3f800000,1.0,0.0,0,0.0,(float)this_01);
  uVar1 = *(uint *)(pCVar4 + 0x1c);
  if (((uVar1 & 8) == 0) && (*(uint *)(pCVar4 + 0x1c) = uVar1 | 8, (uVar1 & 0x400) == 0)) {
    *(uint *)(pCVar4 + 0x1c) = uVar1 | 0x408;
    if (DAT_00d6eb04 != (undefined4 *)0x0) {
      (**(code **)*DAT_00d6eb04)();
    }
  }
  uVar1 = *(uint *)(pCVar4 + 0x1c);
  if (((uVar1 & 0x20) == 0) && (*(uint *)(pCVar4 + 0x1c) = uVar1 | 0x20, (uVar1 & 0x400) == 0)) {
    *(uint *)(pCVar4 + 0x1c) = uVar1 | 0x420;
    if (DAT_00d6eb04 != (undefined4 *)0x0) {
      (**(code **)*DAT_00d6eb04)();
    }
  }
  pCVar28 = (CFastStringInt *)0x0;
  pCVar27 = (CVisionViewportDx9 *)0x0;
  CPlugTree::SetVisual
            (*(CPlugTree **)(this + 0x15d4),(CVisionVisualKeeper *)pCVar4,(CPlugVisual *)0x0);
  pCVar24 = (CVisionViewportDx9 *)0x1;
  (**(code **)(**(int **)(this + 0x15d4) + 0xbc))();
  *(undefined4 *)(this + 0x84c) = 0x3f800000;
  *(undefined4 *)(this + 0x15a8) = 0;
  *(undefined4 *)(this + 0x15ac) = 0;
  *(undefined4 *)(this + 0x840) = 0;
  *(undefined4 *)(this + 0x848) = 0;
  *(undefined4 *)(this + 0x844) = 0;
  *(undefined4 *)(this + 0x850) = 1;
  *(undefined4 *)(this + 0x854) = 0;
  *(undefined4 *)(this + 0x858) = 0;
  *(undefined4 *)(this + 0x85c) = 0;
  *(undefined4 *)(this + 0x860) = 0;
  *(undefined4 *)(this + 0x864) = 0;
  *(undefined4 *)(this + 0x924) = DAT_00d770ac;
  *(undefined4 *)(this + 0x928) = DAT_00d770b0;
  *(undefined4 **)(this + 0x92c) = &DAT_00d77528;
  SyncGpuConstruct(this,pCVar24);
  *(undefined4 *)(this + 0x15e4) = 0;
  *(undefined4 *)(this + 0x15a0) = 0;
  uVar3 = _DAT_00b50954;
  *(undefined4 *)(this + 0x9a4) = 0;
  *(undefined4 *)(this + 0x834) = uVar3;
  *(undefined4 *)(this + 0x9a8) = 0;
  *(undefined4 *)(this + 0x1608) = 0;
  *(undefined4 *)(this + 0x838) = 0x3f800000;
  *(undefined4 *)(this + 0x160c) = 0;
  *(undefined4 *)(this + 0x1610) = 0;
  *(undefined4 *)(this + 0x160) = 0;
  *(undefined4 *)(this + 0x83c) = 1;
  DAT_00d770a0 = this;
  operator_delete(DAT_00d7037c);
  DAT_00d7037c = operator_new(0xc);
  if (DAT_00d7037c == (undefined4 *)0x0) {
    DAT_00d7037c = (undefined4 *)0x0;
  }
  else {
    *DAT_00d7037c =
         CFastCallbackInstance3P<class_CVisionViewportDx9,class_CPlugFilePng*,class_CClassicBuffer&,int>
         ::vftable;
    DAT_00d7037c[1] = this;
    DAT_00d7037c[2] = FileJpgImport;
  }
  operator_delete(DAT_00d6f48c);
  DAT_00d6f48c = operator_new(0xc);
  if (DAT_00d6f48c == (undefined4 *)0x0) {
    DAT_00d6f48c = (undefined4 *)0x0;
  }
  else {
    *DAT_00d6f48c =
         CFastCallbackInstance3P<class_CVisionViewportDx9,class_CPlugFileJpg*,class_CClassicBuffer&,int>
         ::vftable;
    DAT_00d6f48c[1] = this;
    DAT_00d6f48c[2] = FileJpgImport;
  }
  DAT_00d6e59c = 1;
  DAT_00d10dd0 = 1;
  operator_delete(DAT_00d6f610);
  DAT_00d6f610 = operator_new(0xc);
  if (DAT_00d6f610 == (undefined4 *)0x0) {
    DAT_00d6f610 = (undefined4 *)0x0;
  }
  else {
    *DAT_00d6f610 =
         CFastCallbackInstance1P<class_CVisionViewportDx9,struct_CPlugBitmap::SCompress*>::vftable;
    DAT_00d6f610[1] = this;
    DAT_00d6f610[2] = TextureCompress;
  }
  operator_delete(DAT_00d6e6c4);
  DAT_00d6e6c4 = operator_new(0xc);
  if (DAT_00d6e6c4 == (undefined4 *)0x0) {
    DAT_00d6e6c4 = (undefined4 *)0x0;
  }
  else {
    *DAT_00d6e6c4 =
         CFastCallbackInstance3P<class_CVisionViewportDx9,struct_CPlugFileImg::SDesc&,unsigned_char*,unsigned_long>
         ::vftable;
    DAT_00d6e6c4[1] = this;
    DAT_00d6e6c4[2] = FileImgGetDescFromFileInMemory;
  }
  operator_delete(DAT_00d6e6c8);
  DAT_00d6e6c8 = operator_new(0xc);
  if (DAT_00d6e6c8 == (undefined4 *)0x0) {
    DAT_00d6e6c8 = (undefined4 *)0x0;
  }
  else {
    *DAT_00d6e6c8 =
         CFastCallbackInstance2P<class_CVisionViewportDx9,struct_CPlugFileImg::SDesc&,class_CFastStringInt_const&>
         ::vftable;
    DAT_00d6e6c8[1] = this;
    DAT_00d6e6c8[2] = FileImgGetDescFromFile;
  }
  operator_delete(DAT_00d6e6cc);
  DAT_00d6e6cc = operator_new(0xc);
  if (DAT_00d6e6cc == (undefined4 *)0x0) {
    DAT_00d6e6cc = (undefined4 *)0x0;
  }
  else {
    *DAT_00d6e6cc =
         CFastCallbackInstance3P<class_CVisionViewportDx9,class_CFastStringInt_const&,class_CFastStringInt_const&,struct_CPlugFileImg::SDesc_const&>
         ::vftable;
    DAT_00d6e6cc[1] = this;
    DAT_00d6e6cc[2] = FileImgConvertFileToFile;
  }
  operator_delete(DAT_00d6fe80);
  DAT_00d6fe80 = operator_new(0xc);
  if (DAT_00d6fe80 == (undefined4 *)0x0) {
    DAT_00d6fe80 = (undefined4 *)0x0;
  }
  else {
    *DAT_00d6fe80 = CFastCallbackInstance1P<class_CVisionViewportDx9,class_CPlugFileVso*>::vftable;
    DAT_00d6fe80[1] = this;
    DAT_00d6fe80[2] = VsoCompile;
  }
  operator_delete(DAT_00d6fdf8);
  DAT_00d6fdf8 = operator_new(0xc);
  if (DAT_00d6fdf8 == (undefined4 *)0x0) {
    DAT_00d6fdf8 = (undefined4 *)0x0;
  }
  else {
    *DAT_00d6fdf8 = CFastCallbackInstance1P<class_CVisionViewportDx9,class_CPlugFilePso*>::vftable;
    DAT_00d6fdf8[1] = this;
    DAT_00d6fdf8[2] = PsoCompile;
  }
  DAT_00d705e0 = HLShaderCompileBegin;
  DAT_00d705e4 = HLShaderCompileIsTargetOk;
  DAT_00d705e8 = HLShaderCompileEnd;
  DAT_00d7031c = CGameCtnMenus::_vcall__504__flat______;
  DAT_00d70320 = 1;
  DAT_00d6f5a4 = CTrackManiaMenus::_vcall__516__flat______;
  DAT_00d6f598 = PixelShaderUndirty;
  DAT_00d75ad8 = &DAT_00d770c4;
  DAT_00d75828 = &DAT_00d770c4;
  _DAT_00d75684 = &DAT_00d770c4;
  DAT_00d756a0 = &DAT_00d770c4;
  DAT_00d76f78 = &DAT_00d770c4;
  DAT_00d6f59c = this;
  DAT_00d6f5a0 = this;
  DAT_00d70318 = this;
  DAT_00d705dc = this;
  _DAT_00d75688 = this;
  DAT_00d7569c = this;
  DAT_00d75824 = this;
  DAT_00d75a38 = this;
  DAT_00d75a60 = this;
  DAT_00d75af4 = this;
  DAT_00d75afc = this;
  DAT_00d75b08 = this;
  DAT_00d76f74 = this;
  DAT_00d77b18 = this;
  *(undefined4 *)(this + 0x890) = 0;
  BitmapStdInitAll(this,pCVar27);
  pCVar24 = this + 0x1474;
  for (iVar5 = 0x27; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined4 *)pCVar24 = 0;
    pCVar24 = pCVar24 + 4;
  }
  CMwId::SetLocalName(this + 0x1510,(CMwId *)"LDirInCamera",pCVar28);
  ExceptionList = in_stack_00000010;
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::ComputeAndSetCullMode
// =================================================
void __thiscall
CVisionViewportDx9::ComputeAndSetCullMode
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,SHmsCameraLocation *param_2)
{
{
  uint uVar1;
  ulong uVar2;
  uint uVar3;
  ulong local_8 [2];
  
  uVar1 = *(uint *)(this + 0x414);
  uVar3 = (uVar1 >> 1 ^ *(uint *)(param_1 + 0xa0) ^ uVar1) & 1;
  if ((*(int *)(this + 0x84) != 0) && ((uVar1 & 4) != 0)) {
    uVar3 = (uint)(uVar3 == 0);
  }
  local_8[0] = 2;
  local_8[1] = 3;
  uVar2 = local_8[uVar3];
  *(ulong *)(this + 0x91c) = uVar2;
  *(uint *)(this + 0x920) = (uVar2 == 2) + 2;
  CDx9StateBlock::FilterRenderState(0x16,uVar2);
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::ForceDeviceSynchro
// =================================================
int __thiscall
CVisionViewportDx9::ForceDeviceSynchro(CVisionViewportDx9 *this,CVisionViewportDx9 *param_1)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CPlugShader *unaff_EBP;
  CVisionViewport *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CVisionViewport *pCVar5;
  CVisionViewportDx9 *pCVar6;
  
  if (*(int *)(this + 0x2f8) == 0) {
    pCVar6 = *(CVisionViewportDx9 **)(this + 0x9f8);
    (**(code **)(*(int *)pCVar6 + 0x14))();
    iVar1 = CVisionViewport::ForceDeviceSynchro((CVisionViewport *)this,pCVar6);
    if (iVar1 != 0) {
      pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x584,unaff_EDI);
      pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this + 0x584,pCVar4,(ulong)unaff_ESI);
          pCVar5 = *(CVisionViewport **)pSVar3;
          if (((byte)pCVar5[0x1e] & 1) != 0) {
            CVisionViewport::ShaderGetKeeper((CVisionViewport *)this,pCVar5,unaff_EBP);
            unaff_ESI = pCVar5;
          }
          pCVar4 = pCVar4 + 1;
        } while (pCVar4 < pCVar2);
      }
      CDx9VisualKeeper::PackStaticGeometry();
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: CVisionViewportDx9::NodBindFakeFid
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0099b4d1) overlaps instruction at (ram,0x0099b4cc)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x0099b4d1) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CVisionViewportDx9::NodBindFakeFid
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CMwNod *param_2,
          CFastStringInt *param_3)
{
{
  CMwNod *pCVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  undefined1 uVar6;
  byte bVar7;
  byte bVar8;
  char cVar15;
  undefined4 in_EAX;
  undefined3 uVar18;
  int iVar11;
  int iVar12;
  int iVar13;
  byte bVar16;
  uint uVar14;
  byte *pbVar19;
  byte bVar20;
  byte bVar21;
  CMwNod *in_EDX;
  byte *unaff_EBX;
  uint *puVar22;
  uint unaff_EBP;
  byte *pbVar23;
  undefined1 *puVar24;
  char *pcVar25;
  uint *unaff_EDI;
  int *piVar26;
  undefined2 in_CS;
  byte in_AF;
  bool bVar27;
  bool in_OF;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined2 in_FPUStatusWord;
  uint unaff_retaddr;
  undefined4 in_stack_00000010;
  int in_stack_00000014;
  undefined1 *in_stack_00000018;
  uint auStack_5d [22];
  int *piStack_4;
  uint uVar9;
  uint *puVar10;
  char cVar17;
  
  cVar17 = (char)((uint)this >> 8);
  if (in_OF) {
    in_AF = (unaff_retaddr & 0x10) != 0;
    in_ID = (unaff_retaddr & 0x200000) != 0;
    in_AC = (unaff_retaddr & 0x40000) != 0;
    in_VIP = 0;
    in_VIF = 0;
    unaff_EBX = (byte *)CONCAT22((short)((uint)unaff_EBX >> 0x10),
                                 CONCAT11((byte)((uint)unaff_EBX >> 8) | *unaff_EBX,(char)unaff_EBX)
                                );
    cVar17 = (char)((uint)param_1 >> 8);
    in_EDX = param_2;
  }
  bVar27 = in_OF && (unaff_retaddr & 0x400) != 0;
  *unaff_EDI = *unaff_EDI | (uint)unaff_EDI;
  bVar16 = 9 < ((byte)in_EAX & 0xf) | in_AF;
  uVar9 = CONCAT31((int3)((uint)in_EAX >> 8),(byte)in_EAX + bVar16 * -6) & 0xffffff0f;
  cVar5 = (char)uVar9;
  cVar15 = (char)((uint)in_EAX >> 8) - bVar16;
  pcVar25 = (char *)CONCAT22((short)(uVar9 >> 0x10),CONCAT11(cVar15,cVar5));
  *pcVar25 = *pcVar25 + cVar15;
  bVar21 = (byte)in_EDX;
  *(char *)((int)pcVar25 * 2) = *(char *)((int)pcVar25 * 2) + bVar21;
  *pcVar25 = *pcVar25 + cVar5;
  uVar18 = (undefined3)((uint)pcVar25 >> 8);
  uVar9 = CONCAT31(uVar18,cVar5) ^ 0x36;
  pcVar25 = (char *)(uVar9 * 2);
  bVar20 = (byte)((uint)in_EDX >> 8);
  *pcVar25 = *pcVar25 + bVar20;
  pcVar25 = (char *)(uVar9 + 0x31);
  *pcVar25 = *pcVar25 + cVar17;
  pbVar19 = &DAT_2738d338;
  piVar26 = (int *)(_DAT_2738d338 * 0x77);
  uVar6 = in(0x3a);
  pcVar25 = (char *)CONCAT31(uVar18,uVar6);
  _DAT_3e1f3de9 = in_FPUStatusWord;
  *pcVar25 = *pcVar25 - (char)((uint)unaff_EBX >> 8);
  bVar7 = (byte)unaff_EBP ^ 0x3e;
  puVar10 = (uint *)(unaff_EBP ^ 0x3e);
  pbVar23 = (byte *)(pcVar25 + (uint)bVar27 * -8 + 4);
  out(*(undefined4 *)pcVar25,(short)in_EDX);
  if ((char)bVar7 < '\0') {
    _DAT_2738d338 = CONCAT31(DAT_2738d338_1,DAT_2738d338 - CARRY1(DAT_2738d338,bVar20));
    pbVar23 = (byte *)((uint)pbVar23 & _DAT_2738d338);
    _DAT_2738d338 = _DAT_2738d338 ^ (uint)pbVar23;
    piStack_4 = piVar26 + (uint)bVar27 * -2 + 1;
    iVar2 = in((short)in_EDX);
    *piVar26 = iVar2;
    pCVar1 = in_EDX + 0x31;
    *(uint *)pCVar1 = *(uint *)pCVar1 ^ (uint)pbVar23;
    uVar9 = *(uint *)pCVar1;
    uVar14 = unaff_retaddr;
code_r0x0099b4a0:
    if (-1 < (int)uVar9) {
      *pbVar23 = *pbVar23 + 1;
      if (pbVar23 + *piStack_4 != (byte *)0x0 || *piStack_4 != 0) {
        bVar16 = 9 < ((byte)puVar10 & 0xf) | bVar16;
        bVar7 = (byte)puVar10 + bVar16 * '\x06';
        bVar7 = bVar7 + (0x90 < (bVar7 & 0xf0) |
                        puVar10 < *(uint **)(&stack0x00000000 + (int)piStack_4) |
                        bVar16 * (0xf9 < bVar7)) * '`';
        out(CONCAT11(0x3b,bVar21),CONCAT31((int3)((uint)puVar10 >> 8),bVar7));
        *piStack_4 = *piStack_4 - (int)piStack_4;
        bVar16 = 9 < (bVar7 & 0xf) | bVar16;
        bVar7 = (bVar7 + bVar16 * -6 & 0xf) + 1;
        bVar16 = 9 < (bVar7 & 0xf) | bVar16;
        bVar7 = bVar7 + bVar16 * -6 & 0xf;
        bVar16 = 9 < bVar7 | bVar16;
        bVar16 = 9 < ((byte)in_stack_00000018 & 0xf) | 9 < (bVar7 + bVar16 * -6 & 0xf) | bVar16;
        uVar9 = CONCAT31((int3)((uint)in_stack_00000018 >> 8),(byte)in_stack_00000018 + bVar16 * -6)
                & 0xffffff0f;
        uVar9 = CONCAT22((short)(uVar9 >> 0x10),
                         CONCAT11((char)((uint)in_stack_00000018 >> 8) - bVar16,(char)uVar9));
        bVar16 = 9 < ((byte)uVar14 & 0xf) | bVar16;
        bVar7 = (byte)uVar14 + bVar16 * -6 & 0xf;
        bVar16 = (char)(uVar14 >> 8) - bVar16;
        bVar4 = 9 < bVar7 || (bVar16 & 0x10) != 0;
        bVar7 = bVar7 + bVar4 * -6 & 0xf;
        *piStack_4 = *piStack_4 >> 0xb;
        bVar3 = 9 < bVar7 || bVar4;
        uVar14 = CONCAT31((int3)(uVar14 >> 8),bVar7 + bVar3 * -6) & 0xffff000f;
        bVar7 = (byte)uVar14;
        cVar17 = (bVar16 - bVar4) - bVar3;
        pcVar25 = (char *)CONCAT22((short)(uVar14 >> 0x10),CONCAT11(cVar17,bVar7));
        *pcVar25 = *pcVar25 + bVar7;
        pcVar25[0x980000] = pcVar25[0x980000] + (byte)in_stack_00000010;
        *pcVar25 = *pcVar25 + bVar7;
        bVar21 = (byte)((uint)in_stack_00000010 >> 8);
        *pcVar25 = *pcVar25 + bVar21;
        bVar3 = 9 < bVar7 || bVar3;
        uVar14 = CONCAT31((int3)((uint)pcVar25 >> 8),bVar7 + bVar3 * '\x06') & 0xffffff0f;
        pbVar19 = (byte *)(CONCAT22((short)(uVar14 >> 0x10),CONCAT11(cVar17 + bVar3,(char)uVar14)) +
                           0x7f + uVar9);
        *pbVar19 = *pbVar19 ^ (byte)((uint)in_stack_00000014 >> 8);
        *(byte *)(in_stack_00000014 + uVar9) =
             *(byte *)(in_stack_00000014 + uVar9) ^ (byte)in_stack_00000014;
        in_stack_00000018 = &stack0x0000001c;
        *(uint *)(uVar9 + 0x4a31d531) = *(uint *)(uVar9 + 0x4a31d531) ^ uVar9;
        bVar16 = (byte)in_stack_00000010 ^ *(byte *)(uVar9 + 0x32);
        puVar24 = (undefined1 *)
                  (*(int *)CONCAT31((int3)((uint)in_stack_00000010 >> 8),bVar16) * 0x3296327b);
        bVar21 = bVar21 ^ bVar16;
        pcVar25 = puVar24 + (uint)bVar27 * -2 + 1;
        out(*puVar24,CONCAT11(bVar21,bVar16));
        *(uint *)(((uint)&stack0x00000018 ^ *(uint *)(&stack0xffffffa2 + (int)pcVar25)) - 4) =
             CONCAT22((short)((uint)in_stack_00000010 >> 0x10),CONCAT11(bVar21 - *pcVar25,bVar16));
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    *pbVar19 = *pbVar19 ^ 0xa0;
    *(uint *)(unaff_retaddr + 0x32) = *(uint *)(unaff_retaddr + 0x32) ^ (uint)puVar10;
  }
  else {
    bVar8 = (byte)puVar10 % 0x3e;
    bVar16 = 9 < (bVar8 & 0xf) | bVar16;
    uVar9 = CONCAT31((int3)(unaff_EBP >> 8),bVar8 + bVar16 * -6) & 0xffff000f;
    iVar11 = CONCAT22((short)(uVar9 >> 0x10),CONCAT11(bVar7 / 0x3e - bVar16,(char)uVar9));
    iVar2 = iVar11 + -0x613f4c3f;
    iVar12 = iVar2 - (uint)bVar16;
    bVar7 = 9 < ((byte)iVar12 & 0xf) | bVar16;
    bVar8 = (byte)iVar12 + bVar7 * -6 & 0xf;
    bVar3 = (bool)(9 < bVar8 | bVar7);
    uVar9 = CONCAT31((int3)((uint)iVar12 >> 8),bVar8 + bVar3 * -6) & 0xffff000f;
    iVar13 = CONCAT22((short)(uVar9 >> 0x10),
                      CONCAT11(((char)((uint)iVar12 >> 8) - bVar7) - bVar3,(char)uVar9));
    if (SBORROW4(iVar11,0x613f4c3f) != SBORROW4(iVar2,(uint)bVar16)) {
      in_EDX = (CMwNod *)CONCAT31((int3)((uint)in_EDX >> 8),bVar21 ^ (byte)in_EDX[0x32]);
      goto code_r0x0099b4b4;
    }
    if (bVar3 || iVar12 == 0) {
      bVar16 = 9 < ((byte)pbVar23 & 0xf) | bVar3;
      uVar9 = CONCAT31((int3)((uint)pbVar23 >> 8),(byte)pbVar23 + bVar16 * -6) & 0xffffff0f;
      bVar7 = (byte)uVar9;
      bVar8 = (char)((uint)pbVar23 >> 8) - bVar16;
      puVar10 = (uint *)CONCAT22((short)(uVar9 >> 0x10),CONCAT11(bVar8,bVar7));
      *(byte *)(puVar10 + 0x3d0000) = (byte)puVar10[0x3d0000] + bVar7;
      *(byte *)puVar10 = (byte)*puVar10 + bVar7;
      pbVar19 = (byte *)(iVar13 + 0x30);
      *pbVar19 = *pbVar19 ^ bVar7;
      pbVar23 = (byte *)(iVar13 + -1);
      pCVar1 = in_EDX + 0x30;
      *pCVar1 = (CMwNod)((byte)*pCVar1 ^ (byte)unaff_EBX);
      if (*pCVar1 == (CMwNod)0x0) goto code_r0x0099b4b4;
      *puVar10 = *puVar10 ^ 0x30983086;
      puVar22 = (uint *)CONCAT31((int3)((uint)unaff_EBX >> 8),(byte)unaff_EBX ^ bVar8);
      pbVar19 = &DAT_27380038;
      DAT_c330a930 = bVar7;
      *(byte *)puVar10 = (byte)*puVar10 ^ 0x38;
      *puVar10 = *puVar10 ^ (uint)in_EDX;
      *puVar10 = *puVar10 ^ (uint)puVar22;
      *puVar22 = *puVar22 ^ (uint)&stack0x00000000;
      _DAT_27380038 = _DAT_27380038 ^ (uint)pbVar23;
      puVar22 = (uint *)(unaff_retaddr + 0x31);
      *puVar22 = *puVar22 ^ unaff_retaddr;
      uVar9 = *puVar22;
      piStack_4 = piVar26;
      uVar14 = CONCAT22((ushort)(in_ID & 1) * 0x20 | (ushort)(in_VIP & 1) * 0x10 |
                        (ushort)(in_VIF & 1) * 8 | (ushort)(in_AC & 1) * 4,in_CS);
      goto code_r0x0099b4a0;
    }
  }
  in_EDX = (CMwNod *)
           CONCAT22((short)((uint)in_EDX >> 0x10),
                    CONCAT11(bVar20 ^ *pbVar23,bVar21 ^ pbVar23[-0x42cd63ce]));
code_r0x0099b4b4:
  in_EDX[0x64341e34] = (CMwNod)((byte)in_EDX[0x64341e34] | (byte)((uint)in_EDX >> 8));
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: CVisionViewportDx9::RasterizeConstruct
// =================================================
void __thiscall
CVisionViewportDx9::RasterizeConstruct(CVisionViewportDx9 *this,CVisionViewportDx9 *param_1)
{
{
  *(undefined4 *)(this + 0xa4c) = 0;
  *(undefined4 *)(this + 0xa50) = 0;
  *(undefined4 *)(this + 0xa54) = 0;
  *(undefined4 *)(this + 0xa58) = 0;
  *(undefined4 *)(this + 0xa5c) = 0;
  *(undefined4 *)(this + 0xa60) = 0;
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::RasterizeQuadAdd
// =================================================
SRasterizeVertex * __thiscall
CVisionViewportDx9::RasterizeQuadAdd
          (CVisionViewportDx9 *this,float param_1,float *param_3,float param_4,float param_5,
          float *param_6)
{
{
  float fVar1;
  SRasterizeVertex *pSVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  pSVar2 = *(SRasterizeVertex **)(this + 0xa60);
  if (pSVar2 == (SRasterizeVertex *)0x0) {
    return pSVar2;
  }
  fVar3 = *param_3 * *(float *)(this + 0xa64) + *(float *)(this + 0xa6c);
  fVar4 = *(float *)(this + 0xa68) * param_3[1] + *(float *)(this + 0xa70);
  fVar5 = param_3[2] * *(float *)(this + 0xa64) + *(float *)(this + 0xa6c);
  fVar6 = param_3[3] * *(float *)(this + 0xa68) + *(float *)(this + 0xa70);
  *(float *)(pSVar2 + 0x10) = param_1;
  *(float *)pSVar2 = fVar5;
  *(float *)(pSVar2 + 4) = fVar4;
  *(float *)(pSVar2 + 8) = param_4;
  *(float *)(pSVar2 + 0xc) = param_5;
  fVar1 = param_6[1];
  *(float *)(pSVar2 + 0x14) = *param_6;
  *(float *)(pSVar2 + 0x18) = fVar1;
  *(float *)(pSVar2 + 0x24) = fVar3;
  *(float *)(pSVar2 + 0x28) = fVar4;
  *(float *)(pSVar2 + 0x2c) = param_4;
  *(float *)(pSVar2 + 0x30) = param_5;
  *(float *)(pSVar2 + 0x34) = param_1;
  fVar1 = param_6[1];
  *(float *)(pSVar2 + 0x38) = param_6[2];
  *(float *)(pSVar2 + 0x3c) = fVar1;
  *(float *)(pSVar2 + 0x90) = fVar3;
  *(float *)(pSVar2 + 0x94) = fVar4;
  *(float *)(pSVar2 + 0x98) = param_4;
  *(float *)(pSVar2 + 0x9c) = param_5;
  *(float *)(pSVar2 + 0xa0) = param_1;
  fVar1 = param_6[1];
  *(float *)(pSVar2 + 0xa4) = param_6[2];
  *(float *)(pSVar2 + 0xa8) = fVar1;
  *(float *)(pSVar2 + 0x48) = fVar5;
  *(float *)(pSVar2 + 0x4c) = fVar6;
  *(float *)(pSVar2 + 0x50) = param_4;
  *(float *)(pSVar2 + 0x54) = param_5;
  *(float *)(pSVar2 + 0x58) = param_1;
  fVar1 = param_6[3];
  *(float *)(pSVar2 + 0x5c) = *param_6;
  *(float *)(pSVar2 + 0x60) = fVar1;
  *(float *)(pSVar2 + 0x6c) = fVar5;
  *(float *)(pSVar2 + 0x70) = fVar6;
  *(float *)(pSVar2 + 0x74) = param_4;
  *(float *)(pSVar2 + 0x78) = param_5;
  *(float *)(pSVar2 + 0x7c) = param_1;
  fVar1 = param_6[3];
  *(float *)(pSVar2 + 0x80) = *param_6;
  *(float *)(pSVar2 + 0x84) = fVar1;
  *(float *)(pSVar2 + 0xb4) = fVar3;
  *(float *)(pSVar2 + 0xb8) = fVar6;
  *(float *)(pSVar2 + 0xbc) = param_4;
  *(float *)(pSVar2 + 0xc0) = param_5;
  *(float *)(pSVar2 + 0xc4) = param_1;
  fVar1 = param_6[3];
  *(float *)(pSVar2 + 200) = param_6[2];
  *(float *)(pSVar2 + 0xcc) = fVar1;
  *(int *)(this + 0xa60) = *(int *)(this + 0xa60) + 0xd8;
  return pSVar2;
}
}

// =================================================
// Function: CVisionViewportDx9::RasterizeQuadAlloc
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CVisionViewportDx9::RasterizeQuadAlloc
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,ulong param_2,int param_3)
{
{
  CVisionViewportDx9 *this_00;
  float fVar1;
  float fVar2;
  float fVar3;
  SNewTriangleVert *pSVar4;
  uint uVar5;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *pCVar6;
  GmScaleTrans2 *pGVar7;
  int *piStack_20;
  int iStack_c;
  
  uVar5 = (int)param_1 * 0xd8;
  if (*(uint *)(this + 0xa54) <= uVar5 && uVar5 - *(uint *)(this + 0xa54) != 0) {
    piStack_20 = *(int **)(this + 0xa4c);
    *(uint *)(this + 0xa54) = uVar5;
    if (piStack_20 != (int *)0x0) {
      (**(code **)(*piStack_20 + 8))();
    }
    piStack_20 = (int *)0x0;
    (**(code **)(**(int **)(this + 0x9f8) + 0x68))
              (*(int **)(this + 0x9f8),*(undefined4 *)(this + 0xa54),0x208,0,0,this + 0xa4c);
  }
  pCVar6 = *(CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> **)
            (this + 0xa4c);
  piStack_20 = (int *)0x2000;
  pGVar7 = (GmScaleTrans2 *)0x0;
  (**(code **)(*(int *)pCVar6 + 0x2c))(pCVar6,0,uVar5,this + 0xa60);
  fVar1 = (float)*(int *)(this + 0x2a4);
  *(undefined4 *)(this + 0xa5c) = *(undefined4 *)(this + 0xa60);
  *(undefined4 *)(this + 0xa58) = 0;
  this_00 = this + 0xa64;
  if (*(int *)(this + 0x2a4) < 0) {
    fVar1 = fVar1 + _DAT_00c418d0;
  }
  *(float *)this_00 = -fVar1;
  fVar2 = (float)*(int *)(this + 0x2a8);
  if (*(int *)(this + 0x2a8) < 0) {
    fVar2 = fVar2 + _DAT_00c418d0;
  }
  *(float *)(this + 0xa68) = -fVar2;
  fVar3 = (float)_DAT_00b313b8;
  *(float *)this_00 = *(float *)this_00 * fVar3;
  *(float *)(this + 0xa68) = *(float *)(this + 0xa68) * fVar3;
  *(float *)(this + 0xa6c) = fVar1;
  *(float *)(this + 0xa70) = fVar2;
  *(float *)(this + 0xa6c) = *(float *)(this + 0xa6c) * fVar3;
  *(float *)(this + 0xa70) = fVar3 * *(float *)(this + 0xa70);
  if (iStack_c != 0) {
    pSVar4 = CFastBuffer<struct_SHmsRenderRect>::GetLastElem(this + 0x484,pCVar6);
    piStack_20 = *(int **)(pSVar4 + 0x44);
    GmScaleTrans2::LeftMult(this_00,(GmScaleTrans2 *)&piStack_20,pGVar7);
  }
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::RasterizeQuadGetFullRect
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CVisionViewportDx9::RasterizeQuadGetFullRect
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,GmRectAligned *param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = (float)*(int *)(this + 0x2a4);
  if (*(int *)(this + 0x2a4) < 0) {
    fVar1 = fVar1 + _DAT_00c418d0;
  }
  fVar1 = (float)_DAT_00b33a58 / fVar1;
  fVar2 = (float)*(int *)(this + 0x2a8);
  if (*(int *)(this + 0x2a8) < 0) {
    fVar2 = fVar2 + _DAT_00c418d0;
  }
  fVar2 = (float)_DAT_00b33a58 / fVar2;
  fVar3 = (float)_DAT_00b55920;
  *(float *)param_1 = fVar3 - fVar1;
  *(float *)(param_1 + 4) = fVar3 - fVar2;
  *(float *)(param_1 + 8) = fVar1 + 1.0;
  *(float *)(param_1 + 0xc) = fVar2 + 1.0;
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::RasterizeQuadSetUV1
// =================================================
void __thiscall
CVisionViewportDx9::RasterizeQuadSetUV1
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,SRasterizeVertex *param_2,
          GmRectAligned *param_3)
{
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)param_2;
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  uVar1 = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(param_1 + 0x44) = uVar1;
  uVar1 = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(param_1 + 0xb0) = uVar1;
  uVar1 = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)param_2;
  *(undefined4 *)(param_1 + 0x68) = uVar1;
  uVar1 = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)param_2;
  *(undefined4 *)(param_1 + 0x8c) = uVar1;
  uVar1 = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(param_1 + 0xd0) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(param_1 + 0xd4) = uVar1;
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::RasterizeQuads
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CVisionViewportDx9::RasterizeQuads
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CDx9StateBlock *param_2)
{
{
  ulong uVar1;
  void *unaff_ESI;
  uint uVar2;
  CFastBuffer<class_CCrystalFace*> *pCVar3;
  
  if (*(int *)(this + 0xa60) != 0) {
    uVar2 = (*(int *)(this + 0xa60) - *(int *)(this + 0xa5c)) / 0x24;
    *(uint *)(this + 0xa58) = uVar2;
    uVar2 = uVar2 / 6;
    (**(code **)(**(int **)(this + 0xa4c) + 0x30))(*(int **)(this + 0xa4c));
    *(undefined4 *)(this + 0xa60) = 0;
    *(undefined4 *)(this + 0xa5c) = 0;
    if (uVar2 != 0) {
      DAT_00d7568c = 0xffffffff;
      DAT_00d7582c = 0;
      CDx9StateBlock::ResetCache();
      CDx9TextureKeeper::ResetCache();
      _DAT_00d75ae0 = 0;
      DAT_00d75b00 = 0;
      DAT_00d75a68 = 0;
      if ((*(int *)(this + 0x994) == 1) && (DAT_00d76f80 != 0)) {
        *(undefined4 **)(DAT_00d76f74 + 0x92c) = &DAT_00d77528;
        DAT_00d76f80 = 0;
        (**(code **)(*DAT_00d76f70 + 0x134))(DAT_00d76f70,0);
      }
      CDx9StateBlock::FilterSetStreamSource(0,*(IDirect3DVertexBuffer9 **)(this + 0xa4c),0x24,0);
      CDx9VertexDeclaration::StaticSetStream0Decl(SUB41(*(undefined4 *)(this + 0xa50),0));
      pCVar3 = DAT_00d75af8;
      (**(code **)(*(int *)DAT_00d75af8 + 0x170))(DAT_00d75af8,0);
      if ((DAT_00d75b00 != 0) &&
         (uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount((void *)(DAT_00d75afc + 0x46c),pCVar3),
         uVar1 != 0)) {
        pCVar3 = (CFastBuffer<class_CCrystalFace*> *)0x98cda7;
        CDx9VertexShader::UpdateClipPlaneEqs();
      }
      DAT_00d75b00 = 0;
      CDx9StateBlock::Apply(unaff_ESI,(CDx9StateBlock *)pCVar3);
      (**(code **)(**(int **)(this + 0x9f8) + 0x144))(*(int **)(this + 0x9f8),4,0,uVar2 * 2);
    }
  }
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::RenderShader
// =================================================
void __thiscall
CVisionViewportDx9::RenderShader
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugShader *param_2,
          CPlugVisual *param_3)
{
{
  CMwNod *this_00;
  CMwNod *this_01;
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  CMwNod *pCVar1;
  CMwNod *pCVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  this_00 = *(CMwNod **)(*(int *)(this + 0x15d4) + 0x94);
  this_01 = *(CMwNod **)(*(int *)(this + 0x15d4) + 0x90);
  if (param_2 == (CPlugShader *)0x0) {
    param_2 = (CPlugShader *)this_01;
  }
  CMwNod::MwAddRef(this_01,unaff_EDI);
  CMwNod::MwAddRef(this_00,unaff_ESI);
  uVar4 = 0;
  uVar3 = 0;
  CPlugTree::SetVisual(*(CPlugTree **)(this + 0x15d4),(CVisionVisualKeeper *)param_2,param_3);
  (**(code **)(*(int *)this + 0x170))(*(undefined4 *)(this + 0x15d4),uVar3,uVar4);
  pCVar2 = (CMwNod *)0x0;
  pCVar1 = (CMwNod *)0x0;
  CPlugTree::SetVisual
            (*(CPlugTree **)(this + 0x15d4),(CVisionVisualKeeper *)this_01,(CPlugVisual *)this_00);
  CMwNod::MwRelease(this_00,pCVar1);
  CMwNod::MwRelease(this_01,pCVar2);
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::RenderShaderOnFullQuad
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CVisionViewportDx9::RenderShaderOnFullQuad
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugShader *param_2,
          CPlugBitmap *param_3,SGxPixRect *param_4,CPlugVisual *param_5,SRenderShaderParam *param_6)
{
{
  CVisionViewportDx9 *this_00;
  CVisionViewportDx9 *this_01;
  float fVar1;
  CVisionShaderKeeper *pCVar2;
  SLoadedLight *pSVar3;
  SCasterCat *pSVar4;
  SLoadedLight *pSVar5;
  uint uVar6;
  SCasterCat *this_02;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  SNewTriangleVert *pSVar8;
  SCasterCat *pSVar9;
  int iVar10;
  undefined4 uVar11;
  CPlugVisual *pCVar12;
  CVisionViewportDx9 *unaff_EBX;
  CPlugShader *unaff_EBP;
  int unaff_ESI;
  undefined4 *puVar13;
  undefined4 *puVar14;
  ulong unaff_EDI;
  SLoadedLight *pSVar15;
  CPlugShader *pCVar16;
  CVisionViewportDx9 *in_stack_0000001c;
  CVisionViewportDx9 *in_stack_00000020;
  int in_stack_00000024;
  CPlugShader *in_stack_00000028;
  CPlugShader *in_stack_0000002c;
  float in_stack_00000030;
  CPlugShader *in_stack_00000034;
  SUser **ppSVar17;
  CPlugShader *in_stack_ffffffc4;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *pCVar18;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *in_stack_ffffffc8;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *pCVar19;
  int *piVar20;
  ulong in_stack_ffffffcc;
  ulong uVar21;
  ulong in_stack_ffffffd0;
  CFastBuffer<struct_CTrackManiaNetwork::SReplayToValidateData> *in_stack_ffffffd4;
  CFastBuffer<struct_CTrackManiaNetwork::SReplayToValidateData> *in_stack_ffffffd8;
  CFastBuffer<class_CCrystalFace*> *pCVar22;
  ulong in_stack_ffffffec;
  
  CPlugShader::SetReceiverShadowGroupMask((CPlugShader *)param_1,(CPlugShader *)0x0,unaff_EDI);
  CHmsItem::SetIsForcePointDynamicCollisionResponse((CHmsItem *)param_1,(CHmsItem *)0x0,unaff_ESI);
  CVisionViewport::ShaderGetKeeper((CVisionViewport *)this,(CVisionViewport *)param_1,unaff_EBP);
  if (((byte)param_1[0x1e] & 1) != 0) {
    pCVar2 = CVisionViewport::ShaderGetKeeper
                       ((CVisionViewport *)this,(CVisionViewport *)param_1,(CPlugShader *)unaff_EBX)
    ;
    ppSVar17 = (SUser **)0x98fbef;
    unaff_EBX = param_1;
    (**(code **)(*(int *)pCVar2 + 8))();
    CFastBuffer<struct_CGameRemoteBuffer::SUser*>::ReplaceByLastIfFound
              (this + 0x590,(CFastBuffer<struct_CGameRemoteBuffer::SUser*> *)&param_3,ppSVar17);
    DAT_00d7582c = 0;
  }
  pCVar12 = param_5;
  if (param_5 != (CPlugVisual *)0x0) {
    if (*(int *)(param_5 + 0x14) == 0) {
      (**(code **)(*(int *)this + 0xb0))(param_5);
    }
    if (*(int *)(*(int *)(pCVar12 + 0x14) + 0xc) == 0) {
      return;
    }
  }
  CVisionViewport::ShaderGetKeeper
            ((CVisionViewport *)this,(CVisionViewport *)param_1,(CPlugShader *)unaff_EBX);
  puVar14 = *(undefined4 **)(this + 900);
  *(undefined4 *)(this + 0x3c0) = 0;
  *(undefined4 *)(this + 0x450) = 0;
  *(undefined4 *)(this + 0x430) = 0;
  pSVar9 = *(SCasterCat **)(this + 0x388);
  *(undefined2 *)(this + 900) = 0;
  *(undefined2 *)(this + 0x386) = 0;
  *(undefined2 *)(this + 0x388) = 0;
  *(undefined2 *)(this + 0x38a) = 0;
  SetShaderForced(this,(CVisionViewportDx9 *)0x0,in_stack_ffffffc4);
  if (in_stack_00000028 == (CPlugShader *)0x0) {
    if (pCVar12 == (CPlugVisual *)0x0) goto LAB_0098fcdf;
    uVar6 = (uint)((*(uint *)(pCVar12 + 0x54) >> 10 & 1) != DAT_00d6e59c);
  }
  else {
    uVar6 = *(uint *)in_stack_00000028;
  }
  *(uint *)(this + 0x414) = (uVar6 * 2 ^ *(uint *)(this + 0x414)) & 2 ^ *(uint *)(this + 0x414);
LAB_0098fcdf:
  pSVar3 = CFastBuffer<struct_SHmsCameraLocation>::AddNewElem(this + 0x454,in_stack_ffffffc8);
  puVar13 = &DAT_00d670f8;
  pSVar5 = pSVar3;
  for (iVar10 = 0x29; iVar10 != 0; iVar10 = iVar10 + -1) {
    *(undefined4 *)pSVar5 = *puVar13;
    puVar13 = puVar13 + 1;
    pSVar5 = pSVar5 + 4;
  }
  pSVar4 = GmMat4::operator[](pSVar3 + 0x60,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                              in_stack_ffffffcc);
  pCVar18 = *(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> **)(this + 0x9f8);
  pCVar19 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x2;
  (**(code **)(*(int *)pCVar18 + 0xb0))();
  pSVar5 = CFastBuffer<struct_CHmsViewport::SClippingFrustum>::AddNewElem(this + 0x460,pCVar18);
  puVar13 = &DAT_00d67340;
  for (iVar10 = 0x4e; iVar10 != 0; iVar10 = iVar10 + -1) {
    *(undefined4 *)pSVar5 = *puVar13;
    puVar13 = puVar13 + 1;
    pSVar5 = pSVar5 + 4;
  }
  pSVar5 = CFastBuffer<struct_SHmsCameraProjection>::AddNewElem(this + 0x478,pCVar19);
  pCVar16 = in_stack_0000002c;
  puVar13 = &DAT_00d671a0;
  if (((byte)this[0x414] & 2) == 0) {
    puVar13 = &DAT_00d67270;
  }
  pSVar15 = pSVar5;
  for (iVar10 = 0x34; iVar10 != 0; iVar10 = iVar10 + -1) {
    *(undefined4 *)pSVar15 = *puVar13;
    puVar13 = puVar13 + 1;
    pSVar15 = pSVar15 + 4;
  }
  if (((in_stack_0000002c != (CPlugShader *)0x0) && (((byte)*in_stack_0000002c & 2) != 0)) &&
     (in_stack_00000020 != (CVisionViewportDx9 *)0x0)) {
    iVar10 = *(int *)(in_stack_00000020 + 0x14);
    fVar1 = (float)*(int *)(iVar10 + 0x24);
    if (*(int *)(iVar10 + 0x24) < 0) {
      fVar1 = fVar1 + _DAT_00c418d0;
    }
    fVar1 = 1.0 / fVar1;
    *(float *)pSVar5 = *(float *)pSVar5 - fVar1 * *(float *)(pSVar5 + 0x30);
    *(float *)(pSVar5 + 4) = *(float *)(pSVar5 + 4) - *(float *)(pSVar5 + 0x34) * fVar1;
    *(float *)(pSVar5 + 8) = *(float *)(pSVar5 + 8) - *(float *)(pSVar5 + 0x38) * fVar1;
    *(float *)(pSVar5 + 0xc) = *(float *)(pSVar5 + 0xc) - fVar1 * *(float *)(pSVar5 + 0x3c);
    fVar1 = (float)*(int *)(iVar10 + 0x28);
    if (*(int *)(iVar10 + 0x28) < 0) {
      fVar1 = fVar1 + _DAT_00c418d0;
    }
    fVar1 = 1.0 / fVar1;
    param_1 = (CVisionViewportDx9 *)(*(float *)(pSVar5 + 0x34) * fVar1);
    param_2 = (CPlugShader *)(*(float *)(pSVar5 + 0x38) * fVar1);
    param_3 = (CPlugBitmap *)(fVar1 * *(float *)(pSVar5 + 0x3c));
    *(float *)(pSVar5 + 0x10) = *(float *)(pSVar5 + 0x10) + fVar1 * *(float *)(pSVar5 + 0x30);
    *(float *)(pSVar5 + 0x14) = *(float *)(pSVar5 + 0x14) + (float)param_1;
    *(float *)(pSVar5 + 0x18) = *(float *)(pSVar5 + 0x18) + (float)param_2;
    *(float *)(pSVar5 + 0x1c) = (float)param_3 + *(float *)(pSVar5 + 0x1c);
    GmMat4::SetTranspose(pSVar5 + 0x40,(GmMat2 *)pSVar5,(GmMat2 *)pSVar4);
  }
  pSVar4 = GmMat4::operator[](pSVar5 + 0x40,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                              in_stack_ffffffd0);
  piVar20 = *(int **)(this + 0x9f8);
  uVar21 = 3;
  (**(code **)(*piVar20 + 0xb0))();
  pCVar22 = *(CFastBuffer<class_CCrystalFace*> **)(this + 0x91c);
  uVar6 = (*(uint *)(this + 0x414) & 2 | 4) >> 1;
  *(uint *)(this + 0x91c) = uVar6;
  *(uint *)(this + 0x920) = (uVar6 == 2) + 2;
  CDx9StateBlock::FilterRenderState(0x16,uVar6);
  CFastBuffer<class_CSystemFidsFolder*>::SetCount
            (this + 0x538,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,(ulong)piVar20);
  this_02 = CFastBuffer<struct_CHmsViewport::SVisualLocation>::operator[]
                      (this + 0x538,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,uVar21);
  if ((pCVar16 == (CPlugShader *)0x0) || (((byte)*pCVar16 & 0x40) == 0)) {
    GmIso4::SetIdentity(this_02,(GmMat43 *)pSVar4);
    pSVar4 = this_02 + 0x70;
    for (iVar10 = 0xc; pCVar16 = in_stack_00000034, iVar10 != 0; iVar10 = iVar10 + -1) {
      *(undefined4 *)pSVar4 = *puVar14;
      puVar14 = puVar14 + 1;
      pSVar4 = pSVar4 + 4;
    }
  }
  else {
    in_stack_00000030 = (*(float *)(pCVar16 + 4) + *(float *)(pCVar16 + 4)) - (float)_DAT_00b2c188;
    GmMat3::SetIdentity((SPlugFaceCull *)(this_02 + 0x70),(GmMat43 *)pSVar4);
    *(undefined4 *)(this_02 + 0x94) = 0;
    *(undefined4 *)(this_02 + 0x98) = 0;
    *(CPlugShader **)(this_02 + 0x9c) = in_stack_00000034;
    GmIso4::SetMult(this_02,(SPlugFaceCull *)(this_02 + 0x70),(SPlugFaceCull *)(puVar14 + 0xc),
                    (GmIso4 *)in_stack_ffffffd4);
  }
  (**(code **)(*(int *)this + 0x1a4))();
  in_stack_00000030 = (float)DAT_00d75fa0;
  if (DAT_00d75fa0 == 0) {
    CDx9StateBlock::LockRenderState(0x1c,0);
  }
  if ((pCVar16 == (CPlugShader *)0x0) || (((byte)*pCVar16 & 0x40) == 0)) {
    uVar21 = 0;
  }
  else {
    uVar21 = 1;
  }
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CDx9StateBlock::LockRenderState(7,uVar21);
  uVar21 = CDx9StateBlock::LockRenderState(0xe,0);
  if (in_stack_00000024 == 0) {
    RenderShader(this,in_stack_00000020,in_stack_0000002c,(CPlugVisual *)this_02);
  }
  else {
    piVar20 = *(int **)(in_stack_00000024 + 0x14);
    if ((pCVar16 == (CPlugShader *)0x0) || (((byte)*pCVar16 & 4) == 0)) {
      uVar11 = 0;
    }
    else {
      uVar11 = 1;
    }
    if (*piVar20 == 5) {
      pCVar12 = (CPlugVisual *)((uint)piVar20[8] >> 3 & 1);
      iVar10 = func_0x009b4f10(piVar20,*(uint *)pCVar16 >> 3 & 7,uVar11);
    }
    else {
      pCVar12 = (CPlugVisual *)0x0;
      iVar10 = func_0x009b4e70(piVar20,0,uVar11,(uint)piVar20[8] >> 3 & 1);
    }
    if (iVar10 != 0) {
      if (in_stack_0000002c != (CPlugShader *)0x0) {
        param_2 = *(CPlugShader **)in_stack_0000002c;
        param_6 = (SRenderShaderParam *)0x0;
        param_3 = *(CPlugBitmap **)(in_stack_0000002c + 4);
        param_4 = (SGxPixRect *)(*(int *)(in_stack_0000002c + 8) - (int)param_2);
        in_stack_0000001c = (CVisionViewportDx9 *)0x3f800000;
        param_5 = (CPlugVisual *)(*(int *)(in_stack_0000002c + 0xc) - (int)param_3);
        pCVar12 = (CPlugVisual *)0x990023;
        ViewportSet(this,(CVisionViewportDx9 *)&param_2,(SHmsRenderRect *)in_stack_ffffffd4);
      }
      RenderShader(this,in_stack_0000001c,in_stack_00000028,pCVar12);
      if ((*(byte *)(piVar20 + 8) & 8) != 0) {
        CDx9TextureKeeper::AutoGenMipMapSetDirty(piVar20,(CDx9TextureKeeper *)in_stack_ffffffd4);
      }
    }
  }
  if ((in_stack_00000034 == (CPlugShader *)0x0) && (DAT_00d75fa0 = 0, DAT_00d75c90 != 0)) {
    CDx9StateBlock::PackRenderState(0x1c,0xffffffff,(SPackedDesc *)&param_2);
    *(uint *)(&DAT_00d76ed8 + (int)param_2 * 4) =
         *(uint *)(&DAT_00d76ed8 + (int)param_2 * 4) | (uint)param_4;
  }
  _DAT_00d75f4c = 0;
  if (DAT_00d75c3c != 0) {
    CDx9StateBlock::PackRenderState(7,0xffffffff,(SPackedDesc *)&param_2);
    *(uint *)(&DAT_00d76ed8 + (int)param_2 * 4) =
         *(uint *)(&DAT_00d76ed8 + (int)param_2 * 4) | (uint)param_4;
  }
  CDx9StateBlock::FilterRenderState(7,(ulong)pSVar9);
  _DAT_00d75f68 = 0;
  if (DAT_00d75c58 != 0) {
    CDx9StateBlock::PackRenderState(0xe,0xffffffff,(SPackedDesc *)&param_2);
    *(uint *)(&DAT_00d76ed8 + (int)param_2 * 4) =
         *(uint *)(&DAT_00d76ed8 + (int)param_2 * 4) | (uint)param_4;
  }
  CDx9StateBlock::FilterRenderState(0xe,uVar21);
  *(ulong *)(this + 0x91c) = in_stack_ffffffec;
  *(uint *)(this + 0x920) = (in_stack_ffffffec == 2) + 2;
  CDx9StateBlock::FilterRenderState(0x16,in_stack_ffffffec);
  this_00 = this + 0x478;
  CFastBuffer<struct_CTrackManiaNetwork::SReplayToValidateData>::RemoveLastElem
            (this_00,in_stack_ffffffd4);
  CFastBuffer<struct_CTrackManiaNetwork::SReplayToValidateData>::RemoveLastElem
            (this + 0x460,in_stack_ffffffd8);
  this_01 = this + 0x454;
  CFastBuffer<struct_CTrackManiaNetwork::SReplayToValidateData>::RemoveLastElem
            (this_01,(CFastBuffer<struct_CTrackManiaNetwork::SReplayToValidateData> *)pSVar3);
  uVar21 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,pCVar22);
  if (uVar21 != 0) {
    pSVar8 = CFastBuffer<struct_SHmsCameraProjection>::GetLastElem
                       (this_00,(CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>
                                 *)0x0);
    pSVar9 = GmMat4::operator[](pSVar8 + 0x40,pCVar7,(ulong)pSVar9);
    pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3;
    (**(code **)(**(int **)(this + 0x9f8) + 0xb0))(*(int **)(this + 0x9f8));
  }
  uVar21 = CFastBuffer<class_CCrystalFace*>::GetCount
                     (this_01,(CFastBuffer<class_CCrystalFace*> *)pCVar7);
  if (uVar21 != 0) {
    pSVar8 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem
                       (this_01,(CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>
                                 *)0x0);
    pSVar4 = GmMat4::operator[](pSVar8 + 0x60,
                                (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pSVar9,
                                in_stack_ffffffec);
    pSVar9 = (SCasterCat *)0x2;
    (**(code **)(**(int **)(this + 0x9f8) + 0xb0))(*(int **)(this + 0x9f8),2,pSVar4);
  }
  SetShaderForced(this,param_1,(CPlugShader *)pSVar9);
  *(CPlugBitmap **)(this + 900) = param_3;
  *(SGxPixRect **)(this + 0x388) = param_4;
  *(uint *)(this + 0x414) =
       *(uint *)(this + 0x414) ^ ((int)param_5 * 2 ^ *(uint *)(this + 0x414)) & 2;
  *(SRenderShaderParam **)(this + 0x3c0) = param_6;
  *(CVisionViewportDx9 **)(this + 0x450) = in_stack_0000001c;
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::RenderTargetClear
// =================================================
void __thiscall
CVisionViewportDx9::RenderTargetClear
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,ulong param_2,ulong param_3,
          float param_4,ulong param_5)
{
{
  undefined1 uVar1;
  undefined4 in_EAX;
  
  uVar1 = in(0x3c);
  (&stack0x00000000)[CONCAT31((int3)((uint)in_EAX >> 8),uVar1)] =
       (&stack0x00000000)[CONCAT31((int3)((uint)in_EAX >> 8),uVar1)] + '\x01';
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::RenderTargetExtraMrtSet
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009b5002) overlaps instruction at (ram,0x009b4ffe)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x009b4c91) */
/* WARNING: Removing unreachable block (ram,0x009b4f5c) */
/* WARNING: Removing unreachable block (ram,0x009b4be7) */
/* WARNING: Removing unreachable block (ram,0x009b4d18) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CVisionViewportDx9::RenderTargetExtraMrtSet
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,ulong param_2,
          CDx9TextureKeeper *param_3)
{
{
  longlong lVar1;
  code *pcVar2;
  undefined3 uVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  undefined1 uVar8;
  char cVar17;
  int *in_EAX;
  uint uVar9;
  int *piVar10;
  undefined3 uVar18;
  int iVar11;
  uint uVar12;
  uint *puVar13;
  uint uVar14;
  char *pcVar15;
  uint *puVar16;
  undefined2 uVar19;
  CVisionViewportDx9 *pCVar20;
  uint uVar21;
  undefined4 uVar22;
  uint *puVar23;
  uint *puVar24;
  uint *in_EDX;
  int iVar25;
  uint *puVar26;
  byte bVar27;
  uint unaff_EBX;
  uint *puVar28;
  undefined4 *puVar29;
  uint *puVar30;
  undefined4 *puVar31;
  uint unaff_EBP;
  CVisionViewportDx9 *pCVar32;
  int *piVar33;
  byte *pbVar34;
  byte *pbVar35;
  uint *puVar36;
  uint *unaff_EDI;
  byte *pbVar37;
  undefined2 in_ES;
  char in_CF;
  bool bVar38;
  byte in_AF;
  byte bVar39;
  bool bVar40;
  byte *unaff_retaddr;
  uint *in_stack_00000010;
  CVisionViewportDx9 *in_stack_00000014;
  uint *in_stack_00000018;
  uint in_stack_0000001c;
  uint *in_stack_00000020;
  char *in_stack_00000024;
  uint *puStack00000028;
  int *in_stack_0000002c;
  byte abStack_a [10];
  
  uVar21 = (uint)in_stack_00000020;
  bVar40 = false;
  *(char *)in_EAX = ((char)*in_EAX - (char)((uint)in_EDX >> 8)) - in_CF;
  piVar33 = (int *)(*in_EAX * -0x67);
  *(byte *)(unaff_EDI + -0x1973d574) = (byte)unaff_EDI[-0x1973d574] ^ (byte)unaff_EBX;
  uVar12 = *(uint *)(unaff_EBP + 0xf334e334);
  uVar9 = (uint)in_EAX ^ 0x35c33575;
  *piVar33 = *piVar33 << ((byte)this & 0x1f);
  bVar6 = POPCOUNT((uint)(this + -1) & 0xff);
  bVar4 = 9 < ((char)uVar9 + (char)(uVar9 >> 8) * '5' & 0xfU) | in_AF;
  bVar39 = 9 < (-bVar4 & 0xf) | bVar4;
  uVar9 = CONCAT31(CONCAT21((short)(uVar9 >> 0x10),bVar4),-bVar4 + bVar39 * '\x06') & 0xffffff0f;
  piVar10 = (int *)CONCAT22((short)(uVar9 >> 0x10),CONCAT11(bVar4 + bVar39,(char)uVar9));
  pCVar20 = this + -2;
  puVar13 = in_EDX;
  pCVar32 = (CVisionViewportDx9 *)(unaff_EBP ^ uVar12);
  pbVar34 = (byte *)((uint)piVar33 ^ *unaff_EDI);
  if (this + -2 == (CVisionViewportDx9 *)0x0 || this + -1 != (CVisionViewportDx9 *)0x0) {
    *piVar10 = *piVar10 + 1;
    puVar13 = in_stack_00000010;
    if ((int)in_stack_00000018 < 0x3d4f3d2f) {
      bVar40 = (in_stack_0000001c & 0x400) != 0;
      bVar6 = (byte)((uint)param_3 >> 8);
      *unaff_retaddr = *unaff_retaddr + bVar6 + (in_stack_00000018 < (uint *)0x3de53dc5);
      *unaff_retaddr = *unaff_retaddr ^ bVar6;
      in_stack_00000020 = (uint *)CONCAT22(in_stack_00000020._2_2_,in_ES);
      bVar38 = 9 < ((byte)in_stack_00000018 & 0xf) || (in_stack_0000001c & 0x10) != 0;
      bVar4 = ((byte)in_stack_00000018 + bVar38 * -6 & 0xf) - 0x3f;
      bVar6 = POPCOUNT(bVar4);
      bVar39 = 9 < (bVar4 & 0xf) || bVar38;
      uVar12 = CONCAT31((int3)((uint)in_stack_00000018 >> 8),bVar4 + bVar39 * -6) & 0xffff000f;
      piVar10 = (int *)CONCAT22((short)(uVar12 >> 0x10),
                                CONCAT11(((char)((uint)in_stack_00000018 >> 8) - bVar38) - bVar39,
                                         (char)uVar12));
      pCVar20 = in_stack_00000014;
      puVar13 = in_stack_00000020;
      unaff_EBX = uVar21;
      pCVar32 = param_1;
      pbVar34 = unaff_retaddr;
      unaff_EDI = in_EDX;
      goto CVisionViewportDx9_RenderTargetExtraMrtRemoveAll;
    }
  }
  else {
CVisionViewportDx9_RenderTargetExtraMrtRemoveAll:
    if ((bVar6 & 1) == 0) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    in_EDX = unaff_EDI + (uint)bVar40 * -2 + 1;
    *unaff_EDI = (uint)piVar10;
    bVar39 = 9 < (byte)piVar10 | bVar39;
    bVar6 = 9 < (-bVar39 & 0xf) | bVar39;
    bVar5 = -bVar39 + bVar6 * -6 & 0xf;
    bVar4 = 9 < bVar5 | bVar6;
    uVar12 = CONCAT31((int3)((uint)piVar10 >> 8),bVar5 + bVar4 * -6) & 0xffff000f;
    cVar17 = (char)uVar12;
    bVar4 = (((char)((uint)piVar10 >> 8) - bVar39) - bVar6) - bVar4;
    uVar18 = (undefined3)(CONCAT22((short)(uVar12 >> 0x10),CONCAT11(bVar4,cVar17)) >> 8);
    bVar6 = cVar17 + bVar4;
    bVar6 = bVar6 ^ *(byte *)CONCAT31(uVar18,bVar6);
    in_stack_00000018 = (uint *)CONCAT31(uVar18,bVar6);
    *(byte *)in_stack_00000018 = bVar6;
    *(byte *)in_stack_00000018 = (char)*in_stack_00000018 + bVar6;
    unaff_retaddr = (byte *)(((uint)pbVar34 & *in_stack_00000018) - 1);
    ((char *)((int)in_stack_00000018 + -0x61))[(int)unaff_retaddr] =
         ((char *)((int)in_stack_00000018 + -0x61))[(int)unaff_retaddr] ^ (byte)((uint)puVar13 >> 8)
    ;
    uVar12 = CONCAT22((short)((uint)pCVar20 >> 0x10),
                      CONCAT11((byte)((uint)pCVar20 >> 8) ^ (byte)puVar13 ^ (byte)(unaff_EBX >> 8),
                               (char)pCVar20));
    *(byte *)puVar13 = (byte)*puVar13 ^ bVar4;
    *(uint *)(pCVar32 + 0x31) = *(uint *)(pCVar32 + 0x31) ^ uVar12;
    bVar40 = ((uint)in_stack_00000024 & 0x400) != 0;
    bVar39 = ((uint)in_stack_00000024 & 0x10) != 0;
    param_3 = (CDx9TextureKeeper *)(unaff_EBX ^ (uint)&stack0x00000028);
    in_stack_00000014 = (CVisionViewportDx9 *)(uVar12 ^ (uint)unaff_retaddr);
  }
  *puVar13 = *puVar13 ^ (uint)in_stack_00000014;
  uVar19 = (undefined2)((uint)param_3 >> 0x10);
  bVar27 = (byte)param_3;
  pbVar34 = (byte *)CONCAT22(uVar19,CONCAT11((byte)((uint)param_3 >> 8) ^
                                             *(byte *)((int)puVar13 + 0x32),bVar27));
  uVar12 = CONCAT22((short)((uint)puVar13 >> 0x10),
                    CONCAT11((byte)((uint)puVar13 >> 8) ^ (byte)*in_stack_00000014,
                             (byte)puVar13 ^ bVar27));
  uVar21 = (uint)in_stack_00000014 ^ *(uint *)((int)in_EDX + 0x33);
  iVar11 = (uVar12 - (uVar12 < 0x3dc63d6f)) + 0x34c18bc1;
  bVar39 = 9 < ((byte)iVar11 & 0xf) | bVar39;
  uVar12 = CONCAT31((int3)((uint)iVar11 >> 8),(byte)iVar11 + bVar39 * -6) & 0xffffff0f;
  pbVar37 = (byte *)(*in_EDX * -0x7d);
  bVar4 = 9 < (byte)uVar12 | bVar39;
  uVar18 = CONCAT21((short)(uVar12 >> 0x10),((char)((uint)iVar11 >> 8) - bVar39) - bVar4);
  bVar4 = 9 < ((byte)uVar21 & 0xf) | bVar4;
  bVar39 = (byte)uVar21 + bVar4 * -6 & 0xf;
  pcVar15 = (char *)CONCAT31(uVar18,0x3f);
  bVar6 = 9 < bVar39 | bVar4;
  uVar12 = CONCAT31((int3)(uVar21 >> 8),bVar39 + bVar6 * -6) & 0xffff000f;
  lVar1 = CONCAT44(CONCAT31((int3)((uint)in_stack_00000018 >> 8),
                            (byte)in_stack_00000018 ^ (byte)((uint)in_stack_00000014 >> 8)),
                   CONCAT22((short)(uVar12 >> 0x10),
                            CONCAT11(((char)(uVar21 >> 8) - bVar4) - bVar6,(char)uVar12))) %
          (longlong)*(int *)pbVar37;
  bVar4 = (byte)in_stack_00000024;
  *in_stack_00000024 = *in_stack_00000024 + bVar4;
  *pcVar15 = *pcVar15 + '?';
  *pbVar34 = *pbVar34 ^ bVar27;
  DAT_9c70676f = DAT_9c70676f ^ bVar4;
  uVar3 = (undefined3)((uint)in_stack_00000024 >> 8);
  bVar5 = (byte)((uint)in_stack_00000024 >> 8) ^ 0x3f;
  bVar4 = bVar4 ^ (byte)((ulonglong)lVar1 >> 8);
  DAT_3a312531 = DAT_3a312531 ^ bVar4;
  *(uint *)(pbVar34 + 0x31) = *(uint *)(pbVar34 + 0x31) ^ (uint)pbVar34;
  *(uint *)(pbVar37 + -0x1cce36cf) = *(uint *)(pbVar37 + -0x1cce36cf) ^ (uint)&stack0x00000028;
  uVar12 = (uint)lVar1 ^ (uint)unaff_retaddr;
  *(uint *)(pcVar15 + -0x3ccd58ce) =
       *(uint *)(pcVar15 + -0x3ccd58ce) ^ CONCAT31(uVar3,bVar4) ^ 0x3f00;
  bVar4 = bVar4 ^ bVar27;
  uVar21 = CONCAT31(uVar3,bVar4) ^ 0x3f00;
  puStack00000028 = (uint *)CONCAT22(uVar19,(ushort)bVar27);
  bVar39 = *unaff_retaddr ^ 0x3f;
  uVar9 = *(uint *)((int)puStack00000028 + 0x33fc33) ^ 0xe53fd33f;
  out((short)uVar21,(byte)uVar12 ^ 0x10);
  if (CONCAT31(uVar18,*unaff_retaddr) != 0x3f) {
    pcVar2 = (code *)swi(1);
    (*pcVar2)();
    return;
  }
  _DAT_ca35b135 = uVar12 ^ 0x3883386c;
  puVar13 = (uint *)(uVar12 ^ 0xef30e2a);
  bVar7 = (byte)puVar13;
  if (puVar13 == (uint *)0x0) {
    *unaff_retaddr = *unaff_retaddr + bVar4;
    uVar22 = 0;
code_r0x009b4daa:
    bVar6 = 9 < ((byte)uVar22 & 0xf) | bVar6;
    uVar12 = CONCAT31((int3)((uint)uVar22 >> 8),(byte)uVar22 + bVar6 * '\x06') & 0xffffff0f;
    *(undefined4 *)
     CONCAT22((short)(uVar12 >> 0x10),CONCAT11((char)((uint)uVar22 >> 8) + bVar6,(char)uVar12)) =
         *(undefined4 *)unaff_retaddr;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((int)puVar13 < 0) {
    out(0x3f,puVar13);
    *(byte *)puVar13 = (char)*puVar13 + bVar7;
    *(byte *)puVar13 = (char)*puVar13 + bVar4;
    pbVar34 = (byte *)((uint)puVar13 ^ *puVar13);
    bVar4 = (byte)pbVar34;
    *pbVar34 = *pbVar34 ^ bVar4;
    *pbVar34 = *pbVar34 + bVar4;
    *pbVar37 = bVar4;
    *(uint *)(unaff_retaddr + 0x37ce344c) =
         *(uint *)(unaff_retaddr + 0x37ce344c) ^ (uint)unaff_retaddr;
  }
  else {
    _DAT_fa37b237 =
         CONCAT22((short)((uint)puVar13 >> 0x10),
                  CONCAT11(bVar6 << 4 | ((POPCOUNT((uint)puVar13 & 0xff) & 1U) == 0) << 2,bVar7)) |
         0x200;
    bVar4 = *pbVar37;
    *pbVar37 = *pbVar37 + bVar5;
    bVar6 = 9 < (bVar7 & 0xf) | bVar6;
    uVar12 = CONCAT31((int3)(_DAT_fa37b237 >> 8),bVar7 + bVar6 * '\x06') & 0xffffff0f;
    uVar8 = (undefined1)uVar12;
    uVar12 = CONCAT22((short)(uVar12 >> 0x10),CONCAT11((char)(_DAT_fa37b237 >> 8) + bVar6,uVar8));
    if (*pbVar37 == 0) {
      *(undefined4 *)(abStack_a + (int)unaff_retaddr) =
           *(undefined4 *)(abStack_a + (int)unaff_retaddr);
    }
    else if ((char)*pbVar37 < '\0') {
      uVar12 = CONCAT31((int3)(uVar12 >> 8),uVar8) ^ 0xce;
    }
    else if (!SCARRY1(bVar4,bVar5)) {
      *(char *)puStack00000028 =
           (char)*puStack00000028 - (uVar21 < *(uint *)((int)puStack00000028 + (int)pbVar37));
      *(char *)puStack00000028 = '\0';
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    bVar6 = 9 < ((byte)uVar12 & 0xf) | bVar6;
    uVar14 = CONCAT31((int3)(uVar12 >> 8),(byte)uVar12 + bVar6 * '\x06') & 0xffffff0f;
    pbVar34 = (byte *)CONCAT22((short)(uVar14 >> 0x10),
                               CONCAT11((char)(uVar12 >> 8) + bVar6,(char)uVar14));
  }
  bRam36e3350c = bRam36e3350c | bVar5;
  piVar10 = (int *)(CONCAT22((short)((uint)pbVar34 >> 0x10),
                             CONCAT11((char)((ushort)pbVar34 % (ushort)*unaff_retaddr),
                                      (char)((ushort)pbVar34 / (ushort)*unaff_retaddr))) +
                   -0x28c73ec9);
  iVar11 = *(int *)unaff_retaddr;
  piVar33 = (int *)*(undefined6 *)unaff_retaddr;
  *piVar33 = *piVar33 >> (bVar39 & 0x1f);
  bVar38 = (bVar39 & 0x1f) != 0;
  uVar22 = 0xffffffff;
  bVar4 = (byte)piVar10;
  bVar39 = (byte)((uint)piVar10 >> 8);
  if ((bVar38 || iVar11 != -0x6c) && (!bVar38 || *piVar33 != 0)) {
    bVar6 = 9 < (bVar4 & 0xf) | bVar6;
    uVar12 = CONCAT31((int3)((uint)piVar10 >> 8),bVar4 + bVar6 * -6) & 0xffffff0f;
    cVar17 = (char)uVar12;
    puVar13 = (uint *)CONCAT22((short)(uVar12 >> 0x10),CONCAT11(bVar39 - bVar6,cVar17));
    *(char *)puVar13 = (char)*puVar13 + cVar17;
    *(char *)puVar13 = (char)*puVar13 + (char)(uVar21 >> 8);
    pcVar15 = (char *)((uint)puVar13 ^ *puVar13);
    *pcVar15 = *pcVar15 + (char)pcVar15;
    unaff_retaddr = unaff_retaddr + (uint)bVar40 * -2 + 1;
    *puStack00000028 = *puStack00000028 ^ (uint)unaff_retaddr;
    *(undefined2 *)unaff_retaddr = *(undefined2 *)unaff_retaddr;
    goto code_r0x009b4daa;
  }
  *(char *)piVar10 = *(char *)piVar10 + -1;
  *(byte *)piVar10 = *(char *)piVar10 + bVar4;
  pbVar34 = unaff_retaddr + *piVar10;
  *(byte *)(puStack00000028 + 0x1c8c30cc) =
       (byte)puStack00000028[0x1c8c30cc] ^ (byte)((uint)in_stack_0000002c >> 8);
  pcVar15 = (char *)(CONCAT31((int3)(CONCAT22((short)((uint)piVar10 >> 0x10),
                                              CONCAT11(bVar39 ^ bVar27,bVar4)) >> 8),bVar4) ^
                    0x36873692);
  bVar4 = (byte)pcVar15;
  DAT_7337d436 = bVar4;
  *pcVar15 = *pcVar15 + bVar4;
  pcVar15[0x33] = pcVar15[0x33] + (char)in_stack_0000002c;
  *(undefined1 *)((int)pcVar15 * 2) = *(undefined1 *)((int)pcVar15 * 2);
  *pcVar15 = *pcVar15 + bVar4;
  *(uint *)(pcVar15 + 0x31) = *(uint *)(pcVar15 + 0x31) ^ (uint)&stack0x00000028;
  *puStack00000028 = (uint)(pbVar34 + *puStack00000028);
  puVar29 = (undefined4 *)((uint)&stack0x0000002c ^ *(uint *)(pbVar34 + 0x33));
  pbVar37 = (byte *)((uint)in_stack_0000002c ^
                    *(uint *)((int)(puStack00000028 + 0xce70ce6) + (int)pbVar34));
  bVar6 = 9 < (bVar4 & 0xf) | bVar6;
  bVar4 = bVar4 + bVar6 * -6 ^ 0x13;
  puVar13 = (uint *)(piVar33 + (uint)bVar40 * -2 + 1);
  pbVar35 = pbVar34 + (uint)bVar40 * -8 + 4;
  *piVar33 = *(int *)pbVar34;
  bVar6 = 9 < (bVar4 & 0xf) | bVar6;
  uVar12 = CONCAT31((int3)((uint)pcVar15 >> 8),bVar4 + bVar6 * -6) & 0xffffff0f;
  bVar39 = (byte)uVar12;
  cVar17 = (char)((uint)pcVar15 >> 8) - bVar6;
  pbVar34 = (byte *)CONCAT22((short)(uVar12 >> 0x10),CONCAT11(cVar17,bVar39));
  *pbVar34 = *pbVar34 + bVar39;
  pbVar34[0x33] = pbVar34[0x33] + cVar17;
  *pbVar34 = *pbVar34 + bVar27;
  bVar4 = *pbVar34;
  *pbVar34 = *pbVar34 + bVar39;
  puVar28 = (uint *)CONCAT31((int3)((uint)pbVar34 >> 8),bVar39 + 0x30 + CARRY1(bVar4,bVar39));
  *puVar28 = *puVar28 << 0x1f;
  if (*puVar28 == 0) {
    puVar13 = (uint *)((uint)puVar13 & *puStack00000028);
    *puStack00000028 = *puStack00000028 ^ (uint)puVar13;
    pbVar37 = pbVar37 + -1;
  }
  else {
    *pbVar37 = *pbVar37 ^ (byte)((uint)pbVar37 >> 8);
    *(uint *)(pbVar35 + -0x7f) = *(uint *)(pbVar35 + -0x7f) ^ (uint)pbVar37;
    *(uint *)(pbVar35 + -0x4ce21cf) = *(uint *)(pbVar35 + -0x4ce21cf) ^ (uint)pbVar37;
    *(uint *)((int)(puStack00000028 + 0x18) + (int)pbVar35) =
         *(uint *)((int)(puStack00000028 + 0x18) + (int)pbVar35) ^ (uint)puStack00000028;
    puVar29 = (undefined4 *)
              ((uint)puVar29 ^ *(uint *)((int)(puStack00000028 + 0x1a) + (int)pbVar35));
    uVar12 = (uint)puVar28 ^ uRama0349332 ^ 0x360f3516;
    pbVar35 = pbVar35 + *puVar13;
    *(ushort *)((int)puVar29 + -4) = (ushort)bVar27;
    bVar6 = 9 < ((byte)uVar12 & 0xf) | bVar6;
    uVar8 = in((short)pbVar37);
    puVar28 = (uint *)CONCAT31(CONCAT21((short)(uVar12 >> 0x10),(char)(uVar12 >> 8) + bVar6),uVar8);
  }
  bVar39 = DAT_0000003f;
  bVar6 = 9 < (bVar27 & 0xf) | bVar6;
  cVar17 = -bVar6;
  puVar23 = (uint *)CONCAT31(CONCAT21(uVar19,cVar17),DAT_0000003f);
  puVar24 = (uint *)0xfffffffe;
  bVar4 = bVar6;
  if (SBORROW4((int)puVar28,0x3dc03da1)) {
LAB_009b4ede:
    *(byte *)puVar28 = (byte)*puVar28 | (byte)((uint)puVar28 >> 8);
    puVar16 = (uint *)(CONCAT31((int3)((uint)puVar23 >> 8),-bVar6) | 0x3b);
    *puVar28 = *puVar28 - (int)puVar13;
    puVar31 = puVar29;
  }
  else {
    *(char *)((int)puVar23 * 2) = *(char *)((int)puVar23 * 2) + (char)puVar28;
    cRamfffffffe = cRamfffffffe + cVar17;
    bVar39 = bVar39 ^ *(byte *)((int)puVar13 + 0x32);
    bVar4 = 9 < (bVar39 & 0xf) | bVar6;
    uVar12 = CONCAT31(CONCAT21(uVar19,cVar17),bVar39 + bVar4 * -6) & 0xffffff0f;
    uVar8 = (undefined1)uVar12;
    puVar29[-1] = puVar28;
    puVar13 = (uint *)puVar29[-1];
    pbVar35 = (byte *)*puVar29;
    uVar9 = puVar29[1];
    puVar28 = (uint *)puVar29[3];
    pbVar37 = (byte *)puVar29[4];
    puVar23 = (uint *)puVar29[5];
    puVar16 = (uint *)puVar29[6];
    puVar30 = puVar29 + 7;
    puVar24 = puVar23;
    puVar31 = puVar29 + 7;
    if ((int)(CONCAT31((int3)(CONCAT22((short)(uVar12 >> 0x10),CONCAT11(cVar17 - bVar4,uVar8)) >> 8)
                       ,uVar8) ^ 0x360835ac) < 1) {
      puVar29 = puVar29 + 8;
      bVar40 = (*puVar30 & 0x400) != 0;
      bVar4 = (*puVar30 & 0x10) != 0;
      puVar28 = (uint *)CONCAT22((short)((uint)puVar28 >> 0x10),
                                 CONCAT11((byte)((uint)puVar28 >> 8) ^ (byte)*puVar23,(char)puVar28)
                                );
      *(short *)puVar23 = (short)*puVar23;
      pbVar34 = (byte *)((int)puVar13 + (uint)bVar40 * -2 + 1);
      pbVar35 = pbVar35 + (uint)bVar40 * -2 + 1;
      bVar6 = (byte)((uint)pbVar37 >> 8) < *(byte *)((int)puVar16 + 0x3a);
      LOCK();
      puVar13 = *(uint **)pbVar37;
      *(byte **)pbVar37 = pbVar34;
      UNLOCK();
      puVar24 = puVar16;
      goto LAB_009b4ede;
    }
  }
  cVar17 = (char)puVar16;
  *(char *)puVar16 = (char)*puVar16 + cVar17;
  *(char *)((int)puVar16 + 0x440033) = *(char *)((int)puVar16 + 0x440033) + cVar17;
  *(char *)puVar16 = (char)*puVar16 + cVar17;
  iVar11 = CONCAT22((short)((uint)pbVar37 >> 0x10),
                    CONCAT11((char)((uint)pbVar37 >> 8) + (char)*puVar16,(char)pbVar37));
  *(byte *)(iVar11 + -0x40cf4bd1) = *(byte *)(iVar11 + -0x40cf4bd1) ^ (byte)((uint)puVar24 >> 8);
  *(byte *)(iVar11 + 0x31) = *(byte *)(iVar11 + 0x31) ^ (byte)((uint)puVar16 >> 8);
  iVar25 = CONCAT31((int3)((uint)(iVar11 + -1) >> 8),0x32);
  puVar23 = (uint *)((uint)pbVar35 & *puVar28);
  *(byte *)puVar28 = (byte)*puVar28 ^ (byte)((uint)(iVar11 + -1) >> 8);
  *(uint **)((int)puVar31 + -4) = puVar24;
  uVar12 = (uint)puVar16 ^ 0x366c3616;
  if (uVar12 == 0) {
    *(uint *)((int)puVar28 + 0x2132c032) = *(uint *)((int)puVar28 + 0x2132c032) ^ (uint)puVar23;
    puVar16 = (uint *)0x0;
code_r0x009b4f9b:
    puVar36 = (uint *)((uint)puVar23 ^ *puVar13);
    uVar21 = (uint)puVar28 ^ (uint)puVar13;
    puVar24 = (uint *)((uint)puVar24 ^ *puVar16);
    puVar26 = (uint *)(iVar25 + -1);
    bVar6 = bVar4 * '\x06' + 0x89 & 0xf;
    cVar17 = (char)((uint)puVar16 >> 8) + bVar4;
    *(undefined1 **)((int)puVar31 + -8) = (undefined1 *)((int)puVar31 + -4);
    bVar4 = 9 < bVar6 | bVar4;
    uVar12 = CONCAT31((int3)((uint)puVar16 >> 8),bVar6 + bVar4 * '\x06') & 0xffff000f;
    pbVar34 = (byte *)CONCAT22((short)(uVar12 >> 0x10),CONCAT11(cVar17 + bVar4,(char)uVar12));
    puVar28 = (uint *)CONCAT22((short)(uVar21 >> 0x10),
                               CONCAT11((byte)(uVar21 >> 8) & (byte)*puVar24,(char)uVar21));
    *(uint **)((int)puVar31 + -0xc) = puVar28;
    bVar38 = *(undefined1 **)(pbVar34 + 0x39) < (undefined1 *)((int)puVar31 + -0xc);
    puVar23 = puVar36;
    if (!SBORROW4((int)*(undefined1 **)(pbVar34 + 0x39),(int)((int)puVar31 + -0xc))) {
      puVar23 = (uint *)((int)puVar36 + (uint)bVar40 * -2 + 1);
      out((char)*puVar36,(short)puVar26);
      goto code_r0x009b4fd2;
    }
  }
  else {
    if (-1 < (int)uVar12) {
      *puVar13 = *puVar13 << 1;
      out(0x37,uVar12);
      return;
    }
    bVar4 = 9 < ((byte)puVar28 & 0xf) | bVar4;
    uVar21 = (uint)puVar28 >> 0x10;
    cVar17 = (char)((uint)puVar28 >> 8) + bVar4;
    puVar28 = (uint *)CONCAT22((short)(uVar12 >> 0x10),
                               CONCAT11((char)(uVar12 >> 8) + (byte)*puVar13,(char)uVar12));
    puVar26 = (uint *)(iVar25 + -1);
    bVar4 = 9 < (DAT_77384d37 & 0xf) | bVar4;
    uVar12 = CONCAT31(CONCAT21((short)uVar21,cVar17),DAT_77384d37 + bVar4 * -6) & 0xffffff0f;
    uVar19 = (undefined2)(uVar12 >> 0x10);
    bVar6 = (byte)uVar12;
    bVar39 = cVar17 - bVar4;
    pbVar34 = (byte *)CONCAT22(uVar19,CONCAT11(bVar39,bVar6));
    puVar24 = (uint *)((int)puVar24 + -1);
    if (puVar24 == (uint *)0x0 || puVar26 != (uint *)0x0) {
      *pbVar34 = *pbVar34 + bVar6;
      pbVar34[0x440033] = pbVar34[0x440033] + bVar39;
      bVar5 = *pbVar34;
      *pbVar34 = *pbVar34 + bVar6;
      iVar25 = CONCAT22((short)((uint)puVar26 >> 0x10),
                        CONCAT11((char)((uint)puVar26 >> 8) + *pbVar34 + CARRY1(bVar5,bVar6),
                                 (char)puVar26));
      *puVar24 = *puVar24 ^ 0xffffff94;
      *(uint *)(uVar9 + 0xb331c631) = *(uint *)(uVar9 + 0xb331c631) ^ (uint)puVar23;
      puVar16 = (uint *)((uint)CONCAT21(uVar19,bVar39 ^ *(byte *)puVar24) << 8);
      goto code_r0x009b4f9b;
    }
  }
  puVar28 = (uint *)CONCAT22((short)((uint)puVar28 >> 0x10),
                             CONCAT11(((char)((uint)puVar28 >> 8) - (byte)*puVar28) -
                                      (*puVar26 < 0x3b123a97),(char)puVar28));
  bVar4 = 9 < (byte)pbVar34 | bVar4;
  uVar12 = CONCAT31((int3)((uint)pbVar34 >> 8),(byte)pbVar34 + bVar4 * -6) & 0xffffff0f;
  bVar6 = (byte)uVar12;
  pbVar34 = (byte *)CONCAT22((short)(uVar12 >> 0x10),
                             CONCAT11((char)((uint)pbVar34 >> 8) - bVar4,bVar6));
  pbVar34[0x740033] = pbVar34[0x740033] + (char)((uint)puVar26 >> 8);
  bVar38 = CARRY1(*pbVar34,bVar6);
  *pbVar34 = *pbVar34 + bVar6;
  puVar24 = (uint *)((int)puVar24 + -1);
  if (puVar24 != (uint *)0x0) {
    puVar23 = (uint *)((int)puVar23 - *puVar23);
    bVar38 = false;
    *puVar23 = *puVar23 ^ 0xffffff96;
  }
code_r0x009b4fd2:
  uVar21 = (int)puVar23 + (uint)bVar38 + *puVar24;
  *(uint *)(uVar21 + 0x31) = *(uint *)(uVar21 + 0x31) ^ (uint)puVar26;
  *puVar26 = *puVar26 & uVar21;
  uVar12 = (uint)puVar26 ^ *(uint *)((int)puVar24 + 0x4333c833);
  bVar6 = (byte)(uVar12 >> 8) ^ DAT_355d354a;
  *(uint *)(uVar21 ^ *puVar26) = *(uint *)(uVar21 ^ *puVar26) ^ 0xffffff96;
  *(byte *)puVar13 = (byte)*puVar13 | bVar6;
  if ((byte)uVar12 != *(byte *)((int)puVar13 + 0x3a)) {
    *puVar28 = *puVar28 << ((byte)puVar24 & 0x1f);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(byte *)puVar13 = ((byte)pbVar34 & 0x31) + 1 ^ 0x9c | 0x37;
  pcVar2 = (code *)swi(1);
  in_stack_0000002c = piVar33;
  (*pcVar2)();
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::RenderTargetPushEmpty
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009b5002) overlaps instruction at (ram,0x009b4ffe)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x009b4f5c) */
/* WARNING: Removing unreachable block (ram,0x009b4c91) */
/* WARNING: Removing unreachable block (ram,0x009b4d18) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CVisionViewportDx9::RenderTargetPushEmpty(CVisionViewportDx9 *this,CVisionViewportDx9 *param_1)
{
{
  longlong lVar1;
  code *pcVar2;
  undefined3 uVar3;
  undefined3 uVar4;
  byte bVar5;
  byte bVar6;
  undefined1 uVar7;
  char cVar15;
  undefined4 in_EAX;
  int *piVar8;
  int iVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  char *pcVar13;
  uint *puVar14;
  undefined2 uVar16;
  byte bVar17;
  undefined4 uVar18;
  uint *puVar19;
  uint *puVar20;
  byte bVar24;
  undefined4 in_EDX;
  byte *pbVar21;
  int iVar22;
  uint *puVar23;
  undefined4 unaff_EBX;
  CVisionViewportDx9 *pCVar25;
  uint *puVar26;
  uint uVar27;
  undefined4 *puVar28;
  uint *puVar29;
  undefined4 *puVar30;
  uint uVar31;
  undefined4 *unaff_ESI;
  byte *pbVar32;
  byte *pbVar33;
  uint *puVar34;
  int *unaff_EDI;
  byte *pbVar35;
  int *piVar36;
  byte bVar37;
  bool bVar38;
  byte in_AF;
  bool bVar39;
  char *unaff_retaddr;
  int *in_stack_00000008;
  undefined4 auStack_2a [10];
  
  bVar39 = false;
  pbVar32 = (byte *)(unaff_ESI + 1);
  out(*unaff_ESI,(short)in_EDX);
  bVar37 = 9 < ((byte)in_EAX & 0xf) | in_AF;
  uVar10 = CONCAT31((int3)((uint)in_EAX >> 8),(byte)in_EAX + bVar37 * '\x06') & 0xffffff0f;
  piVar8 = (int *)CONCAT22((short)(uVar10 >> 0x10),
                           CONCAT11((char)((uint)in_EAX >> 8) + bVar37,(char)uVar10));
  pbVar33 = (byte *)CONCAT31((int3)((uint)unaff_EBX >> 8),0x37);
  *piVar8 = *piVar8 >> 1;
  iVar9 = (int)piVar8 + (0x34c18bc1 - (uint)(piVar8 < (int *)0x3dc63d6f));
  bVar37 = 9 < ((byte)iVar9 & 0xf) | bVar37;
  uVar10 = CONCAT31((int3)((uint)iVar9 >> 8),(byte)iVar9 + bVar37 * -6) & 0xffffff0f;
  pbVar35 = (byte *)(*unaff_EDI * -0x7d);
  bVar5 = 9 < (byte)uVar10 | bVar37;
  uVar3 = CONCAT21((short)(uVar10 >> 0x10),((char)((uint)iVar9 >> 8) - bVar37) - bVar5);
  bVar5 = 9 < ((byte)this & 0xf) | bVar5;
  bVar17 = (byte)this + bVar5 * -6 & 0xf;
  pcVar13 = (char *)CONCAT31(uVar3,0x3f);
  bVar37 = 9 < bVar17 | bVar5;
  uVar10 = CONCAT31((int3)((uint)this >> 8),bVar17 + bVar37 * -6) & 0xffff000f;
  lVar1 = CONCAT44(in_EDX,CONCAT22((short)(uVar10 >> 0x10),
                                   CONCAT11(((char)((uint)this >> 8) - bVar5) - bVar37,(char)uVar10)
                                  )) % (longlong)*(int *)pbVar35;
  bVar5 = (byte)unaff_retaddr;
  *unaff_retaddr = *unaff_retaddr + bVar5;
  *pcVar13 = *pcVar13 + '?';
  *pbVar33 = *pbVar33 ^ 0x37;
  DAT_9c70676f = DAT_9c70676f ^ bVar5;
  uVar4 = (undefined3)((uint)unaff_retaddr >> 8);
  bVar24 = (byte)((uint)unaff_retaddr >> 8) ^ 0x3f;
  bVar5 = bVar5 ^ (byte)((ulonglong)lVar1 >> 8);
  DAT_3a312531 = DAT_3a312531 ^ bVar5;
  *(uint *)(pbVar33 + 0x31) = *(uint *)(pbVar33 + 0x31) ^ (uint)pbVar33;
  *(uint *)(pbVar35 + -0x1cce36cf) = *(uint *)(pbVar35 + -0x1cce36cf) ^ (uint)&param_1;
  uVar10 = (uint)lVar1 ^ (uint)pbVar32;
  *(uint *)(pcVar13 + -0x3ccd58ce) =
       *(uint *)(pcVar13 + -0x3ccd58ce) ^ CONCAT31(uVar4,bVar5) ^ 0x3f00;
  uVar27 = CONCAT31(uVar4,bVar5) ^ 0x3f37;
  uVar16 = (undefined2)((uint)unaff_EBX >> 0x10);
  pCVar25 = (CVisionViewportDx9 *)CONCAT22(uVar16,0x37);
  bVar17 = *pbVar32 ^ 0x3f;
  uVar31 = *(uint *)(pCVar25 + 0x33fc33) ^ 0xe53fd33f;
  out((short)uVar27,(byte)uVar10 ^ 0x10);
  if (CONCAT31(uVar3,*pbVar32) != 0x3f) {
    pcVar2 = (code *)swi(1);
    iVar9 = (*pcVar2)();
    return iVar9;
  }
  _DAT_ca35b135 = uVar10 ^ 0x3883386c;
  puVar11 = (uint *)(uVar10 ^ 0xef30e2a);
  bVar6 = (byte)puVar11;
  if (puVar11 == (uint *)0x0) {
    *pbVar32 = *pbVar32 + (bVar5 ^ 0x37);
    uVar18 = 0;
code_r0x009b4daa:
    bVar37 = 9 < ((byte)uVar18 & 0xf) | bVar37;
    uVar10 = CONCAT31((int3)((uint)uVar18 >> 8),(byte)uVar18 + bVar37 * '\x06') & 0xffffff0f;
    *(undefined4 *)
     CONCAT22((short)(uVar10 >> 0x10),CONCAT11((char)((uint)uVar18 >> 8) + bVar37,(char)uVar10)) =
         *(undefined4 *)pbVar32;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((int)puVar11 < 0) {
    out(0x3f,puVar11);
    *(byte *)puVar11 = (char)*puVar11 + bVar6;
    *(byte *)puVar11 = (char)*puVar11 + (bVar5 ^ 0x37);
    pbVar33 = (byte *)((uint)puVar11 ^ *puVar11);
    bVar5 = (byte)pbVar33;
    *pbVar33 = *pbVar33 ^ bVar5;
    *pbVar33 = *pbVar33 + bVar5;
    *pbVar35 = bVar5;
    unaff_ESI[0xdf38d14] = unaff_ESI[0xdf38d14] ^ (uint)pbVar32;
  }
  else {
    _DAT_fa37b237 =
         CONCAT22((short)((uint)puVar11 >> 0x10),
                  CONCAT11(bVar37 << 4 | ((POPCOUNT((uint)puVar11 & 0xff) & 1U) == 0) << 2,bVar6)) |
         0x200;
    bVar5 = *pbVar35;
    *pbVar35 = *pbVar35 + bVar24;
    bVar37 = 9 < (bVar6 & 0xf) | bVar37;
    uVar10 = CONCAT31((int3)(_DAT_fa37b237 >> 8),bVar6 + bVar37 * '\x06') & 0xffffff0f;
    uVar7 = (undefined1)uVar10;
    uVar10 = CONCAT22((short)(uVar10 >> 0x10),CONCAT11((char)(_DAT_fa37b237 >> 8) + bVar37,uVar7));
    if (*pbVar35 == 0) {
      *(undefined4 *)(&stack0xffffffd2 + (int)pbVar32) =
           *(undefined4 *)(&stack0xffffffd2 + (int)pbVar32);
    }
    else if ((char)*pbVar35 < '\0') {
      uVar10 = CONCAT31((int3)(uVar10 >> 8),uVar7) ^ 0xce;
    }
    else if (!SCARRY1(bVar5,bVar24)) {
      *pCVar25 = (CVisionViewportDx9)((char)*pCVar25 - (uVar27 < *(uint *)(pCVar25 + (int)pbVar35)))
      ;
      *pCVar25 = (CVisionViewportDx9)0x0;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    bVar37 = 9 < ((byte)uVar10 & 0xf) | bVar37;
    uVar12 = CONCAT31((int3)(uVar10 >> 8),(byte)uVar10 + bVar37 * '\x06') & 0xffffff0f;
    pbVar33 = (byte *)CONCAT22((short)(uVar12 >> 0x10),
                               CONCAT11((char)(uVar10 >> 8) + bVar37,(char)uVar12));
  }
  bRam36e3350c = bRam36e3350c | bVar24;
  piVar8 = (int *)(CONCAT22((short)((uint)pbVar33 >> 0x10),
                            CONCAT11((char)((ushort)pbVar33 % (ushort)*pbVar32),
                                     (char)((ushort)pbVar33 / (ushort)*pbVar32))) + -0x28c73ec9);
  iVar9 = *(int *)pbVar32;
  piVar36 = (int *)*(undefined6 *)pbVar32;
  *piVar36 = *piVar36 >> (bVar17 & 0x1f);
  bVar38 = (bVar17 & 0x1f) != 0;
  uVar18 = 0xffffffff;
  bVar5 = (byte)piVar8;
  if ((bVar38 || iVar9 != -0x6c) && (!bVar38 || *piVar36 != 0)) {
    bVar37 = 9 < (bVar5 & 0xf) | bVar37;
    uVar10 = CONCAT31((int3)((uint)piVar8 >> 8),bVar5 + bVar37 * -6) & 0xffffff0f;
    cVar15 = (char)uVar10;
    puVar11 = (uint *)CONCAT22((short)(uVar10 >> 0x10),
                               CONCAT11((char)((uint)piVar8 >> 8) - bVar37,cVar15));
    *(char *)puVar11 = (char)*puVar11 + cVar15;
    *(char *)puVar11 = (char)*puVar11 + (char)(uVar27 >> 8);
    pcVar13 = (char *)((uint)puVar11 ^ *puVar11);
    *pcVar13 = *pcVar13 + (char)pcVar13;
    pbVar32 = (byte *)((int)unaff_ESI + 5);
    *(uint *)pCVar25 = *(uint *)pCVar25 ^ (uint)pbVar32;
    *(undefined2 *)pbVar32 = *(undefined2 *)pbVar32;
    goto code_r0x009b4daa;
  }
  *(char *)piVar8 = *(char *)piVar8 + -1;
  *(byte *)piVar8 = *(char *)piVar8 + bVar5;
  pbVar32 = pbVar32 + *piVar8;
  pCVar25[0x7230c330] =
       (CVisionViewportDx9)((byte)pCVar25[0x7230c330] ^ (byte)((uint)in_stack_00000008 >> 8));
  pcVar13 = (char *)((uint)piVar8 ^ 0x36870192);
  bVar5 = (byte)pcVar13;
  DAT_7337d436 = bVar5;
  *pcVar13 = *pcVar13 + bVar5;
  pcVar13[0x33] = pcVar13[0x33] + (char)in_stack_00000008;
  *(undefined1 *)((int)pcVar13 * 2) = *(undefined1 *)((int)pcVar13 * 2);
  *pcVar13 = *pcVar13 + bVar5;
  *(uint *)(pcVar13 + 0x31) = *(uint *)(pcVar13 + 0x31) ^ (uint)&param_1;
  *(byte **)pCVar25 = pbVar32 + *(uint *)pCVar25;
  puVar28 = (undefined4 *)((uint)&stack0x00000008 ^ *(uint *)(pbVar32 + 0x33));
  pbVar21 = (byte *)((uint)in_stack_00000008 ^ *(uint *)(pCVar25 + 0x339c3398 + (int)pbVar32));
  bVar37 = 9 < (bVar5 & 0xf) | bVar37;
  bVar5 = bVar5 + bVar37 * -6 ^ 0x13;
  puVar11 = (uint *)(piVar36 + 1);
  pbVar33 = pbVar32 + 4;
  *piVar36 = *(int *)pbVar32;
  bVar37 = 9 < (bVar5 & 0xf) | bVar37;
  uVar10 = CONCAT31((int3)((uint)pcVar13 >> 8),bVar5 + bVar37 * -6) & 0xffffff0f;
  bVar17 = (byte)uVar10;
  cVar15 = (char)((uint)pcVar13 >> 8) - bVar37;
  pbVar35 = (byte *)CONCAT22((short)(uVar10 >> 0x10),CONCAT11(cVar15,bVar17));
  *pbVar35 = *pbVar35 + bVar17;
  pbVar35[0x33] = pbVar35[0x33] + cVar15;
  *pbVar35 = *pbVar35 + 0x37;
  bVar5 = *pbVar35;
  *pbVar35 = *pbVar35 + bVar17;
  puVar26 = (uint *)CONCAT31((int3)((uint)pbVar35 >> 8),bVar17 + 0x30 + CARRY1(bVar5,bVar17));
  *puVar26 = *puVar26 << 0x1f;
  if (*puVar26 == 0) {
    puVar11 = (uint *)((uint)puVar11 & *(uint *)pCVar25);
    *(uint *)pCVar25 = *(uint *)pCVar25 ^ (uint)puVar11;
    pbVar21 = pbVar21 + -1;
  }
  else {
    *pbVar21 = *pbVar21 ^ (byte)((uint)pbVar21 >> 8);
    *(uint *)(pbVar32 + -0x7b) = *(uint *)(pbVar32 + -0x7b) ^ (uint)pbVar21;
    *(uint *)(pbVar32 + -0x4ce21cb) = *(uint *)(pbVar32 + -0x4ce21cb) ^ (uint)pbVar21;
    *(uint *)(pCVar25 + 0x60 + (int)pbVar33) =
         *(uint *)(pCVar25 + 0x60 + (int)pbVar33) ^ (uint)pCVar25;
    puVar28 = (undefined4 *)((uint)puVar28 ^ *(uint *)(pCVar25 + 0x68 + (int)pbVar33));
    uVar10 = (uint)puVar26 ^ uRama0349332 ^ 0x360f3516;
    pbVar33 = pbVar33 + *puVar11;
    *(undefined2 *)((int)puVar28 + -4) = 0x37;
    bVar37 = 9 < ((byte)uVar10 & 0xf) | bVar37;
    uVar7 = in((short)pbVar21);
    puVar26 = (uint *)CONCAT31(CONCAT21((short)(uVar10 >> 0x10),(char)(uVar10 >> 8) + bVar37),uVar7)
    ;
  }
  bVar17 = DAT_0000003f;
  cVar15 = -bVar37;
  uVar3 = CONCAT21(uVar16,cVar15);
  puVar19 = (uint *)CONCAT31(uVar3,DAT_0000003f);
  puVar20 = (uint *)0xfffffffe;
  bVar5 = bVar37;
  if (SBORROW4((int)puVar26,0x3dc03da1)) {
LAB_009b4ede:
    *(byte *)puVar26 = (byte)*puVar26 | (byte)((uint)puVar26 >> 8);
    puVar14 = (uint *)(CONCAT31((int3)((uint)puVar19 >> 8),-bVar37) | 0x3b);
    *puVar26 = *puVar26 - (int)puVar11;
    puVar30 = puVar28;
  }
  else {
    *(char *)((int)puVar19 * 2) = *(char *)((int)puVar19 * 2) + (char)puVar26;
    cRamfffffffe = cRamfffffffe + cVar15;
    bVar17 = bVar17 ^ *(byte *)((int)puVar11 + 0x32);
    bVar5 = 9 < (bVar17 & 0xf) | bVar37;
    uVar10 = CONCAT31(uVar3,bVar17 + bVar5 * -6) & 0xffffff0f;
    uVar7 = (undefined1)uVar10;
    puVar28[-1] = puVar26;
    puVar11 = (uint *)puVar28[-1];
    pbVar33 = (byte *)*puVar28;
    uVar31 = puVar28[1];
    puVar26 = (uint *)puVar28[3];
    pbVar21 = (byte *)puVar28[4];
    puVar19 = (uint *)puVar28[5];
    puVar14 = (uint *)puVar28[6];
    puVar29 = puVar28 + 7;
    puVar20 = puVar19;
    puVar30 = puVar28 + 7;
    if ((int)(CONCAT31((int3)(CONCAT22((short)(uVar10 >> 0x10),CONCAT11(cVar15 - bVar5,uVar7)) >> 8)
                       ,uVar7) ^ 0x360835ac) < 1) {
      puVar28 = puVar28 + 8;
      bVar39 = (*puVar29 & 0x400) != 0;
      bVar5 = (*puVar29 & 0x10) != 0;
      puVar26 = (uint *)CONCAT22((short)((uint)puVar26 >> 0x10),
                                 CONCAT11((byte)((uint)puVar26 >> 8) ^ (byte)*puVar19,(char)puVar26)
                                );
      *(short *)puVar19 = (short)*puVar19;
      pbVar32 = (byte *)((int)puVar11 + (uint)bVar39 * -2 + 1);
      pbVar33 = pbVar33 + (uint)bVar39 * -2 + 1;
      bVar37 = (byte)((uint)pbVar21 >> 8) < *(byte *)((int)puVar14 + 0x3a);
      LOCK();
      puVar11 = *(uint **)pbVar21;
      *(byte **)pbVar21 = pbVar32;
      UNLOCK();
      puVar20 = puVar14;
      goto LAB_009b4ede;
    }
  }
  cVar15 = (char)puVar14;
  *(char *)puVar14 = (char)*puVar14 + cVar15;
  *(char *)((int)puVar14 + 0x440033) = *(char *)((int)puVar14 + 0x440033) + cVar15;
  *(char *)puVar14 = (char)*puVar14 + cVar15;
  iVar9 = CONCAT22((short)((uint)pbVar21 >> 0x10),
                   CONCAT11((char)((uint)pbVar21 >> 8) + (char)*puVar14,(char)pbVar21));
  *(byte *)(iVar9 + -0x40cf4bd1) = *(byte *)(iVar9 + -0x40cf4bd1) ^ (byte)((uint)puVar20 >> 8);
  *(byte *)(iVar9 + 0x31) = *(byte *)(iVar9 + 0x31) ^ (byte)((uint)puVar14 >> 8);
  iVar22 = CONCAT31((int3)((uint)(iVar9 + -1) >> 8),0x32);
  puVar19 = (uint *)((uint)pbVar33 & *puVar26);
  *(byte *)puVar26 = (byte)*puVar26 ^ (byte)((uint)(iVar9 + -1) >> 8);
  *(uint **)((int)puVar30 + -4) = puVar20;
  uVar10 = (uint)puVar14 ^ 0x366c3616;
  if (uVar10 == 0) {
    *(uint *)((int)puVar26 + 0x2132c032) = *(uint *)((int)puVar26 + 0x2132c032) ^ (uint)puVar19;
    puVar14 = (uint *)0x0;
code_r0x009b4f9b:
    puVar34 = (uint *)((uint)puVar19 ^ *puVar11);
    uVar27 = (uint)puVar26 ^ (uint)puVar11;
    puVar20 = (uint *)((uint)puVar20 ^ *puVar14);
    puVar23 = (uint *)(iVar22 + -1);
    bVar37 = bVar5 * '\x06' + 0x89 & 0xf;
    cVar15 = (char)((uint)puVar14 >> 8) + bVar5;
    *(undefined1 **)((int)puVar30 + -8) = (undefined1 *)((int)puVar30 + -4);
    bVar5 = 9 < bVar37 | bVar5;
    uVar10 = CONCAT31((int3)((uint)puVar14 >> 8),bVar37 + bVar5 * '\x06') & 0xffff000f;
    pbVar32 = (byte *)CONCAT22((short)(uVar10 >> 0x10),CONCAT11(cVar15 + bVar5,(char)uVar10));
    puVar26 = (uint *)CONCAT22((short)(uVar27 >> 0x10),
                               CONCAT11((byte)(uVar27 >> 8) & (byte)*puVar20,(char)uVar27));
    *(uint **)((int)puVar30 + -0xc) = puVar26;
    bVar38 = *(undefined1 **)(pbVar32 + 0x39) < (undefined1 *)((int)puVar30 + -0xc);
    puVar19 = puVar34;
    if (!SBORROW4((int)*(undefined1 **)(pbVar32 + 0x39),(int)((int)puVar30 + -0xc))) {
      puVar19 = (uint *)((int)puVar34 + (uint)bVar39 * -2 + 1);
      out((char)*puVar34,(short)puVar23);
      goto code_r0x009b4fd2;
    }
  }
  else {
    if (-1 < (int)uVar10) {
      *puVar11 = *puVar11 << 1;
      out(0x37,uVar10);
      return uVar10;
    }
    bVar5 = 9 < ((byte)puVar26 & 0xf) | bVar5;
    uVar27 = (uint)puVar26 >> 0x10;
    cVar15 = (char)((uint)puVar26 >> 8) + bVar5;
    puVar26 = (uint *)CONCAT22((short)(uVar10 >> 0x10),
                               CONCAT11((char)(uVar10 >> 8) + (byte)*puVar11,(char)uVar10));
    puVar23 = (uint *)(iVar22 + -1);
    bVar5 = 9 < (DAT_77384d37 & 0xf) | bVar5;
    uVar10 = CONCAT31(CONCAT21((short)uVar27,cVar15),DAT_77384d37 + bVar5 * -6) & 0xffffff0f;
    uVar16 = (undefined2)(uVar10 >> 0x10);
    bVar37 = (byte)uVar10;
    bVar17 = cVar15 - bVar5;
    pbVar32 = (byte *)CONCAT22(uVar16,CONCAT11(bVar17,bVar37));
    puVar20 = (uint *)((int)puVar20 + -1);
    if (puVar20 == (uint *)0x0 || puVar23 != (uint *)0x0) {
      *pbVar32 = *pbVar32 + bVar37;
      pbVar32[0x440033] = pbVar32[0x440033] + bVar17;
      bVar24 = *pbVar32;
      *pbVar32 = *pbVar32 + bVar37;
      iVar22 = CONCAT22((short)((uint)puVar23 >> 0x10),
                        CONCAT11((char)((uint)puVar23 >> 8) + *pbVar32 + CARRY1(bVar24,bVar37),
                                 (char)puVar23));
      *puVar20 = *puVar20 ^ 0xffffff94;
      *(uint *)(uVar31 + 0xb331c631) = *(uint *)(uVar31 + 0xb331c631) ^ (uint)puVar19;
      puVar14 = (uint *)((uint)CONCAT21(uVar16,bVar17 ^ *(byte *)puVar20) << 8);
      goto code_r0x009b4f9b;
    }
  }
  puVar26 = (uint *)CONCAT22((short)((uint)puVar26 >> 0x10),
                             CONCAT11(((char)((uint)puVar26 >> 8) - (byte)*puVar26) -
                                      (*puVar23 < 0x3b123a97),(char)puVar26));
  bVar5 = 9 < (byte)pbVar32 | bVar5;
  uVar10 = CONCAT31((int3)((uint)pbVar32 >> 8),(byte)pbVar32 + bVar5 * -6) & 0xffffff0f;
  bVar37 = (byte)uVar10;
  pbVar32 = (byte *)CONCAT22((short)(uVar10 >> 0x10),
                             CONCAT11((char)((uint)pbVar32 >> 8) - bVar5,bVar37));
  pbVar32[0x740033] = pbVar32[0x740033] + (char)((uint)puVar23 >> 8);
  bVar38 = CARRY1(*pbVar32,bVar37);
  *pbVar32 = *pbVar32 + bVar37;
  puVar20 = (uint *)((int)puVar20 + -1);
  if (puVar20 != (uint *)0x0) {
    puVar19 = (uint *)((int)puVar19 - *puVar19);
    bVar38 = false;
    *puVar19 = *puVar19 ^ 0xffffff96;
  }
code_r0x009b4fd2:
  uVar27 = (int)puVar19 + (uint)bVar38 + *puVar20;
  *(uint *)(uVar27 + 0x31) = *(uint *)(uVar27 + 0x31) ^ (uint)puVar23;
  *puVar23 = *puVar23 & uVar27;
  uVar10 = (uint)puVar23 ^ *(uint *)((int)puVar20 + 0x4333c833);
  bVar37 = (byte)(uVar10 >> 8) ^ DAT_355d354a;
  *(uint *)(uVar27 ^ *puVar23) = *(uint *)(uVar27 ^ *puVar23) ^ 0xffffff96;
  *(byte *)puVar11 = (byte)*puVar11 | bVar37;
  if ((byte)uVar10 != *(byte *)((int)puVar11 + 0x3a)) {
    *puVar26 = *puVar26 << ((byte)puVar20 & 0x1f);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(byte *)puVar11 = ((byte)pbVar32 & 0x31) + 1 ^ 0x9c | 0x37;
  pcVar2 = (code *)swi(1);
  param_1 = pCVar25;
  in_stack_00000008 = piVar36;
  iVar9 = (*pcVar2)();
  return iVar9;
}
}

// =================================================
// Function: CVisionViewportDx9::RenderTargetSet
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009b5002) overlaps instruction at (ram,0x009b4ffe)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x009b4f5c) */

int __thiscall
CVisionViewportDx9::RenderTargetSet
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,IDirect3DSurface9 *param_2,
          IDirect3DSurface9 *param_3,CDx9TextureKeeper *param_4,CDx9TextureKeeper *param_5,
          ulong *param_6)
{
{
  int *piVar1;
  code *pcVar2;
  undefined3 uVar3;
  undefined1 uVar4;
  byte bVar5;
  ushort uVar6;
  int in_EAX;
  char *pcVar7;
  char cVar12;
  uint uVar8;
  char cVar13;
  CVisionViewportDx9 *pCVar9;
  undefined2 uVar14;
  uint *puVar10;
  int iVar11;
  CVisionViewportDx9 *pCVar15;
  CVisionViewportDx9 *pCVar16;
  uint in_EDX;
  byte *pbVar17;
  int iVar18;
  uint *puVar19;
  byte bVar20;
  uint unaff_EBX;
  uint *puVar21;
  uint uVar22;
  undefined4 *puVar23;
  uint *puVar24;
  undefined4 *puVar25;
  int unaff_EBP;
  byte *unaff_ESI;
  byte *pbVar26;
  byte *pbVar27;
  uint *puVar28;
  uint *puVar29;
  int *piVar30;
  uint *puVar31;
  byte *pbVar32;
  byte bVar33;
  bool bVar34;
  byte in_AF;
  byte bVar35;
  bool bVar36;
  uint unaff_retaddr;
  uint *puStack_4;
  
  bVar36 = false;
  pcVar7 = (char *)(in_EAX + -1);
  *pcVar7 = *pcVar7 + (char)pcVar7;
  *unaff_ESI = *unaff_ESI + (char)in_EDX;
  bVar35 = (byte)((uint)pcVar7 >> 8);
  this[0x31] = (CVisionViewportDx9)((byte)this[0x31] ^ bVar35);
  puStack_4 = (uint *)(unaff_EBX ^ (uint)&stack0x00000000 ^ (uint)unaff_ESI);
  *(uint *)(in_EAX + 0x33) = *(uint *)(in_EAX + 0x33) ^ (uint)this;
  uVar6 = (ushort)(in_EDX ^ 0x350835f8) | 0x35;
  if (this == (CVisionViewportDx9 *)0x0) {
    pCVar15 = (CVisionViewportDx9 *)0x0;
code_r0x009b4daa:
    bVar35 = 9 < ((byte)pCVar15 & 0xf) | in_AF;
    uVar8 = CONCAT31((int3)((uint)pCVar15 >> 8),(byte)pCVar15 + bVar35 * '\x06') & 0xffffff0f;
    *(undefined4 *)
     CONCAT22((short)(uVar8 >> 0x10),CONCAT11((char)((uint)pCVar15 >> 8) + bVar35,(char)uVar8)) =
         *(undefined4 *)unaff_ESI;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  piVar1 = (int *)(CONCAT22((short)((in_EDX ^ 0x350835f8) >> 0x10),
                            CONCAT11((char)(uVar6 % (ushort)*unaff_ESI),(char)(uVar6 / *unaff_ESI)))
                  + -0x28c73ec9);
  iVar11 = *(int *)unaff_ESI;
  piVar30 = (int *)*(undefined6 *)unaff_ESI;
  *piVar30 = *piVar30 >> ((byte)this & 0x1f);
  bVar34 = ((uint)this & 0x1f) != 0;
  pCVar15 = this + -1;
  bVar33 = (byte)piVar1;
  bVar5 = (byte)((uint)piVar1 >> 8);
  if (pCVar15 == (CVisionViewportDx9 *)0x0 ||
      (bVar34 || iVar11 != -0x6c) && (!bVar34 || *piVar30 != 0)) {
    in_AF = 9 < (bVar33 & 0xf) | in_AF;
    uVar8 = CONCAT31((int3)((uint)piVar1 >> 8),bVar33 + in_AF * -6) & 0xffffff0f;
    cVar12 = (char)uVar8;
    puVar31 = (uint *)CONCAT22((short)(uVar8 >> 0x10),CONCAT11(bVar5 - in_AF,cVar12));
    *(char *)puVar31 = (char)*puVar31 + cVar12;
    *(byte *)puVar31 = (char)*puVar31 + bVar35;
    pcVar7 = (char *)((uint)puVar31 ^ *puVar31);
    *pcVar7 = *pcVar7 + (char)pcVar7;
    unaff_ESI = unaff_ESI + 1;
    *puStack_4 = *puStack_4 ^ (uint)unaff_ESI;
    *(undefined2 *)unaff_ESI = *(undefined2 *)unaff_ESI;
    goto code_r0x009b4daa;
  }
  *(byte *)piVar1 = *(char *)piVar1 + (byte)pCVar15;
  *(byte *)piVar1 = *(char *)piVar1 + bVar33;
  pbVar26 = unaff_ESI + *piVar1;
  *(byte *)(puStack_4 + 0x1c8c30cc) = (byte)puStack_4[0x1c8c30cc] ^ (byte)(unaff_retaddr >> 8);
  *(uint *)pCVar15 = *(uint *)pCVar15 ^ (uint)pCVar15;
  bVar20 = (byte)puStack_4;
  pcVar7 = (char *)(CONCAT31((int3)(CONCAT22((short)((uint)piVar1 >> 0x10),
                                             CONCAT11(bVar5 ^ bVar20,bVar33)) >> 8),bVar33) ^
                   0x36873692);
  bVar35 = (byte)pcVar7;
  DAT_7337d436 = bVar35;
  *pcVar7 = *pcVar7 + bVar35;
  pcVar7[0x33] = pcVar7[0x33] + (char)unaff_retaddr;
  cVar13 = (char)((uint)puStack_4 >> 8);
  *(char *)((int)pcVar7 * 2) = *(char *)((int)pcVar7 * 2) + cVar13;
  *pcVar7 = *pcVar7 + bVar35;
  *(uint *)(pcVar7 + 0x31) = *(uint *)(pcVar7 + 0x31) ^ (uint)&puStack_4;
  *puStack_4 = (uint)(pbVar26 + *puStack_4);
  puVar23 = (undefined4 *)((uint)&stack0x00000000 ^ *(uint *)(pbVar26 + 0x33));
  pbVar17 = (byte *)(unaff_retaddr ^ *(uint *)((int)(puStack_4 + 0xce70ce6) + (int)pbVar26));
  bVar33 = 9 < (bVar35 & 0xf) | in_AF;
  bVar35 = bVar35 + bVar33 * -6 ^ 0x13;
  puVar31 = (uint *)(piVar30 + 1);
  pbVar27 = pbVar26 + 4;
  *piVar30 = *(int *)pbVar26;
  bVar33 = 9 < (bVar35 & 0xf) | bVar33;
  uVar8 = CONCAT31((int3)((uint)pcVar7 >> 8),bVar35 + bVar33 * -6) & 0xffffff0f;
  bVar5 = (byte)uVar8;
  cVar12 = (char)((uint)pcVar7 >> 8) - bVar33;
  pbVar32 = (byte *)CONCAT22((short)(uVar8 >> 0x10),CONCAT11(cVar12,bVar5));
  *pbVar32 = *pbVar32 + bVar5;
  pbVar32[0x33] = pbVar32[0x33] + cVar12;
  *pbVar32 = *pbVar32 + bVar20;
  bVar35 = *pbVar32;
  *pbVar32 = *pbVar32 + bVar5;
  cVar12 = bVar5 + 0x30 + CARRY1(bVar35,bVar5);
  puVar21 = (uint *)CONCAT31((int3)((uint)pbVar32 >> 8),cVar12);
  *puVar21 = *puVar21 << ((byte)pCVar15 & 0x1f);
  bVar34 = ((uint)pCVar15 & 0x1f) != 0;
  pCVar15 = this + -2;
  if (pCVar15 != (CVisionViewportDx9 *)0x0 && (!bVar34 && cVar12 == '\0' || bVar34 && *puVar21 == 0)
     ) {
    puVar31 = (uint *)((uint)puVar31 & *puStack_4);
    *puStack_4 = *puStack_4 ^ (uint)puVar31;
    pbVar17 = pbVar17 + -1;
  }
  else {
    *pbVar17 = *pbVar17 ^ (byte)((uint)pbVar17 >> 8);
    *(uint *)(this + -0x7f + (int)pbVar27) = *(uint *)(this + -0x7f + (int)pbVar27) ^ (uint)pbVar17;
    *(uint *)(pbVar26 + -0x4ce21cb) = *(uint *)(pbVar26 + -0x4ce21cb) ^ (uint)pbVar17;
    *(uint *)((int)(puStack_4 + 0x18) + (int)pbVar27) =
         *(uint *)((int)(puStack_4 + 0x18) + (int)pbVar27) ^ (uint)puStack_4;
    puVar23 = (undefined4 *)((uint)puVar23 ^ *(uint *)((int)(puStack_4 + 0x1a) + (int)pbVar27));
    uVar8 = (uint)puVar21 ^ *(uint *)(this + -0x5fcb6cce) ^ 0x360f3516;
    pbVar27 = pbVar27 + *puVar31;
    *(undefined2 *)((int)puVar23 + -4) = puStack_4._0_2_;
    bVar33 = 9 < ((byte)uVar8 & 0xf) | bVar33;
    uVar4 = in((short)pbVar17);
    puVar21 = (uint *)CONCAT31(CONCAT21((short)(uVar8 >> 0x10),(char)(uVar8 >> 8) + bVar33),uVar4);
  }
  bVar5 = DAT_0000003f;
  bVar33 = 9 < (bVar20 & 0xf) | bVar33;
  cVar13 = cVar13 - bVar33;
  uVar3 = CONCAT21((short)((uint)puStack_4 >> 0x10),cVar13);
  pCVar16 = (CVisionViewportDx9 *)CONCAT31(uVar3,DAT_0000003f);
  bVar35 = bVar33;
  if (SBORROW4((int)puVar21,0x3dc03da1)) {
LAB_009b4ede:
    *(byte *)puVar21 = (byte)*puVar21 | (byte)((uint)puVar21 >> 8);
    pCVar9 = (CVisionViewportDx9 *)(CONCAT31((int3)((uint)pCVar16 >> 8),-bVar33) | 0x3b);
    *puVar21 = *puVar21 - (int)puVar31;
    puVar25 = puVar23;
  }
  else {
    *(char *)((int)pCVar16 * 2) = *(char *)((int)pCVar16 * 2) + (char)puVar21;
    *pCVar15 = (CVisionViewportDx9)((char)*pCVar15 + cVar13);
    bVar5 = bVar5 ^ *(byte *)((int)puVar31 + 0x32);
    bVar35 = 9 < (bVar5 & 0xf) | bVar33;
    uVar8 = CONCAT31(uVar3,bVar5 + bVar35 * -6) & 0xffffff0f;
    uVar4 = (undefined1)uVar8;
    puVar23[-1] = puVar21;
    puVar31 = (uint *)puVar23[-1];
    pbVar27 = (byte *)*puVar23;
    unaff_EBP = puVar23[1];
    puVar21 = (uint *)puVar23[3];
    pbVar17 = (byte *)puVar23[4];
    pCVar16 = (CVisionViewportDx9 *)puVar23[5];
    pCVar9 = (CVisionViewportDx9 *)puVar23[6];
    puVar24 = puVar23 + 7;
    pCVar15 = pCVar16;
    puVar25 = puVar23 + 7;
    if ((int)(CONCAT31((int3)(CONCAT22((short)(uVar8 >> 0x10),CONCAT11(cVar13 - bVar35,uVar4)) >> 8)
                       ,uVar4) ^ 0x360835ac) < 1) {
      puVar23 = puVar23 + 8;
      bVar36 = (*puVar24 & 0x400) != 0;
      bVar35 = (*puVar24 & 0x10) != 0;
      puVar21 = (uint *)CONCAT22((short)((uint)puVar21 >> 0x10),
                                 CONCAT11((byte)((uint)puVar21 >> 8) ^ (byte)*pCVar16,(char)puVar21)
                                );
      *(undefined2 *)pCVar16 = *(undefined2 *)pCVar16;
      pbVar32 = (byte *)((int)puVar31 + (uint)bVar36 * -2 + 1);
      pbVar27 = pbVar27 + (uint)bVar36 * -2 + 1;
      bVar33 = (byte)SUB41((uint)pbVar17 >> 8,0) < (byte)pCVar9[0x3a];
      LOCK();
      puVar31 = *(uint **)pbVar17;
      *(byte **)pbVar17 = pbVar32;
      UNLOCK();
      pCVar15 = pCVar9;
      goto LAB_009b4ede;
    }
  }
  cVar12 = (char)pCVar9;
  *pCVar9 = (CVisionViewportDx9)((char)*pCVar9 + cVar12);
  pCVar9[0x440033] = (CVisionViewportDx9)((char)pCVar9[0x440033] + cVar12);
  *pCVar9 = (CVisionViewportDx9)((char)*pCVar9 + cVar12);
  iVar11 = CONCAT22((short)((uint)pbVar17 >> 0x10),
                    CONCAT11((char)((uint)pbVar17 >> 8) + (char)*pCVar9,(char)pbVar17));
  *(byte *)(iVar11 + -0x40cf4bd1) = *(byte *)(iVar11 + -0x40cf4bd1) ^ (byte)((uint)pCVar15 >> 8);
  *(byte *)(iVar11 + 0x31) = *(byte *)(iVar11 + 0x31) ^ (byte)((uint)pCVar9 >> 8);
  iVar18 = CONCAT31((int3)((uint)(iVar11 + -1) >> 8),0x32);
  puVar28 = (uint *)((uint)pbVar27 & *puVar21);
  *(byte *)puVar21 = (byte)*puVar21 ^ (byte)((uint)(iVar11 + -1) >> 8);
  *(CVisionViewportDx9 **)((int)puVar25 + -4) = pCVar15;
  uVar8 = (uint)pCVar9 ^ 0x366c3616;
  if (uVar8 == 0) {
    *(uint *)((int)puVar21 + 0x2132c032) = *(uint *)((int)puVar21 + 0x2132c032) ^ (uint)puVar28;
    puVar10 = (uint *)0x0;
code_r0x009b4f9b:
    puVar29 = (uint *)((uint)puVar28 ^ *puVar31);
    uVar22 = (uint)puVar21 ^ (uint)puVar31;
    pCVar15 = (CVisionViewportDx9 *)((uint)pCVar15 ^ *puVar10);
    puVar19 = (uint *)(iVar18 + -1);
    bVar33 = bVar35 * '\x06' + 0x89 & 0xf;
    cVar12 = (char)((uint)puVar10 >> 8) + bVar35;
    *(undefined1 **)((int)puVar25 + -8) = (undefined1 *)((int)puVar25 + -4);
    bVar35 = 9 < bVar33 | bVar35;
    uVar8 = CONCAT31((int3)((uint)puVar10 >> 8),bVar33 + bVar35 * '\x06') & 0xffff000f;
    pbVar27 = (byte *)CONCAT22((short)(uVar8 >> 0x10),CONCAT11(cVar12 + bVar35,(char)uVar8));
    puVar21 = (uint *)CONCAT22((short)(uVar22 >> 0x10),
                               CONCAT11((byte)(uVar22 >> 8) & (byte)*pCVar15,(char)uVar22));
    *(uint **)((int)puVar25 + -0xc) = puVar21;
    bVar34 = *(undefined1 **)(pbVar27 + 0x39) < (undefined1 *)((int)puVar25 + -0xc);
    puVar28 = puVar29;
    if (!SBORROW4((int)*(undefined1 **)(pbVar27 + 0x39),(int)((int)puVar25 + -0xc))) {
      puVar28 = (uint *)((int)puVar29 + (uint)bVar36 * -2 + 1);
      out((char)*puVar29,(short)puVar19);
      goto code_r0x009b4fd2;
    }
  }
  else {
    if (-1 < (int)uVar8) {
      *puVar31 = *puVar31 << 1;
      out(0x37,uVar8);
      return uVar8;
    }
    bVar35 = 9 < ((byte)puVar21 & 0xf) | bVar35;
    uVar22 = (uint)puVar21 >> 0x10;
    cVar12 = (char)((uint)puVar21 >> 8) + bVar35;
    puVar21 = (uint *)CONCAT22((short)(uVar8 >> 0x10),
                               CONCAT11((char)(uVar8 >> 8) + (byte)*puVar31,(char)uVar8));
    puVar19 = (uint *)(iVar18 + -1);
    bVar35 = 9 < (DAT_77384d37 & 0xf) | bVar35;
    uVar8 = CONCAT31(CONCAT21((short)uVar22,cVar12),DAT_77384d37 + bVar35 * -6) & 0xffffff0f;
    uVar14 = (undefined2)(uVar8 >> 0x10);
    bVar33 = (byte)uVar8;
    bVar5 = cVar12 - bVar35;
    pbVar27 = (byte *)CONCAT22(uVar14,CONCAT11(bVar5,bVar33));
    pCVar15 = pCVar15 + -1;
    if (pCVar15 == (CVisionViewportDx9 *)0x0 || puVar19 != (uint *)0x0) {
      *pbVar27 = *pbVar27 + bVar33;
      pbVar27[0x440033] = pbVar27[0x440033] + bVar5;
      bVar20 = *pbVar27;
      *pbVar27 = *pbVar27 + bVar33;
      iVar18 = CONCAT22((short)((uint)puVar19 >> 0x10),
                        CONCAT11((char)((uint)puVar19 >> 8) + *pbVar27 + CARRY1(bVar20,bVar33),
                                 (char)puVar19));
      *(uint *)pCVar15 = *(uint *)pCVar15 ^ 0xffffff94;
      *(uint *)(unaff_EBP + -0x4cce39cf) = *(uint *)(unaff_EBP + -0x4cce39cf) ^ (uint)puVar28;
      puVar10 = (uint *)((uint)CONCAT21(uVar14,bVar5 ^ (byte)*pCVar15) << 8);
      goto code_r0x009b4f9b;
    }
  }
  puVar21 = (uint *)CONCAT22((short)((uint)puVar21 >> 0x10),
                             CONCAT11(((char)((uint)puVar21 >> 8) - (byte)*puVar21) -
                                      (*puVar19 < 0x3b123a97),(char)puVar21));
  bVar35 = 9 < (byte)pbVar27 | bVar35;
  uVar8 = CONCAT31((int3)((uint)pbVar27 >> 8),(byte)pbVar27 + bVar35 * -6) & 0xffffff0f;
  bVar33 = (byte)uVar8;
  pbVar27 = (byte *)CONCAT22((short)(uVar8 >> 0x10),
                             CONCAT11((char)((uint)pbVar27 >> 8) - bVar35,bVar33));
  pbVar27[0x740033] = pbVar27[0x740033] + (char)((uint)puVar19 >> 8);
  bVar34 = CARRY1(*pbVar27,bVar33);
  *pbVar27 = *pbVar27 + bVar33;
  pCVar15 = pCVar15 + -1;
  if (pCVar15 != (CVisionViewportDx9 *)0x0) {
    puVar28 = (uint *)((int)puVar28 - *puVar28);
    bVar34 = false;
    *puVar28 = *puVar28 ^ 0xffffff96;
  }
code_r0x009b4fd2:
  uVar22 = (int)puVar28 + (uint)bVar34 + *(uint *)pCVar15;
  *(uint *)(uVar22 + 0x31) = *(uint *)(uVar22 + 0x31) ^ (uint)puVar19;
  *puVar19 = *puVar19 & uVar22;
  uVar8 = *(uint *)(pCVar15 + 0x4333c833);
  bVar35 = (byte)(((uint)puVar19 ^ uVar8) >> 8) ^ DAT_355d354a;
  *(uint *)(uVar22 ^ *puVar19) = *(uint *)(uVar22 ^ *puVar19) ^ 0xffffff96;
  *(byte *)puVar31 = (byte)*puVar31 | bVar35;
  if ((byte)((uint)puVar19 ^ uVar8) != *(byte *)((int)puVar31 + 0x3a)) {
    *puVar21 = *puVar21 << ((byte)pCVar15 & 0x1f);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(byte *)puVar31 = ((byte)pbVar27 & 0x31) + 1 ^ 0x9c | 0x37;
  pcVar2 = (code *)swi(1);
  iVar11 = (*pcVar2)();
  return iVar11;
}
}

// =================================================
// Function: CVisionViewportDx9::SetShaderForced
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009a0673) overlaps instruction at (ram,0x009a066f)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Removing unreachable block (ram,0x009a05f4) */
/* WARNING: Removing unreachable block (ram,0x009a05f6) */
/* WARNING: Removing unreachable block (ram,0x009a062d) */
/* WARNING: Removing unreachable block (ram,0x009a05f8) */
/* WARNING: Removing unreachable block (ram,0x009a061a) */
/* WARNING: Removing unreachable block (ram,0x009a0650) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CVisionViewportDx9::SetShaderForced
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugShader *param_2)
{
{
  code *pcVar1;
  byte bVar2;
  byte bVar3;
  int in_EAX;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  undefined3 uVar13;
  ushort uVar15;
  ushort extraout_var;
  char *pcVar9;
  uint *puVar10;
  uint extraout_ECX;
  uint *puVar16;
  uint *extraout_ECX_00;
  int iVar17;
  byte bVar20;
  undefined4 in_EDX;
  byte *pbVar18;
  byte *extraout_EDX;
  uint *puVar19;
  uint unaff_EBX;
  byte *pbVar21;
  int *piVar22;
  undefined4 *puVar23;
  uint unaff_EBP;
  undefined4 *puVar24;
  uint unaff_ESI;
  uint uVar25;
  byte unaff_DI;
  byte in_AF;
  byte bVar26;
  undefined8 uVar27;
  undefined1 auStack_8 [8];
  byte *pbVar8;
  char cVar11;
  byte bVar12;
  uint3 uVar14;
  
  puVar4 = (uint *)(in_EAX + 1);
  *(byte *)puVar4 = *(byte *)puVar4 + (char)puVar4;
  this[0x30] = (CVisionViewportDx9)((char)this[0x30] + (char)((uint)puVar4 >> 8));
  *this = (CVisionViewportDx9)((byte)*this | (byte)((uint)in_EDX >> 8));
  uVar25 = unaff_ESI ^ (uint)this;
  *puVar4 = *puVar4 | uVar25;
  bVar26 = 9 < ((unaff_DI | 0x36) & 0xf) | in_AF;
  uVar27 = func_0x003f5a3d();
  pbVar18 = (byte *)((int)uVar27 * 2 + 0x30180000);
  bVar2 = *pbVar18;
  *pbVar18 = *pbVar18 + (byte)unaff_EBX;
  *(byte *)puVar4 = *(byte *)puVar4 ^ (byte)((ulonglong)uVar27 >> 0x28);
  puVar5 = (uint *)(unaff_EBX + 0x338c3388 + uVar25);
  *puVar5 = *puVar5 ^ ((int)uVar27 + 0xdcfc6d0) - (uint)CARRY1(bVar2,(byte)unaff_EBX);
  puVar5 = (uint *)((uint)auStack_8 ^ 0xc033bc33);
  puVar16 = (uint *)(extraout_ECX ^ (uint)puVar5 ^ (uint)auStack_8);
  pbVar18 = (byte *)((uint)((ulonglong)uVar27 >> 0x20) ^ *(uint *)(unaff_EBX + 0x339c3398 + uVar25)
                     ^ (uint)puVar5 ^ (uint)auStack_8);
  pbVar21 = (byte *)(unaff_EBX ^ (uint)puVar5 ^ (uint)auStack_8);
  piVar22 = (int *)0x0;
  puVar24 = (undefined4 *)(unaff_EBP ^ *(uint *)(unaff_EBX + 0x33b433b0 + uVar25) ^ (uint)puVar5);
  puVar4 = (uint *)((uint)puVar4 ^ (uint)puVar5);
  uVar6 = (uint)puVar5 ^ *puVar5;
  bVar2 = (byte)uVar6 ^ 0x92;
  bVar26 = 9 < (bVar2 & 0xf) | bVar26;
  uVar7 = CONCAT31((int3)(uVar6 >> 8),bVar2 + bVar26 * '\x06') & 0xffffff0f;
  uVar15 = (ushort)(uVar7 >> 0x10);
  bVar2 = (byte)uVar7;
  cVar11 = (char)(uVar6 >> 8) + bVar26;
  pbVar8 = (byte *)CONCAT22(uVar15,CONCAT11(cVar11,bVar2));
  uVar6 = (uVar25 ^ (uint)puVar5) - *puVar4;
  _DAT_b0003d74 =
       _DAT_b0003d74 +
       (ushort)((uVar25 ^ (uint)puVar5) < *puVar4 || uVar6 < bVar26) *
       (((ushort)puVar4 & 3) - (_DAT_b0003d74 & 3));
  uVar13 = (undefined3)((uint)pbVar8 >> 8);
  bVar2 = bVar2 | *pbVar8;
  _DAT_b336b636 = (char *)CONCAT31(uVar13,bVar2);
  *_DAT_b336b636 = *_DAT_b336b636 + bVar2;
  bVar2 = bVar2 * '\x02' | *(byte *)CONCAT31(uVar13,bVar2 * '\x02');
  *(char *)CONCAT31(uVar13,bVar2) = *(char *)CONCAT31(uVar13,bVar2) + bVar2;
  iVar17 = CONCAT22(uVar15,(ushort)(byte)(bVar2 + cVar11 * '0'));
  uVar6 = uVar6 - bVar26 & *puVar16;
  puVar5 = (uint *)(iVar17 + -0x29ce3ccf);
  *puVar5 = *puVar5 ^ (uint)puVar16;
  puVar23 = (undefined4 *)(iVar17 + 0x32);
  *puVar23 = *puVar23;
  puVar5 = (uint *)(uVar6 & *(uint *)(pbVar21 + uVar6 * 4));
  uVar15 = uVar15 ^ 0x3586;
  uVar6 = (uint)puVar5 ^ *puVar5;
  puVar5 = (uint *)((int)puVar4 + 2);
  pcVar1 = (code *)swi(4);
  if (SCARRY4((int)puVar4 + 1,1)) {
    (*pcVar1)();
    puVar16 = extraout_ECX_00;
    pbVar18 = extraout_EDX;
    uVar15 = extraout_var;
  }
  bVar2 = in((short)pbVar18);
  cVar11 = bVar2 - *(byte *)(uVar6 + 0x3a);
  bVar12 = (cVar11 < '\0') << 7 | (cVar11 == '\0') << 6 | bVar26 << 4 |
           ((POPCOUNT(cVar11) & 1U) == 0) << 2 | 2 | bVar2 < *(byte *)(uVar6 + 0x3a);
  pcVar9 = (char *)CONCAT22(uVar15,CONCAT11(bVar12,bVar2));
  *pcVar9 = *pcVar9 + bVar2;
  *pbVar18 = *pbVar18 >> 1 | *pbVar18 << 7;
  *pcVar9 = *pcVar9 + bVar12;
  *pcVar9 = *pcVar9 + bVar2;
  bVar20 = (char)((uint)pbVar18 >> 8) + bVar2 & *(byte *)puVar5;
  puVar19 = (uint *)CONCAT22((short)((uint)pbVar18 >> 0x10),CONCAT11(bVar20,(byte)pbVar18));
  uVar14 = (uint3)((uint)pcVar9 >> 8);
  puVar10 = (uint *)(CONCAT31(uVar14,bVar2) ^ 0x37);
  iVar17 = (int)puVar16 + -1;
  _DAT_403ab63a = puVar10;
  if (iVar17 != 0 && puVar10 != (uint *)*puVar10) {
    if (puVar24 < *(undefined4 **)((int)puVar10 + 0x39)) goto code_r0x009a05c3;
    iVar17 = *piVar22;
    piVar22 = piVar22 + 1;
  }
  *(char *)((int)puVar10 * 2) = *(char *)((int)puVar10 * 2) + (byte)pbVar21;
  bVar2 = (byte)puVar10;
  *(byte *)puVar10 = (char)*puVar10 + bVar2;
  *puVar10 = *puVar10 & (uint)puVar5;
  bVar26 = 9 < (bVar2 & 0xf) | bVar26;
  bVar3 = bVar2 + bVar26 * '\x06' & 0xf;
  *(undefined4 *)((int)piVar22 + -4) = 0x59397739;
  bVar2 = 9 < bVar3 | bVar26;
  uVar7 = CONCAT31((int3)(((uint)(uVar14 >> 8) << 0x10) >> 8),bVar3 + bVar2 * -6) & 0xffffff0f;
  cVar11 = (char)uVar7;
  pcVar9 = (char *)CONCAT22((short)(uVar7 >> 0x10),CONCAT11((bVar12 + bVar26) - bVar2,cVar11));
  *pcVar9 = *pcVar9 + cVar11;
  uVar13 = (undefined3)((uint)pcVar9 >> 8);
  bVar20 = cVar11 + bVar20;
  uVar7 = CONCAT31(uVar13,bVar20 | *(byte *)CONCAT31(uVar13,bVar20));
  *(int *)((int)&ExceptionList + uVar7) = *(int *)((int)&ExceptionList + uVar7) + uVar7;
  bVar2 = (byte)iVar17;
  *(char *)(iVar17 + -0x57cf6ad0) = *(char *)(iVar17 + -0x57cf6ad0) + bVar2;
  puVar16 = (uint *)CONCAT31((int3)((uint)iVar17 >> 8),bVar2 ^ (byte)pbVar21);
  bVar2 = (byte)pbVar18 ^ bVar2 ^ (byte)((uint)pbVar21 >> 8);
  puVar19 = (uint *)CONCAT31((int3)((uint)puVar19 >> 8),bVar2);
  *pbVar21 = *pbVar21 ^ bVar2;
  *puVar16 = *puVar16 ^ (uint)((int)piVar22 + -4);
  *puVar19 = *puVar19 ^ (uint)puVar5;
  *(uint *)((int)puVar4 + 0x33) = *(uint *)((int)puVar4 + 0x33) ^ (uint)puVar24;
  piVar22 = (int *)(uVar7 ^ uVar6);
  puVar24 = (undefined4 *)((uint)puVar24 ^ (uint)piVar22);
  uVar6 = uVar6 ^ (uint)puVar24;
code_r0x009a05c3:
  in((short)((int)puVar19 + 1));
  *puVar5 = *puVar5 + uVar6;
  bVar2 = (byte)((uint)((int)puVar19 + 1) >> 8);
  if ((bVar2 < *(byte *)puVar5) && ((POPCOUNT(bVar2 - *(byte *)puVar5) & 1U) == 0)) {
    *puVar5 = *puVar5 ^ 0x378c3786;
    puVar23 = (undefined4 *)((int)piVar22 + -4);
    *(undefined4 **)((int)piVar22 + -4) = puVar24;
    cVar11 = '\x16';
    do {
      puVar24 = puVar24 + -1;
      puVar23 = puVar23 + -1;
      *puVar23 = *puVar24;
      cVar11 = cVar11 + -1;
    } while ('\0' < cVar11);
    *(undefined1 **)((int)piVar22 + -0x60) = (undefined1 *)((int)piVar22 + -4);
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: CVisionViewportDx9::SetStageTexture
// =================================================
void __thiscall
CVisionViewportDx9::SetStageTexture
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2,ulong param_3)
{
{
  int iVar1;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    (**(code **)(*(int *)this + 0xb0))(param_1);
  }
  iVar1 = *(int *)(param_1 + 0x14);
  if ((&DAT_00d756a8)[(int)param_2] != iVar1) {
    (**(code **)(*DAT_00d75698 + 0x104))(DAT_00d75698,param_2,*(undefined4 *)(iVar1 + 0xc));
    (&DAT_00d756a8)[(int)param_2] = iVar1;
  }
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::Shadow_CanRenderInTexDepth
// =================================================
int __thiscall
CVisionViewportDx9::Shadow_CanRenderInTexDepth(CVisionViewportDx9 *this,CVisionViewportDx9 *param_1)
{
{
  ulong uVar1;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  
  if (1 < *(int *)(this + 0x32c)) {
    uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d777c8,unaff_ESI);
    if ((((uVar1 != 0) && (2 < *(int *)(this + 0x248))) && (*(int *)(this + 0x80) == 0)) &&
       ((*(int *)(this + 0x84) != 0 || (2 < DAT_00d123b8._2_2_)))) {
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: CVisionViewportDx9::Shadow_ComputeFrustumLocation
// =================================================
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CVisionViewportDx9::Shadow_ComputeFrustumLocation
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugVolumeShadow *param_2,
          ulong param_3)
{
{
  byte *pbVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  byte bVar6;
  byte bVar7;
  code *pcVar8;
  byte bVar9;
  char cVar10;
  uint in_EAX;
  uint uVar11;
  uint uVar12;
  int iVar15;
  uint in_EDX;
  undefined4 unaff_EBX;
  byte *unaff_ESI;
  uint *unaff_EDI;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined1 auStack_8 [4];
  undefined4 uStack_4;
  uint uVar13;
  char *pcVar14;
  
  *unaff_ESI = *unaff_ESI ^ (byte)(in_EDX >> 8);
  _DAT_ca3db13d = (in_EAX & 0xffffff38) + 1 & 0x83392e39;
  iVar15 = CONCAT22((short)((uint)unaff_EBX >> 0x10),
                    CONCAT11((byte)((uint)unaff_EBX >> 8) | *unaff_ESI,(char)unaff_EBX));
  uVar11 = _DAT_ca3db13d + 0x8fc19cc2;
  uVar3 = *unaff_EDI;
  *unaff_EDI = *unaff_EDI + (int)unaff_EDI;
  uVar4 = *unaff_EDI;
  uVar12 = uVar11 & 0x993f4d3f;
  bVar5 = 9 < ((byte)uVar12 & 0xf);
  bVar6 = bVar5 | in_AF;
  bVar9 = (byte)uVar12 + bVar6 * -6 & 0xf;
  bVar7 = 9 < bVar9 | bVar6;
  uVar13 = CONCAT31((int3)(uVar11 >> 8),bVar9 + bVar7 * -6) & 0x993f000f;
  cVar10 = (char)uVar13;
  pcVar14 = (char *)CONCAT22((short)(uVar13 >> 0x10),
                             CONCAT11((((int)uVar12 < 0) << 7 | (uVar12 == 0) << 6 | bVar6 << 4 |
                                       ((POPCOUNT(uVar11 & 0x3f) & 1U) == 0) << 2 | 2 | bVar6) -
                                      bVar7,cVar10));
  *pcVar14 = *pcVar14 + cVar10;
  pcVar14[0x840025] = pcVar14[0x840025] + (byte)in_EDX;
  *pcVar14 = *pcVar14 + cVar10;
  uStack_4 = 0x23348f32;
  pbVar1 = (byte *)(iVar15 + 0x6c30a230);
  *pbVar1 = *pbVar1 ^ (byte)in_EDX;
  puVar2 = (uint *)(iVar15 + -0x47ce59cf);
  *puVar2 = *puVar2 ^ in_EDX;
  _DAT_00000000 = 0;
  out(0x32,(uint)pcVar14 ^ 0x23348f32);
  uVar11 = (uint)pcVar14 ^ 0x23ca8f3d;
  *(uint *)(((uint)auStack_8 ^
            *(uint *)((int)unaff_EDI + CARRY4(uVar3,(uint)unaff_EDI) + uVar4 + 0x31342333)) - 4) =
       (uint)(in_NT & 1) * 0x4000 | (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
       (uint)((int)uVar11 < 0) * 0x80 | (uint)(uVar11 == 0) * 0x40 |
       (uint)(byte)(9 < bVar9 | bVar5 | in_AF & 1) * 0x10 |
       (uint)((POPCOUNT(uVar11 & 0xff) & 1U) == 0) * 4 | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  pcVar8 = (code *)swi(3);
  iVar15 = (*pcVar8)();
  return iVar15;
}
}

// =================================================
// Function: CVisionViewportDx9::Shadow_ComputeWorldPrVolume
// =================================================
/* WARNING: Control flow encountered bad instruction data */

int __thiscall
CVisionViewportDx9::Shadow_ComputeWorldPrVolume
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugVolumeShadow *param_2,
          int param_3,GxLight *param_4,GmBoxAligned *param_5,SShadowCameraInter *param_6)
{
{
  bool bVar1;
  code *pcVar2;
  byte bVar3;
  byte bVar4;
  undefined4 uVar5;
  uint uVar6;
  int extraout_ECX;
  uint *puVar7;
  uint *unaff_EBX;
  uint unaff_EDI;
  byte in_AF;
  undefined8 uVar8;
  byte in_stack_0000001c;
  uint in_stack_00000020;
  
  pcVar2 = (code *)swi(0x39);
  uVar8 = (*pcVar2)();
  puVar7 = (uint *)((ulonglong)uVar8 >> 0x20);
  bVar3 = (byte)uVar8;
  if (extraout_ECX == 1) {
    *(char *)puVar7 = ((char)*puVar7 - (char)((uint)unaff_EBX >> 8)) - CARRY4(unaff_EDI,*puVar7);
    if ((POPCOUNT((int)unaff_EBX - *(int *)((int)puVar7 + 0x3b) & 0xff) & 1U) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  else {
    *(byte *)(extraout_ECX + 0x2430ae2f) =
         *(byte *)(extraout_ECX + 0x2430ae2f) ^ (byte)((ulonglong)uVar8 >> 8);
    *unaff_EBX = *unaff_EBX ^ (uint)puVar7;
    unaff_EBX = (uint *)CONCAT31((int3)((uint)unaff_EBX >> 8),0x33);
    uVar5 = in(0x33);
    bVar3 = (byte)(CONCAT44(puVar7,uVar5) / (ulonglong)*unaff_EBX) ^ 3;
  }
  out(0x35,bVar3 ^ 100);
  *(byte *)unaff_EBX = (byte)*unaff_EBX + (char)((uint)param_5 >> 8);
  *(byte *)unaff_EBX = (byte)*unaff_EBX ^ 0x86;
  bVar3 = 9 < ((byte)unaff_EBX & 0xf) | 9 < (in_stack_0000001c & 0xf) | in_AF;
  bVar4 = (byte)unaff_EBX + bVar3 * '\x06' & 0xf;
  bVar1 = 9 < bVar4 || (in_stack_00000020 & 0x10) != 0;
  uVar6 = CONCAT31((int3)((uint)unaff_EBX >> 8),bVar4 + bVar1 * '\x06') & 0xffff000f;
  return CONCAT22((short)(uVar6 >> 0x10),
                  CONCAT11((char)((uint)unaff_EBX >> 8) + bVar3 + bVar1,(char)uVar6));
}
}

// =================================================
// Function: CVisionViewportDx9::Shadow_RenderCaster
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x009ae0b5) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CVisionViewportDx9::Shadow_RenderCaster
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CHmsZone *param_2,
          CPlugVolumeShadow *param_3,ulong param_4,ulong param_5,GmBoxAligned *param_6,
          CPlugBitmapRenderShadow *param_7,GmVec4 *param_8,float *param_9)
{
{
  byte in_AL;
  byte *in_EDX;
  byte unaff_BH;
  uint unaff_EBP;
  undefined1 *unaff_ESI;
  uint unaff_EDI;
  
  *in_EDX = *in_EDX ^ in_AL ^ unaff_BH;
  _DAT_83314e31 = _DAT_83314e31 ^ unaff_EDI;
  *(uint *)(unaff_ESI + 0x36322331) = *(uint *)(unaff_ESI + 0x36322331) ^ unaff_EBP;
  out(*unaff_ESI,(short)in_EDX);
  swi(4);
  unaff_ESI[1] = unaff_ESI[1] + '\x01';
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: CVisionViewportDx9::StdGpuVGet
// =================================================
CPlugFileGPUV * __thiscall
CVisionViewportDx9::StdGpuVGet
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,EStdGpuV param_2,SStdGpuMask param_3
          ,int param_4)
{
{
  int iVar1;
  SStdGpuMask unaff_BL;
  CVisionViewportDx9 *pCVar2;
  
  iVar1 = (int)param_1 * 4;
  if (((&DAT_00d77970)[(int)param_1] & param_2) != param_2) {
    return (CPlugFileGPUV *)0x0;
  }
  pCVar2 = this + 0x138c;
  if (param_2 != DAT_00d77b0c) {
    pCVar2 = this + 0x1400;
  }
  if (*(int *)(pCVar2 + iVar1) == 0) {
    StdGpuVLoad(this,param_1,param_2,unaff_BL);
  }
  if ((*(int *)(*(int *)(pCVar2 + iVar1) + 0x1c) == 0) && (param_4 != 0)) {
    (**(code **)(*(int *)this + 0x1f0))(*(int *)(pCVar2 + iVar1),1);
  }
  return *(CPlugFileGPUV **)(pCVar2 + iVar1);
}
}

// =================================================
// Function: CVisionViewportDx9::StdGpuVLoad
// =================================================
CPlugFileGPUV * __thiscall
CVisionViewportDx9::StdGpuVLoad
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,EStdGpuV param_2,SStdGpuMask param_3
          )
{
{
  CDx9GpuBuilder *pCVar1;
  CPlugFileGPUV *pCVar2;
  CVisionViewportDx9 *pCVar3;
  SCasterCat *pSVar4;
  CPlugFileVHlsl *this_00;
  CMwNod *extraout_EAX;
  CPlugFileVsh *this_01;
  CMwNod *extraout_EAX_00;
  undefined1 *puVar5;
  undefined *puVar6;
  CFastStringInt *pCVar7;
  SStringParam *unaff_EBX;
  CMwNod *unaff_EBP;
  CPlugFileVHlsl *unaff_ESI;
  SStringParam *unaff_EDI;
  CMwNod *pCVar8;
  SStringParam *in_stack_ffffffd4;
  CFastStringInt *pCVar9;
  char *local_20;
  undefined4 local_1c;
  undefined *local_18;
  CVisionViewportDx9 *local_14;
  char *local_10;
  void *local_c;
  CVisionViewportDx9 *local_8;
  char *local_4;
  
  local_4 = (char *)0xffffffff;
  local_8 = (CVisionViewportDx9 *)&LAB_00aeace6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_2 == DAT_00d77b0c) {
    pCVar3 = this + 0x138c;
  }
  else {
    pCVar3 = this + 0x1400;
  }
  pCVar1 = (CDx9GpuBuilder *)(pCVar3 + (int)param_1 * 4);
  if (*(CPlugFileGPUV **)pCVar1 != (CPlugFileGPUV *)0x0) {
    ExceptionList = param_1;
    return *(CPlugFileGPUV **)pCVar1;
  }
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(DAT_00d73300 + 0x20),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000009,
                      DAT_00cca150 ^ (uint)&stack0xffffffc0);
  pCVar9 = (CFastStringInt *)0x0;
  if (param_1 == (CVisionViewportDx9 *)0x1) {
    local_20 = "TexelToDepth";
    local_1c = 0xc;
    CFastString::SetString((CFastString *)&stack0xffffffd8,(CFastStringInt *)&local_20,unaff_EDI);
    this_01 = operator_new(0xf0);
    param_1 = (CVisionViewportDx9 *)0x1;
    if (this_01 == (CPlugFileVsh *)0x0) {
      pCVar8 = (CMwNod *)0x0;
    }
    else {
      CPlugFileVsh::CPlugFileVsh(this_01,(CPlugFileVsh *)unaff_ESI);
      pCVar8 = extraout_EAX_00;
    }
    if (pCVar8 != *(CMwNod **)pCVar1) {
      if (pCVar8 != (CMwNod *)0x0) {
        CMwNod::MwAddRef(pCVar8,unaff_EBP);
      }
      if (*(CMwNod **)pCVar1 != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)pCVar1,unaff_EBP);
      }
      *(CMwNod **)pCVar1 = pCVar8;
    }
    local_8 = (CVisionViewportDx9 *)0xbd32b8;
    local_4 = (char *)0x165;
    pCVar7 = (CFastStringInt *)&local_8;
  }
  else {
    if (param_1 != (CVisionViewportDx9 *)&DAT_0000000e) {
      CDx9GpuBuilder::BuildVHlsl
                (*(CDx9GpuBuilder **)(*(int *)pSVar4 + 0x20),pCVar1,
                 (CMwNodRef<class_CPlugFileGPUV> *)param_1,param_2,SUB41(&stack0xffffffd8,0),
                 (CFastString *)unaff_EDI);
      goto LAB_0098a0cf;
    }
    local_20 = "ProjectorFadeZ";
    local_1c = 0xe;
    CFastString::SetString((CFastString *)&stack0xffffffd8,(CFastStringInt *)&local_20,unaff_EDI);
    this_00 = operator_new(0xe0);
    param_1 = (CVisionViewportDx9 *)0x2;
    if (this_00 == (CPlugFileVHlsl *)0x0) {
      pCVar8 = (CMwNod *)0x0;
    }
    else {
      CPlugFileVHlsl::CPlugFileVHlsl(this_00,unaff_ESI);
      pCVar8 = extraout_EAX;
    }
    if (pCVar8 != *(CMwNod **)pCVar1) {
      if (pCVar8 != (CMwNod *)0x0) {
        CMwNod::MwAddRef(pCVar8,unaff_EBP);
      }
      if (*(CMwNod **)pCVar1 != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)pCVar1,unaff_EBP);
      }
      *(CMwNod **)pCVar1 = pCVar8;
    }
    local_10 = 
    "struct VS_INPUT {\r\n\tfloat4 Position : POSITION;\r\n\tfloat4 TexCoord0 : TEXCOORD0;\r\n};\r\nstruct VS_OUTPUT {\r\n\tfloat4 Position : POSITION;\r\n\tfloat4 TcProjector : TEXCOORD0;\r\n\tfloat2 TcFadeZ : TEXCOORD1;\r\n\tfloat2 TcAlpha : TEXCOORD2;\r\n};\r\nvs_1_1 VS_OUTPUT vsMain(const VS_INPUT v,\r\n\tuniform float4x4 GbxVisualPrCamera : register(c0),\r\n\tuniform float4x3 GbxVisualPrProjector1 : register(c4),\r\n\tuniform float4 GbxVisualToShadow1I : register(c7))\r\n{\r\n\tVS_OUTPUT Output = (VS_OUTPUT)0;\r\n\tOutput.Position = mul(v.Position, GbxVisualPrCamera);\r\n\tOutput.TcProjector = mul(v.Position, GbxVisualPrProjector1).xyzz;\r\n\tOutput.TcFadeZ = dot(v.Position, GbxVisualToShadow1I);\r\n\tOutput.TcAlpha = v.TexCoord0;\r\n\treturn Output;\r\n}\r\n"
    ;
    local_c = (void *)0x2c6;
    pCVar7 = (CFastStringInt *)&local_10;
  }
  CFastString::SetString((CFastString *)(*(int *)pCVar1 + 0x14),pCVar7,(SStringParam *)unaff_EBP);
LAB_0098a0cf:
  if (*(int *)(*(int *)pCVar1 + 8) == 0) {
    local_4 = "Dx9\\Media\\Text\\VHlsl\\";
    CFastStringInt::CFastStringInt(&local_14,(CFastStringInt *)&local_4,unaff_EBX);
    local_4 = local_18;
    local_8 = local_14;
    CFastStringInt::Concat(&local_10,(CFastStringInt *)&local_8,(SStringParam *)this);
    local_4 = ".VHlsl.txt";
    CFastStringInt::Concat(&local_c,(CFastStringInt *)&local_4,in_stack_ffffffd4);
    NodBindFakeFid(local_14,*(CVisionViewportDx9 **)pCVar1,(CMwNod *)&local_8,pCVar9);
    if (PTR_DAT_00bbf7dc != &DAT_0000000a) {
      if ((DAT_00000009 & 0x80) == 0) {
        puVar5 = &DAT_00000008;
      }
      else {
        puVar5 = &DAT_00000006;
      }
      operator_delete__(puVar5);
    }
  }
  pCVar2 = *(CPlugFileGPUV **)pCVar1;
  if (local_18 != PTR_DAT_00bbf7d8) {
    puVar6 = local_18 + -1;
    if ((local_18[-1] & 0x80) != 0) {
      puVar6 = local_18 + -4;
    }
    operator_delete__(puVar6);
  }
  ExceptionList = param_1;
  return pCVar2;
}
}

// =================================================
// Function: CVisionViewportDx9::StdShaderGet
// =================================================
CPlugShaderApply * __thiscall
CVisionViewportDx9::StdShaderGet
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,EStdShader2 param_2,ulong param_3)
{
{
  code *pcVar1;
  char *in_EAX;
  char *pcVar2;
  CPlugShaderApply *pCVar3;
  uint unaff_ESI;
  int unaff_EDI;
  
  *in_EAX = *in_EAX + (char)in_EAX;
  pcVar2 = in_EAX + 1;
  *pcVar2 = *pcVar2 + (char)pcVar2;
  *(uint *)(unaff_EDI + unaff_ESI) = *(uint *)(unaff_EDI + unaff_ESI) & unaff_ESI;
  pcVar1 = (code *)swi(1);
  pCVar3 = (CPlugShaderApply *)(*pcVar1)();
  return pCVar3;
}
}

// =================================================
// Function: CVisionViewportDx9::StdShaderLoad
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CPlugShaderApply * __thiscall
CVisionViewportDx9::StdShaderLoad
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,EStdShader2 param_2,ulong param_3)
{
{
  bool bVar1;
  bool bVar2;
  CPlugShaderApply *pCVar3;
  CPlugShaderApply *this_00;
  CMwNod *extraout_EAX;
  CPlugFileGPUP *extraout_EAX_00;
  int extraout_EAX_01;
  CPlugBitmap *pCVar4;
  CPlugBitmap *extraout_EAX_02;
  CPlugFileGen *this_01;
  CPlugFileGen *extraout_EAX_03;
  CPlugFileGPUP *extraout_EAX_04;
  int extraout_EAX_05;
  CPlugFilePsh *pCVar5;
  CPlugFileGPUP *extraout_EAX_06;
  EStdGpuV extraout_EAX_07;
  CPlugFileGPUP *extraout_EAX_08;
  CPlugFileGpuBuilder *pCVar6;
  CPlugFileVHlsl *pCVar7;
  int extraout_EAX_09;
  CPlugFilePHlsl *pCVar8;
  CPlugFileGPUP *extraout_EAX_10;
  CPlugBitmapApply *pCVar9;
  CPlugFileGPUV *pCVar10;
  int *piVar11;
  CPlugFilePHlsl *this_02;
  SStringParam *unaff_EBX;
  CMwNod *this_03;
  int iVar12;
  int iVar13;
  CFastString *pCVar14;
  EStdGpuV EVar15;
  CPlugFileGPU *this_04;
  EGxTexAddress EVar16;
  CPlugShader *unaff_EBP;
  CPlugFileGen *this_05;
  CPlugFileGPUP *pCVar17;
  CPlugShader *unaff_ESI;
  CFastStringInt *unaff_EDI;
  char *in_stack_fffffe54;
  char *in_stack_fffffe58;
  char *in_stack_fffffe5c;
  char *pcVar18;
  char *in_stack_fffffe60;
  char *in_stack_fffffe64;
  char *pcVar19;
  CPlugFilePsh *in_stack_fffffe68;
  CPlugFileGpuBuilder *in_stack_fffffe6c;
  CPlugFileImg *in_stack_fffffe70;
  CPlugFileGpuBuilder *in_stack_fffffe74;
  CPlugFilePHlsl *in_stack_fffffe78;
  CPlugFileGpuBuilder *in_stack_fffffe7c;
  GxColor *in_stack_fffffe80;
  CFastStringInt *in_stack_fffffe84;
  CPlugShader *in_stack_fffffe88;
  CPlugBitmapSampler *in_stack_fffffe8c;
  GxColor *pGVar20;
  EGxTexOp EVar21;
  CPlugShaderPass *pCVar22;
  SStdGpuMask SVar23;
  char *pcVar24;
  CPlugFileGPU *pCVar25;
  ulong uVar26;
  EGxBlendFactor EVar27;
  uchar uVar28;
  SStringParam *pSVar29;
  CPlugFileGPU *pCVar30;
  SParam_Id *pSVar31;
  EGxBlendFactor EVar32;
  CPlugFileGPUV *pCVar33;
  CPlugBitmapSampler *pCVar34;
  CPlugShader *pCVar35;
  CPlugFileGPU *in_stack_fffffeb0;
  CPlugFileGPU *pCVar36;
  EGxTexAddress in_stack_fffffeb4;
  EStdGpuV EVar37;
  CPlugFilePHlsl *in_stack_fffffebc;
  EGxTexAddress in_stack_fffffec0;
  ulong in_stack_fffffec4;
  int in_stack_fffffec8;
  int local_12c;
  int local_128;
  int local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  int local_dc;
  int iStack_d8;
  int local_d4;
  undefined4 local_d0;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  int iStack_80;
  int iStack_7c;
  int local_78;
  undefined4 local_74;
  undefined1 auStack_60 [4];
  CFastStringInt aCStack_5c [4];
  undefined1 local_58 [4];
  CFastStringInt local_54 [4];
  undefined1 local_50 [4];
  CFastStringInt local_4c [4];
  undefined4 local_48;
  CFastStringInt local_44 [4];
  undefined1 local_40 [4];
  CFastStringInt local_3c [4];
  undefined1 local_38 [4];
  undefined4 uStack_34;
  undefined4 uStack_30;
  CFastStringInt aCStack_2c [8];
  undefined4 local_24;
  undefined4 local_20;
  SParam_Id aSStack_1c [4];
  SParam_Id local_18 [12];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00aeb290;
  local_c = ExceptionList;
  pCVar3 = (CPlugShaderApply *)(DAT_00cca150 ^ (uint)&stack0xfffffe9c);
  ExceptionList = &local_c;
  pGVar20 = (GxColor *)0x9991e0;
  this_00 = operator_new(0xa8);
  this_03 = (CMwNod *)0x0;
  local_4 = 0;
  if (this_00 != (CPlugShaderApply *)0x0) {
    CPlugShaderApply::CPlugShaderApply(this_00,pCVar3);
    this_03 = extraout_EAX;
  }
  if (this_03 != *(CMwNod **)(this + (int)param_1 * 4 + 0x1294)) {
    if (this_03 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this_03,(CMwNod *)unaff_EDI);
    }
    if (*(CMwNod **)(this + (int)param_1 * 4 + 0x1294) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + (int)param_1 * 4 + 0x1294),(CMwNod *)unaff_EDI);
    }
    *(CMwNod **)(this + (int)param_1 * 4 + 0x1294) = this_03;
  }
  EVar15 = DAT_00d77b0c;
  switch(param_1) {
  case (CVisionViewportDx9 *)0x0:
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x1,
               0,(GxColor *)unaff_EDI);
    break;
  case (CVisionViewportDx9 *)0x1:
    SVar23 = (SStdGpuMask)0x1;
    pGVar20 = (GxColor *)0x999278;
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x1,
               0,(GxColor *)unaff_EDI);
    CPlugShader::SetReceiverDisable(*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),unaff_ESI);
    iVar13 = 0x999294;
    CPlugShader::SetFogEnable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,
               (int)unaff_EBP);
    goto LAB_0099929d;
  case (CVisionViewportDx9 *)0x2:
    iVar13 = 1;
    SVar23 = (SStdGpuMask)0x11;
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x1,
               0,(GxColor *)unaff_EDI);
    CPlugShader::SetReceiverDisable(*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),unaff_ESI);
    CPlugShader::SetFogEnable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,
               (int)unaff_EBP);
    uVar28 = 'D';
    pCVar9 = CPlugShaderApply::AddTextureApply
                       (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                        *(CPlugShaderApply **)(this + 0x151c),(CPlugBitmap *)0x10,0,(ulong)unaff_EBX
                       );
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x1,(int)this_00);
    goto LAB_00999356;
  case (CVisionViewportDx9 *)0x3:
    CPlugShader::SetDoubleSided
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x1,(int)unaff_EDI
              );
    iVar13 = 1;
    SVar23 = (SStdGpuMask)0xda;
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x1,
               0,(GxColor *)unaff_ESI);
    CPlugShader::SetReceiverDisable(*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),unaff_EBP);
    CPlugShader::SetFogEnable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,
               (int)unaff_EBX);
LAB_0099929d:
    pCVar35 = *(CPlugShader **)(this + (int)param_1 * 4 + 0x1294);
    pCVar10 = StdGpuVGet(this,(CVisionViewportDx9 *)0x0,(EStdGpuV)pGVar20,SVar23,iVar13);
    CPlugShader::SetVertexShader(pCVar35,(CPlugShaderPass *)0x0,pCVar10);
    break;
  case (CVisionViewportDx9 *)0x4:
    CPlugShader::SetDoubleSided
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x1,(int)unaff_EDI
              );
    SVar23 = SUB41(pGVar20,0);
    uVar28 = '\x01';
    iVar13 = 0x9993a3;
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x1,
               0,(GxColor *)unaff_ESI);
    CPlugShader::SetReceiverDisable(*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),unaff_EBP);
    CPlugShader::SetFogEnable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,
               (int)unaff_EBX);
    pCVar9 = CPlugShaderApply::AddTextureApply
                       (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                        *(CPlugShaderApply **)(this + 0x151c),(CPlugBitmap *)0x10,0,(ulong)this_00);
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x1,(int)in_stack_fffffeb0);
LAB_00999356:
    pCVar35 = *(CPlugShader **)(this + (int)param_1 * 4 + 0x1294);
    pCVar10 = StdGpuVGet(this,(CVisionViewportDx9 *)0x0,(EStdGpuV)in_stack_fffffe8c,SVar23,iVar13);
    CPlugShader::SetVertexShader(pCVar35,(CPlugShaderPass *)0x0,pCVar10);
LAB_00999370:
    CPlugShaderApply::SetAlphaCmp_Pass
              (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderApply *)0x3,0x33
               ,uVar28);
    break;
  case (CVisionViewportDx9 *)0x5:
    piVar11 = &iStack_80;
    iStack_80 = _DAT_00b33a54;
    iStack_7c = _DAT_00b33a54;
    local_78 = _DAT_00b33a54;
    local_74 = 0x3f800000;
    goto LAB_00999417;
  case (CVisionViewportDx9 *)0x6:
    piVar11 = (int *)&stack0xfffffec0;
    goto LAB_00999463;
  case (CVisionViewportDx9 *)0x7:
    CPlugShader::SetDoubleSided
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x1,(int)unaff_EDI
              );
    local_dc = _DAT_00b33a54;
    piVar11 = &local_dc;
    iStack_d8 = _DAT_00b33a54;
    local_d4 = _DAT_00b33a54;
    local_d0 = 0x3f800000;
LAB_00999417:
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x0,
               (EPlugShaderVertexColor)piVar11,(GxColor *)unaff_EDI);
    CPlugShader::SetReceiverDisable(*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),unaff_ESI);
    CPlugShader::SetFogEnable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,
               (int)unaff_EBP);
    break;
  case (CVisionViewportDx9 *)0x8:
    CPlugShader::SetDoubleSided
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x1,(int)unaff_EDI
              );
    local_12c = _DAT_00b33a54;
    piVar11 = &local_12c;
    local_128 = _DAT_00b33a54;
    local_124 = _DAT_00b33a54;
    local_120 = 0x3f800000;
LAB_00999463:
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x0,
               (EPlugShaderVertexColor)piVar11,(GxColor *)unaff_EDI);
    CPlugShader::SetReceiverDisable(*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),unaff_ESI);
    CPlugShader::SetFogEnable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,
               (int)unaff_EBP);
    uVar28 = 0xa5;
    CPlugShaderApply::AddTextureApply
              (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
               *(CPlugShaderApply **)(this + 0x151c),(CPlugBitmap *)&DAT_00000012,0,(ulong)unaff_EBX
              );
    goto LAB_00999370;
  case (CVisionViewportDx9 *)0x9:
    CPlugShader::SetDoubleSided
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x1,(int)unaff_EDI
              );
    local_11c = 0x3f800000;
    local_118 = 0;
    local_114 = 0;
    local_110 = 0x3f800000;
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x0,
               (EPlugShaderVertexColor)&local_11c,(GxColor *)unaff_ESI);
    CPlugShader::SetReceiverDisable(*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),unaff_EBP);
    CPlugShader::SetFogEnable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,
               (int)unaff_EBX);
    CPlugShaderApply::SetBlending
              (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x0,1,
               (EGxBlendFactor)this_00);
    CPlugShader::SetIgnoreUserClipPlanes
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x1,
               (int)in_stack_fffffeb0);
    break;
  case (CVisionViewportDx9 *)0xa:
    uStack_a0 = 0x3f800000;
    uStack_9c = 0x3f800000;
    local_98 = 0x3f800000;
    local_94 = 0x3f800000;
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x0,
               (EPlugShaderVertexColor)&uStack_a0,(GxColor *)unaff_EDI);
    CPlugShader::SetReceiverDisable(*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),unaff_ESI);
    CPlugShader::SetFogEnable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,
               (int)unaff_EBP);
    pCVar9 = CPlugShaderApply::AddTextureApply
                       (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                        *(CPlugShaderApply **)(this + 0x151c),(CPlugBitmap *)0x0,0,(ulong)unaff_EBX)
    ;
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x0,(int)this_00);
    CPlugBitmapAddress::SetGenerateUV
              ((CPlugBitmapAddress *)pCVar9,(CPlugBitmapAddress *)&DAT_0000000d,0,
               (int)in_stack_fffffeb0);
    CPlugBitmapSampler::SetTexAddress
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x2,2,0,in_stack_fffffeb4);
    CPlugBitmapSampler::SetFiltering((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x0,EVar15);
    break;
  case (CVisionViewportDx9 *)0xb:
    local_110 = 0x3f800000;
    local_10c = 0x3f800000;
    local_108 = 0x3f800000;
    local_104 = 0x3f800000;
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x0,
               (EPlugShaderVertexColor)&local_110,(GxColor *)unaff_EDI);
    CPlugShader::SetReceiverDisable(*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),unaff_ESI);
    CPlugShader::SetFogEnable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,
               (int)unaff_EBP);
    pcVar24 = (char *)0x999785;
    pCVar9 = CPlugShaderApply::AddTextureApply
                       (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                        *(CPlugShaderApply **)(this + 0x151c),(CPlugBitmap *)0x0,0,(ulong)unaff_EBX)
    ;
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x0,(int)this_00);
    CPlugBitmapAddress::SetGenerateUV
              ((CPlugBitmapAddress *)pCVar9,(CPlugBitmapAddress *)&DAT_0000000d,0,
               (int)in_stack_fffffeb0);
    CPlugBitmapSampler::SetTexAddress
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x2,2,0,in_stack_fffffeb4);
    CPlugBitmapSampler::SetFiltering((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x0,EVar15);
    pCVar8 = operator_new(0xcc);
    if (pCVar8 == (CPlugFilePHlsl *)0x0) {
      pCVar17 = (CPlugFileGPUP *)0x0;
    }
    else {
      CPlugFilePHlsl::CPlugFilePHlsl(pCVar8,in_stack_fffffebc);
      pCVar17 = extraout_EAX_00;
    }
    local_4 = 0xffffffff;
    CFastString::operator<<
              ((CFastString *)(pCVar17 + 0x14),
               (CPlugFileGpuBuilder *)
               "#include <Common.PHlsl.txt>\r\nstruct PS_INPUT {\r\n\tfpart4 Color0    : COLOR0;\r\n\tfloat2 TexCoord\t: TEXCOORD0;\r\n};\r\nstruct PS_OUTPUT {\r\n\tfpart4 Color\t: COLOR0;\r\n};\r\nsampler2D\tMapRedAsZ;\r\nps_2_0 PS_OUTPUT psMain(const PS_INPUT v)\r\n{\r\n\tPS_OUTPUT\tOutput = (PS_OUTPUT) 0;\r\n\tfpart Depth = tex2D(MapRedAsZ, v.TexCoord);\r\n\tfpart InShadow = Depth<1.f;\r\n\tOutput.Color.rgb = 1-InShadow;\r\n\tOutput.Color.a   = InShadow;\r\n\treturn Output;\r\n}\r\n"
               ,pcVar24);
    CPlugShader::SetPixelShader
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x0,pCVar17);
    break;
  case (CVisionViewportDx9 *)0xc:
    uStack_c0 = 0;
    uStack_bc = 0;
    local_b8 = 0;
    EVar27 = 0;
    local_b4 = 0x3f800000;
    pCVar22 = (CPlugShaderPass *)0x9996d0;
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x0,
               (EPlugShaderVertexColor)&uStack_c0,(GxColor *)unaff_EDI);
    CPlugShader::SetReceiverDisable(*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),unaff_ESI);
    CPlugShader::SetFogEnable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,
               (int)unaff_EBP);
    EVar32 = 0x999703;
    pCVar9 = CPlugShaderApply::AddTextureApply
                       (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                        *(CPlugShaderApply **)(this + 0x151c),(CPlugBitmap *)0x10,0,(ulong)unaff_EBX
                       );
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x0,(int)this_00);
    CPlugBitmapSampler::SetTexAddress
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x2,2,0,
               (EGxTexAddress)in_stack_fffffeb0);
    CPlugBitmapSampler::SetFiltering
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x2,in_stack_fffffeb4);
    goto LAB_0099a985;
  case (CVisionViewportDx9 *)0xd:
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x1,
               0,(GxColor *)unaff_EDI);
    CPlugShader::SetReceiverDisable(*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),unaff_ESI);
    CPlugShader::SetFogEnable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,
               (int)unaff_EBP);
    pCVar9 = CPlugShaderApply::AddTextureApply
                       (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                        *(CPlugShaderApply **)(this + 0x151c),(CPlugBitmap *)0x1,0,(ulong)unaff_EBX)
    ;
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x0,(int)this_00);
    CPlugBitmapSampler::SetTexAddress
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x2,2,0,
               (EGxTexAddress)in_stack_fffffeb0);
    CPlugBitmapSampler::SetFiltering
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x2,in_stack_fffffeb4);
    CPlugShaderApply::SetBlending
              (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x1,
               EVar15,(EGxBlendFactor)in_stack_fffffebc);
    break;
  case (CVisionViewportDx9 *)0xe:
    uStack_f0 = 0x3f800000;
    uStack_ec = 0x3f800000;
    local_e8 = 0x3f800000;
    local_e4 = _DAT_00b31460;
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x0,
               (EPlugShaderVertexColor)&uStack_f0,(GxColor *)unaff_EDI);
    CPlugShader::SetReceiverDisable(*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),unaff_ESI);
    CPlugShader::SetFogEnable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,
               (int)unaff_EBP);
    CPlugShaderApply::SetBlending
              (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
               (CPlugShaderPass *)&DAT_00000004,5,(EGxBlendFactor)unaff_EBX);
    pCVar9 = CPlugShaderApply::AddTextureApply
                       (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                        *(CPlugShaderApply **)(this + 0x151c),(CPlugBitmap *)0x1,0,(ulong)this_00);
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x0,(int)in_stack_fffffeb0);
    CPlugBitmapAddress::SetGenerateUV
              ((CPlugBitmapAddress *)pCVar9,(CPlugBitmapAddress *)0x1,1,in_stack_fffffeb4);
    CPlugBitmapSampler::SetTexAddress
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x2,2,0,EVar15);
    CPlugBitmapSampler::SetFiltering
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x0,
               (EGxTexFilter)in_stack_fffffebc);
    break;
  case (CVisionViewportDx9 *)0xf:
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x1,
               0,(GxColor *)unaff_EDI);
    CPlugShader::SetReceiverDisable(*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),unaff_ESI);
    CPlugShader::SetFogEnable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,
               (int)unaff_EBP);
    pCVar35 = *(CPlugShader **)(this + (int)param_1 * 4 + 0x1294);
    pCVar10 = StdGpuVGet(this,(CVisionViewportDx9 *)0x1,DAT_00d77b0c,(SStdGpuMask)0x1,(int)unaff_EBX
                        );
    CPlugShader::SetVertexShader(pCVar35,(CPlugShaderPass *)0x0,pCVar10);
    CPlugShader::SetPixelShader
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x0,
               *(CPlugFileGPUP **)(this + 0x1474));
    pCVar9 = CPlugShaderApply::AddTextureApply
                       (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                        *(CPlugShaderApply **)(this + 0x151c),(CPlugBitmap *)0x0,0,(ulong)this_00);
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x0,(int)in_stack_fffffeb0);
    CPlugBitmapSampler::SetTexAddress
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x2,2,0,in_stack_fffffeb4);
    pCVar9 = CPlugShaderApply::AddTextureApply
                       (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                        *(CPlugShaderApply **)(this + 0x151c),(CPlugBitmap *)0x0,0,EVar15);
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x0,(int)in_stack_fffffebc);
    CPlugBitmapSampler::SetTexAddress
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x2,2,0,in_stack_fffffec0);
    break;
  case (CVisionViewportDx9 *)0x10:
    goto switchD_0099924c_caseD_10;
  case (CVisionViewportDx9 *)0x11:
    CPlugShader::SetDoubleSided
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x1,(int)unaff_EDI
              );
    goto switchD_0099924c_caseD_10;
  case (CVisionViewportDx9 *)0x12:
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x1,
               0,(GxColor *)unaff_EDI);
    CPlugShader::SetReceiverDisable(*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),unaff_ESI);
    CPlugShader::SetFogEnable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,
               (int)unaff_EBP);
    pCVar9 = CPlugShaderApply::AddTextureApply
                       (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                        *(CPlugShaderApply **)(this + 0x1534),(CPlugBitmap *)0x0,0xffffffff,
                        (ulong)unaff_EBX);
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x1,(int)this_00);
    pCVar9 = CPlugShaderApply::AddTextureApply
                       (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                        *(CPlugShaderApply **)(this + 0x151c),(CPlugBitmap *)0x0,0,
                        (ulong)in_stack_fffffeb0);
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x1,in_stack_fffffeb4);
    pCVar35 = *(CPlugShader **)(this + (int)param_1 * 4 + 0x1294);
    pCVar10 = StdGpuVGet(this,(CVisionViewportDx9 *)0x2,DAT_00d77b10,(SStdGpuMask)0x1,EVar15);
    CPlugShader::SetVertexShader(pCVar35,(CPlugShaderPass *)0x0,pCVar10);
    CPlugShader::SetPixelShader
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x0,
               *(CPlugFileGPUP **)(this + 0x147c));
    break;
  case (CVisionViewportDx9 *)0x13:
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x1,
               0,(GxColor *)unaff_EDI);
    CPlugShader::SetReceiverDisable(*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),unaff_ESI);
    CPlugShader::SetFogEnable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,
               (int)unaff_EBP);
    pCVar35 = *(CPlugShader **)(this + (int)param_1 * 4 + 0x1294);
    pCVar10 = StdGpuVGet(this,(CVisionViewportDx9 *)&DAT_00000005,DAT_00d77b0c,(SStdGpuMask)0x1,
                         (int)unaff_EBX);
    CPlugShader::SetVertexShader(pCVar35,(CPlugShaderPass *)0x0,pCVar10);
    CPlugShader::SetPixelShader
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x0,
               *(CPlugFileGPUP **)(this + 0x14a0));
    break;
  case (CVisionViewportDx9 *)0x14:
    CPlugShader::SetDoubleSided
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x1,(int)unaff_EDI
              );
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x1,
               0,(GxColor *)unaff_ESI);
    CPlugShader::SetReceiverDisable(*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),unaff_EBP);
    CPlugShader::SetFogEnable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,
               (int)unaff_EBX);
    pCVar35 = *(CPlugShader **)(this + (int)param_1 * 4 + 0x1294);
    pCVar10 = StdGpuVGet(this,(CVisionViewportDx9 *)&DAT_00000005,DAT_00d77b0c,(SStdGpuMask)0x1,
                         (int)this_00);
    CPlugShader::SetVertexShader(pCVar35,(CPlugShaderPass *)0x0,pCVar10);
    CPlugShader::SetPixelShader
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x0,
               *(CPlugFileGPUP **)(this + 0x14a0));
    break;
  case (CVisionViewportDx9 *)0x15:
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x1,
               0,(GxColor *)unaff_EDI);
    CPlugShader::SetReceiverDisable(*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),unaff_ESI);
    CPlugShader::SetFogEnable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,
               (int)unaff_EBP);
    pCVar9 = CPlugShaderApply::AddTextureApply
                       (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                        *(CPlugShaderApply **)(this + 0x151c),(CPlugBitmap *)0x0,0,(ulong)unaff_EBX)
    ;
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x1,(int)this_00);
    pCVar35 = *(CPlugShader **)(this + (int)param_1 * 4 + 0x1294);
    pCVar10 = StdGpuVGet(this,(CVisionViewportDx9 *)&DAT_00000005,DAT_00d77b10,(SStdGpuMask)0x1,
                         (int)in_stack_fffffeb0);
    CPlugShader::SetVertexShader(pCVar35,(CPlugShaderPass *)0x0,pCVar10);
    CPlugShader::SetPixelShader
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x0,
               *(CPlugFileGPUP **)(this + 0x14a4));
    break;
  case (CVisionViewportDx9 *)0x16:
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x1,
               0,(GxColor *)unaff_EDI);
    CPlugShader::SetReceiverDisable(*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),unaff_ESI);
    CPlugShader::SetFogEnable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,
               (int)unaff_EBP);
    pCVar9 = CPlugShaderApply::AddTextureApply
                       (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                        *(CPlugShaderApply **)(this + 0x1534),(CPlugBitmap *)0x0,0xffffffff,
                        (ulong)unaff_EBX);
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x1,(int)this_00);
    pCVar35 = *(CPlugShader **)(this + (int)param_1 * 4 + 0x1294);
    pCVar10 = StdGpuVGet(this,(CVisionViewportDx9 *)&DAT_00000006,DAT_00d77b0c,(SStdGpuMask)0x1,
                         (int)in_stack_fffffeb0);
    CPlugShader::SetVertexShader(pCVar35,(CPlugShaderPass *)0x0,pCVar10);
    CPlugShader::SetPixelShader
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x0,
               *(CPlugFileGPUP **)(this + 0x14a8));
    break;
  case (CVisionViewportDx9 *)0x17:
    pCVar7 = operator_new(0xe0);
    if (pCVar7 == (CPlugFileVHlsl *)0x0) {
      iVar12 = 0;
    }
    else {
      CPlugFileVHlsl::CPlugFileVHlsl(pCVar7,(CPlugFileVHlsl *)unaff_EDI);
      iVar12 = extraout_EAX_01;
    }
    uVar26 = 0x999cea;
    SStringParam::SStringParam
              (&local_48,
               (SStringParam *)
               "struct VS_INPUT {\r\n\tfloat4 Position : POSITION;\r\n};\r\nstruct VS_OUTPUT {\r\n\tfloat4 Position\t: POSITION;\r\n\tfloat3 EyeInLight: TEXCOORD0;\r\n};\r\nconst float4x3\tVisualToLight = {\r\n\t1,0,0,\r\n\t0,1,0,\r\n\t0,0,1,\r\n\t0,0,0 \r\n};\r\nvs_1_1 VS_OUTPUT vsMain(const VS_INPUT v,\r\n\tuniform float4x4\tGbxVisualPrCamera)\r\n{\r\n\tVS_OUTPUT Output = (VS_OUTPUT)0;\r\n\tOutput.Position\t= mul(v.Position, GbxVisualPrCamera);\r\n\tfloat3\tEyeVect = float3(v.Position.x, v.Position.y, 1);\r\n\tOutput.EyeInLight= mul(EyeVect, VisualToLight);\r\n\treturn Output;\r\n}\r\n"
               ,(char *)unaff_EDI);
    iVar13 = 0x999cfa;
    CFastString::SetString((CFastString *)(iVar12 + 0x14),local_44,(SStringParam *)unaff_ESI);
    pCVar4 = operator_new(0x78);
    if (pCVar4 == (CPlugBitmap *)0x0) {
      pCVar4 = (CPlugBitmap *)0x0;
    }
    else {
      CPlugBitmap::CPlugBitmap(pCVar4,(CPlugBitmap *)in_stack_fffffe6c);
      pCVar4 = extraout_EAX_02;
    }
    uStack_30 = 0xffffffff;
    this_01 = operator_new(0x50);
    uStack_30 = 4;
    if (this_01 == (CPlugFileGen *)0x0) {
      this_05 = (CPlugFileGen *)0x0;
    }
    else {
      CPlugFileGen::CPlugFileGen(this_01,(CPlugFileGen *)in_stack_fffffe6c);
      this_05 = extraout_EAX_03;
    }
    local_100 = 0x3f800000;
    local_fc = 0x3f800000;
    uStack_f8 = 0x3f800000;
    uStack_f4 = 0x3f800000;
    local_e0 = 0;
    local_dc = 0;
    uStack_30 = 0xffffffff;
    iStack_d8 = 0;
    local_d4 = 0x3f800000;
    CPlugFileGen::GenCubeNormals
              (this_05,(CPlugFileGen *)&DAT_00000040,1,(ulong)&local_e0,(GxColor *)&local_100,
               (GxColor *)in_stack_fffffe6c);
    CPlugBitmap::SetImage(pCVar4,(CVisionTexConverter *)this_05,in_stack_fffffe70);
    CPlugBitmap::SetMipMapping(pCVar4,(CPlugBitmap *)0x0,(int)in_stack_fffffe74);
    CPlugBitmap::SetDefaultTexFilter(pCVar4,(CPlugBitmap *)0x2,(EGxTexFilter)in_stack_fffffe78);
    pCVar5 = operator_new(0xcc);
    local_20 = 5;
    if (pCVar5 == (CPlugFilePsh *)0x0) {
      pCVar17 = (CPlugFileGPUP *)0x0;
    }
    else {
      CPlugFilePsh::CPlugFilePsh(pCVar5,(CPlugFilePsh *)in_stack_fffffe7c);
      pCVar17 = extraout_EAX_04;
    }
    local_20 = 0xffffffff;
    CFastString::operator<<
              ((CFastString *)(pCVar17 + 0x14),
               (CPlugFileGpuBuilder *)
               "ps_1_1\t\t\t\t\t\t\t\r\n// Decl(t0, NormalInCamera)\t\r\n// Decl(t1, Specular)\t\t\t\r\ntex\t\tt0\t\t\t\t\t\r\ntexreg2gb\tt1, t0\t\t\t\t\r\nmov\t\tr0.rgb, 1-t1\t\t\r\n+mov\t\tr0.a,\t1-t1.b\t\t\r\n"
               ,(char *)in_stack_fffffe7c);
    CPlugShader::SetDoubleSided
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x1,(int)this_01);
    local_a8 = _DAT_00b31460;
    uStack_a4 = _DAT_00b31460;
    uStack_a0 = 0x3f800000;
    uStack_9c = 0x3f800000;
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x0,
               (EPlugShaderVertexColor)&local_a8,(GxColor *)in_stack_fffffe84);
    CPlugShader::SetReceiverDisable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),in_stack_fffffe88);
    CPlugShader::SetVertexShader
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x0,
               (CPlugFileGPUV *)unaff_EBP);
    CPlugShader::SetPixelShader
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x0,pCVar17);
    pCVar9 = CPlugShaderApply::AddTextureApply
                       (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                        (CPlugShaderApply *)pCVar4,(CPlugBitmap *)0x0,0xffffffff,
                        (ulong)in_stack_fffffe8c);
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x1,(int)pCVar5);
    EVar21 = 0xffffffff;
    goto LAB_00999ea8;
  case (CVisionViewportDx9 *)0x18:
    pCVar7 = operator_new(0xe0);
    if (pCVar7 == (CPlugFileVHlsl *)0x0) {
      iVar12 = 0;
    }
    else {
      CPlugFileVHlsl::CPlugFileVHlsl(pCVar7,(CPlugFileVHlsl *)unaff_EDI);
      iVar12 = extraout_EAX_05;
    }
    uVar26 = 0x999f18;
    SStringParam::SStringParam
              (local_58,(SStringParam *)
                        "struct VS_INPUT {\r\n\tfloat4 Position : POSITION;\r\n\tfloat3 LDirInTgt: NORMAL;\r\n\tfloat4 Color0   : COLOR0;\r\n\tfloat2 TexCoord : TEXCOORD0;\r\n};\r\nstruct VS_OUTPUT {\r\n\tfloat4 Position\t: POSITION;\r\n\tfloat4 Color0    : COLOR0;\r\n\tfloat2 TcNormal\t: TEXCOORD0;\r\n\tfloat3 LDirInTgt\t: TEXCOORD1;\r\n\tfloat3 NullVect\t: TEXCOORD2;\r\n};\r\n\tconst float4x4\tGbxVisualPrCamera;\r\nvs_1_1 VS_OUTPUT vsMain(const VS_INPUT v)\r\n{\r\n\tVS_OUTPUT Output = (VS_OUTPUT)0;\r\n\tOutput.Position\t= mul(v.Position, GbxVisualPrCamera);\r\n\tOutput.Color0\t= v.Color0;\r\n\tOutput.TcNormal\t= v.TexCoord;\r\n\tOutput.LDirInTgt = v.LDirInTgt;\r\n\tOutput.NullVect\t= 0;\r\n\treturn Output;\r\n}\r\n"
               ,(char *)unaff_EDI);
    iVar13 = 0x999f28;
    CFastString::SetString((CFastString *)(iVar12 + 0x14),local_54,(SStringParam *)unaff_ESI);
    pCVar10 = *(CPlugFileGPUV **)(this + 0x1538);
    pCVar33 = pCVar10;
    (**(code **)(*(int *)this + 0xb0))();
    pcVar24 = "";
    if ((*(byte *)(*(int *)(pCVar10 + 0x14) + 0x20) & 0x10) == 0) {
      pcVar24 = "_bx2";
    }
    pCVar5 = operator_new(0xcc);
    uStack_34 = 7;
    if (pCVar5 == (CPlugFilePsh *)0x0) {
      pCVar17 = (CPlugFileGPUP *)0x0;
    }
    else {
      CPlugFilePsh::CPlugFilePsh(pCVar5,in_stack_fffffe68);
      pCVar17 = extraout_EAX_06;
    }
    pcVar19 = 
    "\r\nmul\t\tr0.rgb, t2, v0\t\t\r\n+mul\t\tr0.a,\tt2,\tt2\t\t\r\nmul\t\tr0.a,\tr0,\tr0\t\t\r\nmul\t\tr0.a,\tr0,\tr0\t\t\r\nmul\t\tr0.a,\tr0, v0\t\t\r\n"
    ;
    pcVar18 = "\r\ntexm3x2tex\tt2, t0";
    uStack_34 = 0xffffffff;
    pCVar6 = CFastString::operator<<
                       ((CFastString *)(pCVar17 + 0x14),
                        (CPlugFileGpuBuilder *)
                        "ps_1_1\t\t\t\t\t\t\t\r\n// Decl(t0, NormalInCamera)\t\r\n// t1 = LDirInCamera\t\t\t\r\n// Decl(t2, Specular)\t\t\t\r\ntex\t\tt0\t\t\t\t\t\r\ntexm3x2pad\tt1, t0"
                        ,pcVar24);
    pCVar6 = CFastString::operator<<((CFastString *)pCVar6,(CPlugFileGpuBuilder *)pcVar18,pcVar24);
    pCVar6 = CFastString::operator<<
                       ((CFastString *)pCVar6,(CPlugFileGpuBuilder *)pcVar19,
                        (char *)in_stack_fffffe68);
    pCVar6 = CFastString::operator<<
                       ((CFastString *)pCVar6,in_stack_fffffe6c,(char *)in_stack_fffffe70);
    CFastString::operator<<((CFastString *)pCVar6,in_stack_fffffe74,(char *)in_stack_fffffe78);
    CPlugShader::SetDoubleSided
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x1,
               (int)in_stack_fffffe7c);
    local_8c = _DAT_00b31460;
    local_88 = _DAT_00b31460;
    uStack_84 = 0x3f800000;
    iStack_80 = 0x3f800000;
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x0,
               (EPlugShaderVertexColor)&local_8c,in_stack_fffffe80);
    CPlugShader::SetReceiverDisable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)pCVar5);
    CPlugShader::SetVertexShader
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x0,pCVar33);
    CPlugShader::SetPixelShader
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x0,pCVar17);
    CPlugShaderApply::SetBlending
              (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x1,1,
               (EGxBlendFactor)in_stack_fffffe88);
    pCVar9 = CPlugShaderApply::AddTextureApply
                       (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                        (CPlugShaderApply *)pCVar33,(CPlugBitmap *)0x0,0,(ulong)in_stack_fffffe8c);
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x1,(int)pGVar20);
    EVar21 = 0;
LAB_00999ea8:
    pCVar3 = *(CPlugShaderApply **)(this + 0x151c);
LAB_00999eb1:
    pCVar9 = CPlugShaderApply::AddTextureApply
                       (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),pCVar3,
                        (CPlugBitmap *)0x0,EVar21,uVar26);
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x1,iVar13);
    break;
  case (CVisionViewportDx9 *)0x19:
    pCVar7 = operator_new(0xe0);
    if (pCVar7 != (CPlugFileVHlsl *)0x0) {
      CPlugFileVHlsl::CPlugFileVHlsl(pCVar7,(CPlugFileVHlsl *)unaff_EDI);
      EVar15 = extraout_EAX_07;
    }
    SStringParam::SStringParam
              (auStack_60,
               (SStringParam *)
               "struct VS_INPUT {\r\n\tfloat4 Position : POSITION;\r\n\tfloat3 LDirInTgt: NORMAL;\r\n\tfloat4 Color0   : COLOR0;\r\n\tfloat2 TexCoord : TEXCOORD0;\r\n};\r\nstruct VS_OUTPUT {\r\n\tfloat4 Position\t: POSITION;\r\n\tfloat4 Color0    : COLOR0;\r\n\tfloat2 TcNormal\t: TEXCOORD0;\r\n\tfloat3 LDirInTgt\t: TEXCOORD1;\r\n};\r\n\tconst float4x4\tGbxVisualPrCamera;\r\nvs_1_1 VS_OUTPUT vsMain(const VS_INPUT v)\r\n{\r\n\tVS_OUTPUT Output = (VS_OUTPUT)0;\r\n\tOutput.Position\t= mul(v.Position, GbxVisualPrCamera);\r\n\tOutput.Color0\t= v.Color0;\r\n\tOutput.TcNormal\t= v.TexCoord;\r\n\tOutput.LDirInTgt = v.LDirInTgt;\r\n\treturn Output;\r\n}\r\n"
               ,(char *)unaff_EDI);
    EVar32 = 0x99a0cf;
    CFastString::SetString((CFastString *)(EVar15 + 0x14),aCStack_5c,(SStringParam *)unaff_ESI);
    pCVar3 = *(CPlugShaderApply **)(this + 0x1538);
    (**(code **)(*(int *)this + 0xb0))();
    pCVar35 = (CPlugShader *)&DAT_00b2c878;
    if ((*(byte *)(*(int *)(pCVar3 + 0x14) + 0x20) & 0x10) == 0) {
      pCVar35 = (CPlugShader *)&DAT_00bd4ec8;
    }
    pCVar8 = operator_new(0xcc);
    local_24 = 9;
    if (pCVar8 == (CPlugFilePHlsl *)0x0) {
      pCVar17 = (CPlugFileGPUP *)0x0;
    }
    else {
      CPlugFilePHlsl::CPlugFilePHlsl(pCVar8,in_stack_fffffe78);
      pCVar17 = extraout_EAX_08;
    }
    pcVar24 = 
    ";\r\n\tfpart3 LDirInTgt = v.LDirInTgt;\r\n\tclip(dot(Normal,Normal)-0.01);\r\n\tNormal = normalize(Normal);\r\n\tfpart  Dot = saturate(dot(Normal, LDirInTgt));\r\n\tOutput.Color.rgb = pow(Dot, ExpL);\r\n\tOutput.Color.a   = pow(Dot, ExpA);\r\n\tOutput.Color\t\t= Output.Color*v.Color0;\r\n\treturn Output;\r\n}\r\nps_2_0 PS_OUTPUT psMain(const PS_INPUT v) {return Main(v);}\r\nps_2_a PS_OUTPUT psMain(const PS_INPUT v) {return Main(v);}\r\n"
    ;
    local_24 = 0xffffffff;
    pCVar6 = CFastString::operator<<
                       ((CFastString *)(pCVar17 + 0x14),
                        (CPlugFileGpuBuilder *)
                        "#include <Common.PHlsl.txt>\r\nstruct PS_INPUT {\r\n\tfpart4 Color0    : COLOR0;\r\n\tfloat2 TcNormal\t: TEXCOORD0;\r\n\tfpart3 LDirInTgt\t: TEXCOORD1;\r\n};\r\nstruct PS_OUTPUT {\r\n\tfpart4 Color\t: COLOR0;\r\n};\r\nsampler2D\tMapNormal;\r\nfloat\t\tExpL = 1.f;\r\nfloat\t\tExpA =50.f;\r\nPS_OUTPUT Main(const PS_INPUT v)\r\n{\r\n\tPS_OUTPUT\tOutput = (PS_OUTPUT) 0;\r\n\tfpart3 Normal = tex2D(MapNormal, v.TcNormal)"
                        ,(char *)pCVar35);
    pCVar6 = CFastString::operator<<
                       ((CFastString *)pCVar6,(CPlugFileGpuBuilder *)pcVar24,
                        (char *)in_stack_fffffe78);
    CFastString::operator<<((CFastString *)pCVar6,in_stack_fffffe7c,(char *)in_stack_fffffe80);
    pCVar9 = CPlugShaderApply::AddTextureApply
                       (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),pCVar3,
                        (CPlugBitmap *)0x0,0,(ulong)in_stack_fffffe84);
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x1,(int)in_stack_fffffe88);
    CPlugShader::SetDoubleSided
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x1,(int)pCVar8);
    local_10c = _DAT_00b31460;
    local_108 = _DAT_00b31460;
    local_104 = 0x3f800000;
    local_100 = 0x3f800000;
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x0,
               (EPlugShaderVertexColor)&local_10c,pGVar20);
    CPlugShader::SetReceiverDisable(*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),pCVar35);
    CPlugShader::SetVertexShader
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x0,
               (CPlugFileGPUV *)pCVar7);
    CPlugShader::SetPixelShader
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x0,pCVar17);
    EVar27 = 1;
    goto LAB_0099a983;
  case (CVisionViewportDx9 *)0x1a:
  case (CVisionViewportDx9 *)0x1b:
  case (CVisionViewportDx9 *)0x1c:
  case (CVisionViewportDx9 *)0x1d:
  case (CVisionViewportDx9 *)0x1e:
  case (CVisionViewportDx9 *)0x1f:
    if (((param_1 == (CVisionViewportDx9 *)&DAT_0000001d) || (param_1 == (CVisionViewportDx9 *)0x1b)
        ) || (param_1 == (CVisionViewportDx9 *)0x1f)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (((param_1 == (CVisionViewportDx9 *)&DAT_0000001a) || (param_1 == (CVisionViewportDx9 *)0x1b)
        ) || ((param_1 == (CVisionViewportDx9 *)0x1e || (param_1 == (CVisionViewportDx9 *)0x1f)))) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    iVar13 = 0;
    if (bVar1) {
      pCVar7 = operator_new(0xe0);
      if (pCVar7 != (CPlugFileVHlsl *)0x0) {
        CPlugFileVHlsl::CPlugFileVHlsl(pCVar7,(CPlugFileVHlsl *)unaff_EDI);
        iVar13 = extraout_EAX_09;
      }
      pcVar24 = (char *)0x99a286;
      SStringParam::SStringParam
                (local_50,(SStringParam *)"struct VS_INPUT {\r\n\tfloat4 Position : POSITION;\r\n",
                 (char *)unaff_EDI);
      unaff_EDI = local_4c;
      pCVar14 = (CFastString *)(iVar13 + 0x14);
      pSVar29 = (SStringParam *)0x99a298;
      CFastString::SetString(pCVar14,unaff_EDI,(SStringParam *)unaff_ESI);
      if (bVar2) {
        unaff_EDI = (CFastStringInt *)0x99a2ad;
        SStringParam::SStringParam
                  (&uStack_30,(SStringParam *)"\tfloat2 TcAlpha : TEXCOORD0;\r\n",(char *)unaff_EBP)
        ;
        CFastString::Concat(pCVar14,aCStack_2c,unaff_EBX);
      }
      in_stack_fffffe7c = (CPlugFileGpuBuilder *)0x99a2cd;
      SStringParam::SStringParam
                (local_40,(SStringParam *)
                          "};\r\nstruct VS_OUTPUT {\r\n\tfloat4 Position\t: POSITION;\r\n\tfloat4 PosInW\t: TEXCOORD0;\r\n\tfloat2 TcAlpha\t: TEXCOORD1;\r\n};\r\nconst float4x4\tGbxVisualPrCamera;\r\nconst float4x4\tGbxVisualToWorld;\r\nvs_1_1 VS_OUTPUT vsMain(const VS_INPUT v)\r\n{\r\n\tVS_OUTPUT Output = (VS_OUTPUT)0;\r\n\tOutput.Position\t= mul(v.Position, GbxVisualPrCamera);\r\n\tOutput.PosInW.xyz= mul(v.Position, GbxVisualToWorld);\r\n\tOutput.PosInW.w\t= 1;\r\n"
                 ,(char *)in_stack_fffffe84);
      in_stack_fffffe84 = local_3c;
      in_stack_fffffe80 = (GxColor *)0x99a2dc;
      CFastString::Concat(pCVar14,in_stack_fffffe84,(SStringParam *)in_stack_fffffe88);
      if (bVar2) {
        in_stack_fffffe84 = (CFastStringInt *)0x99a2f1;
        SStringParam::SStringParam
                  (local_50,(SStringParam *)"\tOutput.TcAlpha = v.TcAlpha;\r\n",
                   (char *)in_stack_fffffe8c);
        in_stack_fffffe88 = (CPlugShader *)0x99a300;
        CFastString::Concat(pCVar14,local_4c,(SStringParam *)pGVar20);
      }
      in_stack_fffffe8c = (CPlugBitmapSampler *)0x99a311;
      SStringParam::SStringParam(local_38,(SStringParam *)"\treturn Output;\r\n}\r\n",pcVar24);
      pGVar20 = (GxColor *)0x99a320;
      CFastString::Concat(pCVar14,(CFastStringInt *)&uStack_34,pSVar29);
    }
    iVar13 = 0xcc;
    uVar26 = 0x99a330;
    pCVar8 = operator_new(0xcc);
    if (pCVar8 == (CPlugFilePHlsl *)0x0) {
      pCVar17 = (CPlugFileGPUP *)0x0;
    }
    else {
      iVar13 = 0x99a34d;
      CPlugFilePHlsl::CPlugFilePHlsl(pCVar8,(CPlugFilePHlsl *)unaff_EDI);
      pCVar17 = extraout_EAX_10;
    }
    pCVar14 = (CFastString *)(pCVar17 + 0x14);
    local_48 = 0xffffffff;
    CFastString::operator<<
              (pCVar14,(CPlugFileGpuBuilder *)
                       "#include <Common.PHlsl.txt>\r\nstruct PS_INPUT {\r\n\tfloat4 PosInW : TEXCOORD0;\r\n"
               ,in_stack_fffffe54);
    if (in_stack_fffffe70 != (CPlugFileImg *)0x0) {
      CFastString::operator<<
                (pCVar14,(CPlugFileGpuBuilder *)"\tfloat2 TcAlpha\t: TEXCOORD1;\r\n",
                 in_stack_fffffe58);
    }
    CFastString::operator<<
              (pCVar14,(CPlugFileGpuBuilder *)
                       "};\r\nstruct PS_OUTPUT {\r\n\tfloat4 Color : COLOR0;\r\n};\r\nsampler2D MapWaterFogDayTimed;\r\n"
               ,in_stack_fffffe5c);
    if (in_stack_fffffe78 != (CPlugFilePHlsl *)0x0) {
      CFastString::operator<<
                (pCVar14,(CPlugFileGpuBuilder *)"sampler2D MapAlpha;\r\n",in_stack_fffffe60);
    }
    CFastString::operator<<
              (pCVar14,(CPlugFileGpuBuilder *)
                       "ps_2_0 PS_OUTPUT psMain(const PS_INPUT v)\r\n{\r\n\tPS_OUTPUT Output = (PS_OUTPUT) 0;\r\n"
               ,in_stack_fffffe64);
    if (in_stack_fffffe80 != (GxColor *)0x0) {
      CFastString::operator<<
                (pCVar14,(CPlugFileGpuBuilder *)
                         "\tfloat Alpha = tex2D(MapAlpha, v.TcAlpha).a;\r\n\tclip(Alpha-0.5);\r\n",
                 (char *)in_stack_fffffe68);
    }
    CFastString::operator<<
              (pCVar14,(CPlugFileGpuBuilder *)
                       "\tfloat EyeWaterLen_ToDiv;\r\n\tfloat EyeWaterLen_Div;\r\n",
               (char *)in_stack_fffffe6c);
    if (in_stack_fffffe84 == (CFastStringInt *)0x0) {
      pcVar24 = "\tGetEyeWaterLen_QuotientInV(EyeWaterLen_ToDiv, EyeWaterLen_Div, v.PosInW);\r\n";
    }
    else {
      pcVar24 = 
      "\tGetEyeWaterLen_QuotientInV_TileH(EyeWaterLen_ToDiv, EyeWaterLen_Div, v.PosInW);\r\n";
    }
    CFastString::operator<<(pCVar14,(CPlugFileGpuBuilder *)pcVar24,(char *)in_stack_fffffe70);
    CFastString::operator<<
              (pCVar14,(CPlugFileGpuBuilder *)
                       "\tfloat4 TcWaterFog;\r\n\tTcWaterFog.zw = EyeWaterLen_Div;\r\n\tTcWaterFog.y = TcWaterFog.w-EyeWaterLen_ToDiv*GbxWaterDepthMax_yInv_FracST.y;\r\n\tTcWaterFog.x = GbxDayTime.y*TcWaterFog.w;\r\n\tOutput.Color = tex2Dproj(MapWaterFogDayTimed, TcWaterFog);\r\n\treturn Output;\r\n}\r\n"
               ,(char *)in_stack_fffffe74);
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x1,
               0,(GxColor *)in_stack_fffffe78);
    CPlugShader::SetReceiverDisable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)in_stack_fffffe7c)
    ;
    if (unaff_EDI != (CFastStringInt *)0x0) {
      CPlugShader::SetVertexShader
                (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x0,
                 (CPlugFileGPUV *)unaff_EDI);
    }
    CPlugShader::SetPixelShader
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x0,pCVar17);
    CPlugShaderApply::SetBlending
              (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
               (CPlugShaderPass *)&DAT_00000004,5,(EGxBlendFactor)in_stack_fffffe80);
    pCVar9 = CPlugShaderApply::AddTextureApply
                       (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                        *(CPlugShaderApply **)(this + 0x151c),(CPlugBitmap *)0x0,0xffffffff,
                        (ulong)in_stack_fffffe84);
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x1,(int)in_stack_fffffe88);
    CPlugBitmapAddress::SetGenerateUV
              ((CPlugBitmapAddress *)pCVar9,(CPlugBitmapAddress *)0x2,0,(int)in_stack_fffffe8c);
    CPlugBitmapAddress::Force3Components
              ((CPlugBitmapAddress *)pCVar9,(CPlugBitmapAddress *)0x1,(int)pGVar20);
    if (this_00 == (CPlugShaderApply *)0x0) break;
    pCVar3 = *(CPlugShaderApply **)(this + 0x151c);
    EVar21 = 0;
    goto LAB_00999eb1;
  case (CVisionViewportDx9 *)0x20:
  case (CVisionViewportDx9 *)0x22:
    goto switchD_0099924c_caseD_20;
  case (CVisionViewportDx9 *)0x21:
  case (CVisionViewportDx9 *)0x23:
    EVar15 = DAT_00d77b0c | 1;
    goto switchD_0099924c_caseD_20;
  case (CVisionViewportDx9 *)0x24:
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x1,
               0,(GxColor *)unaff_EDI);
    CPlugShader::SetFogEnable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,
               (int)unaff_ESI);
    CPlugShader::SetReceiverDisable(*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),unaff_EBP);
    EVar32 = 0x99a676;
    pCVar9 = CPlugShaderApply::AddTextureApply
                       (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                        *(CPlugShaderApply **)(this + 0x151c),(CPlugBitmap *)0x0,0,(ulong)unaff_EBX)
    ;
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x0,(int)this_00);
    CPlugBitmapSampler::SetTexAddress
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x2,2,0,
               (EGxTexAddress)in_stack_fffffeb0);
    CPlugBitmapSampler::SetFiltering
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x0,in_stack_fffffeb4);
    pCVar10 = StdGpuVGet(this,(CVisionViewportDx9 *)0x15,DAT_00d77b0c,(SStdGpuMask)0x1,EVar15);
    pCVar17 = *(CPlugFileGPUP **)(this + 0x14ec);
    goto LAB_0099a963;
  case (CVisionViewportDx9 *)0x25:
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x1,
               0,(GxColor *)unaff_EDI);
    CPlugShader::SetFogEnable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,
               (int)unaff_ESI);
    CPlugShader::SetReceiverDisable(*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),unaff_EBP);
    EVar32 = 0x99a6f6;
    pCVar9 = CPlugShaderApply::AddTextureApply
                       (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                        *(CPlugShaderApply **)(this + 0x151c),(CPlugBitmap *)0x0,0xffffffff,
                        (ulong)unaff_EBX);
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x0,(int)this_00);
    CPlugBitmapSampler::SetTexAddress
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x0,0,0,
               (EGxTexAddress)in_stack_fffffeb0);
    CPlugBitmapSampler::SetFiltering
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x1,in_stack_fffffeb4);
    pCVar10 = StdGpuVGet(this,(CVisionViewportDx9 *)&DAT_0000001a,DAT_00d77b0c,(SStdGpuMask)0x1,
                         EVar15);
    CPlugShader::SetVertexShader
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x0,pCVar10);
    goto LAB_0099a981;
  case (CVisionViewportDx9 *)0x26:
  case (CVisionViewportDx9 *)0x27:
  case (CVisionViewportDx9 *)0x28:
  case (CVisionViewportDx9 *)0x29:
    CPlugShaderGeneric::SetVertexColor
              (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x1,
               0,(GxColor *)unaff_EDI);
    CPlugShader::SetFogEnable
              (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,
               (int)unaff_ESI);
    CPlugShader::SetReceiverDisable(*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),unaff_EBP);
    EVar32 = 0x99a77f;
    pCVar9 = CPlugShaderApply::AddTextureApply
                       (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                        *(CPlugShaderApply **)(this + 0x151c),(CPlugBitmap *)0x0,0,(ulong)unaff_EBX)
    ;
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x0,(int)this_00);
    CPlugBitmapSampler::SetTexAddress
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x0,0,0,
               (EGxTexAddress)in_stack_fffffeb0);
    CPlugBitmapSampler::SetFiltering
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x1,in_stack_fffffeb4);
    pCVar10 = StdGpuVGet(this,(CVisionViewportDx9 *)
                              ((param_1 != (CVisionViewportDx9 *)&DAT_00000026) + 0x1b),DAT_00d77b0c
                         ,(SStdGpuMask)0x1,EVar15);
    if (param_1 == (CVisionViewportDx9 *)&DAT_00000026) {
      pCVar17 = *(CPlugFileGPUP **)(this + 0x1500);
    }
    else if (param_1 == (CVisionViewportDx9 *)0x27) {
      pCVar17 = *(CPlugFileGPUP **)(this + 0x1504);
    }
    else if (param_1 == (CVisionViewportDx9 *)&DAT_00000028) {
      pCVar17 = *(CPlugFileGPUP **)(this + 0x1508);
    }
    else {
      iVar13 = 0x26;
      if (param_1 != (CVisionViewportDx9 *)&DAT_00000029) {
        iVar13 = local_124;
      }
      pCVar17 = *(CPlugFileGPUP **)(this + iVar13 * 4 + 0x1474);
    }
    goto LAB_0099a963;
  case (CVisionViewportDx9 *)0x2a:
  case (CVisionViewportDx9 *)0x2c:
  case (CVisionViewportDx9 *)0x2e:
  case (CVisionViewportDx9 *)0x30:
    goto switchD_0099924c_caseD_2a;
  case (CVisionViewportDx9 *)0x2b:
  case (CVisionViewportDx9 *)0x2d:
  case (CVisionViewportDx9 *)0x2f:
  case (CVisionViewportDx9 *)0x31:
    goto switchD_0099924c_caseD_2a;
  }
switchD_0099924c_default:
  (**(code **)(**(int **)(this + (int)param_1 * 4 + 0x1294) + 0xa8))();
  (**(code **)(**(int **)(this + (int)param_1 * 4 + 0x1294) + 0xac))();
  ExceptionList = puStack_8;
  return *(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294);
switchD_0099924c_caseD_2a:
  Shadow_CanRenderInTexDepth(this,(CVisionViewportDx9 *)unaff_EDI);
  uVar26 = 0x99a846;
  CPlugShaderGeneric::SetVertexColor
            (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x1,0,
             (GxColor *)unaff_ESI);
  EVar32 = 0x99a856;
  CPlugShader::SetFogEnable
            (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,(int)unaff_EBP
            );
  pCVar35 = *(CPlugShader **)(this + (int)param_1 * 4 + 0x1294);
  CPlugShader::SetReceiverShadowGroupMask(pCVar35,(CPlugShader *)0x0,(ulong)unaff_EBX);
  pCVar34 = (CPlugBitmapSampler *)0x0;
  CHmsItem::SetIsForcePointDynamicCollisionResponse
            ((CHmsItem *)pCVar35,(CHmsItem *)0x0,(int)this_00);
  if ((int)(param_1 + -0x2a) / 2 != -1) {
    do {
      pCVar9 = CPlugShaderApply::AddTextureApply
                         (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                          *(CPlugShaderApply **)(this + 0x151c),(CPlugBitmap *)0x0,0xffffffff,
                          (ulong)in_stack_fffffe84);
      CPlugBitmapSampler::SetUseBitmapDefaults
                ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x0,(int)in_stack_fffffe88);
      in_stack_fffffe84 = (CFastStringInt *)0x2;
      CPlugBitmapSampler::SetTexAddress
                ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x2,2,0,
                 (EGxTexAddress)in_stack_fffffe8c);
      in_stack_fffffe8c = pCVar34;
      in_stack_fffffe88 = (CPlugShader *)0x99a8cb;
      pCVar34 = in_stack_fffffe8c;
      CPlugBitmapSampler::SetFiltering
                ((CPlugBitmapSampler *)pCVar9,in_stack_fffffe8c,(EGxTexFilter)pGVar20);
      pCVar34 = pCVar34 + -1;
    } while (pCVar34 != (CPlugBitmapSampler *)0x0);
  }
  EVar16 = (uint)in_stack_fffffeb0 & 1;
  if (EVar16 != 0) {
    pCVar9 = CPlugShaderApply::AddTextureApply
                       (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                        *(CPlugShaderApply **)(this + 0x151c),(CPlugBitmap *)0x0,0,uVar26);
    uVar26 = 1;
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x1,EVar32);
  }
  switch((int)(param_1 + -0x2a) / 2) {
  default:
    pCVar10 = StdGpuVGet(this,(CVisionViewportDx9 *)&DAT_00000011,(EStdGpuV)in_stack_fffffeb0,
                         (SStdGpuMask)0x1,uVar26);
    EVar16 = EVar16 | 0x16;
    break;
  case 1:
    pCVar10 = StdGpuVGet(this,(CVisionViewportDx9 *)&DAT_00000012,(EStdGpuV)in_stack_fffffeb0,
                         (SStdGpuMask)0x1,uVar26);
    EVar16 = EVar16 | 0x18;
    break;
  case 2:
    pCVar10 = StdGpuVGet(this,(CVisionViewportDx9 *)&DAT_00000013,(EStdGpuV)in_stack_fffffeb0,
                         (SStdGpuMask)0x1,uVar26);
    EVar16 = EVar16 | 0x1a;
    break;
  case 3:
    pCVar10 = StdGpuVGet(this,(CVisionViewportDx9 *)&DAT_00000014,(EStdGpuV)in_stack_fffffeb0,
                         (SStdGpuMask)0x1,uVar26);
    EVar16 = EVar16 | 0x1c;
  }
  pCVar17 = *(CPlugFileGPUP **)(this + EVar16 * 4 + 0x1474);
LAB_0099a963:
  CPlugShader::SetVertexShader
            (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x0,pCVar10);
  CPlugShader::SetPixelShader
            (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x0,pCVar17);
LAB_0099a981:
  EVar27 = 0;
LAB_0099a983:
  pCVar22 = (CPlugShaderPass *)0x1;
LAB_0099a985:
  CPlugShaderApply::SetBlending
            (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),pCVar22,EVar27,EVar32);
  goto switchD_0099924c_default;
switchD_0099924c_caseD_20:
  if ((param_1 == (CVisionViewportDx9 *)0x22) || (param_1 == (CVisionViewportDx9 *)&DAT_00000023)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  EVar37 = DAT_00d77b0c;
  pCVar10 = StdGpuVGet(this,(CVisionViewportDx9 *)(bVar2 + 0xf),EVar15,(SStdGpuMask)0x0,
                       (int)unaff_EDI);
  if (bVar2) {
    this_04 = *(CPlugFileGPU **)(this + (uint)((EVar15 & 1) != 0) * 4 + 0x14c0);
  }
  else {
    this_04 = *(CPlugFileGPU **)(this + (uint)((EVar15 & 1) != 0) * 4 + 0x14b8);
  }
  EVar15 = EVar15 & 1;
  pCVar30 = (CPlugFileGPU *)0x0;
  pCVar25 = (CPlugFileGPU *)0x1;
  CSystemFidParameters::SParam_Id::SParam_Id(aSStack_1c,(SParam_Id *)&DAT_00d6ecf0);
  puStack_8 = &DAT_0000000c;
  pCVar36 = in_stack_fffffeb0;
  CPlugFileGPU::DefineIdUpdateFromText(in_stack_fffffeb0,pCVar25);
  CPlugFileGPU::DefineIdUpdateFromText(this_04,pCVar30);
  CPlugFileVHlsl::ApplyFidParameter_Crypted
            ((CPlugFileVHlsl *)&local_20,(CPlugFilePHlsl *)in_stack_fffffeb0,(SParam_Id *)&local_20)
  ;
  pSVar31 = local_18;
  EVar32 = 0x99a551;
  pCVar25 = this_04;
  CPlugFilePHlsl::ApplyFidParameter_Crypted(this_02,(CPlugFilePHlsl *)this_04,pSVar31);
  CPlugShaderGeneric::SetVertexColor
            (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x1,0,
             (GxColor *)this_00);
  CPlugShader::SetFogEnable
            (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,(int)pCVar36);
  pCVar35 = *(CPlugShader **)(this + (int)param_1 * 4 + 0x1294);
  CPlugShader::SetReceiverShadowGroupMask(pCVar35,(CPlugShader *)0x0,EVar15);
  CHmsItem::SetIsForcePointDynamicCollisionResponse((CHmsItem *)pCVar35,(CHmsItem *)0x0,EVar37);
  pCVar35 = (CPlugShader *)0x99a5a4;
  pCVar9 = CPlugShaderApply::AddTextureApply
                     (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                      *(CPlugShaderApply **)(this + 0x151c),(CPlugBitmap *)0x0,0xffffffff,
                      (ulong)pCVar10);
  CPlugBitmapSampler::SetUseBitmapDefaults
            ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x1,in_stack_fffffec0);
  if (local_128 != 0) {
    pCVar9 = CPlugShaderApply::AddTextureApply
                       (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                        *(CPlugShaderApply **)(this + 0x151c),(CPlugBitmap *)0x0,0,in_stack_fffffec4
                       );
    CPlugBitmapSampler::SetUseBitmapDefaults
              ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x1,in_stack_fffffec8);
  }
  CPlugShader::SetVertexShader
            (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x0,
             (CPlugFileGPUV *)pCVar35);
  CPlugShader::SetPixelShader
            (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x0,
             (CPlugFileGPUP *)this_04);
  CPlugShaderApply::SetBlending
            (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x1,0,
             EVar32);
  CPlugShader::SetDoubleSided
            (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),pCVar35,(int)pCVar25);
  local_4 = 0xffffffff;
  CSystemFidParameters::SParam_Id::~SParam_Id((SParam_Id *)&local_24,pSVar31);
  goto switchD_0099924c_default;
switchD_0099924c_caseD_10:
  CPlugShaderGeneric::SetVertexColor
            (*(CPlugShaderGeneric **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderGeneric *)0x1,0,
             (GxColor *)unaff_EDI);
  CPlugShader::SetReceiverDisable(*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),unaff_ESI);
  CPlugShader::SetFogEnable
            (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShader *)0x0,0,(int)unaff_EBP
            );
  pCVar35 = *(CPlugShader **)(this + (int)param_1 * 4 + 0x1294);
  pCVar10 = StdGpuVGet(this,(CVisionViewportDx9 *)0x2,DAT_00d77b0c,(SStdGpuMask)0x1,(int)unaff_EBX);
  CPlugShader::SetVertexShader(pCVar35,(CPlugShaderPass *)0x0,pCVar10);
  CPlugShader::SetPixelShader
            (*(CPlugShader **)(this + (int)param_1 * 4 + 0x1294),(CPlugShaderPass *)0x0,
             *(CPlugFileGPUP **)(this + 0x1478));
  pCVar9 = CPlugShaderApply::AddTextureApply
                     (*(CPlugShaderApply **)(this + (int)param_1 * 4 + 0x1294),
                      *(CPlugShaderApply **)(this + 0x1534),(CPlugBitmap *)0x0,0xffffffff,
                      (ulong)this_00);
  CPlugBitmapSampler::SetUseBitmapDefaults
            ((CPlugBitmapSampler *)pCVar9,(CPlugBitmapSampler *)0x1,(int)in_stack_fffffeb0);
  goto switchD_0099924c_default;
}
}

// =================================================
// Function: CVisionViewportDx9::SurfaceFind
// =================================================
IDirect3DSurface9 * __thiscall
CVisionViewportDx9::SurfaceFind
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,ESurface param_2,GmNat2 *param_3,
          _D3DFORMAT param_4,_D3DMULTISAMPLE_TYPE param_5)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  int in_stack_00000018;
  
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (this + ((int)param_1 * 3 + 0x282) * 4,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    iVar1 = *(int *)param_3;
    do {
      pSVar3 = CFastArray<struct_CPlugMaterial::SDeviceMat>::operator[]
                         (this + ((int)param_1 * 3 + 0x282) * 4,pCVar4,unaff_ESI);
      if ((((*(int *)pSVar3 == iVar1) && (*(int *)(pSVar3 + 4) == *(int *)(param_4 + 4))) &&
          (*(_D3DMULTISAMPLE_TYPE *)(pSVar3 + 0xc) == param_5)) &&
         (*(int *)(pSVar3 + 0x10) == in_stack_00000018)) {
        return *(IDirect3DSurface9 **)(pSVar3 + 0x14);
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  return (IDirect3DSurface9 *)0x0;
}
}

// =================================================
// Function: CVisionViewportDx9::SurfaceFindOrAdd
// =================================================
IDirect3DSurface9 * __thiscall
CVisionViewportDx9::SurfaceFindOrAdd
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,ESurface param_2,GmNat2 *param_3,
          _D3DFORMAT param_4,_D3DMULTISAMPLE_TYPE param_5)
{
{
  ESurface EVar1;
  GmNat2 *pGVar2;
  IDirect3DSurface9 *pIVar3;
  CPlugFileGpuBuilder *pCVar4;
  int iVar5;
  char *unaff_EBX;
  CPlugFileGpuBuilder *unaff_EBP;
  _D3DFORMAT _Var6;
  int iVar7;
  IDirect3DSurface9 *unaff_ESI;
  _D3DMULTISAMPLE_TYPE unaff_EDI;
  CPlugFileGpuBuilder *unaff_retaddr;
  CPlugFileGpuBuilder *pCVar8;
  char *pcVar9;
  CPlugFileGpuBuilder *pCVar10;
  char *pcVar11;
  LPCSTR *ppCVar12;
  
  _Var6 = param_4;
  pGVar2 = param_3;
  EVar1 = param_2;
  pIVar3 = SurfaceFind(this,param_1,param_2,param_3,param_4,unaff_EDI);
  if (pIVar3 == (IDirect3DSurface9 *)0x0) {
    param_3 = (GmNat2 *)0x0;
    param_4 = 0;
    do {
      switch(param_2) {
      case 0:
        iVar7 = (**(code **)(**(int **)(this + 0x9f8) + 0x70))
                          (*(int **)(this + 0x9f8),*(undefined4 *)EVar1,*(undefined4 *)(EVar1 + 4),
                           pGVar2,_Var6,0,0,&param_4,0);
        break;
      case 1:
        iVar7 = SafeCreateDepthStencilSurface
                          (*(CSystemConfig **)(this + 0x24c),*(ulong *)EVar1,*(ulong *)(EVar1 + 4),
                           (_D3DFORMAT)pGVar2,_Var6,0,(IDirect3DSurface9 **)&param_4);
        break;
      case 2:
        iVar7 = (**(code **)(**(int **)(this + 0x9f8) + 0x90))
                          (*(int **)(this + 0x9f8),*(undefined4 *)EVar1,*(undefined4 *)(EVar1 + 4),
                           pGVar2,2,&param_4,0);
        break;
      case 3:
        iVar7 = (**(code **)(**(int **)(this + 0x9f8) + 0x90))
                          (*(int **)(this + 0x9f8),*(undefined4 *)EVar1,*(undefined4 *)(EVar1 + 4),
                           pGVar2,3,&param_4,0);
        break;
      default:
        iVar7 = -0x7789f796;
      }
      param_3 = param_3 + 1;
      if (iVar7 == -0x7789fe84) {
        if (DAT_00d71e54 != 0) {
          DAT_00d71e54 = 0;
          *DAT_00d71e58 = 0;
        }
        pcVar11 = (&PTR_s_render_target_00d38dcc)[param_2];
        pcVar9 = *(char **)(EVar1 + 4);
        ppCVar12 = &lpOutputString_00b2bcc4;
        pCVar10 = (CPlugFileGpuBuilder *)&DAT_00b2d0d4;
        pCVar8 = (CPlugFileGpuBuilder *)&DAT_00b2edc8;
        pCVar4 = CFastString::operator<<
                           ((CFastString *)&DAT_00d71e54,
                            (CPlugFileGpuBuilder *)"[Dx9] OutOfVideoMemory ",*(char **)EVar1);
        pCVar4 = CFastString::operator<<((CFastString *)pCVar4,pCVar8,pcVar9);
        pCVar4 = CFastString::operator<<((CFastString *)pCVar4,pCVar10,pcVar11);
        pCVar4 = CFastString::operator<<
                           ((CFastString *)pCVar4,(CPlugFileGpuBuilder *)ppCVar12,(char *)unaff_ESI)
        ;
        unaff_ESI = (IDirect3DSurface9 *)0x988988;
        pCVar4 = CFastString::operator<<((CFastString *)pCVar4,unaff_EBP,unaff_EBX);
        unaff_EBX = (char *)0x98898f;
        pCVar4 = CFastString::operator<<((CFastString *)pCVar4,unaff_retaddr,(char *)param_1);
        CFastString::operator<<
                  ((CFastString *)pCVar4,(CPlugFileGpuBuilder *)param_2,(char *)param_3);
        CClassicLog::AddLogStringInFile();
        param_3 = (GmNat2 *)0x0;
        param_2 = *(int *)EVar1 * *(int *)(EVar1 + 4) & 0x7fffffff;
        param_1 = (CVisionViewportDx9 *)0x9889af;
        iVar5 = TextureMemoryMipFree(this,(CVisionViewportDx9 *)param_2,0,(CPlugBitmap *)param_4);
        if (iVar5 == 0) goto LAB_009889d3;
      }
      if ((GmNat2 *)&DAT_00000005 <= param_3) {
        if (iVar7 == -0x7789fe84) {
LAB_009889d3:
          param_4 = 0x9889da;
          TriggerErrorOutOfMemory(this,(CVisionViewportDx9 *)param_5);
          return (IDirect3DSurface9 *)0x0;
        }
        break;
      }
      _Var6 = param_5;
    } while (iVar7 == -0x7789fe84);
    if (param_4 == 0) {
      return (IDirect3DSurface9 *)0x0;
    }
    SurfaceAdd(this,(CVisionViewportDx9 *)param_2,EVar1,pGVar2,param_5,param_4,unaff_ESI);
    pIVar3 = (IDirect3DSurface9 *)param_5;
  }
  return pIVar3;
}
}

// =================================================
// Function: CVisionViewportDx9::SyncGpuConstruct
// =================================================
void __thiscall
CVisionViewportDx9::SyncGpuConstruct(CVisionViewportDx9 *this,CVisionViewportDx9 *param_1)
{
{
  *(undefined4 *)(this + 0x93c) = 0;
  *(undefined4 *)(this + 0x940) = 0;
  *(undefined4 *)(this + 0x944) = 0;
  *(undefined4 *)(this + 0x948) = 10000;
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::TexRender_BlurHV
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CVisionViewportDx9::TexRender_BlurHV
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2,
          CPlugBitmap *param_3,ulong *param_4,float param_5,float param_6,ulong param_7)
{
{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  code *pcVar6;
  int iVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  SCasterCat *pSVar9;
  undefined3 extraout_var;
  CPlugBitmap *this_00;
  CPlugBitmap *extraout_EAX;
  SCasterCat *pSVar10;
  CPlugBitmapAddress *pCVar11;
  CMwNod *pCVar12;
  CVisionViewport *pCVar13;
  CVisionShaderKeeper *this_01;
  CPlugBitmap *unaff_EBX;
  CVisionViewportDx9 *pCVar14;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBP;
  TiXmlAttribute *unaff_ESI;
  CMwNod *pCVar15;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar16;
  CPlugBitmap *pCVar17;
  CFastBufferRef<class_CGameTournament> *this_02;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar18;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar19;
  float10 extraout_ST0;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000020;
  CPlugShader *pCStack00000024;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack00000028;
  int in_stack_0000002c;
  undefined4 in_stack_00000030;
  CMwNod *in_stack_00000034;
  ulong in_stack_00000038;
  SInputEvent *in_stack_ffffffa8;
  SInputEvent *pSVar20;
  ulong uVar21;
  CVisionViewport *pCVar22;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar23;
  CFastBuffer<class_CCrystalFace*> *pCVar24;
  ulong uVar25;
  CFastBufferRef<class_CGameTournament> *this_03;
  CVisionViewportDx9 *pCVar26;
  CPlugBitmapAddress *in_stack_ffffffd0;
  CVisionViewportDx9 *in_stack_ffffffd8;
  CVisionViewportDx9 *pCVar27;
  CVisionViewportDx9 *pCStack_1c;
  int iStack_18;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_14;
  CMwNod *pCStack_10;
  CPlugBitmap *local_c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_8;
  CVisionShaderKeeper *local_4;
  
  local_4 = (CVisionShaderKeeper *)0xffffffff;
  pCStack_8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&LAB_00aeb043;
  local_c = ExceptionList;
  pcVar6 = (code *)(DAT_00cca150 ^ (uint)&stack0xffffffb4);
  ExceptionList = &local_c;
  if ((DAT_00d77528 == 2) || (0x100 < DAT_00d775f4)) {
    if (1 < *(uint *)param_3) {
      *(uint *)param_3 = (*(uint *)param_3 + 1 & 0xfffffffe) - 1;
      if (*(int *)(param_1 + 0x14) == 0) {
        in_stack_ffffffa8 = (SInputEvent *)0x9932e9;
        iVar7 = (**(code **)(*(int *)this + 0xb0))(param_1);
        if (iVar7 == 0) {
          *(undefined4 *)param_3 = 0;
          goto LAB_00993a18;
        }
      }
      pCVar26 = *(CVisionViewportDx9 **)(param_1 + 0x14);
      this_03 = (CFastBufferRef<class_CGameTournament> *)0x0;
      local_4 = (CVisionShaderKeeper *)0x0;
      if (param_2 == (CPlugBitmap *)0x0) {
        pCVar14 = this + 0x1564;
        pSVar20 = (SInputEvent *)0x993320;
        pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount
                           (pCVar14,(CFastBuffer<class_CCrystalFace*> *)pcVar6);
        pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (pCVar8 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          do {
            pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (pCVar14,pCVar16,(ulong)in_stack_ffffffa8);
            param_2 = *(CPlugBitmap **)pSVar9;
            if (((*(int *)(param_2 + 0x14) != 0) && ((*(uint *)(param_2 + 0x4c) & 0x80000) == 0)) &&
               ((char)*(uint *)(param_2 + 0x4c) == '\x03')) {
              in_stack_ffffffa8 = (SInputEvent *)(this_03 + 0x24);
              bVar5 = SHmsPackLightMapCacheId::operator==
                                ((void *)(*(int *)(param_2 + 0x14) + 0x24),in_stack_ffffffa8,pSVar20
                                );
              if (CONCAT31(extraout_var,bVar5) != 0) goto LAB_009933cd;
            }
            pCVar16 = pCVar16 + 1;
          } while (pCVar16 < pCVar8);
        }
        pCVar17 = (CPlugBitmap *)(pCVar26 + 0x24);
        this_00 = operator_new(0x78);
        local_4._0_1_ = 1;
        if (this_00 == (CPlugBitmap *)0x0) {
          param_2 = (CPlugBitmap *)0x0;
        }
        else {
          CPlugBitmap::CPlugBitmap(this_00,(CPlugBitmap *)pcVar6);
          param_2 = extraout_EAX;
        }
        local_4 = (CVisionShaderKeeper *)((uint)local_4._1_3_ << 8);
        CPlugBitmap::GenerateRender
                  (param_2,pCVar17,(GmNat2 *)0x1,*(uint *)(param_1 + 0x4c) >> 0x1f,0,
                   (EPixelUpdate)pcVar6);
        pcVar6 = (code *)0x0;
        CPlugBitmap::SetMipLevelSkipCountMax(param_2,(CPlugBitmap *)0x0,(ulong)unaff_EDI);
        if (param_2 != (CPlugBitmap *)0x0) {
          unaff_EDI = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x9933c9;
          CMwNod::MwAddRef((CMwNod *)param_2,(CMwNod *)pcVar6);
        }
      }
LAB_009933cd:
      pCVar14 = this;
      if (((*(int *)(param_2 + 0x14) == 0) &&
          (iVar7 = (**(code **)(*(int *)this + 0xb0))(param_2), iVar7 == 0)) ||
         ((*(int *)(pCVar26 + 0x24) != *(int *)(*(int *)(param_2 + 0x14) + 0x24) ||
          (*(int *)(pCVar26 + 0x28) != *(int *)(*(int *)(param_2 + 0x14) + 0x28))))) {
        *(undefined4 *)param_3 = 0;
        local_4 = (CVisionShaderKeeper *)0xffffffff;
        if (this_03 != (CFastBufferRef<class_CGameTournament> *)0x0) {
          CMwNod::MwRelease((CMwNod *)this_03,(CMwNod *)pcVar6);
        }
        goto LAB_00993a18;
      }
      if (this_03 != (CFastBufferRef<class_CGameTournament> *)0x0) {
        CFastBufferRef<class_CPlugBitmap>::AddPtr(this + 0x1564,this_03,(CGameTournament *)pcVar6);
      }
      if ((_DAT_00d77b84 & 1) == 0) {
        _DAT_00d77b84 = _DAT_00d77b84 | 1;
        CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                  (&DAT_00d77b78,(CFastBuffer<class_CPlugFileSndGen*> *)pcVar6);
        pcVar6 = `protected:_int___thiscall_CVisionViewportDx9::
                 TexRender_BlurHV(class_CPlugBitmap*,class_CPlugBitmap*,unsigned_long&,float,float,unsigned_long)'
                 ::__l41::_dynamic_atexit_destructor_for__GaussValues__;
        _atexit(`protected:_int___thiscall_CVisionViewportDx9::
                TexRender_BlurHV(class_CPlugBitmap*,class_CPlugBitmap*,unsigned_long&,float,float,unsigned_long)'
                ::__l41::_dynamic_atexit_destructor_for__GaussValues__);
      }
      CFastBuffer<float>::AllocSetCount
                (&DAT_00d77b78,*(CFastBuffer<class_GxVertex2> **)param_3,(ulong)pcVar6);
      iVar2 = *(int *)param_3;
      iVar7 = iVar2 + -1;
      fVar1 = (float)iVar7;
      if (iVar7 < 0) {
        fVar1 = fVar1 + _DAT_00c418d0;
      }
      fVar3 = (float)_DAT_00b313b8;
      pCVar11 = (CPlugBitmapAddress *)(fVar1 * fVar3);
      if ((float)pCVar11 < fVar3 != ((float)pCVar11 == fVar3)) {
        pCVar11 = _DAT_00b31460;
      }
      __CIlog();
      pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (iVar2 == 0) {
        pCStack_1c = (CVisionViewportDx9 *)0xffffffff;
      }
      else {
        do {
          pCStack_1c = (CVisionViewportDx9 *)pCVar8;
          __CIexp();
          pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (&DAT_00d77b78,
                              (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCStack_1c,
                              (ulong)unaff_EDI);
          *(CVisionViewportDx9 **)pSVar9 = pCStack_1c;
          unaff_EDI = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCStack_1c;
          pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (&DAT_00d77b78,
                              (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCStack_1c,
                              (ulong)unaff_ESI);
          param_7 = (ulong)(*(float *)pSVar9 + (float)param_7);
          pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(pCStack_1c + 1);
        } while ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(pCStack_1c + 1) <
                 (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)*param_4);
      }
      pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (*param_4 != 0) {
        do {
          pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (&DAT_00d77b78,pCVar8,(ulong)unaff_EDI);
          pCVar8 = pCVar8 + 1;
          *(float *)pSVar9 = param_6 * *(float *)pSVar9;
        } while (pCVar8 < (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)*param_4);
      }
      if (1 < *param_4) {
        pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1;
        do {
          pCVar16 = pCVar8 + -1;
          pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (&DAT_00d77b78,pCVar16,(ulong)unaff_EDI);
          param_7 = *(ulong *)pSVar9;
          pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                              (&DAT_00d77b78,pCVar8,(ulong)unaff_ESI);
          fVar1 = *(float *)pSVar10;
          fVar3 = fVar1 + (float)in_stack_00000020;
          *(float *)pSVar9 = fVar3;
          fVar4 = (float)(int)pCVar16;
          if ((int)pCVar16 < 0) {
            fVar4 = fVar4 + _DAT_00c418d0;
          }
          param_7 = (ulong)(fVar1 / fVar3 +
                           (fVar4 - ((float)extraout_ST0 / (float)pCVar11) / (float)pCVar11));
          unaff_EDI = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x9935f6;
          pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (&DAT_00d77b78,pCVar8,(ulong)unaff_EBP);
          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar9 = in_stack_00000020;
          unaff_ESI = (TiXmlAttribute *)0x993607;
          unaff_EBP = pCVar8;
          pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (&DAT_00d77b78,pCVar8,(ulong)unaff_EBX);
          pCVar8 = pCVar8 + 2;
          *(float *)pSVar9 = *(float *)pSVar9 + (float)_DAT_00b313b8;
        } while (pCVar8 < (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)*param_4);
      }
      pCVar15 = (CMwNod *)(*param_4 + 1 >> 1);
      pCVar11 = (CPlugBitmapAddress *)((uint)(pCVar15 + 3) >> 2);
      if ((*(uint *)(in_stack_ffffffd0 + 0x24) < *(uint *)(in_stack_ffffffd8 + 0x24)) ||
         (param_5 = 0.0, *(uint *)(in_stack_ffffffd0 + 0x28) < *(uint *)(in_stack_ffffffd8 + 0x28)))
      {
        param_5 = 1.4013e-45;
      }
      this_02 = this_03 + 0x135c;
      param_7 = CFastBuffer<class_CCrystalFace*>::GetCount
                          (this_02,(CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
      pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (param_7 != 0) {
        do {
          pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_02,pCVar8,(ulong)unaff_ESI);
          pCVar13 = *(CVisionViewport **)pSVar9;
          unaff_ESI = (TiXmlAttribute *)0x993689;
          pCVar12 = (CMwNod *)(**(code **)(*(int *)pCVar13 + 0x7c))();
          if (pCVar12 == pCVar15) goto LAB_009936c2;
          pCVar8 = pCVar8 + 1;
        } while (pCVar8 < param_7);
      }
      pCVar13 = (CVisionViewport *)
                BlurHVCreateShader(pCVar26,(ulong)in_stack_ffffffd8,(ulong)pCVar15,
                                   *(CPlugBitmap **)(pCVar26 + 0x151c));
      param_7 = (ulong)pCVar13;
      CFastBuffer<class_CDx9TextureKeeper*>::Add(this_02,(TiXmlAttributeSet *)&param_7,unaff_ESI);
LAB_009936c2:
      pCStack_14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   (-(uint)(param_7 != 0) & (uint)&pCStack_10);
      pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (param_7 != 0) {
        pCStack_8 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(in_stack_ffffffd8 + 0x24);
        local_4 = *(CVisionShaderKeeper **)(in_stack_ffffffd8 + 0x28);
        local_c = (CPlugBitmap *)0x0;
        pCStack_10 = (CMwNod *)0x0;
      }
      this_01 = CVisionViewport::ShaderGetKeeper
                          ((CVisionViewport *)in_stack_ffffffd0,pCVar13,(CPlugShader *)unaff_EBP);
      uVar21 = 0x99370d;
      pCVar22 = pCVar13;
      CDx9ShaderKeeper::SetKeeperAllBitmapNoDirty
                ((CDx9ShaderKeeper *)this_01,(CDx9ShaderKeeper *)pCVar13,(CPlugShaderApply *)param_5
                 ,unaff_EBX);
      pCStack00000028 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      pCStack00000024 = (CPlugShader *)0x0;
      if (pCStack_1c != (CVisionViewportDx9 *)0x0) {
        do {
          pCVar23 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x99372d;
          pCVar24 = (CFastBuffer<class_CCrystalFace*> *)pCStack00000028;
          pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (pCVar13 + 0x2c,pCStack00000028,(ulong)pCVar14);
          pCStack_10 = *(CMwNod **)pSVar9;
          pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
          pCVar18 = pCStack00000028 + 1;
          do {
            if (pCStack_14 <= pCVar8) break;
            in_stack_ffffffd0 = _DAT_00b31460;
            if (pCVar18 < *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)param_7) {
              pCVar22 = (CVisionViewport *)0x99375d;
              pCVar23 = pCVar18;
              pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 (&DAT_00d77b78,pCVar18,(ulong)pCVar24);
              in_stack_ffffffd0 = *(CPlugBitmapAddress **)pSVar9;
            }
            if ((uint)param_5 < *param_4) {
              pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 (&DAT_00d77b78,
                                  (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_5,uVar21);
              in_stack_ffffffd8 = *(CVisionViewportDx9 **)pSVar9;
            }
            else {
              in_stack_ffffffd8 = (CVisionViewportDx9 *)0x0;
            }
            pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (pCVar13 + 0x94,pCVar8,uVar21);
            CPlugBitmapAddress::TexCoordTransfoBiasTexel
                      (*(CPlugBitmapAddress **)pSVar9,pCVar11,(float)_DAT_00b31460,(float)pCVar22);
            uVar21 = 0x9937c6;
            pCVar22 = (CVisionViewport *)pCVar16;
            pSVar9 = CFastBuffer<class_GxColor>::operator[]
                               (pCStack_1c + 0x2c,pCVar16,(ulong)pCVar23);
            in_stack_00000020 = in_stack_00000020 + 2;
            *(CVisionViewportDx9 **)(pSVar9 + 0xc) = pCStack_1c;
            pCVar16 = pCVar16 + 1;
            pCVar8 = pCVar8 + 1;
            pCVar18 = pCVar18 + 2;
          } while (pCVar16 < (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000004);
          pCStack_14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                       CFastBuffer<class_CCrystalFace*>::GetCount
                                 ((void *)(iStack_18 + 0x2c),pCVar24);
          for (; pCVar16 < pCStack_14; pCVar16 = pCVar16 + 1) {
            pCVar22 = (CVisionViewport *)0x993808;
            pSVar9 = CFastBuffer<class_GxColor>::operator[]
                               ((void *)(iStack_18 + 0x2c),pCVar16,(ulong)pCVar24);
            *(undefined4 *)(pSVar9 + 0xc) = 0;
          }
          pCStack00000028 = pCStack00000028 + 1;
        } while (pCStack00000028 < pCStack_1c);
      }
      uVar21 = param_7;
      pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      pCVar27 = in_stack_ffffffd8;
      RenderShaderOnFullQuad
                (in_stack_ffffffd8,(CVisionViewportDx9 *)pCVar13,(CPlugShader *)param_7,local_c,
                 (SGxPixRect *)0x0,(CPlugVisual *)0x0,(SRenderShaderParam *)pCVar14);
      if (DAT_00d77b74 == 0) {
        local_4 = CVisionViewport::ShaderGetKeeper
                            ((CVisionViewport *)in_stack_ffffffd8,pCVar13,(CPlugShader *)this_03);
        uVar25 = 0x993881;
        pCVar22 = pCVar13;
        CDx9ShaderKeeper::SetKeeperAllBitmapNoDirty
                  ((CDx9ShaderKeeper *)local_4,(CDx9ShaderKeeper *)pCVar13,
                   (CPlugShaderApply *)uVar21,(CPlugBitmap *)pCVar26);
        in_stack_00000034 = (CMwNod *)0x0;
        in_stack_00000030 = 0;
        if (pCStack_10 != (CMwNod *)0x0) {
          do {
            pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x9938a0;
            pCVar23 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)in_stack_00000034;
            pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (pCVar13 + 0x2c,
                                (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)in_stack_00000034,
                                (ulong)in_stack_ffffffd0);
            pCStack_8 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar9;
            pCVar18 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
            pCVar19 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(in_stack_00000034 + 1);
            do {
              if (pCStack_8 <= pCVar8) break;
              if (pCVar19 < *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pCStack00000028) {
                pCVar22 = (CVisionViewport *)0x9938cd;
                pCVar16 = pCVar19;
                CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                          (&DAT_00d77b78,pCVar19,(ulong)pCVar23);
              }
              if (in_stack_00000020 < *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)param_7) {
                CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                          (&DAT_00d77b78,in_stack_00000020,uVar25);
              }
              pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 (pCVar13 + 0x94,pCVar8,uVar25);
              CPlugBitmapAddress::TexCoordTransfoBiasTexel
                        (*(CPlugBitmapAddress **)pSVar9,_DAT_00b31460,(float)param_7,(float)pCVar22)
              ;
              uVar25 = 0x993936;
              pCVar22 = (CVisionViewport *)pCVar18;
              pSVar9 = CFastBuffer<class_GxColor>::operator[]
                                 (pCStack_14 + 0x2c,pCVar18,(ulong)pCVar16);
              in_stack_0000002c = in_stack_0000002c + 2;
              *(CPlugBitmap **)(pSVar9 + 0xc) = local_c;
              pCVar18 = pCVar18 + 1;
              pCVar8 = pCVar8 + 1;
              pCVar19 = pCVar19 + 2;
            } while (pCVar18 < (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000004);
            pCVar15 = pCStack_10 + 0x2c;
            pCStack00000028 =
                 (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount
                           (pCVar15,(CFastBuffer<class_CCrystalFace*> *)pCVar23);
            if (pCVar18 < pCStack00000028) {
              do {
                pCVar22 = (CVisionViewport *)0x993978;
                pSVar9 = CFastBuffer<class_GxColor>::operator[](pCVar15,pCVar18,(ulong)pCVar23);
                pCVar18 = pCVar18 + 1;
                *(undefined4 *)(pSVar9 + 0xc) = 0;
              } while (pCVar18 < pCStack00000028);
            }
            in_stack_00000034 = in_stack_00000034 + 1;
          } while (in_stack_00000034 < pCStack_10);
        }
        if (((byte)in_stack_00000038 & 0xf) != 0xf) {
          CDx9StateBlock::FilterRenderState(0xa8,in_stack_00000038);
        }
        RenderShaderOnFullQuad
                  (pCStack_1c,(CVisionViewportDx9 *)pCVar13,pCStack00000024,(CPlugBitmap *)0x0,
                   (SGxPixRect *)0x0,(CPlugVisual *)0x0,(SRenderShaderParam *)in_stack_ffffffd0);
        CDx9StateBlock::FilterRenderState(0xa8,0xf);
        CDx9ShaderKeeper::SetKeeperAllBitmapNoDirty
                  ((CDx9ShaderKeeper *)param_1,(CDx9ShaderKeeper *)pCVar13,
                   *(CPlugShaderApply **)(pCStack_1c + 0x151c),(CPlugBitmap *)pCVar11);
        pCVar15 = pCStack_10;
      }
      pCStack00000024 = (CPlugShader *)0xffffffff;
      if (pCVar15 != (CMwNod *)0x0) {
        CMwNod::MwRelease(pCVar15,(CMwNod *)pCVar27);
      }
    }
    iVar7 = 1;
  }
  else {
LAB_00993a18:
    iVar7 = 0;
  }
  ExceptionList = local_c;
  return iVar7;
}
}

// =================================================
// Function: CVisionViewportDx9::TexRender_CubeBlur
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CVisionViewportDx9::TexRender_CubeBlur
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2,
          CPlugBitmap *param_3,ulong *param_4)
{
{
  undefined4 *puVar1;
  bool bVar2;
  bool bVar3;
  uint *puVar4;
  CMwId CVar5;
  CFastBuffer<class_CCrystalFace*> *pCVar6;
  int iVar7;
  EGxTexFilter *pEVar8;
  SCasterCat *pSVar9;
  CPlugBitmap *extraout_EAX;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined *this_00;
  int iVar10;
  CGameTournament *unaff_EBX;
  CFastBuffer<class_GxVertex2> *pCVar11;
  CPlugShader *pCVar12;
  ulong unaff_EBP;
  CPlugBitmapRender *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar13;
  CPlugBitmap *this_01;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar14;
  CPlugBitmap *unaff_EDI;
  CVisionViewportDx9 *pCVar15;
  CPlugBitmap **ppCVar16;
  float10 extraout_ST0;
  ulong unaff_retaddr;
  undefined4 in_stack_00000014;
  undefined4 uStack00000018;
  undefined4 in_stack_0000001c;
  undefined4 *in_stack_00000020;
  undefined4 in_stack_00000024;
  undefined4 uStack00000028;
  undefined4 in_stack_0000002c;
  undefined4 in_stack_00000030;
  undefined4 in_stack_00000034;
  uint *in_stack_00000038;
  undefined4 in_stack_0000003c;
  undefined4 in_stack_00000040;
  undefined4 in_stack_00000044;
  undefined4 uStack00000048;
  undefined4 in_stack_0000004c;
  void *in_stack_00000054;
  CPlugShader *in_stack_ffffff50;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff58;
  CPlugShaderPass **in_stack_ffffff5c;
  EPlugGpuPipeline *in_stack_ffffff60;
  CPlugBitmap *in_stack_ffffff64;
  CPlugBitmap *in_stack_ffffff68;
  CPlugBitmap *pCVar17;
  ulong in_stack_ffffff6c;
  CPlugShader *in_stack_ffffff70;
  EGxTexFilter *in_stack_ffffff74;
  SPlugGpuLoadFx **in_stack_ffffff78;
  CPlugShaderPass **in_stack_ffffff7c;
  EPlugGpuPipeline *in_stack_ffffff80;
  ulong *in_stack_ffffff84;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_ffffff88;
  code *in_stack_ffffff8c;
  CPlugBitmap *in_stack_ffffff90;
  CPlugVisual *in_stack_ffffff94;
  GmIso3 *in_stack_ffffff98;
  CFastBuffer<class_GxVertex2> *pCVar18;
  float in_stack_ffffffa0;
  CVisionViewportDx9 *pCVar19;
  GmIso4 *pGVar20;
  uint uVar21;
  uint uVar22;
  float fVar23;
  CPlugShader *pCStack_4c;
  uint uStack_48;
  CPlugShader *pCStack_44;
  CPlugShader *pCStack_40;
  CPlugShader *pCStack_3c;
  undefined4 uStack_38;
  float fStack_34;
  CPlugShader *pCStack_30;
  int iStack_2c;
  CVisionShaderKeeper *pCStack_24;
  int aiStack_20 [2];
  CDx9ShaderKeeper *pCStack_18;
  undefined4 *puStack_10;
  void *local_c;
  CVisionViewportDx9 *pCStack_8;
  CVisionViewportDx9 *pCStack_4;
  
  pCStack_4 = (CVisionViewportDx9 *)0xffffffff;
  pCStack_8 = (CVisionViewportDx9 *)&LAB_00aeb0d1;
  local_c = ExceptionList;
  pCVar6 = (CFastBuffer<class_CCrystalFace*> *)(DAT_00cca150 ^ (uint)&stack0xffffff40);
  ExceptionList = &local_c;
  pCVar19 = this;
  if (param_1[0x4d] == (CVisionViewportDx9)0x4) {
    (**(code **)(**(int **)(param_1 + 0x74) + 0x78))();
  }
  if ((DAT_00d77528 == 2) || (0x2ff < DAT_00d775f4)) {
    if ((*(int *)(param_1 + 0x14) != 0) ||
       (iVar7 = (**(code **)(*(int *)this + 0xb0))(param_1), iVar7 != 0)) {
      pCVar15 = this + 0x1564;
      pEVar8 = (EGxTexFilter *)CFastBuffer<class_CCrystalFace*>::GetCount(pCVar15,pCVar6);
      pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pEVar8 != (EGxTexFilter *)0x0) {
        do {
          pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (pCVar15,pCVar13,(ulong)unaff_EDI);
          this_01 = *(CPlugBitmap **)pSVar9;
          if ((((*(uint *)(this_01 + 0x4c) & 0x80000) != 0) &&
              ((char)*(undefined4 *)(param_1 + 0x4c) == (char)*(uint *)(this_01 + 0x4c))) &&
             (pCVar17 = this_01,
             ((*(uint *)(*(int *)(param_1 + 0x48) + 0x24) ^
              *(uint *)(*(int *)(this_01 + 0x48) + 0x24)) & 0x1c) == 0)) goto LAB_009946bc;
          pCVar13 = pCVar13 + 1;
        } while (pCVar13 < in_stack_ffffff58);
      }
      in_stack_ffffff90 = operator_new(0x78);
      this_01 = (CPlugBitmap *)0x0;
      if (in_stack_ffffff90 != (CPlugBitmap *)0x0) {
        CPlugBitmap::CPlugBitmap(in_stack_ffffff90,unaff_EDI);
        this_01 = extraout_EAX;
      }
      unaff_retaddr = 0xffffffff;
      in_stack_ffffff64 = this_01;
      CPlugBitmap::GenerateRenderCube
                (this_01,*(CPlugBitmap **)(in_stack_ffffff58 + 0x24),
                 (uint)(0xf < ((byte)*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x24) & 0x1c)),
                 (int)unaff_EDI);
      CPlugBitmap::SetPixelUpdate(this_01,(CPlugBitmap *)0x0,0,unaff_ESI);
      CPlugBitmap::SetMipLevelSkipCountMax(this_01,(CPlugBitmap *)0x0,unaff_EBP);
      CFastBufferRef<class_CPlugBitmap>::AddPtr
                (pCVar15,(CFastBufferRef<class_CGameTournament> *)this_01,unaff_EBX);
      pCVar17 = in_stack_ffffff68;
LAB_009946bc:
      if ((*(int *)(this_01 + 0x14) == 0) &&
         (iVar7 = (**(code **)(*(int *)this + 0xb0))(), iVar7 == 0)) {
        *in_stack_00000020 = 0;
        ExceptionList = in_stack_00000054;
        return 0;
      }
      if (*(int *)(this + 0x132c) == 0) {
        StdShaderLoad(this,(CVisionViewportDx9 *)&DAT_00000026,(EStdShader2)in_stack_ffffff50,
                      (ulong)pEVar8);
      }
      pCVar12 = *(CPlugShader **)(this + 0x132c);
      pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                CVisionViewport::ShaderGetKeeper
                          ((CVisionViewport *)this,(CVisionViewport *)pCVar12,in_stack_ffffff50);
      CDx9ShaderKeeper::SetShaderBitmapNoDirty
                ((CDx9ShaderKeeper *)pCVar13,(CDx9ShaderKeeper *)0x0,(ulong)param_1,
                 (CPlugBitmap *)0x0,(CPlugBitmapSampler *)0x0,pEVar8);
      CVar5 = CMwId::CreateFromLocalName(&stack0xffffff6c);
      uStack00000018 = 1;
      CPlugShader::GetLoadFxValue
                (pCVar12,(CPlugShader *)&stack0xffffffb0,(CMwId *)CONCAT31(extraout_var,CVar5),
                 (SPlugGpuLoadFx **)in_stack_ffffff58,in_stack_ffffff5c,in_stack_ffffff60,
                 (ulong *)in_stack_ffffff64);
      uStack00000028 = 0xffffffff;
      OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pCVar17);
      puVar4 = in_stack_00000038;
      if (*in_stack_00000038 < 0x10) {
        pCVar15 = (CVisionViewportDx9 *)0x27;
        *in_stack_00000038 = 0xf;
      }
      else if (*in_stack_00000038 < 0x20) {
        pCVar15 = (CVisionViewportDx9 *)&DAT_00000028;
        *in_stack_00000038 = 0x1f;
      }
      else {
        pCVar15 = (CVisionViewportDx9 *)&DAT_00000029;
        *in_stack_00000038 = 0x3f;
      }
      if (*(int *)(this + (int)pCVar15 * 4 + 0x1294) == 0) {
        StdShaderLoad(this,pCVar15,(EStdShader2)pCVar17,in_stack_ffffff6c);
      }
      pCVar12 = *(CPlugShader **)(this + (int)pCVar15 * 4 + 0x1294);
      pCStack_30 = pCVar12;
      pCStack_24 = CVisionViewport::ShaderGetKeeper
                             ((CVisionViewport *)this,(CVisionViewport *)pCVar12,in_stack_ffffff70);
      CDx9ShaderKeeper::SetShaderBitmapNoDirty
                ((CDx9ShaderKeeper *)pCStack_24,(CDx9ShaderKeeper *)0x0,(ulong)param_1,
                 (CPlugBitmap *)0x0,(CPlugBitmapSampler *)0x0,in_stack_ffffff74);
      uStack_48 = 0;
      pCStack_44 = (CPlugShader *)0x0;
      CVar5 = CMwId::CreateFromLocalName(&stack0xffffff8c);
      in_stack_00000038 = (uint *)0x2;
      CPlugShader::GetLoadFxValue
                (pCVar12,(CPlugShader *)&uStack_48,(CMwId *)CONCAT31(extraout_var_00,CVar5),
                 in_stack_ffffff78,in_stack_ffffff7c,in_stack_ffffff80,in_stack_ffffff84);
      uStack00000048 = 0xffffffff;
      OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)in_stack_ffffff88);
      pCVar11 = (CFastBuffer<class_GxVertex2> *)*puVar4;
      pCVar18 = pCVar11;
      if ((_DAT_00d77bb4 & 1) == 0) {
        _DAT_00d77bb4 = _DAT_00d77bb4 | 1;
        CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                  (&DAT_00d77ba8,in_stack_ffffff88);
        _atexit(`protected:_int___thiscall_CVisionViewportDx9::
                TexRender_CubeBlur(class_CPlugBitmap*,class_CPlugBitmap*,unsigned_long&)'::__l41::
                _dynamic_atexit_destructor_for__FaceZRotXs__);
      }
      if ((_DAT_00d77bb4 & 2) == 0) {
        _DAT_00d77bb4 = _DAT_00d77bb4 | 2;
        CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                  (&DAT_00d77b9c,(CFastBuffer<class_CPlugFileSndGen*> *)in_stack_ffffff8c);
        in_stack_ffffff8c =
             `protected:_int___thiscall_CVisionViewportDx9::
             TexRender_CubeBlur(class_CPlugBitmap*,class_CPlugBitmap*,unsigned_long&)'::__l41::
             _dynamic_atexit_destructor_for__FaceZRotYs__;
        _atexit(`protected:_int___thiscall_CVisionViewportDx9::
                TexRender_CubeBlur(class_CPlugBitmap*,class_CPlugBitmap*,unsigned_long&)'::__l41::
                _dynamic_atexit_destructor_for__FaceZRotYs__);
      }
      CFastBuffer<class_GmMat3>::AllocSetCount(&DAT_00d77ba8,pCVar11,(ulong)in_stack_ffffff8c);
      CFastBuffer<class_GmMat3>::AllocSetCount(&DAT_00d77b9c,pCVar11,(ulong)in_stack_ffffff90);
      pGVar20 = (GmIso4 *)0x0;
      pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar11 != (CFastBuffer<class_GxVertex2> *)0x0) {
        pCStack_24 = (CVisionShaderKeeper *)(float)(int)(pCVar11 + 1);
        if ((int)(pCVar11 + 1) < 0) {
          pCStack_24 = (CVisionShaderKeeper *)((float)pCStack_24 + _DAT_00c418d0);
        }
        iVar7 = 0;
        do {
          pCStack_18 = (CDx9ShaderKeeper *)
                       (((float)(int)-((uint)(pCVar11 + -1) >> 1) * (float)_DAT_00b36110) /
                       (float)pCStack_24);
          __CIcos();
          fVar23 = (float)extraout_ST0;
          pSVar9 = CFastArray<class_CCrystalTexCoord>::operator[]
                             (&DAT_00d77ba8,pCVar14,(ulong)in_stack_ffffff94);
          GmMat3::SetIdentity(pSVar9,(GmMat43 *)in_stack_ffffff98);
          in_stack_ffffff94 = (CPlugVisual *)pCVar14;
          pSVar9 = CFastArray<class_CCrystalTexCoord>::operator[]
                             (&DAT_00d77ba8,pCVar14,(ulong)puStack_10);
          in_stack_ffffff98 = (GmIso3 *)0x994915;
          GmMat3::RotateX(pSVar9,(GmIso4 *)pCVar18,in_stack_ffffffa0);
          pCVar18 = (CFastBuffer<class_GxVertex2> *)0x994920;
          pSVar9 = CFastArray<class_CCrystalTexCoord>::operator[]
                             (&DAT_00d77b9c,pCVar14,(ulong)pCVar13);
          GmMat3::SetIdentity(pSVar9,(GmMat43 *)pCVar19);
          in_stack_ffffffa0 = 1.40771e-38;
          pCVar13 = pCVar14;
          pSVar9 = CFastArray<class_CCrystalTexCoord>::operator[]
                             (&DAT_00d77b9c,pCVar14,unaff_retaddr);
          pCVar19 = (CVisionViewportDx9 *)0x994941;
          GmMat3::RotateY(pSVar9,pGVar20,fVar23);
          iStack_2c = iStack_2c + 1;
          *(CPlugShader **)(iVar7 + 0xc + (int)local_c) = pCStack_30;
          *(undefined4 *)(iVar7 + 0x1c + (int)local_c) = 0;
          pCVar14 = pCVar14 + 1;
          *(undefined4 *)(iVar7 + 0x2c + (int)local_c) = 0;
          iVar7 = iVar7 + 0x30;
          fStack_34 = fStack_34 + (float)pCStack_30;
        } while (pCVar14 < pCVar11);
      }
      if (pCVar11 != (CFastBuffer<class_GxVertex2> *)0x0) {
        iVar7 = 0;
        do {
          pCVar11 = pCVar11 + -1;
          *(float *)(iVar7 + 0xc + iStack_2c) =
               *(float *)(iVar7 + 0xc + iStack_2c) * (1.0 / (float)pGVar20);
          iVar7 = iVar7 + 0x30;
        } while (pCVar11 != (CFastBuffer<class_GxVertex2> *)0x0);
      }
      pCVar12 = (CPlugShader *)0x0;
      aiStack_20[0] = 0;
      pCStack_24 = (CVisionShaderKeeper *)0x3;
      pCStack_4c = (CPlugShader *)0x0;
      uVar21 = 0;
      while( true ) {
        do {
          if ((uVar21 == 2) || (uVar21 == 3)) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
          bVar3 = true;
          if ((pCVar12 != (CPlugShader *)0x0) && (bVar3 = bVar2, pCVar12 == (CPlugShader *)0x1)) {
            bVar3 = !bVar2;
          }
          pCStack_24 = (CVisionShaderKeeper *)
                       ((uint)pCStack_24 ^ (uVar21 * 8 ^ (uint)pCStack_24) & 0x38);
          switch((uint)pCStack_24 >> 3 & 7) {
          case 0:
            pCStack_44 = (CPlugShader *)0x3f800000;
            fStack_34 = 1.0;
            pCStack_40 = (CPlugShader *)0x0;
            pCStack_3c = (CPlugShader *)0x0;
            uStack_38 = 0;
            pCStack_30 = (CPlugShader *)0x0;
            break;
          case 1:
            pCStack_40 = (CPlugShader *)0x0;
            pCStack_3c = (CPlugShader *)0x0;
            uStack_38 = 0;
            pCStack_30 = (CPlugShader *)0x0;
            fStack_34 = 1.0;
            pCStack_44 = _DAT_00b2c060;
            break;
          case 2:
            pCStack_44 = (CPlugShader *)0x0;
            pCStack_3c = (CPlugShader *)0x0;
            uStack_38 = 0;
            fStack_34 = 0.0;
            pCStack_40 = (CPlugShader *)0x3f800000;
            pCStack_30 = _DAT_00b2c060;
            break;
          case 3:
            pCStack_44 = (CPlugShader *)0x0;
            pCStack_3c = (CPlugShader *)0x0;
            uStack_38 = 0;
            fStack_34 = 0.0;
            pCStack_30 = (CPlugShader *)0x3f800000;
            pCStack_40 = _DAT_00b2c060;
            break;
          case 4:
            pCStack_44 = (CPlugShader *)0x0;
            pCStack_40 = (CPlugShader *)0x0;
            uStack_38 = 0;
            pCStack_30 = (CPlugShader *)0x0;
            pCStack_3c = (CPlugShader *)0x3f800000;
            fStack_34 = 1.0;
            break;
          case 5:
            pCStack_44 = (CPlugShader *)0x0;
            pCStack_40 = (CPlugShader *)0x0;
            uStack_38 = 0;
            pCStack_30 = (CPlugShader *)0x0;
            fStack_34 = 1.0;
            pCStack_3c = _DAT_00b2c060;
          }
          uVar22 = uVar21;
          GmMat3::SetDOVandUpV
                    (&stack0x00000028,(GmMat3 *)&pCStack_44,(GmVec3 *)&uStack_38,
                     (GmVec3 *)in_stack_ffffff94);
          if (bVar3) {
            pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
            if (uVar22 != 0) {
              iVar7 = 0;
              do {
                this_00 = &DAT_00d77ba8;
                if (pCStack_4c == (CPlugShader *)0x0) {
                  this_00 = &DAT_00d77b9c;
                }
                pSVar9 = CFastArray<class_CCrystalTexCoord>::operator[]
                                   (this_00,pCVar13,(ulong)in_stack_ffffff98);
                in_stack_ffffff98 = (GmIso3 *)&stack0x00000030;
                ppCVar16 = &param_3;
                for (iVar10 = 9; iVar10 != 0; iVar10 = iVar10 + -1) {
                  *ppCVar16 = *(CPlugBitmap **)pSVar9;
                  pSVar9 = pSVar9 + 4;
                  ppCVar16 = ppCVar16 + 1;
                }
                GmMat3::Mult(&param_3,in_stack_ffffff98,(GmIso3 *)pCVar18);
                puVar1 = (undefined4 *)(aiStack_20[0] + iVar7);
                pCVar13 = pCVar13 + 1;
                *puVar1 = param_4;
                puVar1[1] = in_stack_00000014;
                puVar1[2] = uStack00000018;
                puVar1 = (undefined4 *)(aiStack_20[0] + 0x10 + iVar7);
                *puVar1 = in_stack_0000001c;
                puVar1[1] = in_stack_00000020;
                puVar1[2] = in_stack_00000024;
                puVar1 = (undefined4 *)(aiStack_20[0] + 0x20 + iVar7);
                *puVar1 = uStack00000028;
                iVar7 = iVar7 + 0x30;
                puVar1[1] = in_stack_0000002c;
                puVar1[2] = in_stack_00000030;
                this = (CVisionViewportDx9 *)param_3;
                uVar21 = uStack_48;
              } while (pCVar13 < pCStack_4c);
            }
            in_stack_ffffff94 = (CPlugVisual *)aiStack_20;
            RenderShaderOnFullQuad
                      (this,pCStack_8,pCStack_44,(CPlugBitmap *)0x0,(SGxPixRect *)0x0,
                       in_stack_ffffff94,(SRenderShaderParam *)in_stack_ffffff98);
            pCVar12 = pCStack_44;
          }
          else {
            *puStack_10 = in_stack_0000002c;
            in_stack_ffffff94 = (CPlugVisual *)aiStack_20;
            puStack_10[1] = in_stack_00000030;
            puStack_10[2] = in_stack_00000034;
            puStack_10[3] = 0;
            puStack_10[4] = in_stack_00000038;
            puStack_10[5] = in_stack_0000003c;
            puStack_10[6] = in_stack_00000040;
            puStack_10[7] = 0;
            puStack_10[8] = in_stack_00000044;
            puStack_10[9] = uStack00000048;
            puStack_10[10] = in_stack_0000004c;
            puStack_10[0xb] = 0;
            RenderShaderOnFullQuad
                      (this,pCStack_4,pCStack_44,(CPlugBitmap *)0x0,(SGxPixRect *)0x0,
                       in_stack_ffffff94,(SRenderShaderParam *)in_stack_ffffff98);
          }
          uVar21 = uVar21 + 1;
        } while (uVar21 < 6);
        (**(code **)(*(int *)this + 0xe0))();
        uVar21 = uStack_48;
        pCVar12 = pCVar12 + 1;
        if ((CPlugShader *)0x2 < pCVar12) break;
        uVar21 = 0;
        pCStack_4c = pCVar12;
      }
      CDx9ShaderKeeper::SetShaderBitmapNoDirty
                ((CDx9ShaderKeeper *)pCStack_4,(CDx9ShaderKeeper *)0x0,uStack_48,(CPlugBitmap *)0x0,
                 (CPlugBitmapSampler *)0x0,(EGxTexFilter *)in_stack_ffffff94);
      CDx9ShaderKeeper::SetShaderBitmapNoDirty
                (pCStack_18,(CDx9ShaderKeeper *)0x0,uVar21,(CPlugBitmap *)0x0,
                 (CPlugBitmapSampler *)0x0,(EGxTexFilter *)in_stack_ffffff98);
      ExceptionList = in_stack_00000054;
      return 1;
    }
    *(undefined4 *)param_3 = 0;
  }
  ExceptionList = in_stack_00000054;
  return 0;
}
}

// =================================================
// Function: CVisionViewportDx9::TexRender_Gutter
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CVisionViewportDx9::TexRender_Gutter
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2,
          CPlugBitmap *param_3,ulong *param_4)
{
{
  CVisionViewport *pCVar1;
  CPlugBitmap *pCVar2;
  int iVar3;
  SRenderShaderParam *pSVar4;
  SCasterCat *pSVar5;
  CPlugBitmap *pCVar6;
  CDx9ShaderKeeper *this_00;
  CSystemArchiveNod *extraout_ECX;
  CSystemArchiveNod *this_01;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CGameTournament *unaff_ESI;
  CPlugBitmapRender *unaff_EDI;
  CPlugBitmap *in_stack_00000014;
  CPlugShader *in_stack_0000001c;
  SRenderShaderParam *in_stack_00000020;
  int *in_stack_00000024;
  CPlugShader *in_stack_fffffff4;
  SRenderShaderParam *pSVar8;
  SRenderShaderParam *in_stack_fffffffc;
  
  pCVar6 = param_3;
  if (((DAT_00d77528 != 2) && ((_DAT_00d775f4 & 0xff00) != 0x200)) &&
     ((_DAT_00d775f4 & 0xffff) < 0x200)) {
    return 0;
  }
  if (DAT_00d135c0 < *(uint *)param_3) {
    *(uint *)param_3 = DAT_00d135c0;
  }
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if ((*(int *)(param_1 + 0x14) == 0) &&
     (iVar3 = (**(code **)(*(int *)this + 0xb0))(param_1), iVar3 == 0)) {
    *(undefined4 *)pCVar6 = 0;
    return 0;
  }
  pSVar4 = (SRenderShaderParam *)CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x1564,unaff_EBP)
  ;
  this_01 = extraout_ECX;
  pSVar8 = pSVar4;
  if (pSVar4 != (SRenderShaderParam *)0x0) {
    do {
      pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x1564,pCVar7,unaff_EBX);
      pCVar6 = *(CPlugBitmap **)pSVar5;
      this_01 = *(CSystemArchiveNod **)(pCVar6 + 0x4c);
      if ((((uint)this_01 & 0x80000) == 0) &&
         (pSVar4 = in_stack_fffffffc, (char)*(undefined4 *)(param_1 + 0x4c) == (char)this_01)) {
        iVar3 = *(int *)(param_1 + 0x48);
        this_01 = *(CSystemArchiveNod **)(pCVar6 + 0x48);
        if ((((*(uint *)(iVar3 + 0x24) ^ *(uint *)(this_01 + 0x24)) & 0x1c) == 0) &&
           ((*(int *)(this_01 + 0x18) == *(int *)(iVar3 + 0x18) &&
            (this_01 = *(CSystemArchiveNod **)(this_01 + 0x1c), pCVar2 = pCVar6,
            this_01 == *(CSystemArchiveNod **)(iVar3 + 0x1c))))) goto LAB_00994482;
      }
      pCVar7 = pCVar7 + 1;
    } while (pCVar7 < pSVar4);
  }
  param_2 = (CPlugBitmap *)param_1;
  CSystemArchiveNod::Duplicate(this_01,(CPlugVisualVertexs *)&param_2);
  CPlugBitmap::SetPixelUpdate(param_3,(CPlugBitmap *)0x0,0,unaff_EDI);
  CFastBufferRef<class_CPlugBitmap>::AddPtr
            (this + 0x1564,(CFastBufferRef<class_CGameTournament> *)param_4,unaff_ESI);
  pCVar6 = in_stack_00000014;
  pCVar2 = param_3;
LAB_00994482:
  param_3 = pCVar2;
  if ((*(int *)(pCVar6 + 0x14) == 0) &&
     (iVar3 = (**(code **)(*(int *)this + 0xb0))(pCVar6), iVar3 == 0)) {
    *(undefined4 *)in_stack_0000001c = 0;
    return 0;
  }
  if (*(int *)(this + 0x1324) == 0) {
    StdShaderLoad(this,(CVisionViewportDx9 *)0x24,(EStdShader2)in_stack_fffffff4,(ulong)pSVar8);
  }
  pCVar1 = *(CVisionViewport **)(this + 0x1324);
  this_00 = (CDx9ShaderKeeper *)
            CVisionViewport::ShaderGetKeeper((CVisionViewport *)this,pCVar1,in_stack_fffffff4);
  param_2 = (CPlugBitmap *)this_00;
  CDx9ShaderKeeper::SetShaderBitmapNoDirty
            (this_00,(CDx9ShaderKeeper *)0x0,(ulong)param_1,(CPlugBitmap *)0x0,
             (CPlugBitmapSampler *)0x0,(EGxTexFilter *)pSVar8);
  iVar3 = *in_stack_00000024;
  in_stack_00000014 = (CPlugBitmap *)0x0;
  param_4 = (ulong *)0x3;
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    RenderShaderOnFullQuad
              (this,(CVisionViewportDx9 *)pCVar1,in_stack_0000001c,(CPlugBitmap *)0x0,
               (SGxPixRect *)0x0,(CPlugVisual *)&param_4,in_stack_fffffffc);
    in_stack_fffffffc = in_stack_00000020;
    (**(code **)(*(int *)this + 0xe0))(param_1);
    this_00 = (CDx9ShaderKeeper *)param_3;
  }
  CDx9ShaderKeeper::SetShaderBitmapNoDirty
            (this_00,(CDx9ShaderKeeper *)0x0,(ulong)in_stack_0000001c,(CPlugBitmap *)0x0,
             (CPlugBitmapSampler *)0x0,(EGxTexFilter *)in_stack_fffffffc);
  return 1;
}
}

// =================================================
// Function: CVisionViewportDx9::TexRender_HemiAddQuad
// =================================================
void __thiscall
CVisionViewportDx9::TexRender_HemiAddQuad
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,SHemiInfo *param_2,
          GxLightNotAmbient *param_3,float param_4,GmVec3 *param_5)
{
{
  CPlugVisual *this_00;
  int iVar1;
  ulong uVar2;
  CPlugVisual *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  float fVar3;
  float local_c;
  float local_8;
  GxLightNotAmbient *local_4;
  
  local_c = *(float *)(param_2 + 0x1c) * *(float *)(param_2 + 0x58) * *(float *)(param_2 + 0x24) *
            (float)param_3;
  local_8 = *(float *)(param_2 + 0x58) * *(float *)(param_2 + 0x24) * *(float *)(param_2 + 0x20) *
            (float)param_3;
  if (0.0 <= local_c) {
    if (1.0 < local_c) {
      local_c = 1.0;
    }
  }
  else {
    local_c = 0.0;
  }
  if (0.0 <= local_8) {
    if (1.0 < local_8) {
      local_8 = 1.0;
    }
  }
  else {
    local_8 = 0.0;
  }
  local_4 = param_3;
  this_00 = *(CPlugVisual **)(*(int *)(this + 0x868) + 0x90);
  iVar1 = *(int *)param_1;
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00 + 0x78,unaff_EDI);
  if (uVar2 < iVar1 + 4U) {
    CPlugVisual::RemoveTexCoordSetAll(this_00,unaff_ESI);
    fVar3 = 1.4042406e-38;
    (**(code **)(*(int *)this_00 + 0x114))(iVar1 + 4U);
    CPlugVisual::AddTexCoordSet(this_00,(CPlugVisualSprite *)0x3f800000,1.0,0.0,0,0.0,fVar3);
  }
  CPlugVisualQuads::CreateQuadZ
            ((CPlugVisualQuads *)this_00,*(CPlugVisualQuads **)(param_1 + 4),
             SUB41(*(undefined4 *)(param_1 + 8),0),*(float *)(param_1 + 0xc),
             *(float *)(param_1 + 0x10),*(GxColor **)(param_1 + 0x14),(ulong)&local_c,
             *(GmVec3 **)param_1);
  *(int *)param_1 = *(int *)param_1 + 4;
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::TexRender_Hemisphere
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CVisionViewportDx9::TexRender_Hemisphere
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2,
          CPlugBitmapRenderHemisphere *param_3)
{
{
  SPlugFaceCull *this_00;
  uint *puVar1;
  int iVar2;
  float fVar3;
  uint uVar4;
  CHmsViewport *pCVar5;
  float fVar6;
  CFastBuffer<class_GxVertex2> *pCVar7;
  CPlugShader *this_01;
  CPlugVisualQuads *pCVar8;
  GmIso4 *pGVar9;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  SCasterCat *pSVar11;
  SCasterCat *pSVar12;
  CVisionViewportDx9 *pCVar13;
  CVisionVisualKeeper *extraout_EAX;
  CMwNod *extraout_EAX_00;
  CHmsZoneVPacker *pCVar14;
  void *pvVar15;
  SNewTriangleVert *pSVar16;
  SCasterCat *pSVar17;
  CVisionShaderKeeper *this_02;
  GmVec4 *pGVar18;
  int iVar19;
  GxLightNotAmbient *unaff_EBX;
  CPlugBitmap *this_03;
  float fVar20;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  int unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar21;
  CMwNod *this_04;
  undefined4 *puVar22;
  CVisionVisualKeeper *pCVar23;
  float10 fVar24;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffee0;
  code *in_stack_fffffee8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar25;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffeec;
  ulong in_stack_fffffef0;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffef4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffef8;
  SPlugFaceCull *in_stack_fffffefc;
  SHemiInfo *pSVar26;
  SHemiInfo *pSVar27;
  SPlugFaceCull *pSVar28;
  CVisionViewportDx9 *pCVar29;
  CFastBuffer<class_GxVertex2> *in_stack_ffffff04;
  CVisionViewportDx9 *pCVar30;
  GmVec3 *pGVar31;
  GxLightNotAmbient *pGVar32;
  GmVec3 *pGVar33;
  float *in_stack_ffffff0c;
  code *pcVar34;
  EGxTexFilter *pEVar35;
  ulong uVar36;
  CPlugTree *pCVar37;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *pCVar38;
  GmFrustumIso4 *pGVar39;
  CVisionViewportDx9 *pCVar40;
  int *piVar41;
  GxLightNotAmbient *in_stack_ffffff28;
  GxLightNotAmbient *in_stack_ffffff2c;
  GmIso4 *in_stack_ffffff30;
  CPlugTree *pCStack_cc;
  GxLightNotAmbient *pGStack_c8;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  void *pvStack_b0;
  CHmsZoneVPacker *pCStack_ac;
  void *pvStack_a8;
  CVisionViewport *pCStack_a4;
  float fStack_a0;
  CPlugShader *pCStack_9c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_98;
  SCasterCat *pSStack_94;
  CFastBuffer<struct_CHmsVPackerCell::SLightSpotLoc> *pCStack_90;
  CPlugVisual *pCStack_8c;
  float fStack_88;
  float fStack_84;
  int iStack_80;
  CHmsZoneVPacker *pCStack_7c;
  float fStack_78;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *apCStack_74 [3];
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_58;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_54;
  float fStack_50;
  int iStack_4c;
  SPlugFaceCull *pSStack_48;
  float fStack_44;
  float fStack_40;
  CFastBuffer<class_CSystemFidsFolder*> *pCStack_3c;
  int *piStack_38;
  CVisionViewportDx9 aCStack_34 [4];
  int aiStack_30 [2];
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  int iStack_14;
  int iStack_10;
  void *local_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = -1;
  puStack_8 = &LAB_00aeaf0a;
  local_c = ExceptionList;
  pCVar8 = (CPlugVisualQuads *)(DAT_00cca150 ^ (uint)&stack0xffffff18);
  ExceptionList = &local_c;
  iVar19 = *(int *)(param_1 + 0x14);
  (**(code **)(*(int *)param_2 + 0x78))();
  piVar41 = *(int **)(iVar19 + 0x3c);
  if ((piVar41 != (int *)0x0) && (piVar41[5] != 0)) {
    fStack_b4 = (float)piVar41[5];
    uVar36 = 0x98eca5;
    piStack_38 = piVar41;
    pCStack_7c = (CHmsZoneVPacker *)(**(code **)(*piVar41 + 0x78))();
    this_03 = param_2 + 0x4c;
    pGVar9 = (GmIso4 *)CFastBuffer<class_CCrystalFace*>::GetCount(this_03,in_stack_fffffee0);
    if ((DAT_00d77b58 & 1) == 0) {
      DAT_00d77b58 = DAT_00d77b58 | 1;
      CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                (&DAT_00d77b4c,(CFastBuffer<class_CPlugFileSndGen*> *)in_stack_fffffee8);
      _atexit(`protected:_void___thiscall_CVisionViewportDx9::
              TexRender_Hemisphere(class_CPlugBitmap*,class_CPlugBitmapRenderHemisphere*)'::__l4::
              _dynamic_atexit_destructor_for__CorpusZs__);
    }
    if ((DAT_00d77b58 & 2) == 0) {
      DAT_00d77b58 = DAT_00d77b58 | 2;
      aiStack_30[0] = 0;
      CFastRadixSort::CFastRadixSort(&DAT_00d77b34,(CFastRadixSort *)in_stack_fffffee8);
      in_stack_fffffee8 =
           `protected:_void___thiscall_CVisionViewportDx9::
           TexRender_Hemisphere(class_CPlugBitmap*,class_CPlugBitmapRenderHemisphere*)'::__l4::
           _dynamic_atexit_destructor_for__SortCorpuss__;
      _atexit(`protected:_void___thiscall_CVisionViewportDx9::
              TexRender_Hemisphere(class_CPlugBitmap*,class_CPlugBitmapRenderHemisphere*)'::__l4::
              _dynamic_atexit_destructor_for__SortCorpuss__);
      aiStack_30[1] = 0xffffffff;
    }
    CFastBuffer<float>::AllocSetCount(&DAT_00d77b4c,in_stack_ffffff04,(ulong)in_stack_fffffee8);
    pCVar25 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x98ed34;
    pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              CFastBuffer<class_CCrystalFace*>::GetCount(this_03,in_stack_fffffeec);
    pCVar21 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar10 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                            (this_03,pCVar21,(ulong)pCVar25);
        iVar19 = *(int *)pSVar11;
        pCVar25 = pCVar21;
        if ((*(uint *)(*(int *)(*(int *)(*(int *)(iVar19 + 0x48) + 0x14) + 100) + 0x9c) >> 3 & 1) ==
            0) {
          pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                              (&DAT_00d77b4c,pCVar21,(ulong)in_stack_fffffeec);
          pCVar7 = _DAT_00bd3ff4;
        }
        else {
          pGVar9 = (GmIso4 *)
                   ((float)piVar41[0x2a] * *(float *)(iVar19 + 0x44) +
                    (float)piVar41[0x28] * *(float *)(iVar19 + 0x3c) +
                    (float)piVar41[0x29] * *(float *)(iVar19 + 0x40) + (float)piVar41[0x2d]);
          pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                              (&DAT_00d77b4c,pCVar21,(ulong)in_stack_fffffeec);
          pCVar7 = in_stack_ffffff04;
        }
        pCVar21 = pCVar21 + 1;
        *(CFastBuffer<class_GxVertex2> **)pSVar11 = pCVar7;
      } while (pCVar21 < pCVar10);
    }
    CFastRadixSort::Sort(&DAT_00d77b34,DAT_00d77b50,in_stack_ffffff0c,in_stack_fffffef0);
    pGVar32 = (GxLightNotAmbient *)DAT_00d77b3c;
    pCStack_98 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount
                           ((void *)((int)fStack_18 + 100),in_stack_fffffef4);
    pCVar25 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    pCStack_cc = (CPlugTree *)0x0;
    if (pCStack_98 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar11 = CFastBuffer<struct_SHmsCameraProjection>::operator[]
                            ((void *)(iStack_14 + 100),pCVar25,(ulong)in_stack_fffffef8);
        if (pCVar25 < pCVar10) {
          in_stack_fffffef8 =
               *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(uVar36 + (int)pCVar25 * 4);
          pSVar12 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                              (this_03,in_stack_fffffef8,(ulong)in_stack_fffffefc);
          iVar19 = *(int *)pSVar12;
          iVar2 = *(int *)(*(int *)(*(int *)(iVar19 + 0x48) + 0x14) + 100);
          if ((*(uint *)(iVar2 + 0x9c) >> 3 & 1) == 0) goto LAB_0098ee5c;
          in_stack_fffffefc = (SPlugFaceCull *)(iVar19 + 0x18);
          in_stack_fffffef8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(iVar2 + 0x34);
          *(int *)pSVar11 = iVar19;
          GmBoxAligned::SetMult
                    (pSVar11 + 4,(SPlugFaceCull *)in_stack_fffffef8,in_stack_fffffefc,pGVar9);
        }
        else {
LAB_0098ee5c:
          *(undefined4 *)pSVar11 = 0;
        }
        pCVar25 = pCVar25 + 1;
      } while (pCVar25 < pCStack_98);
    }
    RenderTargetClear(this,(CVisionViewportDx9 *)0x1,0,0x3f800000,0.0,(ulong)in_stack_fffffef8);
    if ((_DAT_00b41d80 <= *(float *)(iStack_10 + 0x5c)) && (pGStack_c8 != (GxLightNotAmbient *)0x0))
    {
      pSVar11 = CFastBuffer<struct_SFastCat>::operator[]
                          (&DAT_00000058,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                           (ulong)in_stack_fffffefc);
      fVar3 = *(float *)(pSVar11 + 4);
      fStack_60 = fVar3;
      pSVar11 = CFastBuffer<struct_SFastCat>::operator[]
                          (&DAT_00000058,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                           (ulong)pGVar9);
      pGVar39 = *(GmFrustumIso4 **)(pSVar11 + 4);
      pSVar11 = CFastBuffer<struct_SFastCat>::operator[]
                          (&DAT_00000058,
                           (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000005,
                           (ulong)in_stack_ffffff04);
      if ((fVar3 != 0.0) || ((unaff_ESI != 0 || (*(int *)(pSVar11 + 4) != 0)))) {
        pCVar29 = (CVisionViewportDx9 *)(*(float *)(iStack_4 + 0x60) * (float)_DAT_00ba0e10);
        pCVar30 = _DAT_00b3380c;
        pCVar40 = pCVar29;
        pCStack_98 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                     BitmapSpecularsLAGetClose
                               (this,*(CVisionViewportDx9 **)(iStack_4 + 0x5c),(float)pCVar29,
                                (float)_DAT_00b3380c,(float)pGVar32);
        pCStack_3c = (CFastBuffer<class_CSystemFidsFolder*> *)(uint)(2 < DAT_00d123b8._2_2_);
        pCVar13 = (CVisionViewportDx9 *)
                  ((pCStack_3c != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) + 0x18);
        if (*(int *)(this + (int)pCVar13 * 4 + 0x1294) == 0) {
          pCVar30 = (CVisionViewportDx9 *)0x98ef63;
          pGVar32 = (GxLightNotAmbient *)pCVar13;
          StdShaderLoad(this,pCVar13,(EStdShader2)in_stack_ffffff0c,uVar36);
        }
        pSStack_94 = *(SCasterCat **)(this + (int)pCVar13 * 4 + 0x1294);
        if (*(int *)(this + 0x868) == 0) {
          in_stack_ffffff2c = operator_new(0x98);
          iStack_4 = 1;
          if (in_stack_ffffff2c == (GxLightNotAmbient *)0x0) {
            pCVar23 = (CVisionVisualKeeper *)0x0;
          }
          else {
            CPlugVisualQuads::CPlugVisualQuads((CPlugVisualQuads *)in_stack_ffffff2c,pCVar8);
            pCVar23 = extraout_EAX;
          }
          uVar4 = *(uint *)(pCVar23 + 0x1c);
          if ((uVar4 & 8) != 0) {
            *(uint *)(pCVar23 + 0x1c) = uVar4 & 0xfffffff7;
            if (((uVar4 & 0x400) == 0) &&
               (*(uint *)(pCVar23 + 0x1c) = uVar4 & 0xfffffff7 | 0x400,
               DAT_00d6eb04 != (undefined4 *)0x0)) {
              (**(code **)*DAT_00d6eb04)();
            }
          }
          pCStack_cc = operator_new(0xac);
          if (pCStack_cc == (CPlugTree *)0x0) {
            this_04 = (CMwNod *)0x0;
          }
          else {
            CPlugTree::CPlugTree(pCStack_cc,(CPlugTree *)pCVar40);
            this_04 = extraout_EAX_00;
          }
          param_1 = (CVisionViewportDx9 *)0xffffffff;
          if (this_04 != *(CMwNod **)(this + 0x868)) {
            if (this_04 != (CMwNod *)0x0) {
              CMwNod::MwAddRef(this_04,(CMwNod *)pCVar40);
            }
            if (*(CMwNod **)(this + 0x868) != (CMwNod *)0x0) {
              CMwNod::MwRelease(*(CMwNod **)(this + 0x868),(CMwNod *)pCVar40);
            }
            *(CMwNod **)(this + 0x868) = this_04;
          }
          pGVar39 = (GmFrustumIso4 *)0x0;
          pCVar8 = (CPlugVisualQuads *)0x0;
          pGVar32 = (GxLightNotAmbient *)0x98f051;
          CPlugTree::SetVisual(*(CPlugTree **)(this + 0x868),pCVar23,pCStack_8c);
          *(uint *)(*(int *)(this + 0x868) + 0x9c) =
               *(uint *)(*(int *)(this + 0x868) + 0x9c) & 0xffffdfff;
        }
        aiStack_30[0] = 0;
        fStack_78 = 0.0;
        apCStack_74[0] = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (pCStack_7c != (CHmsZoneVPacker *)0x0) {
          iStack_80 = 0;
          do {
            pSVar28 = pSStack_48;
            pcVar34 = (code *)0x98f09b;
            pCVar25 = apCStack_74[0];
            pSVar11 = CFastBuffer<struct_SHmsCameraProjection>::operator[]
                                (param_2 + 100,apCStack_74[0],(ulong)pCVar8);
            pCVar14 = pCStack_7c + (int)(&PTR_DAT_00d19c28)[*(int *)(param_2 + 0x70)];
            if (*(int *)pSVar11 == 0) {
              if (pCStack_ac <= apCStack_74[0]) break;
            }
            else {
              iVar19 = *(int *)(*(int *)pSVar11 + 0x58);
              apCStack_74[0] = apCStack_74[0] + 1;
              if (iVar19 == 0) {
                fVar3 = 0.0;
              }
              else {
                fVar3 = *(float *)(iVar19 + 0x104);
              }
              pSStack_94 = pSVar11 + 4;
              this_00 = (SPlugFaceCull *)(pSVar11 + 0x1c);
              fStack_28 = 1.0 - (*(float *)pCVar14 + *(float *)(pCVar14 + 8));
              fStack_24 = (*(float *)(pCVar14 + 0xc) + *(float *)(pCVar14 + 4)) - 1.0;
              fStack_20 = 0.0;
              fStack_1c = (*(float *)(pCVar14 + 8) - *(float *)pCVar14) * (float)_DAT_00b33a58;
              fStack_18 = (*(float *)(pCVar14 + 0xc) - *(float *)(pCVar14 + 4)) *
                          (float)_DAT_00b33a58;
              *(float *)(pSVar11 + 100) = *(float *)pSStack_94 - *(float *)(pSVar28 + 0x24);
              *(float *)(pSVar11 + 0x68) = *(float *)(pSVar11 + 8) - *(float *)(pSVar28 + 0x28);
              *(float *)(pSVar11 + 0x6c) = *(float *)(pSVar11 + 0xc) - *(float *)(pSVar28 + 0x2c);
              fStack_a0 = *(float *)(pSVar11 + 100);
              pCStack_9c = *(CPlugShader **)(pSVar11 + 0x68);
              pCStack_98 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar11 + 0x6c);
              in_stack_ffffff2c =
                   (GxLightNotAmbient *)
                   ((float)pCStack_98 * (float)pCStack_98 +
                   (float)pCStack_9c * (float)pCStack_9c + fStack_a0 * fStack_a0);
              if (_DAT_00d38fe4 < (float)in_stack_ffffff2c) {
                fVar24 = (float10)func_0x009c1b40();
                pCVar8 = (CPlugVisualQuads *)(1.0 / (float)fVar24);
                fStack_b8 = (float)pCVar8 * fStack_b8;
                fStack_b4 = fStack_b4 * (float)pCVar8;
                pvStack_b0 = (void *)((float)pCVar8 * (float)pvStack_b0);
              }
              GmMat3::SetDOVandUpV
                        (this_00,(GmMat3 *)&fStack_b8,(GmVec3 *)(iStack_4c + 0x94),(GmVec3 *)pCVar29
                        );
              GmMat3::Transpose(this_00,(GmMat4 *)pCVar30);
              pSVar26 = (SHemiInfo *)0x98f1ff;
              GmMat3::SetMult(pSVar11 + 0x40,pSVar28,this_00,(GmIso4 *)pGVar32);
              if ((float)in_stack_ffffff2c < (float)_DAT_00b44a20) {
                unaff_EBP = (CFastBuffer<class_CCrystalFace*> *)(1.0 - (float)in_stack_ffffff2c);
                pSVar28 = (SPlugFaceCull *)0x98f24f;
                CFastBufferCat<class_CPlugTree*,struct_SFastCat>::SetParsingCat
                          (pvStack_b0,
                           (CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *)0x1,1
                           ,(ulong)pcVar34);
                pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
                if (fStack_50 != 0.0) {
                  do {
                    pSVar12 = CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat>::
                              operator[](pvStack_b0,pCVar10,(ulong)pcVar34);
                    pSVar27 = *(SHemiInfo **)((*(int **)pSVar12)[0x12] + 0x88);
                    if (((byte)pSVar27[0x14] & 8) != 0) {
                      pcVar34 = (code *)apCStack_74;
                      pGVar33 = (GmVec3 *)0x2;
                      pGVar31 = (GmVec3 *)0x98f28d;
                      pvVar15 = (void *)(**(code **)(**(int **)pSVar12 + 0x78))();
                      GmMat3::GetLine(pvVar15,(GmMat3 *)pSVar26,(ulong)pSVar28,pGVar31);
                      pSVar28 = (SPlugFaceCull *)unaff_EBX;
                      pCStack_7c = (CHmsZoneVPacker *)-(float)pCStack_7c;
                      fStack_78 = -fStack_78;
                      apCStack_74[0] =
                           (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)-(float)apCStack_74[0];
                      fStack_24 = (float)pCStack_7c * *(float *)this_00 +
                                  fStack_78 * *(float *)(pSVar11 + 0x20) +
                                  (float)apCStack_74[0] * *(float *)(pSVar11 + 0x24);
                      fStack_20 = *(float *)(pSVar11 + 0x30) * (float)apCStack_74[0] +
                                  *(float *)(pSVar11 + 0x28) * (float)pCStack_7c +
                                  *(float *)(pSVar11 + 0x2c) * fStack_78;
                      fStack_1c = (float)pCStack_7c * *(float *)(pSVar11 + 0x34) +
                                  *(float *)(pSVar11 + 0x38) * fStack_78 +
                                  *(float *)(pSVar11 + 0x3c) * (float)apCStack_74[0];
                      unaff_EBX = (GxLightNotAmbient *)pSVar28;
                      TexRender_HemiAddQuad
                                (this,(CVisionViewportDx9 *)&pCStack_3c,pSVar27,
                                 (GxLightNotAmbient *)pSVar28,(float)&fStack_24,pGVar33);
                      pSVar26 = pSVar27;
                    }
                    pCVar10 = pCVar10 + 1;
                  } while (pCVar10 < pCStack_54);
                }
              }
              fStack_b4 = 0.0;
              in_stack_ffffff28 = (GxLightNotAmbient *)0x0;
              if (fStack_bc == 0.0) {
LAB_0098f439:
                pvVar15 = pvStack_b0;
                pCVar30 = (CVisionViewportDx9 *)0x3;
                pCVar29 = (CVisionViewportDx9 *)0x98f448;
                CFastBufferCat<class_CPlugTree*,struct_SFastCat>::SetParsingCat
                          (pvStack_b0,
                           (CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *)0x3,1
                           ,(ulong)pcVar34);
                pGVar32 = (GxLightNotAmbient *)0x98f455;
                pSVar12 = CFastBuffer<struct_SFastCat>::operator[]
                                    (pvVar15,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                                     (ulong)pCVar25);
                pCStack_cc = (CPlugTree *)(*(int *)((int)pvVar15 + 0x10) + *(int *)pSVar12 * 4);
              }
              else {
                pCVar29 = (CVisionViewportDx9 *)pSVar28;
                if ((DAT_00d77b58 & 4) == 0) {
                  DAT_00d77b58 = DAT_00d77b58 | 4;
                  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                            (&DAT_00d77b28,(CFastBuffer<class_CPlugFileSndGen*> *)pcVar34);
                  pcVar34 = `protected:_void___thiscall_CVisionViewportDx9::
                            TexRender_Hemisphere(class_CPlugBitmap*,class_CPlugBitmapRenderHemisphere*)'
                            ::__l49::_dynamic_atexit_destructor_for__PackerBalls__;
                  _atexit(`protected:_void___thiscall_CVisionViewportDx9::
                          TexRender_Hemisphere(class_CPlugBitmap*,class_CPlugBitmapRenderHemisphere*)'
                          ::__l49::_dynamic_atexit_destructor_for__PackerBalls__);
                  pCVar29 = (CVisionViewportDx9 *)pSVar28;
                }
                if ((DAT_00d77b58 & 8) == 0) {
                  DAT_00d77b58 = DAT_00d77b58 | 8;
                  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                            (&DAT_00d77b1c,(CFastBuffer<class_CPlugFileSndGen*> *)pcVar34);
                  pcVar34 = `protected:_void___thiscall_CVisionViewportDx9::
                            TexRender_Hemisphere(class_CPlugBitmap*,class_CPlugBitmapRenderHemisphere*)'
                            ::__l49::_dynamic_atexit_destructor_for__PackerSpots__;
                  _atexit(`protected:_void___thiscall_CVisionViewportDx9::
                          TexRender_Hemisphere(class_CPlugBitmap*,class_CPlugBitmapRenderHemisphere*)'
                          ::__l49::_dynamic_atexit_destructor_for__PackerSpots__);
                }
                CFastBuffer<int>::SetSizeAtLeast
                          (&DAT_00d77b28,
                           (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)&DAT_00000014,
                           (ulong)pcVar34);
                CFastBuffer<int>::SetSizeAtLeast
                          (&DAT_00d77b1c,
                           (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)&DAT_00000014,
                           (ulong)pCVar25);
                CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
                          (&DAT_00d77b28,(GmFrustumIso4 *)pCVar8);
                CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(&DAT_00d77b1c,pGVar39);
                pGVar39 = (GmFrustumIso4 *)0x1;
                pCVar8 = (CPlugVisualQuads *)&DAT_00d6e350;
                pcVar34 = (code *)&DAT_00d77b1c;
                pGVar32 = (GxLightNotAmbient *)&DAT_00d77b28;
                pCVar30 = (CVisionViewportDx9 *)0x98f405;
                pCVar25 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCStack_90;
                CHmsZoneVPacker::AddInteractLights
                          (pCStack_ac,(CHmsZoneVPacker *)&DAT_00d77b28,
                           (CFastBuffer<struct_CHmsVPackerCell::SLightBallLoc> *)&DAT_00d77b1c,
                           pCStack_90,(CHmsVPackerCell *)&DAT_00d6e350,(SFlags *)0x1,
                           (ERadius)pCVar40);
                iVar19 = DAT_00d77b2c;
                pCVar40 = (CVisionViewportDx9 *)0x98f419;
                fStack_b8 = (float)CFastBuffer<class_CCrystalFace*>::GetCount
                                             (&DAT_00d77b28,unaff_EBP);
                pCStack_9c = DAT_00d77b20;
                unaff_EBP = (CFastBuffer<class_CCrystalFace*> *)0x98f431;
                fStack_bc = (float)CFastBuffer<class_CCrystalFace*>::GetCount
                                             (&DAT_00d77b1c,
                                              (CFastBuffer<class_CCrystalFace*> *)unaff_EBX);
                if (iVar19 == 0) goto LAB_0098f439;
              }
              fVar20 = 0.0;
              if (fVar3 != 0.0) {
                do {
                  pSVar26 = *(SHemiInfo **)((*(int **)(pCStack_cc + (int)fVar20 * 4))[0x12] + 0x88);
                  if (((byte)pSVar26[0x14] & 8) != 0) {
                    iVar19 = (**(code **)(**(int **)(pCStack_cc + (int)fVar20 * 4) + 0x78))();
                    pCStack_8c = (CPlugVisual *)(*(float *)(iVar19 + 0x24) - *(float *)pCStack_98);
                    fStack_88 = *(float *)(iVar19 + 0x28) - *(float *)(pCStack_98 + 4);
                    fStack_84 = *(float *)(iVar19 + 0x2c) - *(float *)(pCStack_98 + 8);
                    fVar6 = fStack_84 * fStack_84 +
                            fStack_88 * fStack_88 + (float)pCStack_8c * (float)pCStack_8c;
                    if ((_DAT_00b37b60 <= fVar6) &&
                       (in_stack_ffffff28 =
                             (GxLightNotAmbient *)
                             (*(float *)(pSVar26 + 0x6c) * *(float *)(pSVar26 + 0x6c)),
                       fVar6 <= (float)in_stack_ffffff28)) {
                      pGVar31 = (GmVec3 *)0x98f515;
                      fVar24 = (float10)func_0x009c1b40();
                      fStack_60 = 1.0 / (float)fVar24;
                      pCVar29 = aCStack_34;
                      fStack_68 = fStack_60 *
                                  ((float)pCStack_90 * *(float *)this_00 +
                                   (float)pCStack_8c * *(float *)(pSVar11 + 0x20) +
                                  fStack_88 * *(float *)(pSVar11 + 0x24));
                      fStack_64 = (*(float *)(pSVar11 + 0x30) * fStack_88 +
                                  *(float *)(pSVar11 + 0x28) * (float)pCStack_90 +
                                  *(float *)(pSVar11 + 0x2c) * (float)pCStack_8c) * fStack_60;
                      fStack_60 = fStack_60 *
                                  ((float)pCStack_90 * *(float *)(pSVar11 + 0x34) +
                                   *(float *)(pSVar11 + 0x38) * (float)pCStack_8c +
                                  *(float *)(pSVar11 + 0x3c) * fStack_88);
                      pGVar32 = (GxLightNotAmbient *)(1.0 - fVar3 / (float)unaff_EBX);
                      in_stack_ffffff28 = pGVar32;
                      TexRender_HemiAddQuad(this,pCVar29,pSVar26,pGVar32,(float)&fStack_68,pGVar31);
                      pCVar30 = (CVisionViewportDx9 *)pSVar26;
                    }
                  }
                  fVar20 = (float)((int)fVar20 + 1);
                } while ((uint)fVar20 < (uint)fVar3);
              }
              pvVar15 = pvStack_a8;
              if (pCStack_ac == (CHmsZoneVPacker *)0x0) {
                pGVar32 = (GxLightNotAmbient *)0x98f611;
                CFastBufferCat<class_CPlugTree*,struct_SFastCat>::SetParsingCat
                          (pvStack_a8,
                           (CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *)
                           &DAT_00000005,1,(ulong)pCVar8);
                pCVar8 = (CPlugVisualQuads *)&DAT_00000005;
                pSVar12 = CFastBuffer<struct_SFastCat>::operator[]
                                    (pvVar15,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                             &DAT_00000005,(ulong)pGVar39);
                pCStack_a4 = (CVisionViewport *)
                             (*(int *)((int)pvVar15 + 0x10) + *(int *)pSVar12 * 4);
              }
              pCStack_cc = (CPlugTree *)0x0;
              if (in_stack_ffffff30 != (GmIso4 *)0x0) {
                do {
                  piVar41 = *(int **)(pCStack_ac + (int)pCStack_cc * 4);
                  pSVar26 = *(SHemiInfo **)(piVar41[0x12] + 0x88);
                  if (((byte)pSVar26[0x14] & 8) != 0) {
                    iVar19 = (**(code **)(*piVar41 + 0x78))();
                    fVar3 = *(float *)(iVar19 + 0x24) - *(float *)pCStack_98;
                    fStack_bc = *(float *)(iVar19 + 0x28) - *(float *)(pCStack_98 + 4);
                    fStack_b8 = *(float *)(iVar19 + 0x2c) - *(float *)(pCStack_98 + 8);
                    in_stack_ffffff28 =
                         (GxLightNotAmbient *)
                         (fStack_b8 * fStack_b8 + fStack_bc * fStack_bc + fVar3 * fVar3);
                    if (_DAT_00b37b60 <= (float)in_stack_ffffff28) {
                      in_stack_ffffff2c = *(GxLightNotAmbient **)(pSVar26 + 0x6c);
                      fVar20 = (float)in_stack_ffffff2c * (float)in_stack_ffffff2c;
                      if ((float)in_stack_ffffff28 <= fVar20) {
                        fVar24 = (float10)func_0x009c1b40();
                        pGVar31 = (GmVec3 *)&fStack_58;
                        fVar6 = 1.0 / (float)fVar24;
                        uVar36 = 2;
                        fVar3 = fVar6 * fVar3;
                        fStack_bc = fStack_bc * fVar6;
                        fStack_b8 = fVar6 * fStack_b8;
                        pGVar32 = (GxLightNotAmbient *)0x98f72f;
                        pvVar15 = (void *)(**(code **)(*piVar41 + 0x78))();
                        pCVar30 = (CVisionViewportDx9 *)0x98f736;
                        GmMat3::GetLine(pvVar15,(GmMat3 *)pGVar32,uVar36,pGVar31);
                        fStack_58 = -fStack_58;
                        pCStack_54 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                     -(float)pCStack_54;
                        fStack_50 = -fStack_50;
                        in_stack_ffffff2c =
                             (GxLightNotAmbient *)
                             (fVar3 * fStack_58 + fStack_bc * (float)pCStack_54 +
                             fStack_b8 * fStack_50);
                        if (*(float *)(pSVar26 + 0xb0) <= (float)in_stack_ffffff2c) {
                          if (*(float *)(pSVar26 + 0xac) <= (float)in_stack_ffffff2c) {
                            pGStack_c8 = (GxLightNotAmbient *)0x3f800000;
                          }
                          else {
                            fVar24 = (float10)func_0x009c2390();
                            in_stack_ffffff2c = (GxLightNotAmbient *)(float)fVar24;
                            pGStack_c8 = in_stack_ffffff2c;
                            if ((float)in_stack_ffffff2c < _DAT_00b37b60) goto LAB_0098f8bb;
                          }
                          pCVar30 = (CVisionViewportDx9 *)aiStack_30;
                          fStack_44 = *(float *)(pSVar11 + 0x24) * fStack_b8 +
                                      fVar3 * *(float *)this_00 +
                                      *(float *)(pSVar11 + 0x20) * fStack_bc;
                          fStack_40 = *(float *)(pSVar11 + 0x30) * fStack_b8 +
                                      *(float *)(pSVar11 + 0x28) * fVar3 +
                                      *(float *)(pSVar11 + 0x2c) * fStack_bc;
                          pCStack_3c = (CFastBuffer<class_CSystemFidsFolder*> *)
                                       (fStack_b8 * *(float *)(pSVar11 + 0x3c) +
                                       *(float *)(pSVar11 + 0x38) * fStack_bc +
                                       *(float *)(pSVar11 + 0x34) * fVar3);
                          in_stack_ffffff2c =
                               (GxLightNotAmbient *)
                               ((1.0 - (float)in_stack_ffffff28 / fVar20) * (float)pGStack_c8);
                          pCVar29 = (CVisionViewportDx9 *)0x98f8a4;
                          TexRender_HemiAddQuad
                                    (this,pCVar30,pSVar26,in_stack_ffffff2c,(float)&fStack_44,
                                     (GmVec3 *)pCVar8);
                          pGVar32 = (GxLightNotAmbient *)pSVar26;
                        }
                      }
                    }
                  }
LAB_0098f8bb:
                  pCStack_cc = pCStack_cc + 1;
                } while (pCStack_cc < in_stack_ffffff30);
              }
            }
            iStack_80 = iStack_80 + 0x10;
            apCStack_74[0] = apCStack_74[0] + 1;
          } while (apCStack_74[0] < pCStack_7c);
          if (aiStack_30[0] != 0) {
            pEVar35 = (EGxTexFilter *)0x98f907;
            CFastBuffer<class_CSystemFidsFolder*>::SetCount
                      (this + 0x454,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,(ulong)pCVar8);
            pSVar12 = CFastBuffer<struct_CHmsViewport::SVisualLocation>::operator[]
                                (this + 0x454,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                 (ulong)pGVar39);
            puVar22 = &DAT_00d670f8;
            pSVar11 = pSVar12;
            for (iVar19 = 0x29; iVar19 != 0; iVar19 = iVar19 + -1) {
              *(undefined4 *)pSVar11 = *puVar22;
              puVar22 = puVar22 + 1;
              pSVar11 = pSVar11 + 4;
            }
            *(uint *)(pSVar12 + 0xa0) = *(uint *)(pSVar12 + 0xa0) & 0xfffffffd;
            pSVar11 = GmMat4::operator[](&DAT_00d67158,
                                         (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                         (ulong)pCVar40);
            pCVar38 = *(CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> **)
                       (this + 0x9f8);
            uVar36 = 2;
            (**(code **)(*(int *)pCVar38 + 0xb0))();
            pSVar16 = CFastBuffer<struct_SHmsRenderRect>::GetLastElem(this + 0x484,pCVar38);
            *(undefined4 *)(pSVar16 + 0x20) = 0;
            pCVar37 = (CPlugTree *)0x98f968;
            CFastBuffer<class_CSystemFidsFolder*>::SetCount
                      (this + 0x460,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,uVar36);
            pSVar11 = CFastBuffer<struct_CHmsViewport::SClippingFrustum>::operator[]
                                (this + 0x460,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                 (ulong)pSVar11);
            puVar22 = &DAT_00d67340;
            for (iVar19 = 0x4e; iVar19 != 0; iVar19 = iVar19 + -1) {
              *(undefined4 *)pSVar11 = *puVar22;
              puVar22 = puVar22 + 1;
              pSVar11 = pSVar11 + 4;
            }
            CFastBuffer<class_CSystemFidsFolder*>::SetCount
                      (this + 0x478,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,(ulong)unaff_EBP);
            pSVar17 = CFastBuffer<struct_SHmsCameraProjection>::operator[]
                                (this + 0x478,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                 (ulong)unaff_EBX);
            puVar22 = &DAT_00d67270;
            pSVar11 = pSVar17;
            for (iVar19 = 0x34; iVar19 != 0; iVar19 = iVar19 + -1) {
              *(undefined4 *)pSVar11 = *puVar22;
              puVar22 = puVar22 + 1;
              pSVar11 = pSVar11 + 4;
            }
            *(uint *)(pSVar17 + 0xcc) = *(uint *)(pSVar17 + 0xcc) & 0xfffffffe;
            pSVar11 = GmMat4::operator[](pSVar17 + 0x40,
                                         (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                         (ulong)in_stack_ffffff28);
            piVar41 = *(int **)(this + 0x9f8);
            uVar36 = 3;
            (**(code **)(*piVar41 + 0xb0))();
            CFastBuffer<class_CSystemFidsFolder*>::SetCount
                      (this + 0x538,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,(ulong)piVar41);
            pSVar17 = CFastBuffer<struct_CHmsViewport::SVisualLocation>::operator[]
                                (this + 0x538,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                 uVar36);
            ComputeAndSetCullMode(this,(CVisionViewportDx9 *)pSVar12,(SHmsCameraLocation *)pSVar11);
            GmIso4::SetIdentity((SPlugFaceCull *)(pSVar17 + 0x70),(GmMat43 *)in_stack_ffffff2c);
            GmIso4::SetMult(pSVar17,(SPlugFaceCull *)(pSVar17 + 0x70),
                            (SPlugFaceCull *)(pSVar12 + 0x30),in_stack_ffffff30);
            uVar36 = 0x98fa10;
            (**(code **)(*(int *)this + 0x1a4))();
            *(undefined2 *)(this + 900) = 0;
            *(undefined2 *)(this + 0x386) = 0;
            *(undefined2 *)(this + 0x388) = 0;
            *(undefined2 *)(this + 0x38a) = 0;
            *(undefined4 *)(this + 0x450) = 0;
            *(undefined4 *)(this + 0x430) = 0;
            this_02 = CVisionViewport::ShaderGetKeeper
                                ((CVisionViewport *)this,pCStack_a4,(CPlugShader *)pCVar30);
            CDx9StateBlock::FilterRenderState(7,0);
            _DAT_00d75f4c = 1;
            if (DAT_00d75c3c != 0) {
              CDx9StateBlock::PackRenderState(7,0,(SPackedDesc *)&fStack_50);
              *(uint *)(&DAT_00d76ed8 + (int)fStack_50 * 4) =
                   *(uint *)(&DAT_00d76ed8 + (int)fStack_50 * 4) & ~(uint)pSStack_48;
            }
            pCVar5 = *(CHmsViewport **)(this + 0x868);
            iVar19 = *(int *)(pCVar5 + 0x90);
            CFastBuffer<class_CSystemFidsFolder*>::SetCount
                      ((void *)(iVar19 + 0x78),pCStack_3c,(ulong)pGVar32);
            this_01 = pCStack_9c;
            if (pCStack_3c == (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
              CDx9ShaderKeeper::SetShaderBitmapNoDirty
                        ((CDx9ShaderKeeper *)this_02,(CDx9ShaderKeeper *)0x1,(ulong)pCStack_98,
                         (CPlugBitmap *)0x0,(CPlugBitmapSampler *)0x0,pEVar35);
            }
            else {
              pGVar18 = CPlugShader::GetLoadFxValue
                                  (pCStack_9c,(CPlugShader *)&DAT_00d77c2c,(CMwId *)0x0,
                                   (SPlugGpuLoadFx **)0x0,(CPlugShaderPass **)0x0,
                                   (EPlugGpuPipeline *)0x0,pEVar35);
              if (pGVar18 != (GmVec4 *)0x0) {
                *(undefined4 *)pGVar18 = *(undefined4 *)(param_1 + 0x5c);
                *(undefined4 *)(pGVar18 + 4) = 0;
                *(undefined4 *)(pGVar18 + 8) = 0;
                *(undefined4 *)(pGVar18 + 0xc) = 0x3f800000;
              }
              pGVar18 = CPlugShader::GetLoadFxValue
                                  (this_01,(CPlugShader *)&DAT_00d77c30,(CMwId *)0x0,
                                   (SPlugGpuLoadFx **)0x0,(CPlugShaderPass **)0x0,
                                   (EPlugGpuPipeline *)0x0,(ulong *)pCVar37);
              if (pGVar18 != (GmVec4 *)0x0) {
                *(undefined4 *)pGVar18 = *(undefined4 *)(param_2 + 0x60);
                *(undefined4 *)(pGVar18 + 4) = 0;
                *(undefined4 *)(pGVar18 + 8) = 0;
                *(undefined4 *)(pGVar18 + 0xc) = 0x3f800000;
              }
            }
            puVar1 = (uint *)(iVar19 + 0x1c);
            *puVar1 = *puVar1 | 0x200;
            CHmsViewport::RenderTree((CHmsViewport *)this,pCVar5,pCVar37);
            _DAT_00d75f4c = 0;
            if (DAT_00d75c3c != 0) {
              CDx9StateBlock::PackRenderState(7,0xffffffff,(SPackedDesc *)&pCStack_8c);
              *(uint *)(&DAT_00d76ed8 + (int)pCStack_8c * 4) =
                   *(uint *)(&DAT_00d76ed8 + (int)pCStack_8c * 4) | (uint)fStack_84;
            }
            CDx9StateBlock::FilterRenderState(7,uVar36);
          }
        }
      }
    }
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::TexRender_LightFromMap
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CVisionViewportDx9::TexRender_LightFromMap
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2,
          CPlugBitmapRenderLightFromMap *param_3)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  SCasterCat *pSVar4;
  SNewTriangleVert *this_00;
  CHmsPackLightMap *this_01;
  EDbgLight EVar5;
  SCasterCat *pSVar6;
  ulong uVar7;
  SCasterCat *pSVar8;
  void *this_02;
  GmVec4 *pGVar9;
  CVisionViewportDx9 *pCVar10;
  int extraout_EDX;
  ulong unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong unaff_EDI;
  CPlugBitmap *pCVar11;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar12;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar13;
  bool bVar14;
  ulong in_stack_fffffeec;
  ulong in_stack_fffffef0;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *in_stack_fffffef4;
  ulong in_stack_fffffef8;
  ulong in_stack_fffffefc;
  ulong in_stack_ffffff00;
  ulong in_stack_ffffff04;
  CHmsPackLightMap *in_stack_ffffff08;
  CPlugShader *in_stack_ffffff0c;
  SHmsRenderRect *pSVar15;
  SCasterCat *pSVar16;
  SHmsCameraLocation *in_stack_ffffff10;
  SHmsRenderRect *pSVar17;
  GmBoxAligned *pGVar18;
  GmIso4 *pGVar19;
  CFastBuffer<class_GxVertex2> *pCVar20;
  int iVar21;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_ffffff14;
  CFastBuffer<class_CCrystalFace*> *pCVar22;
  CHmsZone *pCVar23;
  CPlugBitmapRenderLightFromMap *pCVar24;
  ulong in_stack_ffffff18;
  CPlugBitmap *in_stack_ffffff1c;
  float in_stack_ffffff20;
  float in_stack_ffffff24;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_84;
  undefined4 local_80;
  uint local_7c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_78;
  CVisionViewportDx9 *local_74;
  SNewTriangleVert *local_70;
  SCasterCat *local_6c;
  SCasterCat *local_68;
  undefined1 *local_64;
  undefined4 local_60;
  int local_5c;
  float local_58;
  float local_54;
  uint local_50;
  uint local_4c;
  SCasterCat *local_48;
  float local_44;
  float local_40;
  SCasterCat *local_3c;
  uint local_38;
  uint local_34;
  CHmsViewport *local_30;
  SCasterCat *local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  CPlugBitmap *local_1c;
  float local_18;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_14;
  CPlugBitmap *local_10;
  CHmsItem *local_c;
  CFastBuffer<class_GxVertex2> *local_8;
  
  iVar21 = *(int *)(param_1 + 0x14);
  pCVar10 = (CVisionViewportDx9 *)0x1;
  if (((*(uint *)(param_2 + 0x14) & 0x10) != 0) && ((*(uint *)(param_2 + 0x14) & 0x20) != 0)) {
    pCVar10 = (CVisionViewportDx9 *)((uint)(*(int *)(this + 0x2b8) != 0) * 4 + 3);
  }
  local_28 = iVar21;
  RenderTargetClear(this,pCVar10,0xffffffff,0x3f800000,0.0,unaff_EDI);
  local_24 = *(uint *)(iVar21 + 0x24);
  local_20 = *(uint *)(iVar21 + 0x28);
  if (local_24 == local_20) {
    bVar14 = false;
    iVar21 = 0;
    if (local_24 != 0) {
      for (; (local_24 >> iVar21 & 1) == 0; iVar21 = iVar21 + 1) {
      }
    }
    if (local_24 != 0) {
      bVar14 = local_24 >> ((char)iVar21 + 1U & 0x1f) == 0;
    }
    if (bVar14) {
      bVar14 = false;
      iVar21 = 0;
      if (local_20 != 0) {
        for (; (local_20 >> iVar21 & 1) == 0; iVar21 = iVar21 + 1) {
        }
      }
      if (local_20 != 0) {
        bVar14 = local_20 >> ((char)iVar21 + 1U & 0x1f) == 0;
      }
      if (bVar14) {
        pCVar11 = param_2 + 0x4c;
        local_10 = pCVar11;
        local_8 = (CFastBuffer<class_GxVertex2> *)
                  CFastBuffer<class_CCrystalFace*>::GetCount(pCVar11,unaff_ESI);
        if (local_8 != (CFastBuffer<class_GxVertex2> *)0x0) {
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                              unaff_EBX);
          local_30 = *(CHmsViewport **)(*(int *)pSVar4 + 0x14);
          CFastBuffer<class_CSystemFidsFolder*>::SetCount
                    (this + 0x454,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,in_stack_fffffeec);
          pSVar4 = CFastBuffer<struct_CHmsViewport::SVisualLocation>::operator[]
                             (this + 0x454,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                              in_stack_fffffef0);
          *(uint *)(pSVar4 + 0xa0) = *(uint *)(pSVar4 + 0xa0) | 1;
          this_00 = CFastBuffer<struct_SHmsRenderRect>::GetLastElem(this + 0x484,in_stack_fffffef4);
          *(undefined4 *)(this_00 + 0x20) = 0;
          local_70 = this_00;
          CFastBuffer<class_CSystemFidsFolder*>::SetCount
                    (this + 0x460,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,in_stack_fffffef8);
          local_48 = CFastBuffer<struct_CHmsViewport::SClippingFrustum>::operator[]
                               (this + 0x460,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                in_stack_fffffefc);
          CFastBuffer<class_CSystemFidsFolder*>::SetCount
                    (this + 0x478,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,in_stack_ffffff00);
          local_2c = CFastBuffer<struct_SHmsCameraProjection>::operator[]
                               (this + 0x478,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                in_stack_ffffff04);
          *(undefined2 *)(this + 900) = *(undefined2 *)(param_2 + 0x20);
          *(ushort *)(this + 0x386) = *(ushort *)(param_2 + 0x22) & *(ushort *)(param_2 + 0x20);
          *(undefined2 *)(this + 0x388) = *(undefined2 *)(param_2 + 0x24);
          *(ushort *)(this + 0x38a) = *(ushort *)(param_2 + 0x26) & *(ushort *)(param_2 + 0x24);
          *(undefined4 *)(this + 0x850) = 0;
          if (*(int *)(local_30 + 0x104) == 0) {
            this_01 = (CHmsPackLightMap *)0x0;
          }
          else {
            this_01 = *(CHmsPackLightMap **)(*(int *)(local_30 + 0x104) + 0xf0);
          }
          if (*(int *)(local_30 + 0xb4) == 0) {
            if ((this_01 == (CHmsPackLightMap *)0x0) ||
               (EVar5 = CHmsPackLightMap::DynaDbgLightGet(this_01,in_stack_ffffff08), EVar5 == 0)) {
              GmVec2_SetScaleTransFromMinMax((GmVec2 *)&local_38,(GmVec2 *)(param_2 + 0x9c));
              GmVec2_SetScaleTransFromMinMax((GmVec2 *)&local_44,(GmVec2 *)(extraout_EDX + 0xa4));
              _DAT_00d6e80c = local_38;
              _DAT_00d6e810 = local_44;
              _DAT_00d6e814 = local_40;
              _DAT_00d6e818 = local_34;
            }
            else {
              _DAT_00d6e80c = 0;
              _DAT_00d6e810 = 0;
              _DAT_00d6e818 = 0x3f800000;
              _DAT_00d6e814 = 0x3f800000;
            }
          }
          else {
            GmVec2_SetScaleTransFromMinMax((GmVec2 *)&DAT_00d6e804,(GmVec2 *)(param_2 + 0x94));
          }
          local_80 = *(undefined4 *)(this + 0x8e4);
          local_74 = *(CVisionViewportDx9 **)(this + 0x8ec);
          local_84 = *(undefined4 *)(this + 0x8e8);
          SetShaderForced(this,(CVisionViewportDx9 *)0x1,in_stack_ffffff0c);
          *(undefined4 *)(this + 0x8e4) = 4;
          *(undefined4 *)(this + 0x8e8) = 1;
          local_7c = *(uint *)(local_30 + 0xac) >> 1 & 3;
          *(uint *)(local_30 + 0xac) = *(uint *)(local_30 + 0xac) & 0xfffffff9;
          ComputeAndSetCullMode(this,(CVisionViewportDx9 *)pSVar4,in_stack_ffffff10);
          pSVar15 = (SHmsRenderRect *)&DAT_00000016;
          CDx9StateBlock::FilterRenderState(0x16,*(ulong *)(this + 0x91c));
          if ((_DAT_00d77b68 & 1) == 0) {
            _DAT_00d77b68 = _DAT_00d77b68 | 1;
            CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                      (&DAT_00d77b5c,in_stack_ffffff14);
            _atexit(`protected:_void___thiscall_CVisionViewportDx9::
                    TexRender_LightFromMap(class_CPlugBitmap*,class_CPlugBitmapRenderLightFromMap*)'
                    ::__l26::_dynamic_atexit_destructor_for__ObjectVisibles__);
          }
          CFastBuffer<class_GmVector2<unsigned_short>_>::AllocSetCount
                    (&DAT_00d77b5c,local_8,in_stack_ffffff18);
          local_14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
          if (local_8 != (CFastBuffer<class_GxVertex2> *)0x0) {
            do {
              pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 (local_10,local_14,(ulong)in_stack_ffffff1c);
              local_c = *(CHmsItem **)(*(int *)pSVar6 + 0x48);
              pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 (&DAT_00d77b5c,local_14,(ulong)in_stack_ffffff20);
              in_stack_ffffff20 = 0.0;
              *(uint *)pSVar6 =
                   *(uint *)pSVar6 ^ (*(uint *)(local_c + 0x1c) >> 0xf ^ *(uint *)pSVar6) & 1;
              *(uint *)pSVar6 =
                   *(uint *)(*(int *)(*(int *)(local_c + 0x14) + 100) + 0x9c) >> 2 & 2 |
                   *(uint *)pSVar6 & 1;
              in_stack_ffffff1c = (CPlugBitmap *)0x990d19;
              CHmsItem::IsVisibleSet(local_c,(CHmsItem *)0x0,(int)in_stack_ffffff24);
              local_14 = local_14 + 1;
            } while (local_14 < local_8);
          }
          pSVar6 = (SCasterCat *)&local_a0;
          pCVar22 = (CFastBuffer<class_CCrystalFace*> *)0x0;
          local_a0 = 0;
          local_9c = 0;
          local_98 = 0;
          (**(code **)(*(int *)this + 0x17c))();
          local_1c = *(CPlugBitmap **)(param_2 + 0x80);
          if ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((int)local_1c * (int)local_1c) <
              local_8) {
            local_10 = *(CPlugBitmap **)(param_2 + 0x84);
            do {
              if (local_10 <= local_1c) break;
              local_1c = (CPlugBitmap *)((int)local_1c * 2);
            } while ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                     ((int)local_1c * (int)local_1c) < local_8);
          }
          *(CPlugBitmap **)(param_2 + 0x7c) = local_1c;
          uVar7 = CFastBuffer<class_CCrystalFace*>::GetCount((void *)(local_28 + 0x68),pCVar22);
          if (((uVar7 != 0) && (*(int *)(local_28 + 0x84) * *(int *)(local_28 + 0x80) != 0)) &&
             (pCVar11 = (CPlugBitmap *)(*(uint *)(local_28 + 0x80) >> 1), local_1c < pCVar11)) {
            *(CPlugBitmap **)(param_2 + 0x7c) = pCVar11;
          }
          local_50 = *(uint *)(param_2 + 0x7c);
          local_38 = local_24 / local_50;
          local_34 = local_20 / local_50;
          local_28 = *(uint *)(param_2 + 0x78);
          local_4c = local_28;
          if (local_34 < local_28) {
            local_4c = local_34;
          }
          if (local_38 < local_28) {
            local_28 = local_38;
          }
          local_3c = (SCasterCat *)0x1f;
          if (local_38 / local_28 != 0) {
            for (; local_38 / local_28 >> (int)local_3c == 0; local_3c = local_3c + -1) {
            }
          }
          local_24 = 0;
          local_44 = (float)(int)local_50;
          local_20 = 0;
          if ((int)local_50 < 0) {
            local_44 = local_44 + _DAT_00c418d0;
          }
          local_44 = 1.0 / local_44;
          local_14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
          local_40 = local_44;
          local_10 = (CPlugBitmap *)local_50;
          local_c = (CHmsItem *)local_44;
          if (local_8 != (CFastBuffer<class_GxVertex2> *)0x0) {
            local_78 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(local_50 * local_50);
            do {
              if (local_78 <= local_14) break;
              pSVar17 = (SHmsRenderRect *)0x990e5c;
              pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 (&DAT_00d77b5c,local_14,(ulong)pSVar6);
              if (((*(uint *)pSVar8 & 1) != 0) && ((*(uint *)pSVar8 & 2) != 0)) {
                *(undefined4 *)(this_00 + 0x18) = 0;
                *(undefined4 *)(this_00 + 0x1c) = 0x3f800000;
                local_50 = ((int)local_10 - local_20) - 1;
                *(uint *)(this_00 + 8) = local_38 * local_24;
                *(uint *)(this_00 + 0x10) = local_38;
                *(uint *)(this_00 + 0x14) = local_34;
                *(uint *)(this_00 + 0xc) = local_34 * local_50;
                uVar7 = 0x990eaf;
                pSVar6 = (SCasterCat *)this_00;
                (**(code **)(*(int *)this + 0x1ac))();
                SHmsRenderRect::ComputeTransfosFromRect(this_00,pSVar15);
                ViewportSet(this,(CVisionViewportDx9 *)this_00,pSVar17);
                *(undefined4 *)(this_00 + 0x20) = 0;
                pSVar15 = (SHmsRenderRect *)0x990ed4;
                pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   (param_2 + 0x4c,local_14,uVar7);
                fVar1 = (float)(int)local_28;
                local_c = *(CHmsItem **)pSVar8;
                local_6c = pSVar4 + 0x30;
                local_64 = &stack0xffffff08;
                local_60 = *(undefined4 *)(*(int *)(*(int *)((int)local_c + 0x48) + 0x14) + 100);
                local_5c = (int)local_c + 0x18;
                if ((int)local_28 < 0) {
                  fVar1 = fVar1 + _DAT_00c418d0;
                }
                local_58 = (float)_DAT_00b38328 / fVar1 + 1.0;
                fVar1 = (float)(int)local_4c;
                if ((int)local_4c < 0) {
                  fVar1 = fVar1 + _DAT_00c418d0;
                }
                local_1c = (CPlugBitmap *)0x0;
                local_54 = (float)_DAT_00b38328 / fVar1 + 1.0;
                local_68 = pSVar4;
                do {
                  if (local_1c == (CPlugBitmap *)0x0) {
                    CPlugBitmapRenderLightFromMap::ComputeCamera_DovObjectY
                              ((CPlugBitmapRenderLightFromMap *)param_2,
                               (CPlugBitmapRenderLightFromMap *)&local_6c,(SComputeCamera *)pSVar6);
LAB_00990f7d:
                    pSVar6 = pSVar4;
                    (**(code **)(*(int *)this + 0x19c))();
                    pSVar6 = GmMat4::operator[](pSVar4 + 0x60,
                                                (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                                0x0,(ulong)pSVar6);
                    pGVar18 = *(GmBoxAligned **)(this + 0x9f8);
                    pCVar23 = (CHmsZone *)0x2;
                    (**(code **)(*(int *)pGVar18 + 0xb0))();
                    *(uint *)(pSVar4 + 0xa0) = *(uint *)(pSVar4 + 0xa0) & 0xfffffffd;
                    GmFrustum::SetOrtho(&stack0xfffffeec,(GmFrustum *)&stack0xffffff08,pGVar18);
                    CHmsViewport::SClippingFrustum::Set
                              (local_48,(CMwCmdScriptVarBool *)&stack0xfffffeec,(int)(pSVar4 + 0x30)
                              );
                    pGVar19 = (GmIso4 *)0x0;
                    pSVar8 = local_2c;
                    pSVar16 = local_48;
                    (**(code **)(*(int *)this + 0x1a0))();
                    GmMat4::operator[](local_2c + 0x40,
                                       (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                       (ulong)pSVar8);
                    (**(code **)(**(int **)(this + 0x9f8) + 0xb0))();
                    *(uint *)(local_2c + 0xcc) = *(uint *)(local_2c + 0xcc) & 0xfffffffe;
                    if (local_1c == (CPlugBitmap *)0x0) {
                      if (*(int *)((int)local_c + 0x4c) == 0) {
                        pGVar19 = (GmIso4 *)0x24;
                        pSVar16 = (SCasterCat *)0x99102f;
                        this_02 = operator_new(0x24);
                        if (this_02 == (void *)0x0) {
                          this_02 = (void *)0x0;
                        }
                        else {
                          pGVar19 = (GmIso4 *)0x99103f;
                          CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>::
                          CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>
                                    (this_02,(CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>
                                              *)pCVar23);
                        }
                        *(void **)((int)local_c + 0x4c) = this_02;
                      }
                      pGVar9 = CPlugShaderLoadIds::FindOrAddLoadId
                                         (*(void **)((int)local_c + 0x4c),(CPlugShaderLoadIds *)0xbe
                                          ,(ELoadId)pSVar16);
                      GmMat4::SetMult(&stack0xffffff20,(SPlugFaceCull *)pSVar4,
                                      (SPlugFaceCull *)local_2c,pGVar19);
                      fVar2 = (float)_DAT_00b313b8;
                      fVar1 = local_44 * fVar2;
                      *(float *)pGVar9 = fVar1 * in_stack_ffffff20;
                      *(float *)(pGVar9 + 4) = in_stack_ffffff24 * fVar1;
                      *(float *)(pGVar9 + 8) = local_d8 * fVar1;
                      fVar3 = (float)(int)local_24;
                      if ((int)local_24 < 0) {
                        fVar3 = fVar3 + _DAT_00c418d0;
                      }
                      *(float *)(pGVar9 + 0xc) = fVar1 * local_d4 + (fVar3 + fVar2) * local_44;
                      local_18 = (float)_DAT_00b5dbb0 * local_40;
                      *(float *)(pGVar9 + 0x10) = local_18 * local_d0;
                      *(float *)(pGVar9 + 0x14) = local_cc * local_18;
                      *(float *)(pGVar9 + 0x18) = local_c8 * local_18;
                      *(float *)(pGVar9 + 0x1c) = local_18 * local_c4;
                      fVar1 = (float)(int)local_50;
                      if ((int)local_50 < 0) {
                        fVar1 = fVar1 + _DAT_00c418d0;
                      }
                      *(float *)(pGVar9 + 0x1c) =
                           local_40 * (fVar1 + fVar2) + *(float *)(pGVar9 + 0x1c);
                      this_00 = local_70;
                    }
                    pSVar15 = (SHmsRenderRect *)0x991117;
                    CHmsViewport::RenderZone((CHmsViewport *)this,local_30,pCVar23);
                  }
                  else {
                    iVar21 = CPlugBitmapRenderLightFromMap::ComputeCamera_DovWorldY_IsNeeded
                                       ((CPlugBitmapRenderLightFromMap *)param_2,
                                        (CPlugBitmapRenderLightFromMap *)&local_6c,
                                        (SComputeCamera *)pSVar6);
                    if (iVar21 != 0) goto LAB_00990f7d;
                  }
                  local_1c = local_1c + 1;
                } while (local_1c < (CPlugBitmap *)0x2);
              }
              local_24 = local_24 + 1;
              if ((CPlugBitmap *)local_24 == local_10) {
                local_20 = local_20 + 1;
                local_24 = 0;
              }
              local_14 = local_14 + 1;
            } while (local_14 < local_8);
          }
          pCVar22 = (CFastBuffer<class_CCrystalFace*> *)0x0;
          (**(code **)(*(int *)this + 400))();
          pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
          if (local_8 != (CFastBuffer<class_GxVertex2> *)0x0) {
            do {
              pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 (&DAT_00d77b5c,pCVar12,(ulong)pCVar22);
              pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 (param_2 + 0x4c,pCVar12,*(uint *)pSVar4 & 1);
              pCVar22 = (CFastBuffer<class_CCrystalFace*> *)0x991197;
              CHmsItem::IsVisibleSet
                        (*(CHmsItem **)(*(int *)pSVar4 + 0x48),(CHmsItem *)pSVar6,
                         (int)in_stack_ffffff1c);
              pCVar12 = pCVar12 + 1;
            } while (pCVar12 < local_8);
          }
          if (*(SCasterCat **)(param_2 + 0x74) != local_3c) {
            *(SCasterCat **)(param_2 + 0x74) = local_3c;
            pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x9911b9;
            pCVar20 = local_8;
            CFastBuffer<class_GmVector2<unsigned_short>_>::AllocSetCount
                      (param_2 + 0x5c,local_8,(ulong)pCVar22);
            pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
            if (local_8 != (CFastBuffer<class_GxVertex2> *)0x0) {
              do {
                local_3c = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                     (param_2 + 0x4c,pCVar13,(ulong)pCVar12);
                pCVar12 = pCVar13;
                pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   (param_2 + 0x5c,pCVar13,(ulong)pCVar20);
                pCVar13 = pCVar13 + 1;
                *(undefined4 *)pSVar4 = *(undefined4 *)local_3c;
              } while (pCVar13 < local_8);
            }
          }
          local_10 = param_2 + 0x5c;
          pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                    CFastBuffer<class_CCrystalFace*>::GetCount(local_10,pCVar22);
          pCVar13 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
          if (pCVar12 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
            do {
              pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 (local_10,pCVar13,(ulong)param_1);
              pCVar24 = *(CPlugBitmapRenderLightFromMap **)
                         (*(int *)(*(int *)(*(int *)pSVar4 + 0x48) + 0x14) + 100);
              iVar21 = 0x991220;
              CPlugBitmapRenderLightFromMap::ObjectUpdateMaxMipLevel
                        ((CPlugBitmapRenderLightFromMap *)param_2,pCVar24,(CPlugTree *)pSVar6,
                         in_stack_ffffff1c);
              pCVar13 = pCVar13 + 1;
            } while (pCVar13 < pCVar12);
            if (pCVar12 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
              (**(code **)(*(int *)this + 0x214))();
              CVisionViewport::ShaderUndirtyAll
                        ((CVisionViewport *)this,(CVisionViewport *)0x0,iVar21);
              CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
                        (local_10,(GmFrustumIso4 *)pCVar24);
            }
          }
          *(uint *)(local_30 + 0xac) =
               *(uint *)(local_30 + 0xac) ^ (local_7c * 2 ^ *(uint *)(local_30 + 0xac)) & 6;
          SetShaderForced(this,local_74,(CPlugShader *)pSVar6);
          *(undefined4 *)(this + 0x8e4) = local_80;
          *(undefined4 *)(this + 0x8e8) = local_84;
        }
      }
    }
  }
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::TexRender_LightFromMap_Download
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CVisionViewportDx9::TexRender_LightFromMap_Download
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2)
{
{
  int iVar1;
  uint uVar2;
  CPlugBitmap *pCVar3;
  ulong uVar4;
  SCasterCat *pSVar5;
  int iVar6;
  IDirect3DSurface9 *pIVar7;
  IDirect3DSurface9 *pIVar8;
  uint *puVar9;
  ulong unaff_EBX;
  uint uVar10;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar11;
  float unaff_EBP;
  IDirect3DSurface9 *pIVar12;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  uint uVar13;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar14;
  CVisionViewportDx9 *in_stack_00000020;
  CMwCmdScriptVarBool *pCVar15;
  int *piVar16;
  CDx9TextureKeeper *in_stack_ffffff84;
  IDirect3DSurface9 *in_stack_ffffff88;
  ulong *in_stack_ffffff8c;
  CMwCmdScriptVarBool *in_stack_ffffff94;
  void *local_60;
  IDirect3DSurface9 *local_5c;
  int local_58;
  int iStack_54;
  CVisionViewportDx9 *pCStack_50;
  IDirect3DSurface9 *local_4c;
  IDirect3DSurface9 *local_48;
  IDirect3DSurface9 *local_44;
  undefined8 local_40;
  IDirect3DSurface9 *local_38;
  IDirect3DSurface9 *local_34;
  int local_30;
  int iStack_2c;
  IDirect3DSurface9 *local_28;
  IDirect3DSurface9 *pIStack_24;
  IDirect3DSurface9 *pIStack_20;
  undefined1 auStack_14 [20];
  
  pIVar12 = *(IDirect3DSurface9 **)(param_1 + 0x14);
  iVar6 = *(int *)(param_1 + 0x74);
  local_34 = *(IDirect3DSurface9 **)(pIVar12 + 0x24);
  iVar1 = *(int *)(iVar6 + 0x7c);
  local_30 = *(int *)(pIVar12 + 0x28);
  local_48 = pIVar12;
  local_5c = (IDirect3DSurface9 *)D3DFormatGetBytePerPixel(*(_D3DFORMAT *)(pIVar12 + 0x14));
  pCVar3 = (CPlugBitmap *)
           CFastBuffer<class_CCrystalFace*>::GetCount((void *)(iVar6 + 0x4c),unaff_EDI);
  if ((iVar1 != 0) && (pCVar3 != (CPlugBitmap *)0x0)) {
    pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(iVar6 + 0x68);
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(pCVar11,unaff_ESI);
    if (uVar4 != 0) {
      iVar6 = *(int *)(this + 0x24c);
      if (*(int *)(iVar6 + 0x20) == 0) {
        iVar6 = *(int *)(iVar6 + 0x24);
      }
      else {
        iVar6 = *(int *)(iVar6 + 0x28);
      }
      if (*(int *)(iVar6 + 0xc4) == 0) {
        GxBGRAColor::SetRealRGBA(&local_5c,(GxBGRAColor *)0x3f800000,1.0,1.0,1.0,unaff_EBP);
        pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (pCVar11 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          do {
            pSVar5 = CFastBuffer<class_GxColor>::operator[](local_60,pCVar14,unaff_EBX);
            pCVar14 = pCVar14 + 1;
            *(int *)pSVar5 = local_58;
            *(int *)(pSVar5 + 4) = local_58;
            *(int *)(pSVar5 + 8) = local_58;
            *(int *)(pSVar5 + 0xc) = local_58;
          } while (pCVar14 < pCVar11);
          return;
        }
      }
      else {
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                            (ulong)unaff_EBP);
        local_44 = *(IDirect3DSurface9 **)(*(int *)pSVar5 + 0x14);
        local_38 = (IDirect3DSurface9 *)(iVar1 * 2);
        local_5c = (IDirect3DSurface9 *)((uint)local_28 / (uint)local_38);
        iVar6 = 0x1f;
        if (local_5c != (IDirect3DSurface9 *)0x0) {
          for (; (uint)local_5c >> iVar6 == 0; iVar6 = iVar6 + -1) {
          }
        }
        local_34 = local_38;
        iVar6 = CDx9TextureKeeper::RtWheelToCpuInit
                          (pIVar12,(CDx9TextureKeeper *)&local_38,(GmNat2 *)&DAT_00000004,unaff_EBX)
        ;
        if (iVar6 != 0) {
          pIVar7 = CDx9TextureKeeper::RtWheelToCpuGetToRead(pIVar12,in_stack_ffffff84);
          if (pIVar7 != (IDirect3DSurface9 *)0x0) {
            pIVar8 = SurfaceFindOrAdd(this,(CVisionViewportDx9 *)0x2,(ESurface)&local_30,
                                      *(GmNat2 **)(pIVar12 + 0x14),0,
                                      (_D3DMULTISAMPLE_TYPE)in_stack_ffffff88);
            local_34 = pIVar8;
            CMwProfiler::GetTimeStamp(&local_40);
            in_stack_ffffff88 = pIVar8;
            iVar6 = (**(code **)(**(int **)(local_4c + 0x9f8) + 0x80))
                              (*(int **)(local_4c + 0x9f8),pIVar7);
            if (iVar6 < 0) {
              (**(code **)(*(int *)pIVar7 + 0x30))(pIVar7,auStack_14);
            }
            CMwProfiler::GetTimeStamp((int64 *)&local_28);
            uVar4 = CMwProfiler::GetTimeFromDeltaTimeStamp
                              (CONCAT44(pIStack_24 + (-(uint)(local_28 < local_4c) - (int)local_48),
                                        (int)local_28 - (int)local_4c));
            if (DAT_00d77b70 < uVar4) {
              DAT_00d77b70 = uVar4;
            }
            CMwProfiler::GetTimeStamp((int64 *)&local_4c);
            piVar16 = &local_30;
            pCVar15 = (CMwCmdScriptVarBool *)pIVar8;
            iVar6 = (**(code **)(*(int *)pIVar8 + 0x34))(pIVar8,piVar16,0,0x4010);
            CMwProfiler::GetTimeStamp((int64 *)&local_38);
            uVar4 = CMwProfiler::GetTimeFromDeltaTimeStamp
                              (CONCAT44(local_34 + (-(uint)(local_38 < local_5c) - local_58),
                                        (int)local_38 - (int)local_5c));
            if (DAT_00d77b6c < uVar4) {
              DAT_00d77b6c = uVar4;
            }
            while (iVar6 == -0x7789fde4) {
              iVar6 = (**(code **)(*(int *)pIVar8 + 0x34))(pIVar8,&local_40,0,0x10);
            }
            local_34 = local_44 + -2;
            in_stack_ffffff94 = (CMwCmdScriptVarBool *)0x0;
            local_5c = local_40._4_4_;
            if (in_stack_ffffff88 != (IDirect3DSurface9 *)0x0) {
              pIVar7 = (IDirect3DSurface9 *)0x0;
              do {
                pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)in_stack_ffffff94;
                pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   (in_stack_ffffff8c,
                                    (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                    in_stack_ffffff94,(ulong)pCVar15);
                pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)in_stack_ffffff94;
                if (((*(uint *)(*(int *)(*(int *)pSVar5 + 0x48) + 0x1c) & 0x8000) != 0) &&
                   ((*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)pSVar5 + 0x48) + 0x14) + 100) +
                              0x9c) & 8) != 0)) {
                  local_5c = (IDirect3DSurface9 *)
                             CFastBuffer<class_GxColor>::operator[]
                                       (pCVar14,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                                in_stack_ffffff94,(ulong)piVar16);
                  uVar10 = 0;
                  do {
                    uVar13 = 0;
                    pIVar12 = local_5c + uVar10 * -8 + 8;
                    do {
                      puVar9 = (uint *)((int)(pIVar7 + uVar13) * local_58 +
                                       (int)local_38 * (iStack_2c + uVar10) + iStack_54);
                      if (*(int *)(local_4c + 0xb4) == 0) {
                        uVar2 = *puVar9;
                        in_stack_ffffff88 =
                             (IDirect3DSurface9 *)
                             (((float)(uVar2 >> 0x10 & 0xff) * (float)_DAT_00b3d080 * _DAT_00d6e7d4
                              + _DAT_00d6e7e0) * (float)_DAT_00b5b8e0 +
                             (float)_DAT_00b3d080 * (float)(uVar2 >> 8 & 0xff) * _DAT_00d6e7d8 +
                             _DAT_00d6e7dc);
                        if ((float)in_stack_ffffff88 < 0.0 == ((float)in_stack_ffffff88 == 0.0)) {
                          if (!NAN((float)in_stack_ffffff88) &&
                              1.0 < (float)in_stack_ffffff88 != ((float)in_stack_ffffff88 == 1.0)) {
                            in_stack_ffffff88 = (IDirect3DSurface9 *)0x3f800000;
                          }
                        }
                        else {
                          in_stack_ffffff88 = (IDirect3DSurface9 *)0x0;
                        }
                        in_stack_ffffff94 = (CMwCmdScriptVarBool *)&local_28;
                        piVar16 = (int *)0x3f800000;
                        local_28 = in_stack_ffffff88;
                        pIStack_24 = in_stack_ffffff88;
                        pIStack_20 = in_stack_ffffff88;
                        GxBGRAColor::Set(pIVar12,in_stack_ffffff94,0x3f800000);
                      }
                      else {
                        *(uint *)pIVar12 = *puVar9;
                        in_stack_ffffff88 = pIVar7;
                      }
                      uVar13 = uVar13 + 1;
                      pIVar12 = pIVar12 + 4;
                    } while (uVar13 < 2);
                    uVar10 = uVar10 + 1;
                    pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)this;
                    pIVar8 = local_48;
                    pIVar12 = local_44;
                    pCVar15 = in_stack_ffffff94;
                  } while (uVar10 < 2);
                }
                pIVar7 = pIVar7 + 2;
                if (local_48 <= pIVar7) {
                  pIVar7 = (IDirect3DSurface9 *)0x0;
                  local_34 = local_34 + -2;
                }
                in_stack_ffffff94 = (CMwCmdScriptVarBool *)(pCVar11 + 1);
              } while (in_stack_ffffff94 < in_stack_ffffff88);
            }
            (**(code **)(*(int *)pIVar8 + 0x38))(pIVar8);
            this = pCStack_50;
          }
          pIVar7 = CDx9TextureKeeper::RtWheelToCpuGetToWrite
                             (pIVar12,(CDx9TextureKeeper *)in_stack_ffffff88);
          RenderTargetSet(this,(CVisionViewportDx9 *)pIVar7,(IDirect3DSurface9 *)0x0,
                          (IDirect3DSurface9 *)0x0,(CDx9TextureKeeper *)0x0,(CDx9TextureKeeper *)0x0
                          ,in_stack_ffffff8c);
          TextureBlitOnFullQuad(this,in_stack_00000020,pCVar3);
          CDx9TextureKeeper::RtWheelToCpusIssueQuery(pIVar12,(CDx9TextureKeeper *)in_stack_ffffff94)
          ;
        }
      }
    }
  }
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::TexRender_RasterizeLensFlares
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CVisionViewportDx9::TexRender_RasterizeLensFlares
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CHmsZone *param_2,GmMat4 *param_3,
          float param_4)
{
{
  CVisionViewportDx9 *pCVar1;
  int iVar2;
  float fVar3;
  ulong uVar4;
  SCasterCat *pSVar5;
  SNewTriangleVert *pSVar6;
  int iVar7;
  void *this_00;
  int unaff_EBX;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_EBP;
  CVisionViewportDx9 *this_01;
  ulong unaff_ESI;
  ulong unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  float10 fVar9;
  float unaff_retaddr;
  undefined4 in_stack_00000014;
  float in_stack_00000018;
  GmIso3 *in_stack_0000001c;
  ulong in_stack_ffffff54;
  GmVec3 *pGVar10;
  GmIso3 *in_stack_ffffff58;
  GmIso3 *pGVar11;
  CDx9StateBlock *in_stack_ffffff5c;
  float fStack_94;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_90;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_8c;
  float local_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  CVisionViewportDx9 *local_40;
  float fStack_3c;
  undefined4 uStack_38;
  ulong uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  CVisionViewportDx9 *local_28;
  float fStack_24;
  float local_20;
  float local_1c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_18;
  float fStack_14;
  float fStack_10;
  undefined4 uStack_c;
  float fStack_8;
  float fStack_4;
  
  this_01 = param_1 + 0x58;
  local_40 = this;
  pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                     (this_01,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,unaff_EDI);
  iVar2 = *(int *)(pSVar5 + 4);
  pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                     (this_01,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000005,
                      unaff_ESI);
  local_28 = *(CVisionViewportDx9 **)(pSVar5 + 4);
  pCVar1 = local_28 + iVar2;
  if (pCVar1 != (CVisionViewportDx9 *)0x0) {
    pSVar6 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem(this + 0x454,unaff_EBP);
    local_20 = ABS(*(float *)(pSVar6 + 0x40)) * (float)_DAT_00b3d2c8 + (float)_DAT_00b2c188;
    local_1c = (float)_DAT_00bd45e8 / in_stack_00000018;
    RasterizeQuadAlloc(this,pCVar1,1,unaff_EBX);
    CFastBufferCat<class_CPlugTree*,struct_SFastCat>::SetParsingCat
              (this_01,(CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *)0x3,1,
               in_stack_ffffff54);
    pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (local_8c != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar5 = CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat>::operator[]
                           (this_01,pCVar8,(ulong)in_stack_ffffff58);
        iVar2 = *(int *)((*(int **)pSVar5)[0x12] + 0x88);
        if ((*(byte *)(iVar2 + 0x14) & 8) != 0) {
          in_stack_ffffff58 = (GmIso3 *)0x991364;
          iVar7 = (**(code **)(**(int **)pSVar5 + 0x78))();
          fStack_58 = *(float *)(iVar7 + 0x24) - *(float *)(pSVar6 + 0x54);
          fStack_54 = *(float *)(iVar7 + 0x28) - *(float *)(pSVar6 + 0x58);
          fStack_50 = *(float *)(iVar7 + 0x2c) - *(float *)(pSVar6 + 0x5c);
          pCStack_90 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                       (fStack_50 * fStack_50 + fStack_54 * fStack_54 + fStack_58 * fStack_58);
          fStack_94 = *(float *)(iVar2 + 0x74);
          fStack_68 = fStack_94 * fStack_94;
          if ((float)pCStack_90 <= fStack_68) {
            fStack_78 = *(float *)(iVar7 + 0x24);
            fStack_74 = *(float *)(iVar7 + 0x28);
            fStack_70 = *(float *)(iVar7 + 0x2c);
            fStack_6c = 1.0;
            GmVec4::Mult(&fStack_78,in_stack_0000001c,in_stack_ffffff58);
            local_8c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                       (1.0 - (float)local_8c / fStack_64);
            if ((float)local_8c < 0.0 == ((float)local_8c == 0.0)) {
              if (!NAN((float)local_8c) && 1.0 < (float)local_8c != ((float)local_8c == 1.0)) {
                local_8c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3f800000;
              }
            }
            else {
              local_8c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
            }
            fVar3 = 1.0 / fStack_68;
            fStack_84 = fVar3 * (fStack_74 - fStack_10);
            fStack_80 = (fStack_70 - fStack_10 * fStack_14) * fVar3;
            fStack_7c = (fStack_10 + fStack_74) * fVar3;
            fStack_78 = (fStack_10 + fStack_70) * fVar3;
            fStack_6c = fVar3 * fStack_6c;
            pCStack_90 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar2 + 0x24);
            fStack_60 = (float)pCStack_90 * *(float *)(iVar2 + 0x18);
            fStack_5c = *(float *)(iVar2 + 0x1c) * (float)pCStack_90;
            fStack_58 = (float)pCStack_90 * *(float *)(iVar2 + 0x20);
            fStack_24 = (float)local_8c * fStack_60;
            local_20 = fStack_5c * (float)local_8c;
            local_1c = (float)local_8c * fStack_58;
            uStack_30 = 0x3f800000;
            uStack_2c = 0x3f800000;
            local_40 = (CVisionViewportDx9 *)0x3f800000;
            uStack_38 = 0;
            uStack_34 = 0;
            fStack_48 = 0.0;
            fStack_44 = 0.0;
            fStack_3c = 1.0;
            GxBGRAColor::Set(&fStack_94,(CMwCmdScriptVarBool *)&fStack_24,_DAT_00b5e844);
            in_stack_ffffff58 = (GmIso3 *)&fStack_48;
            RasterizeQuadAdd(local_28,fStack_94,&fStack_84,fStack_6c,fStack_68,in_stack_ffffff58);
          }
        }
        pCVar8 = pCVar8 + 1;
      } while (pCVar8 < local_8c);
    }
    CFastBufferCat<class_CPlugTree*,struct_SFastCat>::SetParsingCat
              (this_01,(CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *)
                       &DAT_00000005,1,(ulong)in_stack_ffffff58);
    pCStack_90 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCStack_18 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pGVar10 = (GmVec3 *)0x9915bc;
        pSVar5 = CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat>::operator[]
                           (this_01,pCStack_90,(ulong)in_stack_ffffff5c);
        iVar2 = *(int *)((*(int **)pSVar5)[0x12] + 0x88);
        if ((*(byte *)(iVar2 + 0x14) & 8) != 0) {
          in_stack_ffffff5c = (CDx9StateBlock *)0x9915d8;
          this_00 = (void *)(**(code **)(**(int **)pSVar5 + 0x78))();
          fStack_60 = *(float *)(pSVar6 + 0x54) - *(float *)((int)this_00 + 0x24);
          fStack_5c = *(float *)(pSVar6 + 0x58) - *(float *)((int)this_00 + 0x28);
          fStack_58 = *(float *)(pSVar6 + 0x5c) - *(float *)((int)this_00 + 0x2c);
          fStack_94 = fStack_58 * fStack_58 + fStack_5c * fStack_5c + fStack_60 * fStack_60;
          local_88 = fStack_94;
          fStack_54 = fStack_60;
          fStack_50 = fStack_5c;
          fStack_4c = fStack_58;
          if (_DAT_00d38fe4 < fStack_94) {
            pGVar11 = (GmIso3 *)0x991654;
            fVar9 = (float10)func_0x009c1b40();
            fVar3 = 1.0 / (float)fVar9;
            fStack_68 = fVar3 * fStack_5c;
            fStack_64 = fStack_64 * fVar3;
            fStack_60 = fVar3 * fStack_60;
            GmMat3::GetLine(this_00,(GmMat3 *)0x2,(ulong)&uStack_c,pGVar10);
            if ((*(float *)(iVar2 + 0xb0) <=
                 unaff_retaddr * fStack_5c + fStack_4 * fStack_60 + fStack_8 * fStack_64) &&
               (fStack_68 = *(float *)(iVar2 + 0x74) * *(float *)(iVar2 + 0x74),
               (float)local_8c <= fStack_68)) {
              fStack_4c = *(float *)((int)this_00 + 0x24);
              fStack_48 = *(float *)((int)this_00 + 0x28);
              fStack_44 = *(float *)((int)this_00 + 0x2c);
              local_40 = (CVisionViewportDx9 *)0x3f800000;
              GmVec4::Mult(&fStack_4c,in_stack_0000001c,pGVar11);
              local_8c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                         (1.0 - local_88 / fStack_64);
              if ((float)local_8c < 0.0 == ((float)local_8c == 0.0)) {
                if (!NAN((float)local_8c) && 1.0 < (float)local_8c != ((float)local_8c == 1.0)) {
                  local_8c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3f800000;
                }
              }
              else {
                local_8c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
              }
              fVar3 = 1.0 / fStack_3c;
              fStack_74 = fVar3 * (fStack_48 - fStack_10);
              fStack_70 = (fStack_44 - fStack_10 * fStack_14) * fVar3;
              fStack_6c = (fStack_10 + fStack_48) * fVar3;
              fStack_68 = (fStack_10 + fStack_44) * fVar3;
              local_40 = (CVisionViewportDx9 *)(fVar3 * (float)local_40);
              fStack_94 = *(float *)(iVar2 + 0x24);
              fStack_24 = fStack_94 * *(float *)(iVar2 + 0x18);
              local_20 = *(float *)(iVar2 + 0x1c) * fStack_94;
              local_1c = fStack_94 * *(float *)(iVar2 + 0x20);
              fStack_84 = (float)local_8c * fStack_24;
              fStack_80 = local_20 * (float)local_8c;
              fStack_7c = (float)local_8c * local_1c;
              uStack_c = 0x3f800000;
              fStack_8 = 1.0;
              param_4 = 1.0;
              uStack_30 = 0;
              uStack_2c = 0;
              param_2 = (CHmsZone *)0x0;
              param_3 = (GmMat4 *)0x0;
              in_stack_00000014 = 0x3f800000;
              GxBGRAColor::Set(&uStack_38,(CMwCmdScriptVarBool *)&fStack_84,_DAT_00b5e844);
              RasterizeQuadAdd(local_28,uStack_38,&fStack_74,local_40,fStack_3c,&param_2);
            }
          }
        }
        pCStack_90 = pCStack_90 + 1;
      } while (pCStack_90 < pCStack_18);
    }
    uVar4 = DAT_00d769fc;
    CDx9StateBlock::FilterRenderState(7,0);
    _DAT_00d75f4c = 1;
    if (DAT_00d75c3c != 0) {
      CDx9StateBlock::PackRenderState(7,0,(SPackedDesc *)&fStack_84);
      *(uint *)(&DAT_00d76ed8 + (int)fStack_84 * 4) =
           *(uint *)(&DAT_00d76ed8 + (int)fStack_84 * 4) & ~(uint)fStack_7c;
    }
    uStack_38 = DAT_00d76c40;
    CDx9StateBlock::FilterRenderState(0x98,0);
    _DAT_00d76190 = 1;
    if (DAT_00d75e80 != 0) {
      CDx9StateBlock::PackRenderState(0x98,0,(SPackedDesc *)&fStack_84);
      *(uint *)(&DAT_00d76ed8 + (int)fStack_84 * 4) =
           *(uint *)(&DAT_00d76ed8 + (int)fStack_84 * 4) & ~(uint)fStack_7c;
    }
    pCVar1 = local_28;
    iVar2 = *(int *)(local_28 + 0x1514);
    if (*(int *)(iVar2 + 0x14) == 0) {
      (**(code **)(*(int *)local_28 + 0xb0))(iVar2);
    }
    iVar2 = *(int *)(iVar2 + 0x14);
    if (DAT_00d756a8 != iVar2) {
      (**(code **)(*DAT_00d75698 + 0x104))(DAT_00d75698,0,*(undefined4 *)(iVar2 + 0xc));
      DAT_00d756a8 = iVar2;
    }
    RasterizeQuads(pCVar1,pCVar1 + 0xf74,in_stack_ffffff5c);
    _DAT_00d75f4c = 0;
    if (DAT_00d75c3c != 0) {
      CDx9StateBlock::PackRenderState(7,0xffffffff,(SPackedDesc *)&fStack_80);
      *(uint *)(&DAT_00d76ed8 + (int)fStack_80 * 4) =
           *(uint *)(&DAT_00d76ed8 + (int)fStack_80 * 4) | (uint)fStack_78;
    }
    CDx9StateBlock::FilterRenderState(7,uVar4);
    _DAT_00d76190 = 0;
    if (DAT_00d75e80 != 0) {
      CDx9StateBlock::PackRenderState(0x98,0xffffffff,(SPackedDesc *)&fStack_80);
      *(uint *)(&DAT_00d76ed8 + (int)fStack_80 * 4) =
           *(uint *)(&DAT_00d76ed8 + (int)fStack_80 * 4) | (uint)fStack_78;
    }
    CDx9StateBlock::FilterRenderState(0x98,uStack_34);
  }
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::TexRender_RenderTexture
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CVisionViewportDx9::TexRender_RenderTexture
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2,
          CPlugBitmapRender *param_3,CFixedArray<class_CPlugBitmap*,4,unsigned_long> *param_4)
{
{
  CDx9ShaderKeeper *this_00;
  CHmsCamera *pCVar1;
  CHmsCorpusLight *this_01;
  float fVar2;
  float fVar3;
  float fVar4;
  CMwId CVar5;
  GmVec3 GVar6;
  CFastArray<class_GxTexCoordSet> *pCVar7;
  int iVar8;
  float fVar9;
  CSystemConfigDisplay *this_02;
  int iVar10;
  SPlugFaceCull *pSVar11;
  undefined4 uVar12;
  ulong uVar13;
  SCasterCat *pSVar14;
  SSamplerState *pSVar15;
  SCasterCat *pSVar16;
  GmMat2 *pGVar17;
  SCasterCat *pSVar18;
  GmVec3 *pGVar19;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  CMwNodRef<class_CGameCamera> *extraout_EAX;
  CMwNodRef<class_CGameCamera> *pCVar20;
  CMwNodRef<class_CGameCamera> *extraout_EAX_00;
  CPlugBitmapRenderCamera *pCVar21;
  CPlugShaderApply *pCVar22;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar23;
  CVisionShaderKeeper *pCVar24;
  SPlugFaceCull *pSVar25;
  undefined3 extraout_var_01;
  SNewTriangleVert *pSVar26;
  uint uVar27;
  CVisionViewportDx9 *pCVar28;
  void *unaff_EBX;
  SPlugFaceCull *unaff_EBP;
  IDirect3DSurface9 *unaff_ESI;
  CVisionViewportDx9 *pCVar29;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar30;
  CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *pCVar31;
  uint uVar32;
  CVisionShaderKeeper *unaff_EDI;
  undefined4 *puVar33;
  GmIso4 *this_03;
  CPlugBitmapRenderCamera *pCVar34;
  bool bVar35;
  GmFrustum *pGVar36;
  ulong in_stack_fffffcbc;
  ulong in_stack_fffffcc0;
  SHmsCameraLocation *in_stack_fffffcc4;
  float in_stack_fffffcc8;
  CPlugShader *in_stack_fffffccc;
  CPlugShader *in_stack_fffffcd0;
  CFastBuffer<class_CCrystalFace*> *pCVar37;
  code *in_stack_fffffcd8;
  IDirect3DSurface9 *in_stack_fffffcdc;
  CFastArray<class_GxTexCoordSet> *pCVar38;
  CFastArray<class_GxTexCoordSet> *in_stack_fffffce0;
  CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *in_stack_fffffce4;
  EGxTexFilter *in_stack_fffffce8;
  CFastBuffer<struct_CDx9StateBlock::STexStageState> *in_stack_fffffcec;
  int *piVar39;
  GmVec4 *pGVar40;
  CVisionShaderKeeper *pCVar41;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffcf0;
  ulong *puVar42;
  CPlugTree *pCVar43;
  GmIso4 *pGVar44;
  CFastBuffer<class_CCrystalFace*> *pCVar45;
  SPlugFaceCull *pSVar46;
  ulong uVar47;
  CPlugShader *pCVar48;
  GmFrustum *pGVar49;
  CVisionViewportDx9 *pCVar50;
  CDx9TextureKeeper *pCVar51;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *pCVar52;
  CPlugTree *pCVar53;
  GmBoxAligned *in_stack_fffffd14;
  GmScaleTrans2 *pGVar54;
  GmScaleTrans2 *in_stack_fffffd18;
  GmIso4 *pGVar55;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar56;
  CFastBuffer<struct_CDx9StateBlock::STexStageState> *pCVar57;
  CMwNodRef<class_CGameCamera> *pCVar58;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffd20;
  GmIso3 *pGVar59;
  CPlugBitmapRender *pCVar60;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffd28;
  CHmsItem *pCVar61;
  undefined4 *puVar62;
  CDx9ShaderKeeper *in_stack_fffffd2c;
  SHmsRenderRect *pSVar63;
  CHmsCorpus *pCVar64;
  CMwId *in_stack_fffffd30;
  CHmsViewport *pCVar65;
  CFastStringInt *pCVar66;
  SNewTriangleVert *in_stack_fffffd38;
  CFastStringInt *pCVar67;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffd3c;
  CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *this_04;
  CHmsItem *pCStack_2bc;
  float fStack_2b8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_2b4;
  CVisionViewportDx9 *pCStack_2b0;
  SHmsRenderRect *pSStack_2ac;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_2a8;
  SNewTriangleVert *pSStack_2a4;
  SNewTriangleVert *pSStack_2a0;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_29c;
  CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *pCStack_298;
  SHmsRenderRect *pSStack_294;
  float fStack_290;
  float fStack_28c;
  float fStack_288;
  CHmsCamera *pCStack_284;
  float fStack_280;
  float fStack_27c;
  float fStack_278;
  float fStack_274;
  undefined4 uStack_270;
  CVisionViewportDx9 aCStack_26c [4];
  undefined4 uStack_268;
  undefined4 uStack_264;
  undefined4 uStack_260;
  undefined4 auStack_25c [2];
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_254;
  SHmsRenderRect *pSStack_250;
  float fStack_24c;
  float fStack_248;
  float fStack_244;
  undefined4 uStack_238;
  undefined4 uStack_234;
  undefined4 uStack_230;
  char acStack_22c [4];
  SPlugFaceCull aSStack_228 [12];
  undefined1 auStack_21c [4];
  CMwCmdScriptVarBool aCStack_218 [8];
  undefined1 auStack_210 [4];
  GmFrustum aGStack_20c [12];
  undefined4 uStack_200;
  undefined4 uStack_1fc;
  undefined4 uStack_1f8;
  undefined1 auStack_1ec [8];
  CPlugTree aCStack_1e4 [4];
  CMwCmdScriptVarBool aCStack_1e0 [8];
  SPlugFaceCull aSStack_1d8 [36];
  float fStack_1b4;
  undefined1 auStack_1a8 [4];
  undefined1 auStack_1a4 [28];
  SPlugFaceCull aSStack_188 [4];
  undefined4 uStack_184;
  undefined1 auStack_180 [12];
  SPlugFaceCull aSStack_174 [28];
  CPlugTree aCStack_158 [4];
  undefined4 auStack_154 [11];
  undefined4 auStack_128 [4];
  SPlugFaceCull aSStack_118 [52];
  GmIso4 aGStack_e4 [4];
  SPlugFaceCull aSStack_e0 [52];
  undefined1 auStack_ac [4];
  GmIso3 aGStack_a8 [20];
  undefined1 auStack_94 [4];
  GmIso3 aGStack_90 [44];
  undefined1 auStack_64 [4];
  undefined1 auStack_60 [4];
  float fStack_5c;
  float fStack_58;
  int iStack_54;
  int iStack_50;
  SPlugFaceCull aSStack_4c [28];
  undefined1 auStack_30 [4];
  CMwId aCStack_2c [12];
  float fStack_20;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00aeb1ad;
  local_c = ExceptionList;
  local_10 = (void *)(DAT_00cca150 ^ (uint)&stack0xfffffd10);
  pCVar7 = (CFastArray<class_GxTexCoordSet> *)(DAT_00cca150 ^ (uint)&stack0xfffffd00);
  ExceptionList = &local_c;
  pCVar28 = param_1;
  iVar8 = (**(code **)(*(int *)this + 0xb4))(param_1);
  if (iVar8 == 0) {
    ExceptionList = local_10;
    return 0;
  }
  pCVar51 = *(CDx9TextureKeeper **)(param_1 + 0x14);
  if (param_2 == (CPlugBitmap *)0x0) {
    param_2 = *(CPlugBitmap **)(param_1 + 0x74);
  }
  pSVar46 = (SPlugFaceCull *)0x996f95;
  this_04 = (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)pCVar51;
  fVar9 = (float)(**(code **)(*(int *)param_2 + 0x78))();
  pCVar50 = (CVisionViewportDx9 *)0x0;
  fStack_2b8 = fVar9;
  if ((_DAT_00d77c18 & 1) == 0) {
    _DAT_00d77c18 = _DAT_00d77c18 | 1;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (&DAT_00d77c0c,(CFastBuffer<class_CPlugFileSndGen*> *)in_stack_fffffcd8);
    in_stack_fffffcd8 =
         `protected:_int___thiscall_CVisionViewportDx9::
         TexRender_RenderTexture(class_CPlugBitmap*,class_CPlugBitmapRender*,class_CFixedArray<class_CPlugBitmap*,4,unsigned_long>_const*)'
         ::__l5::_dynamic_atexit_destructor_for__RWater_CameraIsBelowPlanes__;
    _atexit(`protected:_int___thiscall_CVisionViewportDx9::
            TexRender_RenderTexture(class_CPlugBitmap*,class_CPlugBitmapRender*,class_CFixedArray<class_CPlugBitmap*,4,unsigned_long>_const*)'
            ::__l5::_dynamic_atexit_destructor_for__RWater_CameraIsBelowPlanes__);
  }
  pCVar37 = (CFastBuffer<class_CCrystalFace*> *)0x996fd4;
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
            (&DAT_00d77c0c,(GmFrustumIso4 *)in_stack_fffffcd8);
  if (fVar9 == 5.60519e-45) {
    uVar27 = *(uint *)(param_2 + 0x14) >> 3 & 1;
    if ((((byte)*(CPlugBitmapRender *)(param_2 + 0xb0) & 3) != 0) && (*(int *)(param_2 + 0x5c) != 0)
       ) {
      *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) & 0xff3fffff;
      in_stack_fffffcd8 =
           (code *)StdShaderGet(this,(CVisionViewportDx9 *)&DAT_0000000a,
                                (EStdShader2)in_stack_fffffcdc,(ulong)in_stack_fffffce0);
      unaff_EDI = CVisionViewport::ShaderGetKeeper
                            ((CVisionViewport *)this,(CVisionViewport *)in_stack_fffffcd8,
                             (CPlugShader *)in_stack_fffffce4);
      CDx9ShaderKeeper::SetShaderBitmapNoDirty
                ((CDx9ShaderKeeper *)unaff_EDI,(CDx9ShaderKeeper *)0x0,*(ulong *)(param_2 + 0x5c),
                 (CPlugBitmap *)0x0,(CPlugBitmapSampler *)0x0,in_stack_fffffce8);
      uVar27 = 1;
      in_stack_fffffd28 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1;
      pCVar37 = (CFastBuffer<class_CCrystalFace*> *)0x997055;
      RenderShaderOnFullQuad
                (this,(CVisionViewportDx9 *)in_stack_fffffcd8,(CPlugShader *)param_3,
                 (CPlugBitmap *)0x0,(SGxPixRect *)0x0,(CPlugVisual *)&stack0xfffffd28,
                 (SRenderShaderParam *)in_stack_fffffcec);
      in_stack_fffffce4 =
           *(CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> **)(this + 0x151c);
      in_stack_fffffcec = (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)0x0;
      in_stack_fffffce0 = (CFastArray<class_GxTexCoordSet> *)0x0;
      in_stack_fffffcdc = (IDirect3DSurface9 *)0x99706b;
      CDx9ShaderKeeper::SetShaderBitmapNoDirty
                ((CDx9ShaderKeeper *)unaff_EBP,(CDx9ShaderKeeper *)0x0,(ulong)in_stack_fffffce4,
                 (CPlugBitmap *)0x0,(CPlugBitmapSampler *)0x0,(EGxTexFilter *)in_stack_fffffcf0);
      if (((byte)*(uint *)(param_2 + 0xb0) & 3) == 1) {
        *(uint *)(param_2 + 0xb0) = *(uint *)(param_2 + 0xb0) & 0xfffffffc;
      }
    }
    if ((((byte)*(CPlugBitmapRender *)(param_2 + 0xb0) & 0xc) != 0) &&
       (pCVar29 = *(CVisionViewportDx9 **)(param_2 + 0x60), pCVar29 != (CVisionViewportDx9 *)0x0)) {
      *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) & 0xff3fffff;
      pSVar46 = (SPlugFaceCull *)&stack0xfffffd34;
      pCVar28 = (CVisionViewportDx9 *)(*(uint *)(param_2 + 0x18) >> 7 & 2 ^ uVar27 | 1);
      in_stack_fffffcf0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      in_stack_fffffcec = (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)0x0;
      in_stack_fffffce0 = (CFastArray<class_GxTexCoordSet> *)0x9970cd;
      RenderShaderOnFullQuad
                (this,pCVar29,(CPlugShader *)in_stack_fffffd30,(CPlugBitmap *)0x0,(SGxPixRect *)0x0,
                 (CPlugVisual *)pSVar46,(SRenderShaderParam *)pCVar50);
      in_stack_fffffce4 =
           (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)pCVar29;
      if (((byte)*(uint *)(param_2 + 0xb0) & 0xc) == 4) {
        *(uint *)(param_2 + 0xb0) = *(uint *)(param_2 + 0xb0) & 0xfffffff3;
      }
    }
  }
  else if (fVar9 == 1.26117e-44) {
    *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x10;
  }
  else if (fVar9 == 2.8026e-45) {
    piVar39 = *(int **)(pCVar51 + 0x3c);
    if ((piVar39 != (int *)0x0) && (iVar8 = piVar39[5], iVar8 != 0)) {
      if ((7 < *(uint *)(this + 0x2b8)) &&
         (((byte)*(CPlugBitmapRender *)(param_2 + 0xc4) & 0x40) != 0)) {
        in_stack_fffffcd8 = (code *)0x997139;
        uVar13 = CFastBuffer<class_CCrystalFace*>::GetCount
                           ((void *)(iVar8 + 0xdc),(CFastBuffer<class_CCrystalFace*> *)pCVar50);
        if (uVar13 != 0) {
          iVar10 = *(int *)(this + 0x24c);
          if (*(int *)(iVar10 + 0x20) == 0) {
            this_02 = *(CSystemConfigDisplay **)(iVar10 + 0x24);
          }
          else {
            this_02 = *(CSystemConfigDisplay **)(iVar10 + 0x28);
          }
          in_stack_fffffcdc = (IDirect3DSurface9 *)0x997158;
          iVar10 = CSystemConfigDisplay::WaterGeom
                             (this_02,(CSystemConfigDisplay *)in_stack_fffffce0);
          if (iVar10 != 0) {
            unaff_ESI = (IDirect3DSurface9 *)(iVar8 + 0xdc);
          }
        }
      }
      if (((piVar39[0x70] == 0) || (((byte)*(CPlugBitmapRender *)(param_2 + 0xc4) & 2) != 0)) &&
         ((*(uint *)(param_2 + 0xc4) & 0x200) == 0)) {
        pSVar46 = (SPlugFaceCull *)0x997195;
        iVar10 = (**(code **)(*piVar39 + 0x78))();
        if (in_stack_fffffd18 == (GmScaleTrans2 *)0x0) {
          fVar9 = *(float *)(iVar10 + 0x28);
          if (*(int *)(iVar8 + 0xbc) != 0) {
            fVar9 = fVar9 - *(float *)(iVar8 + 200);
          }
          if (fVar9 < _DAT_00b41d80) {
            ExceptionList = local_10;
            return 1;
          }
        }
        else {
          pCVar50 = (CVisionViewportDx9 *)
                    CFastBuffer<class_CCrystalFace*>::GetCount
                              ((void *)(iVar8 + 0xdc),(CFastBuffer<class_CCrystalFace*> *)pCVar50);
          pSVar46 = (SPlugFaceCull *)0x9971ba;
          CFastBuffer<class_GmVector2<unsigned_short>_>::AllocSetCount
                    (&DAT_00d77c0c,(CFastBuffer<class_GxVertex2> *)pCVar50,(ulong)pCVar7);
          pCVar30 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
          pCVar57 = (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)0x0;
          pCVar7 = (CFastArray<class_GxTexCoordSet> *)0x9971ca;
          in_stack_fffffd28 =
               (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (&DAT_00d77c0c,(CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
          if (in_stack_fffffd28 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
            ExceptionList = local_10;
            return 1;
          }
          do {
            in_stack_fffffce4 =
                 (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)0x9971dc;
            pSVar14 = CFastBuffer<class_GxColor>::operator[]
                                (unaff_EBX,pCVar30,(ulong)in_stack_fffffcec);
            unaff_ESI = (IDirect3DSurface9 *)
                        (*(float *)(pSVar14 + 8) * *(float *)(unaff_EBP + 0x2c) +
                         *(float *)(unaff_EBP + 0x24) * *(float *)pSVar14 +
                         *(float *)(pSVar14 + 4) * *(float *)(unaff_EBP + 0x28) +
                        *(float *)(pSVar14 + 0xc));
            bVar35 = (float)unaff_ESI < _DAT_00b41d80;
            pSVar14 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                (&DAT_00d77c0c,pCVar30,(ulong)in_stack_fffffcf0);
            *(uint *)pSVar14 = (uint)bVar35;
            in_stack_fffffcec = (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)0x99722e;
            in_stack_fffffcf0 = pCVar30;
            pSVar14 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                (&DAT_00d77c0c,pCVar30,(ulong)pSVar46);
            if (*(int *)pSVar14 != 0) {
              in_stack_fffffd14 = in_stack_fffffd14 + 1;
            }
            pCVar30 = pCVar30 + 1;
          } while (pCVar30 < pCVar57);
          if (pCVar57 <= in_stack_fffffd14) {
            ExceptionList = local_10;
            return 1;
          }
        }
      }
    }
  }
  else if (((fVar9 == 0.0) && (((byte)*(CPlugBitmapRender *)(param_2 + 0x5c) & 0x10) != 0)) &&
          (DAT_00d77c08 == 0)) {
    DAT_00d77c08 = 1;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (&stack0xfffffd3c,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar50);
    pCVar57 = (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)(this + 0x15b0);
    in_stack_fffffcd8 = (code *)0x9972d6;
    fStack_20 = fVar9;
    CFastBuffer<class_CGameFid*>::CopyFromFastBuffer
              (&stack0xfffffd40,pCVar57,
               (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)in_stack_fffffce0);
    in_stack_fffffce0 = (CFastArray<class_GxTexCoordSet> *)&stack0xfffffd1c;
    in_stack_fffffcdc = (IDirect3DSurface9 *)0x9972e2;
    iVar8 = CFastArray<class_CGameMenuFrame*>::Find
                      (pCVar57,in_stack_fffffce0,(GxTexCoordSet *)in_stack_fffffce4);
    if (iVar8 != -1) {
      in_stack_fffffce4 =
           (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)&stack0xfffffd20;
      in_stack_fffffce0 = (CFastArray<class_GxTexCoordSet> *)0x9972f3;
      CFastBuffer<class_CGameCtnBlock*>::Remove(pCVar57,in_stack_fffffce4,(ulong)in_stack_fffffce8);
    }
    uVar12 = *(undefined4 *)(this + 0x41c);
    *(undefined4 *)(this + 0x41c) = 0;
    TexRender_UpdateTextures(this,(CVisionViewportDx9 *)in_stack_fffffcec);
    in_stack_fffffcec = (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)&pCStack_2b0;
    *(undefined4 *)(this + 0x41c) = uVar12;
    CFastBuffer<class_CGameFid*>::CopyFromFastBuffer
              (pCVar57,in_stack_fffffcec,
               (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)in_stack_fffffcf0);
    DAT_00d77c08 = 0;
    local_c = (void *)0xffffffff;
    in_stack_fffffcf0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x99733a;
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (&pSStack_2ac,(CFastBuffer<class_CPlugFileGPUV*> *)pSVar46);
  }
  if (*(CPlugShader *)(in_stack_fffffd30 + 0x4c) == (CPlugShader)0x7) {
    piVar39 = *(int **)(this_04 + 0xc);
    pSVar46 = (SPlugFaceCull *)&stack0xfffffd0c;
    unaff_EBX = (void *)0x0;
    puVar42 = (ulong *)0x0;
    pCVar51 = (CDx9TextureKeeper *)this_04;
    (**(code **)(*piVar39 + 0x48))();
    in_stack_fffffce0 = (CFastArray<class_GxTexCoordSet> *)unaff_ESI;
    in_stack_fffffcdc =
         SurfaceFindOrAdd(this,(CVisionViewportDx9 *)0x0,(ESurface)(this_04 + 0x24),
                          (GmNat2 *)0x4c4c554e,0,(_D3DMULTISAMPLE_TYPE)piVar39);
    in_stack_fffffce4 = (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)0x0;
    in_stack_fffffcd8 = (code *)0x99738c;
    unaff_ESI = (IDirect3DSurface9 *)in_stack_fffffce0;
    in_stack_fffffcf0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)unaff_EBP;
    RenderTargetSet(this,(CVisionViewportDx9 *)in_stack_fffffcdc,
                    (IDirect3DSurface9 *)in_stack_fffffce0,(IDirect3DSurface9 *)0x0,
                    (CDx9TextureKeeper *)this_04,(CDx9TextureKeeper *)0x0,puVar42);
    in_stack_fffffcec = (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)0x997398;
    unaff_EBP = (SPlugFaceCull *)in_stack_fffffcf0;
    (**(code **)(*(int *)in_stack_fffffcf0 + 8))();
    this_04 = (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)pCVar51;
  }
  else {
    in_stack_fffffd14 = (GmBoxAligned *)(*(uint *)(param_2 + 0x14) >> 4 & 1);
    if ((*(uint *)(param_2 + 0x14) & 0x40000000) == 0) {
      in_stack_fffffcec = (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)in_stack_fffffd14;
      if (((*(uint *)(in_stack_fffffd30 + 0x54) >> 4 & 0xf) != 0) && (DAT_00d777a4 != 2)) {
        pCVar29 = this + 0x1cc;
        uVar47 = 0x9974bd;
        uVar13 = CFastBuffer<class_CCrystalFace*>::GetCount
                           (pCVar29,(CFastBuffer<class_CCrystalFace*> *)pCVar50);
        pCVar30 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        in_stack_fffffcec = (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)in_stack_fffffd14;
        if (uVar13 != 0) {
          do {
            pSVar14 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                (pCVar29,pCVar30,(ulong)in_stack_fffffcf0);
            in_stack_fffffcec =
                 (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)in_stack_fffffd14;
            if (in_stack_fffffd18 <= *(GmScaleTrans2 **)pSVar14) {
              if ((in_stack_fffffd18 < *(GmScaleTrans2 **)pSVar14) &&
                 (pCVar30 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0)) {
                pCVar30 = pCVar30 + -1;
              }
              if ((pCVar30 < unaff_EBP) &&
                 (pSVar14 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                      (pCVar29,pCVar30,uVar47),
                 in_stack_fffffcec =
                      (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)in_stack_fffffd14,
                 *(int *)pSVar14 != 0)) {
                pSVar14 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                    (pCVar29,pCVar30,(ulong)pCVar50);
                pCVar51 = *(CDx9TextureKeeper **)pSVar14;
                in_stack_fffffcec = (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)0x0;
                pSVar46 = (SPlugFaceCull *)
                          SurfaceFindOrAdd(this,(CVisionViewportDx9 *)0x0,
                                           (ESurface)(pCStack_2bc + 0x24),
                                           *(GmNat2 **)(pCStack_2bc + 0x14),(_D3DFORMAT)pCVar51,
                                           (_D3DMULTISAMPLE_TYPE)pCVar7);
                if (pSVar46 == (SPlugFaceCull *)0x0) {
                  ExceptionList = local_10;
                  return 0;
                }
                if (((byte)pCStack_2bc[0x20] & 8) != 0) {
                  CDx9TextureKeeper::AutoGenMipMapGetSurface0(pCStack_2bc,pCVar51);
                }
                unaff_EDI = (CVisionShaderKeeper *)0x0;
                pCVar7 = (CFastArray<class_GxTexCoordSet> *)0x0;
                pSVar14 = CFastBuffer<struct_CVisionViewportDx9::SRenderTarget>::operator[]
                                    (this + 0x9fc,
                                     (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                     (ulong)pCStack_2bc);
                pCVar50 = *(CVisionViewportDx9 **)(pSVar14 + 0x14);
                in_stack_fffffcf0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x997579;
                iVar8 = RenderTargetSet(this,(CVisionViewportDx9 *)pSVar46,
                                        (IDirect3DSurface9 *)pCVar50,(IDirect3DSurface9 *)pCVar7,
                                        (CDx9TextureKeeper *)unaff_EDI,
                                        (CDx9TextureKeeper *)unaff_ESI,(ulong *)unaff_EBP);
                if (iVar8 == 0) {
                  ExceptionList = local_10;
                  return 0;
                }
                goto LAB_00997398;
              }
              break;
            }
            pCVar30 = pCVar30 + 1;
          } while (pCVar30 < unaff_EBP);
        }
      }
      in_stack_fffffce4 = this_04;
      pSVar46 = (SPlugFaceCull *)0x0;
      in_stack_fffffcf0 =
           (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           (*(uint *)(in_stack_fffffce4 + 0x20) >> 3 & 1);
      in_stack_fffffce0 = (CFastArray<class_GxTexCoordSet> *)0x9974ff;
      in_stack_fffffd14 = (GmBoxAligned *)in_stack_fffffcec;
      this_04 = in_stack_fffffce4;
      iVar8 = func_0x009b4e70(in_stack_fffffce4,0);
      if (iVar8 == 0) {
        ExceptionList = local_10;
        return 0;
      }
    }
  }
LAB_00997398:
  if (in_stack_fffffd20 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    pCVar29 = (CVisionViewportDx9 *)0x0;
    do {
      iVar8 = *(int *)(in_stack_fffffd20 + (int)pCVar29 * 4);
      if (pCVar29 != (CVisionViewportDx9 *)0x0) {
        if (iVar8 == 0) break;
        if (*(int *)(iVar8 + 0x14) == 0) {
          (**(code **)(*(int *)this + 0xb0))(iVar8);
        }
        pSVar46 = *(SPlugFaceCull **)(iVar8 + 0x14);
        if (pSVar46 == (SPlugFaceCull *)0x0) {
          ExceptionList = local_10;
          return 0;
        }
        in_stack_fffffcec = (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)0x9973d8;
        in_stack_fffffcf0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar29;
        RenderTargetExtraMrtSet(this,pCVar29,(ulong)pSVar46,(CDx9TextureKeeper *)pCVar50);
      }
      pCVar29 = pCVar29 + 1;
    } while (pCVar29 < (CVisionViewportDx9 *)&DAT_00000004);
  }
  pSVar11 = (SPlugFaceCull *)(*(uint *)(param_2 + 0x14) >> 7 & 0xf);
  pSVar25 = pSVar11;
  if ((pSVar11 != (SPlugFaceCull *)&DAT_0000000f) && ((DAT_00d77548 & 0x80) != 0)) {
    in_stack_fffffcf0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xa8;
    in_stack_fffffcec = (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)0x997406;
    CDx9StateBlock::FilterRenderState(0xa8,(ulong)pSVar11);
    pSVar46 = pSVar11;
  }
  *(uint *)(this + 0x414) = *(uint *)(this + 0x414) | 0x40;
  *(CMwId **)(this + 0x448) = in_stack_fffffd30;
  *(undefined4 *)(this + 0x44c) = 0;
  *(CPlugBitmap **)(this + 0x420) = param_2;
  uVar27 = (*(uint *)(param_2 + 0x14) >> 2 ^ *(uint *)(this + 0x414)) & 2 ^ *(uint *)(this + 0x414);
  *(uint *)(this + 0x414) = uVar27;
  *(uint *)(this + 0x414) = (*(uint *)(param_2 + 0x14) >> 0x11 ^ uVar27) & 0x80 ^ uVar27;
  if (((*(uint *)(param_2 + 0x14) & 0x2000000) == 0) || (*(int *)(this + 0x248) == 0)) {
    uVar12 = 0;
  }
  else {
    uVar12 = 1;
  }
  *(undefined4 *)(this + 0x424) = uVar12;
  if (((*(uint *)(param_2 + 0x14) & 0x4000000) == 0) || (*(int *)(this + 0x6c) == 0)) {
    uVar12 = 0;
  }
  else {
    uVar12 = 1;
  }
  *(undefined4 *)(this + 0x428) = uVar12;
  *(uint *)(this + 0x42c) = *(uint *)(param_2 + 0x14) >> 0x1c & 1;
  if ((*(ushort *)(param_2 + 0x20) == 0) ||
     ((*(ushort *)(param_2 + 0x22) & *(ushort *)(param_2 + 0x20)) == 0)) {
    bVar35 = false;
  }
  else {
    bVar35 = true;
  }
  *(uint *)(this + 0x850) = (uint)!bVar35;
  switch(pCStack_298) {
  case (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)0x0:
  case (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)0x3:
    if (pCStack_298 == (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)0x0) {
      in_stack_fffffd14 = *(GmBoxAligned **)(param_2 + 100);
      pGVar36 = (GmFrustum *)0x0;
      pCVar60 = (CPlugBitmapRender *)param_2;
      if (in_stack_fffffd14 == (GmBoxAligned *)0x0) goto LAB_00997ad7;
    }
    else {
      pCVar60 = (CPlugBitmapRender *)0x0;
      pGVar36 = (GmFrustum *)param_2;
LAB_00997ad7:
      in_stack_fffffd14 = *(GmBoxAligned **)(this_04 + 0x3c);
      if (in_stack_fffffd14 == (GmBoxAligned *)0x0) break;
    }
    pGVar44 = *(GmIso4 **)(in_stack_fffffd14 + 0x14);
    if (pGVar44 != (GmIso4 *)0x0) {
      pGVar55 = pGVar44;
      pCVar29 = (CVisionViewportDx9 *)pCVar60;
      if (pCVar60 != (CPlugBitmapRender *)0x0) {
        uVar27 = *(uint *)(pCVar60 + 0x5c) >> 5 & 7;
        if ((((uVar27 == 1) && (*(int *)(this_04 + 0x50) != 0)) && (*(int *)(this_04 + 0x54) != 0))
           && ((*(int *)(this_04 + 0x40) != 0 &&
               (pCVar53 = *(CPlugTree **)(this_04 + 0x44), pCVar53 != (CPlugTree *)0x0)))) {
          pGVar55 = *(GmIso4 **)(*(int *)(this_04 + 0x44) + 0x90);
          pGVar54 = *(GmScaleTrans2 **)(*(int *)(this_04 + 0x44) + 0x94);
          puVar62 = (undefined4 *)(*(int *)(this_04 + 0x40) + 0x18);
          puVar33 = auStack_128;
          for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
            *puVar33 = *puVar62;
            puVar62 = puVar62 + 1;
            puVar33 = puVar33 + 1;
          }
          pCVar43 = (CPlugTree *)0x1;
          CPlugTree::GetThisToRootTransfo(pCVar53,aCStack_158,(GmIso4 *)0x1,0,(CPlugTree *)pCVar50);
          pCVar30 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_3;
          if ((*(int *)(param_3 + 0x100) != -1) && (*(int *)(param_3 + 0x104) == 0)) {
            iVar8 = (**(code **)(**(int **)(*(int *)(*(int *)(*(int *)(pCStack_2bc + 0x40) + 0x48) +
                                                    0x14) + 100) + 0xb4))
                              ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_3 + 0x100));
            *(int *)(param_3 + 0x104) = iVar8;
            if (iVar8 == 0) {
              *(undefined4 *)(param_3 + 0x100) = 0xffffffff;
            }
          }
          if (*(CPlugTree **)(param_3 + 0x104) == (CPlugTree *)0x0) {
            puVar62 = auStack_154;
            pCVar53 = aCStack_1e4;
            for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
              *(undefined4 *)pCVar53 = *puVar62;
              puVar62 = puVar62 + 1;
              pCVar53 = pCVar53 + 4;
            }
          }
          else {
            pCVar43 = aCStack_1e4;
            CPlugTree::GetThisToRootTransfo
                      (*(CPlugTree **)(param_3 + 0x104),pCVar43,(GmIso4 *)0x1,0,(CPlugTree *)pCVar7)
            ;
          }
          puVar62 = auStack_154;
          puVar33 = &uStack_184;
          for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
            *puVar33 = *puVar62;
            puVar62 = puVar62 + 1;
            puVar33 = puVar33 + 1;
          }
          pGVar49 = (GmFrustum *)0x997c3c;
          GmIso4::NUScaleSetInverse(auStack_94,(GmIso4 *)aCStack_1e4,(GmIso4 *)pCVar7);
          pCVar50 = (CVisionViewportDx9 *)0x997c50;
          GmIso4::Mult(auStack_180,aGStack_90,(GmIso3 *)unaff_EDI);
          pCStack_2a8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)_DAT_00bd3ff4;
          this_03 = pGVar44 + 0x78;
          pSStack_2a4 = _DAT_00bd3ff4;
          pSStack_2a0 = _DAT_00bd3ff4;
          pCVar66 = _DAT_00bbbe90;
          pCVar67 = _DAT_00bbbe90;
          pGVar19 = (GmVec3 *)
                    CFastBuffer<class_CCrystalFace*>::GetCount
                              (this_03,(CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
          pCVar23 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
          if (pGVar19 != (GmVec3 *)0x0) {
            do {
              pSVar14 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                                  (this_03,pCVar23,(ulong)unaff_EBP);
              unaff_EBP = aSStack_174;
              GmVec3::SetMult(&fStack_2b8,(SPlugFaceCull *)pSVar14,unaff_EBP,pGVar55);
              if ((float)pCStack_2b4 < (float)pCStack_29c) {
                pCStack_29c = pCStack_2b4;
              }
              if ((float)pCStack_2b0 < (float)pCStack_298) {
                pCStack_298 = (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)
                              pCStack_2b0;
              }
              if ((float)pSStack_2ac < (float)pSStack_294) {
                pSStack_294 = pSStack_2ac;
              }
              if ((float)in_stack_fffffd3c < (float)pCStack_2b4) {
                in_stack_fffffd3c = pCStack_2b4;
              }
              if ((float)this_04 < (float)pCStack_2b0) {
                this_04 = (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)
                          pCStack_2b0;
              }
              if ((float)pCStack_2bc < (float)pSStack_2ac) {
                pCStack_2bc = (CHmsItem *)pSStack_2ac;
              }
              pCVar23 = pCVar23 + 1;
            } while (pCVar23 < pCVar30);
          }
          pCVar7 = (CFastArray<class_GxTexCoordSet> *)0x997d53;
          GmIso4::SetMult(auStack_1a8,aSStack_1d8,aSStack_118,(GmIso4 *)unaff_EBP);
          unaff_EDI = (CVisionShaderKeeper *)0x997d6c;
          GmIso4::NUGetIso4AndScale(auStack_1a4,aGStack_e4,(GmIso4 *)&pSStack_294,(GmVec3 *)pGVar55)
          ;
          pCVar23 = pCStack_2a8;
          pSVar46 = (SPlugFaceCull *)(pCVar67 + 0x74);
          unaff_ESI = (IDirect3DSurface9 *)0x997d88;
          unaff_EBP = pSVar46;
          GmIso4::SetMult(*(void **)(pCStack_2a8 + 0x50),pSVar46,aSStack_e0,(GmIso4 *)pSVar25);
          fVar9 = (float)pCStack_298 + (float)this_04;
          fVar2 = (float)pSStack_294 + (float)pCStack_2bc;
          fVar3 = fStack_290 + fStack_2b8;
          fVar4 = (float)_DAT_00b313b8;
          this_04 = (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)
                    (((float)this_04 - (float)pCStack_298) * fVar4);
          pCStack_2bc = (CHmsItem *)(((float)pCStack_2bc - (float)pSStack_294) * fVar4);
          fStack_2b8 = fVar4 * (fStack_2b8 - fStack_290);
          pCStack_2b0 = (CVisionViewportDx9 *)(fVar9 * fVar4 * fStack_28c);
          pSStack_2ac = (SHmsRenderRect *)(fVar2 * fVar4 * fStack_288);
          pCStack_2a8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                        ((float)pCStack_284 * fVar3 * fVar4);
          unaff_EBX = (void *)0x997e4f;
          GmIso4::SetInverse(auStack_ac,(GmScaleTrans2 *)pSVar46,pGVar54);
          GmVec3::Mult(&pSStack_2ac,aGStack_a8,(GmIso3 *)pGVar44);
          fStack_2b8 = fStack_2b8 * (float)pCStack_284;
          in_stack_fffffd14 = (GmBoxAligned *)&pCStack_2a8;
          pCStack_2b4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                        ((float)pCStack_2b4 * fStack_280);
          in_stack_fffffd30 = (CMwId *)((float)pCStack_2b0 * fStack_27c);
          pCStack_2b0 = (CVisionViewportDx9 *)
                        ((float)in_stack_fffffd30 * *(float *)(pCStack_2bc + 0xa4));
          pSVar25 = (SPlugFaceCull *)0x997eac;
          GmBoxAligned::SetCenterHalfDiag
                    (auStack_210,in_stack_fffffd14,(GmVec3 *)&fStack_2b8,pGVar19);
          pGVar36 = aGStack_20c;
          pGVar55 = (GmIso4 *)0x997ebc;
          GmFrustum::SetOrtho(*(void **)(pCVar23 + 0x54),pGVar36,(GmBoxAligned *)pCVar60);
          this_00 = *(CDx9ShaderKeeper **)(this_04 + 0x14);
          if (this_00 != (CDx9ShaderKeeper *)0x0) {
            GmIso4::SetInverse(auStack_1ec,*(GmScaleTrans2 **)(pCVar23 + 0x50),
                               (GmScaleTrans2 *)pCVar30);
            pGVar36 = (GmFrustum *)0x997ef4;
            GmVec3::SetMult(acStack_22c,(SPlugFaceCull *)&pCStack_284,aSStack_188,
                            (GmIso4 *)in_stack_fffffd28);
            GmVec3::SetMult(&fStack_280,aSStack_228,(SPlugFaceCull *)aCStack_1e4,
                            (GmIso4 *)in_stack_fffffd2c);
            fStack_1b4 = fStack_1b4 - fStack_274;
            GmMat43::Set(auStack_30,aCStack_1e0,(int)in_stack_fffffd30);
            CVar5 = CMwId::CreateFromLocalName((char *)&uStack_238);
            pCVar60 = (CPlugBitmapRender *)0x997f67;
            CDx9ShaderKeeper::ContextAllSetShaderConstants
                      (this_00,(CDx9ShaderKeeper *)CONCAT31(extraout_var,CVar5),aCStack_2c,
                       (GmVec4 *)0x3,0,(int)pCVar66);
            OnAccessViolation_ConcatToCrashFileName(pCVar67);
            pCStack_2b4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                          (1.0 / (float)pCStack_29c);
            pSStack_2ac = (SHmsRenderRect *)(1.0 / (float)pCStack_298);
            fStack_278 = 1.0 - fStack_288 / (float)pCStack_298;
            fStack_248 = 1.0 - fStack_28c / (float)pCStack_29c;
            auStack_25c[0] = _DAT_00b31460;
            pCStack_254 = pCStack_2b4;
            pSStack_250 = pSStack_2ac;
            fStack_24c = fStack_278;
            GmVec4::Mult(&pCStack_254,(GmIso3 *)auStack_25c,(GmIso3 *)pCVar67);
            pSStack_250 = (SHmsRenderRect *)-(float)pSStack_250;
            fStack_244 = 1.0 - fStack_244;
            CVar5 = CMwId::CreateFromLocalName(acStack_22c);
            in_stack_fffffd2c = (CDx9ShaderKeeper *)CONCAT31(extraout_var_00,CVar5);
            in_stack_fffffd30 = (CMwId *)&pSStack_250;
            in_stack_fffffd28 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x99803d;
            CDx9ShaderKeeper::ContextAllSetShaderConstants
                      (this_00,in_stack_fffffd2c,in_stack_fffffd30,(GmVec4 *)0x1,0,
                       (int)in_stack_fffffd3c);
            OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)this_04);
          }
          pCVar31 = pCStack_298 + 0xfc;
          if (*(int *)pCVar31 == 0) {
            pCStack_284 = operator_new(0x214);
            if (pCStack_284 == (CHmsCamera *)0x0) {
              pCVar20 = (CMwNodRef<class_CGameCamera> *)0x0;
            }
            else {
              CHmsCamera::CHmsCamera(pCStack_284,(CHmsCamera *)this_04);
              pCVar20 = extraout_EAX;
            }
            CMwNodRef<class_CGameCamera>::MwSetNod(pCVar31,pCVar20,(CGameCamera *)this_04);
          }
          pCVar1 = *(CHmsCamera **)pCVar31;
          pCVar28 = (CVisionViewportDx9 *)0x9980bf;
          in_stack_fffffd38 = pSStack_2a0;
          pSStack_2a4 = (SNewTriangleVert *)pCVar1;
          (**(code **)(*(int *)pCVar1 + 0x80))();
          CHmsCamera::ForceLocation(pCVar1,*(CHmsCamera **)(pCVar23 + 0x50),(GmIso4 *)pCVar43);
          CHmsCamera::SetFrustum(pCVar1,*(CHmsCamera **)(pCVar23 + 0x54),pGVar49);
          pCVar29 = (CVisionViewportDx9 *)pCVar60;
        }
        else if (uVar27 == 2) {
          if (*(int *)(pCVar60 + 0xfc) == 0) {
            pCVar28 = operator_new(0x214);
            puStack_8 = (undefined1 *)0x4;
            if (pCVar28 == (CVisionViewportDx9 *)0x0) {
              pCVar20 = (CMwNodRef<class_CGameCamera> *)0x0;
            }
            else {
              CHmsCamera::CHmsCamera((CHmsCamera *)pCVar28,(CHmsCamera *)pCVar50);
              pCVar20 = extraout_EAX_00;
            }
            puStack_8 = (undefined1 *)0xffffffff;
            CMwNodRef<class_CGameCamera>::MwSetNod
                      ((CVisionViewportDx9 *)(pCVar60 + 0xfc),pCVar20,(CGameCamera *)pCVar50);
          }
          pCVar1 = *(CHmsCamera **)(pCVar60 + 0xfc);
          pGVar49 = (GmFrustum *)PTR_DAT_00d38fe8;
          in_stack_fffffd14 = (GmBoxAligned *)pCVar1;
          pGVar55 = pGVar44;
          (**(code **)(*(int *)pCVar1 + 0x80))();
          CHmsCamera::ForceLocation(pCVar1,(CHmsCamera *)(pCVar60 + 0xa8),pGVar44);
          CHmsCamera::SetFrustum(pCVar1,(CHmsCamera *)(pCVar60 + 0xd8),pGVar49);
        }
      }
      pCVar21 = (CPlugBitmapRenderCamera *)(*(uint *)(pGVar55 + 0xac) >> 1 & 3);
      if ((*(uint *)(param_2 + 0x14) & 0x8000000) == 0) {
        *(uint *)(pGVar55 + 0xac) = *(uint *)(pGVar55 + 0xac) & 0xfffffff9;
      }
      iVar8 = CPlugBitmap::UsageIsRender((CPlugBitmap *)in_stack_fffffd30,(CPlugBitmap *)pCVar50);
      uVar27 = *(uint *)(param_2 + 0x14);
      pCVar50 = (CVisionViewportDx9 *)(uint)(iVar8 != 0);
      if (((uVar27 & 0x10) != 0) && ((uVar27 & 0x20) != 0)) {
        if (*(int *)(this + 0x2b8) == 0) {
          pCVar50 = (CVisionViewportDx9 *)((uint)pCVar50 | 2);
        }
        else {
          pCVar50 = (CVisionViewportDx9 *)((uint)pCVar50 | 6);
        }
      }
      if ((uVar27 & 0xc00000) != 0) {
        if (((*(byte *)(*(int *)(pGVar55 + 0x14) + 0xac) & 6) == 0) || ((uVar27 & 0x20000000) == 0))
        {
          pSVar25 = *(SPlugFaceCull **)(param_2 + 0x1c);
        }
        else {
          GxBGRAColor::Set(&stack0xfffffd10,(CMwCmdScriptVarBool *)(*(int *)(pGVar55 + 0x14) + 0x94)
                           ,0x3f800000);
        }
        if ((pCVar60 != (CPlugBitmapRender *)0x0) && ((*(uint *)(pCVar60 + 0x5c) & 0x100) != 0)) {
          SHmsRenderRect::Reset(auStack_64,(GmFrustumIso4 *)pCVar7);
          pCVar7 = (CFastArray<class_GxTexCoordSet> *)(pGVar36 + 0x1c4);
          SHmsRenderRect::SetRect
                    (auStack_60,(CDynaSpecular *)pCVar7,(ulong)unaff_EDI,(ulong)unaff_ESI,
                     (ulong)unaff_EBP,(ulong)unaff_EBX,(ulong)pSVar25);
          pSVar25 = aSStack_4c;
          unaff_EBX = (void *)0x99824f;
          (**(code **)(*(int *)this + 0x1a8))();
          if ((iStack_54 != 0) && (iStack_50 != 0)) {
            fStack_290 = fStack_5c;
            fStack_288 = (float)((int)fStack_5c + -1 + iStack_54);
            pCStack_284 = (CHmsCamera *)((int)fStack_58 + -1 + iStack_50);
            fStack_28c = fStack_58;
            (**(code **)(**(int **)(this + 0x9f8) + 0xac))
                      (*(int **)(this + 0x9f8),1,&fStack_290,1,pSVar25,0x3f800000,0);
          }
          pCVar50 = (CVisionViewportDx9 *)((uint)pCVar50 & 0xfffffffe);
        }
        RenderTargetClear(this,pCVar50,(ulong)pSVar25,0x3f800000,0.0,(ulong)pCVar7);
      }
      pCVar7 = (CFastArray<class_GxTexCoordSet> *)pCVar21;
      if ((in_stack_fffffd38[0x4c] == (SNewTriangleVert)0x7) &&
         (pCVar60 != (CPlugBitmapRender *)0x0)) {
        pCVar22 = StdShaderGet(this,(CVisionViewportDx9 *)0x1,(EStdShader2)unaff_EDI,
                               (ulong)unaff_ESI);
        *(CPlugShaderApply **)(this + 0x44c) = pCVar22;
        *(undefined4 *)(this + 0x854) = 0;
        CDx9StateBlock::LockRenderStateReal(0xc3,*(float *)(pCVar60 + 0xf4));
        unaff_ESI = *(IDirect3DSurface9 **)(pCVar60 + 0xf8);
        unaff_EDI = (CVisionShaderKeeper *)0xaf;
        CDx9StateBlock::LockRenderStateReal(0xaf,(float)unaff_ESI);
      }
      pCVar50 = (CVisionViewportDx9 *)pCVar60;
      pCVar21 = (CPlugBitmapRenderCamera *)pCVar7;
      TransformStackCameraPush
                (this,(CVisionViewportDx9 *)pGVar36,(CHmsCamera *)pCVar60,
                 (CPlugBitmapRenderCamera *)pCVar7,(CPlugBitmapRenderVDepPlaneY *)unaff_EDI);
      CDx9StateBlock::ResetCache();
      DAT_00d7582c = 0;
      DAT_00d75a68 = 0;
      pSVar26 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem
                          (this + 0x454,
                           (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>
                            *)unaff_ESI);
      ComputeAndSetCullMode(this,(CVisionViewportDx9 *)pSVar26,(SHmsCameraLocation *)unaff_EBP);
      CDx9StateBlock::FilterRenderState(7,1);
      if (((byte)*(CPlugBitmapRender *)(param_2 + 0x14) & 0x40) != 0) {
        ViewportShrink1PixelBorder(this,(CVisionViewportDx9 *)0x0,1.0,(float)unaff_EBX);
      }
      uStack_238 = 0;
      uStack_234 = 0;
      uStack_230 = 0;
      pCVar48 = (CPlugShader *)&uStack_238;
      (**(code **)(*(int *)this + 0x17c))();
      if ((pCVar60 == (CPlugBitmapRender *)0x0) || (*(int *)(pCVar60 + 0x68) == 0)) {
        pCStack_2a8 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x8e4);
        pSStack_2ac = *(SHmsRenderRect **)(this + 0x904);
        *(undefined2 *)(this + 900) = *(undefined2 *)(param_2 + 0x20);
        *(ushort *)(this + 0x386) = *(ushort *)(param_2 + 0x22) & *(ushort *)(param_2 + 0x20);
        *(undefined2 *)(this + 0x388) = *(undefined2 *)(param_2 + 0x24);
        *(ushort *)(this + 0x38a) = *(ushort *)(param_2 + 0x26) & *(ushort *)(param_2 + 0x24);
        if (pCVar60 == (CPlugBitmapRender *)0x0) {
          *(undefined4 *)(this + 0x8e4) = 0xffffffff;
        }
        else {
          iVar8 = *(int *)(pCVar60 + 0x2c);
          *(int *)(this + 0x8e4) = iVar8 + -1;
          *(undefined4 *)(this + 0x8e8) = *(undefined4 *)(pCVar60 + 0x30);
          if (iVar8 + -1 == -1) {
            if (*(CVisionViewportDx9 **)(pCVar60 + 0x60) != (CVisionViewportDx9 *)0x0) {
              SetShaderForced(this,*(CVisionViewportDx9 **)(pCVar60 + 0x60),
                              (CPlugShader *)in_stack_fffffd2c);
              *(undefined4 *)(this + 0x904) = *(undefined4 *)(pCVar60 + 0x60);
            }
          }
          else {
            SetShaderForced(this,(CVisionViewportDx9 *)0x1,(CPlugShader *)in_stack_fffffd2c);
          }
        }
        unaff_EDI = (CVisionShaderKeeper *)0x998533;
        CHmsViewport::RenderZone
                  ((CHmsViewport *)this,(CHmsViewport *)in_stack_fffffd28,
                   (CHmsZone *)in_stack_fffffd2c);
        for (iVar8 = *(int *)(param_2 + 0x3c); iVar8 != 0; iVar8 = *(int *)(iVar8 + 0x3c)) {
          pCVar34 = (CPlugBitmapRenderCamera *)(*(uint *)(iVar8 + 0x14) >> 7 & 0xf);
          if ((DAT_00d77548 & 0x80) != 0) {
            unaff_EDI = (CVisionShaderKeeper *)0x99855d;
            CDx9StateBlock::FilterRenderState(0xa8,(ulong)pCVar34);
            if (pCVar21 == (CPlugBitmapRenderCamera *)&DAT_0000000f) {
              pCVar21 = pCVar34;
            }
          }
          SetShaderForced(this,*(CVisionViewportDx9 **)(iVar8 + 0x5c),pCVar48);
          *(undefined4 *)(this + 0x904) = *(undefined4 *)(iVar8 + 0x5c);
          *(undefined2 *)(this + 900) = *(undefined2 *)(iVar8 + 0x20);
          *(ushort *)(this + 0x386) = *(ushort *)(iVar8 + 0x22) & *(ushort *)(iVar8 + 0x20);
          *(undefined2 *)(this + 0x388) = *(undefined2 *)(iVar8 + 0x24);
          *(ushort *)(this + 0x38a) = *(ushort *)(iVar8 + 0x26) & *(ushort *)(iVar8 + 0x24);
          pCVar65 = (CHmsViewport *)in_stack_fffffd30;
          CHmsViewport::RenderZone
                    ((CHmsViewport *)this,(CHmsViewport *)in_stack_fffffd30,(CHmsZone *)pSVar25);
          pCVar48 = (CPlugShader *)in_stack_fffffd30;
          in_stack_fffffd30 = (CMwId *)pCVar65;
        }
        *(SNewTriangleVert **)(this + 0x8e4) = pSStack_2a4;
        *(CMwId **)(this + 0x8e8) = in_stack_fffffd30;
        SetShaderForced(this,pCVar29,pCVar48);
        *(SNewTriangleVert **)(this + 0x904) = pSStack_2a4;
      }
      else {
        *(undefined2 *)(this + 900) = 0;
        *(undefined2 *)(this + 0x386) = 0;
        *(undefined2 *)(this + 0x388) = 0;
        *(undefined2 *)(this + 0x38a) = 0;
        *(undefined4 *)(this + 0x450) = 0;
        *(undefined4 *)(this + 0x38c) = 0;
        unaff_EDI = (CVisionShaderKeeper *)0x998409;
        CFastBuffer<class_CSystemFidsFolder*>::SetCount
                  (this + 0x538,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,
                   (ulong)in_stack_fffffd2c);
        pSStack_2a0 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem
                                (this + 0x454,
                                 (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>
                                  *)pCVar48);
        pCVar53 = (CPlugTree *)0x0;
        pSVar14 = CFastBuffer<struct_CHmsViewport::SVisualLocation>::operator[]
                            (this + 0x538,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                             (ulong)pSVar25);
        GmIso4::SetIdentity(pSVar14,(GmMat43 *)in_stack_fffffd14);
        in_stack_fffffd14 = (GmBoxAligned *)in_stack_fffffd30;
        pCVar31 = pCStack_298;
        pSVar14 = pSVar14 + 0x70;
        for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
          *(undefined4 *)pSVar14 = *(undefined4 *)pCVar31;
          pCVar31 = pCVar31 + 4;
          pSVar14 = pSVar14 + 4;
        }
        in_stack_fffffd30 = (CMwId *)in_stack_fffffd14;
        (**(code **)(*(int *)this + 0x1a4))();
        uVar27 = *(uint *)(in_stack_fffffd38 + 0x68);
        uVar32 = 0;
        if (uVar27 != 0) {
          do {
            CHmsViewport::RenderTree
                      ((CHmsViewport *)this,
                       *(CHmsViewport **)(*(int *)(pCVar28 + 0x6c) + uVar32 * 4),pCVar53);
            uVar32 = uVar32 + 1;
          } while (uVar32 < uVar27);
        }
      }
      unaff_EBP = (SPlugFaceCull *)0x998606;
      (**(code **)(*(int *)this + 400))();
      if ((*(CFastBuffer<struct_CDx9StateBlock::STexStageState> *)(in_stack_fffffd30 + 0x4c) ==
           (CFastBuffer<struct_CDx9StateBlock::STexStageState>)0x7) &&
         (pCVar29 != (CVisionViewportDx9 *)0x0)) {
        uVar13 = 0xc3;
        CDx9StateBlock::UnlockRenderState(0xc3,(ulong)pCVar50);
        CDx9StateBlock::UnlockRenderState(0xaf,uVar13);
      }
      *(uint *)(pGVar55 + 0xac) =
           *(uint *)(pGVar55 + 0xac) ^ ((int)pCVar21 * 2 ^ *(uint *)(pGVar55 + 0xac)) & 6;
    }
    break;
  case (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)0x2:
  case (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)0x8:
    if ((in_stack_fffffd18 == (GmScaleTrans2 *)0x0) || (DAT_00d38fe0 == 0)) {
      TexRender_Water_PlaneR
                (this,(CVisionViewportDx9 *)in_stack_fffffd30,param_2,(CPlugBitmapRender *)0x0,
                 (GmVec4 *)0xffffffff,0,(int)pCVar50);
    }
    else {
      iVar8 = 0;
      uVar13 = 0;
      pGVar40 = (GmVec4 *)0x0;
      TexRender_Water_PlaneR
                (this,(CVisionViewportDx9 *)in_stack_fffffd30,param_2,(CPlugBitmapRender *)0x0,
                 (GmVec4 *)0x0,0,(int)pCVar50);
      pCVar23 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                CFastBuffer<class_CCrystalFace*>::GetCount
                          (in_stack_fffffd18,(CFastBuffer<class_CCrystalFace*> *)pCVar7);
      pCVar7 = (CFastArray<class_GxTexCoordSet> *)&stack0xfffffd2c;
      pCVar28 = (CVisionViewportDx9 *)0x0;
      pCVar50 = (CVisionViewportDx9 *)0x99869d;
      pCStack_2b4 = pCVar23;
      pCVar30 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                CFastArray<class_CGameMenuFrame*>::Find
                          (&DAT_00d77c0c,pCVar7,(GxTexCoordSet *)unaff_EDI);
      if (pCVar30 < pCVar23) {
        in_stack_fffffd30 = (CMwId *)0x0;
        do {
          pCVar23 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                    CFastBuffer<int>::FindAfter
                              (&DAT_00d77c0c,(CFastBuffer<int> *)&stack0xfffffd18,(int *)pCVar30,
                               (ulong)pGVar40);
          pGVar40 = (GmVec4 *)
                    (uint)(pCVar23 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff);
          pSVar14 = CFastBuffer<class_GxColor>::operator[](pSVar25,pCVar30,(ulong)(pCVar30 + 1));
          TexRender_Water_PlaneR
                    (this,pCVar28,param_2,(CPlugBitmapRender *)pSVar14,pGVar40,uVar13,iVar8);
          pCVar30 = pCVar23;
        } while (pCVar23 < pCStack_2bc);
      }
    }
    break;
  case (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)0x4:
    *(uint *)(this + 0x414) =
         *(uint *)(this + 0x414) ^ (*(int *)(param_2 + 0xb0) * 2 ^ *(uint *)(this + 0x414)) & 0x100;
    bVar35 = (*(uint *)(param_2 + 0x14) & 0xc00000) != 0;
    if (bVar35) {
      CPlugBitmapRender::OnRenderIsDoneClearRGBA
                ((CPlugBitmapRender *)param_2,(CPlugBitmapRender *)pCVar50);
    }
    pCVar29 = (CVisionViewportDx9 *)(uint)bVar35;
    if (((*(uint *)(param_2 + 0x14) & 0x10) != 0) && ((*(uint *)(param_2 + 0x14) & 0x20) != 0)) {
      if (*(int *)(this + 0x2b8) == 0) {
        pCVar29 = (CVisionViewportDx9 *)((uint)pCVar29 | 2);
      }
      else {
        pCVar29 = (CVisionViewportDx9 *)((uint)pCVar29 | 6);
      }
    }
    RenderTargetClear(this,pCVar29,*(ulong *)(param_2 + 0x1c),0x3f800000,0.0,(ulong)pCVar50);
    pCVar50 = (CVisionViewportDx9 *)0x998772;
    uVar13 = CFastBuffer<class_CCrystalFace*>::GetCount
                       ((CPlugBitmapRender *)(param_2 + 100),
                        (CFastBuffer<class_CCrystalFace*> *)pCVar7);
    if (uVar13 == 0) {
      pCVar7 = (CFastArray<class_GxTexCoordSet> *)0x99877e;
      uVar13 = CFastBuffer<class_CCrystalFace*>::GetCount
                         ((CPlugBitmapRender *)(param_2 + 0x74),
                          (CFastBuffer<class_CCrystalFace*> *)pCVar50);
      if (uVar13 == 0) break;
    }
    if (((byte)*(CPlugBitmapRender *)(param_2 + 0xb0) & 0x30) != 0) {
      *(uint *)(this + 0x414) =
           *(uint *)(this + 0x414) ^ (*(int *)(param_2 + 0x14) * 4 ^ *(uint *)(this + 0x414)) & 0x10
      ;
      *(undefined2 *)(this + 900) = *(undefined2 *)(param_2 + 0x20);
      *(ushort *)(this + 0x386) = *(ushort *)(param_2 + 0x22) & *(ushort *)(param_2 + 0x20);
      *(undefined2 *)(this + 0x388) = *(undefined2 *)(param_2 + 0x24);
      *(ushort *)(this + 0x38a) = *(ushort *)(param_2 + 0x26) & *(ushort *)(param_2 + 0x24);
      *(undefined4 *)(this + 0x450) = 0;
      *(undefined4 *)(this + 0x38c) = 0;
      pCVar45 = (CFastBuffer<class_CCrystalFace*> *)0x9987fa;
      CFastBuffer<class_CSystemFidsFolder*>::SetCount
                (this + 0x454,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,(ulong)pCVar50);
      pSVar16 = CFastBuffer<struct_CHmsViewport::SVisualLocation>::operator[]
                          (this + 0x454,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                           (ulong)pCVar7);
      puVar62 = &DAT_00d670f8;
      pSVar14 = pSVar16;
      for (iVar8 = 0x29; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined4 *)pSVar14 = *puVar62;
        puVar62 = puVar62 + 1;
        pSVar14 = pSVar14 + 4;
      }
      *(uint *)(pSVar16 + 0xa0) = *(uint *)(pSVar16 + 0xa0) & 0xfffffffd;
      pSVar14 = GmMat4::operator[](&DAT_00d67158,
                                   (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                   (ulong)unaff_EDI);
      pCVar52 = *(CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> **)
                 (this + 0x9f8);
      uVar13 = 2;
      (**(code **)(*(int *)pCVar52 + 0xb0))();
      pSVar26 = CFastBuffer<struct_SHmsRenderRect>::GetLastElem(this + 0x484,pCVar52);
      *(undefined4 *)(pSVar26 + 0x20) = 0;
      pSVar46 = (SPlugFaceCull *)0x99885c;
      CFastBuffer<class_CSystemFidsFolder*>::SetCount
                (this + 0x460,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,uVar13);
      pCVar50 = (CVisionViewportDx9 *)0x998865;
      pSVar14 = CFastBuffer<struct_CHmsViewport::SClippingFrustum>::operator[]
                          (this + 0x460,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                           (ulong)pSVar14);
      puVar62 = &DAT_00d67340;
      for (iVar8 = 0x4e; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined4 *)pSVar14 = *puVar62;
        puVar62 = puVar62 + 1;
        pSVar14 = pSVar14 + 4;
      }
      pCVar7 = (CFastArray<class_GxTexCoordSet> *)0x998882;
      CFastBuffer<class_CSystemFidsFolder*>::SetCount
                (this + 0x478,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,(ulong)unaff_ESI);
      pSVar14 = CFastBuffer<struct_SHmsCameraProjection>::operator[]
                          (this + 0x478,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                           (ulong)unaff_EBP);
      puVar62 = &DAT_00d671a0;
      if (((byte)this[0x414] & 2) == 0) {
        puVar62 = &DAT_00d67270;
      }
      pSVar16 = pSVar14;
      for (iVar8 = 0x34; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined4 *)pSVar16 = *puVar62;
        puVar62 = puVar62 + 1;
        pSVar16 = pSVar16 + 4;
      }
      *(uint *)(pSVar14 + 0xcc) = *(uint *)(pSVar14 + 0xcc) & 0xfffffffe;
      GmMat4::operator[](pSVar14 + 0x40,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                         (ulong)unaff_EBX);
      piVar39 = *(int **)(this + 0x9f8);
      unaff_EDI = (CVisionShaderKeeper *)0x9988cc;
      (**(code **)(*piVar39 + 0xb0))();
      CFastBuffer<class_CSystemFidsFolder*>::SetCount
                (this + 0x538,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,in_stack_fffffcbc);
      pSVar14 = CFastBuffer<struct_CHmsViewport::SVisualLocation>::operator[]
                          (this + 0x538,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                           in_stack_fffffcc0);
      ComputeAndSetCullMode(this,(CVisionViewportDx9 *)in_stack_fffffce0,in_stack_fffffcc4);
      if (((byte)*(CPlugBitmapRender *)(param_2 + 0x14) & 0x40) != 0) {
        ViewportShrink1PixelBorder(this,(CVisionViewportDx9 *)0x0,1.0,in_stack_fffffcc8);
      }
      CDx9StateBlock::LockRenderState(7,0);
      CDx9StateBlock::LockRenderState(0x1c,0);
      pSVar25 = *(SPlugFaceCull **)(this + 0x904);
      *(undefined4 *)(this + 0x418) = 0;
      SetShaderForced(this,*(CVisionViewportDx9 **)(param_2 + 0xa4),in_stack_fffffccc);
      *(undefined4 *)(this + 0x904) = *(undefined4 *)(param_2 + 0xa4);
      iVar8 = *(int *)(param_2 + 0xa8);
      *(int *)(this + 0x914) = iVar8;
      *(undefined4 *)(this + 0x918) = *(undefined4 *)(param_2 + 0xac);
      if ((iVar8 != 0) && (*(int *)(this + 0x8ec) == 0)) {
        SetShaderForced(this,(CVisionViewportDx9 *)0x1,in_stack_fffffcd0);
      }
      DAT_00d7582c = 0;
      pCVar24 = (CVisionShaderKeeper *)
                CFastBuffer<class_CCrystalFace*>::GetCount
                          ((CPlugBitmapRender *)(param_2 + 100),pCVar37);
      pCVar41 = (CVisionShaderKeeper *)0x0;
      pCVar38 = pCVar7;
      if (pCVar24 != (CVisionShaderKeeper *)0x0) {
        do {
          pSVar25 = (SPlugFaceCull *)
                    CFastBuffer<struct_CPlugBitmapRenderSolid::SSolid>::operator[]
                              ((CPlugBitmapRender *)(param_2 + 100),
                               (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar41,
                               (ulong)in_stack_fffffcd8);
          pSVar11 = (SPlugFaceCull *)pCVar38;
          pSVar16 = (SCasterCat *)pSVar25;
          for (iVar8 = 0xc; pSVar16 = pSVar16 + 4, iVar8 != 0; iVar8 = iVar8 + -1) {
            *(undefined4 *)pSVar11 = *(undefined4 *)pSVar16;
            pSVar11 = pSVar11 + 4;
          }
          pSVar11 = (SPlugFaceCull *)pCVar38;
          pCVar7 = pCVar38;
          GmIso4::SetMult((SPlugFaceCull *)(pCVar38 + 0x70),(SPlugFaceCull *)pCVar38,
                          (SPlugFaceCull *)pCVar50,(GmIso4 *)in_stack_fffffcdc);
          in_stack_fffffcd8 = (code *)0x9989df;
          (**(code **)(*(int *)this + 0x1a4))();
          CHmsViewport::RenderTree
                    ((CHmsViewport *)this,*(CHmsViewport **)(*(int *)unaff_EDI + 100),
                     (CPlugTree *)pSVar11);
          pCVar41 = pCVar41 + 1;
          in_stack_fffffcdc = (IDirect3DSurface9 *)pCVar38;
          pCVar38 = pCVar7;
        } while (pCVar41 < pCVar24);
      }
      uVar13 = CFastBuffer<class_CCrystalFace*>::GetCount
                         ((CPlugBitmapRender *)(param_2 + 0x74),
                          (CFastBuffer<class_CCrystalFace*> *)in_stack_fffffcd8);
      unaff_EBP = pSVar25;
      if (uVar13 != 0) {
        uVar13 = CFastBuffer<class_CCrystalFace*>::GetCount
                           ((CPlugBitmapRender *)(param_2 + 0x80),
                            (CFastBuffer<class_CCrystalFace*> *)pSVar46);
        uVar47 = CFastBuffer<class_CCrystalFace*>::GetCount
                           ((CPlugBitmapRender *)(param_2 + 0x74),
                            (CFastBuffer<class_CCrystalFace*> *)in_stack_fffffce0);
        pSVar11 = (SPlugFaceCull *)(uVar13 / uVar47);
        pCVar50 = (CVisionViewportDx9 *)pSVar11;
        in_stack_fffffd14 =
             (GmBoxAligned *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       ((CPlugBitmapRender *)(param_2 + 0x98),
                        (CFastBuffer<class_CCrystalFace*> *)pSVar14);
        unaff_EBP = pSVar25;
        GmIso4::SetIdentity(pSVar25,(GmMat43 *)pCVar29);
        GmIso4::SetMult(pSVar25 + 0x70,pSVar25,unaff_EBP,(GmIso4 *)pCVar41);
        *(uint *)(this + 0x858) = -(uint)((CVisionViewportDx9 *)0x1 < pSVar11) & (uint)pSVar11;
        *(undefined4 *)(this + 0x860) = *(undefined4 *)(param_2 + 0x90);
        this_04 = (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)
                  CFastBuffer<class_CCrystalFace*>::GetCount
                            ((CPlugBitmapRender *)(param_2 + 0x74),pCVar45);
        pCVar30 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (this_04 != (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)0x0) {
          pSVar25 = (SPlugFaceCull *)0x0;
          do {
            pCVar23 = pCVar30;
            pCVar56 = pCVar30;
            CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                      ((CPlugBitmapRender *)(param_2 + 0x74),pCVar30,(ulong)pSVar46);
            if (pSVar11 != (SPlugFaceCull *)0x0) {
              pSVar46 = pSVar25;
              pSVar14 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
                        ::operator[]((CPlugBitmapRender *)(param_2 + 0x80),in_stack_fffffd20,
                                     (ulong)pCVar50);
              pCVar50 = (CVisionViewportDx9 *)pCVar56;
              pSVar25 = pSVar46;
              for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
                *(undefined4 *)pSVar25 = *(undefined4 *)pSVar14;
                pSVar14 = pSVar14 + 4;
                pSVar25 = pSVar25 + 4;
              }
              pCVar23 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x998ae2;
              pSVar11 = (SPlugFaceCull *)pCVar50;
              pSVar25 = pSVar46;
              pCVar30 = in_stack_fffffd28;
              GmIso4::SetMult(pSVar46 + 0x70,pSVar46,(SPlugFaceCull *)pCVar50,(GmIso4 *)pCVar7);
              in_stack_fffffd28 = pCVar30;
              if ((CFastBuffer<struct_CDx9StateBlock::STexStageState> *)0x1 < in_stack_fffffd14) {
                pCVar50 = (CVisionViewportDx9 *)0x998af9;
                pSVar14 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
                          ::operator[]((CPlugBitmapRender *)(param_2 + 0x80),pCVar30,
                                       (ulong)unaff_EDI);
                *(SCasterCat **)(this + 0x85c) = pSVar14;
                in_stack_fffffd28 = pCVar30;
              }
            }
            unaff_EDI = pCVar24;
            if (in_stack_fffffd30 != (CMwId *)0x0) {
              pSVar14 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                  ((CPlugBitmapRender *)(param_2 + 0x98),pCVar30,(ulong)piVar39);
              iVar8 = *(int *)pSVar14;
              unaff_EDI = pCVar24;
              if (iVar8 != 0) {
                *(undefined2 *)(in_stack_fffffd20 + 0x54) = 0;
                *(short *)(in_stack_fffffd20 + 0x56) = (short)iVar8;
              }
            }
            pCVar7 = (CFastArray<class_GxTexCoordSet> *)0x998b40;
            pCVar24 = unaff_EDI;
            (**(code **)(*(int *)this + 0x1a4))();
            CHmsViewport::RenderTree
                      ((CHmsViewport *)this,(CHmsViewport *)unaff_EBP,(CPlugTree *)pCVar23);
            pSVar25 = pSVar25 + (int)pSVar11;
            pCVar30 = pCVar30 + 1;
          } while (pCVar30 < this_04);
        }
        *(undefined4 *)(this + 0x858) = 0;
        *(undefined4 *)(this + 0x860) = 0;
        *(undefined4 *)(this + 0x85c) = 0;
      }
      *(undefined4 *)(this + 0x914) = 0;
      *(undefined4 *)(this + 0x918) = 0;
      SetShaderForced(this,(CVisionViewportDx9 *)pCStack_2bc,(CPlugShader *)pSVar46);
      *(CVisionViewportDx9 **)(this + 0x904) = pCVar28;
      *(undefined4 *)(this + 0x418) = 1;
      DAT_00d75fa0 = 0;
      if (DAT_00d75c90 != 0) {
        CDx9StateBlock::PackRenderState(0x1c,0xffffffff,(SPackedDesc *)&pCStack_2a8);
        *(uint *)(&DAT_00d76ed8 + (int)pCStack_2a8 * 4) =
             *(uint *)(&DAT_00d76ed8 + (int)pCStack_2a8 * 4) | (uint)pSStack_2a0;
      }
      CDx9StateBlock::UnlockRenderState(7,1);
      if (((byte)*(uint *)(param_2 + 0xb0) & 0x30) == 0x10) {
        *(uint *)(param_2 + 0xb0) = *(uint *)(param_2 + 0xb0) & 0xffffffcf;
      }
    }
    break;
  case (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)0x6:
    TexRender_Hemisphere
              (this,(CVisionViewportDx9 *)in_stack_fffffd30,param_2,
               (CPlugBitmapRenderHemisphere *)pCVar50);
    break;
  case (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)0x9:
    pCVar28 = *(CVisionViewportDx9 **)(param_2 + 0x5c);
    if ((*(int *)(pCVar28 + 0xec) != 0) &&
       (this_01 = *(CHmsCorpusLight **)(pCVar28 + 0xd0), this_01 != (CHmsCorpusLight *)0x0)) {
      if (*(int *)(pCVar28 + 0xf0) == 0) {
        pSVar46 = (SPlugFaceCull *)0x998c37;
        iVar8 = GmBoxAligned::IsNull(pCVar28 + 0xf4,(CSysFidNodRef<class_CPlugBitmap> *)pCVar50);
        if (iVar8 != 0) break;
      }
      pCVar20 = *(CMwNodRef<class_CGameCamera> **)(this_01 + 0x14);
      if (*(int *)(pCVar28 + 0xf0) != 0) {
        iVar8 = *(int *)(pCVar28 + 0xf0);
        pCVar20 = *(CMwNodRef<class_CGameCamera> **)(iVar8 + 0x14);
        pSVar46 = (SPlugFaceCull *)(iVar8 + 0x18);
        in_stack_fffffcf0 =
             (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             (*(int *)(*(int *)(*(int *)(iVar8 + 0x48) + 0x14) + 100) + 0x34);
        in_stack_fffffcec = (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)0x998c78;
        GmBoxAligned::SetMult
                  (pCVar28 + 0xf4,(SPlugFaceCull *)in_stack_fffffcf0,pSVar46,(GmIso4 *)pCVar50);
      }
      GVar6 = CHmsCorpusLight::GetPosition(this_01,(CGameControlCameraTarget *)&uStack_270);
      in_stack_fffffd30 = (CMwId *)CONCAT31(extraout_var_01,GVar6);
      pCVar7 = (CFastArray<class_GxTexCoordSet> *)0x3;
      if (*(int *)(this + 0x2b8) != 0) {
        pCVar7 = (CFastArray<class_GxTexCoordSet> *)&DAT_00000007;
      }
      pCVar58 = pCVar20;
      CMwNodRef<class_CGameCamera>::MwSetNod
                (pCVar28 + 0x120,pCVar20,(CGameCamera *)in_stack_fffffce4);
      if (*(CMwNod **)(pCVar28 + 0x124) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(pCVar28 + 0x124),(CMwNod *)in_stack_fffffcec);
        *(undefined4 *)(pCVar28 + 0x124) = 0;
      }
      *(uint *)(pCVar28 + 0x1dc) = *(uint *)(pCVar28 + 0x1dc) & 0xfffffefe | 10;
      *(undefined4 *)(in_stack_fffffd28 + 0x14) = *(undefined4 *)(*(int *)(pCVar20 + 0x48) + 0x18);
      *(undefined4 *)(in_stack_fffffd28 + 0x18) = *(undefined4 *)(*(int *)(pCVar20 + 0x48) + 0x1c);
      iVar8 = Shadow_ComputeFrustumLocation
                        (this,pCVar28,(CPlugVolumeShadow *)0xffffffff,(ulong)in_stack_fffffcec);
      if (iVar8 != 0) {
        Shadow_ComputeWorldPrVolume
                  (this,pCVar28,(CPlugVolumeShadow *)in_stack_fffffd3c,(int)pCVar58,(GxLight *)0x0,
                   (GmBoxAligned *)0x0,(SShadowCameraInter *)in_stack_fffffcf0);
        Shadow_RenderCaster(this,(CVisionViewportDx9 *)in_stack_fffffd18,(CHmsZone *)pCVar28,
                            (CPlugVolumeShadow *)0xffffffff,(ulong)unaff_EBX,0,
                            (GmBoxAligned *)param_2,(CPlugBitmapRenderShadow *)0x0,(GmVec4 *)0x0,
                            (float *)pSVar46);
      }
      if (*(CMwNod **)(pCVar28 + 0x120) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(pCVar28 + 0x120),(CMwNod *)pCVar50);
        *(undefined4 *)(pCVar28 + 0x120) = 0;
      }
      *(undefined4 *)(pCVar28 + 0xd0) = 0;
    }
    break;
  case (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)0xa:
    iVar8 = 0x997600;
    uVar13 = CFastBuffer<class_CCrystalFace*>::GetCount
                       ((CHmsViewport *)(param_2 + 0x5c),(CFastBuffer<class_CCrystalFace*> *)pCVar50
                       );
    if (uVar13 != 0) {
      uVar27 = *(uint *)(param_2 + 0x14);
      pCVar28 = (CVisionViewportDx9 *)0x1;
      if (((uVar27 & 0x10) != 0) && ((uVar27 & 0x20) != 0)) {
        pCVar28 = (CVisionViewportDx9 *)((uint)(*(int *)(this + 0x2b8) != 0) * 4 + 3);
      }
      if ((uVar27 & 0xc00000) != 0) {
        pCVar50 = (CVisionViewportDx9 *)0x0;
        iVar8 = 0x3f800000;
        RenderTargetClear(this,pCVar28,*(ulong *)(param_2 + 0x1c),0x3f800000,0.0,(ulong)pCVar7);
      }
      CHmsViewport::RenderVisibleZone2ds
                ((CHmsViewport *)this,(CHmsViewport *)(param_2 + 0x5c),
                 (CFastBuffer<class_CHmsZoneOverlay*> *)0x0,iVar8);
    }
    break;
  case (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)0xb:
    if ((*(uint *)(param_2 + 0x14) & 0xc00000) != 0) {
      RenderTargetClear(this,(CVisionViewportDx9 *)0x1,*(ulong *)(param_2 + 0x1c),0x3f800000,0.0,
                        (ulong)pCVar50);
    }
    uVar13 = CFastBuffer<class_CCrystalFace*>::GetCount
                       ((CPlugBitmapRender *)(param_2 + 0x4c),
                        (CFastBuffer<class_CCrystalFace*> *)pCVar50);
    if (((uVar13 != 0) && (uVar13 = *(ulong *)(pCStack_2bc + 0x3c), uVar13 != 0)) &&
       (in_stack_fffffd14 = *(GmBoxAligned **)(uVar13 + 0x14),
       in_stack_fffffd14 != (GmBoxAligned *)0x0)) {
      pCVar57 = (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)(in_stack_fffffd14 + 0x58);
      pCVar50 = (CVisionViewportDx9 *)0x1;
      pSVar14 = CFastBuffer<struct_SFastCat>::operator[]
                          (pCVar57,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                           (ulong)pCVar7);
      if (*(int *)(pSVar14 + 4) != 0) {
        pCVar50 = (CVisionViewportDx9 *)0x0;
        pCVar48 = (CPlugShader *)0x9976c8;
        pSVar15 = CFastBufferCat<class_CSceneMobil*,struct_SFastCat>::GetElemInCat
                            (pCVar57,(CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
                                      *)0x0,1,(ulong)unaff_EDI);
        piVar39 = *(int **)pSVar15;
        pCVar7 = (CFastArray<class_GxTexCoordSet> *)0x9976d7;
        CMwNodRef<class_CGameCamera>::MwSetNod
                  (piVar39 + 0x14,(CMwNodRef<class_CGameCamera> *)in_stack_fffffd3c,
                   (CGameCamera *)unaff_ESI);
        piVar39[0x15] = *(int *)(param_2 + 100);
        unaff_EDI = (CVisionShaderKeeper *)0x9976ec;
        CFastBuffer<class_CSystemFidsFolder*>::SetCount
                  (this + 0x454,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,(ulong)unaff_EBP);
        pSVar16 = CFastBuffer<struct_CHmsViewport::SVisualLocation>::operator[]
                            (this + 0x454,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                             (ulong)unaff_EBX);
        *(uint *)(pSVar16 + 0xa0) = *(uint *)(pSVar16 + 0xa0) | 1;
        pGVar17 = (GmMat2 *)(**(code **)(*piVar39 + 0x78))();
        unaff_EBP = (SPlugFaceCull *)0x99770f;
        GmMat3::SetTranspose(pSVar16,pGVar17,(GmMat2 *)pSVar25);
        *(float *)pSVar16 = -*(float *)pSVar16;
        *(float *)(pSVar16 + 4) = -*(float *)(pSVar16 + 4);
        *(float *)(pSVar16 + 8) = -*(float *)(pSVar16 + 8);
        *(float *)(pSVar16 + 0x18) = -*(float *)(pSVar16 + 0x18);
        *(float *)(pSVar16 + 0x1c) = -*(float *)(pSVar16 + 0x1c);
        *(float *)(pSVar16 + 0x20) = -*(float *)(pSVar16 + 0x20);
        GmMat3::SetTranspose
                  ((GmScaleTrans2 *)(pSVar16 + 0x30),(GmMat2 *)pSVar16,(GmMat2 *)in_stack_fffffd14);
        iVar8 = (**(code **)(*(int *)in_stack_fffffd38 + 0x78))();
        *(undefined4 *)(pSVar16 + 0x54) = *(undefined4 *)(iVar8 + 0x24);
        *(undefined4 *)(pSVar16 + 0x58) = *(undefined4 *)(iVar8 + 0x28);
        *(undefined4 *)(pSVar16 + 0x5c) = *(undefined4 *)(iVar8 + 0x2c);
        GmIso4::SetInverse(pSVar16,(GmScaleTrans2 *)(pSVar16 + 0x30),in_stack_fffffd18);
        pSVar14 = pSVar16;
        (**(code **)(*(int *)this + 0x19c))();
        pSVar14 = GmMat4::operator[](pSVar16 + 0x60,
                                     (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                     (ulong)pSVar14);
        pCVar52 = *(CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> **)
                   (this + 0x9f8);
        uVar47 = 2;
        (**(code **)(*(int *)pCVar52 + 0xb0))();
        *(uint *)(pSVar16 + 0xa0) = *(uint *)(pSVar16 + 0xa0) & 0xfffffffd;
        pSVar26 = CFastBuffer<struct_SHmsRenderRect>::GetLastElem(this + 0x484,pCVar52);
        *(undefined4 *)(pSVar26 + 0x20) = 0;
        CFastBuffer<class_CSystemFidsFolder*>::SetCount
                  (this + 0x460,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,uVar47);
        in_stack_fffffd30 =
             (CMwId *)CFastBuffer<struct_CHmsViewport::SClippingFrustum>::operator[]
                                (this + 0x460,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                 (ulong)pSVar14);
        CFastBuffer<class_CSystemFidsFolder*>::SetCount
                  (this + 0x478,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,uVar13);
        pSVar18 = CFastBuffer<struct_SHmsCameraProjection>::operator[]
                            (this + 0x478,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                             (ulong)in_stack_fffffd20);
        pGVar36 = (GmFrustum *)GmFrustum::GetFarZ(pCStack_2bc + 0x118,(GmFrustum *)param_3);
        fVar9 = GmFrustum::GetNearZ((void *)((int)fStack_2b8 + 0x118),pGVar36);
        GmFrustum::SetFovY(auStack_21c,*(GmFrustum **)(param_2 + 0x5c),1.0,fVar9,
                           (float)in_stack_fffffd28,(float)in_stack_fffffd2c);
        CHmsViewport::SClippingFrustum::Set(pCStack_2bc,aCStack_218,(int)(pSVar16 + 0x30));
        pSVar63 = pSStack_2ac;
        (**(code **)(*(int *)this + 0x1a8))();
        ViewportSet(this,pCStack_2b0,pSVar63);
        pCVar64 = (CHmsCorpus *)0x0;
        pSVar14 = pSVar18;
        pCVar61 = pCStack_2bc;
        (**(code **)(*(int *)this + 0x1a0))();
        pSVar14 = GmMat4::operator[](pSVar18 + 0x40,
                                     (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                     (ulong)pSVar14);
        piVar39 = *(int **)(this + 0x9f8);
        pGVar59 = (GmIso3 *)0x3;
        (**(code **)(*piVar39 + 0xb0))();
        *(uint *)(pSVar18 + 0xcc) = *(uint *)(pSVar18 + 0xcc) & 0xfffffffe;
        in_stack_fffffd14 = (GmBoxAligned *)0x9978a6;
        GmMat4::Set((CPlugBitmapRender *)(param_2 + 0x6c),(CMwCmdScriptVarBool *)pSVar16,
                    (int)piVar39);
        GmMat4::Mult((CPlugBitmapRender *)(param_2 + 0x6c),(GmIso3 *)pSVar18,pGVar59);
        *(undefined2 *)(this + 900) = *(undefined2 *)(param_2 + 0x20);
        *(ushort *)(this + 0x386) = *(ushort *)(param_2 + 0x22) & *(ushort *)(param_2 + 0x20);
        *(undefined2 *)(this + 0x388) = *(undefined2 *)(param_2 + 0x24);
        *(ushort *)(this + 0x38a) = *(ushort *)(param_2 + 0x26) & *(ushort *)(param_2 + 0x24);
        this_04 = *(CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> **)
                   (this + 0x8e4);
        SetShaderForced(this,(CVisionViewportDx9 *)0x1,(CPlugShader *)pSVar14);
        *(undefined4 *)(this + 0x8e4) = 2;
        iVar8 = DAT_00d75fa0;
        if (DAT_00d75fa0 == 0) {
          CDx9StateBlock::LockRenderState(0x1c,0);
        }
        ComputeAndSetCullMode(this,(CVisionViewportDx9 *)pSVar16,(SHmsCameraLocation *)pCVar61);
        CDx9StateBlock::FilterRenderState(0x16,*(ulong *)(this + 0x91c));
        puVar62 = &uStack_200;
        pCVar30 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        uStack_200 = 0;
        uStack_1fc = 0;
        uStack_1f8 = 0;
        (**(code **)(*(int *)this + 0x17c))();
        pCStack_2b4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                      CFastBuffer<class_CCrystalFace*>::GetCount
                                ((CPlugBitmapRender *)(param_2 + 0x4c),
                                 (CFastBuffer<class_CCrystalFace*> *)pCStack_2b4);
        if (pCStack_2b4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          do {
            pSVar14 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                ((CPlugBitmapRender *)(param_2 + 0x4c),pCVar30,(ulong)puVar62);
            pCVar64 = CHmsItem::GetCorpus(*(CHmsItem **)pSVar14,pCStack_2bc,(CHmsZone *)pCVar64);
            puVar62 = (undefined4 *)0x99799f;
            CHmsViewport::RenderCorpus
                      ((CHmsViewport *)this,(CHmsViewport *)pCVar64,(CHmsCorpus *)in_stack_fffffd30)
            ;
            pCVar30 = pCVar30 + 1;
          } while (pCVar30 < pCStack_2a8);
        }
        (**(code **)(*(int *)this + 400))();
        if (*(CVisionViewportDx9 **)(param_2 + 0x68) != (CVisionViewportDx9 *)0x0) {
          SetStageTexture(this,*(CVisionViewportDx9 **)(param_2 + 0x68),(CPlugBitmap *)0x0,
                          (ulong)pCVar48);
          RasterizeQuadAlloc(this,(CVisionViewportDx9 *)0x1,0,(int)pCVar50);
          uStack_260 = 0x3f800000;
          uStack_268 = 0;
          uStack_264 = 0;
          auStack_25c[0] = 0x3f800000;
          fStack_27c = _DAT_00b2c060;
          fStack_280 = _DAT_00b2c060;
          fStack_274 = 1.0;
          fStack_278 = 1.0;
          RasterizeQuadAdd(this,0xffffffff,&fStack_280,0,0x3f800000,&uStack_268);
          pCVar50 = this + 0x1074;
          pCVar48 = (CPlugShader *)0x997a91;
          RasterizeQuads(this,pCVar50,(CDx9StateBlock *)pCVar7);
        }
        if (iVar8 == 0) {
          CDx9StateBlock::UnlockRenderState(0x1c,(ulong)pCVar48);
        }
        SetShaderForced(this,(CVisionViewportDx9 *)unaff_EBP,pCVar48);
        *(GmBoxAligned **)(this + 0x8e4) = in_stack_fffffd14;
      }
    }
    break;
  case (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)0xc:
    TexRender_LightFromMap
              (this,(CVisionViewportDx9 *)in_stack_fffffd30,param_2,
               (CPlugBitmapRenderLightFromMap *)pCVar50);
  }
  *(uint *)(this + 0x414) = *(uint *)(this + 0x414) & 0xfffffe3d;
  *(undefined4 *)(this + 0x420) = 0;
  *(undefined4 *)(this + 0x448) = 0;
  *(undefined4 *)(this + 0x44c) = 0;
  *(uint *)(this + 0x424) = (uint)(*(int *)(this + 0x248) != 0);
  *(undefined4 *)(this + 0x42c) = 1;
  *(undefined4 *)(this + 0x850) = 1;
  *(undefined4 *)(this + 0x434) = 0;
  *(uint *)(this + 0x428) = (uint)(*(int *)(this + 0x6c) != 0);
  if ((DAT_00d77548 & 0x80) != 0) {
    CDx9StateBlock::FilterRenderState(0xa8,0xf);
  }
  pCVar52 = DAT_00d769fc;
  if (((pCStack_298 == (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)0x0) &&
      (((byte)*(CPlugBitmapRender *)(param_2 + 0x5c) & 2) != 0)) && ((DAT_00d77548 & 0x80) != 0)) {
    CDx9StateBlock::FilterRenderState(7,0);
    CDx9StateBlock::FilterRenderState(0xa8,8);
    RasterizeQuadGetFullRect(this,aCStack_26c,(GmRectAligned *)pCVar50);
    RasterizeQuadAlloc(this,(CVisionViewportDx9 *)0x1,0,(int)pCVar7);
    in_stack_fffffd30 = (CMwId *)0x3f800000;
    fStack_274 = 1.0;
    this_04 = (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)0x0;
    fStack_278 = 0.0;
    fStack_27c = 0.0;
    uStack_270 = 0x3f800000;
    RasterizeQuadAdd(this,0xffffffff,&uStack_264,0,0x3f800000,&fStack_27c);
    RasterizeQuads(this,this + 0xc74,(CDx9StateBlock *)unaff_EDI);
    CDx9StateBlock::FilterRenderState(0xa8,0xf);
    CDx9StateBlock::FilterRenderState(7,(ulong)pCVar52);
    pCVar50 = (CVisionViewportDx9 *)pCVar52;
  }
  uVar27 = *(uint *)(param_2 + 0x14) >> 0x1e & 1;
  if ((uVar27 != 0) || ((*(uint *)(in_stack_fffffd30 + 0x54) & 0xf0) != 0)) {
    if (uVar27 == 0) {
      pSVar26 = CFastBuffer<struct_CVisionViewportDx9::SRenderTarget>::GetLastElem
                          (this + 0x9fc,
                           (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>
                            *)pCVar50);
    }
    else {
      pSVar26 = (SNewTriangleVert *)
                CFastBuffer<struct_CVisionViewportDx9::SRenderTarget>::operator[]
                          (this + 0x9fc,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                           (ulong)pCVar50);
    }
    if (*(int *)(pSVar26 + 0x2c) != 0) {
      uVar12 = *(undefined4 *)(pSVar26 + 0x10);
      piVar39 = *(int **)(pCStack_2bc + 0xc);
      pCVar50 = (CVisionViewportDx9 *)&stack0xfffffd14;
      (**(code **)(*piVar39 + 0x48))(piVar39,0);
      iVar8 = (**(code **)(**(int **)(this + 0x9f8) + 0x88))
                        (*(int **)(this + 0x9f8),uVar12,0,unaff_EBP,0,0);
      (**(code **)(*piVar39 + 8))(piVar39);
      if (iVar8 != 0) {
        DAT_00d777a4 = 2;
      }
    }
  }
  uVar27 = 1;
  if ((*(uint *)(param_2 + 0x18) & 0xff) != 0) {
    iVar8 = TexRender_Gutter(this,(CVisionViewportDx9 *)in_stack_fffffd30,(CPlugBitmap *)0x0,
                             (CPlugBitmap *)&stack0xfffffd10,(ulong *)pCVar50);
    uVar27 = (uint)(iVar8 != 0);
    *(CPlugBitmapRender *)(param_2 + 0x18) = SUB41(in_stack_fffffd14,0);
  }
  if (1 < (*(uint *)(param_2 + 0x14) >> 0xe & 0xff)) {
    iVar8 = TexRender_BlurHV(this,(CVisionViewportDx9 *)in_stack_fffffd30,(CPlugBitmap *)0x0,
                             (CPlugBitmap *)&stack0xfffffd10,_DAT_00b313ac,1.0,
                             (float)(*(uint *)(param_2 + 0x18) >> 0xb & 0xf),(ulong)pCVar50);
    if (iVar8 == 0) {
      uVar27 = 0;
    }
    *(uint *)(param_2 + 0x14) =
         *(uint *)(param_2 + 0x14) ^
         ((int)in_stack_fffffd14 << 0xe ^ *(uint *)(param_2 + 0x14)) & 0x3fc000;
  }
  if (((byte)this_04[0x20] & 8) != 0) {
    CDx9TextureKeeper::AutoGenMipMapSetDirty(this_04,(CDx9TextureKeeper *)pCVar50);
  }
  if (pCStack_298 ==
      (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)&DAT_0000000c) {
    TexRender_LightFromMap_Download
              (this,(CVisionViewportDx9 *)in_stack_fffffd30,(CPlugBitmap *)pCVar50);
  }
  if (((byte)*(uint *)(param_2 + 0x14) & 3) == 1) {
    *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) & 0xfffffffc;
  }
  ExceptionList = local_10;
  return uVar27;
}
}

// =================================================
// Function: CVisionViewportDx9::TexRender_RenderTextureCube
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CVisionViewportDx9::TexRender_RenderTextureCube
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2)
{
{
  CPlugBitmapRenderWater CVar1;
  CPlugBitmapRenderWater *this_00;
  code *pcVar2;
  CHmsCorpusLight *this_01;
  bool bVar3;
  float fVar4;
  TiXmlAttribute *pTVar5;
  int iVar6;
  CHmsZone *pCVar7;
  ulong uVar8;
  CVisionShaderKeeper *pCVar9;
  SCasterCat *pSVar10;
  uint uVar11;
  undefined4 uVar12;
  SCasterCat *pSVar13;
  SCasterCat *pSVar14;
  CVisionViewportDx9 *pCVar15;
  TiXmlAttributeSet *pTVar16;
  undefined4 *puVar17;
  SNewTriangleVert *this_02;
  CHmsZone *pCVar18;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  GmIso3 *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar19;
  CPlugTree *this_03;
  CPlugBitmapRenderWater *pCVar20;
  CVisionViewportDx9 *pCVar21;
  GmScaleTrans2 *pGVar22;
  GmScaleTrans2 *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar23;
  GmIso4 *pGVar24;
  float10 fVar25;
  GmFrustum *pGVar26;
  float fVar27;
  CMwNodRef<class_CGameCamera> *unaff_retaddr;
  CPlugShader *in_stack_fffffca8;
  EGxTexFilter *pEVar28;
  float *pfVar29;
  CHmsCamera *in_stack_fffffcbc;
  TiXmlAttribute *pTVar30;
  CPlugTree *in_stack_fffffcc0;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *pCVar31;
  CVisionViewport *pCVar32;
  ulong uVar33;
  float fVar34;
  CPlugShader *in_stack_fffffcc4;
  CPlugTree *pCVar35;
  GmMat3 *pGVar36;
  GmScaleTrans2 *pGVar37;
  TiXmlAttributeSet *pTVar38;
  CMwCmdScriptVarBool *pCVar39;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffcc8;
  GmVec3 *pGVar40;
  CPlugTree *in_stack_fffffccc;
  int *piVar41;
  ulong uVar42;
  GmVec3 *pGVar43;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *pCVar44;
  CIteratorShader *pCVar45;
  GmVec4 *pGVar46;
  CHmsCamera *pCVar47;
  CFastBuffer<class_CCrystalFace*> *pCVar48;
  SNewTriangleVert *pSVar49;
  GmVec3 *pGVar50;
  CHmsViewport *pCVar51;
  ulong uVar52;
  SCasterCat *pSVar53;
  CHmsViewport *pCVar54;
  CHmsZone *pCVar55;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *pCStack_310;
  CMwCmdScriptVarBool *pCStack_30c;
  CVisionViewport *pCStack_308;
  CMwCmdScriptVarBool *pCStack_304;
  float fStack_300;
  void *pvStack_2fc;
  GmScaleTrans2 *pGStack_2f8;
  float fStack_2f4;
  float fStack_2f0;
  float fStack_2ec;
  SNewTriangleVert *pSStack_2e8;
  undefined4 *puStack_2e4;
  CFastBufferRef<class_CGameMobil> *pCStack_2e0;
  CVisionViewportDx9 *pCStack_2dc;
  undefined4 uStack_2d8;
  SCasterCat *pSStack_2d4;
  undefined4 uStack_2d0;
  CMwCmdScriptVarBool *pCStack_2cc;
  CMwCmdScriptVarBool *pCStack_2c8;
  CVisionViewportDx9 *apCStack_2c0 [2];
  undefined4 uStack_2b8;
  undefined4 uStack_2b4;
  float fStack_2b0;
  float fStack_2ac;
  float fStack_2a8;
  float fStack_2a4;
  float fStack_2a0;
  float fStack_29c;
  float fStack_298;
  float fStack_294;
  float fStack_290;
  float fStack_28c;
  float fStack_288;
  float fStack_284;
  undefined1 auStack_280 [8];
  CHmsZone aCStack_278 [36];
  undefined1 auStack_254 [4];
  undefined1 auStack_250 [16];
  CHmsCamera aCStack_240 [4];
  CHmsCamera aCStack_23c [4];
  CHmsCamera aCStack_238 [4];
  CHmsCamera aCStack_234 [12];
  CHmsCamera aCStack_228 [4];
  undefined4 uStack_224;
  undefined4 uStack_1c;
  int iStack_18;
  CVisionViewportDx9 *pCStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00aeb116;
  local_c = ExceptionList;
  pTVar5 = (TiXmlAttribute *)(DAT_00cca150 ^ (uint)&stack0xfffffcdc);
  ExceptionList = &local_c;
  pCVar48 = (CFastBuffer<class_CCrystalFace*> *)param_1;
  iVar6 = (**(code **)(*(int *)this + 0xb4))();
  if (iVar6 != 0) {
    this_00 = *(CPlugBitmapRenderWater **)(param_1 + 0x74);
    pCVar7 = (CHmsZone *)(**(code **)(*(int *)this_00 + 0x78))();
    pCStack_304 = *(CMwCmdScriptVarBool **)(param_1 + 0x14);
    pCVar18 = *(CHmsZone **)(pCStack_304 + 0x38);
    pCStack_308 = *(CVisionViewport **)(pCStack_304 + 0x3c);
    pCVar23 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCStack_304;
    if (((pCVar7 == (CHmsZone *)0x1) && (pCVar18 != (CHmsZone *)0x0)) &&
       (*(int *)(pCStack_304 + 0x50) != 0)) {
      if ((((byte)this_00[0x74] & 1) != 0) && (iVar6 = *(int *)(pCStack_304 + 0x40), iVar6 != 0)) {
        pCVar45 = (CIteratorShader *)0x994df9;
        uVar8 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00 + 0x88,pCVar48);
        if (uVar8 == 0) {
          pCVar45 = *(CIteratorShader **)(*(int *)(*(int *)(iVar6 + 0x48) + 0x14) + 100);
          pCVar48 = (CFastBuffer<class_CCrystalFace*> *)0x0;
          in_stack_fffffccc = (CPlugTree *)0x994e16;
          CPlugTree::CIteratorShader::CIteratorShader
                    (&uStack_2d0,pCVar45,(CPlugTree *)0x0,(EMode)pTVar5);
          unaff_retaddr = (CMwNodRef<class_CGameCamera> *)0x0;
          pCVar21 = apCStack_2c0[0];
joined_r0x00994e26:
          if (pCVar21 != (CVisionViewportDx9 *)0x0) {
            uVar8 = 0x994e3e;
            in_stack_fffffcc0 =
                 (CPlugTree *)
                 CPlugTree::CIteratorShader::GetNextShader
                           (&pSStack_2e8,(CIteratorShader *)&fStack_2f4,
                            (CPlugTree **)in_stack_fffffcc0);
            pTVar30 = (TiXmlAttribute *)0x994e46;
            pCVar9 = CVisionViewport::ShaderGetKeeper
                               ((CVisionViewport *)this,(CVisionViewport *)in_stack_fffffcc0,
                                in_stack_fffffcc4);
            in_stack_fffffcc4 = (CPlugShader *)0x994e50;
            unaff_ESI = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                        CFastBuffer<class_CCrystalFace*>::GetCount(pCVar9 + 0x3c,in_stack_fffffcc8);
            pCVar19 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
            pCVar23 = unaff_EBX;
            pCVar21 = pCStack_2dc;
            if (unaff_ESI != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
              do {
                pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                    (pCVar9 + 0x3c,pCVar19,uVar8);
                if (*(int *)pSVar10 == iStack_18) {
                  CFastBuffer<class_CDx9TextureKeeper*>::Add
                            (this_00 + 0x88,(TiXmlAttributeSet *)&pGStack_2f8,pTVar30);
                  pCVar23 = unaff_EBX;
                  pCVar21 = pCStack_2dc;
                  break;
                }
                pCVar19 = pCVar19 + 1;
                pCVar23 = unaff_EBX;
                pCVar21 = pCStack_2dc;
              } while (pCVar19 < pCVar45);
            }
            goto joined_r0x00994e26;
          }
          uStack_1c = 0xffffffff;
          in_stack_fffffcbc = (CHmsCamera *)0x994ead;
          CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                    (&pSStack_2e8,(CFastBuffer<class_CPlugFileGPUV*> *)in_stack_fffffcc0);
        }
        in_stack_fffffcc0 = (CPlugTree *)0x994eba;
        unaff_EBP = (GmIso3 *)
                    CFastBuffer<class_CCrystalFace*>::GetCount
                              (this_00 + 0x88,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffcc4)
        ;
        if (unaff_EBP != (GmIso3 *)0x0) {
          unaff_EDI = (GmScaleTrans2 *)(*(int *)(pCVar23 + 0x40) + 0x18);
          pCVar35 = (CPlugTree *)0x0;
          pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                              (this_00 + 0x88,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                               (ulong)in_stack_fffffcc8);
          this_03 = *(CPlugTree **)pSVar10;
          while (pCVar23 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1 < unaff_EBX) {
            while( true ) {
              pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                  (this_00 + 0x88,pCVar23,(ulong)pCVar35);
              pCVar35 = *(CPlugTree **)pSVar10;
              iVar6 = CPlugTree::FindTree(this_03,pCVar35,(CPlugTree *)in_stack_fffffcc8);
              if (iVar6 == 0) break;
              pCVar23 = pCVar23 + 1;
              if (unaff_EBX <= pCVar23) goto LAB_00994f20;
            }
            this_03 = *(CPlugTree **)(this_03 + 0x24);
            if (unaff_EBX <= pCVar23) break;
          }
LAB_00994f20:
          in_stack_fffffcc4 = (CPlugShader *)0x1;
          in_stack_fffffcc0 = (CPlugTree *)&uStack_2b8;
          pCStack_308 = (CVisionViewport *)(*(float *)(this_03 + 0x34) + *(float *)(this_00 + 0x68))
          ;
          pCVar23 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                    (*(float *)(this_00 + 0x6c) + *(float *)(this_03 + 0x38));
          fStack_300 = *(float *)(this_00 + 0x70) + *(float *)(this_03 + 0x3c);
          in_stack_fffffcbc = (CHmsCamera *)0x994f69;
          CPlugTree::GetThisToRootTransfo
                    (this_03,in_stack_fffffcc0,(GmIso4 *)0x1,0,in_stack_fffffccc);
          in_stack_fffffccc = (CPlugTree *)unaff_EBP;
          in_stack_fffffcc8 = (CFastBuffer<class_CCrystalFace*> *)0x994f7a;
          unaff_EBP = (GmIso3 *)in_stack_fffffccc;
          GmIso4::Mult(&uStack_2b4,(GmIso3 *)in_stack_fffffccc,(GmIso3 *)pCVar45);
          iVar6 = *(int *)(pCVar23 + 0x50);
          *(float *)(iVar6 + 0x24) =
               fStack_300 * fStack_2b0 + (float)pvStack_2fc * fStack_2ac +
               (float)pGStack_2f8 * fStack_2a8 + fStack_28c;
          *(float *)(iVar6 + 0x28) =
               (float)pGStack_2f8 * fStack_29c +
               (float)pvStack_2fc * fStack_2a0 + fStack_2a4 * fStack_300 + fStack_288;
          *(float *)(iVar6 + 0x2c) =
               fStack_294 * (float)pvStack_2fc + fStack_298 * fStack_300 +
               fStack_290 * (float)pGStack_2f8 + fStack_284;
          pCStack_304 = (CMwCmdScriptVarBool *)pCVar23;
        }
      }
      if ((float)_DAT_00b36298 < *(float *)(this_00 + 0x78)) {
        iVar6 = *(int *)(pCVar23 + 0x50);
        fStack_300 = *(float *)(iVar6 + 0x24) - *(float *)(this_00 + 0x7c);
        pvStack_2fc = (void *)(*(float *)(iVar6 + 0x28) - *(float *)(this_00 + 0x80));
        pGStack_2f8 = (GmScaleTrans2 *)(*(float *)(iVar6 + 0x2c) - *(float *)(this_00 + 0x84));
        fVar25 = (float10)func_0x009c1b40();
        if ((float)fVar25 < *(float *)(this_00 + 0x78)) {
          ExceptionList = pCStack_10;
          return;
        }
      }
    }
    uStack_2b4 = *(undefined4 *)(this + 0x3c0);
    uVar11 = *(uint *)(this + 0x414) & 0xfffffffe | 0x40;
    *(uint *)(this + 0x414) = uVar11;
    *(undefined4 *)(this + 0x3c0) = 0;
    *(CPlugBitmapRenderWater **)(this + 0x420) = this_00;
    *(uint *)(this + 0x414) = (*(uint *)(this_00 + 0x14) >> 0x11 ^ uVar11) & 0x80 ^ uVar11;
    if (((*(uint *)(this_00 + 0x14) & 0x2000000) == 0) || (*(int *)(this + 0x248) == 0)) {
      uVar12 = 0;
    }
    else {
      uVar12 = 1;
    }
    *(undefined4 *)(this + 0x424) = uVar12;
    if (((*(uint *)(this_00 + 0x14) & 0x4000000) == 0) || (*(int *)(this + 0x6c) == 0)) {
      uVar12 = 0;
    }
    else {
      uVar12 = 1;
    }
    *(undefined4 *)(this + 0x428) = uVar12;
    *(uint *)(this + 0x42c) = *(uint *)(this_00 + 0x14) >> 0x1c & 1;
    if ((*(ushort *)(this_00 + 0x20) == 0) ||
       ((*(ushort *)(this_00 + 0x22) & *(ushort *)(this_00 + 0x20)) == 0)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    *(uint *)(this + 0x850) = (uint)!bVar3;
    *(undefined2 *)(this + 900) = 0;
    *(undefined2 *)(this + 0x386) = 0;
    *(undefined2 *)(this + 0x388) = 0;
    *(undefined2 *)(this + 0x38a) = 0;
    if (pCVar7 == (CHmsZone *)0x1) {
      uVar11 = *(uint *)(this_00 + 0x74) >> 1 & 3;
    }
    else {
      uVar11 = 0;
    }
    pTVar16 = (TiXmlAttributeSet *)(pCVar23 + 0x40);
    if (*(int *)(pCVar23 + 0x40) == 0) {
      uVar11 = 1;
    }
    uVar8 = 0xffffffff;
    pCStack_2e0 = (CFastBufferRef<class_CGameMobil> *)0xffffffff;
    if (uVar11 == 0) {
      pCStack_2dc = (CVisionViewportDx9 *)
                    CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x43c,pCVar48);
      pCVar55 = pCVar7;
      CFastBuffer<class_CDx9TextureKeeper*>::Add(this + 0x43c,pTVar16,pTVar5);
      pCVar7 = pCVar18;
      pCVar48 = (CFastBuffer<class_CCrystalFace*> *)pTVar16;
    }
    else {
      *(CMwNodRef<class_CGameCamera> **)(this + 0x448) = unaff_retaddr;
      pCVar55 = pCVar7;
    }
    if (pCVar7 == (CHmsZone *)0x2) {
      if ((pCStack_308 != (CVisionViewport *)0x0) && (pCVar18 != (CHmsZone *)0x0)) {
        if (((byte)this_00[0xc4] & 1) != 0) {
          pGVar46 = (GmVec4 *)0x9951f5;
          unaff_EBP = (GmIso3 *)(**(code **)(*(int *)pCStack_308 + 0x78))();
          if (*(int *)(pCVar18 + 0xbc) == 0) {
            pCStack_2e0 = (CFastBufferRef<class_CGameMobil> *)0x0;
            pCStack_2dc = (CVisionViewportDx9 *)0x3f800000;
            uStack_2d8 = 0;
            pSStack_2d4 = (SCasterCat *)0x0;
          }
          else {
            GmVec4::PlaneEqSetNormPos
                      (&pCStack_2e0,(GmVec4 *)(pCVar18 + 0xd0),(GmVec3 *)(pCVar18 + 0xc4),
                       (GmVec3 *)in_stack_fffffcc8);
          }
          pCVar23 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                    CPlugBitmapRenderWater::UserClipPlaneAdd
                              (this_00,(CPlugBitmapRenderWater *)(this + 0x46c),
                               (CFastBuffer<class_GmVec4> *)&pCStack_2e0,(GmVec4 *)in_stack_fffffcc8
                              );
          unaff_ESI = pCVar23;
          if (pCVar23 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
            CDx9VertexShader::FilterSetVertexShader((CDx9VertexShader *)0x0);
            unaff_EBP = (GmIso3 *)**(float **)(this + 0x9f8);
            in_stack_fffffccc =
                 (CPlugTree *)
                 CFastBuffer<class_GxColor>::operator[]
                           ((CPlugBitmapRenderWater *)(this + 0x46c),pCVar23,
                            (ulong)in_stack_fffffccc);
            (**(code **)(uVar8 + 0xdc))(*(undefined4 *)(this + 0x9f8),pCVar23);
            *(uint *)(this + 0x15a8) = ~(*(uint *)(this_00 + 0xc4) >> 4) & 1;
          }
          pGVar24 = (GmIso4 *)(pCStack_310 + 0x118);
          pGVar26 = (GmFrustum *)GmFrustum::GetFarZ(pGVar24,(GmFrustum *)in_stack_fffffccc);
          pGVar26 = (GmFrustum *)GmFrustum::GetNearZ(pGVar24,pGVar26);
          fVar27 = GmFrustum::GetRatioXY(pGVar24,pGVar26);
          GmFrustum::Set(this_00 + 0x5c,_DAT_00b36190,(int)fVar27);
          CVar1 = this_00[0xc4];
          pCVar18 = pCVar55;
          pCVar20 = this_00 + 0x78;
          for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
            *(undefined4 *)pCVar20 = *(undefined4 *)pCVar18;
            pCVar18 = pCVar18 + 4;
            pCVar20 = pCVar20 + 4;
          }
          if (((byte)CVar1 & 2) != 0) {
            GmIso4::SymmetryPlane(this_00 + 0x78,(GmIso4 *)&uStack_2d8,pGVar46);
          }
        }
        *(uint *)(this_00 + 0xc4) = *(uint *)(this_00 + 0xc4) | 1;
        CFastBuffer<class_CSystemFidsFolder*>::SetCount
                  (this + 0x454,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,(ulong)pCVar48);
        pSVar10 = CFastBuffer<struct_CHmsViewport::SVisualLocation>::operator[]
                            (this + 0x454,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                             (ulong)pTVar5);
        pCVar20 = this_00 + 0x78;
        pGVar22 = (GmScaleTrans2 *)(pSVar10 + 0x30);
        for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined4 *)pGVar22 = *(undefined4 *)pCVar20;
          pCVar20 = pCVar20 + 4;
          pGVar22 = pGVar22 + 4;
        }
        GmIso4::SetInverse(pSVar10,(GmScaleTrans2 *)(pSVar10 + 0x30),unaff_EDI);
        *(uint *)(pCStack_304 + 0xa0) = *(uint *)(pCStack_304 + 0xa0) | 1;
        pCVar39 = pCStack_304;
        (**(code **)(*(int *)this + 0x19c))();
        GmMat3::Set(&fStack_2a8,pCStack_304 + 0x30,(int)pCVar39);
        CFastBuffer<class_CSystemFidsFolder*>::SetCount
                  (this + 0x460,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,(ulong)unaff_ESI);
        pSVar13 = CFastBuffer<struct_CHmsViewport::SClippingFrustum>::operator[]
                            (this + 0x460,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                             (ulong)unaff_EBP);
        CHmsViewport::SClippingFrustum::Set
                  (pSVar13,(CMwCmdScriptVarBool *)(this_00 + 0x5c),(int)(this_00 + 0x78));
        CFastBuffer<class_CSystemFidsFolder*>::SetCount
                  (this + 0x478,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,uVar8);
        pSVar14 = CFastBuffer<struct_SHmsCameraProjection>::operator[]
                            (this + 0x478,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                             (ulong)pCVar55);
        pCVar55 = (CHmsZone *)0x0;
        pSVar13 = pSVar14;
        pGVar22 = pGStack_2f8;
        (**(code **)(*(int *)this + 0x1a0))();
        GmMat4::Set(auStack_254,pCStack_304,(int)pSVar13);
        GmMat4::Mult(auStack_250,(GmIso3 *)pSVar14,(GmIso3 *)pGVar22);
        pCVar18 = (CHmsZone *)(*(uint *)((int)fStack_2ec + 0x20) >> 3 & 1);
        pCVar54 = (CHmsViewport *)&DAT_00000004;
        fVar27 = fStack_2ec;
        func_0x009b4f10();
        pCVar21 = (CVisionViewportDx9 *)0x1;
        if ((*(uint *)(this_00 + 0x14) & 0x10) != 0) {
          pCVar21 = (CVisionViewportDx9 *)((uint)(*(int *)(this + 0x2b8) != 0) * 4 + 3);
        }
        if (((((byte)this_00[0xc4] & 2) == 0) || (((byte)pCStack_304[0xac] & 6) == 0)) ||
           ((*(uint *)(this_00 + 0x14) & 0x20000000) == 0)) {
          pCVar15 = *(CVisionViewportDx9 **)(this_00 + 0x1c);
        }
        else {
          GxBGRAColor::Set(&pCStack_2dc,pCStack_304 + 0x94,0x3f800000);
          pCVar15 = pCStack_2dc;
        }
        RenderTargetClear(this,pCVar21,(ulong)pCVar15,0x3f800000,0.0,(ulong)fVar27);
        pcVar2 = *(code **)(*(int *)this + 0x1a0);
        *(uint *)(this + 0x414) = *(uint *)(this + 0x414) | 1;
        pCVar51 = (CHmsViewport *)0x0;
        pSVar13 = pSVar14;
        (*pcVar2)(pSVar14,pSVar10);
        pCVar48 = (CFastBuffer<class_CCrystalFace*> *)
                  GmMat4::operator[]((GmIso4 *)(pCStack_310 + 0x60),
                                     (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                     (ulong)pSVar13);
        piVar41 = *(int **)(this + 0x9f8);
        (**(code **)(*piVar41 + 0xb0))(piVar41,2);
        *(uint *)(pCStack_310 + 0xa0) = *(uint *)(pCStack_310 + 0xa0) & 0xfffffffd;
        *(undefined4 *)(this + 0x91c) = 3;
        *(undefined4 *)(this + 0x920) = 2;
        CDx9StateBlock::FilterRenderState(0x16,*(ulong *)(this + 0x91c));
        pSVar10 = GmMat4::operator[](pSVar14 + 0x40,
                                     (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                     (ulong)piVar41);
        pGVar36 = *(GmMat3 **)(this + 0x9f8);
        (**(code **)(*(int *)pGVar36 + 0xb0))(pGVar36,3,pSVar10);
        *(uint *)(pSVar14 + 0xcc) = *(uint *)(pSVar14 + 0xcc) & 0xfffffffe;
        *(uint *)(this + 0x414) =
             *(uint *)(this + 0x414) ^
             (*(int *)(this_00 + 0x14) * 4 ^ *(uint *)(this + 0x414)) & 0x10;
        *(undefined2 *)(this + 900) = *(undefined2 *)(this_00 + 0x20);
        *(ushort *)(this + 0x386) = *(ushort *)(this_00 + 0x22) & *(ushort *)(this_00 + 0x20);
        *(undefined2 *)(this + 0x388) = *(undefined2 *)(this_00 + 0x24);
        *(ushort *)(this + 0x38a) = *(ushort *)(this_00 + 0x26) & *(ushort *)(this_00 + 0x24);
        fStack_290 = 0.0;
        fStack_28c = 0.0;
        fStack_288 = 0.0;
        *(undefined4 *)(this + 0x42c) = 0;
        pSVar10 = (SCasterCat *)&fStack_290;
        (**(code **)(*(int *)this + 0x17c))();
        CHmsViewport::RenderZone((CHmsViewport *)this,pCVar51,pCVar18);
        if (((byte)this_00[0xc4] & 0x10) != 0) {
          CPlugBitmapRenderWater::CameraToWorld_Mirror
                    (this_00,(CPlugBitmapRenderWater *)(pCStack_310 + 0x30),(GmIso4 *)pCStack_310,
                     *(GmIso4 **)(pCVar54 + 200),(float)pSVar10);
          *(uint *)(pCStack_310 + 0xa0) = *(uint *)(pCStack_310 + 0xa0) ^ 1;
          pCVar31 = pCStack_310;
          (**(code **)(*(int *)this + 0x19c))();
          pSVar10 = GmMat4::operator[]((GmIso4 *)(pCStack_310 + 0x60),
                                       (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                       (ulong)pCVar31);
          pCVar18 = (CHmsZone *)0x2;
          (**(code **)(**(int **)(this + 0x9f8) + 0xb0))(*(int **)(this + 0x9f8));
          *(uint *)(pCStack_310 + 0xa0) = *(uint *)(pCStack_310 + 0xa0) & 0xfffffffd;
          *(undefined4 *)(this + 0x91c) = 2;
          *(undefined4 *)(this + 0x920) = 3;
          CDx9StateBlock::FilterRenderState(0x16,*(ulong *)(this + 0x91c));
          uVar12 = *(undefined4 *)(this + 0x388);
          *(ushort *)(this + 0x388) = *(ushort *)(this + 0x388) | 2;
          *(ushort *)(this + 0x38a) = *(ushort *)(this + 0x38a) | 2;
          CHmsViewport::RenderZone((CHmsViewport *)this,pCVar54,pCVar18);
          *(undefined4 *)(this + 0x388) = uVar12;
        }
        *(uint *)(this + 0x414) = *(uint *)(this + 0x414) & 0xffffffef;
        if (pCVar48 != (CFastBuffer<class_CCrystalFace*> *)0xffffffff) {
          *(int *)(this + 0x46c) = *(int *)(this + 0x46c) + -1;
        }
        TexRender_RasterizeLensFlares
                  (this,(CVisionViewportDx9 *)pCVar54,aCStack_278,(GmMat4 *)_DAT_00b36190,
                   (float)pSVar10);
        if (((byte)this_00[0xc4] & 0x20) != 0) {
          TexRender_Water_LDirSpecInA
                    (this,pCStack_10,(CPlugBitmap *)this_00,(CPlugBitmapRenderWater *)apCStack_2c0,
                     pGVar36);
        }
        (**(code **)(*(int *)this + 400))(pCVar55);
      }
    }
    else if (pCVar7 == (CHmsZone *)0x1) {
      if (pCVar18 != (CHmsZone *)0x0) {
        uVar42 = 0x9956be;
        CFastBuffer<class_CSystemFidsFolder*>::SetCount
                  (this + 0x454,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,(ulong)pCVar48);
        pTVar16 = (TiXmlAttributeSet *)
                  CFastBuffer<struct_CHmsViewport::SVisualLocation>::operator[]
                            (this + 0x454,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                             (ulong)pTVar5);
        *(uint *)(pTVar16 + 0xa0) = *(uint *)(pTVar16 + 0xa0) | 1;
        CFastBuffer<class_CSystemFidsFolder*>::SetCount
                  (this + 0x460,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,(ulong)unaff_EDI);
        pSVar13 = CFastBuffer<struct_CHmsViewport::SClippingFrustum>::operator[]
                            (this + 0x460,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                             (ulong)unaff_ESI);
        uVar33 = *(ulong *)(this_00 + 100);
        uVar52 = *(ulong *)(this_00 + 0x60);
        pCVar47 = (CHmsCamera *)0x995719;
        pSStack_2d4 = pSVar13;
        GmFrustum::Set(pSVar13,_DAT_00b36190,0x3f800000);
        CFastBuffer<class_CSystemFidsFolder*>::SetCount
                  (this + 0x478,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,uVar52);
        pSVar14 = CFastBuffer<struct_SHmsCameraProjection>::operator[]
                            (this + 0x478,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                             uVar33);
        uVar12 = 0;
        pCVar48 = (CFastBuffer<class_CCrystalFace*> *)0x995748;
        pSVar10 = pSVar13;
        (**(code **)(*(int *)this + 0x1a0))(pSVar14);
        CHmsCamera::CHmsCamera(aCStack_23c,in_stack_fffffcbc);
        uStack_1c = 1;
        uStack_224 = uVar12;
        CHmsCamera::ForceLocation
                  (aCStack_238,(CHmsCamera *)PTR_DAT_00d38fe8,(GmIso4 *)in_stack_fffffcc0);
        CHmsCamera::SetFrustum(aCStack_234,(CHmsCamera *)pSVar13,(GmFrustum *)in_stack_fffffcc4);
        iVar6 = *(int *)(pCStack_310 + 0x50);
        if (iVar6 == 0) {
          pCStack_304 = (CMwCmdScriptVarBool *)0x0;
          pCStack_308 = (CVisionViewport *)0x0;
          pCStack_30c = (CMwCmdScriptVarBool *)0x0;
        }
        else {
          pCStack_30c = *(CMwCmdScriptVarBool **)(iVar6 + 0x24);
          pCStack_308 = *(CVisionViewport **)(iVar6 + 0x28);
          pCStack_304 = *(CMwCmdScriptVarBool **)(iVar6 + 0x2c);
        }
        *(CMwCmdScriptVarBool **)(this_00 + 0x7c) = pCStack_30c;
        *(CVisionViewport **)(this_00 + 0x80) = pCStack_308;
        *(CMwCmdScriptVarBool **)(this_00 + 0x84) = pCStack_304;
        if (((byte)this_00[0x74] & 8) != 0) {
          *(undefined2 *)(this + 900) = *(undefined2 *)(this_00 + 0x20);
          *(ushort *)(this + 0x386) = *(ushort *)(this_00 + 0x20) & *(ushort *)(this_00 + 0x22);
          *(undefined2 *)(this + 0x388) = *(undefined2 *)(this_00 + 0x24);
          *(ushort *)(this + 0x38a) = *(ushort *)(this_00 + 0x24) & *(ushort *)(this_00 + 0x26);
        }
        fStack_28c = 1.4013e-45;
        fStack_288 = 1.4013e-45;
        GxColor::SetFromBGRA
                  (auStack_280,*(GmVec3 **)(this_00 + 0x1c),(uchar *)in_stack_fffffcc8,uVar42);
        fVar27 = 8.40779e-45;
        if (((byte)*(undefined4 *)(this_00 + 0x14) & 3) != 1) {
          fVar27 = *(float *)(this_00 + 0x5c);
        }
        for (; fVar27 != 0.0; fVar27 = (float)((int)fVar27 + -1)) {
          pGVar37 = *(GmScaleTrans2 **)(pCStack_308 + 0x58);
          pGVar43 = (GmVec3 *)0x0;
          pGVar40 = (GmVec3 *)0x1;
          pCVar32 = pCStack_308;
          func_0x009b4f10();
          pGVar22 = (GmScaleTrans2 *)(pTVar16 + 0x30);
          GmMat3::Set(pGVar22,(CMwCmdScriptVarBool *)
                              (&DAT_00d67020 + *(int *)(pCStack_308 + 0x58) * 0x24),(int)pCVar32);
          *(CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> **)
           (pTVar16 + 0x54) = pCStack_310;
          *(float *)(pTVar16 + 0x58) = fVar27;
          *(CVisionViewport **)(pTVar16 + 0x5c) = pCStack_308;
          GmIso4::SetInverse(pTVar16,pGVar22,pGVar37);
          pTVar38 = pTVar16;
          (**(code **)(*(int *)this + 0x19c))();
          pSVar13 = GmMat4::operator[](pTVar16 + 0x60,
                                       (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                       (ulong)pTVar38);
          pGVar24 = *(GmIso4 **)(this + 0x9f8);
          uVar33 = 2;
          (**(code **)(*(int *)pGVar24 + 0xb0))();
          *(uint *)(pTVar16 + 0xa0) = *(uint *)(pTVar16 + 0xa0) & 0xfffffffd;
          CHmsViewport::SClippingFrustum::ComputePlaneEqs
                    (pvStack_2fc,(SClippingFrustum *)pGVar22,pGVar24);
          *(undefined4 *)(this + 0x91c) = 3;
          *(undefined4 *)(this + 0x920) = 2;
          CDx9StateBlock::FilterRenderState(0x16,*(ulong *)(this + 0x91c));
          pSVar14 = GmMat4::operator[]((TiXmlAttributeSet *)(pCVar48 + 0x40),
                                       (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,uVar33)
          ;
          pGVar24 = *(GmIso4 **)(this + 0x9f8);
          uVar33 = 3;
          (**(code **)(*(int *)pGVar24 + 0xb0))();
          CDx9StateBlock::FilterRenderState(7,1);
          *(uint *)(pGVar43 + 0xcc) = *(uint *)(pGVar43 + 0xcc) & 0xfffffffe;
          CHmsCamera::ForceLocation(aCStack_240,(CHmsCamera *)pGVar22,pGVar24);
          pcVar2 = *(code **)(*(int *)this + 0x17c);
          pfVar29 = &fStack_298;
          *(CHmsCamera **)(this + 0x350) = aCStack_23c;
          pCVar18 = (CHmsZone *)0x0;
          (*pcVar2)();
          pEVar28 = (EGxTexFilter *)0x995976;
          pCVar54 = (CHmsViewport *)pCVar48;
          CHmsViewport::RenderZone((CHmsViewport *)this,(CHmsViewport *)pCVar48,pCVar18);
          if (*(int *)(this_00 + 0x94) != 0) {
            pSVar53 = pSVar10;
            if (*(int *)(this + 0x12bc) == 0) {
              pCVar18 = (CHmsZone *)&DAT_0000000a;
              pCVar48 = (CFastBuffer<class_CCrystalFace*> *)0x995995;
              StdShaderLoad(this,(CVisionViewportDx9 *)&DAT_0000000a,(EStdShader2)pfVar29,uVar33);
              pSVar53 = pSVar10;
            }
            fStack_2f0 = *(float *)(this + 0x12bc);
            pCStack_308 = *(CVisionViewport **)(uVar8 + 0x3c);
            puVar17 = (undefined4 *)(**(code **)(*(int *)pCStack_308 + 0x78))();
            pSStack_2e8 = (SNewTriangleVert *)((float)pCVar55 - (float)puVar17[9]);
            puStack_2e4 = (undefined4 *)((float)pCStack_310 - (float)puVar17[10]);
            pCStack_2e0 = (CFastBufferRef<class_CGameMobil> *)(fVar27 - (float)puVar17[0xb]);
            fVar25 = (float10)func_0x009c1b40();
            pGVar50 = (GmVec3 *)((float)fVar25 + *(float *)(this_00 + 0x98));
            CFastBuffer<class_CSystemFidsFolder*>::SetCount
                      (this + 0x538,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,(ulong)pSVar14);
            pCStack_2cc = (CMwCmdScriptVarBool *)
                          CFastBuffer<struct_CHmsViewport::SVisualLocation>::operator[]
                                    (this + 0x538,
                                     (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                     (ulong)pSVar13);
            pSVar10 = (SCasterCat *)pCStack_2cc;
            for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
              *(undefined4 *)pSVar10 = *puVar17;
              puVar17 = puVar17 + 1;
              pSVar10 = pSVar10 + 4;
            }
            GmMat3::GetLine(pCStack_2cc,(GmMat3 *)0x2,(ulong)&pvStack_2fc,pGVar40);
            pSVar10 = (SCasterCat *)pCStack_2c8;
            pGStack_2f8 = (GmScaleTrans2 *)((float)unaff_EBP * (float)pGStack_2f8);
            fStack_2f4 = fStack_2f4 * (float)unaff_EBP;
            fStack_2f0 = fStack_2f0 * (float)unaff_EBP;
            *(float *)(pCStack_2c8 + 0x24) = *(float *)(pCStack_2c8 + 0x24) + (float)pGStack_2f8;
            *(float *)(pCStack_2c8 + 0x28) = fStack_2f4 + *(float *)(pCStack_2c8 + 0x28);
            *(float *)(pCStack_2c8 + 0x2c) = fStack_2f0 + *(float *)(pCStack_2c8 + 0x2c);
            iVar6 = *(int *)(*(int *)(*(int *)(this_00 + 0x94) + 0x48) + 0x18);
            apCStack_2c0[0] =
                 *(CVisionViewportDx9 **)(*(int *)(*(int *)(this_00 + 0x94) + 0x48) + 0x1c);
            unaff_EBP = (GmIso3 *)
                        ((float)unaff_EBP *
                         (*(float *)((int)pvStack_2fc + 300) - *(float *)((int)pvStack_2fc + 0x120))
                         * (float)_DAT_00b313b8 * *(float *)(this_00 + 0x9c));
            fVar34 = (float)iVar6;
            if (iVar6 < 0) {
              fVar34 = fVar34 + _DAT_00c418d0;
            }
            fVar4 = (float)(int)apCStack_2c0[0];
            if ((int)apCStack_2c0[0] < 0) {
              fVar4 = fVar4 + _DAT_00c418d0;
            }
            pvStack_2fc = (void *)((fVar34 * (float)unaff_EBP) / fVar4);
            GmMat3::GetLine(pCStack_2c8,(GmMat3 *)0x0,(ulong)&pGStack_2f8,pGVar43);
            fStack_2f4 = (float)pGStack_2f8 * fStack_2f4;
            fStack_2f0 = fStack_2f0 * (float)pGStack_2f8;
            fStack_2ec = (float)pGStack_2f8 * fStack_2ec;
            GmMat3::SetLine(pSVar10,(GmMat3 *)0x0,(ulong)&fStack_2f4,(GmVec3 *)pCVar47);
            GmMat3::GetLine(pSVar10,(GmMat3 *)0x1,(ulong)&fStack_2f0,(GmVec3 *)pCVar54);
            fStack_2ec = (float)pCStack_310 * fStack_2ec;
            pSStack_2e8 = (SNewTriangleVert *)((float)pSStack_2e8 * (float)pCStack_310);
            puStack_2e4 = (undefined4 *)((float)pCStack_310 * (float)puStack_2e4);
            GmMat3::SetLine(pSVar10,(GmMat3 *)0x1,(ulong)&fStack_2ec,pGVar50);
            pCVar47 = (CHmsCamera *)0x995b7d;
            pTVar16 = (TiXmlAttributeSet *)pSVar10;
            GmIso4::SetMult((SPlugFaceCull *)(pSVar10 + 0x70),(SPlugFaceCull *)pSVar10,
                            (SPlugFaceCull *)pCStack_308,(GmIso4 *)pSVar53);
            (**(code **)(*(int *)this + 0x1a4))();
            pCVar9 = CVisionViewport::ShaderGetKeeper
                               ((CVisionViewport *)this,pCStack_308,in_stack_fffffca8);
            CDx9ShaderKeeper::SetShaderBitmapNoDirty
                      ((CDx9ShaderKeeper *)pCVar9,(CDx9ShaderKeeper *)0x0,*(ulong *)(this_00 + 0x94)
                       ,(CPlugBitmap *)0x0,(CPlugBitmapSampler *)0x0,pEVar28);
            *(undefined2 *)(this + 0x388) = 0;
            *(undefined2 *)(this + 0x38a) = 0;
            RenderShader(this,(CVisionViewportDx9 *)pCStack_308,(CPlugShader *)0x0,
                         (CPlugVisual *)pCVar48);
            *(void **)(this + 0x388) = pvStack_2fc;
            in_stack_fffffca8 = *(CPlugShader **)(this + 0x151c);
            CDx9ShaderKeeper::SetShaderBitmapNoDirty
                      ((CDx9ShaderKeeper *)pCVar9,(CDx9ShaderKeeper *)0x0,(ulong)in_stack_fffffca8,
                       (CPlugBitmap *)0x0,(CPlugBitmapSampler *)0x0,(EGxTexFilter *)pCVar18);
            pCVar54 = (CHmsViewport *)pTVar16;
          }
          (**(code **)(*(int *)this + 400))(0);
          *(undefined4 *)(this + 0x350) = 0;
          *(int *)(pCStack_308 + 0x58) = *(int *)(pCStack_308 + 0x58) + 1;
          if (*(int *)(pCStack_308 + 0x58) == 6) {
            *(undefined4 *)(pCStack_308 + 0x58) = 0;
          }
          pCVar48 = (CFastBuffer<class_CCrystalFace*> *)pCVar54;
        }
        local_c = (void *)0xffffffff;
        CHmsCamera::~CHmsCamera(aCStack_228,pCVar47);
      }
    }
    else if (pCVar7 == (CHmsZone *)&DAT_00000009) {
      pCStack_30c = *(CMwCmdScriptVarBool **)(this_00 + 0x5c);
      pCStack_2dc = *(CVisionViewportDx9 **)(pCStack_30c + 0xec);
      if ((pCStack_2dc != (CVisionViewportDx9 *)0x0) &&
         (this_01 = *(CHmsCorpusLight **)(pCStack_30c + 0xd0), this_01 != (CHmsCorpusLight *)0x0)) {
        uStack_2b8 = *(undefined4 *)(this_01 + 0x14);
        fStack_2f4 = *(float *)(*(int *)(*(int *)(this_01 + 0x48) + 0x88) + 0x68) *
                     (float)_DAT_00b30a18;
        CHmsCorpusLight::GetPosition(this_01,(CGameControlCameraTarget *)&pSStack_2d4);
        pCVar55 = (CHmsZone *)0x3;
        if (*(int *)(this + 0x2b8) != 0) {
          pCVar55 = (CHmsZone *)&DAT_00000007;
        }
        CMwNodRef<class_CGameCamera>::MwSetNod
                  (pCStack_30c + 0x120,unaff_retaddr,(CGameCamera *)pCVar48);
        if (*(CMwNod **)(pCStack_30c + 0x124) != (CMwNod *)0x0) {
          CMwNod::MwRelease(*(CMwNod **)(pCStack_30c + 0x124),(CMwNod *)pTVar5);
          *(undefined4 *)(pCStack_30c + 0x124) = 0;
        }
        *(uint *)(pCStack_30c + 0x1dc) = *(uint *)(pCStack_30c + 0x1dc) & 0xfffffefe | 10;
        *(undefined4 *)(pSStack_2d4 + 0x14) = *(undefined4 *)(*(int *)(param_2 + 0x48) + 0x18);
        *(undefined4 *)(pSStack_2d4 + 0x18) = *(undefined4 *)(*(int *)(param_2 + 0x48) + 0x1c);
        puVar17 = (undefined4 *)(**(code **)(*(int *)this_01 + 0x78))();
        pGVar22 = (GmScaleTrans2 *)(pCStack_30c + 0x30);
        for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined4 *)pGVar22 = *puVar17;
          puVar17 = puVar17 + 1;
          pGVar22 = pGVar22 + 4;
        }
        GmIso4::SetInverse((void *)((int)fStack_300 + 0x60),(GmScaleTrans2 *)(pCStack_30c + 0x30),
                           (GmScaleTrans2 *)unaff_ESI);
        fStack_2b0 = 1.0;
        fStack_2ac = 1.0;
        pCStack_2cc = _DAT_00b2c060;
        pCStack_2c8 = _DAT_00b2c060;
        pCVar48 = (CFastBuffer<class_CCrystalFace*> *)0x3f800000;
        GmFrustum::Set((void *)((int)fStack_300 + 0x14),_DAT_00b2c060,(int)_DAT_00b2c060);
        *(undefined4 *)((int)fStack_300 + 0x118) = 0;
        pCStack_310 = (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *)0x0
        ;
        *(undefined4 *)((int)fStack_300 + 0x114) = 0;
        *(undefined4 *)((int)fStack_300 + 0x110) = 0;
        do {
          iVar6 = 0;
          pCVar44 = (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *)0x1;
          pCVar39 = pCStack_304;
          pCVar31 = pCStack_310;
          func_0x009b4f10();
          this_02 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem
                              (this + 0x454,
                               (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>
                                *)pCVar39);
          pSStack_2e8 = this_02;
          pCStack_2c8 = (CMwCmdScriptVarBool *)
                        CFastBuffer<struct_CHmsViewport::SClippingFrustum>::GetLastElem
                                  (this + 0x460,pCVar31);
          pSStack_2e8 = CFastBuffer<struct_SHmsCameraProjection>::GetLastElem(this + 0x478,pCVar44);
          pGVar22 = (GmScaleTrans2 *)(this_02 + 0x30);
          pGStack_2f8 = pGVar22;
          GmMat3::Set(pGVar22,pCStack_30c,iVar6);
          *(SCasterCat **)(this_02 + 0x54) = pSStack_2d4;
          *(undefined4 *)(this_02 + 0x58) = uStack_2d0;
          *(CMwCmdScriptVarBool **)(this_02 + 0x5c) = pCStack_2cc;
          GmIso4::SetInverse(this_02,pGVar22,(GmScaleTrans2 *)pCVar48);
          pSVar49 = this_02;
          (**(code **)(*(int *)this + 0x19c))();
          pCVar48 = (CFastBuffer<class_CCrystalFace*> *)
                    GmMat4::operator[](this_02 + 0x60,
                                       (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                       (ulong)pSVar49);
          pfVar29 = *(float **)(this + 0x9f8);
          (**(code **)((int)*pfVar29 + 0xb0))(pfVar29,2);
          pCVar39 = pCStack_2c8;
          pCVar18 = pCVar55 + 0x30;
          for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
            *(undefined4 *)pCVar18 = *(undefined4 *)pGVar22;
            pGVar22 = pGVar22 + 4;
            pCVar18 = pCVar18 + 4;
          }
          puVar17 = puStack_2e4;
          pCVar18 = pCVar55 + 0x60;
          for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
            *(undefined4 *)pCVar18 = *puVar17;
            puVar17 = puVar17 + 1;
            pCVar18 = pCVar18 + 4;
          }
          CHmsViewport::SClippingFrustum::Set
                    (pCStack_2c8,(CMwCmdScriptVarBool *)(pCVar55 + 0x14),(int)pvStack_2fc);
          fVar27 = fStack_2ec;
          fVar34 = fStack_2ec;
          (**(code **)(*(int *)this + 0x1a0))(fStack_2ec,pCVar39,0);
          pSVar10 = GmMat4::operator[]((void *)((int)fVar27 + 0x40),
                                       (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                       (ulong)fVar34);
          (**(code **)(**(int **)(this + 0x9f8) + 0xb0))(*(int **)(this + 0x9f8),3,pSVar10);
          Shadow_RenderCaster(this,apCStack_2c0[0],pCVar55,(CPlugVolumeShadow *)0xffffffff,
                              (ulong)unaff_EBP,0,(GmBoxAligned *)this_00,
                              (CPlugBitmapRenderShadow *)0x0,(GmVec4 *)0x0,pfVar29);
          pCStack_30c = pCStack_30c + 0x24;
          pCVar55 = pCVar55 + 1;
          unaff_EBP = unaff_EBP + -1;
        } while (unaff_EBP != (GmIso3 *)0x0);
        if (pCRam00000120 != (CMwNod *)0x0) {
          CMwNod::MwRelease(pCRam00000120,(CMwNod *)pCVar48);
          pCRam00000120 = (CMwNod *)0x0;
        }
        uRam000000d0 = 0;
      }
    }
    *(uint *)(this + 0x414) = *(uint *)(this + 0x414) & 0xffffff3f | 1;
    *(undefined4 *)(this + 0x420) = 0;
    *(undefined4 *)(this + 0x448) = 0;
    *(uint *)(this + 0x424) = (uint)(*(int *)(this + 0x248) != 0);
    *(undefined4 *)(this + 0x44c) = 0;
    *(undefined4 *)(this + 0x42c) = 1;
    *(uint *)(this + 0x428) = (uint)(*(int *)(this + 0x6c) != 0);
    *(undefined4 *)(this + 0x850) = 1;
    *(undefined4 *)(this + 0x3c0) = uStack_2b4;
    if (pCStack_2e0 != (CFastBufferRef<class_CGameMobil> *)0xffffffff) {
      CFastBuffer<class_CNetHttpResult*>::ReplaceByLastAt(this + 0x43c,pCStack_2e0,1,(ulong)pCVar48)
      ;
    }
    if (1 < (*(uint *)(this_00 + 0x14) >> 0xe & 0xff)) {
      TexRender_CubeBlur(this,(CVisionViewportDx9 *)unaff_retaddr,(CPlugBitmap *)0x0,
                         (CPlugBitmap *)&stack0xfffffce8,(ulong *)pCVar48);
      *(uint *)(this_00 + 0x14) =
           *(uint *)(this_00 + 0x14) ^ ((int)pCVar55 << 0xe ^ *(uint *)(this_00 + 0x14)) & 0x3fc000;
    }
    if (((byte)pCStack_304[0x20] & 8) != 0) {
      CDx9TextureKeeper::AutoGenMipMapSetDirty(pCStack_304,(CDx9TextureKeeper *)pCVar48);
    }
    if (((byte)*(uint *)(this_00 + 0x14) & 3) == 1) {
      *(uint *)(this_00 + 0x14) = *(uint *)(this_00 + 0x14) & 0xfffffffc;
    }
  }
  ExceptionList = pCStack_10;
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::TexRender_UpdateTexture
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CVisionViewportDx9::TexRender_UpdateTexture
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2)
{
{
  CVisionViewportDx9 CVar1;
  void *this_00;
  uint uVar2;
  CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
  *this_01;
  int iVar3;
  float fVar4;
  SCasterCat *pSVar5;
  int extraout_EAX;
  SRasterizeVertex *pSVar6;
  int *piVar7;
  CPlugMaterial *pCVar8;
  SCasterCat *pSVar9;
  int iVar10;
  SCasterCat *pSVar11;
  CVisionViewportDx9 *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar12;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBP;
  CPlugBitmap *this_02;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar13;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar14;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EDI;
  CFastBuffer<class_GxVertex2> *pCVar15;
  ulong uVar16;
  float in_stack_0000000c;
  int **ppiVar17;
  int *piVar18;
  undefined1 *puVar19;
  CPlugShader *pCVar20;
  CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
  *pCVar21;
  CPlugBitmap *pCVar22;
  ulong uVar23;
  SGxPixRect *pSVar24;
  CDx9TextureKeeper *pCVar25;
  CFastBuffer<class_GxVertex2> *pCVar26;
  CVisionViewportDx9 *pCVar27;
  CVisionViewportDx9 *pCVar28;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_58;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_54;
  SCasterCat *local_50;
  int *piStack_4c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_48;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_44;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_40;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_3c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_38;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_34;
  SCasterCat *local_30;
  uint local_2c;
  float local_28;
  float local_24;
  float fStack_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  uint local_c;
  uint local_8;
  uint uStack_4;
  
  CVar1 = param_1[0x4d];
  this_02 = *(CPlugBitmap **)(param_1 + 0x14);
  if ((this_02 == (CPlugBitmap *)0x0) || (*(int *)(this + 0x41c) != 0)) {
    return 0;
  }
  *(CVisionViewportDx9 **)(this + 0x41c) = param_1;
  local_40 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1;
  if (*(int *)this_02 != 3) {
    if (*(int *)(this_02 + 0xc) != 0) {
      pCVar12 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(param_1 + 0x74);
      local_48 = pCVar12;
      if (1 < *(int *)(this + 0x32c)) {
        if ((*(int *)(this_02 + 0x3c) == 0) &&
           (iVar10 = (**(code **)(*(int *)pCVar12 + 0x7c))(), iVar10 != 0)) {
          iVar10 = *(int *)(this + 0x238);
          uVar23 = 0x9969c4;
          local_34 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                     CFastBuffer<class_CCrystalFace*>::GetCount((void *)(iVar10 + 0xc),unaff_ESI);
          pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
          pCVar12 = local_48;
          if (local_34 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
            do {
              pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                  ((void *)(iVar10 + 0xc),pCVar14,uVar23);
              iVar3 = *(int *)pSVar11;
              pCVar12 = local_48;
              if (*(int *)(iVar3 + 0x54) != 0) {
                *(int *)(this_02 + 0x3c) = iVar3;
                *(int *)(this_02 + 0x38) = *(int *)(iVar3 + 0x14);
                break;
              }
              pCVar14 = pCVar14 + 1;
            } while (pCVar14 < local_38);
          }
        }
        TexRender_RenderTextureCube(this,param_1,(CPlugBitmap *)unaff_ESI);
        *(undefined4 *)(param_2 + 0x60) = *(undefined4 *)(this + 0x708);
        this_02 = param_2;
      }
      if (((byte)*(int *)(pCVar12 + 0x14) & 3) == 2) {
        *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) & 0xff7fffff;
      }
      if ((*(int *)(pCVar12 + 0x28) != 0) && (*(int *)this_02 == 5)) {
        func_0x009f0ae2(*(undefined4 *)(*(int *)(pCVar12 + 0x28) + 4),4,*(int *)(this_02 + 0xc),0);
        if (*(void **)(pCVar12 + 0x28) != (void *)0x0) {
          CFastStringInt::_scalar_deleting_destructor_
                    (*(void **)(pCVar12 + 0x28),(CPfmHeap *)0x1,(uint)unaff_EDI);
        }
        *(int *)(pCVar12 + 0x28) = 0;
      }
    }
    goto switchD_00996086_caseD_6;
  }
  local_50 = *(SCasterCat **)(this_02 + 8);
  pCVar27 = *(CVisionViewportDx9 **)(this_02 + 0xc);
  switch(CVar1) {
  case (CVisionViewportDx9)0x1:
    piVar7 = *(int **)(param_1 + 0x74);
    pCVar27 = this;
    pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              CFastBuffer<class_CCrystalFace*>::GetCount(piVar7,unaff_ESI);
    if ((pCVar12 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) &&
       (local_58 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0)) {
      local_34 = pCVar12;
      if ((_DAT_00d77bd0 & 1) == 0) {
        _DAT_00d77bd0 = _DAT_00d77bd0 | 1;
        CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                  (&DAT_00d77bc4,(CFastBuffer<class_CPlugFileSndGen*> *)unaff_EDI);
        _atexit(`protected:_int___thiscall_CVisionViewportDx9::
                TexRender_UpdateTexture(class_CPlugBitmap*)'::__l15::
                _dynamic_atexit_destructor_for__SrcRectBuffer__);
      }
      if ((_DAT_00d77bd0 & 2) == 0) {
        _DAT_00d77bd0 = _DAT_00d77bd0 | 2;
        CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                  (&DAT_00d77bb8,unaff_EBP);
        _atexit(`protected:_int___thiscall_CVisionViewportDx9::
                TexRender_UpdateTexture(class_CPlugBitmap*)'::__l15::
                _dynamic_atexit_destructor_for__DstPointBuffer__);
      }
      local_48 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      local_44 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      (**(code **)(*piVar7 + 0x48))(piVar7,0,&local_40);
      local_40 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar12 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pCVar14 = local_40;
          pSVar11 = CFastBuffer<class_GxColor>::operator[](local_58,local_40,(ulong)piVar7);
          piVar18 = *(int **)pSVar11;
          if (piVar18[5] == 0) {
            (**(code **)(*(int *)this + 0xb0))();
            piVar7 = piVar18;
          }
          if (*(int *)(*(int *)pSVar11 + 0x14) != 0) {
            piVar18 = *(int **)(*(int *)(*(int *)pSVar11 + 0x14) + 0xc);
            puVar19 = &stack0xffffffa4;
            uVar23 = 0;
            (**(code **)(*piVar18 + 0x48))();
            pCVar26 = *(CFastBuffer<class_GxVertex2> **)(pSVar11 + 4);
            pCVar15 = *(CFastBuffer<class_GxVertex2> **)(pSVar11 + 8);
            if (*(CFastBuffer<class_GxVertex2> **)(pSVar11 + 8) <= pCVar26) {
              pCVar15 = pCVar26;
            }
            if (pCVar26 == (CFastBuffer<class_GxVertex2> *)0x0) {
              CFastBuffer<class_GmVec4>::AllocSetCount(&DAT_00d77bc4,pCVar15,(ulong)piVar18);
              pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
              pSVar9 = DAT_00d77bc8;
              if (pCVar15 != (CFastBuffer<class_GxVertex2> *)0x0) {
                do {
                  pSVar9 = CFastBuffer<class_GxColor>::operator[](&DAT_00d77bc4,pCVar12,uVar23);
                  *(undefined4 *)(pSVar9 + 4) = 0;
                  *(undefined4 *)pSVar9 = 0;
                  *(undefined4 *)(pSVar9 + 8) =
                       *(undefined4 *)(*(int *)(*(int *)pSVar11 + 0x48) + 0x18);
                  pCVar12 = pCVar12 + 1;
                  *(undefined4 *)(pSVar9 + 0xc) =
                       *(undefined4 *)(*(int *)(*(int *)pSVar11 + 0x48) + 0x1c);
                  pSVar9 = DAT_00d77bc8;
                } while (pCVar12 < pCVar15);
              }
            }
            else {
              pSVar9 = CFastBuffer<class_GxColor>::operator[]
                                 (unaff_EBX + 0xc,
                                  (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar27,
                                  (ulong)piVar18);
            }
            pCVar26 = pCVar15;
            if (*(int *)(pSVar11 + 8) == 0) {
              CFastBuffer<struct_CPlugModelMesh::SPoly>::AllocSetCount(&DAT_00d77bb8,pCVar15,uVar23)
              ;
              pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
              pSVar5 = DAT_00d77bbc;
              this = unaff_EBX;
              if (pCVar15 != (CFastBuffer<class_GxVertex2> *)0x0) {
                do {
                  pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                                     (&DAT_00d77bb8,pCVar12,(ulong)puVar19);
                  pCVar12 = pCVar12 + 1;
                  *(undefined4 *)(pSVar5 + 4) = 0;
                  *(undefined4 *)pSVar5 = 0;
                  pSVar5 = DAT_00d77bbc;
                  this = unaff_EBX;
                } while (pCVar12 < pCVar15);
              }
            }
            else {
              pSVar5 = CFastBuffer<struct_SFastCat>::operator[](pCVar27 + 0x18,local_58,uVar23);
              this = unaff_EBX;
            }
            for (; pCVar26 != (CFastBuffer<class_GxVertex2> *)0x0; pCVar26 = pCVar26 + -1) {
              (**(code **)(**(int **)(pSVar9 + 0x9f8) + 0x78))
                        (*(int **)(pSVar9 + 0x9f8),pCVar27,unaff_EBX,local_50,pSVar5);
              unaff_EBX = unaff_EBX + 0x10;
              pSVar5 = pSVar5 + 8;
              this = (CVisionViewportDx9 *)0x0;
            }
            if (pCVar15 == (CFastBuffer<class_GxVertex2> *)0x0) {
              (**(code **)(**(int **)(pSVar9 + 0x9f8) + 0x78))
                        (*(int **)(pSVar9 + 0x9f8),pCVar27,0,local_50,0);
            }
            (**(code **)(*(int *)pCVar27 + 8))(pCVar27);
            local_50 = local_50 + *(int *)(pSVar11 + 8);
            pCVar12 = local_3c;
            pCVar14 = local_40;
            unaff_EBX = this;
          }
          local_40 = pCVar14 + 1;
        } while (local_40 < pCVar12);
      }
      (**(code **)(*piStack_4c + 8))(piStack_4c);
      *(int *)(param_2 + 0x60) = *(int *)(this + 0x708);
    }
    break;
  case (CVisionViewportDx9)0x2:
    piVar7 = *(int **)(param_1 + 0x74);
    if ((pCVar27 != (CVisionViewportDx9 *)0x0) &&
       (pCVar28 = this, iVar10 = func_0x009b4e70(this_02,0,0,*(uint *)(this_02 + 0x20) >> 3 & 1,0),
       iVar10 != 0)) {
      CDx9StateBlock::LockRenderState(0x1c,0);
      iVar10 = *(int *)(*(int *)(*piVar7 + 0x48) + 0x18);
      local_34 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                  (*(int *)(*piVar7 + 0x48) + 0x1c);
      fVar4 = (float)iVar10;
      if (iVar10 < 0) {
        fVar4 = fVar4 + _DAT_00c418d0;
      }
      local_1c = (float)piVar7[1];
      if (piVar7[1] < 0) {
        local_1c = local_1c + _DAT_00c418d0;
      }
      local_1c = local_1c / fVar4;
      local_14 = (float)piVar7[3];
      if (piVar7[3] < 0) {
        local_14 = local_14 + _DAT_00c418d0;
      }
      local_14 = local_14 / fVar4;
      local_38 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(float)(int)local_34;
      if ((int)local_34 < 0) {
        local_38 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   ((float)local_38 + _DAT_00c418d0);
      }
      local_18 = (float)piVar7[4];
      if (piVar7[4] < 0) {
        local_18 = local_18 + _DAT_00c418d0;
      }
      local_18 = local_18 / (float)local_38;
      local_10 = (float)piVar7[2];
      if (piVar7[2] < 0) {
        local_10 = local_10 + _DAT_00c418d0;
      }
      local_10 = local_10 / (float)local_38;
      RasterizeQuadAlloc(this,(CVisionViewportDx9 *)0x1,0,(int)unaff_EDI);
      local_30 = (SCasterCat *)(1.0 - (float)piVar7[9]);
      __ftol2_sse();
      if (extraout_EAX < 0) {
        iVar10 = 0;
      }
      else {
        iVar10 = extraout_EAX;
        if (0xff < extraout_EAX) {
          iVar10 = 0xff;
        }
      }
      local_40 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3f800000;
      local_3c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3f800000;
      local_30 = (SCasterCat *)_DAT_00b2c060;
      local_8 = _DAT_00b2c060;
      local_2c = _DAT_00b2c060;
      uStack_4 = _DAT_00b2c060;
      pSVar6 = RasterizeQuadAdd(this,iVar10 << 0x18 | 0xffffff,&local_8,0,0x3f800000,&local_18);
      local_28 = (float)piVar7[5];
      if (piVar7[5] < 0) {
        local_28 = local_28 + _DAT_00c418d0;
      }
      local_28 = local_28 / in_stack_0000000c;
      fStack_20 = (float)piVar7[7];
      if (piVar7[7] < 0) {
        fStack_20 = fStack_20 + _DAT_00c418d0;
      }
      fStack_20 = fStack_20 / in_stack_0000000c;
      local_24 = (float)piVar7[8];
      if (piVar7[8] < 0) {
        local_24 = local_24 + _DAT_00c418d0;
      }
      local_24 = local_24 / (float)local_34;
      local_1c = (float)piVar7[6];
      if (piVar7[6] < 0) {
        local_1c = local_1c + _DAT_00c418d0;
      }
      local_1c = local_1c / (float)local_34;
      RasterizeQuadSetUV1(this,(CVisionViewportDx9 *)pSVar6,(SRasterizeVertex *)&local_28,
                          (GmRectAligned *)unaff_EBP);
      SetStageTexture(this,(CVisionViewportDx9 *)*piVar7,(CPlugBitmap *)0x0,(ulong)unaff_EBX);
      pCVar25 = (CDx9TextureKeeper *)0x9964dd;
      SetStageTexture(this,(CVisionViewportDx9 *)*piVar7,(CPlugBitmap *)0x1,(ulong)pCVar28);
      RasterizeQuads(this,this + 0x10f4,(CDx9StateBlock *)pCVar27);
      if (((byte)this_02[0x20] & 8) != 0) {
        CDx9TextureKeeper::AutoGenMipMapSetDirty(this_02,pCVar25);
      }
      CDx9StateBlock::UnlockRenderState(0x1c,(ulong)pCVar25);
      *(int *)(this_02 + 0x60) = *(int *)(this + 0x708);
    }
    break;
  case (CVisionViewportDx9)0x3:
    this_00 = *(void **)(param_1 + 0x74);
    local_44 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
    uVar2 = *(uint *)(this_02 + 0x18);
    local_38 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               (((uVar2 & 0xffffff00) << 0xc | uVar2 & 0xfc000) << 6 |
                (uVar2 >> 0xc & 0xfc000 | uVar2 & 0x3f00000) >> 6 | uVar2 & 0xff);
    this = pCVar27;
    if (*(int *)((int)this_00 + 0x10) != 0) {
      DAT_00d756a4 = this_02;
      if ((*(int *)((int)this_00 + 0xc) == 0) || (local_50 == (SCasterCat *)0x0)) {
        if ((local_44 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) ||
           (local_50 == (SCasterCat *)0x0)) goto LAB_00996670;
        pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        pCVar28 = pCVar27;
        if (local_44 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          do {
            local_30 = CFastBuffer<class_GxColor>::operator[](this_00,pCVar12,(ulong)unaff_EDI);
            unaff_EDI = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
            (**(code **)(*(int *)local_50 + 0x4c))(local_50,0,&local_28,local_30);
            (**(code **)**(undefined4 **)((int)this_00 + 0x10))
                      (param_1,local_44,&local_48,local_38,local_3c);
            (**(code **)(*(int *)local_50 + 0x50))(local_50,0);
            pCVar12 = pCVar12 + 1;
            pCVar28 = pCVar27;
          } while (pCVar12 < local_44);
        }
        pCVar27 = pCVar28;
        (**(code **)(**(int **)(pCVar28 + 0x9f8) + 0x7c))(*(int **)(pCVar28 + 0x9f8),local_50);
        CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
                  (this_00,(GmFrustumIso4 *)local_58);
        piVar7 = *(int **)(pCVar28 + 0x708);
      }
      else {
        *(undefined4 *)((int)this_00 + 0xc) = 0;
        (**(code **)(*(int *)local_50 + 0x4c))(local_50,0,&local_2c,0,0);
        ppiVar17 = &piStack_4c;
        pCVar12 = local_3c;
        (**(code **)**(undefined4 **)((int)this_00 + 0x10))(param_1,0,ppiVar17,local_3c,local_40);
        (**(code **)(*(int *)local_50 + 0x50))(local_50,0);
        (**(code **)(*ppiVar17[0x27e] + 0x7c))(ppiVar17[0x27e],local_50,pCVar12);
        piVar7 = ppiVar17[0x1c2];
      }
      *(int **)(param_2 + 0x60) = piVar7;
      this = pCVar27;
    }
LAB_00996670:
    DAT_00d756a4 = (CPlugBitmap *)0x0;
    break;
  case (CVisionViewportDx9)0x4:
    pCVar12 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(param_1 + 0x74);
    if ((pCVar27 != (CVisionViewportDx9 *)0x0) && (((byte)pCVar12[0x14] & 3) != 0)) {
      if (1 < *(int *)(this + 0x32c)) {
        local_48 = pCVar12;
        if ((*(int *)(this_02 + 0x3c) == 0) &&
           (iVar10 = (**(code **)(*(int *)pCVar12 + 0x7c))(), iVar10 != 0)) {
          iVar10 = *(int *)(this + 0x238);
          uVar23 = 0x9966cc;
          local_30 = (SCasterCat *)
                     CFastBuffer<class_CCrystalFace*>::GetCount
                               ((void *)(iVar10 + 0xc),(CFastBuffer<class_CCrystalFace*> *)unaff_EDI
                               );
          pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
          pCVar12 = local_44;
          if (local_30 != (SCasterCat *)0x0) {
            do {
              pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                  ((void *)(iVar10 + 0xc),pCVar14,uVar23);
              iVar3 = *(int *)pSVar11;
              pCVar12 = local_44;
              if (*(int *)(iVar3 + 0x54) != 0) {
                *(int *)(param_2 + 0x3c) = iVar3;
                *(undefined4 *)(param_2 + 0x38) = *(undefined4 *)(iVar3 + 0x14);
                break;
              }
              pCVar14 = pCVar14 + 1;
            } while (pCVar14 < local_34);
          }
        }
        if ((*(int *)(param_2 + 0x3c) == 0) || (*(int *)(*(int *)(param_2 + 0x3c) + 0x54) != 0)) {
          TexRender_RenderTexture
                    (this,param_1,(CPlugBitmap *)0x0,(CPlugBitmapRender *)0x0,
                     (CFixedArray<class_CPlugBitmap*,4,unsigned_long> *)unaff_EDI);
          *(undefined4 *)((int)in_stack_0000000c + 0x60) = *(undefined4 *)(this + 0x708);
        }
      }
      if (((byte)*(int *)(pCVar12 + 0x14) & 3) == 2) {
        *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) & 0xff7fffff;
      }
    }
    break;
  case (CVisionViewportDx9)0x5:
    pCVar8 = CSysFidNodRef<class_CPlugMaterial>::GetNod
                       ((void *)(*(int *)(param_1 + 0x74) + 0x18),
                        (CSysFidNodRef<class_CPlugMaterial> *)unaff_ESI);
    if (pCVar8 != (CPlugMaterial *)0x0) {
      pSVar24 = (SGxPixRect *)0x0;
      pCVar22 = (CPlugBitmap *)0x0;
      pCVar20 = (CPlugShader *)0x0;
      pCVar8 = CSysFidNodRef<class_CPlugMaterial>::GetNod
                         ((void *)(*(int *)(param_1 + 0x74) + 0x18),
                          (CSysFidNodRef<class_CPlugMaterial> *)param_1);
      RenderShaderOnFullQuad
                (this,(CVisionViewportDx9 *)pCVar8,pCVar20,pCVar22,pSVar24,(CPlugVisual *)unaff_EDI,
                 (SRenderShaderParam *)unaff_EBP);
    }
    *(int *)(this_02 + 0x60) = *(int *)(this + 0x708);
    *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) & 0xff7fffff;
    break;
  case (CVisionViewportDx9)0x7:
    this_01 = *(CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
                **)(param_1 + 0x74);
    pCVar28 = this;
    local_48 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(this_01,unaff_ESI);
    pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    local_1c = -NAN;
    local_14 = 0.0;
    local_18 = -NAN;
    local_10 = 0.0;
    local_38 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1;
    if (local_48 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar11 = CFastBuffer<struct_CPlugBitmap::SSpecularSubMapCat>::operator[]
                            (this_01,pCVar12,(ulong)unaff_EDI);
        if (*(int *)(pSVar11 + 4) != 0) {
          unaff_EDI = pCVar12;
          pSVar11 = CFastBuffer<struct_CPlugBitmap::SSpecularSubMapCat>::operator[]
                              (this_01,pCVar12,(ulong)unaff_EBP);
          if (*(uint *)(pSVar11 + 8) < (uint)local_14) {
            local_14 = (float)*(uint *)(pSVar11 + 8);
          }
          if (*(uint *)(pSVar11 + 0xc) < (uint)local_10) {
            local_10 = (float)*(uint *)(pSVar11 + 0xc);
          }
          if (local_c < *(uint *)(pSVar11 + 0x10)) {
            local_c = *(uint *)(pSVar11 + 0x10);
          }
          if (local_8 < *(uint *)(pSVar11 + 0x14)) {
            local_8 = *(uint *)(pSVar11 + 0x14);
          }
          local_30 = (SCasterCat *)0x0;
        }
        pCVar12 = pCVar12 + 1;
      } while (pCVar12 < local_48);
      if (local_38 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        local_44 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uint)(byte)param_2[0x18];
        pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&local_1c;
        pCVar21 = (CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
                   *)&local_2c;
        uVar23 = 0;
        pSVar11 = local_50;
        (**(code **)(*(int *)local_50 + 0x4c))();
        pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        do {
          pCVar13 = pCVar14;
          pSVar9 = CFastBuffer<struct_CPlugBitmap::SSpecularSubMapCat>::operator[]
                             (this_01,pCVar14,(ulong)pSVar11);
          if (*(int *)(pSVar9 + 4) != 0) {
            local_40 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                       CFastBuffer<struct_CPlugBitmap::SSpecularSubMapCat>::operator[]
                                 (pCVar13,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar28,
                                  uVar23);
            pCVar13 = local_34 +
                      (*(int *)(local_40 + 8) - (int)local_28) * (int)local_50 +
                      (*(int *)(local_40 + 0xc) - (int)local_24) * (int)local_38;
            uVar23 = *(int *)(local_40 + 0x14) - *(int *)(local_40 + 0xc);
            uVar16 = *(int *)(local_40 + 0x10) - *(int *)(local_40 + 8);
            pSVar11 = (SCasterCat *)pCVar27;
            CPlugBitmap::DynaMapBegin
                      (uVar16,uVar23,(ulong)local_50,(uchar *)pCVar13,(ulong)local_38);
            pCVar27 = (CVisionViewportDx9 *)pSVar11;
            local_40 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                       CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
                       ::SetParsingCat(pCVar28,(CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat>
                                                *)pSVar11,1,(ulong)pCVar21);
            pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
            this = pCVar28;
            if (local_40 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
              local_3c = local_3c + 0x3c;
              do {
                pSVar9 = CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
                         ::operator[](pCVar27,pCVar14,(ulong)pCVar12);
                pSVar11 = local_30;
                pCVar12 = local_38;
                CPlugBitmap::DynaMapAddSpecular
                          (uVar16,uVar23,local_48,pCVar13,local_30,pSVar9 + 4,*(undefined4 *)pSVar9)
                ;
                pCVar14 = pCVar14 + 1;
              } while (pCVar14 < local_3c);
            }
            uVar23 = 0x996932;
            pCVar21 = this_01;
            CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
            ::ResetCat(pCVar27,this_01,(ulong)pCVar12);
            pCVar14 = local_54;
            pCVar28 = this;
          }
          pCVar14 = pCVar14 + 1;
        } while (pCVar14 < pCVar27);
        (**(code **)(*(int *)local_50 + 0x50))(local_50,0);
        (**(code **)(**(int **)(this + 0x9f8) + 0x7c))(*(int **)(this + 0x9f8),local_50,pCVar12);
        *(int *)(param_2 + 0x60) = *(int *)(this + 0x708);
      }
    }
  }
switchD_00996086_caseD_6:
  *(int *)(this + 0x41c) = 0;
  return (int)local_3c;
}
}

// =================================================
// Function: CVisionViewportDx9::TexRender_UpdateTextures
// =================================================
void __thiscall
CVisionViewportDx9::TexRender_UpdateTextures(CVisionViewportDx9 *this,CVisionViewportDx9 *param_1)
{
{
  CFastBuffer<struct_CDx9StateBlock::STexStageState> *this_00;
  char cVar1;
  int *piVar2;
  CVisionViewportDx9 *pCVar3;
  int iVar4;
  CFastBuffer<class_GxVertex2> *pCVar5;
  SCasterCat *pSVar6;
  uint uVar7;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  GmFrustumIso4 *unaff_EBP;
  CFastBuffer<struct_CDx9StateBlock::STexStageState> *unaff_ESI;
  uint uVar8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  CFastBuffer<class_GxVertex2> *pCVar10;
  code *unaff_EDI;
  int *piVar11;
  ulong in_stack_00000008;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  ulong in_stack_ffffffdc;
  CFastBuffer<class_CGamePlayerScore*> *in_stack_ffffffe0;
  CSystemFid *pCVar12;
  code *in_stack_ffffffe4;
  CVisionViewportDx9 *pCVar13;
  ulong in_stack_ffffffec;
  ulong uVar14;
  CFastBuffer<class_GxVertex2> *local_c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&LAB_00aeb14e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar13 = this;
  iVar4 = RenderTargetPushEmpty(this,(CVisionViewportDx9 *)(DAT_00cca150 ^ (uint)&stack0xffffffcc));
  if (iVar4 != 0) {
    uVar14 = DAT_00d76a48;
    CDx9StateBlock::FilterRenderState(0x1a,0);
    local_c = (CFastBuffer<class_GxVertex2> *)(uint)(*(int *)(this + 0x15a4) == 0);
    if ((local_c != (CFastBuffer<class_GxVertex2> *)0x0) &&
       (iVar4 = (**(code **)(**(int **)(this + 0x9f8) + 0xa4))(*(int **)(this + 0x9f8)), -1 < iVar4)
       ) {
      *(undefined4 *)(this + 0x15a4) = 1;
    }
    if ((DAT_00d77c04 & 1) == 0) {
      DAT_00d77c04 = DAT_00d77c04 | 1;
      CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                (&DAT_00d77bf8,(CFastBuffer<class_CPlugFileSndGen*> *)unaff_EDI);
      unaff_EDI = `protected:_void___thiscall_CVisionViewportDx9::TexRender_UpdateTextures(void)'::
                  __l7::_dynamic_atexit_destructor_for__TexturePixelUpdates__;
      _atexit(`protected:_void___thiscall_CVisionViewportDx9::TexRender_UpdateTextures(void)'::__l7
              ::_dynamic_atexit_destructor_for__TexturePixelUpdates__);
    }
    if ((DAT_00d77c04 & 2) == 0) {
      DAT_00d77c04 = DAT_00d77c04 | 2;
      CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                (&DAT_00d77bec,(CFastBuffer<class_CPlugFileSndGen*> *)unaff_EDI);
      unaff_EDI = `protected:_void___thiscall_CVisionViewportDx9::TexRender_UpdateTextures(void)'::
                  __l7::_dynamic_atexit_destructor_for__TextureRecurLevels__;
      _atexit(`protected:_void___thiscall_CVisionViewportDx9::TexRender_UpdateTextures(void)'::__l7
              ::_dynamic_atexit_destructor_for__TextureRecurLevels__);
    }
    this_00 = (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)(this + 0x15b0);
    CFastBuffer<class_CGameFid*>::CopyFromFastBuffer
              (&DAT_00d77bf8,this_00,(CFastBuffer<struct_CDx9StateBlock::STexStageState> *)unaff_EDI
              );
    CFastBuffer<class_CGameFid*>::CopyFromFastBuffer(this + 0x15bc,this_00,unaff_ESI);
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this_00,unaff_EBP);
    pCVar5 = (CFastBuffer<class_GxVertex2> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d77bf8,unaff_EBX);
    CFastBuffer<class_GmVector2<unsigned_short>_>::AllocSetCount
              (&DAT_00d77bec,pCVar5,in_stack_ffffffdc);
    local_c = (CFastBuffer<class_GxVertex2> *)0x0;
    if (pCVar5 != (CFastBuffer<class_GxVertex2> *)0x0) {
      do {
        pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (&DAT_00d77bf8,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)local_c,
                            (ulong)in_stack_ffffffe0);
        iVar4 = *(int *)pSVar6;
        cVar1 = *(char *)(iVar4 + 0x4d);
        piVar11 = (int *)0x0;
        in_stack_ffffffe0 = (CFastBuffer<class_CGamePlayerScore*> *)local_8;
        pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (&DAT_00d77bec,local_8,(ulong)in_stack_ffffffe4);
        *(undefined4 *)pSVar6 = 0;
        if (cVar1 == '\x05') {
          iVar4 = *(int *)(iVar4 + 0x74);
          pCVar12 = (CSystemFid *)in_stack_ffffffe0;
          if (*(int *)(iVar4 + 0x1c) == 0) {
            pCVar12 = *(CSystemFid **)(iVar4 + 0x18);
            if (pCVar12 == (CSystemFid *)0x0) {
              piVar11 = (int *)0x0;
              goto LAB_00996cc2;
            }
            in_stack_ffffffe4 = (code *)&DAT_00000007;
            CSystemArchiveNod::LoadFromFid((CMwNod **)&param_1,pCVar12,7);
            pCVar3 = param_1;
            if ((param_1 != (CVisionViewportDx9 *)0x0) &&
               (param_1 != *(CVisionViewportDx9 **)(iVar4 + 0x1c))) {
              in_stack_ffffffe4 = (code *)0x996c1a;
              CMwNod::MwAddRef((CMwNod *)param_1,(CMwNod *)pCVar12);
              if (*(CMwNod **)(iVar4 + 0x1c) != (CMwNod *)0x0) {
                pCVar13 = (CVisionViewportDx9 *)0x996c26;
                CMwNod::MwRelease(*(CMwNod **)(iVar4 + 0x1c),(CMwNod *)pCVar12);
              }
              *(CVisionViewportDx9 **)(iVar4 + 0x1c) = pCVar3;
            }
          }
          piVar11 = *(int **)(iVar4 + 0x1c);
          in_stack_ffffffe0 = (CFastBuffer<class_CGamePlayerScore*> *)pCVar12;
LAB_00996cc2:
          if (piVar11 != (int *)0x0) {
            uVar7 = (**(code **)(*piVar11 + 0x98))();
            uVar8 = 0;
            if (uVar7 != 0) {
              do {
                iVar4 = (**(code **)(*piVar11 + 0x9c))();
                local_8 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar4 + 0x1c);
                if (local_8[0x4d] == (CFastBuffer<struct_CVisionHmsZone::SCasterCat>)0x5) {
                  pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                     (&DAT_00d77bec,
                                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)local_c,
                                      (ulong)in_stack_ffffffe0);
                  in_stack_ffffffe0 = (CFastBuffer<class_CGamePlayerScore*> *)&uStack_4;
                  *(undefined4 *)pSVar6 = 1;
                  CFastBuffer<class_CGamePlayerScore*>::FindOrAdd
                            (&DAT_00d77bf8,in_stack_ffffffe0,(CGamePlayerScore **)in_stack_ffffffe4)
                  ;
                  pCVar5 = (CFastBuffer<class_GxVertex2> *)
                           CFastBuffer<class_CCrystalFace*>::GetCount
                                     (&DAT_00d77bf8,(CFastBuffer<class_CCrystalFace*> *)pCVar13);
                  in_stack_ffffffe4 = (code *)0x996d35;
                  pCVar13 = (CVisionViewportDx9 *)pCVar5;
                  CFastBuffer<class_GmVector2<unsigned_short>_>::AllocSetCount
                            (&DAT_00d77bec,pCVar5,in_stack_ffffffec);
                }
                uVar8 = uVar8 + 1;
              } while (uVar8 < uVar7);
            }
          }
        }
        else if (cVar1 == '\x04') {
          piVar2 = *(int **)(iVar4 + 0x74);
          in_stack_ffffffe4 = (code *)0x996c48;
          iVar4 = (**(code **)(*piVar2 + 0x78))();
          if (iVar4 == 4) {
            if ((piVar2[0x2c] & 3U) != 0) {
              local_8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)piVar2[0x17];
            }
            if ((piVar2[0x2c] & 0xcU) != 0) {
              piVar11 = (int *)piVar2[0x18];
            }
          }
          else {
            if (iVar4 != 1) goto LAB_00996d3c;
            local_8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)piVar2[0x25];
          }
          if ((local_8 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) &&
             (local_8[0x4d] != (CFastBuffer<struct_CVisionHmsZone::SCasterCat>)0x0)) {
            pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (&DAT_00d77bec,
                                (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)local_c,
                                (ulong)in_stack_ffffffe0);
            in_stack_ffffffe0 = (CFastBuffer<class_CGamePlayerScore*> *)&uStack_4;
            *(undefined4 *)pSVar6 = 1;
            CFastBuffer<class_CGamePlayerScore*>::FindOrAdd
                      (&DAT_00d77bf8,in_stack_ffffffe0,(CGamePlayerScore **)in_stack_ffffffe4);
            pCVar5 = (CFastBuffer<class_GxVertex2> *)
                     CFastBuffer<class_CCrystalFace*>::GetCount
                               (&DAT_00d77bf8,(CFastBuffer<class_CCrystalFace*> *)pCVar13);
            in_stack_ffffffe4 = (code *)0x996cc2;
            pCVar13 = (CVisionViewportDx9 *)pCVar5;
            CFastBuffer<class_GmVector2<unsigned_short>_>::AllocSetCount
                      (&DAT_00d77bec,pCVar5,in_stack_ffffffec);
          }
          goto LAB_00996cc2;
        }
LAB_00996d3c:
        local_c = local_c + 1;
      } while (local_c < pCVar5);
      this = (CVisionViewportDx9 *)0x0;
    }
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
              (this + 0x878,(GmFrustumIso4 *)in_stack_ffffffe0);
    pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar5 != (CFastBuffer<class_GxVertex2> *)0x0) {
      do {
        pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (&DAT_00d77bf8,pCVar9,(ulong)in_stack_ffffffe4);
        in_stack_00000008 = *(ulong *)pSVar6;
        if ((*(char *)(in_stack_00000008 + 0x4d) == '\x04') &&
           ((*(uint *)(*(int *)(in_stack_00000008 + 0x74) + 0x18) & 0x8000) != 0)) {
          CFastBuffer<class_CDx9TextureKeeper*>::Add
                    (this + 0x878,(TiXmlAttributeSet *)&stack0x00000008,(TiXmlAttribute *)pCVar13);
          CFastBuffer<class_CNetHttpResult*>::ReplaceByLastAt
                    (&DAT_00d77bf8,(CFastBufferRef<class_CGameMobil> *)pCVar9,1,in_stack_ffffffec);
          in_stack_ffffffec = 1;
          in_stack_ffffffe4 = (code *)0x996db9;
          pCVar13 = (CVisionViewportDx9 *)pCVar9;
          CFastBuffer<class_CNetHttpResult*>::ReplaceByLastAt
                    (&DAT_00d77bec,(CFastBufferRef<class_CGameMobil> *)pCVar9,1,uVar14);
          pCVar9 = pCVar9 + -1;
          pCVar5 = pCVar5 + -1;
        }
        pCVar9 = pCVar9 + 1;
      } while (pCVar9 < pCVar5);
    }
    if ((DAT_00d77c04 & 4) == 0) {
      DAT_00d77c04 = DAT_00d77c04 | 4;
      in_stack_00000018 = 0;
      CFastRadixSort::CFastRadixSort(&DAT_00d77bd4,(CFastRadixSort *)in_stack_ffffffe4);
      in_stack_ffffffe4 =
           `protected:_void___thiscall_CVisionViewportDx9::TexRender_UpdateTextures(void)'::__l45::
           _dynamic_atexit_destructor_for__SortTextures__;
      _atexit(`protected:_void___thiscall_CVisionViewportDx9::TexRender_UpdateTextures(void)'::__l45
              ::_dynamic_atexit_destructor_for__SortTextures__);
      in_stack_0000001c = 0xffffffff;
    }
    CFastRadixSort::Sort(&DAT_00d77bd4,DAT_00d77bf0,(float *)pCVar5,0);
    iVar4 = DAT_00d77bdc;
    pCVar10 = (CFastBuffer<class_GxVertex2> *)0x0;
    if (pCVar5 != (CFastBuffer<class_GxVertex2> *)0x0) {
      do {
        pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (&DAT_00d77bf8,
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                             (iVar4 + (int)pCVar10 * 4),(ulong)in_stack_ffffffe4);
        in_stack_ffffffe4 = *(code **)pSVar6;
        TexRender_UpdateTexture(this,(CVisionViewportDx9 *)in_stack_ffffffe4,(CPlugBitmap *)pCVar13)
        ;
        pCVar10 = pCVar10 + 1;
      } while (pCVar10 < pCVar5);
    }
    pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar5 != (CFastBuffer<class_GxVertex2> *)0x0) {
      do {
        pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (&DAT_00d77bf8,pCVar9,(ulong)in_stack_ffffffe4);
        in_stack_00000008 = *(ulong *)pSVar6;
        if (*(char *)(in_stack_00000008 + 0x4d) == '\x05') {
          pCVar13 = *(CVisionViewportDx9 **)(*(int *)(in_stack_00000008 + 0x74) + 0x20);
          if (pCVar13 != (CVisionViewportDx9 *)0x0) {
            (**(code **)(*(int *)this + 0xe0))();
            in_stack_ffffffe4 = (code *)pCVar13;
          }
        }
        else if (*(char *)(in_stack_00000008 + 0x4d) == '\x04') {
          piVar11 = *(int **)(in_stack_00000008 + 0x74);
          in_stack_ffffffe4 = (code *)0x996ee6;
          iVar4 = (**(code **)(*piVar11 + 0x78))();
          if (((iVar4 == 4) && ((*(byte *)(piVar11 + 0x2c) & 0x40) != 0)) && (piVar11[0x1c] != 0)) {
            CFastBuffer<class_CGamePlayerScore*>::FindOrAdd
                      (this + 0x86c,(CFastBuffer<class_CGamePlayerScore*> *)&param_1,
                       (CGamePlayerScore **)in_stack_ffffffe4);
          }
        }
        pCVar9 = pCVar9 + 1;
      } while (pCVar9 < pCVar5);
    }
    CDx9StateBlock::FilterRenderState(0x1a,in_stack_00000008);
    func_0x009b4fa0();
    if (local_c != (CFastBuffer<class_GxVertex2> *)0x0) {
      (**(code **)(**(int **)(this + 0x9f8) + 0xa8))(*(int **)(this + 0x9f8));
      *(undefined4 *)(this + 0x15a4) = 0;
    }
  }
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::TexRender_UpdateTextures_FromLastFrame_LightDepOnly
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CVisionViewportDx9::TexRender_UpdateTextures_FromLastFrame_LightDepOnly
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1)
{
{
  CFastBuffer<struct_CDx9StateBlock::STexStageState> *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong uVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  GmFrustumIso4 *unaff_EBP;
  CFastBuffer<struct_CDx9StateBlock::STexStageState> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  CFastBuffer<struct_CDx9StateBlock::STexStageState> *unaff_retaddr;
  int in_stack_0000000c;
  CVisionViewportDx9 *in_stack_00000010;
  TiXmlAttributeSet *in_stack_fffffff8;
  CVisionViewportDx9 *pCVar5;
  
  pCVar5 = this;
  if ((_DAT_00d77c28 & 1) == 0) {
    _DAT_00d77c28 = _DAT_00d77c28 | 1;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (&DAT_00d77c1c,unaff_EDI);
    _atexit(`protected:_void___thiscall_CVisionViewportDx9::
            TexRender_UpdateTextures_FromLastFrame_LightDepOnly(void)'::__l2::
            _dynamic_atexit_destructor_for__TexturePixelUpdatesOld__);
  }
  this_00 = (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)(this + 0x15b0);
  CFastBuffer<class_CGameFid*>::CopyFromFastBuffer(&DAT_00d77c1c,this_00,unaff_ESI);
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this_00,unaff_EBP);
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x15bc,unaff_EBX);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x15bc,pCVar4,(ulong)in_stack_fffffff8);
      in_stack_0000000c = *(int *)pSVar2;
      if ((*(char *)(in_stack_0000000c + 0x4d) == '\x04') &&
         ((*(uint *)(*(int *)(in_stack_0000000c + 0x74) + 0x18) & 0x400) != 0)) {
        in_stack_fffffff8 = (TiXmlAttributeSet *)&stack0x0000000c;
        CFastBuffer<class_CDx9TextureKeeper*>::Add
                  (this_00,in_stack_fffffff8,(TiXmlAttribute *)pCVar5);
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (this_00,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffff8);
  if (uVar3 != 0) {
    TexRender_UpdateTextures(in_stack_00000010,pCVar5);
  }
  CFastBuffer<class_CGameFid*>::CopyFromFastBuffer
            (this_00,(CFastBuffer<struct_CDx9StateBlock::STexStageState> *)&DAT_00d77c1c,
             unaff_retaddr);
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::TexRender_Water_LDirSpecInA
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CVisionViewportDx9::TexRender_Water_LDirSpecInA
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2,
          CPlugBitmapRenderWater *param_3,GmMat3 *param_4)
{
{
  CPlugFileGen *this_00;
  int *piVar1;
  CMwId CVar2;
  SCasterCat *pSVar3;
  SSamplerState *pSVar4;
  CPlugBitmap *pCVar5;
  CPlugShaderApply *this_01;
  undefined3 extraout_var;
  GmVec4 *pGVar7;
  void *pvVar8;
  ulong unaff_EBX;
  ulong unaff_EBP;
  int unaff_ESI;
  ulong unaff_EDI;
  void *unaff_retaddr;
  CVisionViewportDx9 *pCStack00000018;
  ulong uVar9;
  GmVec3 *pGVar10;
  GmVec3 *pGVar11;
  int iVar12;
  GmIso4 *pGVar13;
  ulong *puVar14;
  SRenderShaderParam *pSVar15;
  CVisionViewportDx9 *pCVar16;
  float in_stack_ffffffa0;
  EStdShader2 in_stack_ffffffa4;
  ulong in_stack_ffffffa8;
  ulong in_stack_ffffffac;
  CPlugBitmap *in_stack_ffffffb0;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 auStack_2c [8];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  CPlugShader *pCVar6;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00aeb008;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar12 = *(int *)(*(int *)(param_1 + 0x14) + 0x38);
  if (((byte)param_2[0xc4] & 0x20) != 0) {
    if ((DAT_00d77548 & 0x80) == 0) {
      this_00 = *(CPlugFileGen **)(param_1 + 0x48);
      if ((((byte)*(undefined4 *)(this_00 + 0x24) & 0x1c) == 0x10) &&
         (*(int *)(this_00 + 0x34) == 6)) {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00 + 0x38,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                            DAT_00cca150 ^ (uint)&stack0xffffff90);
        CPlugFileGen::GenRenderCube(this_00,*(CPlugFileGen **)pSVar3,3,unaff_EDI);
        CPlugBitmap::SetDirty((CPlugBitmap *)param_1,(CPlugVertexStream *)0x1,unaff_ESI);
      }
      if ((DAT_00d77548 & 0x80) == 0) {
        ExceptionList = unaff_retaddr;
        return;
      }
    }
    if (((byte)*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x24) & 0x1c) == 0x10) {
      pvVar8 = (void *)(iVar12 + 0x58);
      pSVar3 = CFastBuffer<struct_SFastCat>::operator[]
                         (pvVar8,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,unaff_EBP);
      if (*(int *)(pSVar3 + 4) != 0) {
        iVar12 = 0x991b30;
        pSVar4 = CFastBufferCat<class_CSceneMobil*,struct_SFastCat>::GetElemInCat
                           (pvVar8,(CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
                                    *)0x0,1,unaff_EBX);
        piVar1 = *(int **)pSVar4;
        pCStack00000018 = *(CVisionViewportDx9 **)(*(int *)(piVar1[0x12] + 0x88) + 0x54);
        puVar14 = (ulong *)0x991b63;
        pCVar16 = pCStack00000018;
        pCVar5 = BitmapSpecularGetClose(this,pCStack00000018,_DAT_00b3380c,in_stack_ffffffa0);
        this_01 = StdShaderGet(this,(CVisionViewportDx9 *)&DAT_00000017,in_stack_ffffffa4,
                               in_stack_ffffffa8);
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_01 + 0x94,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                            in_stack_ffffffac);
        CPlugBitmapSampler::SetBitmap
                  (*(CPlugBitmapSampler **)pSVar3,(CPlugVolumeProjector *)pCVar5,in_stack_ffffffb0);
        if (((byte)this_01[0x1e] & 1) != 0) {
          (**(code **)(*(int *)this + 0x214))();
          CVisionViewport::ShaderUndirtyAll((CVisionViewport *)this,(CVisionViewport *)0x0,iVar12);
          DAT_00d7582c = 0;
        }
        CVar2 = CMwId::CreateFromLocalName((char *)&param_3);
        pCVar6 = (CPlugShader *)CONCAT31(extraout_var,CVar2);
        pGVar10 = (GmVec3 *)0x0;
        uVar9 = 0;
        pGVar7 = CPlugShader::GetLoadFxValue
                           ((CPlugShader *)this_01,pCVar6,(CMwId *)0x0,(SPlugGpuLoadFx **)0x0,
                            (CPlugShaderPass **)0x0,(EPlugGpuPipeline *)0x0,puVar14);
        OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pCVar16);
        if (pGVar7 != (GmVec4 *)0x0) {
          pSVar15 = (SRenderShaderParam *)&stack0xffffffac;
          pGVar13 = (GmIso4 *)0x2;
          pGVar11 = (GmVec3 *)0x991c05;
          pvVar8 = (void *)(**(code **)(*piVar1 + 0x78))();
          GmMat3::GetLine(pvVar8,(GmMat3 *)pCVar6,uVar9,pGVar10);
          GmMat3::SetDOVInverse(&uStack_30,(GmMat3 *)&stack0xffffffa0,pGVar11);
          GmMat3::SetMult(&stack0xffffffb0,(SPlugFaceCull *)param_4,(SPlugFaceCull *)auStack_2c,
                          pGVar13);
          *(undefined4 *)pGVar7 = uStack_4c;
          *(undefined4 *)(pGVar7 + 4) = uStack_48;
          *(undefined4 *)(pGVar7 + 8) = uStack_44;
          *(undefined4 *)(pGVar7 + 0xc) = 0;
          *(undefined4 *)(pGVar7 + 0x10) = uStack_40;
          *(undefined4 *)(pGVar7 + 0x14) = uStack_3c;
          *(undefined4 *)(pGVar7 + 0x18) = uStack_38;
          *(undefined4 *)(pGVar7 + 0x1c) = 0;
          *(undefined4 *)(pGVar7 + 0x20) = uStack_34;
          *(undefined4 *)(pGVar7 + 0x24) = uStack_30;
          *(undefined4 *)(pGVar7 + 0x28) = auStack_2c[0];
          *(undefined4 *)(pGVar7 + 0x2c) = 0;
          CDx9StateBlock::FilterRenderState(0xa8,8);
          RenderShaderOnFullQuad
                    (this,(CVisionViewportDx9 *)this_01,(CPlugShader *)0x0,(CPlugBitmap *)0x0,
                     (SGxPixRect *)0x0,(CPlugVisual *)0x0,pSVar15);
          CDx9StateBlock::FilterRenderState(0xa8,0xf);
        }
      }
    }
  }
  ExceptionList = unaff_retaddr;
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::TexRender_Water_PlaneR
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CVisionViewportDx9::TexRender_Water_PlaneR
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2,
          CPlugBitmapRender *param_3,GmVec4 *param_4,ulong param_5,int param_6)
{
{
  float fVar1;
  GmMat4 GVar2;
  GmIso3 *pGVar3;
  int iVar4;
  GmMat4 *pGVar5;
  CSystemConfigDisplay *this_00;
  int iVar6;
  undefined4 uVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  CPlugBitmapRenderWater *pCVar9;
  SCasterCat *pSVar10;
  SCasterCat *pSVar11;
  SNewTriangleVert *pSVar12;
  SCasterCat *pSVar13;
  SCasterCat *pSVar14;
  CPlugShaderApply *pCVar15;
  CVisionShaderKeeper *this_01;
  void *this_02;
  uint uVar16;
  GmIso3 *unaff_EBX;
  CPlugBitmapRenderWater *this_03;
  CPlugBitmapRenderWater *this_04;
  GmIso3 *unaff_EBP;
  GmFrustum *unaff_ESI;
  CPlugBitmap *this_05;
  CPlugBitmapRenderWater *pCVar17;
  GmMat4 *pGVar18;
  CMwCmdScriptVarBool *pCVar19;
  CPlugBitmapRenderWater *pCVar20;
  undefined4 *puVar21;
  float *pfVar22;
  GmFrustum *unaff_EDI;
  CHmsCamera *pCVar23;
  CPlugBitmapRenderWater *pCVar24;
  CVisionViewportDx9 *pCVar25;
  float10 extraout_ST0;
  float10 fVar26;
  float10 extraout_ST0_00;
  GmFrustum *pGVar27;
  float fVar28;
  CPlugBitmapRender *in_stack_0000003c;
  CVisionViewportDx9 *in_stack_00000040;
  ulong in_stack_00000044;
  int in_stack_00000048;
  int in_stack_0000004c;
  int in_stack_00000050;
  int in_stack_fffffe20;
  CPlugBitmap *pCVar29;
  CPlugBitmap *pCVar30;
  int in_stack_fffffe2c;
  GmIso3 *pGVar31;
  SParam *pSVar32;
  GmIso3 *pGVar33;
  CHmsCamera *pCVar34;
  CHmsCamera *in_stack_fffffe40;
  double dVar35;
  SHmsCameraLocation *pSVar36;
  GxTexCoord *pGVar37;
  CPlugShader *pCVar38;
  CHmsZone *pCVar39;
  CPlugBitmapRenderWater *this_06;
  GxTexCoord *pGVar40;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *pCVar41;
  float *in_stack_fffffe4c;
  ulong uVar42;
  CPlugShader *pCVar43;
  CPlugVisual *pCVar44;
  ulong uVar45;
  EGxTexFilter *pEVar46;
  GmFrustum *pGStack_1a0;
  CVisionViewportDx9 *pCStack_19c;
  float *pfStack_198;
  CMwCmdScriptVarBool *pCStack_194;
  float fStack_190;
  int iStack_18c;
  CPlugShader *pCStack_188;
  CVisionViewportDx9 *pCStack_184;
  CPlugBitmapRenderWater *pCStack_180;
  CMwCmdScriptVarBool *pCStack_17c;
  CPlugBitmapRenderWater *pCStack_178;
  undefined4 uStack_174;
  float *pfStack_16c;
  float fStack_168;
  undefined8 uStack_164;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  float fStack_144;
  float fStack_140;
  float fStack_13c;
  CHmsZone *pCStack_138;
  undefined4 uStack_134;
  float fStack_130;
  float fStack_12c;
  float fStack_128;
  float fStack_124;
  CHmsCamera aCStack_120 [4];
  undefined8 uStack_11c;
  float fStack_114;
  float fStack_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float fStack_100;
  double dStack_fc;
  double dStack_f4;
  undefined1 auStack_d8 [8];
  CMwCmdScriptVarBool aCStack_d0 [8];
  SPlugFaceCull aSStack_c8 [8];
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 auStack_a0 [9];
  undefined4 auStack_7c [4];
  float afStack_6c [2];
  undefined1 auStack_64 [8];
  GmIso3 aGStack_5c [4];
  CPlugBitmapRenderWater aCStack_58 [8];
  GmIso3 aGStack_50 [56];
  undefined1 auStack_18 [4];
  CMwCmdScriptVarBool aCStack_14 [20];
  
  iVar6 = *(int *)(param_1 + 0x14);
  this_05 = (CPlugBitmap *)0x0;
  pCVar29 = (CPlugBitmap *)0x0;
  iVar4 = (**(code **)(*(int *)param_2 + 0x78))();
  pCVar30 = param_2;
  if (iVar4 == 2) {
    this_05 = param_2;
    pCVar30 = pCVar29;
  }
  pCVar23 = *(CHmsCamera **)(iVar6 + 0x3c);
  if ((pCVar23 != (CHmsCamera *)0x0) && (*(int *)(pCVar23 + 0x14) != 0)) {
    pGVar3 = *(GmIso3 **)(pCVar23 + 0x14);
    pGVar33 = pGVar3;
    pCVar34 = pCVar23;
    CHmsCamera::GetRenderFrustum(pCVar23,aCStack_120,unaff_EDI);
    uStack_174 = *(undefined4 *)(pCVar23 + 0x174);
    pGVar31 = (GmIso3 *)0x1;
    pSVar32 = (SParam *)0x1;
    uVar45 = 0xffffffff;
    pGVar5 = (GmMat4 *)(**(code **)(*(int *)pCVar23 + 0x78))();
    if (this_05 == (CPlugBitmap *)0x0) {
      this_06 = (CPlugBitmapRenderWater *)(in_stack_fffffe2c + 0x7c);
      pCVar17 = (CPlugBitmapRenderWater *)(in_stack_fffffe2c + 0x98);
      this_03 = (CPlugBitmapRenderWater *)(in_stack_fffffe2c + 200);
      this_04 = (CPlugBitmapRenderWater *)(in_stack_fffffe2c + 0x108);
      pCStack_180 = (CPlugBitmapRenderWater *)(in_stack_fffffe2c + 300);
      pCVar9 = (CPlugBitmapRenderWater *)(in_stack_fffffe2c + 0x150);
      pCVar20 = pCVar17;
      pCStack_178 = this_03;
      __CIatan();
      pGVar31 = (GmIso3 *)(float)extraout_ST0_00;
      pGVar18 = pGVar5;
      for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
        *(float *)pCVar17 = *(float *)pGVar18;
        pGVar18 = pGVar18 + 4;
        pCVar17 = pCVar17 + 4;
      }
      GmIso4::SymmetryPlane(pCVar20,(GmIso4 *)(in_stack_fffffe2c + 0x68),(GmVec4 *)unaff_ESI);
      dVar35 = (double)CONCAT44(in_stack_fffffe40,pCVar34);
      pCVar17 = pCVar20 + 0x118;
      pfVar22 = in_stack_fffffe4c;
      for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
        *pfVar22 = *(float *)pCVar17;
        pCVar17 = pCVar17 + 4;
        pfVar22 = pfVar22 + 1;
      }
      pSVar32 = (SParam *)0x0;
      pGVar33 = (GmIso3 *)0x1;
    }
    else {
      if (((byte)*(CPlugBitmapRenderWater *)(this_05 + 0xc4) & 2) != 0) {
        CPlugBitmap::SetOrigin
                  (param_2,(CPlugBitmap *)(~(*(uint *)(param_3 + 0x14) >> 3) & 1),1,(int)unaff_ESI);
      }
      if (param_4 == (GmVec4 *)0x0) {
        if ((pGVar3 == (GmIso3 *)0x0) || (*(int *)(pGVar3 + 0xbc) == 0)) {
          fStack_190 = 0.0;
          iStack_18c = 0x3f800000;
          pCStack_188 = (CPlugShader *)0x0;
          pCStack_184 = (CVisionViewportDx9 *)0x0;
        }
        else {
          GmVec4::PlaneEqSetNormPos
                    (&fStack_190,(GmVec4 *)(pGVar3 + 0xd0),(GmVec3 *)(pGVar3 + 0xc4),
                     (GmVec3 *)unaff_ESI);
        }
      }
      else {
        fStack_190 = *(float *)param_4;
        iStack_18c = *(int *)(param_4 + 4);
        pCStack_188 = *(CPlugShader **)(param_4 + 8);
        pCStack_184 = *(CVisionViewportDx9 **)(param_4 + 0xc);
      }
      uVar16 = *(uint *)(this_05 + 0xc4);
      if (((uVar16 & 2) != 0) && (iVar6 = *(int *)(this + 0x24c), iVar6 != 0)) {
        if (*(int *)(iVar6 + 0x20) == 0) {
          this_00 = *(CSystemConfigDisplay **)(iVar6 + 0x24);
        }
        else {
          this_00 = *(CSystemConfigDisplay **)(iVar6 + 0x28);
        }
        iVar6 = CSystemConfigDisplay::WaterGeom(this_00,(CSystemConfigDisplay *)unaff_ESI);
        if ((iVar6 == 0) && ((uVar16 & 0x400) == 0)) {
          uVar7 = 1;
        }
        else {
          uVar7 = 0;
        }
        *(undefined4 *)(this + 0x434) = uVar7;
        *(uint *)(this + 0x438) = *(uint *)(this_05 + 0xc4) >> 0xd & 3;
      }
      pCVar20 = (CPlugBitmapRenderWater *)(this_05 + 0x78);
      this_06 = (CPlugBitmapRenderWater *)(this_05 + 0x5c);
      this_03 = (CPlugBitmapRenderWater *)(this_05 + 0xd0);
      this_04 = (CPlugBitmapRenderWater *)(this_05 + 0x110);
      pCStack_180 = (CPlugBitmapRenderWater *)(this_05 + 0x134);
      pCVar9 = (CPlugBitmapRenderWater *)(this_05 + 0x158);
      pCStack_178 = this_03;
      if (((byte)*(CPlugBitmapRenderWater *)(this_05 + 0xc4) & 1) == 0) {
        pGStack_1a0 = (GmFrustum *)GmFrustum::GetFovY(&uStack_11c,unaff_ESI);
        dVar35 = (double)CONCAT44(in_stack_fffffe40,pCVar34);
        *(uint *)(pGVar5 + 0xc4) = (uint)*(float *)(pGVar5 + 0xc4) | 1;
      }
      else {
        if ((param_5 != 0) &&
           (pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                     CPlugBitmapRenderWater::UserClipPlaneAdd
                               ((CPlugBitmapRenderWater *)this_05,
                                (CPlugBitmapRenderWater *)(this + 0x46c),
                                (CFastBuffer<class_GmVec4> *)&fStack_190,(GmVec4 *)unaff_ESI),
           pCVar8 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff)) {
          CDx9VertexShader::FilterSetVertexShader((CDx9VertexShader *)0x0);
          iVar6 = **(int **)(this + 0x9f8);
          unaff_EBP = (GmIso3 *)
                      CFastBuffer<class_GxColor>::operator[](this + 0x46c,pCVar8,(ulong)unaff_EBP);
          unaff_ESI = pGStack_1a0;
          pCVar23 = in_stack_fffffe40;
          (**(code **)(iVar6 + 0xdc))(*(undefined4 *)(this + 0x9f8));
          *(uint *)(this + 0x15a8) = ~(*(uint *)(this_05 + 0xc4) >> 4) & 1;
          in_stack_fffffe40 = pCVar23;
        }
        if (((byte)*(CPlugBitmapRenderWater *)(this_05 + 0xc4) & 8) == 0) {
          pCVar23 = pCVar23 + 0x118;
          pGVar27 = (GmFrustum *)GmFrustum::GetFarZ(pCVar23,unaff_ESI);
          pGVar27 = (GmFrustum *)GmFrustum::GetNearZ(pCVar23,pGVar27);
          fVar28 = GmFrustum::GetRatioXY(pCVar23,pGVar27);
          GmFrustum::Set(this_04,_DAT_00b36190,(int)fVar28);
          dVar35 = (double)CONCAT44(in_stack_fffffe40,pCVar34);
        }
        else {
          GmFrustum::GetAspect(&uStack_11c,(GmFrustum *)&pGStack_1a0,(GmRectAligned *)unaff_ESI);
          pGVar31 = (GmIso3 *)(*(float *)(this_05 + 0xac) * (float)_DAT_00b313b8);
          fVar1 = (float)pGVar31 * ((float)pCStack_194 - (float)pCStack_19c);
          fVar28 = (float)pGVar31 * (fStack_190 - (float)pfStack_198);
          pCStack_19c = (CVisionViewportDx9 *)((float)pCStack_19c - fVar1);
          pfStack_198 = (float *)((float)pfStack_198 - fVar28);
          pCStack_194 = (CMwCmdScriptVarBool *)((float)pCStack_194 + fVar1);
          fStack_190 = fStack_190 + fVar28;
          dVar35 = (double)CONCAT44(in_stack_fffffe40,fVar28);
          uStack_11c = (double)CONCAT44(uStack_11c._4_4_,(undefined4)uStack_11c);
          if (((*(uint *)(this_05 + 0xc4) & 0x1000) != 0) &&
             (dVar35 = (double)CONCAT44(in_stack_fffffe40,fVar28),
             uStack_11c = (double)CONCAT44(uStack_11c._4_4_,(undefined4)uStack_11c),
             (*(uint *)(this_05 + 0xc4) & 2) != 0)) {
            GmMat3::GetLine(this_04,(GmMat3 *)0x2,(ulong)&pfStack_16c,(GmVec3 *)unaff_EBP);
            uStack_11c = (double)uStack_164._4_4_;
            dVar35 = (double)fStack_168;
            unaff_EBP = (GmIso3 *)(1.0 - *(float *)(this_05 + 0xb0));
            pSVar32 = (SParam *)unaff_EBP;
            GmFunc::Saturate(this_02,(SParam *)unaff_EBP);
            dStack_f4 = (double)(extraout_ST0 * (float10)fStack_190);
            uStack_164 = (double)uStack_164._4_4_;
            unaff_EBX = (GmIso3 *)0x9921ad;
            fVar26 = (float10)func_0x009c1b40();
            pGVar31 = (GmIso3 *)
                      ((float)dStack_fc -
                      (float)(double)CONCAT44(fStack_168,pfStack_16c) / (float)fVar26);
            if ((float)pGVar31 < 0.0) {
              pfStack_198 = (float *)((float)pfStack_198 + (float)pGVar31);
              fStack_190 = (float)pGVar31 + fStack_190;
            }
          }
          pGVar27 = (GmFrustum *)
                    GmFrustum::GetFarZ((void *)((int)&uStack_11c + 4),(GmFrustum *)unaff_EBP);
          unaff_EBP = (GmIso3 *)GmFrustum::GetNearZ(&fStack_114,pGVar27);
          GmFrustum::Set(this_04,pCStack_194,(int)fStack_190);
        }
        uVar16 = (uint)((ulonglong)dVar35 >> 0x20);
        GVar2 = pGVar5[0xc4];
        pCVar17 = this_04;
        pCVar24 = this_06;
        for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined4 *)pCVar24 = *(undefined4 *)pCVar17;
          pCVar17 = pCVar17 + 4;
          pCVar24 = pCVar24 + 4;
        }
        if (((byte)GVar2 & 2) == 0) {
          *(CPlugBitmapRender **)(this + 0x864) = param_3;
          *(uint *)(pGVar5 + 0xc4) = (uint)*(float *)(pGVar5 + 0xc4) | 1;
          pGVar33 = (GmIso3 *)0x0;
        }
        else {
          if (param_6 != 0) {
            GmIso4::SymmetryPlane(this_06,(GmIso4 *)&iStack_18c,(GmVec4 *)unaff_EBP);
            _DAT_00d6e82c = pCStack_188;
            unaff_EBP = (GmIso3 *)&stack0xfffffe38;
            _DAT_00d6e830 = pCStack_184;
            _DAT_00d6e834 = pCStack_180;
            _DAT_00d6e838 = pCStack_17c;
            GmVec4::Mult(&DAT_00d6e82c,unaff_EBP,unaff_EBX);
            dVar35 = (double)((ulonglong)uVar16 << 0x20);
          }
          *(uint *)(pGVar5 + 0xc4) = (uint)*(float *)(pGVar5 + 0xc4) | 1;
          pGVar33 = (GmIso3 *)0x1;
        }
      }
    }
    *(uint *)(this + 0x414) = *(uint *)(this + 0x414) | 1;
    GmIso4::SetInverse(auStack_d8,(GmScaleTrans2 *)this_06,(GmScaleTrans2 *)unaff_EBP);
    GmMat4::SetFrustumProjection(auStack_64,pGVar5,(GmFrustum *)0x1,(ulong)unaff_EBX);
    GmMat4::Set(this_03,aCStack_d0,in_stack_fffffe20);
    GmMat4::Mult(this_03,aGStack_5c,(GmIso3 *)pCVar9);
    *pfStack_16c = *(float *)this_03;
    pfStack_16c[1] = *(float *)(this_03 + 4);
    pfStack_16c[2] = *(float *)(this_03 + 8);
    pfStack_16c[3] = *(float *)(this_03 + 0x10);
    pfStack_16c[4] = *(float *)(this_03 + 0x14);
    pfStack_16c[5] = *(float *)(this_03 + 0x18);
    pfStack_16c[6] = *(float *)(this_03 + 0x20);
    pfStack_16c[7] = *(float *)(this_03 + 0x24);
    pfStack_16c[8] = *(float *)(this_03 + 0x28);
    *pfStack_198 = *(float *)(this_03 + 0x30) - *(float *)this_03;
    pfStack_198[1] = *(float *)(this_03 + 0x34) - *(float *)(this_03 + 4);
    pfStack_198[2] = *(float *)(this_03 + 0x38) - *(float *)(this_03 + 8);
    fVar28 = (float)_DAT_00b313b8;
    *pfStack_198 = *pfStack_198 * fVar28;
    pfStack_198[1] = pfStack_198[1] * fVar28;
    pfStack_198[2] = pfStack_198[2] * fVar28;
    pfStack_198[3] = *(float *)(this_03 + 0x30) - *(float *)(this_03 + 0x10);
    pfStack_198[4] = *(float *)(this_03 + 0x34) - *(float *)(this_03 + 0x14);
    pfStack_198[5] = *(float *)(this_03 + 0x38) - *(float *)(this_03 + 0x18);
    pfStack_198[3] = pfStack_198[3] * fVar28;
    pfStack_198[4] = pfStack_198[4] * fVar28;
    pfStack_198[5] = fVar28 * pfStack_198[5];
    pfStack_198[6] = *(float *)(this_03 + 0x30);
    pfStack_198[7] = *(float *)(this_03 + 0x34);
    pfStack_198[8] = *(float *)(this_03 + 0x38);
    GmIso4::SetMult(auStack_18,(SPlugFaceCull *)pCStack_19c,aSStack_c8,(GmIso4 *)pCVar30);
    GmMat4::Set(&uStack_14c,aCStack_14,in_stack_fffffe2c);
    GmMat4::Mult(&uStack_148,aGStack_50,pGVar31);
    *(float *)pCVar20 = fStack_114 - fStack_144;
    *(float *)(pCVar20 + 4) = fStack_110 - fStack_140;
    *(float *)(pCVar20 + 8) = fStack_10c - fStack_13c;
    *(float *)(pCVar20 + 0xc) = fStack_108 - (float)pCStack_138;
    pGVar37 = _DAT_00b31460;
    GmVec4::Mult(pCVar20,(GmIso3 *)&stack0xfffffe44,(GmIso3 *)pSVar32);
    *(float *)(pCVar20 + 0x10) = fStack_110 - fStack_130;
    *(float *)(pCVar20 + 0x14) = fStack_10c - fStack_12c;
    *(float *)(pCVar20 + 0x18) = fStack_108 - fStack_128;
    *(float *)(pCVar20 + 0x1c) = fStack_104 - fStack_124;
    pGVar40 = _DAT_00b31460;
    GmVec4::Mult(pCVar20 + 0x10,(GmIso3 *)&stack0xfffffe48,pGVar33);
    *(float *)(pCVar20 + 0x20) = fStack_10c;
    *(float *)(pCVar20 + 0x24) = fStack_108;
    *(float *)(pCVar20 + 0x28) = fStack_104;
    *(float *)(pCVar20 + 0x2c) = fStack_100;
    if (in_stack_0000003c == (CPlugBitmapRender *)0x0) {
      if (*(int *)(this + 0x12b8) == 0) {
        StdShaderLoad(this,(CVisionViewportDx9 *)&DAT_00000009,SUB84(dVar35,0),
                      (ulong)((ulonglong)dVar35 >> 0x20));
      }
      iVar6 = *(int *)(this + 0x12b8);
    }
    else {
      iVar6 = 0;
    }
    pCStack_17c = pCStack_194 + 0x94;
    *(int *)(this + 0x44c) = iVar6;
    *(uint *)(this + 0x854) = (uint)(iVar6 != 0);
    pCVar19 = pCStack_17c;
    puVar21 = auStack_7c;
    for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar21 = *(undefined4 *)pCVar19;
      pCVar19 = pCVar19 + 4;
      puVar21 = puVar21 + 1;
    }
    if ((*(uint *)(in_stack_0000003c + 0x14) & 0x80000000) != 0) {
      fVar28 = *(float *)(pCStack_180 + 0x28) - *(float *)(pCStack_194 + 200);
      if (fVar28 < (float)_DAT_00b2c188 != (fVar28 == (float)_DAT_00b2c188)) {
        fVar28 = 1.0;
      }
      fVar1 = *(float *)(in_stack_0000003c + 0x34);
      *(uint *)(pCStack_194 + 0xac) = *(uint *)(pCStack_194 + 0xac) & 0xfffffffe | 0xe;
      this_04 = (CPlugBitmapRenderWater *)(fVar28 + fVar1);
      *(float *)(pCStack_194 + 0xa0) = fVar28;
      *(CPlugBitmapRenderWater **)(pCStack_194 + 0xa4) = this_04;
      *(uint *)(in_stack_0000003c + 0x14) =
           *(uint *)(in_stack_0000003c + 0x14) ^
           ((uint)(DAT_00d123b8._2_2_ < 3) * 0x8000000 ^ *(uint *)(in_stack_0000003c + 0x14)) &
           0x8000000;
    }
    if ((*(uint *)(in_stack_0000003c + 0x14) & 0x8000000) == 0) {
      *(uint *)(pCStack_194 + 0xac) = *(uint *)(pCStack_194 + 0xac) & 0xfffffff9;
    }
    else {
      *(undefined4 *)(this + 0x424) = 0;
    }
    uVar16 = *(uint *)(in_stack_0000003c + 0x14);
    pCVar25 = (CVisionViewportDx9 *)0x1;
    if ((uVar16 & 0x10) != 0) {
      pCVar25 = (CVisionViewportDx9 *)((uint)(*(int *)(this + 0x2b8) != 0) * 4 + 3);
    }
    if (((pCStack_19c == (CVisionViewportDx9 *)0x0) || (((byte)pCStack_194[0xac] & 6) == 0)) ||
       ((uVar16 & 0x20000000) == 0)) {
      if ((uVar16 & 0x3800) == 0x800) {
        uVar45 = *(ulong *)(in_stack_0000003c + 0x48);
        CPlugBitmapRender::BitmapClearSetUV
                  (in_stack_0000003c,(CPlugBitmapRender *)&stack0xfffffe54,pGVar37);
      }
      this_04 = *(CPlugBitmapRenderWater **)(in_stack_0000003c + 0x1c);
    }
    else {
      GxBGRAColor::Set(&stack0xfffffe54,pCStack_17c,0x3f800000);
    }
    fVar28 = (float)_DAT_00b3d080;
    *(float *)pCStack_17c = (float)((uint)this_04 >> 0x10 & 0xff) * fVar28;
    uVar16 = (uint)this_04 & 0xff;
    *(float *)(pCStack_17c + 4) = (float)((uint)this_04 >> 8 & 0xff) * fVar28;
    *(float *)(pCStack_17c + 8) = fVar28 * (float)uVar16;
    if (((fStack_144 == 0.0) || (pCStack_184 == (CVisionViewportDx9 *)0x0)) ||
       (((byte)pCStack_184[0xc4] & 0x80) == 0)) {
      uVar7 = 0;
    }
    else {
      uVar7 = 1;
    }
    *(undefined4 *)((int)fStack_190 + 0x174) = uVar7;
    if (in_stack_00000044 != 0xffffffff) {
      CDx9StateBlock::FilterRenderState(0x34,1);
      CDx9StateBlock::FilterRenderState(0x35,1);
      CDx9StateBlock::FilterRenderState(0x36,1);
      CDx9StateBlock::FilterRenderState(0x3b,0xffffffff);
      CDx9StateBlock::FilterRenderState(0xe,1);
      if (in_stack_00000044 == 0) {
        CDx9StateBlock::FilterRenderState(0x37,3);
        CDx9StateBlock::FilterRenderState(0x38,8);
        uVar42 = 0;
      }
      else {
        CDx9StateBlock::FilterRenderState(0x38,3);
        CDx9StateBlock::FilterRenderState(0x39,in_stack_00000044);
        pCVar25 = (CVisionViewportDx9 *)((uint)pCVar25 & 0xfffffffa);
        uVar42 = 0xf;
      }
      CDx9StateBlock::FilterRenderState(0xa8,uVar42);
    }
    RenderTargetClear(this,pCVar25,(ulong)this_04,0x3f800000,0.0,(ulong)pGVar37);
    CFastBuffer<class_CSystemFidsFolder*>::SetCount
              (this + 0x454,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,(ulong)pGVar40);
    pSVar10 = CFastBuffer<struct_CHmsViewport::SVisualLocation>::operator[]
                        (this + 0x454,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                         (ulong)in_stack_fffffe4c);
    *(uint *)(pSVar10 + 0xa0) =
         *(uint *)(pSVar10 + 0xa0) ^ (*(uint *)(pSVar10 + 0xa0) ^ (uint)pCStack_194) & 1;
    pCVar20 = pCStack_180;
    pSVar11 = pSVar10 + 0x30;
    for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(undefined4 *)pSVar11 = *(undefined4 *)pCVar20;
      pCVar20 = pCVar20 + 4;
      pSVar11 = pSVar11 + 4;
    }
    puVar21 = auStack_a0;
    pSVar11 = pSVar10;
    for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(undefined4 *)pSVar11 = *puVar21;
      puVar21 = puVar21 + 1;
      pSVar11 = pSVar11 + 4;
    }
    pSVar11 = pSVar10;
    (**(code **)(*(int *)this + 0x19c))();
    GmMat3::Set(aCStack_58,(CMwCmdScriptVarBool *)(pSVar10 + 0x30),(int)pSVar11);
    pSVar11 = GmMat4::operator[](pSVar10 + 0x60,
                                 (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)pGVar5
                                );
    pCVar41 = *(CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> **)
               (this + 0x9f8);
    uVar42 = 2;
    (**(code **)(*(int *)pCVar41 + 0xb0))();
    *(uint *)(pSVar10 + 0xa0) = *(uint *)(pSVar10 + 0xa0) & 0xfffffffd;
    pSVar12 = CFastBuffer<struct_SHmsRenderRect>::GetLastElem(this + 0x484,pCVar41);
    *(undefined4 *)(pSVar12 + 0x20) = 0;
    CFastBuffer<class_CSystemFidsFolder*>::SetCount
              (this + 0x460,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,uVar42);
    pSVar11 = CFastBuffer<struct_CHmsViewport::SClippingFrustum>::operator[]
                        (this + 0x460,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                         (ulong)pSVar11);
    CHmsViewport::SClippingFrustum::Set
              (pSVar11,(CMwCmdScriptVarBool *)pCStack_178,(int)(pSVar10 + 0x30));
    CFastBuffer<class_CSystemFidsFolder*>::SetCount
              (this + 0x478,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,uVar16);
    pSVar13 = CFastBuffer<struct_SHmsCameraProjection>::operator[]
                        (this + 0x478,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,uVar45);
    pEVar46 = (EGxTexFilter *)0x0;
    pSVar11 = pSVar13;
    (**(code **)(*(int *)this + 0x1a0))();
    pSVar14 = GmMat4::operator[](pSVar13 + 0x40,
                                 (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                 (ulong)pSVar11);
    pSVar36 = *(SHmsCameraLocation **)(this + 0x9f8);
    pCVar43 = (CPlugShader *)0x3;
    (**(code **)(*(int *)pSVar36 + 0xb0))();
    *(uint *)(pSVar13 + 0xcc) = *(uint *)(pSVar13 + 0xcc) & 0xfffffffe;
    CDx9StateBlock::ResetCache();
    DAT_00d7582c = 0;
    DAT_00d75a68 = 0;
    ComputeAndSetCullMode(this,(CVisionViewportDx9 *)pSVar10,pSVar36);
    CDx9StateBlock::FilterRenderState(7,1);
    pSVar11 = (SCasterCat *)&uStack_c0;
    uStack_c0 = 0;
    uStack_bc = 0;
    uStack_b8 = 0;
    pCVar38 = pCStack_188;
    (**(code **)(*(int *)this + 0x17c))();
    *(uint *)(this + 0x414) =
         *(uint *)(this + 0x414) ^
         (*(int *)(in_stack_0000003c + 0x14) * 4 ^ *(uint *)(this + 0x414)) & 0x10;
    *(undefined2 *)(this + 900) = *(undefined2 *)(in_stack_0000003c + 0x20);
    *(ushort *)(this + 0x386) =
         *(ushort *)(in_stack_0000003c + 0x22) & *(ushort *)(in_stack_0000003c + 0x20);
    *(undefined2 *)(this + 0x388) = *(undefined2 *)(in_stack_0000003c + 0x24);
    *(ushort *)(this + 0x38a) =
         *(ushort *)(in_stack_0000003c + 0x26) & *(ushort *)(in_stack_0000003c + 0x24);
    if (pCStack_19c == (CVisionViewportDx9 *)0x0) {
      *(ushort *)(this + 0x388) = *(ushort *)(this + 0x388) | 4;
      *(ushort *)(this + 0x38a) = *(ushort *)(this + 0x38a) | 4;
    }
    else if ((*(uint *)(in_stack_0000003c + 0x14) & 0x10000000) != 0) {
      *(undefined4 *)(this + 0x42c) = 0;
    }
    uStack_150 = *(undefined4 *)(this + 0x8e8);
    pCVar44 = *(CPlugVisual **)(this + 0x8e4);
    iVar6 = *(int *)(in_stack_0000003c + 0x2c);
    pGStack_1a0 = *(GmFrustum **)(this + 0x8ec);
    *(int *)(this + 0x8e4) = iVar6 + -1;
    *(undefined4 *)(this + 0x8e8) = *(undefined4 *)(in_stack_0000003c + 0x30);
    if (iVar6 + -1 != -1) {
      if (*(int *)(this + 0x1298) == 0) {
        StdShaderLoad(this,(CVisionViewportDx9 *)0x1,(EStdShader2)pCVar38,(ulong)pSVar11);
      }
      SetShaderForced(this,*(CVisionViewportDx9 **)(this + 0x1298),pCVar38);
    }
    if ((*(int *)(this + 0x434) == 0) || (*(int *)(pCStack_194 + 0xe8) == 0)) {
      CHmsViewport::RenderZone((CHmsViewport *)this,(CHmsViewport *)pCStack_194,(CHmsZone *)pCVar38)
      ;
    }
    else {
      pCVar15 = StdShaderGet(this,(CVisionViewportDx9 *)&DAT_00000025,(EStdShader2)pCVar38,
                             (ulong)pSVar11);
      this_01 = CVisionViewport::ShaderGetKeeper
                          ((CVisionViewport *)this,(CVisionViewport *)pCVar15,pCVar43);
      CDx9ShaderKeeper::SetShaderBitmapNoDirty
                ((CDx9ShaderKeeper *)this_01,(CDx9ShaderKeeper *)0x0,*(ulong *)(pCStack_188 + 0xe8),
                 (CPlugBitmap *)0x0,(CPlugBitmapSampler *)0x0,(EGxTexFilter *)pSVar14);
      RenderShader(this,(CVisionViewportDx9 *)pCVar15,(CPlugShader *)0x0,pCVar44);
      pCVar43 = *(CPlugShader **)(this + 0x151c);
      pCVar44 = (CPlugVisual *)0x0;
      pSVar14 = (SCasterCat *)0x0;
      pSVar11 = (SCasterCat *)0x0;
      CDx9ShaderKeeper::SetShaderBitmapNoDirty
                ((CDx9ShaderKeeper *)this_01,(CDx9ShaderKeeper *)0x0,(ulong)pCVar43,
                 (CPlugBitmap *)0x0,(CPlugBitmapSampler *)0x0,pEVar46);
    }
    pCVar20 = pCStack_180;
    if ((pCStack_180 != (CPlugBitmapRenderWater *)0x0) && (((byte)pCStack_180[0xc4] & 0x10) != 0)) {
      CPlugBitmapRenderWater::CameraToWorld_Mirror
                (pCStack_180,(CPlugBitmapRenderWater *)(pSVar10 + 0x30),(GmIso4 *)pSVar10,
                 *(GmIso4 **)((int)fStack_190 + 200),(float)pSVar11);
      *(uint *)(pSVar10 + 0xa0) = *(uint *)(pSVar10 + 0xa0) ^ 1;
      pSVar11 = pSVar10;
      (**(code **)(*(int *)this + 0x19c))();
      pSVar11 = GmMat4::operator[](pSVar10 + 0x60,
                                   (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                   (ulong)pSVar11);
      pSVar36 = *(SHmsCameraLocation **)(this + 0x9f8);
      pCVar39 = (CHmsZone *)0x2;
      (**(code **)(*(int *)pSVar36 + 0xb0))();
      *(uint *)(pSVar10 + 0xa0) = *(uint *)(pSVar10 + 0xa0) & 0xfffffffd;
      ComputeAndSetCullMode(this,(CVisionViewportDx9 *)pSVar10,pSVar36);
      uVar7 = *(undefined4 *)(this + 0x388);
      *(ushort *)(this + 0x388) = *(ushort *)(this + 0x388) | 2;
      *(ushort *)(this + 0x38a) = *(ushort *)(this + 0x38a) | 2;
      CHmsViewport::RenderZone((CHmsViewport *)this,(CHmsViewport *)pCStack_194,pCVar39);
      *(undefined4 *)(this + 0x388) = uVar7;
    }
    if (in_stack_00000048 != -1) {
      CDx9StateBlock::FilterRenderState(0x34,0);
      CDx9StateBlock::FilterRenderState(0xa8,0xf);
    }
    *(uint *)(this + 0x414) = *(uint *)(this + 0x414) & 0xffffffef;
    *(EGxTexFilter **)(this + 0x8e4) = pEVar46;
    *(undefined4 *)(this + 0x8e8) = uStack_14c;
    SetShaderForced(this,pCStack_19c,(CPlugShader *)pSVar11);
    *(undefined4 *)(this + 0x44c) = 0;
    *(undefined4 *)(this + 0x854) = 0;
    uVar45 = DAT_00d769fc;
    if (pCVar20 != (CPlugBitmapRenderWater *)0x0) {
      if (((byte)pCVar20[0xc4] & 0x20) == 0) {
        if (((in_stack_00000048 != -1) && (in_stack_00000048 != 0)) && (in_stack_00000050 != 0)) {
          CDx9StateBlock::FilterRenderState(7,0);
          CDx9StateBlock::FilterRenderState(0x34,1);
          CDx9StateBlock::FilterRenderState(0x38,6);
          CDx9StateBlock::FilterRenderState(0x39,0);
          CDx9StateBlock::FilterRenderState(0xa8,8);
          RasterizeQuadGetFullRect(this,(CVisionViewportDx9 *)&fStack_168,(GmRectAligned *)pCVar43);
          RasterizeQuadAlloc(this,(CVisionViewportDx9 *)0x1,0,(int)pSVar14);
          fStack_140 = 1.0;
          fStack_13c = 1.0;
          uStack_148 = 0x3f800000;
          pCStack_19c = (CVisionViewportDx9 *)0x0;
          pfStack_198 = (float *)0x0;
          uStack_150 = 0;
          fStack_144 = 1.0;
          uStack_14c = 0;
          RasterizeQuadAdd(this);
          RasterizeQuads(this,this + 0xc74,(CDx9StateBlock *)pCVar44);
          CDx9StateBlock::FilterRenderState(0xa8,0xf);
          CDx9StateBlock::FilterRenderState(0x34,0);
          CDx9StateBlock::FilterRenderState(7,uVar45);
        }
      }
      else {
        TexRender_Water_LDirSpecInA
                  (this,in_stack_00000040,(CPlugBitmap *)pCVar20,aCStack_58,(GmMat3 *)pCVar43);
      }
    }
    pCVar19 = pCStack_17c;
    (**(code **)(*(int *)this + 400))();
    if (fStack_168 != -NAN) {
      *(int *)(this + 0x46c) = *(int *)(this + 0x46c) + -1;
    }
    if ((iStack_18c != 0) && ((*(uint *)(in_stack_0000004c + 0x14) & 0x10000000) != 0)) {
      TexRender_RasterizeLensFlares
                (this,pCStack_184,pCStack_138,(GmMat4 *)uStack_164,(float)pCVar19);
    }
    *(undefined4 *)(pCStack_180 + 0x174) = uStack_134;
    pfVar22 = afStack_6c;
    for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
      *pfStack_16c = *pfVar22;
      pfVar22 = pfVar22 + 1;
      pfStack_16c = pfStack_16c + 1;
    }
  }
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::TextureBlitOnFullQuad
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CVisionViewportDx9::TextureBlitOnFullQuad
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugBitmap *param_2)
{
{
  int iVar1;
  float fVar2;
  SNewTriangleVert *pSVar3;
  int unaff_ESI;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_EDI;
  CDx9StateBlock *in_stack_ffffffd0;
  float local_18;
  float local_14;
  float local_10;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SRenderTarget>::GetLastElem
                     (this + 0x9fc,unaff_EDI);
  fVar2 = (float)*(int *)pSVar3;
  if (*(int *)pSVar3 < 0) {
    fVar2 = fVar2 + _DAT_00c418d0;
  }
  local_10 = (float)*(int *)(pSVar3 + 4);
  if (*(int *)(pSVar3 + 4) < 0) {
    local_10 = local_10 + _DAT_00c418d0;
  }
  local_10 = (float)_DAT_00b313b8 / local_10;
  local_18 = local_10 + 1.0;
  local_14 = (float)_DAT_00b313b8 / fVar2 + 1.0;
  local_10 = local_10 + 0.0;
  if (*(int *)(param_2 + 0x14) == 0) {
    (**(code **)(*(int *)this + 0xb0))(param_2);
  }
  iVar1 = *(int *)(param_2 + 0x14);
  if (DAT_00d756a8 != iVar1) {
    (**(code **)(*DAT_00d75698 + 0x104))(DAT_00d75698,0,*(undefined4 *)(iVar1 + 0xc));
    DAT_00d756a8 = iVar1;
  }
  RasterizeQuadAlloc(this,(CVisionViewportDx9 *)0x1,0,unaff_ESI);
  uStack_4 = _DAT_00b2c060;
  uStack_8 = _DAT_00b2c060;
  RasterizeQuadAdd(this,0xffffffff,&uStack_8,0,0x3f800000,&local_18);
  RasterizeQuads(this,this + 0xdf4,in_stack_ffffffd0);
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::TextureForcePixelUpdate
// =================================================
void __thiscall
CVisionViewportDx9::TextureForcePixelUpdate
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CPlugShader *param_2,
          CHmsCamera *param_3)
{
{
  CVisionShaderKeeper *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong uVar4;
  uint uVar5;
  ulong unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CPlugShader *unaff_EDI;
  int *in_stack_00000010;
  ulong in_stack_00000014;
  
  pCVar1 = CVisionViewport::ShaderGetKeeper
                     ((CVisionViewport *)this,(CVisionViewport *)param_1,unaff_EDI);
  pCVar1 = pCVar1 + 0x34;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(pCVar1,unaff_ESI);
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastArray<struct_CDx9ShaderKeeper::SPassDesc>::operator[](pCVar1,pCVar6,unaff_EBP);
      uVar5 = *(uint *)(pSVar3 + 0x80) & 0x7fffffff;
      if (uVar5 != 0) {
        pSVar3 = pSVar3 + 0x84;
        do {
          if ((*(uint *)(pSVar3 + 4) & 2) != 0) {
            uVar4 = *(ulong *)pSVar3;
            if ((*(uint *)(pSVar3 + 4) & 4) != 0) {
              unaff_EBP = uVar4;
              uVar4 = (**(code **)(*in_stack_00000010 + 0xa4))();
            }
            if ((uVar4 != 0) && (*(char *)(*(int *)(uVar4 + 0x1c) + 0x4d) != '\0')) {
              unaff_EBP = in_stack_00000014;
              (**(code **)(*(int *)this + 0xbc))(*(int *)(uVar4 + 0x1c));
            }
          }
          pSVar3 = pSVar3 + 8;
          uVar5 = uVar5 - 1;
          pCVar1 = (CVisionShaderKeeper *)param_2;
          pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1;
        } while (uVar5 != 0);
      }
      pCVar6 = pCVar6 + 1;
    } while (pCVar6 < pCVar2);
  }
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::TextureMemoryMipFree
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CVisionViewportDx9::TextureMemoryMipFree
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,ulong param_2,CPlugBitmap *param_3)
{
{
  CVisionViewportDx9 *this_00;
  void *pvVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  ulong uVar5;
  CFastRadixSort *pCVar6;
  CFastBuffer<class_CSystemFidsFolder*> *pCVar7;
  SCasterCat *pSVar8;
  uint uVar9;
  int iVar10;
  CPlugFileGpuBuilder *pCVar11;
  CFastString *this_01;
  undefined *puVar12;
  CFastRadixSort *unaff_EBX;
  CPlugFileGpuBuilder *pCVar13;
  ulong unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar14;
  CFastArray<class_CManoeuvre*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar15;
  CDx9TextureKeeper *pCVar16;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  char *pcVar17;
  CDx9TextureKeeper *in_stack_00000014;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff90;
  CFastBuffer<class_CSystemFidsFolder*> *pCVar18;
  ulong in_stack_ffffff94;
  ulong uVar19;
  CPlugFileGpuBuilder *pCVar20;
  code *pcVar21;
  CDx9TextureKeeper *pCVar22;
  CPlugFileGpuBuilder *pCVar23;
  CFastBuffer<class_CCrystalFace*> *pCVar24;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar25;
  TiXmlAttributeSet *pTVar26;
  CFastBuffer<class_CSystemFidsFolder*> *pCVar27;
  CPlugFileGpuBuilder *pCVar28;
  char *pcVar29;
  char *pcVar30;
  char *pcVar31;
  CPlugFileGpuBuilder *pCVar32;
  CDx9TextureKeeper *pCVar33;
  char *pcVar34;
  CDx9TextureKeeper *in_stack_ffffffc4;
  CFastRadixSort *in_stack_ffffffcc;
  CFastRadixSort *pCVar35;
  undefined1 auStack_30 [4];
  undefined4 local_2c;
  undefined *local_28;
  undefined1 auStack_24 [4];
  CPlugBitmap *pCStack_20;
  CFastString local_1c [4];
  CFastString local_18 [4];
  undefined1 local_14 [8];
  void *local_c;
  undefined1 *local_8;
  void *local_4;
  
  uVar5 = param_2;
  local_8 = &LAB_00aeaa90;
  local_c = ExceptionList;
  pCVar6 = (CFastRadixSort *)(DAT_00cca150 ^ (uint)&stack0xffffffa0);
  ExceptionList = &local_c;
  DAT_00d778b4 = DAT_00d778b4 + 1;
  local_4 = (void *)0x0;
  if (DAT_00d778b4 < 2) {
    this_00 = this + 0x59c;
    pcVar21 = (code *)0x9870e3;
    pCVar16 = (CDx9TextureKeeper *)this;
    pCVar7 = (CFastBuffer<class_CSystemFidsFolder*> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (this_00,(CFastBuffer<class_CCrystalFace*> *)pCVar6);
    if ((_DAT_00d778b0 & 1) == 0) {
      _DAT_00d778b0 = _DAT_00d778b0 | 1;
      CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                (&DAT_00d778a4,unaff_EDI);
      pCVar6 = (CFastRadixSort *)0x987108;
      _atexit(`public:_int___thiscall_CVisionViewportDx9::
              TextureMemoryMipFree(unsigned_long,class_CPlugBitmap*)'::__l5::
              _dynamic_atexit_destructor_for__LoggedBitmapFids__);
    }
    if (pCVar7 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
      CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(&local_2c,unaff_ESI);
      param_2 = CONCAT31(param_2._1_3_,1);
      pTVar26 = (TiXmlAttributeSet *)0x98712b;
      pCVar27 = pCVar7;
      CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount(&local_28,pCVar7,unaff_EBP);
      pCVar28 = (CPlugFileGpuBuilder *)0x987134;
      CFastRadixSort::CFastRadixSort(local_14,unaff_EBX);
      pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar7 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
        do {
          pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar15,(ulong)in_stack_ffffff90);
          uVar9 = *(uint *)(*(int *)(*(int *)pSVar8 + 0x14) + 0x20);
          in_stack_ffffff90 = pCVar15;
          pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (&stack0xffffffc4,pCVar15,in_stack_ffffff94);
          pCVar15 = pCVar15 + 1;
          *(uint *)pSVar8 = 0x10 - (uVar9 & 7);
        } while (pCVar15 < pCVar7);
      }
      uVar19 = 0;
      pCVar18 = pCVar7;
      pCVar35 = in_stack_ffffffcc;
      CFastRadixSort::Sort(&local_28,in_stack_ffffffcc,(float *)pCVar7,0);
      pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar7 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
        do {
          in_stack_ffffffcc = pCVar35;
          pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar15,(ulong)pCVar18);
          iVar10 = *(int *)(*(int *)pSVar8 + 0x14);
          pCVar18 = (CFastBuffer<class_CSystemFidsFolder*> *)pCVar15;
          pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (&stack0xffffffc4,pCVar15,uVar19);
          pCVar15 = pCVar15 + 1;
          *(undefined4 *)pSVar8 = *(undefined4 *)(iVar10 + 0x30);
          pCVar35 = in_stack_ffffffcc;
        } while (pCVar15 < pCVar7);
      }
      uVar19 = 0;
      pCVar18 = pCVar7;
      CFastRadixSort::Sort(&local_28,in_stack_ffffffcc,(float *)pCVar7,0);
      pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar7 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
        do {
          pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar15,(ulong)pCVar18);
          uVar9 = *(uint *)(*(int *)pSVar8 + 0x4c) & 0xff;
          pCVar18 = (CFastBuffer<class_CSystemFidsFolder*> *)pCVar15;
          if (uVar9 == 7) {
            pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (&stack0xffffffc4,pCVar15,uVar19);
            *(undefined4 *)pSVar8 = 0;
          }
          else if (uVar9 == 0xf) {
            pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (&stack0xffffffc4,pCVar15,uVar19);
            *(undefined4 *)pSVar8 = 1;
          }
          else {
            pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (&stack0xffffffc4,pCVar15,uVar19);
            *(undefined4 *)pSVar8 = 3;
          }
          pCVar15 = pCVar15 + 1;
        } while (pCVar15 < pCVar7);
      }
      CFastRadixSort::Sort(&local_28,in_stack_ffffffcc,(float *)pCVar7,0);
      pcVar34 = (char *)pCStack_20;
      if ((_DAT_00d778b0 & 2) == 0) {
        _DAT_00d778b0 = _DAT_00d778b0 | 2;
        CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                  (&DAT_00d77898,(CFastBuffer<class_CPlugFileSndGen*> *)pcVar21);
        pcVar21 = `public:_int___thiscall_CVisionViewportDx9::
                  TextureMemoryMipFree(unsigned_long,class_CPlugBitmap*)'::__l20::
                  _dynamic_atexit_destructor_for__BitmapToFrees__;
        _atexit(`public:_int___thiscall_CVisionViewportDx9::
                TextureMemoryMipFree(unsigned_long,class_CPlugBitmap*)'::__l20::
                _dynamic_atexit_destructor_for__BitmapToFrees__);
        pcVar34 = (char *)pCStack_20;
      }
      CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
                (&DAT_00d77898,(GmFrustumIso4 *)pcVar21);
      pcVar31 = (char *)0x0;
      pCVar32 = (CPlugFileGpuBuilder *)0x0;
      this = (CVisionViewportDx9 *)in_stack_ffffffc4;
      while ((pCVar7 = pCVar7 + -1, -1 < (int)pCVar7 &&
             ((CVisionViewportDx9 *)(pCVar32 + (int)pcVar31) < param_1))) {
        pcVar30 = (char *)pCVar7;
        pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (pCVar16 + 0x59c,
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                             (this + (int)pCVar7 * 4),(ulong)pCVar6);
        pCVar33 = *(CDx9TextureKeeper **)pSVar8;
        pvVar1 = *(void **)(pCVar33 + 0x14);
        this = (CVisionViewportDx9 *)pCVar33;
        if (((*(int *)((int)pvVar1 + 0xc) != 0) || (pCVar33 == (CDx9TextureKeeper *)param_3)) &&
           (*(int *)((int)pvVar1 + 0x10) != 1)) {
          pCVar6 = (CFastRadixSort *)0x0;
          pCVar20 = (CPlugFileGpuBuilder *)0x9872c4;
          pCVar22 = pCVar33;
          uVar19 = CDx9TextureKeeper::BiggerMipGetSizeToWin
                             (pvVar1,pCVar33,(CPlugBitmap *)0x0,(ulong *)pTVar26);
          if (uVar19 == 0) {
            pCVar13 = *(CPlugFileGpuBuilder **)(pCVar33 + 8);
            if ((pCVar13 != (CPlugFileGpuBuilder *)0x0) ||
               ((pCVar7 = (CFastBuffer<class_CSystemFidsFolder*> *)pcVar30,
                *(int *)(pCVar33 + 0x48) != 0 &&
                (pCVar13 = *(CPlugFileGpuBuilder **)(*(int *)(pCVar33 + 0x48) + 8),
                pCVar13 != (CPlugFileGpuBuilder *)0x0)))) {
              pTVar26 = (TiXmlAttributeSet *)&stack0xffffffc8;
              pCVar6 = (CFastRadixSort *)0x987325;
              pCVar23 = pCVar13;
              iVar10 = CFastArray<class_CGameMenuFrame*>::Find
                                 (&DAT_00d778a4,(CFastArray<class_GxTexCoordSet> *)pTVar26,
                                  (GxTexCoordSet *)pCVar27);
              pCVar7 = (CFastBuffer<class_CSystemFidsFolder*> *)pcVar30;
              if (iVar10 == -1) {
                CFastBuffer<class_CDx9TextureKeeper*>::Add
                          (&DAT_00d778a4,(TiXmlAttributeSet *)&stack0xffffffcc,
                           (TiXmlAttribute *)pCVar28);
                CFastString::CFastString
                          (local_1c,(CFastString *)"[Dx9] Warning: can\'t free video memory on a ",
                           (char *)unaff_EBX);
                pCVar28 = *(CPlugFileGpuBuilder **)(*(int *)(pCVar33 + 0x48) + 0x1c);
                pTVar26 = *(TiXmlAttributeSet **)(*(int *)(pCVar33 + 0x48) + 0x18);
                pcVar29 = " Texture since ";
                pCVar6 = (CFastRadixSort *)0x98736e;
                pCVar11 = CFastString::operator<<(local_18,(CPlugFileGpuBuilder *)pTVar26,"x");
                pCVar27 = (CFastBuffer<class_CSystemFidsFolder*> *)0x987375;
                pCVar11 = CFastString::operator<<((CFastString *)pCVar11,pCVar28,pcVar29);
                unaff_EBX = (CFastRadixSort *)0x98737c;
                pCVar11 = CFastString::operator<<
                                    ((CFastString *)pCVar11,(CPlugFileGpuBuilder *)pcVar30,pcVar31);
                pcVar31 = (char *)0x987383;
                CFastString::operator<<((CFastString *)pCVar11,pCVar32,(char *)pCVar16);
                pcVar17 = (char *)((*(uint *)((int)pvVar1 + 0x1c) >> 0x1c) +
                                  (*(uint *)((int)pvVar1 + 0x20) & 7));
                pCVar32 = (CPlugFileGpuBuilder *)0x987399;
                pcVar29 = (char *)CDx9TextureKeeper::GetMipLevelSkipCountMax
                                            (pvVar1,pCVar33,(CPlugBitmap *)pcVar34);
                if ((*(byte *)((int)pvVar1 + 0x20) & 8) == 0) {
                  pcVar34 = "not mip-mapped.";
LAB_009873e2:
                  this_01 = (CFastString *)&local_4;
                }
                else {
                  if (pcVar17 < pcVar29) {
                    pcVar34 = &DAT_00bd2f78;
                    goto LAB_009873e2;
                  }
                  pcVar34 = &DAT_00bd2378;
                  pCVar32 = (CPlugFileGpuBuilder *)&DAT_00b2ce74;
                  pcVar30 = "reach skip limit (";
                  unaff_EBX = (CFastRadixSort *)0x9873c4;
                  pCVar11 = CFastString::operator<<
                                      ((CFastString *)&local_4,
                                       (CPlugFileGpuBuilder *)"reach skip limit (",pcVar17);
                  pcVar31 = (char *)0x9873cb;
                  pCVar11 = CFastString::operator<<((CFastString *)pCVar11,pCVar32,pcVar29);
                  pCVar33 = (CDx9TextureKeeper *)0x9873d2;
                  pCVar11 = CFastString::operator<<
                                      ((CFastString *)pCVar11,(CPlugFileGpuBuilder *)pcVar34,
                                       (char *)this);
                  this = (CVisionViewportDx9 *)0x9873d9;
                  this_01 = (CFastString *)
                            CFastString::operator<<((CFastString *)pCVar11,pCVar23,(char *)pCVar35);
                }
                CFastString::operator<<(this_01,pCVar20,(char *)pCVar22);
                if ((pCVar13 != (CPlugFileGpuBuilder *)0x0) &&
                   (iVar10 = (**(code **)(*(int *)pCVar13 + 0x10))(0xb00a000), iVar10 != 0)) {
                  pCVar23 = (CPlugFileGpuBuilder *)&DAT_00b30988;
                  pCVar20 = CFastString::operator<<
                                      ((CFastString *)&local_2c,(CPlugFileGpuBuilder *)&DAT_00b30b34
                                       ,(char *)(pCVar13 + 0x74));
                  pCVar20 = CFastString::operator<<((CFastString *)pCVar20,pCVar23,(char *)pCVar6);
                  pCVar6 = (CFastRadixSort *)0x987426;
                  CFastString::operator<<
                            ((CFastString *)pCVar20,(CPlugFileGpuBuilder *)pTVar26,(char *)pCVar27);
                }
                local_4 = (void *)CONCAT31(local_4._1_3_,2);
                pCVar16 = pCVar33;
                pCVar7 = (CFastBuffer<class_CSystemFidsFolder*> *)pcVar30;
                if (local_28 != PTR_DAT_00bbf7d8) {
                  puVar12 = local_28 + -1;
                  if ((local_28[-1] & 0x80) != 0) {
                    puVar12 = local_28 + -4;
                  }
                  operator_delete__(puVar12);
                  local_2c = 0;
                  pCVar16 = pCVar33;
                  local_28 = PTR_DAT_00bbf7d8;
                  pCVar7 = (CFastBuffer<class_CSystemFidsFolder*> *)pcVar30;
                }
              }
            }
          }
          else {
            pTVar26 = (TiXmlAttributeSet *)&stack0xffffffc8;
            pCVar6 = (CFastRadixSort *)0x9872d9;
            CFastBuffer<class_CDx9TextureKeeper*>::Add
                      (&DAT_00d77898,pTVar26,(TiXmlAttribute *)pCVar27);
            if (pCVar33 == in_stack_00000014) {
              this = this + uVar19;
            }
            else {
              pcVar34 = pcVar34 + uVar19;
            }
          }
        }
      }
      if (param_1 <= (CVisionViewportDx9 *)(pCVar32 + (int)pcVar31)) {
        pCVar24 = *(CFastBuffer<class_CCrystalFace*> **)(pCVar16 + 0x9f8);
        pCVar33 = pCVar16;
        (**(code **)(*(int *)pCVar24 + 0x10))();
        pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                  CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d77898,pCVar24);
        pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (pCVar15 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          do {
            pCVar25 = pCVar14;
            pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (&DAT_00d77898,pCVar14,(ulong)pCVar6);
            pCVar22 = *(CDx9TextureKeeper **)pSVar8;
            pvVar1 = *(void **)(pCVar22 + 0x14);
            pCVar16 = pCVar33;
            if (*(int *)((int)pvVar1 + 0xc) == 0) {
              pCVar6 = (CFastRadixSort *)0x0;
              pCVar25 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar22;
              CDx9TextureKeeper::BiggerMipGetSizeToWin
                        (pvVar1,pCVar22,(CPlugBitmap *)0x0,(ulong *)pTVar26);
              pCVar16 = pCVar33;
            }
            CDx9TextureKeeper::BiggerMipLevelFree(pvVar1,pCVar22,(CPlugBitmap *)0x1,(ulong)pCVar25);
            pCVar14 = pCVar14 + 1;
            pCVar33 = pCVar16;
          } while (pCVar14 < pCVar15);
        }
        (**(code **)(**(int **)(pCVar16 + 0x9f8) + 0x10))(*(int **)(pCVar16 + 0x9f8));
        dVar2 = (double)(int)pcVar31;
        if ((int)pcVar31 < 0) {
          dVar2 = dVar2 + _DAT_00b3dca0;
        }
        dVar4 = (double)*(int *)(pCVar16 + 0x210);
        if (*(int *)(pCVar16 + 0x210) < 0) {
          dVar4 = dVar4 + _DAT_00b3dca0;
        }
        dVar3 = (double)(int)param_2;
        if ((int)uVar5 < 0) {
          dVar3 = dVar3 + _DAT_00b3dca0;
        }
        uVar9 = (uint)(dVar4 + dVar2 * _DAT_00bd2f70 <= dVar3);
        local_4 = (void *)CONCAT31(local_4._1_3_,1);
        CFastRadixSort::~CFastRadixSort(auStack_24,pCVar6);
        CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>
                  (auStack_30,(CFastArray<class_CFuncShader*> *)pTVar26);
        goto LAB_009875cb;
      }
      local_4._1_3_ = (undefined3)((uint)local_4 >> 8);
      local_4 = (void *)CONCAT31(local_4._1_3_,1);
      CFastRadixSort::~CFastRadixSort(auStack_24,pCVar6);
      CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>
                (auStack_30,(CFastArray<class_CFuncShader*> *)pTVar26);
    }
    if (DAT_00d77894 == 0) {
      DAT_00d77894 = 1;
      (**(code **)(*(int *)this + 0xfc))();
    }
  }
  uVar9 = 0;
LAB_009875cb:
  DAT_00d778b4 = DAT_00d778b4 - 1;
  ExceptionList = local_4;
  return uVar9;
}
}

// =================================================
// Function: CVisionViewportDx9::TransformStackCameraPush
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CVisionViewportDx9::TransformStackCameraPush
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,CHmsCamera *param_2,
          CPlugBitmapRenderCamera *param_3,CPlugBitmapRenderVDepPlaneY *param_4)
{
{
  float fVar1;
  CHmsCamera *pCVar2;
  SCasterCat *pSVar3;
  undefined4 *puVar4;
  SCasterCat *pSVar5;
  SNewTriangleVert *this_00;
  SCasterCat *pSVar6;
  int iVar7;
  ulong unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CPlugBitmapRenderCamera *pCVar8;
  ulong unaff_EDI;
  int in_stack_00000018;
  float in_stack_00000024;
  CHmsCamera *in_stack_0000002c;
  CHmsCamera *in_stack_00000030;
  int in_stack_00000034;
  CHmsCamera *in_stack_00000038;
  int in_stack_0000003c;
  float in_stack_00000040;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *pCVar9;
  ulong uVar10;
  ulong in_stack_ffffffd8;
  SNewTriangleVert *pSVar11;
  ulong in_stack_ffffffe0;
  ulong in_stack_ffffffe4;
  int in_stack_ffffffec;
  SHmsRenderRect *in_stack_fffffff0;
  CHmsCamera *in_stack_fffffff8;
  CVisionViewportDx9 *in_stack_fffffffc;
  CVisionViewportDx9 *pCVar12;
  
  CFastBuffer<class_CSystemFidsFolder*>::SetCount
            (this + 0x454,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,unaff_EDI);
  pSVar3 = CFastBuffer<struct_CHmsViewport::SVisualLocation>::operator[]
                     (this + 0x454,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
  *(uint *)(pSVar3 + 0xa0) = *(uint *)(pSVar3 + 0xa0) | 1;
  puVar4 = (undefined4 *)(**(code **)(*(int *)param_3 + 0x78))();
  pSVar6 = pSVar3 + 0x30;
  pSVar5 = pSVar6;
  for (iVar7 = 0xc; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(undefined4 *)pSVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    pSVar5 = pSVar5 + 4;
  }
  pCVar8 = param_3 + 0x88;
  pSVar5 = pSVar3;
  for (iVar7 = 0xc; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(undefined4 *)pSVar5 = *(undefined4 *)pCVar8;
    pCVar8 = pCVar8 + 4;
    pSVar5 = pSVar5 + 4;
  }
  pSVar5 = pSVar3;
  (**(code **)(*(int *)this + 0x19c))();
  pSVar5 = GmMat4::operator[](pSVar3 + 0x60,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                              (ulong)pSVar5);
  pCVar9 = *(CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> **)
            (this + 0x9f8);
  uVar10 = 2;
  (**(code **)(*(int *)pCVar9 + 0xb0))();
  *(uint *)(pSVar3 + 0xa0) = *(uint *)(pSVar3 + 0xa0) & 0xfffffffd;
  this_00 = CFastBuffer<struct_SHmsRenderRect>::GetLastElem(this + 0x484,pCVar9);
  if ((param_2 == (CHmsCamera *)0x0) || (((byte)param_2[0x5c] & 1) == 0)) {
    *(undefined4 *)(this_00 + 0x20) = 0;
  }
  else {
    pSVar11 = this_00;
    SHmsRenderRect::SetRect
              (this_00,(CDynaSpecular *)(param_1 + 0x1c4),uVar10,(ulong)pSVar5,unaff_EBP,unaff_EBX,
               in_stack_ffffffd8);
    *(undefined4 *)this_00 = 0;
    *(undefined4 *)(this_00 + 4) = 0x3f800000;
    this_00 = pSVar11;
  }
  CFastBuffer<class_CSystemFidsFolder*>::SetCount
            (this + 0x460,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,(ulong)this_00);
  pSVar5 = CFastBuffer<struct_CHmsViewport::SClippingFrustum>::operator[]
                     (this + 0x460,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      in_stack_ffffffe0);
  CFastBuffer<class_CSystemFidsFolder*>::SetCount
            (this + 0x478,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,in_stack_ffffffe4);
  pSVar6 = CFastBuffer<struct_SHmsCameraProjection>::operator[]
                     (this + 0x478,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      (ulong)pSVar6);
  if (in_stack_00000030 == (CHmsCamera *)0x0) {
    in_stack_00000030 = *(CHmsCamera **)(param_1 + 0x1fc);
    if (in_stack_0000002c != (CHmsCamera *)0x0) {
      CHmsCamera::ScissorRectSetEnable
                ((CHmsCamera *)param_1,(CHmsCamera *)(*(uint *)(in_stack_0000002c + 0x5c) >> 2 & 1),
                 in_stack_ffffffec);
    }
    fVar1 = (float)*(int *)(this + 0xa4);
    if (*(int *)(this + 0xa4) < 0) {
      fVar1 = fVar1 + _DAT_00c418d0;
    }
    in_stack_0000002c = (CHmsCamera *)(*(float *)(this + 0x11c) / fVar1);
    CHmsCamera::ZClipCompute
              ((CHmsCamera *)param_1,in_stack_0000002c,(float)&param_3,(GmFrustum *)param_1,
               in_stack_fffffff0);
    CHmsCamera::ScissorRectSetEnable((CHmsCamera *)param_1,in_stack_00000038,(int)pSVar5);
    if ((in_stack_00000038 != (CHmsCamera *)0x0) && (((byte)in_stack_00000038[0x5c] & 8) != 0)) {
      param_4 = (CPlugBitmapRenderVDepPlaneY *)
                CHmsCamera::GetFov((CHmsCamera *)param_1,in_stack_fffffff8);
      if (in_stack_00000018 == 0) {
        in_stack_00000040 = in_stack_00000024;
        in_stack_00000038 = in_stack_00000030;
      }
      else {
        in_stack_00000040 = in_stack_00000024 - (float)in_stack_00000030;
        in_stack_00000038 = (CHmsCamera *)((float)in_stack_00000030 + in_stack_00000024);
      }
      if (*(int *)(param_1 + 0x134) == 2) {
        GmFrustum::SetFovX(&stack0x00000018,(GmFrustum *)param_4,
                           *(float *)(in_stack_0000003c + 0x70),in_stack_00000040,
                           (float)in_stack_00000038,(float)in_stack_fffffffc);
      }
      else {
        GmFrustum::SetFovY(&stack0x00000018,(GmFrustum *)param_4,
                           *(float *)(in_stack_0000003c + 0x70),in_stack_00000040,
                           (float)in_stack_00000038,(float)in_stack_fffffffc);
      }
    }
    CHmsViewport::SClippingFrustum::Set
              (param_4,(CMwCmdScriptVarBool *)&stack0x0000001c,in_stack_00000018);
    pCVar12 = param_1;
    (**(code **)(*(int *)this + 0x1a8))();
    ViewportSet(this,param_1,(SHmsRenderRect *)pCVar12);
    (**(code **)(*(int *)this + 0x1a0))(pSVar6,param_4);
  }
  else {
    GmFrustum::Set(&param_2,(CMwCmdScriptVarBool *)(param_1 + 0x118),in_stack_ffffffec);
    pCVar2 = param_2;
    CPlugViewDepLocator::AdaptFrustum
              (*(CPlugViewDepLocator **)(in_stack_00000034 + 0x5c),(CPlugViewDepLocator *)param_2,
               (GmIso4 *)pSVar3,(GmIso4 *)&param_3,(GmFrustum *)pSVar6,(GmMat4 *)in_stack_fffffff0);
    CHmsViewport::SClippingFrustum::Set(param_1,(CMwCmdScriptVarBool *)&param_4,(int)pCVar2);
    param_1 = in_stack_fffffffc;
    if (((byte)this[0x414] & 1) != 0) {
      pSVar5 = GmMat4::operator[](pSVar6,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                                  (ulong)pSVar5);
      *(float *)pSVar5 = -*(float *)pSVar5;
      *(float *)(pSVar5 + 4) = -*(float *)(pSVar5 + 4);
      *(float *)(pSVar5 + 8) = -*(float *)(pSVar5 + 8);
      *(float *)(pSVar5 + 0xc) = -*(float *)(pSVar5 + 0xc);
      param_1 = in_stack_fffffffc;
    }
    if (((byte)this[0x414] & 2) != 0) {
      pSVar5 = GmMat4::operator[](pSVar6,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                                  (ulong)in_stack_fffffff8);
      *(float *)pSVar5 = -*(float *)pSVar5;
      *(float *)(pSVar5 + 4) = -*(float *)(pSVar5 + 4);
      *(float *)(pSVar5 + 8) = -*(float *)(pSVar5 + 8);
      *(float *)(pSVar5 + 0xc) = -*(float *)(pSVar5 + 0xc);
    }
    GmMat4::SetTranspose(pSVar6 + 0x40,(GmMat2 *)pSVar6,(GmMat2 *)in_stack_fffffff8);
  }
  pSVar5 = GmMat4::operator[](pSVar6 + 0x40,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                              (ulong)param_1);
  (**(code **)(**(int **)(this + 0x9f8) + 0xb0))(*(int **)(this + 0x9f8),3,pSVar5);
  *(uint *)(pSVar6 + 0xcc) = *(uint *)(pSVar6 + 0xcc) & 0xfffffffe;
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::TriggerErrorOutOfMemory
// =================================================
void __thiscall
CVisionViewportDx9::TriggerErrorOutOfMemory(CVisionViewportDx9 *this,CVisionViewportDx9 *param_1)
{
{
  *(undefined4 *)(this + 0x318) = 1;
  if (*(int *)(this + 0x314) == 0) {
    *(undefined4 *)(this + 0x314) = 3;
  }
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::ViewportSet
// =================================================
void __thiscall
CVisionViewportDx9::ViewportSet
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,SHmsRenderRect *param_2)
{
{
  SNewTriangleVert *pSVar1;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_EDI;
  
  pSVar1 = CFastBuffer<struct_CVisionViewportDx9::SRenderTarget>::GetLastElem
                     (this + 0x9fc,unaff_EDI);
  *(undefined4 *)(pSVar1 + 0x30) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(pSVar1 + 0x34) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(pSVar1 + 0x38) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(pSVar1 + 0x3c) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(pSVar1 + 0x40) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(pSVar1 + 0x44) = *(undefined4 *)(param_1 + 0x1c);
  (**(code **)(**(int **)(this + 0x9f8) + 0xbc))(*(int **)(this + 0x9f8),param_1 + 8);
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::ViewportShrink1PixelBorder
// =================================================
void __thiscall
CVisionViewportDx9::ViewportShrink1PixelBorder
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1,float param_2,float param_3)
{
{
  SNewTriangleVert *pSVar1;
  int iVar2;
  SNewTriangleVert *this_00;
  SNewTriangleVert *pSVar3;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_ESI;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_EDI;
  
  this_00 = CFastBuffer<struct_SHmsRenderRect>::GetLastElem(this + 0x484,unaff_EDI);
  pSVar1 = this_00 + 8;
  *(undefined4 *)pSVar1 = 1;
  *(undefined4 *)(this_00 + 0xc) = 1;
  *(int *)(this_00 + 0x10) = *(int *)(this + 0x2a4) + -2;
  iVar2 = *(int *)(this + 0x2a8);
  *(float *)(this_00 + 0x18) = param_2;
  *(int *)(this_00 + 0x14) = iVar2 + -2;
  *(float *)(this_00 + 0x1c) = param_3;
  pSVar3 = this_00;
  (**(code **)(*(int *)this + 0x1ac))();
  SHmsRenderRect::ComputeTransfosFromRect(this_00,(SHmsRenderRect *)pSVar3);
  pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SRenderTarget>::GetLastElem
                     (this + 0x9fc,unaff_ESI);
  *(undefined4 *)(pSVar3 + 0x30) = *(undefined4 *)pSVar1;
  *(undefined4 *)(pSVar3 + 0x34) = *(undefined4 *)(this_00 + 0xc);
  *(undefined4 *)(pSVar3 + 0x38) = *(undefined4 *)(this_00 + 0x10);
  *(undefined4 *)(pSVar3 + 0x3c) = *(undefined4 *)(this_00 + 0x14);
  *(undefined4 *)(pSVar3 + 0x40) = *(undefined4 *)(this_00 + 0x18);
  *(undefined4 *)(pSVar3 + 0x44) = *(undefined4 *)(this_00 + 0x1c);
  (**(code **)(**(int **)(this + 0x9f8) + 0xbc))(*(int **)(this + 0x9f8),pSVar1);
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::VisibleZoneCleanShadowAndProjectors
// =================================================
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x009a2cf4) */
/* WARNING: Removing unreachable block (ram,0x009a2cc2) */

void __thiscall
CVisionViewportDx9::VisibleZoneCleanShadowAndProjectors
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1)
{
{
  int in_EAX;
  int iVar1;
  char cVar2;
  int in_EDX;
  int unaff_EBP;
  uint *unaff_ESI;
  
  cVar2 = (char)((uint)this >> 8);
  if (!SBORROW1(cVar2,*(char *)(in_EAX + 0x3a))) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (cVar2 <= *(char *)(in_EAX + 0x3a)) {
    param_1[-0x25ce39cf] =
         (CVisionViewportDx9)((byte)param_1[-0x25ce39cf] ^ (byte)((uint)in_EDX >> 8));
    *(uint *)(in_EDX + (int)unaff_ESI) = *(uint *)(in_EDX + (int)unaff_ESI) ^ unaff_EBP - 1U;
    DAT_f330e330 = (byte)in_EAX;
    iVar1 = CONCAT31((int3)((uint)in_EAX >> 8),DAT_f330e330 ^ (byte)((uint)param_1 >> 8));
    if (iVar1 != *(int *)(iVar1 + 0x34)) {
      swi(4);
    }
    DAT_f330e331 = DAT_00000000;
    *(undefined4 *)(((uint)&stack0x00000008 ^ *unaff_ESI) - 4) = 1;
    return;
  }
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::VisibleZonePrepareShadowAndProjectors
// =================================================
/* WARNING: Control flow encountered bad instruction data */

void __thiscall
CVisionViewportDx9::VisibleZonePrepareShadowAndProjectors
          (CVisionViewportDx9 *this,CVisionViewportDx9 *param_1)
{
{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *unaff_EBP;
  undefined4 uStack_8;
  
  puVar2 = (undefined4 *)&stack0xfffffffc;
  cVar1 = '\x16';
  do {
    unaff_EBP = unaff_EBP + -1;
    puVar2 = puVar2 + -1;
    *puVar2 = *unaff_EBP;
    cVar1 = cVar1 + -1;
  } while ('\0' < cVar1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

