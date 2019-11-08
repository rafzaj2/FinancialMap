#include "authentication.h"

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

    auto collection = dbController->getCollection("users"); 
    int nodoc = collection.count_documents(document{} << "user_id" << 0 << finalize);
    cout << "nodoc is equal to "<< nodoc << endl;

        auto builder = bsoncxx::builder::stream::document{};
        bsoncxx::document::value doc_value = builder
        << "user_id" << 0
        << bsoncxx::builder::stream::finalize;
   
        bsoncxx::document::view view = doc_value.view();

    bsoncxx::stdx::optional<bsoncxx::document::value> maybe_result =
    collection.find_one(view);
    bsoncxx::document::element elem = maybe_result["login"];
    string elemstr = elem.get_utf8().value.to_string()

    if(maybe_result) {
        cout << "maybe result is TRUE";
        //std::cout << bsoncxx::to_json(*maybe_result) << "\n";
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
