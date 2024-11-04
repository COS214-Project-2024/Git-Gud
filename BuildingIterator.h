#ifndef BUILDINGITERATOR_H
#define BUILDINGITERATOR_H

#include "Building.h"

class BuildingIterator {
protected:
    Building*** array;
    int rows, cols;
    int row, col;

public:
    virtual bool hasNext() = 0;
    virtual void next() = 0;
    virtual Building* current() = 0;
};


#endif // BUILDINGITERATOR_H