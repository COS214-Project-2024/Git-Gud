#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Subject.h"
#include "Citizen.h"
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

    EXPECT_EQ(subject.getNumCitizens(), 1);

}


TEST_F(SubjectTest, testNotifyObservers) {

    auto* mockCitizen1 = new MockCitizen;
    auto* mockCitizen2 = new MockCitizen;
    ChangeData changeData;

    EXPECT_CALL(*mockCitizen1, update(changeData)).Times(1);
    EXPECT_CALL(*mockCitizen2, update(changeData)).Times(1);

    subject.attach(mockCitizen1);
    subject.attach(mockCitizen2);
    subject.notify(changeData);

    subject.detach(mockCitizen1);
    subject.detach(mockCitizen2);
    delete mockCitizen1;
    delete mockCitizen2;

}

TEST_F(SubjectTest, testDetachObserverNoNotify) {

    MockCitizen* mockCitizen = new MockCitizen();
    ChangeData changeData;

    subject.attach(mockCitizen);
    subject.detach(mockCitizen);

    EXPECT_CALL(*mockCitizen, update(changeData)).Times(0);

    subject.notify(changeData);

    delete mockCitizen;

}

TEST_F(SubjectTest, testAttachDetachMultipleObservers) {
    Citizen* citizen1 = new Citizen();
    Citizen* citizen2 = new Citizen();

    subject.attach(citizen1);
    subject.attach(citizen2);

    EXPECT_EQ(subject.getObserverListSize(), 2);

    subject.detach(citizen1);
    EXPECT_EQ(subject.getObserverListSize(), 1);

    subject.detach(citizen2);
    EXPECT_EQ(subject.getObserverListSize(), 0);

    delete citizen1;
    delete citizen2;
    
}