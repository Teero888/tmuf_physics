// Class implementation: CSceneVehicleCarTuning

// =================================================
// Function: CSceneVehicleCarTuning::CSceneVehicleCarTuning
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCarTuning::CSceneVehicleCarTuning
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1)
{
{
  CSceneVehicleCarTuning *pCVar1;
  undefined4 uVar2;
  float fVar3;
  CFuncKeysReal *pCVar4;
  CFuncKeysReal *pCVar5;
  CMwNod *extraout_EAX;
  CMwNod *extraout_EAX_00;
  CFuncKeysReal *pCVar6;
  CMwNod *extraout_EAX_01;
  CFuncKeysReal *pCVar7;
  CMwNod *extraout_EAX_02;
  CFuncKeysReal *pCVar8;
  CMwNod *extraout_EAX_03;
  CMwNod *extraout_EAX_04;
  CMwNod *extraout_EAX_05;
  CMwNod *extraout_EAX_06;
  CMwNod *extraout_EAX_07;
  CMwNod *extraout_EAX_08;
  CMwNod *extraout_EAX_09;
  CMwNod *extraout_EAX_10;
  CMwNod *extraout_EAX_11;
  CMwNod *extraout_EAX_12;
  CMwNod *extraout_EAX_13;
  CMwNod *extraout_EAX_14;
  CMwNod *extraout_EAX_15;
  CMwNod *extraout_EAX_16;
  CMwNod *extraout_EAX_17;
  CMwNod *extraout_EAX_18;
  CMwNod *extraout_EAX_19;
  CMwNod *extraout_EAX_20;
  CMwNod *extraout_EAX_21;
  CMwNod *extraout_EAX_22;
  SCasterCat *pSVar9;
  CMwNod *extraout_EAX_23;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBX;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBP;
  CMwNod *this_00;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  float fVar10;
  float in_stack_00000008;
  CFuncKeysReal *in_stack_00000010;
  CMwNod *in_stack_00000014;
  CFuncKeysReal *in_stack_00000018;
  CMwNod *in_stack_0000001c;
  CFuncKeysReal *in_stack_00000020;
  CMwNod *in_stack_00000024;
  CMwNod *in_stack_0000002c;
  CMwNod *in_stack_00000034;
  CMwNod *in_stack_0000003c;
  CMwNod *in_stack_00000044;
  CMwNod *in_stack_0000004c;
  CFuncKeysReal *in_stack_00000054;
  float in_stack_0000005c;
  CMwNod *in_stack_00000064;
  CFuncKeysReal *in_stack_00000068;
  CFuncKeysReal *in_stack_00000070;
  CMwNod *in_stack_00000074;
  float in_stack_0000007c;
  CMwNod *in_stack_00000084;
  CMwNod *in_stack_0000008c;
  CFuncKeysReal *in_stack_00000090;
  CMwNod *in_stack_00000094;
  CMwNod *in_stack_0000009c;
  CMwNod *in_stack_000000a4;
  CFuncKeysReal *in_stack_000000ac;
  float in_stack_000000b4;
  CFuncKeysReal *in_stack_000000bc;
  CMwNod *in_stack_000000c0;
  float in_stack_000000c8;
  CFuncKeysReal *in_stack_000000cc;
  CMwNod *in_stack_000000d0;
  float in_stack_000000d8;
  CFuncKeysReal *in_stack_000000dc;
  CMwNod *in_stack_000000e0;
  float in_stack_000000e8;
  CFuncKeysReal *in_stack_000000ec;
  CMwNod *in_stack_000000f0;
  float in_stack_000000f8;
  CFuncKeysReal *in_stack_000000fc;
  CMwNod *in_stack_00000100;
  float in_stack_00000108;
  ulong in_stack_0000010c;
  ulong in_stack_00000110;
  ulong in_stack_00000118;
  ulong in_stack_0000011c;
  ulong in_stack_00000120;
  ulong in_stack_00000124;
  CFuncKeysReal *in_stack_00000128;
  CMwNod *in_stack_0000012c;
  float in_stack_00000130;
  float in_stack_00000134;
  float in_stack_00000138;
  float in_stack_0000013c;
  ulong in_stack_00000144;
  ulong in_stack_00000148;
  ulong in_stack_0000014c;
  ulong in_stack_00000150;
  ulong in_stack_00000154;
  ulong in_stack_00000158;
  ulong in_stack_0000015c;
  ulong in_stack_00000160;
  ulong in_stack_00000164;
  ulong in_stack_00000168;
  ulong in_stack_0000016c;
  ulong in_stack_00000170;
  ulong in_stack_00000174;
  ulong in_stack_00000178;
  ulong in_stack_0000017c;
  ulong in_stack_00000180;
  ulong in_stack_00000184;
  ulong in_stack_00000188;
  ulong in_stack_0000018c;
  ulong in_stack_00000190;
  ulong in_stack_00000194;
  ulong in_stack_00000198;
  ulong in_stack_0000019c;
  ulong in_stack_000001a0;
  ulong in_stack_000001a4;
  ulong in_stack_000001a8;
  void *in_stack_000001c8;
  CSceneVehicleCarTuning *pCVar11;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_fffffff0;
  CMwNod *pCVar12;
  float fVar13;
  
  fVar13 = -NAN;
  pCVar12 = (CMwNod *)&LAB_00ad0082;
  pCVar8 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar11 = this;
  CSceneVehicleTuning::CSceneVehicleTuning
            ((CSceneVehicleTuning *)this,
             (CSceneVehicleTuning *)(DAT_00cca150 ^ (uint)&stack0xffffffdc));
  *(undefined ***)this = vftable;
  fVar10 = 0.0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0xac) = 0;
  *(undefined4 *)(this + 0xb8) = 0;
  *(undefined4 *)(this + 0xbc) = 0;
  *(undefined4 *)(this + 0x1b4) = 0;
  *(undefined4 *)(this + 0x1bc) = 0;
  *(undefined4 *)(this + 0x1c4) = 0;
  *(undefined4 *)(this + 0x1e0) = 0;
  *(undefined4 *)(this + 0x1ec) = 0;
  *(undefined4 *)(this + 0x1f0) = 0;
  *(undefined4 *)(this + 0x210) = 0;
  *(undefined4 *)(this + 0x214) = 0;
  *(undefined4 *)(this + 0x218) = 0;
  *(undefined4 *)(this + 0x224) = 0;
  *(undefined4 *)(this + 0x230) = 0;
  *(undefined4 *)(this + 0x250) = 0;
  *(undefined4 *)(this + 0x25c) = 0;
  *(undefined4 *)(this + 0x260) = 0;
  *(undefined4 *)(this + 0x288) = 0;
  *(undefined4 *)(this + 0x2a4) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x2c4,unaff_EDI);
  pCVar1 = this + 0x2d4;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(pCVar1,unaff_ESI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x2e0,unaff_EBP);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x2f8,unaff_EBX);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x304,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar11);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x310,in_stack_fffffff0);
  *(undefined4 *)(this + 0x36c) = 0;
  *(undefined4 *)(this + 0x378) = 0;
  *(undefined4 *)(this + 0x380) = 0;
  *(undefined4 *)(this + 0x2c) = _DAT_00ba3814;
  *(undefined4 *)(this + 0x30) = _DAT_00ba3810;
  *(CFuncKeysReal **)(this + 0x3c) = _DAT_00b32e98;
  *(undefined4 *)(this + 0x88) = 1000;
  *(undefined4 *)(this + 0x8c) = 1000;
  *(undefined4 *)(this + 0x38) = 0x3f800000;
  *(undefined4 *)(this + 0x90) = 200;
  *(undefined4 *)(this + 0x58) = 0x3f800000;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0xf8) = 1000;
  pCVar7 = _DAT_00b36194;
  *(undefined4 *)(this + 0xfc) = 1000;
  *(CFuncKeysReal **)(this + 0x60) = pCVar7;
  *(undefined4 *)(this + 0x10c) = 0;
  *(undefined4 *)(this + 0x110) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x364) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0xc0) = 0;
  *(undefined4 *)(this + 0x6c) = 0x3f800000;
  pCVar5 = _DAT_00b31460;
  *(CFuncKeysReal **)(this + 0x70) = _DAT_00b31460;
  pCVar6 = _DAT_00b36160;
  *(CFuncKeysReal **)(this + 0x94) = _DAT_00b36160;
  *(CFuncKeysReal **)(this + 0x74) = pCVar6;
  uVar2 = _DAT_00b41d80;
  *(undefined4 *)(this + 0x98) = _DAT_00b41d80;
  *(undefined4 *)(this + 0x9c) = 0;
  *(undefined4 *)(this + 0xb4) = 0;
  *(undefined4 *)(this + 0x198) = 0;
  *(undefined4 *)(this + 0xe4) = 0x3f800000;
  *(undefined4 *)(this + 0x54) = 0x3f800000;
  *(undefined4 *)(this + 0xe8) = 0x3f800000;
  *(undefined4 *)(this + 0xec) = 0x3f800000;
  *(undefined4 *)(this + 0xc4) = _DAT_00b9f20c;
  *(undefined4 *)(this + 200) = _DAT_00ba1318;
  *(CFuncKeysReal **)(this + 0xcc) = pCVar7;
  *(undefined4 *)(this + 0xd0) = uVar2;
  *(undefined4 *)(this + 0x50) = 0x3f800000;
  *(CFuncKeysReal **)(this + 0x40) = pCVar6;
  *(undefined4 *)(this + 0x44) = 0;
  uVar2 = _DAT_00b36174;
  *(undefined4 *)(this + 0x48) = _DAT_00b36174;
  *(undefined4 *)(this + 0x4c) = uVar2;
  *(undefined4 *)(this + 0xa4) = _DAT_00b2c060;
  *(undefined4 *)(this + 0xa8) = 0;
  *(undefined4 *)(this + 0xb0) = _DAT_00b36138;
  *(undefined4 *)(this + 0xd4) = 0;
  *(undefined4 *)(this + 0xd8) = 0;
  *(undefined4 *)(this + 0xdc) = 0;
  *(undefined4 *)(this + 0xe0) = 0;
  fVar3 = DAT_00b36188;
  *(float *)(this + 0xf0) = DAT_00b36188;
  *(float *)(this + 0xf4) = fVar3;
  *(undefined4 *)(this + 0x100) = 0x3f800000;
  *(CFuncKeysReal **)(this + 0x104) = pCVar7;
  uVar2 = _DAT_00b3380c;
  *(undefined4 *)(this + 0x108) = _DAT_00b3380c;
  *(undefined4 *)(this + 0x368) = _DAT_00ba3760;
  *(undefined4 *)(this + 0x114) = 0;
  *(undefined4 *)(this + 0x118) = 0;
  *(undefined4 *)(this + 0x11c) = 0;
  *(undefined4 *)(this + 0x120) = 0;
  *(undefined4 *)(this + 0x124) = 0;
  *(CFuncKeysReal **)(this + 0x194) = _DAT_00b3618c;
  *(float *)(this + 0x128) = _DAT_00b33a54;
  *(undefined4 *)(this + 300) = uVar2;
  *(undefined4 *)(this + 0x130) = _DAT_00b99518;
  *(undefined4 *)(this + 0x134) = 0x3f800000;
  *(CFuncKeysReal **)(this + 0x138) = pCVar5;
  *(CFuncKeysReal **)(this + 0x13c) = pCVar5;
  *(CFuncKeysReal **)(this + 0x140) = pCVar5;
  *(undefined4 *)(this + 0x16c) = 9;
  *(undefined4 *)(this + 400) = 1;
  *(undefined4 *)(this + 0x144) = 0;
  *(undefined4 *)(this + 0x350) = 0;
  *(undefined4 *)(this + 0x148) = 0;
  *(undefined4 *)(this + 0x354) = 0;
  *(undefined4 *)(this + 0x358) = 0;
  *(undefined4 *)(this + 0x154) = uVar2;
  *(CFuncKeysReal **)(this + 0x158) = pCVar5;
  *(undefined4 *)(this + 0x15c) = 0x3f800000;
  *(undefined4 *)(this + 0x160) = 0x3f800000;
  *(undefined4 *)(this + 0x164) = 0x3f800000;
  *(undefined4 *)(this + 0x168) = _DAT_00b36144;
  fVar3 = _DAT_00b41140;
  *(float *)(this + 0x170) = _DAT_00b41140;
  uVar2 = _DAT_00b3613c;
  *(undefined4 *)(this + 0x174) = _DAT_00b3613c;
  *(undefined4 *)(this + 0x188) = uVar2;
  *(undefined4 *)(this + 0x178) = 0;
  *(undefined4 *)(this + 0x17c) = 0;
  *(undefined4 *)(this + 0x18c) = 0;
  *(undefined4 *)(this + 0x184) = 0;
  *(float *)(this + 0x180) = fVar3;
  *(undefined4 *)(this + 0x35c) = 0x3f800000;
  *(undefined4 *)(this + 0x360) = 0x3f800000;
  pCVar5 = operator_new(0x2c);
  in_stack_00000018 = (CFuncKeysReal *)CONCAT31(in_stack_00000018._1_3_,0x21);
  if (pCVar5 == (CFuncKeysReal *)0x0) {
    this_00 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar5,pCVar8);
    this_00 = extraout_EAX;
  }
  in_stack_0000001c = (CMwNod *)CONCAT31(in_stack_0000001c._1_3_,0x20);
  if (this_00 != *(CMwNod **)(this + 0x34)) {
    if (this_00 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this_00,pCVar12);
    }
    if (*(CMwNod **)(this + 0x34) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x34),pCVar12);
    }
    *(CMwNod **)(this + 0x34) = this_00;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x34),_DAT_00b36184,(float)_DAT_00b32e98,(float)pCVar12);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x34),(CFuncKeysReal *)0x0,(float)_DAT_00b32e98,fVar13);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x34),_DAT_00b36adc,1.0,fVar10);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x34),_DAT_00b36ad4,0.0,(float)param_1);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x34),_DAT_00b2f708,0.0,in_stack_00000008)
  ;
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x34),_DAT_00b36ad0,0.0,(float)pCVar5);
  pCVar5 = operator_new(0x2c);
  in_stack_00000034 = (CMwNod *)CONCAT31(in_stack_00000034._1_3_,0x22);
  if (pCVar5 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar5,in_stack_00000010);
    pCVar12 = extraout_EAX_00;
  }
  if (pCVar12 != *(CMwNod **)(this + 0xb8)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,in_stack_00000014);
    }
    if (*(CMwNod **)(this + 0xb8) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0xb8),in_stack_00000014);
    }
    *(CMwNod **)(this + 0xb8) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0xb8),(CFuncKeysReal *)0x0,0.0,(float)in_stack_00000014);
  pCVar6 = operator_new(0x2c);
  in_stack_0000003c = (CMwNod *)CONCAT31(in_stack_0000003c._1_3_,0x23);
  if (pCVar6 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar6,in_stack_00000018);
    pCVar12 = extraout_EAX_01;
  }
  if (pCVar12 != *(CMwNod **)(this + 0xac)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,in_stack_0000001c);
    }
    if (*(CMwNod **)(this + 0xac) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0xac),in_stack_0000001c);
    }
    *(CMwNod **)(this + 0xac) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0xac),(CFuncKeysReal *)0x0,(float)_DAT_00b36198,
             (float)in_stack_0000001c);
  pCVar7 = operator_new(0x2c);
  in_stack_00000044 = (CMwNod *)CONCAT31(in_stack_00000044._1_3_,0x24);
  if (pCVar7 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar7,in_stack_00000020);
    pCVar12 = extraout_EAX_02;
  }
  if (pCVar12 != *(CMwNod **)(this + 0x68)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,in_stack_00000024);
    }
    if (*(CMwNod **)(this + 0x68) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x68),in_stack_00000024);
    }
    *(CMwNod **)(this + 0x68) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x68),(CFuncKeysReal *)0x0,_DAT_00b313ac,
             (float)in_stack_00000024);
  pCVar8 = operator_new(0x2c);
  in_stack_0000004c = (CMwNod *)CONCAT31(in_stack_0000004c._1_3_,0x25);
  if (pCVar8 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar8,pCVar5);
    pCVar12 = extraout_EAX_03;
  }
  if (pCVar12 != *(CMwNod **)(this + 0x78)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,in_stack_0000002c);
    }
    if (*(CMwNod **)(this + 0x78) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x78),in_stack_0000002c);
    }
    *(CMwNod **)(this + 0x78) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x78),(CFuncKeysReal *)0x0,0.0,(float)in_stack_0000002c);
  pCVar5 = operator_new(0x2c);
  in_stack_00000054 = (CFuncKeysReal *)CONCAT31(in_stack_00000054._1_3_,0x26);
  if (pCVar5 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar5,pCVar6);
    pCVar12 = extraout_EAX_04;
  }
  if (pCVar12 != *(CMwNod **)(this + 0xbc)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,in_stack_00000034);
    }
    if (*(CMwNod **)(this + 0xbc) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0xbc),in_stack_00000034);
    }
    *(CMwNod **)(this + 0xbc) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0xbc),(CFuncKeysReal *)0x0,1.0,(float)in_stack_00000034);
  pCVar6 = operator_new(0x2c);
  in_stack_0000005c = (float)CONCAT31(in_stack_0000005c._1_3_,0x27);
  if (pCVar6 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar6,pCVar7);
    pCVar12 = extraout_EAX_05;
  }
  if (pCVar12 != *(CMwNod **)(this + 0xa0)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,in_stack_0000003c);
    }
    if (*(CMwNod **)(this + 0xa0) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0xa0),in_stack_0000003c);
    }
    *(CMwNod **)(this + 0xa0) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0xa0),(CFuncKeysReal *)0x0,(float)_DAT_00b36194,
             (float)in_stack_0000003c);
  pCVar7 = operator_new(0x2c);
  in_stack_00000064 = (CMwNod *)CONCAT31(in_stack_00000064._1_3_,0x28);
  if (pCVar7 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar7,pCVar8);
    pCVar12 = extraout_EAX_06;
  }
  in_stack_00000068 = (CFuncKeysReal *)CONCAT31(in_stack_00000068._1_3_,0x20);
  if (pCVar12 != *(CMwNod **)(this + 0x36c)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,in_stack_00000044);
    }
    if (*(CMwNod **)(this + 0x36c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x36c),in_stack_00000044);
    }
    *(CMwNod **)(this + 0x36c) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x36c),(CFuncKeysReal *)0x0,1.0,(float)in_stack_00000044);
  *(undefined4 *)(this + 0x37c) = 0x3f800000;
  *(undefined4 *)(this + 0x388) = 0x3f800000;
  *(undefined4 *)(this + 0x394) = 0x3f800000;
  *(undefined4 *)(this + 0x38c) = 0x3f800000;
  *(undefined4 *)(this + 0x390) = 0x3f800000;
  pCVar8 = _DAT_00b36160;
  *(CFuncKeysReal **)(this + 0x398) = _DAT_00b36160;
  pCVar4 = _DAT_00b3618c;
  *(CFuncKeysReal **)(this + 0x39c) = _DAT_00b3618c;
  *(CFuncKeysReal **)(this + 0x28) = pCVar8;
  *(CFuncKeysReal **)(this + 0x3a0) = pCVar4;
  pCVar8 = operator_new(0x2c);
  if (pCVar8 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar8,pCVar5);
    pCVar12 = extraout_EAX_07;
  }
  in_stack_00000070 = (CFuncKeysReal *)CONCAT31(in_stack_00000070._1_3_,0x20);
  if (pCVar12 != *(CMwNod **)(this + 0x380)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,in_stack_0000004c);
    }
    if (*(CMwNod **)(this + 0x380) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x380),in_stack_0000004c);
    }
    *(CMwNod **)(this + 0x380) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x380),(CFuncKeysReal *)0x0,0.0,(float)in_stack_0000004c);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x380),_DAT_00b36160,1.0,(float)pCVar6);
  *(undefined4 *)(this + 900) = _DAT_00b3616c;
  *(undefined4 *)(this + 0x3a4) = _DAT_00ba380c;
  *(float *)(this + 0x3a8) = _DAT_00b33a54;
  *(CFuncKeysReal **)(this + 0x14c) = _DAT_00b36adc;
  *(undefined4 *)(this + 0x150) = _DAT_00b3d270;
  *(undefined4 *)(this + 0x1a0) = 0x3f800000;
  *(undefined4 *)(this + 0x1a4) = 0;
  *(undefined4 *)(this + 0x1a8) = 0x3f800000;
  *(undefined4 *)(this + 0x1ac) = 0;
  *(undefined4 *)(this + 0x19c) = 0x3f800000;
  pCVar5 = operator_new(0x2c);
  if (pCVar5 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar5,in_stack_00000054);
    pCVar12 = extraout_EAX_08;
  }
  in_stack_0000007c = (float)CONCAT31(in_stack_0000007c._1_3_,0x20);
  if (pCVar12 != *(CMwNod **)(this + 0x1b4)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,(CMwNod *)pCVar7);
    }
    if (*(CMwNod **)(this + 0x1b4) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x1b4),(CMwNod *)pCVar7);
    }
    *(CMwNod **)(this + 0x1b4) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x1b4),(CFuncKeysReal *)0x0,(float)_DAT_00b36194,
             (float)pCVar7);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x1b4),_DAT_00b36adc,(float)_DAT_00b36160,in_stack_0000005c)
  ;
  *(undefined4 *)(this + 0x1b8) = 0x3f800000;
  pCVar6 = operator_new(0x2c);
  in_stack_00000084 = (CMwNod *)CONCAT31(in_stack_00000084._1_3_,0x2b);
  if (pCVar6 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar6,pCVar8);
    pCVar12 = extraout_EAX_09;
  }
  if (pCVar12 != *(CMwNod **)(this + 0x1c4)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,in_stack_00000064);
    }
    if (*(CMwNod **)(this + 0x1c4) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x1c4),in_stack_00000064);
    }
    *(CMwNod **)(this + 0x1c4) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x1c4),(CFuncKeysReal *)0x0,(float)_DAT_00b36adc,
             (float)in_stack_00000064);
  *(undefined4 *)(this + 0x1c8) = 0x3f800000;
  pCVar7 = operator_new(0x2c);
  in_stack_0000008c = (CMwNod *)CONCAT31(in_stack_0000008c._1_3_,0x2c);
  if (pCVar7 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar7,in_stack_00000068);
    pCVar12 = extraout_EAX_10;
  }
  in_stack_00000090 = (CFuncKeysReal *)CONCAT31(in_stack_00000090._1_3_,0x20);
  if (pCVar12 != *(CMwNod **)(this + 0x1bc)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,(CMwNod *)pCVar5);
    }
    if (*(CMwNod **)(this + 0x1bc) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x1bc),(CMwNod *)pCVar5);
    }
    *(CMwNod **)(this + 0x1bc) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x1bc),(CFuncKeysReal *)0x0,_DAT_00b313e0,(float)pCVar5);
  *(undefined4 *)(this + 0x1c0) = 0x3f800000;
  *(undefined4 *)(this + 0x1cc) = _DAT_00b83838;
  *(undefined4 *)(this + 0x1d0) = _DAT_00b36144;
  *(undefined4 *)(this + 0x1b0) = 0x3f800000;
  *(undefined4 *)(this + 0x1d4) = 0;
  uVar2 = _DAT_00b790e0;
  *(undefined4 *)(this + 0x1d8) = _DAT_00b790e0;
  *(undefined4 *)(this + 0x1dc) = uVar2;
  pCVar5 = operator_new(0x2c);
  in_stack_00000094 = (CMwNod *)CONCAT31(in_stack_00000094._1_3_,0x2d);
  if (pCVar5 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar5,in_stack_00000070);
    pCVar12 = extraout_EAX_11;
  }
  if (pCVar12 != *(CMwNod **)(this + 0x1e0)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,in_stack_00000074);
    }
    if (*(CMwNod **)(this + 0x1e0) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x1e0),in_stack_00000074);
    }
    *(CMwNod **)(this + 0x1e0) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x1e0),_DAT_00b36184,(float)_DAT_00b32e98,
             (float)in_stack_00000074);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x1e0),(CFuncKeysReal *)0x0,(float)_DAT_00b32e98,
             (float)pCVar6);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x1e0),_DAT_00b36adc,1.0,in_stack_0000007c);
  *(undefined4 *)(this + 0x1e4) = 0x3f800000;
  *(undefined4 *)(this + 0x1e8) = 500;
  pCVar6 = operator_new(0x2c);
  in_stack_000000a4 = (CMwNod *)CONCAT31(in_stack_000000a4._1_3_,0x2e);
  if (pCVar6 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar6,pCVar7);
    pCVar12 = extraout_EAX_12;
  }
  if (pCVar12 != *(CMwNod **)(this + 0x1ec)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,in_stack_00000084);
    }
    if (*(CMwNod **)(this + 0x1ec) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x1ec),in_stack_00000084);
    }
    *(CMwNod **)(this + 0x1ec) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x1ec),(CFuncKeysReal *)0x0,1.0,(float)in_stack_00000084);
  pCVar7 = operator_new(0x2c);
  in_stack_000000ac = (CFuncKeysReal *)CONCAT31(in_stack_000000ac._1_3_,0x2f);
  if (pCVar7 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar7,pCVar5);
    pCVar12 = extraout_EAX_13;
  }
  if (pCVar12 != *(CMwNod **)(this + 0x1f0)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,in_stack_0000008c);
    }
    if (*(CMwNod **)(this + 0x1f0) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x1f0),in_stack_0000008c);
    }
    *(CMwNod **)(this + 0x1f0) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x1f0),(CFuncKeysReal *)0x0,0.0,(float)in_stack_0000008c);
  *(CFuncKeysReal **)(this + 500) = _DAT_00b36160;
  *(undefined4 *)(this + 0x1f8) = 0;
  *(undefined4 *)(this + 0x1fc) = 1;
  *(undefined4 *)(this + 0x200) = 0x3f800000;
  *(undefined4 *)(this + 0x204) = 0x3f800000;
  *(undefined4 *)(this + 0x208) = _DAT_00ba3814;
  *(CFuncKeysReal **)(this + 0x20c) = _DAT_00b32e98;
  pCVar5 = operator_new(0x2c);
  in_stack_000000b4 = (float)CONCAT31(in_stack_000000b4._1_3_,0x30);
  if (pCVar5 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar5,in_stack_00000090);
    pCVar12 = extraout_EAX_14;
  }
  if (pCVar12 != *(CMwNod **)(this + 0x210)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,in_stack_00000094);
    }
    if (*(CMwNod **)(this + 0x210) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x210),in_stack_00000094);
    }
    *(CMwNod **)(this + 0x210) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x210),(CFuncKeysReal *)0x0,1.0,(float)in_stack_00000094);
  pCVar8 = operator_new(0x2c);
  in_stack_000000bc = (CFuncKeysReal *)CONCAT31(in_stack_000000bc._1_3_,0x31);
  if (pCVar8 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar8,pCVar6);
    pCVar12 = extraout_EAX_15;
  }
  in_stack_000000c0 = (CMwNod *)CONCAT31(in_stack_000000c0._1_3_,0x20);
  if (pCVar12 != *(CMwNod **)(this + 0x214)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,in_stack_0000009c);
    }
    if (*(CMwNod **)(this + 0x214) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x214),in_stack_0000009c);
    }
    *(CMwNod **)(this + 0x214) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x214),(CFuncKeysReal *)0x0,0.0,(float)in_stack_0000009c);
  pCVar6 = operator_new(0x2c);
  if (pCVar6 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar6,pCVar7);
    pCVar12 = extraout_EAX_16;
  }
  in_stack_000000c8 = (float)CONCAT31(in_stack_000000c8._1_3_,0x20);
  if (pCVar12 != *(CMwNod **)(this + 0x218)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,in_stack_000000a4);
    }
    if (*(CMwNod **)(this + 0x218) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x218),in_stack_000000a4);
    }
    *(CMwNod **)(this + 0x218) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x218),(CFuncKeysReal *)0x0,0.0,(float)in_stack_000000a4);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x218),_DAT_00b58724,(float)_DAT_00b58724,(float)pCVar5);
  *(undefined4 *)(this + 0x21c) = _DAT_00b3380c;
  *(float *)(this + 0x220) = _DAT_00b33a54;
  pCVar5 = operator_new(0x2c);
  in_stack_000000d0 = (CMwNod *)CONCAT31(in_stack_000000d0._1_3_,0x33);
  if (pCVar5 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar5,in_stack_000000ac);
    pCVar12 = extraout_EAX_17;
  }
  if (pCVar12 != *(CMwNod **)(this + 0x224)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,(CMwNod *)pCVar8);
    }
    if (*(CMwNod **)(this + 0x224) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x224),(CMwNod *)pCVar8);
    }
    *(CMwNod **)(this + 0x224) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x224),(CFuncKeysReal *)0x0,1.0,(float)pCVar8);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x224),_DAT_00b31460,_DAT_00b313ac,in_stack_000000b4);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x224),(CFuncKeysReal *)0x3f800000,DAT_00b36188,
             (float)pCVar6);
  *(CFuncKeysReal **)(this + 0x228) = _DAT_00b3618c;
  *(CFuncKeysReal **)(this + 0x22c) = _DAT_00b36ad4;
  pCVar6 = operator_new(0x2c);
  in_stack_000000e0 = (CMwNod *)CONCAT31(in_stack_000000e0._1_3_,0x34);
  if (pCVar6 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar6,in_stack_000000bc);
    pCVar12 = extraout_EAX_18;
  }
  if (pCVar12 != *(CMwNod **)(this + 0x230)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,in_stack_000000c0);
    }
    if (*(CMwNod **)(this + 0x230) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x230),in_stack_000000c0);
    }
    *(CMwNod **)(this + 0x230) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x230),_DAT_00b36184,_DAT_00b313ac,(float)in_stack_000000c0)
  ;
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x230),_DAT_00b3617c,(float)_DAT_00b3618c,(float)pCVar5);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x230),(CFuncKeysReal *)0x0,(float)_DAT_00b36194,
             in_stack_000000c8);
  *(undefined4 *)(this + 0x234) = _DAT_00b41d80;
  uVar2 = _DAT_00b3380c;
  *(undefined4 *)(this + 0x238) = _DAT_00b3380c;
  *(undefined4 *)(this + 0x23c) = uVar2;
  *(CFuncKeysReal **)(this + 0x254) = _DAT_00b36194;
  pCVar5 = operator_new(0x2c);
  in_stack_000000f0 = (CMwNod *)CONCAT31(in_stack_000000f0._1_3_,0x35);
  if (pCVar5 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar5,in_stack_000000cc);
    pCVar12 = extraout_EAX_19;
  }
  if (pCVar12 != *(CMwNod **)(this + 0x25c)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,in_stack_000000d0);
    }
    if (*(CMwNod **)(this + 0x25c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x25c),in_stack_000000d0);
    }
    *(CMwNod **)(this + 0x25c) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x25c),(CFuncKeysReal *)0x0,1.0,(float)in_stack_000000d0);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x25c),_DAT_00b3618c,_DAT_00b313ac,(float)pCVar6);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x25c),_DAT_00b36194,DAT_00b36188,in_stack_000000d8);
  pCVar6 = operator_new(0x2c);
  in_stack_00000100 = (CMwNod *)CONCAT31(in_stack_00000100._1_3_,0x36);
  if (pCVar6 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar6,in_stack_000000dc);
    pCVar12 = extraout_EAX_20;
  }
  if (pCVar12 != *(CMwNod **)(this + 0x260)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,in_stack_000000e0);
    }
    if (*(CMwNod **)(this + 0x260) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x260),in_stack_000000e0);
    }
    *(CMwNod **)(this + 0x260) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x260),(CFuncKeysReal *)0x0,0.0,(float)in_stack_000000e0);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x260),(CFuncKeysReal *)0x3f800000,(float)_DAT_00b36198,
             (float)pCVar5);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x260),_DAT_00b36194,(float)_DAT_00b36198,in_stack_000000e8)
  ;
  *(undefined4 *)(this + 0x264) = 0x3f800000;
  *(float *)(this + 600) = DAT_00b36188;
  *(float *)(this + 0x268) = _DAT_00b3d620;
  *(undefined4 *)(this + 0x278) = 0x3f800000;
  fVar3 = _DAT_00b33a54;
  *(float *)(this + 0x27c) = _DAT_00b33a54;
  *(CFuncKeysReal **)(this + 0x280) = _DAT_00b36160;
  *(CFuncKeysReal **)(this + 0x284) = _DAT_00b36194;
  *(float *)(this + 0x26c) = _DAT_00b313ac;
  pCVar5 = _DAT_00b31460;
  *(CFuncKeysReal **)(this + 0x270) = _DAT_00b31460;
  *(CFuncKeysReal **)(this + 0x274) = pCVar5;
  *(CFuncKeysReal **)(this + 0x240) = pCVar5;
  *(undefined4 *)(this + 0x298) = 1000;
  *(undefined4 *)(this + 0x2a8) = 500;
  *(CFuncKeysReal **)(this + 0x29c) = pCVar5;
  *(undefined4 *)(this + 0x2a0) = _DAT_00b41d80;
  *(undefined4 *)(this + 0x2ac) = _DAT_00b313a8;
  *(float *)(this + 0x244) = fVar3;
  *(undefined4 *)(this + 0x2c0) = 0x3f800000;
  *(undefined4 *)(this + 0x2b4) = 0x3f800000;
  *(CFuncKeysReal **)(this + 0x2b0) = _DAT_00b3618c;
  pCVar5 = operator_new(0x2c);
  in_stack_00000110 = CONCAT31(in_stack_00000110._1_3_,0x37);
  if (pCVar5 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar5,in_stack_000000ec);
    pCVar12 = extraout_EAX_21;
  }
  if (pCVar12 != *(CMwNod **)(this + 0x2a4)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,in_stack_000000f0);
    }
    if (*(CMwNod **)(this + 0x2a4) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x2a4),in_stack_000000f0);
    }
    *(CMwNod **)(this + 0x2a4) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x2a4),(CFuncKeysReal *)0x0,_DAT_00b32ea8,
             (float)in_stack_000000f0);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x2a4),_DAT_00b36194,_DAT_00b36180,(float)pCVar6);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x2a4),_DAT_00b32e98,_DAT_00b33a54,in_stack_000000f8);
  pCVar6 = operator_new(0x2c);
  in_stack_00000120 = CONCAT31(in_stack_00000120._1_3_,0x38);
  if (pCVar6 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar6,in_stack_000000fc);
    pCVar12 = extraout_EAX_22;
  }
  in_stack_00000124 = CONCAT31(in_stack_00000124._1_3_,0x20);
  if (pCVar12 != *(CMwNod **)(this + 0x288)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,in_stack_00000100);
    }
    if (*(CMwNod **)(this + 0x288) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x288),in_stack_00000100);
    }
    *(CMwNod **)(this + 0x288) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x288),(CFuncKeysReal *)0x0,0.0,(float)in_stack_00000100);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x288),_DAT_00b36194,(float)_DAT_00b3618c,(float)pCVar5);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x288),_DAT_00b36160,_DAT_00b3d620,in_stack_00000108);
  pCVar11 = this + 0x2c4;
  *(undefined4 *)(this + 0x28c) = _DAT_00b36140;
  *(undefined4 *)(this + 700) = _DAT_00b2f720;
  *(undefined4 *)(this + 0x290) = _DAT_00ba3808;
  *(undefined4 *)(this + 0x294) = _DAT_00ba3804;
  *(CFuncKeysReal **)(this + 0x2b8) = _DAT_00b36194;
  *(float *)(this + 0x2d0) = _DAT_00b41140;
  CFastBuffer<float>::AllocSetCount
            (pCVar11,(CFastBuffer<class_GxVertex2> *)&DAT_00000006,in_stack_0000010c);
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      in_stack_00000110);
  *(undefined4 *)pSVar9 = _DAT_00b313a8;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,(ulong)pCVar6);
  *(float *)pSVar9 = _DAT_00b313ac;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                      in_stack_00000118);
  *(undefined4 *)pSVar9 = 0x3f800000;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                      in_stack_0000011c);
  *(float *)pSVar9 = _DAT_00b41140;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000004,
                      in_stack_00000120);
  *(CFuncKeysReal **)pSVar9 = _DAT_00b31460;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar11,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000005,
                      in_stack_00000124);
  *(undefined4 *)pSVar9 = _DAT_00b36144;
  pCVar5 = operator_new(0x2c);
  in_stack_0000014c = CONCAT31(in_stack_0000014c._1_3_,0x39);
  if (pCVar5 == (CFuncKeysReal *)0x0) {
    pCVar12 = (CMwNod *)0x0;
  }
  else {
    CFuncKeysReal::CFuncKeysReal(pCVar5,in_stack_00000128);
    pCVar12 = extraout_EAX_23;
  }
  in_stack_00000150 = CONCAT31(in_stack_00000150._1_3_,0x20);
  if (pCVar12 != *(CMwNod **)(this + 0x250)) {
    if (pCVar12 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar12,in_stack_0000012c);
    }
    if (*(CMwNod **)(this + 0x250) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x250),in_stack_0000012c);
    }
    *(CMwNod **)(this + 0x250) = pCVar12;
  }
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x250),(CFuncKeysReal *)0x0,0.0,(float)in_stack_0000012c);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x250),(CFuncKeysReal *)0x3f800000,_DAT_00b41140,
             in_stack_00000130);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x250),_DAT_00b36194,1.0,in_stack_00000134);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x250),_DAT_00b36160,1.0,in_stack_00000138);
  CFuncKeysReal::InsertKeyReal
            (*(CFuncKeysReal **)(this + 0x250),_DAT_00b36198,1.0,in_stack_0000013c);
  CFastBuffer<float>::AllocSetCount
            (pCVar1,(CFastBuffer<class_GxVertex2> *)&DAT_00000006,(ulong)pCVar5);
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,in_stack_00000144
                     );
  *(undefined4 *)pSVar9 = 0;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,in_stack_00000148
                     );
  *(undefined4 *)pSVar9 = _DAT_00ba3800;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,in_stack_0000014c
                     );
  *(undefined4 *)pSVar9 = _DAT_00ba3800;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,in_stack_00000150
                     );
  *(undefined4 *)pSVar9 = _DAT_00ba3800;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000004,
                      in_stack_00000154);
  *(undefined4 *)pSVar9 = _DAT_00ba3800;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000005,
                      in_stack_00000158);
  pCVar1 = this + 0x2e0;
  *(undefined4 *)pSVar9 = 0x3f800000;
  CFastBuffer<float>::AllocSetCount
            (pCVar1,(CFastBuffer<class_GxVertex2> *)&DAT_00000006,in_stack_0000015c);
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,in_stack_00000160
                     );
  *(undefined4 *)pSVar9 = 0;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,in_stack_00000164
                     );
  *(undefined4 *)pSVar9 = 0;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,in_stack_00000168
                     );
  *(undefined4 *)pSVar9 = _DAT_00ba37fc;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,in_stack_0000016c
                     );
  *(undefined4 *)pSVar9 = _DAT_00ba37f8;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000004,
                      in_stack_00000170);
  *(undefined4 *)pSVar9 = _DAT_00ba37f4;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000005,
                      in_stack_00000174);
  *(undefined4 *)pSVar9 = _DAT_00ba37f0;
  uVar2 = _DAT_00b2f704;
  pCVar1 = this + 0x2f8;
  *(undefined4 *)(this + 0x2ec) = _DAT_00b2f704;
  *(undefined4 *)(this + 0x2f0) = uVar2;
  *(undefined4 *)(this + 0x2f4) = _DAT_00ba0000;
  CFastBuffer<float>::AllocSetCount
            (pCVar1,(CFastBuffer<class_GxVertex2> *)&DAT_00000006,in_stack_00000178);
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,in_stack_0000017c
                     );
  *(undefined4 *)pSVar9 = 0;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,in_stack_00000180
                     );
  *(undefined4 *)pSVar9 = 0;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,in_stack_00000184
                     );
  *(undefined4 *)pSVar9 = _DAT_00ba37ec;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,in_stack_00000188
                     );
  *(undefined4 *)pSVar9 = _DAT_00b5b9f8;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000004,
                      in_stack_0000018c);
  *(undefined4 *)pSVar9 = DAT_00b3d2a0;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000005,
                      in_stack_00000190);
  pCVar1 = this + 0x304;
  *(undefined4 *)pSVar9 = _DAT_00ba37e8;
  CFastBuffer<float>::AllocSetCount
            (pCVar1,(CFastBuffer<class_GxVertex2> *)&DAT_00000006,in_stack_00000194);
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,in_stack_00000198
                     );
  *(undefined4 *)pSVar9 = 0;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,in_stack_0000019c
                     );
  *(undefined4 *)pSVar9 = 0;
  *(undefined4 *)(this + 0x31c) = _DAT_00b2f704;
  uVar2 = _DAT_00b3d270;
  *(undefined4 *)(this + 800) = _DAT_00b3d270;
  *(undefined4 *)(this + 0x324) = uVar2;
  *(undefined4 *)(this + 0x328) = _DAT_00ba37e4;
  pCVar1 = this + 0x310;
  CFastBuffer<float>::AllocSetCount
            (pCVar1,(CFastBuffer<class_GxVertex2> *)&DAT_00000006,in_stack_000001a0);
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,in_stack_000001a4
                     );
  *(undefined4 *)pSVar9 = 0;
  pSVar9 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000005,
                      in_stack_000001a8);
  *(undefined4 *)pSVar9 = 0;
  *(float *)(this + 0x32c) = DAT_00b36188;
  fVar3 = _DAT_00b313ac;
  *(float *)(this + 0x334) = _DAT_00b313ac;
  *(undefined4 *)(this + 0x338) = _DAT_00b436fc;
  *(undefined4 *)(this + 0x330) = _DAT_00b362b0;
  *(CFuncKeysReal **)(this + 0x248) = _DAT_00b36adc;
  *(CFuncKeysReal **)(this + 0x24c) = _DAT_00b32e98;
  *(undefined4 *)(this + 0x33c) = _DAT_00b3cd40;
  *(CFuncKeysReal **)(this + 0x340) = _DAT_00b36160;
  *(undefined4 *)(this + 0x344) = _DAT_00b5a4cc;
  *(undefined4 *)(this + 0x348) = 0x3f800000;
  *(float *)(this + 0x34c) = fVar3;
  ExceptionList = in_stack_000001c8;
  return;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::Chunk
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicleCarTuning::Chunk
          (CSceneVehicleCarTuning *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3
          )
{
{
  float fVar1;
  CFuncSegment *this_00;
  CClassicArchive *pCVar2;
  CFuncKeysReal *this_01;
  CMwNodRef<class_CGameCamera> *extraout_EAX;
  CMwNodRef<class_CGameCamera> *extraout_EAX_00;
  CMwNodRef<class_CGameCamera> *extraout_EAX_01;
  CMwNodRef<class_CGameCamera> *extraout_EAX_02;
  CMwNodRef<class_CGameCamera> *pCVar3;
  CFuncKeysReal *unaff_EBX;
  CClassicArchive *unaff_ESI;
  CClassicArchive *pCVar4;
  CFuncKeysReal *unaff_EDI;
  void *unaff_retaddr;
  undefined1 *puVar5;
  CClassicArchive *in_stack_00000010;
  CClassicArchive *in_stack_00000014;
  CClassicArchive *in_stack_00000018;
  CClassicArchive *in_stack_0000001c;
  CClassicArchive *in_stack_00000020;
  CClassicArchive *in_stack_00000024;
  CClassicArchive *in_stack_00000028;
  CClassicArchive *in_stack_0000002c;
  CClassicArchive *in_stack_00000030;
  CClassicArchive *in_stack_00000034;
  CFuncSegment *in_stack_00000038;
  CClassicArchive *in_stack_0000003c;
  CClassicArchive *in_stack_00000040;
  CClassicArchive *in_stack_00000044;
  CClassicArchive *in_stack_00000048;
  int in_stack_0000004c;
  void *in_stack_00000078;
  CGameCamera *in_stack_ffffffb8;
  float in_stack_ffffffbc;
  CGameCamera *pCVar6;
  CSceneVehicleCarTuning *pCVar7;
  ulong uVar8;
  ulong uVar9;
  CClassicArchive *pCVar10;
  CGameCamera *in_stack_ffffffdc;
  CMwNodRef<class_CMwRefBuffer> *in_stack_ffffffe0;
  ulong in_stack_ffffffe4;
  ulong in_stack_ffffffe8;
  ulong in_stack_ffffffec;
  ulong in_stack_fffffff0;
  void *pvVar11;
  CClassicArchive *pCVar12;
  void *pvVar13;
  
  this_00 = param_1;
  pvVar13 = (void *)0xffffffff;
  pCVar12 = (CClassicArchive *)&LAB_00ad010c;
  pCVar2 = (CClassicArchive *)(DAT_00cca150 ^ (uint)&stack0xffffffd0);
  if ((CClassicArchive *)0xa029035 < param_2) {
    if ((CClassicArchive *)0xa029050 < param_2) {
      if ((CClassicArchive *)0xa02905e < param_2) {
        if (param_2 < (CClassicArchive *)0xa029066) {
          if (param_2 == (CClassicArchive *)0xa029065) {
            pCVar4 = (CClassicArchive *)(this + 0x348);
          }
          else {
            switch(param_2) {
            case (CClassicArchive *)0xa02905f:
              pCVar4 = (CClassicArchive *)(this + 0x220);
              break;
            case (CClassicArchive *)0xa029060:
              ExceptionList = &stack0xfffffff4;
              CClassicArchive::DoReal
                        ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x30),(float *)0x1,
                         (ulong)pCVar2);
              CClassicArchive::DoReal
                        ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0xf0),(float *)0x1,
                         (ulong)unaff_EDI);
              CClassicArchive::DoReal
                        ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0xf4),(float *)0x1,
                         (ulong)unaff_ESI);
              CClassicArchive::DoNatural
                        ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0xf8),(ulong *)0x1,0,
                         (int)unaff_EBX);
              CClassicArchive::DoNatural
                        ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0xfc),(ulong *)0x1,0,
                         (int)in_stack_ffffffdc);
              ExceptionList = param_2;
              return;
            case (CClassicArchive *)0xa029061:
              ExceptionList = &stack0xfffffff4;
              CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                        ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x378),
                         (CMwNodRef<class_CMwRefBuffer> *)pCVar2);
              ExceptionList = pCVar12;
              return;
            case (CClassicArchive *)0xa029062:
              pCVar4 = (CClassicArchive *)(this + 0x33c);
              break;
            case (CClassicArchive *)0xa029063:
              pCVar4 = (CClassicArchive *)(this + 0x340);
              break;
            case (CClassicArchive *)0xa029064:
              pCVar4 = (CClassicArchive *)(this + 0x344);
              break;
            default:
              goto switchD_007f5efc_default;
            }
          }
        }
        else if (param_2 < (CClassicArchive *)0xa029069) {
          if (param_2 == (CClassicArchive *)0xa029068) goto switchD_007f5efc_caseD_a029021;
          if (param_2 == (CClassicArchive *)0xa029066) {
            pCVar4 = (CClassicArchive *)(this + 0x34c);
          }
          else {
            if (param_2 != (CClassicArchive *)0xa029067) goto switchD_007f5efc_default;
            pCVar4 = (CClassicArchive *)&param_1;
          }
        }
        else {
          if (param_2 != (CClassicArchive *)0xa029069) {
            if (param_2 == (CClassicArchive *)0xffffffff) {
              ExceptionList = pCVar12;
              return;
            }
            goto switchD_007f5efc_default;
          }
          pCVar4 = (CClassicArchive *)&stack0xffffffe4;
        }
        goto LAB_007f7895;
      }
      if (param_2 == (CClassicArchive *)0xa02905e) {
        ExceptionList = &stack0xfffffff4;
        CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                  ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x36c),
                   (CMwNodRef<class_CMwRefBuffer> *)pCVar2);
        ExceptionList = pCVar12;
        return;
      }
      switch(param_2) {
      case (CClassicArchive *)0xa029051:
        pCVar4 = (CClassicArchive *)(this + 0x2a0);
        goto LAB_007f7895;
      case (CClassicArchive *)0xa029052:
        ExceptionList = &stack0xfffffff4;
        CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                  ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x250),
                   (CMwNodRef<class_CMwRefBuffer> *)pCVar2);
        ExceptionList = pCVar12;
        return;
      case (CClassicArchive *)0xa029053:
        pCVar4 = (CClassicArchive *)(this + 0x27c);
        goto LAB_007f7895;
      case (CClassicArchive *)0xa029054:
        ExceptionList = &stack0xfffffff4;
        CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                  (&stack0xffffffe8,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar2);
        pCVar2 = param_2;
        puVar5 = &DAT_00000004;
        CFastBuffer<float>::ArchiveCountAndElems
                  (this + 0x2d4,(CFastArray<struct_SOldLetter> *)param_2,
                   (CClassicArchive *)unaff_EDI);
        pCVar12 = (CClassicArchive *)0x7f7391;
        CFastBuffer<float>::ArchiveCountAndElems
                  (this + 0x2e0,(CFastArray<struct_SOldLetter> *)pCVar2,unaff_ESI);
        unaff_EDI = (CFuncKeysReal *)0x7f739b;
        CFastBuffer<float>::ArchiveCountAndElems
                  (&stack0xfffffff4,(CFastArray<struct_SOldLetter> *)pCVar2,
                   (CClassicArchive *)unaff_EBX);
        goto LAB_007f739c;
      case (CClassicArchive *)0xa029055:
        ExceptionList = &stack0xfffffff4;
        CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                  (&stack0xffffffe8,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar2);
        puVar5 = &DAT_00000005;
        pCVar12 = param_2;
        pCVar2 = unaff_ESI;
