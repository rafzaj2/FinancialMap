#include <pistache/endpoint.h>
#include <iostream>
#include <nlohmann/json.hpp>

using namespace Pistache;
using json = nlohmann::json; 

struct HelloHandler : public Http::Handler {
  int counter;
  HTTP_PROTOTYPE(HelloHandler)
  void onRequest(const Http::Request& request, Http::ResponseWriter writer) override{

    std::cout << "Pistache got request: " << request.method() << std::endl;
    std::cout << "Method = " << request.method() << std::endl;
    std::cout << "Body = " << request.body() << std::endl;
    auto myHeader = request.headers().getRaw("x-raw-header");
    std::cout << "Header name is " << myHeader.name() << std::endl;
    std::cout << "Header value is " << myHeader.value() << std::endl;

    json userData = json::parse(request.body());


    std::cout << "Json userData = " << userData << std::endl;

    writer.send(Http::Code::Ok, "<html>Hello, World!</html>");
  }
};

int main() {
  Http::listenAndServe<HelloHandler>("*:9080");
}


int loginProcedure(json)
{
  //Todo
}
int registerProcedure(json)
{
  //Todo
}
