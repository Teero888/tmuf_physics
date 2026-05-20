// Class implementation: TiXmlDocument

// =================================================
// Function: TiXmlDocument::LoadFile_Gbx
// =================================================
bool __thiscall
TiXmlDocument::LoadFile_Gbx
          (TiXmlDocument *this,TiXmlDocument *param_1,CClassicBuffer *param_2,TiXmlEncoding param_3)
{
{
  CClassicBuffer CVar1;
  TiXmlString TVar2;
  int *piVar3;
  TiXmlNode *pTVar4;
  vector<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_> *pvVar5;
  CClassicBuffer *pCVar6;
  int iVar7;
  void *this_00;
  CClassicBuffer *pCVar8;
  TiXmlString *pTVar9;
  CFastStringInt *pCVar10;
  TiXmlString *pTVar11;
  TiXmlString *pTVar12;
  TiXmlDocument *pTVar13;
  char *in_stack_ffffffd0;
  CFastString *pCVar14;
  TiXmlString *pTVar15;
  undefined4 *puVar16;
  uint uVar17;
  undefined1 auStack_14 [4];
  int iStack_10;
  undefined4 *local_c;
  int *piStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  piStack_8 = (int *)&LAB_00ae2378;
  local_c = ExceptionList;
  pTVar4 = (TiXmlNode *)(DAT_00cca150 ^ (uint)&stack0xffffffdc);
  ExceptionList = &local_c;
  if ((param_1 == (TiXmlDocument *)0x0) || (((byte)param_1[4] & 1) == 0)) {
    pTVar15 = (TiXmlString *)0x0;
    in_stack_ffffffd0 = (char *)0x0;
    pTVar13 = (TiXmlDocument *)0x2;
  }
  else {
    pTVar15 = (TiXmlString *)0x91c8c4;
    TiXmlNode::Clear((TiXmlNode *)this,pTVar4);
    *(undefined4 *)(this + 8) = 0xffffffff;
    *(undefined4 *)(this + 4) = 0xffffffff;
    pTVar4 = (TiXmlNode *)0x91c8d6;
    pvVar5 = (vector<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_> *)
             (**(code **)(*(int *)param_1 + 0x18))();
    if (pvVar5 != (vector<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_> *)0x0) {
      local_c = (undefined4 *)0x0;
      TiXmlString::reserve(&stack0xffffffe8,pvVar5,(uint)in_stack_ffffffd0);
      pCVar6 = operator_new__((uint)(pvVar5 + 1));
      *pCVar6 = (CClassicBuffer)0x0;
      iVar7 = CClassicBuffer::ReadAll((CClassicBuffer *)param_1,pCVar6,pvVar5,(ulong)pTVar15);
      if (iVar7 == 0) {
        operator_delete__(pCVar6);
        pTVar13 = (TiXmlDocument *)0x2;
LAB_0091c932:
        SetError(this,pTVar13,0,(char *)0x0,(TiXmlParsingData *)0x0,(TiXmlEncoding)pTVar4);
      }
      else {
        iVar7 = 0;
        pCVar8 = pCVar6;
        if (0 < (int)pvVar5) {
          do {
            CVar1 = *pCVar8;
            if (CVar1 == (CClassicBuffer)0x0) break;
            if ((byte)CVar1 < 0x20) {
              if (((CVar1 != (CClassicBuffer)0x9) && (CVar1 != (CClassicBuffer)0xa)) &&
                 (CVar1 != (CClassicBuffer)0xd)) goto LAB_0091c9c7;
            }
            else if (CVar1 == (CClassicBuffer)0x7f) {
LAB_0091c9c7:
              operator_delete__(pCVar6);
              pTVar13 = (TiXmlDocument *)&DAT_0000000a;
              goto LAB_0091c932;
            }
            iVar7 = iVar7 + 1;
            pCVar8 = pCVar8 + 1;
          } while (iVar7 < (int)pvVar5);
        }
        pvVar5[(int)pCVar6] =
             (vector<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_>)0x0;
        TVar2 = *(TiXmlString *)pCVar6;
        pTVar11 = (TiXmlString *)pCVar6;
        pTVar12 = (TiXmlString *)pCVar6;
        while (TVar2 != (TiXmlString)0x0) {
          if (*pTVar12 == (TiXmlString)0xa) {
            pTVar15 = pTVar12 + (1 - (int)pTVar11);
            TiXmlString::append(&iStack_10,pTVar11,(char *)pTVar15,(uint)pTVar4);
LAB_0091c9b1:
            pTVar11 = pTVar12 + 1;
            pTVar12 = pTVar11;
          }
          else if (*pTVar12 == (TiXmlString)0xd) {
            pTVar9 = pTVar12 + -(int)pTVar11;
            if (0 < (int)pTVar9) {
              TiXmlString::append(&iStack_10,pTVar11,(char *)pTVar9,(uint)pTVar4);
              pTVar15 = pTVar9;
            }
            TiXmlString::append(auStack_14,(TiXmlString *)&stack0xffffffe8,(char *)0x1,(uint)pTVar15
                               );
            if (pTVar12[1] != (TiXmlString)0xa) goto LAB_0091c9b1;
            pTVar11 = pTVar12 + 2;
            pTVar12 = pTVar11;
          }
          else {
            pTVar12 = pTVar12 + 1;
          }
          TVar2 = *pTVar12;
        }
        if (pTVar12 + -(int)pTVar11 != (TiXmlString *)0x0) {
          TiXmlString::append(&iStack_10,pTVar11,(char *)(pTVar12 + -(int)pTVar11),(uint)pTVar4);
        }
        operator_delete__(pCVar6);
        pCVar10 = (CFastStringInt *)(iStack_10 + 8);
        (**(code **)(*(int *)this + 8))(pCVar10,0,param_2);
        piVar3 = piStack_8;
        iVar7 = (**(code **)(*piStack_8 + 0x24))();
        if (iVar7 != 0) {
          uVar17 = 0;
          puVar16 = &DAT_00d71ca4;
          pCVar14 = (CFastString *)0x91ca74;
          this_00 = (void *)(**(code **)(*piVar3 + 0x24))();
          CFastStringInt::GetUtf8(this_00,pCVar10,pCVar14,(int)puVar16);
          pTVar15 = DAT_00d71ca8;
          do {
            TVar2 = *pTVar15;
            pTVar15 = pTVar15 + 1;
          } while (TVar2 != (TiXmlString)0x0);
          TiXmlString::assign(this + 0x20,DAT_00d71ca8,(char *)(pTVar15 + -(int)(DAT_00d71ca8 + 1)),
                              uVar17);
        }
        if (this[0x2c] == (TiXmlDocument)0x0) {
          if (local_c != &DAT_00d72f38) {
            operator_delete__(local_c);
          }
          ExceptionList = piStack_8;
          return true;
        }
      }
      if (local_c == &DAT_00d72f38) {
        ExceptionList = piStack_8;
        return false;
      }
      operator_delete__(local_c);
      ExceptionList = piStack_8;
      return false;
    }
    pTVar13 = (TiXmlDocument *)&DAT_0000000d;
  }
  SetError(this,pTVar13,0,in_stack_ffffffd0,(TiXmlParsingData *)pTVar15,(TiXmlEncoding)pTVar4);
  ExceptionList = piStack_8;
  return false;
}
}

