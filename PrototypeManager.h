#ifndef PROTOTYPEMANAGER_H
#define PROTOTYPEMANAGER_H

#include "BuildingFactory.h"

class PrototypeManager
{
private:
    BuildingFactory* buildings;
public:
    void addPrototype(BuildingFactory* p);
    void removePrototype(BuildingFactory* p);
    BuildingFactory* getPrototype();
};

#endif // PROTOTYPEMANAGER_H