#include "authentication.h"
#include "investment.h"
#include <iostream>
#include <pistache/http.h>
#include <pistache/router.h>
#include <pistache/endpoint.h>
#include <chrono>
#include <ctime> 


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
  // Port port(9080);

  // int thr = 2;

  // if (argc >=2)
  // {
  //   port = std::stol(argv[1]);

  //   if (argc == 3)
  //     thr = std::stol(argv[2]);
  // }

  // Address addr(Ipv4::any(), port);

  // std::cout << "Cores = " << hardware_concurrency() << std::endl;
  // std::cout << "Using " << thr << " threads" << std::endl;

  // StatsEndpoint stats(addr);

  // Auth auth(stats.getRouter());

  // stats.init(thr);

  // auth.setupRoutes();

  // stats.start();

  InvestmentRetrunPeriod oneDay = InvestmentRetrunPeriod::D1;
  Investment invest(100.00);
  double returnRate = invest.calculateInvestmentReturn(oneDay);
  cout << "Retrun rate from investition is " << returnRate << endl;
}

