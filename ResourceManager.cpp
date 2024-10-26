#include "ResourceManager.h"

ResourceManager* ResourceManager::instance = nullptr;

ResourceManager::ResourceManager()
    : energySupply(0),  // Default value
      waterSupply(0),    // Default value
      cityBudget(100000)   // Default value
{
    resources["Steel"] = std::make_unique<Steel>(300);   // Example initial amount
    resources["Wood"] = std::make_unique<Wood>(200);
    resources["Concrete"] = std::make_unique<Concrete>(400);
}

// Public method to access the singleton instance
ResourceManager* ResourceManager::getInstance() {
    if (instance == nullptr) {
        instance = new ResourceManager();
    }

    return instance;
}

// Initialize or add a new resource type with an initial amount
void ResourceManager::initializeResource(const std::string& resourceType, int amount) {
    if (resources.find(resourceType) == resources.end()) {
        // If resource type doesn't exist, create it and add to map
        if (resourceType == "Steel") {
            resources[resourceType] = std::make_unique<Steel>(amount);
        } else if (resourceType == "Wood") {
            resources[resourceType] = std::make_unique<Wood>(amount);
        } else if (resourceType == "Concrete") {
            resources[resourceType] = std::make_unique<Concrete>(amount);
        } else if (resourceType == "Power") {
            resources[resourceType] = std::make_unique<Power>(amount);
        } else if (resourceType == "Water") {
            resources[resourceType] = std::make_unique<Water>(amount);
        } else if (resourceType == "Budget") {
            resources[resourceType] = std::make_unique<Budget>(amount);
        } else {
            throw std::invalid_argument("Unknown resource type.");
        }
    } else {
        // If resource exists, update its amount
        resources[resourceType]->increaseAmount(amount);
    }
}

// Get a specific resource
Resource* ResourceManager::getResource(const std::string& resourceType) const {
    if (resources.find(resourceType) != resources.end()) {
        return resources.at(resourceType).get();
    }

    return nullptr;
}

bool ResourceManager::sufficientMaterials(int water, int steel, int concrete, int wood, int power) const {
    return (waterSupply >= water &&
            resources.at("Steel")->getAvailableAmount() >= steel &&
            resources.at("Concrete")->getAvailableAmount() >= concrete &&
            resources.at("Wood")->getAvailableAmount() >= wood &&
            energySupply >= power);
}

void ResourceManager::useResources(int water, int steel, int concrete, int wood, int power) {
    if (sufficientMaterials(water, steel, concrete, wood, power)) {
        waterSupply -= water;
        energySupply -= power;
        resources["Steel"]->decreaseAmount(steel);
        resources["Concrete"]->decreaseAmount(concrete);
        resources["Wood"]->decreaseAmount(wood);
    } else {
        throw std::runtime_error("Insufficient resources for operation.");
    }
}

// Add to an existing resource
void ResourceManager::addResource(const std::string& resourceType, int amount) {
    if (resources.find(resourceType) != resources.end()) {
        resources[resourceType]->increaseAmount(amount);
    } else {
        throw std::invalid_argument("Resource type does not exist.");
    }
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
    if (cityBudget >= amount) {
        cityBudget -= amount;
    } else {
        throw std::runtime_error("Insufficient budget for operation.");
    }
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