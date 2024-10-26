#ifndef RESOURCES_H
#define RESOURCES_H

#include <string>

class Resources {
private:
    int wood;
    int steel;
    int concrete;
    int budget;
    int waterSupply;
    int energySupply;

public:
    Resources(int w = 0, int s = 0, int c = 0, int b = 0, int ws = 0, int es = 0);

    // Getters
    int getWood() const;
    int getSteel() const;
    int getConcrete() const;
    int getBudget() const;
    int getWaterSupply() const;
    int getEnergySupply() const;

    // Methods to modify resources
    void addResource(const std::string& resourceType, int amount);
    void useResource(const std::string& resourceType, int amount);

    // For budget, provide specific methods since it may have unique rules
    void addBudget(int amount);
    void spendBudget(int amount);
};

#endif // RESOURCES_H