#ifndef EDUCATION_H
#define EDUCATION_H

#include "PublicService.h"

class Education : public PublicService {
public:
    Education();
    virtual ~Education() = default;
    void provideService() override;
};

#endif  // EDUCATION_H