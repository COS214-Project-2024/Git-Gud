#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Subject.h"
#include "Citizen.h"
#include "ChangeData.h"

// Mock class for Citizen
class MockCitizen : public Citizen {
public:
    MOCK_METHOD(void, update, (ChangeData), (override));
};

TEST(SubjectTest, AttachAndNotify) {
    Subject subject;
    MockCitizen mockCitizen;

    // Attach the observer
    subject.attach(&mockCitizen);

    // Expect the observer to be notified
    ChangeData changeData;
    EXPECT_CALL(mockCitizen, update(changeData)).Times(1);

    // Notify observers
    subject.notify(changeData);
}

TEST(SubjectTest, Detach) {
    Subject subject;
    MockCitizen mockCitizen;

    // Attach and then detach the observer
    subject.attach(&mockCitizen);
    subject.detach(&mockCitizen);

    // Expect the observer not to be notified
    ChangeData changeData;
    EXPECT_CALL(mockCitizen, update(changeData)).Times(0);

    // Notify observers
    subject.notify(changeData);
}

TEST(SubjectTest, AddAndRemoveCitizen) {
    Subject subject;
    MockCitizen mockCitizen;

    // Add and then remove the citizen from the simulation
    subject.addCitizenToSimulation(&mockCitizen);
    subject.removeCitizenFromSimulation(&mockCitizen);

    // No specific expectations for this test, just ensuring no errors occur
}
