#include "logger.h"
#include "authentication.h"
#include "investment.h"
#include "dbController.h"
#include <iostream>
#include <pistache/http.h>
#include <pistache/router.h>
#include <pistache/endpoint.h>
#include <chrono>
#include <ctime> 
#include <memory>



using namespace std;
using namespace std::chrono;


class StatsEndpoint {
  public:
    StatsEndpoint(Address addr)
      : httpEndpoint(std::make_shared<Http::Endpoint>(addr)),
        router(std::make_shared<Rest::Router>())
    {}

  void init(size_t thr = 2)
  {
    auto opts = Http::Endpoint::options()
      .threads(thr);
    httpEndpoint->init(opts);
  }

  void start() 
  {
    httpEndpoint->setHandler(router->handler());
    httpEndpoint->serve();
  }
  std::shared_ptr<Rest::Router> getRouter()
  {
    return router;
  }

  private:
    std::shared_ptr<Http::Endpoint> httpEndpoint;
    std::shared_ptr<Rest::Router> router;

};


int main(int argc, char *argv[]) {

  string logFilePath = "logs/";
  LOGGER_START(static_cast<Logger::Priority>(DEBUGLEVEL), "logfile")
  LOGGER_WRITE(Logger::CONFIG, "input file is ")

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


  cout << "Database controller initialization ..." << endl;

  auto dbController = make_shared<DbController>();
  dbController->init();

  cout << "Database controller initialization completed" << endl;

  StatsEndpoint stats(addr);

  Auth auth(stats.getRouter(), dbController);

  stats.init(thr);

  auth.setupRoutes();

  stats.start();

  LOGGER_STOP()

}

