#include <gtest/gtest.h>
#include "Citizen.h"

TEST(CitizenTest, JobStatus) {
    Citizen citizen;
    citizen.setJobStatus(true);
    EXPECT_TRUE(citizen.getHasJob());
}
