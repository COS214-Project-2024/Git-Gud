#ifndef UTILITYITERATOR_H
#define UTILITYITERATOR_H

#include "UtilityGridNode.h"

class UtilityIterator {
protected:
    UtilGridNode*** array;
    int row, col;

public:
    virtual bool hasNext() = 0;
    virtual void next() = 0;
    virtual UtilGridNode* current() = 0;
};


#endif // UTILITYITERATOR_H