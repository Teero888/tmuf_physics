// Class implementation: CClassicBufferRef

// =================================================
// Function: CClassicBufferRef::CClassicBufferRef
// =================================================
void __thiscall CClassicBufferRef::CClassicBufferRef(void *this,CClassicBufferRef *param_1)
{
{
  CClassicBufferMemory *pCVar1;
  
  pCVar1 = sBufferMemoryGetNew();
  *(CClassicBufferMemory **)this = pCVar1;
  return;
}
}

// =================================================
// Function: CClassicBufferRef::~CClassicBufferRef
// =================================================
void __thiscall CClassicBufferRef::~CClassicBufferRef(void *this,CClassicBufferRef *param_1)
{
{
  sBufferMemoryFree(this);
  return;
}
}

