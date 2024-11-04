#ifndef GAMEENVIRONMENT_H
#define GAMEENVIRONMENT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include "UtilityGridNode.h"
#include "IndustrialBuilding.h"
#include "CommercialBuilding.h"
#include "ResidentialBuilding.h"
#include "Landmark.h"
#include "BuildingIterator.h"
#include "BuildingIteratorLinear.h"
#include "BuildingIteratorRadial.h"
#include "UtilityIterator.h"
#include "UtilityIteratorLinear.h"
#include "UtilityIteratorRadial.h"
//#include "Player.h"
//#include "Utility.h"

using namespace std;


class GameEnvironment {
private:
    Building*** buildingGrid;
    UtilGridNode*** utilityGrid;
    int rows, cols;
    int startingPoint[2]; // Center of the map as the initial off-ramp

    void resizeGrid(int newRows, int newCols, string direction) {
        // Calculate the offset for grid translation
        int rowOffset = (direction == "North") ? newRows - rows : 0;
        int colOffset = (direction == "West") ? newCols - cols : 0;

        // Allocate new grids
        Building*** newBuildingGrid = new Building**[newRows];
        UtilGridNode*** newUtilityGrid = new UtilGridNode**[newRows];

        for (int i = 0; i < newRows; i++) {
            newBuildingGrid[i] = new Building*[newCols];
            newUtilityGrid[i] = new UtilGridNode*[newCols];
            for (int j = 0; j < newCols; j++) {
                newBuildingGrid[i][j] = nullptr;
                newUtilityGrid[i][j] = nullptr;
            }
        }

        // Transfer existing grid data to the new grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i + rowOffset >= 0 && j + colOffset >= 0 && i + rowOffset < newRows && j + colOffset < newCols) {
                    newBuildingGrid[i + rowOffset][j + colOffset] = buildingGrid[i][j];
                    newUtilityGrid[i + rowOffset][j + colOffset] = utilityGrid[i][j];
                }
            }
        }

        // Free the memory of the old grids
        for (int i = 0; i < rows; i++) {
            delete[] buildingGrid[i];
            delete[] utilityGrid[i];
        }
        delete[] buildingGrid;
        delete[] utilityGrid;

        // Update member variables
        buildingGrid = newBuildingGrid;
        utilityGrid = newUtilityGrid;
        rows = newRows;
        cols = newCols;
        startingPoint[0] += rowOffset;
        startingPoint[1] += colOffset;
    }

    void checkCoherence(int &x, int &y) {
        int temp;
        if (x < 0) {
            temp = cols;
            resizeGrid(rows, cols * 1.1, "West");
            x += (cols - temp);
        }
        if (x >= cols) resizeGrid(rows, cols * 1.1, "East");
        if (y < 0) {
            temp = rows;
            resizeGrid(rows * 1.1, cols, "North");
            y += (rows - temp);
        }
        if (y >= rows) resizeGrid(rows * 1.1, cols, "South");
    }

    bool adjToRoad(int x, int y) {
        return ((x + 1 < cols && utilityGrid[y][x + 1] && utilityGrid[y][x + 1]->getHasRoad()) ||
                (x - 1 >= 0 && utilityGrid[y][x - 1] && utilityGrid[y][x - 1]->getHasRoad()) ||
                (y + 1 < rows && utilityGrid[y + 1][x] && utilityGrid[y + 1][x]->getHasRoad()) ||
                (y - 1 >= 0 && utilityGrid[y - 1][x] && utilityGrid[y - 1][x]->getHasRoad()) ||
                (x + 1 < cols && y + 1 < rows && utilityGrid[y + 1][x + 1] && utilityGrid[y + 1][x + 1]->getHasRoad()) ||
                (x - 1 >= 0 && y - 1 >= 0 && utilityGrid[y - 1][x - 1] && utilityGrid[y - 1][x - 1]->getHasRoad()) ||
                (x + 1 < cols && y - 1 >= 0 && utilityGrid[y - 1][x + 1] && utilityGrid[y - 1][x + 1]->getHasRoad()) ||
                (x - 1 >= 0 && y + 1 < rows && utilityGrid[y + 1][x - 1] && utilityGrid[y + 1][x - 1]->getHasRoad()));
    }

public:
    GameEnvironment() : rows(50), cols(50) {
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
        startingPoint[0] = 24;
        startingPoint[1] = 24;
        utilityGrid[startingPoint[0]][startingPoint[1]] = new UtilGridNode();
        utilityGrid[startingPoint[0]][startingPoint[1]]->createRoad();
    }

    ~GameEnvironment() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                delete buildingGrid[i][j];
                delete utilityGrid[i][j];
            }
            delete[] buildingGrid[i];
            delete[] utilityGrid[i];
        }
        delete[] buildingGrid;
        delete[] utilityGrid;
    }

    int getRows() { return rows; }
    int getCols() { return cols; }

    bool add(Building* building, int x, int y) {
        checkCoherence(x, y);
        if (buildingGrid[y][x] || !adjToRoad(x, y)) {
            return false;
        }
        buildingGrid[y][x] = building;
        return true;
    }

    bool add(Utility* utility, int x, int y) {
        checkCoherence(x, y);
        if (!utilityGrid[y][x]) {
            utilityGrid[y][x] = new UtilGridNode();
        }
        return utilityGrid[y][x]->add(utility);
    }

    bool remove(int x, int y, string type = "unspecified") {
        if (x < 0 || x >= cols || y < 0 || y >= rows) {
            return false;
        }
        if (type == "unspecified") {
            if (buildingGrid[y][x]) {
                delete buildingGrid[y][x];
                buildingGrid[y][x] = nullptr;
                return true;
            }
            return false;
        }
        return utilityGrid[y][x] && utilityGrid[y][x]->remove(type);
    }

    bool decouple(int x, int y) {
        if (x < 0 || x >= cols || y < 0 || y >= rows) {
            return false;
        }
        if (buildingGrid[y][x]) {
            buildingGrid[y][x] = nullptr;
            return true;
        }
        return false;
    }

    void printTerminal() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << (buildingGrid[i][j] ? "B" : (utilityGrid[i][j] ? "U" : "."));
            }
            cout << endl;
        }
    }

    void printToFile(string filename = "map.txt") {
        ofstream file(filename);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                file << (buildingGrid[i][j] ? "B" : (utilityGrid[i][j] ? "U" : "."));
            }
            file << endl;
        }
        file.close();
    }

    void createRoad(int x, int y) {
        checkCoherence(x, y);
        if (!utilityGrid[y][x]) {
            utilityGrid[y][x] = new UtilGridNode();
        }
        utilityGrid[y][x]->createRoad();
    }

    BuildingIteratorRadial* createRadBuildItr(int x, int y, int radius) {
        return new BuildingIteratorRadial(x, y, radius, buildingGrid, rows, cols);
    };

    BuildingIteratorLinear* createLinBuildItr() {
        return new BuildingIteratorLinear(buildingGrid, rows, cols);
    };

    UtilityIteratorRadial* createRadUtilItr(int x, int y, int radius) {
        return new UtilityIteratorRadial(utilityGrid, x, y, radius, rows, cols);
    };

    UtilityIteratorLinear* createLinUtilItr() {
        return new UtilityIteratorLinear(utilityGrid, rows, cols);
    };
};


#endif // GAMEENVIRONMENT_H