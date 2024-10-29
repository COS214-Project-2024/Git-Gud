#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "Resources.h"
#include <string>

class ResourceManager {
private:
    static ResourceManager* instance; // Singleton instance
    ResourceManager(); // Private constructor

    Resources resources; // Manages individual resources
    const int startingBudget = 500000;

public:
    static ResourceManager* getInstance();

    // Reset instance for testing
    static void resetInstance();

    bool sufficientMaterials(int water, int steel, int concrete, int wood, int power) const;

    // Resource modification methods
    void initializeResources(int water, int steel, int concrete, int wood);
    void addResource(const std::string& resourceType, int amount);
    void useResource(const std::string& resourceType, int amount);

    // Specific methods for budget
    void addBudget(int amount);
    void spendBudget(int amount);

    // Getters
    int getWood() const;
    int getSteel() const;
    int getConcrete() const;
    int getBudget() const;
    int getWaterSupply() const;
    int getEnergySupply() const;
    int getWasteCapacity() const;
};

#endif // RESOURCEMANAGER_H