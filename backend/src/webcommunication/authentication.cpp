#include "authentication.h"
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
    string user = userData["Username"];
    string password = userData["Password"];

    auto collection = dbController->getCollection("users"); 

    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::document::value doc_value = builder
        << "login" << user
        << "password" << password
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
        response.send(Http::Code::Not_Found);
        return;
    }

    response.send(Http::Code::Not_Implemented);
}

void Auth::doPostRegister(const Rest::Request& request, Http::ResponseWriter response)
{
    std::cout << "doPUTRegister function executing" << std::endl;

    json userData = json::parse(request.body());
    std::cout << "Json userData = " << userData << std::endl;

    response.send(Http::Code::Not_Implemented);
}