LAB_007f739c:
        CFastBuffer<float>::ArchiveCountAndElems
                  (&stack0xffffffec,(CFastArray<struct_SOldLetter> *)pCVar12,
                   (CClassicArchive *)unaff_EDI);
        CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                  (&stack0xfffffff0,(CFastBuffer<class_CPlugFileGPUV*> *)pCVar2);
        ExceptionList = puVar5;
        return;
      case (CClassicArchive *)0xa029056:
        ExceptionList = &stack0xfffffff4;
        CClassicArchive::DoReal
                  ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x2ec),(float *)0x1,
                   (ulong)pCVar2);
        pCVar10 = (CClassicArchive *)(this + 0x2f0);
        pCVar4 = (CClassicArchive *)0x7f73ff;
        CClassicArchive::DoReal((CClassicArchive *)this_00,pCVar10,(float *)0x1,(ulong)unaff_EDI);
        pCVar2 = (CClassicArchive *)(this + 0x2f4);
        break;
      case (CClassicArchive *)0xa029057:
        ExceptionList = &stack0xfffffff4;
        CFastBuffer<float>::ArchiveCountAndElems
                  (this + 0x2f8,(CFastArray<struct_SOldLetter> *)param_1,pCVar2);
        ExceptionList = pCVar12;
        return;
      case (CClassicArchive *)0xa029058:
        pCVar4 = (CClassicArchive *)(this + 0x31c);
        goto LAB_007f7895;
      case (CClassicArchive *)0xa029059:
        ExceptionList = &stack0xfffffff4;
        CClassicArchive::DoReal
                  ((CClassicArchive *)param_1,(CClassicArchive *)(this + 800),(float *)0x1,
                   (ulong)pCVar2);
        pCVar4 = (CClassicArchive *)0x7f7466;
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x32c),(float *)0x1,
                   (ulong)unaff_EDI);
        pCVar2 = (CClassicArchive *)(this + 0x324);
        pCVar10 = (CClassicArchive *)0x7f7476;
        CClassicArchive::DoReal((CClassicArchive *)this_00,pCVar2,(float *)0x1,(ulong)unaff_ESI);
        break;
      case (CClassicArchive *)0xa02905a:
        ExceptionList = &stack0xfffffff4;
        CClassicArchive::DoReal
                  ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x334),(float *)0x1,
                   (ulong)pCVar2);
        pCVar10 = (CClassicArchive *)(this + 0x330);
        pCVar4 = (CClassicArchive *)0x7f74aa;
        CClassicArchive::DoReal((CClassicArchive *)this_00,pCVar10,(float *)0x1,(ulong)unaff_EDI);
        pCVar2 = (CClassicArchive *)(this + 0x338);
        break;
      case (CClassicArchive *)0xa02905b:
        pCVar4 = (CClassicArchive *)0x7f74cc;
        ExceptionList = &stack0xfffffff4;
        CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                  ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x380),
                   (CMwNodRef<class_CMwRefBuffer> *)pCVar2);
        pCVar10 = (CClassicArchive *)(this + 900);
        pCVar2 = (CClassicArchive *)0x1;
        break;
      case (CClassicArchive *)0xa02905c:
        pCVar4 = (CClassicArchive *)(this + 0x248);
        ExceptionList = &stack0xfffffff4;
        CClassicArchive::DoReal((CClassicArchive *)param_1,pCVar4,(float *)0x1,(ulong)pCVar2);
        pCVar10 = (CClassicArchive *)(this + 0x24c);
        pCVar2 = (CClassicArchive *)0x1;
        break;
      case (CClassicArchive *)0xa02905d:
        pvVar11 = ExceptionList;
        ExceptionList = &stack0xfffffff4;
        CClassicArchive::DoReal
                  ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x228),(float *)0x1,
                   (ulong)pCVar2);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x22c),(float *)0x1,
                   (ulong)unaff_EDI);
        CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x230),
                   (CMwNodRef<class_CMwRefBuffer> *)unaff_ESI);
        CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x260),
                   (CMwNodRef<class_CMwRefBuffer> *)unaff_EBX);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x264),(float *)0x1,
                   (ulong)in_stack_ffffffdc);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 600),(float *)0x1,
                   (ulong)in_stack_ffffffe0);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x268),(float *)0x1,
                   in_stack_ffffffe4);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x278),(float *)0x1,
                   in_stack_ffffffe8);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x280),(float *)0x1,
                   in_stack_ffffffec);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x284),(float *)0x1,
                   in_stack_fffffff0);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x26c),(float *)0x1,
                   (ulong)pvVar11);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x270),(float *)0x1,
                   (ulong)pCVar12);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x240),(float *)0x1,
                   (ulong)pvVar13);
        CClassicArchive::DoNatural
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x298),(ulong *)0x1,0,
                   (int)unaff_retaddr);
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x29c),(float *)0x1,
                   (ulong)param_1);
        param_1 = (CFuncSegment *)0x1;
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x2ac),(float *)0x1,
                   (ulong)param_2);
        param_2 = (CClassicArchive *)0x0;
        param_1 = (CFuncSegment *)0x1;
        CClassicArchive::DoNatural
                  ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x2a8),(ulong *)0x1,0,
                   param_3);
        param_3 = 1;
        param_2 = (CClassicArchive *)(this + 0x244);
        param_1 = (CFuncSegment *)0x7f7624;
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,param_2,(float *)0x1,(ulong)in_stack_00000010);
        in_stack_00000010 = (CClassicArchive *)0x1;
        param_3 = (ulong)(this + 0x2c0);
        param_2 = (CClassicArchive *)0x7f7634;
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,(CClassicArchive *)param_3,(float *)0x1,
                   (ulong)in_stack_00000014);
        in_stack_00000014 = (CClassicArchive *)0x1;
        in_stack_00000010 = (CClassicArchive *)(this + 0x2b4);
        param_3 = 0x7f7644;
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,in_stack_00000010,(float *)0x1,
                   (ulong)in_stack_00000018);
        in_stack_00000018 = (CClassicArchive *)0x1;
        in_stack_00000014 = (CClassicArchive *)(this + 0x2b0);
        in_stack_00000010 = (CClassicArchive *)0x7f7654;
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,in_stack_00000014,(float *)0x1,
                   (ulong)in_stack_0000001c);
        in_stack_0000001c = (CClassicArchive *)(this + 0x2a4);
        in_stack_00000018 = (CClassicArchive *)0x7f7662;
        CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                  ((CClassicArchive *)this_00,in_stack_0000001c,
                   (CMwNodRef<class_CMwRefBuffer> *)in_stack_00000020);
        in_stack_00000020 = (CClassicArchive *)(this + 0x288);
        in_stack_0000001c = (CClassicArchive *)0x7f7670;
        CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                  ((CClassicArchive *)this_00,in_stack_00000020,
                   (CMwNodRef<class_CMwRefBuffer> *)in_stack_00000024);
        in_stack_00000024 = (CClassicArchive *)0x1;
        in_stack_00000020 = (CClassicArchive *)(this + 0x28c);
        in_stack_0000001c = (CClassicArchive *)0x7f7680;
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,in_stack_00000020,(float *)0x1,
                   (ulong)in_stack_00000028);
        in_stack_00000028 = (CClassicArchive *)0x1;
        in_stack_00000024 = (CClassicArchive *)(this + 700);
        in_stack_00000020 = (CClassicArchive *)0x7f7690;
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,in_stack_00000024,(float *)0x1,
                   (ulong)in_stack_0000002c);
        in_stack_0000002c = (CClassicArchive *)0x1;
        in_stack_00000028 = (CClassicArchive *)(this + 0x290);
        in_stack_00000024 = (CClassicArchive *)0x7f76a0;
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,in_stack_00000028,(float *)0x1,
                   (ulong)in_stack_00000030);
        in_stack_00000030 = (CClassicArchive *)0x1;
        in_stack_0000002c = (CClassicArchive *)(this + 0x294);
        in_stack_00000028 = (CClassicArchive *)0x7f76b0;
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,in_stack_0000002c,(float *)0x1,
                   (ulong)in_stack_00000034);
        in_stack_00000034 = (CClassicArchive *)0x1;
        in_stack_00000030 = (CClassicArchive *)(this + 0x2b8);
        in_stack_0000002c = (CClassicArchive *)0x7f76c0;
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,in_stack_00000030,(float *)0x1,
                   (ulong)in_stack_00000038);
        in_stack_00000038 = (CFuncSegment *)0x1;
        in_stack_00000034 = (CClassicArchive *)(this + 0x2d0);
        in_stack_00000030 = (CClassicArchive *)0x7f76d0;
        CClassicArchive::DoReal
                  ((CClassicArchive *)this_00,in_stack_00000034,(float *)0x1,
                   (ulong)in_stack_0000003c);
        in_stack_0000003c = (CClassicArchive *)this_00;
        in_stack_00000038 = (CFuncSegment *)0x7f76dc;
        CFastBuffer<float>::ArchiveCountAndElems
                  (this + 0x2c4,(CFastArray<struct_SOldLetter> *)this_00,in_stack_00000040);
        in_stack_00000040 = (CClassicArchive *)this_00;
        in_stack_0000003c = (CClassicArchive *)0x7f76e8;
        CFastBuffer<float>::ArchiveCountAndElems
                  (this + 0x2d4,(CFastArray<struct_SOldLetter> *)this_00,in_stack_00000044);
        in_stack_00000044 = (CClassicArchive *)this_00;
        in_stack_00000040 = (CClassicArchive *)0x7f76f4;
        CFastBuffer<float>::ArchiveCountAndElems
                  (this + 0x2e0,(CFastArray<struct_SOldLetter> *)this_00,in_stack_00000048);
        in_stack_00000048 = (CClassicArchive *)0x0;
        in_stack_00000044 = (CClassicArchive *)0x1;
        in_stack_00000040 = (CClassicArchive *)(this + 0x90);
        in_stack_0000003c = (CClassicArchive *)0x7f7706;
        CClassicArchive::DoNatural
                  ((CClassicArchive *)this_00,in_stack_00000040,(ulong *)0x1,0,in_stack_0000004c);
        ExceptionList = in_stack_00000078;
        return;
      default:
        goto switchD_007f5efc_default;
      }
      goto LAB_007f7899;
    }
    if (param_2 == (CClassicArchive *)0xa029050) {
      param_2 = (CClassicArchive *)0x0;
      pvVar11 = ExceptionList;
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x260),
                 (CMwNodRef<class_CMwRefBuffer> *)pCVar2);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x264),(float *)0x1,
                 (ulong)unaff_EDI);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 600),(float *)0x1,
                 (ulong)unaff_ESI);
      pCVar2 = (CClassicArchive *)0x7f7158;
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x268),(float *)0x1,
                 (ulong)unaff_EBX);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x278),(float *)0x1,
                 (ulong)in_stack_ffffffdc);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x280),(float *)0x1,
                 (ulong)in_stack_ffffffe0);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000020,(float *)0x1,
                 in_stack_ffffffe4);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x284),(float *)0x1,
                 in_stack_ffffffe8);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x26c),(float *)0x1,
                 in_stack_ffffffec);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x270),(float *)0x1,
                 in_stack_fffffff0);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x240),(float *)0x1,
                 (ulong)pvVar11);
      CClassicArchive::DoNatural
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x298),(ulong *)0x1,0,
                 (int)pCVar12);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x29c),(float *)0x1,
                 (ulong)pvVar13);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x2ac),(float *)0x1,
                 (ulong)unaff_retaddr);
      pCVar12 = (CClassicArchive *)(this + 0x2a8);
      CClassicArchive::DoNatural((CClassicArchive *)this_00,pCVar12,(ulong *)0x1,0,(int)param_1);
      param_1 = (CFuncSegment *)0x1;
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x244),(float *)0x1,
                 (ulong)param_2);
      param_2 = (CClassicArchive *)0x1;
      param_1 = (CFuncSegment *)(this + 0x2c0);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)param_1,(float *)0x1,param_3);
      param_3 = 1;
      param_2 = (CClassicArchive *)(this + 0x2b4);
      param_1 = (CFuncSegment *)0x7f723a;
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,param_2,(float *)0x1,(ulong)in_stack_00000010);
      in_stack_00000010 = (CClassicArchive *)0x1;
      param_3 = (ulong)(this + 0x2b0);
      param_2 = (CClassicArchive *)0x7f724a;
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)param_3,(float *)0x1,
                 (ulong)in_stack_00000014);
      in_stack_00000014 = (CClassicArchive *)(this + 0x2a4);
      in_stack_00000010 = (CClassicArchive *)0x7f7258;
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)this_00,in_stack_00000014,
                 (CMwNodRef<class_CMwRefBuffer> *)in_stack_00000018);
      in_stack_00000018 = (CClassicArchive *)(this + 0x288);
      in_stack_00000014 = (CClassicArchive *)0x7f7266;
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)this_00,in_stack_00000018,
                 (CMwNodRef<class_CMwRefBuffer> *)in_stack_0000001c);
      in_stack_0000001c = (CClassicArchive *)0x1;
      in_stack_00000018 = (CClassicArchive *)(this + 0x28c);
      in_stack_00000014 = (CClassicArchive *)0x7f7276;
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,in_stack_00000018,(float *)0x1,(ulong)in_stack_00000020)
      ;
      in_stack_00000020 = (CClassicArchive *)0x1;
      in_stack_0000001c = (CClassicArchive *)(this + 700);
      in_stack_00000018 = (CClassicArchive *)0x7f7286;
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,in_stack_0000001c,(float *)0x1,(ulong)in_stack_00000024)
      ;
      in_stack_00000024 = (CClassicArchive *)0x1;
      in_stack_00000020 = (CClassicArchive *)(this + 0x290);
      in_stack_0000001c = (CClassicArchive *)0x7f7296;
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,in_stack_00000020,(float *)0x1,(ulong)in_stack_00000028)
      ;
      in_stack_00000028 = (CClassicArchive *)0x1;
      in_stack_00000024 = (CClassicArchive *)(this + 0x294);
      in_stack_00000020 = (CClassicArchive *)0x7f72a6;
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,in_stack_00000024,(float *)0x1,(ulong)in_stack_0000002c)
      ;
      in_stack_0000002c = (CClassicArchive *)0x1;
      in_stack_00000028 = (CClassicArchive *)(this + 0x2b8);
      in_stack_00000024 = (CClassicArchive *)0x7f72b6;
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,in_stack_00000028,(float *)0x1,(ulong)in_stack_00000030)
      ;
      in_stack_00000030 = (CClassicArchive *)0x1;
      in_stack_0000002c = (CClassicArchive *)&stack0x00000070;
      in_stack_00000028 = (CClassicArchive *)0x7f72c4;
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,in_stack_0000002c,(float *)0x1,(ulong)in_stack_00000034)
      ;
      in_stack_00000034 = (CClassicArchive *)0x1;
      in_stack_00000030 = (CClassicArchive *)(this + 0x2d0);
      in_stack_0000002c = (CClassicArchive *)0x7f72d4;
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,in_stack_00000030,(float *)0x1,(ulong)in_stack_00000038)
      ;
      in_stack_00000038 = this_00;
      in_stack_00000034 = (CClassicArchive *)0x7f72e0;
      CFastBuffer<float>::ArchiveCountAndElems
                (this + 0x2c4,(CFastArray<struct_SOldLetter> *)this_00,in_stack_0000003c);
      in_stack_0000003c = (CClassicArchive *)&stack0x00000078;
      in_stack_00000038 = (CFuncSegment *)0x7f72ee;
      (**(code **)(*(int *)this_00 + 4))();
      pCVar10 = (CClassicArchive *)0x1;
      pCVar4 = (CClassicArchive *)&param_2;
      goto LAB_007f7899;
    }
    switch(param_2) {
    case (CClassicArchive *)0xa029036:
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::DoReal
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x19c),(float *)0x1,
                 (ulong)pCVar2);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x1a0),(float *)0x1,
                 (ulong)unaff_EDI);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x1a8),(float *)0x1,
                 (ulong)unaff_ESI);
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x1b4),
                 (CMwNodRef<class_CMwRefBuffer> *)unaff_EBX);
      ExceptionList = param_1;
      return;
    case (CClassicArchive *)0xa029037:
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x1c4),
                 (CMwNodRef<class_CMwRefBuffer> *)pCVar2);
      ExceptionList = pCVar12;
      return;
    case (CClassicArchive *)0xa029038:
      pCVar4 = (CClassicArchive *)(this + 0x1c8);
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::DoReal((CClassicArchive *)param_1,pCVar4,(float *)0x1,(ulong)pCVar2);
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x1bc),
                 (CMwNodRef<class_CMwRefBuffer> *)unaff_EDI);
      pCVar2 = (CClassicArchive *)(this + 0x1c0);
      pCVar10 = (CClassicArchive *)0x7f6d77;
      CClassicArchive::DoReal((CClassicArchive *)this_00,pCVar2,(float *)0x1,(ulong)unaff_ESI);
      break;
    case (CClassicArchive *)0xa029039:
      pCVar4 = (CClassicArchive *)(this + 0x1a4);
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::DoReal((CClassicArchive *)param_1,pCVar4,(float *)0x1,(ulong)pCVar2);
      pCVar10 = (CClassicArchive *)(this + 0x1ac);
      pCVar2 = (CClassicArchive *)0x1;
      break;
    case (CClassicArchive *)0xa02903a:
      pCVar4 = (CClassicArchive *)(this + 0x1cc);
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::DoReal((CClassicArchive *)param_1,pCVar4,(float *)0x1,(ulong)pCVar2);
      pCVar10 = (CClassicArchive *)(this + 0x1d0);
      pCVar2 = (CClassicArchive *)0x1;
      break;
    case (CClassicArchive *)0xa02903b:
      pCVar4 = (CClassicArchive *)(this + 0x1b0);
      goto LAB_007f7895;
    case (CClassicArchive *)0xa02903c:
      pCVar4 = (CClassicArchive *)(this + 0x1dc);
      goto LAB_007f7895;
    case (CClassicArchive *)0xa02903d:
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x1e0),
                 (CMwNodRef<class_CMwRefBuffer> *)pCVar2);
      ExceptionList = pCVar12;
      return;
    case (CClassicArchive *)0xa02903e:
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::DoNatural
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x1e8),(ulong *)0x1,0,
                 (int)pCVar2);
      ExceptionList = pCVar12;
      return;
    case (CClassicArchive *)0xa02903f:
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x1ec),
                 (CMwNodRef<class_CMwRefBuffer> *)pCVar2);
      ExceptionList = pCVar12;
      return;
    case (CClassicArchive *)0xa029040:
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x1f0),
                 (CMwNodRef<class_CMwRefBuffer> *)pCVar2);
      ExceptionList = pCVar12;
      return;
    case (CClassicArchive *)0xa029041:
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::DoReal
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 500),(float *)0x1,
                 (ulong)pCVar2);
      CClassicArchive::DoNatural
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x1f8),(ulong *)0x1,0,
                 (int)unaff_EDI);
      ExceptionList = pvVar13;
      return;
    case (CClassicArchive *)0xa029042:
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::DoNatural
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x1fc),(ulong *)0x1,0,
                 (int)pCVar2);
      ExceptionList = pCVar12;
      return;
    case (CClassicArchive *)0xa029043:
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::DoNatural
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x84),(ulong *)0x1,0,
                 (int)pCVar2);
      ExceptionList = pCVar12;
      return;
    case (CClassicArchive *)0xa029044:
      pCVar4 = (CClassicArchive *)(this + 0x200);
      goto LAB_007f7895;
    case (CClassicArchive *)0xa029045:
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::DoReal
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x204),(float *)0x1,
                 (ulong)pCVar2);
      pCVar4 = (CClassicArchive *)0x7f6f40;
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)&param_2,(float *)0x1,
                 (ulong)unaff_EDI);
      pCVar10 = (CClassicArchive *)0x7f6f4e;
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000010,(float *)0x1,
                 (ulong)unaff_ESI);
      pCVar2 = (CClassicArchive *)0x7f6f5e;
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x208),(float *)0x1,
                 (ulong)unaff_EBX);
      break;
    case (CClassicArchive *)0xa029046:
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::DoReal
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x204),(float *)0x1,
                 (ulong)pCVar2);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x208),(float *)0x1,
                 (ulong)unaff_EDI);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x20c),(float *)0x1,
                 (ulong)unaff_ESI);
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x214),
                 (CMwNodRef<class_CMwRefBuffer> *)unaff_EBX);
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x218),
                 (CMwNodRef<class_CMwRefBuffer> *)in_stack_ffffffdc);
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x210),in_stack_ffffffe0);
      ExceptionList = (void *)param_3;
      return;
    case (CClassicArchive *)0xa029047:
      pCVar4 = (CClassicArchive *)(this + 0x21c);
      goto LAB_007f7895;
    case (CClassicArchive *)0xa029048:
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x24),
                 (CMwNodRef<class_CMwRefBuffer> *)pCVar2);
      ExceptionList = pCVar12;
      return;
    case (CClassicArchive *)0xa029049:
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x224),
                 (CMwNodRef<class_CMwRefBuffer> *)pCVar2);
      ExceptionList = pCVar12;
      return;
    case (CClassicArchive *)0xa02904a:
      param_2 = (CClassicArchive *)0x0;
      pCVar4 = (CClassicArchive *)&param_2;
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::DoReal((CClassicArchive *)param_1,pCVar4,(float *)0x1,(ulong)pCVar2);
      pCVar10 = (CClassicArchive *)(this + 0x228);
      pCVar2 = (CClassicArchive *)0x1;
      break;
    case (CClassicArchive *)0xa02904b:
      param_2 = (CClassicArchive *)0x0;
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::DoReal
                ((CClassicArchive *)param_1,(CClassicArchive *)&param_2,(float *)0x1,(ulong)pCVar2);
      CClassicArchive::DoReal
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x22c),(float *)0x1,
                 (ulong)unaff_EDI);
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x230),
                 (CMwNodRef<class_CMwRefBuffer> *)unaff_ESI);
      ExceptionList = unaff_retaddr;
      return;
    case (CClassicArchive *)0xa02904c:
      goto switchD_007f6cc2_caseD_a02904c;
    case (CClassicArchive *)0xa02904d:
      pCVar4 = (CClassicArchive *)(this + 0x234);
      goto LAB_007f7895;
    case (CClassicArchive *)0xa02904e:
      pCVar4 = (CClassicArchive *)(this + 0x238);
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::DoReal((CClassicArchive *)param_1,pCVar4,(float *)0x1,(ulong)pCVar2);
      pCVar10 = (CClassicArchive *)(this + 0x23c);
      pCVar2 = (CClassicArchive *)0x1;
      break;
    case (CClassicArchive *)0xa02904f:
      ExceptionList = &stack0xfffffff4;
      CClassicArchive::DoReal
                ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x254),(float *)0x1,
                 (ulong)pCVar2);
      CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
                ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x25c),
                 (CMwNodRef<class_CMwRefBuffer> *)unaff_EDI);
      ExceptionList = pvVar13;
      return;
    default:
      goto switchD_007f5efc_default;
    }
    goto LAB_007f7899;
  }
  if (param_2 == (CClassicArchive *)0xa029035) {
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoBool
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x80),(int *)0x1,(ulong)pCVar2)
    ;
    ExceptionList = pCVar12;
    return;
  }
  switch(param_2) {
  case (CClassicArchive *)0xa029000:
    param_2 = (CClassicArchive *)0x3f800000;
    pvVar13 = ExceptionList;
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)&param_2,(float *)0x1,(ulong)pCVar2);
    pCVar4 = (CClassicArchive *)0x7f5f28;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x6c),(float *)0x1,
               (ulong)unaff_EDI);
    pCVar10 = (CClassicArchive *)0x7f5f35;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x70),(float *)0x1,
               (ulong)unaff_ESI);
    pCVar2 = (CClassicArchive *)0x7f5f42;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x2c),(float *)0x1,
               (ulong)unaff_EBX);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x114),(float *)0x1,
               (ulong)in_stack_ffffffdc);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x118),(float *)0x1,
               (ulong)in_stack_ffffffe0);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x11c),(float *)0x1,
               in_stack_ffffffe4);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x120),(float *)0x1,
               in_stack_ffffffe8);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x124),(float *)0x1,
               in_stack_ffffffec);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 300),(float *)0x1,
               in_stack_fffffff0);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x3c),(float *)0x1,
               (ulong)pvVar13);
    break;
  case (CClassicArchive *)0xa029001:
    ExceptionList = &stack0xfffffff4;
    CMwId::Archive(this + 0x14,(CFastCrypt<unsigned_long> *)param_1,pCVar2);
    ExceptionList = pCVar12;
    return;
  case (CClassicArchive *)0xa029002:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x130),(float *)0x1,
               (ulong)pCVar2);
    pCVar10 = (CClassicArchive *)(this + 0x144);
    pCVar4 = (CClassicArchive *)0x7f6005;
    CClassicArchive::DoReal((CClassicArchive *)this_00,pCVar10,(float *)0x1,(ulong)unaff_EDI);
    pCVar2 = (CClassicArchive *)(this + 0x148);
    break;
  case (CClassicArchive *)0xa029003:
    param_2 = (CClassicArchive *)0x0;
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)&param_2,(float *)0x1,(ulong)pCVar2);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0xa4),(float *)0x1,
               (ulong)unaff_EDI);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)&param_3,(float *)0x1,(ulong)unaff_ESI)
    ;
    this_01 = operator_new(0x2c);
    param_2 = (CClassicArchive *)0x0;
    if (this_01 == (CFuncKeysReal *)0x0) {
      pCVar3 = (CMwNodRef<class_CGameCamera> *)0x0;
    }
    else {
      CFuncKeysReal::CFuncKeysReal(this_01,unaff_EBX);
      pCVar3 = extraout_EAX;
    }
    param_3 = 0xffffffff;
    CMwNodRef<class_CGameCamera>::MwSetNod(this + 0xb8,pCVar3,in_stack_ffffffdc);
    CFuncKeysReal::InsertKeyReal
              (*(CFuncKeysReal **)(this + 0xb8),(CFuncKeysReal *)0x0,(float)in_stack_00000018,
               (float)in_stack_ffffffe0);
    ExceptionList = (void *)param_3;
    return;
  case (CClassicArchive *)0xa029004:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoBool
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 400),(int *)0x1,(ulong)pCVar2);
    ExceptionList = pCVar12;
    return;
  case (CClassicArchive *)0xa029005:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x160),(float *)0x1,
               (ulong)pCVar2);
    if (*(int *)(this_00 + 8) != 0) {
      ExceptionList = pCVar12;
      return;
    }
    *(undefined4 *)(this + 0x164) = *(undefined4 *)(this + 0x160);
    ExceptionList = pCVar12;
    return;
  case (CClassicArchive *)0xa029006:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)&param_1,(float *)0x1,(ulong)pCVar2);
    pCVar4 = (CClassicArchive *)0x7f6134;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)&param_2,(float *)0x1,(ulong)unaff_EDI)
    ;
    pCVar2 = (CClassicArchive *)&param_3;
    pCVar10 = (CClassicArchive *)0x7f6142;
    CClassicArchive::DoReal((CClassicArchive *)this_00,pCVar2,(float *)0x1,(ulong)unaff_ESI);
    break;
  case (CClassicArchive *)0xa029007:
    pCVar4 = (CClassicArchive *)(this + 0x94);
    goto LAB_007f7895;
  case (CClassicArchive *)0xa029008:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x30),(float *)0x1,
               (ulong)pCVar2);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0xf0),(float *)0x1,
               (ulong)unaff_EDI);
    *(undefined4 *)(this + 0xf4) = *(undefined4 *)(this + 0xf0);
    ExceptionList = pvVar13;
    return;
  case (CClassicArchive *)0xa029009:
    pCVar4 = (CClassicArchive *)(this + 0x40);
    goto LAB_007f7895;
  case (CClassicArchive *)0xa02900a:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x154),(float *)0x1,
               (ulong)pCVar2);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x158),(float *)0x1,
               (ulong)unaff_EDI);
    *(undefined4 *)(this + 0x15c) = 0;
    ExceptionList = pvVar13;
    return;
  case (CClassicArchive *)0xa02900b:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x134),(float *)0x1,
               (ulong)pCVar2);
    pCVar4 = (CClassicArchive *)0x7f620c;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x138),(float *)0x1,
               (ulong)unaff_EDI);
    pCVar2 = (CClassicArchive *)(this + 0x13c);
    pCVar10 = (CClassicArchive *)0x7f6219;
    CClassicArchive::DoReal((CClassicArchive *)this_00,pCVar2,(float *)0x1,(ulong)unaff_ESI);
    break;
  case (CClassicArchive *)0xa02900c:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoBool
              ((CClassicArchive *)param_1,(CClassicArchive *)&param_1,(int *)0x1,(ulong)pCVar2);
    if (*(int *)(this_00 + 8) != 0) {
      ExceptionList = pCVar12;
      return;
    }
    *(uint *)(this + 0x350) = (uint)(param_2 == (CClassicArchive *)0x0);
    ExceptionList = pCVar12;
    return;
  case (CClassicArchive *)0xa02900d:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoNatural
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x16c),(ulong *)0x1,0,
               (int)pCVar2);
    ExceptionList = pCVar12;
    return;
  case (CClassicArchive *)0xa02900e:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoNatural
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x350),(ulong *)0x1,0,
               (int)pCVar2);
    ExceptionList = pCVar12;
    return;
  case (CClassicArchive *)0xa02900f:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)&param_1,(float *)0x1,(ulong)pCVar2);
    param_3 = (ulong)operator_new(0x2c);
    if ((CFuncKeysReal *)param_3 == (CFuncKeysReal *)0x0) {
      pCVar3 = (CMwNodRef<class_CGameCamera> *)0x0;
    }
    else {
      CFuncKeysReal::CFuncKeysReal((CFuncKeysReal *)param_3,unaff_EDI);
      pCVar3 = extraout_EAX_00;
    }
    param_1 = (CFuncSegment *)0xffffffff;
    CMwNodRef<class_CGameCamera>::MwSetNod(this + 0xa0,pCVar3,(CGameCamera *)unaff_ESI);
    CFuncKeysReal::InsertKeyReal
              (*(CFuncKeysReal **)(this + 0xa0),(CFuncKeysReal *)0x0,(float)in_stack_00000010,
               (float)unaff_EBX);
    ExceptionList = param_1;
    return;
  case (CClassicArchive *)0xa029010:
    pCVar4 = (CClassicArchive *)0x1;
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoNatural
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x354),(ulong *)0x1,0,
               (int)pCVar2);
    pCVar2 = (CClassicArchive *)0x1;
    pCVar10 = (CClassicArchive *)(this + 0x98);
    break;
  case (CClassicArchive *)0xa029011:
    param_2 = (CClassicArchive *)0x0;
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)&param_2,(float *)0x1,(ulong)pCVar2);
    pCVar4 = (CClassicArchive *)0x7f637b;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)&param_3,(float *)0x1,(ulong)unaff_EDI)
    ;
    pCVar10 = (CClassicArchive *)0x7f6389;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000010,(float *)0x1,
               (ulong)unaff_ESI);
    pCVar2 = (CClassicArchive *)0x7f6397;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000014,(float *)0x1,
               (ulong)unaff_EBX);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000018,(float *)0x1,
               (ulong)in_stack_ffffffdc);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x0000001c,(float *)0x1,
               (ulong)in_stack_ffffffe0);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000020,(float *)0x1,
               in_stack_ffffffe4);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000024,(float *)0x1,
               in_stack_ffffffe8);
    break;
  case (CClassicArchive *)0xa029012:
    pCVar10 = (CClassicArchive *)0x1;
    pCVar4 = (CClassicArchive *)(this + 0x388);
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal((CClassicArchive *)param_1,pCVar4,(float *)0x1,(ulong)pCVar2);
    pCVar7 = this + 0x390;
    goto LAB_007f63f7;
  case (CClassicArchive *)0xa029013:
    param_2 = (CClassicArchive *)0x0;
    pvVar13 = ExceptionList;
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)&param_2,(float *)0x1,(ulong)pCVar2);
    pCVar4 = (CClassicArchive *)0x7f6487;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)&param_3,(float *)0x1,(ulong)unaff_EDI)
    ;
    pCVar10 = (CClassicArchive *)0x7f6495;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000010,(float *)0x1,
               (ulong)unaff_ESI);
    pCVar2 = (CClassicArchive *)0x7f64a3;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000014,(float *)0x1,
               (ulong)unaff_EBX);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000018,(float *)0x1,
               (ulong)in_stack_ffffffdc);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x0000001c,(float *)0x1,
               (ulong)in_stack_ffffffe0);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000020,(float *)0x1,
               in_stack_ffffffe4);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000024,(float *)0x1,
               in_stack_ffffffe8);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000028,(float *)0x1,
               in_stack_ffffffec);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x0000002c,(float *)0x1,
               in_stack_fffffff0);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000030,(float *)0x1,
               (ulong)pvVar13);
    break;
  case (CClassicArchive *)0xa029014:
    param_2 = (CClassicArchive *)0x0;
    pCVar4 = (CClassicArchive *)&param_2;
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal((CClassicArchive *)param_1,pCVar4,(float *)0x1,(ulong)pCVar2);
    pCVar10 = (CClassicArchive *)&param_2;
    param_2 = (CClassicArchive *)0x0;
    pCVar2 = (CClassicArchive *)0x1;
    break;
  case (CClassicArchive *)0xa029015:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x388),(float *)0x1,
               (ulong)pCVar2);
    pCVar2 = (CClassicArchive *)0x1;
    pCVar10 = (CClassicArchive *)(this + 0x390);
    pCVar4 = (CClassicArchive *)0x7f6563;
    CClassicArchive::DoReal((CClassicArchive *)this_00,pCVar10,(float *)0x1,(ulong)unaff_EDI);
    pCVar7 = this + 0x38c;
