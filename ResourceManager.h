// ResourceManager.h
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "Resources.h"

class ResourceManager {
private:
    static ResourceManager* instance; // Singleton instance
    ResourceManager(); // Private constructor

    Resources resources; // Instance of Resources to manage all resource values
    const int startingBudget = 500000; // Define starting budget, adjust as needed

public:
    static ResourceManager* getInstance();

    // Method to reset the Singleton instance (for testing)
    static void resetInstance();

    bool sufficientMaterials(int water, int steel, int concrete, int wood, int power) const;

    void initializeResources(int water, int steel, int concrete, int wood);

    void useResources(int water, int steel, int concrete, int wood, int power);
    void addResources(int water, int steel, int concrete, int wood);

    void addEnergySupply(int amount);
    void addWaterSupply(int amount);
    void addBudget(int amount);
    void spendBudget(int amount);

    int getWood() const;
    int getSteel() const;
    int getConcrete() const;
    int getBudget() const;
    int getWaterSupply() const;
    int getEnergySupply() const;
};

#endif // RESOURCEMANAGER_H