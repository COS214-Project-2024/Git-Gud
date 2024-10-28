#ifndef RADIAL_ITERATOR_H
#define RADIAL_ITERATOR_H

#include "Iterator.h"

template <typename T>
class RadialIterator : public Iterator<T> {
    protected:
        int radius;
        int x;
        int y;


    public:
        RadialIterator();
        ~RadialIterator();

        RadialIterator(GameEnvironment* game, T*** array, int x, int y, int radius);

        bool hasNext() override;
        void next() override;
        T* current() const override;

    
    
};

#endif // RADIAL_ITERATOR_H