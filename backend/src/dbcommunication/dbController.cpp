/*****************************************************************************/
/****************includes section*********************************************/
#include "dbController.h"


unsigned int  DbController::createDb(string dbName)
{
    return 0;
}

unsigned int  DbController::init()
{
    initDb();
    initCollections();


    return 0;
}

unsigned int  DbController::initCollections()
{
    initUsersColl();

    return 0;
}


unsigned int  DbController::initUsersColl()
{
    if (1)
    {
        mongocxx::collection coll = m_db["users"]; //If the collection you request does not exist, MongoDB creates it when you first store data.
        const string doc = {};
        
    }
    return 0;
}


unsigned int  DbController::initDb()
{
    m_db = m_client["financialmap"];


    return 0;
}