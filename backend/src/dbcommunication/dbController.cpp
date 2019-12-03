/*****************************************************************************/
/****************includes section*********************************************/
#include "dbController.h"
#include "logger.h"


using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;


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
    if (!(m_db.has_collection("users")))
    {
        cout << "initUsersColl() function ..." << endl;
        LOGGER_WRITE(Logger::CONFIG, "Start of initialization of users collection")
        mongocxx::collection coll = m_db["users"]; //If the collection you request does not exist, MongoDB creates it when you first store data.


        //create a unique index
        mongocxx::options::index index_options{};
        index_options.unique(true);
        m_db["users"].create_index(make_document(kvp("login", 1), kvp("email", 1)), index_options);

        //create an admin account in the users collection
        auto builder = bsoncxx::builder::stream::document{};
        bsoncxx::document::value doc_value = builder
        << "login" << "admin"
        << "password" << "admin"
        << "user_id" << 0
        << "email" << "rafzaj2@gmail.com"
        << bsoncxx::builder::stream::finalize;
   
        bsoncxx::document::view view = doc_value.view();

        coll.insert_one(view); // It is to investigate why it duplicate documents in the users collection

        LOGGER_WRITE(Logger::CONFIG, "End of initialization of users collection")
        
    }
    return 0;
}


unsigned int  DbController::initDb()
{
    m_db = m_client["financialmap"];


    return 0;
}

mongocxx::collection DbController::getCollection(string CollName)
{

    return m_db["users"];
}