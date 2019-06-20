#include <pistache/endpoint.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace Pistache;

struct HelloHandler : public Http::Handler {
  int counter;
  HTTP_PROTOTYPE(HelloHandler)
  void onRequest(const Http::Request& request, Http::ResponseWriter writer) override{
    printinfo();
    std::cout << "Pistache got request: " << request.method() << std::endl;
    std::cout << "Method = " << request.method() << std::endl;
    std::cout << "Body = " << request.body() << std::endl;

    //**********************************************************
    // std::fstream finmapHTMLPage;
    // finmapHTMLPage.open("../frontend/src/finmap.html", std::ios::in);
    // if (!finmapHTMLPage.good())
    // {
    //   std::cout << "File haven't been opened succeesfully" << std::endl;
    // }

    
    // char buffer2[ 1024 ];
    // std::streamsize fsize = finmapHTMLPage.;
    // //finmapHTMLPage.seekg(0, ios::beg);
    // finmapHTMLPage.read(buffer2, 1024);
    // finmapHTMLPage.close();
    // if (buffer2 == NULL)
    // {
    //     std::cout << "buffer is null" << std::endl;
    // }
    // else
    // {
    //   //std::cout << "buffer" << buffer[0] << buffer[1] << std::endl;
    //   std::cout << "Wczytano " << finmapHTMLPage.gcount() << " bajtów do buffer2" << std::endl;
    // }

    //**********************************************************

    std::fstream finmapHTMLPage;
    std::string buffer;
    std::string line;
    finmapHTMLPage.open("../frontend/src/finmap.html", std::ios::in);
    if (finmapHTMLPage.good())
    {
      while (!finmapHTMLPage.eof())
      {
        getline(finmapHTMLPage, line);
        buffer.append(line);
      }
      finmapHTMLPage.close();
      std::cout << "File haven been read succeesfully" << std::endl;
    }
    else
    {
      std::cout << "File haven't been opened succeesfully" << std::endl;
    }
    
    writer.send(Http::Code::Ok, buffer);
    std::cout << "Server've reponded succeesfully and sent a " << buffer.size() <<std::endl;
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
