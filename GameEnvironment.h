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
//#include "Player.h"
//#include "Utility.h"

using namespace std;

class BuildingIteratorRadial;
class BuildingIteratorLinear;
class UtilityIteratorRadial;
class UtilityIteratorLinear;


class GameEnvironment {
private:
    Building*** buildingGrid;
    UtilGridNode*** utilityGrid;

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

    void checkCoherence(int &x, int &y)
    {

        int temp;

        if (x < 0) 
        {
            temp = cols;
            resizeGrid(rows, cols*1.1, "West");
            x += (cols-temp);
        }
        if (x >= cols) resizeGrid(rows, cols*1.1, "East");
        if (y < 0) 
        {
            temp = rows;
            resizeGrid(rows*1.1, cols, "North");
            y += (rows-temp);
        }
        if (y >= rows) resizeGrid(rows*1.1, cols, "South");
    };

    friend class BuildingIteratorRadial;
    friend class BuildingIteratorLinear;
    friend class UtilityIteratorRadial;
    friend class UtilityIteratorLinear;

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

    int getRows()
    {
        return rows;
    };

    int getCols()
    {
        return cols;
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
        if (x < 0 || x >= cols || y < 0 || y >= rows) {
            return false;
        }
        
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
    
    BuildingIteratorRadial* createRadBuildItr(int x, int y, int radius);    

    BuildingIteratorLinear* createLinBuildItr();

    UtilityIteratorRadial* createRadUtilItr(int x, int y, int radius);

    UtilityIteratorLinear* createLinUtilItr();

};


struct Node {
    struct Point {
        int x, y;
    };

    Point point;
    Node* next;
};

class BuildingIterator {
    protected:
        GameEnvironment* game;
        Building*** array;
        int row, col;

    public:
        virtual bool hasNext()=0;
        virtual void next()=0;
        virtual Building* current() =0;
};

class BuildingIteratorRadial : public BuildingIterator {
    protected:
        int setRadius;
        int centerX, centerY;
        
        void calculatePoints()
        {
            int yUp, yDown;

            for (int r= 0; r <= setRadius; r++) {
                for (int x = centerX - r; x <= centerX + r; x++) {

                    if (x < 0 || x >= game->rows) {
                        continue;
                    }

                    yUp = sqrt(r*r - (x - centerX)*(x - centerX)) + centerY;
                    yDown = -sqrt(r*r - (x - centerX)*(x - centerX)) + centerY;
                    if (yUp >= 0 && yUp < game->rows && !contains(x, yUp) && this->array[x][yUp] != nullptr) {
                        Node* newNode = new Node;
                        newNode->point.x = x;
                        newNode->point.y = yUp;
                        newNode->next = head;
                        head = newNode;
                    }

                    if (yDown != yUp && yDown >= 0 && yDown < game->rows && !contains(x, yDown) && this->array[x][yDown] != nullptr) {
                        Node* newNode = new Node;
                        newNode->point.x = x;
                        newNode->point.y = yDown;
                        newNode->next = head;
                        head = newNode;
                    }
                }
            }            
        };

