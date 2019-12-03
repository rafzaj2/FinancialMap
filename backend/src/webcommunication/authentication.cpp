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

    auto collection = getUsersCollection();

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
    LOGGER_WRITE(Logger::DEBUG, "Start of executing registration procedure")

    json userData = json::parse(request.body());
    string login = userData["Username"];
    string email = userData["Email"];
    string password = userData["Password"];

    auto collection = getUsersCollection();

    std::optional<User> UserWithLogin = findUser(login, SearchType::LOGIN, collection);
    std::optional<User> UserWithemail = findUser(email, SearchType::EMAIL, collection);

    if (UserWithLogin)
    {
        string errorMessage = "User with the same login already exists";
        LOGGER_WRITE(Logger::DEBUG, errorMessage)

        // Returne Status code is 200 insead of 409 like in Gmail, Facebook, Twitter and Amazon
        response.send(Http::Code::Ok, errorMessage);

    }
    else if (!UserWithLogin && UserWithemail)
    {
        string errorMessage = "User with the same email already exists";
        LOGGER_WRITE(Logger::DEBUG, errorMessage)

        // Returne Status code is 200 insead of 409 like in Gmail, Facebook, Twitter and Amazon
        response.send(Http::Code::Ok, errorMessage);
    }
    else
    {
        addUserAccountToDB(login, email, password, collection);
        response.send(Http::Code::Created);
    }

    LOGGER_WRITE(Logger::DEBUG, "End of executing registration procedure")
}

/**********************************************************************************************************************/

std::optional<User> Auth::findUser(const string& keyValue, SearchType searchType, mongocxx::collection& collection)
{
    std::cout << "User: " << keyValue.c_str() << " searching" << std::endl;

    string keyForSearching;

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

    bsoncxx::stdx::optional<bsoncxx::document::value> userDocument = collection.find_one(view);

    if (userDocument)
    {
        LOGGER_WRITE(Logger::DEBUG, "User found in Users collection in DB")
        User user(userDocument);
        return user;
    }
    else
    {
        LOGGER_WRITE(Logger::DEBUG, "User not found in Users collection in DB")
        return std::nullopt;
    }

    
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


void Auth::addUserAccountToDB(const string login, const string email, const string password, mongocxx::collection& collection)
{
    LOGGER_WRITE(Logger::DEBUG, "Adding user to Data Base")
    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::document::value doc_value = builder
    << "login" << login
    << "password" << password
    << "user_id" << 0
    << "email" << email
    << bsoncxx::builder::stream::finalize;

    bsoncxx::document::view view = doc_value.view();
    collection.insert_one(view);

}



const mongocxx::collection Auth::getUsersCollection()
{
    return dbController->getCollection("users");
}