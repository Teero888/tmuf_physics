#include "CSceneVehicleCar.hpp"
#include "CSceneVehicleCarTuning.hpp"
#include "CHmsItem.hpp"
#include <cmath>
#include <cstdint>

struct DummyCast {
    void* ptr;
    DummyCast(void* p) : ptr(p) {}
    template<typename T> operator T*() { return (T*)ptr; }
    operator size_t() { return (size_t)ptr; }
    operator int() { return (int)(size_t)ptr; }
    operator float() { 
        // Ghidra sometimes stores pointers in float variables on the stack.
        // We just bitcast the pointer to float to bypass the type system.
        union { size_t s; float f; } u; 
        u.s = (size_t)ptr; 
        return u.f; 
    }
};

template<typename T, typename DummyType>
DummyCast DUMMY_CFAST_CALL(CFastBuffer<T>* buffer, DummyType, uint32_t index) {
    if (!buffer || index >= buffer->GetCount()) return DummyCast(nullptr);
    return DummyCast((void*)&(*buffer)[index]);
}
template<typename T, typename DummyType>
DummyCast DUMMY_CFAST_CALL(CFastArray<T>* buffer, DummyType, uint32_t index) {
    if (!buffer || index >= buffer->GetCount()) return DummyCast(nullptr);
    return DummyCast((void*)&(*buffer)[index]);
}
template<typename DummyType>
inline DummyCast DUMMY_CFAST_CALL(void* ptr, DummyType, uint32_t index) {
    if (!ptr) return DummyCast(nullptr);
    void** data_ptr = (void**)((char*)ptr + 8);
    if (!*data_ptr) return DummyCast(nullptr);
    return DummyCast((void*)&((void**)*data_ptr)[index]);
}

