// Class implementation: SSysGraphicAdapter

// =================================================
// Function: SSysGraphicAdapter::CaptureInfoGpu
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
SSysGraphicAdapter::CaptureInfoGpu(void *this,SSysGraphicAdapter *param_1,ulong param_2)
{
{
  char cVar1;
  HMODULE hModule;
  FARPROC pFVar2;
  WCHAR *lpCaption;
  int iVar3;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar4;
  SCasterCat *pSVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  undefined4 unaff_EBX;
  CFastBuffer<struct_CInputDevice::SRumble> *pCVar9;
  TiXmlAttribute *unaff_ESI;
  undefined4 unaff_EDI;
  SSysGraphicAdapter *pSVar10;
  SSysGraphicAdapter *pSVar11;
  WCHAR *pWVar12;
  SRumble *pSVar13;
  SSysGraphicAdapter *pSVar14;
  _D3DMULTISAMPLE_TYPE _Var15;
  WCHAR *pWVar16;
  SSysGraphicAdapter *pSStack_5fc;
  char *pcStack_5f8;
  LPCWSTR apWStack_5f4 [2];
  SSysGraphicAdapter *pSStack_5ec;
  undefined1 *puStack_5e8;
  LPCWSTR pWStack_5e4;
  wchar_t *pwVar17;
  UINT uType;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_5c4;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCStack_5c0;
  ulong local_5bc;
  int iStack_5b4;
  undefined1 auStack_5b0 [20];
  WCHAR aWStack_59c [4];
  uint uStack_594;
  HMODULE local_590;
  uint uStack_58c;
  ulong local_584 [4];
  uint uStack_574;
  uint uStack_544;
  ushort uStack_4ec;
  ushort uStack_4e4;
  char acStack_284 [544];
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  uint local_4;
  
  local_4 = DAT_00cca150 ^ (uint)&pCStack_5c4;
  if (DAT_00d54244 != 0) {
    *(undefined4 *)((int)this + 0x2c) = 0x280;
    *(undefined4 *)((int)this + 0x30) = 0x1e0;
    CFastBuffer<class_GmNat2>::Add
              ((void *)((int)this + 0x3c),(TiXmlAttributeSet *)((int)this + 0x2c),unaff_ESI);
    return;
  }
  local_5bc = ComputeVideoMemorySize_WithoutCurrentFB(local_584);
  hModule = LoadLibraryA("d3d9.dll");
  if (hModule != (HMODULE)0x0) {
    local_590 = hModule;
    pFVar2 = GetProcAddress(hModule,"Direct3DCreate9");
    uType = 0x20;
    pwVar17 = 
    L"\xf88bﾅ㑵h댬뤀ᴐ×껨䱪圀桐⯐³Ⴙ휝\xe800檝L坐ᗿ葔²ｓ퀕늀\xe900р";
    lpCaption = (WCHAR *)(*pFVar2)();
    if (lpCaption == (WCHAR *)0x0) {
      pwVar17 = CClassicI18n::GetTranslatedStringInternal
                          ((CClassicI18n *)&DAT_00d71d10,(CClassicI18n *)L"Error",pwVar17);
      pWStack_5e4 = L"坐ᗿ葔²ｓ퀕늀\xe900р";
      pwVar17 = CClassicI18n::GetTranslatedStringInternal
                          ((CClassicI18n *)&DAT_00d71d10,(CClassicI18n *)L"Could not find DirectX9",
                           pwVar17);
      pWStack_5e4 = L"ｓ퀕늀\xe900р";
      MessageBoxW((HWND)0x0,pwVar17,lpCaption,uType);
      FreeLibrary(hModule);
    }
    else {
      iVar3 = (**(code **)(*(int *)lpCaption + 0x10))();
      if (iVar3 != 0) {
        puStack_5e8 = (undefined1 *)0x43ba02;
        pWStack_5e4 = lpCaption;
        (**(code **)(*(int *)lpCaption + 0x14))();
        puStack_5e8 = auStack_5b0;
        pSStack_5ec = param_1;
        apWStack_5f4[0] = (LPCWSTR)0x43ba10;
        apWStack_5f4[1] = lpCaption;
        (**(code **)(*(int *)lpCaption + 0x20))();
        apWStack_5f4[0] = aWStack_59c;
        pcStack_5f8 = (undefined1 *)0x1;
        pSStack_5fc = param_1;
        pWVar16 = lpCaption;
        (**(code **)(*(int *)lpCaption + 0x38))();
        _Var15 = 0x16;
        pWVar12 = lpCaption;
        pSVar10 = param_1;
        pCVar4 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)
                 (**(code **)(*(int *)lpCaption + 0x18))();
        pCStack_5c0 = pCVar4;
        CFastBuffer<struct_SBindingToSort>::SetSizeAtLeast
                  ((void *)((int)this + 0x3c),pCVar4,(ulong)pWVar12);
        pSStack_5ec = (SSysGraphicAdapter *)0x0;
        if (pCVar4 != (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)0x0) {
          do {
            pSVar11 = pSStack_5ec;
            (**(code **)(*(int *)lpCaption + 0x1c))(lpCaption,param_1,0x16,pSStack_5ec,&puStack_5e8)
            ;
            pcStack_5f8 = puStack_5e8;
            apWStack_5f4[0] = pWStack_5e4;
            if (((undefined1 *)0x27f < puStack_5e8) && ((WCHAR *)0x1df < pWStack_5e4)) {
              pSVar13 = (SRumble *)0x43ba88;
              local_5bc = CFastBuffer<class_CCrystalFace*>::GetCount
                                    ((void *)((int)this + 0x3c),
                                     (CFastBuffer<class_CCrystalFace*> *)pSVar10);
              pCVar9 = (CFastBuffer<struct_CInputDevice::SRumble> *)0x0;
              if (local_5bc != 0) {
                do {
                  pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                                     ((void *)((int)this + 0x3c),
                                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar9,
                                      (ulong)pSVar11);
                  if (pSStack_5ec < *(uint *)pSVar5) break;
                  pCVar9 = pCVar9 + 1;
                } while (pCVar9 < pCStack_5c4);
                if (((pCVar9 != (CFastBuffer<struct_CInputDevice::SRumble> *)0x0) &&
                    (pSVar5 = CFastBuffer<struct_SFastCat>::operator[]
                                        ((void *)((int)this + 0x3c),
                                         (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                         (pCVar9 + -1),(ulong)pSVar13),
                    *(undefined1 **)pSVar5 == puStack_5e8)) &&
                   (*(WCHAR **)(pSVar5 + 4) == pWStack_5e4)) goto LAB_0043badb;
              }
              CFastBuffer<class_GmNat2>::InsertElemAt
                        ((void *)((int)this + 0x3c),pCVar9,(ulong)&pSStack_5fc,pSVar13);
            }
LAB_0043badb:
            pSStack_5ec = (SSysGraphicAdapter *)((int)pSStack_5ec + 1);
          } while (pSStack_5ec < local_5bc);
        }
        *(undefined4 *)((int)this + 4) = uStack_58;
        pcStack_5f8 = acStack_284;
        *(undefined4 *)this = uStack_5c;
        *(undefined4 *)((int)this + 8) = uStack_64;
        *(undefined4 *)((int)this + 0xc) = uStack_60;
        pcVar6 = pcStack_5f8;
        do {
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        apWStack_5f4[0] = (LPCWSTR)(pcVar6 + -(int)(acStack_284 + 1));
        CFastString::SetString
                  ((CFastString *)((int)this + 0x1c),(CFastStringInt *)&pcStack_5f8,
                   (SStringParam *)pSVar10);
        if ((uStack_58c & 0x20000) == 0) {
          uVar7 = 0;
        }
        else {
          uVar7 = 0x1f;
          if (uStack_544 != 0) {
            for (; uStack_544 >> uVar7 == 0; uVar7 = uVar7 - 1) {
            }
          }
        }
        if (7 < uVar7) {
          uVar7 = 7;
        }
        *(byte *)((int)this + 0x35) =
             *(byte *)((int)this + 0x35) ^
             ((char)uVar7 * '\x04' ^ *(byte *)((int)this + 0x35)) & 0x1c;
        pSVar10 = param_1;
        iVar3 = CheckAntiAlias((IDirect3D9 *)param_1,_Var15,(_D3DMULTISAMPLE_TYPE)pWVar16);
        *(byte *)((int)this + 0x35) =
             *(byte *)((int)this + 0x35) ^ ((char)iVar3 << 5 ^ *(byte *)((int)this + 0x35)) & 0x20;
        pSVar14 = param_1;
        iVar3 = CheckAntiAlias((IDirect3D9 *)param_1,(ulong)pSVar10,_Var15);
        *(byte *)((int)this + 0x35) =
             *(byte *)((int)this + 0x35) ^ ((char)iVar3 << 6 ^ *(byte *)((int)this + 0x35)) & 0x40;
        pSVar11 = param_1;
        iVar3 = CheckAntiAlias((IDirect3D9 *)param_1,(ulong)pSVar14,(_D3DMULTISAMPLE_TYPE)pSVar10);
        *(byte *)((int)this + 0x35) = (char)iVar3 << 7 | *(byte *)((int)this + 0x35) & 0x7f;
        pSVar10 = param_1;
        iVar3 = CheckAntiAlias((IDirect3D9 *)param_1,(ulong)pSVar11,(_D3DMULTISAMPLE_TYPE)pSVar14);
        *(byte *)((int)this + 0x36) =
             *(byte *)((int)this + 0x36) ^ (*(byte *)((int)this + 0x36) ^ (byte)iVar3) & 1;
        iVar3 = CheckAntiAlias((IDirect3D9 *)param_1,(ulong)pSVar10,(_D3DMULTISAMPLE_TYPE)pSVar11);
        *(byte *)((int)this + 0x36) =
             *(byte *)((int)this + 0x36) ^ ((char)iVar3 * '\x02' ^ *(byte *)((int)this + 0x36)) & 2;
        apWStack_5f4[0] = (LPCWSTR)0x70;
        apWStack_5f4[1] = (LPCWSTR)0x71;
        uVar7 = 0;
        do {
          iVar3 = (**(code **)(*(int *)lpCaption + 0x28))
                            (lpCaption,param_1,1,pCStack_5c4,1,3,apWStack_5f4[uVar7]);
          if (iVar3 < 0) break;
          uVar7 = uVar7 + 1;
        } while (uVar7 < 2);
        uVar8 = ~(uStack_574 >> 10) & 1;
        if (((uStack_594 & 0x10000) == 0) && (uStack_4e4 < 0x101)) {
          uVar8 = 1;
        }
        *(ushort *)((int)this + 0x18) = uStack_4ec;
        if (uVar8 == 0) {
          if ((uStack_4e4 < 0x101) || (((uint)local_590 & 0x800) == 0)) {
            *(undefined2 *)((int)this + 0x10) = 1;
            *(undefined2 *)((int)this + 0x12) = 0;
          }
          else if (((uStack_4e4 < 0x200) || (uStack_4ec < 0x200)) || (uVar7 != 2)) {
            *(undefined2 *)((int)this + 0x10) = 2;
            if (uStack_4e4 < 0x200) {
              *(ushort *)((int)this + 0x12) = uStack_4e4 & 0xff;
            }
            else {
              *(undefined2 *)((int)this + 0x12) = 0xffff;
            }
          }
          else {
            *(undefined2 *)((int)this + 0x10) = 3;
            *(ushort *)((int)this + 0x12) = uStack_4e4 - 0x200;
          }
        }
        else {
          *(undefined2 *)((int)this + 0x10) = 0;
          *(undefined2 *)((int)this + 0x12) = 0;
        }
        *(undefined4 *)((int)this + 0x2c) = unaff_EDI;
        *(undefined4 *)((int)this + 0x30) = unaff_EBX;
        switch(pCStack_5c4) {
        case (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x14:
          *(undefined1 *)((int)this + 0x34) = 3;
          break;
        default:
          *(undefined1 *)((int)this + 0x34) = 4;
          break;
        case (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x17:
        case (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x18:
        case (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x19:
          *(undefined1 *)((int)this + 0x34) = 2;
        }
        uVar7 = (int)pSStack_5ec +
                (uint)*(byte *)((int)this + 0x34) * *(int *)((int)this + 0x30) *
                *(int *)((int)this + 0x2c);
        if (((*(int *)this == 0x1002) && (0x1ff < uStack_4e4)) && (uVar7 < 0x6400000)) {
          pSStack_5ec = (SSysGraphicAdapter *)0x8000000;
          uVar7 = 0x8000000;
        }
        *(ushort *)((int)this + 0x14) = (ushort)(uVar7 + 0xfffff >> 0x14);
        *(ushort *)((int)this + 0x16) = (ushort)((uint)(iStack_5b4 + 0xfffff) >> 0x14);
        pWStack_5e4 = (LPCWSTR)0x31545844;
        uVar7 = 0;
        do {
          iVar3 = (**(code **)(*(int *)lpCaption + 0x28))
                            (lpCaption,param_1,1,pCStack_5c4,0,3,(&pWStack_5e4)[uVar7]);
          if (iVar3 < 0) break;
          uVar7 = uVar7 + 1;
        } while (uVar7 < 5);
        *(byte *)((int)this + 0x35) =
             *(byte *)((int)this + 0x35) ^ (uVar7 == 5 ^ *(byte *)((int)this + 0x35)) & 1;
        if ((*(int *)this == 0x10de) && (1 < *(ushort *)((int)this + 0x10))) {
          iVar3 = (**(code **)(*(int *)lpCaption + 0x28))(lpCaption,param_1,1,pCStack_5c4,2,3,0x50);
          *(byte *)((int)this + 0x35) =
               *(byte *)((int)this + 0x35) ^
               ((-1 < iVar3) * '\x02' ^ *(byte *)((int)this + 0x35)) & 2;
        }
        else {
          *(byte *)((int)this + 0x35) = *(byte *)((int)this + 0x35) & 0xfd;
        }
        (**(code **)(*(int *)lpCaption + 8))(lpCaption);
        FreeLibrary(local_590);
      }
    }
  }
  return;
}
}

// =================================================
// Function: SSysGraphicAdapter::IsDriverRecentOrEqual
// =================================================
int __thiscall
SSysGraphicAdapter::IsDriverRecentOrEqual
          (void *this,SSysGraphicAdapter *param_1,ushort param_2,ushort param_3,ushort param_4,
          ushort param_5)
{
{
  if (CONCAT22(param_1._0_2_,param_2) < *(uint *)((int)this + 0xc)) {
    return 1;
  }
  if (*(uint *)((int)this + 0xc) < CONCAT22(param_1._0_2_,param_2)) {
    return 0;
  }
  return (uint)(CONCAT22(param_3,param_4) <= *(uint *)((int)this + 8));
}
}

