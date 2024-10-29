#ifndef RESOURCES_H
#define RESOURCES_H

#include "Wood.h"
#include "Steel.h"
#include "Concrete.h"
#include "WaterSupply.h"
#include "EnergySupply.h"
#include "Budget.h"
#include "WasteCapacity.h"

class Resources {
private:
    Wood wood;
    Steel steel;
    Concrete concrete;
    WaterSupply waterSupply;
    EnergySupply energySupply;
    Budget budget;
    WasteCapacity wasteCapacity;

public:
    Resources(int w = 0, int s = 0, int c = 0, int ws = 0, int es = 0, int b = 0, int wc = 0)
        : wood(w), steel(s), concrete(c), waterSupply(ws), energySupply(es), budget(b), wasteCapacity(wc) {}

    // Non-const and const getters for individual resources
    Wood& getWoodResource() { return wood; }
    Steel& getSteelResource() { return steel; }
    Concrete& getConcreteResource() { return concrete; }
    WaterSupply& getWaterSupplyResource() { return waterSupply; }
    EnergySupply& getEnergySupplyResource() { return energySupply; }
    Budget& getBudgetResource() { return budget; }
    WasteCapacity& getWasteCapacityResource() { return wasteCapacity; }

    const Wood& getWoodResource() const { return wood; }
    const Steel& getSteelResource() const { return steel; }
    const Concrete& getConcreteResource() const { return concrete; }
    const WaterSupply& getWaterSupplyResource() const { return waterSupply; }
    const EnergySupply& getEnergySupplyResource() const { return energySupply; }
    const Budget& getBudgetResource() const { return budget; }
    const WasteCapacity& getWasteCapacityResource() const { return wasteCapacity; }

    // Setters for initial values
    void setWood(int amount) { wood.setAmount(amount); }
    void setSteel(int amount) { steel.setAmount(amount); }
    void setConcrete(int amount) { concrete.setAmount(amount); }
    void setWaterSupply(int amount) { waterSupply.setAmount(amount); }
    void setEnergySupply(int amount) { energySupply.setAmount(amount); }
    void setBudget(int amount) { budget.setAmount(amount); }
    void setWasteCapacity(int amount) { wasteCapacity.setAmount(amount); }
};

#endif // RESOURCES_H