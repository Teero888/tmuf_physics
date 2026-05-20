#ifndef CDX9STATEBLOCK_HPP
#define CDX9STATEBLOCK_HPP

#include "typedefs.h"

struct CDx9StateBlock {
    byte _padding_0x0[4];
    int * field_0x4; // accesses: 1
    byte _padding_0x8[4];
    int field_0xc; // accesses: 2

    // Member Functions
    float __cdecl LockRenderStateReal(_D3DRENDERSTATETYPE param_1,float param_2);
    int __cdecl PackRenderState(_D3DRENDERSTATETYPE param_1,ulong param_2,SPackedDesc *param_3);
    int __cdecl PackSamplerState (ulong param_1,_D3DSAMPLERSTATETYPE param_2,ulong param_3,SPackedDesc *param_4);
    int __cdecl PackTexStage (ulong param_1,_D3DTEXTURESTAGESTATETYPE param_2,ulong param_3,SPackedDesc *param_4);
    ulong __cdecl LockRenderState(_D3DRENDERSTATETYPE param_1,ulong param_2);
    void __cdecl FilterRenderState(_D3DRENDERSTATETYPE param_1,ulong param_2);
    void __cdecl FilterSamplerState(ulong param_1,_D3DSAMPLERSTATETYPE param_2,ulong param_3);
    void __cdecl FilterSetStreamSource (ulong param_1,IDirect3DVertexBuffer9 *param_2,ulong param_3,ulong param_4);
    void __cdecl FilterTexStageState(ulong param_1,_D3DTEXTURESTAGESTATETYPE param_2,ulong param_3);
    void __cdecl ResetCache(void);
    void __cdecl UnlockRenderState(_D3DRENDERSTATETYPE param_1,ulong param_2);
    void __thiscall Apply(void *this,CDx9StateBlock *param_1);
    void __thiscall RecordSetSamplerFilter (void *this,CDx9StateBlock *param_1,ulong param_2,EGxTexFilter param_3,int param_4);
    void __thiscall RecordSetSamplerState (void *this,CDx9StateBlock *param_1,ulong param_2,_D3DSAMPLERSTATETYPE param_3, ulong param_4);
    void __thiscall RecordSetTexture (void *this,CDx9StateBlock *param_1,ulong param_2,CPlugBitmap *param_3);
};

#endif // CDX9STATEBLOCK_HPP
