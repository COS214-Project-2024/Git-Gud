#ifndef DISSATISFIED_H
#define DISSATISFIED_H

#include "SatisfactionLevel.h"
#include "Neutral.h"
#include "VeryDissatisfied.h"

class Dissatisfied : public SatisfactionLevel{
    protected:
        float taxReturn = 0.8;

    public:
        float satisfactionRating;

        Dissatisfied(){}
        ~Dissatisfied(){}

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

#endif  // DISSATISFIED_H