#pragma once

#include "bond.h"
#include "share.h"
#include "preciousMetal.h"
#include "realEstate.h"
#include <map>

// MongoDB related includes
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <mongocxx/client.hpp>


class Portfolio
{
private:

    std::map<std::string, Bond>             m_bonds;
    std::map<std::string, Share>            m_shares;
    std::map<std::string, PreciousMetal>    m_preciousMetals;
    std::map<std::string, RealEstate>       m_realEstates;

public:
    Portfolio();
    ~Portfolio();
    void getPortfolioFromDB(mongocxx::collection& collection);
    void updatePortfolioInDB(mongocxx::collection& collection);
};

