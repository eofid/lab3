#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string username;
    std::string password;

public:
    User(const std::string& username, const std::string& password);
    bool authenticate(const std::string& username, const std::string& password) const;
    std::string getUsername() const;
};

#endif // USER_H