// =================================================
// Function: TiXmlDocument::Parse
// =================================================
char * __thiscall
TiXmlDocument::Parse
          (TiXmlDocument *this,TiXmlDeclaration *param_1,char *param_2,TiXmlParsingData *param_3,
          TiXmlEncoding param_4)
{
{
  bool bVar1;
  TiXmlNode *pTVar2;
  TiXmlNode *pTVar3;
  char *pcVar4;
  int iVar5;
  TiXmlParsingData *unaff_EBX;
  TiXmlEncoding unaff_EBP;
  uint unaff_ESI;
  char *pcVar6;
  TiXmlNode *pTVar7;
  undefined4 local_8;
  char *local_4;
  
  this[0x2c] = (TiXmlDocument)0x0;
  *(undefined4 *)(this + 0x30) = 0;
  TiXmlString::assign(this + 0x34,(TiXmlString *)&DAT_00b2c878,(char *)0x0,unaff_ESI);
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
    SetError(this,(TiXmlDocument *)&DAT_0000000d,0,(char *)0x0,(TiXmlParsingData *)0x0,unaff_EBP);
    return (char *)0x0;
  }
  *(undefined4 *)(this + 8) = 0xffffffff;
  *(undefined4 *)(this + 4) = 0xffffffff;
  if (param_3 == (TiXmlParsingData *)0x0) {
    *(undefined4 *)(this + 4) = 0;
    *(undefined4 *)(this + 8) = 0;
  }
  else {
    *(undefined4 *)(this + 4) = *(undefined4 *)param_3;
    *(undefined4 *)(this + 8) = *(undefined4 *)(param_3 + 4);
  }
  local_8 = *(undefined4 *)(this + 8);
  local_4 = param_2;
  *(undefined4 *)(this + 4) = *(undefined4 *)(this + 4);
  *(undefined4 *)(this + 8) = local_8;
  if (((((param_4 == 0) && (*param_2 != '\0')) && (*param_2 == -0x11)) &&
      ((param_2[1] != '\0' && (param_2[1] == -0x45)))) &&
     ((param_2[2] != '\0' && (param_2[2] == -0x41)))) {
    param_4 = 1;
    this[0x44] = (TiXmlDocument)0x1;
  }
  pTVar2 = (TiXmlNode *)TiXmlBase::SkipWhiteSpace(param_2,param_4);
  if (pTVar2 == (TiXmlNode *)0x0) {
    param_4 = 0;
  }
  else {
    do {
      if ((*pTVar2 == (TiXmlNode)0x0) ||
         (pTVar3 = TiXmlNode::Identify((TiXmlNode *)this,pTVar2,(char *)param_4,
                                       (TiXmlEncoding)unaff_EBX), pTVar3 == (TiXmlNode *)0x0))
      break;
      pTVar7 = (TiXmlNode *)&local_8;
      unaff_EBX = (TiXmlParsingData *)param_4;
      pcVar4 = (char *)(**(code **)(*(int *)pTVar3 + 8))(pTVar2);
      TiXmlNode::LinkEndChild((TiXmlNode *)this,pTVar3,pTVar7);
      if (((TiXmlParsingData *)param_4 == (TiXmlParsingData *)0x0) &&
         (iVar5 = (**(code **)(*(int *)pTVar3 + 0x34))(), iVar5 != 0)) {
        iVar5 = (**(code **)(*(int *)pTVar3 + 0x34))();
        pcVar6 = (char *)(*(int *)(iVar5 + 0x30) + 8);
        if (*pcVar6 == '\0') {
          param_4 = 1;
        }
        else {
          bVar1 = TiXmlBase::StringEqual(pcVar6,"UTF-8",true,0);
          if (bVar1) {
            param_4 = 1;
          }
          else {
            bVar1 = TiXmlBase::StringEqual(pcVar6,"UTF8",true,0);
            param_4 = 2 - (uint)bVar1;
          }
        }
      }
      pTVar2 = (TiXmlNode *)TiXmlBase::SkipWhiteSpace(pcVar4,param_4);
    } while (pTVar2 != (TiXmlNode *)0x0);
    if (*(int *)(this + 0x18) != 0) {
      return (char *)pTVar2;
    }
  }
  SetError(this,(TiXmlDocument *)&DAT_0000000d,0,(char *)0x0,(TiXmlParsingData *)param_4,
           (TiXmlEncoding)unaff_EBX);
  return (char *)0x0;
}
}

