#include "Education.h"
#include <iostream>

void Education::callObserver(){

    ChangeData changeData = {"ProvideService", 6.0f};

    this->notify(changeData);

    std::cout << "Education is available in the area" << std::endl;

}