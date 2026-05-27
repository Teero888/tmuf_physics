// Class implementation: CClassicArchive

// =================================================
// Function: CClassicArchive::CClassicArchive
// =================================================
void __thiscall CClassicArchive::CClassicArchive(CClassicArchive *this,CClassicArchive *param_1)
{
{
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  return;
}
}

// =================================================
// Function: CClassicArchive::DetachBuffer
// =================================================
CClassicBuffer * __thiscall
CClassicArchive::DetachBuffer(CClassicArchive *this,CClassicArchive *param_1,int param_2)
{
{
  CClassicBuffer *pCVar1;
  
  if (((param_1 != (CClassicArchive *)0x0) && (*(int *)(this + 0x14) != 0)) &&
     (DAT_00d72e88 != (code *)0x0)) {
    (*DAT_00d72e88)(this);
  }
  pCVar1 = *(CClassicBuffer **)(this + 4);
  *(undefined4 *)(this + 4) = 0;
  return pCVar1;
}
}

// =================================================
// Function: CClassicArchive::DoBool
// =================================================
void __thiscall
CClassicArchive::DoBool(CClassicArchive *this,CClassicArchive *param_1,int *param_2,ulong param_3)
{
{
  if (*(int *)(this + 8) != 0) {
    WriteBool(this,param_1,param_2,param_3);
    return;
  }
  ReadBool(this,param_1,param_2,param_3);
  return;
}
}

// =================================================
// Function: CClassicArchive::DoData
// =================================================
int __thiscall
CClassicArchive::DoData
          (CClassicArchive *this,CNetNod_CheckedArchive *param_1,void *param_2,ulong param_3)
{
{
  int extraout_EAX;
  int extraout_EAX_00;
  
  if (*(int *)(this + 8) != 0) {
    WriteData(this,(CClassicArchive *)param_1,param_2,param_3);
    return extraout_EAX;
  }
  ReadData(this,(CClassicArchive *)param_1,param_2,param_3);
  return extraout_EAX_00;
}
}

// =================================================
// Function: CClassicArchive::DoInteger
// =================================================
void __thiscall
CClassicArchive::DoInteger
          (CClassicArchive *this,CClassicArchive *param_1,int *param_2,ulong param_3,int param_4)
{
{
  if (*(int *)(this + 8) != 0) {
    WriteInteger(this,param_1,param_2,param_3,param_4);
    return;
  }
  ReadInteger(this,param_1,param_2,param_3,param_4);
  return;
}
}

// =================================================
// Function: CClassicArchive::DoNat16
// =================================================
void __thiscall
CClassicArchive::DoNat16
          (CClassicArchive *this,CClassicArchive *param_1,ushort *param_2,ulong param_3,int param_4)
{
{
  if (*(int *)(this + 8) != 0) {
    WriteNat16(this,param_1,param_2,param_3,param_4);
    return;
  }
  ReadNat16(this,param_1,param_2,param_3,param_4);
  return;
}
}

// =================================================
// Function: CClassicArchive::DoNat8
// =================================================
void __thiscall
CClassicArchive::DoNat8
          (CClassicArchive *this,CClassicArchive *param_1,uchar *param_2,ulong param_3,int param_4)
{
{
  if (*(int *)(this + 8) != 0) {
    WriteNat8(this,param_1,param_2,param_3,param_4);
    return;
  }
  ReadNat8(this,param_1,param_2,param_3,param_4);
  return;
}
}

// =================================================
// Function: CClassicArchive::DoNatural
// =================================================
void __thiscall
CClassicArchive::DoNatural
          (CClassicArchive *this,CClassicArchive *param_1,ulong *param_2,ulong param_3,int param_4)
{
{
  if (*(int *)(this + 8) != 0) {
    WriteNatural(this,param_1,param_2,param_3,param_4);
    return;
  }
  ReadNatural(this,param_1,param_2,param_3,param_4);
  return;
}
}

// =================================================
// Function: CClassicArchive::DoReal
// =================================================
void __thiscall
CClassicArchive::DoReal(CClassicArchive *this,CClassicArchive *param_1,float *param_2,ulong param_3)
{
{
  if (*(int *)(this + 8) != 0) {
    WriteReal(this,param_1,param_2,param_3);
    return;
  }
  ReadReal(this,param_1,param_2,param_3);
  return;
}
}

