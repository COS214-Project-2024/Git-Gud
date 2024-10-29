#include <gtest/gtest.h>
#include "Subject.h"
#include "Citizen.h"

TEST(SubjectTest, AttachAndNotify) {
    Subject subject;
    Citizen citizen;
    subject.attach(&citizen);
    EXPECT_EQ(subject.getObserverCount(), 1);

    ChangeData changeData{"taxChange", 0.05f};
    subject.notify(changeData);

    // Confirm citizen received notification (requires Citizen method implementation)
}