LAB_007f63f7:
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)pCVar7,(float *)0x1,(ulong)pCVar4);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x394),(float *)0x1,
               (ulong)pCVar10);
    pCVar4 = (CClassicArchive *)(this + 0x28);
    CClassicArchive::DoReal((CClassicArchive *)this_00,pCVar4,(float *)0x1,(ulong)pCVar2);
    if (*(int *)(this_00 + 8) != 0) {
      ExceptionList = pCVar12;
      return;
    }
    fVar1 = (float)_DAT_00b313b8;
    *(float *)(this + 0x3a0) = *(float *)pCVar4 * fVar1;
    *(undefined4 *)(this + 0x398) = *(undefined4 *)pCVar4;
    *(float *)(this + 0x39c) = *(float *)pCVar4 * fVar1;
    ExceptionList = pCVar12;
    return;
  case (CClassicArchive *)0xa029016:
    param_2 = (CClassicArchive *)0x0;
    pCVar4 = (CClassicArchive *)&param_2;
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal((CClassicArchive *)param_1,pCVar4,(float *)0x1,(ulong)pCVar2);
    pCVar10 = (CClassicArchive *)&stack0xffffffe0;
    pCVar2 = (CClassicArchive *)0x1;
    break;
  case (CClassicArchive *)0xa029017:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x3a4),(float *)0x1,
               (ulong)pCVar2);
    pCVar4 = (CClassicArchive *)0x7f65bc;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x3a8),(float *)0x1,
               (ulong)unaff_EDI);
    param_3 = 0;
    pCVar10 = (CClassicArchive *)0x7f65d2;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x37c),(float *)0x1,
               (ulong)unaff_ESI);
    pCVar2 = (CClassicArchive *)0x7f65e0;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000010,(float *)0x1,
               (ulong)unaff_EBX);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000014,(float *)0x1,
               (ulong)in_stack_ffffffdc);
    in_stack_0000001c = (CClassicArchive *)0x0;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x0000001c,(float *)0x1,
               (ulong)in_stack_ffffffe0);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0xfffffff4,(float *)0x1,
               in_stack_ffffffe4);
    break;
  case (CClassicArchive *)0xa029018:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x154),(float *)0x1,
               (ulong)pCVar2);
    pCVar10 = (CClassicArchive *)(this + 0x158);
    pCVar4 = (CClassicArchive *)0x7f664e;
    CClassicArchive::DoReal((CClassicArchive *)this_00,pCVar10,(float *)0x1,(ulong)unaff_EDI);
    pCVar2 = (CClassicArchive *)(this + 0x15c);
    break;
  case (CClassicArchive *)0xa029019:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x170),(float *)0x1,
               (ulong)pCVar2);
    pCVar4 = (CClassicArchive *)0x7f6682;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x174),(float *)0x1,
               (ulong)unaff_EDI);
    pCVar10 = (CClassicArchive *)0x7f6692;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x178),(float *)0x1,
               (ulong)unaff_ESI);
    pCVar2 = (CClassicArchive *)0x7f66a2;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x17c),(float *)0x1,
               (ulong)unaff_EBX);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x180),(float *)0x1,
               (ulong)in_stack_ffffffdc);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x184),(float *)0x1,
               (ulong)in_stack_ffffffe0);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x188),(float *)0x1,
               in_stack_ffffffe4);
    break;
  case (CClassicArchive *)0xa02901a:
    pCVar4 = (CClassicArchive *)(this + 0x54);
    goto LAB_007f7895;
  case (CClassicArchive *)0xa02901b:
    pCVar4 = (CClassicArchive *)&param_2;
    param_2 = (CClassicArchive *)0x0;
    goto LAB_007f7895;
  case (CClassicArchive *)0xa02901c:
    uVar9 = 0x7f670d;
    pvVar13 = ExceptionList;
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x38),(float *)0x1,
               (ulong)pCVar2);
    pCVar10 = (CClassicArchive *)&param_2;
    uVar8 = 0x7f671b;
    CClassicArchive::DoReal((CClassicArchive *)this_00,pCVar10,(float *)0x1,(ulong)unaff_EDI);
    pCVar2 = (CClassicArchive *)0x7f6722;
    in_stack_00000010 = operator_new(0x2c);
    param_1 = (CFuncSegment *)0x2;
    if (in_stack_00000010 == (CClassicArchive *)0x0) {
      pCVar3 = (CMwNodRef<class_CGameCamera> *)0x0;
    }
    else {
      CFuncKeysReal::CFuncKeysReal((CFuncKeysReal *)in_stack_00000010,(CFuncKeysReal *)unaff_ESI);
      pCVar3 = extraout_EAX_01;
    }
    CMwNodRef<class_CGameCamera>::MwSetNod(this + 0xac,pCVar3,in_stack_ffffffb8);
    CFuncKeysReal::InsertKeyReal
              (*(CFuncKeysReal **)(this + 0xac),(CFuncKeysReal *)0x0,(float)pvVar13,
               in_stack_ffffffbc);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0xb0),(float *)0x1,uVar9);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x50),(float *)0x1,uVar8);
    pCVar4 = (CClassicArchive *)0x1;
    pCVar7 = this + 0x58;
    goto LAB_007f6790;
  case (CClassicArchive *)0xa02901d:
    pCVar4 = (CClassicArchive *)(this + 0x164);
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal((CClassicArchive *)param_1,pCVar4,(float *)0x1,(ulong)pCVar2);
    pCVar2 = (CClassicArchive *)0x1;
    pCVar10 = (CClassicArchive *)(this + 0xc0);
    break;
  case (CClassicArchive *)0xa02901e:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoNatural
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x364),(ulong *)0x1,0,
               (int)pCVar2);
    ExceptionList = pCVar12;
    return;
  case (CClassicArchive *)0xa02901f:
    param_2 = (CClassicArchive *)0x3f800000;
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)&param_2,(float *)0x1,(ulong)pCVar2);
    param_2 = (CClassicArchive *)0x3f800000;
    pCVar10 = (CClassicArchive *)&param_2;
    pCVar4 = (CClassicArchive *)0x7f6820;
    CClassicArchive::DoReal((CClassicArchive *)this_00,pCVar10,(float *)0x1,(ulong)unaff_EDI);
    pCVar2 = (CClassicArchive *)&stack0xffffffe8;
    break;
  case (CClassicArchive *)0xa029020:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0xc4),(float *)0x1,
               (ulong)pCVar2);
    pCVar4 = (CClassicArchive *)0x7f6858;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 200),(float *)0x1,
               (ulong)unaff_EDI);
    pCVar2 = (CClassicArchive *)(this + 0xcc);
    pCVar10 = (CClassicArchive *)0x7f6868;
    CClassicArchive::DoReal((CClassicArchive *)this_00,pCVar2,(float *)0x1,(ulong)unaff_ESI);
    break;
  case (CClassicArchive *)0xa029021:
