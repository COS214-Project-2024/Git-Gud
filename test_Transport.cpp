#include <gtest/gtest.h>
#include "TrafficBuilding.h"
#include "TrafficBuildingFactory.h"
#include "Transportation.h"

class TransportTest : public ::testing::Test {};

TEST_F(TransportTest, Initialization) {
    
    TrafficBuildingFactory* tbf1 = new TrafficBuildingFactory();
    TrafficBuilding* tb1 = tbf1->createTrafficBuilding(TAXI); 
    EXPECT_EQ(tb1->getTransportType(), TAXI);

    TrafficBuilding* tb2 = tbf1->createTrafficBuilding(BUS); 
    EXPECT_EQ(tb2->getTransportType(), BUS);

    TrafficBuilding* tb3 = tbf1->createTrafficBuilding(TRAIN); 
    EXPECT_EQ(tb3->getTransportType(), TRAIN);

    TrafficBuilding* tb4 = tbf1->createTrafficBuilding(AIRPORT); 
    EXPECT_EQ(tb4->getTransportType(), AIRPORT);
}

TEST_F(TransportTest, Simulation) {

    Transportation* ts1 = new Transportation();

    //Add citizens to subject
    ts1->addCitizenToSimulation(new Citizen());
    ts1->addCitizenToSimulation(new Citizen());
    ts1->addCitizenToSimulation(new Citizen());
    ts1->addCitizenToSimulation(new Citizen());
    ts1->addCitizenToSimulation(new Citizen());
    ts1->addCitizenToSimulation(new Citizen());
    ts1->addCitizenToSimulation(new Citizen());
    ts1->addCitizenToSimulation(new Citizen());
    ts1->addCitizenToSimulation(new Citizen());
    ts1->addCitizenToSimulation(new Citizen());
    ts1->addCitizenToSimulation(new Citizen());
    ts1->addCitizenToSimulation(new Citizen());
    ts1->addCitizenToSimulation(new Citizen());
    ts1->addCitizenToSimulation(new Citizen());
    ts1->addCitizenToSimulation(new Citizen());
    ts1->addCitizenToSimulation(new Citizen());
    ts1->addCitizenToSimulation(new Citizen());
    ts1->addCitizenToSimulation(new Citizen());

    //Add one Taxi Station
    ts1->addTrafficBuilding(TAXI);

    ts1->initializeTrafficFlow();

    ts1->calculateTrafficFlow();
    std::cout << "Num citizens: " << ts1->getNumCitizens() << std::endl;

    std::cout << "Total traffic capacity: " << ts1->getTotalTrafficCapacity() << std::endl;

    ts1->addTrafficBuilding(TAXI);
    ts1->addTrafficBuilding(BUS);
    ts1->addTrafficBuilding(BUS);
    ts1->addTrafficBuilding(TRAIN);
    ts1->addTrafficBuilding(TRAIN);
    ts1->addTrafficBuilding(AIRPORT);
    
    ts1->initializeTrafficFlow();

    EXPECT_EQ(ts1->getNumStations(TAXI), 2);
    EXPECT_EQ(ts1->getNumStations(BUS), 2);
    EXPECT_EQ(ts1->getNumStations(TRAIN), 2);
    EXPECT_EQ(ts1->getNumStations(AIRPORT), 1);
    
    EXPECT_EQ(ts1->getTransportTypeString(TAXI), "Taxi");
    EXPECT_EQ(ts1->getTransportTypeString(BUS), "Bus");
    EXPECT_EQ(ts1->getTransportTypeString(TRAIN), "Train");
    EXPECT_EQ(ts1->getTransportTypeString(AIRPORT), "Airport");

    ts1->calculateTrafficFlow();
    std::cout << "Num citizens: " << ts1->getNumCitizens() << std::endl;

    std::cout << "Total traffic capacity: " << ts1->getTotalTrafficCapacity() << std::endl;

    

}

