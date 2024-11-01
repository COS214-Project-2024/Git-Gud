#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "Resources.h"
#include <algorithm>

class WaterSupply {
private:
    int amount;

public:
    WaterSupply(int initialAmount = 0) : amount(initialAmount) {}
    
    int getAmount() const { return amount; }
    void setAmount(int newAmount) { amount = newAmount; }

    void addAmount(int add) { amount += add; }
    void subtractAmount(int sub) { amount = std::max(0, amount - sub); }
};

#endif // WATERSUPPLY_H