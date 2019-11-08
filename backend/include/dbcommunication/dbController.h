#pragma once

/*****************************************************************************/
/****************includes section*********************************************/
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/types.hpp>
#include <iostream>
#include <string>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>

#include <unistd.h>


/*****************************************************************************/
/****************using section should be moved to cpp file********************/
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::open_document;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::finalize;
using namespace std;




/*
DbController should be responsible for:
-creating database
-searching in database
-downloading from database
-updating database
-deleting given database
-deleting given record
*/



class DbController
{
private:
    mongocxx::instance  m_instance{}; // This should be done only once.
    mongocxx::client    m_client{mongocxx::uri{}};
    mongocxx::database  m_db;

    unsigned int        setDb(string collName);
    unsigned int        initDb();
    unsigned int        initCollections();
    unsigned int        initUsersColl();

public:
    unsigned int        createDb(string dbName);
    unsigned int        deleteDb(string dbName);
    unsigned int        deleteCollection(string collName);
    unsigned int        downloadDb(string dbName);
    unsigned int        downloadColl(string collName);
    unsigned int        updateDb(string dbName);
    unsigned int        updateColl(string collName);
    unsigned int        init();
    mongocxx::collection    getCollection(string CollName);
    


};