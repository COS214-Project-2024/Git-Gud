#ifndef GAMEENVIRONMENT_H
#define GAMEENVIRONMENT_H

#include <iostream>
#include <fstream>
#include <vector>
#include "UtilityGridNode.h"
#include "Building.h"
/* #include "ConcreteIterators.h"
#include "RadialIterator.h"
#include "LinearIterator.h" */
using namespace std;
//placeholder
class Utility;
//forward declarations for actual utility
//class Iterator;

class GameEnvironment {
private:
    Building*** buildingGrid;
    UtilGridNode*** utilityGrid;
    friend class Iterator;
    friend class Building;

    int rows, cols;
    int startingPoint[2];//Starting point of the map shal be offramp at the centre. The centre point changes with the size of the map. Intially it is set to 25,25
    void resizeGrid(int newRows, int newCols, string direction)
    {
        ///////Determine offset
        int rowOffset = 0;
        int colOffset = 0;

        if (direction == "North")
        {
            rowOffset = newRows - rows;
        }
        else if (direction == "South")
        {
            rowOffset = 0;
        }
        else if (direction == "West")
        {
            colOffset = newCols - cols;
        }
        else if (direction == "East")
        {
            colOffset = 0;
        }
        ///////Allocate new grids
        Building*** newBuildingGrid = new Building**[newRows];
        UtilGridNode*** newUtilityGrid = new UtilGridNode**[newRows];

        for (int i = 0; i < newRows; i++)
        {
            newBuildingGrid[i] = new Building*[newCols];
            newUtilityGrid[i] = new UtilGridNode*[newCols];
            for (int j = 0; j < newCols; j++)
            {
                newBuildingGrid[i][j] = nullptr;
                newUtilityGrid[i][j] = nullptr;
            }
        }
        ///////Translate old grid to new grid
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                newBuildingGrid[i + rowOffset][j + colOffset] = buildingGrid[i][j];
                newUtilityGrid[i + rowOffset][j + colOffset] = utilityGrid[i][j];
            }
        }
        ///////Delete old grid
        for (int i = 0; i < rows; i++)
        {
            delete[] buildingGrid[i];
            delete[] utilityGrid[i];
        }

        delete[] buildingGrid;
        delete[] utilityGrid;
        ///////Update member variables
        buildingGrid = newBuildingGrid;
        utilityGrid = newUtilityGrid;
        rows = newRows;
        cols = newCols;
        startingPoint[0] += rowOffset;
        startingPoint[1] += colOffset;
    };

    void checkCoherence(int x, int y)
    {
        if (x < 0) resizeGrid(rows, cols*1.1, "West");
        if (x >= cols) resizeGrid(rows, cols*1.1, "East");
        if (y < 0) resizeGrid(rows*1.1, cols, "North");
        if (y >= rows) resizeGrid(rows*1.1, cols, "South");
    };

    bool adjToRoad(int x, int y)
    {
        if ((x+1<cols && (utilityGrid[y][x+1]!=nullptr) && utilityGrid[y][x+1]->getHasRoad())
        ||(x-1>=0 && (utilityGrid[y][x-1]!=nullptr) && utilityGrid[y][x-1]->getHasRoad())
        ||(y+1<rows && (utilityGrid[y+1][x]!=nullptr) && utilityGrid[y+1][x]->getHasRoad())
        ||(y-1>=0 && (utilityGrid[y-1][x]!=nullptr) && utilityGrid[y-1][x]->getHasRoad())
        ||(x+1<cols && y+1<rows && (utilityGrid[y+1][x+1]!=nullptr) && utilityGrid[y+1][x+1]->getHasRoad())
        ||(x-1>=0 && y-1>=0 && (utilityGrid[y-1][x-1]!=nullptr) && utilityGrid[y-1][x-1]->getHasRoad())
        ||(x+1<cols && y-1>=0 && (utilityGrid[y-1][x+1]!=nullptr) && utilityGrid[y-1][x+1]->getHasRoad())
        ||(x-1>=0 && y+1<rows && (utilityGrid[y+1][x-1]!=nullptr) && utilityGrid[y+1][x-1]->getHasRoad()))
        {
            return true;
        }
        return false;
    };