// =================================================
// Function: CClassicArchive::DoString
// =================================================
void __thiscall
CClassicArchive::DoString
          (CClassicArchive *this,CClassicCrypto_BlowFish *param_1,CFastString *param_2,
          CFastString *param_3,ECipherOpMode param_4,uint64 *param_5,int param_6)
{
{
  if (*(int *)(this + 8) != 0) {
    WriteString(this,(CClassicArchive *)param_1,(CFastStringInt *)param_2,(ulong)param_3);
    return;
  }
  ReadString(this,(CClassicArchive *)param_1,(CFastStringInt *)param_2,(ulong)param_3);
  return;
}
}

// =================================================
// Function: CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
// =================================================
void __thiscall
CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
          (CClassicArchive *this,CClassicArchive *param_1,CMwNodRef<class_CMwRefBuffer> *param_2)
{
{
  CClassicArchive *pCVar1;
  CMwNod *unaff_retaddr;
  CMwNod *pCVar2;
  
  pCVar1 = param_1;
  param_1 = *(CClassicArchive **)param_1;
  pCVar2 = (CMwNod *)&param_1;
  (**(code **)(*(int *)this + 4))();
  if (unaff_retaddr != *(CMwNod **)pCVar1) {
    if (unaff_retaddr != (CMwNod *)0x0) {
      CMwNod::MwAddRef(unaff_retaddr,pCVar2);
    }
    if (*(CMwNod **)pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)pCVar1,pCVar2);
    }
    *(CMwNod **)pCVar1 = unaff_retaddr;
  }
  return;
}
}

// =================================================
// Function: CClassicArchive::ReadBool
// =================================================
void __thiscall
CClassicArchive::ReadBool(CClassicArchive *this,CClassicArchive *param_1,int *param_2,ulong param_3)
{
{
  CClassicArchive *unaff_EBX;
  int *piVar1;
  ulong unaff_EDI;
  
  if (*(int *)(this + 0xc) == 0) {
    CClassicBuffer::ReadAll
              (*(CClassicBuffer **)(this + 4),(CClassicBuffer *)param_1,(void *)((int)param_2 * 4),
               unaff_EDI);
    return;
  }
  piVar1 = (int *)0x0;
  if (param_2 != (int *)0x0) {
    do {
      ReadLine(this,unaff_EBX);
      piVar1 = (int *)((int)piVar1 + 1);
      *(uint *)(param_1 + (int)piVar1 * 4 + -4) = (uint)(DAT_00d71e88 == 'T');
    } while (piVar1 < param_2);
  }
  return;
}
}

// =================================================
// Function: CClassicArchive::ReadData
// =================================================
void __thiscall
CClassicArchive::ReadData
          (CClassicArchive *this,CClassicArchive *param_1,void *param_2,ulong param_3)
{
{
  if (param_2 != (void *)0x0) {
    CClassicBuffer::ReadAll
              (*(CClassicBuffer **)(this + 4),(CClassicBuffer *)param_1,param_2,param_3);
    return;
  }
  return;
}
}

// =================================================
// Function: CClassicArchive::ReadInteger
// =================================================
void __thiscall
CClassicArchive::ReadInteger
          (CClassicArchive *this,CClassicArchive *param_1,int *param_2,ulong param_3,int param_4)
{
{
  ulong unaff_EBP;
  int *piVar1;
  CClassicArchive *unaff_EDI;
  char *pcVar2;
  
  if (*(int *)(this + 0xc) == 0) {
    CClassicBuffer::ReadAll
              (*(CClassicBuffer **)(this + 4),(CClassicBuffer *)param_1,(void *)((int)param_2 * 4),
               unaff_EBP);
    return;
  }
  piVar1 = (int *)0x0;
  if (param_2 != (int *)0x0) {
    do {
      ReadLine(this,unaff_EDI);
      if (param_4 == 0) {
        pcVar2 = "%d";
      }
      else {
        pcVar2 = "%x";
      }
      unaff_EDI = (CClassicArchive *)&param_3;
      _sscanf_s(&DAT_00d71e88,pcVar2);
      *(ulong *)(param_1 + (int)piVar1 * 4) = param_3;
      piVar1 = (int *)((int)piVar1 + 1);
    } while (piVar1 < param_2);
  }
  return;
}
}

