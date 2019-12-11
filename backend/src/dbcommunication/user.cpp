#include "user.h"
#include <bsoncxx/types.hpp>

using namespace std;

/**********************************************************************************************************************/

User::User(string login, string email, string password) : m_login(login), m_email(email), m_password(password), m_portfolio(nullptr)
{

}

User::User(bsoncxx::stdx::optional<bsoncxx::document::value>& userDocument) : m_portfolio(nullptr)
{
    bsoncxx::document::view userView = userDocument->view();

    m_login = userView["login"].get_utf8().value.to_string();
    m_email = userView["email"].get_utf8().value.to_string();
    m_password = userView["password"].get_utf8().value.to_string();
}

/**********************************************************************************************************************/

const string& User::getLogin()  const
{
    return m_login;
}

const string& User::getEmail() const
{
    return m_email;
}

const string& User::getPassword() const
{
    return m_password;
}

const string& User::getId() const
{
    return m_id;
}

void User::setLogin(string login)
{
    this->m_login = login;
}

void User::setEmail(string email)
{
    this->m_email = email;
}

void User::setPassword(string password)
{
    this->m_password = password;
}

void User::setId(string id)
{
    this->m_id = id;
}