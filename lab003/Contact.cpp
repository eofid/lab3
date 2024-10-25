#include "Contact.h"

// Реализация конструктора Contact
Contact::Contact(const std::string& name, const std::string& phone, const std::string& email, 
                 const Address& address, const Company& company)
    : name(name), phone(phone), email(email), address(address), company(company) {}




