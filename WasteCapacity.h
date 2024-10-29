#ifndef WASTECAPACITY_H
#define WASTECAPACITY_H

#include "Resources.h"
#include <algorithm>

class WasteCapacity {
private:
    int amount;

public:
    WasteCapacity(int initialAmount = 0) : amount(initialAmount) {}
    
    int getAmount() const { return amount; }
    void setAmount(int newAmount) { amount = newAmount; }

    void addAmount(int add) { amount += add; }
    void subtractAmount(int sub) { amount = std::max(0, amount - sub); }
};

#endif // WASTECAPACITY_H