#include <gtest/gtest.h>
#include "LandmarkBuilding.h"

TEST(LandmarkBuildingTest, GetCost) {
    LandmarkBuilding building(50);
    EXPECT_FLOAT_EQ(building.getCost(), expectedValue); // replace with actual expected value
}
