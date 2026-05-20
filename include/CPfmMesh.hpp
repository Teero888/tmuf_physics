#ifndef CPFMMESH_HPP
#define CPFMMESH_HPP

#include "typedefs.h"

struct CPfmMesh {

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall AddCell(CPfmMesh *this,CPfmMesh *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4);
    void __thiscall Clear(CPfmMesh *this,TiXmlNode *param_1);
    void __thiscall LinkCells(CPfmMesh *this,CPfmMesh *param_1);
};

#endif // CPFMMESH_HPP
