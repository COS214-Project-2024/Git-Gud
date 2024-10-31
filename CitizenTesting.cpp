/*
#include <gtest/gtest.h>
#include "Citizen.h"
#include "Neutral.h" // Include satisfaction level classes
#include "Satisfied.h"
#include "Dissatisfied.h"
#include "ChangeData.h"

class CitizenTest : public ::testing::Test {
protected:
    Citizen* citizen;

    void SetUp() override {
        // Called before every test
        citizen = new Citizen(); // Default citizen
    }

    void TearDown() override {
        // Called after every test
        delete citizen;
    }
};

// Test for default constructor
TEST_F(CitizenTest, DefaultConstructor_SetsHasJobFalse) {
    EXPECT_FALSE(citizen->getHasJob());
}

// Test for parameterized constructor
TEST_F(CitizenTest, ParameterizedConstructor_SetsHasJobTrue) {
    Citizen citizenWithJob(true);
    EXPECT_TRUE(citizenWithJob.getHasJob());
}

// Test for satisfaction level initialization
TEST_F(CitizenTest, SatisfactionLevel_InitializesToNeutral) {
    EXPECT_NE(nullptr, citizen->getSatisfactionLevel());
    EXPECT_EQ(citizen->getSatisfactionLevel()->getCurrentSatisfactionLevel(), "Neutral");
}

// Test for setting job status
TEST_F(CitizenTest, SetJobStatus_UpdatesJobStatus) {
    citizen->setJobStatus(true);
    EXPECT_TRUE(citizen->getHasJob());

    citizen->setJobStatus(false);
    EXPECT_FALSE(citizen->getHasJob());
}

// Test for handling tax change with positive rate
TEST_F(CitizenTest, HandleTaxChange_IncreasesSatisfaction) {
    ChangeData changeData;
    changeData.changeType = "TaxChange";
    changeData.value = 0.1f; // Tax increase

    citizen->update(changeData);
    EXPECT_GT(citizen->getSatisfactionLevel()->satisfactionRating, 0.0f); // Assuming initial rating is 0
}

// Test for handling tax change with negative rate
TEST_F(CitizenTest, HandleTaxChange_DecreasesSatisfaction) {
    citizen->setSatisfactionLevel(new Satisfied()); // Set initial state to Satisfied
    ChangeData changeData;
    changeData.changeType = "TaxChange";
    changeData.value = -0.2f; // Tax decrease

    citizen->update(changeData);
    EXPECT_LT(citizen->getSatisfactionLevel()->satisfactionRating, 0.0f); // Assuming it decreases below satisfaction level
}

// Test for handling building constructed
TEST_F(CitizenTest, HandleBuildingConstructed_UpdatesSatisfaction) {
    ChangeData changeData;
    changeData.changeType = "BuildingConstructed";
    changeData.value = 1.0f; // Building type 1

    float initialRating = citizen->getSatisfactionLevel()->satisfactionRating;
    citizen->update(changeData);
    EXPECT_LT(citizen->getSatisfactionLevel()->satisfactionRating, initialRating);
}

// Test for handling non-existent update type
TEST_F(CitizenTest, Update_IgnoredUnknownChangeType) {
    ChangeData changeData;
    changeData.changeType = "UnknownChangeType";
    citizen->update(changeData);
    EXPECT_EQ(citizen->getSatisfactionLevel()->satisfactionRating, citizen->getSatisfactionLevel()->satisfactionRating);
}
*/

#include "Citizen.h"
#include "gtest/gtest.h"
#include "ChangeData.h"
#include "Neutral.h"

// Test Fixture for Citizen Class
class CitizenTest : public ::testing::Test {
protected:
    Citizen* citizen;

    void SetUp() override {
        citizen = new Citizen();
    }

    void TearDown() override {
        delete citizen;
    }
};

// Test for Default Constructor
TEST_F(CitizenTest, DefaultConstructor_SetsHasJobFalse) {
    EXPECT_FALSE(citizen->getHasJob());
}

