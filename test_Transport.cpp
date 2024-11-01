#include <gtest/gtest.h>
#include "TrafficBuilding.h"
#include "TrafficBuildingFactory.h"
#include "TrafficSimulation.h"

class TransportTest : public ::testing::Test {};

TEST_F(TransportTest, Initialization) {
    
    TrafficBuildingFactory* tbf1 = new TrafficBuildingFactory();
    TrafficBuilding* tb1 = tbf1->createTrafficBuilding(TAXI, 20); 
    EXPECT_EQ(tb1->getTransportType(), TAXI);

    TrafficBuilding* tb2 = tbf1->createTrafficBuilding(BUS, 50); 
    EXPECT_EQ(tb2->getTransportType(), BUS);

    TrafficBuilding* tb3 = tbf1->createTrafficBuilding(TRAIN, 120); 
    EXPECT_EQ(tb3->getTransportType(), TRAIN);

    TrafficBuilding* tb4 = tbf1->createTrafficBuilding(AIRPORT, 250); 
    EXPECT_EQ(tb4->getTransportType(), AIRPORT);
}

TEST_F(TransportTest, Simulation) {
    
    TrafficSimulation* ts1 = new TrafficSimulation();
    ts1->addTrafficBuilding(TAXI, 20);
    ts1->addTrafficBuilding(TAXI, 20);
    ts1->addTrafficBuilding(BUS, 50);
    ts1->addTrafficBuilding(BUS, 50);
    ts1->addTrafficBuilding(TRAIN, 120);
    ts1->addTrafficBuilding(TRAIN, 120);
    ts1->addTrafficBuilding(AIRPORT, 250);

    ts1->initializeTrafficFlow();

    EXPECT_EQ(ts1->getNumStations(TAXI), 2);
    EXPECT_EQ(ts1->getNumStations(BUS), 2);
    EXPECT_EQ(ts1->getNumStations(TRAIN), 2);
    EXPECT_EQ(ts1->getNumStations(AIRPORT), 1);
    
    EXPECT_EQ(ts1->getTransportTypeString(TAXI), "Taxi");
    EXPECT_EQ(ts1->getTransportTypeString(BUS), "Bus");
    EXPECT_EQ(ts1->getTransportTypeString(TRAIN), "Train");
    EXPECT_EQ(ts1->getTransportTypeString(AIRPORT), "Airport");
    
    
}

