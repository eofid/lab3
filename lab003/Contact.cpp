#include "Contact.h"

// Реализация конструктора Contact
Contact::Contact(const std::string& name, const std::string& phone, const std::string& email, 
                 const Address& address, const Company& company)
    : name(name), phone(phone), email(email), address(address), company(company) {}

// Дружественная функция для перегрузки оператора вывода
std::ostream& operator<<(std::ostream& os, const Contact& contact) {
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

// Дружественная функция для перегрузки оператора ввода
std::istream& operator>>(std::istream& is, Contact& contact) {
    std::getline(is, contact.name);
    std::getline(is, contact.phone);
    std::getline(is, contact.email);

    std::string street;
    std::string city;
    std::string postalCode;
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
