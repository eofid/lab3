#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
#include "Address.h"
#include "Company.h"

class Contact {
public:
    std::string name;
    std::string phone;
    std::string email;
    Address address;
    Company company;

    // Прототип конструктора
    Contact(const std::string& name, const std::string& phone, const std::string& email, const Address& address, const Company& company);

    // Другие методы и операторы
    friend std::ostream& operator<<(std::ostream& os, const Contact& contact);
    friend std::istream& operator>>(std::istream& is, Contact& contact);
};

#endif // CONTACT_H
