#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <string>
#include <memory>
#include "Resource.h"
#include "Power.h"
#include "Water.h"
#include "Steel.h"
#include "Wood.h"
#include "Concrete.h"
#include "Budget.h"

class ResourceManager {
    private:
        ResourceManager();

        static ResourceManager* instance; // Singleton instance

        int energySupply;
        int waterSupply;
        int cityBudget;

        // Map to store resources
        std::map<std::string, std::unique_ptr<Resource>> resources;

    public:
        // Singleton instance getter
        static ResourceManager* getInstance();

        // Method to initialize or add resources to the map
        void initializeResource(const std::string& resourceType, int amount);

        // Check if there are sufficient materials available
        bool sufficientMaterials(int water, int steel, int concrete, int wood, int power) const;

        // Methods to update specific resources directly
        void useResources(int water, int steel, int concrete, int wood, int power);
        void addResource(const std::string& resourceType, int amount);

        // Specific methods for energy, water, and budget
        void addEnergy(int amount);
        void addWater(int amount);
        void addBudget(int amount);
        void spendBudget(int amount);

        // Getters for main resources
        int getEnergySupply() const;
        int getWaterSupply() const;
        int getCityBudget() const;
};

#endif // RESOURCEMANAGER_H