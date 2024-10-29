#include <gtest/gtest.h>
#include "IndustrialBuildingFactory.h"

TEST(IndustrialBuildingFactoryTest, ConstructBuilding) {
    IndustrialBuildingFactory factory;
    Building* building = factory.constructBuilding();
    EXPECT_NE(building, nullptr);
    delete building;
}
