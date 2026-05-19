// Reconstructed from ghidra/CHmsDyna.cpp logic (AddForce, Reset, RestoreState)
// and ghidra/CHmsCorpus.cpp (ComputeCurrentState)

#ifndef CHMSSTATEDYNA_HPP
#define CHMSSTATEDYNA_HPP

#include "typedefs.h"
#include "GmQuat.hpp"
#include "GmIso4.hpp"
#include "GmVec3.hpp"

struct CHmsStateDyna {
  GmQuat m_Rotation;        // Offset 0x00
  GmIso4 m_Location;        // Offset 0x10 (contains GmMat3 at 0x10 and GmVec3 at 0x34)
  GmVec3 m_LinearSpeed;     // Offset 0x40
  GmVec3 m_LinearAccel;     // Offset 0x4c
  GmVec3 m_AngularSpeed;    // Offset 0x58
  GmVec3 m_Force;           // Offset 0x64
  GmVec3 m_Torque;          // Offset 0x70
  
  float m_Unknown_7c[9];    // Offset 0x7c (36 bytes = 3 GmVec3?)
  GmQuat m_Unknown_a0;      // Offset 0xa0 (16 bytes)
  class CHmsDyna* m_Dyna;   // Offset 0xb0 (4 bytes, points back to owner)
};

#endif // CHMSSTATEDYNA_HPP
