#ifndef RESOURCES_H
#define RESOURCES_H

class Resources {
private:
    int wood;
    int steel;
    int concrete;
    int budget;
    int waterSupply;
    int energySupply;

public:
    Resources(int w = 0, int s = 0, int c = 0, int b = 0, int ws = 0, int es = 0);

    // Getters
    int getWood() const;
    int getSteel() const;
    int getConcrete() const;
    int getBudget() const;
    int getWaterSupply() const;
    int getEnergySupply() const;

    // Setters for direct initialization
    void setWood(int amount) { wood = amount; }
    void setSteel(int amount) { steel = amount; }
    void setConcrete(int amount) { concrete = amount; }
    void setWaterSupply(int amount) { waterSupply = amount; }

    // Methods to add resources
    void addWood(int amount);
    void addSteel(int amount);
    void addConcrete(int amount);
    void addBudget(int amount);
    void addWaterSupply(int amount);
    void addEnergySupply(int amount);

    // Methods to use resources
    void useWood(int amount);
    void useSteel(int amount);
    void useConcrete(int amount);
    void spendBudget(int amount);
    void useWaterSupply(int amount);
    void useEnergySupply(int amount);
};

#endif // RESOURCES_H