#include "Contact.h"

// ���������� ������������ Contact
Contact::Contact(const std::string& name, const std::string& phone, const std::string& email,
    const Address& address, const Company& company)
    : name(name), phone(phone), email(email), address(address), company(company) {}

// ���������� ���������� ��������� "=="
bool operator==(const Contact& lhs, const Contact& rhs) {
    return (lhs.name == rhs.name) && (lhs.phone == rhs.phone) && (lhs.email == rhs.email) &&
        (lhs.address.getStreet() == rhs.address.getStreet()) &&
        (lhs.address.getCity() == rhs.address.getCity()) &&
        (lhs.address.getPostalCode() == rhs.address.getPostalCode()) &&
        (lhs.company.getName() == rhs.company.getName()) &&
        (lhs.company.getPosition() == rhs.company.getPosition());
}

// ���������� ��������� ������ (��� ������ � ����)
std::ostream& operator<<(std::ostream& os, const Contact& contact) {
    os << contact.name << "\n" << contact.phone << "\n" << contact.email << "\n";
    os << contact.address.getStreet() << "\n" << contact.address.getCity() << "\n" << contact.address.getPostalCode() << "\n";
    os << contact.company.getName() << "\n" << contact.company.getPosition() << "\n";
    return os;  // ���������� �����
}

// ���������� ��������� ����� (��� ������ �� ����� ��� ������)
std::istream& operator>>(std::istream& is, Contact& contact) {
    std::getline(is, contact.name);
    std::getline(is, contact.phone);
    std::getline(is, contact.email);

    std::string street, city, postalCode;
    std::getline(is, street);
    std::getline(is, city);
    std::getline(is, postalCode);

    contact.address = Address(street, city, postalCode); // ����������� �����

    std::string companyName, position;
    std::getline(is, companyName);
    std::getline(is, position);

    contact.company = Company(companyName, position); // ����������� ��������

    return is;  // ���������� �����
}
