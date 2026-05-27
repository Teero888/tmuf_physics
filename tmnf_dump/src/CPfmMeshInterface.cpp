// Class implementation: CPfmMeshInterface

// =================================================
// Function: CPfmMeshInterface::AddCell
// =================================================
void __thiscall
CPfmMeshInterface::AddCell
          (CPfmMeshInterface *this,CPfmMesh *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4
          )
{
{
  CPfmMesh::AddCell(*(CPfmMesh **)(this + 4),param_1,param_2,param_3,param_4);
  return;
}
}

// =================================================
// Function: CPfmMeshInterface::Clear
// =================================================
void __thiscall CPfmMeshInterface::Clear(CPfmMeshInterface *this,TiXmlNode *param_1)
{
{
  CPfmMesh::Clear(*(CPfmMesh **)(this + 4),param_1);
  return;
}
}

// =================================================
// Function: CPfmMeshInterface::LinkCells
// =================================================
void __thiscall CPfmMeshInterface::LinkCells(CPfmMeshInterface *this,CPfmMesh *param_1)
{
{
  CPfmMesh::LinkCells(*(CPfmMesh **)(this + 4),param_1);
  return;
}
}

