#include "authentication.h"
#include "logger.h"
#include <bsoncxx/json.hpp>



void Auth::setupRoutes()
{
    using namespace Rest;
    Routes::Post(*router, "/login", Routes::bind(&Auth::doPostLogin, this));
    Routes::Post(*router, "/register", Routes::bind(&Auth::doPostRegister, this));
}

void Auth::doPostLogin(const Rest::Request& request, Http::ResponseWriter response)
{
    std::cout << "doPostLogin function executing" << std::endl;

    json userData = json::parse(request.body());
    string login = userData["Username"];
    string password = userData["Password"];

    auto collection = dbController->getCollection("users");
    string type("password");
    try
    {
        bool userExistance = findUser(login, password, SearchType::PASSWORD, collection);

        if (userExistance)
        {
            response.send(Http::Code::Not_Implemented);
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

void Auth::doPostRegister(const Rest::Request& request, Http::ResponseWriter response)
{
    std::cout << "doPUTRegister function executing" << std::endl;

    json userData = json::parse(request.body());
    string user = userData["Username"];
    string email = userData["Email"];
    string password = userData["Password"];

    std::cout << "Json userData = " << userData << std::endl;


    response.send(Http::Code::Not_Implemented);
}

bool Auth::findUser(string& login, string& passwordOrEmail, SearchType searchType, mongocxx::collection& collection)
{
    string emailOrPassword;
    if (searchType == SearchType::EMAIL)
    {
        emailOrPassword = "email";
    }
    else if (searchType == SearchType::PASSWORD)
    {
        emailOrPassword = "password";
    }
    else
    {
        throw "Auth::findUser incorrect search type";
    }
    
    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::document::value doc_value = builder
        << "login" << login
        << emailOrPassword << passwordOrEmail
        << bsoncxx::builder::stream::finalize;

    bsoncxx::document::view view = doc_value.view();

    try
    {
        auto users = collection.find_one(view);
        cout << bsoncxx::to_json(users.value()) << endl;
        cout << "Searching user in users collection successfuly finished" << endl;
    }
    catch (...)
    {
        cout << "Searching user in users collection failed" << endl;
        return 1;
    }

    return 0;
}


// bool Auth::addUser(string login, string passworOrEmail, mongocxx::collection collection)
// {

//     return 0;
// }