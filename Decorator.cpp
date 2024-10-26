#ifndef DECORATOR_CPP
#define DECORATOR_CPP

#include "Decorator.h"

void Decorator::provideService(){
    this->building->provideService();
}

#endif