#include <gtest/gtest.h>
#include "ResidentialBuilding.h"

TEST(ResidentialBuildingTest, ProvideService) {
    ResidentialBuilding building(10);
    building.provideService();
    // Validate service provision effects, e.g., on tenants or cost
}
