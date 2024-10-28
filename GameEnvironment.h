#ifndef GAMEENVIRONMENT_H
#define GAMEENVIRONMENT_H

#include <iostream>
#include <fstream>
#include "UtilityGridNode.h"
using namespace std;
//placeholder
class Utility;
class Building;
//forward declarations for actual utility
class Iterator;

class GameEnvironment {
private:
    Building*** buildingGrid;
    UtilGridNode*** utilityGrid;
    friend class Iterator;

    int rows, cols;
    int startingPoint[2];//Starting point of the map shal be offramp at the centre. The centre point changes with the size of the map. Intially it is set to 25,25
    void resizeGrid(int newRows, int newCols, string direction);

public:
    GameEnvironment();
    ~GameEnvironment();

    bool add(Building* building, int x, int y);
    bool add(Utility* utility, int x, int y);
    bool remove(int x, int y, string type="unspecified");
    void printTerminal();
    void printToFile(string filename="map.txt");
    void createRoad(int x, int y);
    

};

#endif // GAMEENVIRONMENT_H