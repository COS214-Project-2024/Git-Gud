
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

        Neutral(){}
        ~Neutral(){}

        /**
        * @brief Method used to enter the next state
        **/
        void enterState() override;
        /**
        * @brief Method used to exit the current state
        **/
        void exitState() override;

        /**
        * @brief Method used to retrieve the current satisfaction level
        * @return std::string
        **/
        std::string getCurrentSatisfactionLevel() override;

        /**
        * @brief Method used to retrieve the tax return of the current state
        * @return float
        **/
        float getTaxReturn()override {return taxReturn;};
};

#endif  // NEUTRAL_H