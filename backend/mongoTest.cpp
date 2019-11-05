// Copyright 2015 MongoDB Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/types.hpp>
#include <iostream>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>

#include <unistd.h>

using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::open_document;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::finalize;




int main(int argc, char const *argv[])
{

    mongocxx::instance instance{}; // This should be done only once.
    mongocxx::client client{mongocxx::uri{}};


    mongocxx::database db = client["mydb"];

    mongocxx::collection coll = db["test1234"];
    try {
        db.create_collection("mycollection");
    }
    catch (...)
    {
        std::cout << "Uwaga 1" << std::endl;
    }

    mongocxx::database db2 = client["mydb2"];

    try {
        db2.create_collection("mycollection");
    }
    catch (...)
    {
        std::cout << "Uwaga 2" << std::endl;
    }

    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::document::value doc_value = builder
    << "name" << "MongoDB"
    << "type" << "database"
    << "count" << 1
    << "versions" << bsoncxx::builder::stream::open_array
        << "v3.2" << "v3.0" << "v2.6"
    << close_array
    << "info" << bsoncxx::builder::stream::open_document
     << "x" << 203
     << "y" << 102
    << bsoncxx::builder::stream::close_document
    << bsoncxx::builder::stream::finalize;

    bsoncxx::document::view view = doc_value.view();

    bsoncxx::document::element element = view["name"];
    if(element.type() != bsoncxx::type::k_utf8) {
      // Error
    }
    std::string name = element.get_utf8().value.to_string();
    bsoncxx::document::element all_db = view["type"];
    std::string all = all_db.get_utf8().value.to_string();
    std::cout << name << std::endl;
    std::cout << all << std::endl;


    coll.insert_one(view);
    unsigned int microseconds = 1000000;
    for (int i = 0; i < 10; i++)
    {
        usleep(microseconds);
    }
    return 0;
}

