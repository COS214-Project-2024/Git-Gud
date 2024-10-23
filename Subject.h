#ifndef SUBJECT_H
#define SUBJECT_H

#include "Citizen.h"

class Subject
{
private:
    Citizen* observerList;
public:
    void attach(Citizen* observer);
    void detach(Citizen* observer);
    void notify();
};


#endif // SUBJECT_H