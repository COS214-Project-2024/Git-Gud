#ifndef LINEAR_ITERATOR_H
#define LINEAR_ITERATOR_H

#include "Iterator.h"

template <typename T>
class LinearIterator : public Iterator<T> {
    protected:
        int row, col;        

    public:
        LinearIterator();
        ~LinearIterator();

        LinearIterator(GameEnvironment* game, T*** array, int row, int col);

        virtual bool hasNext() override;
        virtual void next() override;
        virtual T* current() const override;

};

template <typename T>
LinearIterator<T>::LinearIterator() : Iterator<T>() {
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
}

template <typename T>
LinearIterator<T>::~LinearIterator() {
    game = nullptr;
    array = nullptr;
}

template <typename T>
LinearIterator<T>::LinearIterator(GameEnvironment* game, T*** array, int row, int col)
{
    this->game = game;
    this->array = array;
    this->row = row;
    this->col = col;
}

template <typename T>
bool LinearIterator<T>::hasNext() {
    int tempRow = row;
    int tempCol = col+1;
    while (tempRow < this->game->rows) {
        while (tempCol < this->game->cols) {
            if (this->array[tempRow][tempCol] != nullptr) {
                return true;
            }
            tempCol++;
        }
        tempCol = 0;
        tempRow++;
    }
    return false;
}

template <typename T>
void LinearIterator<T>::next() {
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
        tempCol = 0;
        tempRow++;
    }
}

template <typename T>
T* LinearIterator<T>::current() const {
    return this->array[row][col];
}
            

#endif // LINEAR_ITERATOR_H
