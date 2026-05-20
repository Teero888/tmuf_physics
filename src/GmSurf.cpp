// Class implementation: GmSurf

// =================================================
// Function: GmSurf::ClipSegment
// =================================================
int __thiscall
GmSurf::ClipSegment(GmSurf *this,GmSurfSphere *param_1,GmVec3 *param_2,GmVec3 *param_3,
                   GmVec3 *param_4,float *param_5)
{
{
  int iVar1;
  GmMat3 *unaff_ESI;
  GmMat3 *unaff_EDI;
  GmVec3 *in_stack_0000001c;
  float *pfVar2;
  float local_10 [2];
  undefined1 local_8 [4];
  GmVec3 local_4 [4];
  
  if (param_3[6] == (GmVec3)0x0) {
    iVar1 = GmSurfSphere::ClipSegment
                      ((GmSurfSphere *)param_3,param_1,param_2,param_4 + 0x24,(GmVec3 *)param_5,
                       (float *)unaff_EDI);
    return iVar1;
  }
  if (param_3[6] != (GmVec3)0x7) {
    return 0;
  }
  pfVar2 = (float *)(*(float *)param_1 - *(float *)(param_4 + 0x24));
  local_10[0] = *(float *)(param_1 + 8) - *(float *)(param_4 + 0x2c);
  GmVec3::MultTranspose(&stack0xffffffe8,(GmMat3 *)param_4,unaff_ESI);
  GmVec3::SetMultTranspose(local_8,param_3,param_4,unaff_EDI);
  iVar1 = GmSurfMesh::ClipSegment
                    ((GmSurfMesh *)param_3,(GmSurfSphere *)local_10,local_4,in_stack_0000001c,
                     (GmVec3 *)0x0,pfVar2);
  return iVar1;
}
}

