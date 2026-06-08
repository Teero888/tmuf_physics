import re

ghidra_code = """
  fVar5 = *(float *)param_1;
  iVar6 = *(int *)(param_1 + 8);
  local_3c = (float)iVar6;
  local_38 = fVar5;
  CPlugSurfaceMaterialData::GetRestitutionCoefWith
            (&DAT_00d6eec0 + (uint)*(ushort *)(param_1 + 0x34) * 2,
             (CPlugSurfaceMaterialData *)(&DAT_00d6eec0 + (uint)*(ushort *)(param_1 + 0x36) * 2),
             unaff_EDI);
  local_58 = *(void **)(iVar6 + 0x58);
  pGVar14 = *(GmMat3 **)((int)fVar5 + 0x58);
  uVar10 = *(uint *)(*(int *)((int)fVar5 + 0x48) + 0x18) >> 0xb & 3;
  uVar11 = *(uint *)(*(int *)(iVar6 + 0x48) + 0x18) >> 0xb & 3;
  this_00 = param_1 + 0x10;
  if (uVar11 < uVar10) {
    local_44 = -*(float *)this_00;
    local_40 = -*(float *)(param_1 + 0x14);
    local_3c = -*(float *)(param_1 + 0x18);
    local_48 = (void *)0x0;
    local_4c = (void *)0x0;
    local_50 = 0.0;
  }
"""

def replace_offsets(text):
    # param_1 is SHmsPhysicalCollision*
    text = text.replace('*(float *)param_1', 'collision->m_value00')
    text = text.replace('*(int *)(param_1 + 8)', 'collision->m_body')
    text = text.replace('param_1 + 0x10', '&collision->m_normal')
    text = text.replace('*(float *)(param_1 + 0x14)', 'collision->m_normal.y')
    text = text.replace('*(float *)(param_1 + 0x18)', 'collision->m_normal.z')
    text = text.replace('*(ushort *)(param_1 + 0x34)', 'collision->m_matId1')
    text = text.replace('*(ushort *)(param_1 + 0x36)', 'collision->m_matId2')
    return text

print(replace_offsets(ghidra_code))
