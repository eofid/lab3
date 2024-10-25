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

    // Конструктор
    Contact(const std::string& name, const std::string& phone, const std::string& email, 
            const Address& address, const Company& company);

    // Скрытые друзья — перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Contact& contact) {
        os << contact.name << "\n" << contact.phone << "\n" << contact.email << "\n";
        os << contact.address.getStreet() << "\n" << contact.address.getCity() << "\n" << contact.address.getPostalCode() << "\n";
        os << contact.company.getName() << "\n" << contact.company.getPosition() << "\n";
        return os;
    }

    // Скрытые друзья — перегрузка оператора ввода
    friend std::istream& operator>>(std::istream& is, Contact& contact) {
        std::getline(is, contact.name);
        std::getline(is, contact.phone);
        std::getline(is, contact.email);

        std::string street;
        std:: string city;
        std:: string postalCode;
        std::getline(is, street);
        std::getline(is, city);
        std::getline(is, postalCode);
        contact.address = Address(street, city, postalCode);

        std::string companyName;
        std::string position;
        std::getline(is, companyName);
        std::getline(is, position);
        contact.company = Company(companyName, position);

        return is;
    }
};

#endif // CONTACT_H
