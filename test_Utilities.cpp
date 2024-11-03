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
    MockCitizen* mockCitizen;

    void SetUp() override {
        sewageSystem = new SewageSystem(100, 50);
        mockCitizen = new MockCitizen();

        sewageSystem->attach(mockCitizen);
    }

    void TearDown() override {
        delete sewageSystem;
        delete mockCitizen;
    }
};



//test constructors and getters
TEST_F(SewageSystemTest, Constructor_SetsCorrectValues){

    EXPECT_EQ(sewageSystem->getUtilityType(), "SewageSystem");
    EXPECT_EQ(sewageSystem->getCapacity(), 100);
    EXPECT_EQ(sewageSystem->getMaintenanceCost(), 50);

}

//test observer notification
TEST_F(SewageSystemTest, CallObserver_NotifiesAttachedCitizens){

    ChangeData changeData{"ProvideService", 1.0f};

    EXPECT_CALL(*mockCitizen, update(changeData)).Times(1);

    sewageSystem->callObserver();

}

//test getCapacity
TEST_F(SewageSystemTest, GetCapacity_ReturnsCorrectCapacity){

    EXPECT_EQ(sewageSystem->getCapacity(), 100);

}

//test getMaintenanceCost
TEST_F(SewageSystemTest, GetMaintenanceCost_ReturnsCorrectMaintenanceCost){

    EXPECT_EQ(sewageSystem->getMaintenanceCost(), 50);

}

//test getUtilityType
TEST_F(SewageSystemTest, GetUtilityType_ReturnsCorrectType){

    EXPECT_EQ(sewageSystem->getUtilityType(), "SewageSystem");
    
}
