
#ifndef SATISFIED_H
#define SATISFIED_H

#include "SatisfactionLevel.h"

class Satisfied : public SatisfactionLevel{

    public:
        float satisfactionRating;

        Satisfied() = default;

        void enterState() override;
        void exitState() override;

        void nextState(Citizen* citizen) override;
        void prevState(Citizen* citizen) override;

        std::string getCurrentSatisfactionLevel() override;
};

#endif  // SATISFIED_H