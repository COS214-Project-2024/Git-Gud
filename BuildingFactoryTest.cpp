#include <gtest/gtest.h>
#include <memory>  // For smart pointers
#include "CommercialBuildingFactory.h"
#include "BuildingWithCoffeeShopFactory.h"
#include "BuildingWithParkingFactory.h"
#include "IndustrialBuildingFactory.h"

TEST(CommercialFact, cost){
    BuildingFactory* b=new CommercialBuildingFactory();
    b->Rmanager->initializeResources(50,50,50,50);
    b->Rmanager->addResource("energySupply",50);
    Building* c=b->constructBuilding();

    if (c != nullptr){
        EXPECT_EQ(c->getCost(),50000);
    }
    delete c;
    delete b;
}

TEST(CoffeeShopFact,cost){
    BuildingFactory* b=new CommercialBuildingFactory();
    b->Rmanager->initializeResources(50,50,50,50);
    b->Rmanager->addResource("energySupply",50);
    Building* c=b->constructBuilding();

    BuildingFactory* d=new BuildingWithCoffeeShopFactory();
    d->Rmanager->initializeResources(50,50,50,50);
    d->Rmanager->addResource("energySupply",50);
    Building * e=d->upgradeBuilding(c);

    if (e != nullptr){
        EXPECT_EQ(e->getCost(), 55000);
    }

    delete e;
    delete d;
    delete b;

}

TEST(ParkingCoffee, cost){
    BuildingFactory* b=new IndustrialBuildingFactory();
    b->Rmanager->initializeResources(50,50,50,50);
    b->Rmanager->addResource("energySupply",50);
    Building* c=b->constructBuilding();

    BuildingFactory* d=new BuildingWithCoffeeShopFactory();
    d->Rmanager->initializeResources(50,50,50,50);
    d->Rmanager->addResource("energySupply",50);
    Building * e=d->upgradeBuilding(c);

    BuildingFactory* f=new BuildingWithParkingFactory();
    f->Rmanager->initializeResources(50,50,50,50);
    f->Rmanager->addResource("energySupply",50);
    Building* g=f->upgradeBuilding(e);

    if (g != nullptr){
        EXPECT_EQ(g->getCost(), 65000);
    }

    delete g;
    delete f;
    delete d;
    delete b;

}

TEST(CommercialClone, BusinessType){
    BuildingFactory* b=new CommercialBuildingFactory();
    b->Rmanager->initializeResources(50,50,50,50);
    b->Rmanager->addResource("energySupply",50);
    Building* c=b->constructBuilding();

    Building* d=b->cloneBuilding(c);

    if (d != nullptr){
        EXPECT_EQ(c->getBusinessType(), d->getBusinessType());
    }

    delete d;
    delete c;
    delete b;

}

/*TEST(CoffeeParkingClone, BusinessType){
    BuildingFactory* b=new CommercialBuildingFactory();
    b->Rmanager->initializeResources(50,50,50,50);
    b->Rmanager->addResource("energySupply",50);
    Building* c=b->constructBuilding();

    BuildingFactory* d=new BuildingWithCoffeeShopFactory();
    d->Rmanager->initializeResources(50,50,50,50);
    d->Rmanager->addResource("energySupply",50);
    Building * e=d->upgradeBuilding(c);

    BuildingFactory* f=new BuildingWithParkingFactory();
    f->Rmanager->initializeResources(50,50,50,50);
    f->Rmanager->addResource("energySupply",50);
    Building* g=f->upgradeBuilding(e);
    Building* h=f->cloneBuilding(g);
    //std::cout << (h == nullptr) << std::endl;
    if (g != nullptr){
        EXPECT_EQ(g->getBusinessType(), BusinessType::GENERAL);
    }

    delete g;
    delete f;
    delete d;
    delete b;
    delete h;

}*/

/*int main(){
    BuildingFactory* b=new CommercialBuildingFactory();
    b->Rmanager->initializeResources(50,50,50,50);
    b->Rmanager->addResource("energySupply",50);
    Building* c=b->constructBuilding();

    BuildingFactory* d=new BuildingWithCoffeeShopFactory();
    d->Rmanager->initializeResources(50,50,50,50);
    d->Rmanager->addResource("energySupply",50);
    Building * e=d->upgradeBuilding(c);

    BuildingFactory* f=new BuildingWithParkingFactory();
    f->Rmanager->initializeResources(50,50,50,50);
    f->Rmanager->addResource("energySupply",50);
    Building* g=f->upgradeBuilding(e);
    Building* h=f->cloneBuilding(g);

    delete g;
    delete f;
    delete d;
    delete b;
    delete h;

}*/

    
