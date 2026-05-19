// Reconstructed from ghidra/CHmsDyna.cpp logic

#ifndef CHMSDYNA_HPP
#define CHMSDYNA_HPP

#include "typedefs.h"
#include "CHmsStateDyna.hpp"

class CHmsDyna {
public:
  // Padding/Unknown
  char m_Unknown_0[0x108];   // Offset 0x000

  void* m_InertiaInfo;       // Offset 0x108 (judging by pfVar10 = iVar6 + 0x38 usage)
  CHmsStateDyna m_State1;    // Offset 0x10c
  CHmsStateDyna m_State2;    // Offset 0x1c0
  
  // After states
  CHmsStateDyna* m_PrevState; // Offset 0x328
  CHmsStateDyna* m_State;     // Offset 0x32c
  
  // Buffers
  // CFastBuffer m_Buffer;   // Offset 0x330
  // CFastBufferWheel m_History; // Offset 0x344
};

#endif // CHMSDYNA_HPP
