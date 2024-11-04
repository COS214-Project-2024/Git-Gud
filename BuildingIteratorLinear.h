#ifndef BUILDINGITERATORLINEAR_H
#define BUILDINGITERATORLINEAR_H

#include "BuildingIterator.h"


class BuildingIteratorLinear : public BuildingIterator {
public:
    BuildingIteratorLinear(Building*** array, int rows, int cols) {
        this->array = array;
        this->rows = rows;
        this->cols = cols;
        row = 0;
        col = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (this->array[i][j] != nullptr) {
                    row = i;
                    col = j;
                    return;
                }
            }
        }
        row = -1;  // No valid start position found
        col = -1;
    }

    ~BuildingIteratorLinear() {
        array = nullptr;
    }

    bool hasNext() override {
        if (row == -1 || col == -1) {
            return false;
        }

        int tempRow = row;
        int tempCol = col + 1;
        while (tempRow < rows) {
            while (tempCol < cols) {
                if (this->array[tempRow][tempCol] != nullptr) {
                    return true;
                }
                tempCol++;
            }
            tempRow++;
            tempCol = 0;
        }
        return false;
    }

    void next() override {
        if (row == -1 || col == -1) {
            return;  // Already at the end, do nothing
        }

        int tempRow = row;
        int tempCol = col + 1;
        while (tempRow < rows) {
            while (tempCol < cols) {
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

        row = -1;  // Reached the end, no more elements
        col = -1;
    }

    Building* current() override {
        if (row == -1 || col == -1 || this->array[row][col] == nullptr) {
            return nullptr;
        }
        return this->array[row][col];
    }
};


#endif //BUILDINGITERATORLINEAR_H