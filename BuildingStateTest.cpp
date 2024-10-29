#include <gtest/gtest.h>
#include "BuildingState.h"

class MockBuildingState : public BuildingState {
public:
    void enterState(Building* building) override {}
    void exitState(Building* building) override {}
    void nextState(Building* building) override {}
    std::string getCurrentState() override { return "MockState"; }
};

TEST(BuildingStateTest, GetCurrentState) {
    MockBuildingState state;
    EXPECT_EQ(state.getCurrentState(), "MockState");
}
