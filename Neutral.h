
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

        Neutral() = default;

        void enterState() override;
        void exitState() override;

        void nextState(Citizen* citizen) override;
        void prevState(Citizen* citizen) override;

        std::string getCurrentSatisfactionLevel() override;

        float getTaxReturn()override {return taxReturn;};
};

#endif  // NEUTRAL_H