#ifndef ENERGYSUPPLY_H
#define ENERGYSUPPLY_H

#include "Resources.h"
#include <algorithm>

class EnergySupply {
private:
    int amount;

public:
    EnergySupply(int initialAmount = 0) : amount(initialAmount) {}
    
    int getAmount() const { return amount; }
    void setAmount(int newAmount) { amount = newAmount; }

    void addAmount(int add) { amount += add; }
    void subtractAmount(int sub) { amount = std::max(0, amount - sub); }
};

#endif // ENERGYSUPPLY_H