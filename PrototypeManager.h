#ifndef PROTOTYPEMANAGER_H
#define PROTOTYPEMANAGER_H

#include "Building.h"

class PrototypeManager
{
private:
    Building** prototypeBuildings;
    int capacity, size;
    void resizeArray();
public:
    PrototypeManager();
    ~PrototypeManager();
    void addPrototype(Building* p);
    bool removePrototype(Building* p);
    Building* getPrototype(Building* p) const;
    int getSize() const { return size; } 
    int getCapacity() const { return capacity; }  
};

#endif // PROTOTYPEMANAGER_H