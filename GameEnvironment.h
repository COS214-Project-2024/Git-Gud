#ifndef GAMEENVIRONMENT_H
#define GAMEENVIRONMENT_H

#include "Utility.h"
#include "Citizen.h"
#include "Building.h"
#include "UtilityIterator.h"
#include "BuildingIterator.h"
#include <vector>

class Building;

class GameEnvironment
{
private:
    Utility*** utilityGrid;
    Building*** buildingGrid;
    std::vector <Citizen*> Citizens;
    int rows, cols;
public:
    void addUtility(Utility* utility, int x, int y);
    void addBuilding(Building* building, int x, int y);
    void remove();
    void PrintToTerminal();
    void PrintToFIle();
    UtilityIterator* createUtilityIterator();
    BuildingIterator* createBuildingIterator();

    friend Building;
};

#endif // GAMEENVIRONMENT_H