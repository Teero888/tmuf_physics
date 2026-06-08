#ifndef CSCENEMOBIL_HPP
#define CSCENEMOBIL_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CHmsItem;
class CPlugSolid;
class CPlugTree;
class CSceneSector;
class GmIso4;
class GmVec3;
struct CPfmHeap;

class CSceneMobil : public CMwNod {
public:
    uint32_t m_field_14;       // 0x14
    uint8_t m_padding_18[8];   // 0x18
    uint32_t m_field_20;       // 0x20
    uint8_t m_padding_24[4];   // 0x24
    CHmsItem* m_hmsItem;       // 0x28
    CMwNod* m_nod2c;           // 0x2C
    uint32_t m_field_30;       // 0x30
    uint32_t m_field_34;       // 0x34
    uint8_t m_padding_38[12];  // 0x38
    CMwNod* m_nod44;           // 0x44

    CSceneMobil();
    virtual ~CSceneMobil();

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }

    static CMwNod* MwNewCSceneMobil();
    uint32_t GetMwClassId();
    void* _scalar_deleting_destructor_(CPfmHeap* param_1, uint32_t param_2);

    void SetLocation(CPlugTree* tree, GmIso4* location);
    void SetTranslation(GmIso4* location, GmVec3* translation);
};

#endif // CSCENEMOBIL_HPP
