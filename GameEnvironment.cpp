#include "GameEnvironment.h"



GameEnvironment::GameEnvironment() {
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
    startingPoint[0] = 25;
    startingPoint[1] = 25;
                                            //REMINDER: PULL UTILITIES AND BUILDINGS
    //create road at starting point
    utilityGrid[startingPoint[0]][startingPoint[1]] = new UtilGridNode();
    utilityGrid[startingPoint[0]][startingPoint[1]]->createRoad();   

}

GameEnvironment::~GameEnvironment() {
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
}

bool GameEnvironment::add(Building* building, int x, int y) {
    //receive coordinates, interpret them as row and column
    if (buildingGrid[y][x] != nullptr) {
        return false;
    }
    buildingGrid[y][x] = building;
    return true;
}

bool GameEnvironment::add(Utility* utility, int x, int y) {
    //receive coordinates, interpret them as row and column
    if (utilityGrid[y][x] == nullptr) {
        utilityGrid[y][x] = new UtilGridNode();
    }
    utilityGrid[y][x]->add(utility);
    return true;
}

bool GameEnvironment::remove(int x, int y, string type) {
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
}

void GameEnvironment::printTerminal() {//basic implementation for demonstration purposes
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
}

void GameEnvironment::printToFile(string filename) {
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
}


