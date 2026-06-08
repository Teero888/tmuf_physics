#ifndef CGAMECTNREPLAYRECORD_HPP
#define CGAMECTNREPLAYRECORD_HPP

#include "CMwNod.hpp"

class CFuncSegment;
class CClassicArchive;

#include <vector>
#include <string>

struct SInputEvent {
    uint32_t time;
    uint8_t controlIdx;
    uint32_t value;
};

class CGameCtnReplayRecord : public CMwNod {
public:
    std::vector<std::string> m_controlNames;
    std::vector<SInputEvent> m_events;

    CGameCtnReplayRecord();
    virtual ~CGameCtnReplayRecord();
    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
    void Chunk(CFuncSegment* segment, CClassicArchive* archive, uint32_t chunkId);
};

#endif
