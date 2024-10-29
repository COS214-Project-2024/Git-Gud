#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Subject.h"
#include "Citizen.h"
#include "ChangeData.h"
#include <pthread.h>

// Mock class for Citizen
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



