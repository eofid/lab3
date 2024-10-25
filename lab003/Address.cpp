#include "Address.h"

// Конструктор
Address::Address(const std::string& street, const std::string& city, const std::string& postalCode)
    : street(street), city(city), postalCode(postalCode) {}

// Получение улицы
std::string Address::getStreet() const {
    return street;
}

// Получение города
std::string Address::getCity() const {
    return city;
}

// Получение почтового индекса
std::string Address::getPostalCode() const {
    return postalCode;
}
