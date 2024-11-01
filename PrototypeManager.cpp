#include "PrototypeManager.h"

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