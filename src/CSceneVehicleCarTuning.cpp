
/* public: virtual void * __thiscall CSceneVehicleCarTuning::`scalar deleting
   destructor'(unsigned int) */

void *__thiscall CSceneVehicleCarTuning::`scalar_deleting_destructor'(CSceneVehicleCarTuning *this,uint param_1)

{
  ~CSceneVehicleCarTuning(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

/* public: virtual void __thiscall CSceneVehicleCarTuning::Chunk(class
   CClassicArchive &,unsigned long) */

void __thiscall CSceneVehicleCarTuning::Chunk(CSceneVehicleCarTuning *this,
                                              CClassicArchive *param_1,
                                              ulong param_2)

{
  CGameCamera *pCVar1;
  float *pfVar2;
  CClassicArchive **ppCVar3;
  CClassicArchive *pCVar4;
  CClassicArchive *local_24;
  CFuncKeysReal *local_20;
  CClassicArchive *local_1c;
  CFastBuffer<> local_18[12];
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  pCVar4 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad010c;
  local_c = ExceptionList;
  if (0xa029035 < param_2) {
    if (param_2 < 0xa029051) {
      if (param_2 == 0xa029050) {
        param_2 = 0;
        ExceptionList = &local_c;
        CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)(this + 0x260));
        CClassicArchive::DoReal(pCVar4, (float *)(this + 0x264), 1);
        CClassicArchive::DoReal(pCVar4, (float *)(this + 600), 1);
        CClassicArchive::DoReal(pCVar4, (float *)(this + 0x268), 1);
        CClassicArchive::DoReal(pCVar4, (float *)(this + 0x278), 1);
        CClassicArchive::DoReal(pCVar4, (float *)(this + 0x280), 1);
        CClassicArchive::DoReal(pCVar4, (float *)&param_2, 1);
        CClassicArchive::DoReal(pCVar4, (float *)(this + 0x284), 1);
        CClassicArchive::DoReal(pCVar4, (float *)(this + 0x26c), 1);
        CClassicArchive::DoReal(pCVar4, (float *)(this + 0x270), 1);
        CClassicArchive::DoReal(pCVar4, (float *)(this + 0x240), 1);
        CClassicArchive::DoNatural(pCVar4, (ulong *)(this + 0x298), 1, 0);
        CClassicArchive::DoReal(pCVar4, (float *)(this + 0x29c), 1);
        CClassicArchive::DoReal(pCVar4, (float *)(this + 0x2ac), 1);
        CClassicArchive::DoNatural(pCVar4, (ulong *)(this + 0x2a8), 1, 0);
        CClassicArchive::DoReal(pCVar4, (float *)(this + 0x244), 1);
        CClassicArchive::DoReal(pCVar4, (float *)(this + 0x2c0), 1);
        CClassicArchive::DoReal(pCVar4, (float *)(this + 0x2b4), 1);
        CClassicArchive::DoReal(pCVar4, (float *)(this + 0x2b0), 1);
        CClassicArchive::MwDoNodRef<>(pCVar4, (CMwNodRef<> *)(this + 0x2a4));
        CClassicArchive::MwDoNodRef<>(pCVar4, (CMwNodRef<> *)(this + 0x288));
        CClassicArchive::DoReal(pCVar4, (float *)(this + 0x28c), 1);
        CClassicArchive::DoReal(pCVar4, (float *)(this + 700), 1);
        CClassicArchive::DoReal(pCVar4, (float *)(this + 0x290), 1);
        CClassicArchive::DoReal(pCVar4, (float *)(this + 0x294), 1);
        CClassicArchive::DoReal(pCVar4, (float *)(this + 0x2b8), 1);
        CClassicArchive::DoReal(pCVar4, (float *)&param_2, 1);
        CClassicArchive::DoReal(pCVar4, (float *)(this + 0x2d0), 1);
        CFastBuffer<float>::ArchiveCountAndElems(
            (CFastBuffer<float> *)(this + 0x2c4), pCVar4);
        (**(code **)(*(int *)pCVar4 + 4))(&param_1);
        ppCVar3 = (CClassicArchive **)&param_2;
      } else {
        switch (param_2) {
        case 0xa029036:
          ExceptionList = &local_c;
          CClassicArchive::DoReal(param_1, (float *)(this + 0x19c), 1);
          CClassicArchive::DoReal(pCVar4, (float *)(this + 0x1a0), 1);
          CClassicArchive::DoReal(pCVar4, (float *)(this + 0x1a8), 1);
          CClassicArchive::MwDoNodRef<>(pCVar4, (CMwNodRef<> *)(this + 0x1b4));
          ExceptionList = local_c;
          return;
        case 0xa029037:
          ExceptionList = &local_c;
          CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)(this + 0x1c4));
          ExceptionList = local_c;
          return;
        case 0xa029038:
          ExceptionList = &local_c;
          CClassicArchive::DoReal(param_1, (float *)(this + 0x1c8), 1);
          CClassicArchive::MwDoNodRef<>(pCVar4, (CMwNodRef<> *)(this + 0x1bc));
          CClassicArchive::DoReal(pCVar4, (float *)(this + 0x1c0), 1);
          ppCVar3 = (CClassicArchive **)(this + 0x1b8);
          break;
        case 0xa029039:
          ExceptionList = &local_c;
          CClassicArchive::DoReal(param_1, (float *)(this + 0x1a4), 1);
          ppCVar3 = (CClassicArchive **)(this + 0x1ac);
          break;
        case 0xa02903a:
          ExceptionList = &local_c;
          CClassicArchive::DoReal(param_1, (float *)(this + 0x1cc), 1);
          ppCVar3 = (CClassicArchive **)(this + 0x1d0);
          break;
        case 0xa02903b:
          ppCVar3 = (CClassicArchive **)(this + 0x1b0);
          ExceptionList = &local_c;
          break;
        case 0xa02903c:
          ppCVar3 = (CClassicArchive **)(this + 0x1dc);
          ExceptionList = &local_c;
          break;
        case 0xa02903d:
          ExceptionList = &local_c;
          CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)(this + 0x1e0));
          ExceptionList = local_c;
          return;
        case 0xa02903e:
          ExceptionList = &local_c;
          CClassicArchive::DoNatural(param_1, (ulong *)(this + 0x1e8), 1, 0);
          ExceptionList = local_c;
          return;
        case 0xa02903f:
          ExceptionList = &local_c;
          CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)(this + 0x1ec));
          ExceptionList = local_c;
          return;
        case 0xa029040:
          ExceptionList = &local_c;
          CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)(this + 0x1f0));
          ExceptionList = local_c;
          return;
        case 0xa029041:
          ExceptionList = &local_c;
          CClassicArchive::DoReal(param_1, (float *)(this + 500), 1);
          CClassicArchive::DoNatural(pCVar4, (ulong *)(this + 0x1f8), 1, 0);
          ExceptionList = local_c;
          return;
        case 0xa029042:
          ExceptionList = &local_c;
          CClassicArchive::DoNatural(param_1, (ulong *)(this + 0x1fc), 1, 0);
          ExceptionList = local_c;
          return;
        case 0xa029043:
          ExceptionList = &local_c;
          CClassicArchive::DoNatural(param_1, (ulong *)(this + 0x84), 1, 0);
          ExceptionList = local_c;
          return;
        case 0xa029044:
          ppCVar3 = (CClassicArchive **)(this + 0x200);
          ExceptionList = &local_c;
          break;
        case 0xa029045:
          ExceptionList = &local_c;
          CClassicArchive::DoReal(param_1, (float *)(this + 0x204), 1);
          CClassicArchive::DoReal(pCVar4, (float *)&param_1, 1);
          CClassicArchive::DoReal(pCVar4, (float *)&param_2, 1);
          CClassicArchive::DoReal(pCVar4, (float *)(this + 0x208), 1);
          ppCVar3 = (CClassicArchive **)&local_20;
          break;
        case 0xa029046:
          ExceptionList = &local_c;
          CClassicArchive::DoReal(param_1, (float *)(this + 0x204), 1);
          CClassicArchive::DoReal(pCVar4, (float *)(this + 0x208), 1);
          CClassicArchive::DoReal(pCVar4, (float *)(this + 0x20c), 1);
          CClassicArchive::MwDoNodRef<>(pCVar4, (CMwNodRef<> *)(this + 0x214));
          CClassicArchive::MwDoNodRef<>(pCVar4, (CMwNodRef<> *)(this + 0x218));
          CClassicArchive::MwDoNodRef<>(pCVar4, (CMwNodRef<> *)(this + 0x210));
          ExceptionList = local_c;
          return;
        case 0xa029047:
          ppCVar3 = (CClassicArchive **)(this + 0x21c);
          ExceptionList = &local_c;
          break;
        case 0xa029048:
          ExceptionList = &local_c;
          CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)(this + 0x24));
          ExceptionList = local_c;
          return;
        case 0xa029049:
          ExceptionList = &local_c;
          CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)(this + 0x224));
          ExceptionList = local_c;
          return;
        case 0xa02904a:
          param_2 = 0;
          ExceptionList = &local_c;
          CClassicArchive::DoReal(param_1, (float *)&param_2, 1);
          ppCVar3 = (CClassicArchive **)(this + 0x228);
          break;
        case 0xa02904b:
          param_2 = 0;
          ExceptionList = &local_c;
          CClassicArchive::DoReal(param_1, (float *)&param_2, 1);
          CClassicArchive::DoReal(pCVar4, (float *)(this + 0x22c), 1);
          CClassicArchive::MwDoNodRef<>(pCVar4, (CMwNodRef<> *)(this + 0x230));
          ExceptionList = local_c;
          return;
        case 0xa02904c:
          goto switchD_007f6cc2_caseD_a02904c;
        case 0xa02904d:
          ppCVar3 = (CClassicArchive **)(this + 0x234);
          ExceptionList = &local_c;
          break;
        case 0xa02904e:
          ExceptionList = &local_c;
          CClassicArchive::DoReal(param_1, (float *)(this + 0x238), 1);
          ppCVar3 = (CClassicArchive **)(this + 0x23c);
          break;
        case 0xa02904f:
          ExceptionList = &local_c;
          CClassicArchive::DoReal(param_1, (float *)(this + 0x254), 1);
          CClassicArchive::MwDoNodRef<>(pCVar4, (CMwNodRef<> *)(this + 0x25c));
          ExceptionList = local_c;
          return;
        default:
          goto switchD_007f5efc_caseD_35;
        }
      }
      goto LAB_007f7899;
    }
    if (0xa02905e < param_2) {
      if (param_2 < 0xa029066) {
        if (param_2 == 0xa029065) {
          ppCVar3 = (CClassicArchive **)(this + 0x348);
          ExceptionList = &local_c;
        } else {
          switch (param_2) {
          case 0xa02905f:
            ppCVar3 = (CClassicArchive **)(this + 0x220);
            ExceptionList = &local_c;
            break;
          case 0xa029060:
            ExceptionList = &local_c;
            CClassicArchive::DoReal(param_1, (float *)(this + 0x30), 1);
            CClassicArchive::DoReal(pCVar4, (float *)(this + 0xf0), 1);
            CClassicArchive::DoReal(pCVar4, (float *)(this + 0xf4), 1);
            CClassicArchive::DoNatural(pCVar4, (ulong *)(this + 0xf8), 1, 0);
            CClassicArchive::DoNatural(pCVar4, (ulong *)(this + 0xfc), 1, 0);
            ExceptionList = local_c;
            return;
          case 0xa029061:
            ExceptionList = &local_c;
            CClassicArchive::MwDoNodRef<>(param_1,
                                          (CMwNodRef<> *)(this + 0x378));
            ExceptionList = local_c;
            return;
          case 0xa029062:
            ppCVar3 = (CClassicArchive **)(this + 0x33c);
            ExceptionList = &local_c;
            break;
          case 0xa029063:
            ppCVar3 = (CClassicArchive **)(this + 0x340);
            ExceptionList = &local_c;
            break;
          case 0xa029064:
            ppCVar3 = (CClassicArchive **)(this + 0x344);
            ExceptionList = &local_c;
            break;
          default:
            goto switchD_007f5efc_caseD_35;
          }
        }
      } else if (param_2 < 0xa029069) {
        if (param_2 == 0xa029068)
          goto switchD_007f5efc_caseD_a029021;
        if (param_2 == 0xa029066) {
          ppCVar3 = (CClassicArchive **)(this + 0x34c);
          ExceptionList = &local_c;
        } else {
          if (param_2 != 0xa029067)
            goto switchD_007f5efc_caseD_35;
          ppCVar3 = &param_1;
          ExceptionList = &local_c;
        }
      } else {
        if (param_2 != 0xa029069) {
          if (param_2 == 0xffffffff) {
            return;
          }
          goto switchD_007f5efc_caseD_35;
        }
        ppCVar3 = &local_1c;
        ExceptionList = &local_c;
      }
      goto LAB_007f7899;
    }
    if (param_2 == 0xa02905e) {
      ExceptionList = &local_c;
      CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)(this + 0x36c));
      ExceptionList = local_c;
      return;
    }
    switch (param_2) {
    case 0xa029051:
      ppCVar3 = (CClassicArchive **)(this + 0x2a0);
      ExceptionList = &local_c;
      break;
    case 0xa029052:
      ExceptionList = &local_c;
      CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)(this + 0x250));
      ExceptionList = local_c;
      return;
    case 0xa029053:
      ppCVar3 = (CClassicArchive **)(this + 0x27c);
      ExceptionList = &local_c;
      break;
    case 0xa029054:
      ExceptionList = &local_c;
      CFastBuffer<>::CFastBuffer<>(local_18);
      pCVar4 = param_1;
      local_4 = 4;
      CFastBuffer<float>::ArchiveCountAndElems(
          (CFastBuffer<float> *)(this + 0x2d4), param_1);
      CFastBuffer<float>::ArchiveCountAndElems(
          (CFastBuffer<float> *)(this + 0x2e0), pCVar4);
      CFastBuffer<float>::ArchiveCountAndElems((CFastBuffer<float> *)local_18,
                                               pCVar4);
      goto LAB_007f739c;
    case 0xa029055:
      ExceptionList = &local_c;
      CFastBuffer<>::CFastBuffer<>(local_18);
      local_4 = 5;
      pCVar4 = param_1;
    LAB_007f739c:
      CFastBuffer<float>::ArchiveCountAndElems((CFastBuffer<float> *)local_18,
                                               pCVar4);
      CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)local_18);
      ExceptionList = local_c;
      return;
    case 0xa029056:
      ExceptionList = &local_c;
      CClassicArchive::DoReal(param_1, (float *)(this + 0x2ec), 1);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x2f0), 1);
      ppCVar3 = (CClassicArchive **)(this + 0x2f4);
      break;
    case 0xa029057:
      ExceptionList = &local_c;
      CFastBuffer<float>::ArchiveCountAndElems(
          (CFastBuffer<float> *)(this + 0x2f8), param_1);
      ExceptionList = local_c;
      return;
    case 0xa029058:
      ppCVar3 = (CClassicArchive **)(this + 0x31c);
      ExceptionList = &local_c;
      break;
    case 0xa029059:
      ExceptionList = &local_c;
      CClassicArchive::DoReal(param_1, (float *)(this + 800), 1);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x32c), 1);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x324), 1);
      ppCVar3 = (CClassicArchive **)(this + 0x328);
      break;
    case 0xa02905a:
      ExceptionList = &local_c;
      CClassicArchive::DoReal(param_1, (float *)(this + 0x334), 1);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x330), 1);
      ppCVar3 = (CClassicArchive **)(this + 0x338);
      break;
    case 0xa02905b:
      ExceptionList = &local_c;
      CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)(this + 0x380));
      ppCVar3 = (CClassicArchive **)(this + 900);
      break;
    case 0xa02905c:
      ExceptionList = &local_c;
      CClassicArchive::DoReal(param_1, (float *)(this + 0x248), 1);
      ppCVar3 = (CClassicArchive **)(this + 0x24c);
      break;
    case 0xa02905d:
      ExceptionList = &local_c;
      CClassicArchive::DoReal(param_1, (float *)(this + 0x228), 1);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x22c), 1);
      CClassicArchive::MwDoNodRef<>(pCVar4, (CMwNodRef<> *)(this + 0x230));
      CClassicArchive::MwDoNodRef<>(pCVar4, (CMwNodRef<> *)(this + 0x260));
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x264), 1);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 600), 1);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x268), 1);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x278), 1);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x280), 1);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x284), 1);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x26c), 1);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x270), 1);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x240), 1);
      CClassicArchive::DoNatural(pCVar4, (ulong *)(this + 0x298), 1, 0);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x29c), 1);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x2ac), 1);
      CClassicArchive::DoNatural(pCVar4, (ulong *)(this + 0x2a8), 1, 0);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x244), 1);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x2c0), 1);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x2b4), 1);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x2b0), 1);
      CClassicArchive::MwDoNodRef<>(pCVar4, (CMwNodRef<> *)(this + 0x2a4));
      CClassicArchive::MwDoNodRef<>(pCVar4, (CMwNodRef<> *)(this + 0x288));
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x28c), 1);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 700), 1);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x290), 1);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x294), 1);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x2b8), 1);
      CClassicArchive::DoReal(pCVar4, (float *)(this + 0x2d0), 1);
      CFastBuffer<float>::ArchiveCountAndElems(
          (CFastBuffer<float> *)(this + 0x2c4), pCVar4);
      CFastBuffer<float>::ArchiveCountAndElems(
          (CFastBuffer<float> *)(this + 0x2d4), pCVar4);
      CFastBuffer<float>::ArchiveCountAndElems(
          (CFastBuffer<float> *)(this + 0x2e0), pCVar4);
      CClassicArchive::DoNatural(pCVar4, (ulong *)(this + 0x90), 1, 0);
      ExceptionList = local_c;
      return;
    default:
      goto switchD_007f5efc_caseD_35;
    }
    goto LAB_007f7899;
  }
  if (param_2 == 0xa029035) {
    ExceptionList = &local_c;
    CClassicArchive::DoBool(param_1, (int *)(this + 0x80), 1);
    ExceptionList = local_c;
    return;
  }
  switch (param_2) {
  case 0xa029000:
    param_2 = 0x3f800000;
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)&param_2, 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x6c), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x70), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x2c), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x114), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x118), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x11c), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x120), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x124), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 300), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x3c), 1);
    ppCVar3 = (CClassicArchive **)(this + 0x128);
    break;
  case 0xa029001:
    ExceptionList = &local_c;
    CMwId::Archive((CMwId *)(this + 0x14), param_1);
    ExceptionList = local_c;
    return;
  case 0xa029002:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)(this + 0x130), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x144), 1);
    ppCVar3 = (CClassicArchive **)(this + 0x148);
    break;
  case 0xa029003:
    param_2 = 0;
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)&param_2, 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0xa4), 1);
    CClassicArchive::DoReal(pCVar4, (float *)&param_1, 1);
    local_20 = (CFuncKeysReal *)operator_new(0x2c);
    local_4 = 0;
    if (local_20 == (CFuncKeysReal *)0x0) {
      pCVar1 = (CGameCamera *)0x0;
    } else {
      pCVar1 = (CGameCamera *)CFuncKeysReal::CFuncKeysReal(local_20);
    }
    local_4 = 0xffffffff;
    CMwNodRef<>::MwSetNod((CMwNodRef<> *)(this + 0xb8), pCVar1);
    CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0xb8), 0.0,
                                 (float)param_1);
    ExceptionList = local_c;
    return;
  case 0xa029004:
    ExceptionList = &local_c;
    CClassicArchive::DoBool(param_1, (int *)(this + 400), 1);
    ExceptionList = local_c;
    return;
  case 0xa029005:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)(this + 0x160), 1);
    if (*(int *)(pCVar4 + 8) != 0) {
      ExceptionList = local_c;
      return;
    }
    *(float *)(this + 0x164) = *(float *)(this + 0x160);
    ExceptionList = local_c;
    return;
  case 0xa029006:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)&param_1, 1);
    CClassicArchive::DoReal(pCVar4, (float *)&param_1, 1);
    CClassicArchive::DoReal(pCVar4, (float *)&param_1, 1);
    ppCVar3 = &param_1;
    break;
  case 0xa029007:
    ppCVar3 = (CClassicArchive **)(this + 0x94);
    ExceptionList = &local_c;
    break;
  case 0xa029008:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)(this + 0x30), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0xf0), 1);
    *(float *)(this + 0xf4) = *(float *)(this + 0xf0);
    ExceptionList = local_c;
    return;
  case 0xa029009:
    ppCVar3 = (CClassicArchive **)(this + 0x40);
    ExceptionList = &local_c;
    break;
  case 0xa02900a:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)(this + 0x154), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x158), 1);
    *(undefined4 *)(this + 0x15c) = 0;
    ExceptionList = local_c;
    return;
  case 0xa02900b:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)(this + 0x134), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x138), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x13c), 1);
    ppCVar3 = (CClassicArchive **)(this + 0x140);
    break;
  case 0xa02900c:
    ExceptionList = &local_c;
    CClassicArchive::DoBool(param_1, (int *)&param_1, 1);
    if (*(int *)(pCVar4 + 8) != 0) {
      ExceptionList = local_c;
      return;
    }
    *(uint *)(this + 0x350) = (uint)(param_1 == (CClassicArchive *)0x0);
    ExceptionList = local_c;
    return;
  case 0xa02900d:
    ExceptionList = &local_c;
    CClassicArchive::DoNatural(param_1, (ulong *)(this + 0x16c), 1, 0);
    ExceptionList = local_c;
    return;
  case 0xa02900e:
    ExceptionList = &local_c;
    CClassicArchive::DoNatural(param_1, (ulong *)(this + 0x350), 1, 0);
    ExceptionList = local_c;
    return;
  case 0xa02900f:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)&param_1, 1);
    param_2 = (ulong)operator_new(0x2c);
    local_4 = 1;
    if ((CFuncKeysReal *)param_2 == (CFuncKeysReal *)0x0) {
      pCVar1 = (CGameCamera *)0x0;
    } else {
      pCVar1 =
          (CGameCamera *)CFuncKeysReal::CFuncKeysReal((CFuncKeysReal *)param_2);
    }
    local_4 = 0xffffffff;
    CMwNodRef<>::MwSetNod((CMwNodRef<> *)(this + 0xa0), pCVar1);
    CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0xa0), 0.0,
                                 (float)param_1);
    ExceptionList = local_c;
    return;
  case 0xa029010:
    ExceptionList = &local_c;
    CClassicArchive::DoNatural(param_1, (ulong *)(this + 0x354), 1, 0);
    ppCVar3 = (CClassicArchive **)(this + 0x98);
    break;
  case 0xa029011:
    param_2 = 0;
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)&param_2, 1);
    CClassicArchive::DoReal(pCVar4, (float *)&param_2, 1);
    CClassicArchive::DoReal(pCVar4, (float *)&param_2, 1);
    CClassicArchive::DoReal(pCVar4, (float *)&param_2, 1);
    CClassicArchive::DoReal(pCVar4, (float *)&param_2, 1);
    CClassicArchive::DoReal(pCVar4, (float *)&param_2, 1);
    CClassicArchive::DoReal(pCVar4, (float *)&param_2, 1);
    CClassicArchive::DoReal(pCVar4, (float *)&param_2, 1);
    ppCVar3 = (CClassicArchive **)&param_2;
    break;
  case 0xa029012:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)(this + 0x388), 1);
    pfVar2 = (float *)(this + 0x390);
    goto LAB_007f63f7;
  case 0xa029013:
    param_2 = 0;
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)&param_2, 1);
    CClassicArchive::DoReal(pCVar4, (float *)&param_2, 1);
    CClassicArchive::DoReal(pCVar4, (float *)&param_2, 1);
    CClassicArchive::DoReal(pCVar4, (float *)&param_2, 1);
    CClassicArchive::DoReal(pCVar4, (float *)&param_2, 1);
    CClassicArchive::DoReal(pCVar4, (float *)&param_2, 1);
    CClassicArchive::DoReal(pCVar4, (float *)&param_2, 1);
    CClassicArchive::DoReal(pCVar4, (float *)&param_2, 1);
    CClassicArchive::DoReal(pCVar4, (float *)&param_2, 1);
    CClassicArchive::DoReal(pCVar4, (float *)&param_2, 1);
    CClassicArchive::DoReal(pCVar4, (float *)&param_2, 1);
    ppCVar3 = (CClassicArchive **)&param_2;
    break;
  case 0xa029014:
    param_2 = 0;
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)&param_2, 1);
    ppCVar3 = &param_1;
    param_1 = (CClassicArchive *)0x0;
    break;
  case 0xa029015:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)(this + 0x388), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x390), 1);
    pfVar2 = (float *)(this + 0x38c);
  LAB_007f63f7:
    CClassicArchive::DoReal(pCVar4, pfVar2, 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x394), 1);
    pfVar2 = (float *)(this + 0x28);
    CClassicArchive::DoReal(pCVar4, pfVar2, 1);
    if (*(int *)(pCVar4 + 8) != 0) {
      ExceptionList = local_c;
      return;
    }
    *(float *)(this + 0x3a0) = *pfVar2 * 0.5;
    *(float *)(this + 0x398) = *pfVar2;
    *(float *)(this + 0x39c) = *pfVar2 * 0.5;
    ExceptionList = local_c;
    return;
  case 0xa029016:
    param_2 = 0;
    local_24 = (CClassicArchive *)0x0;
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)&param_2, 1);
    ppCVar3 = &local_24;
    break;
  case 0xa029017:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)(this + 0x3a4), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x3a8), 1);
    param_1 = (CClassicArchive *)0x0;
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x37c), 1);
    CClassicArchive::DoReal(pCVar4, (float *)&param_1, 1);
    CClassicArchive::DoReal(pCVar4, (float *)&param_1, 1);
    param_2 = 0;
    CClassicArchive::DoReal(pCVar4, (float *)&param_2, 1);
    local_24 = (CClassicArchive *)0x0;
    CClassicArchive::DoReal(pCVar4, (float *)&local_24, 1);
    local_20 = (CFuncKeysReal *)0x0;
    ppCVar3 = (CClassicArchive **)&local_20;
    break;
  case 0xa029018:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)(this + 0x154), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x158), 1);
    ppCVar3 = (CClassicArchive **)(this + 0x15c);
    break;
  case 0xa029019:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)(this + 0x170), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x174), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x178), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x17c), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x180), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x184), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x188), 1);
    ppCVar3 = (CClassicArchive **)(this + 0x18c);
    break;
  case 0xa02901a:
    ppCVar3 = (CClassicArchive **)(this + 0x54);
    ExceptionList = &local_c;
    break;
  case 0xa02901b:
    ppCVar3 = (CClassicArchive **)&param_2;
    param_2 = 0;
    ExceptionList = &local_c;
    break;
  case 0xa02901c:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)(this + 0x38), 1);
    CClassicArchive::DoReal(pCVar4, (float *)&param_1, 1);
    param_2 = (ulong)operator_new(0x2c);
    local_4 = 2;
    if ((CFuncKeysReal *)param_2 == (CFuncKeysReal *)0x0) {
      pCVar1 = (CGameCamera *)0x0;
    } else {
      pCVar1 =
          (CGameCamera *)CFuncKeysReal::CFuncKeysReal((CFuncKeysReal *)param_2);
    }
    local_4 = 0xffffffff;
    CMwNodRef<>::MwSetNod((CMwNodRef<> *)(this + 0xac), pCVar1);
    CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0xac), 0.0,
                                 (float)param_1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0xb0), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x50), 1);
    goto LAB_007f6790;
  case 0xa02901d:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)(this + 0x164), 1);
    ppCVar3 = (CClassicArchive **)(this + 0xc0);
    break;
  case 0xa02901e:
    ExceptionList = &local_c;
    CClassicArchive::DoNatural(param_1, (ulong *)(this + 0x364), 1, 0);
    ExceptionList = local_c;
    return;
  case 0xa02901f:
    param_2 = 0x3f800000;
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)&param_2, 1);
    param_1 = (CClassicArchive *)&DAT_3f800000;
    CClassicArchive::DoReal(pCVar4, (float *)&param_1, 1);
    local_20 = (CFuncKeysReal *)&DAT_3f800000;
    ppCVar3 = (CClassicArchive **)&local_20;
    break;
  case 0xa029020:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)(this + 0xc4), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 200), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0xcc), 1);
    ppCVar3 = (CClassicArchive **)(this + 0xd0);
    break;
  case 0xa029021:
  switchD_007f5efc_caseD_a029021:
    ppCVar3 = &param_1;
    ExceptionList = &local_c;
    break;
  case 0xa029022:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)&param_1, 1);
    ppCVar3 = (CClassicArchive **)&param_2;
    break;
  case 0xa029023:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)(this + 0xec), 1);
    ppCVar3 = (CClassicArchive **)(this + 0x74);
    break;
  case 0xa029024:
    ExceptionList = &local_c;
    CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)(this + 0x34));
    ExceptionList = local_c;
    return;
  case 0xa029025:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)&param_1, 1);
    param_2 = (ulong)operator_new(0x2c);
    local_4 = 3;
    if ((CFuncKeysReal *)param_2 == (CFuncKeysReal *)0x0) {
      pCVar1 = (CGameCamera *)0x0;
    } else {
      pCVar1 =
          (CGameCamera *)CFuncKeysReal::CFuncKeysReal((CFuncKeysReal *)param_2);
    }
    local_4 = 0xffffffff;
    CMwNodRef<>::MwSetNod((CMwNodRef<> *)(this + 0x78), pCVar1);
    CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x78), 0.0,
                                 (float)param_1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0xa8), 1);
    ppCVar3 = (CClassicArchive **)(this + 0x100);
    break;
  case 0xa029026:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)(this + 0xd4), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0xd8), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0xdc), 1);
    ppCVar3 = (CClassicArchive **)(this + 0xe0);
    break;
  case 0xa029027:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)(this + 0x9c), 1);
    ppCVar3 = (CClassicArchive **)(this + 0xb4);
    break;
  case 0xa029028:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)(this + 0x38), 1);
    CClassicArchive::MwDoNodRef<>(pCVar4, (CMwNodRef<> *)(this + 0xac));
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0xb0), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x50), 1);
  LAB_007f6790:
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x58), 1);
    ppCVar3 = (CClassicArchive **)(this + 0x194);
    break;
  case 0xa029029:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)(this + 0xa4), 1);
    CClassicArchive::MwDoNodRef<>(pCVar4, (CMwNodRef<> *)(this + 0xb8));
    ExceptionList = local_c;
    return;
  case 0xa02902a:
    ExceptionList = &local_c;
    CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)(this + 0x68));
    ExceptionList = local_c;
    return;
  case 0xa02902b:
    ExceptionList = &local_c;
    CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)(this + 0x78));
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0xa8), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x100), 1);
    CClassicArchive::DoNatural(pCVar4, (ulong *)(this + 0x88), 1, 0);
    ExceptionList = local_c;
    return;
  case 0xa02902c:
    ExceptionList = &local_c;
    CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)(this + 0xbc));
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x368), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x44), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x48), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x4c), 1);
    ppCVar3 = (CClassicArchive **)(this + 0x5c);
    break;
  case 0xa02902d:
    ExceptionList = &local_c;
    CClassicArchive::DoNatural(param_1, (ulong *)(this + 0x8c), 1, 0);
    ExceptionList = local_c;
    return;
  case 0xa02902e:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)(this + 0x7c), 1);
    ppCVar3 = &param_1;
    param_1 = (CClassicArchive *)0x0;
    break;
  case 0xa02902f:
    ExceptionList = &local_c;
    CClassicArchive::DoNatural(param_1, (ulong *)(this + 0xf8), 1, 0);
    *(ulong *)(this + 0xfc) = *(ulong *)(this + 0xf8);
    ExceptionList = local_c;
    return;
  case 0xa029030:
    ExceptionList = &local_c;
    CClassicArchive::MwDoNodRef<>(param_1, (CMwNodRef<> *)(this + 0xa0));
    ExceptionList = local_c;
    return;
  case 0xa029031:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)(this + 0x60), 1);
    ppCVar3 = (CClassicArchive **)(this + 100);
    break;
  case 0xa029032:
    ExceptionList = &local_c;
    CClassicArchive::DoReal(param_1, (float *)(this + 0x388), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x390), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x38c), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x394), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x398), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x39c), 1);
    CClassicArchive::DoReal(pCVar4, (float *)(this + 0x28), 1);
    ppCVar3 = (CClassicArchive **)(this + 0x3a0);
    break;
  case 0xa029033:
    ppCVar3 = (CClassicArchive **)(this + 0x14c);
    ExceptionList = &local_c;
    break;
  case 0xa029034:
    ppCVar3 = (CClassicArchive **)(this + 0x150);
    ExceptionList = &local_c;
    break;
  default:
  switchD_007f5efc_caseD_35:
    ExceptionList = &local_c;
    CSceneVehicleTuning::Chunk((CSceneVehicleTuning *)this, param_1, param_2);
    ExceptionList = local_c;
    return;
  }
LAB_007f7899:
  CClassicArchive::DoReal(pCVar4, (float *)ppCVar3, 1);
switchD_007f6cc2_caseD_a02904c:
  ExceptionList = local_c;
  return;
}

/* public: __thiscall CSceneVehicleCarTuning::CSceneVehicleCarTuning(void) */

CSceneVehicleCarTuning
    *__thiscall CSceneVehicleCarTuning::CSceneVehicleCarTuning(
        CSceneVehicleCarTuning *this)

{
  CFastBuffer<> *this_00;
  CFastBuffer<float> *pCVar1;
  CFuncKeysReal *pCVar2;
  CMwNod *pCVar3;
  undefined4 *puVar4;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad0082;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CSceneVehicleTuning::CSceneVehicleTuning((CSceneVehicleTuning *)this);
  *(undefined ***)this = vftable;
  local_4 = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0xac) = 0;
  *(undefined4 *)(this + 0xb8) = 0;
  *(undefined4 *)(this + 0xbc) = 0;
  *(undefined4 *)(this + 0x1b4) = 0;
  *(undefined4 *)(this + 0x1bc) = 0;
  *(undefined4 *)(this + 0x1c4) = 0;
  *(undefined4 *)(this + 0x1e0) = 0;
  *(undefined4 *)(this + 0x1ec) = 0;
  *(undefined4 *)(this + 0x1f0) = 0;
  *(undefined4 *)(this + 0x210) = 0;
  *(undefined4 *)(this + 0x214) = 0;
  *(undefined4 *)(this + 0x218) = 0;
  *(undefined4 *)(this + 0x224) = 0;
  *(undefined4 *)(this + 0x230) = 0;
  *(undefined4 *)(this + 0x250) = 0;
  *(undefined4 *)(this + 0x25c) = 0;
  *(undefined4 *)(this + 0x260) = 0;
  *(undefined4 *)(this + 0x288) = 0;
  *(undefined4 *)(this + 0x2a4) = 0;
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(this + 0x2c4));
  this_00 = (CFastBuffer<> *)(this + 0x2d4);
  CFastBuffer<>::CFastBuffer<>(this_00);
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(this + 0x2e0));
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(this + 0x2f8));
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(this + 0x304));
  CFastBuffer<>::CFastBuffer<>((CFastBuffer<> *)(this + 0x310));
  *(undefined4 *)(this + 0x36c) = 0;
  *(undefined4 *)(this + 0x378) = 0;
  *(undefined4 *)(this + 0x380) = 0;
  *(undefined4 *)(this + 0x2c) = 0x425e38e4;
  local_4._0_1_ = 0x20;
  *(undefined4 *)(this + 0x30) = 0x415e38e4;
  *(undefined4 *)(this + 0x3c) = 0x42480000;
  *(undefined4 *)(this + 0x88) = 1000;
  *(undefined4 *)(this + 0x8c) = 1000;
  *(undefined4 *)(this + 0x38) = 0x3f800000;
  *(undefined4 *)(this + 0x90) = 200;
  *(undefined4 *)(this + 0x58) = 0x3f800000;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0xf8) = 1000;
  *(undefined4 *)(this + 0xfc) = 1000;
  *(undefined4 *)(this + 0x60) = 0x41200000;
  *(undefined4 *)(this + 0x10c) = 0;
  *(undefined4 *)(this + 0x110) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x364) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0xc0) = 0;
  *(undefined4 *)(this + 0x6c) = 0x3f800000;
  *(undefined4 *)(this + 0x70) = 0x3f000000;
  *(undefined4 *)(this + 0x94) = 0x41a00000;
  *(undefined4 *)(this + 0x74) = 0x41a00000;
  *(undefined4 *)(this + 0x98) = 0x3c23d70a;
  *(undefined4 *)(this + 0x9c) = 0;
  *(undefined4 *)(this + 0xb4) = 0;
  *(undefined4 *)(this + 0x198) = 0;
  *(undefined4 *)(this + 0xe4) = 0x3f800000;
  *(undefined4 *)(this + 0x54) = 0x3f800000;
  *(undefined4 *)(this + 0xe8) = 0x3f800000;
  *(undefined4 *)(this + 0xec) = 0x3f800000;
  *(undefined4 *)(this + 0xc4) = 0x3f060a92;
  *(undefined4 *)(this + 200) = 0x3db2b8c3;
  *(undefined4 *)(this + 0xcc) = 0x41200000;
  *(undefined4 *)(this + 0xd0) = 0x3c23d70a;
  *(undefined4 *)(this + 0x50) = 0x3f800000;
  *(undefined4 *)(this + 0x40) = 0x41a00000;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = 0x43fa0000;
  *(undefined4 *)(this + 0x4c) = 0x43fa0000;
  *(undefined4 *)(this + 0xa4) = 0xbf800000;
  *(undefined4 *)(this + 0xa8) = 0;
  *(undefined4 *)(this + 0xb0) = 0x3f19999a;
  *(undefined4 *)(this + 0xd4) = 0;
  *(undefined4 *)(this + 0xd8) = 0;
  *(undefined4 *)(this + 0xdc) = 0;
  *(undefined4 *)(this + 0xe0) = 0;
  *(undefined **)(this + 0xf0) = &DAT_40400000;
  *(undefined **)(this + 0xf4) = &DAT_40400000;
  *(undefined4 *)(this + 0x100) = 0x3f800000;
  *(undefined4 *)(this + 0x104) = 0x41200000;
  *(undefined4 *)(this + 0x108) = 0x3dcccccd;
  *(undefined4 *)(this + 0x368) = 0x40490fdb;
  *(undefined4 *)(this + 0x114) = 0;
  *(undefined4 *)(this + 0x118) = 0;
  *(undefined4 *)(this + 0x11c) = 0;
  *(undefined4 *)(this + 0x120) = 0;
  *(undefined4 *)(this + 0x124) = 0;
  *(undefined4 *)(this + 0x194) = 0x40a00000;
  *(undefined4 *)(this + 0x128) = 0x3e4ccccd;
  *(undefined4 *)(this + 300) = 0x3dcccccd;
  *(undefined4 *)(this + 0x130) = 0x44480000;
  *(undefined4 *)(this + 0x134) = 0x3f800000;
  *(undefined4 *)(this + 0x138) = 0x3f000000;
  *(undefined4 *)(this + 0x13c) = 0x3f000000;
  *(undefined4 *)(this + 0x140) = 0x3f000000;
  *(undefined4 *)(this + 0x16c) = 9;
  *(undefined4 *)(this + 400) = 1;
  *(undefined4 *)(this + 0x144) = 0;
  *(undefined4 *)(this + 0x350) = 0;
  *(undefined4 *)(this + 0x148) = 0;
  *(undefined4 *)(this + 0x354) = 0;
  *(undefined4 *)(this + 0x358) = 0;
  *(undefined4 *)(this + 0x154) = 0x3dcccccd;
  *(undefined4 *)(this + 0x158) = 0x3f000000;
  *(undefined4 *)(this + 0x15c) = 0x3f800000;
  *(undefined4 *)(this + 0x160) = 0x3f800000;
  *(undefined4 *)(this + 0x164) = 0x3f800000;
  *(undefined4 *)(this + 0x168) = 0x3e99999a;
  *(undefined4 *)(this + 0x170) = 0x3f4ccccd;
  *(undefined4 *)(this + 0x174) = 0x3ecccccd;
  *(undefined4 *)(this + 0x188) = 0x3ecccccd;
  *(undefined4 *)(this + 0x178) = 0;
  *(undefined4 *)(this + 0x17c) = 0;
  *(undefined4 *)(this + 0x18c) = 0;
  *(undefined4 *)(this + 0x184) = 0;
  *(undefined4 *)(this + 0x180) = 0x3f4ccccd;
  *(undefined4 *)(this + 0x35c) = 0x3f800000;
  *(undefined4 *)(this + 0x360) = 0x3f800000;
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x21;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0x34)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0x34) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x34));
    }
    *(CMwNod **)(this + 0x34) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x34), -100.0, 50.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x34), 0.0, 50.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x34), 100.0, 1.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x34), 200.0, 0.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x34), 300.0, 0.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x34), 400.0, 0.0);
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x22;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0xb8)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0xb8) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0xb8));
    }
    *(CMwNod **)(this + 0xb8) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0xb8), 0.0, 0.0);
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x23;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0xac)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0xac) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0xac));
    }
    *(CMwNod **)(this + 0xac) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0xac), 0.0, 30.0);
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x24;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0x68)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0x68) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x68));
    }
    *(CMwNod **)(this + 0x68) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x68), 0.0, 2.0);
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x25;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0x78)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0x78) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x78));
    }
    *(CMwNod **)(this + 0x78) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x78), 0.0, 0.0);
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x26;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0xbc)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0xbc) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0xbc));
    }
    *(CMwNod **)(this + 0xbc) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0xbc), 0.0, 1.0);
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x27;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0xa0)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0xa0) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0xa0));
    }
    *(CMwNod **)(this + 0xa0) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0xa0), 0.0, 10.0);
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x28;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0x36c)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0x36c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x36c));
    }
    *(CMwNod **)(this + 0x36c) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x36c), 0.0, 1.0);
  *(undefined4 *)(this + 0x37c) = 0x3f800000;
  *(undefined4 *)(this + 0x388) = 0x3f800000;
  *(undefined4 *)(this + 0x394) = 0x3f800000;
  *(undefined4 *)(this + 0x38c) = 0x3f800000;
  *(undefined4 *)(this + 0x390) = 0x3f800000;
  *(undefined4 *)(this + 0x398) = 0x41a00000;
  *(undefined4 *)(this + 0x39c) = 0x40a00000;
  *(undefined4 *)(this + 0x28) = 0x41a00000;
  *(undefined4 *)(this + 0x3a0) = 0x40a00000;
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x29;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0x380)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0x380) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x380));
    }
    *(CMwNod **)(this + 0x380) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x380), 0.0, 0.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x380), 20.0, 1.0);
  *(undefined4 *)(this + 900) = 0xbe99999a;
  *(undefined4 *)(this + 0x3a4) = 0x420c0000;
  *(undefined4 *)(this + 0x3a8) = 0x3e4ccccd;
  *(undefined4 *)(this + 0x14c) = 0x42c80000;
  *(undefined4 *)(this + 0x150) = 0x461c4000;
  *(undefined4 *)(this + 0x1a0) = 0x3f800000;
  *(undefined4 *)(this + 0x1a4) = 0;
  *(undefined4 *)(this + 0x1a8) = 0x3f800000;
  *(undefined4 *)(this + 0x1ac) = 0;
  *(undefined4 *)(this + 0x19c) = 0x3f800000;
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x2a;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0x1b4)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0x1b4) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x1b4));
    }
    *(CMwNod **)(this + 0x1b4) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x1b4), 0.0, 10.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x1b4), 100.0, 20.0);
  *(undefined4 *)(this + 0x1b8) = 0x3f800000;
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x2b;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0x1c4)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0x1c4) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x1c4));
    }
    *(CMwNod **)(this + 0x1c4) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x1c4), 0.0, 100.0);
  *(undefined4 *)(this + 0x1c8) = 0x3f800000;
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x2c;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0x1bc)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0x1bc) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x1bc));
    }
    *(CMwNod **)(this + 0x1bc) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x1bc), 0.0, 40.0);
  *(undefined4 *)(this + 0x1c0) = 0x3f800000;
  *(undefined4 *)(this + 0x1cc) = 0x3ba3d70a;
  *(undefined4 *)(this + 0x1d0) = 0x3e99999a;
  *(undefined4 *)(this + 0x1b0) = 0x3f800000;
  *(undefined4 *)(this + 0x1d4) = 0;
  *(undefined4 *)(this + 0x1d8) = 0x3f490fdb;
  *(undefined4 *)(this + 0x1dc) = 0x3f490fdb;
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x2d;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0x1e0)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0x1e0) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x1e0));
    }
    *(CMwNod **)(this + 0x1e0) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x1e0), -100.0, 50.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x1e0), 0.0, 50.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x1e0), 100.0, 1.0);
  *(undefined4 *)(this + 0x1e4) = 0x3f800000;
  *(undefined4 *)(this + 0x1e8) = 500;
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x2e;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0x1ec)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0x1ec) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x1ec));
    }
    *(CMwNod **)(this + 0x1ec) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x1ec), 0.0, 1.0);
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x2f;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0x1f0)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0x1f0) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x1f0));
    }
    *(CMwNod **)(this + 0x1f0) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x1f0), 0.0, 0.0);
  *(undefined4 *)(this + 500) = 0x41a00000;
  *(undefined4 *)(this + 0x1f8) = 0;
  *(undefined4 *)(this + 0x1fc) = 1;
  *(undefined4 *)(this + 0x200) = 0x3f800000;
  *(undefined4 *)(this + 0x204) = 0x3f800000;
  *(undefined4 *)(this + 0x208) = 0x425e38e4;
  *(undefined4 *)(this + 0x20c) = 0x42480000;
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x30;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0x210)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0x210) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x210));
    }
    *(CMwNod **)(this + 0x210) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x210), 0.0, 1.0);
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x31;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0x214)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0x214) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x214));
    }
    *(CMwNod **)(this + 0x214) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x214), 0.0, 0.0);
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x32;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0x218)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0x218) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x218));
    }
    *(CMwNod **)(this + 0x218) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x218), 0.0, 0.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x218), 1000.0,
                               1000.0);
  *(undefined4 *)(this + 0x21c) = 0x3dcccccd;
  *(undefined4 *)(this + 0x220) = 0x3e4ccccd;
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x33;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0x224)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0x224) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x224));
    }
    *(CMwNod **)(this + 0x224) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x224), 0.0, 1.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x224), 0.5, 2.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x224), 1.0, 3.0);
  *(undefined4 *)(this + 0x228) = 0x40a00000;
  *(undefined4 *)(this + 0x22c) = 0x43480000;
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x34;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0x230)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0x230) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x230));
    }
    *(CMwNod **)(this + 0x230) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x230), -100.0, 2.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x230), -50.0, 5.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x230), 0.0, 10.0);
  *(undefined4 *)(this + 0x234) = 0x3c23d70a;
  *(undefined4 *)(this + 0x238) = 0x3dcccccd;
  *(undefined4 *)(this + 0x23c) = 0x3dcccccd;
  *(undefined4 *)(this + 0x254) = 0x41200000;
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x35;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0x25c)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0x25c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x25c));
    }
    *(CMwNod **)(this + 0x25c) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x25c), 0.0, 1.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x25c), 5.0, 2.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x25c), 10.0, 3.0);
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x36;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0x260)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0x260) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x260));
    }
    *(CMwNod **)(this + 0x260) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x260), 0.0, 0.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x260), 1.0, 30.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x260), 10.0, 30.0);
  *(undefined4 *)(this + 0x264) = 0x3f800000;
  *(undefined **)(this + 600) = &DAT_40400000;
  *(undefined4 *)(this + 0x268) = 0x40c00000;
  *(undefined4 *)(this + 0x278) = 0x3f800000;
  *(undefined4 *)(this + 0x27c) = 0x3e4ccccd;
  *(undefined4 *)(this + 0x280) = 0x41a00000;
  *(undefined4 *)(this + 0x284) = 0x41200000;
  *(undefined4 *)(this + 0x26c) = 0x40000000;
  *(undefined4 *)(this + 0x270) = 0x3f000000;
  *(undefined4 *)(this + 0x274) = 0x3f000000;
  *(undefined4 *)(this + 0x240) = 0x3f000000;
  *(undefined4 *)(this + 0x298) = 1000;
  *(undefined4 *)(this + 0x2a8) = 500;
  *(undefined4 *)(this + 0x29c) = 0x3f000000;
  *(undefined4 *)(this + 0x2a0) = 0x3c23d70a;
  *(undefined4 *)(this + 0x2ac) = 0x40800000;
  *(undefined4 *)(this + 0x244) = 0x3e4ccccd;
  *(undefined4 *)(this + 0x2c0) = 0x3f800000;
  *(undefined4 *)(this + 0x2b4) = 0x3f800000;
  *(undefined4 *)(this + 0x2b0) = 0x40a00000;
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x37;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0x2a4)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0x2a4) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x2a4));
    }
    *(CMwNod **)(this + 0x2a4) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x2a4), 0.0, 1.5);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x2a4), 10.0, 1.2);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x2a4), 50.0, 0.2);
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x38;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4._0_1_ = 0x20;
  if (pCVar3 != *(CMwNod **)(this + 0x288)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0x288) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x288));
    }
    *(CMwNod **)(this + 0x288) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x288), 0.0, 0.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x288), 10.0, 5.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x288), 20.0, 6.0);
  pCVar1 = (CFastBuffer<float> *)(this + 0x2c4);
  *(undefined4 *)(this + 0x28c) = 0x3eb33333;
  *(undefined4 *)(this + 700) = 0x43160000;
  *(undefined4 *)(this + 0x290) = 0x3fdf65fe;
  *(undefined4 *)(this + 0x294) = 0x3f48f5c3;
  *(undefined4 *)(this + 0x2b8) = 0x41200000;
  *(undefined4 *)(this + 0x2d0) = 0x3f4ccccd;
  CFastBuffer<float>::AllocSetCount(pCVar1, 6);
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar1, 0);
  *puVar4 = 0x40800000;
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar1, 1);
  *puVar4 = 0x40000000;
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar1, 2);
  *puVar4 = 0x3f800000;
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar1, 3);
  *puVar4 = 0x3f4ccccd;
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar1, 4);
  *puVar4 = 0x3f000000;
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar1, 5);
  *puVar4 = 0x3e99999a;
  pCVar2 = (CFuncKeysReal *)operator_new(0x2c);
  local_4._0_1_ = 0x39;
  if (pCVar2 == (CFuncKeysReal *)0x0) {
    pCVar3 = (CMwNod *)0x0;
  } else {
    pCVar3 = (CMwNod *)CFuncKeysReal::CFuncKeysReal(pCVar2);
  }
  local_4 = CONCAT31(local_4._1_3_, 0x20);
  if (pCVar3 != *(CMwNod **)(this + 0x250)) {
    if (pCVar3 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar3);
    }
    if (*(CMwNod **)(this + 0x250) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x250));
    }
    *(CMwNod **)(this + 0x250) = pCVar3;
  }
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x250), 0.0, 0.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x250), 1.0, 0.8);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x250), 10.0, 1.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x250), 20.0, 1.0);
  CFuncKeysReal::InsertKeyReal(*(CFuncKeysReal **)(this + 0x250), 30.0, 1.0);
  CFastBuffer<float>::AllocSetCount((CFastBuffer<float> *)this_00, 6);
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, 0);
  *puVar4 = 0;
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, 1);
  *puVar4 = 0x3f500000;
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, 2);
  *puVar4 = 0x3f500000;
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, 3);
  *puVar4 = 0x3f500000;
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, 4);
  *puVar4 = 0x3f500000;
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, 5);
  pCVar1 = (CFastBuffer<float> *)(this + 0x2e0);
  *puVar4 = 0x3f800000;
  CFastBuffer<float>::AllocSetCount(pCVar1, 6);
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar1, 0);
  *puVar4 = 0;
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar1, 1);
  *puVar4 = 0;
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar1, 2);
  *puVar4 = 0x3ec00000;
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar1, 3);
  *puVar4 = 0x3f080000;
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar1, 4);
  *puVar4 = 0x3f100000;
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar1, 5);
  *puVar4 = 0x3f200000;
  pCVar1 = (CFastBuffer<float> *)(this + 0x2f8);
  *(undefined4 *)(this + 0x2ec) = 0x459c4000;
  *(undefined4 *)(this + 0x2f0) = 0x459c4000;
  *(undefined4 *)(this + 0x2f4) = 0x451c4000;
  CFastBuffer<float>::AllocSetCount(pCVar1, 6);
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar1, 0);
  *puVar4 = 0;
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar1, 1);
  *puVar4 = 0;
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar1, 2);
  *puVar4 = 0x3edb645a;
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar1, 3);
  *puVar4 = 0x3eaa7efa;
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar1, 4);
  *puVar4 = 0x3e800000;
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar1, 5);
  pCVar1 = (CFastBuffer<float> *)(this + 0x304);
  *puVar4 = 0x3e29fbe7;
  CFastBuffer<float>::AllocSetCount(pCVar1, 6);
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar1, 0);
  *puVar4 = 0;
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar1, 1);
  *puVar4 = 0;
  *(undefined4 *)(this + 0x31c) = 0x459c4000;
  *(undefined4 *)(this + 800) = 0x461c4000;
  *(undefined4 *)(this + 0x324) = 0x461c4000;
  *(undefined4 *)(this + 0x328) = 0x457a0000;
  pCVar1 = (CFastBuffer<float> *)(this + 0x310);
  CFastBuffer<float>::AllocSetCount(pCVar1, 6);
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar1, 0);
  *puVar4 = 0;
  puVar4 = (undefined4 *)CFastBuffer<>::operator[]((CFastBuffer<> *)pCVar1, 5);
  *puVar4 = 0;
  *(undefined **)(this + 0x32c) = &DAT_40400000;
  *(undefined4 *)(this + 0x334) = 0x40000000;
  *(undefined4 *)(this + 0x338) = 0xc0400000;
  *(undefined4 *)(this + 0x330) = 0xc0000000;
  *(undefined4 *)(this + 0x248) = 0x42c80000;
  *(undefined4 *)(this + 0x24c) = 0x42480000;
  *(undefined4 *)(this + 0x33c) = 0x3d4ccccd;
  *(undefined4 *)(this + 0x340) = 0x41a00000;
  *(undefined4 *)(this + 0x344) = 0x41700000;
  *(undefined4 *)(this + 0x348) = 0x3f800000;
  *(undefined4 *)(this + 0x34c) = 0x40000000;
  ExceptionList = local_c;
  return this;
}

/* public: float __thiscall
 * CSceneVehicleCarTuning::GetAccelFromSpeed(float)const  */

float __thiscall CSceneVehicleCarTuning::GetAccelFromSpeed(
    CSceneVehicleCarTuning *this, float param_1)

{
  ulong local_8;
  float local_4;

  local_8 = 0;
  *(undefined4 *)(*(int *)(this + 0x34) + 0x28) = 1;
  CFuncKeysReal::GetValue(*(CFuncKeysReal **)(this + 0x34), param_1 * 3.6,
                          &local_4, &local_8);
  return local_4;
}

/* public: virtual unsigned long __thiscall
 * CSceneVehicleCarTuning::GetChunkCount(void)const  */

ulong __thiscall CSceneVehicleCarTuning::GetChunkCount(
    CSceneVehicleCarTuning *this)

{
  return 0x6c;
}

/* WARNING: Switch with 1 destination removed at 0x007f3355 : 6 cases all go to
 * same destination */
/* public: virtual unsigned long __thiscall
 * CSceneVehicleCarTuning::GetChunkInfo(unsigned long)const
 */

ulong __thiscall CSceneVehicleCarTuning::GetChunkInfo(
    CSceneVehicleCarTuning *this, ulong param_1)

{
  ulong uVar1;

  if (param_1 < 0xa029036) {
    if (param_1 == 0xa029035) {
      return 3;
    }
    switch (param_1) {
    case 0xa029000:
    case 0xa029001:
    case 0xa029002:
    case 0xa029004:
    case 0xa029005:
    case 0xa029007:
    case 0xa029009:
    case 0xa02900b:
    case 0xa02900d:
    case 0xa02900e:
    case 0xa029010:
    case 0xa029013:
    case 0xa029014:
    case 0xa029017:
    case 0xa029018:
    case 0xa029019:
    case 0xa02901a:
    case 0xa02901b:
    case 0xa02901d:
    case 0xa02901e:
    case 0xa02901f:
    case 0xa029020:
    case 0xa029023:
    case 0xa029024:
    case 0xa029026:
    case 0xa029027:
    case 0xa029028:
    case 0xa029029:
    case 0xa02902a:
    case 0xa02902b:
    case 0xa02902c:
    case 0xa02902d:
    case 0xa02902e:
    case 0xa029030:
    case 0xa029031:
    case 0xa029032:
    case 0xa029033:
    case 0xa029034:
      return 3;
    case 0xa029003:
    case 0xa029006:
    case 0xa029008:
    case 0xa02900a:
    case 0xa02900c:
    case 0xa02900f:
    case 0xa029011:
    case 0xa029012:
    case 0xa029015:
    case 0xa029016:
    case 0xa02901c:
    case 0xa029021:
    case 0xa029022:
    case 0xa029025:
    case 0xa02902f:
      goto switchD_007f32fc_caseD_a029003;
    default:
      goto switchD_007f32fc_caseD_35;
    }
  }
  if (param_1 < 0xa029051) {
    if (param_1 != 0xa029050) {
      switch (param_1) {
      case 0xa029036:
      case 0xa029037:
      case 0xa029038:
      case 0xa029039:
      case 0xa02903a:
      case 0xa02903b:
      case 0xa02903c:
      case 0xa02903d:
      case 0xa02903e:
      case 0xa02903f:
      case 0xa029040:
      case 0xa029041:
      case 0xa029042:
      case 0xa029043:
      case 0xa029044:
      case 0xa029046:
      case 0xa029047:
      case 0xa029049:
      case 0xa02904d:
      case 0xa02904e:
      case 0xa02904f:
        goto switchD_007f32fc_caseD_a029000;
      case 0xa029045:
      case 0xa029048:
      case 0xa02904a:
      case 0xa02904b:
      case 0xa02904c:
        break;
      default:
        goto switchD_007f32fc_caseD_35;
      }
    }
  switchD_007f32fc_caseD_a029003:
    return 1;
  }
  if (0xa02905e < param_1) {
    if (param_1 < 0xa029066) {
      if (param_1 == 0xa029065) {
        return 3;
      }
      if (param_1 + 0xf5fd6fa1 < 6) {
        return 3;
      }
    } else if (param_1 < 0xa029069) {
      if (param_1 == 0xa029068) {
        return 1;
      }
      if (param_1 == 0xa029066) {
        return 3;
      }
      if (param_1 == 0xa029067) {
        return 1;
      }
    } else {
      if (param_1 == 0xa029069) {
        return 1;
      }
      if (param_1 == 0xffffffff) {
        return 0xffffffff;
      }
    }
  switchD_007f32fc_caseD_35:
    uVar1 =
        CSceneVehicleTuning::GetChunkInfo((CSceneVehicleTuning *)this, param_1);
    return uVar1;
  }
  if (param_1 != 0xa02905e) {
    switch (param_1) {
    case 0xa029051:
    case 0xa029052:
    case 0xa029053:
    case 0xa029056:
    case 0xa029057:
    case 0xa029058:
    case 0xa029059:
    case 0xa02905a:
    case 0xa02905b:
    case 0xa02905c:
    case 0xa02905d:
      break;
    case 0xa029054:
    case 0xa029055:
      goto switchD_007f32fc_caseD_a029003;
    default:
      goto switchD_007f32fc_caseD_35;
    }
  }
switchD_007f32fc_caseD_a029000:
  return 3;
}

/* public: float __thiscall
 * CSceneVehicleCarTuning::GetLateralContactSlowDownFromSpeed(float)const
 */

float __thiscall CSceneVehicleCarTuning::GetLateralContactSlowDownFromSpeed(
    CSceneVehicleCarTuning *this, float param_1)

{
  ulong local_8;
  float local_4;

  local_8 = 0;
  *(undefined4 *)(*(int *)(this + 0x68) + 0x28) = 1;
  CFuncKeysReal::GetValue(*(CFuncKeysReal **)(this + 0x68), param_1 * 3.6,
                          &local_4, &local_8);
  return local_4;
}

/* public: float __thiscall
 * CSceneVehicleCarTuning::GetMaxSideFrictionFromSpeed(float)const  */

float __thiscall CSceneVehicleCarTuning::GetMaxSideFrictionFromSpeed(
    CSceneVehicleCarTuning *this, float param_1)

{
  ulong local_4;

  param_1 = param_1 * 3.6;
  local_4 = 0;
  CFuncKeysReal::GetValue(*(CFuncKeysReal **)(this + 0xac), param_1, &param_1,
                          &local_4);
  return param_1;
}

/* public: virtual unsigned long __thiscall
 * CSceneVehicleCarTuning::GetMwClassId(void)const  */

ulong __thiscall CSceneVehicleCarTuning::GetMwClassId(
    CSceneVehicleCarTuning *this)

{
  return 0xa029000;
}

/* public: float __thiscall
 * CSceneVehicleCarTuning::GetRolloverLateralCoefFromAngle(float)const  */

float __thiscall CSceneVehicleCarTuning::GetRolloverLateralCoefFromAngle(
    CSceneVehicleCarTuning *this, float param_1)

{
  ulong local_4;

  local_4 = 0;
  CFuncKeysReal::GetValue(*(CFuncKeysReal **)(this + 0xbc), param_1, &param_1,
                          &local_4);
  return param_1;
}

/* public: float __thiscall
 * CSceneVehicleCarTuning::GetRolloverLateralFromSpeed(float)const  */

float __thiscall CSceneVehicleCarTuning::GetRolloverLateralFromSpeed(
    CSceneVehicleCarTuning *this, float param_1)

{
  ulong local_4;

  param_1 = param_1 * 3.6;
  local_4 = 0;
  CFuncKeysReal::GetValue(*(CFuncKeysReal **)(this + 0xb8), param_1, &param_1,
                          &local_4);
  return param_1;
}

/* public: float __thiscall
 * CSceneVehicleCarTuning::GetSteerDriveTorqueFromSpeed(float)const  */

float __thiscall CSceneVehicleCarTuning::GetSteerDriveTorqueFromSpeed(
    CSceneVehicleCarTuning *this, float param_1)

{
  ulong local_4;

  param_1 = param_1 * 3.6;
  local_4 = 0;
  CFuncKeysReal::GetValue(*(CFuncKeysReal **)(this + 0xa0), param_1, &param_1,
                          &local_4);
  return param_1;
}

/* public: float __thiscall
 * CSceneVehicleCarTuning::GetSteerSlowDownFromSpeed(float)const  */

float __thiscall CSceneVehicleCarTuning::GetSteerSlowDownFromSpeed(
    CSceneVehicleCarTuning *this, float param_1)

{
  ulong local_8;
  float local_4;

  local_8 = 0;
  *(undefined4 *)(*(int *)(this + 0x78) + 0x28) = 1;
  CFuncKeysReal::GetValue(*(CFuncKeysReal **)(this + 0x78), param_1 * 3.6,
                          &local_4, &local_8);
  return local_4;
}

/* public: virtual unsigned long __thiscall
   CSceneVehicleCarTuning::GetUidChunkFromIndex(unsigned long)const  */

ulong __thiscall CSceneVehicleCarTuning::GetUidChunkFromIndex(
    CSceneVehicleCarTuning *this, ulong param_1)

{
  if (1 < param_1) {
    return param_1 - 2 | 0xa029000;
  }
  if (param_1 == 0) {
    return 0x1001000;
  }
  return param_1 - 1 | 0xa02e000;
}

/* public: float __thiscall
 * CSceneVehicleCarTuning::GetWaterFrictionFromSpeed(float)const  */

float __thiscall CSceneVehicleCarTuning::GetWaterFrictionFromSpeed(
    CSceneVehicleCarTuning *this, float param_1)

{
  ulong local_4;

  param_1 = param_1 * 3.6;
  local_4 = 0;
  CFuncKeysReal::GetValue(*(CFuncKeysReal **)(this + 0x218), param_1, &param_1,
                          &local_4);
  return param_1;
}

/* public: float __thiscall
 * CSceneVehicleCarTuning::M4GetMaxFrictionForceFromSpeed(float)const  */

float __thiscall CSceneVehicleCarTuning::M4GetMaxFrictionForceFromSpeed(
    CSceneVehicleCarTuning *this, float param_1)

{
  ulong local_4;

  param_1 = param_1 * 3.6;
  local_4 = 0;
  CFuncKeysReal::GetValue(*(CFuncKeysReal **)(this + 0x1bc), param_1, &param_1,
                          &local_4);
  return param_1;
}

/* public: float __thiscall
 * CSceneVehicleCarTuning::M4GetSteerRadiusFromSpeed(float)const  */

float __thiscall CSceneVehicleCarTuning::M4GetSteerRadiusFromSpeed(
    CSceneVehicleCarTuning *this, float param_1)

{
  ulong local_4;

  param_1 = param_1 * 3.6;
  local_4 = 0;
  CFuncKeysReal::GetValue(*(CFuncKeysReal **)(this + 0x1b4), param_1, &param_1,
                          &local_4);
  return param_1;
}

/* public: float __thiscall
 * CSceneVehicleCarTuning::M5GetAccelFromSpeed(float)const  */

float __thiscall CSceneVehicleCarTuning::M5GetAccelFromSpeed(
    CSceneVehicleCarTuning *this, float param_1)

{
  ulong local_4;

  param_1 = param_1 * 3.6;
  local_4 = 0;
  CFuncKeysReal::GetValue(*(CFuncKeysReal **)(this + 0x34), param_1, &param_1,
                          &local_4);
  return param_1;
}

/* public: float __thiscall
 * CSceneVehicleCarTuning::M5GetLateralContactSlowDownFromSpeed(float)const
 */

float __thiscall CSceneVehicleCarTuning::M5GetLateralContactSlowDownFromSpeed(
    CSceneVehicleCarTuning *this, float param_1)

{
  float fVar1;

  fVar1 = CFuncKeysReal::GetValue(*(CFuncKeysReal **)(this + 0x68),
                                  param_1 * 3.6, (ulong *)0x0);
  return fVar1;
}

/* public: float __thiscall
 * CSceneVehicleCarTuning::M5GetSlippingAccelFromSpeed(float)const  */

float __thiscall CSceneVehicleCarTuning::M5GetSlippingAccelFromSpeed(
    CSceneVehicleCarTuning *this, float param_1)

{
  ulong local_4;

  param_1 = param_1 * 3.6;
  local_4 = 0;
  CFuncKeysReal::GetValue(*(CFuncKeysReal **)(this + 0x1e0), param_1, &param_1,
                          &local_4);
  return *(float *)(this + 0x1e4) * param_1;
}

/* public: float __thiscall
 * CSceneVehicleCarTuning::M5GetSteerSlowDownFromSpeed(float)const  */

float __thiscall CSceneVehicleCarTuning::M5GetSteerSlowDownFromSpeed(
    CSceneVehicleCarTuning *this, float param_1)

{
  ulong local_4;

  param_1 = param_1 * 3.6;
  local_4 = 0;
  CFuncKeysReal::GetValue(*(CFuncKeysReal **)(this + 0x78), param_1, &param_1,
                          &local_4);
  return param_1;
}

/* public: void __thiscall
 * CSceneVehicleCarTuning::M6CheckRpmWantedConstistensy(void) */

void __thiscall CSceneVehicleCarTuning::M6CheckRpmWantedConstistensy(
    CSceneVehicleCarTuning *this)

{
  CFastBuffer<> *this_00;
  ulong uVar1;
  float *pfVar2;
  float *pfVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  ulong uVar6;

  this_00 = (CFastBuffer<> *)(this + 0x2e0);
  uVar1 = CFastBuffer<>::GetCount(this_00);
  uVar6 = 0;
  if (uVar1 != 0) {
    do {
      pfVar2 =
          (float *)CFastBuffer<>::operator[]((CFastBuffer<> *)this_00, uVar6);
      pfVar3 = (float *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(this + 0x2f8), uVar6);
      if (*pfVar3 < *pfVar2 != (NAN(*pfVar3) || NAN(*pfVar2))) {
        puVar4 = (undefined4 *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)this_00, uVar6);
        puVar5 = (undefined4 *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(this + 0x2f8), uVar6);
        *puVar5 = *puVar4;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar1);
  }
  return;
}

/* public: float __thiscall
 * CSceneVehicleCarTuning::M6GetBurnoutRadiusFromSpeed(float)const  */

float __thiscall CSceneVehicleCarTuning::M6GetBurnoutRadiusFromSpeed(
    CSceneVehicleCarTuning *this, float param_1)

{
  ulong local_4;

  param_1 = param_1 * 3.6;
  local_4 = 0;
  CFuncKeysReal::GetValue(*(CFuncKeysReal **)(this + 0x25c), param_1, &param_1,
                          &local_4);
  return param_1;
}

/* public: float __thiscall
 * CSceneVehicleCarTuning::M6GetBurnoutRolloverFromSpeed(float)const  */

float __thiscall CSceneVehicleCarTuning::M6GetBurnoutRolloverFromSpeed(
    CSceneVehicleCarTuning *this, float param_1)

{
  ulong local_4;

  param_1 = param_1 * 3.6;
  local_4 = 0;
  CFuncKeysReal::GetValue(*(CFuncKeysReal **)(this + 0x2a4), param_1, &param_1,
                          &local_4);
  return param_1;
}

/* public: float __thiscall
 * CSceneVehicleCarTuning::M6GetDonutRolloverFromSpeed(float)const  */

float __thiscall CSceneVehicleCarTuning::M6GetDonutRolloverFromSpeed(
    CSceneVehicleCarTuning *this, float param_1)

{
  ulong local_4;

  param_1 = param_1 * 3.6;
  local_4 = 0;
  CFuncKeysReal::GetValue(*(CFuncKeysReal **)(this + 0x288), param_1, &param_1,
                          &local_4);
  return param_1;
}

/* public: float __thiscall
 * CSceneVehicleCarTuning::M6GetLateralSpeedFromBurnoutRadius(float)const
 */

float __thiscall CSceneVehicleCarTuning::M6GetLateralSpeedFromBurnoutRadius(
    CSceneVehicleCarTuning *this, float param_1)

{
  ulong local_4;

  local_4 = 0;
  CFuncKeysReal::GetValue(*(CFuncKeysReal **)(this + 0x260), param_1, &param_1,
                          &local_4);
  return param_1 / 3.6;
}

/* public: float __thiscall
 * CSceneVehicleCarTuning::M6GetModulationFromDamperAbsorbVal(float)const
 */

float __thiscall CSceneVehicleCarTuning::M6GetModulationFromDamperAbsorbVal(
    CSceneVehicleCarTuning *this, float param_1)

{
  float fVar1;
  ulong local_4;

  local_4 = 0;
  if ((NAN(*(float *)(this + 0x120)) || NAN(*(float *)(this + 0x11c))) ==
      (*(float *)(this + 0x120) == *(float *)(this + 0x11c))) {
    fVar1 = (param_1 - *(float *)(this + 0x120)) /
            (*(float *)(this + 0x11c) - *(float *)(this + 0x120));
    param_1 = fVar1;
  } else {
    fVar1 = 0.0;
  }
  CFuncKeysReal::GetValue(*(CFuncKeysReal **)(this + 0x224), fVar1, &param_1,
                          &local_4);
  return param_1;
}

/* public: float __thiscall
 * CSceneVehicleCarTuning::M6GetRearGearAccelFromSpeed(float)const  */

float __thiscall CSceneVehicleCarTuning::M6GetRearGearAccelFromSpeed(
    CSceneVehicleCarTuning *this, float param_1)

{
  ulong local_4;

  param_1 = param_1 * 3.6;
  local_4 = 0;
  CFuncKeysReal::GetValue(*(CFuncKeysReal **)(this + 0x230), param_1, &param_1,
                          &local_4);
  return param_1;
}

/* public: float __thiscall
 * CSceneVehicleCarTuning::M6GetRolloverLateralFromSpeedRatio(float)const
 */

float __thiscall CSceneVehicleCarTuning::M6GetRolloverLateralFromSpeedRatio(
    CSceneVehicleCarTuning *this, float param_1)

{
  ulong local_4;

  param_1 = param_1 * 3.6;
  local_4 = 0;
  CFuncKeysReal::GetValue(*(CFuncKeysReal **)(this + 0x250), param_1, &param_1,
                          &local_4);
  return param_1;
}

/* public: void __thiscall CSceneVehicleCarTuning::M6InitRpmDelta(void) */

void __thiscall CSceneVehicleCarTuning::M6InitRpmDelta(
    CSceneVehicleCarTuning *this)

{
  ulong uVar1;
  CFastBuffer<> *this_00;
  float fVar2;
  float fVar3;
  ulong uVar4;
  undefined4 *puVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  float *pfVar9;
  float *pfVar10;
  float *pfVar11;
  ulong uVar12;

  uVar4 = CFastBuffer<>::GetCount((CFastBuffer<> *)(this + 0x2d4));
  this_00 = (CFastBuffer<> *)(this + 0x304);
  puVar5 = (undefined4 *)CFastBuffer<>::operator[](this_00, 0);
  *puVar5 = 0;
  puVar5 = (undefined4 *)CFastBuffer<>::operator[](this_00, 1);
  uVar12 = 2;
  *puVar5 = 0;
  if (2 < uVar4) {
    do {
      pfVar6 = (float *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(this + 0x2c4), uVar12);
      uVar1 = uVar12 - 1;
      pfVar7 = (float *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(this + 0x2c4), uVar1);
      fVar2 = *pfVar6;
      fVar3 = *pfVar7;
      pfVar6 = (float *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(this + 0x2f8), uVar12);
      pfVar7 = (float *)CFastBuffer<>::operator[](
          (CFastBuffer<> *)(this + 0x2d4), uVar1);
      pfVar8 = (float *)CFastBuffer<>::operator[](this_00, uVar1);
      pfVar9 = (float *)CFastBuffer<>::operator[](this_00, uVar12);
      uVar12 = uVar12 + 1;
      *pfVar9 =
          *pfVar8 * (fVar2 / fVar3) +
          (*pfVar6 - (fVar2 / fVar3) * *pfVar7) * *(float *)(this + 0x2d0);
    } while (uVar12 < uVar4);
  }
  uVar12 = 1;
  if (1 < uVar4 - 1) {
    do {
      if (NAN(*(float *)(this + 0x2d0)) == (*(float *)(this + 0x2d0) == 0.0)) {
        uVar1 = uVar12 + 1;
        pfVar6 = (float *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(this + 0x2e0), uVar1);
        pfVar7 = (float *)CFastBuffer<>::operator[](this_00, uVar1);
        pfVar8 = (float *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(this + 0x2c4), uVar12);
        pfVar9 = (float *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(this + 0x2c4), uVar1);
        pfVar11 = (float *)CFastBuffer<>::operator[](this_00, uVar12);
        pfVar10 = (float *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(this + 0x310), uVar12);
        fVar2 = *pfVar11 / *(float *)(this + 0x2d0) +
                ((*pfVar6 - *pfVar7 / *(float *)(this + 0x2d0)) * *pfVar8) /
                    *pfVar9;
      } else {
        pfVar10 = (float *)CFastBuffer<>::operator[](
            (CFastBuffer<> *)(this + 0x310), uVar12);
        fVar2 = 0.0;
      }
      uVar12 = uVar12 + 1;
      *pfVar10 = fVar2;
    } while (uVar12 < uVar4 - 1);
  }
  return;
}

/* public: virtual class CMwClassInfo const * __thiscall
   CSceneVehicleCarTuning::MwGetClassInfo(void)const  */

CMwClassInfo *__thiscall CSceneVehicleCarTuning::MwGetClassInfo(
    CSceneVehicleCarTuning *this)

{
  return &m_MwClassInfo_CSceneVehicleCarTuning;
}

/* public: virtual int __thiscall CSceneVehicleCarTuning::MwIsKindOf(unsigned
 * long)const  */

int __thiscall CSceneVehicleCarTuning::MwIsKindOf(CSceneVehicleCarTuning *this,
                                                  ulong param_1)

{
  if ((param_1 != 0xa029000) && (param_1 != 0xa02e000)) {
    return (uint)(param_1 == 0x1001000);
  }
  return 1;
}

/* public: static class CMwNod * __cdecl
 * CSceneVehicleCarTuning::MwNewCSceneVehicleCarTuning(void)
 */

CMwNod *__cdecl CSceneVehicleCarTuning::MwNewCSceneVehicleCarTuning(void)

{
  CSceneVehicleCarTuning *this;
  CMwNod *pCVar1;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad00ab;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this = (CSceneVehicleCarTuning *)operator_new(0x3ac);
  local_4 = 0;
  if (this != (CSceneVehicleCarTuning *)0x0) {
    pCVar1 = (CMwNod *)CSceneVehicleCarTuning(this);
    ExceptionList = local_c;
    return pCVar1;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}

/* public: virtual void __thiscall CSceneVehicleCarTuning::OnNodLoaded(void) */

void __thiscall CSceneVehicleCarTuning::OnNodLoaded(
    CSceneVehicleCarTuning *this)

{
  CScene2d::OnNodLoaded((CScene2d *)this);
  M6InitRpmDelta(this);
  return;
}

/* public: virtual unsigned long __thiscall
 *CSceneVehicleCarTuning::VirtualParam_Get(class CMwStack ,class CMwValueStd *)
*/

ulong __thiscall CSceneVehicleCarTuning::VirtualParam_Get(
    CSceneVehicleCarTuning *this, CMwStack *param_1, CMwValueStd *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;

  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  uVar3 = *(uint *)(iVar2 + 4);
  if (uVar3 < 0xa029097) {
    switch (uVar3) {
    case 0xa029000:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x2c) * 3.6;
      return 0;
    case 0xa029001:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x30) * 3.6;
      return 0;
    case 0xa029002:
    case 0xa029003:
    case 0xa029004:
    case 0xa029005:
    case 0xa029006:
    case 0xa029007:
    case 0xa029008:
    case 0xa029009:
    case 0xa02900a:
    case 0xa02900b:
    case 0xa02900c:
    case 0xa02900d:
    case 0xa02900e:
    case 0xa02900f:
    case 0xa029010:
    case 0xa029011:
    case 0xa029012:
    case 0xa029013:
    case 0xa029014:
    case 0xa029015:
    case 0xa029016:
    case 0xa029017:
    case 0xa029018:
    case 0xa029019:
    case 0xa02901a:
    case 0xa02901b:
    case 0xa02901c:
    case 0xa02901e:
    case 0xa02901f:
    case 0xa029020:
    case 0xa029021:
    case 0xa029022:
    case 0xa029023:
    case 0xa029024:
    case 0xa029025:
    case 0xa029026:
    case 0xa029027:
    case 0xa029028:
    case 0xa029029:
    case 0xa02902a:
    case 0xa02902b:
    case 0xa02902c:
    case 0xa02902d:
    case 0xa02902e:
    case 0xa02902f:
    case 0xa029030:
    case 0xa029031:
    case 0xa029032:
    case 0xa029033:
    case 0xa029034:
    case 0xa029035:
    case 0xa029036:
    case 0xa029037:
    case 0xa029038:
    case 0xa029039:
    case 0xa02903a:
    case 0xa02903b:
    case 0xa02903e:
    case 0xa02903f:
    case 0xa029040:
    case 0xa029041:
    case 0xa029042:
    case 0xa029043:
    case 0xa029044:
    case 0xa029045:
    case 0xa029046:
    case 0xa029047:
    case 0xa029048:
    case 0xa029049:
    case 0xa02904a:
    case 0xa02904b:
    case 0xa02904c:
    case 0xa02904d:
    case 0xa02904e:
    case 0xa02904f:
    case 0xa029050:
    case 0xa029051:
    case 0xa029052:
    case 0xa029053:
    case 0xa029054:
    case 0xa029055:
    case 0xa029056:
    case 0xa029057:
    case 0xa029058:
    case 0xa029059:
    case 0xa02905a:
    case 0xa02905b:
    case 0xa02905c:
    case 0xa02905d:
    case 0xa02905e:
    case 0xa02905f:
    case 0xa029060:
    case 0xa029061:
    case 0xa029062:
    case 0xa029063:
    case 0xa029064:
    case 0xa029065:
    case 0xa029068:
    case 0xa029069:
    case 0xa02906a:
    case 0xa02906b:
    case 0xa02906c:
    case 0xa02906d:
    case 0xa02906e:
    case 0xa02906f:
    case 0xa029070:
    case 0xa029071:
    case 0xa029072:
    case 0xa029073:
    case 0xa029074:
    case 0xa029075:
    case 0xa029076:
    case 0xa029077:
    case 0xa029078:
    case 0xa029079:
    case 0xa02907a:
    case 0xa02907b:
    case 0xa02907c:
    case 0xa02907d:
    case 0xa02907e:
    case 0xa02907f:
    case 0xa029080:
    case 0xa029081:
    case 0xa029082:
    case 0xa029083:
    case 0xa029084:
    case 0xa029085:
    case 0xa029086:
    case 0xa029087:
    case 0xa029088:
    case 0xa029089:
    case 0xa02908a:
    case 0xa02908b:
    case 0xa02908c:
    case 0xa02908d:
    case 0xa02908e:
    case 0xa02908f:
    case 0xa029090:
    case 0xa029091:
    case 0xa029092:
    case 0xa029093:
    case 0xa029094:
      goto switchD_007f3560_caseD_a029002;
    case 0xa02901d:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x74) * 3.6;
      return 0;
    case 0xa02903c:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x208) * 3.6;
      return 0;
    case 0xa02903d:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x20c) * 3.6;
      return 0;
    case 0xa029066:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = (*(float *)(this + 0xc4) * 180.0) / 3.141593;
      return 0;
    case 0xa029067:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = (*(float *)(this + 200) * 180.0) / 3.141593;
      return 0;
    case 0xa029095:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x254) * 3.6;
      return 0;
    default:
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 600) * 3.6;
      return 0;
    }
  }
  if (uVar3 < 0xa0290bd) {
    if (uVar3 == 0xa0290bc) {
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x32c) * 3.6;
      return 0;
    }
    if (uVar3 == 0xa029097) {
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = (*(float *)(this + 0x290) * 180.0) / 3.141593;
      return 0;
    }
    if (uVar3 == 0xa029098) {
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = (*(float *)(this + 0x294) * 180.0) / 3.141593;
      return 0;
    }
    if (uVar3 == 0xa02909c) {
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x284) * 3.6;
      return 0;
    }
  } else if (uVar3 < 0xa0290c0) {
    if (uVar3 == 0xa0290bf) {
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x338) * 3.6;
      return 0;
    }
    if (uVar3 == 0xa0290bd) {
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x330) * 3.6;
      return 0;
    }
    if (uVar3 == 0xa0290be) {
      *(CMwValueStd **)param_2 = param_2 + 4;
      *(float *)(param_2 + 4) = *(float *)(this + 0x334) * 3.6;
      return 0;
    }
  } else if (uVar3 == 0xffffffff) {
    return 0;
  }
switchD_007f3560_caseD_a029002:
  *(int *)(param_1 + 0x18) = iVar1;
  uVar4 = CMwNod::VirtualParam_Get((CMwNod *)this, param_1, param_2);
  return uVar4;
}

/* public: virtual unsigned long __thiscall
 *CSceneVehicleCarTuning::VirtualParam_Set(class CMwStack ,void *) */

ulong __thiscall CSceneVehicleCarTuning::VirtualParam_Set(
    CSceneVehicleCarTuning *this, CMwStack *param_1, void *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  CFastBuffer<float> *pCVar4;
  ulong uVar5;

  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  uVar3 = *(uint *)(iVar2 + 4);
  if (uVar3 < 0xa029099) {
    switch (uVar3) {
    case 0xa029000:
      /* WARNING: Load size is inaccurate */
      *(float *)(this + 0x2c) = *param_2 / 3.6;
      return 0;
    case 0xa029001:
      /* WARNING: Load size is inaccurate */
      *(float *)(this + 0x30) = *param_2 / 3.6;
      return 0;
    case 0xa029002:
    case 0xa029003:
    case 0xa029004:
    case 0xa029005:
    case 0xa029006:
    case 0xa029007:
    case 0xa029008:
    case 0xa029009:
    case 0xa02900a:
    case 0xa02900b:
    case 0xa02900c:
    case 0xa02900d:
    case 0xa02900e:
    case 0xa02900f:
    case 0xa029010:
    case 0xa029011:
    case 0xa029012:
    case 0xa029013:
    case 0xa029014:
    case 0xa029015:
    case 0xa029016:
    case 0xa029017:
    case 0xa029018:
    case 0xa029019:
    case 0xa02901a:
    case 0xa02901b:
    case 0xa02901c:
    case 0xa02901e:
    case 0xa02901f:
    case 0xa029020:
    case 0xa029021:
    case 0xa029022:
    case 0xa029023:
    case 0xa029024:
    case 0xa029025:
    case 0xa029026:
    case 0xa029027:
    case 0xa029028:
    case 0xa029029:
    case 0xa02902a:
    case 0xa02902b:
    case 0xa02902c:
    case 0xa02902d:
    case 0xa02902e:
    case 0xa02902f:
    case 0xa029030:
    case 0xa029031:
    case 0xa029032:
    case 0xa029033:
    case 0xa029034:
    case 0xa029035:
    case 0xa029036:
    case 0xa029037:
    case 0xa029038:
    case 0xa029039:
    case 0xa02903a:
    case 0xa02903b:
    case 0xa02903e:
    case 0xa02903f:
    case 0xa029040:
    case 0xa029041:
    case 0xa029042:
    case 0xa029043:
    case 0xa029044:
    case 0xa029045:
    case 0xa029046:
    case 0xa029047:
    case 0xa029048:
    case 0xa029049:
    case 0xa02904a:
    case 0xa02904b:
    case 0xa02904c:
    case 0xa02904d:
    case 0xa02904e:
    case 0xa02904f:
    case 0xa029050:
    case 0xa029051:
    case 0xa029052:
    case 0xa029053:
    case 0xa029054:
    case 0xa029055:
    case 0xa029056:
    case 0xa029057:
    case 0xa029058:
    case 0xa029059:
    case 0xa02905a:
    case 0xa02905b:
    case 0xa02905c:
    case 0xa02905d:
    case 0xa02905e:
    case 0xa02905f:
    case 0xa029060:
    case 0xa029061:
    case 0xa029062:
    case 0xa029063:
    case 0xa029064:
    case 0xa029065:
    case 0xa029068:
    case 0xa029069:
    case 0xa02906a:
    case 0xa02906b:
    case 0xa02906c:
    case 0xa02906d:
    case 0xa02906e:
    case 0xa02906f:
    case 0xa029070:
    case 0xa029071:
    case 0xa029072:
    case 0xa029073:
    case 0xa029074:
    case 0xa029075:
    case 0xa029076:
    case 0xa029077:
    case 0xa029078:
    case 0xa029079:
    case 0xa02907a:
    case 0xa02907b:
    case 0xa02907c:
    case 0xa02907d:
    case 0xa02907e:
    case 0xa02907f:
    case 0xa029080:
    case 0xa029081:
    case 0xa029082:
    case 0xa029083:
    case 0xa029084:
    case 0xa029085:
    case 0xa029086:
    case 0xa029087:
    case 0xa029088:
    case 0xa029089:
    case 0xa02908a:
    case 0xa02908b:
    case 0xa02908c:
    case 0xa02908d:
    case 0xa02908e:
    case 0xa02908f:
    case 0xa029090:
    case 0xa029091:
    case 0xa029092:
    case 0xa029093:
    case 0xa029094:
      goto switchD_007f5b52_caseD_a029002;
    case 0xa02901d:
      /* WARNING: Load size is inaccurate */
      *(float *)(this + 0x74) = *param_2 / 3.6;
      return 0;
    case 0xa02903c:
      /* WARNING: Load size is inaccurate */
      *(float *)(this + 0x208) = *param_2 / 3.6;
      return 0;
    case 0xa02903d:
      /* WARNING: Load size is inaccurate */
      *(float *)(this + 0x20c) = *param_2 / 3.6;
      return 0;
    case 0xa029066:
      /* WARNING: Load size is inaccurate */
      *(float *)(this + 0xc4) = (*param_2 * 3.141593) / 180.0;
      return 0;
    case 0xa029067:
      /* WARNING: Load size is inaccurate */
      *(float *)(this + 200) = (*param_2 * 3.141593) / 180.0;
      return 0;
    case 0xa029095:
      /* WARNING: Load size is inaccurate */
      *(float *)(this + 0x254) = *param_2 / 3.6;
      return 0;
    case 0xa029096:
      /* WARNING: Load size is inaccurate */
      *(float *)(this + 600) = *param_2 / 3.6;
      return 0;
    case 0xa029097:
      /* WARNING: Load size is inaccurate */
      *(float *)(this + 0x290) = (*param_2 * 3.141593) / 180.0;
      return 0;
    default:
      /* WARNING: Load size is inaccurate */
      *(float *)(this + 0x294) = (*param_2 * 3.141593) / 180.0;
      return 0;
    }
  }
  if (uVar3 < 0xa0290bd) {
    switch (uVar3) {
    case 0xa02909c:
      /* WARNING: Load size is inaccurate */
      *(float *)(this + 0x284) = *param_2 / 3.6;
      return 0;
    case 0xa02909d:
    case 0xa02909e:
    case 0xa02909f:
    case 0xa0290a0:
    case 0xa0290a1:
    case 0xa0290a2:
    case 0xa0290a3:
    case 0xa0290a4:
    case 0xa0290a5:
    case 0xa0290a6:
    case 0xa0290a7:
    case 0xa0290a8:
    case 0xa0290a9:
    case 0xa0290aa:
    case 0xa0290ab:
    case 0xa0290ac:
    case 0xa0290ad:
    case 0xa0290ae:
    case 0xa0290af:
    case 0xa0290b0:
      goto switchD_007f5b52_caseD_a029002;
    case 0xa0290b1:
      pCVar4 = (CFastBuffer<float> *)(this + 0x2d4);
      break;
    case 0xa0290b2:
      pCVar4 = (CFastBuffer<float> *)(this + 0x2e0);
      break;
    case 0xa0290b3:
      pCVar4 = (CFastBuffer<float> *)(this + 0x2c4);
      break;
    case 0xa0290b4:
      CMwParamFastBuffer<>::SetValue((CFastBuffer<float> *)(this + 0x2f8),
                                     param_1, param_2);
      M6CheckRpmWantedConstistensy(this);
      M6InitRpmDelta(this);
      return 0;
    default:
      /* WARNING: Load size is inaccurate */
      *(float *)(this + 0x32c) = *param_2 / 3.6;
      return 0;
    }
    CMwParamFastBuffer<>::SetValue(pCVar4, param_1, param_2);
    M6InitRpmDelta(this);
    return 0;
  }
  if (uVar3 < 0xa0290c0) {
    if (uVar3 == 0xa0290bf) {
      /* WARNING: Load size is inaccurate */
      *(float *)(this + 0x338) = *param_2 / 3.6;
      return 0;
    }
    if (uVar3 == 0xa0290bd) {
      /* WARNING: Load size is inaccurate */
      *(float *)(this + 0x330) = *param_2 / 3.6;
      return 0;
    }
    if (uVar3 == 0xa0290be) {
      /* WARNING: Load size is inaccurate */
      *(float *)(this + 0x334) = *param_2 / 3.6;
      return 0;
    }
  } else if (uVar3 == 0xffffffff) {
    return 0;
  }
switchD_007f5b52_caseD_a029002:
  *(int *)(param_1 + 0x18) = iVar1;
  uVar5 = CMwNod::VirtualParam_Set((CMwNod *)this, param_1, param_2);
  return uVar5;
}

/* public: virtual __thiscall
 * CSceneVehicleCarTuning::~CSceneVehicleCarTuning(void) */

void __thiscall CSceneVehicleCarTuning::~CSceneVehicleCarTuning(
    CSceneVehicleCarTuning *this)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  puStack_8 = &LAB_00acfd91;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 0x1f;
  if (*(CMwNod **)(this + 0x380) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x380));
  }
  local_4._0_1_ = 0x1e;
  if (*(CMwNod **)(this + 0x378) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x378));
  }
  local_4._0_1_ = 0x1d;
  if (*(CMwNod **)(this + 0x36c) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x36c));
  }
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x310));
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x304));
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x2f8));
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x2e0));
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x2d4));
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x2c4));
  local_4._0_1_ = 0x16;
  if (*(CMwNod **)(this + 0x2a4) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x2a4));
  }
  local_4._0_1_ = 0x15;
  if (*(CMwNod **)(this + 0x288) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x288));
  }
  local_4._0_1_ = 0x14;
  if (*(CMwNod **)(this + 0x260) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x260));
  }
  local_4._0_1_ = 0x13;
  if (*(CMwNod **)(this + 0x25c) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x25c));
  }
  local_4._0_1_ = 0x12;
  if (*(CMwNod **)(this + 0x250) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x250));
  }
  local_4._0_1_ = 0x11;
  if (*(CMwNod **)(this + 0x230) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x230));
  }
  local_4._0_1_ = 0x10;
  if (*(CMwNod **)(this + 0x224) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x224));
  }
  local_4._0_1_ = 0xf;
  if (*(CMwNod **)(this + 0x218) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x218));
  }
  local_4._0_1_ = 0xe;
  if (*(CMwNod **)(this + 0x214) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x214));
  }
  local_4._0_1_ = 0xd;
  if (*(CMwNod **)(this + 0x210) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x210));
  }
  local_4._0_1_ = 0xc;
  if (*(CMwNod **)(this + 0x1f0) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x1f0));
  }
  local_4._0_1_ = 0xb;
  if (*(CMwNod **)(this + 0x1ec) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x1ec));
  }
  local_4._0_1_ = 10;
  if (*(CMwNod **)(this + 0x1e0) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x1e0));
  }
  local_4._0_1_ = 9;
  if (*(CMwNod **)(this + 0x1c4) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x1c4));
  }
  local_4._0_1_ = 8;
  if (*(CMwNod **)(this + 0x1bc) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x1bc));
  }
  local_4._0_1_ = 7;
  if (*(CMwNod **)(this + 0x1b4) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x1b4));
  }
  local_4._0_1_ = 6;
  if (*(CMwNod **)(this + 0xbc) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0xbc));
  }
  local_4._0_1_ = 5;
  if (*(CMwNod **)(this + 0xb8) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0xb8));
  }
  local_4._0_1_ = 4;
  if (*(CMwNod **)(this + 0xac) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0xac));
  }
  local_4._0_1_ = 3;
  if (*(CMwNod **)(this + 0xa0) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0xa0));
  }
  local_4._0_1_ = 2;
  if (*(CMwNod **)(this + 0x78) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x78));
  }
  local_4._0_1_ = 1;
  if (*(CMwNod **)(this + 0x68) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x68));
  }
  local_4 = (uint)local_4._1_3_ << 8;
  if (*(CMwNod **)(this + 0x34) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x34));
  }
  local_4 = 0xffffffff;
  CSceneVehicleTuning::~CSceneVehicleTuning((CSceneVehicleTuning *)this);
  ExceptionList = local_c;
  return;
}