void CSceneVehicleCar::ComputeForcesModel3_Exact(CSceneVehicleCar *param_1,float param_2,GmVec3 *param_3, float param_4,float param_5,GmVec3 *param_6,GmVec3 *param_7,float param_8,int param_9, void *param_10,int *param_11,float *param_12)
{

    float fVar13=0, fVar14=0, fVar15=0, fVar19=0, fVar20=0, fStack_4=0, fStack_c=0;
    float extraout_ST0=0, extraout_ST0_00=0, extraout_ST0_01=0;
    double dVar24=0;
    GmVec3 unaff_EBP(0,0,0), unaff_EBX(0,0,0), in_stack_ffffff94(0,0,0);
    GmVec3 in_stack_ffffffd4(0,0,0), in_stack_ffffffe0(0,0,0), in_stack_ffffffcc(0,0,0);
    CSceneVehicleCar::SSimulationWheel* pSVar7 = nullptr;
    CSceneVehicleCar::SSimulationWheel* pSVar10 = nullptr;
    CSceneVehicleCar* pCVar3 = nullptr;
    CSceneVehicleCarTuning* pCVar4 = nullptr;
    void* pSVar8 = nullptr;
    void* pCVar6 = nullptr;
    void* pCVar21 = nullptr;
    void* pCVar17 = nullptr;
    void* pGVar11 = nullptr;
    void* in_stack_ffffffa0 = nullptr;
    void* in_stack_ffffff98 = nullptr;
    void* unaff_EDI = nullptr;
    uint32_t unaff_ESI = 0;
    int iVar1=0, iVar9=0;
    float* pfVar22 = nullptr;
    float* in_stack_00000064 = nullptr;
    float* in_stack_00000068 = nullptr;
    int* in_stack_0000005c = nullptr;
    int* in_stack_0000003c = nullptr;
    
    float in_stack_ffffffb8=0, in_stack_ffffffbc=0, in_stack_ffffffc0=0, in_stack_ffffffa8=0;
    float in_stack_ffffffb4=0, in_stack_ffffffc8=0, in_stack_ffffffd0=0, in_stack_ffffffd8=0;
    float in_stack_ffffffdc=0;
    GmVec3 stack0xffffffa4(0,0,0);
    GmVec3 fStack_18(0,0,0);
    GmVec3 fStack_10(0,0,0);
    GmVec3 pGVar18(0,0,0);
    float in_stack_ffffff70=0;
    char* pGVar5 = nullptr;
    float in_stack_00000070=0;
    float in_stack_00000050=0, in_stack_00000058=0;
    
    uint32_t uStack00000034=0, in_stack_00000074=0, in_stack_ffffff64=0, in_stack_ffffff6c=0;
    uint32_t in_stack_ffffff74=0, in_stack_ffffff78=0, in_stack_ffffff7c=0, uVar16=0;
    uint32_t in_stack_ffffffac=0, uVar23=0, in_stack_ffffffb0=0;
    void* in_stack_ffffffc4 = nullptr;
    void* pSStack00000080 = nullptr;
    void* this_00 = nullptr;
    float fStack_8=0, fStack_14=0;
    bool bVar2 = false;
    float in_stack_00000040=0, in_stack_00000048=0, in_stack_00000044=0, in_stack_00000054=0, in_stack_00000060=0, fStack0000004c=0;
    float in_stack_00000038=0;
        
{
  
  pGVar5 = (char*)param_6;
  pCVar6 = (void*)0; //
  dVar24 = 0;
  pCVar21 = (void*)0;
  if (pCVar6 != nullptr) {
    do {
      pSVar7 = DUMMY_CFAST_CALL
                         (&this->m_wheels,pCVar21,(uint32_t)(size_t)unaff_ESI);
      uVar23 = 0;
      fVar15 = 1.1723283e-38;
      pSVar10 = pSVar7;
      // WheelAddForce
      unaff_ESI = 1.1723305e-38;
      pSVar8 = DUMMY_CFAST_CALL
                         (&this->m_manoeuvres,
                          (void*)
                          (uint32_t)*(uint16_t*)((char*)(size_t)pSVar7 + 0x128),(uint32_t)(*(size_t*)&unaff_EBX));
      unaff_EBX = GmVec3(0,0,0);
      unaff_EBP = GmVec3(0,0,0);
      pSVar8 = DUMMY_CFAST_CALL
                         ((void *)(*(int*)((char*)(size_t)((char*)(size_t)this + 0x68)) + 0x14),unaff_EBX,(uint32_t)(*(size_t*)&in_stack_ffffff94))
      ;
      iVar9 = *(int*)(size_t)pSVar8 + 0x14;
      dVar24 = (double)(size_t)(uint64_t)(size_t)(iVar9,uVar23);
      if (*(int*)((char*)(size_t)pSVar7 + 0x124) != 0) {
        iVar1 = (int)(size_t)this->m_field_64;
        in_stack_ffffff94 = GmVec3(0,0,0);
        unaff_EBX = GmVec3(0,0,0);
        pSVar8 = DUMMY_CFAST_CALL
                           ((void *)(iVar1 + 0x14),in_stack_ffffff94,(uint32_t)(size_t)in_stack_ffffff98);
        dVar24 = (double)(size_t)(uint64_t)(size_t)(iVar9,uVar23);
        fVar13 = *(float *)(*(int*)(size_t)pSVar8 + 0xa4);
        if (!std::isnan(fVar13) && 0.0 < fVar13 != (fVar13 == 0.0)) {
          in_stack_ffffff98 = *(void**)(iVar1 + 0x24);
          in_stack_ffffff94 = GmVec3(0,0,0);
          pSVar8 = DUMMY_CFAST_CALL
                             ((void *)(iVar1 + 0x14),in_stack_ffffff98,(uint32_t)(size_t)pCVar21);
          dVar24 = (double)(size_t)(uint64_t)(size_t)(iVar9,uVar23);
          if (*(int *)(*(int*)(size_t)pSVar8 + 0x354) != 0) {
            pCVar21 = *(void**)(iVar1 + 0x24);
            in_stack_ffffff98 = (void*)0;
            pSVar8 = DUMMY_CFAST_CALL
                               ((void *)(iVar1 + 0x14),pCVar21,(uint32_t)(size_t)in_stack_ffffffa0);
            dVar24 = (double)(size_t)(uint64_t)(size_t)(iVar9,uVar23);
            if (*(int *)(*(int*)(size_t)pSVar8 + 0x354) == 1) {
              if (*(int*)((char*)(size_t)pSVar7 + 300) == 0) {
                fStack_c = 1.0;
              }
              else {
                in_stack_ffffffa0 =
                     *(void**)(iVar1 + 0x24);
                pCVar21 = (void*)0;
                pSVar8 = DUMMY_CFAST_CALL
                                   ((void *)(iVar1 + 0x14),in_stack_ffffffa0,(uint32_t)(size_t)pCVar6);
                fStack_c = *(float *)(*(int*)(size_t)pSVar8 + 0xb0);
              }
              pSVar8 = DUMMY_CFAST_CALL
                                 ((void *)(iVar1 + 0x14),
                                  *(void**)(iVar1 + 0x24)
                                  ,in_stack_ffffff64);
              fVar13 = ((CSceneVehicleCarTuning*)this->m_field_64)->GetMaxSideFrictionFromSpeed(in_stack_00000068);
              fVar13 = *(float*)((char*)(size_t)pSVar10 + 0xc) * fStack_c * fVar13 * fStack_4;
              fVar14 = *(float*)((char*)(size_t)pSVar7 + 0x148) - *(float*)((char*)(size_t)pSVar7 + 0x14c) * 0.0;
              fVar19 = *(float*)((char*)(size_t)pSVar7 + 0x14c) * 0.0 - *(float*)((char*)(size_t)pSVar7 + 0x144);
              fVar20 = *(float*)((char*)(size_t)pSVar7 + 0x144) * 0.0 - *(float*)((char*)(size_t)pSVar7 + 0x148) * 0.0;
              fStack_4 = fVar20 * fVar20 + fVar14 * fVar14 + fVar19 * fVar19;
              if (fStack_4 <= 0.0001f) {
                unaff_EBP = GmVec3(0,0,0);
                in_stack_ffffff94 = GmVec3(0,0,0);
                unaff_EBX = GmVec3(0,0,0);
              }
              else {
                fVar19 = (float)(size_t)1.0f;
                fStack_4 = 1.0 / (float)(size_t)fVar19;
                unaff_EBP = GmVec3(0,0,0);
                unaff_EBX = GmVec3(0,0,0);
                in_stack_ffffff94 =
                     GmVec3(0,0,0);
              }
              if (*(int*)((char*)(size_t)pSVar7 + 4) != 0) {
                extraout_ST0 = std::cos(0.0f);
                fStack_4 = (float)(size_t)extraout_ST0;
                in_stack_ffffffb8 = fStack_4 * (float)(*(size_t*)&unaff_EBP);
                in_stack_ffffffbc = fStack_4 * (float)(*(size_t*)&unaff_EBX);
                in_stack_ffffffc0 = fStack_4 * (float)(*(size_t*)&in_stack_ffffff94);
                extraout_ST0_00 = std::sin(0.0f); extraout_ST0_01 = std::sin(0.0f);
                in_stack_ffffffb4 = (float)(size_t)extraout_ST0_00;
                fStack_4 = 0;
                unaff_EBP = GmVec3(0,0,0);
                unaff_EBX = GmVec3(0,0,0);
                in_stack_ffffff94 =
                     GmVec3(0,0,0);
              }
              in_stack_ffffffc4 = *(void**)param_6;
              iVar9 = (int)(size_t)this->m_field_64;
              in_stack_ffffffc8 = *(float*)((char*)(size_t)param_6 + 4);
              in_stack_ffffffcc = *(GmVec3*)(param_6 + 8);
              in_stack_ffffff64 = 0x7faa50;
              pSVar8 = DUMMY_CFAST_CALL
                                 ((void *)(iVar9 + 0x14),
                                  *(void**)((char*)(size_t)iVar9 + 0x24)
                                  ,in_stack_ffffff6c);
              pCVar3 = (CSceneVehicleCar *)(size_t)
                       (-*(float *)(*(int*)(size_t)pSVar8 + 0xa4) * (float)(size_t)1.0f *
                       (in_stack_ffffffd0 * (float)(size_t)in_stack_ffffff98 +
                       (float)(*(size_t*)&in_stack_ffffffcc) * (float)(*(size_t*)&in_stack_ffffff94) +
                       in_stack_ffffffc8 * (float)(*(size_t*)&unaff_EBX)));
              unaff_ESI = std::abs((float)(size_t)pCVar3);
              if (unaff_ESI <= fVar15) {
                *(uint32_t*)((char*)(size_t)pSVar7 + 300) = 0;
              }
              else {
                pSVar8 = DUMMY_CFAST_CALL
                                   ((void *)(iVar9 + 0x14),
                                    *(void**)
                                     (iVar9 + 0x24),(uint32_t)(size_t)in_stack_ffffff70);
                unaff_EBP = *(GmVec3*)(*(int*)(size_t)pSVar8 + 0xb4);
                pSVar8 = pSVar10;
                if ((float)(size_t)0 <= 0.0) {
                  pSVar8 = (void *)(size_t)-(float)(size_t)pSVar10;
                }
                *(uint32_t*)((char*)(size_t)pSVar7 + 300) = 1;
                pCVar3 = (CSceneVehicleCar *)(size_t)
                         ((1.0 - (float)(*(size_t*)&unaff_EBP)) * (float)(size_t)0 +
                         (float)(*(size_t*)&unaff_EBP) * (float)(size_t)0);
                param_1 = pCVar3;
              }
              if (*(int*)((char*)(size_t)pSVar7 + 300) != 0) {
                *(uint32_t*)(size_t)param_5 = 1;
              }
              pCVar6 = (void*)0; //
                       ((float)(*(size_t*)&unaff_EBX) * (float)(size_t)pCVar3);
              in_stack_ffffffa8 = (float)(*(size_t*)&in_stack_ffffff94) * (float)(size_t)pCVar3;
              in_stack_00000068 = (float*)(size_t)0;
              // AddVehicleCentralForce
              iVar9 = (int)(size_t)this->m_field_64;
              in_stack_ffffff6c = 0x7fab76;
              pSVar7 = DUMMY_CFAST_CALL
                                 ((void *)(iVar9 + 0x14),
                                  *(void**)((char*)(size_t)iVar9 + 0x24)
                                  ,in_stack_ffffff74);
              this_00 = *(CSceneVehicleCarTuning ***)(size_t)pSVar7;
              in_stack_ffffff70 = 0;
              pSVar7 = DUMMY_CFAST_CALL
                                 ((void *)(iVar9 + 0x14),
                                  *(void**)((char*)(size_t)iVar9 + 0x24)
                                  ,in_stack_ffffff78);
              pCVar4 = (CSceneVehicleCarTuning *)(size_t)std::abs((float)(size_t)in_stack_ffffffa0);
              in_stack_ffffff74 = 0x7faba5;
              fVar13 = ((CSceneVehicleCarTuning*)this->m_field_64)->GetRolloverLateralCoefFromAngle
                                 (*(CSceneVehicleCarTuning ***)(size_t)pSVar7,pCVar4,fVar13);
              dVar24 = (double)(size_t)fVar13;
              in_stack_ffffff78 = 0x7fabb7;
              fVar15 = ((CSceneVehicleCarTuning*)this->m_field_64)->GetRolloverLateralFromSpeed
                                 (this_00,*(CSceneVehicleCarTuning***)((char*)(size_t)param_6 + 8),fVar15);
              param_5 = fVar15 * (float)(size_t)pCVar4 *
                        (float)(double)(size_t)(uint64_t)(size_t)(in_stack_ffffffb4,(int)((uint64_t)(size_t)dVar24 >> 0x20));
              fStack_8 = -param_5;
              fStack_18 = GmVec3(0,0,0);
              fStack_14 = in_stack_ffffffb8 * 0.0 - in_stack_ffffffc0 * 0.0;
              fStack_10 = GmVec3(0,0,0);
              in_stack_ffffff7c = 0x7fac1e;
              // AddVehicleTorque
            }
          }
        }
      }
      pCVar21 = pCVar21 + 1;
    } while (pCVar21 < pCVar6);
  }
  if (param_9 == 0) {
    return;
  }
  pCVar17 = *(void**)((char*)(size_t)this->m_field_64 + 0x24);
  uVar16 = 0x7fac51;
  pSVar10 = DUMMY_CFAST_CALL
                      ((void *)((int)(size_t)this->m_field_64 + 0x14),pCVar17,(uint32_t)(size_t)unaff_ESI);
  if (*(int *)(*(int*)(size_t)pSVar10 + 0x354) != 1) {
    return;
  }
  param_9 = (int)(*(float*)((char*)(size_t)param_6 + 8) * *(float*)((char*)(size_t)param_6 + 8) +
                 *(float*)(size_t)param_6 * *(float*)(size_t)param_6 +
                 *(float*)((char*)(size_t)param_6 + 4) * *(float*)((char*)(size_t)param_6 + 4));
  fVar19 = (float)(size_t)1.0f;
  param_9 = (int)(float)(size_t)fVar19;
  if (*(int*)((char*)(size_t)this + 0x60c) == 0) {
    if (*(float*)((char*)(size_t)((char*)(size_t)this + 0x5cc)) <= (float)(size_t)param_9) {
      if ((float)(size_t)1.0f < *(float*)((char*)(size_t)((char*)(size_t)this + 0x50))) goto LAB_007facea;
    }
    else if (*(float*)((char*)(size_t)((char*)(size_t)this + 0x54)) <= (float)(size_t)1.0f) {
LAB_007facea:
      *(uint32_t*)((char*)(size_t)((char*)(size_t)this + 0x5c4)) = 0;
    }
    else {
      *(uint32_t*)((char*)(size_t)((char*)(size_t)this + 0x5c4)) = 1;
    }
  }
  pGVar11 = (GmVec3 *)0;
  param_6 = (GmVec3 *)0x0;
  if (pGVar11 != (GmVec3 *)0x0) {
    do {
      fVar15 = 1.1725218e-38;
      in_stack_ffffffb4 =
           DUMMY_CFAST_CALL
                     (&this->m_wheels,(void*)param_6,
                      (uint32_t)(*(size_t*)&unaff_EBX));
      iVar9 = *(int*)((char*)(size_t)in_stack_ffffffb4 + 4);
      if (iVar9 == 0) {
        fVar13 = -*(float*)((char*)(size_t)this + 0x840);
      }
      else {
        fVar13 = *(float*)((char*)(size_t)this + 0x840);
      }
      fVar13 = fVar13 * (float)(size_t)1.0f;
      iVar1 = (int)(size_t)this->m_field_64;
      in_stack_ffffffc8 = fVar13 * *(float*)((char*)(size_t)param_10 + 4) + *(float*)(size_t)pGVar5;
      in_stack_ffffffcc = GmVec3(0,0,0);
      in_stack_ffffffd0 = *(float*)((char*)(size_t)pGVar5 + 8) + 0.0;
      pGVar18 = GmVec3(0,0,0);
      pSVar10 = DUMMY_CFAST_CALL
                          ((void *)(iVar1 + 0x14),
                           *(void**)(iVar1 + 0x24),
                           (uint32_t)(*(size_t*)&in_stack_ffffff94));
      param_12 = (float*)(size_t)*(float*)(*(int*)(size_t)pSVar10 + 0x74);
      if ((float)(size_t)00 <= (float)(size_t)02) {
        param_12 = (float *)(size_t)(((float)(size_t)00 / (float)(size_t)02) * (float)(size_t)1.0f *
                            (float)(size_t)1.0f);
        extraout_ST0_00 = std::sin(0.0f); extraout_ST0_01 = std::sin(0.0f);
        pfVar22 = (float *)(size_t)(float)(size_t)extraout_ST0_01;
        param_12 = pfVar22;
      }
      else {
        pfVar22 = (float *)0x3f800000;
      }
      unaff_EBX = GmVec3(0,0,0);
      pSVar10 = DUMMY_CFAST_CALL
                          ((void *)(iVar1 + 0x14),
                           *(void**)(iVar1 + 0x24),
                           (uint32_t)(size_t)in_stack_ffffff98);
      in_stack_ffffff94 = GmVec3(0,0,0);
      fVar14 = ((CSceneVehicleCarTuning*)this->m_field_64)->GetMaxSideFrictionFromSpeed((float)(size_t)pCVar21);
      iVar1 = (int)(size_t)this->m_field_64;
      in_stack_0000003c = (int *)(size_t)(fVar14 * *(float *)((int)(size_t)in_stack_00000040 + 0xc));
      pCVar21 = *(void**)(iVar1 + 0x24);
      in_stack_ffffff98 = (void*)0;
      pSVar10 = DUMMY_CFAST_CALL
                          ((void *)(iVar1 + 0x14),pCVar21,(uint32_t)(size_t)in_stack_ffffffa0);
      in_stack_0000003c =
           (int *)(size_t)(-*(float *)(*(int*)(size_t)pSVar10 + 0xa4) * (float)(size_t)1.0f *
                  ((float)(*(size_t*)&in_stack_ffffffe0) * 0.0 + in_stack_ffffffd8 + in_stack_ffffffdc * 0.0));
      in_stack_ffffffb8 = std::abs((float)(size_t)in_stack_0000003c);
      if (in_stack_00000040 < in_stack_ffffffb8) {
        pCVar21 = (void*)0;
        pSVar10 = DUMMY_CFAST_CALL
                            ((void *)(iVar1 + 0x14),
                             *(void**)(iVar1 + 0x24),
                             (uint32_t)(size_t)pCVar6);
        pCVar6 = *(void**)(iVar1 + 0x24);
        in_stack_ffffffa0 = (void*)0;
        pSVar7 = DUMMY_CFAST_CALL
                           ((void *)(iVar1 + 0x14),pCVar6,(uint32_t)(size_t)pfVar22);
        in_stack_00000048 =
             *(float *)(*(int*)(size_t)pSVar7 + 0xe4) * in_stack_ffffffc0 +
             (1.0 - *(float *)(*(int*)(size_t)pSVar10 + 0xe4)) * in_stack_00000048;
        bVar2 = in_stack_00000044 <= 0.0;
        in_stack_00000044 = in_stack_00000048;
        if (bVar2) {
          in_stack_00000044 = -in_stack_00000048;
        }
      }
      pSVar10 = DUMMY_CFAST_CALL
                          ((void *)(iVar1 + 0x14),
                           *(void**)(iVar1 + 0x24),
                           in_stack_ffffff7c);
      dVar24 = (double)(size_t)(uint64_t)(size_t)(fVar13,pfVar22);
      fVar13 = *(float *)(*(int*)(size_t)pSVar10 + 0x98);
      if (pCVar21 != nullptr) {
        if (*(int*)((char*)(size_t)in_stack_ffffffa0 + 300) == 0) {
          in_stack_ffffff98 = (void*)0;
        }
        else {
          pSVar10 = DUMMY_CFAST_CALL
                              ((void *)(iVar1 + 0x14),
                               *(void**)(iVar1 + 0x24),
                               uVar16);
          in_stack_ffffff98 =
               *(void**)(*(int*)(size_t)pSVar10 + 0x9c);
        }
        in_stack_ffffff7c = 0x7faf60;
        pSVar10 = DUMMY_CFAST_CALL
                            ((void *)(iVar1 + 0x14),
                             *(void**)(iVar1 + 0x24),
                             (uint32_t)(size_t)pCVar17);
        dVar24 = (double)(size_t)param_8;
        uVar16 = 0x7faf7b;
        fVar15 = ((CSceneVehicleCarTuning*)this->m_field_64)->GetSteerDriveTorqueFromSpeed
                           (*(CSceneVehicleCarTuning ***)(size_t)pSVar10,
                            *(CSceneVehicleCarTuning***)((char*)(size_t)pGVar5 + 8),fVar15);
        param_9 = (int)((float)(double)(size_t)(uint64_t)(size_t)(iVar9,(int)((uint64_t)(size_t)dVar24 >> 0x20)) -
                       (float)(size_t)00 * (float)(size_t)pCVar21 * *(float*)((char*)(size_t)((char*)(size_t)this + 0x5e8)) * fVar15 *
                       (float)(size_t)in_stack_ffffffa0);
      }
      fStack_18 = GmVec3(0,0,0);
      fStack_10 = GmVec3(0,0,0); /* vec math */
      fStack_c = 0; /* vec math */
      fStack_8 = 0; /* vec math */
      pCVar17 = (void*)0;
      param_9 = (int)(*(size_t*)&fStack_18);
      fStack_14 = 0;
      // AddVehicleTorque
      in_stack_ffffffa8 = (float)(size_t)(dVar24,0);
      dVar24 = (double)(size_t)(uint64_t)(size_t)(iVar9,(int)((uint64_t)(size_t)dVar24 >> 0x20));
      param_6 = (GmVec3 *)((int)(fVar13 * (float)(size_t)param_6) + 1);
    } while (param_6 < pGVar11);
  }
  pSVar10 = DUMMY_CFAST_CALL
                      ((void *)((int)(size_t)this->m_field_64 + 0x14),
                       *(void**)
                        ((int)(size_t)this->m_field_64 + 0x24),(uint32_t)(*(size_t*)&unaff_EBX));
  param_10 = (SBlendableVals *)(size_t)(size_t)((CSceneVehicleCarTuning*)this->m_field_64)->GetAccelFromSpeed
                       (*(CSceneVehicleCarTuning ***)(size_t)pSVar10,*(CSceneVehicleCarTuning***)((char*)(size_t)pGVar5 + 8)
                        ,(float)(*(size_t*)&in_stack_ffffff94));
  pSVar10 = DUMMY_CFAST_CALL
                      ((void *)((int)(size_t)this->m_field_64 + 0x14),
                       *(void**)
                        ((int)(size_t)this->m_field_64 + 0x24),(uint32_t)(size_t)in_stack_ffffff98);
  fVar15 = ((CSceneVehicleCarTuning*)this->m_field_64)->GetMaxSideFrictionFromSpeed((float)(size_t)pCVar21);
  iVar9 = (int)(size_t)this->m_field_64;
  param_10 = (SBlendableVals *)(size_t)(size_t)(fVar15 * *(float *)((int)(size_t)in_stack_00000040 + 0xc));
  pSVar10 = DUMMY_CFAST_CALL
                      ((void *)(iVar9 + 0x14),
                       *(void**)((char*)(size_t)iVar9 + 0x24),
                       (uint32_t)(size_t)in_stack_ffffffa0);
  in_stack_0000003c =
       (int *)(size_t)std::abs(*(float *)(*(int*)(size_t)pSVar10 + 0xa4) * (float)(size_t)1.0f * *(float*)(size_t)pGVar5);
  if ((float)(size_t)01 < (float)(size_t)in_stack_0000003c) {
    in_stack_0000003c = param_11;
  }
  pSVar10 = DUMMY_CFAST_CALL
                      ((void *)(iVar9 + 0x14),
                       *(void**)((char*)(size_t)iVar9 + 0x24),
                       (uint32_t)(size_t)pCVar6);
  param_12 = (float *)(size_t)std::abs(*(float*)((char*)(size_t)((char*)(size_t)this + 0x5e8)));
  iVar1 = *(int*)(size_t)pSVar10;
  pSVar10 = DUMMY_CFAST_CALL
                      ((void *)(iVar9 + 0x14),
                       *(void**)((char*)(size_t)iVar9 + 0x24),
                       (uint32_t)(size_t)in_stack_ffffffa8);
  fStack0000004c =
       ((CSceneVehicleCarTuning*)this->m_field_64)->GetSteerDriveTorqueFromSpeed
                 (*(CSceneVehicleCarTuning ***)(size_t)pSVar10,*(CSceneVehicleCarTuning***)((char*)(size_t)pGVar5 + 8),
                  (float)(size_t)(dVar24,0));
  fStack0000004c = *(float*)((char*)(size_t)iVar1 + 0x7c) * in_stack_00000048 * in_stack_00000038 * fStack0000004c
  ;
  if (*(int*)((char*)(size_t)((char*)(size_t)this + 0x5c4)) == 0) {
    in_stack_00000048 = 0.0;
  }
  else {
    in_stack_00000048 = 1.0f;
  }
  if (*(int*)((char*)(size_t)this + 0x600) == 0) {
    in_stack_00000038 = 0.0;
  }
  else {
    in_stack_00000038 = *(float*)((char*)(size_t)this + 0x5f4);
  }
  fVar15 = (in_stack_00000040 - fStack0000004c) *
           (*(float*)((char*)(size_t)((char*)(size_t)this + 0x50)) * *(float *)((int)(size_t)in_stack_00000050 + 4) +
            in_stack_00000048 * *(float *)((int)(size_t)in_stack_00000050 + 4) * *(float*)((char*)(size_t)((char*)(size_t)this + 0x54)) +
           in_stack_00000038);
  if (*(int*)((char*)(size_t)this + 0x60c) != 0) {
    if (*(int*)((char*)(size_t)this + 0x600) == 0) {
      fVar15 = 0;
    }
    else {
      fVar15 = in_stack_00000040 * *(float*)((char*)(size_t)this + 0x5f4);
    }
  }
  in_stack_00000040 = fVar15;
  in_stack_00000048 = 0.0;
  if (0.0 < *(float*)((char*)(size_t)pGVar5 + 8)) {
    iVar9 = (int)(size_t)this->m_field_64;
    pSVar10 = DUMMY_CFAST_CALL
                        ((void *)(iVar9 + 0x14),
                         *(void**)((char*)(size_t)iVar9 + 0x24),
                         (uint32_t)((uint64_t)(size_t)dVar24 >> 0x20));
    pSVar7 = DUMMY_CFAST_CALL
                       ((void *)(iVar9 + 0x14),
                        *(void**)((char*)(size_t)iVar9 + 0x24),
                        (uint32_t)(size_t)in_stack_ffffffb4);
    in_stack_00000050 =
         (*(float *)(*(int*)(size_t)pSVar10 + 0x44) * *(float*)((char*)(size_t)pGVar5 + 8) +
         *(float *)(*(int*)(size_t)pSVar7 + 0x40)) * *(float*)((char*)(size_t)((char*)(size_t)this + 0x54));
    if (*in_stack_0000005c == 0) {
      pSVar10 = DUMMY_CFAST_CALL
                          ((void *)(iVar9 + 0x14),
                           *(void**)((char*)(size_t)iVar9 + 0x24),
                           (uint32_t)(*(size_t*)&in_stack_ffffffb8));
      in_stack_00000044 = *(float *)(*(int*)(size_t)pSVar10 + 0x4c);
    }
    else {
      pSVar10 = DUMMY_CFAST_CALL
                          ((void *)(iVar9 + 0x14),
                           *(void**)((char*)(size_t)iVar9 + 0x24),
                           (uint32_t)(*(size_t*)&in_stack_ffffffb8));
      in_stack_00000044 = *(float *)(*(int*)(size_t)pSVar10 + 0x48);
    }
    in_stack_00000044 = (float)(size_t)in_stack_0000005c[2] * in_stack_00000044;
    if (in_stack_00000044 < in_stack_00000054) {
      in_stack_00000054 = in_stack_00000044;
      pCVar21 = (void*)0;
      pCVar6 = (void*)0; //0;
      if (pCVar21 != nullptr) {
        do {
          pSVar10 = DUMMY_CFAST_CALL
                              (&this->m_wheels,pCVar6,(uint32_t)(*(size_t*)&in_stack_ffffffc0));
          pCVar6 = pCVar6 + 1;
          *(uint32_t*)((char*)(size_t)pSVar10 + 300) = 1;
        } while (pCVar6 < pCVar21);
      }
    }
  }
  if (*(float*)((char*)(size_t)pGVar5 + 8) < 0.0) {
    if (*(int*)((char*)(size_t)this + 0x60c) == 0) goto LAB_007fb44c;
    iVar9 = (int)(size_t)this->m_field_64;
    pSVar10 = DUMMY_CFAST_CALL
                        ((void *)(iVar9 + 0x14),
                         *(void**)((char*)(size_t)iVar9 + 0x24),
                         (uint32_t)(*(size_t*)&in_stack_ffffffc0));
    uVar16 = 0x7fb33b;
    pSVar7 = DUMMY_CFAST_CALL
                       ((void *)(iVar9 + 0x14),
                        *(void**)((char*)(size_t)iVar9 + 0x24),
                        (uint32_t)(*(size_t*)&in_stack_ffffffc4));
    in_stack_00000060 =
         (*(float *)(*(int*)(size_t)pSVar10 + 0x40) -
         *(float *)(*(int*)(size_t)pSVar7 + 0x44) * *(float*)((char*)(size_t)pGVar5 + 8)) * *(float*)((char*)(size_t)((char*)(size_t)this + 0x50));
    if (*in_stack_0000003c == 0) {
      in_stack_ffffffc4 = *(void**)((char*)(size_t)iVar9 + 0x24);
      in_stack_ffffffc0 = 1.17275e-38;
      pSVar10 = DUMMY_CFAST_CALL
                          ((void *)(iVar9 + 0x14),in_stack_ffffffc4,(uint32_t)(*(size_t*)&in_stack_ffffffc8));
      in_stack_00000070 = *(float *)(*(int*)(size_t)pSVar10 + 0x4c);
    }
    else {
      in_stack_ffffffc4 = *(void**)((char*)(size_t)iVar9 + 0x24);
      in_stack_ffffffc0 = 1.1727474e-38;
      pSVar10 = DUMMY_CFAST_CALL
                          ((void *)(iVar9 + 0x14),in_stack_ffffffc4,(uint32_t)(*(size_t*)&in_stack_ffffffc8));
      in_stack_00000070 = *(float *)(*(int*)(size_t)pSVar10 + 0x48);
    }
    in_stack_00000070 = (float)(size_t)in_stack_0000003c[2] * in_stack_00000070;
    if (in_stack_00000070 < (float)(size_t)in_stack_00000064) {
      in_stack_ffffffc8 = 1.1727611e-38;
      in_stack_00000064 = (float *)(size_t)in_stack_00000070;
      pCVar21 = (void*)0;
      pCVar6 = (void*)0; //0;
      if (pCVar21 != nullptr) {
        do {
          pSVar10 = DUMMY_CFAST_CALL
                              (&this->m_wheels,pCVar6,uVar16);
          pCVar6 = pCVar6 + 1;
          *(uint32_t*)((char*)(size_t)pSVar10 + 300) = 1;
        } while (pCVar6 < pCVar21);
      }
    }
    in_stack_00000058 = -in_stack_00000058;
  }
  if ((*(int*)((char*)(size_t)this + 0x60c) != 0) && (std::abs(*(float*)((char*)(size_t)pGVar5 + 8)) < 1.0)) {
    in_stack_00000058 = std::abs(*(float*)((char*)(size_t)pGVar5 + 8)) * in_stack_00000058;
  }
LAB_007fb44c:
  *in_stack_00000068 = in_stack_00000058;
  iVar9 = (int)(size_t)this->m_field_64;
  in_stack_00000064 = (float *)(size_t)(in_stack_00000050 - in_stack_00000058);
  pSVar10 = DUMMY_CFAST_CALL
                      ((void *)(iVar9 + 0x14),
                       *(void**)((char*)(size_t)iVar9 + 0x24),
                       (uint32_t)(*(size_t*)&in_stack_ffffffc0));
  pfVar22 = in_stack_00000064;
  in_stack_0000005c = (int *)(size_t)(*(float *)(*(int*)(size_t)pSVar10 + 0x30) * *in_stack_00000064);
  pSVar10 = DUMMY_CFAST_CALL
                      ((void *)(iVar9 + 0x14),
                       *(void**)((char*)(size_t)iVar9 + 0x24),
                       (uint32_t)(*(size_t*)&in_stack_ffffffc4));
  in_stack_00000068 = (float *)(size_t)(*(float *)(*(int*)(size_t)pSVar10 + 0x2c) * *pfVar22);
  if ((float)(size_t)in_stack_00000068 < *(float*)((char*)(size_t)pGVar5 + 8)) {
    pSVar10 = DUMMY_CFAST_CALL
                        ((void *)(iVar9 + 0x14),
                         *(void**)((char*)(size_t)iVar9 + 0x24),
                         (uint32_t)(*(size_t*)&in_stack_ffffffc8));
    in_stack_00000070 = -*(float *)(*(int*)(size_t)pSVar10 + 0x60);
  }
  if (*(float*)((char*)(size_t)pGVar5 + 8) < -(float)(size_t)in_stack_00000064) {
    pSVar10 = DUMMY_CFAST_CALL
                        ((void *)(iVar9 + 0x14),
                         *(void**)((char*)(size_t)iVar9 + 0x24),
                         (uint32_t)(*(size_t*)&in_stack_ffffffcc));
    in_stack_00000074 = *(uint32_t *)(*(int*)(size_t)pSVar10 + 0x60);
  }
  in_stack_00000038 = in_stack_00000070 * in_stack_00000058;
  param_12 = (float *)0x0;
  uStack00000034 = 0;
  in_stack_00000070 = in_stack_00000038;
  // AddVehicleCentralForce
  param_9 = 0;
  param_8 = 0.0;
  pSVar10 = DUMMY_CFAST_CALL
                      ((void *)((int)(size_t)this->m_field_64 + 0x14),
                       *(void**)
                        ((int)(size_t)this->m_field_64 + 0x24),(uint32_t)(size_t)in_stack_ffffffd0);
  param_8 = -in_stack_00000058 * *(float *)(*(int*)(size_t)pSVar10 + 0xc0);
  // AddVehicleTorque
  iVar9 = (int)(size_t)this->m_field_64;
  pSVar10 = DUMMY_CFAST_CALL
                      ((void *)(iVar9 + 0x14),
                       *(void**)((char*)(size_t)iVar9 + 0x24),
                       (uint32_t)(size_t)in_stack_ffffffd8);
  pSVar7 = DUMMY_CFAST_CALL
                     ((void *)(iVar9 + 0x14),
                      *(void**)((char*)(size_t)iVar9 + 0x24),
                      (uint32_t)(size_t)in_stack_ffffffdc);
  param_10 = (SBlendableVals *)(size_t)(size_t)((-*(float *)(*(int*)(size_t)pSVar10 + 100) * in_stack_00000064[2]) /
             *(float *)(*(int*)(size_t)pSVar7 + 0x160));
  param_8 = 0.0;
  param_9 = 0;
  pSStack00000080 = param_10;
  // AddVehicleCentralForce
  return;
}
}
