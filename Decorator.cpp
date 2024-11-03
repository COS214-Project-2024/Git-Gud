#ifndef DECORATOR_CPP
#define DECORATOR_CPP

#include "Decorator.h"

Decorator::~Decorator(){
    if (this->building != nullptr){
    delete this->building;
    }
}

#endif