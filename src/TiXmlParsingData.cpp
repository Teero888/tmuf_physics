// Class implementation: TiXmlParsingData

// =================================================
// Function: TiXmlParsingData::Stamp
// =================================================
void __thiscall
TiXmlParsingData::Stamp(void *this,TiXmlParsingData *param_1,char *param_2,TiXmlEncoding param_3)
{
{
  TiXmlParsingData TVar1;
  TiXmlParsingData TVar2;
  TiXmlParsingData *pTVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  TiXmlParsingData *pTVar7;
  int iVar8;
  
  if (0 < *(int *)((int)this + 0xc)) {
    iVar4 = *(int *)((int)this + 4);
    iVar6 = *(int *)this;
    pTVar3 = *(TiXmlParsingData **)((int)this + 8);
joined_r0x0091dd30:
    pTVar7 = pTVar3;
    if (pTVar7 < param_1) {
      switch((uint)(byte)*pTVar7) {
      case 0:
        goto switchD_0091dd5b_caseD_0;
      default:
        if (param_2 == (char *)0x1) {
          iVar8 = *(int *)(&DAT_00bc4f18 + (uint)(byte)*pTVar7 * 4);
          if (iVar8 == 0) {
            iVar8 = 1;
          }
          iVar5 = 0;
          if (0 < iVar8) {
            do {
              if ((0 < iVar5) && (((byte)*pTVar7 & 0x80) == 0)) break;
              iVar5 = iVar5 + 1;
              pTVar7 = pTVar7 + 1;
            } while (iVar5 < iVar8);
          }
        }
        else {
LAB_0091de13:
          pTVar7 = pTVar7 + 1;
        }
        iVar4 = iVar4 + 1;
        pTVar3 = pTVar7;
        goto joined_r0x0091dd30;
      case 9:
        iVar4 = (iVar4 / *(int *)((int)this + 0xc) + 1) * *(int *)((int)this + 0xc);
        pTVar3 = pTVar7 + 1;
        goto joined_r0x0091dd30;
      case 10:
        iVar6 = iVar6 + 1;
        iVar4 = 0;
        pTVar3 = pTVar7 + 1;
        if (pTVar7[1] == (TiXmlParsingData)0xd) {
          pTVar3 = pTVar7 + 2;
        }
        goto joined_r0x0091dd30;
      case 0xd:
        iVar6 = iVar6 + 1;
        iVar4 = 0;
        pTVar3 = pTVar7 + 1;
        if (pTVar7[1] == (TiXmlParsingData)0xa) {
          pTVar3 = pTVar7 + 2;
        }
        goto joined_r0x0091dd30;
      case 0xef:
        goto switchD_0091dd5b_caseD_ef;
      }
    }
    *(int *)this = iVar6;
    *(int *)((int)this + 4) = iVar4;
    *(TiXmlParsingData **)((int)this + 8) = pTVar7;
switchD_0091dd5b_caseD_0:
  }
  return;
switchD_0091dd5b_caseD_ef:
  if (param_2 != (char *)0x1) goto LAB_0091de13;
  TVar1 = pTVar7[1];
  pTVar3 = pTVar7;
  if ((TVar1 != (TiXmlParsingData)0x0) && (TVar2 = pTVar7[2], TVar2 != (TiXmlParsingData)0x0)) {
    if ((TVar1 == (TiXmlParsingData)0xbb) && (TVar2 == (TiXmlParsingData)0xbf)) {
      pTVar3 = pTVar7 + 3;
      goto joined_r0x0091dd30;
    }
    if (TVar1 == (TiXmlParsingData)0xbf) {
      if (TVar2 == (TiXmlParsingData)0xbe) {
        pTVar3 = pTVar7 + 3;
        goto joined_r0x0091dd30;
      }
      if (TVar2 == (TiXmlParsingData)0xbf) {
        pTVar3 = pTVar7 + 3;
        goto joined_r0x0091dd30;
      }
    }
    iVar4 = iVar4 + 1;
    pTVar3 = pTVar7 + 3;
  }
  goto joined_r0x0091dd30;
}
}

