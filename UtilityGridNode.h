#include <string>
#ifndef UTILITY_GRID_NODE_H
#define UTILITY_GRID_NODE_H

#include "Utility.h"

class UtilGridNode {
    private:
    // Member variable
    bool hasRoad; 
    struct Node {
        Utility* utility;
        Node* next;
    };
    Node* head;

public:
    UtilGridNode()
    {
        head = nullptr;
        hasRoad = false;
    }; // Constructor
    ~UtilGridNode() // Destructor
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    };

    // Member functions
    void createRoad()
    {
        hasRoad = true;
    };

    bool remove(std::string type)
    {
        if (head == nullptr)
        {
            return false;
        }
        if (head->utility->getType() == type)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr)
        {
            if (current->utility->getType() == type)
            {
                previous->next = current->next;
                delete current;
                return true;
            }
        }
        return false;
    };

    bool add(Utility* utility)
    {
        remove(utility->getType());//Calling remove first to avoid duplicate utilities. Minimize traversals
        Node* newNode = new Node;
        newNode->utility = utility;
        newNode->next = head;
        head = newNode;
        return true;
    };
    
    bool getHasRoad()
    {
        return hasRoad;
    };

    Utility* getUtility(std::string type)
    {
        Node* current = head;
        while (current != nullptr)
        {
            if (current->utility->getType() == type)
            {
                return current->utility;
            }
            current = current->next;
        }
        return nullptr;
    };

};

#endif // UTILITY_GRID_NODE_H