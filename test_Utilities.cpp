#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "SewageSystem.h"
#include "Citizen.h"
#include "ChangeData.h"

using ::testing::AtLeast;
using ::testing::_;

class MockCitizen : public Citizen {
public:
    MOCK_METHOD(void, update, (ChangeData changeData), (override));
};

class SewageSystemTest : public ::testing::Test {
protected:
    SewageSystem* sewageSystem;
    MockCitizen* mockCitizen1;
    MockCitizen* mockCitizen2;

    void SetUp() override {
        sewageSystem = new SewageSystem(100, 50);
        mockCitizen1 = new MockCitizen();
        mockCitizen2 = new MockCitizen();

        sewageSystem->attach(mockCitizen1);
        sewageSystem->attach(mockCitizen2);
    }

    void TearDown() override {
        delete sewageSystem;
        delete mockCitizen1;
        delete mockCitizen2;
    }
};

// Test constructors and getters
TEST_F(SewageSystemTest, Constructor_SetsCorrectValues) {
    EXPECT_EQ(sewageSystem->getUtilityType(), "SewageSystem");
    EXPECT_EQ(sewageSystem->getCapacity(), 100);
    EXPECT_EQ(sewageSystem->getMaintenanceCost(), 50);
}

// Test observer notification via callObserver
TEST_F(SewageSystemTest, CallObserver_NotifiesAttachedCitizens) {
    ChangeData changeData{"ProvideService", 1.0f};

    EXPECT_CALL(*mockCitizen1, update(changeData)).Times(1);
    EXPECT_CALL(*mockCitizen2, update(changeData)).Times(1);

    sewageSystem->callObserver();
}

// Test getCapacity
TEST_F(SewageSystemTest, GetCapacity_ReturnsCorrectCapacity) {
    EXPECT_EQ(sewageSystem->getCapacity(), 100);
}

// Test getMaintenanceCost
TEST_F(SewageSystemTest, GetMaintenanceCost_ReturnsCorrectMaintenanceCost) {
    EXPECT_EQ(sewageSystem->getMaintenanceCost(), 50);
}

// Test getUtilityType
TEST_F(SewageSystemTest, GetUtilityType_ReturnsCorrectType) {
    EXPECT_EQ(sewageSystem->getUtilityType(), "SewageSystem");
}

TEST_F(SewageSystemTest, HandleObservers_NotifiesAllCitizens) {

    ChangeData changeData = {"ProvideService", 1.0f};
    sewageSystem->addCitizenToSimulation(mockCitizen1);
    sewageSystem->addCitizenToSimulation(mockCitizen2);

    // Act
    

    EXPECT_CALL(*mockCitizen1, update(changeData)).Times(1);
    EXPECT_CALL(*mockCitizen2, update(changeData)).Times(1);

    // Add mock citizens to the sewage system simulation
    sewageSystem->callObserver(); // Ensure this correctly calls notifyCitizens

    // No assertion needed as EXPECT_CALL handles that.
}