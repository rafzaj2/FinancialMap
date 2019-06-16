#include <pistache/endpoint.h>
#include <iostream>

using namespace Pistache;

struct HelloHandler : public Http::Handler {
  int counter;
  HTTP_PROTOTYPE(HelloHandler)
  void onRequest(const Http::Request& request, Http::ResponseWriter writer) override{
    printinfo();
    std::cout << "Pistache got request: " << request.method() << std::endl;
    std::cout << "Method = " << request.method() << std::endl;
    std::cout << "Body = " << request.body() << std::endl;
    //std::cout << "Headers = " << request.headers().get << std::endl;

    writer.send(Http::Code::Ok, "Hello, World!");
  }
  void printinfo()
  {
    counter++;
    std::cout << "Pistache server is going to send \"Hello World!\" message for the " << counter << " time."<< std::endl;
  }
};

int main() {
  Http::listenAndServe<HelloHandler>("*:9080");
}
