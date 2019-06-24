#include <iostream>
#include <nlohmann/json.hpp>
#include <pistache/http.h>
#include <pistache/router.h>
#include <pistache/endpoint.h>

using namespace Pistache;
using json = nlohmann::json;


// struct BackendHandler : public Http::Handler {
//   int counter;
//   HTTP_PROTOTYPE(BackendHandler)
//   void onRequest(const Http::Request& request, Http::ResponseWriter writer) override{

//     std::cout << "Pistache got request: " << request.method() << std::endl;
//     std::cout << "Method = " << request.method() << std::endl;
//     std::cout << "Body = " << request.body() << std::endl;

//     auto headers = request.headers();

//     auto header = headers.tryGet("Content-Type");

//     if (header == nullptr)
//     {
//       std::cout << "Header is nullptr"<< std::endl;
//     }
//     else
//     {
//       std::cout << "Header exists and his content is: ";
//       header->write(std::cout);
//       std::cout << std::endl;
//     }


//     json userData = json::parse(request.body());

    
//     std::cout << "Json userData = " << userData << std::endl;

//     std::cout << "Pistache server is going to send response" << std::endl;

//     auto mime = Http::Mime::MediaType::fromString("text/plain");

//     auto res = writer.send(Http::Code::Ok, "Authenticated", mime);
//     res.then(
//     [](ssize_t bytes) { std::cout << bytes << " bytes have been sent" << std::endl; },
//     Async::NoExcept
// );
//   }
// };




class StatsEndpoint {
  public:
    StatsEndpoint(Address addr)
      : httpEndpoint(std::make_shared<Http::Endpoint>(addr))
    { }

  void init(size_t thr = 2)
  {
    auto opts = Http::Endpoint::options()
      .threads(thr);
    httpEndpoint->init(opts);
    setupRoutes();
  }

  void start() 
  {
    httpEndpoint->setHandler(router.handler());
    httpEndpoint->serve();
  }

  private:
    void setupRoutes()
    {
      using namespace Rest;

      //Routes::Post(router, "/record/:name/:value?", Routes::bind(&StatsEndpoint::doPutRegister, this));
      Routes::Post(router, "/login", Routes::bind(&StatsEndpoint::doPUTLogin, this));
      //Routes::Get(router, "/ready", Routes::bind(&Generic::handleReady));
      //Routes::Get(router, "/auth", Routes::bind(&StatsEndpoint::doAuth, this));
    }

    void doPUTLogin(const Rest::Request& request, Http::ResponseWriter response)
    {
        std::cout << "doPUTLogin function executing" << std::endl;
    }

    //typedef std::mutex Lock;
    //typedef std::lock_guard<Lock> Guard;
    //Lock metricsLock;
    //std::vector<Metric> metrics;

    std::shared_ptr<Http::Endpoint> httpEndpoint;
    Rest::Router router;
};

int main(int argc, char *argv[]) {
  //Http::listenAndServe<BackendHandler>("*:9080");

  /***************************************************/
  Port port(9080);

  int thr = 2;

  if (argc >=2)
  {
    port = std::stol(argv[1]);

    if (argc == 3)
      thr = std::stol(argv[2]);
  }

  Address addr(Ipv4::any(), port);

  std::cout << "Cores = " << hardware_concurrency() << std::endl;
  std::cout << "Using " << thr << " threads" << std::endl;

  StatsEndpoint stats(addr);

  stats.init(thr);
  stats.start();
}

