#pragma once

#include "bond.h"
#include "share.h"
#include "preciousMetal.h"
#include "realEstate.h"

class Portfolio
{
private:
    Bond            bonds;
    Share           shares;
    PreciousMetal   preciousMetals;
    RealEstate      realEstates;

public:


Portfolio::Portfolio(/* args */)
{
}

Portfolio::~Portfolio()
{
}

};