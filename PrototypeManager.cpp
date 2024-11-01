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
    if (size >= capacity) {
        resizeArray(capacity * 2);
    }
    prototypeBuildings[size++] = p;
}

bool PrototypeManager::removePrototype(Building* p){
    for (int i = 0; i < size; ++i) {
        if (prototypeBuildings[i] == p) {
            delete prototypeBuildings[i];
            for (int j = i; j < size - 1; ++j) {
                prototypeBuildings[j] = prototypeBuildings[j + 1];
            }
            --size;
            return true;
        }
    }
    return false;
}

Building* PrototypeManager::getPrototype(Building* p) const{
    for (int i = 0; i < size; ++i) {
        if (prototypeBuildings[i] == p) {
            return prototypeBuildings[i];
        }
    }
    return nullptr;
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