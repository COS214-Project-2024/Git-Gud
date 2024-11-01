#include "PrototypeManager.h"

PrototypeManager::PrototypeManager(){
    capacity = 10;
    size = 0;
    prototypeBuildings = new Building*[capacity];
}

PrototypeManager::~PrototypeManager(){
    for (int i = 0; i < size; ++i) {
        delete prototypeBuildings[i];
    }
    delete[] prototypeBuildings;
}

void PrototypeManager::addPrototype(Building* p){

}

void PrototypeManager::removePrototype(Building* p){

}

Building* PrototypeManager::getPrototype(){

}

void PrototypeManager::resizeArray(int newCapacity) {
    Building** newPrototypes = new Building*[newCapacity];
    for (int i = 0; i < size; ++i) {
        newPrototypes[i] = prototypeBuildings[i];
    }
    delete[] prototypeBuildings;
    prototypeBuildings = newPrototypes;
    capacity = newCapacity;
}