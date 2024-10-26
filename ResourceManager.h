#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "Resources.h"

class ResourceManager {
private:
    static ResourceManager* instance; // Singleton instance
    ResourceManager(); // Private constructor

    int energySupply;
    int waterSupply;
    int cityBudget;

    Resources resources; // Instance of Resources to manage the resource values

public:
    // Singleton instance getter
    static ResourceManager* getInstance();

    // Check if there are sufficient materials available
    bool sufficientMaterials(int water, int steel, int concrete, int wood, int power) const;

    // Methods to use and add resources
    void useResources(int water, int steel, int concrete, int wood, int power);
    void addResources(int water, int steel, int concrete, int wood);

    // Specific methods for energy, water, and budget
    void addEnergy(int amount);
    void addWater(int amount);
    void addBudget(int amount);
    void spendBudget(int amount);

    // Getters for main resources
    int getEnergySupply() const;
    int getWaterSupply() const;
    int getCityBudget() const;
    
    // Getters for Resources
    int getWood() const;
    int getSteel() const;
    int getConcrete() const;
    int getBudget() const;
};

#endif // RESOURCEMANAGER_H