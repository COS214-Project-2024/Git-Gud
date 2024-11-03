
#ifndef NEUTRAL_H
#define NEUTRAL_H

#include "SatisfactionLevel.h"
#include "Dissatisfied.h"
#include "Satisfied.h"

class Neutral : public SatisfactionLevel{
    protected:
        float taxReturn = 1.0;

    public:
        float satisfactionRating;

        Neutral(){enterState();}
        ~Neutral(){exitState();}

        void enterState() override;
        void exitState() override;

        std::string getCurrentSatisfactionLevel() override;
};

#endif  // NEUTRAL_H