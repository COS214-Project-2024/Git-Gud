
#ifndef NEUTRAL_H
#define NEUTRAL_H

#include "SatisfactionLevel.h"

class Neutral : public SatisfactionLevel{

    public:
        float satisfactionRating;

        Neutral() = default;

        void enterState() override;
        void exitState() override;

        void nextState(Citizen* citizen) override;
        void prevState(Citizen* citizen) override;

        std::string getCurrentSatisfactionLevel() override;
};

#endif  // NEUTRAL_H