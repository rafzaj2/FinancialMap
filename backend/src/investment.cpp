#include "investment.h"
#include <iostream>
#include <chrono>
#include <ctime> 


using namespace std;
using namespace std::chrono;

/* Investment class function definitions */

Investment::Investment(double initialValue, double currentValue)
    : m_id(1), m_intialValue(initialValue), m_currentValue(currentValue)
{

}

Investment::Investment(double initialValue)
    : m_id(1), m_intialValue(initialValue), m_currentValue(initialValue)
{

}

Investment::Investment()
    : m_id(1), m_intialValue(0.00), m_currentValue(0.00)
{

}

Investment::~Investment()
{

}

double Investment::getInitialValue()
{
    return m_intialValue;
}

double Investment::getCurrentValue()
{
    return m_currentValue;
}

double Investment::calculateInvestmentReturn(const InvestmentRetrunPeriod period)
{
    int periodInday = static_cast<int>(period);
    int periodInSeconds = periodInday * 24 * 60 * 60;
    std::chrono::time_point<std::chrono::system_clock> currentTime;
    currentTime = std::chrono::system_clock::now();
    std::time_t currentDate = std::chrono::system_clock::to_time_t(currentTime);
    std::time_t periodDate(static_cast<int>(currentDate) - periodInSeconds);
    

    cout << "Period date is equal to " << std::ctime(&periodDate) << endl;
    cout << "Start date is equal to " << std::ctime(&currentDate) << endl;
    

    double comparedValue = getHistoricalAssetValue(periodDate);
    return m_currentValue / comparedValue;
}

double Investment::getHistoricalAssetValue(std::time_t periodTime)
{
    cout << "getHistoricalAssetValue function is not implemented yet" << endl;
    return 1.00;
}


void Investment::identify() const
{
    cout << "\nObject identyfication...\nObejct is an Investment class type";
}

/****************Share Class********************************************/

Share::Share(double initialValue, double currentValue, Country country, Stock stock)
    : Investment(initialValue, currentValue),
         m_country(country), m_stock(stock)
{
    cout << "\nShare class constructor";  
}

Share::Share(Country country, Stock stock)
    : Investment(),
        m_country(country), m_stock(stock)
{
    cout << "\nShare class constructor";  
}

Share::~Share()
{
    cout << "\nShare class destructor";  
}

void Share::identify() const
{
    cout << "\nObject identyfication...\nObejct is an Share class type";
}

/***** Main function written in testing purposes ************/

int main(int argc, char const *argv[])
{
    InvestmentRetrunPeriod oneDay = InvestmentRetrunPeriod::D1;
    Investment invest(100.00);
    double returnRate = invest.calculateInvestmentReturn(oneDay);
    cout << "Retrun rate from investition is " << returnRate << endl;

    return 0;
}


