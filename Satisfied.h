
#ifndef SATISFIED_H
#define SATISFIED_H

#include "SatisfactionLevel.h"
#include "VerySatisfied.h"
#include "Neutral.h"

class Satisfied : public SatisfactionLevel{
    protected:
        float taxReturn = 1.2;

    public:
        float satisfactionRating;

        Satisfied(){enterState();}
        ~Satisfied(){exitState();}

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

#endif  // SATISFIED_H