switchD_007f5efc_caseD_a029021:
    pCVar4 = (CClassicArchive *)&param_1;
    goto LAB_007f7895;
  case (CClassicArchive *)0xa029022:
    pCVar4 = (CClassicArchive *)&param_1;
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal((CClassicArchive *)param_1,pCVar4,(float *)0x1,(ulong)pCVar2);
    pCVar2 = (CClassicArchive *)0x1;
    pCVar10 = (CClassicArchive *)&param_3;
    break;
  case (CClassicArchive *)0xa029023:
    pCVar4 = (CClassicArchive *)(this + 0xec);
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal((CClassicArchive *)param_1,pCVar4,(float *)0x1,(ulong)pCVar2);
    pCVar2 = (CClassicArchive *)0x1;
    pCVar10 = (CClassicArchive *)(this + 0x74);
    break;
  case (CClassicArchive *)0xa029024:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x34),
               (CMwNodRef<class_CMwRefBuffer> *)pCVar2);
    ExceptionList = pCVar12;
    return;
  case (CClassicArchive *)0xa029025:
    pCVar4 = (CClassicArchive *)&param_1;
    pCVar6 = (CGameCamera *)0x7f68f9;
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal((CClassicArchive *)param_1,pCVar4,(float *)0x1,(ulong)pCVar2);
    pCVar2 = (CClassicArchive *)&DAT_0000002c;
    uVar9 = 0x7f6900;
    param_3 = (ulong)operator_new(0x2c);
    if ((CFuncKeysReal *)param_3 == (CFuncKeysReal *)0x0) {
      pCVar3 = (CMwNodRef<class_CGameCamera> *)0x0;
    }
    else {
      pCVar2 = (CClassicArchive *)0x7f691a;
      CFuncKeysReal::CFuncKeysReal((CFuncKeysReal *)param_3,unaff_EDI);
      pCVar3 = extraout_EAX_02;
    }
    CMwNodRef<class_CGameCamera>::MwSetNod(this + 0x78,pCVar3,pCVar6);
    CFuncKeysReal::InsertKeyReal
              (*(CFuncKeysReal **)(this + 0x78),(CFuncKeysReal *)0x0,(float)pvVar13,(float)pCVar4);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0xa8),(float *)0x1,uVar9);
    pCVar10 = (CClassicArchive *)0x1;
    pCVar4 = (CClassicArchive *)(this + 0x100);
    break;
  case (CClassicArchive *)0xa029026:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0xd4),(float *)0x1,
               (ulong)pCVar2);
    pCVar4 = (CClassicArchive *)0x7f698c;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0xd8),(float *)0x1,
               (ulong)unaff_EDI);
    pCVar2 = (CClassicArchive *)(this + 0xdc);
    pCVar10 = (CClassicArchive *)0x7f699c;
    CClassicArchive::DoReal((CClassicArchive *)this_00,pCVar2,(float *)0x1,(ulong)unaff_ESI);
    break;
  case (CClassicArchive *)0xa029027:
    pCVar4 = (CClassicArchive *)(this + 0x9c);
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal((CClassicArchive *)param_1,pCVar4,(float *)0x1,(ulong)pCVar2);
    pCVar2 = (CClassicArchive *)0x1;
    pCVar10 = (CClassicArchive *)(this + 0xb4);
    break;
  case (CClassicArchive *)0xa029028:
    pCVar4 = (CClassicArchive *)(this + 0x38);
    pCVar7 = (CSceneVehicleCarTuning *)0x7f69e1;
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal((CClassicArchive *)param_1,pCVar4,(float *)0x1,(ulong)pCVar2);
    CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0xac),
               (CMwNodRef<class_CMwRefBuffer> *)unaff_EDI);
    pCVar10 = (CClassicArchive *)0x7f69ff;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0xb0),(float *)0x1,
               (ulong)unaff_ESI);
    pCVar2 = (CClassicArchive *)0x7f6a0c;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x50),(float *)0x1,
               (ulong)unaff_EBX);
