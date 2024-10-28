#ifndef RADIAL_ITERATOR_H
#define RADIAL_ITERATOR_H

#include "Iterator.h"
#include <cmath>

template <typename T>
class RadialIterator : public Iterator<T> {
    protected:
        int setRadius, ;
        int centerX, centerY;
        
        struct Point {
            int x, y;
        };

        struct Node {
            Point point;
            Node* next;
        };

        void calculatePoints();
        bool contains(int x, int y);

        Node* head;


    public:
        RadialIterator();
        ~RadialIterator();

        RadialIterator(GameEnvironment* game, T*** array, int x, int y, int radius);

        bool hasNext() override;
        void next() override;
        T* current() const override;    
    
};

template <typename T>
RadialIterator<T>::RadialIterator() : Iterator<T>() {
    centerX = 0;
    centerY = 0;
    setRadius = 0;
}

template <typename T>
RadialIterator<T>::~RadialIterator() {
    game = nullptr;
    array = nullptr;
}

template <typename T>
RadialIterator<T>::RadialIterator(GameEnvironment* game, T*** array, int x, int y, int radius)
{
    this->game = game;
    this->array = array;
    centerX = x;
    centerY = y;
    setRadius = radius;
    head = nullptr;
}

template <typename T>
bool RadialIterator<T>::contains(int x, int y) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->point.x == x && temp->point.y == y) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <typename T>
void RadialIterator<T>::calculatePoints() {

    int yUp, yDown;

    for (int r= 0; r < setRadius; r++) {
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
}

template <typename T>
bool RadialIterator<T>::hasNext() {
    return head != nullptr;
}

template <typename T>
void RadialIterator<T>::next() {
    Node* temp = head;
    head = head->next;
    delete temp;
}

template <typename T>
T* RadialIterator<T>::current() const {
    return this->array[head->point.x][head->point.y];
}   





#endif // RADIAL_ITERATOR_H