// Test for Parameterized Constructor
TEST_F(CitizenTest, ParameterizedConstructor_SetsHasJobTrue) {
    Citizen* citizenWithJob = new Citizen(true);
    EXPECT_TRUE(citizenWithJob->getHasJob());
    delete citizenWithJob;
}

// Test for Satisfaction Level Initialization
TEST_F(CitizenTest, SatisfactionLevel_InitializesToNeutral) {
    SatisfactionLevel* satisfactionLevel = citizen->getSatisfactionLevel();
    EXPECT_NE(satisfactionLevel, nullptr);
    EXPECT_TRUE(dynamic_cast<Neutral*>(satisfactionLevel)); // Check if it's Neutral
    EXPECT_EQ(satisfactionLevel->satisfactionRating, 0.0f); // Assuming Neutral starts with a rating of 0
}

// Test for Setting Job Status
TEST_F(CitizenTest, SetJobStatus_UpdatesJobStatus) {
    citizen->setJobStatus(true);
    EXPECT_TRUE(citizen->getHasJob());

    citizen->setJobStatus(false);
    EXPECT_FALSE(citizen->getHasJob());
}

// Test for Handling Tax Change (Positive Rate)
TEST_F(CitizenTest, HandleTaxChange_PositiveRate_DecreasesSatisfaction) {
    SatisfactionLevel* satisfactionLevel = citizen->getSatisfactionLevel();
    float initialRating = satisfactionLevel->satisfactionRating;

    ChangeData changeData;
    changeData.changeType = "TaxChange";
    changeData.value = 5.0f; // Positive tax rate

    citizen->update(changeData);

    EXPECT_LT(satisfactionLevel->satisfactionRating, initialRating); // Should decrease
}

// Test for Handling Tax Change (Negative Rate)
TEST_F(CitizenTest, HandleTaxChange_NegativeRate_IncreasesSatisfaction) {
    SatisfactionLevel* satisfactionLevel = citizen->getSatisfactionLevel();
    float initialRating = satisfactionLevel->satisfactionRating;

    ChangeData changeData;
    changeData.changeType = "TaxChange";
    changeData.value = -3.0f; // Negative tax rate

    citizen->update(changeData);

    EXPECT_GT(satisfactionLevel->satisfactionRating, initialRating); // Should increase
}

// Test for Handling Building Constructed (Type 1)
TEST_F(CitizenTest, HandleBuildingConstructed_Type1_DecreasesSatisfaction) {
    SatisfactionLevel* satisfactionLevel = citizen->getSatisfactionLevel();
    float initialRating = satisfactionLevel->satisfactionRating;

    ChangeData changeData;
    changeData.changeType = "BuildingConstructed";
    changeData.value = 1.0f; // Type 1 building

    citizen->update(changeData);

    EXPECT_LT(satisfactionLevel->satisfactionRating, initialRating); // Should decrease
}

// Test for Handling Building Constructed (Type 2)
TEST_F(CitizenTest, HandleBuildingConstructed_Type2_IncreasesSatisfaction) {
    SatisfactionLevel* satisfactionLevel = citizen->getSatisfactionLevel();
    float initialRating = satisfactionLevel->satisfactionRating;

    ChangeData changeData;
    changeData.changeType = "BuildingConstructed";
    changeData.value = 2.0f; // Type 2 building

    citizen->update(changeData);

    EXPECT_GT(satisfactionLevel->satisfactionRating, initialRating); // Should increase
}

// Test for Ignoring Unknown Change Type
TEST_F(CitizenTest, Update_UnknownChangeType_NoEffectOnSatisfaction) {
    SatisfactionLevel* satisfactionLevel = citizen->getSatisfactionLevel();
    float initialRating = satisfactionLevel->satisfactionRating;

    ChangeData changeData;
    changeData.changeType = "UnknownChangeType";
    changeData.value = 0.0f;

    citizen->update(changeData);

    EXPECT_EQ(satisfactionLevel->satisfactionRating, initialRating); // Should remain unchanged
}
