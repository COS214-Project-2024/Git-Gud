#ifndef VERYDISSATISFIED_H
#define VERYDISSATISFIED_H

#include "SatisfactionLevel.h"

class VeryDissatisfied : public SatisfactionLevel{

    public:
        float satisfactionRating;

        VeryDissatisfied() = default;

        void enterState() override;
        void exitState() override;

        void nextState(Citizen* citizen) override;
        void prevState(Citizen* citizen) override;

        std::string getCurrentSatisfactionLevel() override;
};

#endif  // VERYDISSATISFIED_H