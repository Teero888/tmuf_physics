// Class implementation: TiXmlString

// =================================================
// Function: TiXmlString::TiXmlString
// =================================================
void __thiscall TiXmlString::TiXmlString(void *this,TiXmlString *param_1,char *param_2,uint param_3)
{
{
  undefined4 *puVar1;
  
  *(undefined4 *)this = 0;
  if (param_2 == (char *)0x0) {
    *(undefined4 **)this = &DAT_00d72f38;
  }
  else {
    puVar1 = operator_new__((uint)(param_2 + 0xf) & 0xfffffffc);
    *(undefined4 **)this = puVar1;
    *puVar1 = param_2;
    param_2[*(int *)this + 8] = '\0';
    *(char **)(*(int *)this + 4) = param_2;
  }
  _memcpy((void *)(*(int *)this + 8),param_1,(uint)param_2);
  return;
}
}

// =================================================
// Function: TiXmlString::append
// =================================================
TiXmlString * __thiscall
TiXmlString::append(void *this,TiXmlString *param_1,char *param_2,uint param_3)
{
{
  int *piVar1;
  uint unaff_EDI;
  char *pcVar2;
  
  piVar1 = *(int **)this;
  pcVar2 = param_2 + *piVar1;
  if ((char *)piVar1[1] < pcVar2) {
    reserve(this,(vector<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_> *)
                 (pcVar2 + piVar1[1]),unaff_EDI);
  }
  _memmove((void *)(**(int **)this + 8 + (int)*(int **)this),param_2,(uint)param_2);
  **(uint **)this = (uint)pcVar2;
  pcVar2[*(int *)this + 8] = '\0';
  return this;
}
}

// =================================================
// Function: TiXmlString::assign
// =================================================
TiXmlString * __thiscall
TiXmlString::assign(void *this,TiXmlString *param_1,char *param_2,uint param_3)
{
{
  char *pcVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ae2278;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pcVar1 = *(char **)(*(int *)this + 4);
  if ((pcVar1 < param_2) || ((char *)((int)param_2 * 3 + 0x18U) < pcVar1)) {
    puVar3 = &DAT_00d72f38;
    local_4 = 0;
    if (param_2 != (char *)0x0) {
      puVar3 = operator_new__((uint)(param_2 + 0xf) & 0xfffffffc);
      *puVar3 = param_2;
      (param_2 + 8)[(int)puVar3] = '\0';
      puVar3[1] = param_2;
    }
    _memcpy(puVar3 + 2,param_1,(uint)param_2);
    puVar2 = *(undefined4 **)this;
    *(undefined4 **)this = puVar3;
    if (puVar2 != &DAT_00d72f38) {
      operator_delete__(puVar2);
    }
  }
  else {
    _memmove((void *)(*(int *)this + 8),param_1,(uint)param_2);
    **(undefined4 **)this = param_2;
    param_2[*(int *)this + 8] = '\0';
  }
  ExceptionList = local_c;
  return this;
}
}

// =================================================
// Function: TiXmlString::init
// =================================================
void __thiscall
TiXmlString::init(void *this,basic_ios<char,struct_std::char_traits<char>_> *param_1,
                 basic_streambuf<char,struct_std::char_traits<char>_> *param_2,bool param_3)
{
{
  undefined4 *puVar1;
  
  if (param_2 != (basic_streambuf<char,struct_std::char_traits<char>_> *)0x0) {
    puVar1 = operator_new__((uint)(param_2 + 0xf) & 0xfffffffc);
    *(undefined4 **)this = puVar1;
    *puVar1 = param_1;
    param_1[*(int *)this + 8] = (basic_ios<char,struct_std::char_traits<char>_>)0x0;
    *(basic_streambuf<char,struct_std::char_traits<char>_> **)(*(int *)this + 4) = param_2;
    return;
  }
  *(undefined4 **)this = &DAT_00d72f38;
  return;
}
}

// =================================================
// Function: TiXmlString::reserve
// =================================================
void __thiscall
TiXmlString::reserve
          (void *this,vector<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_> *param_1,
          uint param_2)
{
{
  undefined4 *puVar1;
  vector<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_> *pvVar2;
  uint uVar3;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  pvVar2 = param_1;
  local_8 = &LAB_00ae2248;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if ((vector<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_> *)
      (*(undefined4 **)this)[1] < param_1) {
    param_1 = (vector<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_> *)&DAT_00d72f38;
    local_4 = 0;
    init(&param_1,(basic_ios<char,struct_std::char_traits<char>_> *)**(undefined4 **)this,
         (basic_streambuf<char,struct_std::char_traits<char>_> *)pvVar2,
         (bool)((byte)DAT_00cca150 ^ (byte)&stack0xffffffec));
    uVar3 = param_2;
    _memcpy((void *)(param_2 + 8),*(uint **)this + 2,**(uint **)this);
    puVar1 = *(undefined4 **)this;
    *(uint *)this = uVar3;
    if (puVar1 != &DAT_00d72f38) {
      operator_delete__(puVar1);
    }
  }
  ExceptionList = local_8;
  return;
}
}

