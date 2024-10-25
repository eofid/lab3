#include "Contact.h"

// Реализация конструктора Contact
Contact::Contact(const std::string& name, const std::string& phone, const std::string& email, 
                 const Address& address, const Company& company)
    : name(name), phone(phone), email(email), address(address), company(company) {}



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
