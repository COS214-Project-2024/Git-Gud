#ifndef VERYDISSATISFIED_H
#define VERYDISSATISFIED_H

#include "SatisfactionLevel.h"
#include "Dissatisfied.h"

class VeryDissatisfied : public SatisfactionLevel{
    protected:
        float taxReturn = 0.5;

    public:
        float satisfactionRating;

        VeryDissatisfied(){enterState();};
        ~VeryDissatisfied(){exitState();}

        void enterState() override;
        void exitState() override;

        std::string getCurrentSatisfactionLevel() override;

        float getTaxReturn()override {return taxReturn;};
};

#endif  // VERYDISSATISFIED_H