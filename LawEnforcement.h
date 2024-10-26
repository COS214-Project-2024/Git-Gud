#ifndef LAWENFORCEMENT_H
#define LAWENFORCEMENT_H

#include "PublicService.h"

class LawEnforcement : public PublicService {
public:
    void provideService() override;
};

#endif  // LAWENFORCEMENT_H