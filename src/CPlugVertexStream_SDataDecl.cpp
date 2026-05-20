// Class implementation: CPlugVertexStream_SDataDecl

// =================================================
// Function: CPlugVertexStream::SDataDecl::Release
// =================================================
void __thiscall CPlugVertexStream::SDataDecl::Release(void *this,CDx9VStreamKeeper *param_1)
{
{
  if ((*(uint *)((int)this + 4) & 0x40000000) != 0) {
    operator_delete__(*(void **)this);
    *(undefined4 *)this = 0;
  }
  return;
}
}

