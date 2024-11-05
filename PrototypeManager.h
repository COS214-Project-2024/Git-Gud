#ifndef PROTOTYPEMANAGER_H
#define PROTOTYPEMANAGER_H

#include "Building.h"

/**
 * @class PrototypeManager
 * @brief Manages a dynamic array of Building prototypes, allowing for adding, removing, and retrieving prototypes.
 */
class PrototypeManager
{
private:
    /**
     * @brief Array of pointers to Building prototypes.
     */
    Building** prototypeBuildings;

    /**
     * @brief The maximum number of prototypes that can currently be held.
     */
    int capacity;

    /**
     * @brief The current number of prototypes in the array.
     */
    int size;

    /**
     * @brief Resizes the array to accommodate more prototypes if needed.
     */
    void resizeArray();

public:
    /**
     * @brief Constructs a new PrototypeManager with an initial capacity.
     */
    PrototypeManager();

    /**
     * @brief Destructor for PrototypeManager, releases allocated memory for the array of prototypes.
     */
    ~PrototypeManager();

    /**
     * @brief Adds a new prototype to the manager.
     * @param p Pointer to the Building prototype to be added.
     */
    void addPrototype(Building* p);

    /**
     * @brief Removes a prototype from the manager.
     * @param p Pointer to the Building prototype to be removed.
     * @return True if the prototype was successfully removed; false if not found.
     */
    bool removePrototype(Building* p);

    /**
     * @brief Retrieves a prototype from the manager that matches the given prototype.
     * @param p Pointer to the Building prototype to retrieve.
     * @return Pointer to the matched Building prototype if found, or nullptr if not found.
     */
    Building* getPrototype(Building* p) const;

    /**
     * @brief Gets the current number of prototypes managed.
     * @return The number of prototypes currently in the array.
     */
    int getSize() const { return size; }

    /**
     * @brief Gets the current capacity of the array.
     * @return The capacity of the array.
     */
    int getCapacity() const { return capacity; }
};

#endif // PROTOTYPEMANAGER_H
