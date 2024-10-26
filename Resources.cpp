#include "Resources.h"

Resources::Resources(int w, int s, int c, int b, int ws, int es)
    : wood(w), steel(s), concrete(c), budget(b), waterSupply(ws), energySupply(es) {}

int Resources::getWood() const { return wood; }
int Resources::getSteel() const { return steel; }
int Resources::getConcrete() const { return concrete; }
int Resources::getBudget() const { return budget; }
int Resources::getWaterSupply() const { return waterSupply; }
int Resources::getEnergySupply() const { return energySupply; }

void Resources::addResource(const std::string& resourceType, int amount) {
    if (resourceType == "wood") wood += amount;
    else if (resourceType == "steel") steel += amount;
    else if (resourceType == "concrete") concrete += amount;
    else if (resourceType == "waterSupply") waterSupply += amount;
    else if (resourceType == "energySupply") energySupply += amount;
}

void Resources::useResource(const std::string& resourceType, int amount) {
    if (resourceType == "wood") wood = std::max(0, wood - amount);
    else if (resourceType == "steel") steel = std::max(0, steel - amount);
    else if (resourceType == "concrete") concrete = std::max(0, concrete - amount);
    else if (resourceType == "waterSupply") waterSupply = std::max(0, waterSupply - amount);
    else if (resourceType == "energySupply") energySupply = std::max(0, energySupply - amount);
}

void Resources::addBudget(int amount) {
    budget += amount;
}

void Resources::spendBudget(int amount) {
    budget = std::max(0, budget - amount);
}