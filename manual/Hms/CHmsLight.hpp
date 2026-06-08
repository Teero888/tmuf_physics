#ifndef CHMSLIGHT_HPP
#define CHMSLIGHT_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CHmsZone;

class CHmsLight : public CMwNod {
public:
    CHmsZone* m_parentZone;

    CHmsLight() : CMwNod(), m_parentZone(nullptr) {}
    virtual ~CHmsLight() {}

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }
};

#endif // CHMSLIGHT_HPP
