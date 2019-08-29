//#include "authentication.h"
#include "../include/authentication.h"

void Auth::setupRoutes()
{
    using namespace Rest;
    Routes::Post(*router, "/login", Routes::bind(&Auth::doPostLogin, this));
    Routes::Post(*router, "/register", Routes::bind(&Auth::doPostRegister, this));
}

void Auth::doPostLogin(const Rest::Request& request, Http::ResponseWriter response)
{
    std::cout << "doPUTLogin function executing" << std::endl;

    json userData = json::parse(request.body());
    std::cout << "Json userData = " << userData << std::endl;

    response.send(Http::Code::Not_Implemented);
}

void Auth::doPostRegister(const Rest::Request& request, Http::ResponseWriter response)
{
    std::cout << "doPUTRegister function executing" << std::endl;
    response.send(Http::Code::Not_Implemented);
}
