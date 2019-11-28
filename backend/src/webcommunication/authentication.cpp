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
    LOGGER_WRITE(Logger::DEBUG, "Start of executing login procedure")

    json userData = json::parse(request.body());
    string login = userData["Username"];
    string password = userData["Password"];

    auto collection = dbController->getCollection("users");

    try
    {
        std::optional<User> user = findUser(login, SearchType::LOGIN, collection);

        if (user)
        {
            if (password == user->getPassword())
            {
                LOGGER_WRITE(Logger::DEBUG, "password given by the user is correct")
                //To be done
                response.send(Http::Code::Not_Implemented);
            }
            else
            {
                LOGGER_WRITE(Logger::DEBUG, "password given by the user is incorrect")
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

    LOGGER_WRITE(Logger::DEBUG, "End of executing login procedure")

}

/**********************************************************************************************************************/

void Auth::doPostRegister(const Rest::Request& request, Http::ResponseWriter response)
{
    LOGGER_WRITE(Logger::DEBUG, "Start of executing register procedure")

    json userData = json::parse(request.body());
    string login = userData["Username"];
    string email = userData["Email"];
    string password = userData["Password"];

    auto collection = dbController->getCollection("users");

    std::optional<User> user = findUser(login, SearchType::EMAIL, collection);

    if (user)
    {
        //Here is case when an account with a given login or email already exists
        response.send(Http::Code::Not_Implemented);
    }
    else
    {
        createUserAccount(login, email, password, collection);
        response.send(Http::Code::Not_Implemented);
    }


    std::cout << "Json userData = " << userData << std::endl;


    response.send(Http::Code::Not_Implemented);
    LOGGER_WRITE(Logger::DEBUG, "End of executing register procedure")
}

/**********************************************************************************************************************/

std::optional<User> Auth::findUser(const string& keyValue, SearchType searchType, mongocxx::collection& collection)
{

    string keyForSearching;
    std::optional<User> user;

    try
    {
        keyForSearching = makeKeyForSearching(searchType);
    }
    catch (string s)
    {
        LOGGER_WRITE(Logger::ERROR, s)
        return std::nullopt;
    }

    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::document::value doc_value = builder
        << keyForSearching << keyValue
        << bsoncxx::builder::stream::finalize;

    bsoncxx::document::view view = doc_value.view();

    try
    {
        bsoncxx::stdx::optional<bsoncxx::document::value> userDocument = collection.find_one(view);
        User user(userDocument);
        LOGGER_WRITE(Logger::DEBUG, "user found in Users collection in DB")
    }
    catch (...)
    {
        LOGGER_WRITE(Logger::DEBUG, "user not found in Users collection in DB")
        return std::nullopt;
    }

    return user;
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


void Auth::createUserAccount(const string login,const string email, const string password, mongocxx::collection& collection)
{

}