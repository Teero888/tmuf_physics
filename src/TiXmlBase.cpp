// Class implementation: TiXmlBase

// =================================================
// Function: TiXmlBase::IsAlpha
// =================================================
int __cdecl TiXmlBase::IsAlpha(uchar param_1,TiXmlEncoding param_2)
{
{
  int iVar1;
  
  if (param_1 < 0x7f) {
    iVar1 = _isalpha((uint)param_1);
    return iVar1;
  }
  return 1;
}
}

// =================================================
// Function: TiXmlBase::SkipWhiteSpace
// =================================================
char * __cdecl TiXmlBase::SkipWhiteSpace(char *param_1,TiXmlEncoding param_2)
{
{
  int iVar1;
  byte bVar2;
  
  if ((param_1 == (char *)0x0) || (bVar2 = *param_1, bVar2 == 0)) {
    return (char *)0x0;
  }
  if (param_2 != 1) {
    while (((iVar1 = _isspace((uint)bVar2), iVar1 != 0 || (bVar2 == 10)) ||
           ((bVar2 == 0xd || ((*param_1 == '\n' || (*param_1 == '\r'))))))) {
      bVar2 = param_1[1];
      param_1 = param_1 + 1;
      if (bVar2 == 0) {
        return param_1;
      }
    }
    return param_1;
  }
  do {
    if (bVar2 == 0xef) {
      if ((param_1[1] == 0xbb) && (param_1[2] == 0xbf)) {
        param_1 = param_1 + 3;
      }
      else {
        if (param_1[1] != 0xbf) goto LAB_0091dfc4;
        if (param_1[2] == 0xbe) {
          param_1 = param_1 + 3;
        }
        else {
          if (param_1[2] != 0xbf) goto LAB_0091dfc4;
          param_1 = param_1 + 3;
        }
      }
    }
    else {
LAB_0091dfc4:
      iVar1 = _isspace((uint)bVar2);
      if ((((iVar1 == 0) && (bVar2 != 10)) && (bVar2 != 0xd)) &&
         ((*param_1 != 10 && (*param_1 != 0xd)))) {
        return (char *)(byte *)param_1;
      }
      param_1 = param_1 + 1;
    }
    bVar2 = *param_1;
    if (bVar2 == 0) {
      return (char *)(byte *)param_1;
    }
  } while( true );
}
}

// =================================================
// Function: TiXmlBase::StringEqual
// =================================================
bool __cdecl TiXmlBase::StringEqual(char *param_1,char *param_2,bool param_3,TiXmlEncoding param_4)
{
{
  char cVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    return false;
  }
  if (param_3) {
    do {
      if (*param_2 == '\0') {
        return true;
      }
      iVar2 = (int)*param_1;
      if ((param_4 != 1) || (iVar2 < 0x80)) {
        iVar2 = _tolower(iVar2);
      }
      iVar3 = (int)*param_2;
      if ((param_4 != 1) || (iVar3 < 0x80)) {
        iVar3 = _tolower(iVar3);
      }
      if (iVar2 != iVar3) break;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    } while (*param_1 != '\0');
    cVar1 = *param_2;
  }
  else {
    do {
      if (*param_2 == '\0') {
        return true;
      }
      if (*param_1 != *param_2) break;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    } while (*param_1 != '\0');
    cVar1 = *param_2;
  }
  if (cVar1 == '\0') {
    return true;
  }
  return false;
}
}

