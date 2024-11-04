#ifndef UTILITYITERATORRADIAL_H
#define UTILITYiTERATORRADIAL_H

#include "UtilityIterator.h"

class UtilityIteratorRadial : public UtilityIterator {
protected:
    int setRadius;
    int centerX; 
    int centerY;

    void calculatePoints(UtilGridNode*** array, int rows, int cols) {
        int yUp, yDown;

        for (int r = 0; r <= setRadius; r++) {
            for (int x = centerX - r; x <= centerX + r; x++) {
                if (x < 0 || x >= rows) {
                    continue;
                }

                yUp = sqrt(r * r - (x - centerX) * (x - centerX)) + centerY;
                yDown = -sqrt(r * r - (x - centerX) * (x - centerX)) + centerY;

                if (yUp >= 0 && yUp < rows && !contains(x, yUp) && array[x][yUp] != nullptr) {
                    Node* newNode = new Node;
                    newNode->point.x = x;
                    newNode->point.y = yUp;
                    newNode->next = head;
                    head = newNode;
                }

                if (yDown != yUp && yDown >= 0 && yDown < rows && !contains(x, yDown) && array[x][yDown] != nullptr) {
                    Node* newNode = new Node;
                    newNode->point.x = x;
                    newNode->point.y = yDown;
                    newNode->next = head;
                    head = newNode;
                }
            }
        }
    }

    bool contains(int x, int y) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->point.x == x && temp->point.y == y) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    Node* head;

public:
    UtilityIteratorRadial()
        : centerX(0), centerY(0), setRadius(0), head(nullptr) {}

    ~UtilityIteratorRadial() {
        array = nullptr;
    }

    UtilityIteratorRadial(UtilGridNode*** array, int x, int y, int radius, int rows, int cols)
        : centerX(x), centerY(y), setRadius(radius), head(nullptr) {
        this->array = array;
        calculatePoints(array, rows, cols);
    }

    bool hasNext() override {
        return head != nullptr && head->next != nullptr;
    }

    void next() override {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    UtilGridNode* current() override {
        if (head == nullptr) {
            return nullptr;
        }
        return this->array[head->point.x][head->point.y];
    }
};


#endif //UTILITYiTERATORRADIAL_H