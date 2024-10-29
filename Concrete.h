#ifndef CONCRETE_H
#define CONCRETE_H

#include "Resources.h"
#include <algorithm>

class Concrete {
private:
    int amount;

public:
    Concrete(int initialAmount = 0) : amount(initialAmount) {}
    int getAmount() const { return amount; }
    void setAmount(int newAmount) { amount = newAmount; }

    void addAmount(int add) { amount += add; }
    void subtractAmount(int sub) { amount = std::max(0, amount - sub); }
};

#endif // CONCRETE_H