#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address {
private:
    std::string street;
    std::string city;
    std::string postalCode;

public:
    Address(const std::string& street, const std::string& city, const std::string& postalCode);
    std::string getStreet() const;
    std::string getCity() const;
    std::string getPostalCode() const;
};

#endif // ADDRESS_H
