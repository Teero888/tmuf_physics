// Class implementation: CPlugFileGpuBuilder

// =================================================
// Function: CPlugFileGpuBuilder::AddInOut
// =================================================
void __thiscall
CPlugFileGpuBuilder::AddInOut
          (CPlugFileGpuBuilder *this,CPlugFileGpuBuilder *param_1,EInOut param_2,EPlugVDcl param_3,
          char *param_4)
{
{
  CPlugFileGpuBuilder *pCVar1;
  SStringParam SVar2;
  SStringParam *pSVar3;
  
  pCVar1 = this + (int)param_1 * 0xb4 + 0x44;
  *(uint *)pCVar1 = *(uint *)pCVar1 | (&DAT_00d143d0)[param_2];
  if (param_3 == 0) {
    param_3 = (EPlugVDcl)(&PTR_s_Position_00d14218)[param_2];
  }
  pSVar3 = (SStringParam *)param_3;
  if ((SStringParam *)param_3 == (SStringParam *)0x0) {
    CFastString::SetString
              ((CFastString *)(pCVar1 + param_2 * 8 + 4),(CFastStringInt *)&stack0xfffffff8,
               (SStringParam *)0x0);
    return;
  }
  do {
    SVar2 = *pSVar3;
    pSVar3 = pSVar3 + 1;
  } while (SVar2 != (SStringParam)0x0);
  CFastString::SetString
            ((CFastString *)(pCVar1 + param_2 * 8 + 4),(CFastStringInt *)&stack0xfffffff8,
             (SStringParam *)param_3);
  return;
}
}

// =================================================
// Function: CPlugFileGpuBuilder::AddStr
// =================================================
void __thiscall
CPlugFileGpuBuilder::AddStr
          (CPlugFileGpuBuilder *this,CPlugFileGpuBuilder *param_1,CFastString *param_2)
{
{
  char cVar1;
  int iVar2;
  int iVar3;
  char *unaff_EDI;
  undefined4 *unaff_retaddr;
  SStringParam *pSVar4;
  SStringParam *pSVar5;
  SStringParam *pSVar6;
  CFastStringInt aCStack_4 [4];
  
  pSVar4 = (SStringParam *)0x9045000;
  iVar3 = (**(code **)(**(int **)(this + 8) + 0x10))();
  iVar2 = *(int *)(this + 4);
  if (iVar2 == 0) {
    CFastString::Concat((CFastString *)(this + 0x14),(CFastStringInt *)&stack0xfffffff4,pSVar4);
  }
  else if (((iVar2 != 1) && (iVar2 != 4)) && (iVar3 == 0)) {
    CFastString::Concat((CFastString *)(this + iVar2 * 8 + 0x14),(CFastStringInt *)&DAT_00000009,
                        pSVar4);
  }
  pSVar5 = (SStringParam *)unaff_retaddr[1];
  pSVar6 = (SStringParam *)*unaff_retaddr;
  CFastString::Concat((CFastString *)(this + *(int *)(this + 4) * 8 + 0x14),
                      (CFastStringInt *)&stack0xfffffff4,pSVar4);
  iVar2 = *(int *)(this + 4);
  if ((((iVar2 != 0) && (iVar2 != 1)) && (iVar3 == 0)) &&
     ((*(int *)(this + iVar2 * 8 + 0x14) == 0 ||
      ((cVar1 = *(char *)(*(int *)(this + iVar2 * 8 + 0x18) + -1 + *(int *)(this + iVar2 * 8 + 0x14)
                         ), cVar1 != '{' && (cVar1 != '}')))))) {
    SStringParam::SStringParam(&stack0xfffffff8,(SStringParam *)&DAT_00b2c994,unaff_EDI);
    CFastString::Concat((CFastString *)(this + *(int *)(this + 4) * 8 + 0x14),aCStack_4,pSVar5);
  }
  CFastString::Concat((CFastString *)(this + *(int *)(this + 4) * 8 + 0x14),
                      (CFastStringInt *)&stack0x00000000,pSVar6);
  return;
}
}

