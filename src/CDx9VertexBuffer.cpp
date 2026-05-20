// Class implementation: CDx9VertexBuffer

// =================================================
// Function: CDx9VertexBuffer::Create
// =================================================
void __thiscall CDx9VertexBuffer::Create(void *this,CDx9VertexBuffer *param_1)
{
{
  CDx9VertexBuffer *unaff_retaddr;
  int in_stack_00000008;
  uint in_stack_0000000c;
  
  *(CDx9VertexBuffer **)this = param_1;
  *(int *)((int)this + 4) = (int)param_1 * in_stack_00000008;
  *(int *)((int)this + 8) = (int)param_1 * in_stack_00000008;
  *(undefined4 *)((int)this + 0x10) = 1;
  *(uint *)((int)this + 0xc) = in_stack_0000000c | 8;
  Create(this,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CDx9VertexBuffer::Release
// =================================================
void __thiscall CDx9VertexBuffer::Release(void *this,CDx9VStreamKeeper *param_1)
{
{
  int *piVar1;
  
  piVar1 = *(int **)((int)this + 0x14);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)((int)this + 0x14) = 0;
    *(int *)(DAT_00d75af4 + 0x21c) = *(int *)(DAT_00d75af4 + 0x21c) + -1;
  }
  return;
}
}

// =================================================
// Function: CDx9VertexBuffer::~CDx9VertexBuffer
// =================================================
void __thiscall CDx9VertexBuffer::~CDx9VertexBuffer(void *this,CDx9VertexBuffer *param_1)
{
{
  int *piVar1;
  
  piVar1 = *(int **)((int)this + 0x14);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)((int)this + 0x14) = 0;
    *(int *)(DAT_00d75af4 + 0x21c) = *(int *)(DAT_00d75af4 + 0x21c) + -1;
  }
  return;
}
}

