#include "Resources.h"

Resources::Resources(int w, int s, int c, int b, int ws, int es)
    : wood(w), steel(s), concrete(c), budget(b), waterSupply(ws), energySupply(es) {}

// Getters
int Resources::getWood() const {
    return wood;
}

int Resources::getSteel() const {
    return steel;
}

int Resources::getConcrete() const {
    return concrete;
}

int Resources::getBudget() const {
    return budget;
}

int Resources::getWaterSupply() const {
    return waterSupply;
}

int Resources::getEnergySupply() const {
    return energySupply;
}

// Add methods
void Resources::addWood(int amount) {
    wood += amount;
}

void Resources::addSteel(int amount) {
    steel += amount;
}

void Resources::addConcrete(int amount) {
    concrete += amount;
}

void Resources::addBudget(int amount) {
    budget += amount;
}

void Resources::addWaterSupply(int amount) {
    waterSupply += amount;
}

void Resources::addEnergySupply(int amount) {
    energySupply += amount;
}

// Use methods with checks to prevent negative values
void Resources::useWood(int amount) {
    if (wood >= amount) {
        wood -= amount;
    } else {
        wood = 0;
    }
}

void Resources::useSteel(int amount) {
    if (steel >= amount) {
        steel -= amount;
    } else {
        steel = 0;
    }
}

void Resources::useConcrete(int amount) {
    if (concrete >= amount) {
        concrete -= amount;
    } else {
        concrete = 0;
    }
}

void Resources::spendBudget(int amount) {
    if (budget >= amount) {
        budget -= amount;
    } else {
        budget = 0;
    }
}

void Resources::useWaterSupply(int amount) {
    if (waterSupply >= amount) {
        waterSupply -= amount;
    } else {
        waterSupply = 0;
    }
}

void Resources::useEnergySupply(int amount) {
    if (energySupply >= amount) {
        energySupply -= amount;
    } else {
        energySupply = 0;
    }
}