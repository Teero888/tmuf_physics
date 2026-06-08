#include "CGameCtnReplayRecord.hpp"
#include "CClassicArchive.hpp"
#include <iostream>

CGameCtnReplayRecord::CGameCtnReplayRecord() {}
CGameCtnReplayRecord::~CGameCtnReplayRecord() {}

void CGameCtnReplayRecord::Chunk(CFuncSegment* segment, CClassicArchive* archive, uint32_t chunkId) {
    if (chunkId == 0x03093019 || chunkId == 0x03092019) {
        uint32_t eventsDuration;
        archive->DoNatural(&eventsDuration, 1);
        if (eventsDuration != 0) {
            uint32_t u01 = 0;
            archive->DoNatural(&u01, 1);
            uint32_t numNames = 0;
            archive->DoNatural(&numNames, 1);
            for (uint32_t i = 0; i < numNames; ++i) {
                uint32_t id;
                archive->DoNatural(&id, 1);
                if ((id & 0x40000000) != 0) {
                    uint32_t len;
                    archive->DoNatural(&len, 1);
                    std::string name = "";
                    for (uint32_t j = 0; j < len; ++j) {
                        uint8_t c;
                        archive->DoNat8(&c, 1);
                        name += (char)c;
                    }
                    m_controlNames.push_back(name);
                } else {
                    m_controlNames.push_back("UnknownId_" + std::to_string(id));
                }
            }
            uint32_t numEvents = 0;
            archive->DoNatural(&numEvents, 1);
            std::cout << "DEBUG: eventsDuration=" << eventsDuration << ", numNames=" << numNames << ", numEvents=" << numEvents << std::endl;
            uint32_t u02 = 0;
            archive->DoNatural(&u02, 1);
            for (uint32_t i = 0; i < numEvents; ++i) {
                uint32_t time = 0;
                uint8_t controlIdx = 0;
                uint32_t value = 0;
                archive->DoNatural(&time, 1);
                archive->DoNat8(&controlIdx, 1);
                archive->DoNatural(&value, 1);
                m_events.push_back({time, controlIdx, value});
            }
        }
    } else {
        CMwNod::Chunk(segment, archive, chunkId);
    }
}
