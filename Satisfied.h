
#ifndef SATISFIED_H
#define SATISFIED_H

#include "SatisfactionLevel.h"
#include "VerySatisfied.h"
#include "Neutral.h"

class Satisfied : public SatisfactionLevel{
    protected:
        float taxReturn = 1.2;

    public:
        float satisfactionRating;

        Satisfied(){enterState();}
        ~Satisfied(){exitState();}

        void enterState() override;
        void exitState() override;

        std::string getCurrentSatisfactionLevel() override;

        float getTaxReturn()override {return taxReturn;};
};

#endif  // SATISFIED_H