// =================================================
// Function: CClassicArchive::ReadLine
// =================================================
int __thiscall CClassicArchive::ReadLine(CClassicArchive *this,CClassicArchive *param_1)
{
{
  int iVar1;
  CClassicBuffer CVar2;
  ulong unaff_ESI;
  ulong unaff_retaddr;
  CClassicArchive *pCVar3;
  
  DAT_00d72e94 = 0;
  pCVar3 = this;
  while( true ) {
    iVar1 = CClassicBuffer::ReadAll
                      (*(CClassicBuffer **)(this + 4),(CClassicBuffer *)&stack0xffffffff,(void *)0x1
                       ,unaff_ESI);
    if (iVar1 == 0) {
      return 0;
    }
    CVar2 = SUB41(unaff_retaddr >> 0x18,0);
    if (CVar2 == (CClassicBuffer)0x7c) {
      unaff_ESI = 1;
      iVar1 = CClassicBuffer::ReadAll
                        (*(CClassicBuffer **)(this + 4),(CClassicBuffer *)&stack0x00000003,
                         (void *)0x1,(ulong)pCVar3);
      if (iVar1 == 0) {
        return 0;
      }
      CVar2 = param_1._3_1_;
      if (param_1._3_1_ == (CClassicBuffer)0xd) {
        iVar1 = CClassicBuffer::ReadAll
                          (*(CClassicBuffer **)(this + 4),(CClassicBuffer *)((int)&param_1 + 3),
                           (void *)0x1,unaff_retaddr);
        if (iVar1 == 0) {
          return 0;
        }
        (&DAT_00d71e88)[DAT_00d72e94] = 0;
        return 1;
      }
    }
    if ((CVar2 == (CClassicBuffer)0xa) && ((&DAT_00d71e87)[DAT_00d72e94] == '\r')) break;
    if (0xffe < DAT_00d72e94) goto LAB_0090960a;
    *(CClassicBuffer *)(&DAT_00d71e88 + DAT_00d72e94) = CVar2;
    DAT_00d72e94 = DAT_00d72e94 + 1;
  }
  DAT_00d72e94 = DAT_00d72e94 - 1;
LAB_0090960a:
  (&DAT_00d71e88)[DAT_00d72e94] = 0;
  return 0;
}
}

