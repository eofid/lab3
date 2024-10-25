#include "Admin.h"

// Конструктор
Admin::Admin(const std::string& username, const std::string& password)
    : username(username), password(password) {}

// Аутентификация администратора
bool Admin::authenticate(const std::string& username, const std::string& password) const {
    return this->username == username && this->password == password;
}

// Получение имени администратора
std::string Admin::getUsername() const {
    return username;
}
    