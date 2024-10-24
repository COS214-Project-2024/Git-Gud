#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <vector>

#include "Citizen.h"

class Subject{

    private:
        std::vector<Citizen*> observerList;
    public:
        void attach(Citizen* observer);
        void detach(Citizen* observer);
        virtual void notify(std::string, float) = 0;

};


#endif // SUBJECT_H