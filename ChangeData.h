#ifndef CHANGEDATA_H
#define CHANGEDATA_H

#include <iostream>

struct ChangeData{

    std::string changeType;
    float value;

    bool operator==(const ChangeData& other) const{

        return changeType == other.changeType && value == other.value;

    }

};

#endif // CHANGEDATA_H