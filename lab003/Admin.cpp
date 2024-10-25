#include "Admin.h"

// Êîíñòðóêòîð
Admin::Admin(const std::string_veiw username, const std::string_veiw password)
    : username(username), password(password) {}

// Àóòåíòèôèêàöèÿ àäìèíèñòðàòîðà
bool Admin::authenticate(const std::string_veiw username, const std::string_veiw password) const {
    return this->username == username && this->password == password;
}

// Ïîëó÷åíèå èìåíè àäìèíèñòðàòîðà
std::string Admin::getUsername() const {
    return username;
}
    
