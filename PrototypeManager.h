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
    PrototypeManager();
    ~PrototypeManager();
    void addPrototype(Building* p);
    bool removePrototype(Building* p);
    Building* getPrototype(Building* p) const;    
};

#endif // PROTOTYPEMANAGER_H