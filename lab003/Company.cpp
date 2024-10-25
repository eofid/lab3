#include "Company.h"

// Конструктор
Company::Company(const std::string& name, const std::string& position)
    : name(name), position(position) {}

// Получение названия компании
std::string Company::getName() const {
    return name;
}

// Получение должности
std::string Company::getPosition() const {
    return position;
}
