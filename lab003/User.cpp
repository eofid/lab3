#include "User.h"

// Конструктор
User::User(const std::string& username, const std::string& password)
    : username(username), password(password) {}

// Аутентификация пользователя
bool User::authenticate(const std::string& username, const std::string& password) const {
    return this->username == username && this->password == password;
}

// Получение имени пользователя
std::string User::getUsername() const {
    return username;
}
