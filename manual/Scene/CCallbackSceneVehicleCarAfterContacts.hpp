#ifndef CCALLBACKSCENEVEHICLECARAFTERCONTACTS_HPP
#define CCALLBACKSCENEVEHICLECARAFTERCONTACTS_HPP

#include "CHmsItem.hpp"

// Native callback at TmForeverFixed.exe 0x7C3040. Vehicle construction
// installs it in callback slot four, after collision response has completed.
class CCallbackSceneVehicleCarAfterContacts final
    : public CHmsItem::CCallback {
public:
    ~CCallbackSceneVehicleCarAfterContacts() override;

    ECallback GetType() const override { return CB_AFTER_CONTACTS; }
    void AfterContacts(CHmsItem* item) override;

    static CCallbackSceneVehicleCarAfterContacts* Instance();
};

#endif // CCALLBACKSCENEVEHICLECARAFTERCONTACTS_HPP
