#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

class ResourceManager
{
private:
    ResourceManager* instance;
    int ResourceManagerID;
    int energySupply;
    int waterSupply;
    int cityBudget;
public:
    ResourceManager();
    ResourceManager* getInstance();
    void manageMeterials();
    void distributeEnergy();
    void manageWaterSupply();
    void manageCityBudget();
};


#endif // RESOURCEMANAGER_H