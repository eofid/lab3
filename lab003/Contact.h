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

    // Скрытый друг - перегрузка оператора ==
    friend bool operator==(const Contact& lhs, const Contact& rhs) {
        return (lhs.name == rhs.name) && (lhs.phone == rhs.phone) && (lhs.email == rhs.email) &&
               (lhs.address.getStreet() == rhs.address.getStreet()) &&
               (lhs.address.getCity() == rhs.address.getCity()) &&
               (lhs.address.getPostalCode() == rhs.address.getPostalCode()) &&
               (lhs.company.getName() == rhs.company.getName()) &&
               (lhs.company.getPosition() == rhs.company.getPosition());
    }

    // Дружественные операторы для потоков
    friend std::ostream& operator<<(std::ostream& os, const Contact& contact);
    friend std::istream& operator>>(std::istream& is, Contact& contact);
};

#endif // CONTACT_H
