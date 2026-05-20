
/* public: struct SNat128 & __thiscall SNat128::operator=(struct SNat128 const &) */

SNat128 *__thiscall SNat128::operator=(SNat128 *this, SNat128 *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  return this;
}