// =================================================
// Function: GmSurf::ClipSegment2
// =================================================
int __thiscall
GmSurf::ClipSegment2
          (GmSurf *this,GmSurfMesh *param_1,GmVec3 *param_2,GmVec3 *param_3,int param_4,
          float *param_5,GmVec3 *param_6)
{
{
  int iVar1;
  GmIso3 *unaff_EBX;
  GmVec3 *unaff_ESI;
  GmMat3 *unaff_EDI;
  GmMat3 *in_stack_0000001c;
  float local_18;
  float local_14;
  float local_10;
  float local_8;
  float local_4;
  
  if (param_6[6] != (GmVec3)0x7) {
    return 0;
  }
  local_18 = *(float *)param_1 - *(float *)(in_stack_0000001c + 0x24);
  local_14 = *(float *)(param_1 + 4) - *(float *)(in_stack_0000001c + 0x28);
  local_10 = *(float *)(param_1 + 8) - *(float *)(in_stack_0000001c + 0x2c);
  GmVec3::MultTranspose(&local_18,in_stack_0000001c,unaff_EDI);
  local_8 = *(float *)(in_stack_0000001c + 0x18) * *(float *)(param_3 + 8) +
            *(float *)param_3 * *(float *)in_stack_0000001c +
            *(float *)(in_stack_0000001c + 0xc) * *(float *)(param_3 + 4);
  local_4 = *(float *)(in_stack_0000001c + 0x1c) * *(float *)(param_3 + 8) +
            *(float *)(in_stack_0000001c + 4) * *(float *)param_3 +
            *(float *)(in_stack_0000001c + 0x10) * *(float *)(param_3 + 4);
  iVar1 = GmSurfMesh::ClipSegment2
                    ((GmSurfMesh *)param_6,(GmSurfMesh *)&local_14,(GmVec3 *)&local_8,
                     (GmVec3 *)param_4,(int)param_5,(float *)param_6,unaff_ESI);
  if (iVar1 != 0) {
    GmVec3::Mult(param_6,(GmIso3 *)in_stack_0000001c,unaff_EBX);
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: GmSurf::ClipSegment3
// =================================================
int __thiscall
GmSurf::ClipSegment3
          (GmSurf *this,GmSurfMesh *param_1,GmVec3 *param_2,GmVec3 *param_3,float *param_4,
          ushort *param_5)
{
{
  int iVar1;
  GmMat3 *unaff_ESI;
  GmMat3 *unaff_EDI;
  undefined2 *in_stack_00000018;
  GmVec3 *in_stack_0000001c;
  float *in_stack_00000020;
  ushort *puVar2;
  float local_10 [2];
  undefined1 local_8 [4];
  GmVec3 local_4 [4];
  
  if (param_3[6] == (GmVec3)0x0) {
    *in_stack_00000018 = *(undefined2 *)(param_3 + 4);
    iVar1 = GmSurfSphere::ClipSegment
                      ((GmSurfSphere *)param_3,(GmSurfSphere *)param_1,param_2,
                       (GmVec3 *)(param_4 + 9),(GmVec3 *)param_5,(float *)unaff_EDI);
    return iVar1;
  }
  if (param_3[6] != (GmVec3)0x7) {
    return 0;
  }
  puVar2 = (ushort *)(*(float *)param_1 - param_4[9]);
  local_10[0] = *(float *)(param_1 + 8) - param_4[0xb];
  GmVec3::MultTranspose(&stack0xffffffe8,(GmMat3 *)param_4,unaff_ESI);
  GmVec3::SetMultTranspose(local_8,param_3,(GmVec3 *)param_4,unaff_EDI);
  iVar1 = GmSurfMesh::ClipSegment3
                    ((GmSurfMesh *)param_3,(GmSurfMesh *)local_10,local_4,in_stack_0000001c,
                     in_stack_00000020,puVar2);
  return iVar1;
}
}

// =================================================
// Function: GmSurf::ComputeCollision
// =================================================
int __cdecl
GmSurf::ComputeCollision(LocatedGmSurf *param_1,LocatedGmSurf *param_2,CGmCollisionBuffer *param_3)
{
{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  float *pfVar5;
  
  if (*(byte *)(*(int *)param_1 + 6) <= *(byte *)(*(int *)param_2 + 6)) {
    iVar2 = (*(code *)(&DAT_00d706e0)
                      [(uint)*(byte *)(*(int *)param_1 + 6) * 9 +
                       (uint)*(byte *)(*(int *)param_2 + 6)])(param_1,param_2,param_3);
    return iVar2;
  }
  uVar3 = (**(code **)(*(int *)param_3 + 8))();
  iVar2 = (*(code *)(&DAT_00d706e0)
                    [(uint)*(byte *)(*(int *)param_2 + 6) * 9 + (uint)*(byte *)(*(int *)param_1 + 6)
                    ])(param_2,param_1,param_3);
  if (iVar2 == 0) {
    return 0;
  }
  uVar4 = (**(code **)(*(int *)param_3 + 8))();
  for (; uVar3 < uVar4; uVar3 = uVar3 + 1) {
    pfVar5 = (float *)(**(code **)(*(int *)param_3 + 4))(uVar3);
    pfVar5[3] = -pfVar5[3];
    pfVar5[4] = -pfVar5[4];
    pfVar5[5] = -pfVar5[5];
    uVar1 = *(undefined2 *)(pfVar5 + 9);
    *(undefined2 *)(pfVar5 + 9) = *(undefined2 *)((int)pfVar5 + 0x26);
    *pfVar5 = -*pfVar5;
    *(undefined2 *)((int)pfVar5 + 0x26) = uVar1;
    pfVar5[1] = -pfVar5[1];
    pfVar5[2] = -pfVar5[2];
    pfVar5[0xb] = -pfVar5[0xb];
    pfVar5[0xc] = -pfVar5[0xc];
    pfVar5[0xd] = -pfVar5[0xd];
  }
  return 1;
}
}

// =================================================
// Function: GmSurf::CreateDefaultData
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GmSurf::CreateDefaultData(GmSurf *this,CCrystal *param_1)
{
{
  GmSurf GVar1;
  undefined4 uVar2;
  
  GVar1 = this[6];
  if (GVar1 == (GmSurf)0x0) {
    *(undefined4 *)(this + 8) = 0x3f800000;
  }
  else {
    if (GVar1 == (GmSurf)0x1) {
      GmSurfEllipsoid::CreateEllipsoidDefaultData
                ((GmSurfEllipsoid *)this,(GmSurfEllipsoid *)param_1);
      return;
    }
    if (GVar1 == (GmSurf)0x6) {
      *(undefined4 *)(this + 0x10) = 0;
      *(undefined4 *)(this + 0xc) = 0;
      *(undefined4 *)(this + 8) = 0;
      uVar2 = _DAT_00b31460;
      *(undefined4 *)(this + 0x14) = _DAT_00b31460;
      *(undefined4 *)(this + 0x18) = uVar2;
      *(undefined4 *)(this + 0x1c) = uVar2;
      return;
    }
  }
  return;
}
}

// =================================================
// Function: GmSurf::GetBoundingBox
// =================================================
void __thiscall GmSurf::GetBoundingBox(GmSurf *this,GmSurf *param_1,GmBoxAligned *param_2)
{
{
  switch(this[6]) {
  case (GmSurf)0x0:
    GmSurfSphere::GetSphereBoundingBox((GmSurfSphere *)this,(GmSurfSphere *)param_1,param_2);
    return;
  case (GmSurf)0x1:
    GmSurfEllipsoid::GetEllipsoidBoundingBox
              ((GmSurfEllipsoid *)this,(GmSurfEllipsoid *)param_1,param_2);
    return;
  case (GmSurf)0x6:
    *(undefined4 *)param_1 = *(undefined4 *)(this + 8);
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(this + 0xc);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(this + 0x10);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(this + 0x14);
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(this + 0x18);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(this + 0x1c);
    break;
  case (GmSurf)0x7:
    GmSurfMesh::GetMeshBoundingBox((GmSurfMesh *)this,(GmSurfMesh *)param_1,param_2);
    return;
  }
  return;
}
}

// =================================================
// Function: GmSurf::GmSurf
// =================================================
void __thiscall GmSurf::GmSurf(GmSurf *this,GmSurf *param_1)
{
{
  *(undefined ***)this = vftable;
  this[6] = (GmSurf)0xff;
  *(undefined2 *)(this + 4) = 0;
  return;
}
}

// =================================================
// Function: GmSurf::StaticInit
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl GmSurf::StaticInit(void)
{
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00d706e0;
  for (iVar1 = 0x51; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = CSystemFile_testerror;
    puVar2 = puVar2 + 1;
  }
  DAT_00d706e4 = GmCollision_Sphere_Ellipsoid;
  _DAT_00d70704 = GmCollision_Sphere_Ellipsoid;
  _DAT_00d706f8 = GmCollision_Sphere_Box;
  _DAT_00d707b8 = GmCollision_Sphere_Box;
  _DAT_00d706f4 = GmCollision_Sphere_Polygon;
  _DAT_00d70794 = GmCollision_Sphere_Polygon;
  _DAT_00d70718 = GmCollision_Ellipsoid_Polygon;
  _DAT_00d70798 = GmCollision_Ellipsoid_Polygon;
  _DAT_00d706fc = GmCollision_Sphere_Mesh;
  _DAT_00d707dc = GmCollision_Sphere_Mesh;
  _DAT_00d70720 = GmCollision_Ellipsoid_Mesh;
  _DAT_00d707e0 = GmCollision_Ellipsoid_Mesh;
  DAT_00d706e0 = GmCollision_Sphere_Sphere;
  _DAT_00d707d0 = GmCollision_Box_Box;
  _DAT_00d707f8 = GmCollision_Mesh_Mesh;
  _DAT_00d707d4 = GmCollision_Box_Mesh;
  _DAT_00d707f4 = GmCollision_Box_Mesh;
  return;
}
}

