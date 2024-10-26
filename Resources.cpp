#include "Resources.h"

Resources::Resources(int w, int s, int c, int b) : wood(w), steel(s), concrete(c), budget(b) {}

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

void Resources::useWood(int amount) {
    wood -= amount;
}

void Resources::useSteel(int amount) {
    steel -= amount;
}

void Resources::useConcrete(int amount) {
    concrete -= amount;
}

void Resources::spendBudget(int amount) {
    budget -= amount;
}