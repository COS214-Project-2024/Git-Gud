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

        /**
        * @brief Method used to enter the next state
        **/
        virtual void enterState() = 0;

        /**
        * @brief Method used to exit the current state
        **/
        virtual void exitState() = 0;

        /**
        * @brief Method used to retrieve the current satisfaction level
        * @return std::string
        **/
        virtual std::string getCurrentSatisfactionLevel() = 0;

        /**
        * @brief Method used to retrieve the tax return of the current state
        * @return float
        **/
        virtual float getTaxReturn() = 0;
};

#endif  // SATISFACTIONLEVEL_H