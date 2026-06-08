#ifndef CHMSCORPUSLIGHT_HPP
#define CHMSCORPUSLIGHT_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CHmsCorpusLight : public CMwNod {
public:
    class CHmsZone* m_parentZone;
public:
    CHmsCorpusLight() : CMwNod() {}
    virtual ~CHmsCorpusLight() {}

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
};

#endif // CHMSCORPUSLIGHT_HPP
