#ifndef DISSATISFIED_H
#define DISSATISFIED_H

#include "SatisfactionLevel.h"

class Dissatisfied : public SatisfactionLevel{

    public:
        float satisfactionRating;

        Dissatisfied() = default;

        void enterState() override;
        void exitState() override;

        void nextState(Citizen* citizen) override;
        void prevState(Citizen* citizen) override;

        std::string getCurrentSatisfactionLevel() override;
};

#endif  // DISSATISFIED_H