// =================================================
// Function: CClassicArchive::ReadMask
// =================================================
void __thiscall
CClassicArchive::ReadMask
          (CClassicArchive *this,CClassicArchive *param_1,ulong *param_2,ulong param_3)
{
{
  int unaff_retaddr;
  
  ReadNatural(this,param_1,param_2,1,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CClassicArchive::ReadNat16
// =================================================
void __thiscall
CClassicArchive::ReadNat16
          (CClassicArchive *this,CClassicArchive *param_1,ushort *param_2,ulong param_3,int param_4)
{
{
  ulong unaff_EBP;
  ushort *puVar1;
  CClassicArchive *unaff_EDI;
  char *pcVar2;
  
  if (*(int *)(this + 0xc) == 0) {
    CClassicBuffer::ReadAll
              (*(CClassicBuffer **)(this + 4),(CClassicBuffer *)param_1,(void *)((int)param_2 * 2),
               unaff_EBP);
    return;
  }
  puVar1 = (ushort *)0x0;
  if (param_2 != (ushort *)0x0) {
    do {
      ReadLine(this,unaff_EDI);
      if (param_4 == 0) {
        pcVar2 = "%hu";
      }
      else {
        pcVar2 = "%hx";
      }
      unaff_EDI = (CClassicArchive *)&param_3;
      _sscanf_s(&DAT_00d71e88,pcVar2);
      *(undefined2 *)(param_1 + (int)puVar1 * 2) = (undefined2)param_3;
      puVar1 = (ushort *)((int)puVar1 + 1);
    } while (puVar1 < param_2);
  }
  return;
}
}

// =================================================
// Function: CClassicArchive::ReadNat8
// =================================================
void __thiscall
CClassicArchive::ReadNat8
          (CClassicArchive *this,CClassicArchive *param_1,uchar *param_2,ulong param_3,int param_4)
{
{
  ulong unaff_EBP;
  uchar *puVar1;
  CClassicArchive *unaff_EDI;
  char *pcVar2;
  
  if (*(int *)(this + 0xc) == 0) {
    CClassicBuffer::ReadAll
              (*(CClassicBuffer **)(this + 4),(CClassicBuffer *)param_1,param_2,unaff_EBP);
    return;
  }
  puVar1 = (uchar *)0x0;
  if (param_2 != (uchar *)0x0) {
    do {
      ReadLine(this,unaff_EDI);
      if (param_4 == 0) {
        pcVar2 = "%hu";
      }
      else {
        pcVar2 = "%hx";
      }
      unaff_EDI = (CClassicArchive *)&param_3;
      _sscanf_s(&DAT_00d71e88,pcVar2);
      puVar1[(int)param_1] = (uchar)param_3;
      puVar1 = puVar1 + 1;
    } while (puVar1 < param_2);
  }
  return;
}
}

// =================================================
// Function: CClassicArchive::ReadNatural
// =================================================
void __thiscall
CClassicArchive::ReadNatural
          (CClassicArchive *this,CClassicArchive *param_1,ulong *param_2,ulong param_3,int param_4)
{
{
  ulong unaff_EBP;
  ulong *puVar1;
  CClassicArchive *unaff_EDI;
  char *pcVar2;
  
  if (*(int *)(this + 0xc) == 0) {
    CClassicBuffer::ReadAll
              (*(CClassicBuffer **)(this + 4),(CClassicBuffer *)param_1,(void *)((int)param_2 * 4),
               unaff_EBP);
    return;
  }
  puVar1 = (ulong *)0x0;
  if (param_2 != (ulong *)0x0) {
    do {
      ReadLine(this,unaff_EDI);
      if (param_4 == 0) {
        pcVar2 = "%u";
      }
      else {
        pcVar2 = "%x";
      }
      unaff_EDI = (CClassicArchive *)&param_3;
      _sscanf_s(&DAT_00d71e88,pcVar2);
      *(ulong *)(param_1 + (int)puVar1 * 4) = param_3;
      puVar1 = (ulong *)((int)puVar1 + 1);
    } while (puVar1 < param_2);
  }
  return;
}
}

// =================================================
// Function: CClassicArchive::ReadReal
// =================================================
void __thiscall
CClassicArchive::ReadReal
          (CClassicArchive *this,CClassicArchive *param_1,float *param_2,ulong param_3)
{
{
  CClassicArchive *unaff_EBP;
  float *pfVar1;
  ulong unaff_EDI;
  double dVar2;
  
  if (*(int *)(this + 0xc) == 0) {
    CClassicBuffer::ReadAll
              (*(CClassicBuffer **)(this + 4),(CClassicBuffer *)param_1,(void *)((int)param_2 * 4),
               unaff_EDI);
    return;
  }
  pfVar1 = (float *)0x0;
  if (param_2 != (float *)0x0) {
    do {
      ReadLine(this,unaff_EBP);
      unaff_EBP = (CClassicArchive *)&DAT_00d71e88;
      dVar2 = _atof(&DAT_00d71e88);
      *(float *)(param_1 + (int)pfVar1 * 4) = (float)dVar2;
      pfVar1 = (float *)((int)pfVar1 + 1);
    } while (pfVar1 < param_2);
  }
  return;
}
}

// =================================================
// Function: CClassicArchive::ReadString
// =================================================
void __thiscall
CClassicArchive::ReadString
          (CClassicArchive *this,CClassicArchive *param_1,CFastStringInt *param_2,ulong param_3)
{
{
  undefined1 *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  char *pcVar5;
  CPlugFileGpuBuilder *pCVar6;
  CFastStringBase<wchar_t> *pCVar7;
  CFastStringBase<wchar_t> *pCVar8;
  CPlugFileGpuBuilder *unaff_EBX;
  SStringParam *unaff_EBP;
  CFastStringInt *unaff_ESI;
  CFastStringBase<wchar_t> *unaff_EDI;
  CFastStringBase<wchar_t> *in_stack_00000010;
  CFastStringBase<wchar_t> *in_stack_0000001c;
  CFastStringBase<wchar_t> *in_stack_00000020;
  CPlugFileGpuBuilder *pCVar9;
  LPCSTR *ppCVar10;
  CFastStringInt *in_stack_fffffff0;
  SOldChars *in_stack_fffffff4;
  
  pCVar7 = (CFastStringBase<wchar_t> *)param_2;
  while (pCVar7 != (CFastStringBase<wchar_t> *)0x0) {
    if (*(int *)(this + 0xc) == 0) {
      param_2 = (CFastStringInt *)0xffffffff;
      iVar4 = CClassicBuffer::ReadAll
                        (*(CClassicBuffer **)(this + 4),(CClassicBuffer *)&param_2,&DAT_00000004,
                         (ulong)unaff_ESI);
      if ((0xfffffff < param_3) || (pCVar7 = (CFastStringBase<wchar_t> *)param_3, iVar4 == 0)) {
        if (DAT_00d71e54 != 0) {
          DAT_00d71e54 = 0;
          *DAT_00d71e58 = 0;
        }
        ppCVar10 = &lpOutputString_00b2bcc4;
        pCVar9 = (CPlugFileGpuBuilder *)&DAT_00b30988;
        pCVar6 = CFastString::operator<<
                           ((CFastString *)&DAT_00d71e54,
                            (CPlugFileGpuBuilder *)"[CrashInfo] Corrupted ReadString? (Length = ",
                            (char *)param_3);
        pCVar6 = CFastString::operator<<((CFastString *)pCVar6,pCVar9,(char *)ppCVar10);
        unaff_ESI = (CFastStringInt *)0x90a301;
        pCVar6 = CFastString::operator<<
                           ((CFastString *)pCVar6,(CPlugFileGpuBuilder *)unaff_EBP,(char *)unaff_EDI
                           );
        unaff_EDI = (CFastStringBase<wchar_t> *)0x90a308;
        CFastString::operator<<((CFastString *)pCVar6,unaff_EBX,(char *)in_stack_fffffff0);
        CClassicLog::AddLogStringInFile();
        pCVar7 = in_stack_0000001c;
        if (DAT_00d72e8c != (code *)0x0) {
          (*DAT_00d72e8c)();
          pCVar7 = in_stack_0000001c;
        }
      }
      pCVar8 = pCVar7;
      if (pCVar7 != DAT_00d72e98) {
        unaff_EBP = (SStringParam *)0x90a334;
        unaff_EDI = pCVar7;
        CFastStringBase<char>::AllocAtLeast
                  ((CFastStringBase<char> *)&DAT_00d72e98,pCVar7,1,0,in_stack_fffffff4);
        DAT_00d72e9c[(int)pCVar7] = (CClassicBuffer)0x0;
        pCVar8 = in_stack_00000020;
        DAT_00d72e98 = pCVar7;
      }
      if (pCVar8 != (CFastStringBase<wchar_t> *)0x0) {
        unaff_EDI = (CFastStringBase<wchar_t> *)0x90a35b;
        iVar4 = CClassicBuffer::ReadAll
                          (*(CClassicBuffer **)(this + 4),DAT_00d72e9c,pCVar8,
                           (ulong)in_stack_fffffff4);
        if ((iVar4 == 0) && (DAT_00d72e8c != (code *)0x0)) {
          in_stack_fffffff4 = (SOldChars *)0x90a36a;
          (*DAT_00d72e8c)();
        }
      }
    }
    else {
      bVar3 = false;
      if (DAT_00d72e98 != (CFastStringBase<wchar_t> *)0x0) {
        DAT_00d72e98 = (CFastStringBase<wchar_t> *)0x0;
        *DAT_00d72e9c = (CClassicBuffer)0x0;
      }
      do {
        iVar4 = ReadLine(this,(CClassicArchive *)unaff_ESI);
        if (iVar4 == 0) {
          bVar3 = true;
        }
        else {
          (&DAT_00d71e88)[DAT_00d72e94] = 0xd;
          (&DAT_00d71e89)[DAT_00d72e94] = 10;
          puVar1 = &DAT_00d71e8a + DAT_00d72e94;
          DAT_00d72e94 = DAT_00d72e94 + 2;
          *puVar1 = 0;
        }
        pcVar5 = &DAT_00d71e88;
        in_stack_fffffff4 = (SOldChars *)&DAT_00d71e88;
        do {
          cVar2 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar2 != '\0');
        unaff_ESI = (CFastStringInt *)&stack0xfffffff4;
        CFastString::Concat((CFastString *)&DAT_00d72e98,unaff_ESI,unaff_EBP);
      } while (!bVar3);
    }
    if (DAT_00d72e90 == 0) {
      CFastString::FilterStringForPrintableChars((CFastString *)&DAT_00d72e98);
    }
    in_stack_fffffff0 = (CFastStringInt *)&param_3;
    in_stack_00000010 = DAT_00d72e98;
    param_3 = (ulong)DAT_00d72e9c;
    unaff_EBX = (CPlugFileGpuBuilder *)0x90a39e;
    CFastStringInt::SetLatin1OrUtf8(param_1,in_stack_fffffff0,(SStringParam *)in_stack_fffffff4);
    param_1 = param_1 + 8;
    in_stack_0000001c = in_stack_0000001c + -1;
    pCVar7 = in_stack_0000001c;
  }
  return;
}
}

// =================================================
// Function: CClassicArchive::SkipData
// =================================================
void __thiscall
CClassicArchive::SkipData(CClassicArchive *this,CClassicArchive *param_1,ulong param_2)
{
{
  CPlugFileGpuBuilder *this_00;
  char *unaff_EBX;
  ulong unaff_ESI;
  CClassicArchive *pCVar1;
  CPlugFileGpuBuilder *unaff_EDI;
  
  if (param_1 != (CClassicArchive *)0x0) {
    if (*(int *)(this + 8) == 0) {
      CClassicBuffer::Skip
                (*(CClassicBuffer **)(this + 4),(CClassicBuffer *)param_1,(ulong)unaff_EDI);
    }
    else {
      if (DAT_00d71e54 != 0) {
        DAT_00d71e54 = 0;
        *DAT_00d71e58 = 0;
      }
      this_00 = CFastString::operator<<
                          ((CFastString *)&DAT_00d71e54,
                           (CPlugFileGpuBuilder *)
                           "[Archive] SAVING ERROR: Saving skipped datas => data may be lost !!",
                           (char *)&lpOutputString_00b2bcc4);
      CFastString::operator<<((CFastString *)this_00,unaff_EDI,unaff_EBX);
      CClassicLog::AddLogStringInFile();
      _memset(&DAT_00d71e88,0,0x1000);
      if (param_1 != (CClassicArchive *)0x0) {
        do {
          pCVar1 = param_1;
          if ((CClassicArchive *)0x1000 < param_1) {
            pCVar1 = (CClassicArchive *)0x1000;
          }
          WriteData(this,(CClassicArchive *)&DAT_00d71e88,pCVar1,unaff_ESI);
          param_1 = param_1 + -(int)pCVar1;
        } while (param_1 != (CClassicArchive *)0x0);
        return;
      }
    }
  }
  return;
}
}

// =================================================
// Function: CClassicArchive::WriteBool
// =================================================
void __thiscall
CClassicArchive::WriteBool
          (CClassicArchive *this,CClassicArchive *param_1,int *param_2,ulong param_3)
{
{
  CClassicArchive *unaff_EBP;
  int *piVar1;
  ulong unaff_EDI;
  char *pcVar2;
  
  if (*(int *)(this + 0xc) == 0) {
    CClassicBuffer::WriteAll
              (*(CClassicBuffer **)(this + 4),(CClassicBuffer *)param_1,(void *)((int)param_2 * 4),
               unaff_EDI);
    return;
  }
  piVar1 = (int *)0x0;
  if (param_2 != (int *)0x0) {
    do {
      if (*(int *)(param_1 + (int)piVar1 * 4) == 0) {
        pcVar2 = "False";
      }
      else {
        pcVar2 = "True";
      }
      DAT_00d72e94 = sprintf_s<4096>(&DAT_00d71e88,pcVar2);
      WriteLine(this,unaff_EBP);
      piVar1 = (int *)((int)piVar1 + 1);
    } while (piVar1 < param_2);
  }
  return;
}
}

// =================================================
// Function: CClassicArchive::WriteData
// =================================================
void __thiscall
CClassicArchive::WriteData
          (CClassicArchive *this,CClassicArchive *param_1,void *param_2,ulong param_3)
{
{
  if (param_2 != (void *)0x0) {
    CClassicBuffer::WriteAll
              (*(CClassicBuffer **)(this + 4),(CClassicBuffer *)param_1,param_2,param_3);
    return;
  }
  return;
}
}

// =================================================
// Function: CClassicArchive::WriteInteger
// =================================================
void __thiscall
CClassicArchive::WriteInteger
          (CClassicArchive *this,CClassicArchive *param_1,int *param_2,ulong param_3,int param_4)
{
{
  ulong unaff_EBX;
  int *piVar1;
  CClassicArchive *unaff_EDI;
  char *pcVar2;
  
  if (*(int *)(this + 0xc) == 0) {
    CClassicBuffer::WriteAll
              (*(CClassicBuffer **)(this + 4),(CClassicBuffer *)param_1,(void *)((int)param_2 * 4),
               unaff_EBX);
    return;
  }
  piVar1 = (int *)0x0;
  if (param_2 != (int *)0x0) {
    do {
      if (param_3 == 0) {
        pcVar2 = "%d";
      }
      else {
        pcVar2 = "%x";
      }
      DAT_00d72e94 = sprintf_s<4096>(&DAT_00d71e88,pcVar2);
      WriteLine(this,unaff_EDI);
      piVar1 = (int *)((int)piVar1 + 1);
    } while (piVar1 < param_2);
  }
  return;
}
}

// =================================================
// Function: CClassicArchive::WriteLine
// =================================================
void __thiscall CClassicArchive::WriteLine(CClassicArchive *this,CClassicArchive *param_1)
{
{
  ulong unaff_retaddr;
  
  (&DAT_00d71e88)[(int)DAT_00d72e94] = 0xd;
  (&DAT_00d71e89)[(int)DAT_00d72e94] = 10;
  DAT_00d72e94 = (void *)((int)DAT_00d72e94 + 2);
  CClassicBuffer::WriteAll
            (*(CClassicBuffer **)(this + 4),(CClassicBuffer *)&DAT_00d71e88,DAT_00d72e94,
             unaff_retaddr);
  return;
}
}

// =================================================
// Function: CClassicArchive::WriteMask
// =================================================
void __thiscall
CClassicArchive::WriteMask
          (CClassicArchive *this,CClassicArchive *param_1,ulong *param_2,ulong param_3)
{
{
  int unaff_retaddr;
  
  WriteNatural(this,param_1,param_2,1,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CClassicArchive::WriteNat16
// =================================================
void __thiscall
CClassicArchive::WriteNat16
          (CClassicArchive *this,CClassicArchive *param_1,ushort *param_2,ulong param_3,int param_4)
{
{
  ulong unaff_EBX;
  ushort *puVar1;
  CClassicArchive *unaff_EDI;
  char *pcVar2;
  
  if (*(int *)(this + 0xc) == 0) {
    CClassicBuffer::WriteAll
              (*(CClassicBuffer **)(this + 4),(CClassicBuffer *)param_1,(void *)((int)param_2 * 2),
               unaff_EBX);
    return;
  }
  puVar1 = (ushort *)0x0;
  if (param_2 != (ushort *)0x0) {
    do {
      if (param_3 == 0) {
        pcVar2 = "%hu";
      }
      else {
        pcVar2 = "%hx";
      }
      DAT_00d72e94 = sprintf_s<4096>(&DAT_00d71e88,pcVar2);
      WriteLine(this,unaff_EDI);
      puVar1 = (ushort *)((int)puVar1 + 1);
    } while (puVar1 < param_2);
  }
  return;
}
}

// =================================================
// Function: CClassicArchive::WriteNat8
// =================================================
void __thiscall
CClassicArchive::WriteNat8
          (CClassicArchive *this,CClassicArchive *param_1,uchar *param_2,ulong param_3,int param_4)
{
{
  ulong unaff_EBP;
  uint uVar1;
  CClassicArchive *unaff_EDI;
  char *pcVar2;
  
  if (*(int *)(this + 0xc) == 0) {
    CClassicBuffer::WriteAll
              (*(CClassicBuffer **)(this + 4),(CClassicBuffer *)param_1,param_2,unaff_EBP);
    return;
  }
  uVar1 = 0;
  if (param_2 != (uchar *)0x0) {
    do {
      if (param_3 == 0) {
        pcVar2 = "%hu";
      }
      else {
        pcVar2 = "%hx";
      }
      DAT_00d72e94 = sprintf_s<4096>(&DAT_00d71e88,pcVar2);
      WriteLine(this,unaff_EDI);
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_3);
  }
  return;
}
}

// =================================================
// Function: CClassicArchive::WriteNatural
// =================================================
void __thiscall
CClassicArchive::WriteNatural
          (CClassicArchive *this,CClassicArchive *param_1,ulong *param_2,ulong param_3,int param_4)
{
{
  ulong unaff_EBX;
  ulong *puVar1;
  CClassicArchive *unaff_EDI;
  char *pcVar2;
  
  if (*(int *)(this + 0xc) == 0) {
    CClassicBuffer::WriteAll
              (*(CClassicBuffer **)(this + 4),(CClassicBuffer *)param_1,(void *)((int)param_2 * 4),
               unaff_EBX);
    return;
  }
  puVar1 = (ulong *)0x0;
  if (param_2 != (ulong *)0x0) {
    do {
      if (param_3 == 0) {
        pcVar2 = "%u";
      }
      else {
        pcVar2 = "%x";
      }
      DAT_00d72e94 = sprintf_s<4096>(&DAT_00d71e88,pcVar2);
      WriteLine(this,unaff_EDI);
      puVar1 = (ulong *)((int)puVar1 + 1);
    } while (puVar1 < param_2);
  }
  return;
}
}

// =================================================
// Function: CClassicArchive::WriteReal
// =================================================
void __thiscall
CClassicArchive::WriteReal
          (CClassicArchive *this,CClassicArchive *param_1,float *param_2,ulong param_3)
{
{
  CClassicArchive *unaff_ESI;
  float *pfVar1;
  ulong unaff_EDI;
  
  if (*(int *)(this + 0xc) != 0) {
    pfVar1 = (float *)0x0;
    if (param_2 != (float *)0x0) {
      do {
        DAT_00d72e94 = sprintf_s<4096>(&DAT_00d71e88,"%f");
        WriteLine(this,unaff_ESI);
        pfVar1 = (float *)((int)pfVar1 + 1);
      } while (pfVar1 < param_2);
    }
    return;
  }
  CClassicBuffer::WriteAll
            (*(CClassicBuffer **)(this + 4),(CClassicBuffer *)param_1,(void *)((int)param_2 * 4),
             unaff_EDI);
  return;
}
}

// =================================================
// Function: CClassicArchive::WriteString
// =================================================
void __thiscall
CClassicArchive::WriteString
          (CClassicArchive *this,CClassicArchive *param_1,CFastStringInt *param_2,ulong param_3)
{
{
  int iVar1;
  ulong unaff_EBP;
  CFastString *unaff_ESI;
  uint uVar2;
  CFastStringInt *local_4;
  
  if (param_2 != (CFastStringInt *)0x0) {
    local_4 = param_2;
    do {
      CFastStringInt::GetUtf8OrAscii(param_1,(CFastStringInt *)&DAT_00d72e98,unaff_ESI);
      iVar1 = DAT_00d72e9c;
      param_3 = DAT_00d72e98;
      if (*(int *)(this + 0xc) == 0) {
        unaff_ESI = (CFastString *)&DAT_00000004;
        (**(code **)(**(int **)(this + 4) + 8))(&param_3);
        if (param_2 != (CFastStringInt *)0x0) {
          (**(code **)(**(int **)(this + 4) + 8))(iVar1,param_2);
        }
      }
      else {
        uVar2 = 0;
        if (DAT_00d72e98 != 0) {
          do {
            if (*(char *)(iVar1 + uVar2) == '|') {
              WriteData(this,(CClassicArchive *)&DAT_00b2ce4c,(void *)0x1,unaff_EBP);
            }
            if ((*(char *)(iVar1 + uVar2) == '\r') && (*(char *)(iVar1 + 1 + uVar2) == '\n')) {
              WriteData(this,(CClassicArchive *)&DAT_00b2ce4c,(void *)0x1,unaff_EBP);
            }
            (**(code **)(**(int **)(this + 4) + 8))((char *)(iVar1 + uVar2),1);
            uVar2 = uVar2 + 1;
          } while (uVar2 < param_3);
        }
        unaff_ESI = (CFastString *)0x2;
        WriteData(this,(CClassicArchive *)&lpOutputString_00b2bcc4,(void *)0x2,unaff_EBP);
      }
      param_1 = param_1 + 8;
      local_4 = local_4 + -1;
    } while (local_4 != (CFastStringInt *)0x0);
  }
  return;
}
}

// =================================================
// Function: CClassicArchive::~CClassicArchive
// =================================================
void __thiscall CClassicArchive::~CClassicArchive(CClassicArchive *this,CClassicArchive *param_1)
{
{
  *(undefined ***)this = vftable;
  if ((*(int *)(this + 0x14) != 0) && (DAT_00d72e88 != (code *)0x0)) {
    (*DAT_00d72e88)(this);
  }
  return;
}
}

