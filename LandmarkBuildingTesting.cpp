#include "gtest/gtest.h"
#include "Landmark.h"
#include "Citizen.h"
#include <sstream>
#include <thread>
#include <chrono>
#include "ResidentialBuilding.h"

class LandmarkBuildingTest : public ::testing::Test {
protected:
    LandmarkBuilding* landmarkBuilding;
    ResidentialBuilding* residentialBuilding;
    std::vector<Citizen*> testCitizens;

    void SetUp() override {

        residentialBuilding = new ResidentialBuilding(5);
        landmarkBuilding = new LandmarkBuilding(5); // Assuming a capacity of 5

    }

    void TearDown() override {
        delete landmarkBuilding;
        for (Citizen* citizen : testCitizens) {
            delete citizen;
        }
    }
};

TEST_F(LandmarkBuildingTest, ConstructorTest) {
    EXPECT_EQ(landmarkBuilding->getCapacity(), 5);
    
    // Assuming there's a method to get the attached citizens
    std::vector<Citizen*> attachedCitizens = landmarkBuilding->getObserverList(); 
    EXPECT_EQ(landmarkBuilding->getObserverListSize(), 5);
}

TEST_F(LandmarkBuildingTest, GetCostTest) {
    EXPECT_FLOAT_EQ(landmarkBuilding->getCost(), 75000.0);
}

TEST_F(LandmarkBuildingTest, ProvideServiceTest) {
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    landmarkBuilding->provideService();
    EXPECT_EQ(output.str(), "Landmark is providing entertainment to citizens\n");

    std::cout.rdbuf(oldCoutBuf);
}

TEST_F(LandmarkBuildingTest, CloneTest) {
    LandmarkBuilding* clonedBuilding = landmarkBuilding->clone();

    EXPECT_EQ(clonedBuilding->getCapacity(), landmarkBuilding->getCapacity());
    EXPECT_EQ(clonedBuilding->getCost(), landmarkBuilding->getCost());

    delete clonedBuilding;
}
