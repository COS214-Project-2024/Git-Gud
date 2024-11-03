#ifndef VERYSATISFIED_H
#define VERYSATISFIED_H

#include "SatisfactionLevel.h"
#include "Satisfied.h"

class VerySatisfied : public SatisfactionLevel{
    protected:
        float taxReturn = 1.5;

    public:
        float satisfactionRating;

        VerySatisfied(){enterState();};
        ~VerySatisfied(){exitState();}

        void enterState() override;
        void exitState() override;

        std::string getCurrentSatisfactionLevel() override;

        float getTaxReturn()override {return taxReturn;};
};

#endif  // VERYSATISFIED_H