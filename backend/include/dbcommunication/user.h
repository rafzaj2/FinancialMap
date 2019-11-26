#pragma once

#include <string>




class User
{
public:
    std::string getLogin();
    std::string getEmail();
    std::string getPassword();
    std::string getId();
    void setLogin(std::string login);
    void setEmail(std::string email);
    void setPassword(std::string password);
    void setId(std::string id);

private:
    std::string login;
    std::string email;
    std::string password;
    std::string id;
};