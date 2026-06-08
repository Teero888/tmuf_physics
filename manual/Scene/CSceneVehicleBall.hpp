#ifndef CSCENEVEHICLEBALL_HPP
#define CSCENEVEHICLEBALL_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CHmsItem;
class CCallbackSceneVehicleBallAfterContacts;

class CSceneVehicleBall : public CMwNod {
public:
    struct SVehicleBallState {
        virtual ~SVehicleBallState();
        uint32_t field_0x4;
        uint32_t field_0x8;
        uint32_t field_0xc;
        uint32_t field_0x10;
        uint32_t field_0x14;
        uint32_t field_0x18;
        uint32_t field_0x1c;
        uint32_t field_0x20;
        uint32_t field_0x24;
        uint32_t field_0x28;
        uint32_t field_0x2c;
        uint32_t field_0x30;
        uint8_t m_padding[48];
        uint32_t field_0x64;
        uint32_t field_0x68;
        uint32_t field_0x6c;
        uint32_t field_0x70;
        uint32_t field_0x74;
        uint32_t field_0x78;
        uint32_t field_0x7c;
    };

    uint8_t m_padding_ball[36];
    CHmsItem* m_item; // 0x28
    uint8_t m_padding2[0x4E0-0x2C]; // Total size 0x4E0

    CSceneVehicleBall();
    virtual ~CSceneVehicleBall();

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }

    static CMwNod* MwNewCSceneVehicleBall();
    
    uint32_t GetMwClassId();
};

#endif // CSCENEVEHICLEBALL_HPP