LAB_007f6790:
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)pCVar7,(float *)pCVar4,(ulong)pCVar10);
    pCVar4 = (CClassicArchive *)(this + 0x194);
    pCVar10 = (CClassicArchive *)0x1;
    break;
  case (CClassicArchive *)0xa029029:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0xa4),(float *)0x1,
               (ulong)pCVar2);
    CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0xb8),
               (CMwNodRef<class_CMwRefBuffer> *)unaff_EDI);
    ExceptionList = pvVar13;
    return;
  case (CClassicArchive *)0xa02902a:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x68),
               (CMwNodRef<class_CMwRefBuffer> *)pCVar2);
    ExceptionList = pCVar12;
    return;
  case (CClassicArchive *)0xa02902b:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x78),
               (CMwNodRef<class_CMwRefBuffer> *)pCVar2);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0xa8),(float *)0x1,
               (ulong)unaff_EDI);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x100),(float *)0x1,
               (ulong)unaff_ESI);
    CClassicArchive::DoNatural
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x88),(ulong *)0x1,0,
               (int)unaff_EBX);
    ExceptionList = param_1;
    return;
  case (CClassicArchive *)0xa02902c:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0xbc),
               (CMwNodRef<class_CMwRefBuffer> *)pCVar2);
    pCVar4 = (CClassicArchive *)0x7f6ae8;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x368),(float *)0x1,
               (ulong)unaff_EDI);
    pCVar10 = (CClassicArchive *)0x7f6af5;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x44),(float *)0x1,
               (ulong)unaff_ESI);
    pCVar2 = (CClassicArchive *)0x7f6b02;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x48),(float *)0x1,
               (ulong)unaff_EBX);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x4c),(float *)0x1,
               (ulong)in_stack_ffffffdc);
    break;
  case (CClassicArchive *)0xa02902d:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoNatural
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x8c),(ulong *)0x1,0,
               (int)pCVar2);
    ExceptionList = pCVar12;
    return;
  case (CClassicArchive *)0xa02902e:
    pCVar4 = (CClassicArchive *)(this + 0x7c);
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal((CClassicArchive *)param_1,pCVar4,(float *)0x1,(ulong)pCVar2);
    pCVar10 = (CClassicArchive *)&param_2;
    param_2 = (CClassicArchive *)0x0;
    pCVar2 = (CClassicArchive *)0x1;
    break;
  case (CClassicArchive *)0xa02902f:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoNatural
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0xf8),(ulong *)0x1,0,
               (int)pCVar2);
    *(undefined4 *)(this + 0xfc) = *(undefined4 *)(this + 0xf8);
    ExceptionList = pCVar12;
    return;
  case (CClassicArchive *)0xa029030:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0xa0),
               (CMwNodRef<class_CMwRefBuffer> *)pCVar2);
    ExceptionList = pCVar12;
    return;
  case (CClassicArchive *)0xa029031:
    pCVar4 = (CClassicArchive *)(this + 0x60);
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal((CClassicArchive *)param_1,pCVar4,(float *)0x1,(ulong)pCVar2);
    pCVar10 = (CClassicArchive *)(this + 100);
    pCVar2 = (CClassicArchive *)0x1;
    break;
  case (CClassicArchive *)0xa029032:
    ExceptionList = &stack0xfffffff4;
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x388),(float *)0x1,
               (ulong)pCVar2);
    pCVar4 = (CClassicArchive *)0x7f6c02;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x390),(float *)0x1,
               (ulong)unaff_EDI);
    pCVar10 = (CClassicArchive *)0x7f6c12;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x38c),(float *)0x1,
               (ulong)unaff_ESI);
    pCVar2 = (CClassicArchive *)0x7f6c22;
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x394),(float *)0x1,
               (ulong)unaff_EBX);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x398),(float *)0x1,
               (ulong)in_stack_ffffffdc);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x39c),(float *)0x1,
               (ulong)in_stack_ffffffe0);
    CClassicArchive::DoReal
              ((CClassicArchive *)this_00,(CClassicArchive *)(this + 0x28),(float *)0x1,
               in_stack_ffffffe4);
    break;
  case (CClassicArchive *)0xa029033:
    pCVar4 = (CClassicArchive *)(this + 0x14c);
    goto LAB_007f7895;
  case (CClassicArchive *)0xa029034:
    pCVar4 = (CClassicArchive *)(this + 0x150);
