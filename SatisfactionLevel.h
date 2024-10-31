#ifndef SATISFACTIONLEVEL_H
#define SATISFACTIONLEVEL_H

#include <string>
#include "Citizen.h"

class Citizen;

class SatisfactionLevel{
    protected:
        float taxReturn;

    public:
        float satisfactionRating;

        virtual ~SatisfactionLevel(){};
        virtual void enterState() = 0;
        virtual void exitState() = 0;

        virtual void nextState(Citizen* citizen) = 0;
        virtual void prevState(Citizen* citizen) = 0;

        virtual std::string getCurrentSatisfactionLevel() = 0;
        float getTaxReturn(){return taxReturn;};
};

#endif  // SATISFACTIONLEVEL_H