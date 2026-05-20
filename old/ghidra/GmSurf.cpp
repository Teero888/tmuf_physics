
/* public: static int __cdecl GmSurf::ClipSegment(class GmVec3 const &,class
   GmVec3 const &,class GmSurf const &,class GmIso4 const &,float &) */

int __cdecl GmSurf::ClipSegment(GmVec3 *param_1, GmVec3 *param_2,
                                GmSurf *param_3, GmIso4 *param_4,
                                float *param_5)

{
  int iVar1;
  float local_18;
  float local_14;
  float local_10;
  GmVec3 local_c[12];

  if (param_3[6] == (GmSurf)0x0) {
    iVar1 = GmSurfSphere::ClipSegment((GmSurfSphere *)param_3, param_1, param_2,
                                      (GmVec3 *)(param_4 + 0x24), param_5);
    return iVar1;
  }
  if (param_3[6] != (GmSurf)0x7) {
    return 0;
  }
  local_18 = *(float *)param_1 - *(float *)(param_4 + 0x24);
  local_14 = *(float *)(param_1 + 4) - *(float *)(param_4 + 0x28);
  local_10 = *(float *)(param_1 + 8) - *(float *)(param_4 + 0x2c);
  GmVec3::MultTranspose((GmVec3 *)&local_18, (GmMat3 *)param_4);
  GmVec3::SetMultTranspose(local_c, param_2, (GmMat3 *)param_4);
  iVar1 = GmSurfMesh::ClipSegment((GmSurfMesh *)param_3, (GmVec3 *)&local_18,
                                  local_c, param_5, (SPointInTri *)0x0);
  return iVar1;
}

/* public: static int __cdecl GmSurf::ClipSegment2(class GmVec3 const &,class
   GmVec3 const
   &,int,float &,class GmVec3 &,class GmSurf const &,class GmIso4 const &) */

int __cdecl GmSurf::ClipSegment2(GmVec3 *param_1, GmVec3 *param_2, int param_3,
                                 float *param_4, GmVec3 *param_5,
                                 GmSurf *param_6, GmIso4 *param_7)

{
  int iVar1;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  if (param_6[6] != (GmSurf)0x7) {
    return 0;
  }
  local_18 = *(float *)param_1 - *(float *)(param_7 + 0x24);
  local_14 = *(float *)(param_1 + 4) - *(float *)(param_7 + 0x28);
  local_10 = *(float *)(param_1 + 8) - *(float *)(param_7 + 0x2c);
  GmVec3::MultTranspose((GmVec3 *)&local_18, (GmMat3 *)param_7);
  local_c = *(float *)(param_7 + 0x18) * *(float *)(param_2 + 8) +
            *(float *)param_2 * *(float *)param_7 +
            *(float *)(param_7 + 0xc) * *(float *)(param_2 + 4);
  local_8 = *(float *)(param_7 + 0x1c) * *(float *)(param_2 + 8) +
            *(float *)(param_7 + 4) * *(float *)param_2 +
            *(float *)(param_7 + 0x10) * *(float *)(param_2 + 4);
  local_4 = *(float *)(param_7 + 0x20) * *(float *)(param_2 + 8) +
            *(float *)(param_7 + 8) * *(float *)param_2 +
            *(float *)(param_7 + 0x14) * *(float *)(param_2 + 4);
  iVar1 =
      GmSurfMesh::ClipSegment2((GmSurfMesh *)param_6, (GmVec3 *)&local_18,
                               (GmVec3 *)&local_c, param_3, param_4, param_5);
  if (iVar1 != 0) {
    GmVec3::Mult(param_5, (GmMat3 *)param_7);
    return 1;
  }
  return 0;
}

/* public: static int __cdecl GmSurf::ClipSegment3(class GmVec3 const &,class
   GmVec3 const &,class GmSurf const &,class GmIso4 const &,float &,unsigned
   short &) */

int __cdecl GmSurf::ClipSegment3(GmVec3 *param_1, GmVec3 *param_2,
                                 GmSurf *param_3, GmIso4 *param_4,
                                 float *param_5, ushort *param_6)

{
  int iVar1;
  float local_18;
  float local_14;
  float local_10;
  GmVec3 local_c[12];

  if (param_3[6] == (GmSurf)0x0) {
    *param_6 = *(ushort *)(param_3 + 4);
    iVar1 = GmSurfSphere::ClipSegment((GmSurfSphere *)param_3, param_1, param_2,
                                      (GmVec3 *)(param_4 + 0x24), param_5);
    return iVar1;
  }
  if (param_3[6] != (GmSurf)0x7) {
    return 0;
  }
  local_18 = *(float *)param_1 - *(float *)(param_4 + 0x24);
  local_14 = *(float *)(param_1 + 4) - *(float *)(param_4 + 0x28);
  local_10 = *(float *)(param_1 + 8) - *(float *)(param_4 + 0x2c);
  GmVec3::MultTranspose((GmVec3 *)&local_18, (GmMat3 *)param_4);
  GmVec3::SetMultTranspose(local_c, param_2, (GmMat3 *)param_4);
  iVar1 = GmSurfMesh::ClipSegment3((GmSurfMesh *)param_3, (GmVec3 *)&local_18,
                                   local_c, param_5, param_6);
  return iVar1;
}

