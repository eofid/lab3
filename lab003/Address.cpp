#include "Address.h"

// �����������
Address::Address(const std::string& street, const std::string& city, const std::string& postalCode)
    : street(street), city(city), postalCode(postalCode) {}

// ��������� �����
std::string Address::getStreet() const {
    return street;
}

// ��������� ������
std::string Address::getCity() const {
    return city;
}

// ��������� ��������� �������
std::string Address::getPostalCode() const {
    return postalCode;
}
