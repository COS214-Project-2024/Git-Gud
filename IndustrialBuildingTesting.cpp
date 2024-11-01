#include "gtest/gtest.h"
#include "IndustrialBuilding.h"
#include "Citizen.h"
#include <vector>
#include <sstream>

class IndustrialBuildingTest : public ::testing::Test {
protected:
    IndustrialBuilding* buildingManufacturing;
    IndustrialBuilding* buildingEnergy;
    IndustrialBuilding* buildingTechnology;

    void SetUp() override {
        buildingManufacturing = new IndustrialBuilding(std::make_unique<UnderConstruction>(), 15, 300, 4, MANUFACTURING, 35);
        buildingEnergy = new IndustrialBuilding(20, 400, 5, ENERGY, 40);
        buildingTechnology = new IndustrialBuilding(25, 500, 6, TECHNOLOGY, 50);
    }

    void TearDown() override {
        delete buildingManufacturing;
        delete buildingEnergy;
        delete buildingTechnology;
    }
};

TEST_F(IndustrialBuildingTest, ConstructorTest){

    EXPECT_EQ(buildingManufacturing->getSize(), 300);
    EXPECT_EQ(buildingManufacturing->getNumStories(), 4);
    EXPECT_EQ(buildingManufacturing->getIndustryType(), MANUFACTURING);

    EXPECT_EQ(buildingEnergy->getSize(), 400);
    EXPECT_EQ(buildingEnergy->getNumStories(), 5);
    EXPECT_EQ(buildingEnergy->getIndustryType(), ENERGY);

    EXPECT_EQ(buildingTechnology->getSize(), 500);
    EXPECT_EQ(buildingTechnology->getNumStories(), 6);
    EXPECT_EQ(buildingTechnology->getIndustryType(), TECHNOLOGY);

}

TEST_F(IndustrialBuildingTest, GetCostTest){

    EXPECT_FLOAT_EQ(buildingManufacturing->getCost(), 50000.0);
    EXPECT_FLOAT_EQ(buildingEnergy->getCost(), 50000.0);
    EXPECT_FLOAT_EQ(buildingTechnology->getCost(), 50000.0);

}

TEST_F(IndustrialBuildingTest, ProvideServiceTest){

    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    buildingManufacturing->provideService();
    EXPECT_EQ(output.str(), "Building is manufacturing items\n");

    output.str("");
    buildingEnergy->provideService();
    EXPECT_EQ(output.str(), "Building is generating energy\n");

    output.str("");
    buildingTechnology->provideService();
    EXPECT_EQ(output.str(), "Building is producing different technologies\n");

    std::cout.rdbuf(oldCoutBuf);

}

TEST_F(IndustrialBuildingTest, GetSizeTest){

    EXPECT_EQ(buildingManufacturing->getSize(), 300);
    EXPECT_EQ(buildingEnergy->getSize(), 400);
    EXPECT_EQ(buildingTechnology->getSize(), 500);

}

TEST_F(IndustrialBuildingTest, GetNumStoriesTest){

    EXPECT_EQ(buildingManufacturing->getNumStories(), 4);
    EXPECT_EQ(buildingEnergy->getNumStories(), 5);
    EXPECT_EQ(buildingTechnology->getNumStories(), 6);

}

TEST_F(IndustrialBuildingTest, GetIndustryTypeTest){

    EXPECT_EQ(buildingManufacturing->getIndustryType(), MANUFACTURING);
    EXPECT_EQ(buildingEnergy->getIndustryType(), ENERGY);
    EXPECT_EQ(buildingTechnology->getIndustryType(), TECHNOLOGY);

}

TEST_F(IndustrialBuildingTest, AddEmployeesTest){

    Citizen citizen1, citizen2, citizen3;
    citizen1.setJobStatus(false);
    citizen2.setJobStatus(false);
    citizen3.setJobStatus(false);

    buildingManufacturing->addCitizenToSimulation(&citizen1);
    buildingManufacturing->addCitizenToSimulation(&citizen2);
    buildingManufacturing->addCitizenToSimulation(&citizen3);

    buildingManufacturing->addEmployees();

    EXPECT_TRUE(citizen1.getHasJob());
    EXPECT_TRUE(citizen2.getHasJob());
    EXPECT_TRUE(citizen3.getHasJob());

    EXPECT_LE(buildingManufacturing->getObserverListSize(), buildingManufacturing->getCapacity());

}

TEST_F(IndustrialBuildingTest, CloneTest){

    IndustrialBuilding* clonedBuilding = buildingManufacturing->clone();

    EXPECT_EQ(clonedBuilding->getSize(), buildingManufacturing->getSize());
    EXPECT_EQ(clonedBuilding->getNumStories(), buildingManufacturing->getNumStories());
    EXPECT_EQ(clonedBuilding->getIndustryType(), buildingManufacturing->getIndustryType());
    EXPECT_EQ(clonedBuilding->getCost(), buildingManufacturing->getCost());

    delete clonedBuilding;
    
}