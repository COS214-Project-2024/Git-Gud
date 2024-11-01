#ifndef PROTOTYPEMANAGER_H
#define PROTOTYPEMANAGER_H

#include "Building.h"

class PrototypeManager
{
private:
    Building** prototypeBuildings;
    int capacity, size;
    void resizeArray(int newCapacity);
public:
    void addPrototype(Building* p);
    void removePrototype(Building* p);
    Building* getPrototype();    
};

#endif // PROTOTYPEMANAGER_H