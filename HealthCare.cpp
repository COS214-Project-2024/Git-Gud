#include "HealthCare.h"
#include <iostream>

void HealthCare::callObserver(){

    ChangeData changeData = {"ProvideService", 5.0f};

    this->notify(changeData);

    std::cout << "Healthcare is now available in the area" << std::endl;

}