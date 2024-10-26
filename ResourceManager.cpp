#include "ResourceManager.h"
#include <iostream>

ResourceManager* ResourceManager::instance = nullptr;

ResourceManager::ResourceManager() {
    resources.addBudget(startingBudget);
    resources.addResource("wood", 0);
    resources.addResource("steel", 0);
    resources.addResource("concrete", 0);
    resources.addResource("waterSupply", 0);
    resources.addResource("energySupply", 0);
}

ResourceManager* ResourceManager::getInstance() {
    if (!instance) {
        instance = new ResourceManager();
    }
    return instance;
}

void ResourceManager::resetInstance() {
    delete instance;
    instance = new ResourceManager();
}

void ResourceManager::initializeResources(int water, int steel, int concrete, int wood) {
    resources.addResource("waterSupply", water);
    resources.addResource("steel", steel);
    resources.addResource("concrete", concrete);
    resources.addResource("wood", wood);
}

void ResourceManager::addResource(const std::string& resourceType, int amount) {
    resources.addResource(resourceType, amount);
}

void ResourceManager::useResource(const std::string& resourceType, int amount) {
    resources.useResource(resourceType, amount);
}

bool ResourceManager::sufficientMaterials(int water, int steel, int concrete, int wood, int power) const {
    return resources.getWaterSupply() >= water &&
           resources.getSteel() >= steel &&
           resources.getConcrete() >= concrete &&
           resources.getWood() >= wood &&
           resources.getEnergySupply() >= power;
}

// Remaining methods as needed, such as addBudget, spendBudget, and getters
void ResourceManager::addBudget(int amount) {
    resources.addBudget(amount);
}

void ResourceManager::spendBudget(int amount) {
    resources.spendBudget(amount);
}

// Getters delegate to Resources
int ResourceManager::getWood() const { return resources.getWood(); }
int ResourceManager::getSteel() const { return resources.getSteel(); }
int ResourceManager::getConcrete() const { return resources.getConcrete(); }
int ResourceManager::getBudget() const { return resources.getBudget(); }
int ResourceManager::getWaterSupply() const { return resources.getWaterSupply(); }
int ResourceManager::getEnergySupply() const { return resources.getEnergySupply(); }