#include "user.h"

using namespace std;

string User::getLogin()
{
    return login;
}

string User::getEmail()
{
    return email;
}

string User::getPassword()
{
    return password;
}

string User::getId()
{
    return id;
}

void User::setLogin(string login)
{
    this->login = login;
}

void User::setEmail(string email)
{
    this->email = email;
}

void User::setPassword(string password)
{
    this->password = password;
}

void User::setId(string id)
{
    this->id = id;
}
