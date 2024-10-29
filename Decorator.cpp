#ifndef DECORATOR_CPP
#define DECORATOR_CPP

#include "Decorator.h"

void Decorator::provideService(){       // needs updating
    this->building->provideService();
}

Decorator::~Decorator(){
    delete this->building;
}

#endif