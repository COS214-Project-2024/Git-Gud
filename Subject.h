#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <vector>

#include "Citizen.h"

struct ChangeData{

    std::string changeType;
    float value;

};

class Subject{

    private:
        std::vector<Citizen*> observerList;
    public:
        void attach(Citizen* observer);
        void detach(Citizen* observer);
        void notify(ChangeData changeData);

};


#endif // SUBJECT_H