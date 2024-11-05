#include <gtest/gtest.h>
#include "Utility.h"
#include "PowerPlantFactory.h"
#include "SewageSystemFactory.h"
#include "WasteManagementFactory.h"
#include "WaterFilteringPlantFactory.h"  
#include "HealthCareFactory.h"
#include "EducationFactory.h"
#include "LawEnforcementFactory.h"
#include "PowerPlant.h"
#include "SewageSystem.h"
#include "WasteManagement.h"
#include "WaterFilteringPlant.h"

class UtilitiesTest : public ::testing::Test {};

TEST_F(UtilitiesTest, Initialization) {
    // PowerPlant creation
    PowerPlantFactory* ppf1 = new PowerPlantFactory();
    Utility* p1 = ppf1->createUtility(100, 20000);  // Capacity: 100, Maintenance cost: 20000
    EXPECT_EQ(p1->getUtilityType(), "PowerPlant");
    EXPECT_EQ(p1->getCapacity(), 100);

    // SewageSystem creation
    SewageSystemFactory* ssf1 = new SewageSystemFactory();
    Utility* s1 = ssf1->createUtility(50, 30000);  // Capacity: 50, Maintenance cost: 30000
    EXPECT_EQ(s1->getUtilityType(), "SewageSystem");
    EXPECT_EQ(s1->getCapacity(), 50);

    // WasteManagement creation
    WasteManagementFactory* wmf1 = new WasteManagementFactory();
    Utility* wm1 = wmf1->createUtility(30, 10000);  // Capacity: 30, Maintenance cost: 10000
    EXPECT_EQ(wm1->getUtilityType(), "WasteManagement");
    EXPECT_EQ(wm1->getCapacity(), 30);

    // WaterFilteringPlant creation
    WaterFilteringPlantFactory* wfp1 = new WaterFilteringPlantFactory();  
    Utility* wf1 = wfp1->createUtility(40, 21000);  // Filtering capacity: 40, Maintenance cost: 21000
    EXPECT_EQ(wf1->getUtilityType(), "WaterFilteringPlant");
    EXPECT_EQ(wf1->getCapacity(), 40);

    // HealthCare creation
    HealthCareFactory* hcf1 = new HealthCareFactory();
    Utility* hc1 = hcf1->createUtility(40, 21000);  // Capacity: 40, Maintenance cost: 21000
    EXPECT_EQ(hc1->getUtilityType(), "PublicService");
    EXPECT_EQ(hc1->getCapacity(), 40);

    // Education creation
    EducationFactory* ef1 = new EducationFactory();
    Utility* e1 = ef1->createUtility(40, 21000);  // Capacity: 40, Maintenance cost: 21000
    EXPECT_EQ(e1->getUtilityType(), "PublicService");
    EXPECT_EQ(e1->getCapacity(), 40);

    // LawEnforcement creation
    LawEnforcementFactory* lef1 = new LawEnforcementFactory();
    Utility* le1 = lef1->createUtility(40, 21000);  // Capacity: 40, Maintenance cost: 21000
    EXPECT_EQ(le1->getUtilityType(), "PublicService");
    EXPECT_EQ(le1->getCapacity(), 40);

    // Clean up
    delete ppf1;
    delete p1;
    delete ssf1;
    delete s1;
    delete wmf1;
    delete wm1;
    delete wfp1;
    delete wf1;
    delete hcf1;
    delete hc1;
    delete ef1;
    delete e1;
    delete lef1;
    delete le1;
}