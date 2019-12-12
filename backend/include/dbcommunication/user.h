#pragma once

#include <string>
#include <bsoncxx/json.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/stdx.hpp>
#include <bsoncxx/stdx/optional.hpp>

#include "portfolio.h"




class User
{

private:
    std::string                 m_login;
    std::string                 m_email;
    std::string                 m_password;
    int                         m_id;
    Portfolio*                  m_portfolio;

public:
    User(std::string login, std::string email, std::string password);
    User(bsoncxx::stdx::optional<bsoncxx::document::value>& userDocument);
    const std::string& getLogin() const;
    const std::string& getEmail() const;
    const std::string& getPassword() const;
    const int& getId() const;
    void setLogin(std::string login);
    void setEmail(std::string email);
    void setPassword(std::string password);
    void setId(int id);
    

};