// Memento.h

#ifndef MEMENTO_H
#define MEMENTO_H

#include "ResourceManager.h"
#include "GameEnvironment.h"
#include <vector>

class Memento {
private:
    ResourceManagerState savedResourceState;  // Stores the ResourceManager's saved state
    std::vector<std::vector<Building*>> buildingGridSnapshot;
    std::vector<std::vector<UtilGridNode*>> utilityGridSnapshot;

public:
    // Constructor that initializes the memento with a ResourceManagerState and grid snapshots
    Memento(const ResourceManagerState& resourceState,
            const std::vector<std::vector<Building*>>& buildingGrid,
            const std::vector<std::vector<UtilGridNode*>>& utilityGrid)
        : savedResourceState(resourceState), buildingGridSnapshot(buildingGrid), utilityGridSnapshot(utilityGrid) {}

    // Accessors to retrieve saved state and snapshots
    ResourceManagerState getSavedResourceState() const { return savedResourceState; }
    std::vector<std::vector<Building*>> getBuildingGridSnapshot() const { return buildingGridSnapshot; }
    std::vector<std::vector<UtilGridNode*>> getUtilityGridSnapshot() const { return utilityGridSnapshot; }
};

#endif // MEMENTO_H