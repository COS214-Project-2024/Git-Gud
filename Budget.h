#ifndef BUDGET_H
#define BUDGET_H

#include "Resources.h"
#include <algorithm>

class Budget {
private:
    int amount;

public:
    Budget(int initialAmount = 0) : amount(initialAmount) {}
    int getAmount() const { return amount; }
    void setAmount(int newAmount) { amount = newAmount; }

    void addAmount(int add) { amount += add; }
    void subtractAmount(int sub) { amount = std::max(0, amount - sub); }
};

#endif // BUDGET_H