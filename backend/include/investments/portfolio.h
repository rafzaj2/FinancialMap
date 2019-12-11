#pragma once

#include "bond.h"
#include "share.h"
#include "preciousMetal.h"
#include "realEstate.h"


class Portfolio
{
private:
    /* data */
    Bond            m_bonds;
    Share           m_shares;
    PreciousMetal   m_preciousMetals;
    RealEstate      m_realEstates;

public:
    Portfolio(/* args */);
    ~Portfolio();
};

