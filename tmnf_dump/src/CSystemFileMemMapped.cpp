// Class implementation: CSystemFileMemMapped

// =================================================
// Function: CSystemFileMemMapped::Close
// =================================================
void __thiscall CSystemFileMemMapped::Close(CSystemFileMemMapped *this,CClassicLog *param_1)
{
{
  if (*(LPCVOID *)(this + 0x24) != (LPCVOID)0x0) {
    UnmapViewOfFile(*(LPCVOID *)(this + 0x24));
    *(undefined4 *)(this + 0x24) = 0;
  }
  if (*(HANDLE *)(this + 0x1c) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(this + 0x1c));
    *(undefined4 *)(this + 0x1c) = 0;
  }
  if (*(HANDLE *)(this + 0x20) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(this + 0x20));
    *(undefined4 *)(this + 0x20) = 0;
  }
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  return;
}
}

// =================================================
// Function: CSystemFileMemMapped::GetActualSize
// =================================================
ulong __thiscall
CSystemFileMemMapped::GetActualSize(CSystemFileMemMapped *this,CClassicBufferMemory *param_1)
{
{
  return *(ulong *)(this + 0x18);
}
}