// =================================================
// Function: TiXmlDocument::SaveFile_Gbx
// =================================================
bool __thiscall
TiXmlDocument::SaveFile_Gbx(TiXmlDocument *this,TiXmlDocument *param_1,CClassicBuffer *param_2)
{
{
  TiXmlDocument *this_00;
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  ulong unaff_ESI;
  ulong unaff_EDI;
  void *unaff_retaddr;
  undefined4 uStack0000000c;
  ulong uVar4;
  TiXmlPrinter *pTVar5;
  TiXmlPrinter *in_stack_ffffffd8;
  uint in_stack_ffffffdc;
  CClassicBuffer local_1d;
  TiXmlPrinter aTStack_1c [4];
  TiXmlPrinter local_18 [4];
  undefined4 *puStack_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  this_00 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ae2578;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_1 == (TiXmlDocument *)0x0) {
    ExceptionList = unaff_retaddr;
    return false;
  }
  if (((byte)param_1[4] & 2) == 0) {
    ExceptionList = unaff_retaddr;
    return false;
  }
  if (this[0x44] != (TiXmlDocument)0x0) {
    param_1 = (TiXmlDocument *)CONCAT31(param_1._1_3_,0xef);
    in_stack_ffffffd8 = (TiXmlPrinter *)CONCAT13(0xbf,CONCAT12(0xbb,(short)in_stack_ffffffd8));
    iVar2 = CClassicBuffer::WriteAll
                      ((CClassicBuffer *)this_00,(CClassicBuffer *)&param_1,(void *)0x1,
                       DAT_00cca150 ^ (uint)&stack0xffffffd0);
    if (iVar2 == 0) {
      ExceptionList = unaff_retaddr;
      return false;
    }
    iVar2 = CClassicBuffer::WriteAll
                      ((CClassicBuffer *)this_00,(CClassicBuffer *)&stack0xffffffde,(void *)0x1,
                       unaff_EDI);
    if (iVar2 == 0) {
      ExceptionList = unaff_retaddr;
      return false;
    }
    iVar2 = CClassicBuffer::WriteAll((CClassicBuffer *)this_00,&local_1d,(void *)0x1,unaff_ESI);
    if (iVar2 == 0) {
      ExceptionList = unaff_retaddr;
      return false;
    }
  }
  TiXmlPrinter::TiXmlPrinter(local_18,in_stack_ffffffd8);
  uStack0000000c = 0;
  pcVar1 = "\t";
  do {
    pcVar3 = pcVar1;
    pcVar1 = pcVar3 + 1;
  } while (*pcVar3 != '\0');
  pTVar5 = (TiXmlPrinter *)&DAT_00b2fd88;
  uVar4 = 0x91d9ef;
  TiXmlString::assign(&local_4,(TiXmlString *)&DAT_00b2fd88,pcVar3 + -0xb2fd88,in_stack_ffffffdc);
  (**(code **)(*(int *)this + 0x40))();
  iVar2 = CClassicBuffer::WriteAll
                    ((CClassicBuffer *)this_00,(CClassicBuffer *)(puStack_14 + 2),
                     (void *)*puStack_14,uVar4);
  if (iVar2 == 0) {
    TiXmlPrinter::~TiXmlPrinter(aTStack_1c,pTVar5);
    ExceptionList = unaff_retaddr;
    return false;
  }
  TiXmlPrinter::~TiXmlPrinter(aTStack_1c,pTVar5);
  ExceptionList = unaff_retaddr;
  return true;
}
}

