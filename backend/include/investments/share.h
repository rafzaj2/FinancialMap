#pragma once


/*****************************************************************************/
/****************includes section*********************************************/
#include "investment.h"


class Share : public Investment
{
private:
    Country m_country;
    Stock m_stock;
    int m_numberOfShares;
    double m_initialValueofShare;

public:
    Share() = delete;
    Share(Country country, Stock stock, int numberOfShares, double initialValueofShare);
    Share(Country country, Stock stock);
    virtual ~Share();
    void identify() const;
};