public:
    GameEnvironment()
    {
        rows = 50;
        cols = 50;
        //instantiate empty grids
        buildingGrid = new Building**[rows];
        utilityGrid = new UtilGridNode**[rows];
        for (int i = 0; i < rows; i++) {
            buildingGrid[i] = new Building*[cols];
            utilityGrid[i] = new UtilGridNode*[cols];
            for (int j = 0; j < cols; j++) {
                buildingGrid[i][j] = nullptr;
                utilityGrid[i][j] = nullptr;
            }
        }
        //set starting point
        startingPoint[0] = 24;
        startingPoint[1] = 24;
                                                //REMINDER: PULL UTILITIES AND BUILDINGS
        //create road at starting point
        utilityGrid[startingPoint[0]][startingPoint[1]] = new UtilGridNode();
        utilityGrid[startingPoint[0]][startingPoint[1]]->createRoad();   

    };

    ~GameEnvironment()
    {
        //delete buildingGrid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (buildingGrid[i][j] != nullptr) {
                    delete buildingGrid[i][j];
                }
            }
            delete[] buildingGrid[i];
        }
        delete[] buildingGrid;
        //delete utilityGrid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (utilityGrid[i][j] != nullptr) {
                    delete utilityGrid[i][j];
                }
            }
            delete[] utilityGrid[i];
        }
        delete[] utilityGrid;
    };

    bool add(Building* building, int x, int y)
    {
        //receive coordinates, interpret them as row and column
        //check if coordinates are within bounds and translate
        checkCoherence(x, y);
        //check if building already exists at coordinates
        if (buildingGrid[y][x] != nullptr || !adjToRoad(x,y)) {
            return false;
        }
        buildingGrid[y][x] = building;
        return true;
    };

    bool add(Utility* utility, int x, int y){
        //receive coordinates, interpret them as row and column
        checkCoherence(x, y);
        //check if grid node already exists at coordinates
        if (utilityGrid[y][x] == nullptr) {
            utilityGrid[y][x] = new UtilGridNode();
        }
        utilityGrid[y][x]->add(utility);
        return true;
    };

    bool remove(int x, int y, string type="unspecified"){
        //receive coordinates, interpret them as row and column
        //if type is unspecified, remove building
        if (type == "unspecified") {
            if (buildingGrid[y][x] != nullptr) {
                delete buildingGrid[y][x];
                buildingGrid[y][x] = nullptr;
                return true;
            }
            
            return false;
        }
        //Type specified, remove remove specific utility
        if (utilityGrid[y][x] != nullptr) {
            if (utilityGrid[y][x]->remove(type)) {
                return true;
            }
        }
        return false;
    };
    
    void printTerminal(){//basic implementation for demonstration purposes
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (buildingGrid[i][j] != nullptr) {
                    cout << "B";
                }
                else if (utilityGrid[i][j] != nullptr) {
                    cout << "U";
                }
                else {
                    cout << ".";
                }
            }
            cout << endl;
        }
    };
    
    void printToFile(string filename="map.txt"){
        ofstream file;
        file.open(filename);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (buildingGrid[i][j] != nullptr) {
                    file << "B";
                }
                else if (utilityGrid[i][j] != nullptr) {
                    file << "U";
                }
                else {
                    file << ".";
                }
            }
            file << endl;
        }
        file.close();
    };
    
    void createRoad(int x, int y){

        checkCoherence(x, y);

        if (utilityGrid[y][x] == nullptr) {
            utilityGrid[y][x] = new UtilGridNode();
        }
        utilityGrid[y][x]->createRoad();
    };
    
    /* RadialBuildingIterator* createRadBuildIt(int x, int y, int radius);
    RadialUtilityIterator* createRadUtilIt(int x, int y, int radius);
    UtilityIterator* createUtilIt();
    BuildingIterator* createBuildIt(); */

    

};

#endif // GAMEENVIRONMENT_H