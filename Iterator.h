#ifndef ITERATOR_H
#define ITERATOR_H

#include <string>

using namespace std;

class Iterator {

public:
    Iterator();
    ~Iterator();

    bool hasNext();
    string next();

private:
    string* data;
    int size;
    int index;

};

#endif // ITERATOR_H