#include "ResourceManager.h"

ResourceManager* ResourceManager::instance = nullptr;

ResourceManager::ResourceManager() : energySupply(0), waterSupply(0), cityBudget(0);

// Public method to access the singleton instance
ResourceManager* ResourceManager::getInstance() {
    if (instance == nullptr) {
        instance = new ResourceManager();
    }

    return instance;
}

void ResourceManager::manageMaterials() {
    // Logic to manage construction materials like wood, steel, cement, etc.
}

void ResourceManager::distributeEnergy() {
    // Not sure as to how energy distribution would work yet
}

void ResourceManager::manageBudget() {
    // Logic to handle budget allocation
}

int ResourceManager::getEnergySupply() const {
    return energySupply;
}

void ResourceManager::setEnergySupply(int newEnergySupply) {
    energySupply = newEnergySupply;
}

int ResourceManager::getWaterSupply() const {
    return waterSupply;
}

void ResourceManager::setWaterSupply(int newWaterSupply) {
    waterSupply = newWaterSupply;
}

int ResourceManager::getCityBudget() const {
    return cityBudget;
}

void ResourceManager::setCityBudget(int newCityBudget) {
    cityBudget = newCityBudget;
}