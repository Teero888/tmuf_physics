#ifndef CSCENEMOBILABSORBCONTACT_HPP
#define CSCENEMOBILABSORBCONTACT_HPP

#include "CHmsItem.hpp"

// Native callback at TmForeverFixed.exe 0x7B39F0. Its two callback arguments
// are CHmsItem* and CHmsPhysicalContact* (`ret 0x08`); it forwards the contact
// to the item's scene mobil virtual method.
class CSceneMobilAbsorbContact final : public CHmsItem::CCallback {
public:
    ~CSceneMobilAbsorbContact() override;

    ECallback GetType() const override { return CB_ABSORB_CONTACT; }
    void AbsorbContact(
        CHmsItem* item,
        CHmsPhysicalContact* contact) override;

    static CSceneMobilAbsorbContact* Instance();
};

#endif // CSCENEMOBILABSORBCONTACT_HPP
