// Class implementation: CMwStatsValue

// =================================================
// Function: CMwStatsValue::SetSize
// =================================================
void __thiscall CMwStatsValue::SetSize(CMwStatsValue *this,CMwStatsValue *param_1,ulong param_2)
{
{
  CFastBufferWheel<float>::SetCountLimit(this + 0x6c,(CFastBufferWheel<float> *)param_1,param_2);
  return;
}
}

