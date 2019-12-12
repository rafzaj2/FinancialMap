#include "portfolio.h"
#include "logger.h"



Portfolio::Portfolio()
{

}
Portfolio::~Portfolio()
{
    
}


void getPortfolioFromDB(mongocxx::collection& collection, int userId)
{
    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::document::value doc_value = builder
        << "user_id" << userId
        << bsoncxx::builder::stream::finalize;

    bsoncxx::document::view view = doc_value.view();

    bsoncxx::stdx::optional<bsoncxx::document::value> portfolioDocument = collection.find_one(view);

    //ToDo 
}
void updatePortfolioInDB(mongocxx::collection& collection)
{
    LOGGER_WRITE(Logger::DEBUG, "Updating user portfolio in Data Base")
    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::document::value doc_value = builder
    << "user_id" << 0
    << "shares" << "ToDo"
    << "precious_metals" << "ToDo"
    << "real_estates" << "ToDo"
    << "bonds" << "ToDo"
    << bsoncxx::builder::stream::finalize;

    bsoncxx::document::view view = doc_value.view();
    collection.insert_one(view);
}