LAB_007f7895:
    pCVar10 = (CClassicArchive *)0x1;
    ExceptionList = &stack0xfffffff4;
    break;
  default:
switchD_007f5efc_default:
    ExceptionList = &stack0xfffffff4;
    CSceneVehicleTuning::Chunk((CSceneVehicleTuning *)this,param_1,param_2,(ulong)pCVar2);
    ExceptionList = pCVar12;
    return;
  }
LAB_007f7899:
  CClassicArchive::DoReal((CClassicArchive *)this_00,pCVar4,(float *)pCVar10,(ulong)pCVar2);
switchD_007f6cc2_caseD_a02904c:
  ExceptionList = pCVar12;
  return;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::GetAccelFromSpeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CSceneVehicleCarTuning::GetAccelFromSpeed
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1,float param_2)
{
{
  float fVar1;
  undefined1 local_4 [4];
  
  fVar1 = (float)_DAT_00b3d2a8;
  *(undefined4 *)(*(int *)(this + 0x34) + 0x28) = 1;
  CFuncKeysReal::GetValue
            (*(CFuncKeysReal **)(this + 0x34),(CFuncColorGradient *)((float)param_1 * fVar1),
             (float)local_4);
  return 0.0;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::GetChunkCount
// =================================================
ulong __thiscall
CSceneVehicleCarTuning::GetChunkCount(CSceneVehicleCarTuning *this,CPlugSoundMood *param_1)
{
{
  return 0x6c;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::GetChunkInfo
// =================================================
ulong __thiscall
CSceneVehicleCarTuning::GetChunkInfo
          (CSceneVehicleCarTuning *this,CFuncSegment *param_1,ulong param_2)
{
{
  ulong uVar1;
  
  if (param_1 < (CFuncSegment *)0xa029036) {
    if (param_1 != (CFuncSegment *)0xa029035) {
      switch(param_1) {
      case (CFuncSegment *)0xa029000:
      case (CFuncSegment *)0xa029001:
      case (CFuncSegment *)0xa029002:
      case (CFuncSegment *)0xa029004:
      case (CFuncSegment *)0xa029005:
      case (CFuncSegment *)0xa029007:
      case (CFuncSegment *)0xa029009:
      case (CFuncSegment *)0xa02900b:
      case (CFuncSegment *)0xa02900d:
      case (CFuncSegment *)0xa02900e:
      case (CFuncSegment *)0xa029010:
      case (CFuncSegment *)0xa029013:
      case (CFuncSegment *)0xa029014:
      case (CFuncSegment *)0xa029017:
      case (CFuncSegment *)0xa029018:
      case (CFuncSegment *)0xa029019:
      case (CFuncSegment *)0xa02901a:
      case (CFuncSegment *)0xa02901b:
      case (CFuncSegment *)0xa02901d:
      case (CFuncSegment *)0xa02901e:
      case (CFuncSegment *)0xa02901f:
      case (CFuncSegment *)0xa029020:
      case (CFuncSegment *)0xa029023:
      case (CFuncSegment *)0xa029024:
      case (CFuncSegment *)0xa029026:
      case (CFuncSegment *)0xa029027:
      case (CFuncSegment *)0xa029028:
      case (CFuncSegment *)0xa029029:
      case (CFuncSegment *)0xa02902a:
      case (CFuncSegment *)0xa02902b:
      case (CFuncSegment *)0xa02902c:
      case (CFuncSegment *)0xa02902d:
      case (CFuncSegment *)0xa02902e:
      case (CFuncSegment *)0xa029030:
      case (CFuncSegment *)0xa029031:
      case (CFuncSegment *)0xa029032:
      case (CFuncSegment *)0xa029033:
      case (CFuncSegment *)0xa029034:
        break;
      case (CFuncSegment *)0xa029003:
      case (CFuncSegment *)0xa029006:
      case (CFuncSegment *)0xa029008:
      case (CFuncSegment *)0xa02900a:
      case (CFuncSegment *)0xa02900c:
      case (CFuncSegment *)0xa02900f:
      case (CFuncSegment *)0xa029011:
      case (CFuncSegment *)0xa029012:
      case (CFuncSegment *)0xa029015:
      case (CFuncSegment *)0xa029016:
      case (CFuncSegment *)0xa02901c:
      case (CFuncSegment *)0xa029021:
      case (CFuncSegment *)0xa029022:
      case (CFuncSegment *)0xa029025:
      case (CFuncSegment *)0xa02902f:
        goto switchD_007f32fc_caseD_a029003;
      default:
        goto switchD_007f32fc_default;
      }
    }
  }
  else {
    if (param_1 < (CFuncSegment *)0xa029051) {
      if (param_1 != (CFuncSegment *)0xa029050) {
        switch(param_1) {
        case (CFuncSegment *)0xa029036:
        case (CFuncSegment *)0xa029037:
        case (CFuncSegment *)0xa029038:
        case (CFuncSegment *)0xa029039:
        case (CFuncSegment *)0xa02903a:
        case (CFuncSegment *)0xa02903b:
        case (CFuncSegment *)0xa02903c:
        case (CFuncSegment *)0xa02903d:
        case (CFuncSegment *)0xa02903e:
        case (CFuncSegment *)0xa02903f:
        case (CFuncSegment *)0xa029040:
        case (CFuncSegment *)0xa029041:
        case (CFuncSegment *)0xa029042:
        case (CFuncSegment *)0xa029043:
        case (CFuncSegment *)0xa029044:
        case (CFuncSegment *)0xa029046:
        case (CFuncSegment *)0xa029047:
        case (CFuncSegment *)0xa029049:
        case (CFuncSegment *)0xa02904d:
        case (CFuncSegment *)0xa02904e:
        case (CFuncSegment *)0xa02904f:
          goto switchD_007f32fc_caseD_a029000;
        case (CFuncSegment *)0xa029045:
        case (CFuncSegment *)0xa029048:
        case (CFuncSegment *)0xa02904a:
        case (CFuncSegment *)0xa02904b:
        case (CFuncSegment *)0xa02904c:
          break;
        default:
          goto switchD_007f32fc_default;
        }
      }
switchD_007f32fc_caseD_a029003:
      return 1;
    }
    if (param_1 < (CFuncSegment *)0xa02905f) {
      if (param_1 != (CFuncSegment *)0xa02905e) {
        switch(param_1) {
        case (CFuncSegment *)0xa029051:
        case (CFuncSegment *)0xa029052:
        case (CFuncSegment *)0xa029053:
        case (CFuncSegment *)0xa029056:
        case (CFuncSegment *)0xa029057:
        case (CFuncSegment *)0xa029058:
        case (CFuncSegment *)0xa029059:
        case (CFuncSegment *)0xa02905a:
        case (CFuncSegment *)0xa02905b:
        case (CFuncSegment *)0xa02905c:
        case (CFuncSegment *)0xa02905d:
          break;
        case (CFuncSegment *)0xa029054:
        case (CFuncSegment *)0xa029055:
          goto switchD_007f32fc_caseD_a029003;
        default:
          goto switchD_007f32fc_default;
        }
      }
    }
    else {
      if ((CFuncSegment *)0xa029065 < param_1) {
        if (param_1 < (CFuncSegment *)0xa029069) {
          if (param_1 == (CFuncSegment *)0xa029068) {
            return 1;
          }
          if (param_1 == (CFuncSegment *)0xa029066) {
            return 3;
          }
          if (param_1 == (CFuncSegment *)0xa029067) {
            return 1;
          }
        }
        else {
          if (param_1 == (CFuncSegment *)0xa029069) {
            return 1;
          }
          if (param_1 == (CFuncSegment *)0xffffffff) {
            return 0xffffffff;
          }
        }
switchD_007f32fc_default:
        uVar1 = CSceneVehicleTuning::GetChunkInfo((CSceneVehicleTuning *)this,param_1,param_2);
        return uVar1;
      }
      if (param_1 != (CFuncSegment *)0xa029065) {
        switch(param_1) {
        case (CFuncSegment *)0xa02905f:
        case (CFuncSegment *)0xa029060:
        case (CFuncSegment *)0xa029061:
        case (CFuncSegment *)0xa029062:
        case (CFuncSegment *)0xa029063:
        case (CFuncSegment *)0xa029064:
          break;
        default:
          goto switchD_007f32fc_default;
        }
      }
    }
  }
switchD_007f32fc_caseD_a029000:
  return 3;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::GetLateralContactSlowDownFromSpeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CSceneVehicleCarTuning::GetLateralContactSlowDownFromSpeed
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1,float param_2)
{
{
  float fVar1;
  undefined1 local_4 [4];
  
  fVar1 = (float)_DAT_00b3d2a8;
  *(undefined4 *)(*(int *)(this + 0x68) + 0x28) = 1;
  CFuncKeysReal::GetValue
            (*(CFuncKeysReal **)(this + 0x68),(CFuncColorGradient *)((float)param_1 * fVar1),
             (float)local_4);
  return 0.0;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::GetMaxSideFrictionFromSpeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CSceneVehicleCarTuning::GetMaxSideFrictionFromSpeed
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1,float param_2)
{
{
  float unaff_retaddr;
  
  param_1 = (CSceneVehicleCarTuning *)((float)param_1 * (float)_DAT_00b3d2a8);
  CFuncKeysReal::GetValue
            (*(CFuncKeysReal **)(this + 0xac),(CFuncColorGradient *)param_1,(float)&param_1);
  return unaff_retaddr;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::GetMwClassId
// =================================================
ulong __thiscall
CSceneVehicleCarTuning::GetMwClassId(CSceneVehicleCarTuning *this,CControlStyle *param_1)
{
{
  return 0xa029000;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::GetRolloverLateralCoefFromAngle
// =================================================
float __thiscall
CSceneVehicleCarTuning::GetRolloverLateralCoefFromAngle
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1,float param_2)
{
{
  float unaff_retaddr;
  
  CFuncKeysReal::GetValue
            (*(CFuncKeysReal **)(this + 0xbc),(CFuncColorGradient *)param_1,(float)&param_1);
  return unaff_retaddr;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::GetRolloverLateralFromSpeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CSceneVehicleCarTuning::GetRolloverLateralFromSpeed
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1,float param_2)
{
{
  float unaff_retaddr;
  
  param_1 = (CSceneVehicleCarTuning *)((float)param_1 * (float)_DAT_00b3d2a8);
  CFuncKeysReal::GetValue
            (*(CFuncKeysReal **)(this + 0xb8),(CFuncColorGradient *)param_1,(float)&param_1);
  return unaff_retaddr;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::GetSteerDriveTorqueFromSpeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CSceneVehicleCarTuning::GetSteerDriveTorqueFromSpeed
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1,float param_2)
{
{
  float unaff_retaddr;
  
  param_1 = (CSceneVehicleCarTuning *)((float)param_1 * (float)_DAT_00b3d2a8);
  CFuncKeysReal::GetValue
            (*(CFuncKeysReal **)(this + 0xa0),(CFuncColorGradient *)param_1,(float)&param_1);
  return unaff_retaddr;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::GetSteerSlowDownFromSpeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CSceneVehicleCarTuning::GetSteerSlowDownFromSpeed
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1,float param_2)
{
{
  float fVar1;
  undefined1 local_4 [4];
  
  fVar1 = (float)_DAT_00b3d2a8;
  *(undefined4 *)(*(int *)(this + 0x78) + 0x28) = 1;
  CFuncKeysReal::GetValue
            (*(CFuncKeysReal **)(this + 0x78),(CFuncColorGradient *)((float)param_1 * fVar1),
             (float)local_4);
  return 0.0;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::GetUidChunkFromIndex
// =================================================
ulong __thiscall
CSceneVehicleCarTuning::GetUidChunkFromIndex
          (CSceneVehicleCarTuning *this,CMwCmdExpIso4Ident *param_1,ulong param_2)
{
{
  if ((CMwCmdExpIso4Ident *)0x1 < param_1) {
    return (uint)(param_1 + -2) | 0xa029000;
  }
  if (param_1 == (CMwCmdExpIso4Ident *)0x0) {
    return 0x1001000;
  }
  return (uint)(param_1 + -1) | 0xa02e000;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::GetWaterFrictionFromSpeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CSceneVehicleCarTuning::GetWaterFrictionFromSpeed
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1,float param_2)
{
{
  float unaff_retaddr;
  
  param_1 = (CSceneVehicleCarTuning *)((float)param_1 * (float)_DAT_00b3d2a8);
  CFuncKeysReal::GetValue
            (*(CFuncKeysReal **)(this + 0x218),(CFuncColorGradient *)param_1,(float)&param_1);
  return unaff_retaddr;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::M4GetMaxFrictionForceFromSpeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CSceneVehicleCarTuning::M4GetMaxFrictionForceFromSpeed
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1,float param_2)
{
{
  float unaff_retaddr;
  
  param_1 = (CSceneVehicleCarTuning *)((float)param_1 * (float)_DAT_00b3d2a8);
  CFuncKeysReal::GetValue
            (*(CFuncKeysReal **)(this + 0x1bc),(CFuncColorGradient *)param_1,(float)&param_1);
  return unaff_retaddr;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::M4GetSteerRadiusFromSpeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CSceneVehicleCarTuning::M4GetSteerRadiusFromSpeed
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1,float param_2)
{
{
  float unaff_retaddr;
  
  param_1 = (CSceneVehicleCarTuning *)((float)param_1 * (float)_DAT_00b3d2a8);
  CFuncKeysReal::GetValue
            (*(CFuncKeysReal **)(this + 0x1b4),(CFuncColorGradient *)param_1,(float)&param_1);
  return unaff_retaddr;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::M5GetAccelFromSpeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CSceneVehicleCarTuning::M5GetAccelFromSpeed
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1,float param_2)
{
{
  float unaff_retaddr;
  
  param_1 = (CSceneVehicleCarTuning *)((float)param_1 * (float)_DAT_00b3d2a8);
  CFuncKeysReal::GetValue
            (*(CFuncKeysReal **)(this + 0x34),(CFuncColorGradient *)param_1,(float)&param_1);
  return unaff_retaddr;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::M5GetLateralContactSlowDownFromSpeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CSceneVehicleCarTuning::M5GetLateralContactSlowDownFromSpeed
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1,float param_2)
{
{
  float10 extraout_ST0;
  
  CFuncKeysReal::GetValue
            (*(CFuncKeysReal **)(this + 0x68),
             (CFuncColorGradient *)((float)param_1 * (float)_DAT_00b3d2a8),0.0);
  return (float)extraout_ST0;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::M5GetSlippingAccelFromSpeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CSceneVehicleCarTuning::M5GetSlippingAccelFromSpeed
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1,float param_2)
{
{
  float unaff_retaddr;
  
  param_1 = (CSceneVehicleCarTuning *)((float)param_1 * (float)_DAT_00b3d2a8);
  CFuncKeysReal::GetValue
            (*(CFuncKeysReal **)(this + 0x1e0),(CFuncColorGradient *)param_1,(float)&param_1);
  return *(float *)(this + 0x1e4) * unaff_retaddr;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::M5GetSteerSlowDownFromSpeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CSceneVehicleCarTuning::M5GetSteerSlowDownFromSpeed
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1,float param_2)
{
{
  float unaff_retaddr;
  
  param_1 = (CSceneVehicleCarTuning *)((float)param_1 * (float)_DAT_00b3d2a8);
  CFuncKeysReal::GetValue
            (*(CFuncKeysReal **)(this + 0x78),(CFuncColorGradient *)param_1,(float)&param_1);
  return unaff_retaddr;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::M6CheckRpmWantedConstistensy
// =================================================
void __thiscall
CSceneVehicleCarTuning::M6CheckRpmWantedConstistensy
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1)
{
{
  CSceneVehicleCarTuning *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  SCasterCat *pSVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CSceneVehicleCarTuning *pCVar5;
  
  this_00 = this + 0x2e0;
  pCVar5 = this;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar4,(ulong)unaff_EBP);
      unaff_EBP = pCVar4;
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x2f8,pCVar4,unaff_ESI);
      if (*(float *)pSVar3 < *(float *)pSVar2) {
        unaff_EBP = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7f437b;
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar4,(ulong)unaff_EBX);
        unaff_ESI = 0x7f4385;
        unaff_EBX = pCVar4;
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x2f8,pCVar4,(ulong)pCVar5);
        *(undefined4 *)pSVar3 = *(undefined4 *)pSVar2;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::M6GetBurnoutRadiusFromSpeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CSceneVehicleCarTuning::M6GetBurnoutRadiusFromSpeed
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1,float param_2)
{
{
  float unaff_retaddr;
  
  param_1 = (CSceneVehicleCarTuning *)((float)param_1 * (float)_DAT_00b3d2a8);
  CFuncKeysReal::GetValue
            (*(CFuncKeysReal **)(this + 0x25c),(CFuncColorGradient *)param_1,(float)&param_1);
  return unaff_retaddr;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::M6GetBurnoutRolloverFromSpeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CSceneVehicleCarTuning::M6GetBurnoutRolloverFromSpeed
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1,float param_2)
{
{
  float unaff_retaddr;
  
  param_1 = (CSceneVehicleCarTuning *)((float)param_1 * (float)_DAT_00b3d2a8);
  CFuncKeysReal::GetValue
            (*(CFuncKeysReal **)(this + 0x2a4),(CFuncColorGradient *)param_1,(float)&param_1);
  return unaff_retaddr;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::M6GetDonutRolloverFromSpeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CSceneVehicleCarTuning::M6GetDonutRolloverFromSpeed
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1,float param_2)
{
{
  float unaff_retaddr;
  
  param_1 = (CSceneVehicleCarTuning *)((float)param_1 * (float)_DAT_00b3d2a8);
  CFuncKeysReal::GetValue
            (*(CFuncKeysReal **)(this + 0x288),(CFuncColorGradient *)param_1,(float)&param_1);
  return unaff_retaddr;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::M6GetLateralSpeedFromBurnoutRadius
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CSceneVehicleCarTuning::M6GetLateralSpeedFromBurnoutRadius
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1,float param_2)
{
{
  float unaff_retaddr;
  
  CFuncKeysReal::GetValue
            (*(CFuncKeysReal **)(this + 0x260),(CFuncColorGradient *)param_1,(float)&param_1);
  return unaff_retaddr / (float)_DAT_00b3d2a8;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::M6GetModulationFromDamperAbsorbVal
// =================================================
float __thiscall
CSceneVehicleCarTuning::M6GetModulationFromDamperAbsorbVal
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1,float param_2)
{
{
  CFuncColorGradient *pCVar1;
  float unaff_retaddr;
  
  if (*(float *)(this + 0x120) == *(float *)(this + 0x11c)) {
    pCVar1 = (CFuncColorGradient *)0x0;
  }
  else {
    pCVar1 = (CFuncColorGradient *)
             (((float)param_1 - *(float *)(this + 0x120)) /
             (*(float *)(this + 0x11c) - *(float *)(this + 0x120)));
    param_1 = (CSceneVehicleCarTuning *)pCVar1;
  }
  CFuncKeysReal::GetValue(*(CFuncKeysReal **)(this + 0x224),pCVar1,(float)&param_1);
  return unaff_retaddr;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::M6GetRearGearAccelFromSpeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CSceneVehicleCarTuning::M6GetRearGearAccelFromSpeed
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1,float param_2)
{
{
  float unaff_retaddr;
  
  param_1 = (CSceneVehicleCarTuning *)((float)param_1 * (float)_DAT_00b3d2a8);
  CFuncKeysReal::GetValue
            (*(CFuncKeysReal **)(this + 0x230),(CFuncColorGradient *)param_1,(float)&param_1);
  return unaff_retaddr;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::M6GetRolloverLateralFromSpeedRatio
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CSceneVehicleCarTuning::M6GetRolloverLateralFromSpeedRatio
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1,float param_2)
{
{
  float unaff_retaddr;
  
  param_1 = (CSceneVehicleCarTuning *)((float)param_1 * (float)_DAT_00b3d2a8);
  CFuncKeysReal::GetValue
            (*(CFuncKeysReal **)(this + 0x250),(CFuncColorGradient *)param_1,(float)&param_1);
  return unaff_retaddr;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::M6InitRpmDelta
// =================================================
void __thiscall
CSceneVehicleCarTuning::M6InitRpmDelta(CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  CSceneVehicleCarTuning *this_00;
  float *pfVar2;
  float fVar3;
  SCasterCat *pSVar4;
  SCasterCat *pSVar5;
  SCasterCat *pSVar6;
  ulong unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  SCasterCat *in_stack_00000010;
  float *in_stack_00000014;
  float *in_stack_00000018;
  float *in_stack_0000001c;
  SCasterCat *in_stack_00000020;
  ulong in_stack_ffffffec;
  SCasterCat *pSVar8;
  ulong in_stack_fffffff4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffff8;
  ulong in_stack_fffffffc;
  
  pSVar4 = (SCasterCat *)CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2d4,unaff_EDI);
  this_00 = this + 0x304;
  pSVar8 = pSVar4;
  pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
  *(undefined4 *)pSVar5 = 0;
  pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,unaff_EBP);
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2;
  *(undefined4 *)pSVar5 = 0;
  if ((SCasterCat *)0x2 < pSVar4) {
    do {
      CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this + 0x2c4,pCVar7,unaff_EBX);
      pCVar1 = pCVar7 + -1;
      CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                (this + 0x2c4,pCVar1,in_stack_ffffffec);
      unaff_EBX = 0x7f41f7;
      CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this + 0x2f8,pCVar7,(ulong)pSVar8);
      in_stack_ffffffec = 0x7f4207;
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x2d4,pCVar1,in_stack_fffffff4);
      pSVar8 = (SCasterCat *)0x7f4213;
      pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar1,(ulong)in_stack_fffffff8);
      in_stack_fffffff4 = 0x7f421d;
      in_stack_fffffff8 = pCVar7;
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar7,in_stack_fffffffc);
      pCVar7 = pCVar7 + 1;
      pfVar2 = (float *)((*in_stack_00000014 - (float)in_stack_0000001c * *in_stack_00000018) *
                        *(float *)(this + 0x2d0));
      *(float *)pSVar6 = *(float *)pSVar5 * (float)in_stack_0000001c + (float)pfVar2;
      in_stack_00000010 = pSVar4;
      in_stack_0000001c = pfVar2;
    } while (pCVar7 < pSVar4);
  }
  pSVar4 = pSVar4 + -1;
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1;
  if ((SCasterCat *)0x1 < pSVar4) {
    do {
      if (*(float *)(this + 0x2d0) == 0.0) {
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x310,pCVar7,unaff_EBX);
        fVar3 = 0.0;
      }
      else {
        pCVar1 = pCVar7 + 1;
        CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this + 0x2e0,pCVar1,unaff_EBX);
        CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar1,in_stack_ffffffec);
        unaff_EBX = 0x7f42bd;
        CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this + 0x2c4,pCVar7,(ulong)pSVar8)
        ;
        in_stack_ffffffec = 0x7f42cd;
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x2c4,pCVar1,in_stack_fffffff4);
        pSVar8 = (SCasterCat *)0x7f42d7;
        CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                  (this_00,pCVar7,(ulong)in_stack_fffffff8);
        in_stack_fffffff4 = 0x7f42e7;
        in_stack_fffffff8 = pCVar7;
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x310,pCVar7,in_stack_fffffffc);
        fVar3 = *(float *)in_stack_00000010 / *(float *)(this + 0x2d0) +
                ((*in_stack_0000001c - *in_stack_00000018 / *(float *)(this + 0x2d0)) *
                *in_stack_00000014) / *(float *)pSVar4;
        pSVar4 = in_stack_00000020;
      }
      pCVar7 = pCVar7 + 1;
      *(float *)pSVar5 = fVar3;
    } while (pCVar7 < pSVar4);
  }
  return;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall
CSceneVehicleCarTuning::MwGetClassInfo(CSceneVehicleCarTuning *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d6d6a4;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::MwIsKindOf
// =================================================
int __thiscall
CSceneVehicleCarTuning::MwIsKindOf
          (CSceneVehicleCarTuning *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if ((param_1 != (CMwCmdAffectParam *)0xa029000) && (param_1 != (CMwCmdAffectParam *)0xa02e000)) {
    return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
  }
  return 1;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::MwNewCSceneVehicleCarTuning
// =================================================
CMwNod * __cdecl CSceneVehicleCarTuning::MwNewCSceneVehicleCarTuning(void)
{
{
  CSceneVehicleCarTuning *pCVar1;
  CMwNod *extraout_EAX;
  CSceneVehicleCarTuning *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00ad00ab;
  local_c = ExceptionList;
  pCVar1 = (CSceneVehicleCarTuning *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = operator_new(0x3ac);
  local_4 = 0;
  if (local_10 != (CSceneVehicleCarTuning *)0x0) {
    CSceneVehicleCarTuning(local_10,pCVar1);
    ExceptionList = local_8;
    return extraout_EAX;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::OnNodLoaded
// =================================================
void __thiscall
CSceneVehicleCarTuning::OnNodLoaded(CSceneVehicleCarTuning *this,CDx9DeviceCaps *param_1)
{
{
  CFastStringInt *unaff_ESI;
  
  OnAccessViolation_ConcatToCrashFileName(unaff_ESI);
  M6InitRpmDelta(this,(CSceneVehicleCarTuning *)param_1);
  return;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::VirtualParam_Get
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
CSceneVehicleCarTuning::VirtualParam_Get
          (CSceneVehicleCarTuning *this,CPlugBlendShapes *param_1,CMwStack *param_2,
          CMwValueStd *param_3)
{
{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  uVar3 = *(uint *)(iVar2 + 4);
  if (uVar3 < 0xa029097) {
    if (uVar3 == 0xa029096) {
      *(CMwStack **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 600) * (float)_DAT_00b3d2a8;
      return 0;
    }
    switch(uVar3) {
    case 0xa029000:
      *(CMwStack **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x2c) * (float)_DAT_00b3d2a8;
      return 0;
    case 0xa029001:
      *(CMwStack **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x30) * (float)_DAT_00b3d2a8;
      return 0;
    case 0xa02901d:
      *(CMwStack **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x74) * (float)_DAT_00b3d2a8;
      return 0;
    case 0xa02903c:
      *(CMwStack **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x208) * (float)_DAT_00b3d2a8;
      return 0;
    case 0xa02903d:
      *(CMwStack **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x20c) * (float)_DAT_00b3d2a8;
      return 0;
    case 0xa029066:
      *(CMwStack **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) =
           (*(float *)(this + 0xc4) * (float)_DAT_00b36ab8) / (float)_DAT_00b36110;
      return 0;
    case 0xa029067:
      *(CMwStack **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) =
           (*(float *)(this + 200) * (float)_DAT_00b36ab8) / (float)_DAT_00b36110;
      return 0;
    case 0xa029095:
      *(CMwStack **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x254) * (float)_DAT_00b3d2a8;
      return 0;
    }
  }
  else if (uVar3 < 0xa0290bd) {
    if (uVar3 == 0xa0290bc) {
      *(CMwStack **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x32c) * (float)_DAT_00b3d2a8;
      return 0;
    }
    if (uVar3 == 0xa029097) {
      *(CMwStack **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) =
           (*(float *)(this + 0x290) * (float)_DAT_00b36ab8) / (float)_DAT_00b36110;
      return 0;
    }
    if (uVar3 == 0xa029098) {
      *(CMwStack **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) =
           (*(float *)(this + 0x294) * (float)_DAT_00b36ab8) / (float)_DAT_00b36110;
      return 0;
    }
    if (uVar3 == 0xa02909c) {
      *(CMwStack **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x284) * (float)_DAT_00b3d2a8;
      return 0;
    }
  }
  else if (uVar3 < 0xa0290c0) {
    if (uVar3 == 0xa0290bf) {
      *(CMwStack **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x338) * (float)_DAT_00b3d2a8;
      return 0;
    }
    if (uVar3 == 0xa0290bd) {
      *(CMwStack **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x330) * (float)_DAT_00b3d2a8;
      return 0;
    }
    if (uVar3 == 0xa0290be) {
      *(CMwStack **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x334) * (float)_DAT_00b3d2a8;
      return 0;
    }
  }
  else if (uVar3 == 0xffffffff) {
    return 0;
  }
  *(int *)(param_1 + 0x18) = iVar1;
  uVar4 = CMwNod::VirtualParam_Get((CMwNod *)this,param_1,param_2,param_3);
  return uVar4;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::VirtualParam_Set
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
CSceneVehicleCarTuning::VirtualParam_Set
          (CSceneVehicleCarTuning *this,CSystemData *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  uint uVar3;
  CMwCmdAffectParamBool *pCVar4;
  ulong uVar5;
  CSceneVehicleCarTuning *unaff_ESI;
  void *unaff_EDI;
  CSceneVehicleCarTuning *unaff_retaddr;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  uVar3 = *(uint *)(iVar2 + 4);
  if (uVar3 < 0xa029099) {
    if (uVar3 == 0xa029098) {
      *(float *)(this + 0x294) = (*(float *)param_2 * (float)_DAT_00b36110) / (float)_DAT_00b36ab8;
      return 0;
    }
    switch(uVar3) {
    case 0xa029000:
      *(float *)(this + 0x2c) = *(float *)param_2 / (float)_DAT_00b3d2a8;
      return 0;
    case 0xa029001:
      *(float *)(this + 0x30) = *(float *)param_2 / (float)_DAT_00b3d2a8;
      return 0;
    case 0xa02901d:
      *(float *)(this + 0x74) = *(float *)param_2 / (float)_DAT_00b3d2a8;
      return 0;
    case 0xa02903c:
      *(float *)(this + 0x208) = *(float *)param_2 / (float)_DAT_00b3d2a8;
      return 0;
    case 0xa02903d:
      *(float *)(this + 0x20c) = *(float *)param_2 / (float)_DAT_00b3d2a8;
      return 0;
    case 0xa029066:
      *(float *)(this + 0xc4) = (*(float *)param_2 * (float)_DAT_00b36110) / (float)_DAT_00b36ab8;
      return 0;
    case 0xa029067:
      *(float *)(this + 200) = (*(float *)param_2 * (float)_DAT_00b36110) / (float)_DAT_00b36ab8;
      return 0;
    case 0xa029095:
      *(float *)(this + 0x254) = *(float *)param_2 / (float)_DAT_00b3d2a8;
      return 0;
    case 0xa029096:
      *(float *)(this + 600) = *(float *)param_2 / (float)_DAT_00b3d2a8;
      return 0;
    case 0xa029097:
      *(float *)(this + 0x290) = (*(float *)param_2 * (float)_DAT_00b36110) / (float)_DAT_00b36ab8;
      return 0;
    }
  }
  else {
    if (uVar3 < 0xa0290bd) {
      if (uVar3 == 0xa0290bc) {
        *(float *)(this + 0x32c) = *(float *)param_2 / (float)_DAT_00b3d2a8;
        return 0;
      }
      switch(uVar3) {
      case 0xa02909c:
        *(float *)(this + 0x284) = *(float *)param_2 / (float)_DAT_00b3d2a8;
        return 0;
      default:
        goto switchD_007f5b52_caseD_a029002;
      case 0xa0290b1:
        pCVar4 = (CMwCmdAffectParamBool *)(this + 0x2d4);
        break;
      case 0xa0290b2:
        pCVar4 = (CMwCmdAffectParamBool *)(this + 0x2e0);
        break;
      case 0xa0290b3:
        pCVar4 = (CMwCmdAffectParamBool *)(this + 0x2c4);
        break;
      case 0xa0290b4:
        CMwParamFastBuffer<class_CMwParamReal>::SetValue
                  ((CMwParamFastBuffer<class_CMwParamReal> *)param_1,
                   (CMwCmdAffectParamBool *)(this + 0x2f8));
        M6CheckRpmWantedConstistensy(this,unaff_ESI);
        M6InitRpmDelta(this,unaff_retaddr);
        return 0;
      }
      CMwParamFastBuffer<class_CMwParamReal>::SetValue
                ((CMwParamFastBuffer<class_CMwParamReal> *)param_1,pCVar4);
      M6InitRpmDelta(this,unaff_ESI);
      return 0;
    }
    if (uVar3 < 0xa0290c0) {
      if (uVar3 == 0xa0290bf) {
        *(float *)(this + 0x338) = *(float *)param_2 / (float)_DAT_00b3d2a8;
        return 0;
      }
      if (uVar3 == 0xa0290bd) {
        *(float *)(this + 0x330) = *(float *)param_2 / (float)_DAT_00b3d2a8;
        return 0;
      }
      if (uVar3 == 0xa0290be) {
        *(float *)(this + 0x334) = *(float *)param_2 / (float)_DAT_00b3d2a8;
        return 0;
      }
    }
    else if (uVar3 == 0xffffffff) {
      return 0;
    }
  }
switchD_007f5b52_caseD_a029002:
  *(int *)(param_1 + 0x18) = iVar1;
  uVar5 = CMwNod::VirtualParam_Set((CMwNod *)this,param_1,param_2,unaff_EDI);
  return uVar5;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::_scalar_deleting_destructor_
// =================================================
void * __thiscall
CSceneVehicleCarTuning::_scalar_deleting_destructor_
          (CSceneVehicleCarTuning *this,CPfmHeap *param_1,uint param_2)
{
{
  CSceneVehicleCarTuning *unaff_ESI;
  
  ~CSceneVehicleCarTuning(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CSceneVehicleCarTuning::~CSceneVehicleCarTuning
// =================================================
void __thiscall
CSceneVehicleCarTuning::~CSceneVehicleCarTuning
          (CSceneVehicleCarTuning *this,CSceneVehicleCarTuning *param_1)
{
{
  CMwNod *pCVar1;
  CMwNod *unaff_ESI;
  uint unaff_retaddr;
  uint uVar2;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar3;
  CMwNod *in_stack_00000008;
  void *in_stack_00000018;
  CSceneVehicleCarTuning *pCVar4;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar5;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar6;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar7;
  
  pCVar5 = ExceptionList;
  pCVar6 = (CFastBuffer<class_CPlugFileGPUV*> *)&LAB_00acfd91;
  pCVar1 = (CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &stack0xfffffff4;
  *(undefined ***)this = vftable;
  pCVar7 = (CFastBuffer<class_CPlugFileGPUV*> *)0x1f;
  pCVar4 = this;
  if (*(CMwNod **)(this + 0x380) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x380),pCVar1);
  }
  uVar2 = unaff_retaddr & 0xffffff00;
  if (*(CMwNod **)(this + 0x378) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x378),unaff_ESI);
  }
  pCVar3 = (CFastBuffer<class_CPlugFileGPUV*> *)CONCAT31((int3)(uVar2 >> 8),0x1d);
  if (*(CMwNod **)(this + 0x36c) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x36c),unaff_ESI);
  }
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (this + 0x310,(CFastBuffer<class_CPlugFileGPUV*> *)unaff_ESI);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (this + 0x304,(CFastBuffer<class_CPlugFileGPUV*> *)pCVar4);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this + 0x2f8,pCVar5);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this + 0x2e0,pCVar6);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this + 0x2d4,pCVar7);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this + 0x2c4,pCVar3);
  in_stack_00000018 = (void *)CONCAT31(in_stack_00000018._1_3_,0x16);
  if (*(CMwNod **)(this + 0x2a4) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x2a4),(CMwNod *)param_1);
  }
  if (*(CMwNod **)(this + 0x288) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x288),in_stack_00000008);
  }
  if (*(CMwNod **)(this + 0x260) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x260),in_stack_00000008);
  }
  if (*(CMwNod **)(this + 0x25c) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x25c),in_stack_00000008);
  }
  if (*(CMwNod **)(this + 0x250) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x250),in_stack_00000008);
  }
  if (*(CMwNod **)(this + 0x230) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x230),in_stack_00000008);
  }
  if (*(CMwNod **)(this + 0x224) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x224),in_stack_00000008);
  }
  if (*(CMwNod **)(this + 0x218) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x218),in_stack_00000008);
  }
  if (*(CMwNod **)(this + 0x214) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x214),in_stack_00000008);
  }
  if (*(CMwNod **)(this + 0x210) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x210),in_stack_00000008);
  }
  if (*(CMwNod **)(this + 0x1f0) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x1f0),in_stack_00000008);
  }
  if (*(CMwNod **)(this + 0x1ec) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x1ec),in_stack_00000008);
  }
  if (*(CMwNod **)(this + 0x1e0) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x1e0),in_stack_00000008);
  }
  if (*(CMwNod **)(this + 0x1c4) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x1c4),in_stack_00000008);
  }
  if (*(CMwNod **)(this + 0x1bc) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x1bc),in_stack_00000008);
  }
  if (*(CMwNod **)(this + 0x1b4) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x1b4),in_stack_00000008);
  }
  if (*(CMwNod **)(this + 0xbc) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0xbc),in_stack_00000008);
  }
  if (*(CMwNod **)(this + 0xb8) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0xb8),in_stack_00000008);
  }
  if (*(CMwNod **)(this + 0xac) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0xac),in_stack_00000008);
  }
  if (*(CMwNod **)(this + 0xa0) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0xa0),in_stack_00000008);
  }
  if (*(CMwNod **)(this + 0x78) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x78),in_stack_00000008);
  }
  if (*(CMwNod **)(this + 0x68) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x68),in_stack_00000008);
  }
  if (*(CMwNod **)(this + 0x34) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x34),in_stack_00000008);
  }
  CSceneVehicleTuning::~CSceneVehicleTuning
            ((CSceneVehicleTuning *)this,(CSceneVehicleTuning *)in_stack_00000008);
  ExceptionList = in_stack_00000018;
  return;
}
}

