#ifndef VERYDISSATISFIED_H
#define VERYDISSATISFIED_H

#include "SatisfactionLevel.h"
#include "Dissatisfied.h"

class VeryDissatisfied : public SatisfactionLevel{
    protected:
        float taxReturn = 0.5;

    public:
        float satisfactionRating;

        VeryDissatisfied(){};
        ~VeryDissatisfied(){}

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

#endif  // VERYDISSATISFIED_H