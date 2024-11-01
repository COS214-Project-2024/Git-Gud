#include "gtest/gtest.h"
#include "Landmark.h"
#include "Citizen.h"
#include "Subject.h"
#include <vector>
#include <sstream>

class LandmarkBuildingTest : public ::testing::Test {
protected:
    LandmarkBuilding* landmarkBuilding;

    void SetUp() override {
        // Assume you have a Citizen collection for testing.
        std::vector<Citizen*> citizens = { new Citizen(), new Citizen(), new Citizen() };
         // Assuming allCitizens is accessible here.
        landmarkBuilding = new LandmarkBuilding(10); // or use std::make_unique<UnderConstruction>() if applicable
        landmarkBuilding->allCitizens = citizens;
    }

    void TearDown() override {
        
        for (Citizen* citizen : this->landmarkBuilding->allCitizens) {
            delete citizen; // Clean up Citizen objects
        }

        delete landmarkBuilding;
    }
};

TEST_F(LandmarkBuildingTest, ConstructorTest) {
    EXPECT_EQ(landmarkBuilding->getCapacity(), 10); // Check capacity
    // You might need to adjust this depending on what you have implemented for size and stories.
    EXPECT_EQ(landmarkBuilding->getSize(), 0); // Placeholder, update according to implementation
    EXPECT_EQ(landmarkBuilding->getNumStories(), 0); // Placeholder, update according to implementation
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
    // Assuming you have implemented size and number of stories
    EXPECT_EQ(clonedBuilding->getSize(), landmarkBuilding->getSize());
    EXPECT_EQ(clonedBuilding->getNumStories(), landmarkBuilding->getNumStories());
    EXPECT_FLOAT_EQ(clonedBuilding->getCost(), landmarkBuilding->getCost());

    delete clonedBuilding;
}
