#include "../include/investments/investment.h"
#include <gtest/gtest.h>
 
TEST(InvestmentClassSuite, calculateInvestmentReturn)
{
    Investment investment(100, 120);
    ASSERT_EQ(1.2, investment.calculateInvestmentReturn(InvestmentRetrunPeriod::TOTAL));
    ASSERT_EQ(1.2, investment.calculateInvestmentReturn(InvestmentRetrunPeriod::D1));
    ASSERT_EQ(1.2, investment.calculateInvestmentReturn());
}
TEST(InvestmentClassSuite, Getters)
{
    Investment investment(100, 120);
    ASSERT_EQ(100, investment.getInitialValue());
    ASSERT_EQ(120, investment.getCurrentValue());
}
TEST(InvestmentClassSuite, Setters)
{
    Investment investment(100, 120);
    investment.setInitialValue(200);
    investment.setCurrentValue(250);
    ASSERT_EQ(200, investment.getInitialValue());
    ASSERT_EQ(250, investment.getCurrentValue());
}


int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}