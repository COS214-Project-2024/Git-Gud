#ifndef DECORATOR_CPP
#define DECORATOR_CPP

#include "Decorator.h"

Decorator::~Decorator(){
    delete this->building;
}

#endif