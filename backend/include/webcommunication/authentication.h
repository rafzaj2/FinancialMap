#ifndef AUTHENTICATION
#define AUTHENTICATION

#include <pistache/router.h>
#include <nlohmann/json.hpp>
#include "dbController.h"

using namespace Pistache;
using json = nlohmann::json;


class Auth
{
    public:
        Auth(std::shared_ptr<Rest::Router> Router, std::shared_ptr<DbController> dbCtrl):
            router(Router), dbController(dbCtrl)
        {}
        void setupRoutes();

    private:
        void doPostLogin(const Rest::Request& request, Http::ResponseWriter response);
        void doPostRegister(const Rest::Request& request, Http::ResponseWriter response);

        std::shared_ptr<Rest::Router> router;
        std::shared_ptr<DbController> dbController;
};































#endif 
