#include "LawEnforcement.h"
#include <iostream>

void LawEnforcement::callObserver(){

    ChangeData changeData = {"ProvideService", 7.0f};

    this->notify(changeData);   

    std::cout << "Law Enforcement has been employed in the area" << std::endl;

}