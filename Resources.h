#ifndef RESOURCES_H
#define RESOURCES_H

class Resources {
private:
    int wood;
    int steel;
    int concrete;
    int budget;

public:
    Resources(int w = 0, int s = 0, int c = 0, int b = 0);

    // Getters
    int getWood() const;
    int getSteel() const;
    int getConcrete() const;
    int getBudget() const;

    // Methods to add resources
    void addWood(int amount);
    void addSteel(int amount);
    void addConcrete(int amount);
    void addBudget(int amount);

    // Methods to use resources
    void useWood(int amount);
    void useSteel(int amount);
    void useConcrete(int amount);
    void spendBudget(int amount);
};

#endif // RESOURCES_H