#ifndef LAWENFORCEMENT_H
#define LAWENFORCEMENT_H

#include "PublicService.h"

class LawEnforcement : public PublicService {
public:
    LawEnforcement(int capacity, int maintenanceCost) : PublicService(capacity, maintenanceCost, "LawEnforcement", 25000){};
    virtual ~LawEnforcement() = default;
    void callObserver() override;

};

#endif  // LAWENFORCEMENT_H