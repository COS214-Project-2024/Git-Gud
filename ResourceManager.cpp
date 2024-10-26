#include "ResourceManager.h"
#include <iostream>

ResourceManager* ResourceManager::instance = nullptr;

ResourceManager::ResourceManager() {
    // Initialize all starting resource values here
    resources.addBudget(startingBudget); // Starting budget, e.g., 1000
    resources.addWaterSupply(0);         // Default starting value, adjust if needed
    resources.addEnergySupply(0);        // Default starting value, adjust if needed
    resources.addWood(0);                // Default starting value for wood
    resources.addSteel(0);               // Default starting value for steel
    resources.addConcrete(0);            // Default starting value for concrete
}

ResourceManager* ResourceManager::getInstance() {
    if (!instance) {
        instance = new ResourceManager();
    }

    return instance;
}

// Reset the singleton instance for testing
void ResourceManager::resetInstance() {
    delete instance;
    instance = new ResourceManager();  // Create new instance with starting budget
    std::cout << "ResourceManager reset." << std::endl;
}

// For initialization and testing:
void ResourceManager::initializeResources(int water, int steel, int concrete, int wood) {
    resources.setWaterSupply(water);
    resources.setSteel(steel);
    resources.setConcrete(concrete);
    resources.setWood(wood);
}

bool ResourceManager::sufficientMaterials(int water, int steel, int concrete, int wood, int power) const {
    return resources.getWaterSupply() >= water &&
           resources.getSteel() >= steel &&
           resources.getConcrete() >= concrete &&
           resources.getWood() >= wood &&
           resources.getEnergySupply() >= power;
}

void ResourceManager::useResources(int water, int steel, int concrete, int wood, int power) {
    resources.useWaterSupply(water);
    resources.useSteel(steel);
    resources.useConcrete(concrete);
    resources.useWood(wood);
    resources.useEnergySupply(power);

    // Debug output
    std::cout << "After addResources:\n"
              << "Wood: " << resources.getWood()
              << ", Steel: " << resources.getSteel()
              << ", Concrete: " << resources.getConcrete()
              << ", Water: " << resources.getWaterSupply()
              << ", Budget: " << resources.getBudget() << std::endl;
}

void ResourceManager::addResources(int water, int steel, int concrete, int wood) {
    resources.addWaterSupply(water);
    resources.addSteel(steel);
    resources.addConcrete(concrete);
    resources.addWood(wood);

    // Debug output
    std::cout << "After addResources:\n"
              << "Wood: " << resources.getWood()
              << ", Steel: " << resources.getSteel()
              << ", Concrete: " << resources.getConcrete()
              << ", Water: " << resources.getWaterSupply()
              << ", Budget: " << resources.getBudget() << std::endl;
}

// Delegated getters from Resources
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
    return resources.getBudget();
}

int ResourceManager::getWaterSupply() const {
    return resources.getWaterSupply();
}

int ResourceManager::getEnergySupply() const {
    return resources.getEnergySupply();
}

void ResourceManager::addWaterSupply(int amount) {
    resources.addWaterSupply(amount);
}

void ResourceManager::addEnergySupply(int amount) {
    resources.addEnergySupply(amount);
}

void ResourceManager::addBudget(int amount) {
    resources.addBudget(amount);
}

void ResourceManager::spendBudget(int amount) {
    resources.spendBudget(amount);
}