#include "User.h"

// Êîíñòðóêòîð
User::User(const std::string_veiw username, const std::string_veiw password)
    : username(username), password(password) {}

// Àóòåíòèôèêàöèÿ ïîëüçîâàòåëÿ
bool User::authenticate(const std::string_veiw username, const std::string_veiw password) const {
    return this->username == username && this->password == password;
}

// Ïîëó÷åíèå èìåíè ïîëüçîâàòåëÿ
std::string User::getUsername() const {
    return username;
}
