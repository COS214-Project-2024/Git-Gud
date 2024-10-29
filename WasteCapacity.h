#ifndef WASTECAPACITY_H
#define WASTECAPACITY_H

#include "Resources.h"

class WasteCapacity : public Resources {
private:
    int amount;

public:
    WasteCapacity(int initialAmount = 0) : amount(initialAmount) {}
    
    // Getter and setter for amount
    int getAmount() const { return amount; }
    void setAmount(int newAmount) { amount = newAmount; }

    // Method to add to the current waste capacity
    void addAmount(int add) { amount += add; }

    // Method to subtract from the current waste capacity, ensuring it doesn’t go below zero
    void subtractAmount(int sub) { amount = std::max(0, amount - sub); }
};

#endif // WASTECAPACITY_H