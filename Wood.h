#ifndef WOOD_H
#define WOOD_H

#include "Resources.h"

class Wood : public Resources {
private:
    int amount;

public:
    Wood(int initialAmount = 0) : amount(initialAmount) {}
    int getAmount() const { return amount; }
    void setAmount(int newAmount) { amount = newAmount; }

    // Method to add to the current amount
    void addAmount(int add) { amount += add; }

    // Method to subtract from the current amount, with a minimum of 0
    void subtractAmount(int sub) { amount = std::max(0, amount - sub); }
};

#endif // WOOD_H