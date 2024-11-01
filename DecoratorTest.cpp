#include "BuildingWithCoffeeshop.h"
#include "BuildingWithParking.h"
#include "CommercialBuilding.h"
#include "IndustrialBuilding.h"
#include "ResidentialBuilding.h"
#include <sstream>
#include <gtest/gtest.h>

TEST(CoffeeDecoratorTest, Cost){
    Building* c=new CommercialBuilding(50, 100, 3, BusinessType::FOOD);
    Decorator* d=new BuildingWithCoffeeShop(c);
    float f=55000;
    EXPECT_EQ(d->getCost(), f);
}

TEST(ParkingDecoratorTest, Service){
    Building* b=new IndustrialBuilding(50,100,3,Industry::ENERGY,2);
    Decorator* d=new BuildingWithParking(b);
    
    std::stirngstream buffer;
    std::streambuf* oldBuf=std::cout.rdbuf(buffer.rdbuf());

    d->provideService();

    std::cout.rdbuf(oldBuf);

    EXPECT_EQ(buffer.str(), "Building is generating energy and provides parking");
}

TEST(DecoratorStateTest, State){
    Building* b= new ResidentialBuilding(new UnderConstruction(),5);
    Decorator* d=new BuildingWithCoffeeShop(b);

    EXPECT_EQ(d->currentState(), "UnderConstruction");
}