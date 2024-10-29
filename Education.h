#ifndef EDUCATION_H
#define EDUCATION_H

#include "PublicService.h"

class Education : public PublicService {
public:
    Education(int capacity, int maintenanceCost) : PublicService(capacity, maintenanceCost, "Education", 50000){};
    virtual ~Education() = default;
    void provideService() override;
};

#endif  // EDUCATION_H