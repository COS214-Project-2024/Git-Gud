#include "ResourceManager.h"

ResourceManager* ResourceManager::instance = nullptr;

ResourceManager::ResourceManager() : energySupply(0), waterSupply(0), cityBudget(0) {}

ResourceManager* ResourceManager::getInstance() {
    if (!instance) {
        instance = new ResourceManager();
    }
    return instance;
}

bool ResourceManager::sufficientMaterials(int water, int steel, int concrete, int wood, int power) const {
    return resources.getWater() >= water &&
           resources.getSteel() >= steel &&
           resources.getConcrete() >= concrete &&
           resources.getWood() >= wood &&
           energySupply >= power;
}

void ResourceManager::useResources(int water, int steel, int concrete, int wood, int power) {
    resources.useWater(water);
    resources.useSteel(steel);
    resources.useConcrete(concrete);
    resources.useWood(wood);
    energySupply -= power;
}

void ResourceManager::addResources(int water, int steel, int concrete, int wood) {
    resources.addWater(water);
    resources.addSteel(steel);
    resources.addConcrete(concrete);
    resources.addWood(wood);
}

void ResourceManager::addEnergy(int amount) {
    energySupply += amount;
}

void ResourceManager::addWater(int amount) {
    waterSupply += amount;
}

void ResourceManager::addBudget(int amount) {
    cityBudget += amount;
}

void ResourceManager::spendBudget(int amount) {
    cityBudget -= amount;
}

int ResourceManager::getEnergySupply() const {
    return energySupply;
}

int ResourceManager::getWaterSupply() const {
    return waterSupply;
}

int ResourceManager::getCityBudget() const {
    return cityBudget;
}

int ResourceManager::getWood() const {
    return resources.getWood();
}

int ResourceManager::getSteel() const {
    return resources.getSteel();
}

int ResourceManager::getConcrete() const {
    return resources.getConcrete();
}

int ResourceManager::getBudget() const {
    return cityBudget;
}