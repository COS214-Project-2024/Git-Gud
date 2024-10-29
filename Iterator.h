#ifndef ITERATOR_H
#define ITERATOR_H

#include <string>
#include "GameEnvironment.h"

using namespace std;

template <typename T>
class Iterator {
    protected:
        T*** array;
        GameEnvironment* game;

    public:
        Iterator();
        ~Iterator();

        virtual bool hasNext()=0;
        virtual void next()=0;
        virtual T* current() const=0;
    
};

#endif // ITERATOR_H