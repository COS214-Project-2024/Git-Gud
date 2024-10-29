#ifndef DECORATOR_CPP
#define DECORATOR_CPP

#include "Decorator.h"

Decorator::Decorator(Building* b, int cap) : Building(cap){
    this->building=b;
}

void Decorator::provideService(){       // needs updating
    this->building->provideService();
}

Decorator::~Decorator(){
    delete this->building;
}

#endif