#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <vector>

#include "Citizen.h"
#include "ChangeData.h"

//forward declaration:
class Citizen;

class Subject{

    private:
        std::vector<Citizen*> observerList;

    protected:
        static std::vector<Citizen*> allCitizens;

    public:
        void attach(Citizen* observer);
        void detach(Citizen* observer);
        void notify(ChangeData changeData);

        void addCitizenToSimulation(Citizen* newCitizen);
        void removeCitizenFromSimulation(Citizen* citizen);

        int getObserverListSize();
        int getNumCitizens();
        std::vector<Citizen*> getObserverList();

};


#endif // SUBJECT_H