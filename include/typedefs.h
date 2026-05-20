#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <cstdint>
#include <cstddef>

// Calling conventions
#define __cdecl
#define __thiscall
#define __stdcall
#define __fastcall

// Basic types
typedef uint8_t  byte;
typedef uint16_t word;
typedef uint32_t dword;
typedef uint64_t qword;
typedef uint8_t  uchar;
typedef uint32_t uint;
typedef uint16_t ushort;
typedef uint32_t ulong;
typedef int64_t  longlong;
typedef uint64_t ulonglong;

// Ghidra undefined types
typedef uint8_t  undefined;
typedef uint8_t  undefined1;
typedef uint16_t undefined2;
typedef uint32_t undefined4;
typedef uint64_t undefined8;
typedef void     code;
typedef double   float10;

// Nadeo specific base types
typedef uint32_t TimeInt32;

// Enums (defined as uint for compatibility)
typedef uint EAccountType;
typedef uint EAlignHorizontal;
typedef uint EAlignVertical;
typedef uint EArchive;
typedef uint EAvatarVariant;
typedef uint EBalanceGroup;
typedef uint EBillState;
typedef uint EBlockType;
typedef uint ECallback;
typedef uint ECardinalDir;
typedef uint EChallengeCutScene;
typedef uint EChallengeType;
typedef uint ECipherOpMode;
typedef uint ECollisionGroup;
typedef uint EContactInterest;
typedef uint EConvertMethod;
typedef uint ECpuExt;
typedef uint ECubeFace;
typedef uint EDayTime4;
typedef uint EDbgLight;
typedef uint EDecorationMusic;
typedef uint EDirectory;
typedef uint EDoMobilPtrVersion;
typedef uint EDx9Vendor;
typedef uint EDynamicType;
typedef uint EEffectMode;
typedef uint EErrorCode;
typedef uint EEvent;
typedef uint EFidType;
typedef uint EFindWay;
typedef uint EForceOpen;
typedef uint EGmSurfType;
typedef uint EGxAlphaCmp;
typedef uint EGxBlendFactor;
typedef uint EGxBlendOp;
typedef uint EGxTexAddress;
typedef uint EGxTexArg;
typedef uint EGxTexFilter;
typedef uint EGxTexOp;
typedef uint EH_epilog3;
typedef uint EHmsCorpusCat;
typedef uint EInOut;
typedef uint EInterfaceMusic;
typedef uint EInterfaceSound;
typedef uint EKindOS;
typedef uint ELightUpdate;
typedef uint ELoadGfxPerfResult;
typedef uint ELoadId;
typedef uint EMakeDir;
typedef uint EMaterialMode;
typedef uint EMessageType;
typedef uint EMobilStateQuality;
typedef uint EMode;
typedef uint EMwIconList;
typedef uint EMwSchemeTimedPatterns;
typedef uint ENormalFormat;
typedef uint EParam;
typedef uint EParamType;
typedef uint EPixelUpdate;
typedef uint EPlayerInfoArchiveState;
typedef uint EPlayerType;
typedef uint EPlugGpuPipeline;
typedef uint EPlugShaderVertexColor;
typedef uint EPlugVDcl;
typedef uint EPlugVDclType;
typedef uint EPlugVideoTimer;
typedef uint EPredictionType;
typedef uint EPreset;
typedef uint EProtocol;
typedef uint ERaceState;
typedef uint ERadius;
typedef uint EReadFileRes;
typedef uint ERealInterp;
typedef uint EReload;
typedef uint ERenderMode;
typedef uint EReplayGhostVersion;
typedef uint ERetCode;
typedef uint ERROR;
typedef uint ESailType;
typedef uint ESceneLight;
typedef uint ESceneLightUpdate;
typedef uint ESceneMobilQuality;
typedef uint ESceneVehicleParticleQuality;
typedef uint EShadowCaster;
typedef uint ESpectatorCameraTarget;
typedef uint ESpectatorCameraType;
typedef uint ESpriteColor0;
typedef uint EStack_54;
typedef uint EStackType;
typedef uint EState;
typedef uint EStatus;
typedef uint EStdGpuV;
typedef uint EStdShader2;
typedef uint ESurface;
typedef uint ETextMode;
typedef uint ETmValidateResult;
typedef uint ETurboType;
typedef uint EUpdate;
typedef uint EVar1;
typedef uint EVar10;
typedef uint EVar11;
typedef uint EVar13;
typedef uint EVar15;
typedef uint EVar16;
typedef uint EVar2;
typedef uint EVar21;
typedef uint EVar23;
typedef uint EVar27;
typedef uint EVar28;
typedef uint EVar29;
typedef uint EVar3;
typedef uint EVar31;
typedef uint EVar32;
typedef uint EVar37;
typedef uint EVar4;
typedef uint EVar5;
typedef uint EVar6;
typedef uint EVar7;
typedef uint EVar8;
typedef uint EVar9;
typedef uint EVehicleEvent;
typedef uint EVersion;
typedef uint EVolatileTreeType;
typedef uint EXCEPTION_RECORD;
typedef uint EXmlParamAction;

// Missing Classes/Structs

// Common Nadeo Templates (opaque for now)
template<typename T> struct CFastBuffer { uint count; T* data; };
template<typename T> struct CFastArray { uint count; uint capacity; T* data; };
template<typename T, int N, typename S> struct CFixedArray { T data[N]; };

#endif // TYPEDEFS_H
