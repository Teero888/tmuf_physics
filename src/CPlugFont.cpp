// Class implementation: CPlugFont

// =================================================
// Function: CPlugFont::GetLength
// =================================================
float __thiscall CPlugFont::GetLength(CPlugFont *this,CPlugFileSnd *param_1)
{
{
  CPlugVisualSprite *unaff_ESI;
  float fVar1;
  CPlugFileSnd *in_stack_00000010;
  
  SCharStyle::Init(&DAT_00d6e8fc,(CLoadGeomDynaSprite *)&stack0xfffffff0,unaff_ESI,
                   (CVisionViewportDx9 *)0x3f800000,(ESpriteColor0 *)0x3f800000);
  fVar1 = GetLength(this,in_stack_00000010);
  return fVar1;
}
}

// =================================================
// Function: CPlugFont::GetPureString
// =================================================
void __cdecl CPlugFont::GetPureString(CFastStringInt *param_1,CFastStringInt *param_2)
{
{
  SCharStyle *unaff_ESI;
  ulong unaff_EDI;
  SCharStyle *pSVar1;
  CClassicBufferMemory *pCVar2;
  CPlugVisualSprite *in_stack_ffffffbc;
  CVisionViewportDx9 *in_stack_ffffffc0;
  ESpriteColor0 *in_stack_ffffffc4;
  CFastStringInt *pCVar3;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_28 [16];
  SCharStyle local_18 [12];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad5218;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)param_2 != 0) {
    CFastStringBase<wchar_t>::AllocAtLeast
              (param_2,(CFastStringBase<wchar_t> *)0x0,1,0,
               (SOldChars *)(DAT_00cca150 ^ (uint)&stack0xffffffb4));
    **(undefined2 **)(param_2 + 4) = 0;
    *(undefined4 *)param_2 = 0;
  }
  pCVar2 = *(CClassicBufferMemory **)param_2;
  if (pCVar2 != (CClassicBufferMemory *)0x0) {
    pSVar1 = (SCharStyle *)0x851eaf;
    CFastStringBase<wchar_t>::PreAlloc(param_2,pCVar2,unaff_EDI);
    SCharStyle::SCharStyle(&local_2c,unaff_ESI);
    pCVar3 = (CFastStringInt *)0x3f800000;
    local_34 = 0x3f800000;
    local_30 = 0x3f800000;
    local_2c = 0x3f800000;
    SCharStyle::Init(local_28,(CLoadGeomDynaSprite *)&stack0xffffffc8,in_stack_ffffffbc,
                     in_stack_ffffffc0,in_stack_ffffffc4);
    CFastStringInt::ReadCharsStart(param_2,pCVar3);
    pCVar3 = (CFastStringInt *)ReadNextChar(param_2,local_18);
    while (pCVar3 != (CFastStringInt *)0x0) {
      CFastStringInt::Concat(param_2,pCVar3,(SStringParam *)pSVar1);
      pSVar1 = (SCharStyle *)&local_34;
      pCVar3 = (CFastStringInt *)ReadNextChar(param_2,pSVar1);
    }
    SCharStyle::~SCharStyle(&local_34,(SCharStyle *)pCVar2);
  }
  ExceptionList = puStack_8;
  return;
}
}

