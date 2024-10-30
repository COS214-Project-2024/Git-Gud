#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Subject.h"
#include "Citizen.h"
#include "UnderConstruction.h"
#include "Operational.h"
#include "ChangeData.h"

class SubjectTest : public ::testing::Test {

    protected:
        Subject subject;

};

class MockCitizen : public Citizen { 

    public: MOCK_METHOD(void, update, (ChangeData), (override)); 
    
};

TEST_F(SubjectTest, testAttachObserver){

    subject.attach(new Citizen());

    EXPECT_EQ(subject.getObserverListSize(), 1);

}

TEST_F(SubjectTest, testDetachObserver){

    Citizen* newCitizen = new Citizen();

    subject.attach(newCitizen);
    subject.detach(newCitizen);

    EXPECT_EQ(subject.getObserverListSize(), 0);

}

TEST_F(SubjectTest, testAddingCitizensToSimulation){

    subject.addCitizenToSimulation(new Citizen());

    EXPECT_EQ(subject.getNumCitizens(), 1);


}

TEST_F(SubjectTest, testRemovingCitizensFromSimulation){

    Citizen* newCitizen = new Citizen();

    subject.addCitizenToSimulation(newCitizen);
    subject.removeCitizenFromSimulation(newCitizen);

    EXPECT_EQ(subject.getNumCitizens(), 0);

}