// =================================================
// Function: CPlugFileGpuBuilder::AddVersion
// =================================================
void __thiscall
CPlugFileGpuBuilder::AddVersion
          (CPlugFileGpuBuilder *this,CPlugFileGpuBuilder *param_1,char *param_2)
{
{
  int iVar1;
  CPlugFileGpuBuilder *unaff_ESI;
  char *unaff_retaddr;
  CPlugFileGpuBuilder *pCVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar4 = (char *)0x9074000;
  iVar1 = (**(code **)(**(int **)(this + 8) + 0x10))();
  if (iVar1 == 0) {
    iVar1 = (**(code **)(**(int **)(this + 8) + 0x10))(0x9077000);
    if (iVar1 == 0) {
      pcVar3 = (char *)&lpOutputString_00b2bcc4;
    }
    else {
      pcVar3 = " PS_OUTPUT psMain(const PS_INPUT p) {return Main(p);}\r\n";
    }
    pCVar2 = (CPlugFileGpuBuilder *)&DAT_00bb5338;
  }
  else {
    pcVar3 = " VS_OUTPUT vsMain(const VS_INPUT v) {return Main(v);}\r\n";
    pCVar2 = (CPlugFileGpuBuilder *)&DAT_00bb5ea8;
  }
  pCVar2 = CFastString::operator<<((CFastString *)(this + 0xc),pCVar2,unaff_retaddr);
  pCVar2 = CFastString::operator<<((CFastString *)pCVar2,(CPlugFileGpuBuilder *)pcVar3,pcVar4);
  CFastString::operator<<((CFastString *)pCVar2,unaff_ESI,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CPlugFileGpuBuilder::Build
// =================================================
void __thiscall
CPlugFileGpuBuilder::Build
          (CPlugFileGpuBuilder *this,NvStripInfo *param_1,
          vector<class_NvEdgeInfo*,class_std::allocator<class_NvEdgeInfo*>_> *param_2,
          vector<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_> *param_3)
{
{
  CPlugFileGpuBuilder *pCVar1;
  CPlugFileGpuBuilder *pCVar2;
  int iVar3;
  CPlugFileGpuBuilder *pCVar4;
  char *unaff_EBX;
  EInOut EVar5;
  int iVar6;
  ulong unaff_EBP;
  EPlugVDcl unaff_ESI;
  CFastStringBase<char> *this_00;
  EInOut unaff_EDI;
  char *pcVar7;
  char *in_stack_00000010;
  char *in_stack_00000014;
  char *in_stack_00000018;
  char *in_stack_0000001c;
  char *in_stack_00000020;
  char *in_stack_00000024;
  char *in_stack_00000028;
  SStringParam *pSVar8;
  SStringParam *pSVar9;
  char *in_stack_fffffff4;
  char *in_stack_fffffff8;
  char *pcVar10;
  
  this_00 = (CFastStringBase<char> *)(*(int *)(this + 8) + 0x14);
  EVar5 = 0;
  do {
    ConvertInOut(this,(CPlugFileGpuBuilder *)0x0,EVar5,unaff_EDI);
    unaff_EDI = EVar5;
    ConvertInOut(this,(CPlugFileGpuBuilder *)0x1,EVar5,unaff_ESI);
    EVar5 = EVar5 + 1;
  } while (EVar5 < 0x16);
  pCVar4 = this + 0x44;
  iVar6 = 2;
  do {
    *(undefined4 *)pCVar4 = 0;
    pCVar2 = pCVar4 + 4;
    iVar3 = 0x16;
    do {
      if (*(int *)pCVar2 != 0) {
        *(int *)pCVar2 = 0;
        **(undefined1 **)(pCVar2 + 4) = 0;
      }
      pCVar2 = pCVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    pCVar4 = pCVar4 + 0xb4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  pCVar4 = this + 0x34;
  pCVar2 = this + 0x24;
  pCVar1 = this + 0x3c;
  CFastStringBase<char>::PreAlloc
            (this_00,(CClassicBufferMemory *)
                     (*(int *)(this + 0x34) + *(int *)(this + 0x2c) + *(int *)(this + 0x14) +
                      *(int *)(this + 0x24) + *(int *)(this + 0x3c) + 0x400 + *(int *)(this + 0x1c))
             ,unaff_EBP);
  pSVar9 = (SStringParam *)0x9074000;
  iVar6 = (**(code **)(**(int **)(this + 8) + 0x10))();
  if (iVar6 != 0) {
    pcVar10 = *(char **)(this + 0x14);
    pcVar7 = *(char **)(this + 0x18);
    CFastString::SetString((CFastString *)this_00,(CFastStringInt *)&stack0x00000000,pSVar9);
    CFastString::operator<<((CFastString *)this_00,this + 0x1c,unaff_EBX);
    CFastString::operator<<
              ((CFastString *)this_00,
               (CPlugFileGpuBuilder *)"#include <Common.VHlsl.txt>\r\nstruct VS_INPUT {\r\n",
               in_stack_fffffff4);
    CFastString::operator<<((CFastString *)this_00,(CPlugFileGpuBuilder *)param_2,in_stack_fffffff8)
    ;
    CFastString::operator<<
              ((CFastString *)this_00,(CPlugFileGpuBuilder *)&DAT_00bb6000,(char *)pCVar2);
    CFastString::operator<<
              ((CFastString *)this_00,(CPlugFileGpuBuilder *)"struct VS_OUTPUT {\r\n",pcVar7);
    CFastString::operator<<((CFastString *)this_00,this + 0x2c,pcVar10);
    CFastString::operator<<
              ((CFastString *)this_00,(CPlugFileGpuBuilder *)&DAT_00bb6000,(char *)param_2);
    CFastString::operator<<((CFastString *)this_00,pCVar4,(char *)param_3);
    CFastString::operator<<
              ((CFastString *)this_00,(CPlugFileGpuBuilder *)"VS_OUTPUT Main(const VS_INPUT v)\r\n",
               in_stack_00000010);
    CFastString::operator<<
              ((CFastString *)this_00,(CPlugFileGpuBuilder *)&DAT_00bb5fc0,in_stack_00000014);
    CFastString::operator<<
              ((CFastString *)this_00,
               (CPlugFileGpuBuilder *)"\tVS_OUTPUT Output = (VS_OUTPUT)0;\r\n",in_stack_00000018);
    CFastString::operator<<((CFastString *)this_00,pCVar1,in_stack_0000001c);
    CFastString::operator<<
              ((CFastString *)this_00,(CPlugFileGpuBuilder *)"\treturn Output;\r\n",
               in_stack_00000020);
    CFastString::operator<<
              ((CFastString *)this_00,(CPlugFileGpuBuilder *)&DAT_00bb6000,in_stack_00000024);
    CFastString::operator<<((CFastString *)this_00,this + 0xc,in_stack_00000028);
    return;
  }
  pSVar8 = (SStringParam *)0x9077000;
  iVar6 = (**(code **)(**(int **)(this + 8) + 0x10))();
  if (iVar6 != 0) {
    pcVar10 = *(char **)(this + 0x18);
    pcVar7 = *(char **)(this + 0x14);
    CFastString::SetString((CFastString *)this_00,(CFastStringInt *)&stack0xfffffffc,pSVar8);
    CFastString::operator<<((CFastString *)this_00,this + 0x1c,(char *)pSVar9);
    CFastString::operator<<
              ((CFastString *)this_00,
               (CPlugFileGpuBuilder *)"#include <Common.PHlsl.txt>\r\nstruct PS_INPUT {\r\n",
               unaff_EBX);
    CFastString::operator<<((CFastString *)this_00,(CPlugFileGpuBuilder *)param_1,in_stack_fffffff4)
    ;
    CFastString::operator<<
              ((CFastString *)this_00,(CPlugFileGpuBuilder *)&DAT_00bb6000,in_stack_fffffff8);
    CFastString::operator<<
              ((CFastString *)this_00,(CPlugFileGpuBuilder *)"struct PS_OUTPUT {\r\n",pcVar10);
    CFastString::operator<<((CFastString *)this_00,this + 0x2c,pcVar7);
    CFastString::operator<<
              ((CFastString *)this_00,(CPlugFileGpuBuilder *)&DAT_00bb6000,(char *)param_1);
    CFastString::operator<<((CFastString *)this_00,pCVar4,(char *)param_2);
    CFastString::operator<<
              ((CFastString *)this_00,(CPlugFileGpuBuilder *)"PS_OUTPUT Main(const PS_INPUT v)\r\n",
               (char *)param_3);
    CFastString::operator<<
              ((CFastString *)this_00,(CPlugFileGpuBuilder *)&DAT_00bb5fc0,in_stack_00000010);
    CFastString::operator<<
              ((CFastString *)this_00,
               (CPlugFileGpuBuilder *)"\tPS_OUTPUT Output = (PS_OUTPUT)0;\r\n",in_stack_00000014);
    CFastString::operator<<((CFastString *)this_00,pCVar1,in_stack_00000018);
    CFastString::operator<<
              ((CFastString *)this_00,(CPlugFileGpuBuilder *)"\treturn Output;\r\n",
               in_stack_0000001c);
    CFastString::operator<<
              ((CFastString *)this_00,(CPlugFileGpuBuilder *)&DAT_00bb6000,in_stack_00000020);
    CFastString::operator<<((CFastString *)this_00,this + 0xc,in_stack_00000024);
    return;
  }
  CFastString::operator<<((CFastString *)this_00,this + 0xc,(char *)pSVar8);
  CFastString::operator<<((CFastString *)this_00,pCVar4,(char *)pSVar9);
  CFastString::operator<<
            ((CFastString *)this_00,(CPlugFileGpuBuilder *)&lpOutputString_00b2bcc4,unaff_EBX);
  CFastString::operator<<((CFastString *)this_00,(CPlugFileGpuBuilder *)param_1,in_stack_fffffff4);
  CFastString::operator<<
            ((CFastString *)this_00,(CPlugFileGpuBuilder *)&lpOutputString_00b2bcc4,
             in_stack_fffffff8);
  CFastString::operator<<((CFastString *)this_00,pCVar1,(char *)pCVar2);
  return;
}
}

// =================================================
// Function: CPlugFileGpuBuilder::CPlugFileGpuBuilder
// =================================================
void __thiscall
CPlugFileGpuBuilder::CPlugFileGpuBuilder(CPlugFileGpuBuilder *this,CPlugFileGpuBuilder *param_1)
{
{
  CPlugFileGpuBuilder *this_00;
  uint uVar1;
  CPlugFileGpuBuilder *pCVar2;
  ulong uVar3;
  code *pcVar4;
  void *pvVar5;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00ad9fd1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  uVar1 = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined **)(this + 0x10) = PTR_DAT_00bbf7d8;
  pcVar4 = CGameMasterServer::SLadderResult::SLadderResult;
  this_00 = this + 0x14;
  local_4 = 0;
  _eh_vector_constructor_iterator_
            (this_00,8,6,CGameMasterServer::SLadderResult::SLadderResult,
             CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity);
  pCVar2 = this + 0x44;
  uVar3 = 0xb4;
  _eh_vector_constructor_iterator_(pCVar2,0xb4,2,SInOut::SInOut,SInOut::~SInOut);
  pvVar5 = (void *)CONCAT31((int3)((uint)pcVar4 >> 8),2);
  do {
    CFastStringBase<char>::PreAlloc
              ((CFastStringBase<char> *)this_00,
               (CClassicBufferMemory *)((-(uint)(uVar1 != 5) & 0xffffc400) + 0x4000),(ulong)pCVar2);
    uVar1 = uVar1 + 1;
    this_00 = this_00 + 8;
  } while (uVar1 < 6);
  CFastStringBase<char>::PreAlloc
            ((CFastStringBase<char> *)(this + 0xc),(CClassicBufferMemory *)&DAT_00000400,uVar3);
  ExceptionList = pvVar5;
  return;
}
}

// =================================================
// Function: CPlugFileGpuBuilder::ConvertInOut
// =================================================
void __thiscall
CPlugFileGpuBuilder::ConvertInOut
          (CPlugFileGpuBuilder *this,CPlugFileGpuBuilder *param_1,EInOut param_2,EPlugVDcl param_3)
{
{
  uint uVar1;
  EInOut EVar2;
  int iVar3;
  void *pvVar4;
  char *unaff_EBX;
  char *unaff_EBP;
  void *in_stack_00000010;
  int in_stack_0000001c;
  char *pcVar5;
  CFastString *pCVar6;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  EVar2 = param_2;
  local_8 = &LAB_00ad9f18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar3 = (int)param_1 * 0xb4;
  uVar1 = *(uint *)(this + iVar3 + 0x44);
  if ((((&DAT_00d14378)[param_2] & uVar1) != 0) &&
     ((((*(int *)(&DAT_00d14320 + param_2 * 4) == 0 || (*(int *)(&DAT_00d14320 + param_2 * 4) == 1))
       || (7 < param_2 - 10)) ||
      (((uVar1 >> ((char)param_2 * '\x02' - 0x14U & 0x1f)) >> 0xb & 3) != 0)))) {
    pcVar5 = (char *)0x0;
    local_4 = 0;
    pCVar6 = (CFastString *)PTR_DAT_00bbf7d8;
    CFastStringBase<char>::PreAlloc
              ((CFastStringBase<char> *)&stack0xffffffec,(CClassicBufferMemory *)0x100,
               DAT_00cca150 ^ (uint)&stack0xffffffdc);
    CFastString::Format((CFastString *)&stack0xfffffff0,(CFastString *)&stack0xfffffff0,"float%d ");
    CFastString::operator<<((CFastString *)&local_8,this + iVar3 + 0x44 + EVar2 * 8 + 4,unaff_EBP);
    CFastString::operator<<((CFastString *)&local_4,(CPlugFileGpuBuilder *)&DAT_00b626e8,unaff_EBX);
    CFastString::operator<<
              ((CFastString *)&stack0x00000000,
               (CPlugFileGpuBuilder *)(&PTR_s_POSITION0_00d14270)[EVar2],pcVar5);
    if (in_stack_0000001c == 0) {
      *(undefined4 *)(this + 4) = 2;
    }
    else {
      *(undefined4 *)(this + 4) = 3;
    }
    AddStr(this,(CPlugFileGpuBuilder *)&param_1,pCVar6);
    if ((undefined *)param_3 != PTR_DAT_00bbf7d8) {
      pvVar4 = (void *)(param_3 - 1);
      if ((*(byte *)(param_3 - 1) & 0x80) != 0) {
        pvVar4 = (void *)(param_3 - 4);
      }
      operator_delete__(pvVar4);
    }
  }
  ExceptionList = in_stack_00000010;
  return;
}
}

// =================================================
// Function: CPlugFileGpuBuilder::Reset
// =================================================
void __thiscall CPlugFileGpuBuilder::Reset(CPlugFileGpuBuilder *this,GmFrustumIso4 *param_1)
{
{
  CPlugFileGpuBuilder *pCVar1;
  int iVar2;
  CPlugFileGpuBuilder *pCVar3;
  int iVar4;
  char *unaff_EDI;
  CPlugFileGpuBuilder *in_stack_00000008;
  
  *(undefined4 *)(this + 4) = 6;
  *(GmFrustumIso4 **)(this + 8) = param_1;
  if (*(int *)(this + 0xc) != 0) {
    *(undefined4 *)(this + 0xc) = 0;
    **(undefined1 **)(this + 0x10) = 0;
  }
  AddVersion(this,in_stack_00000008,unaff_EDI);
  if (*(int *)(this + 0x14) != 0) {
    *(undefined4 *)(this + 0x14) = 0;
    **(undefined1 **)(this + 0x18) = 0;
  }
  if (*(int *)(this + 0x1c) != 0) {
    *(undefined4 *)(this + 0x1c) = 0;
    **(undefined1 **)(this + 0x20) = 0;
  }
  if (*(int *)(this + 0x24) != 0) {
    *(undefined4 *)(this + 0x24) = 0;
    **(undefined1 **)(this + 0x28) = 0;
  }
  if (*(int *)(this + 0x2c) != 0) {
    *(undefined4 *)(this + 0x2c) = 0;
    **(undefined1 **)(this + 0x30) = 0;
  }
  if (*(int *)(this + 0x34) != 0) {
    *(undefined4 *)(this + 0x34) = 0;
    **(undefined1 **)(this + 0x38) = 0;
  }
  if (*(int *)(this + 0x3c) != 0) {
    *(undefined4 *)(this + 0x3c) = 0;
    **(undefined1 **)(this + 0x40) = 0;
  }
  pCVar3 = this + 0x44;
  iVar4 = 2;
  do {
    *(undefined4 *)pCVar3 = 0;
    pCVar1 = pCVar3 + 4;
    iVar2 = 0x16;
    do {
      if (*(int *)pCVar1 != 0) {
        *(int *)pCVar1 = 0;
        **(undefined1 **)(pCVar1 + 4) = 0;
      }
      pCVar1 = pCVar1 + 8;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    pCVar3 = pCVar3 + 0xb4;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}
}

// =================================================
// Function: CPlugFileGpuBuilder::operator<<
// =================================================
CPlugFileGpuBuilder * __thiscall
CPlugFileGpuBuilder::operator<<
          (CPlugFileGpuBuilder *this,CPlugFileGpuBuilder *param_1,char *param_2)
{
{
  undefined1 *puVar1;
  CFastString *unaff_ESI;
  CFastString local_14 [4];
  CPlugFileGpuBuilder local_10 [4];
  void *local_c;
  undefined1 *local_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  local_8 = &LAB_00acd888;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastString::CFastString
            (local_14,(CFastString *)param_1,(char *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  AddStr(this,local_10,unaff_ESI);
  if (local_8 != PTR_DAT_00bbf7d8) {
    puVar1 = local_8 + -1;
    if ((local_8[-1] & 0x80) != 0) {
      puVar1 = local_8 + -4;
    }
    operator_delete__(puVar1);
  }
  ExceptionList = local_4;
  return this;
}
}

// =================================================
// Function: CPlugFileGpuBuilder::~CPlugFileGpuBuilder
// =================================================
void __thiscall
CPlugFileGpuBuilder::~CPlugFileGpuBuilder(CPlugFileGpuBuilder *this,CPlugFileGpuBuilder *param_1)
{
{
  undefined *puVar1;
  undefined *puVar2;
  code *pcVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00ad9f86;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 1;
  _eh_vector_destructor_iterator_(this + 0x44,0xb4,2,SInOut::~SInOut);
  pcVar3 = CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity;
  _eh_vector_destructor_iterator_
            (this + 0x14,8,6,CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity);
  puVar1 = *(undefined **)(this + 0x10);
  if (puVar1 != PTR_DAT_00bbf7d8) {
    puVar2 = puVar1 + -1;
    if ((puVar1[-1] & 0x80) != 0) {
      puVar2 = puVar1 + -4;
    }
    operator_delete__(puVar2);
    *(undefined4 *)(this + 0xc) = 0;
    *(undefined **)(this + 0x10) = PTR_DAT_00bbf7d8;
  }
  ExceptionList = pcVar3;
  return;
}
}

