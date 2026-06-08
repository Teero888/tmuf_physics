#ifndef CHMSPORTAL_HPP
#define CHMSPORTAL_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CHmsItem;
class CPlugTree;
class CHmsZone;

class CHmsPortal : public CMwNod {
public:
    CHmsPortal() : CMwNod() {}
    virtual ~CHmsPortal() {}

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }

    void BindToBuild(CHmsPortal* portal, CHmsItem* item, CHmsZone* zone);
    void UnbindFromBuild(CHmsZone* zone);
};

#endif // CHMSPORTAL_HPP
