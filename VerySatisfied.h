#ifndef VERYSATISFIED_H
#define VERYSATISFIED_H

#include "SatisfactionLevel.h"

class VerySatisfied : public SatisfactionLevel{

    public:
        float satisfactionRating;

        Satisfied() = default;

        void enterState() override;
        void exitState() override;

        void nextState(Citizen* citizen) override;
        void prevState(Citizen* citizen) override;

        std::string getCurrentSatisfactionLevel() override;
};

#endif  // VERYSATISFIED_H