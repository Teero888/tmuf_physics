// PDB Verified Layout (from TmForeverFixed.pdb and Ghidra logic cross-ref)

#ifndef CHMSSTATEDYNA_HPP
#define CHMSSTATEDYNA_HPP

#include "typedefs.h"
#include "GmQuat.hpp"
#include "GmMat3.hpp"
#include "GmVec3.hpp"

class CHmsDyna;

#pragma pack(push, 4)
struct CHmsStateDyna {
  GmQuat m_Rotation;        // Offset 0x00
  GmMat3 m_Orientation;     // Offset 0x10
  GmVec3 m_Position;        // Offset 0x34
  GmVec3 m_LinearSpeed;     // Offset 0x40
  GmVec3 m_LinearAccel;     // Offset 0x4c
  GmVec3 m_AngularSpeed;    // Offset 0x58
  GmVec3 m_Force;           // Offset 0x64
  GmVec3 m_Torque;          // Offset 0x70
  
  float m_Unknown_7c[13];   // Offset 0x7c (52 bytes)
  CHmsDyna* m_Dyna;         // Offset 0xb0
};
#pragma pack(pop)

#endif // CHMSSTATEDYNA_HPP
