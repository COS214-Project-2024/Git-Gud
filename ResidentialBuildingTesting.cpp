#include "gtest/gtest.h"
#include "ResidentialBuilding.h"
#include "Citizen.h"
#include <sstream>

class ResidentialBuildingTest : public ::testing::Test {
protected:
    ResidentialBuilding* residentialBuilding;
    std::vector<Citizen*> testCitizens;

    void SetUp() override {
        residentialBuilding = new ResidentialBuilding(5);
        for (int i = 0; i < 5; ++i) {
            Citizen* citizen = new Citizen();
            testCitizens.push_back(citizen);
            residentialBuilding->addCitizenToSimulation(citizen);
        }
    }

    void TearDown() override {
        delete residentialBuilding;
        for (Citizen* citizen : testCitizens) {
            delete citizen;
        }
    }
};

TEST_F(ResidentialBuildingTest, ConstructorTest){

    EXPECT_EQ(residentialBuilding->getCapacity(), 5);

    std::list<Citizen*> tenants = residentialBuilding->getTenants();
    EXPECT_EQ(tenants.size(), 5);

}

TEST_F(ResidentialBuildingTest, GetCostTest){

    EXPECT_FLOAT_EQ(residentialBuilding->getCost(), 25000.0);

}

TEST_F(ResidentialBuildingTest, ProvideServiceTest){

    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    residentialBuilding->provideService();
    EXPECT_EQ(output.str(), "Provide services to residents\n");

    std::cout.rdbuf(oldCoutBuf);

}

TEST_F(ResidentialBuildingTest, CloneTest){

    ResidentialBuilding* clonedBuilding = residentialBuilding->clone();

    EXPECT_EQ(clonedBuilding->getCapacity(), residentialBuilding->getCapacity());
    EXPECT_EQ(clonedBuilding->getCost(), residentialBuilding->getCost());

    delete clonedBuilding;

}

TEST_F(ResidentialBuildingTest, AddCitizensTest){

    std::list<Citizen*> tenants = residentialBuilding->getTenants();

    for(Citizen* tenant : tenants){

        EXPECT_NE(tenant, nullptr);

    }
    
    EXPECT_EQ(tenants.size(), 5);

}
