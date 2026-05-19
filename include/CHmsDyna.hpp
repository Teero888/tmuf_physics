// PDB Verified Layout (from TmForeverFixed.pdb and Ghidra logic cross-ref)

#ifndef CHMSDYNA_HPP
#define CHMSDYNA_HPP

#include "typedefs.h"
#include "CHmsStateDyna.hpp"

#pragma pack(push, 4)
class CHmsDyna {
public:
  uint m_VTable;             // 0x00
  uint m_Unknown_04;         // 0x04
  uint m_Unknown_08;         // 0x08
  
  CHmsStateDyna m_State0;    // Offset 0x0c (Length 0xb8)
  
  char m_Unknown_padding0[0x4c]; // 0x110 - (0x0c + 0xb8) = 0x4c
                             
  CHmsStateDyna m_State1;    // Offset 0x110 (Length 0xb8)
  CHmsStateDyna m_State2;    // Offset 0x1c8 (Length 0xb8)
  
  char m_Unknown_padding1[0xb4]; // 0x334 - (0x1c8 + 0xb8) = 0xb4
  
  CHmsStateDyna* m_PrevState; // Offset 0x334
  CHmsStateDyna* m_State;     // Offset 0x33c
  
  char m_Buffer[0x14];       // Offset 0x344
  char m_History[0x14];      // Offset 0x358
};
#pragma pack(pop)

#endif // CHMSDYNA_HPP
