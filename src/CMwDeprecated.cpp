// Class implementation: CMwDeprecated

// =================================================
// Function: CMwDeprecated::Chunk
// =================================================
void __thiscall
CMwDeprecated::Chunk(void *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3)
{
{
  CFuncSegment *this_00;
  ulong unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  int iVar1;
  undefined4 in_stack_00000010;
  undefined4 uStack00000018;
  int in_stack_fffffff8;
  CClassicArchive local_4 [4];
  
  this_00 = param_1;
  if (param_2 == (CClassicArchive *)0x9063000) {
    CClassicArchive::DoNat8((CClassicArchive *)param_1,local_4,&DAT_00000004,1,unaff_EDI);
    CClassicArchive::DoNatural((CClassicArchive *)this_00,local_4,(ulong *)0x1,0,unaff_ESI);
    iVar1 = 5;
    do {
      in_stack_00000010 = 0;
      (**(code **)(*(int *)this_00 + 4))(&stack0x00000010);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    return;
  }
  if (param_2 == (CClassicArchive *)0x9063001) {
    CClassicArchive::DoNat8
              ((CClassicArchive *)param_1,(CClassicArchive *)&stack0xfffffff8,&DAT_00000004,1,
               unaff_EDI);
    CClassicArchive::DoNatural
              ((CClassicArchive *)this_00,(CClassicArchive *)&stack0x00000000,(ulong *)0x1,0,
               unaff_ESI);
    iVar1 = 5;
    do {
      in_stack_00000010 = 0;
      (**(code **)(*(int *)this_00 + 4))(&stack0x00000010);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  else if (param_2 != (CClassicArchive *)0x9063002) {
    return;
  }
  CClassicArchive::DoData
            ((CClassicArchive *)this_00,(CNetNod_CheckedArchive *)&param_1,&DAT_00000004,unaff_EBX);
  CClassicArchive::DoNatural
            ((CClassicArchive *)this_00,(CClassicArchive *)&param_1,(ulong *)0x1,0,in_stack_fffffff8
            );
  iVar1 = 5;
  do {
    uStack00000018 = 0;
    (**(code **)(*(int *)this_00 + 4))();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}
}

// =================================================
// Function: CMwDeprecated::WrapClassId
// =================================================
ulong __cdecl CMwDeprecated::WrapClassId(ulong param_1)
{
{
  if (param_1 < 0x24069001) {
    if (param_1 == 0x24069000) {
      return 0x307c000;
    }
    if (param_1 < 0x2402c001) {
      if (param_1 == 0x2402c000) {
        return 0x305f000;
      }
      if (param_1 < 0x24019001) {
        if (param_1 == 0x24019000) {
          return 0x30ce000;
        }
        if (param_1 < 0x24009001) {
          if (param_1 == 0x24009000) {
            return 51200000;
          }
          if (param_1 < 0x24004001) {
            if (param_1 == 0x24004000) {
              return 0x3033000;
            }
            if (param_1 < 0x9063001) {
              if (param_1 == 0x9063000) {
                return 0x9026000;
              }
              if (param_1 == 0x307b000) {
                return 0x3078000;
              }
              if (param_1 == 0x900d000) {
                return 0x900f000;
              }
            }
            else if (param_1 == 0x24003000) {
              return 0x3043000;
            }
          }
          else if (param_1 < 0x24007001) {
            if (param_1 == 0x24007000) {
              return 0x3057000;
            }
            if (param_1 == 0x24005000) {
              return 0x304e000;
            }
            if (param_1 == 0x24006000) {
              return 0x3036000;
            }
          }
          else if (param_1 == 0x24008000) {
            return 0x3058000;
          }
        }
        else if (param_1 < 0x2400e001) {
          if (param_1 == 0x2400e000) {
            return 0x301d000;
          }
          if (param_1 < 0x2400c001) {
            if (param_1 == 0x2400c000) {
              return 0x305b000;
            }
            if (param_1 == 0x2400a000) {
              return 0x301a000;
            }
            if (param_1 == 0x2400b000) {
              return 0x3044000;
            }
          }
          else if (param_1 == 0x2400d000) {
            return 0x301f000;
          }
        }
        else {
          if (param_1 == 0x2400f000) {
            return 0x301e000;
          }
          if (param_1 == 0x24011000) {
            return 0x305a000;
          }
          if (param_1 == 0x24012000) {
            return 0x30d1000;
          }
        }
      }
      else if (param_1 < 0x24022001) {
        if (param_1 == 0x24022000) {
          return 0x3051000;
        }
        if (param_1 < 0x2401e001) {
          if (param_1 == 0x2401e000) {
            return 0x305e000;
          }
          if (param_1 < 0x2401c001) {
            if (param_1 == 0x2401c000) {
              return 0x305c000;
            }
            if (param_1 == 0x2401a000) {
              return 0x3039000;
            }
            if (param_1 == 0x2401b000) {
              return 0x3092000;
            }
          }
          else if (param_1 == 0x2401d000) {
            return 0x305d000;
          }
        }
        else {
          if (param_1 == 0x2401f000) {
            return 0x3038000;
          }
          if (param_1 == 0x24020000) {
            return 0x304f000;
          }
          if (param_1 == 0x24021000) {
            return 0x3050000;
          }
        }
      }
      else if (param_1 < 0x24028001) {
        if (param_1 == 0x24028000) {
          return 0x30cb000;
        }
        if (param_1 < 0x24025001) {
          if (param_1 == 0x24025000) {
            return 0x3054000;
          }
          if (param_1 == 0x24023000) {
            return 0x3052000;
          }
          if (param_1 == 0x24024000) {
            return 0x3053000;
          }
        }
        else if (param_1 == 0x24027000) {
          return 0x302d000;
        }
      }
      else {
        if (param_1 == 0x24029000) {
          return 0x3055000;
        }
        if (param_1 == 0x2402a000) {
          return 0x30bb000;
        }
        if (param_1 == 0x2402b000) {
          return 0x30d2000;
        }
      }
    }
    else if (param_1 < 0x2404f001) {
      if (param_1 == 0x2404f000) {
        return 0x3073000;
      }
      if (param_1 < 0x2403f001) {
        if (param_1 == 0x2403f000) {
          return 0x3093000;
        }
        if (param_1 < 0x24039001) {
          if (param_1 == 0x24039000) {
            return 0x308f000;
          }
          if (param_1 < 0x24034001) {
            if (param_1 == 0x24034000) {
              return 0x308d000;
            }
            if (param_1 == 0x2402d000) {
              return 0x307e000;
            }
            if (param_1 == 0x24033000) {
              return 0x30d3000;
            }
          }
          else if (param_1 == 0x24038000) {
            return 0x3090000;
          }
        }
        else if (param_1 < 0x2403c001) {
          if (param_1 == 0x2403c000) {
            return 0x301b000;
          }
          if (param_1 == 0x2403a000) {
            return 0x3059000;
          }
          if (param_1 == 0x2403b000) {
            return 0x30cc000;
          }
        }
        else if (param_1 == 0x2403e000) {
          return 0x301c000;
        }
      }
      else if (param_1 < 0x24049001) {
        if (param_1 == 0x24049000) {
          return 0x30e0000;
        }
        if (param_1 < 0x24047001) {
          if (param_1 == 0x24047000) {
            return 0x3047000;
          }
          if (param_1 == 0x24040000) {
            return 0x303b000;
          }
          if (param_1 == 0x24046000) {
            return 0x3035000;
          }
        }
        else if (param_1 == 0x24048000) {
          return 0x30af000;
        }
      }
      else {
        if (param_1 == 0x2404a000) {
          return 0x308c000;
        }
        if (param_1 == 0x2404d000) {
          return 0x308a000;
        }
        if (param_1 == 0x2404e000) {
          return 0x3002000;
        }
      }
    }
    else if (param_1 < 0x2405f001) {
      if (param_1 == 0x2405f000) {
        return 0x3081000;
      }
      if (param_1 < 0x24059001) {
        if (param_1 == 0x24059000) {
          return 0x30b8000;
        }
        if (param_1 < 0x24053001) {
          if (param_1 == 0x24053000) {
            return 0x30c9000;
          }
          if (param_1 == 0x24050000) {
            return 0x303a000;
          }
          if (param_1 == 0x24052000) {
            return 0x30ae000;
          }
        }
        else if (param_1 == 0x24054000) {
          return 0x3045000;
        }
      }
      else {
        if (param_1 == 0x2405a000) {
          return 0x3080000;
        }
        if (param_1 == 0x2405d000) {
          return 0x30b1000;
        }
        if (param_1 == 0x2405e000) {
          return 0x3086000;
        }
      }
    }
    else if (param_1 < 0x24065001) {
      if (param_1 == 0x24065000) {
        return 0x307f000;
      }
      if (param_1 < 0x24063001) {
        if (param_1 == 0x24063000) {
          return 0x3087000;
        }
        if (param_1 == 0x24061000) {
          return 0x3078000;
        }
        if (param_1 == 0x24062000) {
          return 0x3078000;
        }
      }
      else if (param_1 == 0x24064000) {
        return 0x3056000;
      }
    }
    else {
      if (param_1 == 0x24066000) {
        return 0x3085000;
      }
      if (param_1 == 0x24067000) {
        return 0x30a2000;
      }
      if (param_1 == 0x24068000) {
        return 0x30a8000;
      }
    }
  }
  else if (param_1 < 0x240a4001) {
    if (param_1 == 0x240a4000) {
      return 0x30b9000;
    }
    if (param_1 < 0x24083001) {
      if (param_1 == 0x24083000) {
        return 0x30ab000;
      }
      if (param_1 < 0x24075001) {
        if (param_1 == 0x24075000) {
          return 0x30a9000;
        }
        if (param_1 < 0x2406f001) {
          if (param_1 == 0x2406f000) {
            return 0x30a7000;
          }
          if (param_1 < 0x2406c001) {
            if (param_1 == 0x2406c000) {
              return 0x30b2000;
            }
            if (param_1 == 0x2406a000) {
              return 0x3077000;
            }
            if (param_1 == 0x2406b000) {
              return 0x3082000;
            }
          }
          else if (param_1 == 0x2406d000) {
            return 0x3084000;
          }
        }
        else if (param_1 < 0x24072001) {
          if (param_1 == 0x24072000) {
            return 0x3094000;
          }
          if (param_1 == 0x24070000) {
            return 0x30a0000;
          }
          if (param_1 == 0x24071000) {
            return 0x308b000;
          }
        }
        else if (param_1 == 0x24073000) {
          return 0x30cd000;
        }
      }
      else if (param_1 < 0x2407c001) {
        if (param_1 == 0x2407c000) {
          return 0x30b4000;
        }
        if (param_1 < 0x2407a001) {
          if (param_1 == 0x2407a000) {
            return 0x30a1000;
          }
          if (param_1 == 0x24076000) {
            return 0x3079000;
          }
          if (param_1 == 0x24077000) {
            return 0x307a000;
          }
        }
        else if (param_1 == 0x2407b000) {
          return 0x30b3000;
        }
      }
      else {
        if (param_1 == 0x2407d000) {
          return 0x30b5000;
        }
        if (param_1 == 0x24081000) {
          return 0x30a5000;
        }
        if (param_1 == 0x24082000) {
          return 0x30aa000;
        }
      }
    }
    else if (param_1 < 0x24097001) {
      if (param_1 == 0x24097000) {
        return 0x30de000;
      }
      if (param_1 < 0x2408b001) {
        if (param_1 == 0x2408b000) {
          return 0x309f000;
        }
        if (param_1 < 0x24089001) {
          if (param_1 == 0x24089000) {
            return 0x30a6000;
          }
          if (param_1 == 0x24084000) {
            return 0x30a3000;
          }
          if (param_1 == 0x24088000) {
            return 0x30a4000;
          }
        }
        else if (param_1 == 0x2408a000) {
          return 0x30ad000;
        }
      }
      else {
        if (param_1 == 0x24091000) {
          return 0x307d000;
        }
        if (param_1 == 0x24094000) {
          return 0x30ac000;
        }
        if (param_1 == 0x24095000) {
          return 0x3095000;
        }
      }
    }
    else if (param_1 < 0x240a0001) {
      if (param_1 == 0x240a0000) {
        return 0x308e000;
      }
      if (param_1 < 0x2409a001) {
        if (param_1 == 0x2409a000) {
          return 0x30bc000;
        }
        if (param_1 == 0x24098000) {
          return 0x30df000;
        }
        if (param_1 == 0x24099000) {
          return 0x309a000;
        }
      }
      else if (param_1 == 0x2409b000) {
        return 0x3048000;
      }
    }
    else {
      if (param_1 == 0x240a1000) {
        return 0x30be000;
      }
      if (param_1 == 0x240a2000) {
        return 0x309b000;
      }
      if (param_1 == 0x240a3000) {
        return 0x309c000;
      }
    }
  }
  else if (param_1 < 0x240ba001) {
    if (param_1 == 0x240ba000) {
      return 0x30b7000;
    }
    if (param_1 < 0x240b0001) {
      if (param_1 == 0x240b0000) {
        return 0x30c4000;
      }
      if (param_1 < 0x240ab001) {
        if (param_1 == 0x240ab000) {
          return 0x303c000;
        }
        if (param_1 < 0x240a8001) {
          if (param_1 == 0x240a8000) {
            return 0x30bd000;
          }
          if (param_1 == 0x240a5000) {
            return 0x30ba000;
          }
          if (param_1 == 0x240a6000) {
            return 0x30bf000;
          }
        }
        else if (param_1 == 0x240a9000) {
          return 0x30db000;
        }
      }
      else if (param_1 < 0x240ae001) {
        if (param_1 == 0x240ae000) {
          return 0x3097000;
        }
        if (param_1 == 0x240ac000) {
          return 0x30c1000;
        }
        if (param_1 == 0x240ad000) {
          return 0x3096000;
        }
      }
      else if (param_1 == 0x240af000) {
        return 0x30c3000;
      }
    }
    else if (param_1 < 0x240b6001) {
      if (param_1 == 0x240b6000) {
        return 0x30c0000;
      }
      if (param_1 < 0x240b3001) {
        if (param_1 == 0x240b3000) {
          return 0x30c6000;
        }
        if (param_1 == 0x240b1000) {
          return 0x30d0000;
        }
        if (param_1 == 0x240b2000) {
          return 0x30d7000;
        }
      }
      else if (param_1 == 0x240b4000) {
        return 0x30cf000;
      }
    }
    else {
      if (param_1 == 0x240b7000) {
        return 0x30dc000;
      }
      if (param_1 == 0x240b8000) {
        return 0x3098000;
      }
      if (param_1 == 0x240b9000) {
        return 0x30b6000;
      }
    }
  }
  else if (param_1 < 0x240c7001) {
    if (param_1 == 0x240c7000) {
      return 0x3088000;
    }
    if (param_1 < 0x240c1001) {
      if (param_1 == 0x240c1000) {
        return 0x30dd000;
      }
      if (param_1 < 0x240bd001) {
        if (param_1 == 0x240bd000) {
          return 0x3046000;
        }
        if (param_1 == 0x240bb000) {
          return 0x30c5000;
        }
        if (param_1 == 0x240bc000) {
          return 0x30d8000;
        }
      }
      else if (param_1 == 0x240c0000) {
        return 0x3089000;
      }
    }
    else {
      if (param_1 == 0x240c2000) {
        return 0x30d6000;
      }
      if (param_1 == 0x240c3000) {
        return 0x30c8000;
      }
      if (param_1 == 0x240c5000) {
        return 0x30d5000;
      }
    }
  }
  else if (param_1 < 0x240cc001) {
    if (param_1 == 0x240cc000) {
      return 0x3091000;
    }
    if (param_1 < 0x240ca001) {
      if (param_1 == 0x240ca000) {
        return 0x30ca000;
      }
      if (param_1 == 0x240c8000) {
        return 0x30d9000;
      }
      if (param_1 == 0x240c9000) {
        return 0x3099000;
      }
    }
    else if (param_1 == 0x240cb000) {
      return 0x30c2000;
    }
  }
  else if (param_1 == 0x240cd000) {
    param_1 = 0x30da000;
  }
  else {
    if (param_1 == 0x240ce000) {
      return 0x30c7000;
    }
    if (param_1 == 0x240cf000) {
      return 0x3083000;
    }
  }
  return param_1;
}
}

