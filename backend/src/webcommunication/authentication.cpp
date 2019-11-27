#include "authentication.h"
#include "logger.h"
#include "user.h"
#include <bsoncxx/json.hpp>
#include <mongocxx/stdx.hpp>
#include <bsoncxx/stdx/optional.hpp>





void Auth::setupRoutes()
{
    using namespace Rest;
    Routes::Post(*router, "/login", Routes::bind(&Auth::doPostLogin, this));
    Routes::Post(*router, "/register", Routes::bind(&Auth::doPostRegister, this));
}

/**********************************************************************************************************************/

void Auth::doPostLogin(const Rest::Request& request, Http::ResponseWriter response)
{
    std::cout << "doPostLogin function executing" << std::endl;

    json userData = json::parse(request.body());
    string login = userData["Username"];
    string password = userData["Password"];

    auto collection = dbController->getCollection("users");
    User user;

    try
    {
        bool userExistence = findUser(login, SearchType::LOGIN, collection, user);

        if (userExistence)
        {
            if (password == user.getPassword())
            {
                //To be done
                response.send(Http::Code::Not_Implemented);
            }
            else
            {
                //To be done
                response.send(Http::Code::Not_Implemented);
            }
        }
        else
        {
            response.send(Http::Code::Not_Found);
        }
    }
    catch (string s)
    {
        LOGGER_WRITE(Logger::ERROR, s)
    }

}

/**********************************************************************************************************************/

void Auth::doPostRegister(const Rest::Request& request, Http::ResponseWriter response)
{
    std::cout << "doPUTRegister function executing" << std::endl;

    json userData = json::parse(request.body());
    string login = userData["Username"];
    string email = userData["Email"];
    string password = userData["Password"];

    auto collection = dbController->getCollection("users");
    bool userExistence;
    User user;

    try
    {
        userExistence = findUser(login, SearchType::EMAIL, collection, user);

        if (userExistence)
        {
            //Here is case when an account with a given login or email already exists
            response.send(Http::Code::Not_Implemented);
        }
        else
        {
            createUserAccount(login, email, password, collection);
            response.send(Http::Code::Not_Implemented);
        }
    }
    catch (string s)
    {
        LOGGER_WRITE(Logger::ERROR, s)
    }

    std::cout << "Json userData = " << userData << std::endl;


    response.send(Http::Code::Not_Implemented);
}

/**********************************************************************************************************************/

bool Auth::findUser(string& keyValue, SearchType searchType, mongocxx::collection& collection, User& user)
{

    string keyForSearching;

    try
    {
        keyForSearching = makeKeyForSearching(searchType);
    }
    catch (string s)
    {
        LOGGER_WRITE(Logger::ERROR, s)
        return false;
    }

    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::document::value doc_value = builder
        << keyForSearching << keyValue
        << bsoncxx::builder::stream::finalize;

    bsoncxx::document::view view = doc_value.view();

    try
    {
        bsoncxx::stdx::optional<bsoncxx::document::value> userDocument = collection.find_one(view);
        user.createUserFromDocument(userDocument);
        //cout << bsoncxx::to_json(users.value()) << endl;
        LOGGER_WRITE(Logger::INFO, "Searching user in users collection successfuly finished")
    }
    catch (...)
    {
        LOGGER_WRITE(Logger::INFO, "Searching user in users collection complited without success")
        return false;
    }

    return true;
}

/**********************************************************************************************************************/

string Auth::makeKeyForSearching(SearchType searchType)
{
    if (searchType == SearchType::EMAIL)
    {
        return "email";
    }
    else if (searchType == SearchType::LOGIN)
    {
        return "login";
    }
    else
    {
        throw "Auth::makeKeyForSearching incorrect search type";
    }
}



void Auth::createUserAccount(string login, string email, string password, mongocxx::collection& collection)
{

}



// bool Auth::addUser(string login, string passworOrEmail, mongocxx::collection collection)
// {

//     return 0;
// }