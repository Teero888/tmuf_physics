
/* public: static class CMwId __cdecl CMwId::CreateFromLocalName(char const *)
 */

CMwId *__cdecl CMwId::CreateFromLocalName(CMwId *param_1, char *param_2)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  puStack_8 = &LAB_00a82839;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = 0;
  CMwId(param_1);
  local_4 = 0;
  SetLocalName(param_1, param_2);
  ExceptionList = local_c;
  return param_1;
}
