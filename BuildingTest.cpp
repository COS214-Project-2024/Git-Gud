#include <gtest/gtest.h>
#include "Building.h"
#include "UnderConstruction.h"

TEST(BuildingTest, CurrentState) {
    Building building(20);
    EXPECT_EQ(building.currentState(), "UnderConstruction");
}