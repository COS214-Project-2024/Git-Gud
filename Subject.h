#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"

class Subject
{
private:
    Observer* observerList;
public:
    void attach(Observer* observer);
    void detach(Observer* observer);
    void notify();
};


#endif // SUBJECT_H