// =================================================
// Function: CPlugFont::ReadNextChar
// =================================================
ulong __cdecl CPlugFont::ReadNextChar(CFastStringInt *param_1,SCharStyle *param_2)
{
{
  bool bVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  CFastStringInt *unaff_EDI;
  CFastStringInt *pCVar7;
  ulong *in_stack_ffffffe4;
  CFastStringInt *pCVar8;
  
switchD_00851b46_caseD_25:
  do {
    pCVar8 = (CFastStringInt *)(param_2 + 0x18);
    if (*(int *)(param_2 + 0x18) == 0) {
      uVar2 = CFastStringInt::ReadCharsStart(param_1,unaff_EDI);
      *(ulong *)pCVar8 = uVar2;
    }
    uVar2 = CFastStringInt::ReadCharsNext(param_1,pCVar8,(ulong *)unaff_EDI);
  } while (uVar2 == 0xd);
  uVar6 = *(uint *)(param_2 + 0x10);
  bVar1 = true;
  uVar5 = uVar6 >> 7 & 1;
  if (uVar5 == 0) {
    *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 1;
LAB_00851acf:
    bVar1 = false;
  }
  else if ((uVar6 & 0x100) == 0) goto LAB_00851acf;
  *(uint *)(param_2 + 0x10) = uVar6 & 0xfffffeff;
  if (uVar5 == 0) {
    *(uint *)(param_2 + 0x10) = uVar6 & 0xffffeeff;
  }
  else {
    if ((bVar1) && (uVar2 == 0x5b)) {
      *(uint *)(param_2 + 0x10) = uVar6 & 0xfffffeff | 0x1000;
      return 0x5b;
    }
    if (uVar2 == 0x5d) {
      if ((uVar6 & 0x1000) == 0) {
        return 0x5d;
      }
      *(uint *)(param_2 + 0x10) = uVar6 & 0xffffeeff;
      goto switchD_00851b46_caseD_25;
    }
  }
  if (uVar2 == 0x24) {
LAB_00851b20:
    pCVar7 = (CFastStringInt *)(param_2 + 0x18);
    uVar2 = CFastStringInt::ReadCharsNext(param_1,pCVar7,in_stack_ffffffe4);
    if (uVar2 != 0) {
      switch(uVar2) {
      case 0x24:
      case 0x5b:
      case 0x5d:
        goto switchD_00851b46_caseD_24;
      case 0x30:
      case 0x31:
      case 0x32:
      case 0x33:
      case 0x34:
      case 0x35:
      case 0x36:
      case 0x37:
      case 0x38:
      case 0x39:
      case 0x41:
      case 0x42:
      case 0x43:
      case 0x44:
      case 0x45:
      case 0x46:
      case 0x61:
      case 0x62:
      case 99:
      case 100:
      case 0x65:
      case 0x66:
        uVar5 = 0;
        uVar6 = 0;
LAB_00851b51:
        if (2 < uVar6) {
          GxColor::SetFromBGRA
                    (param_2,(GmVec3 *)(uVar5 | 0xff000000),(uchar *)pCVar7,(ulong)in_stack_ffffffe4
                    );
          break;
        }
        if (uVar6 != 0) {
          uVar2 = CFastStringInt::ReadCharsNext
                            (param_1,(CFastStringInt *)(param_2 + 0x18),(ulong *)pCVar7);
          if (uVar2 == 0) goto LAB_00851da3;
          if (uVar2 == 0x24) goto LAB_00851b20;
        }
        if ((uVar2 < 0x30) || (0x39 < uVar2)) {
          if ((uVar2 < 0x61) || (0x66 < uVar2)) {
            if ((uVar2 < 0x41) || (0x46 < uVar2)) {
              uVar5 = uVar5 << 8;
              uVar6 = uVar6 + 1;
            }
            else {
              uVar5 = (uVar5 << 4 | uVar2 - 0x37) << 4 | uVar2 - 0x37;
              uVar6 = uVar6 + 1;
            }
          }
          else {
            uVar5 = (uVar5 << 4 | uVar2 - 0x57) << 4 | uVar2 - 0x57;
            uVar6 = uVar6 + 1;
          }
        }
        else {
          uVar5 = (uVar5 << 4 | uVar2 - 0x30) << 4 | uVar2 - 0x30;
          uVar6 = uVar6 + 1;
        }
        goto LAB_00851b51;
      case 0x3c:
        in_stack_ffffffe4 = (ulong *)0x851cf9;
        SCharStyle::Push(param_2,(CFastBufferWheel<float> *)unaff_EDI,(float *)pCVar8);
        break;
      case 0x3e:
        in_stack_ffffffe4 = (ulong *)0x851d05;
        SCharStyle::Pop(param_2,(SCharStyle *)unaff_EDI);
        break;
      case 0x47:
      case 0x67:
        uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount
                          (param_2 + 0x1c,(CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
        in_stack_ffffffe4 = (ulong *)0x851c08;
        pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                           (param_2 + 0x1c,
                            (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar2 - 1),
                            (ulong)pCVar8);
        *(undefined4 *)param_2 = *(undefined4 *)pSVar3;
        *(undefined4 *)(param_2 + 4) = *(undefined4 *)(pSVar3 + 4);
        *(undefined4 *)(param_2 + 8) = *(undefined4 *)(pSVar3 + 8);
        *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(pSVar3 + 0xc);
        break;
      case 0x48:
      case 0x4c:
      case 0x50:
      case 0x68:
      case 0x6c:
      case 0x70:
        uVar6 = *(uint *)(param_2 + 0x10);
        if ((char)uVar6 < '\0') {
          *(uint *)(param_2 + 0x10) = uVar6 & 0xffffff7f;
        }
        else {
          uVar6 = uVar6 | 0x180;
          *(uint *)(param_2 + 0x10) = uVar6;
          if ((uVar2 == 0x68) || (uVar2 == 0x70)) {
            iVar4 = 1;
          }
          else if ((uVar2 == 0x48) || (uVar2 == 0x50)) {
            iVar4 = 2;
          }
          else {
            iVar4 = 0;
          }
          uVar6 = (iVar4 << 9 ^ uVar6) & 0x600 ^ uVar6;
          *(uint *)(param_2 + 0x10) = uVar6;
          if ((uVar2 == 0x70) || (uVar2 == 0x50)) {
            *(uint *)(param_2 + 0x10) = (uVar6 ^ 0x800) & 0x800 ^ uVar6;
          }
          else {
            *(uint *)(param_2 + 0x10) = uVar6 & 0x800 ^ uVar6;
          }
        }
        break;
      case 0x49:
      case 0x69:
        *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) ^ 1;
        break;
      case 0x4d:
      case 0x6d:
        *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) & 0xffffffdf | 0x10;
        break;
      case 0x4e:
      case 0x6e:
        *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) & 0xffffffcf;
        break;
      case 0x4f:
      case 0x6f:
        *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) ^ 2;
        break;
      case 0x53:
      case 0x73:
        *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) ^ 4;
        break;
      case 0x54:
      case 0x74:
        *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) ^ 0x40;
        break;
      case 0x55:
      case 0x75:
        *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) ^ 8;
        break;
      case 0x57:
      case 0x77:
        *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) & 0xffffffef | 0x20;
        break;
      case 0x5a:
      case 0x7a:
        uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount
                          (param_2 + 0x1c,(CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
        in_stack_ffffffe4 = (ulong *)0x851cd1;
        pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                           (param_2 + 0x1c,
                            (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar2 - 1),
                            (ulong)pCVar8);
        *(undefined4 *)param_2 = *(undefined4 *)pSVar3;
        *(undefined4 *)(param_2 + 4) = *(undefined4 *)(pSVar3 + 4);
        *(undefined4 *)(param_2 + 8) = *(undefined4 *)(pSVar3 + 8);
        *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(pSVar3 + 0xc);
        *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(pSVar3 + 0x10);
      }
      goto switchD_00851b46_caseD_25;
    }
LAB_00851da3:
    uVar2 = 0;
  }
switchD_00851b46_caseD_24:
  return uVar2;
}
}

