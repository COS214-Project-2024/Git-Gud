#ifndef WOOD_H
#define WOOD_H

#include "Resources.h"
#include <algorithm>

class Wood : public Resources {
private:
    int amount;

public:
    Wood(int initialAmount = 0) : amount(initialAmount) {}

    int getAmount() const { return amount; }
    void setAmount(int newAmount) { amount = newAmount; }

    void addAmount(int add) { amount += add; }
    void subtractAmount(int sub) { amount = std::max(0, amount - sub); }
};

#endif // WOOD_H