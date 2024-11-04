#ifndef UTILITYITERATORLINEAR_H
#define UTILITYITERATORLINEAR_H

#include "UtilityIterator.h"

class UtilityIteratorLinear : public UtilityIterator {

private:
    int rows, cols;

public:
    UtilityIteratorLinear(UtilGridNode*** array, int rows, int cols) {
        this->array = array;
        this->rows = rows;
        this->cols = cols;
        row = -1;  // Start at invalid position
        col = -1;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (this->array[i][j] != nullptr) {
                    row = i;
                    col = j;
                    return;
                }
            }
        }
    }

    ~UtilityIteratorLinear() {
        array = nullptr;
    }

    bool hasNext() override {
        if (row == -1 || col == -1) {
            return false;  // Invalid state
        }

        int tempRow = row;
        int tempCol = col + 1;

        while (tempRow < rows) {
            while (tempCol < cols) {
                if (this->array[tempRow][tempCol] != nullptr) {
                    return true;  // Found a next valid utility node
                }
                tempCol++;
            }
            tempRow++;
            tempCol = 0;  // Reset column for next row
        }
        return false;  // No next valid utility node found
    }

    void next() override {

        if (row == -1 || col == -1) {
            return;
        }

        int tempRow = row;
        int tempCol = col + 1;
        while (tempRow < rows) {
            while (tempCol < cols) {
                if (array[tempRow][tempCol] != nullptr) {
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
    }

    UtilGridNode* current() override {
        if (row == -1 || col == -1 || this->array[row][col] == nullptr) {
            return nullptr;
        }
        return this->array[row][col];
    }
};


#endif //UTILITYITERATORLINEAR_H