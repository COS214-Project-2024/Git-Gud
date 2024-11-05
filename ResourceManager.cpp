#include "ResourceManager.h"
#include <iostream>

ResourceManager* ResourceManager::instance = nullptr;

ResourceManager::ResourceManager() {
    resources.setBudget(startingBudget);
}

ResourceManager* ResourceManager::getInstance() {
    if (!instance) {
        instance = new ResourceManager();
    }

    return instance;
}

void ResourceManager::resetInstance() {
    delete instance;
    instance = new ResourceManager();  // Reset to default starting values
    std::cout << "ResourceManager reset." << std::endl;
}

bool ResourceManager::sufficientMaterials(int water, int steel, int concrete, int wood, int power) const {
    return resources.getWaterSupplyResource().getAmount() >= water &&
           resources.getSteelResource().getAmount() >= steel &&
           resources.getConcreteResource().getAmount() >= concrete &&
           resources.getWoodResource().getAmount() >= wood &&
           resources.getEnergySupplyResource().getAmount() >= power &&
           resources.getWasteCapacityResource().getAmount() >= 0;
}

void ResourceManager::initializeResources(int water, int steel, int concrete, int wood) {
    resources.setWaterSupply(water);
    resources.setSteel(steel);
    resources.setConcrete(concrete);
    resources.setWood(wood);
}

void ResourceManager::addResource(const std::string& resourceType, int amount) {
    if (resourceType == "wood") resources.getWoodResource().addAmount(amount);
    else if (resourceType == "steel") resources.getSteelResource().addAmount(amount);
    else if (resourceType == "concrete") resources.getConcreteResource().addAmount(amount);
    else if (resourceType == "waterSupply") resources.getWaterSupplyResource().addAmount(amount);
    else if (resourceType == "energySupply") resources.getEnergySupplyResource().addAmount(amount);
    else if (resourceType == "budget") resources.getBudgetResource().addAmount(amount);
    else if (resourceType == "wasteCapacity") resources.getWasteCapacityResource().addAmount(amount);
}

void ResourceManager::useResource(const std::string& resourceType, int amount) {
    if (resourceType == "wood") resources.getWoodResource().subtractAmount(amount);
    else if (resourceType == "steel") resources.getSteelResource().subtractAmount(amount);
    else if (resourceType == "concrete") resources.getConcreteResource().subtractAmount(amount);
    else if (resourceType == "waterSupply") resources.getWaterSupplyResource().subtractAmount(amount);
    else if (resourceType == "energySupply") resources.getEnergySupplyResource().subtractAmount(amount);
    else if (resourceType == "budget") resources.getBudgetResource().subtractAmount(amount);
    else if (resourceType == "wasteCapacity") resources.getWasteCapacityResource().subtractAmount(amount);
}

void ResourceManager::addBudget(int amount) {
    resources.getBudgetResource().addAmount(amount);
}

void ResourceManager::spendBudget(int amount) {
    resources.getBudgetResource().subtractAmount(amount);
}

// Getters
int ResourceManager::getWood() const { return resources.getWoodResource().getAmount(); }
int ResourceManager::getSteel() const { return resources.getSteelResource().getAmount(); }
int ResourceManager::getConcrete() const { return resources.getConcreteResource().getAmount(); }
int ResourceManager::getBudget() const { return resources.getBudgetResource().getAmount(); }
int ResourceManager::getWaterSupply() const { return resources.getWaterSupplyResource().getAmount(); }
int ResourceManager::getEnergySupply() const { return resources.getEnergySupplyResource().getAmount(); }
int ResourceManager::getWasteCapacity() const { return resources.getWasteCapacityResource().getAmount(); }