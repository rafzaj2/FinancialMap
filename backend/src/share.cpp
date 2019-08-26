#include "share.h"
#include <iostream>



/****************Share Class********************************************/

Share::Share(Country country, Stock stock, int numberOfShares, double initialValueofShare)
    : Investment(numberOfShares * initialValueofShare),
        m_country(country), m_stock(stock), m_numberOfShares(numberOfShares), m_initialValueofShare(initialValueofShare)
{

}

Share::Share(Country country, Stock stock)
    : Investment(),
        m_country(country), m_stock(stock), m_numberOfShares(0), m_initialValueofShare(0.00)
{

}

Share::~Share()
{

}

void Share::identify() const
{
    std::cout << "\nObject identyfication...\nObejct is an Share class type";
}




