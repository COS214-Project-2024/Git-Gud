#ifndef SATISFACTIONLEVEL_H
#define SATISFACTIONLEVEL_H

#include <string>
#include "Citizen.h"

class SatisfactionLevel{
    protected:
        float taxReturn;

    public:
        float satisfactionRating;
        virtual void enterState() = 0;
        virtual void exitState() = 0;

        virtual void nextState(Citizen* citizen) = 0;
        virtual void prevState(Citizen* citizen) = 0;

        virtual std::string getCurrentSatisfactionLevel() = 0;
        virtual float getTaxReturn() = 0;
};

#endif  // SATISFACTIONLEVEL_H