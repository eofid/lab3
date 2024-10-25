#include "Company.h"

// �����������
Company::Company(const std::string& name, const std::string& position)
    : name(name), position(position) {}

// ��������� �������� ��������
std::string Company::getName() const {
    return name;
}

// ��������� ���������
std::string Company::getPosition() const {
    return position;
}
