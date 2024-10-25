#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
#include "Address.h"
#include "Company.h"

class Contact {
private:
    std::string name;
    std::string phone;
    std::string email;
    Address address;
    Company company;

public:
    // Конструктор
    Contact(const std::string& name, const std::string& phone, const std::string& email, 
            const Address& address, const Company& company);

    // Доступ к приватным членам класса
    std::string getName() const { return name; }
    std::string getPhone() const { return phone; }
    std::string getEmail() const { return email; }
    Address getAddress() const { return address; }
    Company getCompany() const { return company; }

    // Перегруженные операторы как скрытые друзья
    friend std::ostream& operator<<(std::ostream& os, const Contact& contact){
        os << contact.name << "\n" 
       << contact.phone << "\n" 
       << contact.email << "\n"
       << contact.address.getStreet() << "\n" 
       << contact.address.getCity() << "\n" 
       << contact.address.getPostalCode() << "\n"
       << contact.company.getName() << "\n" 
       << contact.company.getPosition() << "\n";
    return os;
    }
    friend std::istream& operator>>(std::istream& is, Contact& contact);
};

#endif // CONTACT_H
