#ifndef DISSATISFIED_H
#define DISSATISFIED_H

#include "SatisfactionLevel.h"
#include "Neutral.h"
#include "VeryDissatisfied.h"

class Dissatisfied : public SatisfactionLevel{
    protected:
        float taxReturn = 0.8;

    public:
        float satisfactionRating;

        Dissatisfied(){enterState();}
        ~Dissatisfied(){exitState();}

        void enterState() override;
        void exitState() override;

        std::string getCurrentSatisfactionLevel() override;
};

#endif  // DISSATISFIED_H