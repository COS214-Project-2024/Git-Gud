#include "gtest/gtest.h"
#include "CommercialBuilding.h"
#include "Citizen.h"
#include <vector>
#include <string>
#include <sstream>

class CommercialBuildingTest : public ::testing::Test {
protected:
    CommercialBuilding* buildingLuxury;
    CommercialBuilding* buildingFood;
    CommercialBuilding* buildingGeneral;

    void SetUp() override {
        buildingLuxury = new CommercialBuilding(std::make_unique<UnderConstruction>(), 10, 300, 5, LUXURY);
        buildingFood = new CommercialBuilding(20, 400, 6, FOOD);
        buildingGeneral = new CommercialBuilding(30, 500, 7, GENERAL);
    }

    void TearDown() override{

        delete buildingFood;
        delete buildingGeneral;
        delete buildingLuxury;

    }

};

TEST_F(CommercialBuildingTest, ConstructorTest) {
    EXPECT_EQ(buildingLuxury->getSize(), 300);
    EXPECT_EQ(buildingLuxury->getNumStories(), 5);
    EXPECT_EQ(buildingLuxury->getBusinessType(), LUXURY);

    EXPECT_EQ(buildingFood->getSize(), 400);
    EXPECT_EQ(buildingFood->getNumStories(), 6);
    EXPECT_EQ(buildingFood->getBusinessType(), FOOD);
    
    EXPECT_EQ(buildingGeneral->getSize(), 500);
    EXPECT_EQ(buildingGeneral->getNumStories(), 7);
    EXPECT_EQ(buildingGeneral->getBusinessType(), GENERAL);
}

TEST_F(CommercialBuildingTest, GetCostTest){
    
    EXPECT_FLOAT_EQ(buildingLuxury->getCost(), 50000.0);
    
    EXPECT_FLOAT_EQ(buildingFood->getCost(), 50000.0);
    
    EXPECT_FLOAT_EQ(buildingGeneral->getCost(), 50000.0);

}



TEST_F(CommercialBuildingTest, ProvideServiceTest){
    
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    buildingLuxury->provideService();
    EXPECT_EQ(output.str(), "Building sells luxury items\n");

    output.str("");
    buildingFood->provideService();
    EXPECT_EQ(output.str(), "Building is selling food\n");

    output.str("");
    buildingGeneral->provideService();
    EXPECT_EQ(output.str(), "Building is selling general items\n");

    std::cout.rdbuf(oldCoutBuf);

}

TEST_F(CommercialBuildingTest, GetSizeTest){

    EXPECT_EQ(buildingLuxury->getSize(), 300);
    EXPECT_EQ(buildingFood->getSize(), 400);
    EXPECT_EQ(buildingGeneral->getSize(), 500);

}


TEST_F(CommercialBuildingTest, GetNumStoriesTest){

    EXPECT_EQ(buildingLuxury->getNumStories(), 5);
    EXPECT_EQ(buildingFood->getNumStories(), 6);
    EXPECT_EQ(buildingGeneral->getNumStories(), 7);

}

TEST_F(CommercialBuildingTest, GetBusinessTypeTest){

    EXPECT_EQ(buildingLuxury->getBusinessType(), LUXURY);
    EXPECT_EQ(buildingFood->getBusinessType(), FOOD);
    EXPECT_EQ(buildingGeneral->getBusinessType(), GENERAL);

}

TEST_F(CommercialBuildingTest, AddEmployeesTest){

    Citizen citizen1, citizen2, citizen3;
    citizen1.setJobStatus(false);
    citizen2.setJobStatus(false);
    citizen3.setJobStatus(false);

    buildingLuxury->addCitizenToSimulation(&citizen1);
    buildingLuxury->addCitizenToSimulation(&citizen2);
    buildingLuxury->addCitizenToSimulation(&citizen3);

    buildingLuxury->addEmployees();

    EXPECT_TRUE(citizen1.getHasJob());
    EXPECT_TRUE(citizen2.getHasJob());
    EXPECT_TRUE(citizen3.getHasJob());

    EXPECT_LE(buildingLuxury->getObserverListSize(), buildingLuxury->getCapacity());

}

TEST_F(CommercialBuildingTest, CloneTest){

    CommercialBuilding* clonedBuilding = buildingLuxury->clone();

    EXPECT_EQ(clonedBuilding->getSize(), buildingLuxury->getSize());
    EXPECT_EQ(clonedBuilding->getNumStories(), buildingLuxury->getNumStories());
    EXPECT_EQ(clonedBuilding->getBusinessType(), buildingLuxury->getBusinessType());
    EXPECT_EQ(clonedBuilding->getCost(), buildingLuxury->getCost());

    delete clonedBuilding;

}