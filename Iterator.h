#ifndef ITERATOR_H
#define ITERATOR_H

class Iterator
{
private:
 
public:
    virtual void next() = 0;
    virtual void hasNext() = 0;
    virtual bool current() = 0;
};

#endif // ITERATOR_H