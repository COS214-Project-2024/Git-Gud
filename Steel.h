#ifndef STEEL_H
#define STEEL_H

#include "Resources.h"
#include <algorithm>

class Steel {
private:
    int amount;

public:
    Steel(int initialAmount = 0) : amount(initialAmount) {}
    int getAmount() const { return amount; }
    void setAmount(int newAmount) { amount = newAmount; }

    void addAmount(int add) { amount += add; }
    void subtractAmount(int sub) { amount = std::max(0, amount - sub); }
};

#endif // STEEL_H