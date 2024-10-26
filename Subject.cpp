#include "Subject.h"
#include <iostream>
#include <algorithm>

void Subject::attach(Citizen *observer){

    observerList.push_back(observer);

}

void Subject::detach(Citizen *observer){

    observerList.erase(std::remove(observerList.begin(), observerList.end(), observer), observerList.end());


}

void Subject::notify(ChangeData changeData){

    for(Citizen *citizen: observerList){

        citizen->update(changeData);

    }

}