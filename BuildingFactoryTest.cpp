#include <gtest/gtest.h>
#include "CommercialBuildingFactory.h"
#include "BuildingWithCoffeeShopFactory.h"

TEST(CommercialBuildingFactoryTest, construct){
    BuildingFactory* f=new CommercialBuildingFactory();
    Building* b=f->constructBuilding();
    
    EXPECT_EQ(b->getBusinessType(), BusinessType::GENERAL);
}

TEST(CoffeeShopFactoryTest, construct){
    BuildingFactory* f=new BuildingWithCoffeeShopFactory();
    Building* old=new CommercialBuilding(50,100,3,BusinessType::GENERAL);
    Building* b=f->upgradeBuilding(old);
    CommercialBuilding* c=static_cast<CommercialBuilding*>(b);

    EXPECT_EQ(c->getBusinessType(), BusinessType::GENERAL);
}
