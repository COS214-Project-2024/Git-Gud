#include <gtest/gtest.h>
#include "TaxManager.h"
#include "RetrieveTax.h"

class MockRetrieveTax : public RetrieveTax {
public:
    float retrieveTaxRate() override {
        return 0.15f;
    }
};

TEST(TaxManagerTest, CalculateTax) {
    TaxManager taxManager;
    MockRetrieveTax mockTax;
    taxManager.updateTotalTaxRate(0.2f);
    EXPECT_FLOAT_EQ(taxManager.calculateTax(), 0.2f);
}

TEST(TaxManagerTest, UpdateTotalTaxRate) {
    TaxManager taxManager;
    taxManager.updateTotalTaxRate(0.3f);
    EXPECT_FLOAT_EQ(taxManager.calculateTax(), 0.3f);
}
