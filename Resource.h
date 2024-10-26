#ifndef RESOURCE_H
#define RESOURCE_H

class Resource {
protected:
    int cost;
    int availableAmount;

public:
    Resource(int cost, int initialAmount) : cost(cost), availableAmount(initialAmount) {}
    virtual ~Resource() = default;

    int getCost() const { return cost; }
    int getAvailableAmount() const { return availableAmount; }

    void decreaseAmount(int amount) {
        if (availableAmount >= amount) {
            availableAmount -= amount;
        }
    }

    void addAmount(int amount) {
        availableAmount += amount;
    }
};

#endif // RESOURCE_H