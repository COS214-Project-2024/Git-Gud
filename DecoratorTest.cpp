#include "BuildingWithCoffeeshop.h"
#include "BuildingWithParking.h"
#include "CommercialBuilding.h"
#include "IndustrialBuilding.h"
#include "ResidentialBuilding.h"
#include <sstream>
#include <gtest/gtest.h>

TEST(CoffeeDecoratorTest, Cost){
    Building* a=new CommercialBuilding(50, 100, 3, BusinessType::FOOD);
    Building* b=new BuildingWithCoffeeShop(a);
    float f=55000;
    EXPECT_EQ(b->getCost(), f);
}

/*TEST(ParkingDecoratorTest, Service){
    Building* c=new CommercialBuilding(50, 100, 3, BusinessType::FOOD);
    Building* d=new BuildingWithParking(c);
    
    std::stringstream buffer;
    std::streambuf* oldBuf=std::cout.rdbuf(buffer.rdbuf());

    d->provideService();

    std::cout.rdbuf(oldBuf);

    EXPECT_EQ(buffer.str(), "Building is selling food\n and provides parking\n");
    
}*/

/*TEST(DecoratorStateTest, State){
    Building* b=new IndustrialBuilding(50,100,3,Industry::ENERGY,2);
    Building* d=new BuildingWithParking(b);

    EXPECT_EQ(d->getCost(), 55000);
}*/

TEST(DecorateDecorator, Service){
    Building* b=new ResidentialBuilding(50);
    Building* d=new BuildingWithCoffeeShop(b);
    Building* dd=new BuildingWithParking(d);

    std::stringstream buffer;
    std::streambuf* oldBuf=std::cout.rdbuf(buffer.rdbuf());

    dd->provideService();

    std::cout.rdbuf(oldBuf);

    EXPECT_EQ(buffer.str(), "Provide services to residents\n and serves coffee\n and provides parking\n");
    
}