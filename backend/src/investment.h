#pragma once

/*****************************************************************************/
/****************includes section*********************************************/

#include <chrono>
#include <ctime>




//enums

enum Country
{
    USA = 0,
    GBP = 1,
    PL = 2
};

enum Stock
{
    NASDAQ = 0,
    LSE = 1,
    GPW = 2
};

//enum classes

enum class InvestmentRetrunPeriod
{
    TOTAL = 0,
    D1 = 1,
    D3 = 3,
    D5 = 5,
    D10 = 10,
    M1 = 30,
    M3 = 90,
    M6 = 180,
    YTD = 200,
    Y1 = 365,
    Y3 = 1095,
    Y5 = 1825,
    Y10 = 3650,
    Y20 = 7300
};


/*****************************************************************************/
/****************class declarations*******************************************/

class Investment
{
private:
    const int m_id;
    double m_intialValue;
    double m_currentValue;
public:
    Investment(double initialValue, double currentValue);
    Investment(double initialValue);
    Investment();
    virtual ~Investment();
    double getInitialValue();
    double getCurrentValue();
    double calculateInvestmentReturn();
    double calculateInvestmentReturn(const InvestmentRetrunPeriod period);
    double getHistoricalAssetValue(std::time_t periodTime);
    virtual void identify() const;
};


