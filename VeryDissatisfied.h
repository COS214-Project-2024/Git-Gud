#ifndef VERYDISSATISFIED_H
#define VERYDISSATISFIED_H

#include "SatisfactionLevel.h"
#include "Dissatisfied.h"

class VeryDissatisfied : public SatisfactionLevel{
    protected:
        float taxReturn = 0.5;

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