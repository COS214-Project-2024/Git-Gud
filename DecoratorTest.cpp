#include "BuildingWithCoffeeshop.h"
#include "BuildingWithParking.h"
#include "CommercialBuilding.h"
#include "IndustrialBuilding.h"
#include "ResidentialBuilding.h"
#include <sstream>
#include <gtest/gtest.h>

TEST(CoffeeDecoratorTest, Cost){
    Building* c=new CommercialBuilding(50, 100, 3, BusinessType::FOOD);
    Building* d=new BuildingWithCoffeeShop(c);
    float f=55000;
    EXPECT_EQ(d->getCost(), f);
}

TEST(ParkingDecoratorTest, Service){
    Building* b=new IndustrialBuilding(50,100,3,Industry::ENERGY,2);
    Building* d=new BuildingWithParking(b);
    
    std::stringstream buffer;
    std::streambuf* oldBuf=std::cout.rdbuf(buffer.rdbuf());

    d->provideService();

    std::cout.rdbuf(oldBuf);

    EXPECT_EQ(buffer.str(), "Building is generating energy and provides parking");
}

TEST(DecoratorStateTest, State){
    Building* b= new ResidentialBuilding(new UnderConstruction(),5);
    Building* d=new BuildingWithCoffeeShop(b);

    EXPECT_EQ(d->currentState(), "UnderConstruction");
}

TEST(DecorateDecorator, Service){
    Building* b=new ResidentialBuilding(50);
    Building* d=new BuildingWithCoffeeShop(b);
    Building* dd=new BuildingWithParking(d);

    std::stringstream buffer;
    std::streambuf* oldBuf=std::cout.rdbuf(buffer.rdbuf());

    dd->provideService();

    std::cout.rdbuf(oldBuf);

    EXPECT_EQ(buffer.str(), "Provide services to residents and serves coffee and provides parking");
    
}