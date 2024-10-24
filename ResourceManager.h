#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

class ResourceManager {
    private:
        ResourceManager();

        static ResourceManager* instance; // Singleton instance
        int ResourceManager;
        int energySupply;
        int waterSupply;
        int cityBudget;
    public:
        static ResourceManager* getInstance();

        // Resource management methods
        void manageMaterials();  // Placeholder for managing construction materials
        void distributeEnergy(); // Distributes energy to buildings
        void manageWaterSupply(); // Manages the water supply
        void manageBudget();     // Handles the city budget

        // Getter methods for the resource attributes so that buildings can see if there is enough resources to meet their demand
        int getEnergySupply() const;
        int getWaterSupply() const;
        int getCityBudget() const;

        // Setter methods to update the resource values, e.g. for when new power plants get placed
        void setEnergySupply(int newEnergySupply);
        void setWaterSupply(int newWaterSupply);
        void setCityBudget(int newCityBudget);
}

#endif // RESOURCEMANAGER_H