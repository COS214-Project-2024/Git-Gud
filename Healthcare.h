#ifndef HEALTHCARE_H
#define HEALTHCARE_H

#include "PublicService.h"

class HealthCare : public PublicService {
public:
    void provideService() override;
};

#endif  // HEALTHCARE_H