        bool contains(int x, int y)
        {
            Node* temp = head;
            while (temp != nullptr) {
                if (temp->point.x == x && temp->point.y == y) {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        };

        Node* head;

    public:
        BuildingIteratorRadial()
        {
            centerX = 0;
            centerY = 0;
            setRadius = 0;
        };

        ~BuildingIteratorRadial()
        {
            game = nullptr;
            array = nullptr;
        };

        BuildingIteratorRadial(GameEnvironment* game, int x, int y, int radius)
        {
            this->game = game;
            this->array = game->buildingGrid;
            centerX = x;
            centerY = y;
            setRadius = radius;
            head = nullptr;
            calculatePoints();
        };

        bool hasNext() override
        {
            if (head == nullptr) {
                return false;
            }
            return head->next != nullptr;
        };

        void next() override
        {   
            if (head == nullptr) {
                return;
            }
            Node* temp = head;
            head = head->next;
            delete temp;
        };

        Building* current() override
        {
            if (head == nullptr) {
                return nullptr;
            }
            return this->array[head->point.x][head->point.y];
        };
};

class BuildingIteratorLinear : public BuildingIterator {
    public:
        BuildingIteratorLinear(GameEnvironment* game)
        {
            this->game = game;
            this->array = game->buildingGrid;
            row = 0;
            col = 0;

            for (int i = 0; i < this->game->rows; i++) {
                for (int j = 0; j < this->game->cols; j++) {
                    if (this->array[i][j] != nullptr) {
                        row = i;
                        col = j;
                        return;
                    }
                }
            }
        };

        ~BuildingIteratorLinear()
        {
            game = nullptr;
            array = nullptr;
        };

        bool hasNext() override
        {

            if (row == -1 || col == -1) {
                return false;
            }

            int tempRow = row;
            int tempCol = col+1;
            while (tempRow < this->game->rows) {
                while (tempCol < this->game->cols) {
                    if (this->array[tempRow][tempCol] != nullptr) {
                        return true;
                    }
                    tempCol++;
                }
                tempRow++;
                tempCol = 0;
            }
            return false;
        };

        void next() override
        {
            int tempRow = row;
            int tempCol = col+1;
            while (tempRow < this->game->rows) {
                while (tempCol < this->game->cols) {
                    if (this->array[tempRow][tempCol] != nullptr) {
                        row = tempRow;
                        col = tempCol;
                        return;
                    }
                    tempCol++;
                }
                tempRow++;
                tempCol = 0;
            }

            row = -1;
            col = -1;
        };

        Building* current() override
        {
            if (row == -1 || col == -1 || this->array[row][col] == nullptr) {
                return nullptr;
            }
            return this->array[row][col];
        };

};

class UtilityIterator {
    protected:
        GameEnvironment* game;
        UtilGridNode*** array;
        int row, col;

    public:
        virtual bool hasNext()=0;
        virtual void next()=0;
        virtual UtilGridNode* current() =0;
};

class UtilityIteratorRadial: public UtilityIterator {
    protected:
        int setRadius;
        int centerX, centerY;
        
        void calculatePoints()
        {
            int yUp, yDown;

            for (int r= 0; r <= setRadius; r++) {
                for (int x = centerX - r; x <= centerX + r; x++) {

                    if (x < 0 || x >= game->rows) {
                        continue;
                    }

                    yUp = sqrt(r*r - (x - centerX)*(x - centerX)) + centerY;
                    yDown = -sqrt(r*r - (x - centerX)*(x - centerX)) + centerY;
                    if (yUp >= 0 && yUp < game->rows && !contains(x, yUp) && this->array[x][yUp] != nullptr) {
                        Node* newNode = new Node;
                        newNode->point.x = x;
                        newNode->point.y = yUp;
                        newNode->next = head;
                        head = newNode;
                    }

                    if (yDown != yUp && yDown >= 0 && yDown < game->rows && !contains(x, yDown) && this->array[x][yDown] != nullptr) {
                        Node* newNode = new Node;
                        newNode->point.x = x;
                        newNode->point.y = yDown;
                        newNode->next = head;
                        head = newNode;
                    }
                }
            }            
        };

        bool contains(int x, int y)
        {
            Node* temp = head;
            while (temp != nullptr) {
                if (temp->point.x == x && temp->point.y == y) {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        };

        Node* head;

    public:
        UtilityIteratorRadial()
        {
            centerX = 0;
            centerY = 0;
            setRadius = 0;
        };

        ~UtilityIteratorRadial()
        {
            game = nullptr;
            array = nullptr;
        };

        UtilityIteratorRadial(GameEnvironment* game, int x, int y, int radius)
        {
            this->game = game;
            this->array = game->utilityGrid;
            centerX = x;
            centerY = y;
            setRadius = radius;
            head = nullptr;
            calculatePoints();
        };

        bool hasNext() override
        {
            if (head == nullptr) {
                return false;
            }
            return head->next != nullptr;
        };

        void next() override
        {
            if (head == nullptr) {
                return;
            }
            Node* temp = head;
            head = head->next;
            delete temp;
        };

        UtilGridNode* current() override
        {
            if (head == nullptr) {
                return nullptr;
            }
            return this->array[head->point.x][head->point.y];
        };
};
    
class UtilityIteratorLinear: public UtilityIterator{
    public:
        UtilityIteratorLinear(GameEnvironment* game)
        {
            this->game = game;
            this->array = game->utilityGrid;
            row = 0;
            col = 0;

            for (int i = 0; i < this->game->rows; i++) {
                for (int j = 0; j < this->game->cols; j++) {
                    if (this->array[i][j] != nullptr) {
                        row = i;
                        col = j;
                        return;
                    }
                }
            }
        };

        ~UtilityIteratorLinear()
        {
            game = nullptr;
            array = nullptr;
        };

        bool hasNext() override
        {
            if (row == -1 || col == -1) {
                return false;
            }

            int tempRow = row;
            int tempCol = col+1;
            while (tempRow < this->game->rows) {
                while (tempCol < this->game->cols) {
                    if (this->array[tempRow][tempCol] != nullptr) {
                        return true;
                    }
                    tempCol++;
                }
                tempRow++;
                tempCol = 0;
            }
            return false;
        };

        void next() override
        {
            int tempRow = row;
            int tempCol = col+1;
            while (tempRow < this->game->rows) {
                while (tempCol < this->game->cols) {
                    if (this->array[tempRow][tempCol] != nullptr) {
                        row = tempRow;
                        col = tempCol;
                        return;
                    }
                    tempCol++;
                }
                tempRow++;
                tempCol = 0;
            }

            row = -1;
            col = -1;
        };

        UtilGridNode* current() override
        {
            if (row == -1 || col == -1 || this->array[row][col] == nullptr) {
                return nullptr;
            }
            return this->array[row][col];
        };
};


BuildingIteratorRadial* GameEnvironment::createRadBuildItr(int x, int y, int radius)
{
    return new BuildingIteratorRadial(this, x, y, radius);
};

BuildingIteratorLinear* GameEnvironment::createLinBuildItr()
{
    return new BuildingIteratorLinear(this);
};

UtilityIteratorRadial* GameEnvironment::createRadUtilItr(int x, int y, int radius)
{
    return new UtilityIteratorRadial(this, x, y, radius);
};

UtilityIteratorLinear* GameEnvironment::createLinUtilItr()
{
    return new UtilityIteratorLinear(this);
};

#endif // GAMEENVIRONMENT_H