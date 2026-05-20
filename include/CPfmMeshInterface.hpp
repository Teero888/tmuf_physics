#ifndef CPFMMESHINTERFACE_HPP
#define CPFMMESHINTERFACE_HPP

#include "typedefs.h"

struct CPfmMesh;

struct CPfmMeshInterface {
    byte _padding_0x0[4];
    CPfmMesh * field_0x4; // accesses: 3

    // Member Functions
    void __thiscall AddCell (CPfmMeshInterface *this,CPfmMesh *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4 );
    void __thiscall Clear(CPfmMeshInterface *this,TiXmlNode *param_1);
    void __thiscall LinkCells(CPfmMeshInterface *this,CPfmMesh *param_1);
};

#endif // CPFMMESHINTERFACE_HPP