// =================================================
// Function: TiXmlDocument::SetError
// =================================================
void __thiscall
TiXmlDocument::SetError
          (TiXmlDocument *this,TiXmlDocument *param_1,int param_2,char *param_3,
          TiXmlParsingData *param_4,TiXmlEncoding param_5)
{
{
  TiXmlString TVar1;
  TiXmlString *pTVar2;
  TiXmlString *pTVar3;
  undefined4 *extraout_ECX;
  uint unaff_EDI;
  TiXmlEncoding unaff_retaddr;
  
  if (this[0x2c] == (TiXmlDocument)0x0) {
    *(TiXmlDocument **)(this + 0x30) = param_1;
    this[0x2c] = (TiXmlDocument)0x1;
    pTVar2 = (TiXmlString *)(&PTR_s_No_error_00d345a8)[(int)param_1];
    pTVar3 = pTVar2;
    do {
      TVar1 = *pTVar3;
      pTVar3 = pTVar3 + 1;
    } while (TVar1 != (TiXmlString)0x0);
    TiXmlString::assign(this + 0x34,pTVar2,(char *)(pTVar3 + -(int)(pTVar2 + 1)),unaff_EDI);
    *(undefined4 *)(this + 0x40) = 0xffffffff;
    *(undefined4 *)(this + 0x3c) = 0xffffffff;
    if ((param_3 != (char *)0x0) && (param_4 != (TiXmlParsingData *)0x0)) {
      TiXmlParsingData::Stamp(param_4,(TiXmlParsingData *)param_3,(char *)param_5,unaff_retaddr);
      *(undefined4 *)(this + 0x3c) = *extraout_ECX;
      *(undefined4 *)(this + 0x40) = extraout_ECX[1];
    }
  }
  return;
}
}

// =================================================
// Function: TiXmlDocument::TiXmlDocument
// =================================================
void __thiscall TiXmlDocument::TiXmlDocument(TiXmlDocument *this,TiXmlDocument *param_1)
{
{
  uint unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00ae2353;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  TiXmlNode::TiXmlNode
            ((TiXmlNode *)this,(TiXmlNode *)0x0,
             (NodeType)((uint)DAT_00cca150 ^ (uint)&stack0xffffffe8));
  *(undefined ***)this = vftable;
  *(undefined4 **)(this + 0x34) = &DAT_00d72f38;
  *(undefined4 *)(this + 0x40) = 0xffffffff;
  *(undefined4 *)(this + 0x3c) = 0xffffffff;
  *(undefined4 *)(this + 0x38) = 4;
  this[0x44] = (TiXmlDocument)0x0;
  this[0x2c] = (TiXmlDocument)0x0;
  *(undefined4 *)(this + 0x30) = 0;
  TiXmlString::assign(this + 0x34,(TiXmlString *)&DAT_00b2c878,(char *)0x0,unaff_ESI);
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  ExceptionList = local_4;
  return;
}
}

