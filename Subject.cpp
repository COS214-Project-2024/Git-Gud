#include "Subject.h"
#include <iostream>
#include <algorithm>

std::vector<Citizen*> Subject::allCitizens;

void Subject::attach(Citizen *observer){

    observerList.push_back(observer);

}

void Subject::detach(Citizen *observer){

    observerList.erase(std::remove(observerList.begin(), observerList.end(), observer), observerList.end());


}

void Subject::notify(ChangeData changeData){

    std::vector<Citizen*> copyOfList = observerList;

    for(Citizen *citizen: copyOfList){

        citizen->update(changeData);

    }

}

void Subject::addCitizenToSimulation(Citizen* newCitizen){

    allCitizens.push_back(newCitizen);

}

void Subject::removeCitizenFromSimulation(Citizen* citizen){

    allCitizens.erase(std::remove(allCitizens.begin(), allCitizens.end(), citizen), allCitizens.end());

}

int Subject::getObserverListSize(){

    return observerList.size();

}

int Subject::getNumCitizens(){

    return allCitizens.size();

}