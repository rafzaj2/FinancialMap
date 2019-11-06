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

    return 0;
}


unsigned int  DbController::initDb()
{
    //mongocxx::database db = m_client["financialmap"];


    return 0;
}