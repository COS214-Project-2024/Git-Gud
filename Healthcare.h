#ifndef HEALTHCARE_H
#define HEALTHCARE_H

#include "PublicService.h"

class HealthCare : public PublicService {
public:
    HealthCare();
    virtual ~HealthCare() = default;
    void provideService() override;
};

#endif  // HEALTHCARE_H