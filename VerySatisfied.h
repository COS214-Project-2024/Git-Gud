#ifndef VERYSATISFIED_H
#define VERYSATISFIED_H

#include "SatisfactionLevel.h"
#include "Satisfied.h"

class VerySatisfied : public SatisfactionLevel{
    protected:
        float taxReturn = 1.5;

    public:
        float satisfactionRating;

        VerySatisfied(){};
        ~VerySatisfied(){}

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

#endif  // VERYSATISFIED_H