/* public: static int __cdecl GmSurf::ComputeCollision(struct LocatedGmSurf
   const &,struct LocatedGmSurf const &,struct CGmCollisionBuffer &) */

int __cdecl GmSurf::ComputeCollision(LocatedGmSurf *param_1,
                                     LocatedGmSurf *param_2,
                                     CGmCollisionBuffer *param_3)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  float *pfVar5;

  if (*(byte *)(*(int *)param_1 + 6) <= *(byte *)(*(int *)param_2 + 6)) {
    iVar2 = (*(
        code *)(&m_CollisionFuncTable)[(uint) * (byte *)(*(int *)param_1 + 6) *
                                           9 +
                                       (uint) * (byte *)(*(int *)param_2 + 6)])(
        param_1, param_2, param_3);
    return iVar2;
  }
  uVar3 = (**(code **)(*(int *)param_3 + 8))();
  iVar2 = (*(
      code
          *)(&m_CollisionFuncTable)[(uint) * (byte *)(*(int *)param_2 + 6) * 9 +
                                    (uint) * (byte *)(*(int *)param_1 + 6)])(
      param_2, param_1, param_3);
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

/* public: void __thiscall GmSurf::CreateDefaultData(void) */

void __thiscall GmSurf::CreateDefaultData(GmSurf *this)

{
  GmSurf GVar1;

  GVar1 = this[6];
  if (GVar1 == (GmSurf)0x0) {
    *(undefined4 *)(this + 8) = 0x3f800000;
  } else {
    if (GVar1 == (GmSurf)0x1) {
      GmSurfEllipsoid::CreateEllipsoidDefaultData((GmSurfEllipsoid *)this);
      return;
    }
    if (GVar1 == (GmSurf)0x6) {
      *(undefined4 *)(this + 0x10) = 0;
      *(undefined4 *)(this + 0xc) = 0;
      *(undefined4 *)(this + 8) = 0;
      *(undefined4 *)(this + 0x14) = 0x3f000000;
      *(undefined4 *)(this + 0x18) = 0x3f000000;
      *(undefined4 *)(this + 0x1c) = 0x3f000000;
      return;
    }
  }
  return;
}

/* public: void __thiscall GmSurf::GetBoundingBox(class GmBoxAligned &)const  */

void __thiscall GmSurf::GetBoundingBox(GmSurf *this, GmBoxAligned *param_1)

{
  switch (this[6]) {
  case (GmSurf)0x0:
    GmSurfSphere::GetSphereBoundingBox((GmSurfSphere *)this, param_1);
    return;
  case (GmSurf)0x1:
    GmSurfEllipsoid::GetEllipsoidBoundingBox((GmSurfEllipsoid *)this, param_1);
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
    GmSurfMesh::GetMeshBoundingBox((GmSurfMesh *)this, param_1);
    return;
  }
  return;
}

/* public: __thiscall GmSurf::GmSurf(void) */

void __thiscall GmSurf::GmSurf(GmSurf *this)

{
  *(undefined ***)this = vftable;
  this[6] = (GmSurf)0xff;
  *(undefined2 *)(this + 4) = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: static void __cdecl GmSurf::StaticInit(void) */

void __cdecl GmSurf::StaticInit(void)

{
  int iVar1;
  _func_int_LocatedGmSurf_ptr_LocatedGmSurf_ptr_CGmCollisionBuffer_ptr **
      *ppp_Var2;

  ppp_Var2 = &m_CollisionFuncTable;
  for (iVar1 = 0x51; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppp_Var2 =
        (_func_int_LocatedGmSurf_ptr_LocatedGmSurf_ptr_CGmCollisionBuffer_ptr *
             *)__InitClassInfo_CFuncShader;
    ppp_Var2 = ppp_Var2 + 1;
  }
  _DAT_00d706e4 = GmCollision_Sphere_Ellipsoid;
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
  m_CollisionFuncTable =
      (_func_int_LocatedGmSurf_ptr_LocatedGmSurf_ptr_CGmCollisionBuffer_ptr **)
          GmCollision_Sphere_Sphere;
  _DAT_00d707d0 = GmCollision_Box_Box;
  _DAT_00d707f8 = GmCollision_Mesh_Mesh;
  _DAT_00d707d4 = GmCollision_Box_Mesh;
  _DAT_00d707f4 = GmCollision_Box_Mesh;
  return;
}

/* public: virtual __thiscall GmSurf::~GmSurf(void) */

void __thiscall GmSurf::~GmSurf(GmSurf *this)

{
  *(undefined ***)this = vftable;
  return;
}
