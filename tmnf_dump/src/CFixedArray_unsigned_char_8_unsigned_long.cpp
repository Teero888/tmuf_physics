// Class implementation: CFixedArray_unsigned_char_8_unsigned_long

// =================================================
// Function: unsigned_long>::FillWith
// =================================================
void __thiscall
CFixedArray<unsigned_char,8,unsigned_long>::FillWith
          (void *this,CFixedArray<unsigned_char,8,unsigned_long> *param_1,uchar *param_2)
{
{
  *(CFixedArray<unsigned_char,8,unsigned_long> *)this = *param_1;
  *(CFixedArray<unsigned_char,8,unsigned_long> *)((int)this + 1) = *param_1;
  *(CFixedArray<unsigned_char,8,unsigned_long> *)((int)this + 2) = *param_1;
  *(CFixedArray<unsigned_char,8,unsigned_long> *)((int)this + 3) = *param_1;
  *(CFixedArray<unsigned_char,8,unsigned_long> *)((int)this + 4) = *param_1;
  *(CFixedArray<unsigned_char,8,unsigned_long> *)((int)this + 5) = *param_1;
  *(CFixedArray<unsigned_char,8,unsigned_long> *)((int)this + 6) = *param_1;
  *(CFixedArray<unsigned_char,8,unsigned_long> *)((int)this + 7) = *param_1;
  return;
}
}

