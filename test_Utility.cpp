#include <gtest/gtest.h>
#include "Utility.h"
#include "PowerPlantFactory.h"
#include "SewageSystemFactory.h"
#include "WasteManagementFactory.h"
#include "WaterSupplyFactory.h"
#include "HealthCareFactory.h"
#include "EducationFactory.h"
#include "LawEnforcementFactory.h"
#include "PowerPlant.h"
#include "SewageSystem.h"
#include "WasteManagement.h"
#include "WaterSupply.h"

class UtilitiesTest : public ::testing::Test {

};

TEST_F(UtilitiesTest, Initialization) {

    PowerPlantFactory* ppf1 = new PowerPlantFactory();
    Utility* p1 = ppf1->createUtility(100, 20000);
    EXPECT_EQ(p1->getUtilityType(), "PowerPlant");
    EXPECT_EQ(p1->getCapacity(), 100);

    SewageSystemFactory* ssf1 = new SewageSystemFactory();
    Utility* s1 = ssf1->createUtility(50, 30000);
    EXPECT_EQ(s1->getUtilityType(), "SewageSystem");
    EXPECT_EQ(s1->getCapacity(), 50);

    WasteManagementFactory* wmf1 = new WasteManagementFactory();
    Utility* wm1 = wmf1->createUtility(30, 10000);
    EXPECT_EQ(wm1->getUtilityType(), "WasteManagement");
    EXPECT_EQ(wm1->getCapacity(), 30);

    WaterSupplyFactory* wsf1 = new WaterSupplyFactory();
    Utility* ws1 = wsf1->createUtility(40, 21000);
    EXPECT_EQ(ws1->getUtilityType(), "WaterSupply");
    EXPECT_EQ(ws1->getCapacity(), 40);

    HealthCareFactory* hcf1 = new HealthCareFactory();
    Utility* hc1 = hcf1->createUtility(40, 21000);
    EXPECT_EQ(hc1->getUtilityType(), "PublicService");
    EXPECT_EQ(hc1->getCapacity(), 40);

    EducationFactory* ef1 = new EducationFactory();
    Utility* e1 = ef1->createUtility(40, 21000);
    EXPECT_EQ(e1->getUtilityType(), "PublicService");
    EXPECT_EQ(e1->getCapacity(), 40);

    LawEnforcementFactory* lef1 = new LawEnforcementFactory();
    Utility* le1 = lef1->createUtility(40, 21000);
    EXPECT_EQ(le1->getUtilityType(), "PublicService");
    EXPECT_EQ(le1->getCapacity(), 40);

}

